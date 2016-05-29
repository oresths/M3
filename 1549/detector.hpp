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

#define ITEM_PRESENT_HIGH 0  //1 for high active detection pulse

#define DEBUG_D 0

#define DETECTOR1 '1'
#define DETECTOR2 '2'
#define DETECTOR3 '3'
#define DETECTOR4 '4'
#define DETECTOR5 '5'
#define DETECTOR6 '6'
#define DETECTOR7 '7'
#define DETECTOR8 '8'


void DetectorInit(PinName rx1, PinName rx2, PinName rx3, PinName rx4, PinName rx5, PinName rx6, PinName rx7,
        PinName rx8, Serial* serial_obj);

void DetectorTask(void const *args);

void rise_isr1();
void fall_isr1();
void rise_isr2();
void fall_isr2();
void rise_isr3();
void fall_isr3();
void rise_isr4();
void fall_isr4();
void rise_isr5();
void fall_isr5();
void rise_isr6();
void fall_isr6();
void rise_isr7();
void fall_isr7();
void rise_isr8();
void fall_isr8();


#endif /* DETECTOR_HPP_ */
