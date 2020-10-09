#ifndef GMCIRCULAR_BUFFER_H_
#define GMCIRCULAR_BUFFER_H_

#include <stdbool.h>
#include "gm_measurement.h"

void GMCircularBuffer_Init();

uint16_t GMCircularBuffer_GetElementCount();

GMMeasurement_Value_t GMCircularBuffer_GetMaxElement();

void GMCircularBuffer_Insert(GMMeasurement_Value_t element);

bool GMCircularBuffer_GetElement(GMMeasurement_Value_t *element, uint16_t index);


#endif
