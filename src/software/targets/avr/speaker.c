#include <avr/io.h>
#include "../target.h"

void qm_speaker_mute()
{
  // Switch the speaker pin to being an input.
  DDRD &= ~(1 << DDD6);

  // Disconnect the clock source from the timer, stopping it.
  TCCR0B &= ~(1 << CS02);

  // TODO: do we need to write it low too?
}

void qm_speaker_play(qm_speaker_pitch_t pitch)
{
  // Out-of-range values won't make audible sound anyway.
  if (pitch < QM_SPEAKER_PITCH_MIN || pitch > QM_SPEAKER_PITCH_MAX)
  {
    qm_speaker_mute();
  }
  else
  {
    OCR0A = pitch;

    // Connect the timer to the CPU clock with a 1/256 divider.
    TCCR0B |= (1 << CS02);

    // Change the speaker pin to being an output.
    DDRD |= 1 << DDD6;
  }
}
