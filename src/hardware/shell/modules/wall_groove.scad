include <../calculations/pcb.scad>;
include <../measurements/wall.scad>;

module wall_groove() {
  difference() {
    translate([
      pcb_left - pcb_xy_tolerance - wall_tolerance - wall_thickness - wall_tolerance,
      pcb_bottom - pcb_xy_tolerance - wall_tolerance - wall_thickness - wall_tolerance,
    ]) {
      square([
        wall_tolerance + wall_thickness + wall_tolerance + pcb_xy_tolerance + pcb_width + pcb_xy_tolerance + wall_tolerance + wall_thickness + wall_tolerance,
        wall_tolerance + wall_thickness + wall_tolerance + pcb_xy_tolerance + pcb_height + pcb_xy_tolerance + wall_tolerance + wall_thickness + wall_tolerance,
      ]);
    };

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
};
