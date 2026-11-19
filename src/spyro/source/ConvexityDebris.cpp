#include "spyro/source/ConvexityDebris.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern s32 GS_ConvexFlyingPlatform2LP;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match 'KDSound_Stop(int *)'
void ConvexityDebris::Deinit() {
    MKHeap *temp_r0_63;
    MKHeap *temp_r0_82;
    MKHeap *temp_r3_54;
    MKHeap *var_r31_46;
    MKHeap *var_r31_59;
    MKHeap *var_r3_60;
    MKHeap *var_r4_58;
    u32 temp_r0_68;

    var_r31_46 = this->unk4C;
loop_2:
    if (var_r31_46 != NULL) {
        temp_r3_54 = var_r31_46->unk0;
        if (temp_r3_54 != NULL) {
            KDSound_Stop((s32 *) temp_r3_54);
            var_r31_46 += 4;
            goto loop_2;
        }
    }
    var_r4_58 = this->unk4C;
    var_r31_59 = var_r4_58;
    var_r3_60 = var_r4_58;
loop_7:
    temp_r0_68 = M2C_FIELD(var_r3_60, u32 *, -4);
    var_r3_60 -= 4;
    if (temp_r0_68 != 0U) {
        temp_r0_63 = var_r3_60->unk0;
        if (temp_r0_63 < var_r31_59) {
            var_r31_59 = temp_r0_63;
        }
        goto loop_7;
    }
    if (var_r3_60 != &gEmptyPtrListDL) {
loop_13:
        temp_r0_82 = var_r4_58->unk0;
        if (temp_r0_82 != NULL) {
            if (temp_r0_82 < var_r31_59) {
                var_r31_59 = temp_r0_82;
            }
            var_r4_58 += 4;
            goto loop_13;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_59, NULL, 0);
        } else {
            free(var_r31_59);
        }
    }
    this->unk4C = NULL;
    this->unk50.Deinit();
    MKProp::Deinit();
}
#endif

void ConvexityDebris::Message(MKMessage *arg0) {
    MKHeap *temp_r31_160;
    MKHeap *temp_r3_129;
    MKHeap *var_r30_146;
    MKHeap *var_r31_120;
    s32 temp_r0_133;

    var_r31_120 = this->unk4C;
loop_2:
    if (var_r31_120 != NULL) {
        temp_r3_129 = var_r31_120->unk0;
        if (temp_r3_129 != NULL) {
            ((KDSoundPlayer *) temp_r3_129)->Message(arg0);
            var_r31_120 += 4;
            goto loop_2;
        }
    }
    temp_r0_133 = arg0->unk0;
    if (temp_r0_133 != 0xB5) {
        if (temp_r0_133 < 0xB5) {

        }
    } else if ((s32) this->unk64 == 0) {
        this->unk64 = 1;
        this->unk68 = 0.0f;
        var_r30_146 = this->unk4C;
loop_10:
        if (var_r30_146 != NULL) {
            temp_r31_160 = var_r30_146->unk0;
            if (temp_r31_160 != NULL) {
                var_r30_146 += 4;
                temp_r31_160->unk6C = this->unk78 * MKRand_Float((int *) &gViewSeed, 0.5f, 1.5f);
                goto loop_10;
            }
        }
    }
    MKProp::Message(arg0);
}

