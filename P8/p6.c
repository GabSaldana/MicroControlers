
  /*RUN-STOP-START*/
#include <90s8535.h>
#include <delay.h>
const char tabla7s [10]={0x3F,0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};
#define start  PINB.0
#define stop  PINB.1
#define reset  PINB.2

unsigned char mili;//d3
unsigned char deci;//d2
unsigned char seg;//d1

bit btna;
bit btnp;

void main(void)
{
 
PORTA=0x00;//con ceros
DDRA=0xFF;//salida  SEGUNDOS

PORTC=0x00;//con ceros
DDRC=0xFF;//salida DECI

PORTB=0xFF;//pull
DDRB=0x00;//entrada con pull
 
PORTD=0x00;//con ceros
DDRD=0xFF;//salida  MILI

TCCR0=0x00;TCNT0=0x00;TCCR1A=0x00;TCCR1B=0x00;TCNT1H=0x00;TCNT1L=0x00;
OCR1AH=0x00;OCR1AL=0x00;OCR1BH=0x00;OCR1BL=0x00;
ASSR=0x00;TCCR2=0x00;TCNT2=0x00;OCR2=0x00;
GIMSK=0x00;MCUCR=0x00;TIMSK=0x00;
ACSR=0x80;ADCSR=0x00;SPCR=0x00;

while (1)
      {
            if(start == 0)//detectamos el cero producido por el objeto que obstruye
                btna=0;      
            else
                btna=1;
            //detectamos el flanco de bajada producido
            while((btna == 0)){
                mili++;
                if(mili==10){
                    mili=0;
                    deci++;
                    if(deci==10){
                        deci=0;
                        seg++;
                        if(seg==6){
                            seg=0;
                        }
                    } 
                }
                delay_ms(40);
                
                if(start == 0)
                    continue;
                if(stop == 0)
                    break;
                if(reset == 0){
                
                    mili=0;
                    deci=0;
                    seg=0;
                }
                
                PORTD=~tabla7s[mili];
                PORTC=tabla7s[deci];
                PORTA=tabla7s[seg];    
            
            }   
      
      }
}
