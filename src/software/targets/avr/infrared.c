#include "../infrared.h"
#include "io.h"

void qm_infrared_power_down()
{
  QM_AVR_IO_LOWER(QM_AVR_IO_INFRARED_RECEIVER_VCC);
}

void qm_infrared_power_up()
{
  QM_AVR_IO_RAISE(QM_AVR_IO_INFRARED_RECEIVER_VCC);

  // TODO: DELAY
}

void qm_infrared_transmit(bool bit)
{
  // TODO: doc
  TCCR0A = (1 << COM0B0) | (1 << WGM01);
  TCCR0B = (1 << CS00);
  OCR0A = 110;

  // TODO: DELAY
}
