/*
 * detector.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author:
 */
#include "detector.hpp"

static InterruptIn* detector1;

static Serial* detector_uart;

static Thread* detector_thread;

DigitalOut myled(LED1);

uint8_t item_count = 0;


void DetectorInit(PinName rx, Serial* serial_obj) {
    detector1 = new InterruptIn(rx);
    detector1->rise(&rise_isr);
    detector1->fall(&fall_isr);

    detector_uart = serial_obj;

    detector_thread = new Thread(DetectorTask);
}

void rise_isr() {
    if (ITEM_PRESENT_HIGH) {
        myled = 1;
    } else {
        myled = 0;
        item_count += 1;
        detector_thread->signal_set(DETECTOR_SIGNAL);

    }
}

void fall_isr() {
    if (!ITEM_PRESENT_HIGH) {
        myled = 1;
    } else {
        myled = 0;
        item_count += 1;
        detector_thread->signal_set(DETECTOR_SIGNAL);
    }
}

void DetectorTask(void const *args) {
    while (true) {
        Thread::signal_wait(DETECTOR_SIGNAL);

        detector_uart->putc(DETECTOR1);

//        printf("Items passed: %d\n\r", item_count);
    }
}
