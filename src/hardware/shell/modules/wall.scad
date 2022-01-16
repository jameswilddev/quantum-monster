include <../measurements/infrared.scad>;
include <../measurements/pcb.scad>;
include <../measurements/wall.scad>;
include <../calculations/pcb.scad>;

module wall() {
  difference() {
    translate([
      pcb_left - pcb_xy_tolerance - wall_tolerance - wall_thickness,
      pcb_bottom - pcb_xy_tolerance - wall_tolerance - wall_thickness,
    ]) {
      square([
        wall_thickness + wall_tolerance + pcb_xy_tolerance + pcb_width + pcb_xy_tolerance + wall_tolerance + wall_thickness,
        wall_thickness + wall_tolerance + pcb_xy_tolerance + pcb_height + pcb_xy_tolerance + wall_tolerance + wall_thickness,
      ]);
    };

    translate([
      pcb_left - pcb_xy_tolerance - wall_tolerance,
      pcb_bottom - pcb_xy_tolerance - wall_tolerance,
    ]) {
      square([
        wall_tolerance + pcb_xy_tolerance + pcb_width + pcb_xy_tolerance + wall_tolerance,
        wall_tolerance + pcb_xy_tolerance + pcb_height + pcb_xy_tolerance + wall_tolerance,
      ]);
    };

    translate([
      pcb_left + infrared_pcb_left - infrared_tolerance,
      pcb_bottom + pcb_height + pcb_xy_tolerance + wall_tolerance,
    ]) {
      square([infrared_width + infrared_tolerance * 2, wall_thickness]);
    };
  };
};
