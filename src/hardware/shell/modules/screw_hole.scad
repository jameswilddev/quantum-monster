include <../measurements/screw.scad>;
include <../measurements/plate.scad>;
include <../measurements/print_settings.scad>;

module screw_hole(head_depth, head_diameter, head_tolerance, head_sides) {
  rotate([0,, 0, 90]) {
    cylinder(
      d = head_diameter + head_tolerance * 2,
      h = head_depth,
      $fn = head_sides
    );
  };

  translate([
    0,
    0,
    head_depth,
  ]) {
    linear_extrude(layer_height) {
      intersection() {
        circle(d = head_diameter + head_tolerance * 2, $fn = head_sides);
        square([
          head_diameter + head_tolerance * 2,
          screw_thread_diameter + screw_thread_tolerance * 2
        ], center = true);
      };
    };
  };

  translate([
    0,
    0,
    head_depth + layer_height,
  ]) {
    linear_extrude(layer_height) {
      intersection() {
        circle(d = head_diameter + head_tolerance * 2, $fn = head_sides);
        square(screw_thread_diameter + screw_thread_tolerance * 2, center = true);
      };
    };
  };

  translate([
    0,
    0,
    head_depth + layer_height * 2,
  ]) {
    cylinder(
      d = screw_thread_diameter + screw_thread_tolerance * 2,
      h = plate_thickness - head_depth + layer_height * 2,
      $fn = screw_thread_sides
    );
  };
};
