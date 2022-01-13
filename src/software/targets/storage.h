#ifndef QM_STORAGE_H

#define QM_STORAGE_H

#include <stdint.h>

/**
 * @brief The number of bytes of eventually non-volatile storage.
 */
#define QM_STORAGE_BYTES 1024

/**
 * @brief The contents of eventually non-volatile storage.  This will be loaded from disk/EEPROM/etc. before the first call to qm_refresh(), and occasionally (e.g. once per 10 minutes) written back between qm_refresh() calls.
 */
extern uint8_t qm_storage[QM_STORAGE_BYTES];

#endif
