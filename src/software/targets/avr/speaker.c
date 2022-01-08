#include <avr/io.h>
#include "speaker.h"
#include "../speaker.h"

qm_speaker_frequency_t qm_speaker_frequency = QM_SPEAKER_FREQUENCY_MUTED;

void qm_target_avr_speaker_initialize()
{
  // Configure timer 0 to count from 0 to OCR0A and back down to 0, toggling OC0B (pin D5) each time it does.
  TCCR0A = (1 << WGM01) | (1 << COM0B0);
}

void qm_target_avr_speaker_post_update()
{
  int frequency = 62500 / qm_speaker_frequency;

  if (frequency < 1 || frequency > 255) {
    // Disconnect the CPU clock from timer 0.
    TCCR0B = 0;
    // TODO: does this lower the pin?
  } else {


    // Connect timer 0 to the CPU clock through a 1/64 prescaler, making it tick at 125kHz.
    TCCR0B = (1 << CS00) | (1 << CS01);

// TODO: why does this need to come second
    // TODO: calculate correctly
    OCR0A = frequency;
  }
}
