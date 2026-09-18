#include <Arduino.h>

const int servoPin = 16;
const int potPin = 17;
const int freq = 50;
const int channel = 0;
const int res = 12;

void setup() {
  Serial.begin(9600);
  ledcSetup(channel, freq, res);
  ledcAttachPin(servoPin, channel);
}

void loop() {
  int potValue = analogRead(potPin); // Hasil: 0 - 4095
  int pwmValue = map(potValue, 0, 4095, 0, 255); // Konversi ke 0 - 255
  
  // ledcWrite(channel, pwmValue);
  delay(15);

  ledcWrite(channel, pwmValue); // Posisi ~0 derajat
  delay(1000);

  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);

}