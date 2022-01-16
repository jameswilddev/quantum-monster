include <../measurements/corner.scad>;
include <../measurements/pcb.scad>;
include <../measurements/wall.scad>;
include <../measurements/display.scad>;
include <../measurements/plate.scad>;
include <wall.scad>;

/**
 * The width of the assembled device, in millimeters.
 */
overall_width = corner_radius + wall_surround + wall_tolerance + wall_thickness + wall_tolerance + pcb_xy_tolerance
  + pcb_width
  + pcb_xy_tolerance + wall_tolerance + wall_thickness + wall_tolerance + wall_surround + corner_radius;

/**
 * The height of the assembled device, in millimeters.
 */
overall_height = wall_surround + wall_tolerance + wall_thickness + wall_tolerance + pcb_xy_tolerance
  + pcb_height
  + pcb_xy_tolerance + wall_tolerance + wall_thickness + wall_tolerance + wall_surround;

/**
 * The depth of the assembled device, in millimeters.
 */
overall_depth = display_bezel_thickness + display_thickness + display_pcb_distance + pcb_z_tolerance + pcb_thickness + pcb_z_tolerance + pcb_back_clearance + display_bezel_thickness;

// TODO: circular dependency here

/**
 * The height of the wall, in millimeters.
 */
wall_height = overall_depth - plate_thickness * 2 + wall_embed * 2;
