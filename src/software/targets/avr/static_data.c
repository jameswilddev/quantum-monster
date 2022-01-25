#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../static_data.h"

void qm_static_data_read(qm_static_data_address_t from, size_t bytes, void * to)
{
  memcpy_P(to, from, bytes);
}
