#include "mbed.h"
// Teraterm configuration
// 9600 bauds, 8-bit data, no parity, 1 stop bit
//----------------------------------------------
Serial pc(SERIAL_TX, SERIAL_RX);
DigitalIn mybutton(USER_BUTTON);
DigitalOut myled(LED1);
int hl='\0';
int main()
{
	pc.printf("Hello HuyLe\n");
	while(1){
		if (mybutton == 0) {
			myled = 1;
			pc.printf("Pressed button success\n");
			// send char a to consoler uart2
			pc.putc('a');
		}else{
			pc.printf("Please PRESSED Button now\n");
			myled = 0;
		}
		if(pc.readable()){
			pc.putc(pc.getc());
			if(hl=='a'){
				pc.printf("Send char a received from USB\n\r");
			}
			hl='\0';
		}
	}
}
