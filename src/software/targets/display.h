#ifndef QM_DISPLAY_H

#define QM_DISPLAY_H

#include <stdint.h>

#ifndef QM_DISPLAY_WIDTH
  #error QM_DISPLAY_WIDTH must be defined globally.
#endif

#ifndef QM_DISPLAY_HEIGHT
  #error QM_DISPLAY_HEIGHT must be defined globally.
#endif

/**
 * @brief Refreshes or powers down the display.
 * @param pixels When NULL, the display powers down.  Otherwise, an array where each byte describes a horizontal run of 8 1-bit pixels, where the most significant bit is the leftmost and the least significant bit is the rightmost.  A set bit represents white and a cleared bit represents black.  These bytes run from left to right, then top to bottom.
 */
extern void qm_display(const uint8_t pixels[QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8]);

#endif
