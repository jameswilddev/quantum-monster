use <display.scad>;
use <pcb.scad>;
use <wall.scad>;

/**
 * The distance between the left edge of the PCB and the left edge of the infrared window, in millimeters.
 */
function infrared_window_left_pcb_left() = 2.25;

/**
 * The distance between the left edge of the PCB and the right edge of the infrared window, in millimeters.
 */
function infrared_window_right_pcb_left() = 14.125;

/**
 * The position of the left edge of the infrared window, on the X axis, in millimeters.
 */
function infrared_window_left() = pcb_left() + infrared_window_left_pcb_left();

/**
 * The position of the right edge of the infrared window, on the X axis, in millimeters.
 */
function infrared_window_right() = pcb_left() + infrared_window_right_pcb_left();

/**
 * The width of the infrared window, in millimeters.
 */
function infrared_window_window() = infrared_window_right() - infrared_window_left();

/**
 * The thickness of the infrared window, in millimeters.
 */
function infrared_window_thickness() = 0.4;

/**
 * The thickness of the infrared window, in millimeters.
 */
function infrared_window_overlap() = 0.2;

/**
 * The tolerance around the infrared window, in millimeters.
 */
function infrared_window_tolerance() = 0.125;

/**
 * The sizes of the radiuses of the corners of the infrared window, in millimeters.
 */
function infrared_window_radius_size() = display_radius_size();

/**
 * The number of sides of each corner radius of the infrared window.
 */
function infrared_window_radius_sides() = display_radius_sides();

/**
 * The position of the bottom edge of the infrared window, on the Y axis, in millimeters.
 */
function infrared_window_bottom() = wall_top() / 2;

/**
 * The position of the top edge of the infrared window, on the Y axis, in millimeters.
 */
function infrared_window_top() = wall_top();

/**
 * The height of the infrared window, in millimeters.
 */
function infrared_window_height() = infrared_window_top() - infrared_window_bottom();

/**
 * The position of the left edge of the infrared window pane, on the X axis, in millimeters.
 */
function infrared_window_pane_left() = infrared_window_left() - infrared_window_overlap();

/**
 * The position of the right edge of the infrared window pane, on the X axis, in millimeters.
 */
function infrared_window_pane_right() = infrared_window_right() + infrared_window_overlap();

/**
 * The position of the left edge of the infrared window's cutout, on the X axis, in millimeters.
 */
function infrared_window_cutout_left() = infrared_window_pane_left() - infrared_window_tolerance();

/**
 * The position of the right edge of the infrared window's cutout, on the X axis, in millimeters.
 */
function infrared_window_cutout_right() = infrared_window_pane_right() + infrared_window_tolerance();

/**
 * The distance between the infrared window and the top or bottom of the shell.
 */
function infrared_window_inset() = 1.8;

/**
 * The position of the back of the infrared window, on the Z axis, in millimeters.
 */
function infrared_window_back() = infrared_window_inset();

/**
 * The position of the front of the infrared window, on the Z axis, in millimeters.
 */
function infrared_window_front() = display_bezel_front() - infrared_window_back();

/**
 * The position of the back of the infrared window pane, on the Z axis, in millimeters.
 */
function infrared_window_pane_back() = infrared_window_back() - infrared_window_overlap();

/**
 * The position of the front of the infrared window pane, on the Z axis, in millimeters.
 */
function infrared_window_pane_front() = infrared_window_front() + infrared_window_overlap();

/**
 * The position of the back of the infrared window's cutout, on the Z axis, in millimeters.
 */
function infrared_window_cutout_back() = infrared_window_pane_back() - infrared_window_tolerance();

/**
 * The position of the front of the infrared window's cutout, on the Z axis, in millimeters.
 */
function infrared_window_cutout_front() = infrared_window_pane_front() + infrared_window_tolerance();

/**
 * The position of the bottom of the infrared window pane, on the Y axis, in millimeters.
 */
function infrared_window_pane_bottom() = pcb_top() + (wall_top() - pcb_top() - infrared_window_thickness()) / 2;

/**
 * The position of the top of the infrared window pane, on the Y axis, in millimeters.
 */
function infrared_window_pane_top() = infrared_window_pane_bottom() + infrared_window_thickness();

/**
 * The position of the bottom of the infrared window's cutout, on the Y axis, in millimeters.
 */
function infrared_window_cutout_bottom() = infrared_window_pane_bottom() - infrared_window_tolerance();

/**
 * The position of the top of the infrared window's cutout, on the Y axis, in millimeters.
 */
function infrared_window_cutout_top() = infrared_window_pane_top() + infrared_window_tolerance();

/**
 * The width of the infrared window's cutout, in millimeters.
 */
function infrared_window_cutout_width() = infrared_window_cutout_right() - infrared_window_cutout_left();

/**
 * The height of the infrared window's cutout, in millimeters.
 */
function infrared_window_cutout_height() = infrared_window_cutout_top() - infrared_window_cutout_bottom();

/**
 * The depth of the infrared window's cutout, in millimeters.
 */
function infrared_window_cutout_depth() = infrared_window_cutout_front() - infrared_window_cutout_back();
