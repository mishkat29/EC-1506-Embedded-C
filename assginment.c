#include<reg51.h>
void main(void)
  {
    TMOD= 0x20;                // Use Timer 1; 8 Bit Auto-reload
	  TH1= 0xEA;                 // For Baud Rate = 4800 ( XTAL= 40.00 MHz)
	  SCON= 0x50;
	  TR1= 1;
	  while(1)
	   {
	     SBUF= 'T';              // Place value in buffer
		   while(TI==0);
		   TI= 0;
	   }
   }