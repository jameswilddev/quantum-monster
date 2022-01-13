#ifndef QM_NOW_H

#define QM_NOW_H

#include "../library/time_of_day.h"

/**
 * @brief The current time of day.  This is initially midnight, but will be automatically incremented once per second during qm_sleep().
 */
extern qm_time_of_day_t qm_now;

#endif
