use <wall.scad>;

/**
 * The radius of a corner, in millimeters.
 */
function corner_radius() = 3.25;

/**
 * The number of sides on a corner.
 */
function corner_sides() = 16;

/**
 * The locations of the corners on the X and Y axes, in millimeters.
 */
function corner_xy_locations() = [
  [
    corner_radius(),
    corner_radius(),
  ],
  [
    wall_right() - corner_radius(),
    corner_radius(),
  ],
  [
    corner_radius(),
    wall_top() - corner_radius(),
  ],
  [
    wall_right() - corner_radius(),
    wall_top() - corner_radius(),
  ],
];
