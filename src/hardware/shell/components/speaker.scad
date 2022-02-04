use <pcb.scad>;

/**
 * The distance between the left edge of the PCB and the middle of the speaker, in millimeters.
 */
function speaker_pcb_left() = 5.646;

/**
 * The distance between the bottom edge of the PCB and the middle of the speaker, in millimeters.
 */
function speaker_pcb_bottom() = 5.694;

/**
 * The diameter of the speaker, in millimeters.
 */
function speaker_diameter() = 9;

/**
 * The number of sides of the speaker.
 */
function speaker_sides() = 64;

/**
 * The diameter of the hole in the speaker, in millimeters.
 */
function speaker_hole_diameter() = 3;

/**
 * The number of sides of the hole in the speaker.
 */
function speaker_hole_sides() = 24;

/**
 * The height of the speaker, in millimeters.  TODO.
 */
function speaker_height() = 5;

/**
 * The position of the speaker, on the X axis, in millimeters.
 */
function speaker_x() = pcb_left() + pcb_xy_tolerance() + speaker_pcb_left();

/**
 * The position of the speaker, on the Y axis, in millimeters.
 */
function speaker_y() = pcb_bottom() + pcb_xy_tolerance() + speaker_pcb_bottom();

/**
 * The position of the speaker's back face, on the Z axis, in millimeters.
 */
function speaker_back() = pcb_back() - speaker_height();
