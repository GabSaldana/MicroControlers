#include <mega8535.h>
#include <delay.h>


const char tab7seg [10]={0x3F,0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};

#define S0 PORTB.0 
#define S1 PORTB.1 
#define S2 PORTB.2

#define E0 PINB.4 
#define E1 PINB.5 
#define E2 PINB.6

unsigned char con;

void main(void)
{

PORTA=0x00;
DDRA=0x00;
PORTD=0x00;
DDRD=0x00;

DDRC=0xFF;//salida hacia el DISPLAY
PORTC=0x00;

DDRB=0x0F;//mitad entrada/salida  TECLADO
PORTB=0xFF;//unos a la salida del teclado/con pull up a la entrada del teclado

TCCR0=0x00;
TCNT0=0x00;
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;
GIMSK=0x00;
MCUCR=0x00;
TIMSK=0x00;
ACSR=0x80;
ADCSR=0x00;
SPCR=0x00;

while (1)
      {   
               
        con=0;
        delay_ms(40);
        S0=0;//col 0
        S1=1;//col 1
        S2=1;//col 2
        
        if(E0 == 0 && E1 == 1 && E2 == 1)
            PORTC= tab7seg[1];
            //PORTC= ~tab7seg[1];
        if(E0 == 1 && E1 == 0 && E2 == 1)
            PORTC= tab7seg[2];
            //PORTC= ~tab7seg[2];
        if(E0 == 1 && E1 == 1 && E2 == 0)
            PORTC= tab7seg[3];
            //PORTC= ~tab7seg[3];
        if(E0 == 1 && E1 == 1 && E2 == 1)
            con++;
        delay_ms(40);
        
        
        con=0;
        delay_ms(40);
        S0=1;//col 0
        S1=0;//col 1
        S2=1;//col 2
        
        if(E0 == 0 && E1 == 1 && E2 == 1)
            PORTC= tab7seg[4];
            //PORTC= ~tab7seg[4];
        if(E0 == 1 && E1 == 0 && E2 == 1)
            PORTC= tab7seg[5];
            //PORTC= ~tab7seg[5];
        if(E0 == 1 && E1 == 1 && E2 == 0)
            PORTC= tab7seg[6];
            //PORTC= ~tab7seg[6];
        if(E0 == 1 && E1 == 1 && E2 == 1)
            con++;
        delay_ms(40);
        
        
        con=0;
        delay_ms(40);
        S0=1;//col 0
        S1=1;//col 1
        S2=0;//col 2
        
        if(E0 == 0 && E1 == 1 && E2 == 1)
            PORTC= tab7seg[7];
            //PORTC= ~tab7seg[7];
        if(E0 == 1 && E1 == 0 && E2 == 1)
            PORTC= tab7seg[8];
            //PORTC= ~tab7seg[8];
        if(E0 == 1 && E1 == 1 && E2 == 0)
            PORTC= tab7seg[9];
            //PORTC= ~tab7seg[9];
        if(E0 == 1 && E1 == 1 && E2 == 1)
            con++;
        delay_ms(40);                        
      }
}
