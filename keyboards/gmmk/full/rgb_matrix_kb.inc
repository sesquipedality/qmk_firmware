// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(contrast)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool contrast(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  static bool contrast_array[] = {
    1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,     1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0,  1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,  0, 0, 0,  0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,               0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,        1,     0, 0, 0, 1,
    0, 0, 0,          1,       0, 0, 0, 0,     1, 1, 1,  0, 0,
    0, /* Extra ISO key */
  };

  for (uint8_t i = led_min; i < led_max; i++) {
    if (contrast_array[i]) {
//      rgb_matrix_set_color(i, 96, 171, 214);
      rgb_matrix_set_color(i, 0x00, 0xff, 0xff);
    } else {
//      rgb_matrix_set_color(i, 233, 109, 207);
      rgb_matrix_set_color(i, 0xff, 0x00, 0xff);

    }
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
