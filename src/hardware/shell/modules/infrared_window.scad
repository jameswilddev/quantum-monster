include <../measurements/infrared.scad>;
include <../measurements/pcb.scad>;
include <../calculations/pcb.scad>;
include <../calculations/wall.scad>;

module infrared_window() {
  translate([
    pcb_left + infrared_pcb_left,
    pcb_bottom + pcb_height + pcb_xy_tolerance + wall_tolerance,
  ]) {
    square([infrared_width, wall_thickness]);
  };
};
