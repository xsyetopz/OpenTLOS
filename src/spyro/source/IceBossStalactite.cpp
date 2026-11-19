#include "spyro/source/IceBossStalactite.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/GameData.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/WaterDripPS.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(IceBossStalactite ***);                /* extern */
IceBossStalactite ***malloc(s32);                   /* extern */
extern s32 GS_ElecBossCrystalFly;
extern s32 GS_ElecBossCrystalForm;
extern s32 GS_ElecBossCrystalSmash;
extern s32 GS_IceBossIceDrop;
extern s32 GS_IceBossIceEmbed;
extern s32 GS_IceBossIceForm;
extern s32 GS_IceBossIceMelt;
extern s32 GS_SpyroSpikeBurn;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
static s32 lit_644 = 0;

static u8 lit_683 = 1;

#if 0 // DRAFT: undefined identifier 'sp8'
void IceBossStalactiteSpawner::GetSpawnPoint(const MKVector3 &arg0, int arg1) {
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp10;
    s32 temp_r7_51;

    temp_r7_51 = (s32) M2C_ERROR(/* Read from unset register $r6 */) / 5;
    KDMath_GetDirection(NormaliseAngle(M2C_FIELD(&arg0, f32 *, 0x1C) + (1.2566371f * (f32) (M2C_ERROR(/* Read from unset register $r6 */) - (temp_r7_51 * 5)))));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    sp38 = sp8;
    sp10 = sp30 * ((500.0f * (f32) temp_r7_51) + 500.0f);
    sp40 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk0 = sp18;
    sp20 = M2C_FIELD(arg1, f32 *, 8) + (f32) sp40;
    this->unk8 = (f64) sp20;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp20'
void IceBossStalactiteSpawner::Fire(const MKVector3 &arg0) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    IceBossStalactite ***var_r31_220;
    IceBossStalactite **temp_r3_230;
    f32 var_f3_204;
    f32 var_f4_137;
    f64 temp_f1_143;
    f64 temp_f1_149;
    f64 temp_f1_153;
    s32 temp_r4_172;
    s32 var_r0_182;

    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp30 = sp20;
    sp28 = arg0.unk8 - M2C_FIELD(this, f32 *, 8);
    sp38 = (f64) sp28;
    var_f4_137 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f4_137 > 1e-12f) {
        if (var_f4_137 > 0.0f) {
            temp_f1_143 = __frsqrte(var_f4_137);
            temp_f1_149 = 0.5 * temp_f1_143 * -(((f64) var_f4_137 * (temp_f1_143 * temp_f1_143)) - 3.0);
            temp_f1_153 = 0.5 * temp_f1_149 * -(((f64) var_f4_137 * (temp_f1_149 * temp_f1_149)) - 3.0);
            var_f4_137 = (f32) ((f64) var_f4_137 * (0.5 * temp_f1_153 * -(((f64) var_f4_137 * (temp_f1_153 * temp_f1_153)) - 3.0)));
        } else if (var_f4_137 < M2C_BITWISE(f32, 0.0)) {
            var_f4_137 = __float_nan;
        } else {
            sp8 = var_f4_137;
            temp_r4_172 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_172) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_182 = 1;
                } else {
                    var_r0_182 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_182 = 5;
                } else {
                    var_r0_182 = 3;
                }
                break;
            default:
                var_r0_182 = 4;
                break;
            }
            if (var_r0_182 == 1) {
                var_f4_137 = __float_nan;
            }
        }
        var_f3_204 = 1.0f / var_f4_137;
    } else {
        var_f3_204 = 0.0f;
    }
    sp14 = unksp34 * var_f3_204;
    sp10 = (f32) sp30 * var_f3_204;
    sp18 = (f32) sp38 * var_f3_204;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    var_r31_220 = this->unk10;
loop_22:
    if (var_r31_220 != NULL) {
        temp_r3_230 = *var_r31_220;
        if (temp_r3_230 != NULL) {
            ((IceBossStalactite *) (*temp_r3_230))->Fire(*((MKVector3 *) &sp40));
            var_r31_220 += 4;
            goto loop_22;
        }
    }
}
#endif

void IceBossStalactiteSpawner::DropIndividual(int arg0, bool arg1) {
    IceBossStalactite ***var_r7_248;
    IceBossStalactite **temp_r3_264;
    s32 var_r6_246;

    var_r6_246 = 0;
    var_r7_248 = this->unk10;
loop_4:
    if ((var_r7_248 == NULL) || (temp_r3_264 = *var_r7_248, ((temp_r3_264 == NULL) != 0))) {
        return;
    }
    if (var_r6_246 == arg0) {
        ((IceBossStalactite *) (*temp_r3_264))->Drop(arg1, 0U);
        return;
    }
    var_r6_246 += 1;
    var_r7_248 += 4;
    goto loop_4;
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void IceBossStalactiteSpawner::SpawnSingleAtPos(const MKVector3 &arg0) {
    IceBossStalactite ***temp_r3_292;

    M2C_FIELD(this, f32 *, 0x1C) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
    temp_r3_292 = this->unk10 - 4;
    this->unk10 = temp_r3_292;
    ((IceBossStalactite *) (**temp_r3_292))->Spawn(arg0, 1U, 0U);
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void IceBossStalactiteSpawner::Spawn(const MKVector3 &arg0) {
    IceBossStalactiteSpawner sp8;
    IceBossStalactite ***temp_r5_331;
    IceBossStalactite ***temp_r7_360;
    IceBossStalactite ***var_r3_332;
    IceBossStalactite ***var_r4_337;
    IceBossStalactite *temp_r28_364;
    s32 var_r29_348;
    u32 temp_r0_334;

loop_2:
    if ((IceBossStalactite **) *this->unk10 != NULL) {
        this->unk10 += 4;
        goto loop_2;
    }
    this->unk0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk8 = M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this, f32 *, 0x1C) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
    temp_r5_331 = this->unk10;
    var_r3_332 = temp_r5_331;
    do {
        temp_r0_334 = M2C_FIELD(var_r3_332, u32 *, -4);
        var_r3_332 -= 4;
    } while (temp_r0_334 != 0U);
    var_r4_337 = temp_r5_331;
loop_7:
    if ((IceBossStalactite **) *var_r4_337 != NULL) {
        var_r4_337 += 4;
        goto loop_7;
    }
    var_r29_348 = 0;
loop_10:
    if (var_r29_348 < (s32) ((((s32) (temp_r5_331 - var_r3_332) / 4) + ((s32) (var_r4_337 - temp_r5_331) / 4)) - 1)) {
        temp_r7_360 = this->unk10 - 4;
        this->unk10 = temp_r7_360;
        temp_r28_364 = **temp_r7_360;
        sp8.GetSpawnPoint(*((MKVector3 *) this), (s32) this);
        sp8.unk10 = M2C_BITWISE(f64, sp8);
        sp8.unk18 = sp8.unk8;
        sp8.unk14 = M2C_FIELD(this, f32 *, 4);
        temp_r28_364->Spawn(*((MKVector3 *) &sp8.unk10), 0U, 1U);
        var_r29_348 += 1;
        goto loop_10;
    }
}
#endif

void IceBossStalactiteSpawner::Reset() {
    IceBossStalactite ***var_r31_396;
    IceBossStalactite **temp_r3_408;
    IceBossStalactite *temp_r3_399;

    var_r31_396 = this->unk10;
loop_2:
    if (var_r31_396 != NULL) {
        temp_r3_408 = *var_r31_396;
        if (temp_r3_408 == NULL) {

        } else {
            temp_r3_399 = *temp_r3_408;
            temp_r3_399->Disable();
            var_r31_396 += 4;
            goto loop_2;
        }
    }
loop_6:
    if ((IceBossStalactite **) *this->unk10 != NULL) {
        this->unk10 += 4;
        goto loop_6;
    }
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1C) = 0.0f;
}

