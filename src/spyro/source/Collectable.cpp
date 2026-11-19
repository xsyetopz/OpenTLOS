#include "spyro/source/Collectable.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDVolume.h"
#include "spyro/source/KDWaterVolume.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKShape.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "common/gc/Sound_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PropFlags.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

f64 atan2(f32, f32);                                /* extern */
f64 fmod(f32, f64);                                 /* extern */
M2C_UNK free(Matrix *);                             /* extern */
Matrix *malloc(s32);                                /* extern */
extern s32 GS_GemBounce;
extern s32 GS_GemCollect;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

void Collectable::CollectEffects() {

}

#if 0 // DRAFT: illegal implicit conversion from 'Matrix' to
void CollectableSpawner::Emit(SpawnInfo *arg0) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_127;
    f32 temp_f1_156;
    f32 temp_f2_105;
    f32 temp_f2_151;
    f32 temp_f30_122;
    f32 temp_f31_125;
    f32 var_f29_111;
    f64 temp_f0_137;
    f64 temp_f0_148;
    s32 temp_r3_186;
    void *temp_r3_166;
    void *temp_r3_179;
    void *temp_r3_65;
    void *temp_r3_72;
    void *temp_r3_79;
    void *temp_r3_88;

    temp_r3_65 = *(this->unk4C + (this->unk54 * 4));
    M2C_FIELD(temp_r3_65, u8 *, 0x144) = (u8) (M2C_FIELD(temp_r3_65, u8 *, 0x144) & ~0x20);
    temp_r3_72 = *(this->unk4C + (this->unk54 * 4));
    M2C_FIELD(temp_r3_72, u8 *, 0x144) = (u8) (M2C_FIELD(temp_r3_72, u8 *, 0x144) | 0x40);
    temp_r3_79 = *(this->unk4C + (this->unk54 * 4));
    M2C_FIELD(M2C_FIELD(temp_r3_79, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x5C)(temp_r3_79, 0, 1, 0);
    temp_r3_88 = *(this->unk4C + (this->unk54 * 4));
    M2C_FIELD(M2C_FIELD(temp_r3_88, void **, 0x44), M2C_UNK (**)(void *, s32), 0x50)(temp_r3_88, arg0->unk20);
    M2C_FIELD(*(this->unk4C + (this->unk54 * 4)), s32 *, 0xC8) = (s32) arg0->unk24;
    M2C_FIELD(*(this->unk4C + (this->unk54 * 4)), CollectableSpawner **, 0xCC) = this;
    temp_f2_105 = arg0->unk14;
    if (temp_f2_105 > 0.0f) {
        var_f29_111 = arg0->unk18 + arg0->unk1C;
loop_3:
        if (var_f29_111 > 6.2831855f) {
            var_f29_111 -= 6.2831855f;
            goto loop_3;
        }
        temp_f30_122 = MKRand_Float((int *) &gViewSeed, arg0->unk10, temp_f2_105);
        temp_f31_125 = _table_sinf(1.5707964f + var_f29_111);
        temp_f1_127 = _table_sinf(var_f29_111);
        sp30 = temp_f31_125;
        sp28 = temp_f1_127;
        sp2C = 0.0f;
        sp40 = (f64) sp30;
        sp38 = (f64) sp28;
        temp_f0_137 = sp38 * (f64) temp_f30_122;
        sp18 = temp_f0_137;
        sp48 = temp_f0_137;
        sp20 = (f32) sp40 * temp_f30_122;
        sp50 = (f64) sp20;
        temp_f0_148 = M2C_FIELD(arg0, f64 *, 0) + temp_f0_137;
        sp8 = temp_f0_148;
        temp_f2_151 = arg0->unk8;
        temp_f1_156 = temp_f2_151 + (f32) sp50;
        sp58 = temp_f0_148;
        sp10 = temp_f1_156;
        sp60 = (f64) sp10;
        (*(f32 *) ((u8 *) &sp58 + 0x4)) = arg0->unk4;
        temp_r3_166 = *(this->unk4C + (this->unk54 * 4));
        M2C_FIELD(M2C_FIELD(temp_r3_166, void **, 0x44), M2C_UNK (**)(void *, SpawnInfo *, f64 *, M2C_UNK, f32, f32), 0x40)(temp_r3_166, arg0, &sp58, 0, temp_f1_156, temp_f2_151);
    } else {
        temp_r3_179 = *(this->unk4C + (this->unk54 * 4));
        M2C_FIELD(M2C_FIELD(temp_r3_179, void **, 0x44), M2C_UNK (**)(void *, SpawnInfo *, M2C_UNK, M2C_UNK), 0x40)(temp_r3_179, arg0, 0, 0);
    }
    temp_r3_186 = this->unk54 + 1;
    this->unk54 = temp_r3_186;
    if (temp_r3_186 >= (s32) this->unk50) {
        this->unk54 = 0;
    }
}
#endif

