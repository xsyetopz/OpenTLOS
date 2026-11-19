#include "spyro/source/PuddleSplash.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void PuddleSplash::Deinit() {
    MKHeap *temp_r3_50;
    void *temp_r31_47;

    MKProp::Deinit();
    temp_r31_47 = this->unk4C;
    if (temp_r31_47 != NULL) {
        temp_r3_50 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_50 != NULL) {
            ((MKHeap *) (temp_r3_50->Current()))->Free(temp_r31_47, NULL, 0);
        } else {
            free(temp_r31_47);
        }
        this->unk4C = NULL;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void PuddleSplash::Draw() {
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    Matrix sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    MKVector3 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    MKVector3 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKMaterial *temp_r3_87;
    f32 temp_f1_315;
    f32 temp_f2_313;
    f32 temp_f31_295;
    f32 temp_f3_293;
    s32 var_r26_251;
    s32 var_r28_249;
    void *temp_r4_301;
    void *temp_r5_290;

    temp_r3_87 = M2C_FIELD(this->unk4C, MKMaterial **, 0x1C);
    if (temp_r3_87 != NULL) {
        MKMaterial_SetMaterial(temp_r3_87);
    }
    MKPrimitive(0xC, 0);
    spA8 = 0.0f;
    spA0 = 1.0f;
    spA4 = 0.0f;
    sp1E8 = (f64) spA8;
    sp1E0 = (f64) spA0;
    spB8 = 1.0f;
    sp48 = -(f32) sp1E8;
    spB0 = 0.0f;
    spB4 = 0.0f;
    sp40 = -(f32) sp1E0;
    sp44 = -(*(f32 *) ((u8 *) &sp1E0 + 0x4));
    sp1F0 = (f64) spB0;
    sp1F8 = (f64) spB8;
    sp190 = (f64) sp40;
    sp198 = (f64) sp48;
    sp1A0.operator*(10.0f);
    sp1B0.operator*(10.0f);
    sp90 = sp1B0 + M2C_BITWISE(f64, sp1A0);
    sp1C0 = sp90;
    sp98 = sp1B0.unk8 + sp1A0.unk8;
    sp240 = sp90;
    sp1C8 = (f64) sp98;
    sp248 = (f64) sp98;
    sp160.operator*(10.0f);
    sp170.operator*(10.0f);
    sp80 = sp170 + M2C_BITWISE(f64, sp160);
    sp38 = -(f32) sp1E8;
    sp88 = sp170.unk8 + sp160.unk8;
    sp30 = -(f32) sp1E0;
    sp34 = -(*(f32 *) ((u8 *) &sp1E0 + 0x4));
    sp180 = sp80;
    sp188 = (f64) sp88;
    sp250 = sp80;
    sp258 = (f64) sp88;
    sp110 = (f64) sp30;
    sp118 = (f64) sp38;
    sp120.operator*(10.0f);
    sp20 = -(f32) sp1F0;
    sp24 = -(*(f32 *) ((u8 *) &sp1F0 + 0x4));
    sp28 = -(f32) sp1F8;
    sp130 = (f64) sp20;
    sp138 = (f64) sp28;
    sp140.operator*(10.0f);
    sp70 = sp140 + M2C_BITWISE(f64, sp120);
    sp150 = sp70;
    sp78 = sp140.unk8 + sp120.unk8;
    sp260 = sp70;
    sp158 = (f64) sp78;
    sp268 = (f64) sp78;
    spD0.operator*(10.0f);
    sp10 = -(f32) sp1F0;
    sp14 = -(*(f32 *) ((u8 *) &sp1F0 + 0x4));
    sp18 = -(f32) sp1F8;
    spE0 = (f64) sp10;
    spE8 = (f64) sp18;
    spF0.operator*(10.0f);
    sp60 = spF0 + M2C_BITWISE(f64, spD0);
    var_r28_249 = 0;
    var_r26_251 = 0;
    sp100 = sp60;
    sp68 = spF0.unk8 + spD0.unk8;
    sp270 = sp60;
    sp108 = (f64) sp68;
    sp278 = (f64) sp68;
    do {
        if ((u8) *(this->unk4C + (var_r26_251 + 0x20)) != 0) {
            MKEndPrimitive();
            MKMaterial_SetMaterial(*(this->unk4C + (var_r26_251 + 0x1C)));
            MKPrimitive(0xC, 0);
            M2C_STRUCT_COPY((s32) &unksp1FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_r5_290 = ((u8 *) this->unk4C) + var_r26_251;
            temp_f3_293 = M2C_FIELD(temp_r5_290, f32 *, 0x10);
            temp_f31_295 = 1.0f - (M2C_FIELD(temp_r5_290, f32 *, 0x14) / M2C_FIELD(temp_r5_290, f32 *, 0x18));
            sp200.Scale3x3(&sp200, (temp_f31_295 * temp_f3_293) + temp_f3_293);
            temp_r4_301 = ((u8 *) this->unk4C) + var_r26_251;
            sp200.unk30 = M2C_FIELD(temp_r4_301, f32 *, 0);
            sp200.unk34 = M2C_FIELD(temp_r4_301, f32 *, 4);
            sp200.unk38 = M2C_FIELD(temp_r4_301, f32 *, 8);
            sp200.unk3C = 1.0f;
            MKSetMatrix(sp200);
            temp_f2_313 = 1.0f - temp_f31_295;
            sp5C = 1.0f;
            temp_f1_315 = 0.8f * temp_f2_313;
            sp58 = temp_f2_313;
            sp50 = temp_f1_315;
            sp54 = temp_f1_315;
            spC8 = (f64) sp58;
            spC0 = (f64) sp50;
            sp1D0 = (f64) sp50;
            sp1D8 = (f64) sp58;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp240));
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp250));
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp260));
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp270));
            MKEnd();
        }
        var_r28_249 += 1;
        var_r26_251 += 0x28;
    } while (var_r28_249 < 0x64);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal type
