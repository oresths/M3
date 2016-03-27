/*
 * detector.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author:
 */
#include "detector.hpp"

static InterruptIn* detector1;

DigitalOut myled(LED1);

uint8_t item_count = 0;

void DetectorInit(PinName rx) {
    detector1 = new InterruptIn(rx);
    detector1->rise(&rise_isr);
    detector1->fall(&fall_isr);
}

void rise_isr() {
    if (ITEM_PRESENT_HIGH) {
        myled = 1;
    } else {
        myled = 0;
        item_count += 1;
    }
}

void fall_isr() {
    if (!ITEM_PRESENT_HIGH) {
        myled = 1;
    } else {
        myled = 0;
        item_count += 1;
    }
}

void DetectorSchedulerTask(void const *args) {
    while (true) {

        printf("Items passed: %d\n\r", item_count);

        Thread::wait(500);
    }
}
