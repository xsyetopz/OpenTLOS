#include "spyro/source/SparxPath.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Game.h"
#include "spyro/source/Sparx.h"
#include "spyro/source/SplineProp.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern GameGlobals gb;
#if 0 // DRAFT: illegal operand
static s8 lit_stringBase0[0x11] = {
    0x53,
    0x70,
    0x65,
    0x65,
    0x64,
    0,
    0x4F,
    0x6E,
    0x43,
    0x6F,
    0x6D,
    0x70,
    0x6C,
    0x65,
    0x74,
    0x65,
    0,
}; /* const */

void SparxPath::Message(MKMessage *arg0) {
    Sparx *temp_r3_77;
    s32 temp_r0_58;

    temp_r0_58 = arg0->unk0;
    switch (temp_r0_58) {                           /* irregular */
    case 0xB5:
        gb.GetSpyro();
        ((Sparx *) (M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Sparx **, 0xB70)))->SetPath(this);
        break;
    case 0xB4:
        gb.GetSpyro();
        temp_r3_77 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Sparx **, 0xB70);
        if ((u32) temp_r3_77->unk1F4 == this) {
            temp_r3_77->SetPath(NULL);
        }
        break;
    }
    MKProp::Message(arg0);
}
#endif

void SparxPath::Resolve() {
    MKProp::Resolve();
    this->unk50.unk70 *= 100.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char[17]' to
s32 SparxPath::LoadLine(MKIniLine *arg0) {
    s32 var_r31_123;

    var_r31_123 = 0;
    if ((SplineProp::LoadLine(arg0) != 0) || (arg0->LoadFloat(lit_stringBase0, &this->unk50.unk70, 0) != 0) || (this->unk50.unk74.LoadLine(arg0, &lit_stringBase0[6]) != 0)) {
        var_r31_123 = 1;
    }
    return var_r31_123;
}
#endif

void SparxPath::Deinit() {
    SplineProp::Deinit();
}

void SparxPath::Init() {
    this->unk50.unk70 = 200.0f;
    SplineProp::Init();
}

void SparxPath_cpp::__sinit() {
    f32 temp_f0_217;
    f64 temp_f1_198;
    f64 temp_f1_206;
    f64 temp_f3_186;
    f64 temp_f4_195;
    f64 temp_f4_203;
    f64 temp_f8_188;

    temp_f3_186 = __frsqrte(2014000.0);
    temp_f8_188 = __frsqrte(380000.0);
    temp_f4_195 = 0.5 * temp_f3_186 * -((2014000.0 * (temp_f3_186 * temp_f3_186)) - 3.0);
    temp_f1_198 = 0.5 * temp_f8_188 * -((380000.0 * (temp_f8_188 * temp_f8_188)) - 3.0);
    temp_f4_203 = 0.5 * temp_f4_195 * -((2014000.0 * (temp_f4_195 * temp_f4_195)) - 3.0);
    temp_f1_206 = 0.5 * temp_f1_198 * -((380000.0 * (temp_f1_198 * temp_f1_198)) - 3.0);
    temp_f0_217 = (f32) (380000.0 * (0.5 * temp_f1_206 * -((380000.0 * (temp_f1_206 * temp_f1_206)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_203 * -((2014000.0 * (temp_f4_203 * temp_f4_203)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_217;
}
