#include "sensor.h"
#include <xc.h>

void sensor_init()
{
    /* sensor is plugged to RB0 */
    
    /* Configure RB0 as digital */
    ANSELBbits.ANSB0 = 0;
    /* Configure RB0 as input */
    TRISBbits.TRISB0 = 1;  
}
