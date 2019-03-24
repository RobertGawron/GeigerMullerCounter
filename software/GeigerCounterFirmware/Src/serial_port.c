/*
 * serial_port.c
 *
 *  Created on: 24.03.2019
 *      Author: robert
 */

#include <stdlib.h>
#include <string.h>

#include "serial_port.h"
#include "circular_buffer.h"

extern UART_HandleTypeDef huart2;

#define TX_BUFFER_SIZE 10
char txBuffer[TX_BUFFER_SIZE];

void SerialPort_Init()
{

}

void SerialPort_SendData()
{
    uint16_t base = 10;

    SampleStorage_Element_t latestSampleValue;
    CircularBuff_GetElement(&latestSampleValue, 0);


    itoa(latestSampleValue, &txBuffer[0], base);
    uint16_t stringOffset = strlen(txBuffer);

    txBuffer[stringOffset++] = '\r';
    txBuffer[stringOffset++] = '\n';
    txBuffer[stringOffset] = '\0';

    HAL_UART_Transmit(&huart2, (uint8_t*) &txBuffer[0], stringOffset, 0xFFFF);
}
