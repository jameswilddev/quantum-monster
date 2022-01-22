#ifndef QM_SPRITE_H

#define QM_SPRITE_H

#include <stdint.h>

/**
 * @brief The width of a sprite, in columns.
 */
typedef uint8_t qm_sprite_width_t;

/**
 * @brief The height of a sprite, in rows.
 */
typedef uint8_t qm_sprite_height_t;

/**
 * @brief The offset of a sprite on the X axis.  When 0, the left edge of the sprite is on the origin.  When less than 0, the left edge of the sprite is left of the origin.  When greater than 0, the left edge of the sprite is right of the origin.
 */
typedef int8_t qm_sprite_x_offset_t;

/**
 * @brief The offset of a sprite on the Y axis.  When 0, the top edge of the sprite is on the origin.  When less than 0, the top edge of the sprite is above the origin.  When greater than 0, the top edge of the sprite is below the origin.
 */
typedef int8_t qm_sprite_y_offset_t;

/**
 * @brief The encoding of a sprite; see QM_SPRITE_ENCODING_*.
 */
typedef uint8_t qm_sprite_encoding_t;

/**
 * @brief The entire sprite is black.  The data is empty.
 */
#define QM_SPRITE_ENCODING_BLACK 0

/**
 * @brief The entire sprite is white.  The data is empty.
 */
#define QM_SPRITE_ENCODING_WHITE 1

/**
 * @brief The sprite is black and white (without transparency); data is sized width * height / 8 (rounded up).  Each byte describes a horizontal run of 8 single-bit pixels, where 0 is black and 1 is white; the most significant bit is leftmost and the least significant bit is rightmost.  These bytes run from left to right, then top to bottom.  Where the width is not divisible by 8, the additional bits in the final byte on a row are undefined.
 */
#define QM_SPRITE_ENCODING_BLACK_AND_WHITE 2

/**
 * @brief The sprite is black and transparent; data is sized width * height / 8 (rounded up).  Each byte describes a horizontal run of 8 single-bit pixels, where 0 is black and 1 is transparent; the most significant bit is leftmost and the least significant bit is rightmost.  These bytes run from left to right, then top to bottom.  Where the width is not divisible by 8, the additional bits in the final byte on a row are 1.
 */
#define QM_SPRITE_ENCODING_BLACK_AND_TRANSPARENT 3

/**
 * @brief The sprite is white and transparent; data is sized width * height / 8 (rounded up).  Each byte describes a horizontal run of 8 single-bit pixels, where 0 is transparent and 1 is white; the most significant bit is leftmost and the least significant bit is rightmost.  These bytes run from left to right, then top to bottom.  Where the width is not divisible by 8, the additional bits in the final byte on a row are 0.
 */
#define QM_SPRITE_ENCODING_WHITE_AND_TRANSPARENT 4

/**
 * @brief The sprite is black, white and transparent; data is sized 2 * width * height / 8 (rounded up).  Each pair of bytes describes two bit planes of a horizontal run of 8 pixels.  The first byte defines a mask, where 0 bits are black and 1 bits are transparent.  The second byte defines a XOR mask, where 0 bits do not invert the result, and 1 bits invert the result.  These bytes run from left to right, then top to bottom; the most significant bit is leftmost and the least significant bit is rightmost.  Where the width is not divisible by 8, the additional bits in the final bytes on a row are 0.
 */
#define QM_SPRITE_ENCODING_BLACK_WHITE_AND_TRANSPARENT 5

/**
 * @brief Describes a sprite which can be drawn to the display.
 */
typedef struct {
  /**
   * @brief The width of the sprite, in columns.
   */
  qm_sprite_width_t width;

  /**
   * @brief The height of the sprite, in rows.
   */
  qm_sprite_height_t height;

  /**
   * @brief The offset of a sprite on the X axis.  When 0, the left edge of the sprite is on the origin.  When less than 0, the left edge of the sprite is left of the origin.  When greater than 0, the left edge of the sprite is right of the origin.
   */
  qm_sprite_x_offset_t x_offset;

  /**
   * @brief The offset of a sprite on the Y axis.  When 0, the top edge of the sprite is on the origin.  When less than 0, the top edge of the sprite is above the origin.  When greater than 0, the top edge of the sprite is below the origin.
   */
  qm_sprite_y_offset_t y_offset;

  /**
   * @brief The encoding of the sprite; see QM_SPRITE_ENCODING_*.
   */
  qm_sprite_encoding_t encoding;

  /**
   * @brief The sprite's pixel data; see encoding and QM_SPRITE_ENCODING_*.
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
