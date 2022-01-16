include <calculations/overall.scad>;
include <modules/infrared_window.scad>;

linear_extrude(wall_height) {
  infrared_window();
};
