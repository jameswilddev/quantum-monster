#ifndef QM_MILLISECONDS_H

#define QM_MILLISECONDS_H

#include <stdint.h>

/**
 * @brief Represents a number of milliseconds.
 */
typedef uint8_t qm_milliseconds_t;

/**
 * @brief The minimum number of milliseconds which can be represented (0).
 */
#define QM_MILLISECONDS_MIN 0

/**
 * @brief The maximum number of milliseconds which can be represented.
 */
#define QM_MILLISECONDS_MAX 255

#endif
