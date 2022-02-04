use <corner.scad>;

/**
 * The diameter of the pocket for a screw head, in millimeters.
 */
function screw_head_pocket_diameter() = 4.1;

/**
 * The depth of the pocket for a screw head, in millimeters.
 */
function screw_head_pocket_depth() = 2;

/**
 * The number of sides of the pocket for a screw head, in millimeters.
 */
function screw_head_pocket_sides() = 40;

/**
 * The diameter of the cutout for a screw thread, in millimeters.
 */
function screw_thread_cutout_diameter() = 2.2;

/**
 * The number of sides of the cutout for a screw thread.
 */
function screw_thread_cutout_sides() = 32;

/**
 * The diameter of the pocket for a screw's nut (vertex to opposite vertex), in millimeters.
 */
function screw_nut_pocket_diameter() = 4.7;

/**
 * The number of sides of the pocket for a screw's nut.
 */
function screw_nut_pocket_sides() = 6;

/**
 * The depth of the pocket for a screw's nut, in millimeters.
 */
function screw_nut_pocket_depth() = 1.675;

/**
 * The locations of the screws on the X and Y axes, in millimeters.
 */
function screw_xy_locations() = corner_xy_locations();
