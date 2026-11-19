#include "spyro/source/Enemies_FireBoss.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Enemies_FireBossDriver.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/FireBossGoals.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/SpyroHud.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 atoi(s8 *);                                     /* extern */
M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
extern s32 GS_Train2;
extern s32 GS_TrainBossEngineLP;
extern s32 GS_TrainBossMissle01;
extern s32 GS_TrainBossMissle02;
extern s32 GS_TrainEngineBreakLP;
extern s32 GS_TrainJets;
extern s32 GS_TrainTurnSqueal2;
extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrList;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: undefined identifier 'MKVector'
static M2C_UNK lit_750;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_751;                                /* unable to generate initializer: unknown type; const */

void FireBoss::TriggerExplosion() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    M2C_UNK sp30;
    M2C_UNK sp20;
    f32 sp18;
    s32 sp8;

    MKVector(0.0f, 400.0f, 0.0f);
    sp30.GetPos();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp50 = sp10;
    sp18 = sp38 + sp28;
    sp40 = sp10;
    sp58 = (f64) sp18;
    sp8 = 1;
    sp48 = (f64) sp18;
    gb.unk2C0->Trigger(*((MKVector3 *) &sp50), 1.0f, 0U, (MKProp *) this, 0, 0U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

#if 0 // DRAFT: illegal operand
void *FireBossGraphNode::GetEdge(FireBossGraphNode *arg0, int arg1) {
    void *var_r3_134;

    var_r3_134 = this->unk18;
loop_4:
    if (var_r3_134 == NULL) {
        return NULL;
    }
    if (((u32) M2C_FIELD(var_r3_134, u32 *, 4) != arg0) || !(M2C_FIELD(var_r3_134, s32 *, 0x18) & arg1)) {
        var_r3_134 = M2C_FIELD(var_r3_134, void **, 8);
        goto loop_4;
    }
    return var_r3_134;
}
#endif

#if 0 // DRAFT: undefined identifier 'pGraph'
void FireBossGraphNode::AddEdges(FireBossGraphNode *arg0, KDUniformSpline *arg1, float arg2, float arg3, int arg4, bool arg5, unsigned char arg6, unsigned char arg7) {
    s32 var_r28_166;
    s32 var_r3_191;
    u8 var_r31_169;
    void *temp_r3_171;

    var_r28_166 = arg4;
    var_r31_169 = arg7;
    temp_r3_171 = pGraph.unk0->AddEdge();
    M2C_FIELD(temp_r3_171, void **, 8) = (void *) this->unk18;
    this->unk18 = temp_r3_171;
    M2C_FIELD(temp_r3_171, FireBossGraphNode **, 4) = arg0;
    M2C_FIELD(temp_r3_171, KDUniformSpline **, 0) = arg1;
    M2C_FIELD(temp_r3_171, f32 *, 0xC) = arg2;
    M2C_FIELD(temp_r3_171, f32 *, 0x10) = arg3;
    M2C_FIELD(temp_r3_171, s32 *, 0x18) = var_r28_166;
    M2C_FIELD(temp_r3_171, u8 *, 0x1C) = arg6;
    M2C_FIELD(temp_r3_171, u8 *, 0x1D) = var_r31_169;
    this->unk1C += 1;
    if (arg5 != 0) {
        if ((s32) (var_r28_166 & 3) != 3) {
            var_r3_191 = 1;
            if (var_r28_166 & 1) {
                var_r3_191 = 2;
            }
            var_r28_166 = var_r3_191;
        }
        if (var_r31_169 == 2) {
            var_r31_169 = 3;
        } else if (var_r31_169 == 3) {
            var_r31_169 = 2;
        }
        arg0->AddEdges(this, arg1, arg3, arg2, var_r28_166, 0U, arg6, var_r31_169);
    }
}
#endif

void FireBossGraphNode::Init(const MKVector3 &arg0, int arg1) {
    this->unk8 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk10 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk4 = arg1;
    this->unk18 = NULL;
    this->unk1C = 0;
    M2C_FIELD(this, s8 *, 0) = (s8) ((s8) this->unk4 + 0x41);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
FireBossGraphEdge *FireBossDirectedGraph::GetEdge(KDUniformSpline *arg0, float arg1, int arg2) {
    FireBossGraphEdge *temp_r7_255;
    f32 temp_f3_263;
    f32 var_f0_266;
    f32 var_f2_262;
    s32 temp_r0_248;
    s32 var_ctr_250;
    s32 var_r6_249;

    temp_r0_248 = this->unk14;
    var_r6_249 = 0;
    var_ctr_250 = temp_r0_248;
    if (temp_r0_248 > 0) {
loop_1:
        temp_r7_255 = this->unk4 + var_r6_249;
        if (((u32) temp_r7_255->unk0 == arg0) && (temp_r7_255->unk18 & arg2)) {
            var_f2_262 = temp_r7_255->unkC;
            temp_f3_263 = temp_r7_255->unk10;
            if (var_f2_262 < temp_f3_263) {
                var_f0_266 = var_f2_262;
            } else {
                var_f0_266 = temp_f3_263;
            }
            if (var_f2_262 > temp_f3_263) {

            } else {
                var_f2_262 = temp_f3_263;
            }
            if (temp_r7_255->unk1C & 1) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((arg1 == var_f0_266) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((arg1 == var_f2_262) != 0))) {
                    return temp_r7_255;
                }
                goto block_16;
            }
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (arg1 == var_f0_266) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (arg1 == var_f2_262) {
                    return temp_r7_255;
                }
            }
            goto block_16;
        }
block_16:
        var_r6_249 += 0x20;
        var_ctr_250 -= 1;
        if (var_ctr_250 == 0) {
            /* Duplicate return node #17. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void FireBossDirectedGraph::GetEdges(FireBossGraphNode *arg0, int arg1, FireBossGraphEdge **arg2, int arg3) {
    s32 var_r4_311;
    void *var_r7_309;

    var_r7_309 = arg0->unk18;
    var_r4_311 = 0;
loop_4:
    if (var_r7_309 != NULL) {
        if (M2C_FIELD(var_r7_309, s32 *, 0x18) & arg1) {
            *(arg2 + var_r4_311) = var_r7_309;
            var_r4_311 += 4;
        }
        var_r7_309 = M2C_FIELD(var_r7_309, void **, 8);
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
u8 *FireBossDirectedGraph::GetNode(char arg0) {
    s32 temp_r0_331;
    s32 var_ctr_334;
    s32 var_r4_333;
    u8 *temp_r6_339;

    temp_r0_331 = this->unk10;
    var_r4_333 = 0;
    var_ctr_334 = temp_r0_331;
    if (temp_r0_331 > 0) {
loop_1:
        temp_r6_339 = this->unk0 + var_r4_333;
        if (arg0 == (s8) *temp_r6_339) {
            return temp_r6_339;
        }
        var_r4_333 += 0x28;
        var_ctr_334 -= 1;
        if (var_ctr_334 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

void *FireBossDirectedGraph::AddEdge() {
    s32 temp_r5_357;

    temp_r5_357 = this->unk14;
    this->unk14 = temp_r5_357 + 1;
    return this->unk4 + (temp_r5_357 << 5);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
FireBossGraphNode *FireBossDirectedGraph::AddNode(const MKVector3 &arg0) {
    s32 temp_r31_377;
    s32 temp_r5_374;

    temp_r5_374 = this->unk10;
    this->unk10 = temp_r5_374 + 1;
    temp_r31_377 = temp_r5_374 * 0x28;
    ((FireBossGraphNode *) (this->unk0 + temp_r31_377))->Init(arg0, temp_r5_374);
    return this->unk0 + temp_r31_377;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FireBossDirectedGraph::Deinit() {
    MKHeap *temp_r31_398;
    MKHeap *temp_r31_412;
    MKHeap *temp_r3_399;
    MKHeap *temp_r3_413;

    temp_r31_398 = this->unk0;
    temp_r3_399 = MKHeap::Current();
    if (temp_r3_399 != NULL) {
        ((MKHeap *) (temp_r3_399->Current()))->Free(temp_r31_398, NULL, 0);
    } else {
        free(temp_r31_398);
    }
    temp_r31_412 = this->unk4;
    temp_r3_413 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_413 != NULL) {
        ((MKHeap *) (temp_r3_413->Current()))->Free(temp_r31_412, NULL, 0);
        return;
    }
    free(temp_r31_412);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FireBossDirectedGraph::Init() {
    MKHeap *temp_r3_441;
    MKHeap *temp_r3_455;
    MKHeap *var_r3_448;
    MKHeap *var_r3_462;

    temp_r3_441 = MKHeap::Current();
    if (temp_r3_441 != NULL) {
        var_r3_448 = ((MKHeap *) (temp_r3_441->Current()))->Alloc(0x2D0, NULL, 0);
    } else {
        var_r3_448 = malloc(0x2D0);
    }
    this->unk0 = var_r3_448;
    temp_r3_455 = var_r3_448->Current();
    if (temp_r3_455 != NULL) {
        var_r3_462 = ((MKHeap *) (temp_r3_455->Current()))->Alloc(0x580, NULL, 0);
    } else {
        var_r3_462 = malloc(0x580);
    }
    this->unk4 = var_r3_462;
    this->unk8 = this->unk0 + 0x280;
    this->unkC = this->unk0 + 0x2A8;
    this->unk8->Init(zero, 0);
    this->unkC->Init(zero, 0);
    *this->unk8 = 0x58;
    *this->unkC = 0x59;
    this->unk10 = 0;
    this->unk14 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC43'
void FireBoss::InsideEdgeChange() {
    FireBossGraphEdge *temp_r3_541;
    FireBossGraphEdge *var_r30_538;
    u8 var_r31_509;

    var_r31_509 = 0;
    if (((u8) this->unkC43 != 0) || ((SpyroIsInFront() != 0) && (GetCrashEdgeFromNextBranch() != NULL))) {
        var_r31_509 = 1;
        this->unkC41 = 0;
        if ((s32) this->unkC24 > 1) {
            RemoveCrashEdgeFromNextBranch();
        }
    }
    var_r30_538 = M2C_FIELD((this + (MKRand_Int(&gViewSeed, 0, this->unkC24) * 4)), FireBossGraphEdge **, 0xC28);
    if ((u8) this->unkC41 != 0) {
        temp_r3_541 = GetCrashEdgeFromNextBranch();
        if (temp_r3_541 != NULL) {
            var_r30_538 = temp_r3_541;
            this->unkC41 = 0;
            var_r31_509 = 1;
        }
    }
    if ((u8) var_r30_538->unk1D == 2) {
        this->unkC41 = 0;
        var_r31_509 = 1;
        KDSound_Play3d(GS_TrainTurnSqueal2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
    if ((var_r31_509 != 0) && (this->unkF64->IsCharging() != 0)) {
        this->unkF64->ChargeExit();
    }
    SetCurrentEdge(var_r30_538, CalcEdgeSplineStartTime(var_r30_538));
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC24'
FireBossGraphEdge *FireBoss::GetCrashEdgeFromNextBranch() {
    s32 temp_r0_589;
    s32 var_ctr_591;
    s32 var_r4_590;

    temp_r0_589 = this->unkC24;
    var_r4_590 = 0;
    var_ctr_591 = temp_r0_589;
    if (temp_r0_589 > 0) {
loop_1:
        if ((u8) M2C_FIELD(*(this + (var_r4_590 + 0xC28)), u8 *, 0x1D) == 4) {
            return M2C_FIELD((this + var_r4_590), FireBossGraphEdge **, 0xC28);
        }
        var_r4_590 += 4;
        var_ctr_591 -= 1;
        if (var_ctr_591 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC24'
void FireBoss::RemoveCrashEdgeFromNextBranch() {
    s32 temp_r4_638;
    s32 temp_r6_614;
    s32 var_ctr_627;
    s32 var_r4_616;
    s32 var_r5_626;
    s32 var_r7_615;
    s32 var_r8_624;
    void *temp_r5_637;
    void *temp_r6_636;

    temp_r6_614 = this->unkC24;
    var_r7_615 = 0;
    var_r4_616 = 0;
loop_8:
    if (var_r7_615 >= temp_r6_614) {
        return;
    }
    if ((u8) M2C_FIELD(*(this + (var_r4_616 + 0xC28)), u8 *, 0x1D) == 4) {
        var_r8_624 = temp_r6_614 - 1;
        var_r5_626 = var_r8_624 * 4;
        var_ctr_627 = var_r8_624 + 1;
        if (var_r8_624 >= 0) {
loop_3:
            if ((var_r8_624 != var_r7_615) && ((u32) *(this + (var_r5_626 + 0xC28)) != 0U)) {
                temp_r6_636 = this + var_r4_616;
                temp_r5_637 = this + var_r5_626;
                temp_r4_638 = M2C_FIELD(temp_r6_636, s32 *, 0xC28);
                M2C_FIELD(temp_r6_636, s32 *, 0xC28) = (s32) M2C_FIELD(temp_r5_637, s32 *, 0xC28);
                M2C_FIELD(temp_r5_637, s32 *, 0xC28) = temp_r4_638;
                this->unkC24 -= 1;
                return;
            }
            var_r8_624 -= 1;
            var_r5_626 -= 4;
            var_ctr_627 -= 1;
            if (var_ctr_627 == 0) {
                goto block_7;
            }
            goto loop_3;
        }
    }
block_7:
    var_r7_615 += 1;
    var_r4_616 += 4;
    goto loop_8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk7A8'
void FireBoss::LaunchFireball() {
    s32 temp_r3_702;
    u8 var_r31_670;
    void **temp_r3_732;
    void *temp_r4_683;
    var_r31_670 = 0;
    if (((u8) this->unk110.unk7A8 == 2) || (this->unk110.unk7A0.Get() != NULL)) {
        var_r31_670 = 1;
    }
    if (var_r31_670 != 0) {
        temp_r4_683 = this->unkF68;
        if ((temp_r4_683 != NULL) && ((u32) M2C_FIELD(temp_r4_683, u32 *, 0x84) != -1U) && ((u32) M2C_FIELD(temp_r4_683, u32 *, 0) != 0U)) {
            arg_sp40.SetIdentity();
            temp_r3_702 = ((Projectile *) (M2C_FIELD(this->unkF68, Projectile **, 0x80)))->CreateInstance((ProjectileType) (u32) (u64) MKModel_GetRefPointMatrix(this->unk4, this->unkD10.unk200, (Matrix *) &arg_sp40, 1U));
            if (temp_r3_702 != 0) {
                arg_sp30 = arg_sp70;
                arg_sp38 = arg_sp78;
                arg_sp10.GetPos();
                arg_sp20 = arg_sp10;
                arg_sp28 = arg_sp18;
                arg_sp24 = arg_sp34;
                M2C_FIELD(M2C_FIELD(temp_r3_702, void **, 0x44), M2C_UNK (**)(s32, f64 *, f64 *, FireBoss *, s32, M2C_UNK, f32), 0x4C)(temp_r3_702, &arg_sp30, &arg_sp20, this, GS_TrainBossMissle01, 0, 1000.0f);
                this->unkD10.EmitSmoke();
                temp_r3_732 = this->unk1088 - 4;
                this->unk1088 = temp_r3_732;
                *temp_r3_732 = (void *) temp_r3_702;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkF68'
void FireBoss::TriggerFireball() {
    MKAnim **temp_r3_759;
    void *temp_r4_752;

    temp_r4_752 = this->unkF68;
    if ((temp_r4_752 != NULL) && ((u32) M2C_FIELD(temp_r4_752, u32 *, 0x84) != -1U)) {
        temp_r3_759 = M2C_FIELD(temp_r4_752, MKAnim ***, 0);
        if (temp_r3_759 != NULL) {
            this->unkF70.SetAnim(*temp_r3_759, 1.0f, 0.0f, 4, -1);
            this->unkFC8 = 1;
            this->unkF50 += this->unkF54;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk7A8'
void FireBoss::SquashHero() {
    s8 spD9;
    u8 spD8;
    s32 spD4;
    f32 spD0;
    s32 spCC;
    s8 spCA;
    s8 spC9;
    s8 spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    FireBoss *spB4;
    s32 spB0;
    f64 spA8;
    AITargetData sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_813;
    f32 temp_f3_810;
    f32 temp_f4_814;
    f32 temp_f5_808;
    f32 temp_f6_806;
    f32 temp_f7_811;
    s32 temp_r3_879;
    s32 var_r0_893;
    u8 var_r30_793;
    u8 var_r30_866;
    void *temp_r3_877;
    void *var_r3_888;

    var_r30_793 = 0;
    if (((u8) this->unk110.unk7A8 == 2) || (this->unk110.unk7A0.Get() != NULL)) {
        var_r30_793 = 1;
    }
    if (var_r30_793 != 0) {
        temp_f6_806 = this->unkD4;
        temp_f5_808 = this->unkC0;
        temp_f3_810 = this->unkC8;
        temp_f7_811 = this->unkD0;
        temp_f2_813 = this->unkC4;
        temp_f4_814 = this->unkD8;
        sp40 = (temp_f7_811 * temp_f2_813) - (temp_f6_806 * temp_f5_808);
        sp3C = (temp_f4_814 * temp_f5_808) - (temp_f7_811 * temp_f3_810);
        sp38 = (temp_f6_806 * temp_f3_810) - (temp_f4_814 * temp_f2_813);
        sp58.unk28 = (f64) sp40;
        sp58.unk20 = (f64) sp38;
        sp58.GetDir();
        if ((((f32) sp58.unk28 * sp58.unk8) + (((f32) sp58.unk20 * M2C_BITWISE(f32, sp58)) + (unksp7C * unksp5C))) > 0.0f) {
            sp58.unk10 = sp58.unk20;
            sp58.unk18 = sp58.unk28;
        } else {
            sp8 = -(f32) sp58.unk20;
            spC = -unksp7C;
            sp10 = -(f32) sp58.unk28;
            sp48 = (f64) sp8;
            sp50 = (f64) sp10;
            sp58.unk10 = (f64) sp8;
            sp58.unk18 = (f64) sp10;
        }
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        var_r30_866 = 1;
        sp58.unk18 = (f32) sp58.unk18 * 400.0f;
        gb.GetSpyro();
        if (((KDStateMachine<Spyro> *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x7C))->GetState() != 2) {
            gb.GetSpyro();
            temp_r3_877 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x27C);
            temp_r3_879 = M2C_FIELD(temp_r3_877, s32 *, 0x16C);
            if (((u32) (-temp_r3_879 & ~temp_r3_879) >> 0x1FU) != 0) {
                if (temp_r3_879 != 0) {
                    var_r3_888 = temp_r3_877 + 8 + ((temp_r3_879 - 1) * 0x58);
                } else {
                    var_r3_888 = NULL;
                }
                var_r0_893 = M2C_FIELD(var_r3_888, s32 *, 0x44);
            } else {
                var_r0_893 = 0;
            }
            if (!(var_r0_893 & 0x08000000)) {
                var_r30_866 = 0;
            }
        }
        if ((var_r30_866 == 0) || (gb.GetSpyro(), (((s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x5C) == 9) == 0))) {
            sp58.unk34 = 0.0f;
            if (var_r30_866 != 0) {
                sp58.unk30 = 1e-44f;
                spB0 = 6;
                spB4 = this;
                sp58.unk38 = sp58.unk10;
                sp58.unk40 = (f64) sp58.unk18;
                spC8 = 1;
                spD4 = 2;
                spD0 = 5.0f;
                spC9 = 0;
                spCA = 0;
                spCC = -1;
                sp58.unk40.unk8 = M2C_FIELD(&one, f64 *, 0);
                spA8 = M2C_FIELD(&one, f64 *, 8);
                spD8 = 0;
                if (this != NULL) {
                    sp28.GetPos();
                    spB8 = sp28;
                    spC0 = sp30;
                } else {
                    spB8 = 0.0f;
                    unkspBC = 0.0f;
                    spC0 = 0.0f;
                }
                spD9 = 0;
            } else {
                sp58.unk30 = 1e-44f;
                spB0 = 3;
                spB4 = this;
                sp58.unk38 = M2C_FIELD(&zero, f64 *, 0);
                sp58.unk40 = M2C_FIELD(&zero, f64 *, 8);
                spC8 = 1;
                spD4 = 2;
                spD0 = 10.0f;
                spC9 = 0;
                spCA = 0;
                spCC = -1;
                sp58.unk40.unk8 = M2C_FIELD(&one, f64 *, 0);
                spA8 = M2C_FIELD(&one, f64 *, 8);
                spD8 = 0;
                if (this != NULL) {
                    sp18.GetPos();
                    spB8 = sp18;
                    spC0 = sp20;
                } else {
                    spB8 = 0.0f;
                    unkspBC = 0.0f;
                    spC0 = 0.0f;
                }
                spD9 = 0;
            }
            M2C_FIELD(gb.unk0->__vptr, M2C_UNK (**)(HeroInterface *, f32 *), 0x1C)(gb.unk0, &sp58.unk30);
            if (spD8 != 0) {
                if ((u8) this->unkC1C->unk1D == 1) {
                    this->unkC43 = 1;
                    this->unkC41 = 0;
                }
                if (KDSound_IsVoicePlaying(this->unk106C) == 0) {
                    this->unk106C = KDSound_Play3d(GS_Train2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk7A8'
void FireBoss::HurtHero() {
    s8 spC1;
    u8 spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    FireBoss *sp9C;
    s32 sp98;
    f64 sp90;
    AITargetData sp40;
    MKVector3 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_1198;
    f32 temp_f2_1080;
    f32 temp_f3_1077;
    f32 temp_f4_1081;
    f32 temp_f5_1076;
    f32 temp_f6_1075;
    f32 temp_f7_1078;
    f32 var_f3_1187;
    f32 var_f4_1120;
    f64 temp_f1_1126;
    f64 temp_f1_1132;
    f64 temp_f1_1136;
    s32 temp_r3_1155;
    s32 var_r0_1165;
    u8 var_r30_1058;

    var_r30_1058 = 0;
    if (((u8) this->unk110.unk7A8 == 2) || (this->unk110.unk7A0.Get() != NULL)) {
        var_r30_1058 = 1;
    }
    if (var_r30_1058 != 0) {
        sp40.unk34 = 0.0f;
        temp_f6_1075 = this->unkD4;
        temp_f5_1076 = this->unkC0;
        temp_f3_1077 = this->unkC8;
        temp_f7_1078 = this->unkD0;
        temp_f2_1080 = this->unkC4;
        temp_f4_1081 = this->unkD8;
        sp28 = (temp_f7_1078 * temp_f2_1080) - (temp_f6_1075 * temp_f5_1076);
        sp24 = (temp_f4_1081 * temp_f5_1076) - (temp_f7_1078 * temp_f3_1077);
        sp20 = (temp_f6_1075 * temp_f3_1077) - (temp_f4_1081 * temp_f2_1080);
        sp40.unk28 = (f64) sp28;
        sp40.unk20 = (f64) sp20;
        sp40.GetDir();
        KDMath_Slerp(sp30, *((MKVector3 *) &this->unkC0), ((f32) sp40.unk28 * sp40.unk8) + (((f32) sp40.unk20 * M2C_BITWISE(f32, sp40)) + (unksp64 * unksp44)));
        sp40.unk10 = M2C_BITWISE(f64, sp30);
        sp40.unk18 = (f64) sp30.unk8;
        var_f4_1120 = ((f32) sp40.unk18 * (f32) sp40.unk18) + (((f32) sp40.unk10 * (f32) sp40.unk10) + (unksp54 * unksp54));
        if (var_f4_1120 > 0.000001f) {
            if (var_f4_1120 > 0.0f) {
                temp_f1_1126 = __frsqrte(var_f4_1120);
                temp_f1_1132 = 0.5 * temp_f1_1126 * -(((f64) var_f4_1120 * (temp_f1_1126 * temp_f1_1126)) - 3.0);
                temp_f1_1136 = 0.5 * temp_f1_1132 * -(((f64) var_f4_1120 * (temp_f1_1132 * temp_f1_1132)) - 3.0);
                var_f4_1120 = (f32) ((f64) var_f4_1120 * (0.5 * temp_f1_1136 * -(((f64) var_f4_1120 * (temp_f1_1136 * temp_f1_1136)) - 3.0)));
            } else if (var_f4_1120 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1120 = __float_nan;
            } else {
                sp8 = var_f4_1120;
                temp_r3_1155 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1155) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1165 = 1;
                    } else {
                        var_r0_1165 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1165 = 5;
                    } else {
                        var_r0_1165 = 3;
                    }
                    break;
                default:
                    var_r0_1165 = 4;
                    break;
                }
                if (var_r0_1165 == 1) {
                    var_f4_1120 = __float_nan;
                }
            }
            var_f3_1187 = 1.0f / var_f4_1120;
        } else {
            var_f3_1187 = 0.0f;
        }
        temp_f0_1198 = (f32) sp40.unk18 * var_f3_1187;
        sp40.unk10 = (f32) sp40.unk10 * var_f3_1187;
        unksp54 *= var_f3_1187;
        sp40.unk18 = temp_f0_1198;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f31 */);
        sp40.unk18 = temp_f0_1198 * 20000.0f;
        sp40.unk30 = 1e-44f;
        sp98 = 2;
        sp9C = this;
        sp40.unk38 = (f64) sp40.unk10;
        sp40.unk40 = (f64) sp40.unk18;
        spB0 = 1;
        spBC = 2;
        spB8 = 10.0f;
        spB1 = 0;
        spB2 = 0;
        spB4 = -1;
        sp40.unk40.unk8 = M2C_FIELD(&one, f64 *, 0);
        sp90 = M2C_FIELD(&one, f64 *, 8);
        spC0 = 0;
        if (this != NULL) {
            sp10.GetPos();
            spA0 = sp10;
            spA8 = sp18;
        } else {
            spA0 = 0.0f;
            unkspA4 = 0.0f;
            spA8 = 0.0f;
        }
        spC1 = 0;
        M2C_FIELD(gb.unk0->__vptr, M2C_UNK (**)(HeroInterface *, f32 *), 0x1C)(gb.unk0, &sp40.unk30);
        if (spC0 != 0) {
            if ((u8) this->unkC1C->unk1D == 1) {
                this->unkC43 = 1;
                this->unkC41 = 0;
            }
            if (KDSound_IsVoicePlaying(this->unk106C) == 0) {
                this->unk106C = KDSound_Play3d(GS_Train2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk7A8'
u8 FireBoss::SpyroIsInFront() {
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    u8 var_r31_1301;
    void *temp_r3_1317;

    var_r31_1301 = 0;
    if (((u8) this->unk110.unk7A8 == 2) || (this->unk110.unk7A0.Get() != NULL)) {
        var_r31_1301 = 1;
    }
    if (var_r31_1301 != 0) {
        sp38.GetPos();
        temp_r3_1317 = this->unk8;
        sp48 = sp38;
        sp28 = M2C_FIELD(temp_r3_1317, f64 *, 0x30);
        sp50 = sp40;
        sp30 = M2C_FIELD(temp_r3_1317, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp18 = sp8;
        sp10 = (f32) sp50 - (f32) sp30;
        sp20 = (f64) sp10;
        if ((((f32) sp20 * this->unkC8) + (((f32) sp18 * this->unkC0) + (unksp1C * this->unkC4))) > 0.0f) {
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkD10'
void FireBoss::CheckFlameThrowerHit() {
    u32 var_r29_1569;
    u32 var_r30_1503;
    u8 var_r30_1383;
    u8 var_r30_1485;
    u8 var_r30_1551;
    void *temp_r4_1405;
    if ((u8) this->unkD10.unk90 != 0) {
        var_r30_1383 = 0;
        if (((u8) this->unk110.unk7A8 == 2) || (this->unk110.unk7A0.Get() != NULL)) {
            var_r30_1383 = 1;
        }
        if (var_r30_1383 != 0) {
            MKModel_GetRefPointMatrix(this->unkD10.unk4, this->unkD10.unk1F0, (Matrix *) &arg_sp120, 1U);
            MKModel_GetRefPointMatrix(this->unkD10.unk4, this->unkD10.unk1F8, (Matrix *) &arg_spE0, 1U);
            temp_r4_1405 = this->unk110.unk524;
            arg_sp10 = temp_r4_1405;
            if (temp_r4_1405 != NULL) {
                arg_sp14 = M2C_FIELD(temp_r4_1405, u8 *, 4);
                M2C_FIELD(temp_r4_1405, u8 *, 4) = 0U;
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            arg_spC8 = arg_sp28;
            arg_sp30 = arg_sp148 * -1.0f;
            arg_spD0 = (f64) arg_sp30;
            arg_sp140 = (f32) arg_spC8;
            arg_sp144 = arg_spCC;
            arg_sp148 = (f32) arg_spD0;
            arg_sp14C = 0.0f;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            arg_sp10C = 0.0f;
            arg_spB8 = arg_sp18;
            arg_sp20 = arg_sp108 * -1.0f;
            arg_spC0 = (f64) arg_sp20;
            arg_sp100 = (f32) arg_spB8;
            arg_sp104 = arg_spBC;
            arg_sp108 = (f32) arg_spC0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp70 = (f32) arg_spD0 * 500.0f;
            arg_sp98 = arg_sp68;
            arg_spA0 = (f64) arg_sp70;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spA8 = arg_sp58;
            arg_sp60 = arg_sp158 + (f32) arg_spA0;
            arg_spB0 = (f64) arg_sp60;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp150), *((MKVector3 *) &arg_spA8), 200.0f, (MKCollisionResult *) &arg_sp160, (MKCollisionMode) 2, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) != 0) {
                var_r30_1485 = 0;
                if (((u8) this->unk110.unk7A8 == 2) || (this->unk110.unk7A0.Get() != NULL)) {
                    var_r30_1485 = 1;
                }
                if (var_r30_1485 != 0) {
                    if ((arg_sp1B0 != 0) && (arg_sp1A8 != NULL) && (var_r30_1503 = M2C_FIELD(arg_sp1A8, u32 *, 8), ((var_r30_1503 == 0U) == 0))) {

                    } else {
                        var_r30_1503 = 0U;
                    }
                    if (var_r30_1503 == this->unk110.unk760.GetProp()) {
                        HurtHero();
                    }
                }
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp78 = arg_sp48;
            arg_sp50 = arg_sp108 * 500.0f;
            arg_sp80 = (f64) arg_sp50;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp88 = arg_sp38;
            arg_sp40 = arg_sp118 + (f32) arg_sp80;
            arg_sp90 = (f64) arg_sp40;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp110), *((MKVector3 *) &arg_sp88), 200.0f, (MKCollisionResult *) &arg_sp160, (MKCollisionMode) 2, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) != 0) {
                var_r30_1551 = 0;
                if (((u8) this->unk110.unk7A8 == 2) || (this->unk110.unk7A0.Get() != NULL)) {
                    var_r30_1551 = 1;
                }
                if (var_r30_1551 != 0) {
                    if ((arg_sp1B0 != 0) && (arg_sp1A8 != NULL) && (var_r29_1569 = M2C_FIELD(arg_sp1A8, u32 *, 8), ((var_r29_1569 == 0U) == 0))) {

                    } else {
                        var_r29_1569 = 0U;
                    }
                    if (var_r29_1569 == this->unk110.unk760.GetProp()) {
                        HurtHero();
                    }
                }
            }
            this->unkFCB = 0;
            arg_sp8 = 1;
            this->unkFCC.Update(GS_TrainBossMissle02, 1U, 1U, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            if (arg_sp10 != NULL) {
                M2C_FIELD(arg_sp10, u8 *, 4) = arg_sp14;
            }
        } else {
            goto block_33;
        }
    } else {
block_33:
        this->unkFCB = 1;
        arg_sp8 = 1;
        this->unkFCC.Update(GS_TrainBossMissle02, 1U, 0U, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk524'
s32 FireBoss::HasRunOverSpyro() {
    MKCollisionResult spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    u8 spC;
    void *sp8;
    u32 var_r31_1738;
    void *temp_r3_1659;
    void *temp_r3_1698;
    void *temp_r4_1640;

    temp_r4_1640 = this->unk110.unk524;
    sp8 = temp_r4_1640;
    if (temp_r4_1640 != NULL) {
        spC = M2C_FIELD(temp_r4_1640, u8 *, 4);
        M2C_FIELD(temp_r4_1640, u8 *, 4) = 0U;
    }
    if ((this->unk110.unkA10 > 100.0f) && ((M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */), M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */), temp_r3_1659 = this->unk8, sp48 = this->unkC8 * -350.0f, sp80 = sp40, sp90 = M2C_FIELD(temp_r3_1659, f64 *, 0x30), sp88 = (f64) sp48, sp98 = M2C_FIELD(temp_r3_1659, f64 *, 0x38), M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */), spA0 = sp30, sp38 = (f32) sp98 + (f32) sp88, spA8 = (f64) sp38, ((MKCollision_SphereCollide(*((MKVector3 *) &spA0), 350.0f, &spB0, 1, (MKCollisionMode) 2, -0x04000001) == 0) == 0)) || (M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */), M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */), temp_r3_1698 = this->unk8, sp28 = this->unkC8 * 300.0f, sp50 = sp20, sp60 = M2C_FIELD(temp_r3_1698, f64 *, 0x30), sp58 = (f64) sp28, sp68 = M2C_FIELD(temp_r3_1698, f64 *, 0x38), M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */), sp70 = sp10, sp18 = (f32) sp68 + (f32) sp58, sp78 = (f64) sp18, ((MKCollision_SphereCollide(*((MKVector3 *) &sp70), 350.0f, &spB0, 1, (MKCollisionMode) 2, -0x04000001) == 0) == 0)))) {
        if ((spB0.unk50 != 0) && (spB0.unk48 != NULL) && (var_r31_1738 = M2C_FIELD(spB0.unk48, u32 *, 8), ((var_r31_1738 == 0U) == 0))) {

        } else {
            var_r31_1738 = 0U;
        }
        if (var_r31_1738 == this->unk110.unk760.GetProp()) {
            SquashHero();
        }
    }
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
u8 FireBoss::IsSpyroOnInsideTrack(int arg0) {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1839;
    f32 temp_f1_1849;
    f32 temp_f4_1817;
    u8 var_r0_1786;
    void *temp_r3_1788;
    void *temp_r4_1784;

    temp_r4_1784 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, GameGlobals *), 0xC)(gb.unk0, &gb), void **, 8);
    var_r0_1786 = 0;
    temp_r3_1788 = this + (arg0 * 0x60);
    sp28 = M2C_FIELD(temp_r4_1784, f64 *, 0x30);
    sp30 = M2C_FIELD(temp_r4_1784, f64 *, 0x38);
    temp_f4_1817 = M2C_FIELD(temp_r3_1788, f32 *, 0xC50);
    sp8 = M2C_FIELD(temp_r3_1788, f32 *, 0xCA0) + (((f32) sp30 * M2C_FIELD(temp_r3_1788, f32 *, 0xC90)) + (((f32) sp28 * M2C_FIELD(temp_r3_1788, f32 *, 0xC70)) + (unksp2C * M2C_FIELD(temp_r3_1788, f32 *, 0xC80))));
    spC = M2C_FIELD(temp_r3_1788, f32 *, 0xCA4) + (((f32) sp30 * M2C_FIELD(temp_r3_1788, f32 *, 0xC94)) + (((f32) sp28 * M2C_FIELD(temp_r3_1788, f32 *, 0xC74)) + (unksp2C * M2C_FIELD(temp_r3_1788, f32 *, 0xC84))));
    sp10 = M2C_FIELD(temp_r3_1788, f32 *, 0xCA8) + (((f32) sp30 * M2C_FIELD(temp_r3_1788, f32 *, 0xC98)) + (((f32) sp28 * M2C_FIELD(temp_r3_1788, f32 *, 0xC78)) + (unksp2C * M2C_FIELD(temp_r3_1788, f32 *, 0xC88))));
    sp28 = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    sp30 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if ((f32) sp28 == temp_f4_1817) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((f32) sp28 == (temp_f4_1817 + M2C_FIELD(temp_r3_1788, f32 *, 0xC60))) {
            temp_f1_1839 = M2C_FIELD(temp_r3_1788, f32 *, 0xC54);
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (unksp2C == temp_f1_1839) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (unksp2C == (temp_f1_1839 + M2C_FIELD(temp_r3_1788, f32 *, 0xC64))) {
                    temp_f1_1849 = M2C_FIELD(temp_r3_1788, f32 *, 0xC58);
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if ((f32) sp30 == temp_f1_1849) {
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if ((f32) sp30 == (temp_f1_1849 + M2C_FIELD(temp_r3_1788, f32 *, 0xC68))) {
                            var_r0_1786 = 1;
                        }
                    }
                }
            }
        }
    }
    return var_r0_1786;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC1C'
