 /*
 By- Mishkat
 60-Hz external clock is being fed into pin TO (P3.4). 
 program for counter 0 in mode 2 (8-Bit Auto-reload) to display the seconds and minutes on PI and P2, respectively.
 */
 #include<reg51.h>
 void secmin(unsigned char);
 void main()
 {
	 unsigned char val;
	 T0=1;
	 TMOD=0x06;
	 TH0=-60;
	 while(true)
	 {
		 do
		 {
	           TR0=1;
		   val=TL0;
		   ecmin(val);
		 }
		 while(TF0==0);
		 TR0=0;
		 TF0=0;
	 }
 }
 void secmin(unsigned char val)
 {
    unsigned char sec, min;
    min= val/60;
    sec= val%60;
    P1=sec;
    P2=min;
 }
