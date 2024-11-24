SSD1306AsciiWire display;

void setupDisplay() {
  display.begin(&Adafruit128x64, ssd1306addr);
  // display um 180° drehen
  display.displayRemap(true);
  display.setFont(TimesNewRoman13);
  display.clear();
  display.println(F("Sensorturm"));
  display.println(F(__DATE__));
  display.println(F(__TIME__));
}

//*********************************************************************************************************************
// SSD1306AsciiWire String kontrollieren, ob alle Zeichen vorhanden sind
void checkcharset(String t) {
  uint8_t w = display.strWidth(t.c_str());

  if ((t != "") && (w == 0)) {
    Serial.println(F("Warnung: Zeichen nicht im Zeichensatz"));
  }
}

static String lastt = "";

//*********************************************************************************************************************
// SSD1306AsciiWire mag es gar nicht, wenn ein Zeichen nicht im Font enthalten ist
void displaySingleInfo(String t, String ut) {
  t.trim();

  if (t != lastt) {
    lastt = t;

    checkcharset(t);
    checkcharset(ut);

    const byte sideofs = 8;
    display.clear();

    uint8_t h = 0;

    display.setFont(lcdnums14x24);
    uint8_t w = display.strWidth(t.c_str());
    display.setCursor(display.displayWidth() - w - sideofs, h);
    display.print(t);

    display.setFont(TimesNewRoman13);
    w = display.strWidth(ut.c_str());
    h = 4;
    display.setCursor(display.displayWidth() - w - sideofs, h);
    display.print(ut);
  }
}

//*********************************************************************************************************************
void displayAll() {
  String t = "";

  t += String(messdatencontainer.scd4xco2, 0) + " ppm co2\n";

  // float temp = (messdatencontainer.bmp280temperatur + messdatencontainer.scd4xtemperatur) / 2.0;
  // float dtemp = abs(messdatencontainer.bmp280temperatur - messdatencontainer.scd4xtemperatur) / 2.0;

  t += String(messdatencontainer.bmp280temperatur + 0.05, 1) + "/" + String(messdatencontainer.scd4xtemperatur + 0.05, 1) + " C ";
  t += String(messdatencontainer.bmp280pressure + 0.5, 0) + " hPa\n";
  t += String(messdatencontainer.scd4xhumidity + 0.5, 0) + " % rF  ";
  t += String(messdatencontainer.bh1750lux + 0.5, 0) + " Lux";

  if (t != lastt) {
    lastt = t;
    display.clear();
    display.setFont(TimesNewRoman13);
    display.print(t);
  }
}

//*********************************************************************************************************************
inline void loopSensoren() {
  messungBH1750();
  messungBMP280();
  messungSCD4x();

  static uint32_t ticker = 0;

  if (millis() - ticker > 1000) {
    ticker = millis();
    switch (currentdisplay) {
      case 0:
        {
          if (messdatencontainer.scd4xvalid) {
            displaySingleInfo(String(messdatencontainer.scd4xco2 + 0.05, 1), "ppm co2");
          }
          break;
        }
      case 1:
        {
          if (messdatencontainer.bmp280valid) {
            displaySingleInfo(String(messdatencontainer.bmp280temperatur + 0.05, 1),
                              "( " + String(messdatencontainer.scd4xtemperatur + 00.5, 1) + ") C");
          }
          break;
        }
      case 2:
        {
          if (messdatencontainer.bmp280valid) {
            displaySingleInfo(String(messdatencontainer.bmp280pressure + 0.5, 0), "hPa");
          }
          break;
        }
      case 3:
        {
          if (messdatencontainer.scd4xvalid) {
            displaySingleInfo(String(messdatencontainer.scd4xhumidity + 0.5, 0), "% rF");
          }
          break;
        }
      case 4:
        {
          if (messdatencontainer.bh1750valid) {
            displaySingleInfo(String(messdatencontainer.bh1750lux + 0.5, 0), "Lux");
          }
          break;
        }
      case maxdisplay - 1:
        {
          displayAll();
          break;
        }
    }
  }
}


//