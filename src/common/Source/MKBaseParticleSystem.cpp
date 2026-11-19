#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "dolphin/os.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MKParticleChunk **);                   /* extern */
MKParticleChunk **malloc(s32);                      /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern MKParticleChunk **gParticleChunks;
extern s32 gTotalNumChunks;
extern f32 gUpdateTimeDelta;

s32 MKBaseParticleSystem::LoadDone() {
    MKProp::LoadDone();
    if (this->unk10 & 2) {
        this->unkB4 = 1;
    }
}

void MKBaseParticleSystemDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f32 *, 0x60) = -100000.0f;
    this->unk64 = -100000.0f;
    this->unk68 = -100000.0f;
    this->unk70 = -100000.0f;
    this->unk74 = -100000.0f;
    this->unk78 = -100000.0f;
    this->unk1C = (BoundingVolume *) &this->unk60;
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
    this->unk18 = -0x2710;
}

void MKParticleSystem_FreeChunk(MKParticleChunk *arg0) {
    MKParticleChunk **temp_r3_78;
    MKParticleChunk **var_r4_73;
    MKParticleChunk *temp_r0_89;
    MKParticleChunk *temp_r5_81;

    var_r4_73 = gParticleChunks;
loop_4:
    temp_r0_89 = *var_r4_73;
    if (temp_r0_89 == NULL) {
        return;
    }
    if (temp_r0_89 == arg0) {
        temp_r3_78 = gParticleChunks;
        gParticleChunks = temp_r3_78 + 4;
        temp_r5_81 = *temp_r3_78;
        *temp_r3_78 = *var_r4_73;
        *var_r4_73 = temp_r5_81;
        return;
    }
    var_r4_73 += 4;
    goto loop_4;
}

#if 0 // DRAFT: illegal operand
MKParticleChunk *MKParticleSystem_AllocChunk(int arg0) {
    MKParticleChunk **temp_r3_105;
    MKParticleChunk *temp_r3_111;
    s32 var_ctr_116;
    s32 var_r4_110;
    s32 var_r6_106;
    void *temp_r5_120;

    if ((u32) M2C_FIELD(gParticleChunks, u32 *, -4) == 0U) {
        return NULL;
    }
    temp_r3_105 = gParticleChunks - 4;
    var_r6_106 = 0;
    gParticleChunks = temp_r3_105;
    var_r4_110 = 0;
    temp_r3_111 = *temp_r3_105;
    M2C_FIELD(temp_r3_111, s32 *, 0xA84) = 0;
    M2C_FIELD(temp_r3_111, s32 *, 0xA88) = 0;
    M2C_FIELD(temp_r3_111, s32 *, 0xA8C) = 0;
    M2C_FIELD(temp_r3_111, s32 *, 0x480) = -1;
    var_ctr_116 = 0x18;
    do {
        temp_r5_120 = temp_r3_111 + (var_r6_106 + 0x484);
        var_r6_106 += 0x40;
        *(temp_r3_111 + (var_r4_110 + 0x2C)) = temp_r5_120;
        var_r4_110 += 0x30;
        var_ctr_116 -= 1;
    } while (var_ctr_116 != 0);
    return temp_r3_111;
}
#endif

#if 0 // DRAFT: type mismatch 'MKParticleChunk *' and 'MKParticleChunk **'
void MKParticleSystem_DeinitModule() {
    MKParticleChunk **var_r31_136;
    MKParticleChunk **var_r3_137;
    MKParticleChunk **var_r4_135;
    MKParticleChunk *temp_r0_140;
    MKParticleChunk *temp_r0_159;
    u32 temp_r0_145;

    var_r4_135 = gParticleChunks;
    var_r31_136 = var_r4_135;
    var_r3_137 = var_r4_135;
loop_3:
    temp_r0_145 = M2C_FIELD(var_r3_137, u32 *, -4);
    var_r3_137 -= 4;
    if (temp_r0_145 != 0U) {
        temp_r0_140 = *var_r3_137;
        if (temp_r0_140 < var_r31_136) {
            var_r31_136 = &temp_r0_140->unk0;
        }
        goto loop_3;
    }
    if (var_r3_137 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_159 = *var_r4_135;
        if (temp_r0_159 != NULL) {
            if (temp_r0_159 < var_r31_136) {
                var_r31_136 = &temp_r0_159->unk0;
            }
            var_r4_135 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_136, NULL, 0);
        } else {
            free(var_r31_136);
        }
    }
    gParticleChunks = NULL;
}
#endif

