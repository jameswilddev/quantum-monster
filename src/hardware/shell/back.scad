include <measurements/button.scad>;
include <measurements/display.scad>;
include <measurements/plate.scad>;
include <measurements/print_settings.scad>;
include <measurements/screw.scad>;
include <calculations/button.scad>;
include <calculations/overall.scad>;
include <calculations/screw.scad>;
include <modules/face_outline.scad>;
include <modules/infrared_window_cutout.scad>;
include <modules/pcb_cutout.scad>;
include <modules/pcb_retainer.scad>;
include <modules/pcb_retainer_corner_cuts.scad>;
include <modules/screw_hole.scad>;
include <modules/wall_groove.scad>;

difference() {
  union() {
    difference() {
      linear_extrude(plate_thickness) {
        face_outline();
      };

      translate([0, 0, button_cap_thickness]) {
        linear_extrude(plate_thickness - button_cap_thickness) {
          pcb_cutout();
        };
      };
    };

    linear_extrude(button_cap_thickness + pcb_back_clearance - pcb_z_tolerance) {
      difference() {
        pcb_retainer();

        pcb_retainer_corner_cuts();

        infrared_window_cutout();
      };

      for (location = button_locations_relative_to_pcb) {
        translate([
          location[0] + pcb_left,
          location[1] + pcb_bottom,
        ]) {
          square(button_rear_support_size, center = true);
        };
      };
    };
  };

  for (screw_xy_location = screw_xy_locations) {
    translate([screw_xy_location[0], screw_xy_location[1], 0]) {
      screw_hole(screw_nut_depth, screw_nut_diameter, screw_nut_tolerance, screw_nut_sides);
    };
  };

  translate([0, 0, plate_thickness - wall_embed]) {
    linear_extrude(wall_embed) {
      wall_groove();
    };
  };
};
