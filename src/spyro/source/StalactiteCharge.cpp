#include "spyro/source/StalactiteCharge.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CutsceneProp.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/IceBossStalactite.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSpline.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(IceBossStalactiteSpawner *);           /* extern */
IceBossStalactiteSpawner *malloc(M2C_UNK);          /* extern */
extern s32 GS_PLACEHOLDER;
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
#if 0 // DRAFT: undefined identifier 'KDStateMachine'
static M2C_UNK lit_672;                                /* unable to generate initializer: unknown type */
static KDStateMachine<StalactiteCharge>::State StalactiteChargeStates; /* unable to generate initializer: confusing struct layout */

void StalactiteCharge::StateSCResetExit() {

}
#endif

#if 0 // DRAFT: undefined identifier 'unk50'
void StalactiteCharge::StateSCResetUpdate() {
    this->unk50.SetState(this, 0, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk10'
void StalactiteCharge::StateSCResetEnter() {
    f64 sp118;                                      /* compiler-managed */
    KDSplinePathSegment spD0;
    KDSplinePathSegment spB0;
    M2C_UNK spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    KDUniformSpline sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_208;
    f32 temp_f27_110;
    f32 temp_f28_112;
    f32 temp_f29_113;
    f32 temp_f2_303;
    f32 temp_f4_291;
    f32 temp_f5_293;
    f32 temp_f6_289;
    f32 var_f2_281;
    f32 var_f4_214;
    f64 temp_f1_220;
    f64 temp_f1_226;
    f64 temp_f1_230;
    s32 temp_r3_249;
    s32 temp_r3_357;
    s32 var_r0_259;
    s32 var_r30_103;

    this->unk4C->Reset();
    this->unkE8 = 1;
    var_r30_103 = 0;
    temp_f27_110 = MKVector3::up.unk4;
    temp_f28_112 = MKVector3::up.unk8;
    temp_f29_113 = MKVector3::up.unk0;
    this->unkD8 = 1.0f / ((f32) this->unkE0 - 1.0f);
loop_25:
    temp_r3_357 = this->unkE0;
    if (var_r30_103 < temp_r3_357) {
        if (var_r30_103 == (s32) (temp_r3_357 - 1)) {
            spD0.GetPosition(this->unkD8 * (f32) var_r30_103);
            spD0.unk10.GetPosition((this->unkD8 * (f32) var_r30_103) - 1.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spD0.unk20 = sp30;
            sp38 = M2C_BITWISE(f32, spD0.unk18) - spD0.unk8;
            spD0.unk30.unk10 = sp30;
            spD0.unk28 = (f64) sp38;
            sp118 = (f64) sp38;
        } else {
            spA0.GetPosition(this->unkD8 * (f32) (var_r30_103 + 1));
            spB0.GetPosition(this->unkD8 * (f32) var_r30_103);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spB0.unk10 = sp20;
            sp28 = spB0.unk8 - spA8;
            spD0.unk30.unk10 = sp20;
            spB0.unk18 = (f64) sp28;
            sp118 = (f64) sp28;
        }
        temp_f0_208 = M2C_BITWISE(f32, spD0.unk44);
        var_f4_214 = ((f32) sp118 * (f32) sp118) + (((f32) spD0.unk30.unk10 * (f32) spD0.unk30.unk10) + (temp_f0_208 * temp_f0_208));
        if (var_f4_214 > 0.000001f) {
            if (var_f4_214 > 0.0f) {
                temp_f1_220 = __frsqrte(var_f4_214);
                temp_f1_226 = 0.5 * temp_f1_220 * -(((f64) var_f4_214 * (temp_f1_220 * temp_f1_220)) - 3.0);
                temp_f1_230 = 0.5 * temp_f1_226 * -(((f64) var_f4_214 * (temp_f1_226 * temp_f1_226)) - 3.0);
                var_f4_214 = (f32) ((f64) var_f4_214 * (0.5 * temp_f1_230 * -(((f64) var_f4_214 * (temp_f1_230 * temp_f1_230)) - 3.0)));
            } else if (var_f4_214 < M2C_BITWISE(f32, 0.0)) {
                var_f4_214 = __float_nan;
            } else {
                sp8 = var_f4_214;
                temp_r3_249 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_249) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_259 = 1;
                    } else {
                        var_r0_259 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_259 = 5;
                    } else {
                        var_r0_259 = 3;
                    }
                    break;
                default:
                    var_r0_259 = 4;
                    break;
                }
                if (var_r0_259 == 1) {
                    var_f4_214 = __float_nan;
                }
            }
            var_f2_281 = 1.0f / var_f4_214;
        } else {
            var_f2_281 = 0.0f;
        }
        temp_f6_289 = (f32) spD0.unk30.unk10 * var_f2_281;
        temp_f4_291 = M2C_BITWISE(f32, spD0.unk44) * var_f2_281;
        temp_f5_293 = (f32) sp118 * var_f2_281;
        spD0.unk44 = temp_f4_291;
        spD0.unk30.unk10 = temp_f6_289;
        sp118 = temp_f5_293;
        temp_f2_303 = this->unkD0 * 0.5f;
        sp18 = (temp_f29_113 * temp_f4_291) - (temp_f27_110 * temp_f6_289);
        sp10 = (temp_f27_110 * temp_f5_293) - (temp_f28_112 * temp_f4_291);
        sp14 = (temp_f28_112 * temp_f6_289) - (temp_f29_113 * temp_f5_293);
        sp98 = (f64) sp18;
        sp90 = (f64) sp10;
        spD0.unk30 = (f64) sp10;
        spD0.unk30.unk8 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
        sp58 = (f32) (f64) sp18 * MKRand_Float(&gViewSeed, -temp_f2_303, temp_f2_303);
        sp60 = sp50;
        sp68 = (f64) sp58;
        spC = 0.0f;
        sp70.GetMeasure(this->unkD8 * (f32) var_r30_103, (Matrix *) &this->unkEC->unk30, KDSpline_PositionMixer);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp70.unk10 = sp40;
        sp48 = sp70.unk8 + (f32) sp68;
        sp88 = (f64) sp48;
        this->unk4C->SpawnSingleAtPos(*((MKVector3 *) &sp70.unk10));
        var_r30_103 += 1;
        goto loop_25;
    }
    this->unk140 = 0;
}
#endif

