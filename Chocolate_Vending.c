/*
Embedded   Firmware   module   of   Automatic Chocolate Vending Machine to send message
“Insert Coin” to the serial port if switch SWin OFF
“Take Chocolate” to the serial port if switch SW is ON
Also,  turn  SW  to  OFF  state  after  a  delay  of  20  seconds  and  hence, change the message back to “Insert Coin”
8051 microcontroller with XTAL = 16 MHz
SW  is  connected  to  pin  1.1 which  switches  ON  after receiving the correct amount coin
Data is transmitted serially at baud rate of 4800 with 8 Bit Data and 1 stop Bit.
*/
#include<reg51.h>
sbit SW= P1^1;
void msDelay(void);
void main(void)
{
	unsigned char z;
	unsigned char x;
	unsigned char fmessage[] = "Insert Coin";
	unsigned char lmessage[] = "Take Chocolate";
	TMOD = 0x20;
	TH1 = 0xF7;
	SCON = 0x50;
	TR1 = 1;
	if(SW == 0)
	{
		for(z=0;z<11;z++)
		{
			SBUF = fmessage[z];
			while(TI==0);
			TI = 0;
		}
	}
	else
	{
		for(z=0;z<14;z++)
		{
			SBUF = lmessage[z];
			while(TI==0);
			TI = 0;
		}
	  for(x=0;x<800:x++)
		{
			msDelay();
		}
		SW=0;
		for(z=0;z<11;z++)
		{
			SBUF = fmessage[z];
			while(TI==0);
			TI = 0;
		}
	}
}
void msDelay(void)
{
	TMOD = 0x20;
	TL1 = 0xCB:
	TH1 = 0x7D;
	TR1 = 1;
	while(TF1==0);
	TR1 = 0;
	TF1 = 0;
}		