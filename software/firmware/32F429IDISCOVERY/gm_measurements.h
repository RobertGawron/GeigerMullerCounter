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
 * \file gm_measurements.h
 * \brief Store and manipulate obtained samples .
 * \author Robert Gawron
 * \version 0.1
 *
 * Circular buffer of obtained samples.
 *
 */
#ifndef __GM_MEASUREMENTS_HEADER__
#define __GM_MEASUREMENTS_HEADER__

#include "stm32f4xx.h"

#define GM_MAX_MEASUREMENTS_ITEMS 240

/* Ring-buffer, fixed-size. */
typedef struct gm_measurements_t {
    uint8_t counts[GM_MAX_MEASUREMENTS_ITEMS];
    uint16_t index;
    uint16_t capacity;
} gm_measurements_t;

/* It's like a simple iterator but it isn't. */
enum gm_measurements_iterr {
    GM_MEASUREMENTS_ITERR_CURR,
    GM_MEASUREMENTS_ITERR_PREV,
};

void gm_measurements_init(gm_measurements_t *object);

void gm_measurements_count(gm_measurements_t *object);

void gm_measurements_next_sample(gm_measurements_t *object);

uint8_t gm_measurements_get(gm_measurements_t *object, enum gm_measurements_iterr iterr);

uint8_t gm_measurements_index(gm_measurements_t *object);

#endif