void MKParticleSystem_InitModule(int arg0) {
    MKParticleChunk **temp_r4_223;
    MKParticleChunk **var_r3_211;
    s32 temp_r31_193;
    s32 var_ctr_226;

    temp_r31_193 = (s32) (arg0 + 0x17) / 24;
    gTotalNumChunks = temp_r31_193;
    if (temp_r31_193 == 0) {
        gParticleChunks = (MKParticleChunk **) (&gEmptyPtrListDL + 4);
        return;
    }
    if (MKHeap::Current() != NULL) {
        var_r3_211 = (MKParticleChunk **) (((MKHeap *) (MKHeap::Current()))->Alloc(((temp_r31_193 + 2) * 4) + (temp_r31_193 * 0xA90), NULL, 0));
    } else {
        var_r3_211 = malloc(((temp_r31_193 + 2) * 4) + (temp_r31_193 * 0xA90));
    }
    gParticleChunks = var_r3_211;
    temp_r4_223 = var_r3_211 + (temp_r31_193 * 0xA90);
    gParticleChunks = temp_r4_223;
    *temp_r4_223 = NULL;
    var_ctr_226 = temp_r31_193;
    if (temp_r31_193 > 0) {
        do {
            gParticleChunks += 4;
            M2C_FIELD(gParticleChunks, MKParticleChunk ***, 4) = var_r3_211;
            var_r3_211 += 0xA90;
            var_ctr_226 -= 1;
        } while (var_ctr_226 != 0);
    }
    gParticleChunks += 4;
    M2C_FIELD(gParticleChunks, MKParticleChunk ***, 4) = NULL;
}

void MKBaseParticleSystem::DrawChunk(Matrix *arg0, MKVector4 *arg1, MKParticleChunk *arg2) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r29_282;
    Matrix *temp_r30_285;
    f32 temp_f0_319;
    f32 temp_f0_335;
    f32 temp_f0_438;
    f32 temp_f0_449;
    f32 temp_f10_331;
    f32 temp_f11_325;
    f32 temp_f12_327;
    f32 temp_f13_333;
    f32 temp_f1_321;
    f32 temp_f1_341;
    f32 temp_f22_329;
    f32 temp_f22_358;
    f32 temp_f23_357;
    f32 temp_f24_355;
    f32 temp_f25_356;
    f32 temp_f26_352;
    f32 temp_f27_351;
    f32 temp_f28_316;
    f32 temp_f2_344;
    f32 temp_f3_342;
    f32 temp_f3_392;
    f32 temp_f5_350;
    f32 temp_f6_349;
    f32 temp_f6_398;
    f32 temp_f7_323;
    f32 temp_f7_343;
    f32 temp_f7_404;
    f32 var_f0_383;
    s32 temp_r25_297;
    s32 var_r18_296;
    s32 var_r24_294;
    void *temp_r23_301;
    void *temp_r28_286;

    temp_r29_282 = MKView_GetCameraMatrix();
    temp_r30_285 = MKView_GetCameraMatrix();
    temp_r28_286 = this->unk0;
    MKBegin(M2C_FIELD(arg2, s32 *, 0xA84) * 4);
    var_r24_294 = 0;
    var_r18_296 = 0;
    temp_r25_297 = M2C_FIELD(this->unk0, s32 *, 0x80) - 1;
