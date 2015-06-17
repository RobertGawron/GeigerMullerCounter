/**
 * |----------------------------------------------------------------------
 * | Copyright (C) Robert Gawron, 2015
 * | Homepage https://github.com/RobertGawron/GeigerMullerCounter
 * |
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * |
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */

#include <stdio.h>

#include "stm32f4xx.h"

/* Pin interrupt */
#include "stm32f4xx.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"

#include "tm_stm32f4_delay.h"

#include "gm_display.h"
#include "gm_gpio.h"
#include "gm_graph.h"

// TODO move to a separate file
typedef struct gm_measurement_t
{
	uint8_t current_counts;
	uint8_t previous_counts;
} gm_measurement_t;

static gm_measurement_t gm_measurement;

// TODO move to gm_display file

/* Handle PB12 interrupt */
void EXTI15_10_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line12) != RESET) {
        /* Do your stuff when PB12 is changed */

    	// TODO synchronization
    	gm_measurement.current_counts++;

    	char textBuffer[10];
    	sprintf(textBuffer, "Current:  %4d", gm_measurement.current_counts);
    	gm_display_update(GM_DISPLAY_FIELD_CURRENT_VALUE, textBuffer);


        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line12);
    }
}

int main(void)
{
	SystemInit();

	gm_display_init();

	TM_DELAY_Init();

	/* Configure PB12 as interrupt */
	Configure_PB12();

	//GMCounts = 0;
	gm_measurement.current_counts = 0U;
	gm_measurement.previous_counts = 0U;

    char textBuffer[10];

    sprintf(textBuffer, "Current: %4d", gm_measurement.previous_counts);
    gm_display_update(GM_DISPLAY_FIELD_CURRENT_VALUE, textBuffer);

    sprintf(textBuffer, "Previous: %4d", gm_measurement.previous_counts);
    gm_display_update(GM_DISPLAY_FIELD_PREVIOUS_VALUE, textBuffer);


	TM_DELAY_SetTime(0);

	while (1)
	{
		 if (TM_DELAY_Time() >= 60*1000)
		 {
			 /* Reset time */
		     TM_DELAY_SetTime(0);

		     gm_measurement.previous_counts = gm_measurement.current_counts;
		     gm_measurement.current_counts = 0U;

		     sprintf(textBuffer, "Current: %4d", gm_measurement.previous_counts);
		     gm_display_update(GM_DISPLAY_FIELD_CURRENT_VALUE, textBuffer);

		     sprintf(textBuffer, "Previous: %4d", gm_measurement.previous_counts);
		     gm_display_update(GM_DISPLAY_FIELD_PREVIOUS_VALUE, textBuffer);
		 }
	}

}
