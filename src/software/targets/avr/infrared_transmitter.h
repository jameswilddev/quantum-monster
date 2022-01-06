#ifndef QM_TARGET_AVR_INFRARED_TRANSMITTER_H

#define QM_TARGET_AVR_INFRARED_TRANSMITTER_H

/**
 * @brief Called during start-up to initialize infrared transmitter.
 */
extern void qm_target_avr_infrared_transmitter_initialize();

/**
 * @brief Called after qm_refresh() to enable or disable the infrared transmitter as appropriate.
 */
extern void qm_target_avr_infrared_transmitter_post_update();

#endif
