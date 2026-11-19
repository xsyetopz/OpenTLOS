#include "spyro/source/Gem.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GemMagicFX.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, s8 *);                            /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK fingerprintData;
extern s32 gViewSeed;
extern void **gb;

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void Gem::Draw() {
    f64 sp10;
    f64 sp8;
    MKMaterial *temp_r3_102;
    f64 *temp_r3_105;
    void *temp_r3_100;

    temp_r3_100 = GetDescriptor();
    temp_r3_102 = M2C_FIELD(temp_r3_100, MKMaterial **, 0xD4);
    if (temp_r3_102 != NULL) {
        temp_r3_105 = MKMaterial_GetColor(temp_r3_102);
        sp8 = M2C_FIELD(temp_r3_105, f64 *, 0);
        sp10 = M2C_FIELD(temp_r3_105, f64 *, 8);
        MKMaterial_SetColor(M2C_FIELD(temp_r3_100, MKMaterial **, 0xD4), *(temp_r3_100 + 0xA8));
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, this->unk148, 1U, 1U);
        Collectable::Draw();
        MKMaterial_SetColor(M2C_FIELD(temp_r3_100, MKMaterial **, 0xD4), *((MKVector4 *) &sp8));
        return;
    }
    Collectable::Draw();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void Gem::CollectingStateInit() {
    f32 temp_f31_152;

    Collectable::CollectingStateInit();
    temp_f31_152 = M2C_FIELD(GetDescriptor(), f32 *, 0xD0);
    M2C_FIELD(*gb, M2C_UNK (**)(void **, s32, void ***, f32), 0x74)(gb, M2C_FIELD(GetDescriptor(), s32 *, 0xC8), &gb, temp_f31_152);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void Gem::Spawn(const MKVector3 *arg0, const MKVector3 *arg1, bool arg2) {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    Collectable::Spawn(arg0, arg1, arg2);
    this->unk148 = MKRand_Int(&gViewSeed, 0, M2C_FIELD(GetDescriptor(), s32 *, 0xCC));
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    MKModel_SetColor(this->unk4, *((MKVector4 *) &sp18));
}
#endif

void Gem::Deinit() {
    Collectable::Deinit();
}

void Gem::Update() {
    Collectable::Update();
}

void Gem::Init() {
    Collectable::Init();
    this->unk148 = -1;
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void Gem::CollectEffects() {
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
    MKVector3 sp160;
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
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKVector3 *temp_r30_318;
    MKVector3 *temp_r30_408;
    f32 temp_f1_376;
    f32 temp_f1_547;
    f32 temp_f26_291;
    f32 temp_f26_325;
    f32 temp_f26_352;
    f32 temp_f27_286;
    f32 temp_f27_320;
    f32 temp_f27_357;
    f32 var_f0_471;
    f32 var_f0_489;
    f32 var_f0_511;
    f32 var_f0_529;
    f32 var_f1_455;
    f32 var_f1_480;
    f32 var_f1_503;
    f32 var_f1_520;
    f32 var_f3_622;
    f32 var_f4_555;
    f64 temp_f1_561;
    f64 temp_f1_567;
    f64 temp_f1_571;
    s32 temp_r3_590;
    s32 var_r0_600;
    s32 var_r29_280;
    void *temp_r4_413;

    var_r29_280 = 0;
    do {
        temp_f27_286 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f26_291 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        spF0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spF4 = temp_f26_291;
        spF8 = temp_f27_286;
        sp1C0 = (f64) spF0;
        sp1C8 = (f64) spF8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp1D0 = spE0;
        spE8 = (f32) sp1C8 * 600.0f;
        sp1D8 = (f64) spE8;
        temp_r30_318 = this->unk8 + 0x30;
        temp_f27_320 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f26_325 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spD0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spD4 = temp_f26_325;
        spD8 = temp_f27_320;
        sp1A0 = (f64) spD0;
        sp1A8 = (f64) spD8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp1B0 = spC0;
        spC8 = (f32) sp1A8 * 3.1415927f;
        sp1B8 = (f64) spC8;
        temp_f26_352 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_357 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spB0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spB4 = temp_f27_357;
        spB8 = temp_f26_352;
        sp180 = (f64) spB0;
        sp188 = (f64) spB8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        temp_f1_376 = (f32) sp188 * 3.1415927f;
        sp190 = spA0;
        spA8 = temp_f1_376;
        sp198 = (f64) spA8;
        ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0x9C)))->Emit(*temp_r30_318, *((MKVector3 *) &sp1D0), *((MKVector3 *) &sp1B0), *((MKVector3 *) &sp190), 1.0f, *(GetDescriptor(temp_f1_376) + 0xA8), 0, NULL);
        var_r29_280 += 1;
    } while (var_r29_280 < 4);
    temp_r30_408 = checked_cast<Spyro *, MKProp>(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0))) + 0x238;
    sp98 = -1.0f;
    temp_r4_413 = this->unk8;
    sp88 = 1.0f;
    sp90 = -1.0f;
    sp94 = 0.0f;
    sp80 = 1.0f;
    sp84 = 1.0f;
    sp150 = (f64) sp90;
    sp158 = (f64) sp98;
    sp140 = (f64) sp80;
    sp148 = (f64) sp88;
    sp50 = 1.0f;
    sp54 = 1.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    sp100 = (f64) sp50;
    sp108 = (f64) sp58;
    GetDescriptor(M2C_BITWISE(f32, temp_r4_413), (f64) sp50, 1.0f, (f64) sp98, (f64) sp90);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp110 = sp60;
    sp70 = 0.0f;
    var_f1_455 = (f32) sp110;
    sp74 = 0.0f;
    sp78 = 0.0f;
    sp7C = 1.0f;
    sp118 = sp68;
    sp120 = (f64) sp70;
    sp128 = (f64) sp78;
    if (var_f1_455 < (f32) sp100) {

    } else {
        var_f1_455 = (f32) sp100;
    }
    var_f0_471 = unksp114;
    sp10 = var_f1_455;
    if (var_f0_471 < unksp104) {

    } else {
        var_f0_471 = unksp104;
    }
    var_f1_480 = (f32) sp118;
    sp14 = var_f0_471;
    if (var_f1_480 < (f32) sp108) {

    } else {
        var_f1_480 = (f32) sp108;
    }
    var_f0_489 = unksp11C;
    sp18 = var_f1_480;
    if (var_f0_489 < unksp10C) {

    } else {
        var_f0_489 = unksp10C;
    }
    sp1C = var_f0_489;
    sp40 = (f64) sp10;
    var_f1_503 = (f32) sp40;
    sp48 = (f64) sp18;
    if (var_f1_503 > (f32) sp120) {

    } else {
        var_f1_503 = (f32) sp120;
    }
    var_f0_511 = unksp44;
    sp30 = var_f1_503;
    if (var_f0_511 > unksp124) {

    } else {
        var_f0_511 = unksp124;
    }
    var_f1_520 = (f32) sp48;
    sp34 = var_f0_511;
    if (var_f1_520 > (f32) sp128) {

    } else {
        var_f1_520 = (f32) sp128;
    }
    var_f0_529 = unksp4C;
    sp38 = var_f1_520;
    if (var_f0_529 > unksp12C) {

    } else {
        var_f0_529 = unksp12C;
    }
    sp3C = var_f0_529;
    sp130 = (f64) sp30;
    sp138 = (f64) sp38;
    KDRand_Vector(sp160, *((MKVector3 *) &sp150));
    temp_f1_547 = M2C_BITWISE(f32, sp160);
    var_f4_555 = (sp160.unk8 * sp160.unk8) + ((temp_f1_547 * temp_f1_547) + (sp160.unk4 * sp160.unk4));
    if (var_f4_555 > 1e-12f) {
        if (var_f4_555 > 0.0f) {
            temp_f1_561 = __frsqrte(var_f4_555);
            temp_f1_567 = 0.5 * temp_f1_561 * -(((f64) var_f4_555 * (temp_f1_561 * temp_f1_561)) - 3.0);
            temp_f1_571 = 0.5 * temp_f1_567 * -(((f64) var_f4_555 * (temp_f1_567 * temp_f1_567)) - 3.0);
            var_f4_555 = (f32) ((f64) var_f4_555 * (0.5 * temp_f1_571 * -(((f64) var_f4_555 * (temp_f1_571 * temp_f1_571)) - 3.0)));
        } else if (var_f4_555 < M2C_BITWISE(f32, 0.0)) {
            var_f4_555 = __float_nan;
        } else {
            sp8 = var_f4_555;
            temp_r3_590 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_590) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_600 = 1;
                } else {
                    var_r0_600 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_600 = 5;
                } else {
                    var_r0_600 = 3;
                }
                break;
            default:
                var_r0_600 = 4;
                break;
            }
            if (var_r0_600 == 1) {
                var_f4_555 = __float_nan;
            }
        }
        var_f3_622 = 1.0f / var_f4_555;
    } else {
        var_f3_622 = 0.0f;
    }
    sp20 = M2C_BITWISE(f32, sp160) * var_f3_622;
    sp24 = sp160.unk4 * var_f3_622;
    sp28 = sp160.unk8 * var_f3_622;
    sp170 = (f64) sp20;
    sp178 = (f64) sp28;
    ((GemMagicFX *) (M2C_FIELD(&gb, GemMagicFX **, 0x238)))->Emit(*(temp_r4_413 + 0x30), *((MKVector3 *) &sp170), temp_r30_408, *((MKVector4 *) &sp130), 1U);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CollectableState'
