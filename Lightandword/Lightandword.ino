#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();
unsigned long lastMillis1;
unsigned long lastMillis2;

void setup() {
  // put your setup code here, to run once:
  matrix.begin(0x70);
  pinMode(17, OUTPUT);    // Bluetooth
  pinMode(2, OUTPUT);     // Wifi
  pinMode(15, OUTPUT);    // NTP
  pinMode(12, OUTPUT);    // IoT
  lastMillis1 = millis();
  lastMillis2 = millis();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( millis() - lastMillis1 > 100 ){
    for(int8_t x=7; x>=-100; x--){
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("Hello World!");
      matrix.writeDisplay();
    }
  }
}
