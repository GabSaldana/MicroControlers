#include <mega8535.h>
#include <delay.h>
#define boton  PIND.0
//character types as numbers
unsigned char var;//unidades
unsigned char var2;//decenas
bit btna;
bit btnp;
const char tabla7s [10]={0x3F,0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};

void main(void)
{
 
PORTA=0x00;//con ceros
DDRA=0xFF;//salida
PORTC=0x00;//con ceros
DDRC=0xFF;//salida
PORTB=0x00;
DDRB=0x00;//no se usa 
PORTD=0x00;//con pull
DDRD=0x00;//entrada

TCCR0=0x00;TCNT0=0x00;TCCR1A=0x00;TCCR1B=0x00;TCNT1H=0x00;TCNT1L=0x00;
OCR1AH=0x00;OCR1AL=0x00;OCR1BH=0x00;OCR1BL=0x00;
ASSR=0x00;TCCR2=0x00;TCNT2=0x00;OCR2=0x00;
GIMSK=0x00;MCUCR=0x00;TIMSK=0x00;
ACSR=0x80;ADCSR=0x00;SPCR=0x00;

while (1)
      {
            if(boton==0)//detectamos el cero producido por el objeto que obstruye
                btna=0;      
            else
                btna=1;
            //detectamos el flanco de bajada producido
            if((btnp==0)&&(btna==1)){
                var++;
                if(var==10){
                    var=0;
                    var2++;
                    if(var2==10){
                        var2=0;
                    } 
                }
                delay_ms(40);
            }
            //detectamos el flanco de subida y esperamos a que se regularice
            if((btnp==1)&&(btna==0))
                delay_ms(40);
      
            PORTC=tabla7s[var];
            PORTA=tabla7s[var2];
            btnp=btna; //cambio de estado   

      }
      
}