void CollectableSpawner::Spawn(const MKVector3 &arg0, float arg1, float arg2) {
    s32 temp_r0_227;
    s32 temp_r5_218;
    s32 temp_r5_228;
    s32 temp_r6_240;
    s32 var_r0_241;
    void *temp_r3_256;

    temp_r5_218 = this->unk60;
    if ((temp_r5_218 == (s32) this->unk5C) && (temp_r5_218 > 0)) {
        this->unk64 += 1;
        temp_r0_227 = this->unk64;
        temp_r5_228 = this->unk5C;
        if (temp_r0_227 >= temp_r5_228) {
            this->unk64 = temp_r0_227 - temp_r5_228;
        }
        this->unk60 -= 1;
    }
    temp_r6_240 = this->unk5C;
    var_r0_241 = this->unk64 + this->unk60;
    if (var_r0_241 >= temp_r6_240) {
        var_r0_241 -= temp_r6_240;
    }
    this->unk60 += 1;
    temp_r3_256 = this->unk68 + (var_r0_241 * 0x28);
    M2C_FIELD(temp_r3_256, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(temp_r3_256, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(temp_r3_256, f32 *, 0x10) = arg1;
    M2C_FIELD(temp_r3_256, f32 *, 0x14) = arg1;
    M2C_FIELD(temp_r3_256, f32 *, 0x18) = arg2;
    M2C_FIELD(temp_r3_256, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(temp_r3_256, s32 *, 0x20) = -1;
    M2C_FIELD(temp_r3_256, s32 *, 0x24) = 0;
}

void CollectableSpawner::Spawn(const MKVector3 &arg0, int arg1, float arg2, float arg3, int arg4, MKProp *arg5) {
    f32 temp_f26_353;
    f32 temp_f27_304;
    f64 temp_f28_305;
    f64 temp_f29_306;
    s32 temp_r0_323;
    s32 temp_r3_314;
    s32 temp_r3_324;
    s32 temp_r4_336;
    s32 var_r0_337;
    s32 var_r0_365;
    s32 var_r31_309;
    void *temp_r24_354;

    if (arg1 >= 1) {
        temp_f27_304 = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        temp_f28_305 = M2C_FIELD(&arg0, f64 *, 0);
        temp_f29_306 = M2C_FIELD(&arg0, f64 *, 8);
        var_r31_309 = 0;
loop_12:
        if (var_r31_309 < arg1) {
            temp_r3_314 = this->unk60;
            if ((temp_r3_314 == (s32) this->unk5C) && (temp_r3_314 > 0)) {
                this->unk64 += 1;
                temp_r0_323 = this->unk64;
                temp_r3_324 = this->unk5C;
                if (temp_r0_323 >= temp_r3_324) {
                    this->unk64 = temp_r0_323 - temp_r3_324;
                }
                this->unk60 -= 1;
            }
            temp_r4_336 = this->unk5C;
            var_r0_337 = this->unk64 + this->unk60;
            if (var_r0_337 >= temp_r4_336) {
                var_r0_337 -= temp_r4_336;
            }
            this->unk60 += 1;
            temp_f26_353 = 6.2831855f / (f32) arg1;
            temp_r24_354 = this->unk68 + (var_r0_337 * 0x28);
            M2C_FIELD(temp_r24_354, f64 *, 0) = temp_f28_305;
            M2C_FIELD(temp_r24_354, f64 *, 8) = temp_f29_306;
            M2C_FIELD(temp_r24_354, f32 *, 0x10) = arg2;
            M2C_FIELD(temp_r24_354, f32 *, 0x14) = arg3;
            M2C_FIELD(temp_r24_354, f32 *, 0x18) = temp_f27_304;
            var_r0_365 = arg4;
            M2C_FIELD(temp_r24_354, f32 *, 0x1C) = (f32) (temp_f26_353 * ((f32) var_r31_309 + MKRand_Float((int *) &gViewSeed, 0.0f, temp_f26_353)));
            if (arg4 > -1) {
                var_r0_365 = arg4 + var_r31_309;
            }
            M2C_FIELD(temp_r24_354, s32 *, 0x20) = var_r0_365;
            var_r31_309 += 1;
            M2C_FIELD(temp_r24_354, MKProp **, 0x24) = arg5;
            goto loop_12;
        }
    }
}

void CollectableSpawner::Message(MKMessage *arg0) {
    MKProp::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'Matrix *' to
void *CollectableSpawner::Update() {
    SpawnInfo *var_r0_434;
    SpawnInfo *var_r4_439;
    s32 temp_r0_450;
    s32 temp_r3_451;
    s32 var_r31_428;

    MKProp::Update();
    var_r31_428 = 0;
    if ((s32) this->unk60 > 0) {
        var_r0_434 = this->unk68 + (this->unk64 * 0x28);
    } else {
        var_r0_434 = NULL;
    }
    var_r4_439 = var_r0_434;
loop_12:
    if ((var_r4_439 != NULL) && (var_r31_428 < 5)) {
        Emit(var_r4_439);
        if ((s32) this->unk60 > 0) {
            this->unk64 += 1;
            temp_r0_450 = this->unk64;
            temp_r3_451 = this->unk5C;
            if (temp_r0_450 >= temp_r3_451) {
                this->unk64 = temp_r0_450 - temp_r3_451;
            }
            this->unk60 -= 1;
        }
        if ((s32) this->unk60 > 0) {
            var_r4_439 = this->unk68 + (this->unk64 * 0x28);
        } else {
            var_r4_439 = NULL;
        }
        var_r31_428 += 1;
        goto loop_12;
    }
}
#endif

void CollectableSpawner::Reset() {
    MKProp::Reset();
    this->unk64 = 0;
    this->unk60 = 0;
}

#if 0 // DRAFT: ')' expected
f32 CollectableSpawner::Resolve() {
    MKHeap *temp_r29_525;
    MKHeap *temp_r3_523;
    MKHeap *temp_r3_545;
    MKHeap *var_r29_562;
    MKHeap *var_r3_528;
    Matrix *var_r3_552;
    s32 temp_r30_544;
    s32 var_r30_559;
    void *temp_r3_574;
    void *temp_r3_579;
    void *temp_r3_584;

    MKProp::Resolve();
    temp_r3_523 = checked_cast<CollectableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, s32), 0x5C)(gMK, M2C_FIELD(checked_cast<CollectableSpawnerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60)));
    temp_r29_525 = temp_r3_523;
    this->unk50 = 0;
    var_r3_528 = checked_cast<Collectable *, MKProp>((MKProp *) temp_r3_523->unk28);
loop_4:
    if (var_r3_528 != NULL) {
        if ((void *) var_r3_528->unkC8 == NULL) {
            this->unk50 += 1;
        }
        var_r3_528 = checked_cast<Collectable *, MKProp>(M2C_BITWISE(MKProp *, var_r3_528->unk38));
        goto loop_4;
    }
    temp_r30_544 = this->unk50 * 4;
    temp_r3_545 = var_r3_528->Current();
    if (temp_r3_545 != NULL) {
        var_r3_552 = ((MKHeap *) (temp_r3_545->Current()))->Alloc(temp_r30_544, NULL, 0);
    } else {
        var_r3_552 = malloc(temp_r30_544);
    }
    this->unk4C = var_r3_552;
    var_r30_559 = 0;
    var_r29_562 = checked_cast<Collectable *, MKProp>((MKProp *) temp_r29_525->unk28);
loop_12:
    if (var_r29_562 != NULL) {
        if ((void *) var_r29_562->unkC8 == NULL) {
            *(this->unk4C + var_r30_559) = var_r29_562;
            temp_r3_574 = *(this->unk4C + var_r30_559);
            M2C_FIELD(temp_r3_574, u8 *, 0x144) = (u8) (M2C_FIELD(temp_r3_574, u8 *, 0x144) & ~0x20);
            temp_r3_579 = *(this->unk4C + var_r30_559);
            M2C_FIELD(temp_r3_579, u8 *, 0x144) = (u8) (M2C_FIELD(temp_r3_579, u8 *, 0x144) | 0x40);
            temp_r3_584 = *(this->unk4C + var_r30_559);
            M2C_FIELD(M2C_FIELD(temp_r3_584, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x5C)(temp_r3_584, 0, 1, 0);
            var_r30_559 += 4;
        }
        var_r29_562 = checked_cast<Collectable *, MKProp>(M2C_BITWISE(MKProp *, var_r29_562->unk38));
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CollectableSpawner::Deinit() {
    MKHeap *temp_r3_615;
    MKHeap *temp_r3_638;
    Matrix *temp_r31_612;
    Matrix *temp_r31_635;

    temp_r31_612 = this->unk68;
    if (temp_r31_612 != NULL) {
        temp_r3_615 = MKHeap::Current();
        if (temp_r3_615 != NULL) {
            ((MKHeap *) (temp_r3_615->Current()))->Free(temp_r31_612, NULL, 0);
        } else {
            free(temp_r31_612);
        }
        this->unk68 = NULL;
    }
    this->unk5C = 0;
    this->unk64 = 0;
    this->unk60 = 0;
    temp_r31_635 = this->unk4C;
    if (temp_r31_635 != NULL) {
        temp_r3_638 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_638 != NULL) {
            ((MKHeap *) (temp_r3_638->Current()))->Free(temp_r31_635, NULL, 0);
        } else {
            free(temp_r31_635);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void CollectableSpawner::Init() {
    MKHeap *temp_r3_674;
    Matrix *var_r3_681;

    MKProp::Init();
    this->unk4C = NULL;
    this->unk54 = 0;
    temp_r3_674 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_674 != NULL) {
        var_r3_681 = ((MKHeap *) (temp_r3_674->Current()))->Alloc(0x7D0, NULL, 0);
    } else {
        var_r3_681 = malloc(0x7D0);
    }
    this->unk68 = var_r3_681;
    this->unk5C = 0x32;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 CollectableSpawnerDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_706;

    var_r31_706 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadString("propName", &this->unk60, 0) != 0)) {
        var_r31_706 = 1;
    }
    return var_r31_706;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[5]' to
void CollectableSpawnerDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = "Opal";
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Collectable::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_757;

    temp_r3_757 = this->unkC4;
    if (temp_r3_757 != NULL) {
        spC = 0;
        sp8 = 0x24;
        sp10 = &this->unkB0;
        sp14 = 0;
        sp18 = 0;
        M2C_FIELD(temp_r3_757->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x24, 0);
        this->unkC4 = NULL;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void Collectable::PlatformAttach(MKProp *arg0) {
    s32 sp18;
    s8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;

    this->unkC4 = arg0;
    spC = 0;
    sp8 = 0x23;
    sp10 = &this->unkB0;
    sp14 = 0;
    sp18 = 0;
    arg0->Message(&sp8, 0x23, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkBC'
s32 Collectable::PlayCollectSound() {
    s32 temp_r3_817;

    temp_r3_817 = this->unk124->unkBC;
    if (temp_r3_817 != 0) {
        return KDSound_Play(temp_r3_817, 0U, -1);
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Collectable::RotateCameraFacing() {
    Matrix spA0;
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp10;
    MKHeap *temp_r3_868;
    f32 temp_f3_939;
    f64 temp_f1_892;
    f64 temp_f1_905;
    void *temp_r5_891;
    void *temp_r5_902;

    M2C_STRUCT_COPY((s32) &sp60.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    if ((s32) this->unk124->unk9C & 2) {
        spA0.SetRotationYaw(this->unk60.unk4);
    }
    sp60.SetIdentity();
    temp_r3_868 = this->unk124;
    if ((s32) temp_r3_868->unk9C & 0x40) {
        sp60.SetRotationPitch(M2C_BITWISE(f32, temp_r3_868->unk70));
    }
    spA0.Multiply3x3(&spA0, &sp60);
    if ((s32) this->unk124->unk9C & 4) {
        temp_r5_891 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        temp_f1_892 = M2C_FIELD(temp_r5_891, f64 *, 0x30);
        sp20 = temp_f1_892;
        sp28 = M2C_FIELD(temp_r5_891, f64 *, 0x38);
        M2C_FIELD(this->__vptr, M2C_UNK (**)(f32 *, Collectable *, void *, f64, f32, f32), 0x44)(&sp10, this, temp_r5_891, temp_f1_892);
        temp_r5_902 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        temp_f1_905 = M2C_FIELD(temp_r5_902, f64 *, 0x30);
        sp40 = temp_f1_905;
        sp48 = M2C_FIELD(temp_r5_902, f64 *, 0x38);
        M2C_FIELD(this->__vptr, M2C_UNK (**)(f32 *, Collectable *, void *, f64, f32, f32), 0x44)(&sp30, this, temp_r5_902, temp_f1_905, (f32) sp28, sp18);
        sp60.SetRotationYaw(3.1415927f - (f32) atan2((f32) sp40 - sp30, (f32) sp28 - sp18));
    }
    spA0.Multiply3x3(&spA0, &sp60);
    spA0.Scale3x3(&spA0, this->unkE0);
    sp50 = this->unk50;
    sp58 = this->unk58;
    temp_f3_939 = (*(f32 *) ((u8 *) &sp50 + 0x4)) + this->unkF4;
    spA0.unk30 = (f32) sp50;
    spA0.unk34 = temp_f3_939;
    spA0.unk38 = (f32) sp58;
    spA0.unk3C = 1.0f;
    (*(f32 *) ((u8 *) &sp50 + 0x4)) = temp_f3_939;
    MKModel_SetWorldMatrix(this->unk4, spA0);
}
#endif

void Collectable::SetState(CollectableState arg0) {
    u8 *temp_r4_1005;

    if ((u32) arg0 <= 0xAU) {
        switch ((s32) arg0) {
        case 0:
        case 1:
        case 10:
            if (!((s32) this->unk124->unk9C & 0x1000)) {
                PropFlagsClear((unsigned int *) &this->unk10, 0x160000U);
                Disable();
            } else {
                this->unkF8 = (this->unk124->unk7C * MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f)) + M2C_FIELD(&gb, f32 *, 0x30C);
            }
            temp_r4_1005 = &this->unk128;
            M2C_FIELD(this->unk130, void **, 4) = (void *) this->unk12C;
            M2C_FIELD(this->unk12C, void **, 8) = (void *) this->unk130;
            this->unk130 = temp_r4_1005;
            this->unk12C = temp_r4_1005;
            this->unkC8 = NULL;
            PlatformDetach();
            break;
        case 8:
            PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
            Enable();
            CollectingStateInit();
            PlatformDetach();
            break;
        case 3:
            PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
            Enable();
            this->unkF8 = 0.5f;
            break;
        case 7:
            PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
            Enable();
            this->unk7C = 0.0f;
            break;
        case 2:
            PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
            Enable();
            this->unkF8 = 0.5f;
            break;
        case 6:
        case 9:
            PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
            Enable();
            break;
        }
    }
    this->unkD4 = (s32) arg0;
}

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::CollectedState() {
    Matrix sp10;
    M2C_UNK spC;
    f32 var_f0_1114;

    if ((M2C_FIELD(&gb, f32 *, 0x30C) > this->unkF8) && ((s32) this->unk124->unk9C & 0x1000)) {
        var_f0_1114 = (4.0f * gUpdateTimeDelta) + this->unkE0;
        if (var_f0_1114 < 1.0f) {

        } else {
            var_f0_1114 = 1.0f;
        }
        this->unkE0 = var_f0_1114;
        this->unkE8 = var_f0_1114;
        M2C_STRUCT_COPY((s32) &spC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        Tools_SetMatrixScale(&sp10, this->unkE0);
        MKModel_SetWorldMatrix(this->unk4, sp10);
        if (this->unkE0 >= 1.0f) {
            this->unkF8 = 0.0f;
            if ((u8) M2C_FIELD(this->unk124, u8 *, 0x67) != 0) {
                CalcShadowPos();
            }
            SetState(6);
        }
    }
}
#endif

void Collectable::PresentingState() {
    MKHeap *temp_r4_1197;
    f32 var_f0_1182;

    var_f0_1182 = (2.5f * (this->unkE4 * gUpdateTimeDelta)) + this->unkE0;
    if (var_f0_1182 < 1.0f) {

    } else {
        var_f0_1182 = 1.0f;
    }
    if (var_f0_1182 > 0.0f) {

    } else {
        var_f0_1182 = 0.0f;
    }
    this->unkE0 = var_f0_1182;
    temp_r4_1197 = this->unk124;
    if ((s32) temp_r4_1197->unk9C & 2) {
        this->unk60.unk4 += temp_r4_1197->unk6C * gUpdateTimeDelta;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::CollectingState() {
    Matrix sp10;
    M2C_UNK spC;
    f32 temp_f2_1226;

    this->unkE8 = -((2.0f * gUpdateTimeDelta) - this->unkE8);
    temp_f2_1226 = this->unkE0;
    if (temp_f2_1226 > 0.0f) {
        this->unkE0 = -((4.0f * gUpdateTimeDelta) - temp_f2_1226);
    }
    if ((this->unkE8 <= 0.0f) || (this->unkE0 <= 0.0f) || ((s32) this->unk124->unk9C & 0x400)) {
        this->unkE8 = 0.0f;
        this->unkE0 = 0.0f;
        SetState(0xA);
    }
    M2C_STRUCT_COPY((s32) &spC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    Tools_SetMatrixScale(&sp10, this->unkE0);
    MKModel_SetWorldMatrix(this->unk4, sp10);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkBC'
void Collectable::CollectingStateInit() {
    MKHeap *temp_r5_1292;
    s32 temp_r3_1309;

    temp_r5_1292 = this->unk124;
    if (((s32) temp_r5_1292->unkBC > -1) && (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r5_1292->unkA0)) {
        temp_r5_1292->unkA0 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.05f;
        temp_r3_1309 = PlayCollectSound();
        if (((s32) this->unk124->unk9C & 0x80) && (temp_r3_1309 > 0)) {
            Sound_MusicDuckVolume(0U, temp_r3_1309, 0xF);
        }
    }
    this->unk121 = 0;
    CollectEffects();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::MagnetisedState() {
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f1_1491;
    f32 temp_f28_1493;
    f32 temp_f31_1492;
    f32 var_f29_1406;
    f32 var_f4_1473;
    f64 temp_f0_1375;
    f64 temp_f0_1520;
    f64 temp_f1_1412;
    f64 temp_f1_1418;
    f64 temp_f1_1422;
    f64 temp_f2_1376;
    s32 temp_r3_1441;
    s32 var_r0_1451;
    void *temp_r3_1373;
    void *temp_r4_1351;

    temp_r4_1351 = this->unkC0;
    if (temp_r4_1351 == NULL) {
        SetState(8);
        return;
    }
    if (this->unk7C >= 50.0f) {
        SetState(8);
        return;
    }
    temp_r3_1373 = M2C_FIELD(temp_r4_1351, void **, 8);
    temp_f0_1375 = M2C_FIELD(temp_r3_1373, f64 *, 0x30);
    temp_f2_1376 = M2C_FIELD(temp_r3_1373, f64 *, 0x38);
    sp90 = temp_f0_1375;
    this->unk90 = temp_f0_1375;
    this->unk98 = temp_f2_1376;
    sp98 = temp_f2_1376;
    M2C_FIELD(this, f32 *, 0x94) = (f32) (M2C_FIELD(this, f32 *, 0x94) + this->unkD8);
    sp30 = this->unk90 - this->unk50;
    spA0 = sp30;
    sp38 = (f32) M2C_FIELD(this, f64 *, 0x98) - M2C_FIELD(this, f32 *, 0x58);
    spA8 = (f64) sp38;
    var_f29_1406 = ((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + ((*(f32 *) ((u8 *) &sp98 + 0xc)) * (*(f32 *) ((u8 *) &sp98 + 0xc))));
    if (var_f29_1406 > 0.000001f) {
        if (var_f29_1406 > 0.0f) {
            temp_f1_1412 = __frsqrte(var_f29_1406);
            temp_f1_1418 = 0.5 * temp_f1_1412 * -(((f64) var_f29_1406 * (temp_f1_1412 * temp_f1_1412)) - 3.0);
            temp_f1_1422 = 0.5 * temp_f1_1418 * -(((f64) var_f29_1406 * (temp_f1_1418 * temp_f1_1418)) - 3.0);
            var_f29_1406 = (f32) ((f64) var_f29_1406 * (0.5 * temp_f1_1422 * -(((f64) var_f29_1406 * (temp_f1_1422 * temp_f1_1422)) - 3.0)));
        } else if (var_f29_1406 < M2C_BITWISE(f32, 0.0)) {
            var_f29_1406 = __float_nan;
        } else {
            sp8 = var_f29_1406;
            temp_r3_1441 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1441) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1451 = 1;
                } else {
                    var_r0_1451 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1451 = 5;
                } else {
                    var_r0_1451 = 3;
                }
                break;
            default:
                var_r0_1451 = 4;
                break;
            }
            if (var_r0_1451 == 1) {
                var_f29_1406 = __float_nan;
            }
        }
        var_f4_1473 = 1.0f / var_f29_1406;
    } else {
        var_f4_1473 = 0.0f;
        var_f29_1406 = 0.0f;
    }
    spA0 = (f32) spA0 * var_f4_1473;
    (*(f32 *) ((u8 *) &sp98 + 0xc)) *= var_f4_1473;
    spA8 = (f32) spA8 * var_f4_1473;
    temp_f1_1491 = this->unk7C;
    temp_f31_1492 = this->unkF0;
    temp_f28_1493 = temp_f1_1491 + gUpdateTimeDelta;
    sp50.operator*(temp_f1_1491);
    sp60.operator*(32.0f);
    sp70.operator*(var_f29_1406);
    sp20 = sp70 * (f64) temp_f31_1492;
    this->unk70 = sp20;
    sp28 = sp70.unk8 * temp_f31_1492;
    sp80 = sp20;
    M2C_FIELD(this, f64 *, 0x78) = (f64) sp28;
    sp88 = (f64) sp28;
    temp_f0_1520 = this->unk70 * (f64) gUpdateTimeDelta;
    sp10 = temp_f0_1520;
    sp40 = temp_f0_1520;
    sp18 = (f32) M2C_FIELD(this, f64 *, 0x78) * gUpdateTimeDelta;
    sp48 = (f64) sp18;
    this->unk50 += temp_f0_1520;
    M2C_FIELD(this, f32 *, 0x58) = (f32) (M2C_FIELD(this, f32 *, 0x58) + (f32) sp48);
    this->unk7C = temp_f28_1493;
    if (((u8) M2C_FIELD(this->unk124, u8 *, 0x67) != 0) && (((s32) M2C_FIELD(&gb, f32 *, 0x30C) % 5) == 0)) {
        CalcShadowPos();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::IdleState() {
    MKHeap *temp_r3_1607;
    f32 temp_f1_1600;
    f32 temp_f1_1629;

    if ((s32) this->unk124->unk9C & 1) {
        this->unkF4 = this->unk124->unk74 * _table_sinf(this->unkEC);
        this->unkEC += this->unk124->unk78 * gUpdateTimeDelta;
        temp_f1_1600 = this->unkEC;
        if (temp_f1_1600 >= 6.2831855f) {
            this->unkEC = temp_f1_1600 - 6.2831855f;
        }
    }
    temp_r3_1607 = this->unk124;
    if ((s32) temp_r3_1607->unk9C & 2) {
        this->unk60.unk4 += temp_r3_1607->unk6C * gUpdateTimeDelta;
    }
    if (MKCollision_SphereCollide(*((MKVector3 *) &this->unk50), 50.0f, NULL, 1, (MKCollisionMode) 7, 0x83) == 0) {
        FindGround();
    }
    temp_f1_1629 = this->unkFC;
    if (temp_f1_1629 > 0.0f) {
        this->unkFC = temp_f1_1629 - gUpdateTimeDelta;
    }
    if (this->unkFC < 0.0f) {
        this->unkE0 = -((4.0f * gUpdateTimeDelta) - this->unkE0);
        if (this->unkE0 <= 0.0f) {
            this->unkFC = 0.0f;
            this->unkE0 = 1.0f;
            SetState(0);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::JustSpawnedState() {
    MKHeap *temp_r3_1699;
    f32 temp_f0_1714;
    f32 temp_f1_1692;
    f32 temp_f2_1709;

    if ((s32) this->unk124->unk9C & 1) {
        this->unkF4 = this->unk124->unk74 * _table_sinf(this->unkEC);
        this->unkEC += this->unk124->unk78 * gUpdateTimeDelta;
        temp_f1_1692 = this->unkEC;
        if (temp_f1_1692 >= 6.2831855f) {
            this->unkEC = temp_f1_1692 - 6.2831855f;
        }
    }
    temp_r3_1699 = this->unk124;
    if ((s32) temp_r3_1699->unk9C & 2) {
        this->unk60.unk4 += temp_r3_1699->unk6C * gUpdateTimeDelta;
    }
    temp_f2_1709 = this->unkF8;
    if (temp_f2_1709 > 0.0f) {
        temp_f0_1714 = temp_f2_1709 - gUpdateTimeDelta;
        this->unkF8 = temp_f0_1714;
        if (temp_f0_1714 < 0.0f) {
            if ((u8) M2C_FIELD(this->unk124, u8 *, 0x67) != 0) {
                CalcShadowPos();
            }
            SetState(6);
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void Collectable::SpawningState() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKHeap *temp_r3_1756;
    MKHeap *temp_r4_2004;
    f32 temp_f1_1811;
    f32 temp_f1_1868;
    f32 temp_f1_2008;
    f32 temp_f1_2046;
    f32 temp_f2_1766;
    f32 temp_f2_1873;
    f32 temp_f2_1973;
    f32 temp_f2_1980;
    f32 temp_f2_2007;
    f32 temp_f3_1892;
    f32 temp_f5_1901;
    f32 temp_f5_1972;
    f32 temp_f6_1970;
    f32 temp_f7_1894;
    f32 temp_f8_1893;
    f32 var_f1_1985;
    f32 var_f29_1904;
    f64 temp_f0_1916;

    temp_r3_1756 = this->unk124;
    if ((s32) temp_r3_1756->unk9C & 2) {
        this->unk60.unk4 += temp_r3_1756->unk6C * gUpdateTimeDelta;
    }
    temp_f2_1766 = this->unk7C;
    if (temp_f2_1766 >= 1.0f) {
        this->unk7C = 1.0f;
        this->unk50 = this->unk90;
        this->unk58 = this->unk98;
        if (FindGround() == 0) {
            this->unk120 = 1;
            if (((s32) M2C_FIELD(GetDescriptor(), s32 *, 0xC0) != 0) && ((u8) this->unk13C != 0)) {
                temp_f1_1811 = (f32) KDSound_GetSoundEventVol(M2C_FIELD(GetDescriptor(), s32 *, 0xC0));
                this->unk140 = (s32) (this->unk134 * temp_f1_1811);
                KDSound_Play3d(M2C_FIELD(GetDescriptor(temp_f1_1811), s32 *, 0xC0), ((u8 *) this->unk8) + 0x30, 0U, this->unk140, 0.0f, 0U);
            }
            if ((u8) this->unk120 != 0) {
                this->unkC0 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
                if ((void *) this->unkC0 != NULL) {
                    this->unkD8 = M2C_FIELD(*gb, f32 (**)(void **), 0x6C)(gb);
                    SetState(7);
                }
            } else {
                SetState(3);
            }
            goto block_32;
        }
    } else {
        temp_f1_1868 = M2C_FIELD(this, f32 *, 0x70);
        M2C_FIELD(this, f64 *, 0x50) = (f32) ((temp_f2_1766 * ((f32) M2C_FIELD(this, f64 *, 0x90) - temp_f1_1868)) + temp_f1_1868);
        temp_f2_1873 = M2C_FIELD(this, f32 *, 0x78);
        M2C_FIELD(this, f64 *, 0x58) = (f32) ((this->unk7C * ((f32) M2C_FIELD(this, f64 *, 0x98) - temp_f2_1873)) + temp_f2_1873);
        if ((s32) this->unk124->unk9C & 0x2000) {
            temp_f3_1892 = (f32) fmod(3.0f * this->unk7C, 1.0) - 0.5f;
            temp_f8_1893 = this->unk7C;
            temp_f7_1894 = M2C_FIELD(this, f32 *, 0x74);
            temp_f5_1901 = -((4.0f * (temp_f3_1892 * temp_f3_1892)) - 1.0f);
            var_f29_1904 = temp_f5_1901;
            M2C_FIELD(this, f32 *, 0x54) = (f32) ((this->unk100 * (500.0f * temp_f5_1901 * (1.0f - temp_f8_1893))) + ((temp_f8_1893 * (M2C_FIELD(this, f32 *, 0x94) - temp_f7_1894)) + temp_f7_1894));
            if ((s32) this->unk124->unk9C & 0x4000) {
                temp_f0_1916 = this->unkA0 * (f64) gUpdateTimeDelta;
                sp18 = temp_f0_1916;
                sp78 = temp_f0_1916;
                sp20 = this->unkA8 * gUpdateTimeDelta;
                sp80 = (f64) sp20;
                M2C_FIELD(this, f64 *, 0x60) = (f64) (M2C_FIELD(this, f64 *, 0x60) + temp_f0_1916);
                this->unk60.unk8 += (f32) sp80;
                if (this->unk138 > temp_f5_1901) {
                    MKVector(1.0f, 1.0f, 1.0f);
                    MKVector(-1.0f, -1.0f, -1.0f);
                    KDRand_Vector(sp48, sp38);
                    sp58.operator*(3.1415927f);
                    sp8 = sp58 * 5.304989477e-315;
                    this->unkA0 = sp8;
                    sp10 = sp58.unk8 * 2.0f;
                    sp68 = sp8;
                    sp70 = (f64) sp10;
                    M2C_FIELD(this, f32 *, 0xA8) = (f64) sp10;
                }
            }
        } else {
            temp_f6_1970 = this->unk7C;
            temp_f5_1972 = M2C_FIELD(this, f32 *, 0x74);
            temp_f2_1973 = temp_f6_1970 - 0.5f;
            temp_f2_1980 = -((4.0f * (temp_f2_1973 * temp_f2_1973)) - 1.0f);
            var_f29_1904 = temp_f2_1980;
            M2C_FIELD(this, f32 *, 0x54) = (f32) ((150.0f * temp_f2_1980) + ((temp_f6_1970 * (M2C_FIELD(this, f32 *, 0x94) - temp_f5_1972)) + temp_f5_1972));
        }
        var_f1_1985 = this->unk7C;
        if (var_f1_1985 < 0.2f) {

        } else {
            var_f1_1985 = 0.2f;
        }
        if (var_f1_1985 > 0.0f) {

        } else {
            var_f1_1985 = 0.0f;
        }
        this->unkE0 = 5.0f * var_f1_1985;
        temp_r4_2004 = this->unk124;
        temp_f2_2007 = this->unk100;
        temp_f1_2008 = gUpdateTimeDelta * temp_r4_2004->unk84;
        this->unk7C += temp_f2_2007 * temp_f1_2008;
        if ((s32) M2C_FIELD(GetDescriptor(M2C_BITWISE(f32, temp_r4_2004), temp_f1_2008, temp_f2_2007), s32 *, 0xC0) != 0) {
            if (this->unk138 > var_f29_1904) {
                this->unk13C = 1;
            }
            if (((u8) this->unk13C != 0) && (var_f29_1904 > this->unk138)) {
                temp_f1_2046 = (f32) KDSound_GetSoundEventVol(M2C_FIELD(GetDescriptor(), s32 *, 0xC0));
                this->unk140 = (s32) (this->unk134 * temp_f1_2046);
                KDSound_Play3d(M2C_FIELD(GetDescriptor(temp_f1_2046), s32 *, 0xC0), ((u8 *) this->unk8) + 0x30, 0U, this->unk140, 0.0f, 0U);
                this->unk13C = 0;
                if (this->unk134 > M2C_FIELD(GetDescriptor(), f32 *, 0xC4)) {
                    this->unk134 -= M2C_FIELD(GetDescriptor(), f32 *, 0xC4);
                }
            }
            this->unk138 = var_f29_1904;
        }
block_32:
        if (this->unkF8 < 0.0f) {
            if ((u8) this->unk120 != 0) {
                this->unkC0 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
                if ((void *) this->unkC0 != NULL) {
                    this->unkD8 = M2C_FIELD(*gb, f32 (**)(void **), 0x6C)(gb);
                    SetState(7);
                }
            } else {
                SetState(6);
            }
        }
        if ((u8) M2C_FIELD(this->unk124, u8 *, 0x67) != 0) {
            CalcShadowPos();
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::SlidingState() {
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f31_2215;
    f64 temp_f0_2222;

    if (MKCollision_SphereCollide(*((MKVector3 *) &this->unk50), 20.0f, NULL, 1, (MKCollisionMode) 7, 0) == 0) {
        if (FindGround() == 0) {
            this->unkC0 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
            if ((void *) this->unkC0 != NULL) {
                this->unkD8 = M2C_FIELD(*gb, f32 (**)(void **), 0x6C)(gb);
                SetState(7);
            }
        }
    } else {
        temp_f31_2215 = gUpdateTimeDelta;
        sp18.operator*(this->unk108);
        temp_f0_2222 = sp18 * (f64) temp_f31_2215;
        sp8 = temp_f0_2222;
        sp28 = temp_f0_2222;
        sp10 = sp18.unk8 * temp_f31_2215;
        sp30 = (f64) sp10;
        this->unk50 += temp_f0_2222;
        M2C_FIELD(this, f32 *, 0x58) = (f32) (M2C_FIELD(this, f32 *, 0x58) + (f32) sp30);
        this->unk108 += 980.0f * this->unk10C * gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKCollisionResult' to
u8 Collectable::FindGround() {
    MKCollisionResult sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f4_2344;
    f32 var_f4_2412;
    f64 temp_f0_2307;
    f64 temp_f1_2350;
    f64 temp_f1_2356;
    f64 temp_f1_2360;
    f64 temp_f1_2415;
    f64 temp_f1_2421;
    f64 temp_f1_2425;
    s32 temp_r3_2379;
    s32 temp_r3_2444;
    s32 var_r0_2389;
    s32 var_r0_2454;

    Tools_TestFloor(*((MKVector3 *) &this->unk50), &sp90, 4000.0f, (MKCollisionMode) 7);
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        this->unk90 = M2C_BITWISE(f64, sp90);
        this->unk98 = (f64) sp90.unk8;
        sp38 = 0.0f;
        this->unk110 = (f64) sp90.unk10;
        this->unk118 = (f64) sp90.unk18;
        sp30 = 0.0f;
        sp34 = 20.0f;
        sp68 = (f64) sp38;
        sp60 = (f64) sp30;
        this->unk10C = 1.0f - (((f32) M2C_FIELD(this, f64 *, 0x118) * MKVector3::up.unk8) + (((f32) M2C_FIELD(this, f64 *, 0x110) * MKVector3::up.unk0) + (M2C_FIELD(this, f32 *, 0x114) * MKVector3::up.unk4)));
        temp_f0_2307 = this->unk50 - this->unk90;
        sp40 = temp_f0_2307;
        sp70 = temp_f0_2307;
        sp48 = M2C_FIELD(this, f32 *, 0x58) - (f32) M2C_FIELD(this, f64 *, 0x98);
        sp78 = (f64) sp48;
        sp20 = sp70 - sp60;
        sp10 = -MKVector3::up.unk0;
        sp80 = sp20;
        sp28 = (f32) sp78 - (f32) sp68;
        sp14 = -MKVector3::up.unk4;
        sp88 = (f64) sp28;
        sp18 = -MKVector3::up.unk8;
        this->unk70 = (f64) sp10;
        var_f4_2344 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + ((*(f32 *) ((u8 *) &sp80 + 0x4)) * (*(f32 *) ((u8 *) &sp80 + 0x4))));
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        M2C_FIELD(this, f64 *, 0x78) = (f64) sp18;
        if (var_f4_2344 > 0.0f) {
            temp_f1_2350 = __frsqrte(var_f4_2344);
            temp_f1_2356 = 0.5 * temp_f1_2350 * -(((f64) var_f4_2344 * (temp_f1_2350 * temp_f1_2350)) - 3.0);
            temp_f1_2360 = 0.5 * temp_f1_2356 * -(((f64) var_f4_2344 * (temp_f1_2356 * temp_f1_2356)) - 3.0);
            var_f4_2344 = (f32) ((f64) var_f4_2344 * (0.5 * temp_f1_2360 * -(((f64) var_f4_2344 * (temp_f1_2360 * temp_f1_2360)) - 3.0)));
        } else if (var_f4_2344 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2344 = __float_nan;
        } else {
            spC = var_f4_2344;
            temp_r3_2379 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_2379) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_2389 = 1;
                } else {
                    var_r0_2389 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_2389 = 5;
                } else {
                    var_r0_2389 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_2389 = 4;
                break;
            }
            if (var_r0_2389 == 1) {
                var_f4_2344 = __float_nan;
            }
        }
        var_f4_2412 = var_f4_2344 / 980.0f;
        if (var_f4_2412 > 0.0f) {
            temp_f1_2415 = __frsqrte(var_f4_2412);
            temp_f1_2421 = 0.5 * temp_f1_2415 * -(((f64) var_f4_2412 * (temp_f1_2415 * temp_f1_2415)) - 3.0);
            temp_f1_2425 = 0.5 * temp_f1_2421 * -(((f64) var_f4_2412 * (temp_f1_2421 * temp_f1_2421)) - 3.0);
            var_f4_2412 = (f32) ((f64) var_f4_2412 * (0.5 * temp_f1_2425 * -(((f64) var_f4_2412 * (temp_f1_2425 * temp_f1_2425)) - 3.0)));
        } else if (var_f4_2412 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2412 = __float_nan;
        } else {
            sp8 = var_f4_2412;
            temp_r3_2444 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_2444) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2454 = 1;
                } else {
                    var_r0_2454 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2454 = 5;
                } else {
                    var_r0_2454 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_2454 = 4;
                break;
            }
            if (var_r0_2454 == 1) {
                var_f4_2412 = __float_nan;
            }
        }
        this->unk7C = var_f4_2412;
        this->unk108 = 980.0f * gUpdateTimeDelta;
        SetState(4, 980.0f);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void Collectable::FallingState() {
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f10_2595;
    f32 temp_f11_2597;
    f32 temp_f12_2593;
    f32 temp_f13_2591;
    f32 temp_f1_2559;
    f32 temp_f1_2639;
    f32 temp_f31_2512;
    f32 temp_f4_2549;
    f32 temp_f5_2592;
    f32 temp_f6_2555;
    f32 temp_f6_2613;
    f32 temp_f7_2610;
    f32 temp_f8_2614;
    f32 temp_f9_2551;
    f32 temp_f9_2590;
    f64 temp_f0_2519;

    if (this->unk7C > 0.0f) {
        temp_f31_2512 = gUpdateTimeDelta;
        sp78.operator*(this->unk108);
        temp_f0_2519 = sp78 * (f64) temp_f31_2512;
        sp38 = temp_f0_2519;
        sp88 = temp_f0_2519;
        sp40 = sp78.unk8 * temp_f31_2512;
        sp90 = (f64) sp40;
        this->unk50 += temp_f0_2519;
        M2C_FIELD(this, f32 *, 0x58) = (f32) (M2C_FIELD(this, f32 *, 0x58) + (f32) sp90);
        this->unk7C -= gUpdateTimeDelta;
        this->unk108 += 980.0f * gUpdateTimeDelta;
        return;
    }
    temp_f4_2549 = M2C_FIELD(this, f32 *, 0x114);
    temp_f9_2551 = M2C_FIELD(this, f32 *, 0x110);
    temp_f6_2555 = M2C_FIELD(this, f32 *, 0x118);
    temp_f1_2559 = (temp_f6_2555 * MKVector3::up.unk8) + ((temp_f9_2551 * MKVector3::up.unk0) + (temp_f4_2549 * MKVector3::up.unk4));
    if (((temp_f1_2559 < 0.9f) && (temp_f1_2559 > 0.0f)) || ((temp_f1_2559 > -0.1f) && (temp_f1_2559 < 0.0f))) {
        sp28 = (MKVector3::up.unk4 * temp_f6_2555) - (MKVector3::up.unk8 * temp_f4_2549);
        sp2C = (MKVector3::up.unk8 * temp_f9_2551) - (MKVector3::up.unk0 * temp_f6_2555);
        sp30 = (MKVector3::up.unk0 * temp_f4_2549) - (MKVector3::up.unk4 * temp_f9_2551);
        this->unk70 = (f64) sp28;
        M2C_FIELD(this, f64 *, 0x78) = (f64) sp30;
        temp_f9_2590 = (f32) M2C_FIELD(this, f64 *, 0x78);
        temp_f13_2591 = M2C_FIELD(this, f32 *, 0x110);
        temp_f5_2592 = M2C_FIELD(this, f32 *, 0x118);
        temp_f12_2593 = M2C_FIELD(this, f32 *, 0x74);
        temp_f10_2595 = (f32) M2C_FIELD(this, f64 *, 0x70);
        temp_f11_2597 = M2C_FIELD(this, f32 *, 0x114);
        sp70 = (f64) sp30;
        sp1C = (temp_f5_2592 * temp_f10_2595) - (temp_f13_2591 * temp_f9_2590);
        sp18 = (temp_f11_2597 * temp_f9_2590) - (temp_f5_2592 * temp_f12_2593);
        sp20 = (temp_f13_2591 * temp_f12_2593) - (temp_f11_2597 * temp_f10_2595);
        this->unk70 = (f64) sp18;
        M2C_FIELD(this, f64 *, 0x78) = (f64) sp20;
        temp_f7_2610 = M2C_FIELD(this, f32 *, 0x74);
        sp68 = (f64) sp28;
        temp_f6_2613 = (f32) M2C_FIELD(this, f64 *, 0x70);
        temp_f8_2614 = (f32) M2C_FIELD(this, f64 *, 0x78);
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        if (((temp_f8_2614 * MKVector3::up.unk8) + ((temp_f6_2613 * MKVector3::up.unk0) + (temp_f7_2610 * MKVector3::up.unk4))) > 0.0f) {
            sp8 = -temp_f6_2613;
            spC = -temp_f7_2610;
            sp10 = -temp_f8_2614;
            this->unk70 = (f64) sp8;
            sp48 = (f64) sp8;
            sp50 = (f64) sp10;
            M2C_FIELD(this, f64 *, 0x78) = (f64) sp10;
        }
        temp_f1_2639 = 980.0f * this->unk10C;
        this->unk108 = temp_f1_2639 * gUpdateTimeDelta;
        SetState(5, temp_f1_2639, 980.0f);
        return;
    }
    SetState(6);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::SpawnDynamic(const MKVector3 &arg0) {
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f31_2694;

    SetState(2);
    this->unk50 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk58 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk134 = 1.0f;
    this->unk138 = 0.0f;
    this->unk13C = 0;
    temp_f31_2694 = MKRand_Float((int *) &gViewSeed, 100.0f, 280.0f);
    KDRand_UnitVector();
    sp28.operator*(temp_f31_2694);
    sp8 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp28);
    this->unk90 = sp8;
    sp10 = arg0.unk8 + sp28.unk8;
    sp38 = sp8;
    this->unk98 = (f64) sp10;
    sp40 = (f64) sp10;
    M2C_FIELD(this, f32 *, 0x94) = (f32) arg0.unk4;
    SpawnStatic(*((MKVector3 *) &this->unk50), *((MKVector3 *) &this->unk90));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void Collectable::SpawnStatic(const MKVector3 &arg0, const MKVector3 &arg1) {
    MKCollisionResult sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_2777;
    f32 temp_f0_2906;
    f32 temp_f1_2913;
    f32 var_f3_2895;
    f32 var_f4_2828;
    f64 temp_f1_2834;
    f64 temp_f1_2840;
    f64 temp_f1_2844;
    f64 temp_f2_2911;
    s32 temp_cr0_eq_2799;
    s32 temp_r3_2863;
    s32 var_r0_2873;
    u32 var_r3_2792;

    SetState(2);
    this->unk134 = 1.0f;
    this->unk138 = 0.0f;
    this->unk13C = 0;
    this->unk50 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk58 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk90 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk98 = M2C_FIELD(&arg1, f64 *, 8);
    M2C_FIELD(this, f32 *, 0x5C) = 1.0f;
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &this->unk50));
    sp70 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f0_2777 = 20.0f + (*(f32 *) ((u8 *) &sp70 + 0x4));
    sp60 = M2C_FIELD(&arg1, f64 *, 0);
    sp78 = M2C_FIELD(&arg0, f64 *, 8);
    sp68 = M2C_FIELD(&arg1, f64 *, 8);
    (*(f32 *) ((u8 *) &sp70 + 0x4)) = temp_f0_2777;
    (*(f32 *) ((u8 *) &sp60 + 0x4)) = temp_f0_2777;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp70), *((MKVector3 *) &sp60), &sp80, (MKCollisionMode) 7, 0x200) != 0) {
        if ((sp80.unk50 != 0) && (sp80.unk48 != NULL) && (var_r3_2792 = M2C_FIELD(sp80.unk48, u32 *, 8), ((var_r3_2792 == 0U) == 0))) {

        } else {
            var_r3_2792 = 0U;
        }
        temp_cr0_eq_2799 = var_r3_2792 == 0U;
        if ((temp_cr0_eq_2799 != 0) || ((temp_cr0_eq_2799 == 0) && (var_r3_2792 != (void *) this->unkC8))) {
            sp20 = sp60 - sp70;
            sp50 = sp20;
            sp28 = (f32) sp68 - (f32) sp78;
            sp58 = (f64) sp28;
            sp40 = sp20;
            sp48 = (f64) sp28;
            var_f4_2828 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp48 + 0xc)) * (*(f32 *) ((u8 *) &sp48 + 0xc))));
            if (var_f4_2828 > 0.000001f) {
                if (var_f4_2828 > 0.0f) {
                    temp_f1_2834 = __frsqrte(var_f4_2828);
                    temp_f1_2840 = 0.5 * temp_f1_2834 * -(((f64) var_f4_2828 * (temp_f1_2834 * temp_f1_2834)) - 3.0);
                    temp_f1_2844 = 0.5 * temp_f1_2840 * -(((f64) var_f4_2828 * (temp_f1_2840 * temp_f1_2840)) - 3.0);
                    var_f4_2828 = (f32) ((f64) var_f4_2828 * (0.5 * temp_f1_2844 * -(((f64) var_f4_2828 * (temp_f1_2844 * temp_f1_2844)) - 3.0)));
                } else if (var_f4_2828 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2828 = __float_nan;
                } else {
                    sp8 = var_f4_2828;
                    temp_r3_2863 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_2863) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2873 = 1;
                        } else {
                            var_r0_2873 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2873 = 5;
                        } else {
                            var_r0_2873 = 3;
                        }
                        break;
                    default:
                        var_r0_2873 = 4;
                        break;
                    }
                    if (var_r0_2873 == 1) {
                        var_f4_2828 = __float_nan;
                    }
                }
                var_f3_2895 = 1.0f / var_f4_2828;
            } else {
                var_f3_2895 = 0.0f;
            }
            temp_f0_2906 = (f32) sp58 * var_f3_2895;
            sp50 = (f32) sp50 * var_f3_2895;
            (*(f32 *) ((u8 *) &sp48 + 0xc)) *= var_f3_2895;
            sp58 = temp_f0_2906;
            temp_f2_2911 = (f64) sp50 * 5.49408334e-315;
            sp50 = temp_f2_2911;
            temp_f1_2913 = temp_f0_2906 * 50.0f;
            sp58 = temp_f1_2913;
            sp10 = M2C_BITWISE(f64, sp80) - temp_f2_2911;
            sp30 = sp10;
            sp18 = sp80.unk8 - temp_f1_2913;
            sp60 = sp10;
            sp38 = (f64) sp18;
            sp68 = (f64) sp18;
            if (MKCollision_SphereCollide(*((MKVector3 *) &sp60), 10.0f, NULL, 0, (MKCollisionMode) 7, 0x200) != 0) {
                sp60 = sp70;
                sp68 = sp78;
            }
            this->unk90 = sp60;
            this->unk98 = sp68;
        }
    }
    sp70 = sp60;
    sp78 = sp68;
    (*(f32 *) ((u8 *) &sp70 + 0x4)) += 100.0f;
    (*(f32 *) ((u8 *) &sp60 + 0x4)) -= 1000.0f;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp70), *((MKVector3 *) &sp60), &sp80, (MKCollisionMode) 7, 0x200) != 0) {
        if (((KDWaterVolume *) &this->unk90)->IsWithin(*NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */)) == 0) {
            this->unk120 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
            M2C_FIELD(this, f32 *, 0x94) = (f32) (50.0f + sp80.unk4);
        }
        if ((u8) this->unk120 == 0) {
            spC = 0.0f;
            M2C_FIELD(this, f32 *, 0x94) = (f32) (M2C_FIELD(this, f32 *, 0x94) - 50.0f);
            if (((KDWaterVolume *) &this->unk90)->IsWithin(*((MKVector3 *) &spC), NULL, M2C_ERROR(/* Read from unset register $r6 */)) != 0) {
                this->unk120 = 1;
            }
            M2C_FIELD(this, f32 *, 0x94) = (f32) (M2C_FIELD(this, f32 *, 0x94) + 50.0f);
        }
    } else {
        this->unk120 = 1;
    }
    this->unk70 = this->unk50;
    M2C_FIELD(this, f64 *, 0x78) = (f64) this->unk58;
    this->unk7C = 0.0f;
    this->unk100 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKVector3 *' to
void Collectable::Spawn(const MKVector3 *arg0, const MKVector3 *arg1, bool arg2) {
    u8 sp140;
    s32 sp13C;
    void *sp138;
    s32 sp134;
    f32 sp130;
    s32 sp12C;
    s8 sp12B;
    s8 sp12A;
    s16 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    MKVector3 spB0;
    M2C_UNK spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    Collectable *spC;
    s32 sp8;
    MKProp *var_r4_3260;
    MKVector3 *var_r28_3046;
    f32 temp_f4_3222;
    f64 temp_f0_3237;
    f64 temp_f5_3216;
    void *temp_r3_3164;

    this->unk134 = 1.0f;
    var_r28_3046 = arg0;
    this->unk138 = 0.0f;
    this->unk13C = 0;
    if (((u8) this->unk144 >> 6U) & 1) {
        if ((s32) this->unkD4 >= 8) {
            return;
        }
        if (var_r28_3046 == NULL) {
            var_r28_3046 = (MKVector3 *) &this->unk50;
        }
        Enable();
        this->unkE0 = 0.0f;
        if (arg2 != 0) {
            this->unk50 = M2C_FIELD(var_r28_3046, f64 *, 0);
            this->unk58 = M2C_FIELD(var_r28_3046, f64 *, 8);
            this->unk90 = this->unk50;
            this->unk98 = this->unk58;
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &this->unk50));
            SetState(6);
        } else if (arg1 == NULL) {
            SpawnDynamic(*var_r28_3046);
        } else {
            SpawnStatic(*var_r28_3046, *arg1);
        }
        this->unk10 |= 0x80;
        if (((KDWaterVolume *) &this->unk90)->IsWithin(*NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */)) != 0) {
            this->unk10 |= 0x200;
        } else {
            this->unk10 &= 0xFFFFFDFF;
        }
        this->unk10 &= 0xFFFFFFF7;
        this->unkFC = this->unk124->unk80;
        if ((s32) this->unk124->unk9C & 0x4000) {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(spC0, spB0);
            spD0.operator*(3.1415927f);
            sp10 = spD0 * 5.304989477e-315;
            this->unkA0 = sp10;
            sp18 = spD0.unk8 * 2.0f;
            spE0 = sp10;
            spE8 = (f64) sp18;
            M2C_FIELD(this, f64 *, 0xA8) = (f64) sp18;
        }
        temp_r3_3164 = this->unkC8;
        if (temp_r3_3164 != NULL) {
            spC = NULL;
            sp8 = 0x5C;
            spC = this;
            M2C_FIELD(M2C_FIELD(temp_r3_3164, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        if ((MKProp *) this->unkC4 == NULL) {
            sp30 = 0.0f;
            sp34 = -500.0f;
            sp38 = 0.0f;
            spF0 = 0.0f;
            spF4 = 0.0f;
            spF8 = 0.0f;
            sp100 = 0.0f;
            sp104 = 0.0f;
            sp108 = 0.0f;
            sp110 = 0.0f;
            sp114 = 0.0f;
            sp118 = 0.0f;
            sp11C = 1.0f;
            sp120 = 0.0f;
            sp124 = 0.0f;
            sp128 = 0;
            sp12A = 0;
            sp12B = 0;
            sp12C = 0;
            sp130 = 3.4028235e38f;
            sp134 = 0;
            sp138 = NULL;
            sp13C = -1;
            sp140 = 0;
            sp60 = (f64) sp30;
            sp68 = (f64) sp38;
            temp_f5_3216 = this->unk50;
            sp20 = temp_f5_3216 + sp60;
            sp58 = 0.0f;
            temp_f4_3222 = (f32) M2C_FIELD(this, f64 *, 0x58);
            sp50 = 0.0f;
            sp54 = 500.0f;
            sp28 = temp_f4_3222 + (f32) sp68;
            sp80 = (f64) sp50;
            sp70 = sp20;
            sp78 = (f64) sp28;
            sp88 = (f64) sp58;
            temp_f0_3237 = temp_f5_3216 + sp80;
            sp40 = temp_f0_3237;
            sp90 = temp_f0_3237;
            sp48 = temp_f4_3222 + (f32) sp88;
            sp98 = (f64) sp48;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp90), *((MKVector3 *) &sp70), (MKCollisionResult *) &spF0, (MKCollisionMode) 7, 0) != 0) {
                if ((sp140 != 0) && (sp138 != NULL) && (var_r4_3260 = M2C_FIELD(sp138, MKProp **, 8), ((var_r4_3260 == NULL) == 0))) {

                } else {
                    var_r4_3260 = NULL;
                }
                if ((var_r4_3260 != NULL) && (M2C_FIELD(var_r4_3260->unk0, s32 *, 0xC) & 0x4000)) {
                    PlatformAttach(var_r4_3260);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void Collectable::Message(MKMessage *arg0) {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    u8 sp84;
    Collectable *sp80;
    Collectable *sp7C;
    s32 sp78;
    HeroInterface sp68;
    f64 sp60;
    f64 sp58;
    HeroInterface sp48;
    f32 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKHeap *temp_r3_3425;
    MKProp *temp_r3_3402;
    f32 temp_f3_3442;
    f32 temp_f3_3456;
    f32 temp_f3_3473;
    f32 temp_f4_3499;
    f64 temp_f0_3421;
    f64 temp_f1_3345;
    f64 temp_f1_3409;
    f64 temp_f1_3632;
    f64 temp_f2_3501;
    f64 temp_f3_3500;
    s32 temp_r0_3294;
    s32 temp_r0_3386;
    s32 temp_r0_3467;
    s32 temp_r0_3544;
    s32 temp_r0_3588;
    s32 temp_r0_3699;
    s32 temp_r3_3621;
    u8 *temp_r5_3759;
    u8 var_r0_3448;
    void *temp_r3_3400;
    void *temp_r3_3407;
    void *temp_r3_3498;
    void *temp_r3_3543;
    void *temp_r3_3692;
    void *temp_r3_3722;
    void *temp_r6_3765;
    void *temp_r7_3764;

    temp_r0_3294 = arg0->unk0;
    switch (temp_r0_3294) {                         /* switch 1; irregular */
    case 0xB8:                                      /* switch 1 */
        sp68.GetPos();
        temp_f1_3345 = M2C_BITWISE(f64, sp68);
        this->unk50 = temp_f1_3345;
        this->unk58 = sp70;
        M2C_FIELD(this, f32 *, 0x54) = (f32) (M2C_FIELD(this, f32 *, 0x54) + M2C_FIELD(*gb, f32 (**)(void **, f64), 0x6C)(gb, temp_f1_3345));
        SetState(6);
        Update();
    default:                                        /* switch 1 */
block_81:
        MKProp::Message(arg0);
        return;
    case 0x9:                                       /* switch 1 */
        if (M2C_FIELD(*gMK, u8 (**)(void **, Collectable *, s32), 0x9C)(gMK, this, *MKResource::sWorkingChunkID) != 0) {
            if (!(this->unk10 & 0x40000)) {
                return;
            }
            temp_r0_3386 = this->unkD4;
            if ((temp_r0_3386 >= 2) && (temp_r0_3386 < 8)) {
                if ((temp_r0_3386 == 2) && (this->unk7C < 0.6f)) {
                    return;
                }
                temp_r3_3400 = checked_cast<CollectRequestMsg *, MKMessage>(arg0);
                temp_r3_3402 = M2C_FIELD(temp_r3_3400, MKProp **, 0xC);
                if (temp_r3_3402 != NULL) {
                    this->unkC0 = checked_cast<MKProp *, MKProp>(temp_r3_3402);
                    temp_r3_3407 = M2C_FIELD(temp_r3_3400, void **, 0x10);
                    temp_f1_3409 = M2C_FIELD(temp_r3_3407, f64 *, 0);
                    sp98 = temp_f1_3409;
                    this->unkD8 = M2C_FIELD(temp_r3_3400, f32 *, 0x14);
                    spA0 = M2C_FIELD(temp_r3_3407, f64 *, 8);
                    (*(f32 *) ((u8 *) &sp98 + 0x4)) += M2C_FIELD(temp_r3_3400, f32 *, 0x14);
                    temp_f0_3421 = temp_f1_3409 - this->unk50;
                    sp38 = temp_f0_3421;
                    temp_r3_3425 = this->unk124;
                    sp88 = temp_f0_3421;
                    sp40 = (f32) spA0 - M2C_FIELD(this, f32 *, 0x58);
                    sp90 = (f64) sp40;
                    if ((u8) M2C_FIELD(temp_r3_3425, u8 *, 0x68) != 0) {
                        if (((u8) this->unk144 >> 7U) & 1) {
                            temp_f3_3442 = M2C_FIELD(temp_r3_3400, f32 *, 0x20);
                            var_r0_3448 = (((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp88 + 0x4))))) < (temp_f3_3442 * temp_f3_3442);
                        } else {
                            temp_f3_3456 = M2C_FIELD(temp_r3_3400, f32 *, 0x24);
                            var_r0_3448 = (((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp88 + 0x4))))) < (temp_f3_3456 * temp_f3_3456);
                        }
                        if (var_r0_3448 != 0) {
                            temp_r0_3467 = this->unkD4;
                            if ((temp_r0_3467 != 0) && (temp_r0_3467 < 7) && ((temp_f3_3473 = temp_r3_3425->unkA4, ((temp_f3_3473 == 0.0f) != 0)) || ((((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp88 + 0x4))))) <= temp_f3_3473))) {
                                SetState(7);
                                this->unkF0 = M2C_FIELD(temp_r3_3400, f32 *, 0x1C);
                            }
                        }
                    }
                    temp_r3_3498 = M2C_FIELD(this->unkC0, void **, 8);
                    temp_f4_3499 = M2C_FIELD(temp_r3_3400, f32 *, 0x18);
                    temp_f3_3500 = M2C_FIELD(temp_r3_3498, f64 *, 0x30);
                    temp_f2_3501 = M2C_FIELD(temp_r3_3498, f64 *, 0x38);
                    sp98 = temp_f3_3500;
                    sp58 = temp_f3_3500;
                    sp60 = temp_f2_3501;
                    (*(f32 *) ((u8 *) &sp98 + 0x4)) += M2C_FIELD(temp_r3_3400, f32 *, 0x14);
                    spA0 = temp_f2_3501;
                    sp8 = sp98 - this->unk50;
                    sp18 = sp8;
                    sp10 = (f32) spA0 - M2C_FIELD(this, f32 *, 0x58);
                    sp20 = (f64) sp10;
                    sp28 = sp8;
                    sp30 = (f64) sp10;
                    if ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * (*(f32 *) ((u8 *) &sp18 + 0x4))))) < (temp_f4_3499 * temp_f4_3499)) {
                        SetState(8);
                    }
                    goto block_81;
                }
            }
        }
        break;
    case 0xB:                                       /* switch 1 */
        temp_r3_3543 = checked_cast<CollectableControlMsg *, MKMessage>(arg0);
        temp_r0_3544 = M2C_FIELD(temp_r3_3543, s32 *, 0x18);
        switch (temp_r0_3544) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            this->unk50 = M2C_FIELD(temp_r3_3543, f64 *, 8);
            this->unk58 = M2C_FIELD(temp_r3_3543, f64 *, 0x10);
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &this->unk50));
            break;
        case 1:                                     /* switch 2 */
            PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
            this->unkE0 = 0.0f;
            this->unkE4 = 1.0f;
            break;
        case 2:                                     /* switch 2 */
            this->unkE0 = 1.0f;
            this->unkE4 = -1.0f;
            break;
        case 3:                                     /* switch 2 */
            SetState(0xA);
            break;
        }
        temp_r0_3588 = this->unkD4;
        if ((temp_r0_3588 < 9) || (temp_r0_3588 == 0xA)) {
            this->unkD4 = 9;
        }
        goto block_81;
    case 0xB9:                                      /* switch 1 */
        if (M2C_FIELD(*gMK, u8 (**)(void **, Collectable *, s32), 0x9C)(gMK, this, *MKResource::sWorkingChunkID) != 0) {
            if (!(this->unk10 & 0x40000)) {
                return;
            }
            if (M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb) != 0U) {
                temp_r3_3621 = this->unkD4;
                if (temp_r3_3621 != 1) {
                    if ((u32) (temp_r3_3621 - 8) > 2U) {
                        sp48.GetPos();
                        temp_f1_3632 = M2C_BITWISE(f64, sp48);
                        this->unk50 = temp_f1_3632;
                        this->unk58 = sp50;
                        M2C_FIELD(this, f32 *, 0x54) = (f32) (M2C_FIELD(this, f32 *, 0x54) + M2C_FIELD(*gb, f32 (**)(void **, f64), 0x6C)(gb, temp_f1_3632));
                        SetState(6);
                        Update();
                    }
                } else {
                    this->unkD4 = 8;
                    CollectingStateInit();
                    this->unkC0 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
                    this->unkD8 = M2C_FIELD(*gb, f32 (**)(void **, void ***), 0x6C)(gb, &gb);
                    sp7C = NULL;
                    sp78 = 0xA;
                    sp7C = this;
                    sp80 = this;
                    sp84 = M2C_FIELD(this->unk124, u8 *, 0x64);
                    temp_r3_3692 = this->unkC0;
                    M2C_FIELD(M2C_FIELD(temp_r3_3692, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_3692, &sp78);
                }
                goto block_81;
            }
        }
        break;
    case 0x14:                                      /* switch 1 */
        temp_r0_3699 = this->unkD4;
        if (temp_r0_3699 == 7) {
            SetState(6);
            this->unkC0 = NULL;
        } else if (temp_r0_3699 == 8) {
            this->unk121 = 1;
        }
        goto block_81;
    case 0x26:                                      /* switch 1 */
        PlatformDetach();
        goto block_81;
    case 0x22:                                      /* switch 1 */
        temp_r3_3722 = M2C_FIELD(checked_cast<PlatformMoveMsg *, MKMessage>(arg0), void **, 8);
        this->unk50 = M2C_FIELD(temp_r3_3722, f64 *, 0);
        this->unk58 = M2C_FIELD(temp_r3_3722, f64 *, 8);
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &this->unk50));
        goto block_81;
    case 0xBE:                                      /* switch 1 */
        PropFlagsMessage((unsigned int *) &this->unk10, arg0);
        SetState(3);
        goto block_81;
    case 0xBF:                                      /* switch 1 */
        PropFlagsMessage((unsigned int *) &this->unk10, arg0);
        SetState(1);
        goto block_81;
    case 0x5B:                                      /* switch 1 */
        M2C_FIELD(checked_cast<GetPosMsg *, MKMessage>(arg0), f64 **, 8) = &this->unk50;
        return;
    case 0x5E:                                      /* switch 1 */
        temp_r5_3759 = &this->unk128;
        M2C_FIELD(this->unk130, void **, 4) = (void *) this->unk12C;
        temp_r7_3764 = this->unk130;
        temp_r6_3765 = this->unk12C;
        M2C_FIELD(temp_r6_3765, void **, 8) = temp_r7_3764;
        this->unk130 = temp_r5_3759;
        this->unk12C = temp_r5_3759;
        this->unkC8 = NULL;
        M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK, u8 *, void *, void *), 0x5C)(0, temp_r5_3759, temp_r6_3765, temp_r7_3764);
        goto block_81;
    case 0x71:                                      /* switch 1 */
        ((FindNearestCollectableMsg *) (checked_cast<P25FindNearestCollectableMsg))->Test(9MKMessage>__FP9MKMessage(arg0), this);
        goto block_81;
    }
}
#endif