void StalactiteCharge::StateSCLerpCameraExit() {
    s8 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_419;

    temp_r3_419 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0));
    spC = 0;
    sp8 = 0xAC;
    M2C_FIELD(M2C_FIELD(temp_r3_419, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    sp1C = 0;
    sp18 = 0x403;
    sp20 = 0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp18, 0);
    sp14 = 0;
    sp10 = 0x40E;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp10);
}

#if 0 // DRAFT: undefined identifier 'arg_sp14'
void StalactiteCharge::StateSCLerpCameraUpdate() {
    f32 temp_f1_600;
    f32 temp_f30_525;
    f32 temp_f4_552;
    f32 var_f0_510;
    void *temp_r3_496;
    void *temp_r4_610;
    if (((u8) this->unk140 == 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x64)(M2C_FIELD(&gb, void ***, 0)) == 0)) {
        this->unk140 = 1;
        temp_r3_496 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0));
        arg_sp14 = 0;
        arg_sp10 = 0xAB;
        M2C_FIELD(M2C_FIELD(temp_r3_496, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp10);
    }
    var_f0_510 = this->unkF4 + gUpdateTimeDelta;
    if (var_f0_510 < 3.0f) {

    } else {
        var_f0_510 = 3.0f;
    }
    this->unkF4 = var_f0_510;
    temp_f30_525 = _table_sinf(0.33333334f * (3.1415927f * this->unkF4));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_spB8 = arg_sp68;
    arg_sp70 = this->unk128 * 200.0f;
    arg_spC0 = (f64) arg_sp70;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp60 = (f32) arg_spC0 * temp_f30_525;
    arg_spD8 = this->unk110;
    temp_f4_552 = 0.33333334f * this->unkF4;
    arg_spE8 = this->unk100;
    arg_spC8 = arg_sp58;
    arg_spD0 = (f64) arg_sp60;
    arg_spE0 = this->unk118;
    arg_spF0 = this->unk108;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    arg_sp88 = arg_sp38;
    arg_sp40 = (f32) arg_spE0 - (f32) arg_spF0;
    arg_sp90 = (f64) arg_sp40;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp78 = arg_sp28;
    arg_sp30 = (f32) arg_sp90 * temp_f4_552;
    arg_sp80 = (f64) arg_sp30;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    arg_spF8 = arg_sp18;
    arg_sp20 = (f32) arg_spF0 + (f32) arg_sp80;
    arg_sp100 = (f64) arg_sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_f1_600 = (f32) arg_sp100 + (f32) arg_spD0;
    arg_sp118 = arg_sp48;
    arg_sp50 = temp_f1_600;
    arg_sp120 = (f64) arg_sp50;
    temp_r4_610 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, f32, f32, f32, f32, f32, f64, f64), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_f1_600, (f32) arg_sp100, (f32) arg_spF0, temp_f4_552, 0.33333334f, (f64) arg_sp60, arg_sp58), void **, 8);
    arg_sp98 = M2C_FIELD(temp_r4_610, f64 *, 0x30);
    arg_spA0 = M2C_FIELD(temp_r4_610, f64 *, 0x38);
    arg_spA8.GetHeroTargetPos(*(M2C_FIELD(&gb, MKVector3 **, 0x3B8)));
    arg_sp108 = arg_spA8;
    arg_sp110 = arg_spB0;
    arg_sp130.SetLookAt(*((MKVector3 *) &arg_sp118), *((MKVector3 *) &arg_sp108));
    arg_sp174 = 0;
    arg_sp170.Init(*((Matrix *) &arg_sp130));
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, MKVector3 **, 0x3B8), void **, 0x44), M2C_UNK (**)(MKVector3 *, M2C_UNK *), 0x2C)(M2C_FIELD(&gb, MKVector3 **, 0x3B8), &arg_sp170);
    if (this->unkF4 == 3.0f) {
        this->unk50.SetState(this, 2, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void StalactiteCharge::StateSCLerpCameraEnter() {
    s8 sp251;
    u8 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    s32 sp20C;
    s32 sp208;
    f64 sp200;                                      /* compiler-managed */
    f64 sp1F8;                                      /* compiler-managed */
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    HeroInterface sp1C8;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    HeroInterface sp198;
    MKVector3 sp188;
    f64 sp180;
    f64 sp178;
    HeroInterface sp168;
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
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp30;
    f64 sp28;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f3_904;
    f32 temp_f4_902;
    f32 temp_f5_907;
    f32 var_f2_893;
    f32 var_f4_826;
    f64 temp_f0_706;
    f64 temp_f1_832;
    f64 temp_f1_838;
    f64 temp_f1_842;
    f64 temp_f2_705;
    f64 temp_f5_721;
    s32 temp_r3_861;
    s32 var_r0_871;
    void *temp_r3_1034;
    void *temp_r3_801;
    void *temp_r4_704;

    this->unkF4 = 0.0f;
    sp20 = 0;
    sp1C = 0x402;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp1C, 0);
    sp18 = 0;
    sp14 = 0x40D;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp14);
    temp_r4_704 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    temp_f2_705 = M2C_FIELD(temp_r4_704, f64 *, 0x30);
    temp_f0_706 = M2C_FIELD(temp_r4_704, f64 *, 0x38);
    sp1D8 = temp_f2_705;
    this->unk100 = temp_f2_705;
    this->unk108 = temp_f0_706;
    sp1E0 = temp_f0_706;
    sp20C = 0;
    KDMath_GetDirection(0.9254072f);
    sp1C8.GetPos();
    temp_f5_721 = M2C_BITWISE(f64, sp1C8);
    sp208 = 0x421;
    sp210 = temp_f5_721;
    sp218 = sp1D0;
    sp220 = sp1B8;
    sp228 = sp1C0;
    sp230 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp238 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp240 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp248 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp250 = 0;
    sp251 = 0;
    sp28 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp30 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, f64, f64, f64, f64, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp208, 0x421, M2C_FIELD(&MKVector3::zero, f64 *, 0), sp1C0, sp1B8, sp1D0, temp_f5_721);
    if (sp250 != 0) {
        this->unk110 = sp230;
        this->unk118 = sp238;
    } else {
        sp168.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp178 = sp38;
        sp40 = (f32) M2C_FIELD(this, f64 *, 0x108) - sp170;
        sp180 = (f64) sp40;
        KDMath_GetReflectedVector(sp188, *((MKVector3 *) &sp178));
        sp198.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        this->unk110 = sp98;
        spA0 = sp1A0 + sp188.unk8;
        sp1A8 = sp98;
        sp1B0 = (f64) spA0;
        this->unk118 = (f64) spA0;
    }
    temp_r3_801 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp158 = M2C_FIELD(temp_r3_801, f64 *, 0x30);
    sp160 = M2C_FIELD(temp_r3_801, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp1F8 = spE8;
    spF0 = (f32) M2C_FIELD(this, f64 *, 0x118) - (f32) sp160;
    sp200 = (f64) spF0;
    var_f4_826 = ((f32) sp200 * (f32) sp200) + (((f32) sp1F8 * (f32) sp1F8) + (unksp1FC * unksp1FC));
    if (var_f4_826 > 0.000001f) {
        if (var_f4_826 > 0.0f) {
            temp_f1_832 = __frsqrte(var_f4_826);
            temp_f1_838 = 0.5 * temp_f1_832 * -(((f64) var_f4_826 * (temp_f1_832 * temp_f1_832)) - 3.0);
            temp_f1_842 = 0.5 * temp_f1_838 * -(((f64) var_f4_826 * (temp_f1_838 * temp_f1_838)) - 3.0);
            var_f4_826 = (f32) ((f64) var_f4_826 * (0.5 * temp_f1_842 * -(((f64) var_f4_826 * (temp_f1_842 * temp_f1_842)) - 3.0)));
        } else if (var_f4_826 < M2C_BITWISE(f32, 0.0)) {
            var_f4_826 = __float_nan;
        } else {
            sp8 = var_f4_826;
            temp_r3_861 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_861) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_871 = 1;
                } else {
                    var_r0_871 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_871 = 5;
                } else {
                    var_r0_871 = 3;
                }
                break;
            default:
                var_r0_871 = 4;
                break;
            }
            if (var_r0_871 == 1) {
                var_f4_826 = __float_nan;
            }
        }
        var_f2_893 = 1.0f / var_f4_826;
    } else {
        var_f2_893 = 0.0f;
    }
    temp_f4_902 = unksp1FC * var_f2_893;
    temp_f3_904 = (f32) sp200 * var_f2_893;
    temp_f5_907 = (f32) sp1F8 * var_f2_893;
    sp1F8 = temp_f5_907;
    unksp1FC = temp_f4_902;
    sp200 = temp_f3_904;
    sp88 = (MKVector3::up.unk4 * temp_f3_904) - (MKVector3::up.unk8 * temp_f4_902);
    sp8C = (MKVector3::up.unk8 * temp_f5_907) - (MKVector3::up.unk0 * temp_f3_904);
    sp90 = (MKVector3::up.unk0 * temp_f4_902) - (MKVector3::up.unk4 * temp_f5_907);
    this->unk120 = (f64) sp88;
    M2C_FIELD(this, f64 *, 0x128) = (f64) sp90;
    sp148 = (f64) sp88;
    sp150 = (f64) sp90;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    spC0 = this->unk128 * 200.0f;
    sp118 = this->unk110;
    sp128 = this->unk100;
    sp108 = spB8;
    sp110 = (f64) spC0;
    sp120 = this->unk118;
    sp130 = this->unk108;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    spD8 = sp78;
    sp80 = (f32) sp120 - (f32) sp130;
    spE0 = (f64) sp80;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    spC8 = sp68;
    sp70 = (f32) spE0 * 0.5f;
    spD0 = (f64) sp70;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    sp138 = sp58;
    sp60 = (f32) sp130 + (f32) spD0;
    sp140 = (f64) sp60;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spB0 = (f32) sp140 + (f32) sp110;
    sp1E8 = spA8;
    sp1F0 = (f64) spB0;
    if (MKCollision_SphereCollide(*((MKVector3 *) &sp1E8), M2C_ERROR(/* unknown instruction: ps_mr $f1, $f31 */), NULL, 1, (MKCollisionMode) 1, 0) != 0) {
        sp48 = -(f32) M2C_FIELD(this, f64 *, 0x120);
        sp4C = -M2C_FIELD(this, f32 *, 0x124);
        sp50 = -this->unk128;
        this->unk120 = (f64) sp48;
        spF8 = (f64) sp48;
        sp100 = (f64) sp50;
        M2C_FIELD(this, f64 *, 0x128) = (f64) sp50;
    }
    if (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x64)(M2C_FIELD(&gb, void ***, 0)) == 0) {
        this->unk140 = 1;
        temp_r3_1034 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0));
        sp10 = 0;
        spC = 0xAB;
        M2C_FIELD(M2C_FIELD(temp_r3_1034, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spC);
    }
}
#endif

