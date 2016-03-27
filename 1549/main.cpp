#include "mbed.h"
#include "rtos.h"

#include "servo.hpp"
#include "detector.hpp"

#include "USBSerial.h"


int main() {

    ServoInit(D5);

    DetectorInit(D3);

    Thread tServoCaller(ServoSchedulerTask);

    Thread tDetectorCaller(DetectorSchedulerTask);


    Thread::wait(osWaitForever);
}
