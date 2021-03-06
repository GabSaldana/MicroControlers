#include <mega8535.h>
unsigned char variable;
unsigned char variable1;
  
const char tabla7s [10]={0x3F,0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};
//BCD - 7segmentos
void main(void)
{
//PORT es el valor con el que se cargan inicialmente los registros
//DDR es la configuracion E/S 
PORTA=0xFF;
DDRA=0xFF;//salida
PORTB=0x00;
DDRB=0xFF;//salida
 
PORTC=0x0F;//la mitad con valor P por default
DDRC=0x00;//entrada

PORTD=0x0F;
DDRD=0x00;//entrada

TCCR0=0x00;TCNT0=0x00;TCCR1A=0x00;TCCR1B=0x00;TCNT1H=0x00;TCNT1L=0x00;
OCR1AH=0x00;OCR1AL=0x00;OCR1BH=0x00;OCR1BL=0x00;
ASSR=0x00;TCCR2=0x00;TCNT2=0x00;OCR2=0x00;
GIMSK=0x00;MCUCR=0x00;TIMSK=0x00;
ACSR=0x80;ADCSR=0x00;SPCR=0x00;

while (1)
      {
        variable=PIND&0x0f;//dejamos pasar solo los 4 bits menos significativos
        variable1=PINC&0x0f; 
        
        if(variable<10){//si lo que leemos esta del 0-9 lomostramos
            PORTB=tabla7s[variable]; //CATODO    
        }
        if(variable>=10){
            PORTB=0x79;//si no mostramos error E
        }  
        if(variable1<10){//si lo que leemos esta del 0-9 lomostra
            PORTA=~tabla7s[variable1];    //ANODO 
        }
        if(variable1>=10){
            PORTA=~(0x79);
        }
        
    }
}
