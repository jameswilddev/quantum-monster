use <button.scad>;
use <corner.scad>;
use <print_settings.scad>;
use <screw.scad>;
use <uncut.scad>;
use <wall.scad>;

/**
 * The tolerance around the top, left right and bottom edges of the PCB.
 */
function pcb_xy_tolerance() = 0.25;

/**
 * The distance between the left and right edges of the PCB, in millimeters.
 */
function pcb_width() = 50.3 + pcb_xy_tolerance() * 2;

/**
 * The distance between the top and bottom edges of the PCB, in millimeters.
 */
function pcb_height() = 39.9 + pcb_xy_tolerance() * 2;

/**
 * The tolerance in front of and behind the PCB.
 */
function pcb_z_tolerance() = 0.125;

/**
 * The distance between the front and back faces of the PCB, in millimeters.
 */
function pcb_thickness() = 1.6 + pcb_z_tolerance() * 2;

/**
 * The PCB's rear clearance, in millimeters.
 */
function pcb_back_clearance() = 7;

/**
 * The position of the PCB's back face, on the Z axis, in millimeters.
 */
function pcb_back() = back_thickness() + pcb_back_clearance();

/**
 * The position of the PCB's front face, on the Z axis, in millimeters.
 */
function pcb_front() = pcb_back() + pcb_thickness();

/**
 * The position of the left edge of the PCB, on the X axis, in millimeters.
 */
function pcb_left() = corner_radius() + screw_thread_cutout_diameter() / 2 + print_settings_nozzle_diameter();

/**
 * The position of the right edge of the PCB, on the X axis.
 */
function pcb_right() = pcb_left() + pcb_width();

/**
 * The position of the bottom edge of the PCB, on the Y axis.
 */
function pcb_bottom() = wall_thickness();

/**
 * The position of the top edge of the PCB, on the Y axis.
 */
function pcb_top() = pcb_bottom() + pcb_height();

/**
 * The thickness of the PCB retaining wall, in millimeters.
 */
function pcb_retainer_thickness() = 0.6;

/**
 * The position of the left edge of the PCB's clearance, on the X axis, in millimeters.
 */
function pcb_clearance_left() = pcb_left() + pcb_retainer_thickness();

/**
 * The position of the right edge of the PCB's clearance, on the X axis, in millimeters.
 */
function pcb_clearance_right() = pcb_right() - pcb_retainer_thickness();

/**
 * The width of the PCB's clearance, in millimeters.
 */
function pcb_clearance_width() = pcb_clearance_right() - pcb_clearance_left();

/**
 * The position of the bottom edge of the PCB's clearance, on the Y axis, in millimeters.
 */
function pcb_clearance_bottom() = pcb_bottom() + pcb_retainer_thickness();

/**
 * The position of the top edge of the PCB's clearance, on the Y axis, in millimeters.
 */
function pcb_clearance_top() = pcb_top() - pcb_retainer_thickness();

/**
 * The height of the PCB's clearance, in millimeters.
 */
function pcb_clearance_height() = pcb_clearance_top() - pcb_clearance_bottom();

/**
 * The PCB's rear clearance, in millimeters.
 */
function pcb_front_clearance() = button_height();