void StalactiteCharge::StateSCDropExit() {
    s32 spC;
    s32 sp8;

    spC = 0;
    sp8 = 0x430;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8);
}

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void StalactiteCharge::StateSCDropUpdate() {
    f64 spD0;
    f64 spC8;
    s32 spC4;
    s32 spC0;
    f64 spB8;
    f64 spB0;
    s32 spAC;
    s32 spA8;
    f64 spA0;
    KDUniformSpline sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    HeroInterface sp48;
    M2C_UNK sp38;
    f32 sp30;
    f32 sp20;
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    KDSplinePathSegment *temp_r4_1091;
    f32 temp_f5_1158;
    f32 var_f1_1094;
    f32 var_f1_1289;
    f32 var_f1_1305;
    f32 var_f4_1224;
    f64 temp_f1_1108;
    f64 temp_f1_1227;
    f64 temp_f1_1233;
    f64 temp_f1_1237;
    s32 temp_r3_1125;
    s32 temp_r3_1164;
    s32 temp_r3_1256;
    s32 var_r0_1266;
    void *temp_r3_1199;

    spC4 = 0;
    temp_r4_1091 = this->unkEC;
    var_f1_1094 = this->unkDC / temp_r4_1091->unk30.unk8;
    if (var_f1_1094 < 1.0f) {

    } else {
        var_f1_1094 = 1.0f;
    }
    spC = 0.0f;
    sp88.GetMeasure(var_f1_1094, (Matrix *) &temp_r4_1091->unk30, KDSpline_PositionMixer);
    temp_f1_1108 = M2C_BITWISE(f64, sp88);
    spC8 = temp_f1_1108;
    spC0 = 0x41B;
    spD0 = (f64) sp88.unk8;
    sp88.unk10 = temp_f1_1108;
    spA0 = (f64) sp88.unk8;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &spC0, temp_f1_1108);
    temp_r3_1125 = this->unkE0;
    if ((s32) this->unkE4 > temp_r3_1125) {
        this->unk50.SetState(this, 0, 0U);
        this->unkE8 = 0;
        sp14 = 0;
        sp10 = 0x41A;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp10);
        return;
    }
    temp_f5_1158 = this->unkEC->unk30.unk8 / (f32) temp_r3_1125;
    this->unkDC += this->unkD4 * gUpdateTimeDelta;
    temp_r3_1164 = this->unkE4;
    if (((temp_f5_1158 * (f32) temp_r3_1164) + 1.0f) < this->unkDC) {
        this->unkE4 = temp_r3_1164 + 1;
        this->unk4C->DropIndividual((this->unkE0 - 1) - this->unkE4, (this->unkE4 % (s32) (1.0f / (temp_f5_1158 / this->unkD4))) == 0);
    }
    temp_r3_1199 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), void **, 8);
    sp68 = M2C_FIELD(temp_r3_1199, f64 *, 0x30);
    sp70 = M2C_FIELD(temp_r3_1199, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp78 = sp28;
    sp30 = (f32) sp70 - this->unk138;
    sp80 = (f64) sp30;
    var_f4_1224 = ((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + (unksp7C * unksp7C));
    if (var_f4_1224 > 0.0f) {
        temp_f1_1227 = __frsqrte(var_f4_1224);
        temp_f1_1233 = 0.5 * temp_f1_1227 * -(((f64) var_f4_1224 * (temp_f1_1227 * temp_f1_1227)) - 3.0);
        temp_f1_1237 = 0.5 * temp_f1_1233 * -(((f64) var_f4_1224 * (temp_f1_1233 * temp_f1_1233)) - 3.0);
        var_f4_1224 = (f32) ((f64) var_f4_1224 * (0.5 * temp_f1_1237 * -(((f64) var_f4_1224 * (temp_f1_1237 * temp_f1_1237)) - 3.0)));
    } else if (var_f4_1224 < M2C_BITWISE(f32, 0.0)) {
        var_f4_1224 = __float_nan;
    } else {
        sp8 = var_f4_1224;
        temp_r3_1256 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_1256) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1266 = 1;
            } else {
                var_r0_1266 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1266 = 5;
            } else {
                var_r0_1266 = 3;
            }
            break;
        default:
            var_r0_1266 = 4;
            break;
        }
        if (var_r0_1266 == 1) {
            var_f4_1224 = __float_nan;
        }
    }
    var_f1_1289 = var_f4_1224 * this->unkF8;
    if (var_f1_1289 < 1.0f) {

    } else {
        var_f1_1289 = 1.0f;
    }
    if (var_f1_1289 > 0.0f) {

    } else {
        var_f1_1289 = 0.0f;
    }
    var_f1_1305 = 1.2f * var_f1_1289;
    if (var_f1_1305 < 1.0f) {

    } else {
        var_f1_1305 = 1.0f;
    }
    if (var_f1_1305 > 0.0f) {

    } else {
        var_f1_1305 = 0.0f;
    }
    spAC = 0;
    sp38.GetPosition(var_f1_1305);
    sp48.GetPos();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spA8 = 0x42E;
    spB0 = sp18;
    sp20 = sp50 - sp40;
    sp58 = sp18;
    spB8 = (f64) sp20;
    sp60 = (f64) sp20;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &spA8, sp18, sp50);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void StalactiteCharge::StateSCDropEnter() {
    s8 sp9D;
    s8 sp9C;
    f32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    M2C_UNK sp50;
    f64 sp48;
    KDUniformSpline sp30;
    f64 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    f64 temp_f2_1403;

    this->unkDC = 0.0f;
    this->unkE4 = -1;
    sp74 = 0;
    spC = 0.0f;
    sp30.GetMeasure(0.0f, (Matrix *) &this->unkEC->unk30, KDSpline_PositionMixer);
    sp30.unk10 = M2C_BITWISE(f64, sp30);
    sp48 = (f64) sp30.unk8;
    MKVector(0.7f, 0.7f, 0.7f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f2_1403 = M2C_BITWISE(f64, sp30.unk10);
    sp18 = sp58 * 10.0f;
    sp70 = 0x419;
    sp88 = sp10;
    sp90 = (f64) sp18;
    sp9D = 1;
    sp78 = temp_f2_1403;
    sp80 = sp48;
    sp9C = 1;
    sp98 = 6000.0f;
    sp60 = sp10;
    sp68 = (f64) sp18;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, f64, f64, f64, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp70, 0x419, sp48, temp_f2_1403, (f64) sp18, sp10);
    sp8 = 0.0f;
    sp20.GetMeasure(0.0f, (Matrix *) &this->unkEC->unk30, KDSpline_PositionMixer);
    this->unk130 = sp20;
    M2C_FIELD(this, f64 *, 0x138) = sp28;
    this->unkF8 = 1.0f / this->unkEC->unk30.unk8;
}
#endif