void Collectable::DrawLocator() {
    f64 sp10;
    f64 sp8;

    sp8 = this->unk50;
    sp10 = this->unk58;
    (*(f32 *) ((u8 *) &sp8 + 0x4)) += 10000.0f;
    MKShape_DrawLine(*((MKVector3 *) &this->unk50), *((MKVector3 *) &sp8), this->unk124->unk88, MKVector4::one, Matrix::identity);
}

#if 0 // DRAFT: function call 'Normalise(MKVector3)' does not match
void Collectable::DrawShadow() {
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    MKVector3 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    MKVector3 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    MKVector3 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f10_3857;
    f32 temp_f10_3893;
    f32 temp_f6_3856;
    f32 temp_f6_3887;
    f32 temp_f8_3855;
    f32 temp_f8_3891;
    f64 temp_f0_3937;
    f64 temp_f0_3949;
    f64 temp_f0_3985;
    f64 temp_f0_4033;
    f64 temp_f0_4068;

    spF8 = 0.0f;
    spFC = 0.0f;
    sp100 = 1.0f;
    sp2A8 = (f64) spF8;
    sp2B0 = (f64) sp100;
    spE8 = 0.2f;
    spEC = 0.2f;
    spF0 = 0.2f;
    spF4 = 1.0f;
    sp288 = (f64) spE8;
    sp290 = (f64) spF0;
    temp_f8_3855 = this->unk84;
    temp_f6_3856 = this->unk88;
    temp_f10_3857 = this->unk80;
    sp278 = this->unk50;
    spE0 = (temp_f10_3857 * (*(f32 *) ((u8 *) &sp2A8 + 0x4))) - (temp_f8_3855 * (f32) sp2A8);
    spD8 = (temp_f8_3855 * (f32) sp2B0) - (temp_f6_3856 * (*(f32 *) ((u8 *) &sp2A8 + 0x4)));
    spDC = (temp_f6_3856 * (f32) sp2A8) - (temp_f10_3857 * (f32) sp2B0);
    sp280 = this->unk58;
    (*(f32 *) ((u8 *) &sp278 + 0x4)) = this->unkDC;
    sp258 = (f64) spD8;
    sp260 = (f64) spE0;
    Normalise(sp268);
    sp298 = M2C_BITWISE(f64, sp268);
    sp2A0 = (f64) sp268.unk8;
    temp_f6_3887 = this->unk88;
    temp_f8_3891 = this->unk84;
    temp_f10_3893 = this->unk80;
    sp70 = -(f32) sp2A0;
    sp6C = -(*(f32 *) ((u8 *) &sp298 + 0x4));
    spD0 = (temp_f10_3893 * (*(f32 *) ((u8 *) &sp298 + 0x4))) - (temp_f8_3891 * (f32) sp298);
    sp68 = -(f32) sp298;
    spC8 = (temp_f8_3891 * (f32) sp2A0) - (temp_f6_3887 * (*(f32 *) ((u8 *) &sp298 + 0x4)));
    spCC = (temp_f6_3887 * (f32) sp298) - (temp_f10_3893 * (f32) sp2A0);
    sp250 = (f64) spD0;
    sp248 = (f64) spC8;
    sp2A8 = (f64) spC8;
    sp2B0 = (f64) spD0;
    sp1E8 = (f64) sp68;
    sp1F0 = (f64) sp70;
    sp1F8.operator*(50.0f);
    sp78 = -(f32) sp2A8;
    sp7C = -(*(f32 *) ((u8 *) &sp2A8 + 0x4));
    sp80 = -(f32) sp2B0;
    sp208 = (f64) sp78;
    sp210 = (f64) sp80;
    sp218.operator*(50.0f);
    temp_f0_3937 = sp218 + M2C_BITWISE(f64, sp1F8);
    sp58 = temp_f0_3937;
    sp228 = temp_f0_3937;
    sp60 = sp218.unk8 + sp1F8.unk8;
    sp230 = (f64) sp60;
    temp_f0_3949 = sp228 + sp278;
    spB8 = temp_f0_3949;
    sp238 = temp_f0_3949;
    sp2B8 = temp_f0_3949;
    spC0 = (f32) sp230 + (f32) sp280;
    sp240 = (f64) spC0;
    sp2C0 = (f64) spC0;
    sp198.operator*(50.0f);
    sp48 = -(f32) sp2A8;
    sp4C = -(*(f32 *) ((u8 *) &sp2A8 + 0x4));
    sp50 = -(f32) sp2B0;
    sp1A8 = (f64) sp48;
    sp1B0 = (f64) sp50;
    sp1B8.operator*(50.0f);
    temp_f0_3985 = sp1B8 + M2C_BITWISE(f64, sp198);
    sp38 = temp_f0_3985;
    sp1C8 = temp_f0_3985;
    sp40 = sp1B8.unk8 + sp198.unk8;
    sp1D0 = (f64) sp40;
    spA8 = sp1C8 + sp278;
    spB0 = (f32) sp1D0 + (f32) sp280;
    sp28 = -(f32) sp298;
    sp2C = -(*(f32 *) ((u8 *) &sp298 + 0x4));
    sp30 = -(f32) sp2A0;
    sp1D8 = spA8;
    sp1E0 = (f64) spB0;
    sp2C8 = spA8;
    sp2D0 = (f64) spB0;
    sp148 = (f64) sp28;
    sp150 = (f64) sp30;
    sp158.operator*(50.0f);
    sp168.operator*(50.0f);
    temp_f0_4033 = sp168 + M2C_BITWISE(f64, sp158);
    sp18 = temp_f0_4033;
    sp178 = temp_f0_4033;
    sp20 = sp168.unk8 + sp158.unk8;
    sp180 = (f64) sp20;
    sp98 = sp178 + sp278;
    sp188 = sp98;
    spA0 = (f32) sp180 + (f32) sp280;
    sp2D8 = sp98;
    sp190 = (f64) spA0;
    sp2E0 = (f64) spA0;
    sp108.operator*(50.0f);
    sp118.operator*(50.0f);
    temp_f0_4068 = sp118 + M2C_BITWISE(f64, sp108);
    sp8 = temp_f0_4068;
    sp128 = temp_f0_4068;
    sp10 = sp118.unk8 + sp108.unk8;
    sp130 = (f64) sp10;
    sp88 = sp128 + sp278;
    sp2E8 = sp88;
    sp90 = (f32) sp130 + (f32) sp280;
    sp138 = sp88;
    sp2F0 = (f64) sp90;
    sp140 = (f64) sp90;
    MKMaterial_SetMaterial(M2C_FIELD(GetDescriptor(sp88, sp118.unk8), MKMaterial **, 0xB8));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &sp288));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp2B8));
    MKSetColorV(*((MKVector4 *) &sp288));
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp2C8));
    MKSetColorV(*((MKVector4 *) &sp288));
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp2D8));
    MKSetColorV(*((MKVector4 *) &sp288));
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp2E8));
    MKEnd();
    MKEndPrimitive();
}
#endif

