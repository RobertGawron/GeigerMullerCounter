/*
 * geiger_counter.h
 *
 *  Created on: 10.02.2019
 *      Author: robert
 */

#ifndef GEIGER_COUNTER_H_
#define GEIGER_COUNTER_H_

void GeigerCounter_Init();

void GeigerCounter_OnTimeSampleFinish();

void GeigerCounter_OnPulseObserved();

#endif /* GEIGER_COUNTER_H_ */
