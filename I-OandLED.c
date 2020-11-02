/*
Embedded C Code to take input from P0 port and send it to either P1 or P3
depending upon he condition. Also P2 is declared as LED, which is intitially
at off position but goes to on position when message is sent to either of the 
port. Delay for P1 is 250ms and for P3 is 300ms
By-
Mishkat
*/
#include<reg51.h>
#define LED P2
void MSdelay(unsigned int)
void main(void)
{
	unsigned char mybyte;
	P0=0xFF;
	LED=0;
	while(1)
	{
		mybyte=P0;
		if(mybyte<100)
		{
			P1=mybyte;
		  LED=1;
		  MSdelay(250);
		}
		else
		{
			P3=mybyte;
			LED=1;
			MSdelay(300);
		}
	}
}
void MSdelay(unsigned int Time)
{
	unsigned int i,j;
	for(i=0;i<Time;i++)
	  for(j=0;j<1275;j++)
}		