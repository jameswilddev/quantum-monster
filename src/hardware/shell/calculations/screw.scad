include <overall.scad>;
include <../measurements/screw.scad>;

/**
 * The locations of the screws on the X and Y axes, in millimeters.
 */
screw_xy_locations = [
  [
    screw_x_offset,
    screw_y_offset,
  ],
  [
    screw_x_offset,
    overall_height - screw_y_offset,
  ],
  [
    overall_width - screw_x_offset,
    screw_y_offset,
  ],
  [
    overall_width - screw_x_offset,
    overall_height - screw_y_offset,
  ],
];
