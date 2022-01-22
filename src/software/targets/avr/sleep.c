#include <stdbool.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "../sleep.h"
#include "sleep.h"

qm_avr_sleep_blocker_t qm_avr_sleep_blocker = 0;

void qm_avr_sleep_initialize()
{
  sleep_enable();
}

qm_sleep_wake_reason_t qm_sleep(qm_sleep_wake_reason_t wake_reasons, qm_time_of_day_t time_of_day, qm_milliseconds_t delay)
{
  // TODO: ensure display finished
  // TODO: delay

  set_sleep_mode(qm_avr_sleep_blocker ? SLEEP_MODE_EXT_STANDBY : SLEEP_MODE_PWR_SAVE);

  // TODO: configure pin change interrupts

  while (true) {
    qm_sleep_wake_reason_t met_criteria = 0;

    // TODO: set bits

    met_criteria &= wake_reasons;

    if (met_criteria) {
      return met_criteria;
    } else {
      // This disables the brown-out-detector during sleep which saves power.  The brown-out-detector largely exists to prevent EEPROM corruption, which is not likely during sleep (ATmega328P datasheet, 7.4.2 Preventing EEPROM Corruption):
      // https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf

      // Note that this has to be done each time the CPU wakes from sleep, as the bit is cleared after 3 CPU cycles (ATmega328P datasheet, 9.11.2 MCUCR – MCU Control Register):
      // https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
      sleep_bod_disable();

      // Enable interrupts.  The instruction immediately following will be executed before any interrupt handlers (Atmel AVR Instruction Set Manual, 108. SEI – Set Global Interrupt Flag):
      // http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf
      sei();

      sleep_cpu();
    }
  }
}
