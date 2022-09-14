#include <Wire.h>
#include <MAX6956.h>

#define MAX6956_1 0x40 //AD0 GND, AD1 GND
#define MAX6956_2 0x44 //AD0 GND, AD1 VCC
#define BRIGHTNESS 0xFF // Max brightness

const byte digitCodes[] = {0b11010111, 0b10000100, 0b11001011, 0b11001110, 0b10011100, 0b01011110, 0b01011111, 0b11000100, 0b11011111, 0b11011100}; //byte codes for each digit

MAX6956 max6956(MAX6956_1, MAX6956_2, BRIGHTNESS);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

int counter = 0;

void loop() {
  max6956.outputDigit((String)counter);
  counter++;
  delay(counter*counter);
}