void FireBoss::SetCurrentEdge(FireBossGraphEdge *arg0, float arg1) {
    FireBossGraphEdge *temp_r3_1879;
    FireBossGraphEdge *temp_r3_1918;
    FireBossGraphEdge *temp_r3_1942;
    s32 var_r4_1954;

    temp_r3_1879 = this->unkC1C;
    if (temp_r3_1879 != NULL) {
        this->unkC20 = (u8 *) temp_r3_1879->unk4;
    } else {
        this->unkC20 = this->unkC18->GetNode(0x41);
    }
    this->unkC1C = arg0;
    this->unkC38 &= this->unkC1C->unk18;
    if ((s32) this->unkC38 == 0) {
        this->unkC38 = this->unkC1C->unk18;
    }
    this->unkF64->unk110.unkA04 = this->unkC38 & 1;
    this->unk110.unkA18 = arg1;
    this->unkC14 = this->unkC1C->unk0;
    this->unk110.unkA20 = 1.0f / M2C_FIELD(this->unkC14, f32 *, 8);
    temp_r3_1918 = this->unkC1C;
    if (temp_r3_1918->unk1C & 1) {
        if ((s32) temp_r3_1918->unk18 == 1) {
            this->unk110.unkA1C = 1.0f;
        } else {
            this->unk110.unkA1C = -1.0f;
        }
    } else if (temp_r3_1918->unkC < temp_r3_1918->unk10) {
        this->unk110.unkA1C = 1.0f;
    } else {
        this->unk110.unkA1C = -1.0f;
    }
    temp_r3_1942 = this->unkC1C;
    if (((u8) temp_r3_1942->unk1D == 1) && ((u8) this->unkC41 == 0) && ((u8) this->unkC43 == 0)) {
        var_r4_1954 = 0;
        if ((void *) temp_r3_1942->unk0 == &this->unk110.unkA50) {
            var_r4_1954 = 1;
        }
        if (IsSpyroOnInsideTrack(var_r4_1954) != 0) {
            this->unkC41 = 1;
        }
    }
    UpdateNextBranch();
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC1C'
s32 FireBoss::CheckForEndOfEdge(bool arg0) {
    FireBossGraphEdge *temp_r5_1980;
    f32 temp_f1_1992;
    f32 temp_f1_2003;
    f32 temp_f2_1988;
    f32 temp_f2_2019;
    u8 var_r4_0;

    var_r4_0 = arg0;
    temp_r5_1980 = this->unkC1C;
    if ((u8) temp_r5_1980->unk1D == 0) {
        var_r4_0 = 0;
        if (temp_r5_1980->unk1C & 1) {
            temp_f2_1988 = this->unk110.unkA1C;
            if (((temp_f2_1988 < 0.0f) && (temp_f1_1992 = this->unk110.unkA18, ((temp_f1_1992 < temp_r5_1980->unk10) != 0)) && (temp_f1_1992 > temp_r5_1980->unkC)) || ((temp_f2_1988 > 0.0f) && (temp_f1_2003 = this->unk110.unkA18, ((temp_f1_2003 > temp_r5_1980->unk10) != 0)) && (temp_f1_2003 < temp_r5_1980->unkC))) {
                return 1;
            }
            return 0;
        }
    }
    if ((var_r4_0 != 0) || ((temp_f2_2019 = this->unk110.unkA1C, ((temp_f2_2019 > 0.0f) != 0)) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((this->unk110.unkA18 == temp_r5_1980->unk10) != 0))) || ((temp_f2_2019 < 0.0f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk110.unkA18 == temp_r5_1980->unk10) != 0)))) {
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC1C'
f32 FireBoss::CalcEdgeSplineStartTime(FireBossGraphEdge *arg0) {
    if (((u8) this->unkC1C->unk1D == 0) && ((u8) arg0->unk1D == 0)) {
        return this->unk110.unkA18;
    }
    return arg0->unkC;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FireBoss::MoveAlongCurrentSpline(float arg0) {
    f32 temp_f0_2126;
    f32 temp_f1_2094;
    f32 temp_f1_2110;
    u8 var_r31_2076;

    var_r31_2076 = 0;
    if (M2C_FIELD(gb.unk0->__vptr, u8 (**)(HeroInterface *, GameGlobals *), 0x70)(gb.unk0, &gb) != 0) {
        this->unkD10.unk14 = 1.5f;
    } else {
        temp_f1_2094 = gUpdateTimeDelta * (arg0 * M2C_BITWISE(f32, this->unk110.unkA20) * this->unk110.unkA1C);
        this->unk110.unkA18 += temp_f1_2094;
        if ((void *) this->unkC14 == &this->unk110.unkA28) {
            this->unk110.unkA08 += (f32) fabs(temp_f1_2094);
        }
        if (this->unk110.unkA1C > 0.0f) {
            temp_f1_2110 = this->unk110.unkA18;
            if (temp_f1_2110 > 1.0f) {
                var_r31_2076 = 1;
                this->unk110.unkA18 = temp_f1_2110 - 1.0f;
                this->unk110.unkA24 = this->unk110.unkA18 / M2C_BITWISE(f32, this->unk110.unkA20);
                M2C_FIELD(this, s32 *, 0xB14) = (s32) (M2C_FIELD(this, s32 *, 0xB14) + 1);
            }
        } else {
            temp_f0_2126 = this->unk110.unkA18;
            if (temp_f0_2126 < 0.0f) {
                var_r31_2076 = 1;
                this->unk110.unkA18 = temp_f0_2126 + 1.0f;
                this->unk110.unkA24 = (1.0f - this->unk110.unkA18) / M2C_BITWISE(f32, this->unk110.unkA20);
                M2C_FIELD(this, s32 *, 0xB14) = (s32) (M2C_FIELD(this, s32 *, 0xB14) + 1);
            }
        }
    }
    CheckForEndOfEdge(var_r31_2076);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC1C'
void FireBoss::UpdateNextBranch() {
    FireBossGraphEdge *sp8;
    s32 temp_r3_2246;
    s32 var_ctr_2182;
    s32 var_r4_2181;
    s32 var_r5_2171;
    u8 temp_r0_2201;
    u8 temp_r0_2226;
    u8 temp_r31_2167;
    void *temp_r5_2200;
    void *temp_r5_2218;
    void *temp_r5_2242;
    void *temp_r5_2261;

    temp_r31_2167 = this->unkC1C->unk1D;
    this->unkC24 = 0;
    memset(&this->unkC28, 0, 0x10U);
    var_r5_2171 = this->unkC3C;
    if (temp_r31_2167 == 0) {
        var_r5_2171 = this->unkC38;
    }
    this->unkC18->GetEdges(this->unkC1C->unk4, var_r5_2171, &sp8, 4);
    var_r4_2181 = 0;
    var_ctr_2182 = M2C_ERROR(/* Read from unset register $r3 */);
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) > 0) {
        do {
            switch ((s32) temp_r31_2167) {          /* irregular */
            case 4:
                break;
            case 0:
                temp_r5_2200 = *(&sp8 + var_r4_2181);
                temp_r0_2201 = M2C_FIELD(temp_r5_2200, u8 *, 0x1D);
                if ((temp_r0_2201 == 0) || (temp_r0_2201 == 3)) {
                    *(this + ((this->unkC24 * 4) + 0xC28)) = temp_r5_2200;
                    this->unkC24 += 1;
                }
                break;
            case 1:
                temp_r5_2218 = *(&sp8 + var_r4_2181);
                if ((((u32) M2C_FIELD(temp_r5_2218, u32 *, 4) != (u8 *) this->unkC20) && ((u8) M2C_FIELD(temp_r5_2218, u8 *, 0x1D) == 1)) || (temp_r0_2226 = M2C_FIELD(temp_r5_2218, u8 *, 0x1D), ((temp_r0_2226 == 2) != 0)) || (temp_r0_2226 == 4)) {
                    *(this + ((this->unkC24 * 4) + 0xC28)) = temp_r5_2218;
                    this->unkC24 += 1;
                }
                break;
            case 2:
                temp_r5_2242 = *(&sp8 + var_r4_2181);
                if ((u8) M2C_FIELD(temp_r5_2242, u8 *, 0x1D) == 0) {
                    temp_r3_2246 = this->unkC38;
                    if (temp_r3_2246 == (s32) (temp_r3_2246 & M2C_FIELD(temp_r5_2242, s32 *, 0x18))) {
                        *(this + ((this->unkC24 * 4) + 0xC28)) = temp_r5_2242;
                        this->unkC24 += 1;
                    }
                }
                break;
            case 3:
                temp_r5_2261 = *(&sp8 + var_r4_2181);
                if ((u8) M2C_FIELD(temp_r5_2261, u8 *, 0x1D) == 1) {
                    *(this + ((this->unkC24 * 4) + 0xC28)) = temp_r5_2261;
                    this->unkC24 += 1;
                }
                break;
            }
            var_r4_2181 += 4;
            var_ctr_2182 -= 1;
        } while (var_ctr_2182 != 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC18'
void FireBoss::FinaliseGraph() {
    FireBossDirectedGraph *temp_r5_2292;
    u8 *temp_r22_2335;
    u8 *temp_r23_2330;
    u8 *temp_r24_2325;
    u8 *temp_r25_2320;
    u8 *temp_r26_2315;
    u8 *temp_r27_2310;
    u8 *temp_r28_2305;
    u8 *temp_r29_2300;
    void *temp_r30_2339;
    void *temp_r30_2358;
    void *temp_r30_2377;
    void *temp_r30_2396;

    temp_r5_2292 = this->unkC18;
    temp_r5_2292->unk10 += 2;
    temp_r29_2300 = this->unkC18->GetNode(0x42);
    temp_r28_2305 = this->unkC18->GetNode(0x43);
    temp_r27_2310 = this->unkC18->GetNode(0x47);
    temp_r26_2315 = this->unkC18->GetNode(0x46);
    temp_r25_2320 = this->unkC18->GetNode(0x4B);
    temp_r24_2325 = this->unkC18->GetNode(0x4A);
    temp_r23_2330 = this->unkC18->GetNode(0x4F);
    temp_r22_2335 = this->unkC18->GetNode(0x4E);
    temp_r30_2339 = temp_r27_2310->GetEdge((FireBossGraphNode *) temp_r26_2315, 3);
    temp_r29_2300->AddEdges((FireBossGraphNode *) temp_r27_2310, (KDUniformSpline *) &this->unk110.unkA28, M2C_FIELD(temp_r29_2300->GetEdge((FireBossGraphNode *) temp_r28_2305, 3), f32 *, 0xC), M2C_FIELD(temp_r30_2339, f32 *, 0xC), 1, 1U, 0U, 0U);
    temp_r30_2358 = temp_r25_2320->GetEdge((FireBossGraphNode *) temp_r24_2325, 3);
    temp_r26_2315->AddEdges((FireBossGraphNode *) temp_r25_2320, (KDUniformSpline *) &this->unk110.unkA28, M2C_FIELD(temp_r26_2315->GetEdge((FireBossGraphNode *) temp_r27_2310, 3), f32 *, 0xC), M2C_FIELD(temp_r30_2358, f32 *, 0xC), 1, 1U, 0U, 0U);
    temp_r30_2377 = temp_r23_2330->GetEdge((FireBossGraphNode *) temp_r22_2335, 3);
    temp_r24_2325->AddEdges((FireBossGraphNode *) temp_r23_2330, (KDUniformSpline *) &this->unk110.unkA28, M2C_FIELD(temp_r24_2325->GetEdge((FireBossGraphNode *) temp_r25_2320, 3), f32 *, 0xC), M2C_FIELD(temp_r30_2377, f32 *, 0xC), 1, 1U, 0U, 0U);
    temp_r30_2396 = temp_r28_2305->GetEdge((FireBossGraphNode *) temp_r29_2300, 3);
    temp_r22_2335->AddEdges((FireBossGraphNode *) temp_r28_2305, (KDUniformSpline *) &this->unk110.unkA28, M2C_FIELD(temp_r22_2335->GetEdge((FireBossGraphNode *) temp_r23_2330, 3), f32 *, 0xC), M2C_FIELD(temp_r30_2396, f32 *, 0xC), 1, 1U, 0U, 0U);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FireBoss *' to
void FireBoss::CreateTurnSplines(int arg0, int arg1, int arg2, float arg3, float arg4) {
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    KDUniformSpline sp120;
    f64 sp110;
    KDUniformSpline spF0;
    MKVector3 spE0;
    KDUniformSpline spC0;
    f64 spB0;
    f64 spA0;
    MKVector3 sp90;
    KDUniformSpline sp70;
    KDUniformSpline sp50;
    M2C_UNK sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    FireBossGraphNode *temp_r23_2680;
    FireBossGraphNode *temp_r24_2667;
    FireBossGraphNode *temp_r25_2509;
    FireBossGraphNode *temp_r30_2504;
    KDUniformSpline *temp_r26_2465;
    KDUniformSpline *temp_r27_2450;
    Matrix *temp_r31_2475;
    f32 temp_f28_2459;
    f32 temp_f30_2477;
    f32 temp_f31_2472;
    f32 temp_f31_2566;
    f32 var_f26_2679;
    f32 var_f28_2687;
    f32 var_f29_2568;
    f64 temp_f0_2599;
    f64 temp_f1_2598;
    u8 var_r8_2722;

    temp_r27_2450 = this + ((arg0 * 0x14) + 0xB74);
    temp_f28_2459 = 1.0f / (f32) (this->unk110.unkA2C - 1);
    temp_r27_2450->Init(5, 0U);
    temp_r26_2465 = this + ((arg1 * 0x14) + 0xB74);
    temp_r26_2465->Init(5, 0U);
    temp_f31_2472 = 3.0f * temp_f28_2459;
    temp_r31_2475 = this + ((arg2 * 0x14) + 0xB4C);
    sp24 = 0.0f;
    temp_f30_2477 = arg3 + temp_f31_2472;
    sp120.GetMeasure(arg4, temp_r31_2475, KDSpline_PositionMixer);
    sp150 = M2C_BITWISE(f64, sp120);
    sp158 = (f64) sp120.unk8;
    sp20 = 0.0f;
    sp110.GetMeasure(temp_f30_2477, (Matrix *) &this->unk110.unkA28, KDSpline_PositionMixer);
    sp140 = sp110;
    sp148 = sp118;
    temp_r30_2504 = this->unkC18->AddNode(*((MKVector3 *) &sp150));
    temp_r25_2509 = this->unkC18->AddNode(*((MKVector3 *) &sp140));
    temp_r27_2450->AddNode(*((MKVector3 *) &sp150));
    sp1C = 0.0f;
    spF0.GetMeasure((0.5f * temp_f28_2459) + arg3, (Matrix *) &this->unk110.unkA28, KDSpline_PositionMixer);
    InterpolateLinear(*((MKVector3 *) &spF0.unk10), *((MKVector3 *) &sp150), 0.75f);
    sp120.unk10 = M2C_BITWISE(f64, spF0.unk10);
    sp138 = sp108;
    temp_r27_2450->AddNode(*((MKVector3 *) &sp120.unk10));
    InterpolateLinear(spE0, *((MKVector3 *) &sp150), 0.5f);
    sp120.unk10 = M2C_BITWISE(f64, spE0);
    sp138 = (f64) spE0.unk8;
    sp18 = 0.0f;
    spC0.GetMeasure((1.3f * temp_f28_2459) + arg3, (Matrix *) &this->unk110.unkA28, KDSpline_PositionMixer);
    InterpolateLinear(*((MKVector3 *) &spC0.unk10), *((MKVector3 *) &sp120.unk10), 0.9f);
    sp120.unk10 = M2C_BITWISE(f64, spC0.unk10);
    sp138 = spD8;
    temp_r27_2450->AddNode(*((MKVector3 *) &sp120.unk10));
    temp_r27_2450->AddNode(*((MKVector3 *) &sp140));
    temp_f31_2566 = arg3 - temp_f31_2472;
    var_f29_2568 = temp_f31_2566;
    if (temp_f31_2566 < 0.0f) {
        var_f29_2568 = temp_f31_2566 + 1.0f;
    }
    sp14 = 0.0f;
    spB0.GetMeasure(arg4, temp_r31_2475, KDSpline_PositionMixer);
    sp150 = spB0;
    sp158 = spB8;
    sp10 = 0.0f;
    spA0.GetMeasure(var_f29_2568, (Matrix *) &this->unk110.unkA28, KDSpline_PositionMixer);
    temp_f1_2598 = sp150;
    temp_f0_2599 = sp158;
    sp140 = spA0;
    sp148 = spA8;
    sp30 = temp_f1_2598;
    sp38 = temp_f0_2599;
    sp150 = spA0;
    sp158 = spA8;
    sp140 = temp_f1_2598;
    sp148 = temp_f0_2599;
    temp_r26_2465->AddNode(*((MKVector3 *) &sp150));
    InterpolateLinear(sp90, *((MKVector3 *) &sp150), 0.5f);
    sp120.unk10 = M2C_BITWISE(f64, sp90);
    sp138 = (f64) sp90.unk8;
    spC = 0.0f;
    sp70.GetMeasure((1.7f * temp_f28_2459) + var_f29_2568, (Matrix *) &this->unk110.unkA28, KDSpline_PositionMixer);
    InterpolateLinear(*((MKVector3 *) &sp70.unk10), *((MKVector3 *) &sp120.unk10), 0.9f);
    sp120.unk10 = M2C_BITWISE(f64, sp70.unk10);
    sp138 = sp88;
    temp_r26_2465->AddNode(*((MKVector3 *) &sp120.unk10));
    sp8 = 0.0f;
    sp50.GetMeasure((2.5f * temp_f28_2459) + var_f29_2568, (Matrix *) &this->unk110.unkA28, KDSpline_PositionMixer);
    InterpolateLinear(*((MKVector3 *) &sp50.unk10), *((MKVector3 *) &sp140), 0.75f);
    sp120.unk10 = M2C_BITWISE(f64, sp50.unk10);
    sp138 = sp68;
    temp_r26_2465->AddNode(*((MKVector3 *) &sp120.unk10));
    temp_r26_2465->AddNode(*((MKVector3 *) &sp140));
    temp_r24_2667 = this->unkC18->AddNode(*((MKVector3 *) &sp150));
    sp28 = 0.0f;
    sp40.GetMeasure(arg3, (Matrix *) &this->unk110.unkA28, KDSpline_PositionMixer);
    var_f26_2679 = temp_f31_2566;
    temp_r23_2680 = this->unkC18->AddNode(*((MKVector3 *) &sp40));
    if (temp_f31_2566 < 0.0f) {
        var_f26_2679 = temp_f31_2566 + 1.0f;
    }
    var_f28_2687 = 0.0f;
    if (arg0 > 3) {
        var_f28_2687 = 1.0f;
    }
    temp_r30_2504->AddEdges(temp_r25_2509, temp_r27_2450, 0.0f, 1.0f, 1, 1U, 0U, 2U);
    temp_r30_2504->AddEdges(temp_r24_2667, temp_r26_2465, 1.0f, 0.0f, 2, 1U, 0U, 2U);
    temp_r30_2504->AddEdges(temp_r23_2680, (KDUniformSpline *) temp_r31_2475, arg4, var_f28_2687, 1, 0U, 0U, 4U);
    var_r8_2722 = 0;
    if (arg0 == 0) {
        var_r8_2722 = 1;
    }
    temp_r25_2509->AddEdges(temp_r24_2667, (KDUniformSpline *) &this->unk110.unkA28, temp_f30_2477, var_f26_2679, 2, 1U, var_r8_2722, 0U);
    if ((u32) arg0 <= 6U) {
        switch (arg0) {
        case 0:
            temp_r30_2504->AddEdges(this->unkC18->unkC, (KDUniformSpline *) temp_r31_2475, arg4, 0.5f, 3, 1U, 0U, 1U);
            return;
        case 2:
            temp_r30_2504->AddEdges(this->unkC18->unk8, (KDUniformSpline *) temp_r31_2475, arg4, 0.5f, 3, 1U, 0U, 1U);
            return;
        case 4:
            temp_r30_2504->AddEdges(this->unkC18->unkC, (KDUniformSpline *) temp_r31_2475, arg4, 0.5f, 3, 1U, 0U, 1U);
            return;
        case 6:
            temp_r30_2504->AddEdges(this->unkC18->unk8, (KDUniformSpline *) temp_r31_2475, arg4, 0.5f, 3, 1U, 0U, 1U);
            break;
        }
    } else {
    case 1:
    case 3:
    case 5:
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA34'
void FireBoss::CreateInsideSplines() {
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;                                      /* compiler-managed */
    f64 sp268;                                      /* compiler-managed */
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp208;
    f64 sp1F8;
    KDUniformSpline sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f32 sp1B8;
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
    f64 sp118;
    f32 sp110;
    f32 sp100;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    FireBossGraphNode *temp_r4_3071;
    FireBossGraphNode *temp_r5_3057;
    Matrix *temp_r25_3200;
    Matrix *temp_r27_3093;
    f32 temp_f25_3080;
    f32 temp_f26_3082;
    f32 temp_f27_3083;
    f32 temp_f3_3205;
    f32 temp_f4_3203;
    f32 temp_f5_3201;
    f32 var_f21_3125;
    f32 var_f2_3191;
    f64 temp_f1_3130;
    f64 temp_f1_3136;
    f64 temp_f1_3140;
    s32 temp_r25_2857;
    s32 temp_r3_3159;
    s32 temp_r7_2955;
    s32 var_r0_3169;
    s32 var_r28_3078;
    s32 var_r29_3076;
    s32 var_r31_3072;
    void *temp_r26_3198;
    void *temp_r5_2957;
    void *temp_r5_2962;
    void *temp_r6_2851;
    void *temp_r6_2860;
    void *temp_r6_2951;

    temp_r6_2851 = this->unk110.unkA34;
    temp_r25_2857 = (s32) (this->unk110.unkA2C - 1) / 2;
    sp298 = M2C_FIELD(temp_r6_2851, f64 *, 0);
    temp_r6_2860 = temp_r6_2851 + (temp_r25_2857 << 5);
    sp2A0 = M2C_FIELD(temp_r6_2851, f64 *, 8);
    sp288 = M2C_FIELD(temp_r6_2860, f64 *, 0);
    sp290 = M2C_FIELD(temp_r6_2860, f64 *, 8);
    this->unk110.unkA3C.Init(4, 0U);
    this->unk110.unkA50.Init(4, 0U);
    this->unk110.unkA3C.AddNode(*((MKVector3 *) &sp298));
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    sp188 = spF8;
    sp100 = (f32) sp290 - (f32) sp2A0;
    sp190 = (f64) sp100;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f19 */);
    sp178 = spE8;
    spF0 = (f32) sp190 * 0.2f;
    sp180 = (f64) spF0;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    sp248 = spD8;
    spE0 = (f32) sp2A0 + (f32) sp180;
    sp250 = (f64) spE0;
    this->unk110.unkA3C.AddNode(*((MKVector3 *) &sp248));
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    sp168 = spC8;
    spD0 = (f32) sp290 - (f32) sp2A0;
    sp170 = (f64) spD0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
    sp158 = spB8;
    spC0 = (f32) sp170 * 0.8f;
    sp160 = (f64) spC0;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    sp238 = spA8;
    spB0 = (f32) sp2A0 + (f32) sp160;
    sp240 = (f64) spB0;
    this->unk110.unkA3C.AddNode(*((MKVector3 *) &sp238));
    this->unk110.unkA3C.AddNode(*((MKVector3 *) &sp288));
    temp_r6_2951 = this->unk110.unkA34;
    temp_r7_2955 = (s32) (this->unk110.unkA2C - 1) / 4;
    temp_r5_2957 = temp_r6_2951 + (temp_r7_2955 << 5);
    temp_r5_2962 = temp_r6_2951 + ((temp_r7_2955 + temp_r25_2857) << 5);
    sp298 = M2C_FIELD(temp_r5_2957, f64 *, 0);
    sp2A0 = M2C_FIELD(temp_r5_2957, f64 *, 8);
    sp288 = M2C_FIELD(temp_r5_2962, f64 *, 0);
    sp290 = M2C_FIELD(temp_r5_2962, f64 *, 8);
    this->unk110.unkA50.AddNode(*((MKVector3 *) &sp298));
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    sp148 = sp98;
    spA0 = (f32) sp290 - (f32) sp2A0;
    sp150 = (f64) spA0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
    sp138 = sp88;
    sp90 = (f32) sp150 * 0.2f;
    sp140 = (f64) sp90;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    sp228 = sp78;
    sp80 = (f32) sp2A0 + (f32) sp140;
    sp230 = (f64) sp80;
    this->unk110.unkA50.AddNode(*((MKVector3 *) &sp228));
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    sp128 = sp68;
    sp70 = (f32) sp290 - (f32) sp2A0;
    sp130 = (f64) sp70;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
    sp118 = sp58;
    sp60 = (f32) sp130 * 0.8f;
    sp120 = (f64) sp60;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    sp218 = sp48;
    sp50 = (f32) sp2A0 + (f32) sp120;
    sp220 = (f64) sp50;
    this->unk110.unkA50.AddNode(*((MKVector3 *) &sp218));
    this->unk110.unkA50.AddNode(*((MKVector3 *) &sp288));
    sp14 = 0.0f;
    sp208.GetMeasure(0.5f, (Matrix *) &this->unk110.unkA3C, KDSpline_PositionMixer);
    temp_r5_3057 = this->unkC18->unkC;
    temp_r5_3057->unk8 = sp208;
    temp_r5_3057->unk10 = sp210;
    sp10 = 0.0f;
    sp1F8.GetMeasure(0.5f, (Matrix *) &this->unk110.unkA50, KDSpline_PositionMixer);
    temp_r4_3071 = this->unkC18->unk8;
    var_r31_3072 = 0;
    var_r29_3076 = 0;
    var_r28_3078 = 0;
    temp_r4_3071->unk8 = sp1F8;
    temp_f25_3080 = up.unk4;
    temp_r4_3071->unk10 = sp200;
    temp_f26_3082 = up.unk8;
    temp_f27_3083 = up.unk0;
    do {
        sp1C = 0.0f;
        temp_r27_3093 = this + (var_r28_3078 + 0xB4C);
        sp1D8.GetMeasure(0.2f, temp_r27_3093, KDSpline_PositionMixer);
        sp20 = 0.0f;
        sp1D8.unk10.GetMeasure(0.8f, temp_r27_3093, KDSpline_PositionMixer);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp268 = sp108;
        sp110 = sp1F0 - sp1D8.unk8;
        unksp26C = 0.0f;
        sp270 = (f64) sp110;
        var_f21_3125 = ((f32) sp270 * (f32) sp270) + (((f32) sp268 * (f32) sp268) + (0.0f * 0.0f));
        if (var_f21_3125 > 0.000001f) {
            if (var_f21_3125 > 0.0f) {
                temp_f1_3130 = __frsqrte(var_f21_3125);
                temp_f1_3136 = 0.5 * temp_f1_3130 * -(((f64) var_f21_3125 * (temp_f1_3130 * temp_f1_3130)) - 3.0);
                temp_f1_3140 = 0.5 * temp_f1_3136 * -(((f64) var_f21_3125 * (temp_f1_3136 * temp_f1_3136)) - 3.0);
                var_f21_3125 = (f32) ((f64) var_f21_3125 * (0.5 * temp_f1_3140 * -(((f64) var_f21_3125 * (temp_f1_3140 * temp_f1_3140)) - 3.0)));
            } else if (var_f21_3125 < M2C_BITWISE(f32, 0.0)) {
                var_f21_3125 = __float_nan;
            } else {
                sp8 = var_f21_3125;
                temp_r3_3159 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_3159) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3169 = 1;
                    } else {
                        var_r0_3169 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3169 = 5;
                    } else {
                        var_r0_3169 = 3;
                    }
                    break;
                default:
                    var_r0_3169 = 4;
                    break;
                }
                if (var_r0_3169 == 1) {
                    var_f21_3125 = __float_nan;
                }
            }
            var_f2_3191 = 1.0f / var_f21_3125;
        } else {
            var_f2_3191 = 0.0f;
            var_f21_3125 = 0.0f;
        }
        temp_r26_3198 = this + var_r29_3076;
        temp_r25_3200 = temp_r26_3198 + 0xC70;
        temp_f5_3201 = (f32) sp268 * var_f2_3191;
        temp_f4_3203 = unksp26C * var_f2_3191;
        temp_f3_3205 = (f32) sp270 * var_f2_3191;
        sp268 = temp_f5_3201;
        unksp26C = temp_f4_3203;
        sp270 = temp_f3_3205;
        sp40 = (temp_f27_3083 * temp_f4_3203) - (temp_f25_3080 * temp_f5_3201);
        sp38 = (temp_f25_3080 * temp_f3_3205) - (temp_f26_3082 * temp_f4_3203);
        sp3C = (temp_f26_3082 * temp_f5_3201) - (temp_f27_3083 * temp_f3_3205);
        sp1D0 = (f64) sp40;
        sp1C8 = (f64) sp38;
        sp278 = (f64) sp38;
        sp280 = (f64) sp40;
        temp_r25_3200->SetIdentity();
        spC = 0.0f;
        sp1B8.GetMeasure(0.5f, temp_r27_3093, KDSpline_PositionMixer);
        M2C_FIELD(temp_r26_3198, f32 *, 0xCA0) = sp1B8;
        M2C_FIELD(temp_r26_3198, f32 *, 0xCA4) = sp1BC;
        M2C_FIELD(temp_r26_3198, f32 *, 0xCA8) = sp1C0;
        M2C_FIELD(temp_r26_3198, f32 *, 0xCAC) = 1.0f;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC70) = (f32) sp278;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC74) = unksp27C;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC78) = (f32) sp280;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC7C) = 0.0f;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC80) = temp_f27_3083;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC84) = temp_f25_3080;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC88) = temp_f26_3082;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC8C) = 0.0f;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC90) = sp268;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC94) = unksp26C;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC98) = sp270;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC9C) = 0.0f;
        temp_r25_3200->Inverse(temp_r25_3200);
        sp18 = 0.0f;
        sp1A8.GetMeasure(0.5f, temp_r27_3093, KDSpline_PositionMixer);
        var_r31_3072 += 1;
        sp258 = sp1A8;
        var_r29_3076 += 0x60;
        var_r28_3078 += 0x14;
        sp260 = sp1B0;
        sp28 = M2C_FIELD(temp_r26_3198, f32 *, 0xCA0) + (((f32) sp260 * M2C_FIELD(temp_r26_3198, f32 *, 0xC90)) + (((f32) sp258 * M2C_FIELD(temp_r26_3198, f32 *, 0xC70)) + (unksp25C * M2C_FIELD(temp_r26_3198, f32 *, 0xC80))));
        sp2C = M2C_FIELD(temp_r26_3198, f32 *, 0xCA4) + (((f32) sp260 * M2C_FIELD(temp_r26_3198, f32 *, 0xC94)) + (((f32) sp258 * M2C_FIELD(temp_r26_3198, f32 *, 0xC74)) + (unksp25C * M2C_FIELD(temp_r26_3198, f32 *, 0xC84))));
        sp30 = M2C_FIELD(temp_r26_3198, f32 *, 0xCA8) + (((f32) sp260 * M2C_FIELD(temp_r26_3198, f32 *, 0xC98)) + (((f32) sp258 * M2C_FIELD(temp_r26_3198, f32 *, 0xC78)) + (unksp25C * M2C_FIELD(temp_r26_3198, f32 *, 0xC88))));
        sp258 = (f64) sp28;
        sp260 = (f64) sp30;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC50) = (f32) ((f32) sp258 - 300.0f);
        M2C_FIELD(temp_r26_3198, f32 *, 0xC54) = (f32) (unksp25C - 500.0f);
        M2C_FIELD(temp_r26_3198, f32 *, 0xC58) = (f32) -((0.5f * var_f21_3125) - (f32) sp260);
        M2C_FIELD(temp_r26_3198, f32 *, 0xC60) = 600.0f;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC64) = 1000.0f;
        sp198 = (f64) sp28;
        sp1A0 = (f64) sp30;
        M2C_FIELD(temp_r26_3198, f32 *, 0xC68) = var_f21_3125;
    } while (var_r31_3072 < 2);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA28'
