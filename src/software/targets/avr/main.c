#include <stdbool.h>
#include "../../applications/loop.h"
#include "io.h"
#include "display.h"
#include "storage.h"
#include "now.h"
#include "sleep.h"

int main()
{
  qm_avr_io_initialize();
  qm_avr_display_initialize();
  qm_avr_now_initialize();
  qm_avr_storage_initialize();
  qm_avr_sleep_initialize();

  while (true) {
    qm_loop();
  }
}
