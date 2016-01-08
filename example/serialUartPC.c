#include "mbed.h"
// Teraterm configuration
// 9600 bauds, 8-bit data, no parity, 1 stop bit
//----------------------------------------------
Serial pc(SERIAL_TX, SERIAL_RX);
DigitalIn mybutton(USER_BUTTON);
DigitalOut myled(LED1);
int main()
{
	pc.printf("Hello HuyLe\n");
	if (mybutton == 0) {
		myled = 1;
		pc.printf("Welcome HuyLe\n");
	}else{
		pc.printf("Please PRESSED Button now\n");
		myled = 0;
	}
}
