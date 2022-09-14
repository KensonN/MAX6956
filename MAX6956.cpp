#include "Arduino.h"
#include "MAX6956.h"
#include <Wire.h>

MAX6956::MAX6956(byte addr1, byte addr2, byte bright)
  : _addr1(addr1), _addr2(addr2), _bright(bright)
{
  Wire.begin();
  sendI2C(_addr1, 0x0B, 0x00); // configuring all ports for led output
  sendI2C(_addr1, 0x0C, 0x00);
  sendI2C(_addr1, 0x0D, 0x00);
  sendI2C(_addr1, 0x0E, 0x00);
  sendI2C(_addr1, 0x0F, 0x00);
  sendI2C(_addr1, 0x07, 0x00); //turn off test mode
  sendI2C(_addr1, 0x04, 0x01); //required for normal operation
  sendI2C(_addr1, 0x02, _bright); 
  
  sendI2C(_addr2, 0x0B, 0x00); // configuring all ports for led output
  sendI2C(_addr2, 0x0C, 0x00);
  sendI2C(_addr2, 0x0D, 0x00);
  sendI2C(_addr2, 0x0E, 0x00);
  sendI2C(_addr2, 0x0F, 0x00);
  sendI2C(_addr2, 0x07, 0x00); //turn off test mode
  sendI2C(_addr2, 0x04, 0x01); //required for normal operation
  sendI2C(_addr2, 0x02, _bright);     
}

void MAX6956::outputDigit(String number)
{
  byte digitBytes[4] = {0x00, 0x00, 0x00, 0x00};
  short digitCount = 4;
  bool sameDigit = false;
  for (short i = number.length()-1; i >= 0; i--) {
    !sameDigit ? digitCount-- : sameDigit = false;
    if (number[i]-'0' >= 0 && number[i]-'0' <= 9) {
      digitBytes[digitCount] |= digitCodes[number[i]-'0'];
    }
    else if (number[i] == '.') {
      digitBytes[digitCount] |= (0b1 << 5);
      sameDigit = true;
    }
  }
  // 0x56 is address for ports 22-29
  // 0x4E is address for ports 14-22
  sendI2C(_addr1, 0x4E, digitBytes[0]); //ports 
  sendI2C(_addr1, 0x56, digitBytes[1]);
  sendI2C(_addr2, 0x4E, digitBytes[2]);
  sendI2C(_addr2, 0x56, digitBytes[3]);
}

void MAX6956::sendI2C(byte addr, byte reg, byte data) {
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}
