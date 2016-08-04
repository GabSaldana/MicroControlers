#include <mega8535.h>
#include <delay.h>
unsigned char variable;
#define boton  PIND.0
bit btna;
bit btnp;
const char tabla7s [10]={0x3F,0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};
//CONTADOR 0-9 por flanco sin rebotes

void main(void)
{
//PORT es el valor con el que se cargan inicialmente los registros
//DDR es la configuracion E/S 
PORTA=0x00;
DDRA=0x00;
PORTB=0x00;
DDRB=0xFF;//salida
PORTC=0x00;
DDRC=0x00;
PORTD=0xFF;//todos con pull
DDRD=0x00;//entrada

TCCR0=0x00;TCNT0=0x00;TCCR1A=0x00;TCCR1B=0x00;TCNT1H=0x00;TCNT1L=0x00;
OCR1AH=0x00;OCR1AL=0x00;OCR1BH=0x00;OCR1BL=0x00;
ASSR=0x00;TCCR2=0x00;TCNT2=0x00;OCR2=0x00;
GIMSK=0x00;MCUCR=0x00;TIMSK=0x00;
ACSR=0x80;ADCSR=0x00;SPCR=0x00;

while (1)
      {
      if(boton==0)
            //pasamos de un uno logico a un cero
            btna=0;      
      else
            btna=1;
      if((btna==0)&&(btnp==1)){//detectamos un flanco de bajada que es cuando se aprieta el boton
         variable++;
         if(variable==10)
            variable=0;
         
         delay_ms(40);
      }    
      if((btnp==0)&&(btna==1))
        delay_ms(40);//para que se espere en lo que regresamos al estado inicial de 1 a esperar 0
      
      PORTB=tabla7s[variable];
      btnp=btna;
      }

     
}
