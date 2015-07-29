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
 * \file gm_display.h
 * \brief Update of the layout content.
 * \author Robert Gawron
 * \version 0.1
 *
 * Makes layout updates more flexible. Decides where particular elements should be displayed, and how their content should be updated.
 *
 */
#ifndef __GM_DISPLAY_HEADER__
#define __GM_DISPLAY_HEADER__

#include "gm_measurements.h"

enum gm_display_field {
    GM_DISPLAY_FIELD_CURRENT_VALUE, /*!< Current measurement. */
    GM_DISPLAY_FIELD_PREVIOUS_VALUE, /*!< Previous measurement. */
    GM_DISPLAY_FIELD_GRAPH, /*!< Graph of the measurements. */
    GM_DISPLAY_FIELD_LAST /*!< Last item in the enum. */
};

/* no method overloading by arguments in C */
enum gm_display_data_type {
    GM_DISPLAY_CONTENT_TYPE_STRING,
    GM_DISPLAY_CONTENT_TYPE_UINT8,
    GM_DISPLAY_CONTENT_TYPE_LAST
};

typedef struct gm_display_data {
    enum gm_display_data_type type;
    union {
        char* as_string;
        gm_measurements_t* as_gm_measurements;
    } value;
} gm_display_data_t;

void gm_display_init();

void gm_display_update(enum gm_display_field field, gm_display_data_t* data);

#endif
