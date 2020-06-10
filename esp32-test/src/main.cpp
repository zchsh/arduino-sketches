// Uses the ThingPulse ESP8266 OLED library:
// The built in OLED is a 128*64 mono pixel display
// https://github.com/ThingPulse/esp8266-oled-ssd1306

#include "Arduino.h"
#include "SSD1306.h"

uint8_t ledPin = 16; // Onboard LED reference
SSD1306 display(0x3c, 5, 4); // instance for the OLED. Addr, SDA, SCL

int pixel_x = 0;
int pixel_y = 0;
bool led_state = false;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
    display.init(); // initialise the OLED
   display.setColor(INVERSE);
}

void loop() {
    Serial.println("Hello, Noodles!");
    Serial.println(pixel_x);

    if (pixel_x % 20 == 0) {
      led_state = !led_state;
      // digitalWrite(ledPin, led_state);
    }

    

    // Draw a pixel at given position
    
    display.setPixel(pixel_x, pixel_y);
    display.display(); // display whatever is in the buffer
    pixel_x++;

    if (pixel_x == 129) {
      pixel_x = 0;
      pixel_y++;
    }

    if (pixel_y == 65) {
      pixel_x = 0;
      pixel_y = 0;
    }

    delay(1);
}