/*
 * hbridge.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author:
 */

#include "hbridge.hpp"

static DigitalOut* ain1;
static DigitalOut* ain2;
static DigitalOut* stby;
static DigitalOut* bin1;
static DigitalOut* bin2;

static PwmOut* pwma;
static PwmOut* pwmb;

void HbridgeInit(PinName _ain1, PinName _ain2, PinName _pwma, PinName _stby, PinName _bin1, PinName _bin2, PinName _pwmb) {
    ain1 = new DigitalOut(_ain1);
    ain2 = new DigitalOut(_ain2);
    stby = new DigitalOut(_stby);
    bin1 = new DigitalOut(_bin1);
    bin2 = new DigitalOut(_bin2);

    pwma = new PwmOut(_pwma);
    pwma->period_ms(2);
    pwma->write(10);

    pwmb = new PwmOut(_pwmb);
    pwmb->period_ms(2);
    pwmb->write(10);
}

void move(uint8_t motor, float speed, uint8_t direction) {
//Move specific motor at speed and direction
//motor: 0 for A, 1 for B
//speed: 0 is short break, 1 is full speed
//direction: 0 clockwise, 1 counter-clockwise

    stby->write(1); //disable standby

    uint8_t inPin1 = 0;
    uint8_t inPin2 = 1;

    if (direction == 1) {
        inPin1 = 1;
        inPin2 = 0;
    }

    if (!motor) {
        ain1->write(inPin1);
        ain2->write(inPin2);
        pwma->write(speed);
    } else {
        bin1->write(inPin1);
        bin2->write(inPin2);
        pwmb->write(speed);
    }
}

void standby() {
    stby->write(0); //enable standby
}

//TODO when the final servo - motor configuration is decided, make speed-direction function
void HbridgeSchedulerTask(void const *args) {
    while (true) {

        move(0, 0.1, 0);
        move(1, 0.1, 0);

        Thread::wait(3000);

        move(0, 0, 0);
        move(1, 0, 0);

        Thread::wait(1500);

        move(0, 0.2, 0);
        move(1, 0.2, 0);

        Thread::wait(3000);
    }
}
