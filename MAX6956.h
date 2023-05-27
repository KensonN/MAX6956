#ifndef MAX6956_H
#define MAX6956_H

#include <Arduino.h>

class MAX6956
{
  public:
    MAX6956(byte addr1, byte addr2, byte bright);
    void outputDigit(double number, int precision);
  private:
    void sendI2C(byte addr, byte reg, byte data);
    byte _addr1;
    byte _addr2;
    byte _bright;
    const byte digitCodes[10] = {0b11111010, 0b00110000, 0b11011001, 0b01111001, 0b00110011, 0b01101011, 0b11101011, 0b00111000, 0b11111011, 0b00111011}; //byte codes for each digit
    const byte digitCodes2[10] = {0b11010111, 0b10000001, 0b11001110, 0b11001011, 0b10011001, 0b01011011, 0b01011111, 0b11000001, 0b11011111, 0b11011001};
};
#endif
