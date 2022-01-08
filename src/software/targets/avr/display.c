#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "pin_mapping.h"
#include "display.h"
#include "../display.h"

static qm_display_mode_t qm_target_avr_display_previous_mode = QM_DISPLAY_MODE_OFF;

uint8_t qm_display_pixels[QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8];
qm_display_mode_t qm_display_mode = QM_DISPLAY_MODE_OFF;

static void qm_target_avr_display_wait_until_ready_for_next_byte()
{
  while (!(UCSR0A & (1<<UDRE0)));
}

static void qm_target_avr_display_wait_until_byte_fully_written()
{
  while (!(UCSR0A & (1<<TXC0)));
}

static void qm_target_avr_display_start_writing_byte(uint8_t byte)
{
  qm_target_avr_display_wait_until_ready_for_next_byte();

  UCSR0A |= 1<<TXC0;
  UDR0 = byte;
}

static void qm_target_avr_display_command_mode()
{
  qm_target_avr_display_wait_until_byte_fully_written();
  QM_TARGET_AVR_PIN_MAPPING_LOWER(QM_TARGET_AVR_PIN_MAPPING_DISPLAY_DC);
}

static void qm_target_avr_display_data_mode()
{
  qm_target_avr_display_wait_until_byte_fully_written();
  QM_TARGET_AVR_PIN_MAPPING_RAISE(QM_TARGET_AVR_PIN_MAPPING_DISPLAY_DC);
}

static void qm_target_avr_display_blit()
{
  qm_target_avr_display_data_mode();

  for (int i = 0; i < QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8; i++) {
    uint8_t next = qm_display_pixels[i];

    qm_target_avr_display_start_writing_byte(next);
  }
}

static void qm_target_avr_display_clear()
{
  qm_target_avr_display_data_mode();

  for (int i = 0; i < QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8; i++) {
    qm_target_avr_display_start_writing_byte(0);
  }
}

void qm_target_avr_display_initialize()
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

  memset(qm_display_pixels, 0, sizeof(qm_display_pixels));

  // A single CPU cycle takes 125ns at 8MHz, so we have definitely had the line low for at least 100ns after a single CPU clock (PCD8544 datasheet, 12 AC CHARACTERISTICS, Serial bus timing characteristics):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
  QM_TARGET_AVR_PIN_MAPPING_RAISE(QM_TARGET_AVR_PIN_MAPPING_DISPLAY_RES);

  // A target's display is meant to start powered off.  This is indeed the case after reset, but one interpretation of the following is that the contents of RAM are not cleared by reset, and having non-zero RAM could cause inadvertent power draw (PCD8544 datasheet, 8.2 Reset function; 8.3 Function set):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf

  // Power the display up.
	qm_target_avr_display_start_writing_byte(0b00100010);

  qm_target_avr_display_clear();

  // Power the display down.
  qm_target_avr_display_command_mode();
  qm_target_avr_display_start_writing_byte(0b00100100);
}

static bool qm_target_avr_display_mode_shows_pixels(qm_display_mode_t mode) {
  switch (mode) {
    case QM_DISPLAY_MODE_OFF:
    case QM_DISPLAY_MODE_BLANK_BLACK:
    case QM_DISPLAY_MODE_BLANK_WHITE:
      return false;
  }

  return true;
}

static void qm_target_avr_display_select_display_mode()
{
  switch (qm_display_mode) {
    case QM_DISPLAY_MODE_BLANK_WHITE:
      qm_target_avr_display_start_writing_byte(0b00001101);
      break;

    case QM_DISPLAY_MODE_NORMAL:
      qm_target_avr_display_start_writing_byte(0b00001100);
      break;

    case QM_DISPLAY_MODE_BLANK_BLACK:
      qm_target_avr_display_start_writing_byte(0b00001101);
      break;

    case QM_DISPLAY_MODE_INVERTED:
      qm_target_avr_display_start_writing_byte(0b00001101);
      break;
  }
}

void qm_target_avr_display_post_update()
{
  if (qm_display_mode == qm_target_avr_display_previous_mode) {
    // There is not a "transactional" way of handling blits when the display mode is visible; a visible "wipe" may be visible.
    if (qm_target_avr_display_mode_shows_pixels(qm_display_mode)) {
      qm_target_avr_display_blit();
    }
  } else if (qm_display_mode == QM_DISPLAY_MODE_OFF) {
    qm_target_avr_display_clear();

    // Power down.
    qm_target_avr_display_command_mode();
    qm_target_avr_display_start_writing_byte(0b00100100);
  } else if (qm_target_avr_display_previous_mode == QM_DISPLAY_MODE_OFF) {
    // Power up and change to the extended instruction set.
    qm_target_avr_display_command_mode();
    qm_target_avr_display_start_writing_byte(0b00100011);

    // Set bias to 3. TODO
    qm_target_avr_display_start_writing_byte(0b00010011);

    // Set temperature coefficient to 2. // TODO
    qm_target_avr_display_start_writing_byte(0b00000110);

    // VOP = 66. TODO
    qm_target_avr_display_start_writing_byte(0b11000010);

    // Return to the standard instruction set.
    qm_target_avr_display_start_writing_byte(0b00100010);

    // Blit pixels before setting the display mode as the entire display will refresh simultaneously when the mode is set.
    if (qm_target_avr_display_mode_shows_pixels(qm_display_mode)) {
      qm_target_avr_display_blit();
      qm_target_avr_display_command_mode();
    }

    qm_target_avr_display_select_display_mode();
  } else if (!qm_target_avr_display_mode_shows_pixels(qm_display_mode)) {
    // Don't bother blitting as the pixels won't be visible; just switch mode.
    qm_target_avr_display_command_mode();
    qm_target_avr_display_select_display_mode();
  } else if (!qm_target_avr_display_mode_shows_pixels(qm_target_avr_display_previous_mode)) {
    // Blit pixels before setting the display mode as the entire display will refresh simultaneously when the mode is set.
    qm_target_avr_display_blit();
    qm_target_avr_display_command_mode();
    qm_target_avr_display_select_display_mode();
  } else {
    // There is not a "transactional" way of handling switches between visible display modes, so there will be a brief flash of the new pixels with the old display mode.
    if (qm_target_avr_display_mode_shows_pixels(qm_display_mode)) {
      qm_target_avr_display_blit();
    }

    qm_target_avr_display_command_mode();
    qm_target_avr_display_select_display_mode();
  }

  qm_target_avr_display_previous_mode = qm_display_mode;
}
