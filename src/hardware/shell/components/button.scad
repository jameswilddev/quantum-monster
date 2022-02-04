use <display.scad>;
use <pcb.scad>;
use <wall.scad>;

/**
 * The distance between the left edge of the PCB and the middle of a button, in millimeters.
 */
function button_pcb_left() = 42.17;

/**
 * The distance between the bottom edge of the PCB and the middle of a button, in millimeters.
 */
function button_pcb_bottom() = 7.91;

/**
 * The distance between the surface of the PCB and the top of a button, in millimeters.
 */
function button_height() = 4.2;

/**
 * The number of buttons.
 */
function button_count() = 3;

/**
 * The position of the buttons, on the X axis, in millimeters.
 */
function button_x() = pcb_left() + pcb_xy_tolerance() + button_pcb_left();

/**
 * The position of the first button, on the Y axis, in millimeters.
 */
function button_first_y() = pcb_bottom() + pcb_xy_tolerance() + button_pcb_bottom();

/**
 * The positions of the buttons, on the Y axis, in millimeters.
 */
function button_y_locations() = [button_first_y() : (wall_top() - button_first_y() * 2) / (button_count() - 1) : wall_top() - button_first_y()];

/**
 * The width and height of the column which supports a button from the back of the PCB.
 */
function button_rear_support_size() = 4.2;

/**
 * The size of a button, in millimeters.
 */
function button_cutout_size() = (button_first_y() - display_cutout_bottom()) * 2;

/**
 * The sizes of the radiuses of the corners of the button cutouts, in millimeters.
 */
function button_cutout_radius_size() = display_radius_size();

/**
 * The number of sides of each corner radius of the button cutout.
 */
function button_cutout_radius_sides() = display_radius_sides();

/**
 * The position of the button caps' backs, on the Z axis, in millimeters.
 */
function button_cap_back() = pcb_front() + pcb_front_clearance();

/**
 * The position of the button caps' fronts, on the Z axis, in millimeters.
 */
function button_cap_front() = display_bezel_front();

/**
 * The thickness of the button caps, in millimeters.
 */
function button_cap_thickness() = button_cap_front() - button_cap_back();

/**
 * The gap around a button cap, in millimeters.
 */
function button_cap_gap() = 0.6;

/**
 * The thickness of the sprue which holes a button cap in place.
 */
function button_cap_sprue_thickness() = 0.4;
