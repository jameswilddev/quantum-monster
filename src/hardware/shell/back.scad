use <components/uncut.scad>;
use <components/wall.scad>;

intersection() {
  uncut();

  difference() {
    cube([
      wall_right(),
      wall_top(),
      wall_overlap_top(),
    ]);

    translate([
      wall_overlap_outer_left(),
      wall_overlap_outer_bottom(),
      wall_overlap_bottom(),
    ]) {
      cube([
        wall_overlap_outer_width(),
        wall_overlap_outer_height(),
        wall_overlap_height(),
      ]);
    };
  };
};
