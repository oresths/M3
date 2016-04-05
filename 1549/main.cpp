#include "mbed.h"
#include "rtos.h"

#include "servo.hpp"
#include "hbridge.hpp"
#include "detector.hpp"

#include "USBSerial.h"


int main() {

    ServoInit(D2);

    HbridgeInit(D6, D7, D4, D3, D8, D9, D5); //AIN1, AIN2, PWMA, STBY, BIN1, BIN2, PWMB

    DetectorInit(A3);

    Thread tServoCaller(ServoSchedulerTask);

    Thread tHbridgeCaller(HbridgeSchedulerTask);

    Thread tDetectorCaller(DetectorSchedulerTask);


    Thread::wait(osWaitForever);
}
