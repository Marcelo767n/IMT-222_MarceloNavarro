//definimos los pines con las macros 
#define NUM_LEDS   15       
#define INTERVALO  500       
#define LED1   2
#define LED2   3
#define LED3   4
#define LED4   5
#define LED5   6
#define LED6   7
#define LED7   8
#define LED8   9
#define LED9   10
#define LED10  11
#define LED11  12
#define LED12  13
#define LED13  A0
#define LED14  A1
#define LED15  A2

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  pinMode(LED13, OUTPUT);
  pinMode(LED14, OUTPUT);
  pinMode(LED15, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH); delay(INTERVALO);
  digitalWrite(LED2, HIGH); delay(INTERVALO);
  digitalWrite(LED3, HIGH); delay(INTERVALO);
  digitalWrite(LED4, HIGH); delay(INTERVALO);
  digitalWrite(LED5, HIGH); delay(INTERVALO);
  digitalWrite(LED6, HIGH); delay(INTERVALO);
  digitalWrite(LED7, HIGH); delay(INTERVALO);
  digitalWrite(LED8, HIGH); delay(INTERVALO);
  digitalWrite(LED9, HIGH); delay(INTERVALO);
  digitalWrite(LED10, HIGH); delay(INTERVALO);
  digitalWrite(LED11, HIGH); delay(INTERVALO);
  digitalWrite(LED12, HIGH); delay(INTERVALO);
  digitalWrite(LED13, HIGH); delay(INTERVALO);
  digitalWrite(LED14, HIGH); delay(INTERVALO);
  digitalWrite(LED15, HIGH); delay(INTERVALO);
}
