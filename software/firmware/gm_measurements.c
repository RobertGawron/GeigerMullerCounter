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

void gm_measurements_init(gm_measurements_t *object) {
    object->capacity = GM_MAX_MEASUREMENTS_ITEMS;
    object->index = 0U;
    // current measurement is zero counts
    object->counts[0U] = 0U;
}

void gm_measurements_update_sample(gm_measurements_t *object) {
    object->counts[object->index]++;
}

void gm_measurements_next_sample(gm_measurements_t *object) {
    // set the index of the current measurement
    object->index++;

    if (object->index == object->capacity) {
        object->index = 0U;
    }

    // current measurement is zero counts
    object->counts[object->index] = 0U;
}

uint8_t gm_measurements_get(gm_measurements_t *object, enum gm_measurements_iterr iterr) {
    uint8_t ret = 0U;
    switch (iterr) {
        case GM_MEASUREMENTS_ITERR_CURR: {
            uint16_t index = object->index;
            ret = object->counts[index];
            break;
        }
        case GM_MEASUREMENTS_ITERR_PREV: {
            if (object->index > 0U) {
                uint16_t index = object->index - 1U;
                ret = object->counts[index];
            } else {
                uint16_t index = object->capacity - 1U;
                ret = object->counts[index];
            }
        }
        default: {
            /* should not happened */
            ret = 0U;
        }
    }

    return ret;
}
