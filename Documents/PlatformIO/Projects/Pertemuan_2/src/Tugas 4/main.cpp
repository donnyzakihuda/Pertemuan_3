#include <Arduino.h>

const int potPin = 34;      
const int ledMerah = 25;    
const int ledKuning = 33;   
const int ledHijau = 32;    
const int buttonPin = 14;   

void setup() {
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  pinMode(buttonPin, INPUT_PULLDOWN);

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  } else {
    int rawADC = analogRead(potPin);

    if (rawADC < 1365) {
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, LOW);
    } else if (rawADC >= 1365 && rawADC < 2730) {
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledHijau, LOW);
    } else {
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, HIGH);
    }
  }

  delay(100);
}