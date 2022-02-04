use <components/display.scad>;
use <components/uncut.scad>;
use <components/wall.scad>;

intersection() {
  uncut();

  union() {
    translate([
      0,
      0,
      wall_overlap_top(),
    ]) {
      cube([
        wall_right(),
        wall_top(),
        display_bezel_front() - wall_overlap_top(),
      ]);
    };

    translate([
      wall_overlap_inner_left(),
      wall_overlap_inner_bottom(),
      wall_overlap_bottom(),
    ]) {
      cube([
        wall_overlap_inner_width(),
        wall_overlap_inner_height(),
        wall_overlap_height(),
      ]);
    };
  };
};
