#include "mbed.h"
#include "rtos.h"

#include "servo.hpp"
#include "hbridge.hpp"
#include "detector.hpp"


int main() {
    Serial pc(USBTX, USBRX);
    pc.baud(115200);   //Baud 115200, 8N1

    ServoInit(D2, &pc);

    HbridgeInit(D6, D7, D4, D3, D8, D9, D5); //AIN1, AIN2, PWMA, STBY, BIN1, BIN2, PWMB

    DetectorInit(A3, &pc);

//    USBInit();

    Thread tServoCaller(ServoReceiverTask);

    Thread tHbridgeCaller(HbridgeSchedulerTask);


    Thread::wait(osWaitForever);
}
