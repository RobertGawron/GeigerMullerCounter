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
#include "gm_measurements.h"

#include <stdio.h>

void gm_measurements_reset_samples(gm_measurements_t *object);
uint16_t gm_measurements_prev_sample_index(gm_measurements_t *object);

void gm_measurements_init(gm_measurements_t *object) {
    object->capacity = GM_MAX_MEASUREMENTS_ITEMS;
    gm_measurements_reset_samples(object);
    object->index = 0U;
}

void gm_measurements_update_sample(gm_measurements_t *object) {
    object->counts[object->index]++;
}

void gm_measurements_next_sample(gm_measurements_t *object) {
    // set index of the current sample
    object->index++;
    object->index %= object->capacity;

    // reset current sample value
    object->counts[object->index] = 0U;
}

uint8_t gm_measurements_get(gm_measurements_t *object, enum gm_measurements_iterr iterr) {
    uint16_t index = 0U;

    switch (iterr) {
        case GM_MEASUREMENTS_ITERR_CURR: {
            index = object->index;
            break;
        }
        case GM_MEASUREMENTS_ITERR_PREV: {
            index = gm_measurements_prev_sample_index(object);
            break;
        }
        default: {
            // should not happened
        }
    }

    return object->counts[index];
}

void gm_measurements_reset_samples(gm_measurements_t *object) {
    uint16_t i;
    for (i = 0U; i < object->capacity; i++) {
        object->counts[i] = 0U;
    }
}

uint16_t gm_measurements_prev_sample_index(gm_measurements_t *object) {
    uint16_t index = 0U;
    if (object->index == 0U) {
        index = object->capacity - 1U;
    } else {
        index = object->index - 1U;
    }
    return index;
}
