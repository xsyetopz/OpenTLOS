#include "spyro/source/DamageShieldEffect.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Texture.h"
#include "spyro/source/KDProp.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "common/gc/MKView_GC.h"
#include <m2c_macros.h>

extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal explicit conversion from 'DamageShieldEffect' to
static Texture lit_stringBase0;                        /* type too large by 0x87; unable to generate initializer: non-zero padding; const */

void DamageShieldEffect::SpawnRipple(const MKVector3 &arg0, float arg1) {
    f32 temp_f30_76;
    f32 temp_f31_81;
    s32 var_ctr_56;
    s32 var_r31_55;
    void *temp_r3_86;
    void *temp_r5_63;

    var_r31_55 = 0;
    var_ctr_56 = 0xA;
loop_1:
    if ((u8) *(this + (var_r31_55 + 0xB8)) == 0) {
        temp_r5_63 = this + var_r31_55;
        M2C_FIELD(temp_r5_63, f64 *, 0xA0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r5_63, f64 *, 0xA8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r5_63, f32 *, 0xB0) = arg1;
        M2C_FIELD(temp_r5_63, f32 *, 0xB4) = 0.0f;
        M2C_FIELD(temp_r5_63, s8 *, 0xB8) = 1;
        temp_f30_76 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
        temp_f31_81 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
        temp_r3_86 = this + var_r31_55;
        M2C_FIELD(temp_r3_86, f32 *, 0xC0) = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
        M2C_FIELD(temp_r3_86, f32 *, 0xC4) = temp_f31_81;
        M2C_FIELD(temp_r3_86, f32 *, 0xC8) = temp_f30_76;
        M2C_FIELD(temp_r3_86, f32 *, 0xCC) = 1.0f;
        return;
    }
    var_r31_55 += 0x30;
    var_ctr_56 -= 1;
    if (var_ctr_56 == 0) {
        return;
    }
    goto loop_1;
}
#endif

void DamageShieldEffect::Deinit() {
    this->unk90->Destroy();
    MKMaterial_Destroy(this->unk94);
    MKMaterial_Destroy(this->unk98);
    KDProp::Deinit();
}