#if 0 // DRAFT: illegal explicit conversion from 'KDSpline' to 'double'
void ConvexityDebris::Draw() {
    Matrix sp50;
    f64 sp40;
    KDSpline sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    MKHeap *temp_r31_248;
    MKHeap *var_r30_190;
    f64 temp_f0_218;

    if ((s32) this->unk64 != 0) {
        var_r30_190 = this->unk4C;
loop_3:
        if (var_r30_190 != NULL) {
            temp_r31_248 = var_r30_190->unk0;
            if (temp_r31_248 != NULL) {
                sp50.SetIdentity();
                sp50.SetRotationPYR(*((MKVector3 *) &temp_r31_248->unk38));
                sp50.Scale3x3(&sp50, temp_r31_248->unk6C);
                sp10 = this->unk68 + M2C_BITWISE(f32, temp_r31_248->unk68);
                sp28.GetMeasure(Clamp<float>(0.0f, sp10, 1.0f), (Matrix *) &this->unk50);
                temp_f0_218 = M2C_BITWISE(f64, sp28) + M2C_FIELD(temp_r31_248, f64 *, 0x48);
                sp18 = temp_f0_218;
                sp50.unk3C = 1.0f;
                sp28.unk10 = temp_f0_218;
                sp20 = sp28.unk8 + M2C_BITWISE(f32, temp_r31_248->unk50);
                sp40 = (f64) sp20;
                sp50.unk30 = M2C_BITWISE(f32, sp28.unk10);
                sp50.unk34 = sp3C;
                sp50.unk38 = (f32) sp40;
                MKModel_SetWorldMatrix((MKModel *) temp_r31_248->unk70, sp50);
                MKModel_SetColor((MKModel *) temp_r31_248->unk70, this->unk80);
                MKModel_Draw((MKModel *) temp_r31_248->unk70, NULL);
                var_r30_190 += 4;
                goto loop_3;
            }
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void *ConvexityDebris::Update() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    MKHeap *temp_r31_405;
    MKHeap *temp_r3_311;
    MKHeap *var_r30_293;
    MKHeap *var_r30_344;
    f32 temp_f1_393;
    f32 temp_f1_396;
    f32 var_f0_328;
    f32 var_f2_386;
    f64 temp_f0_351;
    s32 temp_r0_315;

    var_r30_293 = this->unk4C;
loop_2:
    if (var_r30_293 != NULL) {
        temp_r3_311 = var_r30_293->unk0;
        if (temp_r3_311 != NULL) {
            sp8 = 1;
            ((KDSoundFader *) temp_r3_311)->Update(GS_ConvexFlyingPlatform2LP, 1U, this->unk64 != 0, NULL, (MKVector3 *) &temp_r3_311->unk58, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            var_r30_293 += 4;
            goto loop_2;
        }
    }
    temp_r0_315 = this->unk64;
    if ((temp_r0_315 != 1) && (temp_r0_315 < 1)) {
        if (temp_r0_315 < 0) {
            goto block_9;
        }
    } else {
block_9:
        var_f0_328 = (this->unk6C * gUpdateTimeDelta) + this->unk68;
        if (var_f0_328 < 1.0f) {

        } else {
            var_f0_328 = 1.0f;
        }
        if (var_f0_328 > 0.0f) {

        } else {
            var_f0_328 = 0.0f;
        }
        this->unk68 = var_f0_328;
        var_r30_344 = this->unk4C;
loop_22:
        if (var_r30_344 != NULL) {
            temp_r31_405 = var_r30_344->unk0;
            if (temp_r31_405 != NULL) {
                temp_f0_351 = M2C_FIELD(temp_r31_405, f64 *, 0x28) * (f64) gUpdateTimeDelta;
                sp10 = temp_f0_351;
                sp20 = temp_f0_351;
                sp18 = M2C_FIELD(temp_r31_405, f32 *, 0x30) * gUpdateTimeDelta;
                sp28 = (f64) sp18;
                M2C_FIELD(temp_r31_405, f64 *, 0x38) = (f64) (M2C_FIELD(temp_r31_405, f64 *, 0x38) + temp_f0_351);
                temp_r31_405->unk40 = M2C_BITWISE(f32, temp_r31_405->unk40) + (f32) sp28;
                MKModel_GetPosition((MKModel *) temp_r31_405->unk70);
                M2C_FIELD(temp_r31_405, f64 *, 0x58) = (f64) *M2C_ERROR(/* Read from unset register $r3 */);
                M2C_FIELD(temp_r31_405, f64 *, 0x60) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f64 *, 8);
                if ((this->unk68 + M2C_BITWISE(f32, temp_r31_405->unk68)) >= 1.0f) {
                    var_f2_386 = 0.5f * (3.0f * gUpdateTimeDelta);
                    if (var_f2_386 < 1.0f) {

                    } else {
                        var_f2_386 = 1.0f;
                    }
                    temp_f1_393 = temp_r31_405->unk6C;
                    temp_f1_396 = (var_f2_386 * (0.01f - temp_f1_393)) + temp_f1_393;
                    temp_r31_405->unk6C = (var_f2_386 * (0.01f - temp_f1_396)) + temp_f1_396;
                }
                var_r30_344 += 4;
                goto loop_22;
            }
        }
        if (this->unk68 >= 1.0f) {
            this->unk64 = 0;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 ConvexityDebris::LoadDone() {
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    MKVector3 spC8;
    M2C_UNK spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    M2C_UNK sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    M2C_UNK sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKHeap *temp_r30_469;
    MKHeap *temp_r3_467;
    f32 temp_f28_463;
    f32 temp_f31_533;
    f32 var_f27_458;
    s32 temp_r31_456;

    MKProp::LoadDone();
    M2C_FIELD(this, f64 *, 0x80) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0x88) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78);
    temp_r31_456 = (long) (checked_cast<ConvexityDebrisDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0));
    var_f27_458 = 0.0f;
    this->unk6C /= this->unk50.unk8;
    temp_f28_463 = this->unk74 / this->unk50.unk8;
loop_4:
    if ((u32) M2C_FIELD(this->unk4C, u32 *, -4) != 0U) {
        temp_r3_467 = this->unk4C - 4;
        this->unk4C = temp_r3_467;
        temp_r30_469 = temp_r3_467->unk0;
        if (temp_r30_469 != NULL) {
            temp_r30_469->unk68 = var_f27_458;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(spD8, spC8);
            sp28 = spD8 * 5.370091495e-315;
            M2C_FIELD(temp_r30_469, f64 *, 0x38) = sp28;
            sp30 = spD8.unk8 * 6.2831855f;
            spE8 = sp28;
            spF0 = (f64) sp30;
            M2C_FIELD(temp_r30_469, f64 *, 0x40) = (f64) sp30;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp98, sp88);
            sp18 = sp98 * 5.328646264e-315;
            M2C_FIELD(temp_r30_469, f64 *, 0x28) = sp18;
            sp20 = sp98.unk8 * 3.1415927f;
            spA8 = sp18;
            temp_r30_469->unk30 = (f64) sp20;
            spB0 = (f64) sp20;
            temp_f31_533 = this->unk70;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp58, sp48);
            sp8 = sp58 * (f64) temp_f31_533;
            M2C_FIELD(temp_r30_469, f64 *, 0x48) = sp8;
            sp10 = sp58.unk8 * temp_f31_533;
            sp68 = sp8;
            sp70 = (f64) sp10;
            M2C_FIELD(temp_r30_469, f64 *, 0x50) = (f64) sp10;
            temp_r30_469->unk70 = *(temp_r31_456 + ((MKRand_Int((int *) &gViewSeed, 0, 2) * 4) + 0x60));
            temp_r30_469->unk6C = this->unk78 * MKRand_Float((int *) &gViewSeed, 0.5f, 1.5f);
            temp_r30_469->unk58 = 0.0f;
            temp_r30_469->unk5C = 0.0f;
            temp_r30_469->unk60 = 0.0f;
            ((KDSoundFader *) temp_r30_469)->Init(0.25f, 0.25f);
        }
        var_f27_458 += temp_f28_463;
        goto loop_4;
    }
}
#endif

