#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <Arduino.h>
#include <EEPROM.h>
#define BTN1 5
#define BTN2 7
#define BAUDRATE 115200
#define VMIN 0
#define VMAX 10
#define PRIMERACELDA 0
uint8_t vol = 0;
void conf(void);
void subirVolumen();
void bajarVolumen();
#endif
