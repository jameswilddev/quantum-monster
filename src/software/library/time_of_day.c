#include "time_of_day.h"

uint8_t qm_time_of_day_get_second_of_minute(qm_time_of_day_t time_of_day)
{
  return time_of_day % QM_TIME_OF_DAY_SECONDS_PER_MINUTE;
}

uint8_t qm_time_of_day_get_minute_of_hour(qm_time_of_day_t time_of_day)
{
  return (time_of_day / QM_TIME_OF_DAY_SECONDS_PER_MINUTE) % QM_TIME_OF_DAY_MINUTES_PER_HOUR;
}

uint8_t qm_time_of_day_get_hours_since_midnight(qm_time_of_day_t time_of_day)
{
  return time_of_day / QM_TIME_OF_DAY_SECONDS_PER_MINUTE / QM_TIME_OF_DAY_MINUTES_PER_HOUR;
}

qm_time_of_day_t qm_time_of_day_increment_minute_of_hour(qm_time_of_day_t time_of_day)
{
  uint8_t minute_of_hour = qm_time_of_day_get_minute_of_hour(time_of_day);

  if (minute_of_hour >= QM_TIME_OF_DAY_MINUTES_PER_HOUR - 1) {
    return time_of_day - QM_TIME_OF_DAY_SECONDS_PER_MINUTE * minute_of_hour;
  } else {
    return time_of_day + QM_TIME_OF_DAY_SECONDS_PER_MINUTE;
  }
}

qm_time_of_day_t qm_time_of_day_increment_hours_since_midnight(qm_time_of_day_t time_of_day)
{
  uint8_t hours_since_midnight = qm_time_of_day_get_hours_since_midnight(time_of_day);

  if (hours_since_midnight >= QM_TIME_OF_DAY_HOURS_PER_DAY - 1) {
    return 0;
  } else {
    return time_of_day + QM_TIME_OF_DAY_SECONDS_PER_HOUR;
  }
}

qm_time_of_day_t qm_time_of_day_increment_seconds_since_midnight(qm_time_of_day_t time_of_day)
{
  return (time_of_day + 1) % QM_TIME_OF_DAY_MAX;
}
