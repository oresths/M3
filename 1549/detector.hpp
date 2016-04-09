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

#define DETECTOR_SIGNAL 0x1

#define DETECTOR1 'A' //A


void DetectorInit(PinName rx, Serial* serial_obj);

void rise_isr();

void fall_isr();

void DetectorTask(void const *args);


#endif /* DETECTOR_HPP_ */
