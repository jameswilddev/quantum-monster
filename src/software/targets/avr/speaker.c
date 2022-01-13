#include <avr/io.h>
#include "../speaker.h"
#include "sleep.h"

void qm_speaker_mute()
{
  // Disconnect the timer from the CPU clock and OC1A (pin B1).
  // TODO: REFERENCE
  TCCR1A = 0;
  TCCR1B = 0;

  qm_avr_sleep_blocker &= ~QM_AVR_SLEEP_BLOCKER_SPEAKER;
}

void qm_speaker_play(qm_frequency_t frequency)
{
  int top = (uint32_t)4000000 / frequency;

  if (top < 1 || top > 65535) {
    qm_speaker_mute();
  } else {
    // Configure timer 1 to count from 0 to OCR1A and back down to 0, toggling OC1A (pin B1) each time it does.  This is count non-prescaled CPU clocks.
    // TODO: REFERENCE
    TCCR1A = (1 << COM1A0);
    TCCR1B = (1 << WGM12) | (1 << CS10);

    OCR1A = top;

    qm_avr_sleep_blocker |= QM_AVR_SLEEP_BLOCKER_SPEAKER;
  }
}
