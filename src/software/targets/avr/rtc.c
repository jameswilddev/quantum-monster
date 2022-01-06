#include <avr/interrupt.h>
#include "../hour.h"
#include "../minute.h"
#include "../second.h"
#include "../../applications/refresh.h"

qm_hour_t qm_hour = 0;
qm_minute_t qm_minute = 0;
qm_second_t qm_second = 0;

void qm_target_avr_rtc_initialize()
{
  // This procedure is based upon the ATmega328P datasheet (17.9 Asynchronous Operation of Timer/Counter2):
  // https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf

/*
Disable the Timer/Counter2 interrupts by clearing OCIE2x and TOIE2.
b. Select clock source by setting AS2 as appropriate.
c. Write new values to TCNT2, OCR2x, and TCCR2x.
d. To switch to asynchronous operation: Wait for TCN2xUB, OCR2xUB, and TCR2xUB.
e. Clear the Timer/Counter2 interrupt flags.
f. Enable interrupts, if needed
*/



  // Set timer 2 to asynchronous mode, using the 32.768kHz external crystal rather than the CPU clock.
  ASSR |= 1 << AS2;

  // // Divide the 32.768kHz clock by 128 to produce 256Hz.
  // TCCR2B |= (1 << CS22) | (1 << CS00);

}

ISR(TIMER2_OVF_vect)
{
  if (qm_second >= QM_SECOND_MAX) {
    qm_second = QM_SECOND_MIN;

    if (qm_minute >= QM_MINUTE_MAX) {
      qm_minute = QM_MINUTE_MIN;

      if (qm_hour >= QM_HOUR_MAX) {
        qm_hour = QM_HOUR_MIN;
      } else {
        qm_hour++;
      }
    } else {
      qm_minute++;
    }
  } else {
    qm_second++;
  }

  qm_refresh();
}
