#ifndef QM_TARGET_AVR_DISPLAY_H

#define QM_TARGET_AVR_DISPLAY_H

/**
 * @brief Called during start-up to initialize the display.
 */
extern void qm_target_avr_display_initialize();

/**
 * @brief Called following qm_refresh() to apply changes to the display.
 */
extern void qm_target_avr_display_post_update();

#endif
