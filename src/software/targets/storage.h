#ifndef QM_TARGET_STORAGE_H

#define QM_TARGET_STORAGE_H

#include <stdint.h>

/**
 * @brief The state of the speaker; see qm_speaker_state, QM_SPEAKER_STATE_MUTE, QM_SPEAKER_STATE_TONE_MINUMUM and QM_SPEAKER_STATE_TONE_MAXIMUM.
 */
extern qm_speaker_state_t qm_speaker_state;

/**
 * @brief The number of bytes of eventually non-volatile storage.
 */
#define QM_STORAGE_BYTES 1024

/**
 * @brief The contents of eventually non-volatile storage.  This will be loaded from disk/EEPROM/etc. before the first call to qm_refresh(), and occasionally (e.g. once per 10 minutes) written back between qm_refresh() calls.
 */
extern uint8_t qm_storage[QM_STORAGE_BYTES];

#endif
