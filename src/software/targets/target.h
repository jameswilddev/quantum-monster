#ifndef QM_TARGET_H

#define QM_TARGET_H

#include <stdint.h>
#include <stdbool.h>

/**
 * Bit flags describing events to wait until.
 */
typedef uint8_t qm_wait_until_t;

/**
 * Wait until the A button to change from released to pressed.
 */
#define QM_WAIT_UNTIL_A_BUTTON_DOWN 1

/**
 * Wait until the A button to change from released to pressed, or a repeat occurs as it is held down.
 */
#define QM_WAIT_UNTIL_A_BUTTON_DOWN_OR_REPEAT 2

/**
 * Wait until the B button to change from released to pressed.
 */
#define QM_WAIT_UNTIL_B_BUTTON_DOWN 4

/**
 * Wait until the B button to change from released to pressed, or a repeat occurs as it is held down.
 */
#define QM_WAIT_UNTIL_B_BUTTON_DOWN_OR_REPEAT 8

/**
 * Wait until the C button to change from released to pressed.
 */
#define QM_WAIT_UNTIL_C_BUTTON_DOWN 16

/**
 * Wait until the C button to change from released to pressed, or a repeat occurs as it is held down.
 */
#define QM_WAIT_UNTIL_C_BUTTON_DOWN_OR_REPEAT 32

/**
 * Wait until the real time clock to tick (occurs once per second, asynchronously; this will take between 0 and 1 second(s) to trigger).
 */
#define QM_WAIT_UNTIL_REAL_TIME_CLOCK 64

/**
 * Wait until an update from the link system (e.g. start, true, false, end).
 */
#define QM_WAIT_UNTIL_LINK_EVENT 128

/**
 * Wait until the A, B or C button to change from pressed from released to pressed.
 */
#define QM_WAIT_UNTIL_ANY_BUTTTON_DOWN (QM_WAIT_UNTIL_A_BUTTON_DOWN | QM_WAIT_UNTIL_B_BUTTON_DOWN | QM_WAIT_UNTIL_C_BUTTON_DOWN)

/**
 * Indicates which event ended the wait.
 */
typedef uint8_t qm_wait_result_t;

/**
 * The wait ended as the A button either changed from released or pressed or repeated as it was held down.
 */
#define QM_WAIT_RESULT_A_BUTTON_DOWN_OR_REPEAT 0

/**
 * The wait ended as the B button either changed from released or pressed or repeated as it was held down.
 */
#define QM_WAIT_RESULT_B_BUTTON_DOWN_OR_REPEAT 1

/**
 * The wait ended as the C button either changed from released or pressed or repeated as it was held down.
 */
#define QM_WAIT_RESULT_C_BUTTON_DOWN_OR_REPEAT 2

/**
 * The wait ended as the real time clock ticked (occurs once per second).
 */
#define QM_WAIT_RESULT_REAL_TIME_CLOCK 3

/**
 * The wait ended as the start of a link message was received.
 */
#define QM_WAIT_RESULT_LINK_START 4

/**
 * The wait ended as a "true" bit was received in a link message.
 */
#define QM_WAIT_RESULT_LINK_TRUE 5

/**
 * The wait ended as a "false" bit was received in a link message.
 */
#define QM_WAIT_RESULT_LINK_FALSE 6

/**
 * The wait ended as the end of a link message was received.
 */
#define QM_WAIT_RESULT_LINK_END 7

/**
 * Pauses the program until an event occurs.
 * @param qm_wait_until The event(s) to wait until.
 * @return The event which ended the wait.
 */
qm_wait_result_t wait(qm_wait_until_t wait_until);

/**
 * The number of rows on the display.  Each is 8 pixels tall.
 */
#define QM_DISPLAY_ROWS 6

/**
 * The number of a row on the display.
 */
typedef uint8_t qm_display_row_index_t;

/**
 * The number of the display's first row.  (TODO: top or bottom)
 */
#define QM_DISPLAY_ROW_INDEX_MIN 0

/**
 * The number of the display's last row.  (TODO: top or bottom)
 */
#define QM_DISPLAY_ROW_INDEX_MAX (DISPLAY_ROWS - 1)

/**
 * The number of columns on the display.  Each is 1 pixel wide.
 */
#define QM_DISPLAY_COLUMNS 84

/**
 * The number of a column on the display.
 */
typedef uint8_t qm_display_column_index_t;

