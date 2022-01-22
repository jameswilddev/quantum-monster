include <measurements/display.scad>;

linear_extrude(display_pcb_distance) {
  difference() {
    union() {
      difference() {
        square([display_width, display_height]);

        translate([
          display_spacer_thickness,
          display_spacer_thickness,
        ]) {
          square([
            display_width - display_spacer_thickness * 2,
            display_height - display_spacer_thickness * 2,
          ]);
        };
      };

      translate([
        display_width - display_right_connector_right - display_connector_width - display_spacer_thickness,
        display_bottom_connector_bottom - display_spacer_thickness,
      ]) {
        square([
          display_spacer_thickness + display_connector_width + display_right_connector_right,
          display_spacer_thickness * 2 + display_connector_height,
        ]);
      };
    };

    translate([
      display_width - display_right_connector_right - display_connector_width - display_connector_tolerance,
      display_bottom_connector_bottom - display_connector_tolerance,
    ]) {
      square([
        display_connector_width + display_connector_tolerance * 2,
        display_connector_height + display_connector_tolerance * 2,
      ]);
    };
  };
};
