#ifndef QM_TARGET_MINUTE_H

#define QM_TARGET_MINUTE_H

#include <stdint.h>

/**
 * @brief An minute value; see QM_MINUTE_*.
 */
typedef uint8_t qm_minute_t;

/**
 * @brief The minimum minute value.
 *
 */
#define QM_MINUTE_MIN 0

/**
 * @brief The maximum minute value.
 */
#define QM_MINUTE_MAX 59

/**
 * @brief The current minute; see QM_MINUTE_*.  This will be automatically incremented as appropriate between qm_refresh() calls, and can be overwritten within qm_refresh() to set the time.
 */
extern qm_minute_t qm_minute;

#endif
