/*
 * circular_buffer.h
 *
 *  Created on: 02.02.2019
 *      Author: robert
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>
#include "sample_storage.h"

void CircularBuff_Init();

uint16_t CircularBuff_GetElementCount();

SampleStorage_Element_t CircularBuff_GetMaxElement();

void CircularBuff_Insert(SampleStorage_Element_t element);

bool CircularBuff_GetElement(SampleStorage_Element_t *element, uint16_t index);


#endif /* CIRCULAR_BUFFER_H_ */
