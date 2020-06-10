// TTGO Test. This is a test script for a "TTGO" ESP32 Dev Board
// including an LCD module and a 18650 battery pack.
//
// There is an integrated LED on digital pin 16 - woohoo!!
//
// The built in OLED is a 128*64 mono pixel display
// i2c address = 0x3c
// SDA = 5
// SCL = 4
//
// I use the ThingPulse ESP8266 OLED library, found here:
// https://github.com/ThingPulse/esp8266-oled-ssd1306
//
// Please see the library for more detail on OLED commands
//
// Aidan Taylor
// March 2018
// Electric Noodle Box

#include "Arduino.h"
#include "SSD1306.h"

uint8_t ledPin = 16; // Onboard LED reference

SSD1306 display(0x3c, 5, 4); // instance for the OLED. Addr, SDA, SCL

// for fun:

uint16_t loopCount = 0; // Use to print how many times the program has looped
uint32_t progTime = 0;

void setup() {
    pinMode(ledPin, OUTPUT);

    Serial.begin(115200);

    display.init(); // initialise the OLED
    display.flipScreenVertically(); // does what is says
    display.setFont(ArialMT_Plain_24); // does what is says
    // Set the origin of text to top left
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
}

void loop() {
  // prints to the Serial Monitor - good to test for successful flash
  Serial.println("Hello World");

  // blink the LED a few times - LED is lit when LOW for me
  for(uint8_t n = 0; n < 5; n++) {
    digitalWrite(ledPin, LOW);
    delay(30);
    digitalWrite(ledPin, HIGH);
    delay(30);
  }

  // Upwards scroll OLED text
  for(uint8_t i = 0; i < 3; i++) {     for(int8_t n = 112; n > -72; n--) {
      display.drawString(63, n, "Electric");
      display.drawString(63, n+24, "Noodle");
      display.drawString(63, n+48, "Box");
      display.display();
      delay(10);
      display.clear();
    }
  }

  // Horizontal scroll OLED text, with pause in center
  for(uint8_t i = 0; i < 3; i++) {
    for(int16_t n = -127; n < 191; n++) {
      if(n == 63){
        display.drawString(n, 31, "Why, Hello!!");
        display.display();
        delay(2000);
        display.clear();
      }
      else {
        display.drawString(n, 31, "Why, Hello!!");
        display.display();
        delay(10);
        display.clear();
      }
    }
  }

  // Print progTime:
  progTime = millis()/1000;

  display.setFont(ArialMT_Plain_16); // make the font smaller
  display.drawString(63, 14, "Run time(S) =");
  display.setFont(ArialMT_Plain_24); // and bigger again
  display.drawString(63, 38, String(progTime));
  display.display();
  delay(2000);
  display.clear();
  display.display();

  // Print loopCount:
  display.setFont(ArialMT_Plain_16); // make the font smaller
  display.drawString(63, 14, "Loops =");
  display.setFont(ArialMT_Plain_24); // and bigger again
  display.drawString(63, 38, String(loopCount));
  display.display();
  delay(2000);
  display.clear();
  display.display();

  loopCount++; // iterate loopCount
}