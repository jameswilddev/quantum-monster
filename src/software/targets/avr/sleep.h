#ifndef QM_AVR_SLEEP_H

#define QM_AVR_SLEEP_H

#include <stdint.h>

/**
 * @brief Called during start-up to initialize the sleep routine.
 */
extern void qm_avr_sleep_initialize();

/**
 * @brief A bit field where each bit, when set, represents a reason that the CPU clock should not stop during qm_sleep(); see QM_AVR_SLEEP_BLOCKER_*.
 */
typedef uint8_t qm_avr_sleep_blocker_t;

/**
 * @brief The CPU clock is not to stop as the speaker is using it to generate sound.
 */
#define QM_AVR_SLEEP_BLOCKER_SPEAKER 1

/**
 * @brief A bit field where each bit, when set, represents a reason that the CPU clock should not stop during qm_sleep(); see QM_AVR_SLEEP_BLOCKER_*.
 */
extern qm_avr_sleep_blocker_t qm_avr_sleep_blocker;

#endif
