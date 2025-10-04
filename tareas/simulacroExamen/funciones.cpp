#include "funciones.h"

// ---------------- Variables globales ----------------
volatile bool banderaUp = false;
volatile bool banderaDown = false;

unsigned long ultimoReboteUp   = 0;
unsigned long ultimoReboteDown = 0;
unsigned long ultimoReboteMode = 0;
unsigned long ultimoReboteSave = 0;

unsigned int minutos = 0;
unsigned int segundos = 0;
bool modoMin = true; // true = MIN, false = SEG

// ---------------- Inicialización ----------------
void inicializar() {
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_SAVE, INPUT_PULLUP);

  pinMode(LED_MIN, OUTPUT);
  pinMode(LED_SEG, OUTPUT);

  // ISR para UP y DOWN
  attachInterrupt(digitalPinToInterrupt(BTN_UP), isrUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN_DOWN), isrDown, FALLING);

  leerEEPROM();

  digitalWrite(LED_MIN, HIGH); // inicia en minutos por defecto
  digitalWrite(LED_SEG, LOW);

  Serial.begin(9600);
  Serial.println("Sistema Iniciado");
}

// ---------------- Interrupciones ----------------
void isrUp() {       // Ojo: tu función se llamaba isrUP (mayúsculas) → corregido
  banderaUp = true;
}

void isrDown() {     // Ojo: estaba mal escrito como "isDown" → corregido
  banderaDown = true;
}

// ---------------- Procesar Botones ----------------
void procesarBotones() {
  unsigned long ahora = millis();

  // --- Botón UP ---
  if (banderaUp && (ahora - ultimoReboteUp > 1000)) {  // debounce 50 ms
    banderaUp = false;
    ultimoReboteUp = ahora;

    if (modoMin) {
      minutos = (minutos + 1) % 60;
    } else {
      segundos = (segundos + 1) % 60;
    }

    // Mostrar valores cada vez que se incrementa
    Serial.print("MIN: ");
    Serial.print(minutos);
    Serial.print(" SEG: ");
    Serial.println(segundos);
  }

  // --- Botón DOWN ---
  if (banderaDown && (ahora - ultimoReboteDown > 1000)) {
    banderaDown = false;
    ultimoReboteDown = ahora;

    if (modoMin) {
      minutos = (minutos - 1 + 60) % 60;
    } else {
      segundos = (segundos - 1 + 60) % 60;
    }

    // Mostrar valores cada vez que se decrementa
    Serial.print("MIN: ");
    Serial.print(minutos);
    Serial.print(" SEG: ");
    Serial.println(segundos);
  }

  // --- Botón MODE ---
  if (!digitalRead(BTN_MODE) && (ahora - ultimoReboteMode > 200)) {
    ultimoReboteMode = ahora;
    modoMin = !modoMin;  

    digitalWrite(LED_MIN, modoMin ? HIGH : LOW);
    digitalWrite(LED_SEG, modoMin ? LOW : HIGH);

    Serial.println(modoMin ? "Editando MINUTOS" : "Editando SEGUNDOS");
  }

  // --- Botón SAVE ---
  if (!digitalRead(BTN_SAVE) && (ahora - ultimoReboteSave > 200)) {
    ultimoReboteSave = ahora;
    guardarEEPROM();

    Serial.print("Guardado -> MIN: ");
    Serial.print(minutos);
    Serial.print(" SEG: ");
    Serial.println(segundos);
  }
}


// ---------------- FSM ----------------
//void actualizarFSM() {
  // aquí se podría expandir con estados adicionales
  // por ahora, solo refleja el valor por Serial
  //static unsigned long ultimoPrint = 0;

  //if (millis() - ultimoPrint > 1000) {
    //ultimoPrint = millis();
    //Serial.print("MIN: ");
    //Serial.print(minutos);
    //Serial.print(" SEG: ");
    //Serial.println(segundos);
  //}
//}

// ---------------- EEPROM ----------------
void guardarEEPROM() {
  EEPROM.update(EMINUTOS, minutos);   // Usamos update para no desgastar EEPROM
  EEPROM.update(ESEGUNDOS, segundos);
}

void leerEEPROM() {
  minutos  = EEPROM.read(EMINUTOS);
  segundos = EEPROM.read(ESEGUNDOS);

  // Validación de rangos
  if (minutos > 59)  minutos = 0;
  if (segundos > 59) segundos = 0;
}
