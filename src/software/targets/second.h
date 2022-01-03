#ifndef QM_TARGET_SECOND_H

#define QM_TARGET_SECOND_H

#include <stdint.h>

/**
 * @brief An second value; see QM_SECOND_*.
 */
typedef uint8_t qm_second_t;

/**
 * @brief The minimum second value.
 *
 */
#define QM_SECOND_MIN 0

/**
 * @brief The maximum second value.
 */
#define QM_SECOND_MAX 59

/**
 * @brief The current second; see QM_SECOND_*.  This will be automatically incremented as appropriate between qm_refresh() calls, and can be overwritten within qm_refresh() to set the time.
 */
extern qm_second_t qm_second;

#endif
