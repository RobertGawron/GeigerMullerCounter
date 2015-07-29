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
#include "gm_graph.h"
#include <stdio.h>
#include "tm_stm32f4_ili9341.h"

typedef struct gm_graph_plotline_t {
    uint16_t x0;
    uint16_t x1;
    uint16_t y0;
    uint16_t y1;
} gm_graph_plotline_t;

void gm_plot_scale_to_fit_lcd(uint16_t x, uint16_t y, gm_graph_plotline_t* coordinate);

void gm_graph_plot(gm_measurements_t* data) {
    uint8_t x = gm_measurements_index(data);
    uint8_t y = gm_measurements_get(data, GM_MEASUREMENTS_ITERR_CURR);

    gm_graph_plotline_t coordinate;
    gm_plot_scale_to_fit_lcd(x, y, &coordinate);

    TM_ILI9341_DrawLine(coordinate.x0, coordinate.y0, coordinate.x1, coordinate.y1, ILI9341_COLOR_WHITE);
}

void gm_plot_scale_to_fit_lcd(uint16_t x, uint16_t y, gm_graph_plotline_t* coordinate) {
    coordinate->x0 = x;
    coordinate->x1 = x;
    coordinate->y0 = ILI9341_WIDTH;
    coordinate->y1 = ILI9341_WIDTH - y;
}
