include <pcb.scad>;

/**
 * The diameter of the screw head, in millimeters.
 */
screw_head_diameter = 3.75;

/**
 * The tolerance around the screw head, in millimeters.
 */
screw_head_tolerance = 0.25;

/**
 * The depth that a screw's head embeds into the shell.
 */
screw_head_depth = 2;

/**
 * The number of sides of the screw's head.
 */
screw_head_sides = 72;

/**
 * The diameter of the screw thread, in millimeters.
 */
screw_thread_diameter = 2;

/**
 * The tolerance around the screw thread, in millimeters.
 */
screw_thread_tolerance = 0.1;

/**
 * The number of sides of the screw's thread.
 */
screw_thread_sides = 48;

/**
 * The diameter of the screw's nut (vertex to opposite vertex), in millimeters.
 */
screw_nut_diameter = 4.5;

/**
 * The tolerance around the screw's nut, in millimeters.
 */
screw_nut_tolerance = 0.1;

/**
 * The number of sides of the screw's nut.
 */
screw_nut_sides = 6;

/**
 * The depth that a screw's nut embeds into the shell.
 */
screw_nut_depth = 1.675;

/**
 * The number of millimeters between the left or right edge of the device and the center of a screw.
 */
screw_x_offset = 3.25;

/**
 * The number of millimeters between the top or bottom edge of the device and the center of a screw.
 */
screw_y_offset = 3.25;
