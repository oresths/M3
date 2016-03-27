/*
 * detector.hpp
 *
 *  Created on: Mar 27, 2016
 *      Author:
 */

#ifndef DETECTOR_HPP_
#define DETECTOR_HPP_

#include "mbed.h"
#include "rtos.h"

#define ITEM_PRESENT_HIGH 1  //1 for high active

void DetectorInit(PinName rx);

void rise_isr();

void fall_isr();

void DetectorSchedulerTask(void const *args);


#endif /* DETECTOR_HPP_ */