loop_5:
    if (var_r24_294 < (s32) M2C_FIELD(arg2, s32 *, 0xA84)) {
        temp_r23_301 = arg2 + var_r18_296;
        temp_f28_316 = (f32) (temp_r25_297 & (s32) (this->unkB0 + M2C_FIELD(temp_r23_301, f32 *, 0x20)));
        _table_sincosf(M2C_FIELD(temp_r23_301, f32 *, 0x24), spC, sp8);
        temp_f0_319 = temp_r29_282->unk0;
        temp_f1_321 = temp_r29_282->unk4;
        temp_f7_323 = temp_r29_282->unk8;
        temp_f11_325 = temp_r30_285->unk10;
        temp_f12_327 = temp_r30_285->unk14;
        temp_f22_329 = temp_r30_285->unk18;
        temp_f10_331 = this->unkAC;
        temp_f13_333 = this->unkA8;
        temp_f0_335 = M2C_FIELD(temp_r23_301, f32 *, 0x28);
        temp_f1_341 = temp_f10_331 * ((temp_f11_325 * sp8) - (temp_f0_319 * spC));
        temp_f3_342 = temp_f13_333 * ((temp_f11_325 * spC) + (temp_f0_319 * sp8));
        temp_f7_343 = temp_f10_331 * ((temp_f12_327 * sp8) - (temp_f1_321 * spC));
        temp_f2_344 = temp_f13_333 * ((temp_f12_327 * spC) + (temp_f1_321 * sp8));
        temp_f6_349 = temp_f10_331 * ((temp_f22_329 * sp8) - (temp_f7_323 * spC));
        temp_f5_350 = temp_f13_333 * ((temp_f22_329 * spC) + (temp_f7_323 * sp8));
        temp_f27_351 = temp_f0_335 * (temp_f1_341 - temp_f3_342);
        temp_f26_352 = temp_f0_335 * (temp_f7_343 - temp_f2_344);
        temp_f24_355 = temp_f0_335 * (temp_f1_341 + temp_f3_342);
        temp_f25_356 = temp_f0_335 * (temp_f6_349 - temp_f5_350);
        temp_f23_357 = temp_f0_335 * (temp_f7_343 + temp_f2_344);
        temp_f22_358 = temp_f0_335 * (temp_f6_349 + temp_f5_350);
        sp20 = M2C_FIELD(arg1, f64 *, 0) * M2C_FIELD(temp_r23_301, f64 *, 0x10);
        sp28 = M2C_FIELD(arg1, f64 *, 8) * M2C_FIELD(temp_r23_301, f64 *, 0x18);
        sp40 = sp20;
        sp48 = sp28;
        sp40 *= (f64) (*(f32 *) ((u8 *) &sp48 + 0x4));
        sp48 *= (f64) (*(f32 *) ((u8 *) &sp48 + 0x4));
        var_f0_383 = 2.0f * (*(f32 *) ((u8 *) &sp48 + 0x4));
        if (var_f0_383 < 1.0f) {

        } else {
            var_f0_383 = 1.0f;
        }
        (*(f32 *) ((u8 *) &sp48 + 0x4)) = var_f0_383;
        temp_f3_392 = M2C_FIELD(temp_r23_301, f32 *, 4);
        temp_f6_398 = M2C_FIELD(temp_r23_301, f32 *, 0);
        temp_f7_404 = M2C_FIELD(temp_r23_301, f32 *, 8);
        sp10 = arg0->unk30 + ((temp_f7_404 * arg0->unk20) + ((temp_f6_398 * arg0->unk0) + (temp_f3_392 * arg0->unk10)));
        sp14 = arg0->unk34 + ((temp_f7_404 * arg0->unk24) + ((temp_f6_398 * arg0->unk4) + (temp_f3_392 * arg0->unk14)));
        sp18 = arg0->unk38 + ((temp_f7_404 * arg0->unk28) + ((temp_f6_398 * arg0->unk8) + (temp_f3_392 * arg0->unk18)));
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        MKSetColorV(*((MKVector4 *) &sp40));
        MKSetTexCoord1F(temp_f28_316 * M2C_FIELD(temp_r28_286, f32 *, 0x84), 0.0f);
        MKSetPositionF((f32) sp30 + temp_f27_351, (*(f32 *) ((u8 *) &sp30 + 0x4)) + temp_f26_352, (f32) sp38 + temp_f25_356);
        temp_f0_438 = M2C_FIELD(temp_r28_286, f32 *, 0x84);
        MKSetTexCoord1F((temp_f28_316 * temp_f0_438) + temp_f0_438, 0.0f);
        MKSetPositionF((f32) sp30 + temp_f24_355, (*(f32 *) ((u8 *) &sp30 + 0x4)) + temp_f23_357, (f32) sp38 + temp_f22_358);
        temp_f0_449 = M2C_FIELD(temp_r28_286, f32 *, 0x84);
        MKSetTexCoord1F((temp_f28_316 * temp_f0_449) + temp_f0_449, 1.0f);
        MKSetPositionF((f32) sp30 - temp_f27_351, (*(f32 *) ((u8 *) &sp30 + 0x4)) - temp_f26_352, (f32) sp38 - temp_f25_356);
        MKSetTexCoord1F(temp_f28_316 * M2C_FIELD(temp_r28_286, f32 *, 0x84), 1.0f);
        MKSetPositionF((f32) sp30 - temp_f24_355, (*(f32 *) ((u8 *) &sp30 + 0x4)) - temp_f23_357, (f32) sp38 - temp_f22_358);
        var_r24_294 += 1;
        var_r18_296 += 0x30;
        goto loop_5;
    }
    MKEnd();
}

void MKBaseParticleSystem::InitDraw(Matrix *arg0, MKVector4 *arg1) {
    MKMaterial_SetMaterial(M2C_FIELD(this->unk0, MKMaterial **, 0x38));
    MKPrimitive(0xE, 0x10);
}

MKParticleChunk *MKBaseParticleSystem::GetNextParticle(MKBaseParticleSystem::ParticleRec *arg1) {
    MKParticleChunk *temp_r0_537;
    MKParticleChunk *temp_r6_526;
    s32 temp_r3_532;

    temp_r6_526 = M2C_FIELD(arg1, MKParticleChunk **, 0);
    temp_r3_532 = ((s32) (M2C_FIELD(arg1, MKParticleChunk **, 4) - temp_r6_526) / 48) + 1;
    if (temp_r3_532 >= (s32) M2C_FIELD(temp_r6_526, s32 *, 0xA84)) {
        M2C_FIELD(arg1, MKParticleChunk **, 0) = (MKParticleChunk *) M2C_FIELD(temp_r6_526, MKParticleChunk **, 0xA8C);
        temp_r0_537 = M2C_FIELD(arg1, MKParticleChunk **, 0);
        if (temp_r0_537 == NULL) {
            M2C_FIELD(arg1, MKParticleChunk **, 4) = NULL;
        } else {
            M2C_FIELD(arg1, MKParticleChunk **, 4) = temp_r0_537;
        }
    } else {
        M2C_FIELD(arg1, MKParticleChunk **, 4) = (MKParticleChunk *) (temp_r6_526 + (temp_r3_532 * 0x30));
    }
    return M2C_FIELD(arg1, MKParticleChunk **, 4);
}

MKParticleChunk *MKBaseParticleSystem::GetFirstParticle(MKBaseParticleSystem::ParticleRec *arg1) {
    if ((s32) this->unkD8 == 0) {
        M2C_FIELD(arg1, MKParticleChunk **, 0) = NULL;
        M2C_FIELD(arg1, MKParticleChunk **, 4) = NULL;
        return NULL;
    }
    M2C_FIELD(arg1, MKParticleChunk **, 0) = (MKParticleChunk *) this->unkD0;
    M2C_FIELD(arg1, MKParticleChunk **, 4) = (MKParticleChunk *) this->unkD0;
    return M2C_FIELD(arg1, MKParticleChunk **, 4);
}

