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
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);
  if ( millis() - lastMillis1 > 5000){
    for(int8_t x=7; x>=-100; x--){
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("Hello World!");
      matrix.writeDisplay();
      delay(100);
    }
  lastMillis1 = millis();
  }
  if ( millis() - lastMillis2 > 1200){
    digitalWrite(17,HIGH);
    delay(100);
    digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(15,HIGH);
    delay(100);
    digitalWrite(12,HIGH);
    delay(300);
    
    // ปิด LED
    digitalWrite(17,LOW);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
    digitalWrite(15,LOW);
    delay(100);
    digitalWrite(12,LOW);
    delay(300);
    lastMillis2 = millis();
  }
}
