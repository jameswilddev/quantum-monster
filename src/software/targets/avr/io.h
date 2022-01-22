#ifndef QM_AVR_IO_H

#define QM_AVR_IO_H

#include <avr/io.h>

/**
 * @brief The letter of the port through which the display's RES line is connected.
 */
#define QM_AVR_IO_DISPLAY_RES_PORT_LETTER C

/**
 * @brief The number of the pin through which the display's RES line is connected.
 */
#define QM_AVR_IO_DISPLAY_RES_PIN_NUMBER 0


/**
 * @brief The letter of the port through which the display's SDIN line is connected.  Note that this uses hardware SPI.
 */
#define QM_AVR_IO_DISPLAY_SDIN_PORT_LETTER D

/**
 * @brief The number of the pin through which the display's SDIN line is connected.  Note that this uses hardware SPI.
 */
#define QM_AVR_IO_DISPLAY_SDIN_PIN_NUMBER 1


/**
 * @brief The letter of the port through which the display's DC line is connected.
 */
#define QM_AVR_IO_DISPLAY_DC_PORT_LETTER C

/**
 * @brief The number of the pin through which the display's DC line is connected.
 */
#define QM_AVR_IO_DISPLAY_DC_PIN_NUMBER 1


/**
 * @brief The letter of the port through which the display's SCLK line is connected.  Note that this uses hardware SPI.
 */
#define QM_AVR_IO_DISPLAY_SCLK_PORT_LETTER D

/**
 * @brief The number of the pin through which the display's SCLK line is connected.  Note that this uses hardware SPI.
 */
#define QM_AVR_IO_DISPLAY_SCLK_PIN_NUMBER 4


/**
 * @brief The letter of the port through which the speaker is connected.  Note that this uses hardware PWM and so changes will be required in speaker.c should this change.
 */
#define QM_AVR_IO_SPEAKER_PORT_LETTER B

/**
 * @brief The number of the pin through which the speaker is connected.  Note that this uses hardware PWM and so changes will be required in speaker.c should this change.
 */
#define QM_AVR_IO_SPEAKER_PIN_NUMBER 1


/**
 * @brief The letter of the port through which the A button is connected.
 */
#define QM_AVR_IO_A_BUTTON_PORT_LETTER D

/**
 * @brief The number of the pin through which the A button is connected.
 */
#define QM_AVR_IO_A_BUTTON_PIN_NUMBER 0

/**
 * @brief The pin change mask register of the pin through which the A button is connected.
 */
#define QM_AVR_IO_A_BUTTON_PIN_CHANGE_MASK_REGISTER PCMSK2

/**
 * @brief The PCINT number of the pin through which the A button is connected.
 */
#define QM_AVR_IO_A_BUTTON_PCINT_NUMBER 2


/**
 * @brief The letter of the port through which the B button is connected.
 */
#define QM_AVR_IO_B_BUTTON_PORT_LETTER D

/**
 * @brief The number of the pin through which the B button is connected.
 */
#define QM_AVR_IO_B_BUTTON_PIN_NUMBER 5

/**
 * @brief The pin change mask register of the pin through which the B button is connected.
 */
#define QM_AVR_IO_B_BUTTON_PIN_CHANGE_MASK_REGISTER PCMSK2

/**
 * @brief The PCINT number of the pin through which the B button is connected.
 */
#define QM_AVR_IO_B_BUTTON_PCINT_NUMBER 21


/**
 * @brief The letter of the port through which the C button is connected.
 */
#define QM_AVR_IO_C_BUTTON_PORT_LETTER D

/**
 * @brief The number of the pin through which the C button is connected.
 */
#define QM_AVR_IO_C_BUTTON_PIN_NUMBER 7

/**
 * @brief The pin change mask register of the pin through which the C button is connected.
 */
#define QM_AVR_IO_C_BUTTON_PIN_CHANGE_MASK_REGISTER PCMSK0

/**
 * @brief The PCINT number of the pin through which the C button is connected.
 */
#define QM_AVR_IO_C_BUTTON_PCINT_NUMBER 23


/**
 * @brief The letter of the port through which the infrared receiver's OUT line is connected.
 */
#define QM_AVR_IO_INFRARED_RECEIVER_OUT_PORT_LETTER C

/**
 * @brief The number of the pin through which the infrared receiver's OUT line is connected.
 */
#define QM_AVR_IO_INFRARED_RECEIVER_OUT_PIN_NUMBER 5

/**
 * @brief The pin change mask register of the pin through which the infrared receiver's OUT line is connected.
 */
#define QM_AVR_IO_INFRARED_RECEIVER_OUT_PIN_CHANGE_MASK_REGISTER PCMSK1

