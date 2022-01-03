#ifndef QM_TARGET_HOUR_H

#define QM_TARGET_HOUR_H

#include <stdint.h>

/**
 * @brief An hour value; see QM_HOUR_*.
 */
typedef uint8_t qm_hour_t;

/**
 * @brief The minimum hour value.
 *
 */
#define QM_HOUR_MIN 0

/**
 * @brief The maximum hour value.
 */
#define QM_HOUR_MAX 23

/**
 * @brief The current hour; see QM_HOUR_*.  This will be automatically incremented as appropriate between qm_refresh() calls, and can be overwritten within qm_refresh() to set the time.
 */
extern qm_hour_t qm_hour;

#endif
