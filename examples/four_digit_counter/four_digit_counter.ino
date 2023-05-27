#include <Wire.h>
#include <MAX6956.h>

#define MAX6956_1 0x40 //AD0 GND, AD1 GND
#define MAX6956_2 0x44 //AD0 GND, AD1 VCC
#define BRIGHTNESS 0xFF // Max brightness

MAX6956 max6956(MAX6956_1, MAX6956_2, BRIGHTNESS);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

int counter = 0;

void loop() {
  max6956.outputDigit((String)counter);
  counter++;
  delay(1);
}
