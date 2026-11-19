#include "spyro/source/LavaSmashProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/LavaBubbleFX.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

f64 fmod(f32, f64);                                 /* extern */
extern s32 GS_PLACEHOLDER;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void LavaSmashProp::PostShatter() {
    s8 sp288;
    f64 sp280;
    f64 sp278;
    s32 sp274;
    s32 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    MKVector3 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    MKVector3 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    MKVector3 sp1A0;
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
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp108;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spB8;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_203;
    f32 temp_f1_255;
    f32 temp_f1_416;
    f32 temp_f4_417;
    f32 var_f0_126;
    f32 var_f3_330;
    f32 var_f4_263;
    f32 var_f4_59;
    f64 temp_f1_269;
    f64 temp_f1_275;
    f64 temp_f1_279;
    f64 temp_f1_433;
    f64 temp_f1_62;
    f64 temp_f1_68;
    f64 temp_f1_72;
    s32 temp_r3_298;
    s32 temp_r3_91;
    s32 var_r0_101;
    s32 var_r0_308;
    void *temp_r30_29;
    void *temp_r3_32;
    void *temp_r5_27;

    if (!(M2C_BITWISE(f32, this->unk168) > 0.0f)) {
        temp_r5_27 = this->unk8;
        temp_r30_29 = checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3_32 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        sp220 = M2C_FIELD(temp_r5_27, f64 *, 0x30);
        sp230 = M2C_FIELD(temp_r3_32, f64 *, 0x30);
        sp228 = M2C_FIELD(temp_r5_27, f64 *, 0x38);
        sp238 = M2C_FIELD(temp_r3_32, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp240 = sp100;
        sp108 = (f32) sp238 - (f32) sp228;
        sp248 = (f64) sp108;
        var_f4_59 = ((f32) sp248 * (f32) sp248) + (((f32) sp240 * (f32) sp240) + (unksp244 * unksp244));
        if (var_f4_59 > 0.0f) {
            temp_f1_62 = __frsqrte(var_f4_59);
            temp_f1_68 = 0.5 * temp_f1_62 * -(((f64) var_f4_59 * (temp_f1_62 * temp_f1_62)) - 3.0);
            temp_f1_72 = 0.5 * temp_f1_68 * -(((f64) var_f4_59 * (temp_f1_68 * temp_f1_68)) - 3.0);
            var_f4_59 = (f32) ((f64) var_f4_59 * (0.5 * temp_f1_72 * -(((f64) var_f4_59 * (temp_f1_72 * temp_f1_72)) - 3.0)));
        } else if (var_f4_59 < M2C_BITWISE(f32, 0.0)) {
            var_f4_59 = __float_nan;
        } else {
            spC = var_f4_59;
            temp_r3_91 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_91) {                   /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_101 = 1;
                } else {
                    var_r0_101 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_101 = 5;
                } else {
                    var_r0_101 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_101 = 4;
                break;
            }
            if (var_r0_101 == 1) {
                var_f4_59 = __float_nan;
            }
        }
        var_f0_126 = 25.0f - (var_f4_59 / 100.0f);
        if (var_f0_126 < 25.0f) {

        } else {
            var_f0_126 = 25.0f;
        }
        if (var_f0_126 > 0.0f) {

        } else {
            var_f0_126 = 0.0f;
        }
        sp78 = -0.5f;
        sp68 = 0.5f;
        this->unk1E8.unk8 = var_f0_126;
        sp70 = -0.5f;
        sp74 = 0.0f;
        sp60 = 0.5f;
        sp64 = 3.5f;
        sp1D0 = (f64) sp70;
        sp1D8 = (f64) sp78;
        sp1C0 = (f64) sp60;
        sp1C8 = (f64) sp68;
        KDRand_Vector(sp1E0, *((MKVector3 *) &sp1D0));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp1F0 = sp50;
        sp58 = sp1E0.unk8 * 50.0f;
        sp1F8 = (f64) sp58;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp200 = sp40;
        sp48 = M2C_FIELD(this, f32 *, 0x1E0) + (f32) sp1F8;
        sp208 = (f64) sp48;
        KDMath_Smooth<MKVector3>(sp210, *((MKVector3 *) &this->unk1D8), 2.0f, gUpdateTimeDelta);
        this->unk1D8 = M2C_BITWISE(f64, sp210);
        M2C_FIELD(this, f64 *, 0x1F0) = (f64) sp210.unk8;
        this->unk1E8.unk0 += M2C_FIELD(temp_r30_29, f32 *, 0x178) * gUpdateTimeDelta;
        temp_f1_203 = this->unk1E8.unk0;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_203 == M2C_FIELD(temp_r30_29, f32 *, 0x174)) {
            SetSmashPropState((SmashPropState) 3);
            M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) & ~0x40);
            this->unk1D0 = 0;
            return;
        }
        sp34 = temp_f1_203;
        sp30 = 0.0f;
        sp38 = 0.0f;
        M2C_FIELD(this, f64 *, 0x130) = (f64) sp30;
        sp1B0 = (f64) sp30;
        sp1B8 = (f64) sp38;
        this->unk138 = (f64) sp38;
        if (MKRand_Int(&gViewSeed, 0, 0xA) == 0) {
            spF8 = -1.0f;
            spE8 = 1.0f;
            spF0 = -1.0f;
            spF4 = 0.0f;
            spE0 = 1.0f;
            spE4 = 0.0f;
            sp190 = (f64) spF0;
            sp198 = (f64) spF8;
            sp180 = (f64) spE0;
            sp188 = (f64) spE8;
            KDRand_Vector(sp1A0, *((MKVector3 *) &sp190));
            temp_f1_255 = M2C_BITWISE(f32, sp1A0);
            var_f4_263 = (sp1A0.unk8 * sp1A0.unk8) + ((temp_f1_255 * temp_f1_255) + (sp1A0.unk4 * sp1A0.unk4));
            if (var_f4_263 > 1e-12f) {
                if (var_f4_263 > 0.0f) {
                    temp_f1_269 = __frsqrte(var_f4_263);
                    temp_f1_275 = 0.5 * temp_f1_269 * -(((f64) var_f4_263 * (temp_f1_269 * temp_f1_269)) - 3.0);
                    temp_f1_279 = 0.5 * temp_f1_275 * -(((f64) var_f4_263 * (temp_f1_275 * temp_f1_275)) - 3.0);
                    var_f4_263 = (f32) ((f64) var_f4_263 * (0.5 * temp_f1_279 * -(((f64) var_f4_263 * (temp_f1_279 * temp_f1_279)) - 3.0)));
                } else if (var_f4_263 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_263 = __float_nan;
                } else {
                    sp8 = var_f4_263;
                    temp_r3_298 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_298) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_308 = 1;
                        } else {
                            var_r0_308 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_308 = 5;
                        } else {
                            var_r0_308 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_308 = 4;
                        break;
                    }
                    if (var_r0_308 == 1) {
                        var_f4_263 = __float_nan;
                    }
                }
                var_f3_330 = 1.0f / var_f4_263;
            } else {
                var_f3_330 = 0.0f;
            }
            spD0 = M2C_BITWISE(f32, sp1A0) * var_f3_330;
            spD4 = sp1A0.unk4 * var_f3_330;
            spD8 = sp1A0.unk8 * var_f3_330;
            sp260 = (f64) spD0;
            sp268 = (f64) spD8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp170 = spC0;
            spC8 = (f32) sp268 * M2C_FIELD(temp_r30_29, f32 *, 0x16C);
            sp178 = (f64) spC8;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp88 = 1.0f;
            spA8 = 0.0f;
            sp80 = 1.0f;
            sp84 = 1.0f;
            spB8 = this->unk1E0 + (f32) sp178;
            sp140 = (f64) sp80;
            sp148 = (f64) sp88;
            spA0 = 0.0f;
            spA4 = M2C_FIELD(temp_r30_29, f32 *, 0x170);
            sp250 = spB0;
            sp150 = (f64) spA0;
            sp258 = (f64) spB8;
            sp158 = (f64) spA8;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp160 = sp90;
            sp98 = (f32) sp258 + (f32) sp158;
            sp168 = (f64) sp98;
            ((LavaBubbleFX *) (M2C_FIELD(&gb, LavaBubbleFX **, 0x90)))->CreateBubble(*((MKVector3 *) &sp160), *((MKVector3 *) &sp140));
        }
        this->unk1D0 = 1;
        sp274 = 0;
        temp_f1_416 = this->unk1E8.unk8;
        temp_f4_417 = -temp_f1_416;
        sp18 = temp_f1_416;
        sp28 = temp_f4_417;
        sp10 = temp_f1_416;
        sp14 = temp_f1_416;
        sp20 = temp_f4_417;
        sp24 = temp_f4_417;
        sp110 = (f64) sp10;
        sp118 = (f64) sp18;
        sp120 = (f64) sp20;
        sp128 = (f64) sp28;
        KDRand_Vector(sp130, *((MKVector3 *) &sp120));
        temp_f1_433 = M2C_BITWISE(f64, sp130);
        sp270 = 0x417;
        sp278 = temp_f1_433;
        sp280 = (f64) sp130.unk8;
        sp288 = 0;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp270, temp_f1_433);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void LavaSmashProp::Message(MKMessage *arg0) {
    Shatterable::Message(arg0);
    this->unk198.Message(arg0);
}
#endif

