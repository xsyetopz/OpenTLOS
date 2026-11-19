#include "common/Source/MKDynamicBone.h"
#include "common/Source/Animation.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"
#include "common/Source/MKSystem.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'gDynamicBones' redeclared
f64 atan2(f32, f32, f32, f32, f32);                 /* extern */
M2C_UNK free(MKDynamicBone **);                     /* extern */
MKDynamicBone **malloc(s32);                        /* extern */
extern void **gDynamicBones;
#endif
extern M2C_UNK gEmptyPtrListDL;
extern MKHeap gMKDefaults;
extern f32 gUpdateTimeDelta;
extern MKDynamicBone **spareTemplates;
#if 0 // DRAFT: identifier 'gDynamicBoneEnable' redeclared
static u32 gDynamicBoneEnable = 1U;
#endif

void MKDynamicBone::DefaultUpdater(MKDynamicBone *arg0, void *arg1) {
    Update();
}

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to
void MKDynamicBone::Reset() {
    Matrix spE0;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s16 sp10;
    Animation *temp_r3_49;
    Matrix *temp_r30_34;
    f32 temp_f31_37;
    f64 temp_f0_148;
    f64 temp_f0_160;
    s16 temp_r29_36;
    s32 temp_r31_47;
    u16 temp_r28_38;
    u32 temp_r0_62;

    temp_r30_34 = this->unk20;
    temp_r29_36 = M2C_FIELD(temp_r30_34, s16 *, 0x70);
    temp_f31_37 = M2C_FIELD(temp_r30_34, f32 *, 0x74);
    temp_r28_38 = M2C_FIELD(temp_r30_34, u16 *, 0x72);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r29_36, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r31_47 = MKModel_GetWorldMatrix(this->unk24);
    temp_r3_49 = MKModel_GetAnimation(this->unk24);
    sp10 = temp_r29_36;
    temp_r3_49->CalculateMatrices(&spE0, 1, &sp10, (Matrix *) temp_r31_47);
    spE0.Multiply(temp_r30_34, &spE0);
    temp_r0_62 = temp_r28_38 & 0x1E;
    spC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    spD0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    switch (temp_r0_62) {
    case 2:
        spC8 = M2C_BITWISE(f64, spE0);
        spD0 = (f64) spE0.unk8;
        break;
    case 4:
        spC8 = (f64) spE0.unk10;
        spD0 = (f64) spE0.unk18;
        break;
    case 8:
        spC8 = (f64) spE0.unk20;
        spD0 = (f64) spE0.unk28;
        break;
    case 18:
        sp58 = -M2C_BITWISE(f32, spE0);
        sp5C = -spE0.unk4;
        sp60 = -spE0.unk8;
        spB8 = (f64) sp58;
        spC0 = (f64) sp60;
        spC8 = (f64) sp58;
        spD0 = (f64) sp60;
        break;
    case 20:
        sp48 = -spE0.unk10;
        sp4C = -spE0.unk14;
        sp50 = -spE0.unk18;
        spA8 = (f64) sp48;
        spB0 = (f64) sp50;
        spC8 = (f64) sp48;
        spD0 = (f64) sp50;
        break;
    case 24:
        sp38 = -spE0.unk20;
        sp3C = -spE0.unk24;
        sp40 = -spE0.unk28;
        sp98 = (f64) sp38;
        spA0 = (f64) sp40;
        spC8 = (f64) sp38;
        spD0 = (f64) sp40;
        break;
    }
    Normalise(sp68);
    temp_f0_148 = sp68 * (f64) temp_f31_37;
    sp28 = temp_f0_148;
    sp78 = temp_f0_148;
    sp30 = sp68.unk8 * temp_f31_37;
    sp80 = (f64) sp30;
    temp_f0_160 = spE0.unk30 + temp_f0_148;
    sp18 = temp_f0_160;
    M2C_FIELD(this, f64 *, 0) = temp_f0_160;
    sp88 = temp_f0_160;
    sp20 = spE0.unk38 + (f32) sp80;
    M2C_FIELD(this, f64 *, 8) = (f64) sp20;
    sp90 = (f64) sp20;
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 8);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MKDynamicBone::Update() {
    Matrix sp6A0;
    Matrix sp660;
    Matrix sp620;
    Matrix sp5E0;
    M2C_UNK sp5DC;
    f64 sp5D0;                                      /* compiler-managed */
    f64 sp5C8;
    f64 sp5C0;                                      /* compiler-managed */
    f64 sp5B8;
    f64 sp5B0;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp598;
    f64 sp590;
    f64 sp588;
    f64 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp560;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    f64 sp510;
    f64 sp508;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    MKVector3 sp4B8;
    MKVector3 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    MKVector3 sp408;
    MKVector3 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f32 sp388;
    f64 sp380;
    f64 sp378;
    MKVector3 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    MKVector3 sp328;
    f64 sp320;
    f64 sp318;
    MKVector3 sp308;
    MKVector3 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    MKVector3 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    MKVector3 sp298;
    MKVector3 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    MKVector3 sp228;
    f32 sp220;
    f64 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f64 sp1D8;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f64 sp198;
    f32 sp190;
    f64 sp188;
    f32 sp180;
    f64 sp178;
    f32 sp170;
    f64 sp168;
    f32 sp160;
    f64 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    s16 sp12;
    s16 sp10;
    Animation *temp_r3_236;
    Animation *temp_r3_254;
    Matrix *temp_r28_220;
    Matrix *temp_r31_217;
    f32 temp_f0_1035;
    f32 temp_f0_507;
    f32 temp_f0_526;
    f32 temp_f0_847;
    f32 temp_f0_941;
    f32 temp_f1_1058;
    f32 temp_f1_468;
    f32 temp_f1_500;
    f32 temp_f1_711;
    f32 temp_f1_870;
    f32 temp_f1_964;
    f32 temp_f22_404;
    f32 temp_f22_701;
    f32 temp_f23_224;
    f32 temp_f24_223;
    f32 temp_f25_222;
    f32 temp_f3_410;
    f32 temp_f3_698;
    f32 temp_f8_1005;
    f32 temp_f8_818;
    f32 temp_f8_911;
    f32 var_f28_479;
    f32 var_f28_631;
    f32 var_f29_444;
    f64 temp_f0_1082;
    f64 temp_f0_408;
    f64 temp_f0_485;
    f64 temp_f0_503;
    f64 temp_f0_550;
    f64 temp_f1_530;
    f64 temp_f2_405;
    f64 temp_f2_496;
    f64 temp_f3_518;
    f64 temp_f5_634;
    f64 temp_f5_640;
    f64 temp_f5_644;
    s16 temp_r29_219;
    s32 temp_r26_234;
    s32 temp_r26_252;
    s32 temp_r30_391;
    s32 temp_r3_663;
    s32 var_r0_673;
    s8 temp_r25_232;
    u16 temp_r30_221;
    u32 temp_r26_277;

    temp_r31_217 = this->unk20;
    temp_r29_219 = M2C_FIELD(temp_r31_217, s16 *, 0x70);
    temp_r28_220 = temp_r31_217 + 0x40;
    temp_r30_221 = M2C_FIELD(temp_r31_217, u16 *, 0x72);
    temp_f25_222 = M2C_FIELD(temp_r31_217, f32 *, 0x74);
    temp_f24_223 = M2C_FIELD(temp_r31_217, f32 *, 0x7C);
    temp_f23_224 = M2C_FIELD(temp_r31_217, f32 *, 0x78);
    temp_r25_232 = (s8) M2C_FIELD((M2C_FIELD(MKModel_GetAnimation(this->unk24)->unk0, s32 *, 0x28) + (temp_r29_219 << 5)), u8 *, 0x36);
    temp_r26_234 = MKModel_GetWorldMatrix(this->unk24);
    temp_r3_236 = MKModel_GetAnimation(this->unk24);
    sp12 = (s16) temp_r25_232;
    temp_r3_236->CalculateMatrices(&sp620, 1, &sp12, (Matrix *) temp_r26_234);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r29_219, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r26_252 = MKModel_GetWorldMatrix(this->unk24);
    temp_r3_254 = MKModel_GetAnimation(this->unk24);
    sp10 = temp_r29_219;
    temp_r3_254->CalculateMatrices(&sp660, 1, &sp10, (Matrix *) temp_r26_252);
    M2C_STRUCT_COPY((s32) &sp5DC + 4, (s32) &sp620.unk3C + 4, 0x40);
    if (((u32) gDynamicBoneEnable != 0U) && ((u8) this->unk30 != 0)) {
        temp_r26_277 = temp_r30_221 & 0x1E;
        if (temp_r26_277 != 0) {
            sp6A0.Multiply(temp_r31_217, &sp660);
            sp588 = (f64) sp6A0.unk30;
            sp590 = (f64) sp6A0.unk38;
            sp558 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
            sp560 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
            switch (temp_r26_277) {                 /* switch 1 */
            case 2:                                 /* switch 1 */
                sp558 = M2C_BITWISE(f64, sp6A0);
                sp560 = (f64) sp6A0.unk8;
                break;
            case 4:                                 /* switch 1 */
                sp558 = (f64) sp6A0.unk10;
                sp560 = (f64) sp6A0.unk18;
                break;
            case 8:                                 /* switch 1 */
                sp558 = (f64) sp6A0.unk20;
                sp560 = (f64) sp6A0.unk28;
                break;
            case 18:                                /* switch 1 */
                sp1C8 = -M2C_BITWISE(f32, sp6A0);
                sp1CC = -sp6A0.unk4;
                sp1D0 = -sp6A0.unk8;
                sp4F8 = (f64) sp1C8;
                sp500 = (f64) sp1D0;
                sp558 = (f64) sp1C8;
                sp560 = (f64) sp1D0;
                break;
            case 20:                                /* switch 1 */
                sp1B8 = -sp6A0.unk10;
                sp1BC = -sp6A0.unk14;
                sp1C0 = -sp6A0.unk18;
                sp4E8 = (f64) sp1B8;
                sp4F0 = (f64) sp1C0;
                sp558 = (f64) sp1B8;
                sp560 = (f64) sp1C0;
                break;
            case 24:                                /* switch 1 */
                sp1A8 = -sp6A0.unk20;
                sp1AC = -sp6A0.unk24;
                sp1B0 = -sp6A0.unk28;
                sp4D8 = (f64) sp1A8;
                sp4E0 = (f64) sp1B0;
                sp558 = (f64) sp1A8;
                sp560 = (f64) sp1B0;
                break;
            }
            Normalise(sp4A8);
            sp4B8.operator*(temp_f25_222);
            sp198 = sp588 + M2C_BITWISE(f64, sp4B8);
            sp4C8 = sp198;
            sp1A0 = (f32) sp590 + sp4B8.unk8;
            sp5A8 = sp198;
            sp4D0 = (f64) sp1A0;
            sp5B0 = (f64) sp1A0;
        }
        temp_r30_391 = temp_r30_221 & 0xE0;
        if (temp_r30_391 != 0) {
            sp6A0.Multiply(temp_r31_217, &sp660);
            sp5A8 = (f64) sp6A0.unk30;
            sp5B0 = (f64) sp6A0.unk38;
        }
        temp_f22_404 = 1.0f / gUpdateTimeDelta;
        temp_f2_405 = M2C_FIELD(this, f64 *, 0);
        temp_f0_408 = temp_f2_405 - M2C_FIELD(this, f64 *, 0x10);
        sp38 = temp_f0_408;
        temp_f3_410 = this->unk8;
        sp488 = temp_f0_408;
        sp40 = temp_f3_410 - this->unk18;
        sp490 = (f64) sp40;
        sp188 = temp_f0_408 * (f64) temp_f22_404;
        sp498 = sp188;
        sp190 = (f32) sp490 * temp_f22_404;
        sp5C8 = sp188;
        sp4A0 = (f64) sp190;
        sp5D0 = (f64) sp190;
        sp178 = sp5A8 - temp_f2_405;
        sp478 = sp178;
        sp180 = (f32) sp5B0 - temp_f3_410;
        sp598 = sp178;
        sp480 = (f64) sp180;
        sp5A0 = (f64) sp180;
        if (temp_f24_223 < temp_f22_404) {
            var_f29_444 = temp_f24_223;
        } else {
            var_f29_444 = temp_f22_404;
        }
        sp28 = -(f32) sp5C8;
        sp2C = -unksp5CC;
        sp30 = -(f32) sp5D0;
        sp458 = (f64) sp28;
        sp460 = (f64) sp30;
        sp168 = sp458 * (f64) var_f29_444;
        temp_f1_468 = 1.0f / (gUpdateTimeDelta * gUpdateTimeDelta);
        sp468 = sp168;
        sp5B8 = sp168;
        sp170 = (f32) sp460 * var_f29_444;
        sp470 = (f64) sp170;
        sp5C0 = (f64) sp170;
        if (temp_f23_224 < temp_f1_468) {
            var_f28_479 = temp_f23_224;
        } else {
            var_f28_479 = temp_f1_468;
        }
        temp_f0_485 = sp598 * (f64) var_f28_479;
        sp158 = temp_f0_485;
        sp448 = temp_f0_485;
        sp160 = (f32) sp5A0 * var_f28_479;
        sp450 = (f64) sp160;
        temp_f2_496 = sp5B8 + temp_f0_485;
        sp5B8 = temp_f2_496;
        temp_f1_500 = (f32) sp5C0 + (f32) sp450;
        sp5C0 = temp_f1_500;
        temp_f0_503 = temp_f2_496 + M2C_FIELD(temp_r28_220, f64 *, 0);
        sp5B8 = temp_f0_503;
        temp_f0_507 = temp_f1_500 + temp_r28_220->unk8;
        sp5C0 = temp_f0_507;
        sp148 = temp_f0_503 * (f64) gUpdateTimeDelta;
        sp150 = temp_f0_507 * gUpdateTimeDelta;
        sp438 = sp148;
        sp440 = (f64) sp150;
        temp_f3_518 = sp5C8 + sp438;
        sp5C8 = temp_f3_518;
        M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0);
        M2C_FIELD(this, f32 *, 0x18) = (f64) M2C_FIELD(this, f32 *, 8);
        temp_f0_526 = (f32) sp5D0 + (f32) sp440;
        sp5D0 = temp_f0_526;
        temp_f1_530 = temp_f3_518 * (f64) gUpdateTimeDelta;
        sp138 = temp_f1_530;
        sp140 = temp_f0_526 * gUpdateTimeDelta;
        sp428 = temp_f1_530;
        sp430 = (f64) sp140;
        M2C_FIELD(this, f64 *, 0) = (f64) (M2C_FIELD(this, f64 *, 0) + sp428);
        this->unk8 += (f32) sp430;
        if ((s32) temp_r26_277 != 0) {
            temp_f0_550 = M2C_FIELD(this, f64 *, 0) - sp588;
            sp18 = temp_f0_550;
            sp3E8 = temp_f0_550;
            sp20 = this->unk8 - (f32) sp590;
            sp3F0 = (f64) sp20;
            Normalise(sp3F8);
            sp408.operator*(temp_f25_222);
            sp128 = sp588 + M2C_BITWISE(f64, sp408);
            M2C_FIELD(this, f64 *, 0) = sp128;
            sp130 = (f32) sp590 + sp408.unk8;
            sp418 = sp128;
            M2C_FIELD(this, f32 *, 8) = (f64) sp130;
            sp420 = (f64) sp130;
            sp118 = M2C_FIELD(this, f64 *, 0) - sp588;
            sp3D8 = sp118;
            sp120 = this->unk8 - (f32) sp590;
            sp578 = sp118;
            sp3E0 = (f64) sp120;
            sp580 = (f64) sp120;
            sp108 = sp5A8 - sp588;
            sp110 = (f32) sp5B0 - (f32) sp590;
            sp568 = sp108;
            sp570 = (f64) sp110;
            sp3C8 = sp108;
            sp3D0 = (f64) sp110;
            spF8 = (unksp56C * (f32) sp580) - ((f32) sp570 * unksp57C);
            spFC = ((f32) sp570 * (f32) sp578) - ((f32) sp568 * (f32) sp580);
            sp100 = ((f32) sp568 * unksp57C) - (unksp56C * (f32) sp578);
            sp548 = (f64) spF8;
            sp550 = (f64) sp100;
            sp3B8 = (f64) spF8;
            sp3C0 = (f64) sp100;
            var_f28_631 = ((f32) sp550 * (f32) sp550) + (((f32) sp548 * (f32) sp548) + (unksp54C * unksp54C));
            if (var_f28_631 > 0.0f) {
                temp_f5_634 = __frsqrte(var_f28_631);
                temp_f5_640 = 0.5 * temp_f5_634 * -(((f64) var_f28_631 * (temp_f5_634 * temp_f5_634)) - 3.0);
                temp_f5_644 = 0.5 * temp_f5_640 * -(((f64) var_f28_631 * (temp_f5_640 * temp_f5_640)) - 3.0);
                var_f28_631 = (f32) ((f64) var_f28_631 * (0.5 * temp_f5_644 * -(((f64) var_f28_631 * (temp_f5_644 * temp_f5_644)) - 3.0)));
            } else if (var_f28_631 < M2C_BITWISE(f32, 0.0)) {
                var_f28_631 = __float_nan;
            } else {
                sp14 = var_f28_631;
                temp_r3_663 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_663) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_673 = 1;
                    } else {
                        var_r0_673 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_673 = 5;
                    } else {
                        var_r0_673 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_673 = 4;
                    break;
                }
                if (var_r0_673 == 1) {
                    var_f28_631 = __float_nan;
                }
            }
            temp_f3_698 = ((f32) sp578 * (f32) sp568) + (unksp57C * unksp56C);
            temp_f22_701 = (f32) atan2(var_f28_631, ((f32) sp580 * (f32) sp570) + temp_f3_698, temp_f3_698, (f32) sp568, (f32) sp578);
            if (temp_f22_701 != 0.0f) {
                sp6A0.SetIdentity();
                if (var_f28_631 > 0.0001f) {
                    temp_f1_711 = 1.0f / var_f28_631;
                    sp218 = sp548 * (f64) temp_f1_711;
                    sp220 = (f32) sp550 * temp_f1_711;
                    sp3A8 = sp218;
                    sp3B0 = (f64) sp220;
                    sp6A0.SetRotateAroundAxis(*((MKVector3 *) &sp3A8), temp_f22_701);
                }
                ((Animation *) &sp388)->GetNodeOrigin(MKModel_GetAnimation(this->unk24));
                spE8 = sp660.unk30 + ((sp390 * sp660.unk20) + ((sp388 * M2C_BITWISE(f32, sp660)) + (sp38C * sp660.unk10)));
                spEC = sp660.unk34 + ((sp390 * sp660.unk24) + ((sp388 * sp660.unk4) + (sp38C * sp660.unk14)));
                spF0 = sp660.unk38 + ((sp390 * sp660.unk28) + ((sp388 * sp660.unk8) + (sp38C * sp660.unk18)));
                sp538 = (f64) spE8;
                sp540 = (f64) spF0;
                sp398 = (f64) spE8;
                spD8 = -(f32) sp538;
                spDC = -unksp53C;
                spE0 = -(f32) sp540;
                sp3A0 = (f64) spF0;
                sp378 = (f64) spD8;
                sp380 = (f64) spE0;
                sp5E0.Translate(&sp5E0, *((MKVector3 *) &sp378));
                sp5E0.Multiply(&sp5E0, &sp6A0);
                sp5E0.Translate(&sp5E0, *((MKVector3 *) &sp538));
            }
        }
        if (temp_r30_391 != 0) {
            Normalise(sp368);
            sp518 = M2C_BITWISE(f64, sp368);
            sp520 = (f64) sp368.unk8;
            spC8 = (f32) sp518;
            spCC = unksp51C;
            temp_f8_818 = M2C_FIELD(temp_r31_217, f32 *, 0x60);
            sp208 = this->unk0;
            sp528 = (f64) spC8;
            sp20C = this->unk4;
            spD0 = (f32) sp520;
            sp348 = (f64) sp208;
            spD4 = -(((f32) sp5B0 * (f32) sp520) + (((f32) sp5A8 * (f32) sp518) + (unksp5AC * unksp51C)));
            sp210 = this->unk8;
            sp530 = (f64) spD0;
            sp214 = 1.0f;
            sp350 = (f64) sp210;
            sp358 = (f64) spC8;
            sp360 = (f64) spD0;
            temp_f0_847 = (unksp534 * unksp354) + (((f32) sp530 * (f32) sp350) + (((f32) sp528 * (f32) sp348) + (unksp52C * unksp34C)));
            if (temp_f0_847 > temp_f8_818) {
                sp328.operator*(temp_f8_818 - temp_f0_847);
                spB8 = M2C_FIELD(this, f64 *, 0) + M2C_BITWISE(f64, sp328);
                M2C_FIELD(this, f64 *, 0) = spB8;
                spC0 = this->unk8 + sp328.unk8;
                sp338 = spB8;
                sp340 = (f64) spC0;
                M2C_FIELD(this, f32 *, 8) = (f64) spC0;
            } else {
                temp_f1_870 = M2C_FIELD(temp_r31_217, f32 *, 0x50);
                if (temp_f0_847 < temp_f1_870) {
                    sp308.operator*(temp_f1_870 - temp_f0_847);
                    spA8 = M2C_FIELD(this, f64 *, 0) + M2C_BITWISE(f64, sp308);
                    M2C_FIELD(this, f64 *, 0) = spA8;
                    spB0 = this->unk8 + sp308.unk8;
                    sp318 = spA8;
                    sp320 = (f64) spB0;
                    M2C_FIELD(this, f32 *, 8) = (f64) spB0;
                }
            }
            Normalise(sp2F8);
            sp518 = M2C_BITWISE(f64, sp2F8);
            sp520 = (f64) sp2F8.unk8;
            sp98 = (f32) sp518;
            temp_f8_911 = M2C_FIELD(temp_r31_217, f32 *, 0x64);
            sp9C = unksp51C;
            sp1F8 = this->unk0;
            sp528 = (f64) sp98;
            sp1FC = this->unk4;
            spA0 = (f32) sp520;
            sp2D8 = (f64) sp1F8;
            spA4 = -(((f32) sp5B0 * (f32) sp520) + (((f32) sp5A8 * (f32) sp518) + (unksp5AC * unksp51C)));
            sp200 = this->unk8;
            sp530 = (f64) spA0;
            sp204 = 1.0f;
            sp2E0 = (f64) sp200;
            sp2E8 = (f64) sp98;
            sp2F0 = (f64) spA0;
            temp_f0_941 = (unksp534 * unksp2E4) + (((f32) sp530 * (f32) sp2E0) + (((f32) sp528 * (f32) sp2D8) + (unksp52C * unksp2DC)));
            if (temp_f0_941 > temp_f8_911) {
                sp2B8.operator*(temp_f8_911 - temp_f0_941);
                sp88 = M2C_FIELD(this, f64 *, 0) + M2C_BITWISE(f64, sp2B8);
                M2C_FIELD(this, f64 *, 0) = sp88;
                sp90 = this->unk8 + sp2B8.unk8;
                sp2C8 = sp88;
                sp2D0 = (f64) sp90;
                M2C_FIELD(this, f32 *, 8) = (f64) sp90;
            } else {
                temp_f1_964 = M2C_FIELD(temp_r31_217, f32 *, 0x54);
                if (temp_f0_941 < temp_f1_964) {
                    sp298.operator*(temp_f1_964 - temp_f0_941);
                    sp78 = M2C_FIELD(this, f64 *, 0) + M2C_BITWISE(f64, sp298);
                    M2C_FIELD(this, f64 *, 0) = sp78;
                    sp80 = this->unk8 + sp298.unk8;
                    sp2A8 = sp78;
                    sp2B0 = (f64) sp80;
                    M2C_FIELD(this, f32 *, 8) = (f64) sp80;
                }
            }
            Normalise(sp288);
            sp518 = M2C_BITWISE(f64, sp288);
            sp520 = (f64) sp288.unk8;
            sp68 = (f32) sp518;
            temp_f8_1005 = M2C_FIELD(temp_r31_217, f32 *, 0x68);
            sp6C = unksp51C;
            sp1E8 = this->unk0;
            sp528 = (f64) sp68;
            sp1EC = this->unk4;
            sp70 = (f32) sp520;
            sp268 = (f64) sp1E8;
            sp74 = -(((f32) sp5B0 * (f32) sp520) + (((f32) sp5A8 * (f32) sp518) + (unksp5AC * unksp51C)));
            sp1F0 = this->unk8;
            sp530 = (f64) sp70;
            sp1F4 = 1.0f;
            sp270 = (f64) sp1F0;
            sp278 = (f64) sp68;
            sp280 = (f64) sp70;
            temp_f0_1035 = (unksp534 * unksp274) + (((f32) sp530 * (f32) sp270) + (((f32) sp528 * (f32) sp268) + (unksp52C * unksp26C)));
            if (temp_f0_1035 > temp_f8_1005) {
                sp248.operator*(temp_f8_1005 - temp_f0_1035);
                sp58 = M2C_FIELD(this, f64 *, 0) + M2C_BITWISE(f64, sp248);
                M2C_FIELD(this, f64 *, 0) = sp58;
                sp60 = this->unk8 + sp248.unk8;
                sp258 = sp58;
                sp260 = (f64) sp60;
                M2C_FIELD(this, f32 *, 8) = (f64) sp60;
            } else {
                temp_f1_1058 = M2C_FIELD(temp_r31_217, f32 *, 0x58);
                if (temp_f0_1035 < temp_f1_1058) {
                    sp228.operator*(temp_f1_1058 - temp_f0_1035);
                    sp48 = M2C_FIELD(this, f64 *, 0) + M2C_BITWISE(f64, sp228);
                    M2C_FIELD(this, f64 *, 0) = sp48;
                    sp50 = this->unk8 + sp228.unk8;
                    sp238 = sp48;
                    sp240 = (f64) sp50;
                    M2C_FIELD(this, f32 *, 8) = (f64) sp50;
                }
            }
            temp_f0_1082 = M2C_FIELD(this, f64 *, 0) - sp5A8;
            sp1D8 = temp_f0_1082;
            sp508 = temp_f0_1082;
            sp1E0 = this->unk8 - (f32) sp5B0;
            sp510 = (f64) sp1E0;
            sp5E0.Translate(&sp5E0, *((MKVector3 *) &sp508));
        }
    }
    sp620.Inverse(&sp620);
    sp5E0.Multiply(&sp5E0, &sp620);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r29_219, &sp5E0, (AnimationMatrixPosition) 4, 0U);
}
#endif

