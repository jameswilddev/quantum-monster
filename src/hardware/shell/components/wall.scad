use <pcb.scad>;
use <wall.scad>;

/**
 * The total thickness of the outer wall, in millimeters.
 */
function wall_thickness() = 1.6;

/**
 * The length of the overlapping section between the front and back halves of the shell, in millimeters.
 */
function wall_overlap_height() = 1.2;

/**
 * The tolerance between the front and back halves of the shell where they overlap, in millimeters.
 */
function wall_overlap_tolerance() = 0.125;

/**
 * The position of the top edge of the wall, on the Y axis, in millimeters.
 */
function wall_top() = pcb_top() + wall_thickness();

/**
 * The position of the right edge of the wall, on the X axis, in millimeters.
 */
function wall_right() = pcb_left() * 2 + pcb_width();

/**
 * The position of the bottom of the overlapping section of the wall, on the Z axis, in millimeters.
 */
function wall_overlap_bottom() = (pcb_front() + pcb_back() - wall_overlap_height()) / 2;

/**
 * The position of the top of the overlapping section of the wall, on the Z axis, in millimeters.
 */
function wall_overlap_top() = wall_overlap_bottom() + wall_overlap_height();

/**
 * The position of the left edge of the inner overlap of the wall, on the X axis, in millimeters.
 */
function wall_overlap_inner_left() = pcb_left() - (wall_thickness() - wall_overlap_tolerance()) / 2;

/**
 * The position of the right edge of the inner overlap of the wall, on the X axis, in millimeters.
 */
function wall_overlap_inner_right() = pcb_right() + (wall_thickness() - wall_overlap_tolerance()) / 2;

/**
 * The position of the bottom edge of the inner overlap of the wall, on the Y axis, in millimeters.
 */
function wall_overlap_inner_bottom() = pcb_bottom() - (wall_thickness() - wall_overlap_tolerance()) / 2;

/**
 * The position of the top edge of the inner overlap of the wall, on the Y axis, in millimeters.
 */
function wall_overlap_inner_top() = pcb_top() + (wall_thickness() - wall_overlap_tolerance()) / 2;

/**
 * The width of the inner overlap of the wall, in millimeters.
 */
function wall_overlap_inner_width() = wall_overlap_inner_right() - wall_overlap_inner_left();

/**
 * The height of the inner overlap of the wall, in millimeters.
 */
function wall_overlap_inner_height() = wall_overlap_inner_top() - wall_overlap_inner_bottom();

/**
 * The position of the left edge of the outer overlap of the wall, on the X axis, in millimeters.
 */
function wall_overlap_outer_left() = wall_overlap_inner_left() - wall_overlap_tolerance();

/**
 * The position of the right edge of the outer overlap of the wall, on the X axis, in millimeters.
 */
function wall_overlap_outer_right() = wall_overlap_inner_right() + wall_overlap_tolerance();

/**
 * The position of the bottom edge of the outer overlap of the wall, on the Y axis, in millimeters.
 */
function wall_overlap_outer_bottom() = wall_overlap_inner_bottom() - wall_overlap_tolerance();

/**
 * The position of the top edge of the outer overlap of the wall, on the Y axis, in millimeters.
 */
function wall_overlap_outer_top() = wall_overlap_inner_top() + wall_overlap_tolerance();

/**
 * The width of the outer overlap of the wall, in millimeters.
 */
function wall_overlap_outer_width() = wall_overlap_outer_right() - wall_overlap_outer_left();

/**
 * The height of the outer overlap of the wall, in millimeters.
 */
function wall_overlap_outer_height() = wall_overlap_outer_top() - wall_overlap_outer_bottom();
