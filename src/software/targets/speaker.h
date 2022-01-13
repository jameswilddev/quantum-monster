#ifndef QM_SPEAKER_H

#define QM_SPEAKER_H

#include "../library/frequency.h"

/**
 * @brief Mute the speaker if it is currently producing sound.
 */
extern void qm_speaker_mute();

/**
 * @brief Play a square wave at a specified frequency.
 * @param frequency The frequency at which to play a square wave.
 */
extern void qm_speaker_play(qm_frequency_t frequency);

#endif
