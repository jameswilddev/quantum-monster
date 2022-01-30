#ifndef QM_MATH_H

#define QM_MATH_H

/**
 * @brief Returns the lesser of its arguments.
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return T The lesser of the given arguments.
 */
#define QM_MATH_MIN(a, b) ((b) < (a) ? (b) : (a))

/**
 * @brief Returns the greater of its arguments.
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return T The greater of the given arguments.
 */
#define QM_MATH_MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief Rounds a given integer up to the nearest integer multiple of a given integer.
 * @param value The integer to round up.
 * @param to_nearest The integer to which to round.
 * @return T The given integer, rounded up to the nearest integer multiple of the given integer.
 */
#define QM_MATH_ROUND_UP(value, to_nearest) ((((value) + ((to_nearest) - 1)) / (to_nearest)) * (to_nearest))

#endif
