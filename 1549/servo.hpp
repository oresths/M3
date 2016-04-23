/*
 * servo.hpp
 *
 *  Created on: Mar 27, 2016
 *      Author:
 */

#ifndef SERVO_HPP_
#define SERVO_HPP_

#include "mbed.h"
#include "rtos.h"

#define DEBUG 1

void ServoInit(PinName tx, Serial* serial_obj);

void RX_isr();

void ServoReceiverTask(void const *args);


#endif /* SERVO_HPP_ */
