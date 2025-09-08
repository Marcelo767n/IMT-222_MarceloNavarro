#include "funciones.h"
external uint8_t vol;
void conf(void){
  Serial.begin(BAUDRATE);
  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  vol== EEPROM.read(PRIMERACELDA);
  if(vol>VMAX){
    EEPROM.write(PRIMERACELDA, 5) //5 es un volumen medio volumen arranca en 5 

  }
}

void subirVolumen(){
  if(vol<VMAX){
    vol++;
  }
}
void bajarVolumen(){
  if(vol>VMIN){
    vol--;
  }
delay(20); //el delay es un retardante bloqueante, la placa no hace nada 
}