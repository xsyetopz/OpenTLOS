#include "spyro/source/KDParticleSystem.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

f64 fmod(f32, f32);                                 /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
f64 pow(f32, f32);                                  /* extern */
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: illegal implicit conversion from 'float' to
static M2C_UNK gDefaultEnvelope;                    /* unable to generate initializer: unknown type */

void KDEnvParticleSystem::KDEnvConfigureSystemData(KDParticleSystem *arg0, MKParticle *arg1) {
    void *temp_r3_21;

    temp_r3_21 = M2C_FIELD(this->unk0, void **, 0xD4);
    arg0->unk20 = 0.0f;
    arg0->unk28 = M2C_FIELD(temp_r3_21, f32 *, 8);
    arg0->unk10 = 1.0f;
    arg0->unk14 = 1.0f;
    arg0->unk18 = 1.0f;
    arg0->unk1C = M2C_FIELD(temp_r3_21, f32 *, 4);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp8'
void KDEnvParticleSystem::UpdateParticles() {
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r28_86;
    f32 temp_f0_152;
    f32 temp_f0_94;
    f32 temp_f27_61;
    f32 temp_f2_158;
    f32 temp_f31_130;
    f32 temp_f3_169;
    f32 temp_f4_164;
    f64 temp_f0_63;
    f64 temp_f0_74;
    f64 temp_f1_113;
    s32 temp_r0_178;
    s32 temp_r29_60;
    s32 var_r3_142;
    s32 var_r5_141;
    void *temp_r30_57;
    void *temp_r3_163;
    void *temp_r4_90;

    this->unkF4 += gUpdateTimeDelta;
    temp_r30_57 = this->unk0;
    temp_r29_60 = M2C_FIELD(temp_r30_57, s32 *, 0xD4);
    temp_f27_61 = gUpdateTimeDelta * M2C_FIELD(temp_r30_57, f32 *, 0x90);
    temp_f0_63 = M2C_FIELD(temp_r30_57, f64 *, 0xA0) * (f64) gUpdateTimeDelta;
    sp30 = temp_f0_63;
    sp60 = temp_f0_63;
    sp38 = M2C_FIELD(temp_r30_57, f32 *, 0xA8) * gUpdateTimeDelta;
    sp68 = (f64) sp38;
    temp_f0_74 = M2C_FIELD(temp_r30_57, f64 *, 0xB0) * (f64) gUpdateTimeDelta;
    sp20 = temp_f0_74;
    sp50 = temp_f0_74;
    sp28 = M2C_FIELD(temp_r30_57, f32 *, 0xB8) * gUpdateTimeDelta;
    sp58 = (f64) sp28;
    var_r28_86 = GetFirstParticle(&unksp8);
loop_9:
    if (var_r28_86 != NULL) {
        temp_r4_90 = var_r28_86->unk2C;
        temp_f0_94 = this->unkF4 - M2C_FIELD(temp_r4_90, f32 *, 0x14);
        if (temp_f0_94 > M2C_FIELD(temp_r30_57, f32 *, 0xC8)) {
            var_r28_86 = DestroyParticle(&unksp8);
        } else {
            M2C_FIELD(var_r28_86, f64 *, 0) = (f64) (M2C_FIELD(var_r28_86, f64 *, 0) + sp60);
            var_r28_86->unk8 += (f32) sp68;
            temp_f1_113 = M2C_FIELD(temp_r4_90, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f1_113;
            sp40 = temp_f1_113;
            sp18 = M2C_FIELD(temp_r4_90, f32 *, 8) * gUpdateTimeDelta;
            sp48 = (f64) sp18;
            M2C_FIELD(var_r28_86, f64 *, 0) = (f64) (M2C_FIELD(var_r28_86, f64 *, 0) + temp_f1_113);
            var_r28_86->unk8 += (f32) sp48;
            temp_f31_130 = M2C_FIELD(temp_r30_57, f32 *, 0xC4);
            M2C_FIELD(temp_r4_90, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_90, f64 *, 0) * (f64) temp_f31_130);
            M2C_FIELD(temp_r4_90, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_90, f32 *, 8) * temp_f31_130);
            M2C_FIELD(temp_r4_90, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_90, f64 *, 0) + sp50);
            var_r5_141 = 1;
            var_r3_142 = 0x14;
            M2C_FIELD(temp_r4_90, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_90, f32 *, 8) + (f32) sp58);
            var_r28_86->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r4_90, f32 *, 0x10);
            temp_f0_152 = temp_f0_94 / M2C_FIELD(temp_r30_57, f32 *, 0xC8);