#if 0 // DRAFT: ')' expected
void LavaSmashProp::Update() {
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    f32 temp_f1_612;
    void *temp_r4_577;

    Shatterable::Update();
    if ((s32) M2C_FIELD(checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x17C) != 0) {
        temp_r4_577 = checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk198.Update(M2C_FIELD(temp_r4_577, s32 *, 0x17C), 1U, this->unk1D0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) this->unk16C == 3) {
        this->unk1E8.unk4 += gUpdateTimeDelta;
        temp_f1_612 = 0.5f * (this->unk1E8.unkC * (1.0f + _table_sinf(0.5f * (6.2831855f * (f32) fmod(this->unk1E8.unk4, 2.0)))));
        sp10 = this->unk108 + temp_f1_612;
        sp14 = this->unk108 - temp_f1_612;
        sp18 = this->unk10C - temp_f1_612;
        sp1C = this->unk110;
        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp10));
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void LavaSmashProp::Resolve() {
    void *temp_r31_644;

    Shatterable::Resolve();
    temp_r31_644 = checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk198.Init(M2C_FIELD(checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x180), M2C_FIELD(temp_r31_644, f32 *, 0x184));
    this->unk1D0 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1E8'
void LavaSmashProp::Reset() {
    Shatterable::Reset();
    this->unk1E8.unk4 = 1.5f;
    this->unk1E8.unk8 = 0.0f;
    this->unk1D0 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1D8'
void LavaSmashProp::LoadDone() {
    Shatterable::LoadDone();
    this->unk1D8 = M2C_FIELD(&loadInfo, f64 *, 0x40);
    M2C_FIELD(this, f64 *, 0x1F0) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x48);
    this->unk1D8 = this->unk1D8;
    M2C_FIELD(this, f64 *, 0x1E0) = (f64) M2C_FIELD(this, f64 *, 0x1F0);
    M2C_FIELD(this, f64 *, 0x108) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0x110) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x78);
    this->unk1E8.unkC = 1.0f - this->unk108;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void LavaSmashProp::Deinit() {
    Shatterable::Deinit();
    KDSound_Stop((s32 *) &this->unk198);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1E8'
void LavaSmashProp::Init() {
    Shatterable::Init();
    this->unk1E8.unk0 = 0.0f;
    this->unk1E8.unk4 = 1.5f;
    this->unk1E8.unk8 = 0.0f;
    this->unk1D0 = 0;
    this->unk1E8.unkC = 0.0f;
}
#endif

void LavaSmashPropDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk16C *= 100.0f;
    this->unk170 *= 100.0f;
    this->unk174 *= 100.0f;
    this->unk178 *= 100.0f;
}

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[16], long *)' does
s32 LavaSmashPropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_796;

    var_r31_796 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("burnRadius", &this->unk16C, 0) != 0) || (arg0->LoadFloat("lavaBubbleYOffset", &this->unk170, 0) != 0) || (arg0->LoadFloat("sinkSpeed", &this->unk178, 0) != 0) || (arg0->LoadFloat("sinkDepth", &this->unk174, 0) != 0) || (arg0->LoadFloat("LavaSoundFadeIn", &this->unk180, 0) != 0) || (arg0->LoadFloat("LavaSoundFadeOut", &this->unk184, 0) != 0) || (KDSound_LoadLine(arg0, "LavaBubbleSound", &this->unk17C) != 0)) {
        var_r31_796 = 1;
    }
    return var_r31_796;
}
#endif

void LavaSmashPropDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk16C = 0.0f;
    this->unk170 = 0.0f;
    this->unk174 = 0.0f;
    this->unk178 = 0.02f;
    this->unk180 = 0.25f;
    this->unk184 = 0.25f;
    this->unk17C = GS_PLACEHOLDER;
}