void MKBaseParticleSystem::DestroyAllParticles() {
    MKParticleChunk *var_r31_583;

    var_r31_583 = this->unkD0;
loop_2:
    if (var_r31_583 != NULL) {
        MKParticleSystem_FreeChunk(var_r31_583);
        var_r31_583 = M2C_FIELD(var_r31_583, MKParticleChunk **, 0xA8C);
        goto loop_2;
    }
    this->unkD0 = NULL;
    this->unkD4 = 0;
    this->unkD8 = 0;
}

MKParticleChunk *MKBaseParticleSystem::DestroyParticle(MKBaseParticleSystem::ParticleRec *arg1) {
    MKParticleChunk *temp_r3_636;
    MKParticleChunk *temp_r3_642;
    MKParticleChunk *temp_r3_669;
    MKParticleChunk *temp_r4_613;
    MKParticleChunk *temp_r4_671;
    MKParticleChunk *temp_r4_691;
    MKParticleChunk *var_r31_616;
    s32 temp_r0_618;
    s32 temp_r3_619;
    s32 temp_r5_615;
    s32 var_r30_623;
    void *temp_r3_630;
    void *temp_r6_670;

    temp_r4_613 = M2C_FIELD(arg1, MKParticleChunk **, 0);
    temp_r5_615 = M2C_FIELD(temp_r4_613, s32 *, 0xA84);
    var_r31_616 = temp_r4_613;
    temp_r0_618 = (s32) (M2C_FIELD(arg1, MKParticleChunk **, 4) - temp_r4_613) / 48;
    temp_r3_619 = temp_r5_615 - 1;
    if (temp_r0_618 == temp_r3_619) {
        var_r31_616 = M2C_FIELD(temp_r4_613, MKParticleChunk **, 0xA8C);
        var_r30_623 = 0;
    } else {
        var_r30_623 = temp_r0_618;
    }
    if (temp_r5_615 == 1) {
        temp_r3_630 = M2C_FIELD(temp_r4_613, void **, 0xA88);
        if (temp_r3_630 != NULL) {
            M2C_FIELD(temp_r3_630, MKParticleChunk **, 0xA8C) = (MKParticleChunk *) M2C_FIELD(temp_r4_613, MKParticleChunk **, 0xA8C);
        }
        temp_r3_636 = M2C_FIELD(temp_r4_613, MKParticleChunk **, 0xA8C);
        if (temp_r3_636 != NULL) {
            M2C_FIELD(temp_r3_636, void **, 0xA88) = (void *) M2C_FIELD(temp_r4_613, void **, 0xA88);
        }
        temp_r3_642 = this->unkD0;
        if (temp_r3_642 == (MKParticleChunk *) M2C_FIELD(arg1, MKParticleChunk **, 0)) {
            this->unkD0 = M2C_FIELD(temp_r3_642, MKParticleChunk **, 0xA8C);
        }
        M2C_FIELD(M2C_FIELD(arg1, MKParticleChunk **, 0), s32 *, 0xA84) = 0;
        M2C_FIELD(M2C_FIELD(arg1, MKParticleChunk **, 0), s32 *, 0xA8C) = 0;
        M2C_FIELD(M2C_FIELD(arg1, MKParticleChunk **, 0), s32 *, 0xA88) = 0;
        MKParticleSystem_FreeChunk(M2C_FIELD(arg1, MKParticleChunk **, 0));
        M2C_FIELD(arg1, MKParticleChunk **, 0) = NULL;
        this->unkD4 -= 1;
    } else if (temp_r0_618 != temp_r3_619) {
        temp_r3_669 = &temp_r4_613[temp_r0_618];
        temp_r6_670 = temp_r3_669->unk2C;
        temp_r4_671 = &temp_r4_613[temp_r3_619];
        M2C_FIELD(temp_r3_669, f64 *, 0) = (f64) M2C_FIELD(temp_r4_671, f64 *, 0);
        M2C_FIELD(temp_r3_669, f64 *, 8) = (f64) M2C_FIELD(temp_r4_671, f64 *, 8);
        M2C_FIELD(temp_r3_669, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_671, f64 *, 0x10);
        M2C_FIELD(temp_r3_669, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_671, f64 *, 0x18);
        temp_r3_669->unk20 = temp_r4_671->unk20;
        temp_r3_669->unk24 = temp_r4_671->unk24;
        temp_r3_669->unk28 = temp_r4_671->unk28;
        temp_r3_669->unk2C = temp_r4_671->unk2C;
        M2C_FIELD(arg1, MKParticleChunk **, 0)[temp_r3_619].unk2C = temp_r6_670;
        temp_r4_691 = M2C_FIELD(arg1, MKParticleChunk **, 0);
        M2C_FIELD(temp_r4_691, s32 *, 0xA84) = (s32) (M2C_FIELD(temp_r4_691, s32 *, 0xA84) - 1);
    } else {
        M2C_FIELD(temp_r4_613, s32 *, 0xA84) = (s32) (M2C_FIELD(temp_r4_613, s32 *, 0xA84) - 1);
    }
    this->unkD8 -= 1;
    M2C_FIELD(arg1, MKParticleChunk **, 0) = var_r31_616;
    if (var_r31_616 == NULL) {
        M2C_FIELD(arg1, MKParticleChunk **, 4) = NULL;
        return NULL;
    }
    M2C_FIELD(arg1, MKParticleChunk **, 4) = &M2C_FIELD(arg1, MKParticleChunk **, 0)[var_r30_623];
    return M2C_FIELD(arg1, MKParticleChunk **, 4);
}

