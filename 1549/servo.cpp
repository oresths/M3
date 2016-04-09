/*
 * servo.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author:
 */
#include "servo.hpp"

static PwmOut *servoPWM;

static Serial *servo_uart;

static Queue<uint8_t, 19> servo_rx_queue;

void ServoInit(PinName tx, Serial* serial_obj) {
    servoPWM = new PwmOut(tx);
    servoPWM->period_ms(20);
    servoPWM->pulsewidth_us(1500);

    servo_uart = serial_obj;
    servo_uart->attach(&RX_isr, Serial::RxIrq);
}

void RX_isr() {
    uint8_t servo_recv = servo_uart->getc();
    servo_rx_queue.put((uint8_t *) servo_recv);
}

void ServoReceiverTask(void const *args) {
//    servoPWM->pulsewidth_us(1400);
    uint8_t direction = 0;
    while (true) {
        osEvent evt = servo_rx_queue.get();   //If queue empty, stops here and lets other threads run
        int recv_char = evt.value.v;    //Received character

        servo_uart->putc(recv_char); //TODO delete, only for debug purposes

        if (direction) {
            servoPWM->pulsewidth_us(1400);
            direction = 0;
        }
        else {
            servoPWM->pulsewidth_us(1550);
            direction = 1;
        }
    }
}
