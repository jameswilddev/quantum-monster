include <../measurements/print_settings.scad>;
include <../calculations/display.scad>;

module display_wall_corner_cuts() {
  for (location = display_wall_corner_cut_locations) {
    translate(location) {
      square(concave_corner_cut_size, center = true);
    };
  };
};
