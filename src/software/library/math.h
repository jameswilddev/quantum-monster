#ifndef QM_MATH_H

#define QM_MATH_H

/**
 * @brief Returns the lesser of its arguments.
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return T The lesser of the given arguments.
 */
#define QM_MIN(a, b) ((b) < (a) ? (b) : (a))

/**
 * @brief Returns the greater of its arguments.
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return T The greater of the given arguments.
 */
#define QM_MAX(a, b) ((a) > (b) ? (a) : (b))

#endif
