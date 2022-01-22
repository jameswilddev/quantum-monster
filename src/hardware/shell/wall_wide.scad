include <measurements/keychain.scad>;
include <measurements/pcb.scad>;
include <measurements/plate.scad>;
include <measurements/screw.scad>;
include <measurements/wall.scad>;
include <calculations/button.scad>;
include <calculations/overall.scad>;
include <calculations/pcb.scad>;
include <calculations/screw.scad>;
include <calculations/side_cutout.scad>;
include <calculations/wall.scad>;
include <modules/face_outline.scad>;
include <modules/infrared_window_cutout.scad>;
include <modules/wall.scad>;

difference() {
  union () {
    linear_extrude(wall_height - wall_embed * 2) {
      difference() {
        face_outline();

        for (screw_xy_location = screw_xy_locations) {
          translate([screw_xy_location[0], screw_xy_location[1], 0]) {
            circle(d = screw_thread_diameter + screw_thread_tolerance * 2, $fn = screw_thread_sides);
          };
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
      };
    };

    translate([0, 0, -wall_embed]) {
      linear_extrude(wall_embed) {
        wall();
      };
    };
  };

  translate([
    0,
    0,
    -wall_embed,
  ]) {
    linear_extrude(pcb_back_clearance + wall_embed + button_cap_thickness - plate_thickness) {
      infrared_window_cutout();
    };
  };

  translate([
    overall_width - side_cutout_depth - wall_surround - wall_tolerance,
    0,
    0,
  ]) {
    cube([
      side_cutout_depth + wall_surround + wall_tolerance,
      side_cutout_inset + side_cutout_depth,
      keychain_thickness,
    ]);
  };
};
