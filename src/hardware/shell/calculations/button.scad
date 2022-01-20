include <../measurements/button.scad>;
include <../measurements/display.scad>;
include <../measurements/pcb.scad>;

/**
 * The thickness of button caps, in millimeters.
 */
button_cap_thickness = display_bezel_thickness + display_thickness + display_pcb_distance + pcb_z_tolerance - button_height;
