include <measurements/button.scad>;
include <measurements/pcb.scad>;
include <measurements/plate.scad>;
include <calculations/button.scad>;
include <calculations/overall.scad>;
include <modules/infrared_window_cutout.scad>;
include <modules/wall.scad>;

difference() {
  linear_extrude(wall_height) {
    wall();
  };

  linear_extrude(wall_embed + pcb_back_clearance + button_cap_thickness - plate_thickness) {
    infrared_window_cutout();
  };
};
