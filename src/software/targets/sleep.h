#ifndef QM_SLEEP_H

#define QM_SLEEP_H

#include <stdint.h>
#include "../library/time_of_day.h"
#include "../library/delay.h"

/**
 * @brief A bit field, where each bit represents a reason that sleep may be interrupted; see QM_SLEEP_WAKE_REASON_*.
 */
typedef uint16_t qm_sleep_wake_reason_t;

/**
 * @brief Wake as the A button is down (held).  This is not debounced.
 */
#define QM_SLEEP_WAKE_REASON_A_BUTTON_DOWN 1

/**
 * @brief Wake as the A button is up (released).  This is not debounced.
 */
#define QM_SLEEP_WAKE_REASON_A_BUTTON_UP 2

/**
 * @brief Wake as the B button is down (held).  This is not debounced.
 */
#define QM_SLEEP_WAKE_REASON_B_BUTTON_DOWN 4

/**
 * @brief Wake as the B button is up (released).  This is not debounced.
 */
#define QM_SLEEP_WAKE_REASON_B_BUTTON_UP 8

/**
 * @brief Wake as the C button is down (held).  This is not debounced.
 */
#define QM_SLEEP_WAKE_REASON_C_BUTTON_DOWN 16

/**
 * @brief Wake as the C button is up (released).  This is not debounced.
 */
#define QM_SLEEP_WAKE_REASON_C_BUTTON_UP 32

/**
 * @brief Wake as the infrared transciever has received a 0 bit.  Behavior is undefined if the infrared receiver is powered down.
 */
#define QM_SLEEP_WAKE_REASON_INFRARED_0_BIT 64

/**
 * @brief Wake as the infrared transciever has received a 1 bit.  Behavior is undefined if the infrared receiver is powered down.
 */
#define QM_SLEEP_WAKE_REASON_INFRARED_1_BIT 128

/**
 * @brief Wake as a specific time of day has arrived.
 */
#define QM_SLEEP_WAKE_REASON_TIME_OF_DAY 256

/**
 * @brief Wake as a number of milliseconds have passed.
 */
#define QM_SLEEP_WAKE_REASON_DELAY 512

/**
 * @brief Sleep until one or more event(s) occur.
 * @param wake_reasons The reason(s) that sleep may be interrupted.
 * @param time_of_day When configured as a wake reason, the time of day at which to wake.
 * @param delay When configured as a wake reason, the number of milliseconds to delay until wake.
 * @return qm_sleep_wake_reason_t The reason(s) that sleep was interrupted.
 */
extern qm_sleep_wake_reason_t qm_sleep(qm_sleep_wake_reason_t wake_reasons, qm_time_of_day_t time_of_day, qm_delay_t delay);

#endif
