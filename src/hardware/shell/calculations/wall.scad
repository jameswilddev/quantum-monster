include <../measurements/print_settings.scad>;
include <../measurements/wall.scad>;

/**
 * The thickness of the wall, in millimeters.
 */
wall_thickness = wall_thickness_nozzle_diameters * nozzle_diameter + fudge;

/**
 * The minimum amount of plastic surrounding the wall-retaining grooves in the front and back faces, in millimeters.
 */
wall_surround = wall_surround_nozzle_diameters * nozzle_diameter + fudge;