#if 0 // DRAFT: illegal explicit conversion from 'IceBossStalactiteSpawner *' to
void IceBossStalactiteSpawner::LoadDone() {
    IceBossStalactite ***var_r31_442;
    IceBossStalactite **temp_r3_475;
    s32 temp_r0_445;

    var_r31_442 = this->unk10 - 4;
loop_8:
    if ((var_r31_442 != NULL) && ((IceBossStalactite **) *var_r31_442 != NULL)) {
        temp_r0_445 = this->unk20;
        switch (temp_r0_445) {                      /* irregular */
        case 2:
            **var_r31_442 = checked_cast<IceBossStalactite *, MKProp>(gMK->CreateProp("IceBossStalactite"));
            break;
        case 1:
            **var_r31_442 = checked_cast<IceBossStalactite *, MKProp>(gMK->CreateProp("P5033_BossStalactite"));
            break;
        }
        M2C_FIELD(**var_r31_442, MKProp **, 0x21C) = (MKProp *) this->unk14;
        temp_r3_475 = *var_r31_442;
        var_r31_442 -= 4;
        (*temp_r3_475)->unk210 = M2C_BITWISE(f32, this);
        goto loop_8;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void IceBossStalactiteSpawner::Deinit() {
    IceBossStalactite ***var_r31_502;
    IceBossStalactite ***var_r3_503;
    IceBossStalactite ***var_r4_501;
    IceBossStalactite **temp_r0_506;
    IceBossStalactite **temp_r0_525;
    MKHeap *temp_r3_528;
    u32 temp_r0_511;

    var_r4_501 = this->unk10;
    var_r31_502 = var_r4_501;
    var_r3_503 = var_r4_501;
loop_3:
    temp_r0_511 = M2C_FIELD(var_r3_503, u32 *, -4);
    var_r3_503 -= 4;
    if (temp_r0_511 != 0U) {
        temp_r0_506 = *var_r3_503;
        if (temp_r0_506 < var_r31_502) {
            var_r31_502 = (IceBossStalactite ***) temp_r0_506;
        }
        goto loop_3;
    }
    if (var_r3_503 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_525 = *var_r4_501;
        if (temp_r0_525 != NULL) {
            if (temp_r0_525 < var_r31_502) {
                var_r31_502 = (IceBossStalactite ***) temp_r0_525;
            }
            var_r4_501 += 4;
            goto loop_9;
        }
        temp_r3_528 = var_r3_503->Current();
        if (temp_r3_528 != NULL) {
            ((MKHeap *) (temp_r3_528->Current()))->Free(var_r31_502, NULL, 0);
        } else {
            free(var_r31_502);
        }
    }
    this->unk10 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void IceBossStalactiteSpawner::Init(MKProp *arg0, int arg1, int arg2) {
    IceBossStalactite ***temp_r3_588;
    IceBossStalactite ***temp_r3_595;
    IceBossStalactite ***temp_r3_602;
    IceBossStalactite ***var_r3_576;
    IceBossStalactite ***var_r5_587;
    MKHeap *temp_r3_567;
    s32 var_ctr_591;

    if (arg1 == 0) {
        this->unk10 = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_567 = MKHeap::Current();
        if (temp_r3_567 != NULL) {
            var_r3_576 = ((MKHeap *) (temp_r3_567->Current()))->Alloc(((arg1 * 2) + 2) * 4, NULL, 0);
        } else {
            var_r3_576 = malloc(((arg1 * 2) + 2) * 4);
        }
        this->unk10 = var_r3_576;
        var_r5_587 = this->unk10;
        temp_r3_588 = &var_r5_587[arg1];
        this->unk10 = temp_r3_588;
        *temp_r3_588 = NULL;
        var_ctr_591 = arg1;
        if (arg1 > 0) {
            do {
                temp_r3_595 = this->unk10;
                this->unk10 = temp_r3_595 + 4;
                M2C_FIELD(temp_r3_595, IceBossStalactite ****, 4) = var_r5_587;
                var_r5_587 += 4;
                var_ctr_591 -= 1;
            } while (var_ctr_591 != 0);
        }
        temp_r3_602 = this->unk10;
        this->unk10 = temp_r3_602 + 4;
        M2C_FIELD(temp_r3_602, IceBossStalactite ****, 4) = NULL;
    }
    this->unk14 = arg0;
    this->unk20 = arg2;
}
#endif

#if 0 // DRAFT: illegal operand
void IceBossStalactite::Collided(MKCollisionResult *arg0) {
    s8 sp1C9;
    s8 sp1C8;
    s32 sp1C4;
    f32 sp1C0;
    s32 sp1BC;
    s8 sp1BA;
    s8 sp1B9;
    s8 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    s32 sp1A4;
    s32 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    s32 sp17C;
    s32 sp178;
    MKCollisionResult sp120;
    MKVector3 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    s32 var_r28_834;
    u8 temp_r4_638;
    void *temp_r28_891;
    void *temp_r3_641;
    void *temp_r3_655;
    void *temp_r3_669;
    void *temp_r3_729;
    void *temp_r3_751;
    void *temp_r3_840;
    void *temp_r3_884;
    void *temp_r3_888;
    void *var_r0_644;
    void *var_r0_658;
    void *var_r0_754;
    void *var_r3_672;
    void *var_r3_732;

    temp_r4_638 = arg0->unk50;
    if ((temp_r4_638 != 0) && (temp_r3_641 = arg0->unk48, ((temp_r3_641 == NULL) == 0)) && (var_r0_644 = M2C_FIELD(temp_r3_641, void **, 8), ((var_r0_644 == NULL) == 0))) {

    } else {
        var_r0_644 = NULL;
    }
    if (var_r0_644 != NULL) {
        if ((temp_r4_638 != 0) && (temp_r3_655 = arg0->unk48, ((temp_r3_655 == NULL) == 0)) && (var_r0_658 = M2C_FIELD(temp_r3_655, void **, 8), ((var_r0_658 == NULL) == 0))) {

        } else {
            var_r0_658 = NULL;
        }
        if (var_r0_658 != this) {
            if ((temp_r4_638 != 0) && (temp_r3_669 = arg0->unk48, ((temp_r3_669 == NULL) == 0)) && (var_r3_672 = M2C_FIELD(temp_r3_669, void **, 8), ((var_r3_672 == NULL) == 0))) {

            } else {
                var_r3_672 = NULL;
            }
            if ((u32) M2C_FIELD(this, u32 *, 0x21C) != var_r3_672) {
                sp17C = 0;
                sp178 = 7;
                sp1A0 = 1;
                sp1A4 = 0;
                sp180 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                sp188 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
                sp1B8 = 1;
                sp1C4 = 2;
                sp1C0 = 10.0f;
                sp1B9 = 0;
                sp1BA = 0;
                sp1BC = -1;
                sp190 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp198 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp1C8 = 0;
                sp1A8 = 0.0f;
                sp1AC = 0.0f;
                sp1B0 = 0.0f;
                sp1C9 = 0;
                sp1BC = GS_SpyroSpikeBurn;
                if (((u8) arg0->unk50 != 0) && (temp_r3_729 = arg0->unk48, ((temp_r3_729 == NULL) == 0)) && (var_r3_732 = M2C_FIELD(temp_r3_729, void **, 8), ((var_r3_732 == NULL) == 0))) {

                } else {
                    var_r3_732 = NULL;
                }
                M2C_FIELD(M2C_FIELD(var_r3_732, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp178);
            }
            M2C_FIELD(this, s8 *, 0x245) = 1;
            goto block_46;
        }
    } else {
        if ((temp_r4_638 != 0) && (temp_r3_751 = arg0->unk48, ((temp_r3_751 == NULL) == 0)) && (var_r0_754 = M2C_FIELD(temp_r3_751, void **, 8), ((var_r0_754 == NULL) == 0))) {

        } else {
            var_r0_754 = NULL;
        }
        if (var_r0_754 == NULL) {
            MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk230, &sp110);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            spF0 = sp70;
            sp78 = M2C_FIELD(this, f32 *, 0x1C0) * 10.0f;
            spF8 = (f64) sp78;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp100 = sp60;
            sp68 = sp110.unk8 + (f32) spF8;
            sp108 = (f64) sp68;
            if (MKCollision_RayCollide(sp110, *((MKVector3 *) &sp100), &sp120, (MKCollisionMode) 4, 0) != 0) {
                if (((u8) M2C_FIELD(this, u8 *, 0x244) >> 6U) & 1) {
                    M2C_FIELD(this, s8 *, 0x245) = 1;
                } else {
                    StickInGround(*((MKVector3 *) &sp120));
                    M2C_FIELD(this, u8 *, 0x244) = (u8) ((M2C_FIELD(this, u8 *, 0x244) & ~4) | ((sp120.unk44 << 2) & 4));
                    this->unk1D8 = M2C_BITWISE(f64, sp120);
                    this->unk1E0 = (f64) sp120.unk8;
                }
            } else {
                StickInGround(*((MKVector3 *) arg0));
                M2C_FIELD(this, u8 *, 0x244) = (u8) ((M2C_FIELD(this, u8 *, 0x244) & ~4) | ((sp120.unk44 << 2) & 4));
                this->unk1D8 = M2C_FIELD(arg0, f64 *, 0);
                this->unk1E0 = M2C_FIELD(arg0, f64 *, 8);
            }
            var_r28_834 = 0;
            this->unk22C = 1.0f;
            do {
                temp_r3_840 = checked_cast<IceBossStalactiteDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                sp58 = -1.0f;
                sp48 = 1.0f;
                sp50 = -1.0f;
                sp54 = 0.5f;
                sp40 = 1.0f;
                sp44 = 3.0f;
                spC0 = (f64) sp50;
                spC8 = (f64) sp58;
                spB0 = (f64) sp40;
                spB8 = (f64) sp48;
                KDRand_Vector(spD0, *((MKVector3 *) &spC0));
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                spE0 = sp30;
                sp38 = spD0.unk8 * 600.0f;
                spE8 = (f64) sp38;
                sp8 = MKRand_Float(&gViewSeed, 0.4f, 0.8f);
                ((IceBitsPS *) (M2C_FIELD(temp_r3_840, IceBitsPS **, 0x16C)))->Emit(*((MKVector3 *) &this->unk1D8), *((MKVector3 *) &spE0), sp8);
                var_r28_834 += 1;
            } while (var_r28_834 < 0x19);
            temp_r3_884 = this->unk224;
            temp_r3_888 = M2C_FIELD(M2C_FIELD(temp_r3_884, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_884);
            if (temp_r3_888 != NULL) {
                temp_r28_891 = M2C_FIELD(temp_r3_888, void **, 0x2C);
                M2C_FIELD(temp_r3_888, f64 *, 0) = (f64) this->unk1D8;
                M2C_FIELD(temp_r3_888, f64 *, 8) = (f64) this->unk1E0;
                M2C_FIELD(temp_r3_888, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_888, f32 *, 0x28) = 0.0f;
                sp10 = -M2C_FIELD(this, f32 *, 0x1B8);
                sp14 = -M2C_FIELD(this, f32 *, 0x1BC);
                sp18 = -M2C_FIELD(this, f32 *, 0x1C0);
                sp90 = (f64) sp10;
                sp98 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                M2C_FIELD(temp_r28_891, f64 *, 0) = sp20;
                sp28 = (f32) sp98 * 500.0f;
                spA0 = sp20;
                spA8 = (f64) sp28;
                M2C_FIELD(temp_r28_891, f64 *, 8) = (f64) sp28;
                M2C_FIELD(temp_r28_891, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                M2C_FIELD(temp_r28_891, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r28_891, f32 *, 0x14) = (f32) M2C_FIELD(this->unk224, f32 *, 0xF4);
            }
            if (!(((u8) M2C_FIELD(this, u8 *, 0x244) >> 2U) & 1)) {
                this->unk224 = 3.0f;
            } else {
                this->unk224 = 1.0f;
            }
        }
block_46:
        this->unk228 = 3.0f;
        M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x80);
        this->unk218 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void IceBossStalactite::StickInGround(const MKVector3 &arg0) {
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_1006;

    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk230, &sp58);
    KDSound_Stop((s32 *) &this->unk220);
    KDSound_Play3d(GS_IceBossIceEmbed, &sp58, 0U, -1, 0.0f, 0U);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) | 0x20);
    temp_f1_1006 = MKRand_Float(&gViewSeed, 0.85f, 0.95f);
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f0 */);
    sp28 = sp8;
    sp10 = this->unk1F8.unk8 - sp58.unk8;
    sp30 = (f64) sp10;
    sp38.operator*(temp_f1_1006);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x208) = sp18;
    sp20 = arg0.unk8 + sp38.unk8;
    sp48 = sp18;
    M2C_FIELD(this, f32 *, 0x210) = (f64) sp20;
    sp50 = (f64) sp20;
    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk230, (MKVector3 *) &this->unk1E8);
    M2C_FIELD(this, f32 *, 0x1B8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1BC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1C0) = 0.0f;
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void IceBossStalactite::Fire(const MKVector3 &arg0) {
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) | 0x80);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x10);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) | 8);
    M2C_FIELD(this, f64 *, 0x1A8) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x1B0) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk218 = 6.2831855f;
    M2C_FIELD(this, f32 *, 0x218) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, 0.0f, 1.0f));
}
#endif

