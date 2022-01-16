include <../measurements/display.scad>;
include <../measurements/print_settings.scad>;
include <../calculations/display.scad>;
include <display_cutout.scad>;

module display_wall() {
  difference() {
    translate([
      display_left - display_wall_thickness - display_xy_tolerance,
      display_bottom - display_wall_thickness - display_xy_tolerance,
    ]) {
      square([
        display_wall_thickness + display_xy_tolerance + display_width + display_xy_tolerance + display_wall_thickness,
        display_wall_thickness + display_xy_tolerance + display_height + display_xy_tolerance + display_wall_thickness,
      ]);
    };

    display_cutout();
  };
};
