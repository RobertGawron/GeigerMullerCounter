#include "gm_dose_counter.h"

float GMDoseCounter_Calculate(GMMeasurement_Value_t count)
{
    // from https://mightyohm.com/forum/viewtopic.php?f=15&t=454
    // STS-5 is an older verson SBM-20, but they are quite the same,
    // so the conversion should be valid
    float dose = (float)count / 57.0;

    return dose;
}
