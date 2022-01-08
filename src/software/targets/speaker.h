#ifndef QM_TARGET_SPEAKER_H

#define QM_TARGET_SPEAKER_H

#include <stdint.h>

/**
 * @brief A frequency, in Hertz, for the speaker to produce.  See QM_SPEAKER_FREQUENCY_* and qm_speaker_frequency.
 */
typedef uint16_t qm_speaker_frequency_t;

/**
 * @brief The speaker is to stop producing sound.
 */
#define QM_SPEAKER_FREQUENCY_MUTED 0

/**
 * @brief The frequency at which the speaker is to produce a square wave.  Set to zero (the default value) to mute the speaker.  Changes are applied after qm_refresh() returns.
 */
extern qm_speaker_frequency_t qm_speaker_frequency;

#endif