void StalactiteCharge::StateSCWaitExit() {

}

void StalactiteCharge::StateSCWaitUpdate() {

}

void StalactiteCharge::StateSCWaitEnter() {

}

#if 0 // DRAFT: undefined identifier 'unk50'
void StalactiteCharge::Update() {
    KDUniformSpline sp18;
    f32 sp10;
    s32 sp8;
    KDSplinePathSegment *temp_r4_1490;
    f32 var_f1_1494;
    s32 temp_r3_1519;
    void *temp_r31_1515;

    this->unk50.Update(this, 0);
    if ((s32) M2C_FIELD(checked_cast<StalactiteChargeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) != 0) {
        if (this->unk50.GetState() == 2) {
            temp_r4_1490 = this->unkEC;
            var_f1_1494 = this->unkDC / temp_r4_1490->unk30.unk8;
            if (var_f1_1494 < 1.0f) {

            } else {
                var_f1_1494 = 1.0f;
            }
            sp10 = 0.0f;
            sp18.GetMeasure(var_f1_1494, (Matrix *) &temp_r4_1490->unk30, KDSpline_PositionMixer);
            this->unk170 = M2C_BITWISE(f64, sp18);
            this->unk178 = (f64) sp18.unk8;
        }
        temp_r31_1515 = checked_cast<StalactiteChargeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3_1519 = 2 - this->unk50.GetState();
        sp8 = 1;
        this->unk144.Update(M2C_FIELD(temp_r31_1515, s32 *, 0x60), 1U, temp_r3_1519 == 0, NULL, (MKVector3 *) &this->unk170, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    MKProp::Update();
}
#endif

#if 0 // DRAFT: expression syntax error
void StalactiteCharge::Message(MKMessage *arg0) {
    s32 temp_r0_1552;

    this->unk144.Message(arg0);
    temp_r0_1552 = arg0->unk0;
    switch (temp_r0_1552) {                         /* irregular */
    case 0xB5:
        if ((this->unk50.GetState() == 0) && ((u8) this->unkE8 != 0)) {
            this->unk50.SetState(this, 1, 0U);
        }
        break;
    case 0xD5:
        if ((u8) this->unkE8 == 0) {
            this->unk50.SetState(this, 3, 0U);
        }
        break;
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk50'
void StalactiteCharge::Resolve() {
    MKSceneManager *temp_r3_1606;
    u32 temp_r4_1605;

    temp_r4_1605 = (u32) this->unk50.SetState(this, 0, 0U);
    temp_r3_1606 = this->unkF0;
    if (temp_r3_1606 != NULL) {
        this->unkF0 = checked_cast<CutsceneProp *, MKProp>(temp_r3_1606->PropResolver_Resolve((s32) temp_r4_1605));
    }
    MKProp::Resolve();
}
#endif

#if 0 // DRAFT: undefined identifier 'unkB0'
void StalactiteCharge::LoadDone() {
    KDUniformSpline sp38;
    KDUniformSpline sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSplinePathSegment *temp_r3_1698;

    this->unkB8 = 1.0f;
    this->unkB4 = 1.0f;
    M2C_FIELD(this, f32 *, 0xB0) = 1.0f;
    this->unkC8 = -1.0f;
    this->unkC4 = -1.0f;
    this->unkC0 = -1.0f;
    M2C_FIELD(this->unk0, M2C_UNK **, 0x1C) = &this->unkB0;
    M2C_STRUCT_COPY((s32) &this->unk6C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = 0.0f;
    sp18.GetMeasure(0.0f, (Matrix *) &this->unkEC->unk30, KDSpline_PositionMixer);
    spC = 0.0f;
    sp18.unk10.GetMeasure(0.0f, (Matrix *) &this->unkEC->unk30, KDSpline_PositionMixer);
    sp8 = 0.0f;
    sp38.GetMeasure(0.0f, (Matrix *) &this->unkEC->unk30, KDSpline_PositionMixer);
    this->unkA0 = M2C_BITWISE(f32, sp38);
    this->unkA4 = sp2C;
    this->unkA8 = sp18.unk8;
    this->unkAC = 1.0f;
    this->unk8 = &this->unk70;
    this->unk4C->Init((MKProp *) this, this->unkE0, 2);
    this->unk4C->LoadDone();
    temp_r3_1698 = this->unkEC;
    if (temp_r3_1698 != NULL) {
        temp_r3_1698->LoadDone();
    }
    MKProp::LoadDone();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 StalactiteCharge::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("Width", &this->unkD0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("NumStalactites", &this->unkE0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("DropSpeed", &this->unkD4, 0) != 0) {
        this->unkD4 *= 100.0f;
        return 1U;
    }
    if (((KDSplinePathSegment *) this->unkEC == NULL) && (arg0->IsField("waypoints") != 0) && (arg0->GetNmbrOfSubLines() > 0)) {
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x30) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x34) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x38) = 0.0f;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x3C) = 0;
        }
        this->unkEC = M2C_ERROR(/* Read from unset register $r3 */);
        this->unkEC->Init();
        this->unkEC->unk44 = 0;
        this->unkEC->LoadLine(arg0);
        return 1U;
    }
    return (u8) (arg0->LoadInt("CutscenePlayerID", (s32 *) &this->unkF0, 0) != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk50'
void StalactiteCharge::Deinit() {
    IceBossStalactiteSpawner *temp_r31_1841;
    KDSplinePathSegment *temp_r3_1855;
    MKHeap *temp_r3_1842;

    this->unk50.Deinit(this);
    this->unk4C->Deinit();
    temp_r31_1841 = this->unk4C;
    temp_r3_1842 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1842 != NULL) {
        ((MKHeap *) (temp_r3_1842->Current()))->Free(temp_r31_1841, NULL, 0);
    } else {
        free(temp_r31_1841);
    }
    temp_r3_1855 = this->unkEC;
    if (temp_r3_1855 != NULL) {
        temp_r3_1855->Deinit();
        operator delete(this->unkEC);
    }
    if ((s32) M2C_FIELD(checked_cast<StalactiteChargeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) != 0) {
        KDSound_Stop(&this->unk144);
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__34KDStateMachine'
void StalactiteCharge::Init() {
    IceBossStalactiteSpawner *var_r3_1899;
    MKHeap *temp_r3_1892;

    temp_r3_1892 = ((MKHeap *) (Init__34KDStateMachine<16StalactiteCharge>FPQ234KDStateMachine<16StalactiteCharge>5StateP34KDStateMachine<16StalactiteCharge>(&this->unk50, &StalactiteChargeStates, NULL)))->Current();
    if (temp_r3_1892 != NULL) {
        var_r3_1899 = ((MKHeap *) (temp_r3_1892->Current()))->Alloc(0x28, NULL, 0);
    } else {
        var_r3_1899 = malloc(0x28);
    }
    this->unk4C = var_r3_1899;
    this->unkE8 = 0;
    this->unkEC = NULL;
    this->unkF0 = NULL;
    if ((s32) M2C_FIELD(checked_cast<StalactiteChargeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) != 0) {
        this->unk144.Init(0.25f, 0.25f);
    }
    this->unkF4 = 0.0f;
    this->unkF8 = 0.0f;
    M2C_FIELD(this, f32 *, 0x100) = 0.0f;
    M2C_FIELD(this, f32 *, 0x104) = 0.0f;
    M2C_FIELD(this, f32 *, 0x108) = 0.0f;
    M2C_FIELD(this, f32 *, 0x110) = 0.0f;
    M2C_FIELD(this, f32 *, 0x114) = 0.0f;
    M2C_FIELD(this, f32 *, 0x118) = 0.0f;
    M2C_FIELD(this, f32 *, 0x120) = 0.0f;
    M2C_FIELD(this, f32 *, 0x124) = 0.0f;
    this->unk128 = 0.0f;
    M2C_FIELD(this, f32 *, 0x130) = 0.0f;
    M2C_FIELD(this, f32 *, 0x134) = 0.0f;
    this->unk138 = 0.0f;
    M2C_FIELD(this, f32 *, 0x170) = 0.0f;
    M2C_FIELD(this, f32 *, 0x174) = 0.0f;
    M2C_FIELD(this, f32 *, 0x178) = 0.0f;
    this->unk140 = 0;
    MKProp::Init();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk50'
StalactiteCharge::StalactiteCharge() {
    this->unk50.unk0 = -1;
    this->unk54 = -1;
    this->unk58 = 0;
    this->unk5C = 0;
    this->unk144 = 0;
    return this;
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[14], long *)' does
s32 StalactiteChargeDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1977;

    var_r31_1977 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndRumbleLoop", &this->unk60) != 0)) {
        var_r31_1977 = 1;
    }
    return var_r31_1977;
}
#endif

void StalactiteChargeDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = GS_PLACEHOLDER;
}

#if 0 // DRAFT: undefined identifier 'lit_672'
void StalactiteCharge_cpp::__sinit() {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r20_2258;

    temp_r20_2258 = &lit_672 + 0x90;
    sp2C = M2C_FIELD(&lit_672, s32 *, 0x68);
    M2C_FIELD(temp_r20_2258, s32 *, 0x60) = (s32) M2C_FIELD(&lit_672, s32 *, 0x60);
    sp8 = M2C_FIELD(&lit_672, s32 *, 0x6C);
    M2C_FIELD(temp_r20_2258, s32 *, 0x68) = sp2C;
    spC = M2C_FIELD(&lit_672, s32 *, 0x70);
    M2C_FIELD(temp_r20_2258, s32 *, 0x6C) = sp8;
    sp10 = M2C_FIELD(&lit_672, s32 *, 0x74);
    M2C_FIELD(temp_r20_2258, s32 *, 0x70) = spC;
    sp14 = M2C_FIELD(&lit_672, s32 *, 0x78);
    M2C_FIELD(temp_r20_2258, s32 *, 0x74) = sp10;
    sp18 = M2C_FIELD(&lit_672, s32 *, 0x7C);
    M2C_FIELD(temp_r20_2258, s32 *, 0x78) = sp14;
    sp1C = M2C_FIELD(&lit_672, s32 *, 0x80);
    M2C_FIELD(temp_r20_2258, s32 *, 0x7C) = sp18;
    sp20 = M2C_FIELD(&lit_672, s32 *, 0x84);
    M2C_FIELD(temp_r20_2258, s32 *, 0x80) = sp1C;
    sp24 = M2C_FIELD(&lit_672, s32 *, 0x88);
    M2C_FIELD(temp_r20_2258, s32 *, 0x84) = sp20;
    M2C_FIELD(temp_r20_2258, s32 *, 0x88) = sp24;
    M2C_FIELD(&lit_672, s32 *, 0x90) = (s32) M2C_FIELD(&lit_672, s32 *, 0);
    M2C_FIELD(&lit_672, s32 *, 0x94) = (s32) M2C_FIELD(&lit_672, s32 *, 4);
    M2C_FIELD(&lit_672, s32 *, 0x98) = (s32) M2C_FIELD(&lit_672, s32 *, 8);
    M2C_FIELD(temp_r20_2258, s32 *, 0xC) = (s32) M2C_FIELD(&lit_672, s32 *, 0xC);
    M2C_FIELD(temp_r20_2258, s32 *, 0x10) = (s32) M2C_FIELD(&lit_672, s32 *, 0x10);
    M2C_FIELD(temp_r20_2258, s32 *, 0x14) = (s32) M2C_FIELD(&lit_672, s32 *, 0x14);
    M2C_FIELD(temp_r20_2258, s32 *, 0x18) = (s32) M2C_FIELD(&lit_672, s32 *, 0x18);
    M2C_FIELD(temp_r20_2258, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_672, s32 *, 0x1C);
    M2C_FIELD(temp_r20_2258, s32 *, 0x20) = (s32) M2C_FIELD(&lit_672, s32 *, 0x20);
    M2C_FIELD(temp_r20_2258, s32 *, 0x24) = (s32) M2C_FIELD(&lit_672, s32 *, 0x24);
    M2C_FIELD(temp_r20_2258, s32 *, 0x28) = (s32) M2C_FIELD(&lit_672, s32 *, 0x28);
    M2C_FIELD(temp_r20_2258, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_672, s32 *, 0x2C);
    M2C_FIELD(temp_r20_2258, s32 *, 0x30) = (s32) M2C_FIELD(&lit_672, s32 *, 0x30);
    M2C_FIELD(temp_r20_2258, s32 *, 0x34) = (s32) M2C_FIELD(&lit_672, s32 *, 0x34);
    M2C_FIELD(temp_r20_2258, s32 *, 0x38) = (s32) M2C_FIELD(&lit_672, s32 *, 0x38);
    M2C_FIELD(temp_r20_2258, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_672, s32 *, 0x3C);
    M2C_FIELD(temp_r20_2258, s32 *, 0x40) = (s32) M2C_FIELD(&lit_672, s32 *, 0x40);
    M2C_FIELD(temp_r20_2258, s32 *, 0x44) = (s32) M2C_FIELD(&lit_672, s32 *, 0x44);
    M2C_FIELD(temp_r20_2258, s32 *, 0x48) = (s32) M2C_FIELD(&lit_672, s32 *, 0x48);
    M2C_FIELD(temp_r20_2258, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_672, s32 *, 0x4C);
    M2C_FIELD(temp_r20_2258, s32 *, 0x50) = (s32) M2C_FIELD(&lit_672, s32 *, 0x50);
    M2C_FIELD(temp_r20_2258, s32 *, 0x54) = (s32) M2C_FIELD(&lit_672, s32 *, 0x54);
    M2C_FIELD(temp_r20_2258, s32 *, 0x58) = (s32) M2C_FIELD(&lit_672, s32 *, 0x58);
    M2C_FIELD(temp_r20_2258, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_672, s32 *, 0x5C);
    M2C_FIELD(temp_r20_2258, s32 *, 0x64) = (s32) M2C_FIELD(&lit_672, s32 *, 0x64);
    M2C_FIELD(temp_r20_2258, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_672, s32 *, 0x8C);
    sp28 = M2C_FIELD(&lit_672, s32 *, 0x8C);
}
#endif
