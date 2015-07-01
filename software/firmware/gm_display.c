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
#include "gm_display.h"

const uint16_t GM_BACKGROUND_COLOR = ILI9341_COLOR_BLACK;
const TM_ILI9341_Orientation_t GM_ORIENTATION = TM_ILI9341_Orientation_Landscape_1;

void gm_display_init()
{
    /* Initialize ILI9341 LCD on board */
    TM_ILI9341_Init();
    TM_ILI9341_Fill(GM_BACKGROUND_COLOR);
    TM_ILI9341_Rotate(GM_ORIENTATION);
}
void gm_display_update(enum gm_display_field field, char* content)
{
    // TODO remove magic numbers
    switch (field)
    {
    case GM_DISPLAY_FIELD_CURRENT_VALUE:
    {
        TM_ILI9341_Puts(5, 20, content, &TM_Font_16x26,
                                ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

        break;
    }
    case GM_DISPLAY_FIELD_PREVIOUS_VALUE:
    {
        TM_ILI9341_Puts(5, 50, content, &TM_Font_16x26,
                                ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
        break;
    }

    default:
    {
        // ignore incorrect fields
        break;
    }
    }
}


void gm_dummy_graph(){}
