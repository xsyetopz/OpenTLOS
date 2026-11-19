#include "spyro/source/LavaDerick.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;

#if 0 // DRAFT: ')' expected
void LavaDerick::Message(MKMessage *arg0) {
    LavaDerick *spC;
    s32 sp8;
    void **temp_r3_61;
    void *temp_r3_65;

    if ((s32) arg0->unk0 != 0x12) {

    } else if ((s32) this->unk180 == (s32) (M2C_FIELD(checked_cast<LavaDerickDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160) - 1)) {
        temp_r3_61 = M2C_FIELD(checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0), void ***, 0xC);
        temp_r3_65 = M2C_FIELD(*temp_r3_61, void *(**)(void **), 0x2C)(temp_r3_61);
        if (temp_r3_65 != NULL) {
            spC = NULL;
            sp8 = 0x1A;
            spC = this;
            M2C_FIELD(M2C_FIELD(temp_r3_65, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
    Shatterable::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void *LavaDerickDescriptor::CalcBounds() {
    MKVector3 sp8;
    BoundingVolume *temp_r3_105;
    BoundingVolume *temp_r3_115;
    BoundingVolume *temp_r3_125;
    BoundingVolume *temp_r3_135;
    BoundingVolume *temp_r3_147;
    BoundingVolume *temp_r3_159;
    BoundingVolume *temp_r4_171;
    f32 temp_f1_107;
    f32 temp_f1_117;
    f32 temp_f1_127;
    f32 temp_f2_138;
    f32 temp_f2_150;
    f32 temp_f2_162;
    f32 var_f0_106;
    f32 var_f0_116;
    f32 var_f0_126;
    f32 var_f0_139;
    f32 var_f0_151;
    f32 var_f0_163;

    MKModel_CalculateRefPointWorldPosition(this->unk2C, (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "hurtsphere1"), &sp8);
    temp_r3_105 = this->unk1C;
    var_f0_106 = M2C_BITWISE(f32, sp8);
    temp_f1_107 = temp_r3_105->unk0;
    if (var_f0_106 < temp_f1_107) {

    } else {
        var_f0_106 = temp_f1_107;
    }
    temp_r3_105->unk0 = var_f0_106;
    temp_r3_115 = this->unk1C;
    var_f0_116 = sp8.unk4;
    temp_f1_117 = temp_r3_115->unk4;
    if (var_f0_116 < temp_f1_117) {

    } else {
        var_f0_116 = temp_f1_117;
    }
    temp_r3_115->unk4 = var_f0_116;
    temp_r3_125 = this->unk1C;
    var_f0_126 = sp8.unk8;
    temp_f1_127 = temp_r3_125->unk8;
    if (var_f0_126 < temp_f1_127) {

    } else {
        var_f0_126 = temp_f1_127;
    }
    temp_r3_125->unk8 = var_f0_126;
    temp_r3_135 = this->unk1C;
    temp_f2_138 = temp_r3_135->unk10;
    var_f0_139 = M2C_BITWISE(f32, sp8) - temp_r3_135->unk0;
    if (var_f0_139 > temp_f2_138) {

    } else {
        var_f0_139 = temp_f2_138;
    }
    temp_r3_135->unk10 = var_f0_139;
    temp_r3_147 = this->unk1C;
    temp_f2_150 = temp_r3_147->unk14;
    var_f0_151 = sp8.unk4 - temp_r3_147->unk4;
    if (var_f0_151 > temp_f2_150) {

    } else {
        var_f0_151 = temp_f2_150;
    }
    temp_r3_147->unk14 = var_f0_151;
    temp_r3_159 = this->unk1C;
    temp_f2_162 = temp_r3_159->unk18;
    var_f0_163 = sp8.unk8 - temp_r3_159->unk8;
    if (var_f0_163 > temp_f2_162) {

    } else {
        var_f0_163 = temp_f2_162;
    }
    temp_r3_159->unk18 = var_f0_163;
    temp_r4_171 = this->unk1C;
    M2C_FIELD(temp_r4_171, f32 *, 0x10) = (f64) ((f64) M2C_FIELD(temp_r4_171, f32 *, 0x10) - (f64) M2C_FIELD(temp_r4_171, f32 *, 0));
    temp_r4_171->unk18 -= temp_r4_171->unk8;
    return &temp_r4_171->unk10;
}
#endif

void LavaDerickDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    CalcBounds();
}

void LavaDerick_cpp::__sinit() {
    f32 temp_f0_247;
    f64 temp_f1_228;
    f64 temp_f1_236;
    f64 temp_f3_216;
    f64 temp_f4_225;
    f64 temp_f4_233;
    f64 temp_f8_218;

    temp_f3_216 = __frsqrte(2014000.0);
    temp_f8_218 = __frsqrte(380000.0);
    temp_f4_225 = 0.5 * temp_f3_216 * -((2014000.0 * (temp_f3_216 * temp_f3_216)) - 3.0);
    temp_f1_228 = 0.5 * temp_f8_218 * -((380000.0 * (temp_f8_218 * temp_f8_218)) - 3.0);
    temp_f4_233 = 0.5 * temp_f4_225 * -((2014000.0 * (temp_f4_225 * temp_f4_225)) - 3.0);
    temp_f1_236 = 0.5 * temp_f1_228 * -((380000.0 * (temp_f1_228 * temp_f1_228)) - 3.0);
    temp_f0_247 = (f32) (380000.0 * (0.5 * temp_f1_236 * -((380000.0 * (temp_f1_236 * temp_f1_236)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_233 * -((2014000.0 * (temp_f4_233 * temp_f4_233)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_247;
}
