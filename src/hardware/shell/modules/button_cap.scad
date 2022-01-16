include <../measurements/button.scad>;
include <../calculations/pcb.scad>;

module button_cap() {
  minkowski() {
    for (button_cap_polygon = button_cap_polygons_relative_to_pcb) {
      polygon([
        for (vertex = button_cap_polygon) [
          vertex[0] + pcb_left,
          vertex[1] + pcb_bottom,
        ]
      ]);
    };

    circle(r = button_cap_radius, $fn = button_cap_sides);
  };
};
