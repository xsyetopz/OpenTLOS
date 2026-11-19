#include "spyro/source/SwampFlutter.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Volume.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal use of non-static member
void SwampFlutterCritter::Deinit() {
    MKHeap *temp_r3_57;
    void *temp_r31_54;

    temp_r31_54 = this->unk170;
    if (temp_r31_54 != NULL) {
        temp_r3_57 = MKHeap::Current();
        if (temp_r3_57 != NULL) {
            ((MKHeap *) (temp_r3_57->Current()))->Free(temp_r31_54, NULL, 0);
        } else {
            free(temp_r31_54);
        }
    }
    this->unk170 = NULL;
    Critters::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void SwampFlutterCritter::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_92;
    s32 var_r31_93;
    void *temp_r29_100;

    var_r30_92 = 0;
    var_r31_93 = 0;
loop_2:
    if (var_r30_92 < (s32) this->unk90) {
        temp_r29_100 = this->unk170 + var_r31_93;
        this->unk80->SetAnim(M2C_FIELD(temp_r29_100, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
        this->unk80->JumpToPos(M2C_FIELD(temp_r29_100, f32 *, 0x54), -1);
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (temp_r29_100 - 4) + 4, 0x40);
        MKModel_SetWorldMatrix(this->unk4, sp10);
        MKModel_Draw(this->unk4, NULL);
        var_r30_92 += 1;
        var_r31_93 += 0x80;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void SwampFlutterCritter::FindNewFlyParameters(SwampFlutter *arg0) {
    f64 spB8;
    f64 spB0;
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    f64 sp90;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f12_356;
    f32 temp_f13_358;
    f32 temp_f1_173;
    f32 temp_f2_172;
    f32 temp_f31_360;
    f32 temp_f3_350;
    f32 temp_f4_174;
    f32 temp_f6_354;
    f32 temp_f7_352;
    f32 var_f4_247;
    f32 var_f4_278;
    f32 var_f5_256;
    f32 var_f6_180;
    f64 temp_f1_186;
    f64 temp_f1_192;
    f64 temp_f1_196;
    f64 temp_f1_283;
    f64 temp_f1_289;
    f64 temp_f1_293;
    s32 temp_r3_215;
    s32 temp_r3_312;
    s32 var_r0_225;
    s32 var_r0_322;

    sp80.GetRandPos();
    spB0 = sp80;
    spB8 = sp88;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg0->unk68 = sp20;
    sp28 = (f32) spB8 - arg0->unk38;
    sp70 = sp20;
    arg0->unk70 = (f64) sp28;
    temp_f2_172 = (f32) M2C_FIELD(arg0, f64 *, 0x68);
    temp_f1_173 = M2C_FIELD(arg0, f32 *, 0x6C);
    temp_f4_174 = (f32) M2C_FIELD(arg0, f64 *, 0x70);
    sp78 = (f64) sp28;
    var_f6_180 = (temp_f4_174 * temp_f4_174) + ((temp_f2_172 * temp_f2_172) + (temp_f1_173 * temp_f1_173));
    if (var_f6_180 > 0.000001f) {
        if (var_f6_180 > 0.0f) {
            temp_f1_186 = __frsqrte(var_f6_180);
            temp_f1_192 = 0.5 * temp_f1_186 * -(((f64) var_f6_180 * (temp_f1_186 * temp_f1_186)) - 3.0);
            temp_f1_196 = 0.5 * temp_f1_192 * -(((f64) var_f6_180 * (temp_f1_192 * temp_f1_192)) - 3.0);
            var_f6_180 = (f32) ((f64) var_f6_180 * (0.5 * temp_f1_196 * -(((f64) var_f6_180 * (temp_f1_196 * temp_f1_196)) - 3.0)));
        } else if (var_f6_180 < M2C_BITWISE(f32, 0.0)) {
            var_f6_180 = __float_nan;
        } else {
            spC = var_f6_180;
            temp_r3_215 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_215) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_225 = 1;
                } else {
                    var_r0_225 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_225 = 5;
                } else {
                    var_r0_225 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_225 = 4;
                break;
            }
            if (var_r0_225 == 1) {
                var_f6_180 = __float_nan;
            }
        }
        var_f4_247 = 1.0f / var_f6_180;
    } else {
        var_f4_247 = 0.0f;
        var_f6_180 = 0.0f;
    }
    var_f5_256 = 0.0f;
    M2C_FIELD(arg0, f64 *, 0x68) = (f32) ((f32) M2C_FIELD(arg0, f64 *, 0x68) * var_f4_247);
    M2C_FIELD(arg0, f32 *, 0x6C) = (f32) (M2C_FIELD(arg0, f32 *, 0x6C) * var_f4_247);
    M2C_FIELD(arg0, f64 *, 0x70) = (f32) ((f32) M2C_FIELD(arg0, f64 *, 0x70) * var_f4_247);
    arg0->unk64 = var_f6_180 / 200.0f;
    spA0 = arg0->unk68;
    spA8 = arg0->unk70;
    unkspA4 = 0.0f;
    var_f4_278 = ((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + (0.0f * 0.0f));
    if (var_f4_278 > 0.000001f) {
        if (var_f4_278 > 0.0f) {
            temp_f1_283 = __frsqrte(var_f4_278);
            temp_f1_289 = 0.5 * temp_f1_283 * -(((f64) var_f4_278 * (temp_f1_283 * temp_f1_283)) - 3.0);
            temp_f1_293 = 0.5 * temp_f1_289 * -(((f64) var_f4_278 * (temp_f1_289 * temp_f1_289)) - 3.0);
            var_f4_278 = (f32) ((f64) var_f4_278 * (0.5 * temp_f1_293 * -(((f64) var_f4_278 * (temp_f1_293 * temp_f1_293)) - 3.0)));
        } else if (var_f4_278 < M2C_BITWISE(f32, 0.0)) {
            var_f4_278 = __float_nan;
        } else {
            sp8 = var_f4_278;
            temp_r3_312 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_312) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_322 = 1;
                } else {
                    var_r0_322 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_322 = 5;
                } else {
                    var_r0_322 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_322 = 4;
                break;
            }
            if (var_r0_322 == 1) {
                var_f4_278 = __float_nan;
            }
        }
        var_f5_256 = 1.0f / var_f4_278;
    }
    temp_f3_350 = (f32) spA0 * var_f5_256;
    temp_f7_352 = unkspA4 * var_f5_256;
    temp_f6_354 = (f32) spA8 * var_f5_256;
    temp_f12_356 = -temp_f3_350;
    temp_f13_358 = -temp_f7_352;
    temp_f31_360 = -temp_f6_354;
    spA0 = temp_f3_350;
    sp40 = temp_f12_356;
    sp44 = temp_f13_358;
    sp48 = temp_f31_360;
    sp60 = (f64) sp40;
    sp68 = (f64) sp48;
    sp18 = temp_f31_360;
    sp10 = temp_f12_356;
    sp30 = (unksp64 * MKVector3::up.unk8) - ((f32) sp68 * MKVector3::up.unk4);
    sp34 = ((f32) sp68 * MKVector3::up.unk0) - ((f32) sp60 * MKVector3::up.unk8);
    sp38 = ((f32) sp60 * MKVector3::up.unk4) - (unksp64 * MKVector3::up.unk0);
    sp90 = (f64) sp30;
    sp98 = (f64) sp38;
    arg0->unk0 = (f32) sp90;
    arg0->unk4 = unksp94;
    arg0->unk8 = (f32) sp98;
    arg0->unkC = 0.0f;
    arg0->unk10 = MKVector3::up.unk0;
    sp14 = temp_f13_358;
    arg0->unk14 = MKVector3::up.unk4;
    arg0->unk18 = MKVector3::up.unk8;
    sp50 = (f64) sp10;
    sp58 = (f64) sp18;
    arg0->unk1C = 0.0f;
    arg0->unk20 = (f32) sp50;
    arg0->unk24 = unksp54;
    arg0->unk28 = (f32) sp58;
    unkspA4 = temp_f7_352;
    spA8 = temp_f6_354;
    arg0->unk2C = 0.0f;
}
#endif