loop_5:
            temp_f2_158 = *(temp_r29_60 + var_r3_142);
            if (temp_f0_152 > temp_f2_158) {
                var_r5_141 += 1;
                var_r3_142 += 0x14;
                goto loop_5;
            }
            temp_r3_163 = temp_r29_60 + ((var_r5_141 - 1) * 0x14);
            temp_f4_164 = M2C_FIELD(temp_r3_163, f32 *, 0);
            temp_f3_169 = (temp_f0_152 - temp_f4_164) / (temp_f2_158 - temp_f4_164);
            var_r28_86->unk1C = (temp_f3_169 * M2C_FIELD(temp_r3_163, f32 *, 0xC)) + M2C_FIELD(temp_r3_163, f32 *, 4);
            var_r28_86->unk28 = M2C_FIELD(temp_r4_90, f32 *, 0x18) * ((temp_f3_169 * M2C_FIELD(temp_r3_163, f32 *, 0x10)) + M2C_FIELD(temp_r3_163, f32 *, 8));
            temp_r0_178 = M2C_FIELD(temp_r30_57, s32 *, 0x80);
            if (temp_r0_178 > 1) {
                var_r28_86->unk20 = (f32) fmod(var_r28_86->unk20 + temp_f27_61, (f32) temp_r0_178);
            }
            var_r28_86 = GetNextParticle(&unksp8);
        }
        goto loop_9;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkF0'
void KDEnvParticleSystem::Init() {
    KDParticleSystem::Init();
    this->unkF0 = &KDEnvParticleSystem::KDEnvConfigureSystemData;
}
#endif

void KDEnvParticleSystemDescriptor::CalculateEnvelope() {
    s32 temp_r5_259;
    s32 var_r4_241;
    s32 var_r6_240;
    void *temp_r5_246;
    void *temp_r5_252;

    var_r6_240 = 0;
    var_r4_241 = 0;
loop_2:
    temp_r5_259 = this->unkD0;
    if (var_r6_240 < (s32) (temp_r5_259 - 1)) {
        var_r6_240 += 1;
        temp_r5_246 = ((u8 *) this->unkD4) + var_r4_241;
        M2C_FIELD(temp_r5_246, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r5_246, f32 *, 0x18) - M2C_FIELD(temp_r5_246, f32 *, 4));
        temp_r5_252 = ((u8 *) this->unkD4) + var_r4_241;
        var_r4_241 += 0x14;
        M2C_FIELD(temp_r5_252, f32 *, 0x10) = (f32) (M2C_FIELD(temp_r5_252, f32 *, 0x1C) - M2C_FIELD(temp_r5_252, f32 *, 8));
        goto loop_2;
    }
    M2C_FIELD((((u8 *) this->unkD4) + (temp_r5_259 * 0x14)), f32 *, -8) = 0.0f;
    M2C_FIELD((((u8 *) this->unkD4) + (this->unkD0 * 0x14)), f32 *, -4) = 0.0f;
}

