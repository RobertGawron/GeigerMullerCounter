#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "GMCounter.h"
#include "LayoutWelcome.h"
#include "LayoutHistogram.h"
#include "LayoutPulseCounter.h"


// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

const byte ledPin = 13;
const byte gmInputPin = 2;
const byte userKeyPin = 12;


// global variables for interrupt handling

volatile byte gmPinState = LOW;
volatile int pulseCounter = 0;


// interrupt handling routine

void interruptHandler() 
{
    gmPinState = !gmPinState;

    if (gmPinState == HIGH)
    {
        pulseCounter++;
    }

    digitalWrite(ledPin, gmPinState);
}


inline void setupGPIO()
{
    // setup GM status diode
    pinMode(ledPin, OUTPUT);

    // setup GM input pin
    pinMode(gmInputPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(gmInputPin), interruptHandler, CHANGE);

    // setup button to select requested layout
//    pinMode(userKeyPin, INPUT);
//    attachInterrupt(digitalPinToInterrupt(userKeyPin), interruptHandler, CHANGE);


}

inline void setupDisplay()
{
    display.begin();
    display.setContrast(47);

    // show welcome screen untill we don't have data
    LayoutWelcome w(display);
    layoutConfig_t lconf;
    w.draw(NULL, lconf);
}


void setup()   
{
    Serial.begin(57600);
    setupGPIO();
    setupDisplay();
}


void loop() 
{
#if 0 
    // Circular Buffer test

    CircularBuffer<uint8_t, 5U> b;

    b.add(4);
    b.add(7);
    b.add(8);
    b.add(12);
    b.add(43);
    b.add(120);
    uint8_t count = b.count();
    Serial.print("count() = ");
    Serial.println(count);

    for(uint8_t j = 0U; j < b.count(); j++)
    {
        uint8_t item = b.get(j);
        Serial.print(item);
        Serial.print(", ");
    }
    Serial.println(" ");

    while(1);
#endif

#if 0 
    // GM Counter test: overview
    GMCounter<5U> gm;
    gm.addSample(4);
    gm.addSample(14);
    gm.addSample(23);
    gm.addSample(12);
    gm.addSample(56);
    gm.addSample(14);

    Serial.print(gm.getSample(0));
    Serial.println(" ");
 
    Serial.print(gm.getSample(1));
    Serial.println(" ");
 
    Serial.print(gm.getMaxSampleValue());
    Serial.println(" ");
 
    while(1); 
#endif

#if 0 
    // GM Counter test: histogram
    GMCounter<6U> gm;
    gm.addSample(14);
    gm.addSample(23);
    gm.addSample(12);
    gm.addSample(56);
    gm.addSample(22);
    gm.addSample(14);

    // min: 14, max: 56, mean: 21
    Serial.println(gm.getBinValue(0, 2));
    Serial.println(gm.getBinValue(1, 2));

    while(1); 
#endif

#if 0
    // Histogram layout test
    static LayoutHistogram layoutHistogram(display);
    static GMCounter<4 * 60> minuteGMCounter;
 
    minuteGMCounter.addSample(10);
    minuteGMCounter.addSample(12);
    minuteGMCounter.addSample(34);
    minuteGMCounter.addSample(45);
    minuteGMCounter.addSample(44);
    minuteGMCounter.addSample(22);
    minuteGMCounter.addSample(5);
    minuteGMCounter.addSample(45);
    minuteGMCounter.addSample(70);
    minuteGMCounter.addSample(66);
 
    layoutConfig_t conf;
    conf.legendText = "1min int hist";

    layoutHistogram.draw(&minuteGMCounter, conf);

    Serial.print("layout end");
    
    while(1);
#endif



#if 1 

    // GM data specific
    static GMCounter<4 * 60> minuteGMCounter;
    static GMCounter<4 * 24> hourGMCounter;

    static uint8_t minuteCounter = 0U;
    
    // layout handling specific
    static LayoutHistogram layoutHistogram(display);
    static LayoutPulseCounter layoutPulseCounter(display);

    bool isLayoutUpdate = false;
    static uint8_t currentLayoutId = 0U;

    // time before display update
    const unsigned long updateInterval = 5L * 1000L;
    unsigned long currentMillis = millis();
    static unsigned long previousMillis = 0;   

    // key related
    uint8_t previousKeyState = HIGH;

    // handle data processing
    if (currentMillis - previousMillis >= updateInterval) 
    {
        previousMillis = currentMillis;
        minuteCounter++;
 
        // handle GM data
        minuteGMCounter.addSample(pulseCounter);
        pulseCounter = 0U;

        // handle hour interval data colection
        const uint8_t minutesInHour = 60U;
     
        if(minuteCounter++ == minutesInHour)
        {
            sample_t hourSample = minuteGMCounter.getMean(minutesInHour);
            hourGMCounter.addSample(hourSample);
            minuteCounter = 0U;
        }
       
        // repaint is needed
        isLayoutUpdate = true;
    }

    // handle key processing
    uint8_t currentKeyState = digitalRead(userKeyPin);

    if ((currentKeyState == LOW) && (previousKeyState == HIGH))
    {
        isLayoutUpdate = true;
        currentLayoutId++;
    }

    previousKeyState = currentKeyState;
    
    // handle layout processing
    if (isLayoutUpdate)
    {
        Serial.println(currentLayoutId);
 
    
        switch (currentLayoutId)
        {
            // pulse counter 1 minute interval
            case 0:
            {
                layoutConfig_t conf;
                layoutPulseCounter.draw(&minuteGMCounter, conf);
            } 
            break;

            // histogram 1 minute interval
            case 1:
            {
                layoutConfig_t conf;
                conf.legendText = "1min int hist";
                layoutHistogram.draw(&minuteGMCounter, conf);
            } 
            break;

            // pulse counter 1 minute interval
            default:
            {
                layoutConfig_t conf;
                layoutPulseCounter.draw(&minuteGMCounter, conf);
                // circulating layouts
                currentLayoutId = 1U;
            } 
            break;


        };

        isLayoutUpdate = false;
    }
#endif
}

