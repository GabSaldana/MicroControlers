/*RECEPTOR*/

#include <90s8535.h>
#include <delay.h>
#define entrada PINB.0
unsigned int i=0, cont=0;
unsigned char estado=0;
void main(void)

{
PORTD=0x00;//con ceros
DDRD=0xFF;//salida  SEGUNDOS
PORTB=0x00;//sin pull
DDRB=0x00;//entrada con pull 0->entrada 1->salida
PORTC=0x00;//con ceros
DDRC=0xFF;//no se usa

PORTA=0x00;//con ceros
DDRA=0x00;//no se usa
TCCR0=0x00;TCNT0=0x00;TCCR1A=0x00;TCCR1B=0x00;TCNT1H=0x00;TCNT1L=0x00;
OCR1AH=0x00;OCR1AL=0x00;OCR1BH=0x00;OCR1BL=0x00;
ASSR=0x00;TCCR2=0x00;TCNT2=0x00;OCR2=0x00;
GIMSK=0x00;MCUCR=0x00;TIMSK=0x00;
ACSR=0x80;ADCSR=0x00;SPCR=0x00;

   while(1){
        
      //Evitamos que giren en un inicio
      PORTD.0=0;
      PORTD.1=0;
      PORTD.2=0;
      PORTD.3=0;
      
      if(entrada == 1){
      
         estado=1;
         while(1){
                
             //etapa de conteo
             for(i=0;i<1000;i++){
             
                if(estado == 0 && entrada == 1){//flanco de subida
                     cont++;
                     estado=1;//estado =pasado  entrada=actual     
                }
                if(estado == 1 && entrada == 0){//no queremos contar flancos de bajada
                    etado=0;
                }
               
             }
            //etapa de comparación de ventana             
             if(cont > && cont<){//señal para M1I
                
                //I               
                PORTD.0 =0;
                PORTD.1=1;
             }
             
             if(cont > && cont<){//señal para M1D
                
                // D              
                PORTD.0 =1;
                PORTD.1=0;
             }
                  
             if(cont > && cont<){//señal para M2I
                
                //I               
                PORTD.2 =0;
                PORTD.3=1;
             }
             
             if(cont > && cont<){//señal para M2D
                
                // D              
                PORTD.2 =1;
                PORTD.3=0;
             }  
             
             delay_ms(500);
         }
      }     
      
   }
}