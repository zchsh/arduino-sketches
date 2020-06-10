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

uint8_t ledPin = 16; // Onboard LED reference

void setup() {
    pinMode(ledPin, OUTPUT);
    
    Serial.begin(115200);
}

void loop() {
    Serial.println("Hello, Noodles!");

    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
}