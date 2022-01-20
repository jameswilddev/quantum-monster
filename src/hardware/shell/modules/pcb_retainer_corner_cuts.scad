include <../measurements/print_settings.scad>;
include <../calculations/pcb.scad>;

module pcb_retainer_corner_cuts() {
  for (location = pcb_retainer_corner_cut_locations) {
    translate(location) {
      square(concave_corner_cut_size, center = true);
    };
  };
};
