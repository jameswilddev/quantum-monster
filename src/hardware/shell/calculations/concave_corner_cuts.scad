include <../measurements/display.scad>;
include <../measurements/pcb.scad>;
include <display.scad>;
include <pcb.scad>;

/**
 * The locations of the corner cuts, on the X and Y axes, in millimeters.
 */
concave_corner_cut_locations = [
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
  [
    pcb_left - pcb_xy_tolerance - pcb_retainer_thickness / 2,
    pcb_bottom - pcb_xy_tolerance - pcb_retainer_thickness / 2,
  ],
  [
    pcb_left + pcb_width + pcb_xy_tolerance + pcb_retainer_thickness / 2,
    pcb_bottom - pcb_xy_tolerance - pcb_retainer_thickness / 2,
  ],
  [
    pcb_left - pcb_xy_tolerance - pcb_retainer_thickness / 2,
    pcb_bottom + pcb_height + pcb_xy_tolerance + pcb_retainer_thickness / 2,
  ],
  [
    pcb_left + pcb_width + pcb_xy_tolerance + pcb_retainer_thickness / 2,
    pcb_bottom + pcb_height + pcb_xy_tolerance + pcb_retainer_thickness / 2,
  ],
];
