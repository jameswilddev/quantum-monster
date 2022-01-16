include <../calculations/display.scad>;
include <../measurements/display.scad>;

module display_window() {
  hull() {
    translate([
      display_left + display_left_padding - display_cutout_margin + display_radius_size,
      display_bottom + display_bottom_padding - display_cutout_margin + display_radius_size,
    ]) {
      circle(r = display_radius_size, $fn = display_radius_sides * 4);
    };

    translate([
      display_left + display_width - display_right_padding + display_cutout_margin - display_radius_size,
      display_bottom + display_bottom_padding - display_cutout_margin + display_radius_size,
    ]) {
      circle(r = display_radius_size, $fn = display_radius_sides * 4);
    };

    translate([
      display_left + display_left_padding - display_cutout_margin + display_radius_size,
      display_bottom + display_height - display_bottom_padding + display_cutout_margin - display_radius_size,
    ]) {
      circle(r = display_radius_size, $fn = display_radius_sides * 4);
    };

    translate([
      display_left + display_width - display_right_padding + display_cutout_margin - display_radius_size,
      display_bottom + display_height - display_bottom_padding + display_cutout_margin - display_radius_size,
    ]) {
      circle(r = display_radius_size, $fn = display_radius_sides * 4);
    };
  };
};
