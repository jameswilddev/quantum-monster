#ifndef QM_SPRITE_H

#define QM_SPRITE_H

#include <stdint.h>

/**
 * @brief Describes a sprite which can be drawn to the display.
 */
typedef struct {
  /**
   * @brief The width of the sprite, in columns.  Always divisible by 8.
   */
  uint8_t width;

  /**
   * @brief The height of the sprite, in rows.
   */
  uint8_t height;

  /**
   * @brief The sprite's pixel data, sized width * height / 8.  Each byte describes a horizontal run of 8 single-bit pixels, where the least significant bit is leftmost and the most significant bit is rightmost.  Bytes run from left to right, then top to bottom.  See qm_display_mode/QM_DISPLAY_MODE_* for details on bit to color mapping.
   */
  uint8_t pixels[];
} qm_sprite_t;

/**
 * @brief The distance between the left edge of the sprite and that of the display, in columns.  When less than zero, the sprite's left edge is left of that of the display.
 */
typedef int8_t qm_sprite_x;

/**
 * @brief The distance between the top edge of the sprite and that of the display, in rows.  When less than zero, the sprite's top edge is above that of the display.
 */
typedef int8_t qm_sprite_y;

/**
 * @brief Draws the specified sprite at the specified location on the display.
 * @param sprite A pointer to the sprite to draw.
 * @param x The distance between the left edge of the sprite and that of the display, in columns.
 * @param y The distance between the top edge of the sprite and that of the display, in rows.
 */
extern void qm_sprite_draw(const qm_sprite_t * sprite, qm_sprite_x x, qm_sprite_y y);

#endif
