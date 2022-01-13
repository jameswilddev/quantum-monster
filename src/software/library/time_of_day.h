#ifndef QM_TIME_OF_DAY_H

#define QM_TIME_OF_DAY_H

#include <stdint.h>

/**
 * @brief The number of seconds since midnight.
 */
typedef uint32_t qm_time_of_day_t;

/**
 * @brief The number of seconds in a minute.
 */
#define QM_TIME_OF_DAY_SECONDS_PER_MINUTE 60

/**
 * @brief The number of minutes in an hour.
 */
#define QM_TIME_OF_DAY_MINUTES_PER_HOUR 60

/**
 * @brief The number of hours in a day.
 */
#define QM_TIME_OF_DAY_HOURS_PER_DAY 24

/**
 * @brief The number of seconds in an hour.
 */
#define QM_TIME_OF_DAY_SECONDS_PER_HOUR (QM_TIME_OF_DAY_SECONDS_PER_MINUTE * QM_TIME_OF_DAY_MINUTES_PER_HOUR)

/**
 * @brief The number of seconds in a day.
 */
#define QM_TIME_OF_DAY_SECONDS_PER_DAY ((uint32_t)QM_TIME_OF_DAY_SECONDS_PER_HOUR * QM_TIME_OF_DAY_HOURS_PER_DAY)

/**
 * @brief The number of minutes in a day.
 */
#define QM_TIMEMINUTES_PER_DAY (QM_TIME_OF_DAY_MINUTES_PER_HOUR * QM_TIME_OF_DAY_HOURS_PER_DAY)

/**
 * @brief Midnight (00:00:00).
 */
#define QM_TIME_OF_DAY_MIDNIGHT 0

/**
 * @brief Midnight (00:00:00).
 */
#define QM_TIME_OF_DAY_MIN QM_TIME_OF_DAY_MIDNIGHT

/**
 * @brief One second until midnight (23:59:59).
 */
#define QM_TIME_OF_DAY_MAX (QM_TIME_OF_DAY_SECONDS_PER_DAY - 1)

/**
 * @brief Extracts the number of seconds through the current minute of a time of day.
 * @param time_of_day The time of day from which to extract the number of seconds through the current minute.
 * @return uint8_t The number of seconds through the current minute of the given time of day.
 */
extern uint8_t qm_time_of_day_get_second_of_minute(qm_time_of_day_t time_of_day);

/**
 * @brief Extracts the number of minutes through the current hour of a time of day.
 * @param time_of_day The time of day from which to extract the number of minutes through the current hour.
 * @return uint8_t The number of minutes through the current hour of the given time of day.
 */
extern uint8_t qm_time_of_day_get_minute_of_hour(qm_time_of_day_t time_of_day);

/**
 * @brief Extracts the number of hours since midnight of a time of day.
 * @param time_of_day The time of day from which to extract the number of hours since midnight.
 * @return uint8_t The number of hours since midnight of the given time of day.
 */
extern uint8_t qm_time_of_day_get_hours_since_midnight(qm_time_of_day_t time_of_day);

/**
 * @brief Increments the number of hours since midnight of a time of day.
 * @param time_of_day The time of day of which to increment the number of hours since midnight.
 * @return qm_time_of_day_t The incremented time of day.  Hours and seconds are preserved.  Wraps back around to the start of the hour if in the 59th minute.
 */
extern qm_time_of_day_t qm_time_of_day_increment_minute_of_hour(qm_time_of_day_t time_of_day);

/**
 * @brief Increments the number of hours since midnight of a time of day.
 * @param time_of_day The time of day of which to increment the number of hours since midnight.
 * @return qm_time_of_day_t The incremented time of day.  Minutes and seconds are preserved.  Wraps back around to midnight if in the 23rd hour.
 */
extern qm_time_of_day_t qm_time_of_day_increment_hours_since_midnight(qm_time_of_day_t time_of_day);

/**
 * @brief Increments the number of seconds since midnight of a time of day.
 * @param time_of_day The time of day of which to increment the number of seconds since midnight.
 * @return qm_time_of_day_t The incremented time of day.  Minutes then hours automatically roll over at the end of each minute.  Wraps back around to midnight if given 23:59:59.
 */
extern qm_time_of_day_t qm_time_of_day_increment_seconds_since_midnight(qm_time_of_day_t time_of_day);

#endif
