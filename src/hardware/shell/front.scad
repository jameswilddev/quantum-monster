include <measurements/button.scad>;
include <measurements/display.scad>;
include <measurements/plate.scad>;
include <measurements/print_settings.scad>;
include <measurements/screw.scad>;
include <calculations/button.scad>;
include <calculations/display.scad>;
include <calculations/overall.scad>;
include <calculations/screw.scad>;
include <modules/button_cap.scad>;
include <modules/button_cutout.scad>;
include <modules/concave_corner_cuts.scad>;
include <modules/display_cutout.scad>;
include <modules/display_wall.scad>;
include <modules/display_window.scad>;
include <modules/face_outline.scad>;
include <modules/pcb_cutout.scad>;
include <modules/pcb_retainer.scad>;
include <modules/screw_hole.scad>;
include <modules/wall_groove.scad>;

difference() {
  union() {
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

        linear_extrude(display_bezel_thickness) {
          display_cutout();
        };
      };

      linear_extrude(display_bezel_thickness) {
        display_window();
      };

      linear_extrude(button_cap_thickness) {
        button_cutout();
      };
    };

    linear_extrude(display_bezel_thickness + display_thickness + display_z_tolerance) {
      display_wall();
    };

    linear_extrude(display_bezel_thickness + display_thickness + display_pcb_distance - pcb_z_tolerance) {
      pcb_retainer();
    };

    linear_extrude(button_cap_thickness) {
      button_cap();
    };

    translate([0, 0, button_cap_thickness - button_cap_retainer_thickness]) {
      linear_extrude(button_cap_retainer_thickness) {
        intersection() {
          button_cutout();

          for (location = button_locations_relative_to_pcb) {
            translate([
              location[0] + pcb_left,
              location[1] + pcb_bottom,
            ]) {
              square([overall_width, button_cap_sprue_width], center = true);
            };
          };
        };
      };
    };

    translate([0, display_bottom - display_xy_tolerance, 0]) {
      rotate([-90, 0, 0]) {
        linear_extrude(display_height + display_xy_tolerance* 2) {
          polygon([
            [
              display_left - display_xy_tolerance,
              - display_bezel_thickness - display_z_tolerance - display_thickness,
            ],
            [
              display_left - display_xy_tolerance,
              - display_bezel_thickness - display_z_tolerance - display_clip_thickness - display_thickness,
            ],
            [
              display_left + display_clip_width - display_xy_tolerance,
              - display_bezel_thickness - display_z_tolerance - display_clip_thickness - display_thickness,
            ],
          ]);
        };
      };
    };
  };

  for (screw_xy_location = screw_xy_locations) {
    translate([screw_xy_location[0], screw_xy_location[1], 0]) {
      screw_hole(screw_head_depth, screw_head_diameter, screw_head_tolerance, screw_head_sides);
    };
  };

  translate([0, 0, plate_thickness - wall_embed]) {
    linear_extrude(wall_embed) {
      wall_groove();
    };
  };

  translate([0, 0, display_bezel_thickness]) {
    linear_extrude(overall_depth) {
      concave_corner_cuts();
    };
  };
};