#if 0 // DRAFT: undefined identifier 'identity'
void DamageShieldEffect::DrawRipples() {
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    MKVector3 sp268;
    MKVector3 sp258;
    f64 sp250;
    f64 sp248;
    MKVector3 sp238;
    f64 sp230;
    f64 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
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
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
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
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f24_349;
    f32 temp_f4_344;
    s32 var_r28_317;
    s32 var_r31_319;
    void *temp_r29_336;

    MKMaterial_SetMaterial(this->unk98);
    MKPrimitive(0xC, 0);
    MKSetMatrix(identity);
    sp120 = 0.0f;
    sp118 = 1.0f;
    sp11C = 0.0f;
    sp2E0 = (f64) sp120;
    sp2D8 = (f64) sp118;
    sp130 = 0.0f;
    sp40 = -(f32) sp2E0;
    sp128 = 0.0f;
    sp12C = 1.0f;
    sp38 = -(f32) sp2D8;
    sp3C = -unksp2DC;
    sp2E8 = (f64) sp128;
    sp2F0 = (f64) sp130;
    sp288 = (f64) sp38;
    sp290 = (f64) sp40;
    sp298.operator*(30.0f);
    sp2A8.operator*(30.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp2B8 = sp88;
    sp90 = sp2A8.unk8 + sp298.unk8;
    sp2F8 = sp88;
    sp2C0 = (f64) sp90;
    sp300 = (f64) sp90;
    sp258.operator*(30.0f);
    sp268.operator*(30.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp30 = -(f32) sp2E0;
    sp80 = sp268.unk8 + sp258.unk8;
    sp28 = -(f32) sp2D8;
    sp2C = -unksp2DC;
    sp278 = sp78;
    sp280 = (f64) sp80;
    sp308 = sp78;
    sp310 = (f64) sp80;
    sp208 = (f64) sp28;
    sp210 = (f64) sp30;
    sp218.operator*(30.0f);
    sp18 = -(f32) sp2E8;
    sp1C = -unksp2EC;
    sp20 = -(f32) sp2F0;
    sp228 = (f64) sp18;
    sp230 = (f64) sp20;
    sp238.operator*(30.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp248 = sp68;
    sp70 = sp238.unk8 + sp218.unk8;
    sp318 = sp68;
    sp250 = (f64) sp70;
    sp320 = (f64) sp70;
    sp1C8.operator*(30.0f);
    sp8 = -(f32) sp2E8;
    spC = -unksp2EC;
    sp10 = -(f32) sp2F0;
    sp1D8 = (f64) sp8;
    sp1E0 = (f64) sp10;
    sp1E8.operator*(30.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    var_r28_317 = 0;
    var_r31_319 = 0;
    sp328 = sp58;
    sp60 = sp1E8.unk8 + sp1C8.unk8;
    sp1F8 = sp58;
    sp330 = (f64) sp60;
    sp200 = (f64) sp60;
    M2C_ERROR(/* unknown instruction: psq_lx $f31, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f28, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f26, $zero, $r29, 0x0, qr0 */);
    do {
        temp_r29_336 = this + var_r31_319;
        if ((u8) M2C_FIELD(temp_r29_336, u8 *, 0xB8) != 0) {
            temp_f4_344 = 1.0f - M2C_FIELD(temp_r29_336, f32 *, 0xB4);
            sp54 = 1.0f;
            temp_f24_349 = M2C_FIELD(temp_r29_336, f32 *, 0xB0);
            sp48 = M2C_FIELD(temp_r29_336, f32 *, 0xC0) * temp_f4_344;
            sp4C = M2C_FIELD(temp_r29_336, f32 *, 0xC4) * temp_f4_344;
            sp50 = M2C_FIELD(temp_r29_336, f32 *, 0xC8) * temp_f4_344;
            sp1B8 = (f64) sp48;
            sp1C0 = (f64) sp50;
            sp2C8 = (f64) sp48;
            sp2D0 = (f64) sp50;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp2C8));
            MKSetTexCoord1F(1.0f, 1.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f31, $f24 */);
            sp110 = (f32) sp310 * temp_f24_349;
            sp198 = sp108;
            sp1A0 = (f64) sp110;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1A8 = spF8;
            sp100 = (f32) sp1A0 + M2C_FIELD(temp_r29_336, f32 *, 0xA8);
            sp1B0 = (f64) sp100;
            MKSetPositionV(*((MKVector3 *) &sp1A8));
            MKSetColorV(*((MKVector4 *) &sp2C8));
            MKSetTexCoord1F(0.0f, 1.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
            spF0 = (f32) sp300 * temp_f24_349;
            sp178 = spE8;
            sp180 = (f64) spF0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp188 = spD8;
            spE0 = (f32) sp180 + M2C_FIELD(temp_r29_336, f32 *, 0xA8);
            sp190 = (f64) spE0;
            MKSetPositionV(*((MKVector3 *) &sp188));
            MKSetColorV(*((MKVector4 *) &sp2C8));
            MKSetTexCoord1F(1.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f28, $f24 */);
            spD0 = (f32) sp330 * temp_f24_349;
            sp158 = spC8;
            sp160 = (f64) spD0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp168 = spB8;
            spC0 = (f32) sp160 + M2C_FIELD(temp_r29_336, f32 *, 0xA8);
            sp170 = (f64) spC0;
            MKSetPositionV(*((MKVector3 *) &sp168));
            MKSetColorV(*((MKVector4 *) &sp2C8));
            MKSetTexCoord1F(0.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f26, $f24 */);
            spB0 = (f32) sp320 * temp_f24_349;
            sp138 = spA8;
            sp140 = (f64) spB0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp148 = sp98;
            spA0 = (f32) sp140 + M2C_FIELD(temp_r29_336, f32 *, 0xA8);
            sp150 = (f64) spA0;
            MKSetPositionV(*((MKVector3 *) &sp148));
            MKEnd();
        }
        var_r28_317 += 1;
        var_r31_319 += 0x30;
    } while (var_r28_317 < 0xA);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void DamageShieldEffect::Draw() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_531;

    if ((s32) this->unk280 != 3) {
        MKView_Push();
        MKView_SetRenderTarget(this->unk90, NULL);
        MKView_Clear(3, zero, 0.0f, 0U);
        DrawRipples();
        MKView_Pop();
        gRenderState = this->unk94;
        temp_f1_531 = this->unk288;
        sp14 = 1.0f;
        sp10 = temp_f1_531;
        sp8 = temp_f1_531;
        spC = temp_f1_531;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp18));
        MKModel_Draw(this->unk4, NULL);
        gRenderState = NULL;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void DamageShieldEffect::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_649;
    f32 temp_f2_678;
    f32 temp_f31_610;
    f32 temp_f3_619;
    s32 temp_r0_637;
    s32 var_ctr_574;
    s32 var_r3_569;
    void *temp_r5_576;

    if ((s32) this->unk280 != 3) {
        var_r3_569 = 0;
        var_ctr_574 = 0xA;
        do {
            temp_r5_576 = this + var_r3_569;
            if ((u8) M2C_FIELD(temp_r5_576, u8 *, 0xB8) != 0) {
                M2C_FIELD(temp_r5_576, f32 *, 0xB4) = (f32) (M2C_FIELD(temp_r5_576, f32 *, 0xB4) + gUpdateTimeDelta);
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (M2C_FIELD(temp_r5_576, f32 *, 0xB4) == 1.0f) {
                    M2C_FIELD(temp_r5_576, u8 *, 0xB8) = 0U;
                } else {
                    M2C_FIELD(temp_r5_576, f32 *, 0xB0) = (f32) ((8.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r5_576, f32 *, 0xB0));
                }
            }
            var_r3_569 += 0x30;
            var_ctr_574 -= 1;
        } while (var_ctr_574 != 0);
        this->unk9C -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk9C == 0.0f) {
            temp_f31_610 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            temp_f3_619 = 640.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            sp10 = 0.0f;
            sp8 = temp_f3_619;
            spC = 480.0f * temp_f31_610;
            sp20 = (f64) sp10;
            sp18 = (f64) sp8;
            SpawnRipple(*((MKVector3 *) &sp18), 0.0f);
            this->unk9C = 0.125f;
        }
        this->unk284 += gUpdateTimeDelta;
        temp_r0_637 = this->unk280;
        switch (temp_r0_637) {                      /* irregular */
        case 0:
            temp_f1_649 = this->unk284;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f1_649 == 2.0f) {
                this->unk280 = 1;
                this->unk284 = 0.0f;
                return;
            }
            this->unk288 = temp_f1_649 * 0.5f;
            return;
        case 1:
            this->unk288 = 1.0f;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (this->unk284 == 6.0f) {
                this->unk280 = 2;
                this->unk284 = 0.0f;
                return;
            }
            break;
        case 2:
            temp_f2_678 = this->unk284;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f2_678 == 2.0f) {
                this->unk280 = 3;
                return;
            }
            this->unk288 = -((temp_f2_678 * 0.5f) - 1.0f);
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void DamageShieldEffect::Init() {
    s32 var_ctr_725;
    s32 var_r4_720;
    void *temp_r3_727;

    KDProp::Init();
    lit_stringBase0.CreateRenderTarget((s8 *)0x40, 0x40, 0, M2C_ERROR(/* Read from unset register $r7 */));
    this->unk90 = M2C_ERROR(/* Read from unset register $r3 */);
    var_r4_720 = 0;
    this->unk94 = MKMaterial_Create(&lit_stringBase0.unk0);
    var_ctr_725 = 0xA;
    do {
        temp_r3_727 = this + var_r4_720;
        var_r4_720 += 0x30;
        M2C_FIELD(temp_r3_727, s8 *, 0xB8) = 0;
        M2C_FIELD(temp_r3_727, f32 *, 0xB0) = 0.0f;
        M2C_FIELD(temp_r3_727, f32 *, 0xB4) = 0.0f;
        var_ctr_725 -= 1;
    } while (var_ctr_725 != 0);
    this->unk98 = MKMaterial_Create(&lit_stringBase0.unk11);
    this->unk9C = 0.0f;
    this->unk280 = 3;
    this->unk284 = 0.0f;
}
#endif
