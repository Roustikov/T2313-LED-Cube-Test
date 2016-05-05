/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 07.10.2014
Author  : MakZ
Company : 
Comments: 


Chip type               : ATtiny2313A
AVR Core Clock frequency: 8,000000 MHz
Memory model            : Tiny
External RAM size       : 0
Data Stack size         : 32
*****************************************************/

#include <tiny2313a.h>
#include <delay.h>

#define LATCH1_EN PORTD.5
#define LATCH2_EN PORTD.4
#define LATCH3_EN PORTD.3

#define BUS1 PORTB.0
#define BUS2 PORTB.1
#define BUS3 PORTB.2
#define BUS4 PORTB.3
#define BUS5 PORTB.4

// Declare your global variables here
int array1[] = {1,1,1,1,1};
int array2[] = {1,1,1,1,1};
int array3[] = {1,1,1,1,1};
int i = 0;

void setPins(int array[], int latch)
{
if(latch == 1)
LATCH1_EN = 1;
if(latch == 2)
LATCH2_EN = 1;
if(latch == 3)
LATCH3_EN = 1;

    BUS1 = array[0];
    BUS2 = array[1];
    BUS3 = array[2];
    BUS4 = array[3];
    BUS5 = array[4];
    
if(latch == 1)
LATCH1_EN = 0;
if(latch == 2)
LATCH2_EN = 0;
if(latch == 3)
LATCH3_EN = 0;
}

void main(void)
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

DDRB=0xFF;
DDRD=0xFF;

LATCH1_EN = 0;
LATCH2_EN = 0;
LATCH3_EN = 0;
                   
BUS1 = 0;
BUS2 = 0;
BUS3 = 0;
BUS4 = 0;
BUS5 = 0;

    while(1)
    {    
    int delay = 25;  
        for(i = 4; i >= 0; i--)
        {
            array1[i]=!array1[i];
            setPins(array1, 1);
            
            delay_ms(delay);
        }
         
        for(i = 4; i >= 0; i--)
        {
            array2[i]=!array2[i];
            setPins(array2, 2);
            
            delay_ms(delay);   
        }   
        
        for(i = 4; i >= 0; i--)
        {                
            array3[i]=!array3[i];
            setPins(array3, 3);
            
            delay_ms(delay);
        }
    }    
}
