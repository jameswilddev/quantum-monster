include <../measurements/corner.scad>
include <../measurements/side_cutout.scad>
include <../calculations/overall.scad>
include <../calculations/side_cutout.scad>

module face_outline() {
  difference() {
    union() {
      translate([
        corner_radius,
        0,
      ]) {
        square([
          overall_width - corner_radius * 2,
          overall_height,
        ]);
      };

      translate([
        corner_radius / 2,
        corner_radius,
      ]) {
        square([
          overall_width - corner_radius,
          overall_height - corner_radius * 2,
        ]);
      };

      translate([
        corner_radius,
        corner_radius,
      ]) {
        circle(r = corner_radius, $fn = corner_sides * 4);
      };

      translate([
        overall_width - corner_radius,
        corner_radius,
      ]) {
        circle(r = corner_radius, $fn = corner_sides * 4);
      };

      translate([
        corner_radius,
        overall_height - corner_radius,
      ]) {
        circle(r = corner_radius, $fn = corner_sides * 4);
      };

      translate([
        overall_width - corner_radius,
        overall_height - corner_radius,
      ]) {
        circle(r = corner_radius, $fn = corner_sides * 4);
      };
    };

    polygon([
      [0, side_cutout_inset],
      [0, overall_height - side_cutout_inset],
      [side_cutout_depth, overall_height - side_cutout_inset - side_cutout_depth],
      [side_cutout_depth, side_cutout_inset + side_cutout_depth],
    ]);

    polygon([
      [overall_width, side_cutout_inset],
      [overall_width, overall_height - side_cutout_inset],
      [overall_width - side_cutout_depth, overall_height - side_cutout_inset - side_cutout_depth],
      [overall_width - side_cutout_depth, side_cutout_inset + side_cutout_depth],
    ]);
  };
};
