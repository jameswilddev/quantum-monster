#include <avr/eeprom.h>
#include "../storage.h"
#include "storage.h"

uint8_t qm_storage[QM_STORAGE_BYTES];

void qm_avr_storage_initialize()
{
  eeprom_read_block(qm_storage, 0, QM_STORAGE_BYTES);
}

void qm_avr_storage_post_update()
{
  // TODO
}
