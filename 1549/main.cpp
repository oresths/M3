#include "mbed.h"
#include "USBSerial.h"
#include "rtos.h"

DigitalOut myled(LED1);

int main() {
    while(1) {
        printf("Hello World!\r\n");
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}
