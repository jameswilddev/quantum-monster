include <pcb.scad>;
include <../measurements/display.scad>;

/**
 * The position of the display's left edge, in millimeters.
 */
display_left = pcb_left + display_pcb_left;

/**
 * The position of the display's bottom edge, in millimeters.
 */
display_bottom = pcb_bottom + display_pcb_bottom;

/**
 * The locations of the display retaining wall corner cuts, on the X and Y axes, in millimeters.
 */
display_wall_corner_cut_locations = [
  [
    display_left - display_xy_tolerance - display_wall_thickness / 2,
    display_bottom - display_xy_tolerance - display_wall_thickness / 2,
  ],
  [
    display_left + display_width + display_xy_tolerance + display_wall_thickness / 2,
    display_bottom - display_xy_tolerance - display_wall_thickness / 2,
  ],
  [
    display_left - display_xy_tolerance - display_wall_thickness / 2,
    display_bottom + display_height + display_xy_tolerance + display_wall_thickness / 2,
  ],
  [
    display_left + display_width + display_xy_tolerance + display_wall_thickness / 2,
    display_bottom + display_height + display_xy_tolerance + display_wall_thickness / 2,
  ],
];
