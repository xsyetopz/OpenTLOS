#include "spyro/source/FireAndIceFX.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

static s32 lit_539 = 0;
static s32 lit_543 = 0;

void FireAndIceFX::SetCrumble(const bool &arg0) {
    if (((u8) &arg0 != 0) && ((u8) this->unkA4 == 0)) {
        this->unkA4 = 1;
        this->unk40 = 1.0f;
        this->unk44 = 1.0f;
        this->unk48 = 1.0f;
        this->unk50 = 0.0f;
        this->unk54 = 0.0f;
        this->unk58 = 0.0f;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'const int *' to
void FireAndIceFX::SetState(const int &arg0, float arg1) {
    s32 temp_r0_42;

    this->unk78 = &arg0;
    this->unk80 = 0.0f;
    this->unkA4 = 0;
    this->unk84 = 0.0f;
    this->unk94 = 0.0f;
    this->unkA0 = 0.0f;
    temp_r0_42 = this->unk78;
    switch (temp_r0_42) {                           /* irregular */
    case 1:
        this->unk40 = 1.0f;
        this->unk44 = 1.0f;
        this->unk48 = 1.0f;
        this->unk50 = 0.0f;
        this->unk54 = 0.0f;
        this->unk58 = 0.0f;
        return;
    case 4:
        this->unkA8 = arg1;
        this->unkA0 = arg1;
        return;
    case 5:
        this->unkA0 = arg1;
        return;
    }
}
#endif

void FireAndIceFX::SetDefaults() {
    this->unk78 = 0;
    this->unk80 = 0.0f;
    this->unkA4 = 0;
    this->unk84 = 0.0f;
    this->unk94 = 0.0f;
    this->unkA0 = 0.0f;
}

void FireAndIceFX::Deinit() {
    MKMaterial *temp_r3_104;
    MKMaterial *temp_r3_94;
    MKMaterial *temp_r3_99;

    temp_r3_94 = this->unk60;
    if (temp_r3_94 != NULL) {
        MKMaterial_Destroy(temp_r3_94);
    }
    temp_r3_99 = this->unk6C;
    if (temp_r3_99 != NULL) {
        MKMaterial_Destroy(temp_r3_99);
    }
    temp_r3_104 = this->unk70;
    if (temp_r3_104 != NULL) {
        MKMaterial_Destroy(temp_r3_104);
    }
}

void FireAndIceFX::DrawCleanup() {
    if ((this->unk94 == 1.0f) && ((s32) this->unk78 == 1)) {
        gRenderState = NULL;
        MKModel_SetWorldMatrix(this->unk74, this->unk0);
    }
    if ((this->unk94 == 1.0f) && ((s32) this->unk78 == 2)) {
        gRenderState = NULL;
    }
}

#if 0 // DRAFT: function call 'memcpy(FireAndIceFX *, long, int)' does not match
s32 FireAndIceFX::Draw(unsigned short *arg0) {
    Matrix sp2F0;
    Matrix sp2B0;
    Matrix sp270;
    Matrix sp230;
    Matrix sp1F0;
    Matrix sp1B0;
    Matrix sp170;
    M2C_UNK sp16C;
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
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
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
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_352;
    f32 temp_f1_550;
    f32 temp_f30_348;
    f32 temp_f30_472;
    f32 temp_f30_541;
    f32 temp_f31_343;
    f32 temp_f31_546;
    f32 var_f1_296;
    f64 *temp_r3_257;
    f64 *temp_r3_284;
    f64 *temp_r3_421;
    f64 *temp_r3_454;
    f64 *temp_r3_496;
    f64 temp_f0_479;
    f64 temp_f0_499;
    f64 temp_f1_497;
    f64 temp_f3_424;
    s32 temp_r0_172;

    temp_r0_172 = this->unk78;
    switch (temp_r0_172) {                          /* irregular */
    case 1:
        M2C_STRUCT_COPY(this, MKModel_GetWorldMatrix(this->unk74), 0x40);
        if (this->unk94 < 1.0f) {
            MKModel_Draw(this->unk74, NULL);
        }
        sp90 = 1.0f;
        sp94 = 1.0f;
        sp98 = 1.0f;
        sp9C = this->unk94;
        sp110 = (f64) sp90;
        sp118 = (f64) sp98;
        MKMaterial_SetColor(this->unk60, *((MKVector4 *) &sp110));
        M2C_STRUCT_COPY((s32) &sp2B0.unk3C + 4, MKModel_GetWorldMatrix(this->unk74) - 4 + 4, 0x40);
        sp2F0.Scale3x3(&sp2F0, *((MKVector3 *) &this->unk40));
        MKModel_SetWorldMatrix(this->unk74, sp2F0);
        gRenderState = this->unk60;
        MKModel_Draw(this->unk74, arg0);
        gRenderState = NULL;
        return 1;
    case 4:
        temp_r3_257 = MKModel_GetColor(this->unk74);
        sp80 = 0.7f;
        sp84 = 0.1f;
        sp88 = 0.0f;
        sp8C = 1.0f;
        sp160 = M2C_FIELD(temp_r3_257, f64 *, 0);
        sp168 = M2C_FIELD(temp_r3_257, f64 *, 8);
        sp100 = (f64) sp80;
        sp108 = (f64) sp88;
        MKModel_SetColor(this->unk74, *((MKVector4 *) &sp100));
        MKModel_Draw(this->unk74, NULL);
        MKModel_SetColor(this->unk74, *((MKVector4 *) &sp160));
        temp_r3_284 = MKModel_GetColor(this->unk74);
        sp150 = M2C_FIELD(temp_r3_284, f64 *, 0);
        sp158 = M2C_FIELD(temp_r3_284, f64 *, 8);
        var_f1_296 = 2.0f * ((this->unkA0 / this->unkA8) - 0.5f);
        if (var_f1_296 < 0.0f) {
            var_f1_296 = -var_f1_296;
        }
        sp70 = (f32) sp150;
        sp74 = (*(f32 *) ((u8 *) &sp150 + 0x4));
        sp78 = (f32) sp158;
        sp7C = 1.0f - var_f1_296;
        spF0 = (f64) sp70;
        spF8 = (f64) sp78;
        MKModel_SetColor(this->unk74, *((MKVector4 *) &spF0));
        M2C_STRUCT_COPY((s32) &sp270.unk3C + 4, MKModel_GetWorldMatrix(this->unk74) - 4 + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp230.unk3C + 4, (s32) &sp270.unk3C + 4, 0x40);
        temp_f31_343 = MKRand_Float(&gViewSeed, 1.01f, 1.05f);
        temp_f30_348 = MKRand_Float(&gViewSeed, 1.01f, 1.05f);
        temp_f1_352 = MKRand_Float(&gViewSeed, 1.01f, 1.05f);
        sp28 = temp_f31_343;
        sp20 = temp_f1_352;
        sp24 = temp_f30_348;
        spE8 = (f64) sp28;
        spE0 = (f64) sp20;
        sp270.Scale3x3(&sp270, *((MKVector3 *) &spE0));
        MKModel_SetWorldMatrix(this->unk74, sp270);
        gRenderState = this->unk6C;
        MKModel_Draw(this->unk74, arg0);
        gRenderState = NULL;
        MKModel_SetWorldMatrix(this->unk74, sp2B0);
        MKModel_SetColor(this->unk74, *((MKVector4 *) &sp150));
        return 1;
    case 5:
        MKModel_Draw(this->unk74, NULL);
        M2C_STRUCT_COPY((s32) &sp1F0.unk3C + 4, MKModel_GetWorldMatrix(this->unk74) - 4 + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp1B0.unk3C + 4, (s32) &sp1F0.unk3C + 4, 0x40);
        sp1F0.Scale3x3(&sp1F0, 1.05f);
        MKModel_SetWorldMatrix(this->unk74, sp1F0);
        gRenderState = this->unk70;
        temp_r3_421 = MKModel_GetColor(this->unk74);
        temp_f3_424 = M2C_FIELD(temp_r3_421, f64 *, 0);
        sp60 = 1.0f;
        sp64 = 1.0f;
        sp68 = 1.0f;
        sp6C = 1.0f;
        sp140 = temp_f3_424;
        sp148 = M2C_FIELD(temp_r3_421, f64 *, 8);
        spD0 = (f64) sp60;
        spD8 = (f64) sp68;
        MKModel_SetColor(this->unk74, *((MKVector4 *) &spD0));
        MKModel_Draw(this->unk74, arg0);
        MKModel_SetColor(this->unk74, *((MKVector4 *) &sp140));
        gRenderState = NULL;
        MKModel_SetWorldMatrix(this->unk74, sp230);
        return 1;
    case 2:
        temp_r3_454 = MKModel_GetColor(this->unk74);
        sp130 = M2C_FIELD(temp_r3_454, f64 *, 0);
        sp138 = M2C_FIELD(temp_r3_454, f64 *, 8);
        sp50 = 0.7f;
        sp54 = 0.1f;
        sp58 = 0.0f;
        sp5C = 1.0f;
        temp_f30_472 = 1.0f - (this->unk80 / this->unk88);
        spC0 = (f64) sp50;
        spC8 = (f64) sp58;
        sp40 = spC0 * (f64) temp_f30_472;
        temp_f0_479 = (f64) sp58 * (f64) temp_f30_472;
        sp48 = temp_f0_479;
        sp120 = sp40;
        sp128 = temp_f0_479;
        (*(f32 *) ((u8 *) &sp128 + 0x4)) = 1.0f;
        MKModel_SetColor(this->unk74, *((MKVector4 *) &sp120));
        MKModel_Draw(this->unk74, NULL);
        MKModel_SetColor(this->unk74, *((MKVector4 *) &sp130));
        temp_r3_496 = MKModel_GetColor(this->unk74);
        temp_f1_497 = M2C_FIELD(temp_r3_496, f64 *, 0);
        temp_f0_499 = M2C_FIELD(temp_r3_496, f64 *, 8);
        sp3C = temp_f30_472;
        sp130 = temp_f1_497;
        sp138 = temp_f0_499;
        sp30 = (f32) sp130;
        sp34 = (*(f32 *) ((u8 *) &sp130 + 0x4));
        sp38 = (f32) sp138;
        spB0 = (f64) sp30;
        spB8 = (f64) sp38;
        MKModel_SetColor(this->unk74, *((MKVector4 *) &spB0));
        M2C_STRUCT_COPY((s32) &sp170.unk3C + 4, MKModel_GetWorldMatrix(this->unk74) - 4 + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp16C + 4, (s32) &sp170.unk3C + 4, 0x40);
        temp_f30_541 = MKRand_Float(&gViewSeed, 1.01f, 1.05f);
        temp_f31_546 = MKRand_Float(&gViewSeed, 1.01f, 1.05f);
        temp_f1_550 = MKRand_Float(&gViewSeed, 1.01f, 1.05f);
        sp18 = temp_f30_541;
        sp10 = temp_f1_550;
        sp14 = temp_f31_546;
        spA8 = (f64) sp18;
        spA0 = (f64) sp10;
        sp170.Scale3x3(&sp170, *((MKVector3 *) &spA0));
        MKModel_SetWorldMatrix(this->unk74, sp170);
        gRenderState = this->unk6C;
        MKModel_Draw(this->unk74, arg0);
        gRenderState = NULL;
        MKModel_SetWorldMatrix(this->unk74, sp1B0);
        MKModel_SetColor(this->unk74, *((MKVector4 *) &sp130));
        return 1;
    case 3:
        return 1;
    case 0:
        return 0;
    default:
        return 0;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void FireAndIceFX::Update() {
    MKVector3 sp68;
    M2C_UNK sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    M2C_UNK sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f2_657;
    f32 temp_f2_784;
    f32 var_f0_625;
    f32 var_f0_658;
    f32 var_f0_752;
    f32 var_f0_785;
    f64 temp_f0_694;
    s32 temp_r0_608;

    temp_r0_608 = this->unk78;
    switch (temp_r0_608) {                          /* irregular */
    case 1:
        var_f0_625 = this->unk94 + gUpdateTimeDelta;
        if (var_f0_625 < 1.0f) {

        } else {
            var_f0_625 = 1.0f;
        }
        if (var_f0_625 > 0.0f) {

        } else {
            var_f0_625 = 0.0f;
        }
        this->unk94 = var_f0_625;
        if (this->unk94 >= 0.99f) {
            this->unk94 = 1.0f;
        }
        if (((u8) this->unkA4 != 0) && (this->unk94 == 1.0f)) {
            temp_f2_657 = this->unk8C;
            var_f0_658 = this->unk80 + gUpdateTimeDelta;
            if (var_f0_658 < temp_f2_657) {

            } else {
                var_f0_658 = temp_f2_657;
            }
            if (var_f0_658 > 0.0f) {

            } else {
                var_f0_658 = 0.0f;
            }
            this->unk80 = var_f0_658;
            if (this->unk80 >= this->unk8C) {
                this->unk78 = 0;
                return;
            }
            MKVector(100.0f, 100.0f, 100.0f);
            sp38.operator*(gUpdateTimeDelta);
            temp_f0_694 = M2C_FIELD(this, f64 *, 0x40) + M2C_BITWISE(f64, sp38);
            sp8 = temp_f0_694;
            sp48 = temp_f0_694;
            sp10 = this->unk48 + sp38.unk8;
            sp50 = (f64) sp10;
            MKVector(1.0f, 0.1f, 1.0f);
            Min(sp18, *((MKVector3 *) &sp48));
            Max(sp68, sp18);
            M2C_FIELD(this, f64 *, 0x40) = M2C_BITWISE(f64, sp68);
            M2C_FIELD(this, f32 *, 0x48) = (f64) sp68.unk8;
            this->unk50 += 30.0f * gUpdateTimeDelta;
            this->unk58 += 30.0f * gUpdateTimeDelta;
            this->unk54 += 3.0f * gUpdateTimeDelta;
            goto block_27;
        }
block_27:
        this->unk84 += gUpdateTimeDelta;
        if (this->unk84 > 0.2f) {
            this->unk84 = 0.0f;
            return;
        }
    case 3:
        return;
    case 2:
        var_f0_752 = (2.0f * gUpdateTimeDelta) + this->unk94;
        if (var_f0_752 < 1.0f) {

        } else {
            var_f0_752 = 1.0f;
        }
        if (var_f0_752 > 0.0f) {

        } else {
            var_f0_752 = 0.0f;
        }
        this->unk94 = var_f0_752;
        if (this->unk94 >= 0.99f) {
            this->unk94 = 1.0f;
        }
        if (((u8) this->unkA4 != 0) && (this->unk94 == 1.0f)) {
            temp_f2_784 = this->unk88;
            var_f0_785 = this->unk80 + gUpdateTimeDelta;
            if (var_f0_785 < temp_f2_784) {

            } else {
                var_f0_785 = temp_f2_784;
            }
            if (var_f0_785 > 0.0f) {

            } else {
                var_f0_785 = 0.0f;
            }
            this->unk80 = var_f0_785;
            if (this->unk80 >= this->unk88) {
                this->unk78 = 0;
                return;
            }
        }
        break;
    case 4:
        this->unk9C -= gUpdateTimeDelta;
        if (this->unk9C < 0.0f) {
            this->unk9C = 0.125f;
        }
        this->unkA0 -= gUpdateTimeDelta;
        if (this->unkA0 <= 0.0f) {
            SetState(lit_539, 1.0f);
            return;
        }
        break;
    case 5:
        this->unkA0 -= gUpdateTimeDelta;
        if (this->unkA0 <= 0.0f) {
            SetState(lit_543, 1.0f);
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void FireAndIceFX::Init(MKModel *arg0, const float &arg1, const float &arg2) {
    Matrix sp10;
    M2C_UNK spC;
    f32 temp_f1_919;

    this->unk60 = NULL;
    this->unk60 = MKMaterial_Create("FX_Ice");
    this->unk6C = NULL;
    this->unk6C = MKMaterial_Create("FX_337");
    this->unk70 = NULL;
    this->unk70 = MKMaterial_Create("ZapEnv");
    M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10.Scale3x3(&sp10, 2.0f);
    MKMaterial_SetTextureMatrix(this->unk60, &sp10);
    sp10.SetIdentity();
    sp10.Scale3x3(&sp10, 6.0f);
    this->unk78 = 0;
    this->unk80 = 0.0f;
    temp_f1_919 = &arg2;
    this->unk74 = arg0;
    this->unk88 = &arg1;
    this->unk8C = temp_f1_919;
    this->unk90 = temp_f1_919;
    this->unk40 = 1.0f;
    this->unk44 = 1.0f;
    this->unk48 = 1.0f;
    this->unk50 = 0.0f;
    this->unk54 = 0.0f;
    this->unk58 = 0.0f;
    this->unkA4 = 0;
    this->unk84 = 0.0f;
    this->unk94 = 0.0f;
    this->unk9C = 0.0f;
    this->unkA0 = 0.0f;
    this->unkA8 = 1.0f;
}
#endif
