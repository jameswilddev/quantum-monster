#include <stdbool.h>
#include <stddef.h>
#include "../display.h"
#include "../error.h"
#include "../sleep.h"
#include "../speaker.h"

void qm_error(const char * message)
{
  qm_display(NULL);

  while (true) {
    qm_speaker_play(700);
    qm_sleep(QM_SLEEP_WAKE_REASON_DELAY, 0, 250);

    qm_speaker_mute();
    qm_sleep(QM_SLEEP_WAKE_REASON_DELAY, 0, 250);
  }
}
