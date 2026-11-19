#include "common/Source/MKParticleSystem.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

f64 fmod(f32, f32, f32);                            /* extern */
extern f32 gUpdateTimeDelta;
static MKParticleSystem::Envelope gDefaultEnvelope[2] = { { 0.0f, 1.0f, 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 0.0f, 0.0f } };

void MKParticleSystem::SetMaxParticleAge(float arg0) {
    this->unk12C = arg0;
    CalculateEnvelope();
}

void *MKParticleSystem::HitFloor(MKBaseParticleSystem::ParticleRec *arg1, bool *arg2) {
    f32 temp_f1_27;
    f32 temp_f2_30;
    MKParticleChunk *temp_r5_28;
    void *temp_r6_32;

    *arg2 = 0;
    temp_f1_27 = this->unk11C;
    temp_r5_28 = M2C_FIELD(arg1, MKParticleChunk **, 4);
    temp_f2_30 = temp_r5_28->unk4;
    temp_r6_32 = temp_r5_28->unk2C;
    if (temp_f2_30 >= (temp_f1_27 - this->unk120)) {
        temp_r5_28->unk4 = temp_f1_27;
        M2C_FIELD(temp_r6_32, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r6_32, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_32, f32 *, 8) = 0.0f;
    } else {
        temp_r5_28->unk4 = (f32) (temp_f1_27 + (temp_f1_27 - temp_f2_30));
        M2C_FIELD(temp_r6_32, f32 *, 4) = (f32) (this->unk124 * (f32) __fabs(M2C_FIELD(temp_r6_32, f32 *, 4)));
    }
    return M2C_FIELD(arg1, MKParticleChunk **, 4);
}

#if 0 // DRAFT: undefined identifier 'unkspC'
void MKParticleSystem::UpdateParticles() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    u8 sp8;
    MKParticleChunk *var_r30_113;
    MKParticleSystem::Envelope *temp_r3_201;
    MKParticleSystem::Envelope *temp_r3_238;
    MKParticleSystem::Envelope *temp_r5_206;
    f32 temp_f26_121;
    f32 temp_f27_85;
    f32 temp_f31_157;
    f32 temp_f3_215;
    f32 temp_f5_208;
    f32 temp_f6_203;
    f32 var_f0_219;
    f64 temp_f0_140;
    f64 temp_f0_87;
    f64 temp_f0_98;
    s32 temp_r0_202;
    s32 temp_r3_189;
    s32 temp_r4_200;
    void *temp_r29_117;
    void *temp_r31_84;

    this->unk128 += gUpdateTimeDelta;
    temp_r31_84 = this->unk0;
    temp_f27_85 = gUpdateTimeDelta * this->unkF0;
    temp_f0_87 = M2C_FIELD(this, f64 *, 0xF8) * (f64) gUpdateTimeDelta;
    sp38 = temp_f0_87;
    sp68 = temp_f0_87;
    sp40 = this->unk100 * gUpdateTimeDelta;
    sp70 = (f64) sp40;
    temp_f0_98 = M2C_FIELD(this, f64 *, 0x108) * (f64) gUpdateTimeDelta;
    sp28 = temp_f0_98;
    sp58 = temp_f0_98;
    sp30 = this->unk110 * gUpdateTimeDelta;
    sp60 = (f64) sp30;
    if ((u8) this->unkF4 == 0) {
        var_r30_113 = GetFirstParticle(&unkspC);
loop_16:
        if (var_r30_113 != NULL) {
            temp_r29_117 = var_r30_113->unk2C;
            temp_f26_121 = this->unk128 - M2C_FIELD(temp_r29_117, f32 *, 0x10);
            if (temp_f26_121 > this->unk12C) {
                var_r30_113 = DestroyParticle(&unkspC);
            } else {
                M2C_FIELD(var_r30_113, f64 *, 0) = (f64) (M2C_FIELD(var_r30_113, f64 *, 0) + sp68);
                var_r30_113->unk8 += (f32) sp70;
                temp_f0_140 = M2C_FIELD(temp_r29_117, f64 *, 0) * (f64) gUpdateTimeDelta;
                sp18 = temp_f0_140;
                sp48 = temp_f0_140;
                sp20 = M2C_FIELD(temp_r29_117, f32 *, 8) * gUpdateTimeDelta;
                sp50 = (f64) sp20;
                M2C_FIELD(var_r30_113, f64 *, 0) = (f64) (M2C_FIELD(var_r30_113, f64 *, 0) + temp_f0_140);
                var_r30_113->unk8 += (f32) sp50;
                temp_f31_157 = this->unk118;
                M2C_FIELD(temp_r29_117, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_117, f64 *, 0) * (f64) temp_f31_157);
                M2C_FIELD(temp_r29_117, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_117, f32 *, 8) * temp_f31_157);
                M2C_FIELD(temp_r29_117, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_117, f64 *, 0) + sp58);
                M2C_FIELD(temp_r29_117, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_117, f32 *, 8) + (f32) sp60);
                var_r30_113->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_117, f32 *, 0x18);
                var_r30_113->unk20 = (f32) fmod(var_r30_113->unk20 + temp_f27_85, (f32) M2C_FIELD(temp_r31_84, s32 *, 0x80), gUpdateTimeDelta);
                temp_r3_189 = M2C_FIELD(temp_r29_117, s32 *, 0x14);
                if (temp_f26_121 > (this->unk12C * this->unk134[temp_r3_189].unk0)) {
                    M2C_FIELD(temp_r29_117, s32 *, 0x14) = (s32) (temp_r3_189 + 1);
                }
                temp_r4_200 = M2C_FIELD(temp_r29_117, s32 *, 0x14);
                temp_r3_201 = this->unk134;
                temp_r0_202 = temp_r4_200 - 1;
                temp_f6_203 = this->unk12C;
                temp_r5_206 = &temp_r3_201[temp_r0_202];
                temp_f5_208 = temp_r5_206->unk0;
                temp_f3_215 = -((temp_f6_203 * temp_f5_208) - temp_f26_121) / (temp_f6_203 * (temp_r3_201[temp_r4_200].unk0 - temp_f5_208));
                var_r30_113->unk1C = M2C_FIELD(temp_r29_117, f32 *, 0x20) * ((temp_f3_215 * temp_r5_206->unkC) + temp_r5_206->unk4);
                var_f0_219 = var_r30_113->unk1C;
                if (var_f0_219 < 1.0f) {

                } else {
                    var_f0_219 = 1.0f;
                }
                if (var_f0_219 > 0.0f) {

                } else {
                    var_f0_219 = 0.0f;
                }
                var_r30_113->unk1C = var_f0_219;
                temp_r3_238 = &this->unk134[temp_r0_202];
                var_r30_113->unk28 = M2C_FIELD(temp_r29_117, f32 *, 0x1C) * ((temp_f3_215 * temp_r3_238->unk10) + temp_r3_238->unk8);
                sp8 = 0;
                if (var_r30_113->unk4 <= this->unk11C) {
                    var_r30_113 = HitFloor(&unkspC, &sp8);
                }
                if (sp8 == 0) {
                    var_r30_113 = GetNextParticle(&unkspC);
                }
            }
            goto loop_16;
        }
    }
}
#endif

