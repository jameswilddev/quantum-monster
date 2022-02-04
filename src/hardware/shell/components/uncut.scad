use <button.scad>;
use <corner.scad>;
use <display.scad>;
use <infrared_window.scad>;
use <pcb.scad>;
use <print_settings.scad>;
use <side_inset.scad>;
use <screw.scad>;
use <speaker.scad>;

/**
 * The thickness of the back face, in millimeters.
 */
function back_thickness() = 1.6;

/**
 * The full shell, not cut into front or back pieces.
 */
module uncut() {
  difference() {
    union() {
      difference() {
        linear_extrude(display_bezel_front()) {
          difference() {
            hull() {
              for (corner_xy_location = corner_xy_locations()) {
                translate(corner_xy_location) {
                  circle(r = corner_radius(), $fn = corner_sides() * 4);
                };
              };
            };

            polygon(side_inset_left_vertices());
            polygon(side_inset_right_vertices());

            for (screw_xy_location = screw_xy_locations()) {
              translate(screw_xy_location) {
                circle(
                  d = screw_thread_cutout_diameter(),
                  $fn = screw_thread_cutout_sides()
                );
              };
            };
          };
        };

        translate([0, 0, display_bezel_front() - screw_head_pocket_depth() - print_settings_layer_height()]) {
          linear_extrude(print_settings_layer_height()) {
            for (screw_xy_location = screw_xy_locations()) {
              translate(screw_xy_location) {
                intersection() {
                  circle(
                    d = screw_head_pocket_diameter(),
                    $fn = screw_head_pocket_sides()
                  );
                  square([
                    screw_head_pocket_diameter(),
                    screw_thread_cutout_diameter(),
                  ], center = true);
                };
              };
            };
          };
        };

        translate([0, 0, display_bezel_front() - screw_head_pocket_depth() - print_settings_layer_height() * 2]) {
          linear_extrude(print_settings_layer_height()) {
            for (screw_xy_location = screw_xy_locations()) {
              translate(screw_xy_location) {
                square(screw_thread_cutout_diameter(), center = true);
              };
            };
          };
        };

        translate([
          0,
          0,
          pcb_back(),
        ]) {
          linear_extrude(pcb_thickness()) {
            translate([
              pcb_left(),
              pcb_bottom(),
            ]) {
              square([
                pcb_width(),
                pcb_height(),
              ]);
            };

            translate([
              pcb_left(),
              pcb_bottom(),
            ]) {
              rotate(45) {
                square(print_settings_concave_corner_cut_size(), center = true);
              };
            };

            translate([
              pcb_right(),
              pcb_bottom(),
            ]) {
              rotate(45) {
                square(print_settings_concave_corner_cut_size(), center = true);
              };
            };

            translate([
              pcb_left(),
              pcb_top(),
            ]) {
              rotate(45) {
                square(print_settings_concave_corner_cut_size(), center = true);
              };
            };

            translate([
              pcb_right(),
              pcb_top(),
            ]) {
              rotate(45) {
                square(print_settings_concave_corner_cut_size(), center = true);
              };
            };
          };
        };

        translate([
          pcb_clearance_left(),
          pcb_clearance_bottom(),
          back_thickness(),
        ]) {
          cube([
            pcb_clearance_width(),
            pcb_clearance_height(),
            pcb_back_clearance(),
          ]);
        };

        translate([
          pcb_clearance_left(),
          pcb_clearance_bottom(),
          pcb_front(),
        ]) {
          cube([
            pcb_clearance_width(),
            pcb_clearance_height(),
            pcb_front_clearance(),
          ]);
        };

        for (y = button_y_locations()) {
          translate([
            button_x(),
            y,
            button_cap_back(),
          ]) {
            linear_extrude(button_cap_thickness()) {
              hull() {
                translate([
                  button_cutout_size() / 2 - button_cutout_radius_size(),
                  button_cutout_size() / 2 - button_cutout_radius_size(),
                ]) {
                  circle(
                    r = button_cutout_radius_size(),
                    $fn = button_cutout_radius_sides() * 4
                  );
                };

                translate([
                  button_cutout_size() / 2 - button_cutout_radius_size(),
                  button_cutout_radius_size() + button_cutout_size() / -2,
                ]) {
                  circle(
                    r = button_cutout_radius_size(),
                    $fn = button_cutout_radius_sides() * 4
                  );
                };

                translate([
                  button_cutout_radius_size() + button_cutout_size() / -2,
                  button_cutout_size() / 2 - button_cutout_radius_size(),
                ]) {
                  circle(
                    r = button_cutout_radius_size(),
                    $fn = button_cutout_radius_sides() * 4
                  );
                };

                translate([
                  button_cutout_radius_size() + button_cutout_size() / -2,
                  button_cutout_radius_size() + button_cutout_size() / -2,
                ]) {
                  circle(
                    r = button_cutout_radius_size(),
                    $fn = button_cutout_radius_sides() * 4
                  );
                };
              };
            };
          };
        };
      };

      linear_extrude(pcb_back()) {
        for (y = button_y_locations()) {
          translate([
            button_x(),
            y,
            0,
          ]) {
            square(button_rear_support_size(), center = true);
          };
        };
      };

      translate([
        speaker_x(),
        speaker_y(),
        0,
      ]) {
        cylinder(d = speaker_diameter(), $fn = speaker_sides(), h = speaker_back());
      };

      translate([
        display_wall_left(),
        display_wall_bottom(),
        pcb_front(),
      ]) {
        cube([
          display_wall_width(),
          display_wall_height(),
          pcb_front_clearance(),
        ]);
      };

      for (y = button_y_locations()) {
        translate([
          button_x() + button_cutout_size() / 2 - button_cap_gap(),
          y - button_cutout_size() / 2 + button_cutout_radius_size() + button_cap_gap(),
          button_cap_back(),
        ]) {
          cube([
            button_cap_gap(),
            button_cutout_size() - button_cutout_radius_size() * 2 - button_cap_gap() * 2,
            button_cap_sprue_thickness(),
          ]);
        };

        translate([
          button_x(),
          y,
          button_cap_back(),
        ]) {
          linear_extrude(button_cap_thickness()) {
            hull() {
              translate([
                button_cutout_size() / 2 - button_cutout_radius_size(),
                button_cutout_size() / 2 - button_cutout_radius_size(),
              ]) {
                circle(
                  r = button_cutout_radius_size() - button_cap_gap(),
                  $fn = button_cutout_radius_sides() * 4
                );
              };

              translate([
                button_cutout_size() / 2 - button_cutout_radius_size(),
                button_cutout_radius_size() + button_cutout_size() / -2,
              ]) {
                circle(
                  r = button_cutout_radius_size() - button_cap_gap(),
                  $fn = button_cutout_radius_sides() * 4
                );
              };

              translate([
                button_cutout_radius_size() + button_cutout_size() / -2,
                button_cutout_size() / 2 - button_cutout_radius_size(),
              ]) {
                circle(
                  r = button_cutout_radius_size() - button_cap_gap(),
                  $fn = button_cutout_radius_sides() * 4
                );
              };

              translate([
                button_cutout_radius_size() + button_cutout_size() / -2,
                button_cutout_radius_size() + button_cutout_size() / -2,
              ]) {
                circle(
                  r = button_cutout_radius_size() - button_cap_gap(),
                  $fn = button_cutout_radius_sides() * 4
                );
              };
            };
          };
        };
      };
    };

    translate([
      speaker_x(),
      speaker_y(),
      0,
    ]) {
      cylinder(d = speaker_hole_diameter(), $fn = speaker_hole_sides(), h = speaker_back());
    };

    translate([
      0,
      0,
      pcb_front(),
    ]) {
      linear_extrude(display_spacer_thickness() + display_thickness()) {
        translate([
          display_left(),
          display_bottom(),
        ]) {
          square([
            display_width(),
            display_height(),
          ]);
        };

        translate([
          display_left(),
          display_bottom(),
        ]) {
          rotate(45) {
            square(print_settings_concave_corner_cut_size(), center = true);
          };
        };

        translate([
          display_right(),
          display_bottom(),
        ]) {
          rotate(45) {
            square(print_settings_concave_corner_cut_size(), center = true);
          };
        };

        translate([
          display_left(),
          display_top(),
        ]) {
          rotate(45) {
            square(print_settings_concave_corner_cut_size(), center = true);
          };
        };

        translate([
          display_right(),
          display_top(),
        ]) {
          rotate(45) {
            square(print_settings_concave_corner_cut_size(), center = true);
          };
        };
      };
    };

    translate([
      0,
      0,
      display_bezel_back(),
    ]) {
      linear_extrude(display_bezel_thickness()) {
        hull() {
          translate([
            display_cutout_left() + display_radius_size(),
            display_cutout_bottom() + display_radius_size(),
          ]) {
            circle(
              r = display_radius_size(),
              $fn = display_radius_sides() * 4
            );
          };
          translate([
            display_cutout_left() + display_radius_size(),
            display_cutout_top() - display_radius_size(),
          ]) {
            circle(
              r = display_radius_size(),
              $fn = display_radius_sides() * 4
            );
          };
          translate([
            display_cutout_right() - display_radius_size(),
            display_cutout_bottom() + display_radius_size(),
          ]) {
            circle(
              r = display_radius_size(),
              $fn = display_radius_sides() * 4
            );
          };
          translate([
            display_cutout_right() - display_radius_size(),
            display_cutout_top() - display_radius_size(),
          ]) {
            circle(
              r = display_radius_size(),
              $fn = display_radius_sides() * 4
            );
          };
        };
      };
    };

    translate([
      infrared_window_cutout_left(),
      infrared_window_cutout_bottom(),
      infrared_window_cutout_back(),
    ]) {
      cube([
        infrared_window_cutout_width(),
        infrared_window_cutout_height(),
        infrared_window_cutout_depth(),
      ]);
    };

    translate([0, infrared_window_top(), 0]) {
      rotate([90, 0, 0]) {
        linear_extrude(infrared_window_height()) {
          hull() {
            translate([
              infrared_window_left() + infrared_window_radius_size(),
              infrared_window_back() + infrared_window_radius_size(),
            ]) {
              circle(
                r = infrared_window_radius_size(),
                $fn = infrared_window_radius_sides() * 4
              );
            };

            translate([
              infrared_window_right() - infrared_window_radius_size(),
              infrared_window_back() + infrared_window_radius_size(),
            ]) {
              circle(
                r = infrared_window_radius_size(),
                $fn = infrared_window_radius_sides() * 4
              );
            };

            translate([
              infrared_window_left() + infrared_window_radius_size(),
              infrared_window_front() - infrared_window_radius_size(),
            ]) {
              circle(
                r = infrared_window_radius_size(),
                $fn = infrared_window_radius_sides() * 4
              );
            };

            translate([
              infrared_window_right() - infrared_window_radius_size(),
              infrared_window_front() - infrared_window_radius_size(),
            ]) {
              circle(
                r = infrared_window_radius_size(),
                $fn = infrared_window_radius_sides() * 4
              );
            };
          };
        };
      };
    };

    linear_extrude(screw_nut_pocket_depth()) {
      for (screw_xy_location = screw_xy_locations()) {
        translate(screw_xy_location) {
          rotate(90) {
            circle(
              d = screw_nut_pocket_diameter(),
              $fn = screw_nut_pocket_sides()
            );
          };
        };
      };
    };

    translate([0, 0, display_bezel_front() - screw_head_pocket_depth()]) {
      linear_extrude(screw_head_pocket_depth()) {
        for (screw_xy_location = screw_xy_locations()) {
          translate(screw_xy_location) {
            circle(
              d = screw_head_pocket_diameter(),
              $fn = screw_head_pocket_sides()
            );
          };
        };
      };
    };
  };
};
