#include <mega8535.h>
#include <delay.h>

#define INT4 PIND.5
#define INT3 PIND.6
#define INT1 PINC.0
#define INT2 PINC.1

#define OUT PINB.0

bit ESTADO_LED1;
bit ESTADO_LED2;
bit ESTADO_LED3;
bit ESTADO_LED4;

void main(void)
{
PORTA=0x00;
DDRA=0x00; 
PORTB=0x00;
DDRB=0xFF;//salida
PORTC=0xFF;
DDRC=0x00;//entrada
PORTD=0xFF;
DDRD=0x00;//entrada

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
            //REVISANDO SI ALGUN BOTOTN FUE PRESIONADO
            if(INT1 == 0){
                ESTADO_LED1=1;//fue presionado
            }else{
                ESTADO_LED1=0;
            }  
            
            if(INT2 == 0){
                ESTADO_LED2=1;//fue presionado
            }else{
                ESTADO_LED2=0;
            }
            
            if(INT3 == 0){
                ESTADO_LED3=1;//fue presionado
            }else{
                ESTADO_LED3=0;
            }              
            
            if(INT4 == 0){
                ESTADO_LED4=1;//fue presionado
            }else{
                ESTADO_LED4=0;
            }
            
            //CONTROL DE SE�ALES
            
            if(ESTADO_LED1 == 1){ //4 ms total
                  OUT=1;
                  delay_ms(2);
                  OUT=0;
                  delay_ms(2);
            }
            else if(ESTADO_LED2 == 1){ //8 ms
                  OUT=1;
                  delay_ms(4);
                  OUT=0;
                  delay_ms(4);
            }
            else if(ESTADO_LED3 == 1){//16 ms
                  OUT=1;
                  delay_ms(8);
                  OUT=0;
                  delay_ms(8);
            }
            else if(ESTADO_LED4 == 1){// 32 ms
                  OUT=1;
                  delay_ms(16);
                  OUT=0;
                  delay_ms(16);
            }
            else{
                OUT =0;
            }

      }
}
