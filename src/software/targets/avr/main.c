#include <avr/io.h>
#include "../target.h"
#include "../../applications/application.h"

int main()
{
  // Configure the speaker timer to oscillate between 0 and OCR0A, inverting the speaker pin each time it does so (but do not connect a clock source).
  TCCR0A |= (1 << WGM00) | (1 << COM0A0);
  TCCR0B |= 1 << WGM02;

  while (true)
  {
    qm_speaker_mute();
    qm_display_mode(QM_DISPLAY_MODE_OFF);

    qm_loop();
  }
}