void Gem::SetState(CollectableState arg0) {
    Collectable::SetState(arg0);
}
#endif

void Gem::Message(MKMessage *arg0) {
    Collectable::Message(arg0);
}

#if 0 // DRAFT: illegal use of non-static member
void GemDescriptor::Deinit() {
    MKMaterial *temp_r3_702;

    temp_r3_702 = this->unkD4;
    if (temp_r3_702 != NULL) {
        MKMaterial_Destroy(temp_r3_702);
        this->unkD4 = NULL;
    }
    CollectableDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GemDescriptor::LoadDone() {
    s32 var_r6_740;
    u32 var_r5_737;
    void *temp_r3_743;

    CollectableDescriptor::LoadDone();
    this->unkCC = MKModel_GetNmbrOfSubObjects(this->unk2C, (SubObjectType) 0);
    this->unkD4 = MKMaterial_Create("p_gem_white");
    var_r5_737 = 0U;
    this->unk66 = 0;
    var_r6_740 = 0;
loop_2:
    if ((s8) M2C_FIELD((&fingerprintData + var_r6_740), u8 *, 8) != 0) {
        temp_r3_743 = &fingerprintData + var_r6_740;
        var_r6_740 += 1;
        var_r5_737 += (s8) M2C_FIELD(temp_r3_743, u8 *, 8);
        goto loop_2;
    }
    if (var_r5_737 != (u32) M2C_FIELD(&fingerprintData, u32 *, 0x108)) {
        this->unkD0 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 GemDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;

    if (CollectableDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadString("gemType", &sp8, 0) != 0) {
        if (stricmp(sp8, "Health") == 0) {
            this->unkC8 = 0;
        } else if (stricmp(sp8, "Spirit") == 0) {
            this->unkC8 = 1;
        } else if (stricmp(sp8, "Magic") == 0) {
            this->unkC8 = 2;
        } else if (stricmp(sp8, "Fury") == 0) {
            this->unkC8 = 3;
        }
        return 1;
    }
    return arg0->LoadFloat("statValue", &this->unkD0, 0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GemDescriptor::Init() {
    CollectableDescriptor::Init();
    this->unk9C |= 0x6000;
    this->unk6C = 6.2831855f;
    this->unk78 = 15.0f;
    this->unk74 = 4.0f;
    this->unk98 = 0;
    this->unkC8 = 0;
    this->unkD0 = 1.0f;
    this->unkD4 = NULL;
}
#endif

void Gem_cpp::__sinit() {
    f32 temp_f0_925;
    f64 temp_f1_906;
    f64 temp_f1_914;
    f64 temp_f3_894;
    f64 temp_f4_903;
    f64 temp_f4_911;
    f64 temp_f8_896;

    temp_f3_894 = __frsqrte(2014000.0);
    temp_f8_896 = __frsqrte(380000.0);
    temp_f4_903 = 0.5 * temp_f3_894 * -((2014000.0 * (temp_f3_894 * temp_f3_894)) - 3.0);
    temp_f1_906 = 0.5 * temp_f8_896 * -((380000.0 * (temp_f8_896 * temp_f8_896)) - 3.0);
    temp_f4_911 = 0.5 * temp_f4_903 * -((2014000.0 * (temp_f4_903 * temp_f4_903)) - 3.0);
    temp_f1_914 = 0.5 * temp_f1_906 * -((380000.0 * (temp_f1_906 * temp_f1_906)) - 3.0);
    temp_f0_925 = (f32) (380000.0 * (0.5 * temp_f1_914 * -((380000.0 * (temp_f1_914 * temp_f1_914)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_911 * -((2014000.0 * (temp_f4_911 * temp_f4_911)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_925;
}
