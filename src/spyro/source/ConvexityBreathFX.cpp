#include "spyro/source/ConvexityBreathFX.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(Matrix **);                            /* extern */
Matrix **malloc(M2C_UNK);                           /* extern */
extern s32 GS_SpyroConvexFireball;
extern s32 GS_SpyroConvexFireballLP;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: identifier 'gb' redeclared was declared as: 'GameGlobals' now declared as: 'void **'
extern void **gb;
#endif

void ConvexityBreathFX::DrawRings() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix **var_r30_74;
    Matrix *temp_r31_111;
    f32 var_f0_87;

    var_r30_74 = this->unk118;
loop_4:
    if (var_r30_74 != NULL) {
        temp_r31_111 = *var_r30_74;
        if (temp_r31_111 != NULL) {
            MKModel_SetWorldMatrix(this->unk110, *temp_r31_111);
            var_f0_87 = 2.0f * ((M2C_FIELD(temp_r31_111, f32 *, 0x40) / 0.75f) - 0.5f);
            if (var_f0_87 < 0.0f) {
                var_f0_87 = -var_f0_87;
            }
            sp8 = 1.0f;
            spC = 1.0f;
            sp10 = 1.0f;
            sp14 = 1.0f - var_f0_87;
            sp18 = (f64) sp8;
            sp20 = (f64) sp10;
            MKMaterial_SetColor(this->unk114, *((MKVector4 *) &sp18));
            MKModel_Draw(this->unk110, NULL);
            var_r30_74 += 4;
            goto loop_4;
        }
    }
}

void ConvexityBreathFX::UpdateRings() {
    Matrix sp8;
    Matrix **temp_r3_196;
    Matrix **var_r30_155;
    Matrix *temp_r31_208;
    Matrix *temp_r4_199;
    f32 temp_f1_185;
    f32 temp_f25_183;
    f32 var_f0_165;

    var_r30_155 = this->unk118;
loop_10:
    if (var_r30_155 != NULL) {
        temp_r31_208 = *var_r30_155;
        if (temp_r31_208 != NULL) {
            var_f0_165 = M2C_FIELD(temp_r31_208, f32 *, 0x40) - gUpdateTimeDelta;
            if (var_f0_165 < 0.75f) {

            } else {
                var_f0_165 = 0.75f;
            }
            if (var_f0_165 > 0.0f) {

            } else {
                var_f0_165 = 0.0f;
            }
            M2C_FIELD(temp_r31_208, f32 *, 0x40) = var_f0_165;
            temp_f25_183 = M2C_FIELD(temp_r31_208, f32 *, 0x40) / 0.75f;
            sp8.NormaliseScale();
            temp_f1_185 = 1.0f - temp_f25_183;
            temp_r31_208->Scale3x3(temp_r31_208, 1.0f + (temp_f1_185 * -((6.0f * temp_f1_185) - 20.0f)));
            if (M2C_FIELD(temp_r31_208, f32 *, 0x40) <= 0.0f) {
                temp_r3_196 = this->unk118;
                this->unk118 = temp_r3_196 + 4;
                temp_r4_199 = *temp_r3_196;
                *temp_r3_196 = *var_r30_155;
                *var_r30_155 = temp_r4_199;
            }
            var_r30_155 += 4;
            goto loop_10;
        }
    }
}

void ConvexityBreathFX::SpawnRing(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix **temp_r6_241;
    Matrix **temp_r6_246;
    Matrix *temp_r31_252;

    temp_r6_241 = this->unk118;
    if ((u32) M2C_FIELD(temp_r6_241, u32 *, -4) != 0U) {
        temp_r6_246 = temp_r6_241 - 4;
        this->unk118 = temp_r6_246;
        sp10 = 0.0f;
        temp_r31_252 = *temp_r6_246;
        sp8 = 0.0f;
        spC = 1.0f;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        KDMath_BuildMatrixFromFwd(temp_r31_252, arg1, (MKVector3 *) &sp18);
        temp_r31_252->Scale3x3(temp_r31_252, 12.5f);
        temp_r31_252->unk30 = arg0.unk0;
        temp_r31_252->unk34 = arg0.unk4;
        temp_r31_252->unk38 = arg0.unk8;
        temp_r31_252->unk3C = 1.0f;
        M2C_FIELD(temp_r31_252, f32 *, 0x40) = 0.75f;
    }
}

