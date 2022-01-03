#ifndef QM_TARGET_SPEAKER_H

#define QM_TARGET_SPEAKER_H

#include <stdint.h>

/**
 * @brief The state of the speaker.  Changes are applied after qm_refresh() returns.  The default value is QM_SPEAKER_STATE_MUTED.  See qm_speaker_state and QM_SPEAKER_STATE_*.
 */
typedef uint8_t qm_speaker_state_t;

/**
 * @brief The speaker is to stop producing sound.
 */
#define QM_SPEAKER_STATE_MUTED 0

#endif
