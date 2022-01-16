include <../measurements/corner.scad>;
include <../measurements/pcb.scad>;
include <../measurements/wall.scad>;
include <wall.scad>;

/**
 * The location of the left edge of the PCB, in millimeters.
 */
pcb_left = corner_radius + wall_surround + wall_tolerance + wall_thickness + wall_tolerance + pcb_xy_tolerance;

/**
 * The location of the bottom edge of the PCB, in millimeters.
 */
pcb_bottom = wall_surround + wall_tolerance + wall_thickness + wall_tolerance + pcb_xy_tolerance;
