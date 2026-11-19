#include "spyro/source/EarthBeamFX.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;

void EarthBeamFX_cpp::__sinit() {
    f32 temp_f0_55;
    f64 temp_f1_36;
    f64 temp_f1_44;
    f64 temp_f3_24;
    f64 temp_f4_33;
    f64 temp_f4_41;
    f64 temp_f8_26;

    temp_f3_24 = __frsqrte(2014000.0);
    temp_f8_26 = __frsqrte(380000.0);
    temp_f4_33 = 0.5 * temp_f3_24 * -((2014000.0 * (temp_f3_24 * temp_f3_24)) - 3.0);
    temp_f1_36 = 0.5 * temp_f8_26 * -((380000.0 * (temp_f8_26 * temp_f8_26)) - 3.0);
    temp_f4_41 = 0.5 * temp_f4_33 * -((2014000.0 * (temp_f4_33 * temp_f4_33)) - 3.0);
    temp_f1_44 = 0.5 * temp_f1_36 * -((380000.0 * (temp_f1_36 * temp_f1_36)) - 3.0);
    temp_f0_55 = (f32) (380000.0 * (0.5 * temp_f1_44 * -((380000.0 * (temp_f1_44 * temp_f1_44)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_41 * -((2014000.0 * (temp_f4_41 * temp_f4_41)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_55;
}