void KDEnvParticleSystemDescriptor::LoadDone() {
    KDParticleSystemDescriptor::LoadDone();
    CalculateEnvelope();
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 KDEnvParticleSystemDescriptor::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r30_334;
    s32 temp_r27_313;
    s32 var_r26_343;
    s32 var_r26_367;
    s32 var_r26_392;
    s32 var_r27_344;
    s32 var_r27_368;
    s32 var_r27_393;
    void *var_r3_321;

    if (arg0->LoadInt("Envelope", (int *) &this->unkD0, 0) != 0) {
        temp_r27_313 = this->unkD0 * 0x14;
        if (MKHeap::Current() != NULL) {
            var_r3_321 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_313, NULL, 0);
        } else {
            var_r3_321 = malloc(temp_r27_313);
        }
        this->unkD4 = var_r3_321;
        this->unkD8 = 1;
        var_r30_334 = arg0->unkC->GetSubLine(arg0);
loop_20:
        if (var_r30_334 != NULL) {
            if (var_r30_334->IsField("Time") != 0) {
                var_r26_343 = 0;
                var_r27_344 = 0;
loop_8:
                if (var_r26_343 < (s32) this->unkD0) {
                    var_r30_334->AsFloat(var_r26_343, ((u8 *) this->unkD4) + var_r27_344);
                    var_r26_343 += 1;
                    var_r27_344 += 0x14;
                    goto loop_8;
                }
            } else if (var_r30_334->IsField("Alpha") != 0) {
                var_r26_367 = 0;
                var_r27_368 = 0;
loop_13:
                if (var_r26_367 < (s32) this->unkD0) {
                    var_r30_334->AsFloat(var_r26_367, ((u8 *) this->unkD4) + (var_r27_368 + 4));
                    var_r26_367 += 1;
                    var_r27_368 += 0x14;
                    goto loop_13;
                }
            } else if (var_r30_334->IsField("Scale") != 0) {
                var_r26_392 = 0;
                var_r27_393 = 0;
loop_18:
                if (var_r26_392 < (s32) this->unkD0) {
                    var_r30_334->AsFloat(var_r26_392, ((u8 *) this->unkD4) + (var_r27_393 + 8));
                    var_r26_392 += 1;
                    var_r27_393 += 0x14;
                    goto loop_18;
                }
            }
            var_r30_334 = var_r30_334->unkC->GetNextLine(var_r30_334);
            goto loop_20;
        }
        KDParticleSystemDescriptor::LoadLine(arg0);
        return 1;
    }
    return KDParticleSystemDescriptor::LoadLine(arg0);
}
#endif

void KDEnvParticleSystemDescriptor::Deinit() {
    void *temp_r31_445;

    MKPropDescriptor::Deinit();
    if ((u8) this->unkD8 != 0) {
        temp_r31_445 = this->unkD4;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_445, NULL, 0);
        } else {
            free(temp_r31_445);
        }
    }
    this->unkD0 = 0;
    this->unkD4 = NULL;
    this->unkD8 = 0;
}

