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

/**
 * The locations of the PCB retainer corner cuts, on the X and Y axes, in millimeters.
 */
pcb_retainer_corner_cut_locations = [
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
