#include "funciones.h"

void setup() {
  conf();   
}

void loop() {
  if (checkButtons()) {   
    mostrarCanal();
  }
  delay(10); 
}