void IceBossStalactite::Drop(bool arg0, bool arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) | 0x80);
    sp8 = -MKVector3::up.unk0;
    spC = -MKVector3::up.unk4;
    sp10 = -MKVector3::up.unk8;
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x10);
    M2C_FIELD(this, f64 *, 0x1A8) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x1B0) = (f64) sp10;
    this->unk218 = 6.2831855f;
    sp18 = (f64) sp8;
    M2C_FIELD(this, u8 *, 0x244) = (u8) ((M2C_FIELD(this, u8 *, 0x244) & ~1) | (arg0 & 1));
    sp20 = (f64) sp10;
    M2C_FIELD(this, u8 *, 0x246) = (u8) ((M2C_FIELD(this, u8 *, 0x246) & ~0x80) | ((arg1 << 7) & 0x80));
}

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBossStalactite::Spawn(const MKVector3 &arg0, bool arg1, bool arg2) {
    f32 temp_f0_1219;
    f32 temp_f10_1217;
    f32 temp_f11_1221;
    f32 temp_f12_1218;
    f32 temp_f1_1223;
    f32 temp_f2_1225;
    Reset();
    M2C_FIELD(this, f64 *, 0x208) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x210) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this, f32 *, 0x1B8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1BC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1C0) = 0.0f;
    M2C_FIELD(this, f32 *, 0x218) = 0.0f;
    this->unk218 = 0.0f;
    this->unk21C = 0.0f;
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x80);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x20);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~8);
    this->unk220 = NULL;
    this->unk224 = 0.0f;
    this->unk228 = 0.0f;
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~4);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) | 2);
    M2C_FIELD(this, u8 *, 0x244) = (u8) ((M2C_FIELD(this, u8 *, 0x244) & ~0x40) | ((arg1 << 6) & 0x40));
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) | 1);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) | 0x10);
    M2C_STRUCT_COPY((s32) &arg_sp7C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    M2C_FIELD(this, f64 *, 0x1C8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x1D0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    KDRand_UnitVectorXZ();
    this->unk1C8 = arg_sp60;
    this->unk1D0 = arg_sp68;
    temp_f10_1217 = (f32) M2C_FIELD(this, f64 *, 0x1E0);
    temp_f12_1218 = M2C_FIELD(this, f32 *, 0x1DC);
    temp_f0_1219 = this->unk1C0;
    temp_f11_1221 = (f32) M2C_FIELD(this, f64 *, 0x1D8);
    temp_f1_1223 = this->unk1BC;
    temp_f2_1225 = this->unk1B8;
    arg_sp18 = -temp_f10_1217;
    arg_sp48 = (f64) arg_sp18;
    arg_sp38 = (temp_f2_1225 * temp_f12_1218) - (temp_f1_1223 * temp_f11_1221);
    arg_sp30 = (temp_f1_1223 * temp_f10_1217) - (temp_f0_1219 * temp_f12_1218);
    arg_sp34 = (temp_f0_1219 * temp_f11_1221) - (temp_f2_1225 * temp_f10_1217);
    arg_sp78 = (f64) arg_sp38;
    arg_sp70 = (f64) arg_sp30;
    arg_sp10 = -temp_f11_1221;
    arg_sp28 = -(f32) arg_sp78;
    arg_sp14 = -temp_f12_1218;
    arg_sp58 = (f64) arg_sp28;
    arg_sp40 = (f64) arg_sp10;
    arg_sp20 = -(f32) arg_sp70;
    arg_sp24 = -arg_sp74;
    arg_sp88 = (f32) arg_sp58;
    arg_sp50 = (f64) arg_sp20;
    arg_sp80 = (f32) arg_sp50;
    arg_sp84 = arg_sp54;
    arg_sp8C = 0.0f;
    arg_sp90 = temp_f2_1225;
    arg_sp94 = temp_f1_1223;
    arg_sp98 = temp_f0_1219;
    arg_sp9C = 0.0f;
    arg_spA0 = (f32) arg_sp40;
    arg_spA4 = arg_sp44;
    arg_spA8 = (f32) arg_sp48;
    arg_spAC = 0.0f;
    arg_spB0 = this->unk1F8.unk0;
    arg_spB4 = this->unk1F8.unk4;
    arg_spB8 = this->unk1F8.unk8;
    arg_spBC = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp80));
    if (arg2 != 0) {
        if ((s32) M2C_FIELD(this->unk210, s32 *, 0x20) == 2) {
            KDSound_Play3d(GS_IceBossIceForm, &this->unk1F8, 0U, -1, 0.0f, 0U);
        } else {
            KDSound_Play3d(GS_ElecBossCrystalForm, &this->unk1F8, 0U, -1, 0.0f, 0U);
        }
    }
    if ((u8) M2C_FIELD(checked_cast<IceBossStalactiteDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x114) != 0) {
        this->unkC8.RegisterTargetable();
    }
    M2C_FIELD(this, s8 *, 0x245) = 0;
    Enable();
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void IceBossStalactite::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3) {
    f32 temp_f1_1367;
    s32 var_r5_1364;

    Shatterable::Shatter(arg0, arg1, arg2, arg3, M2C_FIELD(this, u8 *, 0x244) & 1, (((u8) M2C_FIELD(this, u8 *, 0x246) >> 7U) & 1) == 0);
    KDSound_Stop((s32 *) &this->unk220);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x80);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x20);
    this->unk218 = 0.0f;
    if (((u8) M2C_FIELD(this, u8 *, 0x246) >> 7U) & 1) {
        var_r5_1364 = 3;
        temp_f1_1367 = M2C_FIELD(GameData::gameData, f32 *, 0xA0) / M2C_FIELD(GameData::gameData, f32 *, 0xA4);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_1367 == 0.9f) {
            var_r5_1364 = 0;
        } else if (temp_f1_1367 > 0.75f) {
            var_r5_1364 = 1;
        } else if (temp_f1_1367 > 0.25f) {
            var_r5_1364 = 2;
        }
        ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x18)))->Spawn(this->unk1F8, var_r5_1364, 200.0f, 500.0f, -1, NULL);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void IceBossStalactite::Message(MKMessage *arg0) {
    void **temp_r3_1417;
    void **var_r3_1423;

    if ((s32) arg0->unk0 != 0x12) {
        Shatterable::Message(arg0);
    } else {
        temp_r3_1417 = M2C_FIELD(checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0), void ***, 0xC);
        if (temp_r3_1417 != NULL) {
            var_r3_1423 = M2C_FIELD(*temp_r3_1417, void **(**)(), 0x2C)();
        } else {
            var_r3_1423 = NULL;
        }
        if ((var_r3_1423 != NULL) && (M2C_FIELD(*var_r3_1423, s32 *, 0xC) & 8)) {
            Shatter(0U, NULL, -1, NULL);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp13C'
void IceBossStalactite::MeltFX() {
    f32 temp_f0_1512;
    f32 temp_f1_1480;
    f32 temp_f1_1554;
    f32 temp_f30_1500;
    f32 var_f0_1591;
    f32 var_f1_1602;
    f32 var_f29_1499;
    f32 var_f30_1487;
    u8 temp_r3_1570;
    void *temp_r3_1643;
    void *temp_r3_1663;
    M2C_STRUCT_COPY((s32) &arg_sp13C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    temp_f1_1480 = this->unk22C;
    if (temp_f1_1480 > 0.0f) {
        this->unk22C = temp_f1_1480 - gUpdateTimeDelta;
        var_f30_1487 = this->unk22C;
        if (var_f30_1487 < 1.0f) {

        } else {
            var_f30_1487 = 1.0f;
        }
        var_f29_1499 = this->unk22C;
        temp_f30_1500 = MKRand_Float(&gViewSeed, -5.0f, 5.0f) * var_f30_1487;
        if (var_f29_1499 < 1.0f) {

        } else {
            var_f29_1499 = 1.0f;
        }
        temp_f0_1512 = MKRand_Float(&gViewSeed, -5.0f, 5.0f) * var_f29_1499;
        arg_sp88 = temp_f30_1500;
        arg_sp80 = temp_f0_1512;
        arg_sp84 = 0.0f;
        arg_sp138 = (f64) arg_sp88;
        arg_sp130 = (f64) arg_sp80;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp110 = arg_sp40;
        arg_sp48 = this->unk1F8.unk8 + (f32) arg_sp138;
        arg_sp118 = (f64) arg_sp48;
        arg_sp170 = (f32) arg_sp110;
        arg_sp174 = arg_sp114;
        arg_sp178 = (f32) arg_sp118;
        arg_sp17C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp140));
    }
    this->unk224 = M2C_BITWISE(f32, this->unk224) - gUpdateTimeDelta;
    if (!(M2C_BITWISE(f32, this->unk224) > 0.0f)) {
        temp_f1_1554 = this->unk228;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_1554 == 0.0f) {
            return;
        }
        this->unk228 = temp_f1_1554 - gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk228 == 0.0f) {
            DisableCollision();
        }
        temp_r3_1570 = M2C_FIELD(this, u8 *, 0x244);
        if (((temp_r3_1570 >> 1U) & 1) && !((temp_r3_1570 >> 2U) & 1)) {
            M2C_FIELD(this, u8 *, 0x244) = (u8) (temp_r3_1570 & ~2);
            KDSound_Play3d(GS_IceBossIceMelt, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
        var_f0_1591 = -((0.125f * gUpdateTimeDelta) - M2C_BITWISE(f32, this->unk21C));
        if (var_f0_1591 > 0.0f) {

        } else {
            var_f0_1591 = 0.0f;
        }
        this->unk21C = var_f0_1591;
        if (!(((u8) M2C_FIELD(this, u8 *, 0x244) >> 2U) & 1)) {
            var_f1_1602 = M2C_BITWISE(f32, this->unk21C);
            if (var_f1_1602 > 0.6f) {

            } else {
                var_f1_1602 = 0.6f;
            }
            arg_sp38 = var_f1_1602;
            arg_sp30 = var_f1_1602;
            arg_sp34 = var_f1_1602;
            arg_sp108 = (f64) arg_sp38;
            arg_sp100 = (f64) arg_sp30;
            arg_sp140.Scale3x3((Matrix *) &arg_sp140, *((MKVector3 *) &arg_sp100));
            arg_sp28 = 0.0f;
            arg_sp20 = 0.0f;
            arg_sp24 = 100.0f * gUpdateTimeDelta;
            arg_spF8 = (f64) arg_sp28;
            arg_spF0 = (f64) arg_sp20;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            this->unk1F8.unk8 -= (f32) arg_spF8;
            temp_r3_1643 = this->unk8;
            arg_spE0 = M2C_FIELD(temp_r3_1643, f64 *, 0x30);
            arg_spE8 = M2C_FIELD(temp_r3_1643, f64 *, 0x38);
            if (((20.0f * (1.0f - M2C_FIELD(this, f32 *, 0x1AC))) + arg_spE4) > M2C_FIELD(this, f32 *, 0x1EC)) {
                KDRand_UnitVectorXZ();
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                temp_r3_1663 = this->unk8;
                arg_sp78 = arg_spB8 * 30.000002f;
                arg_spC0 = arg_sp70;
                arg_spD0 = M2C_FIELD(temp_r3_1663, f64 *, 0x30);
                arg_spC8 = (f64) arg_sp78;
                arg_spD8 = M2C_FIELD(temp_r3_1663, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp50 = -MKVector3::up.unk0;
                arg_sp54 = -MKVector3::up.unk4;
                arg_sp68 = (f32) arg_spD8 + (f32) arg_spC8;
                arg_sp58 = -MKVector3::up.unk8;
                arg_sp120 = arg_sp60;
                arg_sp128 = (f64) arg_sp68;
                arg_spA0 = (f64) arg_sp50;
                arg_spA8 = (f64) arg_sp58;
                ((WaterDripPS *) (M2C_FIELD(&gb, WaterDripPS **, 0x6C)))->Emit(*((MKVector3 *) &arg_sp120), *((MKVector3 *) &arg_spA0), 3.0f, 0U, 1U, NULL);
            }
        } else {
            arg_sp18 = 0.0f;
            arg_sp10 = 0.0f;
            arg_sp98 = (f64) arg_sp18;
            arg_sp14 = 980.0f * gUpdateTimeDelta * (1.0f + (1.0f - M2C_BITWISE(f32, this->unk21C)));
            arg_sp90 = (f64) arg_sp10;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            this->unk1F8.unk8 -= (f32) arg_sp98;
        }
        arg_sp170 = this->unk1F8.unk0;
        arg_sp174 = this->unk1F8.unk4;
        arg_sp178 = this->unk1F8.unk8;
        arg_sp17C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp140));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp6C'
void IceBossStalactite::Draw() {
    M2C_STRUCT_COPY((s32) &arg_sp6C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    if ((((u8) M2C_FIELD(this, u8 *, 0x244) >> 4U) & 1) && (M2C_BITWISE(f32, this->unk21C) < 1.0f)) {
        M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) &arg_sp6C + 4, 0x40);
        arg_sp18 = 1.0f;
        arg_sp10 = 1.0f;
        arg_sp14 = M2C_BITWISE(f32, this->unk21C);
        arg_sp28 = (f64) arg_sp18;
        arg_sp20 = (f64) arg_sp10;
        arg_sp30.Scale3x3((Matrix *) &arg_sp30, *((MKVector3 *) &arg_sp20));
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp30));
    }
    Shatterable::Draw();
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp70));
}
#endif

