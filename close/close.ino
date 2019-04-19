#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();

void setup() {
  // put your setup code here, to run once:
  matrix.begin(0x70);
  pinMode(17, OUTPUT);    // Bluetooth
  pinMode(2, OUTPUT);     // Wifi
  pinMode(15, OUTPUT);    // NTP
  pinMode(12, OUTPUT);    // IoT
}

void loop() {
  // put your main code here, to run repeatedly:
    matrix.setTextColor(LED_OFF);
    digitalWrite(17,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(15,HIGH);
    digitalWrite(12,HIGH);
}
