include <../measurements/pcb.scad>;
include <../calculations/pcb.scad>;
include <pcb_cutout.scad>;

module pcb_retainer() {
  difference() {
    pcb_cutout();

    translate([
      pcb_left + pcb_retainer_thickness,
      pcb_bottom + pcb_retainer_thickness,
    ]) {
      square([
        - pcb_retainer_thickness + pcb_width - pcb_retainer_thickness,
        - pcb_retainer_thickness + pcb_height - pcb_retainer_thickness,
      ]);
    };
  };
};
