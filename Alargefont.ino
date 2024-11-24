/*
const uint8_t LargeFontBitmaps[] PROGMEM = {
  0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xF0, 0x03, 0xFC, 0x00, 0x7F, 0xE0, 0x0F, 
  0xFF, 0x02, 0x7F, 0xE4, 0x73, 0xFC, 0xEF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 
  0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 
  0xF8, 0x01, 0xFF, 0x80, 0x1F, 0x70, 0x00, 0xE2, 0x00, 0x04, 0x00, 0x00, 
  0x02, 0x00, 0x04, 0x70, 0x00, 0xEF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 
  0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 
  0x01, 0xF7, 0x3F, 0xCE, 0x27, 0xFE, 0x40, 0xFF, 0xF0, 0x07, 0xFE, 0x00, 
  0x3F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
  0x00, 0x00, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 
  0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 
  0x1F, 0x00, 0x00, 0xE0, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 
  0x00, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 
  0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 
  0x00, 0x00, 0xE0, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFC, 
  0x00, 0x7F, 0xE0, 0x0F, 0xFF, 0x00, 0x7F, 0xE4, 0x03, 0xFC, 0xE0, 0x00, 
  0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 
  0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x03, 0xFC, 0xE0, 
  0x7F, 0xE4, 0x0F, 0xFF, 0x02, 0x7F, 0xE0, 0x73, 0xFC, 0x0F, 0x80, 0x00, 
  0xF8, 0x00, 0x0F, 0x80, 0x00, 0xF8, 0x00, 0x0F, 0x80, 0x00, 0xF8, 0x00, 
  0x0F, 0x80, 0x00, 0xF8, 0x00, 0x07, 0x3F, 0xC0, 0x27, 0xFE, 0x00, 0xFF, 
  0xF0, 0x07, 0xFE, 0x00, 0x3F, 0xC0, 0x03, 0xFC, 0x00, 0x7F, 0xE0, 0x0F, 
  0xFF, 0x00, 0x7F, 0xE4, 0x03, 0xFC, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 
  0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 
  0x00, 0x01, 0xF0, 0x00, 0x1F, 0x03, 0xFC, 0xE0, 0x7F, 0xE4, 0x0F, 0xFF, 
  0x00, 0x7F, 0xE4, 0x03, 0xFC, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 
  0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 
  0x01, 0xF0, 0x3F, 0xCE, 0x07, 0xFE, 0x40, 0xFF, 0xF0, 0x07, 0xFE, 0x00, 
  0x3F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x04, 
  0x70, 0x00, 0xEF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 
  0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 
  0x1F, 0x73, 0xFC, 0xE2, 0x7F, 0xE4, 0x0F, 0xFF, 0x00, 0x7F, 0xE4, 0x03, 
  0xFC, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 
  0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x0E, 
  0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFC, 
  0x00, 0x7F, 0xE0, 0x0F, 0xFF, 0x02, 0x7F, 0xE0, 0x73, 0xFC, 0x0F, 0x80, 
  0x00, 0xF8, 0x00, 0x0F, 0x80, 0x00, 0xF8, 0x00, 0x0F, 0x80, 0x00, 0xF8, 
  0x00, 0x0F, 0x80, 0x00, 0xF8, 0x00, 0x0F, 0x80, 0x00, 0x73, 0xFC, 0x02, 
  0x7F, 0xE0, 0x0F, 0xFF, 0x00, 0x7F, 0xE4, 0x03, 0xFC, 0xE0, 0x00, 0x1F, 
  0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 
  0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x3F, 0xCE, 0x07, 0xFE, 0x40, 0xFF, 
  0xF0, 0x07, 0xFE, 0x00, 0x3F, 0xC0, 0x03, 0xFC, 0x00, 0x7F, 0xE0, 0x0F, 
  0xFF, 0x02, 0x7F, 0xE0, 0x73, 0xFC, 0x0F, 0x80, 0x00, 0xF8, 0x00, 0x0F, 
  0x80, 0x00, 0xF8, 0x00, 0x0F, 0x80, 0x00, 0xF8, 0x00, 0x0F, 0x80, 0x00, 
  0xF8, 0x00, 0x0F, 0x80, 0x00, 0x73, 0xFC, 0x02, 0x7F, 0xE0, 0x0F, 0xFF, 
  0x02, 0x7F, 0xE4, 0x73, 0xFC, 0xEF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 
  0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 
  0x01, 0xF7, 0x3F, 0xCE, 0x27, 0xFE, 0x40, 0xFF, 0xF0, 0x07, 0xFE, 0x00, 
  0x3F, 0xC0, 0x03, 0xFC, 0x00, 0x7F, 0xE0, 0x0F, 0xFF, 0x00, 0x7F, 0xE4, 
  0x03, 0xFC, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 
  0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 
  0x1F, 0x00, 0x00, 0xE0, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 
  0x00, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 
  0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x0E, 
  0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFC, 
  0x00, 0x7F, 0xE0, 0x0F, 0xFF, 0x02, 0x7F, 0xE4, 0x73, 0xFC, 0xEF, 0x80, 
  0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 
  0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0x73, 0xFC, 0xE2, 
  0x7F, 0xE4, 0x0F, 0xFF, 0x02, 0x7F, 0xE4, 0x73, 0xFC, 0xEF, 0x80, 0x1F, 
  0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 
  0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xF7, 0x3F, 0xCE, 0x27, 0xFE, 0x40, 0xFF, 
  0xF0, 0x07, 0xFE, 0x00, 0x3F, 0xC0, 0x03, 0xFC, 0x00, 0x7F, 0xE0, 0x0F, 
  0xFF, 0x02, 0x7F, 0xE4, 0x73, 0xFC, 0xEF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 
  0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 0xF8, 0x01, 0xFF, 0x80, 0x1F, 
  0xF8, 0x01, 0xFF, 0x80, 0x1F, 0x73, 0xFC, 0xE2, 0x7F, 0xE4, 0x0F, 0xFF, 
  0x00, 0x7F, 0xE4, 0x03, 0xFC, 0xE0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 
  0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0x00, 
  0x01, 0xF0, 0x3F, 0xCE, 0x07, 0xFE, 0x40, 0xFF, 0xF0, 0x07, 0xFE, 0x00, 
  0x3F, 0xC0
};

const GFXglyph LargeFontGlyphs[] PROGMEM = {
  {     0,   4,   5,   6,    1,   -5 },   // 0x2C ','
  {     0,   0,   0,   0,    0,    0 },   // 0x2D '-'
  {     3,   4,   5,   6,    1,   -5 },   // 0x2E '.'
  {     0,   0,   0,   0,    0,    0 },   // 0x2F '/'
  {     6,  20,  32,  22,    0,  -32 },   // 0x30 '0'
  {    86,  20,  32,  22,    0,  -32 },   // 0x31 '1'
  {   166,  20,  32,  22,    0,  -32 },   // 0x32 '2'
  {   246,  20,  32,  22,    0,  -32 },   // 0x33 '3'
  {   326,  20,  32,  22,    0,  -32 },   // 0x34 '4'
  {   406,  20,  32,  22,    0,  -32 },   // 0x35 '5'
  {   486,  20,  32,  22,    0,  -32 },   // 0x36 '6'
  {   566,  20,  32,  22,    0,  -32 },   // 0x37 '7'
  {   646,  20,  32,  22,    0,  -32 },   // 0x38 '8'
  {   726,  20,  32,  22,    0,  -32 }    // 0x39 '9'
};

const GFXfont LargeFont PROGMEM = {(uint8_t *)LargeFontBitmaps,      
                                        (GFXglyph *)LargeFontGlyphs, 0x2C, 0x39,       56};
*/

// Approx. 8136 bytes