void MKDynamicBoneSystem::ResetModel(MKModel *arg0) {
    MKDynamicBone **var_r31_1146;
    MKDynamicBone *temp_r3_1161;

    var_r31_1146 = this->unk0;
loop_5:
    temp_r3_1161 = *var_r31_1146;
    if (temp_r3_1161 != NULL) {
        if (((MKModel *) temp_r3_1161->unk24 == arg0) && (MKModel_GetAnimation(arg0) != NULL)) {
            ((MKDynamicBone *) (*var_r31_1146))->Reset();
        }
        var_r31_1146 += 4;
        goto loop_5;
    }
}

#if 0 // DRAFT: undefined identifier 'unk2C'
void MKDynamicBoneSystem::Update() {
    MKDynamicBone **var_r31_1181;
    MKDynamicBone *temp_r3_1188;
    MKDynamicBone *temp_r3_1196;

    if ((u8) this->unk4 == 0) {
        var_r31_1181 = this->unk0;
loop_5:
        temp_r3_1196 = *var_r31_1181;
        if (temp_r3_1196 != NULL) {
            if (MKModel_GetAnimation(temp_r3_1196->unk24) != NULL) {
                temp_r3_1188 = *var_r31_1181;
                temp_r3_1188->unk2C(temp_r3_1188, (MKDynamicBone *) temp_r3_1188->unk28, M2C_ERROR(/* Read from unset register $r5 */));
            }
            var_r31_1181 += 4;
            goto loop_5;
        }
    }
}
#endif