void MKBaseParticleSystem::Message(MKMessage *arg0) {
    s32 temp_r0_734;

    temp_r0_734 = arg0->unk0;
    switch (temp_r0_734) {                          /* irregular */
    case -3:
        this->unkB4 = 1;
        break;
    case -4:
        this->unkB4 = 0;
        DestroyAllParticles();
        break;
    }
    MKProp::Message(arg0);
}

void *MKBaseParticleSystem::AllocateParticle() {
    MKParticleChunk *temp_r0_816;
    MKParticleChunk *temp_r0_825;
    MKParticleChunk *temp_r3_780;
    MKParticleChunk *temp_r3_788;
    MKParticleChunk *temp_r3_812;
    MKParticleChunk *temp_r4_799;
    MKParticleChunk *temp_r4_806;
    MKParticleChunk *temp_r5_811;
    MKParticleChunk *var_r4_820;
    s32 temp_r3_807;
    void *temp_r4_838;

    if ((u8) this->unkB4 == 0) {
        return NULL;
    }
    if ((MKBaseParticleSystem *) this->unkC8 != NULL) {
        return NULL;
    }
    temp_r3_780 = this->unkD0;
    if ((temp_r3_780 == NULL) || ((s32) M2C_FIELD(temp_r3_780, s32 *, 0xA84) >= 0x18)) {
        temp_r3_788 = MKParticleSystem_AllocChunk(this->unkCC);
        if (temp_r3_788 == NULL) {
            return NULL;
        }
        this->unkD4 += 1;
        M2C_FIELD(temp_r3_788, MKParticleChunk **, 0xA8C) = (MKParticleChunk *) this->unkD0;
        temp_r4_799 = this->unkD0;
        if (temp_r4_799 != NULL) {
            M2C_FIELD(temp_r4_799, MKParticleChunk **, 0xA88) = temp_r3_788;
        }
        this->unkD0 = temp_r3_788;
        goto block_11;
    }
block_11:
    temp_r4_806 = this->unkD0;
    temp_r3_807 = M2C_FIELD(temp_r4_806, s32 *, 0xA84);
    M2C_FIELD(temp_r4_806, s32 *, 0xA84) = (s32) (temp_r3_807 + 1);
    temp_r5_811 = this->unkD0;
    temp_r3_812 = &temp_r4_806[temp_r3_807];
    if ((s32) M2C_FIELD(temp_r5_811, s32 *, 0xA84) >= 0x18) {
        temp_r0_816 = M2C_FIELD(temp_r5_811, MKParticleChunk **, 0xA8C);
        if (temp_r0_816 != NULL) {
            this->unkD0 = temp_r0_816;
            var_r4_820 = this->unkD0;
loop_15:
            temp_r0_825 = M2C_FIELD(var_r4_820, MKParticleChunk **, 0xA8C);
            if (temp_r0_825 != NULL) {
                var_r4_820 = temp_r0_825;
                goto loop_15;
            }
            M2C_FIELD(var_r4_820, MKParticleChunk **, 0xA8C) = temp_r5_811;
            M2C_FIELD(temp_r5_811, MKParticleChunk **, 0xA88) = var_r4_820;
            M2C_FIELD(temp_r5_811, MKParticleChunk **, 0xA8C) = NULL;
            M2C_FIELD(this->unkD0, MKParticleChunk **, 0xA88) = NULL;
        }
    }
    this->unkD8 += 1;
    temp_r4_838 = this->unkA0;
    if (temp_r4_838 != NULL) {
        M2C_FIELD(temp_r3_812, f64 *, 0) = (f64) M2C_FIELD(temp_r4_838, f64 *, 0);
        M2C_FIELD(temp_r3_812, f64 *, 8) = (f64) M2C_FIELD(temp_r4_838, f64 *, 8);
    }
    return temp_r3_812;
}

