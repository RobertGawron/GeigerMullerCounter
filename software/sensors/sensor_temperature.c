#include "sensor_temperature.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void sensor_temperature_configure();
int8_t sensor_temperature_rescale(int inputValue);

int8_t sensor_temperature_get_value() {
	sensor_temperature_configure();
	ADC_SoftwareStartConv(ADC1);
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC))
		;
	return sensor_temperature_rescale(ADC_GetConversionValue(ADC1));
}

int8_t sensor_temperature_rescale(int inputValue) {
	return inputValue;
}

void sensor_temperature_configure() {
	ADC_InitTypeDef ADC_init_structure;
	GPIO_InitTypeDef GPIO_initStructre;

	//Clock configuration
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //The ADC1 is connected the APB2 peripheral bus thus we will use its clock source
	RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOCEN, ENABLE); //Clock for the ADC port.

	//Analog pin configuration
	GPIO_initStructre.GPIO_Pin = GPIO_Pin_0; //The channel 10 is connected to PC0
	GPIO_initStructre.GPIO_Mode = GPIO_Mode_AN; //The PC0 pin is configured in analog mode
	GPIO_initStructre.GPIO_PuPd = GPIO_PuPd_NOPULL; //We don't need any pull up or pull down
	GPIO_Init(GPIOC, &GPIO_initStructre); //Affecting the port with the initialization structure configuration

	//ADC structure configuration
	ADC_DeInit();
	ADC_init_structure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_init_structure.ADC_Resolution = ADC_Resolution_12b; //Input voltage is converted into a 12bit number giving a maximum value of 4096
	ADC_init_structure.ADC_ContinuousConvMode = ENABLE; //the conversion is continuous, the input data is converted more than once
	ADC_init_structure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1; // conversion is synchronous with TIM1 and CC1
	ADC_init_structure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None; //no trigger for conversion
	ADC_init_structure.ADC_NbrOfConversion = 1;
	ADC_init_structure.ADC_ScanConvMode = DISABLE; //The scan is configured in one channel
	ADC_Init(ADC1, &ADC_init_structure); //Initialize ADC with the previous configuration

	//Enable ADC conversion
	ADC_Cmd(ADC1, ENABLE);

	//Select the channel to be read from
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_144Cycles);
}