#if 0 // DRAFT: undefined identifier 'unk0'
s32 ConvexityBreathFX::Trigger(MKProp *arg0, const MKVector3 &arg1, const MKVector3 &arg2, const float &arg3) {
    f64 sp190;
    f64 sp188;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    f64 sp170;                                      /* compiler-managed */
    f64 sp168;                                      /* compiler-managed */
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    MKVector3 spC8;
    MKVector3 spB8;
    MKVector3 spA8;
    M2C_UNK sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    TargetManager ***var_r29_369;
    TargetManager **temp_r31_536;
    TargetManager **var_r30_356;
    f32 temp_f1_753;
    f32 temp_f31_704;
    f32 temp_f4_510;
    f32 temp_f5_511;
    f32 temp_f6_508;
    f32 var_f0_432;
    f32 var_f30_365;
    f32 var_f3_638;
    f32 var_f4_571;
    f32 var_f5_499;
    f64 temp_f0_414;
    f64 temp_f0_670;
    f64 temp_f0_725;
    f64 temp_f1_408;
    f64 temp_f1_577;
    f64 temp_f1_583;
    f64 temp_f1_587;
    f64 temp_f2_438;
    f64 temp_f2_444;
    f64 temp_f2_448;
    f64 temp_f2_668;
    s32 temp_r3_467;
    s32 temp_r3_606;
    s32 var_r0_477;
    s32 var_r0_616;
    s32 var_r28_698;
    void *temp_r3_407;

    if (this->unk120 > 0.0f) {
        return 0;
    }
    sp80 = 0.0f;
    this->unk120 = 1.0f;
    this->unkAC = 1;
    this->unkB0 = 0.5f;
    this->unkB8 = 0.0f;
    this->unkBC = 0.0f;
    this->unkC0 = 0.0f;
    sp78 = 0.0f;
    sp7C = 1.0f;
    sp190 = (f64) sp80;
    sp188 = (f64) sp78;
    this->unk1B0 = 0.25f;
    M2C_STRUCT_COPY((s32) &this->unk16C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp70 = 0.0f;
    sp68 = 0.0f;
    sp6C = 1.0f;
    sp130 = (f64) sp70;
    sp128 = (f64) sp68;
    KDMath_BuildMatrixFromUp(&this->unk170, arg2, *((MKVector3 *) &sp128));
    this->unk170.unk30 = arg1.unk0;
    var_r30_356 = NULL;
    this->unk170.unk34 = arg1.unk4;
    this->unk170.unk38 = arg1.unk8;
    this->unk170.unk3C = 1.0f;
    sp178 = M2C_FIELD(&arg2, f64 *, 0);
    var_f30_365 = 3.4028235e38f;
    sp180 = M2C_FIELD(&arg2, f64 *, 8);
    var_r29_369 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_32:
    if (var_r29_369 != NULL) {
        temp_r31_536 = *var_r29_369;
        if (temp_r31_536 != NULL) {
            if (((*temp_r31_536)->unk8.unk0(temp_r31_536) != NULL) && (M2C_FIELD(*temp_r31_536, u8 (**)(TargetManager **), 0x18)(temp_r31_536) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r31_536)->unk8.unk4)(temp_r31_536) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r31_536)->unk8.unk4)(temp_r31_536)))->IsActive() != 0))) {
                temp_r3_407 = M2C_FIELD((*temp_r31_536)->unk8.unk0(temp_r31_536), void **, 8);
                temp_f1_408 = M2C_FIELD(temp_r3_407, f64 *, 0x30);
                sp118 = temp_f1_408;
                sp120 = M2C_FIELD(temp_r3_407, f64 *, 0x38);
                temp_f0_414 = temp_f1_408 - (f64) M2C_FIELD(&arg1, f32 *, 0);
                sp58 = temp_f0_414;
                sp168 = temp_f0_414;
                sp60 = (f32) sp120 - arg1.unk8;
                sp170 = (f64) sp60;
                var_f0_432 = ((f32) sp170 * (f32) sp170) + (((f32) sp168 * (f32) sp168) + ((*(f32 *) ((u8 *) &sp158 + 0x14)) * (*(f32 *) ((u8 *) &sp158 + 0x14))));
                if (var_f0_432 > 0.000001f) {
                    if (var_f0_432 > 0.0f) {
                        temp_f2_438 = __frsqrte(var_f0_432);
                        temp_f2_444 = 0.5 * temp_f2_438 * -(((f64) var_f0_432 * (temp_f2_438 * temp_f2_438)) - 3.0);
                        temp_f2_448 = 0.5 * temp_f2_444 * -(((f64) var_f0_432 * (temp_f2_444 * temp_f2_444)) - 3.0);
                        var_f0_432 = (f32) ((f64) var_f0_432 * (0.5 * temp_f2_448 * -(((f64) var_f0_432 * (temp_f2_448 * temp_f2_448)) - 3.0)));
                    } else if (var_f0_432 < M2C_BITWISE(f32, 0.0)) {
                        var_f0_432 = __float_nan;
                    } else {
                        spC = var_f0_432;
                        temp_r3_467 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_467) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_477 = 1;
                            } else {
                                var_r0_477 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_477 = 5;
                            } else {
                                var_r0_477 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_477 = 4;
                            break;
                        }
                        if (var_r0_477 == 1) {
                            var_f0_432 = __float_nan;
                        }
                    }
                    var_f5_499 = 1.0f / var_f0_432;
                } else {
                    var_f5_499 = 0.0f;
                    var_f0_432 = 0.0f;
                }
                temp_f6_508 = (f32) sp168 * var_f5_499;
                temp_f4_510 = (*(f32 *) ((u8 *) &sp158 + 0x14)) * var_f5_499;
                temp_f5_511 = (f32) sp170 * var_f5_499;
                sp168 = temp_f6_508;
                (*(f32 *) ((u8 *) &sp158 + 0x14)) = temp_f4_510;
                sp170 = temp_f5_511;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                if ((var_f0_432 == 10000.0f) && (var_f0_432 < var_f30_365) && (((temp_f5_511 * arg2.unk8) + ((temp_f6_508 * arg2.unk0) + (temp_f4_510 * arg2.unk4))) > 0.9f)) {
                    var_f30_365 = var_f0_432;
                    var_r30_356 = temp_r31_536;
                }
            }
            var_r29_369 += 4;
            goto loop_32;
        }
    }
    if (var_r30_356 != NULL) {
        M2C_FIELD(*var_r30_356, M2C_UNK (**)(TargetManager **, MKVector3 *, f64 *), 0x2C)(var_r30_356, &arg1, &sp158);
        sp38 = sp158 - (f64) M2C_FIELD(&arg1, f32 *, 0);
        sp178 = sp38;
        sp40 = sp160 - arg1.unk8;
        sp180 = (f64) sp40;
        sp108 = sp38;
        sp110 = (f64) sp40;
        var_f4_571 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + ((*(f32 *) ((u8 *) &sp158 + 0x24)) * (*(f32 *) ((u8 *) &sp158 + 0x24))));
        if (var_f4_571 > 0.000001f) {
            if (var_f4_571 > 0.0f) {
                temp_f1_577 = __frsqrte(var_f4_571);
                temp_f1_583 = 0.5 * temp_f1_577 * -(((f64) var_f4_571 * (temp_f1_577 * temp_f1_577)) - 3.0);
                temp_f1_587 = 0.5 * temp_f1_583 * -(((f64) var_f4_571 * (temp_f1_583 * temp_f1_583)) - 3.0);
                var_f4_571 = (f32) ((f64) var_f4_571 * (0.5 * temp_f1_587 * -(((f64) var_f4_571 * (temp_f1_587 * temp_f1_587)) - 3.0)));
            } else if (var_f4_571 < M2C_BITWISE(f32, 0.0)) {
                var_f4_571 = __float_nan;
            } else {
                sp8 = var_f4_571;
                temp_r3_606 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_606) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_616 = 1;
                    } else {
                        var_r0_616 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_616 = 5;
                    } else {
                        var_r0_616 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_616 = 4;
                    break;
                }
                if (var_r0_616 == 1) {
                    var_f4_571 = __float_nan;
                }
            }
            var_f3_638 = 1.0f / var_f4_571;
        } else {
            var_f3_638 = 0.0f;
        }
        sp178 = (f32) sp178 * var_f3_638;
        (*(f32 *) ((u8 *) &sp158 + 0x24)) *= var_f3_638;
        sp180 = (f32) sp180 * var_f3_638;
    }
    KDMath_BuildMatrixFromFwd(&this->unkD0, *((MKVector3 *) &sp178), (MKVector3 *) &sp188);
    this->unkD0.unk30 = arg1.unk0;
    this->unkD0.unk34 = arg1.unk4;
    this->unkD0.unk38 = arg1.unk8;
    temp_f2_668 = (f64) M2C_FIELD(&arg1, f32 *, 0);
    this->unkD0.unk3C = 1.0f;
    temp_f0_670 = (f64) M2C_FIELD(&arg1, f32 *, 8);
    sp148 = temp_f2_668;
    sp150 = temp_f0_670;
    this->unk150 = temp_f2_668;
    this->unk158 = temp_f0_670;
    KDSound_Play3d(GS_SpyroConvexFireball, &arg1, 0U, -1, 0.0f, 0U);
    ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(1.0f, 1.0f, 0.15f, 0, 4.0f, 0U);
    var_r28_698 = 0;
    do {
        temp_f31_704 = MKRand_Float((int *) &gViewSeed, 50.0f, 2000.0f);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(spB8, spA8);
        spC8.operator*(0.5f);
        temp_f0_725 = (f64) sp178 + M2C_BITWISE(f64, spC8);
        sp18 = temp_f0_725;
        spD8 = temp_f0_725;
        sp20 = sp180 + spC8.unk8;
        spE0 = (f64) sp20;
        Normalise(spE8);
        sp28 = spE8 * (f64) temp_f31_704;
        spF8 = sp28;
        sp30 = spE8.unk8 * temp_f31_704;
        sp138 = sp28;
        sp100 = (f64) sp30;
        sp140 = (f64) sp30;
        temp_f1_753 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        sp48 = temp_f1_753;
        sp54 = 1.0f;
        sp4C = 0.25f * temp_f1_753;
        sp50 = 0.75f * temp_f1_753;
        sp88 = (f64) sp48;
        sp90 = (f64) sp50;
        sp10 = MKRand_Float((int *) &gViewSeed, 20.0f, 25.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp148), *((MKVector3 *) &sp138), sp10, *((MKVector4 *) &sp88), -200.0f);
        var_r28_698 += 1;
    } while (var_r28_698 < 0x3C);
    return 1;
}
#endif