s32 ConvexityDebris::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r31_672;

    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("fMoveSpeed", &this->unk6C, 0) != 0) || (arg0->LoadFloat("fRadius", &this->unk70, 0) != 0) || (arg0->LoadFloat("fDebrisSpread", &this->unk74, 0) != 0) || (arg0->LoadFloat("fDebrisScale", &this->unk78, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("Waypoints") != 0) {
        this->unk50.Init(arg0->GetNmbrOfSubLines(), 0U);
        var_r31_672 = arg0->unkC->GetSubLine(arg0);
loop_9:
        if (var_r31_672 != NULL) {
            var_r31_672->AsVector3(0, &sp8);
            this->unk50.AddNode(sp8);
            var_r31_672 = var_r31_672->unkC->GetNextLine(var_r31_672);
            goto loop_9;
        }
    }
    return 0;
}

void ConvexityDebris::Init() {
    MKHeap *temp_r3_730;
    MKHeap *temp_r3_736;
    MKHeap *var_r3_715;
    MKHeap *var_r5_724;
    s32 var_ctr_728;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_715 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x2F0, NULL, 0));
    } else {
        var_r3_715 = malloc(0x2F0);
    }
    this->unk4C = var_r3_715;
    var_r5_724 = this->unk4C;
    this->unk4C = var_r5_724 + 0x2D0;
    M2C_FIELD(var_r5_724, s32 *, 0x2D0) = 0;
    var_ctr_728 = 6;
    do {
        temp_r3_730 = this->unk4C;
        this->unk4C = (MKHeap *) &temp_r3_730->unk4;
        temp_r3_730->unk4 = (s32) var_r5_724;
        var_r5_724 += 0x78;
        var_ctr_728 -= 1;
    } while (var_ctr_728 != 0);
    temp_r3_736 = this->unk4C;
    this->unk4C = (MKHeap *) &temp_r3_736->unk4;
    temp_r3_736->unk4 = 0;
    this->unk68 = 0.0f;
    this->unk64 = 0;
    this->unk6C = 1000.0f;
    this->unk70 = 500.0f;
    this->unk74 = 1000.0f;
    this->unk78 = 1.0f;
}

#if 0 // DRAFT: function call 'MKModel_Destroy(ConvexityDebrisDescriptor)' does not match 'MKModel_Destroy(MKModel *)'
void ConvexityDebrisDescriptor::Deinit() {
    s32 var_r30_766;
    s32 var_r31_767;

    var_r30_766 = 0;
    var_r31_767 = 0;
    do {
        MKModel_Destroy(*(this + (var_r31_767 + 0x60)));
        var_r30_766 += 1;
        var_r31_767 += 4;
    } while (var_r30_766 < 2);
    MKPropDescriptor::Deinit();
}
#endif

void ConvexityDebrisDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = (long) (MKModel_Create("P6001_TiltPlatform_A", NULL, 2, NULL));
    this->unk64 = (long) (MKModel_Create("P6001_TiltPlatform_C", NULL, 2, NULL));
}
