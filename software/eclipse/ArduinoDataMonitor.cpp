#include "ApplicationBuilder.h"


static ApplicationBuilder application;

void setup()
{
    application.init();
}


void loop()
{
    application.run();


#if 0

    //
    // the device has three parallel tubes.
    //static const uint8_t AMOUNT_OF_PRRALLEL_TUBES = 3U;

    // GM data specific
    static GMCounter<4 * 60, AMOUNT_OF_PRRALLEL_TUBES> minuteGMCounter;
    static GMCounter<4 * 24, AMOUNT_OF_PRRALLEL_TUBES> hourGMCounter;
    static uint8_t minuteCounter = 0U;

    // layout handling specific
    static LayoutHistogram layoutHistogram(display);
    static LayoutPulseCounter layoutPulseCounter(display);

    // changing layout specific
    bool isLayoutUpdate = false;
    bool isLayoutSwitch = false;

    // time before display update
    const unsigned long updateInterval = 60L * 1000L;
    unsigned long currentMillis = millis();
    static unsigned long previousMillis = 0;

    // key related
    static uint8_t previousKeyState = HIGH;

    // handle data processing
    if (currentMillis - previousMillis >= updateInterval)
    {
        previousMillis = currentMillis;
        minuteCounter++;

        // handle minute interval GM data
        minuteGMCounter.addSample(pulseCounter);
        pulseCounter = 0U;

        // handle hour interval GM data
        const uint8_t minutesInHour = 60U;

        if(minuteCounter == minutesInHour)
        {
            sample_t hourSample = minuteGMCounter.getMean(minutesInHour);
            hourGMCounter.addSample(hourSample);
            minuteCounter = 0U;
        }

        // new data is available - repaint current layout
        isLayoutUpdate = true;
    }


    // TODO: this 50 below is a dirty way, make it better
    if(((currentMillis - previousMillis) % 50U) == 0U)
    {
        // handle key processing, no software debouncing!
        uint8_t currentKeyState = digitalRead(userKeyPin);

        if ((currentKeyState == LOW) && (previousKeyState == HIGH))
        {
            isLayoutSwitch = true;
        }
        previousKeyState = currentKeyState;
    }

    // handle layout processing
    if (isLayoutUpdate || isLayoutSwitch)
    {
        static int8_t currentLayoutId = 0U;

        if(isLayoutSwitch)
        {
            currentLayoutId++;
        }

        switch (currentLayoutId)
        {
            case 0:
            {
                // pulse counter 1 minute interval
                layoutConfig_t conf;
                conf.pulseConfig.pulseLabel = "cpm";
                conf.pulseConfig.doseLabel  = "uS/h";
                layoutPulseCounter.draw(&minuteGMCounter, conf);
            } break;

            case 1:
            {
                // pulse counter 1 hour interval
                layoutConfig_t conf;
                conf.pulseConfig.pulseLabel = "cph";
                conf.pulseConfig.doseLabel  = "";
                layoutPulseCounter.draw(&hourGMCounter, conf);
            } break;

            case 2:
            {
                // histogram 1 minute interval
                layoutConfig_t conf;
                conf.legendText = "1min hist";
                layoutHistogram.draw(&minuteGMCounter, conf);
            } break;

            default:
            {
                // histogram 1 hour interval
                layoutConfig_t conf;
                conf.legendText = "1h hist";
                layoutHistogram.draw(&hourGMCounter, conf);

                // circulating layouts
                currentLayoutId = -1;
            } break;
        };

        isLayoutUpdate = false;
    }
#endif
}