#if 0 // DRAFT: type mismatch 'Matrix *' and 'Matrix **'
void ConvexityBreathFX::Deinit() {
    Matrix **var_r31_809;
    Matrix **var_r3_810;
    Matrix **var_r4_808;
    Matrix *temp_r0_813;
    Matrix *temp_r0_832;
    u32 temp_r0_818;

    MKModel_Destroy(this->unkA8);
    MKModel_Destroy(this->unk110);
    var_r4_808 = this->unk118;
    var_r31_809 = var_r4_808;
    var_r3_810 = var_r4_808;
loop_3:
    temp_r0_818 = M2C_FIELD(var_r3_810, u32 *, -4);
    var_r3_810 -= 4;
    if (temp_r0_818 != 0U) {
        temp_r0_813 = *var_r3_810;
        if (temp_r0_813 < var_r31_809) {
            var_r31_809 = (Matrix **) temp_r0_813;
        }
        goto loop_3;
    }
    if (var_r3_810 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_832 = *var_r4_808;
        if (temp_r0_832 != NULL) {
            if (temp_r0_832 < var_r31_809) {
                var_r31_809 = (Matrix **) temp_r0_832;
            }
            var_r4_808 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_809, NULL, 0);
        } else {
            free(var_r31_809);
        }
    }
    this->unk118 = NULL;
    KDSound_Stop((int *) &this->unk124);
    MKModel_Destroy(this->unk160);
    BaseBreathFX::Deinit();
}
#endif