void Collectable::Draw() {
    Matrix sp40;
    M2C_UNK sp3C;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKHeap *temp_r3_4160;
    MKHeap *temp_r3_4221;
    MKModel *temp_r3_4171;

    if (this->unk10 & 0x40000) {
        temp_r3_4160 = this->unk124;
        if ((s32) temp_r3_4160->unk9C & 8) {
            this->unk4 = (MKModel *) temp_r3_4160->unk2C;
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) this->unk8));
        }
        temp_r3_4171 = this->unk124->unk9C;
        if ((s32) temp_r3_4171 & 4) {
            RotateCameraFacing();
        } else if ((s32) temp_r3_4171 & 0x4003) {
            MKModel_SetWorldMatrix(this->unk4, Matrix::identity);
            MKModel_SetRotation(this->unk4, this->unk60);
            M2C_STRUCT_COPY((s32) &sp3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
            sp40.Scale3x3(&sp40, this->unkE0);
            MKModel_SetWorldMatrix(this->unk4, sp40);
            sp30 = this->unk50;
            sp38 = this->unk58;
            (*(f32 *) ((u8 *) &sp30 + 0x4)) += this->unkF4;
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp30));
        }
        temp_r3_4221 = this->unk124;
        if ((u8) M2C_FIELD(temp_r3_4221, u8 *, 0x66) != 0) {
            sp10 = temp_r3_4221->unkA8;
            sp14 = temp_r3_4221->unkAC;
            sp18 = temp_r3_4221->unkB0;
            sp1C = this->unk20;
            sp20 = (f64) sp10;
            sp28 = (f64) sp18;
            MKModel_SetColor(this->unk4, *((MKVector4 *) &sp20));
        } else {
            MKModel_SetAlpha(this->unk4, this->unk20);
        }
        MKModel_Draw(this->unk4, NULL);
        if (((s32) this->unk124->unk9C & 0x10) || ((u8) *CollectableDescriptor::bDrawLocator != 0)) {
            DrawLocator();
        }
        if ((s32) this->unk124->unk9C & 8) {
            this->unk4 = NULL;
        }
        if (((u8) M2C_FIELD(this->unk124, u8 *, 0x67) != 0) && (this->unk10 & 0x40000)) {
            DrawShadow();
        }
    }
}

