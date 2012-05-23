#include <16F887.h>
#fuses INTRC_IO,NOWDT,NOLVP,MCLR,NOPROTECT,NOPUT
#use delay(clock=8000000)
#use fast_io(B)
#define RUEDA_DERECHA 0
#define RUEDA_IZQUIERDA 1
#define TIEMPO_RETRASO_LECTURA_MS 500
#define DURACION_MOVIMIENTO 1000

void apagarRueda(int, long);
void vueltaEnLIzquierda(long);
void vueltaEnLDerecha(long);
void vueltaAbiertaIzquierda(long);
void vueltaAbiertaDerecha(long);
void avanzarHaciaAdelante(long);
void avanzarHaciaAtras(long);

void main(void){
   int A0, A1, A2, A3;
   
   while(true){
   A0 = input(PIN_A0);
   A1 = input(PIN_A1);
   A2 = input(PIN_A2);
   A3 = input(PIN_A3);

   if(0 == A0 && 1 == A1 && 1 == A2 && 0 == A3){
      avanzarHaciaAdelante(DURACION_MOVIMIENTO);

   } else if(1 == A0 && 1 == A1 && 1 == A2 && 0 == A3){
      avanzarHaciaAdelante(DURACION_MOVIMIENTO);

   } else if(0 == A1) {
      vueltaEnLIzquierda(DURACION_MOVIMIENTO);

   } else if(0 == A2) {
      vueltaEnLDerecha(DURACION_MOVIMIENTO);

   } else {
      // De reversa mami
      avanzarHaciaAtras(DURACION_MOVIMIENTO);
   }
   delay_ms(TIEMPO_RETRASO_LECTURA_MS);
   }
}

void apagarRueda(int rueda, long tiempo){
   
   if(RUEDA_DERECHA == rueda){
      output_low(PIN_B2);
      output_low(PIN_B3);
      delay_ms(tiempo);
      output_high(PIN_B2);
      output_low(PIN_B3);
      
   } else {
      output_low(PIN_B0);
      output_low(PIN_B1);
      delay_ms(tiempo);
      output_high(PIN_B0);
      output_low(PIN_B1);
   }
}

void vueltaAbiertaIzquierda(long tiempo){
   output_high(PIN_B2);
   output_low(PIN_B3);
   apagarRueda(RUEDA_IZQUIERDA, tiempo);
}

void vueltaAbiertaDerecha(long tiempo){
   output_high(PIN_B0);
   output_low(PIN_B1);
   apagarRueda(RUEDA_DERECHA, tiempo);
}

void avanzarHaciaAdelante(long tiempo){
   output_high(PIN_B0);
   output_low(PIN_B1);
   output_high(PIN_B2);
   output_low(PIN_B3);
   delay_ms(tiempo);
}

void avanzarHaciaAtras(long tiempo){
   output_high(PIN_B1);
   output_low(PIN_B0);
   output_high(PIN_B3);
   output_low(PIN_B2);
   delay_ms(tiempo);
}

void vueltaEnLIzquierda(long tiempo){
   output_high(PIN_B2);
   output_low(PIN_B3);
   apagarRueda(RUEDA_IZQUIERDA, tiempo);
}

void vueltaEnLDerecha(long tiempo){
   output_high(PIN_B0);
   output_low(PIN_B1);
   apagarRueda(RUEDA_DERECHA, tiempo);
}

void correrRuedaReversa(int rueda, long tiempo){
   
   if(RUEDA_DERECHA == rueda){
      output_low(PIN_B2);
      output_high(PIN_B3);
      delay_ms(tiempo);
      output_high(PIN_B2);
      output_low(PIN_B3);
      
   } else {
      output_low(PIN_B0);
      output_high(PIN_B1);
      delay_ms(tiempo);
      output_high(PIN_B0);
      output_low(PIN_B1);
   }
}
