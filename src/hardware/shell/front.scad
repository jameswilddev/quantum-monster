include <measurements/display.scad>;
include <measurements/pcb.scad>;

difference() {
  cube([
    pcb_width + pcb_wall_thickness * 2 + pcb_xy_tolerance * 2,
    pcb_height + pcb_wall_thickness * 2 + pcb_xy_tolerance * 2,
    pcb_thickness + display_pcb_distance + display_thickness + bezel_thickness,
  ]);

  difference() {
    translate([
      pcb_wall_thickness,
      pcb_wall_thickness,
      0,
    ]) {
      cube([
        pcb_width + pcb_xy_tolerance * 2,
        pcb_height + pcb_xy_tolerance * 2,
        pcb_thickness + display_pcb_distance + display_thickness,
      ]);
    };

    translate([
      pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance - display_wall_thickness,
      pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom - display_xy_tolerance - display_wall_thickness,
      pcb_thickness,
    ]) {
      cube([
        display_width + display_xy_tolerance * 2 + display_wall_thickness * 2,
        display_height + display_xy_tolerance * 2 + display_wall_thickness * 2,
        display_pcb_distance + display_thickness,
      ]);
    };
  };

  difference() {
    translate([
      pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance,
      pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom - display_xy_tolerance,
      pcb_thickness,
    ]) {
      cube([
        display_width + display_xy_tolerance * 2,
        display_height + display_xy_tolerance * 2,
        display_pcb_distance + display_thickness,
      ]);
    };
  };

  translate([
    0,
    0,
    pcb_thickness + display_pcb_distance + display_thickness,
  ]) {
    linear_extrude(bezel_thickness) {
      hull() {
        translate([
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance / 2 + display_left_padding + display_radius_size - display_cutout_margin,
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom - display_xy_tolerance / 2 + display_bottom_padding + display_radius_size - display_cutout_margin,
        ]) {
          circle(r = display_radius_size, $fn = display_radius_sides * 4);
        };

        translate([
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left + display_width + display_xy_tolerance / 2 - display_right_padding - display_radius_size + display_cutout_margin,
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom - display_xy_tolerance / 2 + display_bottom_padding + display_radius_size - display_cutout_margin,
        ]) {
          circle(r = display_radius_size, $fn = display_radius_sides * 4);
        };

        translate([
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance / 2 + display_left_padding + display_radius_size - display_cutout_margin,
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom + display_height + display_xy_tolerance / 2 - display_top_padding - display_radius_size + display_cutout_margin,
        ]) {
          circle(r = display_radius_size, $fn = display_radius_sides * 4);
        };

        translate([
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left + display_width + display_xy_tolerance / 2 - display_right_padding - display_radius_size + display_cutout_margin,
          pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom + display_height + display_xy_tolerance / 2 - display_top_padding - display_radius_size + display_cutout_margin,
        ]) {
          circle(r = display_radius_size, $fn = display_radius_sides * 4);
        };
      };
    };
  }

  /*translate([
    pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance / 2 + display_left_padding,
    pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom - display_xy_tolerance / 2 + display_bottom_padding,
    pcb_thickness + display_pcb_distance + display_thickness,
  ]) {
    cube([
      display_width + display_xy_tolerance - display_left_padding - display_right_padding,
      display_height + display_xy_tolerance - display_bottom_padding - display_top_padding,
      bezel_thickness,
    ]);
  };*/
};

  translate([
    0,
    pcb_wall_thickness + pcb_xy_tolerance + display_pcb_bottom - display_xy_tolerance,
    0,
  ]) {
    rotate([-90, 0, 0]) {
      linear_extrude(display_height + display_xy_tolerance * 2) {
        polygon([
          [pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance, -pcb_thickness - display_pcb_distance + display_z_tolerance],
          [pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance, -pcb_thickness - display_pcb_distance + display_z_tolerance + display_clip_thickness],
          [pcb_wall_thickness + pcb_xy_tolerance + display_pcb_left - display_xy_tolerance + display_clip_width, -pcb_thickness - display_pcb_distance + display_z_tolerance + display_clip_thickness],
        ]);
      };
    };
  };
