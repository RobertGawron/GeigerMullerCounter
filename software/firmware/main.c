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

/* interrupts */
#include "stm32f4xx.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"

#include "tm_stm32f4_delay.h"

#include "gm_measurements.h"
#include "gm_display.h"
#include "gm_gpio.h"
#include "gm_graph.h"

static gm_measurements_t gm_measurements;

/* Handle PB12 interrupt */
/* TODO move it somewhere */
void EXTI15_10_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line12) != RESET) {

        // TODO synchronization
        gm_measurements_update_sample(&gm_measurements);

       /* gm_display_data_t data;
        data.type = GM_DISPLAY_CONTENT_TYPE_STRING;
        char textBuffer[20]; //TODO magic number

        data.value.as_string = &textBuffer[0];

        sprintf(textBuffer, "Counting: %3d", gm_measurements_get(&gm_measurements, GM_MEASUREMENTS_ITERR_CURR));
        gm_display_update(GM_DISPLAY_FIELD_CURRENT_VALUE, &data);
*/
        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line12);
    }
}

int main(void) {
    SystemInit();

    /* Configure display */
    gm_display_init();

    /* Configure measurements */
    gm_measurements_init(&gm_measurements);


    /* No data yet, show blank marks */
    gm_display_data_t data;
    data.type = GM_DISPLAY_CONTENT_TYPE_STRING;

    data.value.as_string = "Current: ..";
    gm_display_update(GM_DISPLAY_FIELD_CURRENT_VALUE, &data);

    data.value.as_string = "Previous: ..";
    gm_display_update(GM_DISPLAY_FIELD_PREVIOUS_VALUE, &data);

    TM_DELAY_Init();

    /* Configure PB12 as interrupt */
    Configure_PB12();

    TM_DELAY_SetTime(0);


    while (1) {
      //  if (TM_DELAY_Time() >= 60*1000){
        if (TM_DELAY_Time() >= 3 * 1000) {
            /* Reset time */
            TM_DELAY_SetTime(0);


            char text_buffer[20]; //TODO magic number
            data.value.as_string = &text_buffer[0];

            uint8_t current_value = gm_measurements_get(&gm_measurements, GM_MEASUREMENTS_ITERR_CURR);
            sprintf(text_buffer, "Counting: %3d", current_value);
            gm_display_update(GM_DISPLAY_FIELD_CURRENT_VALUE, &data);

            uint8_t previous_value = gm_measurements_get(&gm_measurements, GM_MEASUREMENTS_ITERR_PREV);
            sprintf(text_buffer, "Previous: %3d", previous_value);
            gm_display_update(GM_DISPLAY_FIELD_PREVIOUS_VALUE, &data);

            gm_measurements_next_sample(&gm_measurements);
        }
    }
}
