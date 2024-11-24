/*

  Board: LGT8F328P-LQFP48

  Pinmap: 
    a5 scl
    a4 sda
    13 LED/HB
    5  Taster 1
    6  Taster 2

  I2C:
    0x23     Brightness BH1750
    0x39     Umgebungslicht Gesten APDS-9960 unbenutzt
    0x3C     Display ssd1306
    0x62     CO2 Sensirion 41
    0x76     Temp/Pressure bmp280

    alle mit 400 kHz?

*/

#include <Wire.h>

#include <BH1750FVI.h>          // https://github.com/RobTillaart/BH1750FVI_RT
#include <Adafruit_BMP280.h>    // https://github.com/adafruit/Adafruit_BMP280_Library
#include <SensirionI2CScd4x.h>  // https://github.com/Sensirion/arduino-i2c-scd4x

#include <SSD1306Ascii.h>  // https://github.com/greiman/SSD1306Ascii
#include <SSD1306AsciiWire.h>

#include <lgt_LowPower.h>

#include <Button2.h>  // https://github.com/LennartHennigs/Button2

/*
zu groß
#include <Adafruit_GFX.h>      // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h>  // https://github.com/adafruit/Adafruit_SSD1306
*/


void setup() {
  Serial.begin(115200);
  delay(1500);
  Serial.print(F("\nSensorturm "));
  Serial.print(F(__DATE__));
  Serial.print(" ");
  Serial.print(F(__TIME__));
  Serial.println();

  setupHeartBeat();
  setupI2C();
  setupButtons();
  setupDisplay();
  setupSensorik();
}

void loop() {
  loopHeartBeat();
  loopSensoren();
  loopButtons();

  idle();
}

//