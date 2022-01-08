#ifndef QM_TARGET_DISPLAY_H

#define QM_TARGET_DISPLAy_H

#include <stdint.h>

/**
 * @brief The number of columns on the display.  Always divisible by 8.
 */
extern const uint8_t qm_display_width;

/**
 * @brief The number of rows on the display.
 */
extern const uint8_t qm_display_height;

/**
 * @brief The pixel data which will be shown on the display when qm_refresh() returns, sized qm_display_width * qm_display_height / 8.  Each byte describes a horizontal run of 8 single-bit pixels, where the least significant bit is leftmost and the most significant bit is rightmost.  Bytes run from left to right, then top to bottom.  See qm_display_mode/QM_DISPLAY_MODE_* for details on bit to color mapping.  Initially zero-filled.  The pixel aspect ratio is 5:4 (the width of a pixel is 125% of its height).
 */
extern uint8_t qm_display_pixels[];

/**
 * @brief A mode for the display; see qm_display_mode and QM_DISPLAY_MODE_*.  Defaults to QM_DISPLAY_MODE_OFF.
 */
typedef uint8_t qm_display_mode_t;

/**
 * @brief The display is to be blanked, white.  This is similar to QM_DISPLAY_MODE_OFF in terms of appearance, but is better optimized for brief flashes to white, e.g. for effects, as the display is not powered down and therefore does not need time to re-initialize on switching to other modes.
 */
#define QM_DISPLAY_MODE_BLANK_WHITE 0

/**
 * @brief The display is to be blanked, black.
 */
#define QM_DISPLAY_MODE_BLANK_BLACK 1

/**
 * @brief The display is to display the contents of qm_display_pixels, where set bits are black and unset bits are white.
 */
#define QM_DISPLAY_MODE_INVERTED 2

/**
 * @brief The display is to display the contents of qm_display_pixels, where set bits are black and unset bits are black.
 */
#define QM_DISPLAY_MODE_NORMAL 3

/**
 * @brief The display is to be blanked, white.  This is similar to QM_DISPLAY_MODE_BLANK_WHITE in terms of appearance, but is better optimized for long periods of blanking, e.g. for sleep modes, as the display fully powers down.  It will be re-initialized on switching to any other mode.
 */
#define QM_DISPLAY_MODE_OFF 4

/**
 * @brief The current display mode.  Changes are applied after qm_refresh() returns.  The default value is QM_DISPLAY_MODE_OFF.  See QM_DISPLAY_MODE_*.
 */
extern qm_display_mode_t qm_display_mode;

#endif
