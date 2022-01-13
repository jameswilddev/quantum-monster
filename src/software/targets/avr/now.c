#include <avr/interrupt.h>
#include "../../library/time_of_day.h"
#include "../now.h"

qm_time_of_day_t qm_now = QM_TIME_OF_DAY_MIDNIGHT;

void qm_avr_now_initialize()
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
  // ASSR |= 1 << AS2;

  // Divide the 32.768kHz clock by 128 to produce 256Hz.
  // TCCR2B |= (1 << CS22) | (1 << CS00);


    ASSR   = _BV(AS2);		// Switch to asynchronous mode            (2)
    TCCR2B = (1 << CS22) | (1 << CS00);
    while (ASSR & _BV(TCR2BUB));                                       // (4)
    TIMSK2 = _BV(TOIE2);	// Enable timer2 overflow interrupt       (6)
}

// TODO: do not reti
ISR(TIMER2_OVF_vect)
{
  qm_now = qm_time_of_day_increment_seconds_since_midnight(qm_now);
}
