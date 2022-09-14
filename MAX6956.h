#ifndef MAX6956_H
#define MAX6956_H

#include <Arduino.h>

class MAX6956
{
  public:
    MAX6956(byte addr1, byte addr2, byte bright);
    void outputDigit(String number);
  private:
    void sendI2C(byte addr, byte reg, byte data);
    byte _addr1;
    byte _addr2;
    byte _bright;
    const byte digitCodes[10] = {0b11010111, 0b10000100, 0b11001011, 0b11001110, 0b10011100, 0b01011110, 0b01011111, 0b11000100, 0b11011111, 0b11011100}; //byte codes for each digit
};

#endif
