#include <avr/io.h>
#include "../target.h"

qm_wait_result_t wait(qm_wait_until_t wait_until)
{
    // TODO disabled BOD
    // TODO enable BOD on wake
    // TODO disable ADC all times
    // TODO disable analog comparator all times
    // TODO disable internal voltage reference
    // TODO disable watchdog timer
    // TODO Power Reduction Register
}