include <../measurements/pcb.scad>;
include <../calculations/pcb.scad>;

module pcb_cutout() {
  translate([
    pcb_left - pcb_xy_tolerance,
    pcb_bottom - pcb_xy_tolerance,
  ]) {
    square([
      pcb_xy_tolerance + pcb_width + pcb_xy_tolerance,
      pcb_xy_tolerance + pcb_height + pcb_xy_tolerance,
    ]);
  };
};
