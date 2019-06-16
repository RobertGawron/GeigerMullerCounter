/*
 * dose_counter.h
 *
 *  Created on: 24.03.2019
 *      Author: robert
 */

#ifndef DOSE_COUNTER_H_
#define DOSE_COUNTER_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>
#include "sample_storage.h"

float DoseCounter_Calculate(SampleStorage_Element_t count);

#endif /* DOSE_COUNTER_H_ */
