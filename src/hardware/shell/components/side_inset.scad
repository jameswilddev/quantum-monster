use <corner.scad>;
use <pcb.scad>;
use <wall.scad>;

/**
 * The offset of the side inset from the corner, in millimeters.  Positive values are further from the top and bottom edges, while negative values are closes to the top and bottom edges.
 */
function side_inset_corner_offset() = 1;

/**
 * The position of the right edge of the left side inset, on the X axis.
 */
function side_inset_left_right() = pcb_left() - wall_thickness();

/**
 * The position of the left edge of the right side inset, on the X axis.
 */
function side_inset_right_left() = wall_right() - side_inset_left_right();

/**
 * The position of the bottom-most vertex of a side inset, on the Y axis.
 */
function side_inset_bottom_bottom() = corner_radius() + side_inset_corner_offset();

/**
 * The position of the second bottom-most vertex of a side inset, on the Y axis.
 */
function side_inset_bottom_top() = side_inset_bottom_bottom() + side_inset_left_right();

/**
 * The position of the top-most vertex of a side inset, on the Y axis.
 */
function side_inset_top_top() = wall_top() - side_inset_bottom_bottom();

/**
 * The position of the second top-most vertex of a side inset, on the Y axis.
 */
function side_inset_top_bottom() = side_inset_top_top() - side_inset_left_right();

/**
 * The vertices of the left side inset on the X and Y axes, in millimeters.
 */
function side_inset_left_vertices() = [
  [
    0,
    side_inset_bottom_bottom(),
  ],
  [
    0,
    side_inset_top_top(),
  ],
  [
    side_inset_left_right(),
    side_inset_top_bottom(),
  ],
  [
    side_inset_left_right(),
    side_inset_bottom_top(),
  ],
];

/**
 * The vertices of the right side inset on the X and Y axes, in millimeters.
 */
function side_inset_right_vertices() = [
  [
    wall_right(),
    side_inset_top_top(),
  ],
  [
    wall_right(),
    side_inset_bottom_bottom(),
  ],
  [
    side_inset_right_left(),
    side_inset_bottom_top(),
  ],
  [
    side_inset_right_left(),
    side_inset_top_bottom(),
  ],
];