void Collectable::CalcShadowPos() {
    MKCollisionResult sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_4305;
    f32 temp_f2_4301;
    f32 temp_f4_4303;

    temp_f2_4301 = M2C_FIELD(this, f32 *, 0x54);
    temp_f4_4303 = M2C_FIELD(this, f32 *, 0x50);
    temp_f0_4305 = M2C_FIELD(this, f32 *, 0x58);
    sp18 = temp_f4_4303;
    sp1C = temp_f2_4301;
    sp20 = temp_f0_4305;
    sp10 = temp_f0_4305;
    sp8 = temp_f4_4303;
    spC = temp_f2_4301 - 400.0f;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp38), *((MKVector3 *) &sp28), &sp48, (MKCollisionMode) 1, 0x200) != 0) {
        M2C_FIELD(this, f64 *, 0x80) = (f64) sp48.unk10;
        M2C_FIELD(this, f64 *, 0x88) = (f64) sp48.unk18;
        this->unkDC = 1.0f + sp48.unk4;
    }
}

void Collectable::UpdateShadow() {

}

void *Collectable::Update() {
    MKHeap *temp_r3_4435;
    MKModel *temp_r3_4446;
    s32 temp_r4_4353;

    temp_r4_4353 = this->unkD4;
    if (((temp_r4_4353 != 0) || ((s32) this->unk124->unk9C & 0x1000)) && (this->unk10 & 0x20000)) {
        if ((u32) temp_r4_4353 <= 0xAU) {
            switch (temp_r4_4353) {
            case 6:
                IdleState();
                break;
            case 7:
                MagnetisedState();
                break;
            case 8:
                CollectingState();
                break;
            case 2:
                SpawningState();
                break;
            case 3:
                JustSpawnedState();
                break;
            case 4:
                FallingState();
                break;
            case 5:
                SlidingState();
                break;
            case 9:
                PresentingState();
                break;
            case 10:
                CollectedState();
                break;
            }
        }
        temp_r3_4435 = this->unk124;
        if ((s32) temp_r3_4435->unk9C & 2) {
            this->unkEC = NormaliseAngle(-((temp_r3_4435->unk6C * gUpdateTimeDelta) - this->unkEC));
        }
        temp_r3_4446 = this->unk4;
        if (temp_r3_4446 != NULL) {
            MKModel_SetPosition(temp_r3_4446, *((MKVector3 *) &this->unk50));
        }
    }
}

