#ifndef FUNCIONES_C
#define FUNCIONES_C
#include <Arduino.h>
#include <EEPROM.h>
#include <stdint.h>
#define BAUDRATE 9600



#define BTN_UP    2   
#define BTN_DOWN  3   
//boton que cambia de minutos a segundos
#define BTN_MODE  4   
//boton que guarda en la epromt los numeros
#define BTN_SAVE  5   
#define LED_MIN   8
#define LED_SEG   9
#define MAXVAL 59
#define MINVAL 0


extern volatile uint8_t minutos;
extern volatile uint8_t segundos;
extern volatile bool canalMinutos;
extern volatile bool flagUp;
extern volatile bool flagDown;


void conf(void);
void isrUp(void);
void isrDown(void);
bool checkButtons(void);
void mostrarCanal(void);
void guardarEEPROM(void);
void leerEEPROM(void);

#endif
