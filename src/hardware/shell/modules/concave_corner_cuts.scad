include <../measurements/print_settings.scad>;
include <../calculations/concave_corner_cuts.scad>;

module concave_corner_cuts() {
  for (location = concave_corner_cut_locations) {
    translate(location) {
      square(concave_corner_cut_size, center = true);
    };
  };
};
