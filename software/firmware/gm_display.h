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
#ifndef __GM_DISPLAY_HEADER__
#define __GM_DISPLAY_HEADER__

/* libs */
#include "stm32f4xx_spi.h"
#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"

/* project */
#include "gm_measurements.h"

enum gm_display_field
{
	GM_DISPLAY_FIELD_CURRENT_VALUE,
	GM_DISPLAY_FIELD_PREVIOUS_VALUE,
	GM_DISPLAY_FIELD_GRAPH,
	GM_DISPLAY_FIELD_LAST
};

void gm_display_init();

void gm_display_update(enum gm_display_field field, char* content);

void gm_dummy_graph();

#endif
