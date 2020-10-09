#include <stdlib.h>
#include <string.h>

#include "gm_logger.h"
#include "gm_measurement.h"
#include "stm32f0xx_hal.h"

#define TX_BUFFER_SIZE 10
char txBuffer[TX_BUFFER_SIZE];

extern UART_HandleTypeDef huart2; // auto-generated in main.c

void GMLogger_Init()
{

}

void GMLogger_SendMeasurement()
{
    /*
    SampleStorage_Element_t latestSampleValue;
    CircularBuff_GetElement(&latestSampleValue, 0);

    uint16_t base = 10;
    itoa(latestSampleValue, &txBuffer[0], base);
    uint16_t stringOffset = strlen(txBuffer);

    txBuffer[stringOffset++] = '\r';
    txBuffer[stringOffset++] = '\n';
    txBuffer[stringOffset] = '\0';

    HAL_UART_Transmit(&huart2, (uint8_t*) &txBuffer[0], stringOffset, 0xFFFF);
    */
//
    GMMeasurement_Value_t latestMeasurement;
  //  CircularBuff_GetElement(&latestSampleValue, 0);

    uint16_t base = 10;
    itoa(latestMeasurement, &txBuffer[0], base);
    uint16_t stringOffset = strlen(txBuffer);

    txBuffer[stringOffset++] = '\r';
    txBuffer[stringOffset++] = '\n';
    txBuffer[stringOffset] = '\0';

    HAL_UART_Transmit(&huart2, (uint8_t*) &txBuffer[0], stringOffset, 0xFFFF);

}
