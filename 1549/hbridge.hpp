/*
 * hbridge.hpp
 *
 *  Created on: Apr 5, 2016
 *      Author:
 */

#ifndef HBRIDGE_HPP_
#define HBRIDGE_HPP_

#include "mbed.h"
#include "rtos.h"

void HbridgeInit(PinName _ain1, PinName _ain2, PinName _pwma, PinName _stby, PinName _bin1, PinName _bin2, PinName _pwmb);

void move(uint8_t motor, float speed, uint8_t direction);

void standby();

void HbridgeSchedulerTask(void const *args);

#endif /* HBRIDGE_HPP_ */