void FireBoss::CreateOutsideSpline() {
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    M2C_UNK spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    M2C_UNK sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f28_3433;
    s32 var_r30_3436;

    this->unk110.unkA28.Init(0x21, 0U);
    sp68 = 152.116f;
    sp6C = 65.413f;
    sp70 = -753.277f;
    spF8 = (f64) sp68;
    sp100 = (f64) sp70;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    sp50 = -730.638f;
    sp60 = (f32) sp100 * 100.0f;
    sp48 = 171.801f;
    sp4C = 65.413f;
    sp128 = sp58;
    spD8 = (f64) sp48;
    sp130 = (f64) sp60;
    spE0 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    spE8 = sp38;
    sp40 = (f32) spE0 * 100.0f;
    spF0 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp118 = sp28;
    sp30 = (f32) spF0 - (f32) sp130;
    unksp11C = 0.0f;
    sp120 = (f64) sp30;
    temp_f28_3433 = KDMath_GetYaw(*((MKVector3 *) &sp118));
    var_r30_3436 = 0;
    do {
        KDMath_GetDirection((-0.19634955f * (f32) var_r30_3436) + temp_f28_3433);
        spB8.operator*(3000.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spC8 = sp18;
        sp20 = (f32) sp130 + spB8.unk8;
        sp108 = sp18;
        spD0 = (f64) sp20;
        sp110 = (f64) sp20;
        this->unk110.unkA28.AddNode(*((MKVector3 *) &sp108));
        var_r30_3436 += 1;
    } while (var_r30_3436 < 0x20);
    KDMath_GetDirection(temp_f28_3433);
    sp88.operator*(3000.0f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp98 = sp8;
    sp10 = (f32) sp130 + sp88.unk8;
    sp108 = sp8;
    spA0 = (f64) sp10;
    sp110 = (f64) sp10;
    this->unk110.unkA28.AddNode(*((MKVector3 *) &sp108));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk92C'
s32 FireBoss::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;
    void **temp_r3_3518;

    temp_r3_3518 = this->unk110.unk92C;
    if (M2C_FIELD(*temp_r3_3518, u8 (**)(void **, M2C_UNK), 0x3C)(temp_r3_3518, 0x71) != 0) {
        MKModel_CalculateRefPointWorldPosition(this->unkD10.unk4, this->unkD10.unk220, arg1);
    } else {
        MKVector(0.0f, 0.5f * GetCollisionHeight(), 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(arg1, f64 *, 0) = sp8;
        sp10 = this->unk110.unk480 + sp20;
        sp28 = sp8;
        sp30 = (f64) sp10;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk92C'
s32 FireBoss::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;
    void **temp_r3_3576;

    temp_r3_3576 = this->unk110.unk92C;
    if (M2C_FIELD(*temp_r3_3576, u8 (**)(void **, M2C_UNK), 0x3C)(temp_r3_3576, 0x71) != 0) {
        MKModel_CalculateRefPointWorldPosition(this->unkD10.unk4, this->unkD10.unk220, arg1);
    } else {
        MKVector(0.0f, 0.5f * GetCollisionHeight(), 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(arg1, f64 *, 0) = sp8;
        sp10 = this->unk110.unk480 + sp20;
        sp28 = sp8;
        sp30 = (f64) sp10;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    }
    return 1;
}
#endif

#if 0 // DRAFT: identifier 'FireBoss::GetCharacterName()' redeclared
s32 FireBoss::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x324);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkF64'
void FireBoss::UpdateMovementCustom() {
    FireBossDriver *temp_r3_3662;
    FireBossDriver *temp_r3_3672;
    FireBossDriver *temp_r3_3677;
    FireBossDriver *temp_r5_3646;
    f64 temp_f1_3673;
    f64 temp_f2_3656;
    f64 temp_f3_3655;

    UpdateRotation();
    UpdateModel();
    temp_r5_3646 = this->unkF64;
    M2C_FIELD(temp_r5_3646, f64 *, 0xE0) = (f64) M2C_FIELD(this, f64 *, 0xC0);
    M2C_FIELD(temp_r5_3646, f64 *, 0xE8) = (f64) M2C_FIELD(this, f64 *, 0xC8);
    temp_f3_3655 = M2C_FIELD(temp_r5_3646, f64 *, 0xE0);
    temp_f2_3656 = M2C_FIELD(temp_r5_3646, f64 *, 0xE8);
    M2C_FIELD(temp_r5_3646, f64 *, 0xC0) = temp_f3_3655;
    M2C_FIELD(temp_r5_3646, f64 *, 0xC8) = temp_f2_3656;
    temp_r5_3646->unk110.unk5A5 |= 0x40;
    temp_r3_3662 = this->unkF64;
    M2C_FIELD(temp_r3_3662, f64 *, 0xF0) = (f64) M2C_FIELD(&up, f64 *, 0);
    M2C_FIELD(temp_r3_3662, f64 *, 0xF8) = (f64) M2C_FIELD(&up, f64 *, 8);
    M2C_FIELD(temp_r3_3662, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r3_3662, f64 *, 0xF0);
    M2C_FIELD(temp_r3_3662, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r3_3662, f64 *, 0xF8);
    temp_r3_3662->unk110.unk5A5 |= 0x40;
    temp_r3_3672 = this->unkF64;
    temp_f1_3673 = this->unk110.unk478;
    temp_r3_3672->unk110.unk478 = temp_f1_3673;
    M2C_FIELD(temp_r3_3672, f64 *, 0x590) = (f64) M2C_FIELD(this, f64 *, 0x590);
    temp_r3_3677 = this->unkF64;
    temp_r3_3677->UpdateModel(1, temp_r5_3646, temp_f1_3673, temp_f2_3656, temp_f3_3655);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkFCC'
void FireBoss::Message(MKMessage *arg0) {
    EnemyHudData sp18;
    f64 sp10;
    f64 sp8;
    Projectile *temp_r3_3950;
    f32 temp_f0_3858;
    f32 temp_f31_3790;
    f32 temp_f3_3871;
    f32 temp_f4_3868;
    f32 temp_f5_3864;
    s32 temp_r0_3711;
    s32 temp_r0_3740;
    u8 var_r5_3814;
    u8 var_r5_3920;
    void **temp_r3_3805;
    void **temp_r3_3880;
    void **temp_r3_3911;
    void **var_r4_3951;
    void *temp_r0_3960;
    void *temp_r29_3804;
    void *temp_r3_3844;
    void *temp_r3_3854;
    void *temp_r3_3893;
    void *temp_r4_3813;
    void *temp_r4_3919;

    this->unkFCC.Message(arg0);
    this->unkFF4.Message(arg0);
    this->unk101C.Message(arg0);
    this->unk1044.Message(arg0);
    temp_r0_3711 = arg0->unk0;
    switch (temp_r0_3711) {                         /* switch 1; irregular */
    case 0xB5:                                      /* switch 1 */
        Enable();
    default:                                        /* switch 1 */
block_60:
        Enemy::Message(arg0);
        return;
    case 0x15:                                      /* switch 1 */
        temp_r0_3740 = this->unk110.unkA00;
        switch (temp_r0_3740) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            this->unk1084.Send(NULL);
            GetMaxHealth();
            SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            break;
        case 1:                                     /* switch 2 */
            this->unk1084.Send(NULL);
            GetMaxHealth();
            SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            break;
        case 2:                                     /* switch 2 */
            this->unk1084.Send(NULL);
            GetMaxHealth();
            SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            break;
        case 3:                                     /* switch 2 */
            this->unk1084.Send(NULL);
            GetMaxHealth();
            SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            break;
        }
        sp18.EnemyHudData();
        temp_f31_3790 = this->unk110.unk9B8;
        GetMaxHealth();
        sp18.Init((Enemy *) this, temp_f31_3790, M2C_ERROR(/* Read from unset register $f1 */));
        EnemyHud_Modified(sp18);
        goto block_60;
    case 0x4:                                       /* switch 1 */
        temp_r29_3804 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
        temp_r3_3805 = this->unk110.unk930;
        if (M2C_FIELD(*temp_r3_3805, u8 (**)(void **, M2C_UNK), 0x3C)(temp_r3_3805, 0x71) != 0) {
            temp_r4_3813 = this->unk110.unk940;
            var_r5_3814 = 0;
            if ((temp_r4_3813 != NULL) && ((u32) M2C_FIELD(temp_r4_3813, u32 *, 0x40) == (u32) this->unk110.unk520->unk20)) {
                var_r5_3814 = 1;
            }
            if (var_r5_3814 == 0) {
                this->unkC45 = 1;
                this->unkC48 += M2C_FIELD(temp_r29_3804, f32 *, 0x20);
            } else {
                goto block_31;
            }
        } else {
block_31:
            M2C_FIELD(temp_r29_3804, f32 *, 0x20) = (f32) (M2C_FIELD(temp_r29_3804, f32 *, 0x20) * 0.25f);
        }
        this->unkC40 = 1;
        goto block_60;
    case 0x1:                                       /* switch 1 */
        temp_r3_3844 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
        if ((void **) M2C_FIELD(temp_r3_3844, void ***, 8) != this) {
            temp_r3_3854 = this->unk8;
            temp_f0_3858 = M2C_FIELD(temp_r3_3844, f32 *, 0x20) + GetCollisionRadius();
            sp8 = M2C_FIELD(temp_r3_3854, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r3_3854, f64 *, 0x38);
            temp_f5_3864 = unkspC - M2C_FIELD(temp_r3_3844, f32 *, 0x14);
            temp_f4_3868 = (f32) sp8 - M2C_FIELD(temp_r3_3844, f32 *, 0x10);
            temp_f3_3871 = (f32) sp10 - M2C_FIELD(temp_r3_3844, f32 *, 0x18);
            if (!(((temp_f3_3871 * temp_f3_3871) + ((temp_f4_3868 * temp_f4_3868) + (temp_f5_3864 * temp_f5_3864))) < (temp_f0_3858 * temp_f0_3858))) {
                return;
            }
            temp_r3_3880 = M2C_FIELD(temp_r3_3844, void ***, 8);
            if (temp_r3_3880 != NULL) {
                if (!(M2C_FIELD(*temp_r3_3880, s32 *, 0xC) & 0x40)) {
                    return;
                }
            case 0x5:                               /* switch 1 */
                if ((s32) this->unk110.unkA00 <= 3) {
                    temp_r3_3893 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
                    if ((s32) M2C_FIELD(temp_r3_3893, s32 *, 0x38) == 3) {
                        if ((s32) M2C_FIELD(temp_r3_3893, s32 *, 0x48) != 0) {
                            M2C_FIELD(temp_r3_3893, f32 *, 0x34) = 0.1f;
                            goto block_44;
                        }
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if (M2C_FIELD(temp_r3_3893, f32 *, 0x34) != 0.0f) {
                            goto block_44;
                        }
                    } else {
block_44:
                        temp_r3_3911 = this->unk110.unk930;
                        if (M2C_FIELD(*temp_r3_3911, u8 (**)(void **, M2C_UNK), 0x3C)(temp_r3_3911, 0x71) != 0) {
                            temp_r4_3919 = this->unk110.unk940;
                            var_r5_3920 = 0;
                            if ((temp_r4_3919 != NULL) && ((u32) M2C_FIELD(temp_r4_3919, u32 *, 0x40) == (u32) this->unk110.unk520->unk20)) {
                                var_r5_3920 = 1;
                            }
                            if (var_r5_3920 == 0) {
                                this->unkC45 = 1;
                                this->unkC48 += M2C_FIELD(temp_r3_3893, f32 *, 0x34);
                            } else {
                                goto block_50;
                            }
                        } else {
block_50:
                            M2C_FIELD(temp_r3_3893, f32 *, 0x34) = (f32) (M2C_FIELD(temp_r3_3893, f32 *, 0x34) * 0.25f);
                        }
                        this->unkC40 = 1;
                        goto block_60;
                    }
                }
            }
        }
        break;
    case 0x4E:                                      /* switch 1 */
        temp_r3_3950 = checked_cast<Projectile *, MKProp>((MKProp *) arg0->unk4);
        var_r4_3951 = this->unk1088;
loop_56:
        temp_r0_3960 = *var_r4_3951;
        if (temp_r0_3960 == NULL) {
            var_r4_3951 = NULL;
        } else if (temp_r0_3960 == temp_r3_3950) {

        } else {
            var_r4_3951 += 4;
            goto loop_56;
        }
        if (var_r4_3951 != NULL) {
            this->unk1088.Destroy(temp_r3_3950);
        }
        goto block_60;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void FireBoss::Draw() {
    s32 var_r29_4006;
    s32 var_r31_4007;
    void *temp_r3_3993;
    void *temp_r3_4023;

    temp_r3_3993 = checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, *M2C_FIELD((M2C_FIELD(temp_r3_3993, s32 *, 0x3DC) + (this->unk108C * 0xC)), s32 **, 4), 0U, 1U);
    var_r29_4006 = 1;
    var_r31_4007 = 4;
loop_2:
    temp_r3_4023 = M2C_FIELD(temp_r3_3993, s32 *, 0x3DC) + (this->unk108C * 0xC);
    if (var_r29_4006 < (s32) M2C_FIELD(temp_r3_4023, s32 *, 0)) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, *(M2C_FIELD(temp_r3_4023, s32 *, 4) + var_r31_4007), 0U, 1U);
        var_r29_4006 += 1;
        var_r31_4007 += 4;
        goto loop_2;
    }
    if (this->unk110.unk640.Draw(NULL) == 0) {
        MKModel_Draw(this->unk4, NULL);
    }
    this->unkD10.Draw();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk928'
void FireBoss::UpdatePhrasesAndSounds() {
    EnemyDescriptor *temp_r3_4060;
    f32 temp_f1_4162;
    f32 temp_f30_4071;
    f32 temp_f30_4086;
    f32 temp_f31_4067;
    f32 temp_f31_4123;
    s32 var_r29_4092;
    s32 var_r30_4093;

    temp_r3_4060 = this->unk110.unk928;
    temp_f31_4067 = this->unk110.unk9B8;
    temp_f30_4071 = (f32) temp_r3_4060->unk11C * this->unk110.unk928->GetEnemySetting((EnemySettingType) 0);
    temp_f30_4086 = ((temp_f30_4071 - ((f32) (this->unk110.unk9D8 + 1) * temp_r3_4060->GetEnemySetting((EnemySettingType) 0))) + temp_f31_4067) / temp_f30_4071;
    if (temp_f30_4086 > this->unk107C) {
        this->unk107C = temp_f30_4086;
    }
    var_r29_4092 = 0;
    var_r30_4093 = 0;
loop_3:
    if ((temp_f30_4086 != 0.0f) && (*(checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_4093 + 0x2D4)) != 0.0f) && (this->unk107C > *(checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_4093 + 0x2D4))) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f30_4086 == *(checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_4093 + 0x2D4))) != 0))) {
        temp_f31_4123 = 2.0f * M2C_FIELD(checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x3D4);
        this->unk1080 = MKRand_Float(&gViewSeed, M2C_FIELD(checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x3D4), temp_f31_4123);
        this->unk1078 = checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_4093 + 0x2B4);
    } else {
        var_r29_4092 += 1;
        var_r30_4093 += 0x24;
        if (var_r29_4092 < 8) {
            goto loop_3;
        }
    }
    if ((this->unk1080 < 0.0f) && ((s8 *) this->unk1078 != NULL) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        this->unk1070 = PhrasePlayer_PlayEvent(this->unk1078);
        this->unk1080 = 0.0f;
        this->unk1078 = NULL;
    }
    this->unk107C = temp_f30_4086;
    temp_f1_4162 = this->unk1080;
    if (temp_f1_4162 > 0.0f) {
        this->unk1080 = temp_f1_4162 - gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA24'
void FireBoss::Update() {
    s32 sp8;
    f32 temp_f1_4257;
    f32 temp_f1_4268;
    f32 temp_f2_4213;
    f32 var_f0_4256;
    f32 var_f0_4267;
    u32 temp_r31_4294;
    void *temp_r3_4291;

    this->unk110.unkA24 = 0.0f;
    Enemy::Update();
    sp8 = 1;
    this->unk101C.Update(GS_TrainEngineBreakLP, 1U, this->unkFC9, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    this->unkFF4.Update(GS_TrainJets, 1U, this->unkFCB, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f2_4213 = this->unk110.unkA10;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f2_4213 == 100.0f) {
        KDSound_SetPitch(this->unk1044, 0.5f);
    } else {
        KDSound_SetPitch(this->unk1044, (0.000416f * temp_f2_4213) + 0.5f);
    }
    sp8 = 1;
    this->unk1044.Update(GS_TrainBossEngineLP, 1U, this->unkFCA, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (this->unk110.unk9B8 > 0.0f) {
        UpdatePhrasesAndSounds();
    }
    this->unk110.unkA10 += this->unk110.unkA0C * gUpdateTimeDelta;
    if (this->unk110.unkA0C > 0.0f) {
        var_f0_4256 = this->unk110.unkA10;
        temp_f1_4257 = this->unk110.unkA14;
        if (var_f0_4256 < temp_f1_4257) {

        } else {
            var_f0_4256 = temp_f1_4257;
        }
        this->unk110.unkA10 = var_f0_4256;
    } else {
        var_f0_4267 = this->unk110.unkA10;
        temp_f1_4268 = this->unk110.unkA14;
        if (var_f0_4267 > temp_f1_4268) {

        } else {
            var_f0_4267 = temp_f1_4268;
        }
        this->unk110.unkA10 = var_f0_4267;
    }
    HasRunOverSpyro();
    CheckFlameThrowerHit();
    if ((u8) this->unkC1C->unk1D != 1) {
        this->unkC43 = 0;
    }
    if ((u8) this->unkFC8 != 0) {
        temp_r3_4291 = this->unkF68;
        if (temp_r3_4291 != NULL) {
            temp_r31_4294 = M2C_FIELD(temp_r3_4291, u32 *, 0x84);
            if (temp_r31_4294 != -1U) {
                this->unkF70.Animate(MKModel_GetAnimation(this->unk4), (s32) temp_r31_4294, NULL);
                if (this->unkF70.CheckEvent(0) != 0) {
                    LaunchFireball();
                }
                if (this->unkF70.unk2C & 1) {
                    this->unkFC8 = 0;
                }
            }
        }
    }
    this->unkD10.unk234 = this->unk110.unkA14;
    this->unkD10.unk230 = this->unk110.unkA10;
    this->unkD10.Update();
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA00'
void FireBoss::SetDefaults() {
    Enemy::SetDefaults();
    this->unk110.unkA00 = 0;
    this->unk110.unk9D8 = this->unk110.unkA00;
    M2C_FIELD(this, s32 *, 0xB14) = 0;
    this->unk110.unkA08 = 0.0f;
    this->unk110.unkA0C = 0.0f;
    this->unk110.unkA10 = 0.0f;
    this->unk110.unkA14 = 0.0f;
    this->unk110.unkA24 = 0.0f;
    this->unkC41 = 0;
    this->unkC42 = 0;
    this->unkC43 = 0;
    this->unkC44 = 1;
    this->unkC45 = 0;
    this->unkFCA = 1;
    this->unkFCB = 1;
    this->unkC40 = 0;
    this->unkC38 = 1;
    this->unkC3C = 1;
    this->unkD10.Reset();
    this->unkD10.unk10 = 0.0f;
    this->unkF50 = 0.0f;
    this->unkF54 = 0.0f;
    this->unkF58 = 0.0f;
    this->unkF5C = 0.0f;
    this->unkF60 = 0.0f;
    this->unkC48 = 0.0f;
    this->unkFC8 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkD10'
void FireBoss::Resolve() {
    void **var_r0_4403;
    void **var_r5_4408;
    void *temp_r3_4427;
    void *temp_r4_4414;

    Enemy::Resolve();
    this->unkD10.Resolve();
    this->unk110.unk930 = this->unk110.unk92C;
    if ((u32) M2C_FIELD(checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0x228) != 0U) {
        var_r0_4403 = *M2C_FIELD(checked_cast<FireBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void ****, 0x228);
    } else {
        var_r0_4403 = NULL;
    }
    var_r5_4408 = var_r0_4403;
loop_9:
    if ((var_r5_4408 == NULL) || (temp_r3_4427 = *var_r5_4408, ((temp_r3_4427 == NULL) != 0))) {
        return;
    }
    if (M2C_FIELD(temp_r3_4427, s32 *, 0x38) & 2) {
        temp_r4_4414 = M2C_FIELD(temp_r3_4427, void **, 0);
        if ((temp_r4_4414 != NULL) && ((s32) M2C_FIELD(temp_r4_4414, s32 *, 0x68) == 0x50)) {
            this->unkF68 = temp_r3_4427;
            return;
        }
    }
    var_r5_4408 += 4;
    goto loop_9;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkD10'
void FireBoss::LoadDone() {
    FireBossDriver *temp_r3_4511;
    MKModel *temp_r31_4496;

    Enemy::LoadDone();
    this->unkD10.Init((Matrix *) this->unk8, this->unk4, this->unk110.unk520);
    CreateOutsideSpline();
    CreateInsideSplines();
    CreateTurnSplines(0, 1, 0, 0.0f, 0.2f);
    CreateTurnSplines(2, 3, 1, 0.25f, 0.2f);
    CreateTurnSplines(4, 5, 0, 0.5f, 0.8f);
    CreateTurnSplines(6, 7, 1, 0.75f, 0.8f);
    FinaliseGraph();
    this->unk110.unkA18 = 0.0f;
    this->unk110.unkA1C = 1.0f;
    this->unkC14 = NULL;
    this->unk110.unkA20 = 0.0f;
    this->unkC1C = NULL;
    this->unkC20 = NULL;
    this->unkC24 = 0;
    temp_r31_4496 = this->unk4;
    this->unkF70.Init(MKModel_GetName(temp_r31_4496), temp_r31_4496);
    this->unkFC8 = 0;
    this->unkF64 = checked_cast<FireBossDriver *, MKProp>(gMK->CreateProp("FireBossDriver"));
    temp_r3_4511 = this->unkF64;
    temp_r3_4511->Disable();
    Disable();
    SetCurrentEdge(this->unkC18->GetEdge((KDUniformSpline *) &this->unk110.unkA28, 0.0f, 1), 0.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1084'
s32 FireBoss::LoadLine(MKIniLine *arg0) {
    s32 var_r31_4546;

    var_r31_4546 = 0;
    if ((Enemy::LoadLine(arg0) != 0) || (this->unk1084.LoadLine(arg0, "OnReset") != 0)) {
        var_r31_4546 = 1;
    }
    return var_r31_4546;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkF70'
void FireBoss::Deinit() {
    FireBossDirectedGraph *temp_r31_4633;
    MKHeap *temp_r3_4616;
    MKHeap *temp_r3_4634;
    s32 var_r30_4585;
    s32 var_r31_4586;
    void **temp_r31_4612;
    void **temp_r3_4607;
    void **var_r4_4595;
    void *temp_r3_4602;

    this->unkF70.Deinit();
    this->unk110.unkA28.Deinit();
    this->unk110.unkA3C.Deinit();
    this->unk110.unkA50.Deinit();
    var_r30_4585 = 0;
    var_r31_4586 = 0;
    do {
        ((KDUniformSpline *) (this + (var_r31_4586 + 0xB74)))->Deinit();
        var_r30_4585 += 1;
        var_r31_4586 += 0x14;
    } while (var_r30_4585 < 8);
    var_r4_4595 = this->unk1088;
loop_4:
    temp_r3_4602 = *var_r4_4595;
    if (temp_r3_4602 != NULL) {
        M2C_FIELD(temp_r3_4602, s32 *, 0x130) = 0;
        var_r4_4595 += 4;
        goto loop_4;
    }
    do {
        temp_r3_4607 = this->unk1088 - 4;
        this->unk1088 = temp_r3_4607;
    } while ((void *) *temp_r3_4607 != NULL);
    temp_r31_4612 = this->unk1088;
    if (temp_r31_4612 != &gEmptyPtrList) {
        temp_r3_4616 = temp_r3_4607->Current();
        if (temp_r3_4616 != NULL) {
            ((MKHeap *) (temp_r3_4616->Current()))->Free(temp_r31_4612, NULL, 0);
        } else {
            free((MKHeap *) temp_r31_4612);
        }
    }
    this->unk1088 = NULL;
    this->unkC18->Deinit();
    temp_r31_4633 = this->unkC18;
    temp_r3_4634 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4634 != NULL) {
        ((MKHeap *) (temp_r3_4634->Current()))->Free(temp_r31_4633, NULL, 0);
    } else {
        free((MKHeap *) temp_r31_4633);
    }
    KDSound_Stop(&this->unkFCC);
    KDSound_Stop(&this->unkFF4);
    KDSound_Stop(&this->unk1044);
    KDSound_Stop(&this->unk101C);
    this->unkFC9 = 0;
    this->unkFCA = 0;
    this->unkFCB = 0;
    KDSound_Stop(&this->unk106C);
    PhrasePlayer_StopEvent(this->unk1070);
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FireBoss::Init() {
    FireBossGoal_Think *temp_r30_4685;
    MKHeap *temp_r3_4711;
    MKHeap *temp_r3_4729;
    MKHeap *var_r3_4718;
    MKHeap *var_r3_4736;
    s32 var_ctr_4749;
    void **temp_r3_4751;
    void **temp_r4_4756;

    Enemy::Init();
    operator new(0x54U, NULL, 0);
    temp_r30_4685 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r30_4685 != NULL) {
        temp_r30_4685->__vptr = &__vt__15Goal<8FireBoss>;
        temp_r30_4685->unk4 = 0;
        temp_r30_4685->unk8 = 1;
        temp_r30_4685->unk9 = 0;
        temp_r30_4685->unkC = 0;
        temp_r30_4685->__vptr = (struct __vt__15Goal<8FireBoss> *) &__vt__24CompositeGoal<8FireBoss>;
        temp_r30_4685->unk1C = 0;
        temp_r30_4685->unk18 = 0;
        temp_r30_4685->unk10 = 0;
        temp_r30_4685->unk14 = 0;
        temp_r30_4685->__vptr = &__vt;
    }
    temp_r30_4685->Init(this);
    this->unk110.unk92C = &temp_r30_4685->__vptr;
    temp_r3_4711 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4711 != NULL) {
        var_r3_4718 = ((MKHeap *) (temp_r3_4711->Current()))->Alloc(0x18, NULL, 0);
    } else {
        var_r3_4718 = malloc(0x18);
    }
    this->unkC18 = (FireBossDirectedGraph *) var_r3_4718;
    this->unkC18->Init();
    pGraph.unk0 = this->unkC18;
    temp_r3_4729 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4729 != NULL) {
        var_r3_4736 = ((MKHeap *) (temp_r3_4729->Current()))->Alloc(0x58, NULL, 0);
    } else {
        var_r3_4736 = malloc(0x58);
    }
    this->unk1088 = (void **) var_r3_4736;
    M2C_FIELD(this->unk1088, void **, 0) = NULL;
    var_ctr_4749 = 0x14;
    do {
        temp_r3_4751 = this->unk1088;
        this->unk1088 = temp_r3_4751 + 4;
        M2C_FIELD(temp_r3_4751, s32 *, 4) = 0xDEADBEEF;
        var_ctr_4749 -= 1;
    } while (var_ctr_4749 != 0);
    temp_r4_4756 = this->unk1088;
    this->unk1088 = temp_r4_4756 + 4;
    M2C_FIELD(temp_r4_4756, s32 *, 4) = 0;
    this->unkF64 = NULL;
    this->unkF68 = NULL;
    this->unkFCC.Init(0.25f, 0.25f);
    this->unkFF4.Init(0.25f, 0.25f);
    this->unk101C.Init(0.25f, 0.25f);
    this->unk1044.Init(0.25f, 0.25f);
    this->unkFC9 = 0;
    this->unkFCA = 1;
    this->unkFCB = 1;
    this->unkC40 = 0;
    this->unk106C = 0;
    this->unk1070 = 0;
    this->unk1074 = 0;
    this->unk1078 = NULL;
    this->unk107C = 0.0f;
    this->unk1080 = 0.0f;
    this->unk108C = 0;
    this->unk1084.Init();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void FireBossDescriptor::Deinit() {
    MKHeap *temp_r30_4816;
    MKHeap *temp_r30_4832;
    MKHeap *temp_r30_4852;
    MKHeap *temp_r3_4814;
    MKHeap *temp_r3_4817;
    MKHeap *temp_r3_4830;
    MKHeap *temp_r3_4833;
    MKHeap *temp_r3_4853;
    s32 var_r29_4810;
    s32 var_r31_4811;

    var_r29_4810 = 0;
    var_r31_4811 = 0;
loop_8:
    if (var_r29_4810 < (s32) this->unk3D8) {
        temp_r3_4814 = this->unk3DC;
        temp_r30_4816 = *(temp_r3_4814 + (var_r31_4811 + 4));
        temp_r3_4817 = temp_r3_4814->Current();
        if (temp_r3_4817 != NULL) {
            ((MKHeap *) (temp_r3_4817->Current()))->Free(temp_r30_4816, NULL, 0);
        } else {
            free(temp_r30_4816);
        }
        temp_r3_4830 = this->unk3DC;
        temp_r30_4832 = *(temp_r3_4830 + (var_r31_4811 + 8));
        temp_r3_4833 = temp_r3_4830->Current();
        if (temp_r3_4833 != NULL) {
            ((MKHeap *) (temp_r3_4833->Current()))->Free(temp_r30_4832, NULL, 0);
        } else {
            free(temp_r30_4832);
        }
        var_r29_4810 += 1;
        var_r31_4811 += 0xC;
        goto loop_8;
    }
    temp_r30_4852 = this->unk3DC;
    temp_r3_4853 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4853 != NULL) {
        ((MKHeap *) (temp_r3_4853->Current()))->Free(temp_r30_4852, NULL, 0);
    } else {
        free(temp_r30_4852);
    }
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal operand
void FireBossDescriptor::LoadDone() {
    s32 temp_r0_4889;
    s32 var_ctr_4887;
    s32 var_r28_4899;
    s32 var_r29_4895;
    s32 var_r30_4900;
    s32 var_r31_4896;
    s32 var_r3_4886;
    void *temp_r3_4917;

    EnemyDescriptor::LoadDone();
    var_r3_4886 = 0;
    var_ctr_4887 = 8;
    do {
        temp_r0_4889 = var_r3_4886 + 0x2D4;
        var_r3_4886 += 0x24;
        *(this + temp_r0_4889) = *(this + temp_r0_4889) / 100.0f;
        var_ctr_4887 -= 1;
    } while (var_ctr_4887 != 0);
    var_r29_4895 = 0;
    var_r31_4896 = 0;
loop_7:
    if (var_r29_4895 < (s32) this->unk3D8) {
        var_r28_4899 = 0;
        var_r30_4900 = 0;
loop_5:
        temp_r3_4917 = var_r31_4896 + this->unk3DC;
        if (var_r28_4899 < (s32) M2C_FIELD(temp_r3_4917, s32 *, 0)) {
            var_r28_4899 += 1;
            *(*(var_r31_4896 + &this->unk3DC->unk4) + var_r30_4900) = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, *(M2C_FIELD(temp_r3_4917, s32 *, 8) + var_r30_4900));
            var_r30_4900 += 4;
            goto loop_5;
        }
        var_r29_4895 += 1;
        var_r31_4896 += 0xC;
        goto loop_7;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_750'
s32 FireBossDescriptor::LoadLine(MKIniLine *arg0) {
    s8 sp3A;
    s8 sp30;
    M2C_UNK sp2C;
    s8 sp10;
    s8 *spC;
    s8 *sp8;
    MKHeap *temp_r3_5084;
    MKHeap *temp_r3_5116;
    MKHeap *temp_r3_5119;
    MKHeap *temp_r3_5135;
    MKHeap *temp_r3_5138;
    MKHeap *var_r3_5091;
    MKHeap *var_r3_5126;
    MKHeap *var_r3_5145;
    MKIniLine *var_r24_5158;
    MKIniLine *var_r28_4986;
    MKIniLine *var_r28_5102;
    s32 temp_r25_5083;
    s32 temp_r25_5118;
    s32 temp_r25_5137;
    s32 temp_r3_5080;
    s32 temp_r5_5049;
    s32 temp_ret_5006;
    s32 temp_ret_5046;
    s32 var_r26_5160;
    s32 var_r27_5104;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&lit_750 - 4) + 4, 0x20);
    M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&lit_751 - 4) + 4, 0x20);
    if (EnemyDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("HurtPhrases") != 0) {
        var_r28_4986 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r28_4986 != NULL) {
            strcpy(&sp30, var_r28_4986->GetFieldName());
            if (strnicmp("hurtPhrase", &sp30, 0xA) == 0) {
                strcpy(&sp10, &sp3A);
                temp_ret_5006 = atoi(&sp10);
                if (temp_ret_5006 <= 8) {
                    var_r28_4986->LoadString(Str_Printf("hurtPhrase%s", &sp10, M2C_BITWISE(f32, temp_ret_5006)), &spC, 0);
                    strcpy(this + (((atoi(&sp10) - 1) * 0x24) + 0x2B4), spC);
                }
            } else if (strnicmp("Percentage", &sp30, 0xA) == 0) {
                strcpy(&sp10, &sp3A);
                if (atoi(&sp10) <= 8) {
                    temp_ret_5046 = atoi(&sp10);
                    temp_r5_5049 = (temp_ret_5046 - 1) * 0x24;
                    var_r28_4986->LoadFloat(Str_Printf("percentage%s", &sp10, temp_r5_5049, M2C_BITWISE(f32, temp_ret_5046)), this + (temp_r5_5049 + 0x2D4), 0);
                }
            }
            var_r28_4986 = var_r28_4986->unkC->GetNextLine(var_r28_4986);
            goto loop_11;
        }
        return 1;
    }
    if (arg0->IsField("DamageStates") != 0) {
        temp_r3_5080 = arg0->GetNmbrOfSubLines();
        this->unk3D8 = temp_r3_5080;
        temp_r25_5083 = this->unk3D8 * 0xC;
        temp_r3_5084 = temp_r3_5080->Current();
        if (temp_r3_5084 != NULL) {
            var_r3_5091 = ((MKHeap *) (temp_r3_5084->Current()))->Alloc(temp_r25_5083, NULL, 0);
        } else {
            var_r3_5091 = malloc(temp_r25_5083);
        }
        this->unk3DC = var_r3_5091;
        var_r28_5102 = arg0->unkC->GetSubLine(arg0);
        var_r27_5104 = 0;
loop_31:
        if (var_r28_5102 != NULL) {
            if (var_r28_5102->IsField("state") != 0) {
                *(this->unk3DC + var_r27_5104) = var_r28_5102->GetNmbrOfSubLines();
                temp_r3_5116 = this->unk3DC;
                temp_r25_5118 = *(temp_r3_5116 + var_r27_5104) * 4;
                temp_r3_5119 = temp_r3_5116->Current();
                if (temp_r3_5119 != NULL) {
                    var_r3_5126 = ((MKHeap *) (temp_r3_5119->Current()))->Alloc(temp_r25_5118, NULL, 0);
                } else {
                    var_r3_5126 = malloc(temp_r25_5118);
                }
                *(this->unk3DC + (var_r27_5104 + 4)) = var_r3_5126;
                temp_r3_5135 = this->unk3DC;
                temp_r25_5137 = *(temp_r3_5135 + var_r27_5104) * 4;
                temp_r3_5138 = temp_r3_5135->Current();
                if (temp_r3_5138 != NULL) {
                    var_r3_5145 = ((MKHeap *) (temp_r3_5138->Current()))->Alloc(temp_r25_5137, NULL, 0);
                } else {
                    var_r3_5145 = malloc(temp_r25_5137);
                }
                *(this->unk3DC + (var_r27_5104 + 8)) = var_r3_5145;
                var_r24_5158 = var_r28_5102->unkC->GetSubLine(var_r28_5102);
                var_r26_5160 = 0;
loop_29:
                if (var_r24_5158 != NULL) {
                    if (var_r24_5158->LoadString("subObject", &sp8, 0) != 0) {
                        *(*(var_r27_5104 + &this->unk3DC->unk8) + var_r26_5160) = sp8;
                        var_r26_5160 += 4;
                    }
                    var_r24_5158 = var_r24_5158->unkC->GetNextLine(var_r24_5158);
                    goto loop_29;
                }
                var_r27_5104 += 0xC;
                var_r28_5102 = var_r28_5102->unkC->GetNextLine(var_r28_5102);
            }
            goto loop_31;
        }
    }
    return arg0->LoadFloat("phraseDelay", &this->unk3D4, 0);
}
#endif

#if 0 // DRAFT: illegal type
void FireBossDescriptor::Init() {
    s32 var_r28_5224;
    s32 var_r30_5219;
    void *temp_r29_5228;

    EnemyDescriptor::Init();
    var_r30_5219 = 0;
    this->unk1D4 = 0;
    var_r28_5224 = 0;
    this->unk3D4 = 1.0f;
    do {
        temp_r29_5228 = this + var_r30_5219;
        strcpy(temp_r29_5228 + 0x2B4, "");
        var_r28_5224 += 1;
        M2C_FIELD(temp_r29_5228, f32 *, 0x2D4) = 0.0f;
        var_r30_5219 += 0x24;
    } while (var_r28_5224 < 8);
    this->unk3D8 = 0;
    this->unk3DC = NULL;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<Projectile *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FireBossDriver *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FireBossDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

void Enemies_FireBoss_cpp::__sinit() {
    f32 temp_f0_5783;
    f64 temp_f1_5764;
    f64 temp_f1_5772;
    f64 temp_f3_5752;
    f64 temp_f4_5761;
    f64 temp_f4_5769;
    f64 temp_f8_5754;

    temp_f3_5752 = __frsqrte(2014000.0);
    temp_f8_5754 = __frsqrte(380000.0);
    temp_f4_5761 = 0.5 * temp_f3_5752 * -((2014000.0 * (temp_f3_5752 * temp_f3_5752)) - 3.0);
    temp_f1_5764 = 0.5 * temp_f8_5754 * -((380000.0 * (temp_f8_5754 * temp_f8_5754)) - 3.0);
    temp_f4_5769 = 0.5 * temp_f4_5761 * -((2014000.0 * (temp_f4_5761 * temp_f4_5761)) - 3.0);
    temp_f1_5772 = 0.5 * temp_f1_5764 * -((380000.0 * (temp_f1_5764 * temp_f1_5764)) - 3.0);
    temp_f0_5783 = (f32) (380000.0 * (0.5 * temp_f1_5772 * -((380000.0 * (temp_f1_5772 * temp_f1_5772)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_5769 * -((2014000.0 * (temp_f4_5769 * temp_f4_5769)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_5783;
}

#if 0 // DRAFT: undefined identifier 'lit_1720lit_GetAimPoint'
void FireBoss::lit_1720lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((FireBoss *) (this - 0x6B8))->FireBoss::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_1720lit_GetLookToPoint'
void FireBoss::lit_1720lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((FireBoss *) (this - 0x6B8))->FireBoss::GetLookToPoint(arg0, arg1);
}
#endif
