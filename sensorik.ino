// #define zeigemessungen 1
#define shortmessages 1

// ca. 1.5 k

//*********************************************************************************************************************
void setupI2C() {
  Wire.begin();
  Wire.setClock(400000L);
  i2cbusscanner();
}

//*********************************************************************************************************************
void setupSensorik() {
  setupBH1750();
  setupBMP280();
  setupSCD41();
}

//*********************************************************************************************************************
bool HasDeviceAtI2CAddr(uint8_t addr) {
  Wire.beginTransmission(addr);
  byte error = Wire.endTransmission();

  return (error == 0);
}

//*********************************************************************************************************************
void i2cbusscanner() {
  byte address;
  byte nDevices = 0;
  bool first = true;

  for (address = 1; address < 127; address++) {
    if (HasDeviceAtI2CAddr(address)) {
      if (first) {
        Serial.print("I2C: ");
        first = false;
      }
      Serial.print("0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.print(" ");

      nDevices++;
    }
  }
  if (nDevices == 0) {
    Serial.print(" no devices found.");
  }
  Serial.println();
}

//*********************************************************************************************************************
BH1750FVI* sensorBH1750 = NULL;
//*********************************************************************************************************************
void setupBH1750() {
  if (HasDeviceAtI2CAddr(bh1750addr)) {
    sensorBH1750 = new BH1750FVI(bh1750addr);
    sensorBH1750->powerOn();
    sensorBH1750->setContHighRes();
  } else {
    delete sensorBH1750;
    sensorBH1750 = NULL;
#ifdef shortmessages
    Serial.println(F("b1"));
#else
    Serial.println(F("Panic: bh1750 not found."));
#endif
  }
}

//*********************************************************************************************************************
bool messungBH1750() {
  const uint32_t zyklus = 15l * 1000l;
  static uint32_t ticker = -zyklus;

  if (millis() - ticker >= zyklus) {
    ticker = millis();
    if (sensorBH1750) {
      messdatencontainer.bh1750lux = sensorBH1750->getLux();
      messdatencontainer.bh1750valid = true;
#ifdef zeigemessungen
      Serial.print(F("BH1750 Brightness: "));
      Serial.print(messdatencontainer.bh1750lux);
      Serial.println(F(" lux"));
#endif
      return true;
    }
  }

  return false;
}

//*********************************************************************************************************************
Adafruit_BMP280* bmp280 = NULL;
//*********************************************************************************************************************
void setupBMP280() {
  bmp280 = new Adafruit_BMP280();
  bool status = bmp280->begin(bmp280addr);
  if (!status) {
    delete bmp280;
    bmp280 = NULL;
#ifdef shortmessages
    Serial.println(F("m1"));
#else
    Serial.println(F("Panic: bmp280 not found."));
#endif
  } else {
    /* Default settings from datasheet. */
    bmp280->setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                        Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                        Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                        Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                        Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  }
}

//*********************************************************************************************************************
bool messungBMP280() {
  const uint32_t zyklus = 15l * 1000l;
  static uint32_t ticker = -zyklus;

  if (millis() - ticker >= zyklus) {
    ticker = millis();
    if (bmp280) {
      messdatencontainer.bmp280temperatur = bmp280->readTemperature();
      messdatencontainer.bmp280pressure = bmp280->readPressure() / 100.0;
      messdatencontainer.bmp280valid = true;
#ifdef zeigemessungen
      Serial.print(F("BMP280 Temperatur: "));
      Serial.print(messdatencontainer.bmp280temperatur);
      Serial.print(F(" °C Pressure: "));
      Serial.print(messdatencontainer.bmp280pressure);
      Serial.println(F(" hPa"));
#endif
      return true;
    }
  }

  return false;
}

//*********************************************************************************************************************
SensirionI2CScd4x* scd4x = NULL;
//*********************************************************************************************************************
void setupSCD41() {
  scd4x = new SensirionI2CScd4x();
  scd4x->begin(Wire);

  bool error = scd4x->stopPeriodicMeasurement();
  if (error) {
    delete scd4x;
    scd4x = NULL;
#ifdef shortmessages
    Serial.println(F("s1"));
#else
    Serial.print(F("Panic: SCD4X.stopPeriodicMeasurement() error "));
#endif
    Serial.println(error);
  } else {

    uint16_t serial0;
    uint16_t serial1;
    uint16_t serial2;
    error = scd4x->getSerialNumber(serial0, serial1, serial2);
    if (error) {
#ifdef shortmessages
      Serial.println(F("s2"));
#else
      Serial.print(F("Panic: SCD4X error.getSerialNumber() "));
#endif
      Serial.println(error);
    } else {
#ifndef shortmessages
      Serial.print(F("SCD4X-Serialnumber: "));
      Serial.print(serial0, HEX);
      Serial.print(serial1, HEX);
      Serial.println(serial2, HEX);
#endif
    }

    // Start Measurement
    error = scd4x->startPeriodicMeasurement();
    if (error) {
#ifdef shortmessages
      Serial.println(F("s3"));
#else
      Serial.print(F("Panic: SCD4X error.startPeriodicMeasurement()"));
#endif
      Serial.println(error);
    }
  }
}

//*********************************************************************************************************************
bool messungSCD4x() {
  const uint32_t zyklus = 15l * 1000l;
  static uint32_t ticker = -zyklus;

  if (millis() - ticker >= zyklus) {
    ticker = millis();
    if (scd4x) {
      bool error;

      // Druck setzen, wenn vorhanden
      if (messdatencontainer.bmp280valid) {
        error = scd4x->setAmbientPressure((uint16_t)(messdatencontainer.bmp280pressure + 0.5));
        if (error) {
#ifdef shortmessages
          Serial.println(F("s4"));
#else
          Serial.print(F("Panic: SCD4X error.setAmbientPressure()"));
#endif
          Serial.println(error);
        }
      }

      bool isDataReady = false;
      error = scd4x->getDataReadyFlag(isDataReady);
      if (error) {
#ifdef shortmessages
        Serial.println(F("s5"));
#else
        Serial.print(F("Panic: SCD4X error.getDataReadyFlag() "));
#endif
        Serial.println(error);
      }
      if (isDataReady) {
        uint16_t co2 = 0;
        error = scd4x->readMeasurement(co2, messdatencontainer.scd4xtemperatur, messdatencontainer.scd4xhumidity);
        messdatencontainer.scd4xco2 = co2;
        messdatencontainer.scd4xvalid = true;
        if (error) {
#ifdef shortmessages
          Serial.println(F("s6"));
#else
          Serial.print(F("Panic: SCD4X error.readMeasurement() "));
#endif
          Serial.println(error);
        } else if (co2 == 0) {
#ifdef shortmessages
          Serial.println(F("s6"));
#else
          Serial.println(F("Good: SCD4x invalid sample detected, skipping."));
#endif
        } else {
#ifdef zeigemessungen
          Serial.print(F("SCD4x Co2: "));
          Serial.print(messdatencontainer.scd4xco2, 0);
          Serial.print(F(" ppm Temperature: "));
          Serial.print(messdatencontainer.scd4xtemperatur);
          Serial.print(F(" °C Humidity: "));
          Serial.print(messdatencontainer.scd4xhumidity);
          Serial.println(F(" %RH"));
#endif
          return true;
        }
      }
    }
  }

  return false;
}


//
