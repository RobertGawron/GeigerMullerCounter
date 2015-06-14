#include "stm32f4xx.h"

//#include "tm_stm32_defs.h"
#include <stdio.h>

/* LCD */
#include "stm32f4xx_spi.h"
#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"

/* Pin interrupt */
#include "stm32f4xx.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"

//#include "stm32f4xx_tim.h"
#include "tm_stm32f4_delay.h"

void Configure_PB12(void) {
    /* Set variables used */
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    /* Enable clock for GPIOB */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    /* Enable clock for SYSCFG */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    /* Set pin as input */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Tell system that you will use PB12 for EXTI_Line12 */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource12);

    /* PB12 is connected to EXTI_Line12 */
    EXTI_InitStruct.EXTI_Line = EXTI_Line12;
    /* Enable interrupt */
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct);

    /* Add IRQ vector to NVIC */
    /* PB12 is connected to EXTI_Line12, which has EXTI15_10_IRQn vector */
    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
    /* Set priority */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
    /* Enable interrupt */
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct);
}

/* Set interrupt handlers */
/* Handle PD0 interrupt */
void EXTI0_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
        /* Do your stuff when PD0 is changed */


        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

static int GMCounts;
static int oldGMCounts;

/* Handle PB12 interrupt */
void EXTI15_10_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line12) != RESET) {
        /* Do your stuff when PB12 is changed */

    	GMCounts++;
    	char s[10];
    	sprintf(s, "Current:  %4d", GMCounts);

    	TM_ILI9341_Puts(5, 20, s, &TM_Font_16x26,
    					ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line12);
    }
}

int main(void)
{
	SystemInit();

	//TM_TIMER_Init();
	TM_DELAY_Init();

	/* Configure PB12 as interrupt */
	Configure_PB12();



	/* Initialize ILI9341 LCD on board */
	TM_ILI9341_Init();
	TM_ILI9341_Fill(ILI9341_COLOR_BLACK);
	TM_ILI9341_Rotate(TM_ILI9341_Orientation_Landscape_1);

	TM_ILI9341_Puts(5, 5, "Geiger-Muller counter", &TM_Font_7x10,
					ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	GMCounts = 0;
	TM_DELAY_SetTime(0);

	while (1)
	{
		 if (TM_DELAY_Time() >= 60*1000)
		 {
			 /* Reset time */
		     TM_DELAY_SetTime(0);


		     oldGMCounts = GMCounts;
		     GMCounts = 0;
		     char textBuffer[10];
		     sprintf(textBuffer, "Previous: %4d", oldGMCounts);

		     TM_ILI9341_Puts(5, 50, textBuffer, &TM_Font_16x26,
		    		 	 ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

		     //TM_ILI9341_Puts(5, 20, textBuffer, &TM_Font_16x26,
		     //    					ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

		 }
	}

}