#if 0 // DRAFT: illegal type
void SwampFlutterCritter::Update() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    SwampFlutter *temp_r4_439;
    f32 temp_f1_453;
    s32 var_r30_433;
    s32 var_r31_434;

    var_r30_433 = 0;
    var_r31_434 = 0;
loop_8:
    if (var_r30_433 < (s32) this->unk90) {
        temp_r4_439 = this->unk170 + var_r31_434;
        temp_r4_439->unk64 -= gUpdateTimeDelta;
        temp_r4_439->unk54 += temp_r4_439->unk58 * gUpdateTimeDelta;
        if ((s32) temp_r4_439->unk60 != 0) {

        } else {
            temp_f1_453 = temp_r4_439->unk54;
            if (temp_f1_453 > 1.0f) {
                temp_r4_439->unk54 = temp_f1_453 - 1.0f;
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r4, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp38 = sp28;
            sp30 = M2C_FIELD(temp_r4_439, f32 *, 0x70) * 200.0f;
            sp40 = (f64) sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp48 = sp18;
            sp20 = (f32) sp40 * gUpdateTimeDelta;
            sp50 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp58 = sp8;
            sp10 = temp_r4_439->unk38 + (f32) sp50;
            M2C_FIELD(temp_r4_439, f32 *, 0x30) = (f32) sp58;
            sp60 = (f64) sp10;
            temp_r4_439->unk34 = unksp5C;
            temp_r4_439->unk38 = (f32) sp60;
            temp_r4_439->unk3C = 1.0f;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r4_439->unk64 == 0.0f) {
                FindNewFlyParameters(temp_r4_439);
            }
        }
        var_r30_433 += 1;
        var_r31_434 += 0x80;
        goto loop_8;
    }
}
#endif

