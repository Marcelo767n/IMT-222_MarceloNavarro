#include "funciones.h"

// ================== Variables globales ==================
volatile uint8_t minutos = 0;
volatile uint8_t segundos = 0;
volatile bool canalMinutos = true;

volatile bool flagUp = false;
volatile bool flagDown = false;

static unsigned long lastUpMillis = 0;
static unsigned long lastDownMillis = 0;
static unsigned long lastModeMillis = 0;
static unsigned long lastSaveMillis = 0;
const unsigned long DEBOUNCE_MS = 50;

void conf(void) {
  Serial.begin(BAUDRATE);

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_SAVE, INPUT_PULLUP);

  pinMode(LED_MIN, OUTPUT);
  pinMode(LED_SEG, OUTPUT);

  digitalWrite(LED_MIN, LOW);
  digitalWrite(LED_SEG, LOW);

 
  attachInterrupt(digitalPinToInterrupt(BTN_UP), isrUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN_DOWN), isrDown, FALLING);

  leerEEPROM(); 
}

void isrUp()   { flagUp = true; }
void isrDown() { flagDown = true; }

bool checkButtons(void) {
  bool changed = false;
  unsigned long now = millis();

  if (flagUp) {
    flagUp = false;
    if (now - lastUpMillis > DEBOUNCE_MS) {
      lastUpMillis = now;
      if (canalMinutos) {
        minutos = (minutos + 1) % 60;   
      } else {
        segundos = (segundos + 1) % 60;
      }
      changed = true;
    }
  }


  if (flagDown) {
    flagDown = false;
    if (now - lastDownMillis > DEBOUNCE_MS) {
      lastDownMillis = now;
      if (canalMinutos) {
        minutos = (minutos == 0) ? 59 : minutos - 1;
      } else {
        segundos = (segundos == 0) ? 59 : segundos - 1;
      }
      changed = true;
    }
  }

  
  if (digitalRead(BTN_MODE) == LOW) {
    if (now - lastModeMillis > DEBOUNCE_MS) {
      lastModeMillis = now;
      canalMinutos = !canalMinutos;
      changed = true;
      while (digitalRead(BTN_MODE) == LOW) { delay(5); } 
      lastModeMillis = millis();
    }
  }

  if (digitalRead(BTN_SAVE) == LOW) {
    if (now - lastSaveMillis > DEBOUNCE_MS) {
      lastSaveMillis = now;
      guardarEEPROM();
      changed = true;
      while (digitalRead(BTN_SAVE) == LOW) { delay(5); } 
      lastSaveMillis = millis();
    }
  }

  return changed;
}


void mostrarCanal(void) {
  if (canalMinutos) {
    digitalWrite(LED_MIN, HIGH);
    digitalWrite(LED_SEG, LOW);
  } else {
    digitalWrite(LED_MIN, LOW);
    digitalWrite(LED_SEG, HIGH);
  }

  Serial.print("Minutos: ");
  Serial.print(minutos);
  Serial.print(" | Segundos: ");
  Serial.println(segundos);
}


void guardarEEPROM(void) {
  if (EEPROM.read(0) != minutos) EEPROM.write(0, minutos);
  if (EEPROM.read(1) != segundos) EEPROM.write(1, segundos);

  Serial.println("Guardado en EEPROM.");


  for (uint8_t i = 0; i < 2; i++) {
    digitalWrite(LED_MIN, HIGH);
    digitalWrite(LED_SEG, HIGH);
    delay(120);
    digitalWrite(LED_MIN, LOW);
    digitalWrite(LED_SEG, LOW);
    delay(120);
  }
}

void leerEEPROM(void) {
  uint8_t m = EEPROM.read(0);
  uint8_t s = EEPROM.read(1);

  if (m <= MAXVAL && s <= MAXVAL) {
    minutos = m;
    segundos = s;
  } else {
    minutos = 0;
    segundos = 0;
  }
}