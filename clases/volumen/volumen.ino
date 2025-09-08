#include "funciones.h"

void setup() {
  // put your setup code here, to run once:
  conf();
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(vol);
  if(!digitalRead(BTNUP)){
    subir();
  }
  if(!digitalRead(BTNDOWN)){
    bajar();
  }
  delay(20);
}