void MKDynamicBoneSystem::Enable(MKModel *arg0, bool arg1) {
    MKDynamicBone **var_r6_1210;
    MKDynamicBone *temp_r3_1220;

    var_r6_1210 = this->unk0;
loop_4:
    temp_r3_1220 = *var_r6_1210;
    if (temp_r3_1220 != NULL) {
        if ((MKModel *) temp_r3_1220->unk24 == arg0) {
            temp_r3_1220->unk30 = arg1;
        }
        var_r6_1210 += 4;
        goto loop_4;
    }
}

#if 0 // DRAFT: type mismatch
void MKDynamicBoneSystem::RemoveModel(MKModel *arg0) {
    MKDynamicBone **temp_r5_1255;
    MKDynamicBone **temp_r5_1263;
    MKDynamicBone **var_r6_1239;
    MKDynamicBone **var_r8_1229;
    MKDynamicBone *temp_r0_1248;
    MKDynamicBone *temp_r5_1273;
    MKDynamicBone *temp_r6_1266;
    MKDynamicBone *temp_r7_1258;
    Matrix *temp_r5_1235;

    var_r8_1229 = this->unk0;
loop_13:
    temp_r5_1273 = *var_r8_1229;
    if (temp_r5_1273 != NULL) {
        if ((MKModel *) temp_r5_1273->unk24 == arg0) {
            temp_r5_1235 = temp_r5_1273->unk20;
            if (M2C_FIELD(temp_r5_1235, u16 *, 0x72) & 0x100) {
                var_r6_1239 = spareTemplates;
loop_7:
                temp_r0_1248 = *var_r6_1239;
                if (temp_r0_1248 == NULL) {
                    var_r6_1239 = NULL;
                } else if (temp_r0_1248 == temp_r5_1235) {

                } else {
                    var_r6_1239 += 4;
                    goto loop_7;
                }
                if (var_r6_1239 != NULL) {
                    temp_r5_1255 = spareTemplates;
                    spareTemplates = temp_r5_1255 + 4;
                    temp_r7_1258 = *temp_r5_1255;
                    *temp_r5_1255 = *var_r6_1239;
                    *var_r6_1239 = temp_r7_1258;
                }
            }
            temp_r5_1263 = this->unk0;
            this->unk0 = temp_r5_1263 + 4;
            temp_r6_1266 = *temp_r5_1263;
            *temp_r5_1263 = *var_r8_1229;
            *var_r8_1229 = temp_r6_1266;
        }
        var_r8_1229 += 4;
        goto loop_13;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKDynamicBoneSystem::AddModel(MKModel *arg0) {
    Animation *temp_r3_1311;
    MKDynamicBone **temp_r5_1330;
    MKDynamicBone *temp_r30_1332;
    Matrix *temp_r22_1361;
    f32 *temp_r22_1402;
    f32 *temp_r22_1412;
    s16 temp_r0_1293;
    s16 var_ctr_1294;
    s32 temp_r28_1319;
    s32 var_r20_1345;
    s32 var_r21_1342;
    s32 var_r22_1346;
    s32 var_r23_1343;
    s32 var_r24_1323;
    s32 var_r27_1322;
    s32 var_r5_1291;
    u16 *var_r29_1299;
    void *temp_r3_1292;

    var_r5_1291 = 0;
    temp_r3_1292 = M2C_FIELD(arg0->unk0, void **, 0x30);
    temp_r0_1293 = M2C_FIELD(temp_r3_1292, s16 *, 0xC);
    var_ctr_1294 = temp_r0_1293;
    if (temp_r0_1293 > 0) {
loop_1:
        var_r29_1299 = M2C_FIELD(temp_r3_1292, s32 *, 0x60) + var_r5_1291;
        if ((u16) *var_r29_1299 == 7) {

        } else {
            var_r5_1291 += 0x10;
            var_ctr_1294 -= 1;
            if (var_ctr_1294 == 0) {
                goto block_4;
            }
            goto loop_1;
        }
    } else {
block_4:
        var_r29_1299 = NULL;
    }
    temp_r3_1311 = MKModel_GetAnimation(arg0);
    if ((var_r29_1299 != NULL) && (temp_r3_1311 != NULL)) {
        temp_r3_1311->EnableCustomMatrices(1U);
        temp_r28_1319 = M2C_FIELD(var_r29_1299, s32 *, 4);
        var_r27_1322 = 0;
        var_r24_1323 = 0;
loop_15:
        if (var_r27_1322 < (s32) M2C_FIELD(var_r29_1299, s32 *, 8)) {
            temp_r5_1330 = this->unk0 - 4;
            this->unk0 = temp_r5_1330;
            temp_r30_1332 = *temp_r5_1330;
            temp_r30_1332->unk24 = arg0;
            temp_r30_1332->unk20 = temp_r28_1319 + var_r24_1323;
            temp_r30_1332->unk2C = &MKDynamicBone::DefaultUpdater;
            temp_r30_1332->unk28 = NULL;
            temp_r30_1332->unk30 = 1;
            if (temp_r30_1332->unk20->unk3C != 1.0f) {
                var_r21_1342 = 0;
                var_r23_1343 = 0;
                do {
                    var_r20_1345 = 0;
                    var_r22_1346 = 0;
loop_11:
                    FlipEndian(temp_r30_1332->unk20 + (var_r23_1343 + var_r22_1346));
                    var_r20_1345 += 1;
                    var_r22_1346 += 4;
                    if (var_r20_1345 < 4) {
                        goto loop_11;
                    }
                    var_r21_1342 += 1;
                    var_r23_1343 += 0x10;
                } while (var_r21_1342 < 4);
                temp_r22_1361 = temp_r30_1332->unk20 + 0x40;
                FlipEndian(&temp_r22_1361->unk0);
                FlipEndian(&temp_r22_1361->unk4);
                FlipEndian(&temp_r22_1361->unk8);
                FlipEndian(&temp_r22_1361->unkC);
                FlipEndian(&temp_r30_1332->unk0);
                FlipEndian(&temp_r30_1332->unk4);
                FlipEndian(&temp_r30_1332->unk8);
                FlipEndian(&temp_r30_1332->unkC);
                FlipEndian(&temp_r30_1332->unk10);
                FlipEndian(&temp_r30_1332->unk14);
                FlipEndian(&temp_r30_1332->unk18);
                FlipEndian(&temp_r30_1332->unk1C);
                FlipEndian(temp_r30_1332->unk20 + 0x70);
                FlipEndian(temp_r30_1332->unk20 + 0x74);
                FlipEndian(temp_r30_1332->unk20 + 0x78);
                FlipEndian(temp_r30_1332->unk20 + 0x7C);
                FlipEndian(temp_r30_1332->unk20 + 0x72);
                temp_r22_1402 = temp_r30_1332->unk20 + 0x50;
                FlipEndian(temp_r22_1402);
                FlipEndian(temp_r22_1402 + 4);
                FlipEndian(temp_r22_1402 + 8);
                FlipEndian(temp_r22_1402 + 0xC);
                temp_r22_1412 = temp_r30_1332->unk20 + 0x60;
                FlipEndian(temp_r22_1412);
                FlipEndian(temp_r22_1412 + 4);
                FlipEndian(temp_r22_1412 + 8);
                FlipEndian(temp_r22_1412 + 0xC);
            }
            temp_r30_1332->Reset();
            var_r27_1322 += 1;
            var_r24_1323 += 0x80;
            goto loop_15;
        }
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKDynamicBoneSystem::Deinit() {
    MKDynamicBone **var_r30_1449;
    MKDynamicBone **var_r30_1491;
    MKDynamicBone **var_r3_1450;
    MKDynamicBone **var_r3_1492;
    MKDynamicBone **var_r4_1448;
    MKDynamicBone **var_r4_1490;
    MKDynamicBone *temp_r0_1453;
    MKDynamicBone *temp_r0_1472;
    MKDynamicBone *temp_r0_1495;
    MKDynamicBone *temp_r0_1514;
    MKHeap *temp_r3_1475;
    MKHeap *temp_r3_1517;
    u32 temp_r0_1458;
    u32 temp_r0_1500;

    var_r4_1448 = spareTemplates;
    var_r30_1449 = var_r4_1448;
    var_r3_1450 = var_r4_1448;
loop_3:
    temp_r0_1458 = M2C_FIELD(var_r3_1450, u32 *, -4);
    var_r3_1450 -= 4;
    if (temp_r0_1458 != 0U) {
        temp_r0_1453 = *var_r3_1450;
        if (temp_r0_1453 < var_r30_1449) {
            var_r30_1449 = (MKDynamicBone **) temp_r0_1453;
        }
        goto loop_3;
    }
    if (var_r3_1450 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_1472 = *var_r4_1448;
        if (temp_r0_1472 != NULL) {
            if (temp_r0_1472 < var_r30_1449) {
                var_r30_1449 = (MKDynamicBone **) temp_r0_1472;
            }
            var_r4_1448 += 4;
            goto loop_9;
        }
        temp_r3_1475 = ((MKHeap *) var_r3_1450)->Current();
        if (temp_r3_1475 != NULL) {
            ((MKHeap *) (temp_r3_1475->Current()))->Free(var_r30_1449, NULL, 0);
        } else {
            free(var_r30_1449);
        }
    }
    spareTemplates = NULL;
    var_r4_1490 = this->unk0;
    var_r30_1491 = var_r4_1490;
    var_r3_1492 = var_r4_1490;
loop_16:
    temp_r0_1500 = M2C_FIELD(var_r3_1492, u32 *, -4);
    var_r3_1492 -= 4;
    if (temp_r0_1500 != 0U) {
        temp_r0_1495 = *var_r3_1492;
        if (temp_r0_1495 < var_r30_1491) {
            var_r30_1491 = (MKDynamicBone **) temp_r0_1495;
        }
        goto loop_16;
    }
    if (var_r3_1492 != &gEmptyPtrListDL) {
loop_22:
        temp_r0_1514 = *var_r4_1490;
        if (temp_r0_1514 != NULL) {
            if (temp_r0_1514 < var_r30_1491) {
                var_r30_1491 = (MKDynamicBone **) temp_r0_1514;
            }
            var_r4_1490 += 4;
            goto loop_22;
        }
        temp_r3_1517 = ((MKHeap *) var_r3_1492)->Current();
        if (temp_r3_1517 != NULL) {
            ((MKHeap *) (temp_r3_1517->Current()))->Free(var_r30_1491, NULL, 0);
        } else {
            free(var_r30_1491);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void MKDynamicBoneSystem::Init() {
    MKDynamicBone **temp_r3_1580;
    MKDynamicBone **temp_r3_1587;
    MKDynamicBone **temp_r3_1594;
    MKDynamicBone **temp_r4_1631;
    MKDynamicBone **var_r3_1567;
    MKDynamicBone **var_r3_1620;
    MKDynamicBone **var_r5_1579;
    MKHeap *temp_r3_1557;
    MKHeap *temp_r3_1610;
    MKModel *temp_r30_1549;
    MKModel *var_ctr_1583;
    f32 temp_r30_1602;
    f32 var_ctr_1635;

    temp_r30_1549 = gMKDefaults.unk9C;
    if (temp_r30_1549 == NULL) {
        this->unk0 = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_1557 = gMKDefaults.Current();
        if (temp_r3_1557 != NULL) {
            var_r3_1567 = ((MKHeap *) (temp_r3_1557->Current()))->Alloc(((s32) (temp_r30_1549 + 2) * 4) + ((s32) temp_r30_1549 * 0x38), NULL, 0);
        } else {
            var_r3_1567 = malloc(((s32) (temp_r30_1549 + 2) * 4) + ((s32) temp_r30_1549 * 0x38));
        }
        this->unk0 = var_r3_1567;
        var_r5_1579 = this->unk0;
        temp_r3_1580 = var_r5_1579 + ((s32) temp_r30_1549 * 0x38);
        this->unk0 = temp_r3_1580;
        *temp_r3_1580 = NULL;
        var_ctr_1583 = temp_r30_1549;
        if (temp_r30_1549 > 0) {
            do {
                temp_r3_1587 = this->unk0;
                this->unk0 = temp_r3_1587 + 4;
                M2C_FIELD(temp_r3_1587, MKDynamicBone ***, 4) = var_r5_1579;
                var_r5_1579 += 0x38;
                var_ctr_1583 -= 1;
            } while (var_ctr_1583 != NULL);
        }
        temp_r3_1594 = this->unk0;
        this->unk0 = temp_r3_1594 + 4;
        M2C_FIELD(temp_r3_1594, MKDynamicBone ***, 4) = NULL;
    }
    temp_r30_1602 = gMKDefaults.unkA0;
    if (M2C_BITWISE(s32, temp_r30_1602) == 0) {
        spareTemplates = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_1610 = gMKDefaults.Current();
        if (temp_r3_1610 != NULL) {
            var_r3_1620 = ((MKHeap *) (temp_r3_1610->Current()))->Alloc(((M2C_BITWISE(s32, temp_r30_1602) + 2) * 4) + (M2C_BITWISE(s32, temp_r30_1602) << 7), NULL, 0);
        } else {
            var_r3_1620 = malloc(((M2C_BITWISE(s32, temp_r30_1602) + 2) * 4) + (M2C_BITWISE(s32, temp_r30_1602) << 7));
        }
        spareTemplates = var_r3_1620;
        temp_r4_1631 = var_r3_1620 + (M2C_BITWISE(s32, temp_r30_1602) << 7);
        spareTemplates = temp_r4_1631;
        *temp_r4_1631 = NULL;
        var_ctr_1635 = temp_r30_1602;
        if (M2C_BITWISE(s32, temp_r30_1602) > 0) {
            do {
                spareTemplates += 4;
                M2C_FIELD(spareTemplates, MKDynamicBone ***, 4) = var_r3_1620;
                var_r3_1620 += 0x80;
                var_ctr_1635 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_ctr_1635) - 1));
            } while (M2C_BITWISE(s32, var_ctr_1635) != 0);
        }
        spareTemplates += 4;
        M2C_FIELD(spareTemplates, MKDynamicBone ***, 4) = NULL;
    }
    this->unk4 = 0;
}
#endif

#if 0 // DRAFT: identifier 'arg2' redeclared
void MKDynamicBone_SetUpdater(MKDynamicBone *arg0, void (*arg2)(MKDynamicBone *, void *), void *arg2) {
    if (arg1 != NULL) {
        arg0->unk2C = (void (*)(MKDynamicBone *, MKDynamicBone *, void *)) arg1;
        arg0->unk28 = arg2;
        return;
    }
    arg0->unk2C = &MKDynamicBone::DefaultUpdater;
    arg0->unk28 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKDynamicBoneSystem' to
void *MKDynamicBone_GetDynamicBone(MKModel *arg0, int arg1) {
    void **var_r30_1687;
    void *temp_r3_1697;
    void *temp_r3_1706;

    var_r30_1687 = gDynamicBones;
loop_6:
    temp_r3_1706 = *var_r30_1687;
    if (temp_r3_1706 == NULL) {
        return NULL;
    }
    if (((u32) M2C_FIELD(temp_r3_1706, u32 *, 0x24) == arg0) && (MKModel_GetAnimation(arg0) != NULL)) {
        temp_r3_1697 = *var_r30_1687;
        if ((s16) M2C_FIELD(M2C_FIELD(temp_r3_1697, void **, 0x20), s16 *, 0x70) == (s16) arg1) {
            return temp_r3_1697;
        }
    }
    var_r30_1687 += 4;
    goto loop_6;
}
#endif

#if 0 // DRAFT: illegal operand
void *MKDynamicBone_AddDynamicBone(MKModel *arg0, int arg1) {
    Animation *temp_r3_1727;
    MKDynamicBone **temp_r3_1736;
    MKDynamicBone *temp_r31_1738;
    void **temp_r3_1761;
    void *var_r30_1729;

    temp_r3_1727 = MKModel_GetAnimation(arg0);
    var_r30_1729 = NULL;
    if (temp_r3_1727 != NULL) {
        temp_r3_1727->EnableCustomMatrices(1U);
        temp_r3_1736 = spareTemplates - 4;
        spareTemplates = temp_r3_1736;
        temp_r31_1738 = *temp_r3_1736;
        memset(temp_r31_1738, 0, 0x80U);
        temp_r31_1738->unk70 = (s16) arg1;
        temp_r31_1738->unk72 = 0x100;
        temp_r31_1738->unk74 = 10.0f;
        M2C_STRUCT_COPY(temp_r31_1738, &Matrix::identity, 0x40);
        temp_r3_1761 = gDynamicBones - 4;
        gDynamicBones = temp_r3_1761;
        var_r30_1729 = *temp_r3_1761;
        memset(var_r30_1729, 0, 0x38U);
        M2C_FIELD(var_r30_1729, MKModel **, 0x24) = arg0;
        M2C_FIELD(var_r30_1729, MKDynamicBone **, 0x20) = temp_r31_1738;
        M2C_FIELD(var_r30_1729, void (**)(MKDynamicBone *, MKDynamicBone *, void *), 0x2C) = &MKDynamicBone::DefaultUpdater;
        M2C_FIELD(var_r30_1729, s32 *, 0x28) = 0;
        M2C_FIELD(var_r30_1729, s8 *, 0x30) = 1;
    }
    return var_r30_1729;
}
#endif

void MKDynamicBone_ResetModel(MKModel *arg0) {
    ((MKDynamicBoneSystem *) &gDynamicBones)->ResetModel(arg0);
}
