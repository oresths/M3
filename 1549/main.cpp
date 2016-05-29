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

    DetectorInit(A0, A1, A2, A3, D10, D11, D12, D14, &pc); //D13 is connected with D5 ->
                                                     //-> first pin-arg prints debug info in terminal when DEBUG_D is enabled

    Thread tServoCaller(ServoReceiverTask);

    Thread tHbridgeCaller(HbridgeSchedulerTask);


    Thread::wait(osWaitForever);
}