#if 0 // DRAFT: type mismatch
f32 Collectable::Resolve() {
    M2C_UNK sp8;
    MKSceneManager *temp_r3_4468;

    MKProp::Resolve();
    temp_r3_4468 = this->unk104;
    if ((temp_r3_4468 > 0) && !(this->unk18 & 0x80000000)) {
        this->unkC4 = temp_r3_4468->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        PlatformAttach(this->unkC4);
    } else {
        this->unkC4 = NULL;
    }
    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, Collectable *), 0x44)(&sp8, this);
    if (((KDWaterVolume *) &sp8)->IsWithin(*NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */)) != 0) {
        this->unk10 |= 0x200;
    }
}
#endif

void Collectable::Reset() {
    MKProp::Reset();
    ClearData();
}

void Collectable::ClearData() {
    this->unkE0 = 1.0f;
    this->unkE8 = 1.0f;
    this->unk120 = 0;
    this->unk144 &= ~0x80;
}

#if 0 // DRAFT: function call 'MKModel_Create(MKHeap *, int, int, int)' does not match
s32 Collectable::LoadDone() {
    this->unk50 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40);
    this->unk58 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x48);
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x50);
    M2C_FIELD(this, f64 *, 0x68) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
    this->unkE0 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x60);
    MKProp::LoadDone();
    if (!((s32) this->unk124->unk9C & 8)) {
        this->unk4 = MKModel_Create(MKModel_GetName(M2C_FIELD(this->unk0, MKModel **, 0x2C)), NULL, 2, NULL);
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &this->unk50));
        this->unk8 = MKModel_GetWorldMatrix(this->unk4);
    } else {
        this->unk4 = NULL;
        this->unk8 = &Matrix::identity;
    }
    ClearData();
    if ((u8) M2C_FIELD(this->unk124, u8 *, 0x67) != 0) {
        CalcShadowPos();
    }
}
#endif