#if 0 // DRAFT: illegal implicit conversion from 'float' to 'MKParticleChunk *'
void *MKBaseParticleSystem::CreateParticle() {
    MKParticleChunk *temp_r0_909;
    MKParticleChunk *temp_r0_918;
    MKParticleChunk *temp_r3_873;
    MKParticleChunk *temp_r3_881;
    MKParticleChunk *temp_r3_905;
    MKParticleChunk *temp_r4_892;
    MKParticleChunk *temp_r4_899;
    MKParticleChunk *temp_r5_904;
    MKParticleChunk *var_r4_913;
    s32 temp_r3_900;
    void *temp_r4_931;

    if ((u8) this->unkB4 == 0) {
        return NULL;
    }
    if ((MKBaseParticleSystem *) this->unkC8 != NULL) {
        return NULL;
    }
    temp_r3_873 = this->unkD0;
    if ((temp_r3_873 == NULL) || ((s32) M2C_FIELD(temp_r3_873, s32 *, 0xA84) >= 0x18)) {
        temp_r3_881 = MKParticleSystem_AllocChunk(this->unkCC);
        if (temp_r3_881 == NULL) {
            return NULL;
        }
        this->unkD4 += 1;
        M2C_FIELD(temp_r3_881, MKParticleChunk **, 0xA8C) = (MKParticleChunk *) this->unkD0;
        temp_r4_892 = this->unkD0;
        if (temp_r4_892 != NULL) {
            M2C_FIELD(temp_r4_892, MKParticleChunk **, 0xA88) = temp_r3_881;
        }
        this->unkD0 = temp_r3_881;
        goto block_11;
    }
block_11:
    temp_r4_899 = this->unkD0;
    temp_r3_900 = M2C_FIELD(temp_r4_899, s32 *, 0xA84);
    M2C_FIELD(temp_r4_899, s32 *, 0xA84) = (s32) (temp_r3_900 + 1);
    temp_r5_904 = this->unkD0;
    temp_r3_905 = &temp_r4_899[temp_r3_900];
    if ((s32) M2C_FIELD(temp_r5_904, s32 *, 0xA84) >= 0x18) {
        temp_r0_909 = M2C_FIELD(temp_r5_904, MKParticleChunk **, 0xA8C);
        if (temp_r0_909 != NULL) {
            this->unkD0 = temp_r0_909;
            var_r4_913 = this->unkD0;
loop_15:
            temp_r0_918 = M2C_FIELD(var_r4_913, MKParticleChunk **, 0xA8C);
            if (temp_r0_918 != NULL) {
                var_r4_913 = temp_r0_918;
                goto loop_15;
            }
            M2C_FIELD(var_r4_913, MKParticleChunk **, 0xA8C) = temp_r5_904;
            M2C_FIELD(temp_r5_904, MKParticleChunk **, 0xA88) = var_r4_913;
            M2C_FIELD(temp_r5_904, MKParticleChunk **, 0xA8C) = NULL;
            M2C_FIELD(this->unkD0, MKParticleChunk **, 0xA88) = NULL;
        }
    }
    this->unkD8 += 1;
    temp_r4_931 = this->unkA0;
    if (temp_r4_931 != NULL) {
        M2C_FIELD(temp_r3_905, f64 *, 0) = (f64) M2C_FIELD(temp_r4_931, f64 *, 0);
        M2C_FIELD(temp_r3_905, f64 *, 8) = (f64) M2C_FIELD(temp_r4_931, f64 *, 8);
    } else {
        temp_r3_905->unk0 = 0.0f;
        temp_r3_905->unk4 = 0.0f;
        temp_r3_905->unk8 = 0.0f;
    }
    temp_r3_905->unk28 = 1.0f;
    temp_r3_905->unk10 = 1.0f;
    temp_r3_905->unk14 = 1.0f;
    temp_r3_905->unk18 = 1.0f;
    temp_r3_905->unk1C = 1.0f;
    temp_r3_905->unk20 = 0.0f;
    temp_r3_905->unk24 = 0.0f;
    return temp_r3_905;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp5C'
void MKBaseParticleSystem::Draw(Matrix *arg0, MKVector4 *arg1) {
    M2C_UNK spA0;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    MKParticleChunk *var_r30_987;
    f32 temp_f3_1004;
    f32 temp_f3_1094;
    f32 temp_f6_1008;
    f32 temp_f7_1017;
    f64 temp_f0_1039;
    s32 var_r10_1065;
    s32 var_r11_1068;
    s32 var_r3_1069;
    s32 var_r3_998;
    s32 var_r4_1070;
    s32 var_r4_999;
    s32 var_r7_997;
    void *temp_r31_982;
    void *temp_r6_1002;
    void *temp_r8_1074;
    void *temp_r9_1079;

    if (((u8) this->unkB4 != 0) && ((s32) this->unkD8 > 0)) {
        temp_r31_982 = MKView_GetCameraMatrix() + 0x30;
        InitDraw(arg0, arg1);
        var_r30_987 = this->unkD0;
loop_15:
        if (var_r30_987 != NULL) {
            if ((s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(this->unk0, void **, 0x38), void **, 0x24), s32 *, 0x24) == 3) {
                var_r7_997 = 0;
                var_r3_998 = 0;
                var_r4_999 = 0;
loop_6:
                if (var_r7_997 < (s32) M2C_FIELD(var_r30_987, s32 *, 0xA84)) {
                    temp_r6_1002 = var_r30_987 + var_r4_999;
                    temp_f3_1004 = M2C_FIELD(temp_r6_1002, f32 *, 4);
                    temp_f6_1008 = M2C_FIELD(temp_r6_1002, f32 *, 0);
                    temp_f7_1017 = M2C_FIELD(temp_r6_1002, f32 *, 8);
                    sp30 = arg0->unk30 + ((temp_f7_1017 * arg0->unk20) + ((temp_f6_1008 * arg0->unk0) + (temp_f3_1004 * arg0->unk10)));
                    sp34 = arg0->unk34 + ((temp_f7_1017 * arg0->unk24) + ((temp_f6_1008 * arg0->unk4) + (temp_f3_1004 * arg0->unk14)));
                    sp38 = arg0->unk38 + ((temp_f7_1017 * arg0->unk28) + ((temp_f6_1008 * arg0->unk8) + (temp_f3_1004 * arg0->unk18)));
                    sp40 = (f64) sp30;
                    sp48 = (f64) sp38;
                    temp_f0_1039 = (f64) sp30 - M2C_FIELD(temp_r31_982, f64 *, 0);
                    sp20 = temp_f0_1039;
                    var_r7_997 += 1;
                    var_r4_999 += 0x30;
                    sp50 = temp_f0_1039;
                    sp28 = (f32) sp48 - M2C_FIELD(temp_r31_982, f32 *, 8);
                    sp58 = (f64) sp28;
                    *(&spA0 + var_r3_998) = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp50 + 0x4)) * (*(f32 *) ((u8 *) &sp50 + 0x4))));
                    var_r3_998 += 4;
                    goto loop_6;
                }
                var_r10_1065 = 1;
