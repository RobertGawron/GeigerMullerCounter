#include <stdio.h>
#include <stdint.h>

#include "gm_display_updater.h"
#include "gm_measurement_calculator.h"
#include "gm_logger.h"


static void Simulation_Init()
{
    GMDisplayUpdater_Init();
    GMMeasurementCalculator_Init();
    GMLogger_Init();
}

int main()
{
    Simulation_Init();

    // invoke some actions ond DUT
    for(int i=0; i<30; i++)
    GMMeasurementCalculator_OnGMPulseObserved();
    GMMeasurementCalculator_OnGMPulseObserved();
    GMMeasurementCalculator_OnGMPulseObserved();
    GMMeasurementCalculator_OnGMPulseObserved();
    GMMeasurementCalculator_OnSamplingDone();

    GMLogger_LogMeasurement();

    // check if possible to retreive data
    uint8_t *buffer;
    uint16_t size;
    GMLoggerSIM_GetLoggedData(&buffer, &size);

    for(int i = 0; i < size; i++)
    {
        printf("%c", buffer[i]);
    }

    printf("\n***\ndone\n");
}