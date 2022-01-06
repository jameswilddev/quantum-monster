#include "pin_mapping.h"
#include "display.h"
#include "../display.h"

static qm_display_mode_t qm_target_avr_display_previous_mode = QM_DISPLAY_MODE_OFF;

const uint8_t qm_display_width = 48;
const uint8_t qm_display_height = 84;
uint8_t qm_display_pixels[48 * 84];
qm_display_mode_t qm_display_mode = QM_DISPLAY_MODE_OFF;

static void qm_target_avr_display_power_down()
{
  // TODO clear
  // TODO mode 0
  // TODO H 0
  // TODO V 0
  // TODO power down
}

void qm_target_avr_display_initialize()
{
  // A single CPU cycle takes 125ns at 8MHz, so we have definitely had the line low for at least 100ns (PCD8544 datasheet, 12 AC CHARACTERISTICS, Serial bus timing characteristics):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
  QM_TARGET_AVR_PIN_MAPPING_RAISE(QM_TARGET_AVR_PIN_MAPPING_DISPLAY_RES);

  // A target's display is meant to start powered off.  This is indeed the case after reset, but one interpretation of the following is that the contents of RAM are not cleared by reset, and having non-zero RAM could cause inadvertent power draw (PCD8544 datasheet, 8.2 Reset function; 8.3 Function set):
  // https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf

  // By powering up and then going through a full clear and power down sequence, we can be sure that the display is initially powered down and drawling as little power as possible.

  // TODO: power up

  qm_target_avr_display_power_down();
}

void qm_target_avr_display_post_update()
{
  if (qm_display_mode != qm_target_avr_display_previous_mode) {
    if (qm_target_avr_display_previous_mode == QM_DISPLAY_MODE_OFF) {
      // TODO: power up, set bias, etc.
    }

    switch (qm_display_mode) {
      case QM_DISPLAY_MODE_OFF:
        qm_target_avr_display_power_down();
        break;

      case QM_DISPLAY_MODE_NORMAL:
        // TODO
        break;

      case QM_DISPLAY_MODE_INVERTED:
        // TODO
        break;

      case QM_DISPLAY_MODE_BLANK_WHITE:
        // TODO
        break;

      case QM_DISPLAY_MODE_BLANK_BLACK:
        // TODO
        break;
    }

    qm_target_avr_display_previous_mode = qm_display_mode;
  }

  switch (qm_display_mode) {
    case QM_DISPLAY_MODE_NORMAL:
    case QM_DISPLAY_MODE_INVERTED:
      // TODO: blit
      break;
  }

  // TODO
}