/**
 * @brief The PCINT number of the pin through which the infrared receiver's OUT line is connected.
 */
#define QM_AVR_IO_INFRARED_RECEIVER_OUT_PCINT_NUMBER 13


/**
 * @brief The letter of the port through which the infrared receiver's VCC is connected.
 */
#define QM_AVR_IO_INFRARED_RECEIVER_VCC_PORT_LETTER D

/**
 * @brief The number of the pin through which the infrared receiver's VCC is connected.
 */
#define QM_AVR_IO_INFRARED_RECEIVER_VCC_PIN_NUMBER 2


/**
 * @brief The letter of the port through which the infrared transmitter is connected.  Note that this uses hardware PWM and so changes will be required in infrared_transmitter.c should this change.
 */
#define QM_AVR_IO_INFRARED_TRANSMITTER_PORT_LETTER D

/**
 * @brief The number of the pin through which the infrared transmitter is connected.  Note that this uses hardware PWM and so changes will be required in infrared_transmitter.c should this change.
 */
#define QM_AVR_IO_INFRARED_TRANSMITTER_PIN_NUMBER 6


#define QM_AVR_IO_CONCAT_2(A, B) A##B
#define QM_AVR_IO_CONCAT_3(A, B, C) A##B##C

#define QM_AVR_IO_SET_IMPL(REGISTER_PREFIX, CONSTANT_PREFIX, PORT_LETTER, PIN_NUMBER) \
  QM_AVR_IO_CONCAT_2(REGISTER_PREFIX, PORT_LETTER) |= 1 << QM_AVR_IO_CONCAT_3(CONSTANT_PREFIX, PORT_LETTER, PIN_NUMBER)

#define QM_AVR_IO_SET(REGISTER_PREFIX, CONSTANT_PREFIX, NAME) \
  QM_AVR_IO_SET_IMPL(REGISTER_PREFIX, CONSTANT_PREFIX, QM_AVR_IO_CONCAT_2(NAME, _PORT_LETTER), QM_AVR_IO_CONCAT_2(NAME, _PIN_NUMBER))

#define QM_AVR_IO_CLEAR_IMPL(REGISTER_PREFIX, CONSTANT_PREFIX, PORT_LETTER, PIN_NUMBER) \
  QM_AVR_IO_CONCAT_2(REGISTER_PREFIX, PORT_LETTER) &= ~(1 << QM_AVR_IO_CONCAT_3(CONSTANT_PREFIX, PORT_LETTER, PIN_NUMBER))

#define QM_AVR_IO_CLEAR(REGISTER_PREFIX, CONSTANT_PREFIX, NAME) \
  QM_AVR_IO_CLEAR_IMPL(REGISTER_PREFIX, CONSTANT_PREFIX, QM_AVR_IO_CONCAT_2(NAME, _PORT_LETTER), QM_AVR_IO_CONCAT_2(NAME, _PIN_NUMBER))

#define QM_AVR_IO_GET_IMPL(REGISTER_PREFIX, CONSTANT_PREFIX, PORT_LETTER, PIN_NUMBER) \
  (QM_AVR_IO_CONCAT_2(REGISTER_PREFIX, PORT_LETTER) & (1 << QM_AVR_IO_CONCAT_3(CONSTANT_PREFIX, PORT_LETTER, PIN_NUMBER)))

#define QM_AVR_IO_GET(REGISTER_PREFIX, CONSTANT_PREFIX, NAME) \
  QM_AVR_IO_GET_IMPL(REGISTER_PREFIX, CONSTANT_PREFIX, QM_AVR_IO_CONCAT_2(NAME, _PORT_LETTER), QM_AVR_IO_CONCAT_2(NAME, _PIN_NUMBER))

#define QM_AVR_IO_RAISE(NAME) \
  QM_AVR_IO_SET(PORT, PORT, NAME)

#define QM_AVR_IO_LOWER(NAME) \
  QM_AVR_IO_CLEAR(PORT, PORT, NAME)

#define QM_AVR_IO_RAISED(NAME) \
  QM_AVR_IO_GET(PORT, PORT, NAME)

#define QM_AVR_IO_LOWERED(NAME) \
  (!QM_AVR_IO_GET(PORT, PORT, NAME))

#define QM_AVR_IO_INPUT(NAME) \
  QM_AVR_IO_CLEAR(DDR, DD, NAME)

#define QM_AVR_IO_OUTPUT(NAME) \
  QM_AVR_IO_SET(DDR, DD, NAME)


/**
 * @brief Called during start-up to configure inputs and prevent unused IO pins floating, which decreases power consumption (ATmega328P datasheet, 13.2.6 Unconnected Pins):
 *        https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
 */
extern void qm_avr_io_initialize();

#endif
