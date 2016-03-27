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

void ServoInit(PinName tx);

void ServoSchedulerTask(void const *args);


#endif /* SERVO_HPP_ */
