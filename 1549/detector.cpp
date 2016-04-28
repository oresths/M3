/*
 * detector.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author:
 */
#include "detector.hpp"

static InterruptIn* detector1;
static InterruptIn* detector2;
static InterruptIn* detector3;
static InterruptIn* detector4;
static InterruptIn* detector5;
static InterruptIn* detector6;
static InterruptIn* detector7;
static InterruptIn* detector8;

static Queue<uint8_t, 19> detector_rx_queue;

static Serial* detector_uart;

static Thread* detector_thread;

#if DEBUG
DigitalOut myled(LED1);

uint8_t item_count = 0;
#endif


void DetectorInit(PinName rx1, PinName rx2, PinName rx3, PinName rx4, PinName rx5, PinName rx6, PinName rx7,
        PinName rx8, Serial* serial_obj) {
    detector1 = new InterruptIn(rx1);
    detector1->rise(&rise_isr1);
    detector1->fall(&fall_isr1);
    detector2 = new InterruptIn(rx2);
    detector2->rise(&rise_isr2);
    detector2->fall(&fall_isr2);
    detector3 = new InterruptIn(rx3);
    detector3->rise(&rise_isr3);
    detector3->fall(&fall_isr3);
    detector4 = new InterruptIn(rx4);
    detector4->rise(&rise_isr4);
    detector4->fall(&fall_isr4);
    detector5 = new InterruptIn(rx5);
    detector5->rise(&rise_isr5);
    detector5->fall(&fall_isr5);
    detector6 = new InterruptIn(rx6);
    detector6->rise(&rise_isr6);
    detector6->fall(&fall_isr6);
    detector7 = new InterruptIn(rx7);
    detector7->rise(&rise_isr7);
    detector7->fall(&fall_isr7);
    detector8 = new InterruptIn(rx8);
    detector8->rise(&rise_isr8);
    detector8->fall(&fall_isr8);

    detector_uart = serial_obj;

    detector_thread = new Thread(DetectorTask);
}

void DetectorTask(void const *args) {
    while (true) {
        osEvent evt = detector_rx_queue.get();   //If queue empty, stops here and lets other threads run
        int recv_char = evt.value.v;    //Received character

#if DEBUG
        printf("Items passed: %d\n\r", item_count);
#else
        detector_uart->putc(recv_char);
#endif
    }
}

void rise_isr1() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR1);
    } else { //what to do when item gets OUT of detection

    }
}

void fall_isr1() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR1);
    } else { //what to do when item gets OUT of detection

    }
}

void rise_isr2() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR2);
    } else { //what to do when item gets OUT of detection

    }
}

void fall_isr2() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR2);
    } else { //what to do when item gets OUT of detection

    }
}

void rise_isr3() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR3);
    } else { //what to do when item gets OUT of detection

    }
}

void fall_isr3() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR3);
    } else { //what to do when item gets OUT of detection

    }
}

void rise_isr4() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR4);
#if DEBUG
        myled = 0; //leds low active
        item_count += 1;
#endif
    } else { //what to do when item gets OUT of detection
#if DEBUG
        myled = 1; //leds low active
#endif
    }
}

void fall_isr4() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR4);
#if DEBUG
        myled = 0; //leds low active
        item_count += 1;
#endif
    } else { //what to do when item gets OUT of detection
#if DEBUG
        myled = 1; //leds low active
#endif
    }
}

void rise_isr5() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR5);
    } else { //what to do when item gets OUT of detection

    }
}

void fall_isr5() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR5);
    } else { //what to do when item gets OUT of detection

    }
}

void rise_isr6() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR6);
    } else { //what to do when item gets OUT of detection

    }
}

void fall_isr6() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR6);
    } else { //what to do when item gets OUT of detection

    }
}

void rise_isr7() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR7);
    } else { //what to do when item gets OUT of detection

    }
}

void fall_isr7() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR7);
    } else { //what to do when item gets OUT of detection

    }
}

void rise_isr8() {
    if (ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR8);
    } else { //what to do when item gets OUT of detection

    }
}

void fall_isr8() {
    if (!ITEM_PRESENT_HIGH) { //what to do when item gets IN detection
        detector_rx_queue.put((uint8_t *) DETECTOR8);
    } else { //what to do when item gets OUT of detection

    }
}
