#include "spyro/source/CreationTable.h"
#include "common/Source/MKAnimScript.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TrainChaseSpyro.h"
#include <m2c_macros.h>

M2C_UNK __construct_array(KDUniformSpline *, MKAnimScript *(*)(MKAnimScript *), SpyroSoundPlayer::SpyroLoopSounds *(*)(SpyroSoundPlayer::SpyroLoopSounds *, s16), M2C_UNK, M2C_UNK, void *, M2C_UNK); /* extern */
TrainChaseSpyro *malloc(s32);                       /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;

void CreationTable_cpp::__sinit() {
    f32 temp_f0_24561;
    f64 temp_f1_24542;
    f64 temp_f1_24550;
    f64 temp_f3_24530;
    f64 temp_f4_24539;
    f64 temp_f4_24547;
    f64 temp_f8_24532;

    temp_f3_24530 = __frsqrte(2014000.0);
    temp_f8_24532 = __frsqrte(380000.0);
    temp_f4_24539 = 0.5 * temp_f3_24530 * -((2014000.0 * (temp_f3_24530 * temp_f3_24530)) - 3.0);
    temp_f1_24542 = 0.5 * temp_f8_24532 * -((380000.0 * (temp_f8_24532 * temp_f8_24532)) - 3.0);
    temp_f4_24547 = 0.5 * temp_f4_24539 * -((2014000.0 * (temp_f4_24539 * temp_f4_24539)) - 3.0);
    temp_f1_24550 = 0.5 * temp_f1_24542 * -((380000.0 * (temp_f1_24542 * temp_f1_24542)) - 3.0);
    temp_f0_24561 = (f32) (380000.0 * (0.5 * temp_f1_24550 * -((380000.0 * (temp_f1_24550 * temp_f1_24550)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_24547 * -((2014000.0 * (temp_f4_24547 * temp_f4_24547)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_24561;
}