void MKParticleSystem::CalculateEnvelope() {
    MKParticleSystem::Envelope *temp_r5_300;
    MKParticleSystem::Envelope *temp_r5_310;
    f32 temp_f0_313;
    s32 temp_r7_301;
    s32 temp_r9_295;
    s32 var_ctr_296;
    s32 var_r4_294;
    s32 var_r8_293;
    void *temp_r6_303;
    void *temp_r6_311;

    var_r8_293 = 0;
    var_r4_294 = 0;
    temp_r9_295 = this->unk130 - 1;
    if (temp_r9_295 > 0) {
        for (var_ctr_296 = 0; var_ctr_296 < temp_r9_295; var_ctr_296++) {
            temp_r5_300 = this->unk134;
            temp_r7_301 = (var_r8_293 + 1) * 0x14;
            var_r8_293 += 1;
            temp_r6_303 = (u8 *) temp_r5_300 + var_r4_294;
            M2C_FIELD(temp_r6_303, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r5_300, f32 *, temp_r7_301 + 4) - M2C_FIELD(temp_r6_303, f32 *, 4));
            temp_r5_310 = this->unk134;
            temp_r6_311 = (u8 *) temp_r5_310 + var_r4_294;
            temp_f0_313 = M2C_FIELD(temp_r6_311, f32 *, 8);
            var_r4_294 += 0x14;
            M2C_FIELD(temp_r6_311, f32 *, 0x10) = (f32) (M2C_FIELD(temp_r5_310, f32 *, temp_r7_301 + 8) - temp_f0_313);
        }
    }
    this->unk134[temp_r9_295].unkC = 0.0f;
    this->unk134[temp_r9_295].unk10 = 0.0f;
}

void MKParticleSystem::SetEnvelope(MKParticleSystem::Envelope *arg1, int arg2) {
    this->unk134 = arg1;
    this->unk130 = arg2;
    CalculateEnvelope();
}

void *MKParticleSystem::CreateParticle() {
    void *temp_r3_353;
    void *temp_r4_368;

    temp_r3_353 = MKBaseParticleSystem::CreateParticle();
    if (temp_r3_353 == NULL) {
        return NULL;
    }
    M2C_FIELD(temp_r3_353, f32 *, 0x1C) = (f32) this->unk134->unk4;
    M2C_FIELD(temp_r3_353, f32 *, 0x28) = (f32) this->unk134->unk8;
    temp_r4_368 = M2C_FIELD(temp_r3_353, void **, 0x2C);
    M2C_FIELD(temp_r4_368, f32 *, 0x10) = (f32) this->unk128;
    M2C_FIELD(temp_r4_368, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r4_368, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r4_368, f32 *, 8) = 0.0f;
    M2C_FIELD(temp_r4_368, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r4_368, f32 *, 0x18) = 0.0f;
    M2C_FIELD(temp_r4_368, f32 *, 0x1C) = 1.0f;
    M2C_FIELD(temp_r4_368, f32 *, 0x20) = 1.0f;
    return temp_r3_353;
}

void MKParticleSystem::Deinit() {
    MKBaseParticleSystem::Deinit();
}

void MKParticleSystem::Init() {
    MKBaseParticleSystem::Init();
    this->unk128 = 0.0f;
    this->unkF0 = 0.0f;
    this->unkF4 = 0;
    this->unk12C = 10.0f;
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unk100 = 0.0f;
    this->unk108 = 0.0f;
    this->unk10C = -4000.0f;
    this->unk110 = 0.0f;
    this->unk118 = 0.99999f;
    this->unk11C = -1e12f;
    this->unk120 = 0.0f;
    this->unk124 = 0.75f;
    SetEnvelope(gDefaultEnvelope, 2);
}
