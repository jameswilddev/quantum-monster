use <pcb.scad>;

/**
 * The position of the display spacer's back face, on the Z axis, in millimeters.
 */
function display_spacer_back() = pcb_front();

/**
 * The thickness of the display's spacer, in millimeters.
 */
function display_spacer_thickness() = 1.2;

/**
 * The position of the display spacer's front face, on the Z axis, in millimeters.
 */
function display_spacer_front() = display_spacer_back() + display_spacer_thickness();

/**
 * The position of the display's back face, on the Z axis, in millimeters.
 */
function display_back() = display_spacer_front();

/**
 * The tolerance in front of and behind the display.
 */
function display_z_tolerance() = 0.125;

/**
 * The distance between the (visible) front and (PCB-facing) back faces of the display's casing, ignoring the connector, in millimeters.
 */
function display_thickness() = 2 + display_z_tolerance() * 2;

/**
 * The position of the display's front face, on the Z axis, in millimeters.
 */
function display_front() = display_back() + display_thickness();

/**
 * The position of the display bezel's back face, on the Z axis, in millimeters.
 */
function display_bezel_back() = display_front();

/**
 * The thickness of the front bezel, in millimeters.
 */
function display_bezel_thickness() = 1.4;

/**
 * The position of the display bezel's front face, on the Z axis, in millimeters.
 */
function display_bezel_front() = display_bezel_back() + display_bezel_thickness();

/**
 * The tolerance around the top, left right and bottom edges of the display.
 */
function display_xy_tolerance() = 0.125;

/**
 * The distance between the left and right edges of the display's casing, in millimeters.
 */
function display_width() = 33.3 + display_xy_tolerance() * 2;

/**
 * The distance between the top and bottom edges of the display's casing, in millimeters.
 */
function display_height() = 38.3 + display_xy_tolerance() * 2;

/**
 * The amount of margin around the display, in millimeters.
 */
function display_margin() = 1;

/**
 * The distance between the left edge of the display's casing and the left edge of its viewable area, in millimeters.
 */
function display_left_padding() = 3.5;

/**
 * The distance between the right edge of the display's casing and the right edge of its viewable area, in millimeters.
 */
function display_right_padding() = 8.3;

/**
 * The distance between the top edge of the display's casing and the left top of its viewable area, in millimeters.
 */
function display_top_padding() = 4;

/**
 * The distance between the left edge of the display's casing and the bottom edge of its viewable area, in millimeters.
 */
function display_bottom_padding() = 4;

/**
 * The sizes of the radiuses of the corners of the display bezel cutout, in millimeters.
 */
function display_radius_size() = 2;

/**
 * The number of sides of each corner radius of the display bezel cutout.
 */
function display_radius_sides() = 12;

/**
 * The distance between the left edge of the display's casing and the left edge of the PCB, in millimeters.
 */
function display_pcb_left() = 0.8;

/**
 * The distance between the bottom edge of the display's casing and the bottom edge of the PCB, in millimeters.
 */
function display_pcb_bottom() = 0.8;

/**
 * The position of the display casing's left edge, on the X axis, in millimeters.
 */
function display_left() = pcb_left() + pcb_xy_tolerance() + display_pcb_left() - display_xy_tolerance();

/**
 * The position of the display casing's right edge, on the X axis, in millimeters.
 */
function display_right() = display_left() + display_width();

/**
 * The position of the display casing's bottom edge, on the Y axis, in millimeters.
 */
function display_bottom() = pcb_bottom() + pcb_xy_tolerance() + display_pcb_bottom() - display_xy_tolerance();

/**
 * The position of the display casing's top edge, on the Y axis, in millimeters.
 */
function display_top() = display_bottom() + display_height();

/**
 * The position of the display cutout's left edge, on the X axis, in millimeters.
 */
function display_cutout_left() = display_left() + display_left_padding() - display_margin();

/**
 * The position of the display cutout's right edge, on the X axis, in millimeters.
 */
function display_cutout_right() = display_right() - display_right_padding() + display_margin();

/**
 * The position of the display cutout's bottom edge, on the Y axis, in millimeters.
 */
function display_cutout_bottom() = display_bottom() + display_bottom_padding() - display_margin();

/**
 * The position of the display cutout's top edge, on the Y axis, in millimeters.
 */
function display_cutout_top() = display_top() - display_top_padding() + display_margin();

/**
 * The thickness of the display's retaining wall, in millimeters.
 */
function display_wall_thickness() = 0.8;

/**
 * The position of the left edge of the display's retaining wall, on the X axis, in millimeters.
 */
function display_wall_left() = display_left() - display_wall_thickness();

/**
 * The position of the right edge of the display's retaining wall, on the X axis, in millimeters.
 */
function display_wall_right() = display_right() + display_wall_thickness();

/**
 * The position of the bottom edge of the display's retaining wall, on the Y axis, in millimeters.
 */
function display_wall_bottom() = display_bottom() - display_wall_thickness();

/**
 * The position of the top edge of the display's retaining wall, on the Y axis, in millimeters.
 */
function display_wall_top() = display_top() + display_wall_thickness();

/**
 * The width of the display's retaining wall, in millimeters.
 */
function display_wall_width() = display_wall_right() - display_wall_left();

/**
 * The height of the display's retaining wall, in millimeters.
 */
function display_wall_height() = display_wall_top() - display_wall_bottom();
