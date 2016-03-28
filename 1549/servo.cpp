/*
 * servo.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author:
 */
#include "servo.hpp"

static PwmOut *servoPWM;

void ServoInit(PinName tx) {
    servoPWM = new PwmOut(tx);
    servoPWM->period_ms(20);
    servoPWM->pulsewidth_us(1500);
}

void ServoSchedulerTask(void const *args) {
    while (true) {

        servoPWM->pulsewidth_us(1400);

        Thread::wait(1500);

        servoPWM->pulsewidth_us(1550);

        Thread::wait(1500);
    }
}

