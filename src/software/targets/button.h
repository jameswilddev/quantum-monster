#ifndef QM_TARGET_BUTTON_H

#define QM_TARGET_BUTTON_H

#include <stdint.h>

/**
 * @brief Describes the current state of a button;
 */
typedef uint8_t qm_button_state_t;

/**
 * @brief The button is currently released.
 */
#define QM_BUTTON_STATE_RELEASED 0

/**
 * @brief The button changed from released to pressed during this qm_refresh().
 */
#define QM_BUTTON_STATE_DOWN 1

/**
 * @brief The button is currently held down.
 */
#define QM_BUTTON_STATE_PRESSED 2

/**
 * @brief The button repeated while being held down during this qm_refresh().
 */
#define QM_BUTTON_STATE_REPEATING 3

/**
 * @brief The state of the A button; see QM_BUTTON_STATE_*.
 */
extern const qm_button_state_t qm_a_button;

/**
 * @brief The state of the B button; see QM_BUTTON_STATE_*.
 */
extern const qm_button_state_t qm_b_button;

/**
 * @brief The state of the C button; see QM_BUTTON_STATE_*.
 */
extern const qm_button_state_t qm_c_button;

#endif
