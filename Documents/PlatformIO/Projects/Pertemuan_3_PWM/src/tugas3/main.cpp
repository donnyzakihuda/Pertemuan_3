#include <Arduino.h>

const int potPin = 16;
const int servoPin = 16;
const int freq = 50;
const int channel = 0;
const int res = 12;


void setup() {
  // Inisialisasi aktuator PWM di sini
  Serial.begin(115200);
  ledcSetup(channel, freq, res);
  ledcAttachPin(servoPin, channel);
}

void loop() {
  int potValue = analogRead(potPin); // Hasil: 0 - 4095
  int pwmValue = map(potValue, 0, 4095, 0, 255); // Konversi ke 0 - 255
  
  // ledcWrite(channel, pwmValue);
  Serial.print("Potensiometers value: ");
  Serial.print(potValue);
  delay(15);

  ledcWrite(pwmValue, 102); // Posisi ~0 derajat
  delay(1000);
}