void ConvexityBreathFX::Draw() {
    Matrix sp70;
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f5_931;
    f32 var_f1_912;
    void ***temp_r31_958;

    if ((s32) this->unkAC != 0) {
        M2C_STRUCT_COPY((s32) &sp30.unk3C + 4, (s32) &this->unkCC + 4, 0x40);
        sp70.Scale3x3(&sp70, *((MKVector3 *) &this->unkB8));
        MKModel_SetWorldMatrix(this->unkA8, sp70);
        MKModel_Draw(this->unkA8, NULL);
    }
    if (this->unk1B0 > 0.0f) {
        M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) &this->unk16C + 4, 0x40);
        var_f1_912 = this->unk1B0;
        if (var_f1_912 < 0.25f) {

        } else {
            var_f1_912 = 0.25f;
        }
        if (var_f1_912 > 0.0f) {

        } else {
            var_f1_912 = 0.0f;
        }
        temp_f5_931 = var_f1_912 / 0.25f;
        sp10 = 10.0f * temp_f5_931;
        sp14 = (8.0f * (1.0f - temp_f5_931)) + 2.0f;
        sp18 = 20.0f * temp_f5_931;
        sp20 = (f64) sp10;
        sp28 = (f64) sp18;
        sp30.Scale3x3(&sp30, *((MKVector3 *) &sp20));
        MKModel_SetWorldMatrix(this->unk160, sp30);
        MKModel_Draw(this->unk160, NULL);
    }
    temp_r31_958 = (void ***) (&gb + 0x24);
    ((GameGlobals::Capture *) temp_r31_958)->Get();
    DrawRings();
    ((GameGlobals::Capture *) temp_r31_958)->Release();
}

