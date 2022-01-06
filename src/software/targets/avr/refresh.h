#ifndef QM_TARGET_AVR_REFRESH_H

#define QM_TARGET_AVR_REFRESH_H

/**
 * @brief Called either during start-up or during an interrupt to poll inputs, refresh the application and update outputs.
 */
extern void qm_target_avr_refresh();

#endif
