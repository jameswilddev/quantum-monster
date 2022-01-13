#include <stdint.h>
#include <avr/io.h>
#include "io.h"

extern void qm_avr_io_initialize()
{
  uint8_t temp_DDRB = 0
    | (1 << DDB0)
    | (1 << DDB1)
    | (1 << DDB2)
    | (1 << DDB3)
    | (1 << DDB4)
    | (1 << DDB5);

  // B6 and B7 are connected to the crystal.

  uint8_t temp_PORTB = 0;

  uint8_t temp_DDRC = 0
    | (1 << DDC0)
    | (1 << DDC1)
    | (1 << DDC2)
    | (1 << DDC3)
    | (1 << DDC4)
    | (1 << DDC5);

  // C6 is reset.

  uint8_t temp_PORTC = 0;

  uint8_t temp_DDRD = 0
    | (1 << DDD0)
    | (1 << DDD1)
    | (1 << DDD2)
    | (1 << DDD3)
    | (1 << DDD4)
    | (1 << DDD5)
    | (1 << DDD6)
    | (1 << DDD7);

  uint8_t temp_PORTD = 0;

  // The following pins are mapped, but should be left as outputs at 0VDC:
  // - Display RES.
  // - Display SDIN.
  // - Display DC.
  // - Display SCLK.
  // - Speaker.
  // - Receiver VCC.
  // - Infrared transmitter.

  // TODO
  #define CONCAT2(A, B) A##B
  #define CONCAT3(A, B, C) A##B##C
  #define INPUT_WITH_INTERNAL_PULL_UP_IMPL(PORT_LETTER, PIN_NUMBER) \
    CONCAT2(temp_DDR, PORT_LETTER) &= ~(1 << CONCAT3(DD, PORT_LETTER, PIN_NUMBER)); \
    CONCAT2(temp_PORT, PORT_LETTER) |= 1 << CONCAT3(PORT, PORT_LETTER, PIN_NUMBER);
  #define INPUT_WITH_INTERNAL_PULL_UP(NAME) INPUT_WITH_INTERNAL_PULL_UP_IMPL(CONCAT2(NAME, _PORT_LETTER), CONCAT2(NAME, _PIN_NUMBER))

  INPUT_WITH_INTERNAL_PULL_UP(QM_AVR_IO_A_BUTTON);
  INPUT_WITH_INTERNAL_PULL_UP(QM_AVR_IO_B_BUTTON);
  INPUT_WITH_INTERNAL_PULL_UP(QM_AVR_IO_C_BUTTON);
  INPUT_WITH_INTERNAL_PULL_UP(QM_AVR_IO_INFRARED_RECEIVER_OUT);

  DDRB = temp_DDRB;
  PORTB = temp_PORTB;
  DDRC = temp_DDRC;
  PORTC = temp_PORTC;
  DDRD = temp_DDRD;
  PORTD = temp_PORTD;
}
