/*
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

/**
 * \file gm_gpio.h
 * \brief Receive data from the GM device.
 * \author Robert Gawron
 * \version 0.1
 *
 * The file is responsible for interrupt configuration for the GM device. GM device is connected to PB12 and raises an interrupt when a pulse is observed.
 *
 */
#ifndef __GM_GPIO_HEADER__
#define __GM_GPIO_HEADER__

/* Pin interrupt */
#include "stm32f4xx.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"

// TODO move body to .c file

void Configure_PB12(void);

#ifdef NOT_HERE_FOR_NOW
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
#endif

#endif