#if 0 // DRAFT: type mismatch
void IceBossStalactite::Update() {
    f32 temp_f1_2198;
    f32 temp_f1_2326;
    f32 temp_f1_2349;
    f32 temp_f1_2398;
    f32 temp_f1_2439;
    f32 temp_f27_2138;
    f32 temp_f27_2194;
    f32 temp_f27_2261;
    f32 temp_f28_2133;
    f32 temp_f28_2266;
    f32 temp_f29_2322;
    f32 temp_f29_2394;
    f32 temp_f2_1886;
    f32 temp_f2_2470;
    f32 temp_f30_2389;
    f32 temp_f31_2120;
    f32 temp_f31_2248;
    f32 temp_f3_2441;
    f32 temp_f3_2467;
    f32 temp_f4_2437;
    f32 temp_f4_2471;
    f32 temp_f5_2442;
    f32 temp_f5_2466;
    f32 temp_f6_1950;
    f32 temp_f6_2435;
    f32 temp_f6_2465;
    f32 temp_f7_1952;
    f32 temp_f7_2433;
    f32 temp_f7_2468;
    f32 temp_f8_1954;
    f32 var_f0_1893;
    s32 temp_r0_2107;
    s32 temp_r0_2573;
    u8 temp_r3_1856;
    u8 temp_r4_1908;
    void *temp_r3_2154;
    void *temp_r3_2282;
    void *temp_r4_2029;
    void *temp_r9_2414;
    void *var_r0_1863;
    temp_r3_1856 = M2C_FIELD(this, u8 *, 0x244);
    if (!((temp_r3_1856 >> 7U) & 1) && !((temp_r3_1856 >> 4U) & 1)) {
        var_r0_1863 = this->unk170 - 1;
        if ((s32) lit_644 < var_r0_1863) {
            var_r0_1863 = (void *) lit_644;
        }
        if (((s32) *(this->unk158 + (((s32) var_r0_1863 << 7) + 0x44)) == 1) || (((u8) M2C_FIELD(this, u8 *, 0x244) >> 5U) & 1)) {
            goto block_6;
        }
    } else {
block_6:
        Shatterable::Update();
        if ((s32) this->unk16C != 3) {
            if ((((u8) M2C_FIELD(this, u8 *, 0x244) >> 4U) & 1) && (temp_f2_1886 = M2C_BITWISE(f32, this->unk21C), ((temp_f2_1886 < 1.0f) != 0))) {
                var_f0_1893 = (0.5f * gUpdateTimeDelta) + temp_f2_1886;
                if (var_f0_1893 < 1.0f) {

                } else {
                    var_f0_1893 = 1.0f;
                }
                this->unk21C = var_f0_1893;
            } else {
                M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x10);
            }
            temp_r4_1908 = M2C_FIELD(this, u8 *, 0x244);
            if ((temp_r4_1908 >> 7U) & 1) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (M2C_FIELD(&gb, f32 *, 0x30C) == M2C_FIELD(this, f32 *, 0x218)) {
                    if ((temp_r4_1908 >> 3U) & 1) {
                        if ((s32) M2C_FIELD(this->unk210, s32 *, 0x20) == 2) {
                            this->unk220 = KDSound_Play3d(GS_IceBossIceDrop, &this->unk1F8, 0U, -1, 0.0f, 0U);
                        } else {
                            this->unk220 = KDSound_Play3d(GS_ElecBossCrystalFly, &this->unk1F8, 0U, -1, 0.0f, 0U);
                        }
                        M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~8);
                    }
                    temp_f6_1950 = -this->unk198;
                    temp_f7_1952 = -M2C_FIELD(this, f32 *, 0x1AC);
                    temp_f8_1954 = -M2C_FIELD(this, f32 *, 0x1B0);
                    arg_sp1C8 = temp_f6_1950;
                    arg_sp1CC = temp_f7_1952;
                    arg_sp1D0 = temp_f8_1954;
                    arg_sp3E8 = (f64) arg_sp1C8;
                    arg_sp3F0 = (f64) arg_sp1D0;
                    if (((this->unk1C0 * (f32) arg_sp3F0) + ((this->unk1B8 * (f32) arg_sp3E8) + (this->unk1BC * arg_sp3EC))) < 0.99f) {
                        arg_sp80 = temp_f8_1954;
                        arg_sp78 = temp_f6_1950;
                        arg_sp7C = temp_f7_1952;
                        arg_sp3D0 = (f64) arg_sp80;
                        arg_sp3C8 = (f64) arg_sp78;
                        KDMath_Slerp(*((MKVector3 *) &arg_sp3D8), *((MKVector3 *) &this->unk1B8), 3.1415927f * gUpdateTimeDelta);
                        M2C_FIELD(this, f32 *, 0x1C8) = arg_sp3D8;
                        M2C_FIELD(this, f32 *, 0x1D0) = arg_sp3E0;
                    }
                    arg_sp398.operator*(980.0f);
                    arg_sp3A8.operator*(gUpdateTimeDelta);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    arg_sp3B8 = arg_sp68;
                    arg_sp70 = arg_sp3B0 * 0.1f;
                    arg_sp3C0 = (f64) arg_sp70;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
                    M2C_FIELD(this, f32 *, 0x1C0) = (f32) (M2C_FIELD(this, f32 *, 0x1C0) + (f32) arg_sp3C0);
                    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk230, (MKVector3 *) &arg_sp408);
                    temp_r4_2029 = this->unk158 + (((s32) this->unk170 << 7) + 0x68);
                    arg_sp1C = temp_r4_2029;
                    if (temp_r4_2029 != NULL) {
                        arg_sp20 = M2C_FIELD(temp_r4_2029, u8 *, 4);
                        M2C_FIELD(temp_r4_2029, u8 *, 4) = 0U;
                    }
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp388 = arg_sp1B8;
                    arg_sp1C0 = arg_sp410 + M2C_FIELD(this, f32 *, 0x1C0);
                    arg_sp390 = (f64) arg_sp1C0;
                    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp408), *((MKVector3 *) &arg_sp388), 50.0f, (MKCollisionResult *) &arg_sp460, (MKCollisionMode) 7, 0) != 0) {
                        Collided((MKCollisionResult *) &arg_sp460);
                    } else {
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r3, 0x0, qr0 */);
                        this->unk1F8.unk8 += M2C_FIELD(this, f32 *, 0x1C0);
                    }
                    if (arg_sp1C != NULL) {
                        M2C_FIELD(arg_sp1C, u8 *, 4) = arg_sp20;
                    }
                    if ((u8) M2C_FIELD(this, u8 *, 0x245) != 0) {
                        if ((s32) M2C_FIELD(this->unk210, s32 *, 0x20) == 1) {
                            Shatter(0U, NULL, GS_ElecBossCrystalSmash, NULL);
                        } else {
                            Shatter(0U, NULL, -1, NULL);
                        }
                        M2C_FIELD(this, u8 *, 0x245) = 0U;
                    }
                    temp_r0_2107 = M2C_FIELD(this->unk210, s32 *, 0x20);
                    switch (temp_r0_2107) {         /* switch 1; irregular */
                    case 2:                         /* switch 1 */
                        temp_f31_2120 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
                        arg_sp180 = 0.0f;
                        arg_sp178 = 0.0f;
                        arg_sp17C = 200.0f;
                        arg_sp330 = (f64) arg_sp180;
                        arg_sp328 = (f64) arg_sp178;
                        temp_f28_2133 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f27_2138 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_sp1A8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_sp1AC = temp_f27_2138;
                        arg_sp1B0 = temp_f28_2133;
                        arg_sp338 = (f64) arg_sp1A8;
                        arg_sp340 = (f64) arg_sp1B0;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                        temp_r3_2154 = this->unk8;
                        arg_sp348 = arg_sp198;
                        arg_sp1A0 = (f32) arg_sp340 * 100.0f;
                        arg_sp358 = M2C_FIELD(temp_r3_2154, f64 *, 0x30);
                        arg_sp350 = (f64) arg_sp1A0;
                        arg_sp360 = M2C_FIELD(temp_r3_2154, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp368 = arg_sp188;
                        arg_sp190 = (f32) arg_sp360 + (f32) arg_sp350;
                        arg_sp370 = (f64) arg_sp190;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp378 = arg_sp168;
                        arg_sp170 = (f32) arg_sp370 + (f32) arg_sp330;
                        arg_sp380 = (f64) arg_sp170;
                        temp_f27_2194 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f1_2198 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_sp160 = temp_f27_2194;
                        arg_sp158 = temp_f1_2198;
                        arg_sp15C = 1.0f;
                        arg_sp310 = (f64) arg_sp160;
                        arg_sp308 = (f64) arg_sp158;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                        arg_sp318 = arg_sp148;
                        arg_sp150 = (f32) arg_sp310 * 310.0f;
                        arg_sp320 = (f64) arg_sp150;
                        arg_sp18 = MKRand_Float(&gViewSeed, 7.1f, 15.0f);
                        arg_sp138 = temp_f31_2120;
                        arg_sp13C = temp_f31_2120;
                        arg_sp140 = 1.0f;
                        arg_sp144 = 1.0f;
                        arg_sp2F8 = (f64) arg_sp138;
                        arg_sp300 = (f64) arg_sp140;
                        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp378), *((MKVector3 *) &arg_sp318), arg_sp18, *((MKVector4 *) &arg_sp2F8), 0.0f);
                        break;
                    case 1:                         /* switch 1 */
                        temp_f31_2248 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
                        arg_sp100 = 0.0f;
                        arg_spF8 = 0.0f;
                        arg_spFC = 200.0f;
                        arg_sp2A0 = (f64) arg_sp100;
                        arg_sp298 = (f64) arg_spF8;
                        temp_f27_2261 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f28_2266 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_sp128 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_sp12C = temp_f28_2266;
                        arg_sp130 = temp_f27_2261;
                        arg_sp2A8 = (f64) arg_sp128;
                        arg_sp2B0 = (f64) arg_sp130;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                        temp_r3_2282 = this->unk8;
                        arg_sp2B8 = arg_sp118;
                        arg_sp120 = (f32) arg_sp2B0 * 100.0f;
                        arg_sp2C8 = M2C_FIELD(temp_r3_2282, f64 *, 0x30);
                        arg_sp2C0 = (f64) arg_sp120;
                        arg_sp2D0 = M2C_FIELD(temp_r3_2282, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp2D8 = arg_sp108;
                        arg_sp110 = (f32) arg_sp2D0 + (f32) arg_sp2C0;
                        arg_sp2E0 = (f64) arg_sp110;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp2E8 = arg_spE8;
                        arg_spF0 = (f32) arg_sp2E0 + (f32) arg_sp2A0;
                        arg_sp2F0 = (f64) arg_spF0;
                        temp_f29_2322 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f1_2326 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_spE0 = temp_f29_2322;
                        arg_spD8 = temp_f1_2326;
                        arg_spDC = 1.0f;
                        arg_sp280 = (f64) arg_spE0;
                        arg_sp278 = (f64) arg_spD8;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                        arg_sp288 = arg_spC8;
                        arg_spD0 = (f32) arg_sp280 * 310.0f;
                        arg_sp290 = (f64) arg_spD0;
                        temp_f1_2349 = MKRand_Float(&gViewSeed, 7.1f, 15.0f);
                        arg_spB8 = temp_f31_2248;
                        arg_spBC = 0.0f;
                        arg_sp14 = temp_f1_2349;
                        arg_spC0 = temp_f31_2248;
                        arg_spC4 = 1.0f;
                        arg_sp268 = (f64) arg_spB8;
                        arg_sp270 = (f64) arg_spC0;
                        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp2E8), *((MKVector3 *) &arg_sp288), arg_sp14, *((MKVector4 *) &arg_sp268), 0.0f);
                        arg_sp98 = 1.0f;
                        arg_sp9C = 0.0f;
                        arg_spA0 = 0.25f;
                        arg_spA4 = 1.0f;
                        arg_sp238 = (f64) arg_sp98;
                        arg_sp240 = (f64) arg_spA0;
                        arg_sp10 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                        temp_f30_2389 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f29_2394 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f1_2398 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_spB0 = temp_f30_2389;
                        arg_spA8 = temp_f1_2398;
                        arg_spAC = temp_f29_2394;
                        arg_sp250 = (f64) arg_spB0;
                        arg_sp248 = (f64) arg_spA8;
                        temp_r9_2414 = this->unk8;
                        arg_sp258 = M2C_FIELD(temp_r9_2414, f64 *, 0x30);
                        arg_sp260 = M2C_FIELD(temp_r9_2414, f64 *, 0x38);
                        ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &arg_sp258), *((MKVector3 *) &arg_sp248), arg_sp10, lit_683, (MKVector4) &arg_sp238);
                        break;
                    }
                }
            }
            M2C_STRUCT_COPY((s32) &arg_sp41C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
            temp_f7_2433 = this->unk1BC;
            temp_f6_2435 = M2C_FIELD(this, f32 *, 0x1D8);
            temp_f4_2437 = M2C_FIELD(this, f32 *, 0x1E0);
            temp_f1_2439 = this->unk1B8;
            temp_f3_2441 = M2C_FIELD(this, f32 *, 0x1DC);
            temp_f5_2442 = this->unk1C0;
            arg_sp90 = (temp_f1_2439 * temp_f3_2441) - (temp_f7_2433 * temp_f6_2435);
            arg_sp8C = (temp_f5_2442 * temp_f6_2435) - (temp_f1_2439 * temp_f4_2437);
            arg_sp88 = (temp_f7_2433 * temp_f4_2437) - (temp_f5_2442 * temp_f3_2441);
            arg_sp400 = (f64) arg_sp90;
            arg_sp3F8 = (f64) arg_sp88;
            KDMath_Slerp(*((MKVector3 *) &arg_sp228), *((MKVector3 *) &this->unk1C8), this->unk218 * gUpdateTimeDelta);
            this->unk1C8 = arg_sp228;
            this->unk1D0 = arg_sp230;
            temp_f6_2465 = this->unk1BC;
            temp_f5_2466 = M2C_FIELD(this, f32 *, 0x1D8);
            temp_f3_2467 = M2C_FIELD(this, f32 *, 0x1E0);
            temp_f7_2468 = this->unk1B8;
            temp_f2_2470 = M2C_FIELD(this, f32 *, 0x1DC);
            temp_f4_2471 = this->unk1C0;
            arg_sp60 = (temp_f7_2468 * temp_f2_2470) - (temp_f6_2465 * temp_f5_2466);
            arg_sp5C = (temp_f4_2471 * temp_f5_2466) - (temp_f7_2468 * temp_f3_2467);
            arg_sp58 = (temp_f6_2465 * temp_f3_2467) - (temp_f4_2471 * temp_f2_2470);
            arg_sp400 = (f64) arg_sp60;
            arg_sp3F8 = (f64) arg_sp58;
            arg_sp218 = (f64) arg_sp58;
            arg_sp220 = (f64) arg_sp60;
            arg_sp48 = (arg_sp3FC * temp_f4_2471) - ((f32) arg_sp400 * temp_f6_2465);
            arg_sp4C = ((f32) arg_sp400 * temp_f7_2468) - ((f32) arg_sp3F8 * temp_f4_2471);
            arg_sp50 = ((f32) arg_sp3F8 * temp_f6_2465) - (arg_sp3FC * temp_f7_2468);
            arg_sp1F8 = (f64) arg_sp48;
            arg_sp200 = (f64) arg_sp50;
            Normalise(*((MKVector3 *) &arg_sp208));
            this->unk1C8 = arg_sp208;
            this->unk1D0 = arg_sp210;
            arg_sp42C = 0.0f;
            arg_sp38 = -(f32) arg_sp3F8;
            arg_sp3C = -arg_sp3FC;
            arg_sp40 = -(f32) arg_sp400;
            arg_sp1E8 = (f64) arg_sp38;
            arg_sp1F0 = (f64) arg_sp40;
            arg_sp420 = (f32) arg_sp1E8;
            arg_sp424 = arg_sp1EC;
            arg_sp428 = (f32) arg_sp1F0;
            arg_sp430 = this->unk1B8;
            arg_sp434 = this->unk1BC;
            arg_sp438 = this->unk1C0;
            arg_sp43C = 0.0f;
            arg_sp44C = 0.0f;
            arg_sp28 = -M2C_FIELD(this, f32 *, 0x1D8);
            arg_sp2C = -M2C_FIELD(this, f32 *, 0x1DC);
            arg_sp30 = -M2C_FIELD(this, f32 *, 0x1E0);
            arg_sp1D8 = (f64) arg_sp28;
            arg_sp1E0 = (f64) arg_sp30;
            arg_sp440 = (f32) arg_sp1D8;
            arg_sp444 = arg_sp1DC;
            arg_sp448 = (f32) arg_sp1E0;
            arg_sp450 = this->unk1F8.unk0;
            arg_sp454 = this->unk1F8.unk4;
            arg_sp458 = this->unk1F8.unk8;
            arg_sp45C = 1.0f;
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp420));
            if ((((u8) M2C_FIELD(this, u8 *, 0x244) >> 5U) & 1) && ((s32) this->unk15C.unk0 == 2)) {
                temp_r0_2573 = M2C_FIELD(this->unk210, s32 *, 0x20);
                switch (temp_r0_2573) {             /* switch 2; irregular */
                case 2:                             /* switch 2 */
                    MeltFX();
                    return;
                case 1:                             /* switch 2 */
                    Shatter(0U, NULL, GS_ElecBossCrystalSmash, NULL);
                    break;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBossStalactite::LoadDone() {
    Shatterable::LoadDone();
    Disable();
    M2C_FIELD(this, s32 *, 0x21C) = 0;
    M2C_FIELD(this, f32 *, 0x218) = 0.0f;
    this->unk218 = 0.0f;
    this->unk21C = 0.0f;
    this->unk224 = 0.0f;
    this->unk22C = 0.0f;
    this->unk228 = 0.0f;
    M2C_FIELD(this, f32 *, 0x1E8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1EC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1F0) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1F8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1FC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x200) = 0.0f;
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x80);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x20);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x10);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~4);
    M2C_FIELD(this, u8 *, 0x244) = (u8) (M2C_FIELD(this, u8 *, 0x244) & ~0x40);
    this->unk230 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "tip");
    this->unk224 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("SnowPuffPS"));
    this->unk84 = 0.5f;
    M2C_FIELD(this, s8 *, 0x245) = 0;
    M2C_FIELD(this, u8 *, 0x246) = (u8) (M2C_FIELD(this, u8 *, 0x246) | 0x80);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'IceBitsPS *' to
void IceBossStalactiteDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk16C = checked_cast<IceBitsPS *, MKProp>(gMK->CreateProp("IceBitsPS"));
}
#endif
