#include "spyro/source/WeatherAshPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gWeatherAshPSEnv; /* unable to generate initializer: confusing struct layout */

void WeatherAshPS::UpdateParticles() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    MKVector3 sp50;
    M2C_UNK sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r31_74;
    MKParticleSystem::Envelope *temp_r3_211;
    f32 temp_f25_140;
    f32 temp_f26_143;
    f32 temp_f27_147;
    f32 temp_f28_81;
    f32 temp_f29_137;
    f32 temp_f3_189;
    f32 temp_f3_224;
    f32 temp_f4_217;
    f32 temp_f5_213;
    f32 var_f0_227;
    f64 temp_f0_114;
    f64 temp_f0_161;
    f64 temp_f0_93;
    s32 temp_r3_185;
    s32 temp_r3_199;
    s32 temp_r4_210;
    s32 temp_r6_214;
    void *temp_r30_77;
    void *temp_r5_215;
    void *temp_r5_247;

    this->unk128 += gUpdateTimeDelta;
    var_r31_74 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r31_74 != NULL) {
        temp_r30_77 = var_r31_74->unk2C;
        temp_f28_81 = this->unk128 - M2C_FIELD(temp_r30_77, f32 *, 0x10);
        if (temp_f28_81 > this->unk12C) {
            var_r31_74 = DestroyParticle(&unksp8);
        } else {
            temp_f0_93 = M2C_FIELD(temp_r30_77, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp30 = temp_f0_93;
            sp80 = temp_f0_93;
            sp38 = M2C_FIELD(temp_r30_77, f32 *, 8) * gUpdateTimeDelta;
            sp88 = (f64) sp38;
            M2C_FIELD(var_r31_74, f64 *, 0) = (f64) (M2C_FIELD(var_r31_74, f64 *, 0) + temp_f0_93);
            var_r31_74->unk8 += (f32) sp88;
            temp_f0_114 = M2C_FIELD(this, f64 *, 0x108) * (f64) gUpdateTimeDelta;
            sp20 = temp_f0_114;
            sp70 = temp_f0_114;
            sp28 = this->unk110 * gUpdateTimeDelta;
            sp78 = (f64) sp28;
            M2C_FIELD(temp_r30_77, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_77, f64 *, 0) + temp_f0_114);
            M2C_FIELD(temp_r30_77, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_77, f32 *, 8) + (f32) sp78);
            temp_f29_137 = gUpdateTimeDelta;
            temp_f25_140 = 3.0f * (6.2831855f * (temp_f28_81 / this->unk12C));
            temp_f26_143 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
            temp_f27_147 = _table_sinf((0.25f * temp_f25_140) + 1.5707964f);
            MKVector(_table_sinf(temp_f25_140), 0.0f, temp_f27_147);
            sp50.operator*(100.0f * temp_f26_143);
            temp_f0_161 = sp50 * (f64) temp_f29_137;
            sp10 = temp_f0_161;
            sp60 = temp_f0_161;
            sp18 = sp50.unk8 * temp_f29_137;
            sp68 = (f64) sp18;
            M2C_FIELD(var_r31_74, f64 *, 0) = (f64) (M2C_FIELD(var_r31_74, f64 *, 0) + temp_f0_161);
            var_r31_74->unk8 += (f32) sp68;
            var_r31_74->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r30_77, f32 *, 0x1C);
            temp_r3_185 = M2C_FIELD(checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_189 = var_r31_74->unk20;
            var_r31_74->unk20 = (f32) fmod(temp_r3_185, temp_f3_189 + this->unkF0, (f32) temp_r3_185, temp_f3_189);
            temp_r3_199 = M2C_FIELD(temp_r30_77, s32 *, 0x14);
            if (temp_f28_81 > (this->unk12C * *(this->unk134 + (temp_r3_199 * 0x14)))) {
                M2C_FIELD(temp_r30_77, s32 *, 0x14) = (s32) (temp_r3_199 + 1);
            }
            temp_r4_210 = M2C_FIELD(temp_r30_77, s32 *, 0x14);
            temp_r3_211 = this->unk134;
            temp_f5_213 = this->unk12C;
            temp_r6_214 = (temp_r4_210 - 1) * 0x14;
            temp_r5_215 = temp_r3_211 + temp_r6_214;
            temp_f4_217 = M2C_FIELD(temp_r5_215, f32 *, 0);
            temp_f3_224 = -((temp_f5_213 * temp_f4_217) - temp_f28_81) / (temp_f5_213 * (*(temp_r3_211 + (temp_r4_210 * 0x14)) - temp_f4_217));
            var_r31_74->unk1C = (temp_f3_224 * M2C_FIELD(temp_r5_215, f32 *, 0xC)) + M2C_FIELD(temp_r5_215, f32 *, 4);
            var_f0_227 = var_r31_74->unk1C;
            if (var_f0_227 < 1.0f) {

            } else {
                var_f0_227 = 1.0f;
            }
            if (var_f0_227 > 0.0f) {

            } else {
                var_f0_227 = 0.0f;
            }
            var_r31_74->unk1C = var_f0_227;
            temp_r5_247 = this->unk134 + temp_r6_214;
            var_r31_74->unk28 = M2C_FIELD(temp_r30_77, f32 *, 0x18) * ((temp_f3_224 * M2C_FIELD(temp_r5_247, f32 *, 0x10)) + M2C_FIELD(temp_r5_247, f32 *, 8));
            var_r31_74 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void WeatherAshPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r31_295;
    void *temp_r3_292;

    temp_r3_292 = CreateParticle();
    if (temp_r3_292 != NULL) {
        temp_r31_295 = M2C_FIELD(temp_r3_292, void **, 0x2C);
        M2C_FIELD(temp_r3_292, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_292, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_292, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r31_295, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_295, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_295, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r31_295, f32 *, 0x1C) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r31_295, s32 *, 0x14) = 0;
    }
}
#endif

void WeatherAshPS::Deinit() {
    MKParticleSystem::Deinit();
}

void WeatherAshPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gWeatherAshPSEnv'
void WeatherAshPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = -100.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gWeatherAshPSEnv, 5);
    SetMaxParticleAge(5.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif
