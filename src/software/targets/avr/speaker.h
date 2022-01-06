#ifndef QM_TARGET_AVR_SPEAKER_H

#define QM_TARGET_AVR_SPEAKER_H

/**
 * @brief Called during start-up to initialize the speaker.
 */
extern void qm_target_avr_speaker_initialize();

/**
 * @brief Called following qm_refresh() to apply changes to the speaker.
 */
extern void qm_target_avr_speaker_post_update();

#endif
