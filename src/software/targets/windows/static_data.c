#include <string.h>
#include "../static_data.h"

void qm_static_data_read(qm_static_data_address_t from, size_t bytes, void * to)
{
  memcpy(to, from, bytes);
}
