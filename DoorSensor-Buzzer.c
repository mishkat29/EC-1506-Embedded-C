/*
Door sensor is connected to the Port 1 pin 0 while the Buzzer is connceted
to Port 1 pin 7. Upon getting an on signal from Door ssensor the buzzer goes
from Off state to On for some dealy in both state.
*/
#include<reg51.h>
void MSdelay(unsigned int);
sbit Dsensor=P1^1;
sbit Buzzer=P1^7;
void main(void)
{
	Dsensor=1;
	while(Dsensor==1)
	{
		Buzzer=0;
		MSdelay(200);
		Buzzer=1;
		MSdelay(200);
	}
}
void MSdelay(unsigned int dtime)
{
	unsigned int i,j;
	for(i=0;i<dtime;i++)
	  for(j=0;j<1275;j++);
}	