#if 0 // DRAFT: illegal type
void SwampFlutterCritter::Resolve() {
    Volume sp8;
    SwampFlutter *temp_r30_560;
    s32 temp_r25_588;
    s32 var_r28_553;
    s32 var_r31_551;

    MKProp::Resolve();
    var_r31_551 = 0;
    var_r28_553 = 0;
loop_2:
    if (var_r31_551 < (s32) this->unk90) {
        temp_r30_560 = this->unk170 + var_r28_553;
        sp8.GetRandPos();
        sp8.unk10 = M2C_BITWISE(f64, sp8);
        sp8.unk18 = sp8.unk8;
        M2C_STRUCT_COPY(temp_r30_560, &Matrix::identity, 0x40);
        M2C_FIELD(temp_r30_560, f32 *, 0x30) = (f32) sp8.unk10;
        temp_r30_560->unk34 = unksp1C;
        temp_r30_560->unk38 = (f32) sp8.unk18;
        temp_r30_560->unk3C = 1.0f;
        FindNewFlyParameters(temp_r30_560);
        temp_r30_560->unk60 = 0;
        temp_r25_588 = temp_r30_560->unk60;
        temp_r30_560->unk50 = *(checked_cast<SwampFlutterCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r25_588 * 4) + 0x70));
        temp_r30_560->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_560->unk50, s16 *, 4) / 30.0f));
        temp_r30_560->unk54 = 0.0f;
        temp_r30_560->unk54 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        var_r31_551 += 1;
        var_r28_553 += 0x80;
        goto loop_2;
    }
}
#endif

void SwampFlutterCritter::LoadDone() {
    MKHeap *temp_r3_644;
    s32 temp_r31_643;
    void *var_r3_651;

    Critters::LoadDone();
    temp_r31_643 = this->unk90 << 7;
    temp_r3_644 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_644 != NULL) {
        var_r3_651 = ((MKHeap *) (temp_r3_644->Current()))->Alloc(temp_r31_643, NULL, 0);
    } else {
        var_r3_651 = malloc(temp_r31_643);
    }
    this->unk170 = var_r3_651;
}

void SwampFlutterCritter::Init() {
    Critters::Init();
}

void SwampFlutterCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

#if 0 // DRAFT: expression syntax error
void SwampFlutterCritterDescriptor::LoadDone() {
    s8 *temp_r31_700;
    void *var_r3_710;

    KDPropDescriptor::LoadDone();
    temp_r31_700 = this->unk34;
    if (temp_r31_700->Exists("fly01") != 0) {
        var_r3_710 = temp_r31_700->GetAnim("fly01");
    } else {
        var_r3_710 = NULL;
    }
    this->unk70 = (s32) var_r3_710;
}
#endif

void SwampFlutterCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}
