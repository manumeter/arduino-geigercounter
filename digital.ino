#include <SPI.h>

volatile unsigned long count = 0;

void increment() {
  count++;
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(0, increment, FALLING);
}

void loop() {
  delay(60000);
  Serial.println(count);
  count = 0;
}

