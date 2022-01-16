/**
 * The diameter of the nozzle, in millimeters.  No features narrower than this can be produced.
 */
nozzle_diameter = 0.4;

/**
 * The height of a layer, in millimeters.  No features shorter than this can be produced.
 */
layer_height = 0.2;

/**
 * Added to small features to combat rounding errors.
 */
fudge = 0.00001;

/**
 * Cut out of any concave corners to prevent pinching.
 */
concave_corner_cut_size = 3;
