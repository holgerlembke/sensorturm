const byte PinButtonLeft = 5;
const byte PinButtonRight = 6;

Button2 buttonLeft;
Button2 buttonRight;

//*********************************************************************************************************************
void setupButtons() {
  buttonLeft.begin(PinButtonLeft);
  buttonRight.begin(PinButtonRight);
}

//*********************************************************************************************************************
inline void loopButtons() {
  buttonLeft.loop();
  buttonRight.loop();

  if (buttonRight.wasPressed()) {
    buttonRight.read();
    currentdisplay++;
    if (currentdisplay == maxdisplay) {
      currentdisplay = 0;
    }
  }

  if (buttonLeft.wasPressed()) {
    buttonLeft.read();
    if (currentdisplay == 0) {
      currentdisplay = maxdisplay - 1;
    } else {
      currentdisplay--;
    }
  }

  /*
    switch (buttonLeft.read()) {
      case single_click:
        Serial.println("single");
        break;
      case double_click:
        Serial.println("double");
        break;
      case triple_click:
        Serial.println("triple");
        break;
      case long_click:
        Serial.println("looong");
        break;
    }
    */

  /*
  int blc = buttonLeft.getNumberOfClicks();
  int brc = buttonRight.getNumberOfClicks();
  if (blc > 0) {
    Serial.println(blc);
  }
  if (brc > 0) {
    Serial.println(brc);
  }
*/
}

//