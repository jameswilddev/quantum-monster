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
 * The height of the display's retaining wall, in millimeters.
 */
display_wall_height = display_thickness; // TODO + display_z_tolerance + display_clip_thickness;
