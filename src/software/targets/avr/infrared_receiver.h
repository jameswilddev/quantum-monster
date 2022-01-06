#ifndef QM_TARGET_AVR_INFRARED_RECEIVER_H

#define QM_TARGET_AVR_INFRARED_RECEIVER_H

/**
 * @brief Called during start-up to initialize infrared receiver.
 */
extern void qm_target_avr_infrared_receiver_initialize();

/**
 * @brief Called before qm_refresh() to check for data on the infrared receiver.
 */
extern void qm_target_avr_infrared_receiver_pre_update();

/**
 * @brief Called after qm_refresh() to enable or disable the infrared receiver as appropriate.
 */
extern void qm_target_avr_infrared_receiver_post_update();

#endif
