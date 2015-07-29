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
 * \file gm_graph.h
 * \brief Draw graph on the LCD.
 * \author Robert Gawron
 * \version 0.1
 *
 * To facilitate usage of the device, gathered data is presented in the bar-graph. Currently the group is not scaled (if captured values will go out of range, this bill probably leads to a crash). Each sample is one bar on the graph, 1 pixel of the bar = one count.
 *
 * As an example, 100px bar means, that during capturing of the sample, 100 counts were detected.
 *
 */
#ifndef __GM_GRAPH_HEADER__
#define __GM_GRAPH_HEADER__

#include "gm_measurements.h"

/**
 * Draw a graph of the measurements on the LCD.
 */
void gm_graph_plot(gm_measurements_t* data);

#endif
