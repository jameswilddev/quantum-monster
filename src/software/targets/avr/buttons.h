#ifndef QM_TARGET_AVR_BUTTONS_H

#define QM_TARGET_AVR_BUTTONS_H

/**
 * @brief Called during start-up to initialize buttons.
 */
extern void qm_target_avr_buttons_initialize();

/**
 * @brief Called before qm_refresh() to check for button state changes.
 */
extern void qm_target_avr_buttons_pre_update();

/**
 * @brief Called after qm_refresh() to check for button state changes.
 */
extern void qm_target_avr_buttons_post_update();

#endif