s32 Collectable::LoadLine(MKIniLine *arg0) {
    s32 var_r31_4614;

    var_r31_4614 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0) || (arg0->LoadInt("type", (int *) &this->unkD0, 0) != 0) || (arg0->LoadInt("platformID", (int *) &this->unk104, 0) != 0)) {
        var_r31_4614 = 1;
    }
    return var_r31_4614;
}

void Collectable::Deinit() {
    MKHeap *temp_r3_4660;
    MKHeap *temp_r3_4665;
    u8 *temp_r4_4682;
    void *temp_r31_4664;

    temp_r3_4660 = this->unk124;
    if ((s32) temp_r3_4660->unk9C & 8) {
        temp_r31_4664 = this->unk8;
        temp_r3_4665 = temp_r3_4660->Current();
        if (temp_r3_4665 != NULL) {
            ((MKHeap *) (temp_r3_4665->Current()))->Free(temp_r31_4664, NULL, 0);
        } else {
            free((Matrix *) temp_r31_4664);
        }
        this->unk8 = NULL;
    }
    temp_r4_4682 = &this->unk128;
    M2C_FIELD(this->unk130, void **, 4) = (void *) this->unk12C;
    M2C_FIELD(this->unk12C, void **, 8) = (void *) this->unk130;
    this->unk130 = temp_r4_4682;
    this->unk12C = temp_r4_4682;
    this->unkC8 = NULL;
    PlatformDetach();
    MKProp::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'CollectableDescriptor *' to
void Collectable::Init() {
    MKProp::Init();
    this->unk124 = checked_cast<CollectableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk60.unk0 = 0.0f;
    this->unk60.unk4 = 0.0f;
    this->unk60.unk8 = 0.0f;
    M2C_FIELD(this, f32 *, 0x50) = 0.0f;
    M2C_FIELD(this, f32 *, 0x54) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58) = 0.0f;
    M2C_FIELD(this, f32 *, 0x70) = 0.0f;
    M2C_FIELD(this, f32 *, 0x74) = 0.0f;
    M2C_FIELD(this, f32 *, 0x78) = 0.0f;
    this->unk80 = 0.0f;
    this->unk84 = 1.0f;
    this->unk88 = 0.0f;
    M2C_FIELD(this, f32 *, 0x90) = 0.0f;
    M2C_FIELD(this, f32 *, 0x94) = 0.0f;
    M2C_FIELD(this, f32 *, 0x98) = 0.0f;
    this->unkD8 = 0.0f;
    this->unkDC = 1.0f;
    this->unkE0 = 1.0f;
    this->unkE8 = 1.0f;
    this->unkF0 = 1.0f;
    this->unkE4 = 0.0f;
    this->unkEC = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unkC0 = NULL;
    this->unkC8 = NULL;
    this->unkCC = 0;
    M2C_FIELD(this, Collectable **, 0x128) = this;
    this->unk144 &= ~0x80;
    this->unk144 &= ~0x40;
    this->unk144 &= ~0x20;
    this->unkD4 = 6;
    this->unkD0 = -1;
    this->unkF4 = 0.0f;
    this->unk120 = 0;
    this->unk104 = NULL;
    this->unk100 = 1.0f;
    this->unk134 = 1.0f;
    this->unk138 = 0.0f;
    this->unk13C = 0;
    PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
    M2C_FIELD(this, Collectable **, 0xB0) = this;
    this->unk108 = 980.0f * gUpdateTimeDelta;
    this->unk10C = 1.0f;
}
#endif

