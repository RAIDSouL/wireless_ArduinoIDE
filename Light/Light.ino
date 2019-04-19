#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();

void setup() {
  // ตั้งค่าสถานะพิน ให้เป็นโหมดส่งออก หมายเลขพิน ไม่ต้องใส่ IO 
  // เช่น IO17 ก็ใส่หมายเลข 17 ไปเลย
  matrix.begin(0x70);
  pinMode(17, OUTPUT);    // Bluetooth
  pinMode(2, OUTPUT);     // Wifi
  pinMode(15, OUTPUT);    // NTP
  pinMode(12, OUTPUT);    // IoT
}

void loop() {
  // เปิด LED
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);

  for (int8_t x=7; x>=-100; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello World!");
    matrix.writeDisplay();
    delay(100);
  }
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
}
