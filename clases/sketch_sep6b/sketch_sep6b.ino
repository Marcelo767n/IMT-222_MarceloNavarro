#include "funciones.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(BTN1)){
    subirVolumen();
  }
  if(!digitalRead(BTN2)){
    bajarVolumen();
  }
}
