#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

const char* ssid     = "Thunderock";
const char* password = "65544384";

WiFiServer server(80);

void setup() {
  // ตั้งค่าสถานะพิน ให้เป็นโหมดส่งออก หมายเลขพิน ไม่ต้องใส่ IO 
  // เช่น IO17 ก็ใส่หมายเลข 17 ไปเลย
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
//  
  pinMode(17, OUTPUT);    // Bluetooth
//  pinMode(2, OUTPUT);     // Wifi
  pinMode(15, OUTPUT);    // NTP
//  pinMode(12, OUTPUT);    // IoT
}

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
 
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
 
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
 
            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/12H\">here</a> to turn the LED on pin Bluetooth on.<br>");
            client.print("Click <a href=\"/12L\">here</a> to turn the LED on pin Bluetooth off.<br>");
            client.print("<br>");
            
            client.print("Click <a href=\"/15H\">here</a> to turn the LED on pin NTP on.<br>");
            client.print("Click <a href=\"/15L\">here</a> to turn the LED on pin NTP off.<br>");
            client.print("<br>");
 
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
 
        // Check to see if the client request was "GET /xH" or "GET /xL":
        if (currentLine.endsWith("GET /12L")) {
          digitalWrite(17, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /12H")) {
          digitalWrite(17, LOW);                // GET /L turns the LED off
        }
 
        if (currentLine.endsWith("GET /15L")) {
          digitalWrite(15, HIGH);               // GET /H turns the LED on
        }
 
        if (currentLine.endsWith("GET /15H")) {
          digitalWrite(15, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
//  // เปิด LED
//  digitalWrite(17,HIGH);
//  delay(100);
//  digitalWrite(2,HIGH);
//  delay(100);
//  digitalWrite(15,HIGH);
//  delay(100);
//  digitalWrite(12,HIGH);
//  delay(300);
//  
//  // ปิด LED
//  digitalWrite(17,LOW);
//  delay(100);
//  digitalWrite(2,LOW);
//  delay(100);
//  digitalWrite(15,LOW);
//  delay(100);
//  digitalWrite(12,LOW);
//  delay(300);
}
