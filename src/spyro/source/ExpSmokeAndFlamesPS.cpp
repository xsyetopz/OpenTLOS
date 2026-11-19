#include "spyro/source/ExpSmokeAndFlamesPS.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gExpSmokeAndFlamesPSEnv; /* unable to generate initializer: confusing struct layout */

void ExpSmokeAndFlamesPS::UpdateParticles() {
    f64 spD8;
    f64 spD0;
    MKVector4 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKParticleChunk *var_r27_67;
    MKParticleSystem::Envelope *temp_r3_139;
    f32 temp_f29_77;
    f32 temp_f3_117;
    f32 temp_f4_153;
    f32 temp_f5_146;
    f32 temp_f6_141;
    f32 var_f0_157;
    f64 temp_f0_89;
    s32 temp_r3_113;
    s32 temp_r3_127;
    s32 temp_r4_138;
    s32 temp_r6_142;
    void *temp_r26_73;
    void *temp_r3_176;
    void *temp_r5_144;

    this->unk128 += gUpdateTimeDelta;
    var_r27_67 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r27_67 != NULL) {
        temp_r26_73 = var_r27_67->unk2C;
        temp_f29_77 = this->unk128 - M2C_FIELD(temp_r26_73, f32 *, 0x10);
        if (temp_f29_77 > this->unk12C) {
            var_r27_67 = DestroyParticle(&unksp8);
        } else {
            temp_f0_89 = M2C_FIELD(temp_r26_73, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp60 = temp_f0_89;
            spD0 = temp_f0_89;
            sp68 = M2C_FIELD(temp_r26_73, f32 *, 8) * gUpdateTimeDelta;
            spD8 = (f64) sp68;
            M2C_FIELD(var_r27_67, f64 *, 0) = (f64) (M2C_FIELD(var_r27_67, f64 *, 0) + temp_f0_89);
            var_r27_67->unk8 += (f32) spD8;
            var_r27_67->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r26_73, f32 *, 0x18);
            temp_r3_113 = M2C_FIELD(checked_cast<ExpSmokeAndFlamesPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_117 = var_r27_67->unk20;
            var_r27_67->unk20 = (f32) fmod(temp_r3_113, temp_f3_117 + this->unkF0, (f32) temp_r3_113, temp_f3_117);
            temp_r3_127 = M2C_FIELD(temp_r26_73, s32 *, 0x14);
            if (temp_f29_77 > (this->unk12C * *(this->unk134 + (temp_r3_127 * 0x14)))) {
                M2C_FIELD(temp_r26_73, s32 *, 0x14) = (s32) (temp_r3_127 + 1);
            }
            temp_r4_138 = M2C_FIELD(temp_r26_73, s32 *, 0x14);
            temp_r3_139 = this->unk134;
            temp_f6_141 = this->unk12C;
            temp_r6_142 = (temp_r4_138 - 1) * 0x14;
            temp_r5_144 = temp_r3_139 + temp_r6_142;
            temp_f5_146 = M2C_FIELD(temp_r5_144, f32 *, 0);
            temp_f4_153 = -((temp_f6_141 * temp_f5_146) - temp_f29_77) / (temp_f6_141 * (*(temp_r3_139 + (temp_r4_138 * 0x14)) - temp_f5_146));
            var_r27_67->unk1C = M2C_FIELD(temp_r26_73, f32 *, 0x20) * ((temp_f4_153 * M2C_FIELD(temp_r5_144, f32 *, 0xC)) + M2C_FIELD(temp_r5_144, f32 *, 4));
            var_f0_157 = var_r27_67->unk1C;
            if (var_f0_157 < 1.0f) {

            } else {
                var_f0_157 = 1.0f;
            }
            if (var_f0_157 > 0.0f) {

            } else {
                var_f0_157 = 0.0f;
            }
            var_r27_67->unk1C = var_f0_157;
            temp_r3_176 = this->unk134 + temp_r6_142;
            sp50 = 0.0f;
            sp54 = 0.0f;
            sp58 = 0.0f;
            sp5C = 0.0f;
            sp4C = 0.0f;
            var_r27_67->unk28 = M2C_FIELD(temp_r26_73, f32 *, 0x1C) * ((temp_f4_153 * M2C_FIELD(temp_r3_176, f32 *, 0x10)) + M2C_FIELD(temp_r3_176, f32 *, 8));
            spB0 = (f64) sp50;
            sp48 = gUpdateTimeDelta;
            sp40 = gUpdateTimeDelta;
            sp44 = gUpdateTimeDelta;
            spB8 = (f64) sp58;
            sp80 = (f64) sp40;
            sp88 = (f64) sp48;
            sp30 = sp80 * 5.325712093e-315;
            sp38 = sp88 * 5.325712093e-315;
            sp90 = sp30;
            sp98 = sp38;
            sp20 = M2C_FIELD(var_r27_67, f64 *, 0x10) - sp90;
            sp28 = M2C_FIELD(var_r27_67, f64 *, 0x18) - sp98;
            sp10 = 1.0f;
            sp14 = 1.0f;
            sp18 = 1.0f;
            sp1C = 1.0f;
            spA0 = sp20;
            spA8 = sp28;
            sp70 = (f64) sp10;
            sp78 = (f64) sp18;
            Clamp<MKVector4>(spC0, *((MKVector4 *) &spB0), *((MKVector4 *) &spA0));
            M2C_FIELD(var_r27_67, f64 *, 0x10) = M2C_BITWISE(f64, spC0);
            M2C_FIELD(var_r27_67, f64 *, 0x18) = (f64) spC0.unk8;
            var_r27_67 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void ExpSmokeAndFlamesPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r3_363;
    void *temp_r4_366;

    temp_r3_363 = CreateParticle();
    if (temp_r3_363 != NULL) {
        temp_r4_366 = M2C_FIELD(temp_r3_363, void **, 0x2C);
        M2C_FIELD(temp_r3_363, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_363, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_363, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r4_366, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_366, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4_366, f32 *, 0x1C) = (f32) &arg2;
        M2C_FIELD(temp_r4_366, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r4_366, f32 *, 0x18) = 7.853982f;
        M2C_FIELD(temp_r3_363, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
    }
}
#endif

void ExpSmokeAndFlamesPS::Deinit() {
    MKParticleSystem::Deinit();
}

void ExpSmokeAndFlamesPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gExpSmokeAndFlamesPSEnv'
void ExpSmokeAndFlamesPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 150.5f;
    this->unkAC = 150.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gExpSmokeAndFlamesPSEnv, 5);
    SetMaxParticleAge(0.35f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif

void ExpSmokeAndFlamesPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
