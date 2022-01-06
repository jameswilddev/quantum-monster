#include <stdbool.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "../../applications/refresh.h"
#include "pin_mapping.h"
#include "display.h"
#include "speaker.h"
#include "rtc.h"
#include "storage.h"
#include "buttons.h"
#include "infrared_receiver.h"
#include "infrared_transmitter.h"
#include "refresh.h"

int main()
{
  qm_target_avr_pin_mapping_initialize();
  qm_target_avr_display_initialize();
  qm_target_avr_speaker_initialize();
  qm_target_avr_rtc_initialize();
  qm_target_avr_storage_initialize();
  qm_target_avr_buttons_initialize();
  qm_target_avr_infrared_receiver_initialize();
  qm_target_avr_infrared_transmitter_initialize();

  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
  sleep_enable();

  qm_target_avr_refresh();

  sei();

  // All further work will be done when hardware (pin changes, timers, etc.) wake the CPU from sleep (and launch an interrupt).  Return to sleep each time.
  while (true) {
    // This disables the brown-out-detector during sleep which saves power.  The brown-out-detector largely exists to prevent EEPROM corruption, which is not likely during sleep (ATmega328P datasheet, 7.4.2 Preventing EEPROM Corruption):
    // https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf

    // Note that this has to be done each time the CPU wakes from sleep, as the bit is cleared after 3 CPU cycles (ATmega328P datasheet, 9.11.2 MCUCR – MCU Control Register):
    // https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
    sleep_bod_disable();

    sleep_cpu();
  }
}
