#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "io.h"
#include "display.h"

static void qm_avr_display_wait_until_ready_for_next_byte()
{
  // TODO doc
  while (!(UCSR0A & (1<<UDRE0)));
}

static void qm_avr_display_wait_until_byte_fully_written()
{
  // TODO doc
  while (!(UCSR0A & (1<<TXC0)));
}

static void qm_avr_display_start_writing_byte(uint8_t byte)
{
  qm_avr_display_wait_until_ready_for_next_byte();

  // TODO doc
  UCSR0A |= 1<<TXC0;
  UDR0 = byte;
}

static void qm_avr_display_command_mode()
{
  if (QM_AVR_IO_RAISED(QM_AVR_IO_DISPLAY_DC)) {
    qm_avr_display_wait_until_byte_fully_written();
    QM_AVR_IO_LOWER(QM_AVR_IO_DISPLAY_DC);
  }
}

static void qm_avr_display_data_mode()
{
  if (QM_AVR_IO_LOWERED(QM_AVR_IO_DISPLAY_DC)) {
    qm_avr_display_wait_until_byte_fully_written();
    QM_AVR_IO_RAISE(QM_AVR_IO_DISPLAY_DC);
  }
}

bool qm_avr_display_on;

static void qm_avr_display_power_up() {
  qm_avr_display_command_mode();

  // Power up and change to the extended instruction set.
  qm_avr_display_start_writing_byte(0b00100011);

  // Set bias to 3. TODO
  qm_avr_display_start_writing_byte(0b00010011);

  // Set temperature coefficient to 2. // TODO
  qm_avr_display_start_writing_byte(0b00000110);

  // VOP = 66. TODO
  qm_avr_display_start_writing_byte(0b11000010);

  // Return to the standard instruction set.
  qm_avr_display_start_writing_byte(0b00100010);

  // Enter "inverted" mode; 0 = black, 1 = white.
  qm_avr_display_start_writing_byte(0b00001101);
}

static void qm_avr_display_power_down()
{
  // Clear RAM to reduce power consumption (PCD8544 datasheet, 8.3 Function set):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
  qm_avr_display_data_mode();

  for (int i = 0; i < QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8; i++) {
    qm_avr_display_start_writing_byte(0);
  }

  // Switch to power-down mode (PCD8544 datasheet, Table 1 Instruction set):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
  qm_avr_display_command_mode();
  qm_avr_display_start_writing_byte(0b00100100);

  qm_avr_display_on = false;
}

void qm_avr_display_initialize()
{
  // Halve the clock frequency on the serial output to 2MHz (ATmega328P datasheet, Table 20-1. Equations for Calculating Baud Rate Register Setting):
  // https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
  // This is to avoid the absolute maximum speed of 4MHz (the RC oscillator can drift so it might run over) (PCD8544 datasheet, 12 AC CHARACTERISTICS):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
  UBRR0L = 1;
  UBRR0H = 0;

  // Configure the serial output which is connected to the display to use:
  // - Master SPI mode.
  // - Data changes on falling edge of clock.
  // (ATmega328P datasheet, 118.5.1 SPCR – SPI Control Register; 20.8.2 UCSRnA – USART MSPIM Control and Status Register n A; 20.8.4 UCSRnC – USART MSPIM Control and Status Register n C):
  // https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
  SPCR = 1 << MSTR;
  UCSR0B = 1 << TXEN0;
  UCSR0C = (1 << UMSEL01) | (1 << UMSEL00);

  // A single CPU cycle takes 125ns at 8MHz, so we have definitely had the line low for at least 100ns after a single CPU clock (PCD8544 datasheet, 12 AC CHARACTERISTICS, Serial bus timing characteristics):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
  QM_AVR_IO_RAISE(QM_AVR_IO_DISPLAY_RES);

  // A display is meant to start powered off.  This is indeed the case after reset, but one interpretation of the following is that the contents of RAM are not cleared by reset, and having non-zero RAM could cause inadvertent power draw (PCD8544 datasheet, 8.2 Reset function; 8.3 Function set):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
  qm_avr_display_power_up();
  //qm_avr_display_power_down();
}

void qm_display(const uint8_t pixels[QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8])
{
  if (pixels == NULL) {
    if (qm_avr_display_on) {
      qm_avr_display_power_down();
    }
  } else {
    if (!qm_avr_display_on) {
      qm_avr_display_power_up();
    }

    qm_avr_display_data_mode();

    // TODO: would sizeof work?
    for (int i = 0; i < QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8; i++) {
      // TODO: we need to use a different sequence here.
      uint8_t next = pixels[i];

      qm_avr_display_start_writing_byte(next);
    }
  }
}