/**
 * The number of the display's first column.  (TODO: left or right)
 */
#define QM_DISPLAY_COLUMN_INDEX_MIN 0

/**
 * The number of the display's last column.  (TODO: left or right)
 */
#define QM_DISPLAY_COLUMN_INDEX_MAX (QM_DISPLAY_COLUMNS - 1)

/**
 * An effect applied to the display.
 */
typedef uint8_t qm_display_effect_t;

/**
 * The display is to be blanked, white.
 */
#define QM_DISPLAY_EFFECT_BLANK_WHITE 0

/**
 * The display is to be blanked, black.
 */
#define QM_DISPLAY_EFFECT_BLANK_BLACK 1

/**
 * No effect is to be applied to the display.
 */
#define QM_DISPLAY_EFFECT_NONE 2

/**
 * The display is to be "inverted"; white becomes black and vice-versa.
 */
#define QM_DISPLAY_EFFECT_INVERTED 3

/**
 * Sets the column index to which the next write will be performed.
 * @param column The column index to which the next write will be performed.
 */
void qm_display_column(qm_display_column_index_t column);

/**
 * Sets the row index to which the next write will be performed.
 * @param row The row index to which the next write will be performed.
 */
void qm_display_row(qm_display_row_index_t row);

/**
 * The mode of the display.
 */
typedef uint8_t qm_display_mode_t;

/**
 * The display is to be turned off.  This is the default state.  All other state is lost:
 * - The QM_DISPLAY_EFFECT_BLANK_WHITE effect is applied.
 * - The current column and row are reset to 0.
 * - All pixels are white.
 */
#define QM_DISPLAY_MODE_OFF 0

/**
 * The display is to move to the next column of the same row after each write.
 */
#define QM_DISPLAY_MODE_ROW 1

/**
 * The display is to move to the next row of the same column after each write.
 */
#define QM_DISPLAY_MODE_COLUMN 2

/**
 * Sets the display mode.
 * @param mode The display mode to set.
 */
void qm_display_mode(qm_display_mode_t mode);

/**
 * A cell of the display (1 pixel wide, 8 pixels tall); each bit represents a pixel. (TODO: MSB -> LSB)
 */
typedef uint8_t qm_display_cell_t;

/**
 * Writes a cell to the display; the cell to be updated and the resulting state are controlled by qm_display_column(), qm_display_row() and qm_display_mode().
 * @param cell The content of the cell to write.
 */
void qm_display_write(qm_display_cell_t cell);

/**
 * Indicates the start of a message to a possible recipient.
 */
void qm_link_send_start();

/**
 * Sends a bit during a message to a possible recipient.
 * @param bit The bit to indicate.
 */
void qm_link_send_bit(bool bit);

/**
 * Indicates the end of a message to a possible recipient.
 */
void qm_link_send_end();

/**
 * The pitch of a sound.
 */
typedef uint8_t qm_speaker_pitch_t;

/**
 * The highest audible pitch.
 */
#define QM_SPEAKER_PITCH_MIN 3

/**
 * The lowest audible pitch.
 */
#define QM_SPEAKER_PITCH_MAX 255

/**
 * Stop the current tone, if any.
 */
void qm_speaker_mute();

/**
 * Plays a tone with a specified pitch.
 * @param pitch The pitch of the tone to play.
 */
void qm_speaker_play(qm_speaker_pitch_t pitch);

/**
 * The number of bytes able to be read or written (which will be retained through resets).
 */
#define QM_STORAGE_BYTES 1024

/**
 * An address of which a byte of information can be read or written (which will be retained through resets).
 */
typedef uint16_t qm_storage_address_t;

/**
 * The first address of which a byte of information can be read or written (which will be retained through resets).
 */
#define QM_STORAGE_ADDRESS_MIN 0

/**
 * The last address of which a byte of information can be read or written (which will be retained through resets).
 */
#define QM_STORAGE_ADDRESS_MAX (QM_STORAGE_BYTES - 1)

/**
 * Reads a byte of data from storage (which will be retained through resets).  Returns 0xFF/255 for any bytes which have not previously been written.
 * @param address The address from which to read.
 * @return The byte read at the specified address.
 */
uint8_t qm_storage_read(qm_storage_address_t address);

/**
 * Writes a byte of data to storage (which will be retained through resets).
 * @param address The address from which to write.
 * @param byte The byte to write.
 */
void qm_storage_write(qm_storage_address_t address, uint8_t byte);

#endif
