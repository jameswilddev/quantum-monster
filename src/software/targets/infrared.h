#ifndef QM_INFRARED_H

#define QM_INFRARED_H

#include <stdbool.h>

/**
 * @brief Fully power down the infrared transciever to save power.
 */
extern void qm_infrared_power_down();

/**
 * @brief Power up the infrared transciever.  This may block for some time.
 */
extern void qm_infrared_power_up();

/**
 * @brief Transmit a single bit using the infrared transciever.  This will block for a brief time.  Only call while the infrared transciever is powered up (after qm_infrared_on(), not after qm_infrared_off()).
 * @param bit The bit to transmit.
 */
extern void qm_infrared_transmit(bool bit);

#endif