void ConvexityBreathFX::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) &this->unk124)->Message(arg0);
    KDProp::Message(arg0);
}

#if 0 // DRAFT: pointer/array required
void *ConvexityBreathFX::Update() {
    BreathHitMessage sp258;
    MKCollisionResult sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    MKVector3 sp110;
    f64 sp108;
    f64 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
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
    s32 sp8;
    MKProp *temp_r4_1188;
    Matrix *temp_r3_1372;
    f32 temp_f1_1340;
    f32 temp_f27_1357;
    f32 temp_f2_1169;
    f32 temp_f2_1252;
    f32 temp_f3_1075;
    f32 temp_f3_1134;
    f32 temp_f3_1251;
    f32 temp_f4_1250;
    f32 temp_f5_1248;
    f32 var_f0_1054;
    f32 var_f0_1320;
    f64 temp_f0_1086;
    f64 temp_f0_1096;
    f64 temp_f0_1108;
    f64 temp_f0_1145;
    f64 temp_f0_1155;
    f64 temp_f0_1262;
    f64 temp_f0_1273;
    f64 temp_f0_1370;
    s32 temp_r0_1038;
    void *var_r3_1214;

    this->unk120 = this->unk120 - gUpdateTimeDelta;
    this->unk1B0 -= gUpdateTimeDelta;
    sp8 = 1;
    ((KDSoundFader *) &this->unk124)->Update(GS_SpyroConvexFireballLP, 1U, this->unkAC == 1, NULL, (MKVector3 *) &this->unk150, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    UpdateRings();
    temp_r0_1038 = this->unkAC;
    switch (temp_r0_1038) {                         /* irregular */
    case 1:
        var_f0_1054 = this->unkB0 - gUpdateTimeDelta;
        if (var_f0_1054 < 0.5f) {

        } else {
            var_f0_1054 = 0.5f;
        }
        if (var_f0_1054 > 0.0f) {

        } else {
            var_f0_1054 = 0.0f;
        }
        this->unkB0 = var_f0_1054;
        temp_f3_1075 = this->unkC0;
        spF0 = -this->unkD0.unk20;
        spF4 = -this->unkD0.unk24;
        spF8 = -this->unkD0.unk28;
        sp1A0 = (f64) spF0;
        sp1A8 = (f64) spF8;
        temp_f0_1086 = sp1A0 * (f64) temp_f3_1075;
        spE0 = temp_f0_1086;
        sp1B0 = temp_f0_1086;
        spE8 = (f32) sp1A8 * temp_f3_1075;
        sp1B8 = (f64) spE8;
        temp_f0_1096 = temp_f0_1086 * 5.676053805e-315;
        spD0 = temp_f0_1096;
        sp1C0 = temp_f0_1096;
        spD8 = (f32) sp1B8 * 1000.0f;
        sp1C8 = (f64) spD8;
        temp_f0_1108 = M2C_FIELD(this, f64 *, 0x100) + temp_f0_1096;
        spC0 = temp_f0_1108;
        sp1F0 = temp_f0_1108;
        spC8 = this->unkD0.unk38 + (f32) sp1C8;
        sp1F8 = (f64) spC8;
        this->unkB8 = 10.0f;
        this->unkBC = 10.0f;
        this->unkC0 = 20.0f * (1.0f - (this->unkB0 / 0.5f));
        temp_f3_1134 = this->unkC0;
        spB0 = -this->unkD0.unk20;
        spB4 = -this->unkD0.unk24;
        spB8 = -this->unkD0.unk28;
        sp170 = (f64) spB0;
        sp178 = (f64) spB8;
        temp_f0_1145 = sp170 * (f64) temp_f3_1134;
        spA0 = temp_f0_1145;
        sp180 = temp_f0_1145;
        spA8 = (f32) sp178 * temp_f3_1134;
        sp188 = (f64) spA8;
        temp_f0_1155 = temp_f0_1145 * 5.676053805e-315;
        sp90 = temp_f0_1155;
        sp190 = temp_f0_1155;
        sp98 = (f32) sp188 * 1000.0f;
        sp198 = (f64) sp98;
        sp80 = M2C_FIELD(this, f64 *, 0x100) + temp_f0_1155;
        temp_f2_1169 = this->unkD0.unk38;
        sp1E0 = sp80;
        sp88 = temp_f2_1169 + (f32) sp198;
        sp1E8 = (f64) sp88;
        this->unk150 = sp80;
        this->unk158 = (f64) sp88;
        sp258.unk4 = 0;
        temp_r4_1188 = M2C_FIELD(*gb, MKProp *(**)(void **, f64, f32, f32, f64), 0xC)(gb, sp80, temp_f2_1169, temp_f3_1134, (f64) spC8);
        sp8 = -1;
        sp258.Init(temp_r4_1188, 0xA, 0, 3, 4, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp1F0), *((MKVector3 *) &sp1E0), 50.0f, &sp200, (MKCollisionMode) 7, 0x04000004) != 0) {
            if ((sp200.unk50 != 0) && (sp200.unk48 != NULL) && (var_r3_1214 = M2C_FIELD(sp200.unk48, void **, 8), ((var_r3_1214 == NULL) == 0))) {

            } else {
                var_r3_1214 = NULL;
            }
            if (var_r3_1214 != NULL) {
                sp258.unk30 = (MKCollisionInfo *) sp200.unk48;
                sp258.unk10 = sp1F0;
                sp258.unk18 = sp1F8;
                M2C_FIELD(M2C_FIELD(var_r3_1214, void **, 0x44), M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(&sp258, sp1F0);
            }
        }
        this->unk11C -= gUpdateTimeDelta;
        if (this->unk11C <= 0.0f) {
            this->unk11C = 0.05f;
            temp_f5_1248 = -this->unkD0.unk20;
            temp_f4_1250 = -this->unkD0.unk24;
            temp_f3_1251 = this->unkC0;
            temp_f2_1252 = -this->unkD0.unk28;
            sp70 = temp_f5_1248;
            sp74 = temp_f4_1250;
            sp78 = temp_f2_1252;
            sp140 = (f64) sp70;
            sp148 = (f64) sp78;
            temp_f0_1262 = sp140 * (f64) temp_f3_1251;
            sp60 = temp_f0_1262;
            sp150 = temp_f0_1262;
            sp68 = (f32) sp148 * temp_f3_1251;
            sp158 = (f64) sp68;
            temp_f0_1273 = temp_f0_1262 * 5.634608575e-315;
            sp50 = temp_f0_1273;
            sp160 = temp_f0_1273;
            sp58 = (f32) sp158 * 500.0f;
            sp168 = (f64) sp58;
            sp40 = M2C_FIELD(this, f64 *, 0x100) + temp_f0_1273;
            sp38 = temp_f2_1252;
            sp30 = temp_f5_1248;
            sp48 = this->unkD0.unk38 + (f32) sp168;
            sp34 = temp_f4_1250;
            sp1D0 = sp40;
            sp1D8 = (f64) sp48;
            sp130 = (f64) sp30;
            sp138 = (f64) sp38;
            SpawnRing(*((MKVector3 *) &sp1D0), *((MKVector3 *) &sp130));
        }
        if (this->unkB0 <= 0.0f) {
            this->unkAC = 2;
            this->unkB0 = 0.25f;
        }
    default:
block_33:
        temp_f27_1357 = gUpdateTimeDelta;
        sp10 = -this->unkD0.unk20;
        sp14 = -this->unkD0.unk24;
        sp18 = -this->unkD0.unk28;
        sp100 = (f64) sp10;
        sp108 = (f64) sp18;
        sp110.operator*(2000.0f);
        temp_f0_1370 = sp110 * (f64) temp_f27_1357;
        sp20 = temp_f0_1370;
        temp_r3_1372 = &this->unkD0;
        sp120 = temp_f0_1370;
        sp28 = sp110.unk8 * temp_f27_1357;
        sp128 = (f64) sp28;
        temp_r3_1372->Translate(temp_r3_1372, *((MKVector3 *) &sp120));
        break;
    case 2:
        var_f0_1320 = this->unkB0 - gUpdateTimeDelta;
        if (var_f0_1320 < 0.25f) {

        } else {
            var_f0_1320 = 0.25f;
        }
        if (var_f0_1320 > 0.0f) {

        } else {
            var_f0_1320 = 0.0f;
        }
        this->unkB0 = var_f0_1320;
        temp_f1_1340 = 10.0f * (this->unkB0 / 0.25f);
        this->unkB8 = temp_f1_1340;
        this->unkBC = temp_f1_1340;
        if (this->unkB0 <= 0.0f) {
            this->unkAC = 0;
        }
        goto block_33;
    }
}
#endif

