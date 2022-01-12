#include <avr/io.h>
#include "speaker.h"
#include "../speaker.h"

qm_speaker_frequency_t qm_speaker_frequency = QM_SPEAKER_FREQUENCY_MUTED;

void qm_target_avr_speaker_initialize()
{
  // Configure timer 0 to count from 0 to OCR0A and back down to 0, toggling OC0B (pin D5) each time it does.
  TCCR1A = (1 << COM1A0);
  TCCR1B = (1 << WGM12);
}

void qm_target_avr_speaker_post_update()
{
  int frequency = (uint32_t)4000000 / qm_speaker_frequency;

  if (frequency < 1 || frequency > 65535) {
    // Disconnect the CPU clock from timer 1.
      TCCR1B = (1 << WGM12);
    // TODO: does this lower the pin?
  } else {


    // Connect timer 1 to the CPU clock.
    TCCR1B = (1 << WGM12) | (1 << CS10);

// TODO: why does this need to come second
    // TODO: calculate correctly
    OCR1A = frequency;
  }
}
