#include <avr/pgmspace.h>
#include <stdlib.h>

#include <Wire.h>

#include "SSD1306_I2C_128x64.h"


SSD1306_I2C_128x64::SSD1306_I2C_128x64(uint8_t p)
{
    pin = p;
}

void SSD1306_I2C_128x64::begin(uint8_t switchvcc)
{
    Wire.begin();

    // Setup reset pin direction (used by both SPI and I2C)
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    // VDD (3.3V) goes high at start, lets just chill for a ms
    delay(1);
    // bring reset low
    digitalWrite(pin, LOW);
    // wait 10ms
    delay(10);
    // bring out of reset
    digitalWrite(pin, HIGH);
    // turn on VCC (9V?)

    sendCommand(SSD1306_DISPLAYOFF);                    // 0xAE
//    sendCommand(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
//    sendCommand(0x80);                                  // the suggested ratio 0x80
//    sendCommand(SSD1306_SETMULTIPLEX);                  // 0xA8
//    sendCommand(0x3F);
//    sendCommand(SSD1306_SETDISPLAYOFFSET);              // 0xD3
//    sendCommand(0x0);                                   // no offset
//    sendCommand(SSD1306_SETSTARTLINE | 0x0);            // line #0
//    sendCommand(SSD1306_CHARGEPUMP);                    // 0x8D
//    if (switchvcc == SSD1306_EXTERNALVCC)
//      { sendCommand(0x10); }
//    else
//      { sendCommand(0x14); }
//    sendCommand(SSD1306_MEMORYMODE);                    // 0x20
//    sendCommand(0x00);                                  // 0x0 act like ks0108
//    sendCommand(SSD1306_SEGREMAP | 0x1);
//    sendCommand(SSD1306_COMSCANDEC);
//    sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
//    sendCommand(0x12);
//    sendCommand(SSD1306_SETCONTRAST);                   // 0x81
//    if (switchvcc == SSD1306_EXTERNALVCC)
//      { sendCommand(0x9F); }
//    else
//      { sendCommand(0xCF); }
//    sendCommand(SSD1306_SETPRECHARGE);                  // 0xd9
//    if (switchvcc == SSD1306_EXTERNALVCC)
//      { sendCommand(0x22); }
//    else
//      { sendCommand(0xF1); }
//    sendCommand(SSD1306_SETVCOMDETECT);                 // 0xDB
//    sendCommand(0x40);
//    sendCommand(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
//    sendCommand(SSD1306_NORMALDISPLAY);
    sendCommand(SSD1306_SETLOWCOLUMN | 0x00);
    sendCommand(SSD1306_SETHIGHCOLUMN | 0x0);
    sendCommand(SSD1306_SETSTARTLINE | 0x0);
    sendCommand(SSD1306_SETCONTRAST);
    sendCommand(0x80);
    sendCommand(0xa1);
    sendCommand(SSD1306_NORMALDISPLAY);
//    sendCommand(SSD1306_INVERTDISPLAY);
    sendCommand(SSD1306_DISPLAYALLON_RESUME);
    sendCommand(SSD1306_SETMULTIPLEX);
    sendCommand(0x3F);
    sendCommand(SSD1306_SETDISPLAYOFFSET);
    sendCommand(0x0);
    sendCommand(SSD1306_SETDISPLAYCLOCKDIV);
    sendCommand(0x80);
    sendCommand(SSD1306_SETPRECHARGE);
    sendCommand(0xF1);
    sendCommand(SSD1306_SETCOMPINS);
    sendCommand(0x12);
    sendCommand(SSD1306_SETVCOMDETECT);
    sendCommand(0x40);
    sendCommand(SSD1306_MEMORYMODE);
    sendCommand(0x00);
    sendCommand(SSD1306_SEGREMAP | 0x1);
    sendCommand(SSD1306_COMSCANDEC);
    sendCommand(SSD1306_CHARGEPUMP);
    sendCommand(0x14);
    sendCommand(SSD1306_DISPLAYON);
}
void SSD1306_I2C_128x64::sendCommand(uint8_t cmd)
{
    Wire.beginTransmission(SSD1306_I2C_ADDRESS);
    Wire.write(0x00);
    Wire.write(cmd);
    Wire.endTransmission();
}