void PuddleSplash::Emit(const MKVector3 &arg0, const float &arg1, bool arg2) {
    s32 temp_r29_429;
    s32 var_ctr_381;
    s32 var_r30_380;
    void *temp_r3_383;
    void *temp_r3_399;

    var_r30_380 = 0;
    var_ctr_381 = 0x64;
loop_1:
    temp_r3_383 = this->unk4C;
    if ((u8) *(temp_r3_383 + (var_r30_380 + 0x20)) == 0) {
        M2C_FIELD((((u8 *) temp_r3_383) + var_r30_380), s8 *, 0x20) = 1;
        M2C_FIELD((((u8 *) this->unk4C) + var_r30_380), f32 *, 0x10) = (f32) &arg1;
        temp_r3_399 = ((u8 *) this->unk4C) + var_r30_380;
        M2C_FIELD(temp_r3_399, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_399, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        if (arg2 != 0) {
            M2C_FIELD((((u8 *) this->unk4C) + var_r30_380), f32 *, 0x18) = 3.0f;
            M2C_FIELD((((u8 *) this->unk4C) + var_r30_380), f32 *, 0x14) = 3.0f;
            M2C_FIELD((((u8 *) this->unk4C) + var_r30_380), s32 *, 0x1C) = (s32) M2C_FIELD(checked_cast<PuddleSplashDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x6C);
            return;
        }
        M2C_FIELD((((u8 *) this->unk4C) + var_r30_380), f32 *, 0x18) = 0.35f;
        M2C_FIELD((((u8 *) this->unk4C) + var_r30_380), f32 *, 0x14) = 0.35f;
        temp_r29_429 = MKRand_Int((int *) &gViewSeed, 0, 3);
        M2C_FIELD((((u8 *) this->unk4C) + var_r30_380), s32 *, 0x1C) = (s32) M2C_FIELD((checked_cast<PuddleSplashDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r29_429 * 4)), s32 *, 0x60);
        return;
    }
    var_r30_380 += 0x28;
    var_ctr_381 -= 1;
    if (var_ctr_381 == 0) {
        return;
    }
    goto loop_1;
}
#endif

void *PuddleSplash::Update() {
    s32 var_ctr_457;
    s32 var_r4_453;
    void *temp_r6_460;
    void *temp_r6_469;

    var_r4_453 = 0;
    var_ctr_457 = 0x64;
    do {
        temp_r6_460 = ((u8 *) this->unk4C) + var_r4_453;
        if ((u8) M2C_FIELD(temp_r6_460, u8 *, 0x20) != 0) {
            M2C_FIELD(temp_r6_460, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r6_460, f32 *, 0x14) - gUpdateTimeDelta);
            temp_r6_469 = ((u8 *) this->unk4C) + var_r4_453;
            if (M2C_FIELD(temp_r6_469, f32 *, 0x14) <= 0.0f) {
                M2C_FIELD(temp_r6_469, s8 *, 0x20) = 0;
            }
        }
        var_r4_453 += 0x28;
        var_ctr_457 -= 1;
    } while (var_ctr_457 != 0);
}

#if 0 // DRAFT: illegal type
s32 PuddleSplash::LoadDone() {
    MKHeap *temp_r3_490;
    s32 temp_r0_512;
    s32 temp_r3_511;
    s32 var_ctr_508;
    s32 var_r4_503;
    void *var_r3_497;

    MKProp::LoadDone();
    temp_r3_490 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_490 != NULL) {
        var_r3_497 = ((MKHeap *) (temp_r3_490->Current()))->Alloc(0xFA0, NULL, 0);
    } else {
        var_r3_497 = malloc(0xFA0);
    }
    var_r4_503 = 0;
    this->unk4C = var_r3_497;
    var_ctr_508 = 0x64;
    do {
        temp_r3_511 = var_r4_503 + 0x20;
        temp_r0_512 = var_r4_503 + 0x1C;
        var_r4_503 += 0x28;
        *(this->unk4C + temp_r3_511) = 0;
        *(this->unk4C + temp_r0_512) = 0;
        var_ctr_508 -= 1;
    } while (var_ctr_508 != 0);
}
#endif

void PuddleSplash::Init() {
    MKProp::Init();
    this->unk4C = NULL;
}

#if 0 // DRAFT: function call 'MKMaterial_Destroy(PuddleSplashDescriptor)' does not match
void PuddleSplashDescriptor::Deinit() {
    s32 var_r30_552;
    s32 var_r31_553;

    MKPropDescriptor::Deinit();
    var_r30_552 = 0;
    var_r31_553 = 0;
    do {
        MKMaterial_Destroy(*(this + (var_r31_553 + 0x60)));
        var_r30_552 += 1;
        var_r31_553 += 4;
    } while (var_r30_552 < 4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void PuddleSplashDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create("fx_006");
    this->unk64 = MKMaterial_Create("fx_007");
    this->unk68 = MKMaterial_Create("fx_008");
    this->unk6C = MKMaterial_Create("fx_365");
}
#endif
