const byte PinHB = 13;

//*********************************************************************************************************************
void setupHeartBeat() {
  pinMode(PinHB, OUTPUT);
}

//*********************************************************************************************************************
inline void loopHeartBeat(void) {
  const uint32_t time = 1000l * 10l;
  static uint32_t timetick = time;
  static uint32_t ticker = -time;

  if (millis() - ticker > timetick) {
    ticker = millis();
    if (digitalRead(PinHB)) {
      digitalWrite(PinHB, false);
      timetick = time;
    } else {
      digitalWrite(PinHB, true);
      timetick = 100;
    }
  }
}

//*********************************************************************************************************************
// follows https://github.com/dbuezas/lgt8fx/blob/master/lgt8f/libraries/lgt_LowPower/examples/idleWakePeriodic/idleWakePeriodic.ino
inline void idle() 
{
    // It is recommended to clear ADC interrupt and clear start conversion flag before sleep.
    ADCSRA |=  ( 1<<ADIF );
    ADCSRA &= ~( 1<<ADSC );

    // Timer0 -> millis etc.
    LowPower.idle(SLEEP_1S, ADC_OFF, TIMER3_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_ON, 
                SPI_OFF, USART0_ON, TWI_ON, PCIC_OFF, FLASHCTL_OFF);
}

//