loop_13:
                if (var_r10_1065 < (s32) M2C_FIELD(var_r30_987, s32 *, 0xA84)) {
                    var_r11_1068 = var_r10_1065 - 1;
                    var_r3_1069 = var_r11_1068 * 0x30;
                    var_r4_1070 = var_r11_1068 * 4;
loop_11:
                    if (var_r11_1068 >= 0) {
                        temp_r8_1074 = &spA0 + var_r4_1070;
                        if (M2C_FIELD(temp_r8_1074, f32 *, 0) < M2C_FIELD(temp_r8_1074, f32 *, 4)) {
                            temp_r9_1079 = var_r30_987 + var_r3_1069;
                            M2C_STRUCT_COPY((s32) &unksp5C + 4, (s32) (((u8 *) temp_r9_1079) - 4) + 4, 0x30);
                            var_r11_1068 -= 1;
                            var_r3_1069 -= 0x30;
                            temp_f3_1094 = M2C_FIELD(temp_r8_1074, f32 *, 0);
                            var_r4_1070 -= 4;
                            M2C_FIELD(temp_r9_1079, f64 *, 0) = (f64) M2C_FIELD(temp_r9_1079, f64 *, 0x30);
                            M2C_FIELD(temp_r9_1079, f64 *, 8) = (f64) M2C_FIELD(temp_r9_1079, f64 *, 0x38);
                            M2C_FIELD(temp_r8_1074, f32 *, 0) = (f32) M2C_FIELD(temp_r8_1074, f32 *, 4);
                            M2C_FIELD(temp_r9_1079, f64 *, 0x10) = (f64) M2C_FIELD(temp_r9_1079, f64 *, 0x40);
                            M2C_FIELD(temp_r9_1079, f64 *, 0x18) = (f64) M2C_FIELD(temp_r9_1079, f64 *, 0x48);
                            M2C_FIELD(temp_r8_1074, f32 *, 4) = temp_f3_1094;
                            M2C_FIELD(temp_r9_1079, f32 *, 0x20) = (f32) M2C_FIELD(temp_r9_1079, f32 *, 0x50);
                            M2C_FIELD(temp_r9_1079, f32 *, 0x24) = (f32) M2C_FIELD(temp_r9_1079, f32 *, 0x54);
                            M2C_FIELD(temp_r9_1079, f32 *, 0x28) = (f32) M2C_FIELD(temp_r9_1079, f32 *, 0x58);
                            M2C_FIELD(temp_r9_1079, s32 *, 0x2C) = (s32) M2C_FIELD(temp_r9_1079, s32 *, 0x5C);
                            M2C_FIELD(temp_r9_1079, f64 *, 0x30) = sp60;
                            M2C_FIELD(temp_r9_1079, f64 *, 0x38) = sp68;
                            M2C_FIELD(temp_r9_1079, f64 *, 0x40) = sp70;
                            M2C_FIELD(temp_r9_1079, f64 *, 0x48) = sp78;
                            M2C_FIELD(temp_r9_1079, f32 *, 0x50) = sp80;
                            M2C_FIELD(temp_r9_1079, f32 *, 0x54) = sp84;
                            M2C_FIELD(temp_r9_1079, f32 *, 0x58) = sp88;
                            M2C_FIELD(temp_r9_1079, s32 *, 0x5C) = sp8C;
                            goto loop_11;
                        }
                    }
                    var_r10_1065 += 1;
                    goto loop_13;
                }
            }
            DrawChunk(arg0, arg1, var_r30_987);
            var_r30_987 = M2C_FIELD(var_r30_987, MKParticleChunk **, 0xA8C);
            goto loop_15;
        }
        MKEndPrimitive();
    }
}
#endif

