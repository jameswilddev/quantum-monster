#ifndef QM_DELAY_H

#define QM_DELAY_H

#include <stdint.h>

/**
 * @brief Represents a delay, as a number of milliseconds.
 */
typedef uint8_t qm_delay_t;

/**
 * @brief The minimum delay length possible (1msec).  Note that most implementations are not accurate enough to perform such a short delay.
 */
#define QM_DELAY_MIN 1

/**
 * @brief The maximum delay length possible (255msec).
 */
#define QM_DELAY_MAX 255

#endif
