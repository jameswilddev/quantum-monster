include <../measurements/display.scad>;
include <../calculations/display.scad>;

module display_cutout() {
  translate([
    display_left - display_xy_tolerance,
    display_bottom - display_xy_tolerance,
  ]) {
    square([
      display_xy_tolerance + display_width + display_xy_tolerance,
      display_xy_tolerance + display_height + display_xy_tolerance,
    ]);
  };
};