void MKBaseParticleSystem::Draw() {
    f64 sp10;
    f64 sp8;
    MKBaseParticleSystem *temp_r3_1194;
    u32 temp_r0_1211;
    u32 var_r3_1210;
    void *temp_r3_1176;
    void *temp_r3_1182;

    this->unkBC = OSGetTick();
    sp10 = this->unk58;
    sp8 = this->unk50;
    (*(f32 *) ((u8 *) &sp10 + 0x4)) *= this->unk20;
    temp_r3_1176 = this->unk0;
    if ((u32) M2C_FIELD(temp_r3_1176, u32 *, 0x2C) == 0U) {
        temp_r3_1182 = (void *) (M2C_FIELD(M2C_FIELD(temp_r3_1176, void **, 0x38), s32 *, 0x24) + 0x30);
        sp8 *= M2C_FIELD(temp_r3_1182, f64 *, 0);
        sp10 *= M2C_FIELD(temp_r3_1182, f64 *, 8);
    }
    temp_r3_1194 = this->unkC8;
    if (temp_r3_1194 != NULL) {
        temp_r3_1194->Draw(&this->unk60, (MKVector4 *) &sp8);
        return;
    }
    Draw(&this->unk60, (MKVector4 *) &sp8);
    this->unkBC = OSGetTick() - this->unkBC;
    var_r3_1210 = this->unkBC;
    temp_r0_1211 = this->unkC4;
    if (temp_r0_1211 > var_r3_1210) {
        var_r3_1210 = temp_r0_1211;
    }
    this->unkC4 = var_r3_1210;
}

void MKBaseParticleSystem::EmitParticles() {

}

void MKBaseParticleSystem::PostUpdate() {
    MKParticleChunk *temp_r4_1239;
    MKParticleChunk *temp_r4_1253;
    MKParticleChunk *var_r7_1234;
    u8 var_r6_1235;
    void *temp_r5_1248;

    var_r7_1234 = this->unkD0;
    var_r6_1235 = 0;
loop_10:
    if (var_r7_1234 != NULL) {
        temp_r4_1239 = M2C_FIELD(var_r7_1234, MKParticleChunk **, 0xA8C);
        if ((s32) M2C_FIELD(var_r7_1234, s32 *, 0xA84) >= 0x18) {
            var_r6_1235 = 1;
        } else if (var_r6_1235 != 0) {
            temp_r5_1248 = M2C_FIELD(var_r7_1234, void **, 0xA88);
            if (temp_r5_1248 != NULL) {
                M2C_FIELD(temp_r5_1248, MKParticleChunk **, 0xA8C) = temp_r4_1239;
            }
            temp_r4_1253 = M2C_FIELD(var_r7_1234, MKParticleChunk **, 0xA8C);
            if (temp_r4_1253 != NULL) {
                M2C_FIELD(temp_r4_1253, void **, 0xA88) = (void *) M2C_FIELD(var_r7_1234, void **, 0xA88);
            }
            M2C_FIELD(var_r7_1234, MKParticleChunk **, 0xA8C) = (MKParticleChunk *) this->unkD0;
            M2C_FIELD(var_r7_1234, void **, 0xA88) = NULL;
            M2C_FIELD(this->unkD0, MKParticleChunk **, 0xA88) = var_r7_1234;
            this->unkD0 = var_r7_1234;
        }
        var_r7_1234 = temp_r4_1239;
        goto loop_10;
    }
}

void *MKBaseParticleSystem::Update() {
    f32 temp_f1_1288;
    u32 temp_r0_1330;
    u32 var_r3_1329;

    if ((MKBaseParticleSystem *) this->unkC8 == NULL) {
        if ((u8) this->unkDC != 0) {
            temp_f1_1288 = this->unkE0;
            if (temp_f1_1288 <= 0.0f) {
                this->unkDC = 0;
                this->unkE0 = 0.0f;
                if (OnTimeOut() == 0) {
                    return;
                }
                goto block_6;
            }
            this->unkE0 = temp_f1_1288 - gUpdateTimeDelta;
            goto block_6;
        }
block_6:
        if ((u8) this->unkB4 != 0) {
            this->unkB8 = OSGetTick();
            EmitParticles();
            UpdateParticles();
            PostUpdate();
            this->unkB8 = OSGetTick() - this->unkB8;
            var_r3_1329 = this->unkB8;
            temp_r0_1330 = this->unkC0;
            if (temp_r0_1330 > var_r3_1329) {
                var_r3_1329 = temp_r0_1330;
            }
            this->unkC0 = var_r3_1329;
        }
    }
}

s32 MKBaseParticleSystem::OnTimeOut() {
    Disable();
    return 1;
}

void MKBaseParticleSystem::Deinit() {
    DestroyAllParticles();
    MKProp::Deinit();
}

void MKBaseParticleSystem::Init() {
    MKProp::Init();
    M2C_FIELD(this, f32 *, 0x50) = 1.0f;
    M2C_FIELD(this, f32 *, 0x54) = 1.0f;
    M2C_FIELD(this, f32 *, 0x58) = 1.0f;
    M2C_FIELD(this, f32 *, 0x5C) = 1.0f;
    this->unk60.SetIdentity();
    this->unkA0 = NULL;
    this->unkA4 = 1;
    this->unkC8 = NULL;
    this->unkCC = -1;
    this->unkD0 = NULL;
    this->unkD4 = 0;
    this->unkD8 = 0;
    this->unkB4 = 0;
    this->unkDC = 0;
    this->unkE0 = 0.0f;
    this->unkA8 = 500.0f;
    this->unkAC = 500.0f;
    this->unkB0 = 0.0f;
    this->unk4 = NULL;
    this->unk8 = &this->unk60;
}