void CollectableDescriptor::Deinit() {
    MKMaterial_Destroy(this->unkB8);
    this->unkB8 = NULL;
    MKPropDescriptor::Deinit();
}

void CollectableDescriptor::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_4818;

    MKPropDescriptor::LoadDone();
    temp_f1_4818 = this->unkA4;
    if (temp_f1_4818 > 0.0f) {
        this->unkA4 = temp_f1_4818 * temp_f1_4818;
    }
    sp8 = this->unkA8;
    spC = this->unkAC;
    sp10 = this->unkB0;
    sp14 = 0.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    MKModel_SetColor(this->unk2C, *((MKVector4 *) &sp18));
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 CollectableDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_4856;

    var_r31_4856 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("respawnTime", &this->unk7C, 0) != 0) || (arg0->LoadBool("bChangeModelColor", (u8 *) &this->unk66, 0) != 0) || (arg0->LoadBool("bMagnetic", (u8 *) &this->unk68, 0) != 0) || (arg0->LoadBool("bShadow", this + 0x67, 0) != 0) || (arg0->LoadFloat("timeout", &this->unk80, 0) != 0) || (arg0->LoadFloat("spawnSpeedMultiplier", &this->unk84, 0) != 0) || (arg0->LoadFloat("magRange", &this->unkA4, 0) != 0) || (arg0->LoadFloat("sndBounceVolDropOff", &this->unkC4, 0) != 0) || (arg0->LoadVector4("color", (MKVector4 *) &this->unkA8, 0) != 0) || (KDSound_LoadLine(arg0, "sndCollect", (int *) &this->unkBC) != 0) || (KDSound_LoadLine(arg0, "sndBounce", (int *) &this->unkC0) != 0)) {
        var_r31_4856 = 1;
    }
    return var_r31_4856;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void CollectableDescriptor::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    MKPropDescriptor::Init();
    this->unkC = 2;
    this->unkBC = GS_GemCollect;
    this->unkC0 = GS_GemBounce;
    this->unkC4 = 0.35f;
    this->unk64 = 0;
    this->unk88 = 0.0f;
    this->unk8C = 1.0f;
    this->unk90 = 0.0f;
    this->unk94 = 1.0f;
    this->unk6C = 0.785398f;
    this->unk70 = 0.785398f;
    this->unk74 = 6.0f;
    this->unk78 = 2.5f;
    this->unk7C = 0.0f;
    this->unk80 = 0.0f;
    this->unk84 = 1.0f;
    M2C_FIELD(this, s8 *, 0x67) = 1;
    M2C_FIELD(this, s8 *, 0x68) = 0;
    this->unk98 = 0;
    this->unk9C = 0;
    M2C_FIELD(this, s8 *, 0x66) = 1;
    this->unkA0 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    this->unkA4 = 0.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0xA8) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0xB0) = (f64) sp10;
    this->unkB8 = MKMaterial_Create("FX_DropShadow");
}
#endif
