#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <EEPROM.h>

#define BTN_UP 2
#define BTN_DOWN 3
#define BTN_MODE 4
#define BTN_SAVE 5
#define LED_MIN 6
#define LED_SEG 7
#define EMINUTOS 0
#define ESegundos 1 
void inicializar();
void isrUp();
void isrDown();
void procesarBotones();
void actualizarFSM();
void guardarEEPROM();
void leerEEPROM();

extern volatile bool banderaUp;
extern volatile bool banderaDown;

#endif