void ConvexityBreathFX::Init() {
    Matrix sp50;
    M2C_UNK sp4C;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKModel *temp_r3_1523;
    Matrix **temp_r3_1495;
    Matrix **temp_r4_1501;
    Matrix **var_r3_1480;
    Matrix **var_r5_1489;
    s32 var_ctr_1493;

    BaseBreathFX::Init();
    this->unkA8 = MKModel_Create("FX0015_EarthRocket", NULL, 2, NULL);
    this->unkAC = 0;
    this->unkB0 = 0.0f;
    this->unk110 = MKModel_Create("fx0031_sonicring", NULL, 2, NULL);
    this->unk114 = Tools_GetMatchingMaterial(this->unk110, "fx0031_sonicring");
    M2C_STRUCT_COPY((s32) &sp4C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = 0.01f;
    sp14 = -0.01f;
    sp18 = 0.0f;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50.unk30 = (f32) sp40;
    sp50.unk34 = (*(f32 *) ((u8 *) &sp40 + 0x4));
    sp50.unk38 = (f32) sp48;
    sp50.unk3C = 1.0f;
    MKMaterial_SetTextureMatrix(this->unk114, &sp50);
    if (MKHeap::Current() != NULL) {
        var_r3_1480 = (Matrix **) (((MKHeap *) (MKHeap::Current()))->Alloc(0x4F4, NULL, 0));
    } else {
        var_r3_1480 = malloc(0x4F4);
    }
    this->unk118 = var_r3_1480;
    var_r5_1489 = this->unk118;
    this->unk118 = var_r5_1489 + 0x4B0;
    M2C_FIELD(var_r5_1489, s32 *, 0x4B0) = 0;
    var_ctr_1493 = 0xF;
    do {
        temp_r3_1495 = this->unk118;
        this->unk118 = temp_r3_1495 + 4;
        M2C_FIELD(temp_r3_1495, Matrix ***, 4) = var_r5_1489;
        var_r5_1489 += 0x50;
        var_ctr_1493 -= 1;
    } while (var_ctr_1493 != 0);
    temp_r4_1501 = this->unk118;
    this->unk118 = temp_r4_1501 + 4;
    M2C_FIELD(temp_r4_1501, Matrix ***, 4) = NULL;
    this->unk11C = 0.0f;
    this->unk120 = 0.0f;
    ((KDSoundFader *) &this->unk124)->Init(0.25f, 0.25f);
    M2C_FIELD(this, f32 *, 0x150) = 0.0f;
    M2C_FIELD(this, f32 *, 0x154) = 0.0f;
    M2C_FIELD(this, f32 *, 0x158) = 0.0f;
    temp_r3_1523 = MKModel_Create("Fx0022_EarthShot_Flash", NULL, 2, NULL);
    sp20 = 1.0f;
    sp24 = 0.0f;
    sp28 = 0.2f;
    sp2C = 1.0f;
    this->unk160 = temp_r3_1523;
    sp30 = (f64) sp20;
    sp38 = (f64) sp28;
    MKModel_SetColor(this->unk160, *((MKVector4 *) &sp30));
    this->unk170.SetIdentity();
    this->unk1B0 = 0.0f;
}
