include <../measurements/infrared.scad>;
include <../measurements/pcb.scad>;
include <../calculations/overall.scad>;
include <../calculations/pcb.scad>;

module infrared_window_cutout() {
  translate([
    pcb_left + infrared_pcb_left - infrared_tolerance,
    pcb_bottom + pcb_height / 2,
  ]) {
    square([infrared_width + infrared_tolerance * 2, overall_height]);
  };
}