#if 0 // DRAFT: undefined identifier 'gDefaultEnvelope'
void KDEnvParticleSystemDescriptor::Init() {
    KDParticleSystemDescriptor::Init();
    this->unkD0 = 2;
    this->unkD4 = &gDefaultEnvelope;
    this->unkD8 = 0;
    CalculateEnvelope();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void KDParticleSystem::KDConfigureSystemData(KDParticleSystem *arg0, MKParticle *arg1) {
    arg0->unk28 = 1.0f;
    arg0->unk20 = 0.0f;
    arg0->unk10 = 1.0f;
    arg0->unk14 = 1.0f;
    arg0->unk18 = 1.0f;
    arg0->unk1C = 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp8'
void KDParticleSystem::UpdateParticles() {
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r5_557;
    f32 temp_f31_601;
    f64 temp_f0_534;
    f64 temp_f0_545;
    f64 temp_f0_584;
    void *temp_r31_531;
    void *temp_r6_561;

    this->unkF4 += gUpdateTimeDelta;
    temp_r31_531 = this->unk0;
    temp_f0_534 = M2C_FIELD(temp_r31_531, f64 *, 0xA0) * (f64) gUpdateTimeDelta;
    sp30 = temp_f0_534;
    sp60 = temp_f0_534;
    sp38 = M2C_FIELD(temp_r31_531, f32 *, 0xA8) * gUpdateTimeDelta;
    sp68 = (f64) sp38;
    temp_f0_545 = M2C_FIELD(temp_r31_531, f64 *, 0xB0) * (f64) gUpdateTimeDelta;
    sp20 = temp_f0_545;
    sp50 = temp_f0_545;
    sp28 = M2C_FIELD(temp_r31_531, f32 *, 0xB8) * gUpdateTimeDelta;
    sp58 = (f64) sp28;
    var_r5_557 = GetFirstParticle(&unksp8);
loop_4:
    if (var_r5_557 != NULL) {
        temp_r6_561 = var_r5_557->unk2C;
        if ((this->unkF4 - M2C_FIELD(temp_r6_561, f32 *, 0x14)) > M2C_FIELD(temp_r31_531, f32 *, 0xC8)) {
            var_r5_557 = DestroyParticle(&unksp8);
        } else {
            M2C_FIELD(var_r5_557, f64 *, 0) = (f64) (M2C_FIELD(var_r5_557, f64 *, 0) + sp60);
            var_r5_557->unk8 += (f32) sp68;
            temp_f0_584 = M2C_FIELD(temp_r6_561, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_584;
            sp40 = temp_f0_584;
            sp18 = M2C_FIELD(temp_r6_561, f32 *, 8) * gUpdateTimeDelta;
            sp48 = (f64) sp18;
            M2C_FIELD(var_r5_557, f64 *, 0) = (f64) (M2C_FIELD(var_r5_557, f64 *, 0) + temp_f0_584);
            var_r5_557->unk8 += (f32) sp48;
            temp_f31_601 = M2C_FIELD(temp_r31_531, f32 *, 0xC4);
            M2C_FIELD(temp_r6_561, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_561, f64 *, 0) * (f64) temp_f31_601);
            M2C_FIELD(temp_r6_561, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_561, f32 *, 8) * temp_f31_601);
            M2C_FIELD(temp_r6_561, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_561, f64 *, 0) + sp50);
            M2C_FIELD(temp_r6_561, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_561, f32 *, 8) + (f32) sp58);
            var_r5_557->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r6_561, f32 *, 0x10);
            var_r5_557 = GetNextParticle(&unksp8);
        }
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkF0'
void KDParticleSystem::Init() {
    MKBaseParticleSystem::Init();
    this->unkF4 = 0.0f;
    this->unkA8 = M2C_FIELD(this->unk0, f32 *, 0x94);
    this->unkAC = M2C_FIELD(this->unk0, f32 *, 0x98);
    this->unkF0 = &KDParticleSystem::KDConfigureSystemData;
    this->unkF8 = 0;
}
#endif

void KDParticleSystemDescriptor::Update() {
    this->unkC4 = (f32) pow(this->unkC0, gUpdateTimeDelta);
}

void KDParticleSystemDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk84 = 1.0f / (f32) this->unk80;
}

s32 KDParticleSystemDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_727;

    var_r31_727 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("numSubTextures", (int *) &this->unk80, 0) != 0) || (arg0->LoadFloat("textureAnimSpeed", &this->unk90, 0) != 0) || (arg0->LoadFloat("halfWidth", &this->unk94, 0) != 0) || (arg0->LoadFloat("halfHeight", &this->unk98, 0) != 0) || (arg0->LoadVector3("accel", &this->unkB0, 0) != 0) || (arg0->LoadVector3("drift", &this->unkA0, 0) != 0) || (arg0->LoadFloat("damping", &this->unkC0, 0) != 0) || (arg0->LoadFloat("lifetime", &this->unkC8, 0) != 0)) {
        var_r31_727 = 1;
    }
    return var_r31_727;
}

void KDParticleSystemDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk90 = 0.0f;
    this->unkA0.unk0 = 0.0f;
    this->unkA0.unk4 = 0.0f;
    this->unkA0.unk8 = 0.0f;
    this->unkB0.unk0 = 0.0f;
    this->unkB0.unk4 = 0.0f;
    this->unkB0.unk8 = 0.0f;
    this->unkC0 = 1.0f;
    this->unk94 = 10.0f;
    this->unk98 = 10.0f;
    this->unkC8 = 1.0f;
}
