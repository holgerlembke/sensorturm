const uint32_t I2CBusFrequency = 400000l;

// hier nur die abweichenden Adressen
const uint8_t bh1750addr = 0x23;
const uint8_t bmp280addr = 0x76;
const uint8_t ssd1306addr = 0x3c;

// Container für die Messdaten
struct messdatencontainer_t {
  bool bh1750valid = false;
  float bh1750lux;

  bool bmp280valid = false;
  float bmp280temperatur;
  float bmp280pressure;

  bool scd4xvalid = false;
  float scd4xtemperatur;
  float scd4xhumidity;
  float scd4xco2;

} messdatencontainer;

const uint8_t maxdisplay = 6;
uint8_t currentdisplay = 0;

//