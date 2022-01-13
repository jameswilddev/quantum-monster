#ifndef QM_AVR_STORAGE_H

#define QM_AVR_STORAGE_H

/**
 * @brief Called during start-up to initialize storage.
 */
extern void qm_avr_storage_initialize();

/**
 * @brief Called following qm_refresh() to write changes back to storage (this will only occur every once in a while when the device appears to be entering sleep).
 */
extern void qm_avr_storage_post_update();

#endif
