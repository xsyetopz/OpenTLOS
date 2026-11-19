#include "spyro/source/ExplosionFX.h"
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
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(Matrix **);                            /* extern */
Matrix **malloc(M2C_UNK);                           /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void ExplosionFX::CreateShockwave(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix **temp_r6_46;
    Matrix **temp_r6_50;
    Matrix *temp_r31_56;

    temp_r6_46 = this->unk58;
    if ((u32) M2C_FIELD(temp_r6_46, u32 *, -4) != 0U) {
        temp_r6_50 = temp_r6_46 - 4;
        this->unk58 = temp_r6_50;
        temp_r31_56 = *temp_r6_50;
        M2C_FIELD(temp_r31_56, f32 *, 0x40) = 0.0f;
        M2C_FIELD(temp_r31_56, f32 *, 0x44) = arg2;
        M2C_STRUCT_COPY(temp_r31_56, &Matrix::identity, 0x40);
        sp10 = 0.0f;
        sp8 = 0.0f;
        spC = 1.0f;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        KDMath_BuildMatrixFromFwd(temp_r31_56, arg1, (MKVector3 *) &sp18);
        temp_r31_56->unk30 = arg0.unk0;
        temp_r31_56->unk34 = arg0.unk4;
        temp_r31_56->unk38 = arg0.unk8;
        temp_r31_56->unk3C = 1.0f;
    }
}

void ExplosionFX::CreateTendril(const MKVector3 &arg0, float arg1) {
    Matrix **temp_r5_104;
    Matrix **temp_r5_108;
    Matrix *temp_r31_113;

    temp_r5_104 = this->unk50;
    if ((u32) M2C_FIELD(temp_r5_104, u32 *, -4) != 0U) {
        temp_r5_108 = temp_r5_104 - 4;
        this->unk50 = temp_r5_108;
        temp_r31_113 = *temp_r5_108;
        temp_r31_113->unk14 = 0.0f;
        temp_r31_113->unk18 = arg1;
        M2C_FIELD(temp_r31_113, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r31_113, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        temp_r31_113->unk10 = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
    }
}

#if 0 // DRAFT: type mismatch
void ExplosionFX::Deinit() {
    MKMaterial *temp_r3_181;
    MKMaterial *temp_r3_228;
    Matrix **var_r30_140;
    Matrix **var_r30_187;
    Matrix **var_r3_141;
    Matrix **var_r3_188;
    Matrix **var_r4_139;
    Matrix **var_r4_186;
    Matrix *temp_r0_144;
    Matrix *temp_r0_163;
    Matrix *temp_r0_191;
    Matrix *temp_r0_210;
    u32 temp_r0_149;
    u32 temp_r0_196;

    var_r4_139 = this->unk50;
    var_r30_140 = var_r4_139;
    var_r3_141 = var_r4_139;
loop_3:
    temp_r0_149 = M2C_FIELD(var_r3_141, u32 *, -4);
    var_r3_141 -= 4;
    if (temp_r0_149 != 0U) {
        temp_r0_144 = *var_r3_141;
        if (temp_r0_144 < var_r30_140) {
            var_r30_140 = (Matrix **) temp_r0_144;
        }
        goto loop_3;
    }
    if (var_r3_141 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_163 = *var_r4_139;
        if (temp_r0_163 != NULL) {
            if (temp_r0_163 < var_r30_140) {
                var_r30_140 = (Matrix **) temp_r0_163;
            }
            var_r4_139 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r30_140, NULL, 0);
        } else {
            free(var_r30_140);
        }
    }
    this->unk50 = NULL;
    temp_r3_181 = this->unk4C;
    if (temp_r3_181 != NULL) {
        MKMaterial_Destroy(temp_r3_181);
    }
    var_r4_186 = this->unk58;
    var_r30_187 = var_r4_186;
    var_r3_188 = var_r4_186;
loop_18:
    temp_r0_196 = M2C_FIELD(var_r3_188, u32 *, -4);
    var_r3_188 -= 4;
    if (temp_r0_196 != 0U) {
        temp_r0_191 = *var_r3_188;
        if (temp_r0_191 < var_r30_187) {
            var_r30_187 = (Matrix **) temp_r0_191;
        }
        goto loop_18;
    }
    if (var_r3_188 != &gEmptyPtrListDL) {
loop_24:
        temp_r0_210 = *var_r4_186;
        if (temp_r0_210 != NULL) {
            if (temp_r0_210 < var_r30_187) {
                var_r30_187 = (Matrix **) temp_r0_210;
            }
            var_r4_186 += 4;
            goto loop_24;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r30_187, NULL, 0);
        } else {
            free(var_r30_187);
        }
    }
    this->unk58 = NULL;
    temp_r3_228 = this->unk54;
    if (temp_r3_228 != NULL) {
        MKMaterial_Destroy(temp_r3_228);
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void ExplosionFX::DrawShockwaves() {
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;                                      /* compiler-managed */
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    MKVector3 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
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
    Matrix **var_r24_306;
    Matrix *temp_r3_511;
    f32 temp_f24_313;
    f32 temp_f25_320;
    f32 temp_f4_458;

    MKMaterial_SetMaterial(this->unk54);
    MKPrimitive(0xC, 0x10);
    spA0 = 0.0f;
    sp90 = 0.0f;
    spA8 = 1.0f;
    spAC = 0.8f;
    spB0 = 0.0f;
    spB4 = 1.0f;
    sp98 = 0.0f;
    sp9C = 1.0f;
    sp88 = 1.0f;
    sp8C = 0.0f;
    sp1D8 = (f64) spA8;
    sp1E0 = (f64) spB0;
    sp1C8 = (f64) sp98;
    sp1D0 = (f64) spA0;
    sp1B8 = (f64) sp88;
    sp1C0 = (f64) sp90;
    var_r24_306 = this->unk58;
loop_2:
    if (var_r24_306 != NULL) {
        temp_r3_511 = *var_r24_306;
        if (temp_r3_511 != NULL) {
            temp_f24_313 = M2C_FIELD(temp_r3_511, f32 *, 0x40) / 0.5f;
            sp38 = -(f32) sp1B8;
            temp_f25_320 = (1500.0f * temp_f24_313) + 500.0f;
            sp3C = -(*(f32 *) ((u8 *) &sp1B8 + 0x4));
            sp40 = -(f32) sp1C0;
            sp178 = (f64) sp38;
            sp180 = (f64) sp40;
            sp188.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp198.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp78 = sp198 + M2C_BITWISE(f64, sp188);
            sp1E8 = sp78;
            sp80 = sp198.unk8 + sp188.unk8;
            sp1A8 = sp78;
            sp1F0 = (f64) sp80;
            sp1B0 = (f64) sp80;
            sp148.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp158.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp68 = sp158 + M2C_BITWISE(f64, sp148);
            sp30 = -(f32) sp1C0;
            sp70 = sp158.unk8 + sp148.unk8;
            sp28 = -(f32) sp1B8;
            sp2C = -(*(f32 *) ((u8 *) &sp1B8 + 0x4));
            sp1F8 = sp68;
            sp200 = (f64) sp70;
            spF8 = (f64) sp28;
            sp100 = (f64) sp30;
            sp168 = sp68;
            sp170 = (f64) sp70;
            sp108.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp18 = -(f32) sp1C8;
            sp1C = -(*(f32 *) ((u8 *) &sp1C8 + 0x4));
            sp20 = -(f32) sp1D0;
            sp118 = (f64) sp18;
            sp120 = (f64) sp20;
            sp128.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp58 = sp128 + M2C_BITWISE(f64, sp108);
            sp208 = sp58;
            sp60 = sp128.unk8 + sp108.unk8;
            sp138 = sp58;
            sp210 = (f64) sp60;
            sp140 = (f64) sp60;
            spB8.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp8 = -(f32) sp1C8;
            spC = -(*(f32 *) ((u8 *) &sp1C8 + 0x4));
            sp10 = -(f32) sp1D0;
            spC8 = (f64) sp8;
            spD0 = (f64) sp10;
            spD8.operator*(temp_f25_320 * M2C_FIELD(*var_r24_306, f32 *, 0x44));
            sp48 = spD8 + M2C_BITWISE(f64, spB8);
            temp_f4_458 = 1.0f - temp_f24_313;
            sp1D8 = temp_f4_458;
            sp218 = sp48;
            sp50 = spD8.unk8 + spB8.unk8;
            (*(f32 *) ((u8 *) &sp1D0 + 0xc)) = 0.8f * temp_f4_458;
            sp220 = (f64) sp50;
            sp1E0 = 0.0f;
            (*(f32 *) ((u8 *) &sp1D0 + 0x14)) = 1.0f;
            spE8 = sp48;
            spF0 = (f64) sp50;
            MKSetMatrix(*(*var_r24_306));
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp1D8));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp1E8));
            MKSetColorV(*((MKVector4 *) &sp1D8));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp1F8));
            MKSetColorV(*((MKVector4 *) &sp1D8));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp208));
            MKSetColorV(*((MKVector4 *) &sp1D8));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp218));
            MKEnd();
            var_r24_306 += 4;
            goto loop_2;
        }
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void ExplosionFX::DrawTendrils() {
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    Matrix sp1B0;
    Matrix sp170;
    f64 sp168;                                      /* compiler-managed */
    f64 sp160;                                      /* compiler-managed */
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    MKVector3 spD0;
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
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Matrix **var_r25_600;
    Matrix *temp_r31_601;
    Matrix *temp_r3_795;
    Matrix *temp_r4_745;
    f32 temp_f1_746;
    f32 temp_f23_618;
    f32 temp_f24_641;
    f32 temp_f25_625;
    f32 temp_f26_703;
    f32 temp_f27_693;
    f32 temp_f4_690;

    MKMaterial_SetMaterial(this->unk4C);
    MKPrimitive(0xC, 0x10);
    sp90 = 1.0f;
    sp94 = 1.0f;
    sp88 = 0.0f;
    sp78 = 0.0f;
    sp98 = 1.0f;
    sp9C = 1.0f;
    sp80 = 0.0f;
    sp84 = 1.0f;
    sp70 = 1.0f;
    sp74 = 0.0f;
    sp160 = (f64) sp90;
    sp168 = (f64) sp98;
    sp150 = (f64) sp80;
    sp158 = (f64) sp88;
    sp140 = (f64) sp70;
    sp148 = (f64) sp78;
    var_r25_600 = this->unk50;
    temp_r31_601 = MKView_GetCameraMatrix();
loop_2:
    if (var_r25_600 != NULL) {
        temp_r3_795 = *var_r25_600;
        if (temp_r3_795 != NULL) {
            temp_f23_618 = temp_r3_795->unk14 / 0.5f;
            sp20 = -(f32) sp140;
            temp_f25_625 = 100.0f * temp_f23_618;
            sp24 = -(*(f32 *) ((u8 *) &sp140 + 0x4));
            sp28 = -(f32) sp148;
            sp100 = (f64) sp20;
            sp108 = (f64) sp28;
            sp110.operator*((*var_r25_600)->unk18 * temp_f25_625);
            temp_f24_641 = 3.0f * (400.0f * temp_f23_618);
            sp120.operator*((*var_r25_600)->unk18 * temp_f24_641);
            sp60 = sp120 + M2C_BITWISE(f64, sp110);
            sp1F0 = sp60;
            sp68 = sp120.unk8 + sp110.unk8;
            sp130 = sp60;
            sp1F8 = (f64) sp68;
            sp138 = (f64) sp68;
            spD0.operator*((*var_r25_600)->unk18 * temp_f25_625);
            spE0.operator*((*var_r25_600)->unk18 * temp_f24_641);
            sp50 = spE0 + M2C_BITWISE(f64, spD0);
            sp58 = spE0.unk8 + spD0.unk8;
            sp200 = sp50;
            sp208 = (f64) sp58;
            sp18 = -(f32) sp148;
            temp_f4_690 = (*var_r25_600)->unk18;
            sp10 = -(f32) sp140;
            temp_f27_693 = temp_f4_690 * temp_f25_625;
            sp14 = -(*(f32 *) ((u8 *) &sp140 + 0x4));
            spF0 = sp50;
            spB0 = (f64) sp10;
            spF8 = (f64) sp58;
            spB8 = (f64) sp18;
            sp40 = spB0 * (f64) temp_f27_693;
            temp_f26_703 = temp_f4_690 * temp_f25_625;
            spC0 = sp40;
            sp48 = (f32) spB8 * temp_f27_693;
            sp210 = sp40;
            spC8 = (f64) sp48;
            sp218 = (f64) sp48;
            sp30 = sp140 * (f64) temp_f26_703;
            sp38 = (f32) sp148 * temp_f26_703;
            spA0 = sp30;
            spA8 = (f64) sp38;
            sp220 = sp30;
            sp228 = (f64) sp38;
            sp1B0.SetIdentity();
            sp1B0.RotateRoll(&sp1B0, (*var_r25_600)->unk10);
            M2C_STRUCT_COPY((s32) &(*(f32 *) ((u8 *) &sp158 + 0x14)) + 4, (s32) (temp_r31_601 - 4) + 4, 0x40);
            sp1B0.Multiply3x3(&sp1B0, &sp170);
            temp_r4_745 = *var_r25_600;
            temp_f1_746 = 1.0f - temp_f23_618;
            sp1B0.unk30 = temp_r4_745->unk0;
            sp1B0.unk34 = temp_r4_745->unk4;
            sp1B0.unk38 = temp_r4_745->unk8;
            sp1B0.unk3C = 1.0f;
            sp160 = temp_f1_746;
            (*(f32 *) ((u8 *) &sp158 + 0xc)) = temp_f1_746;
            sp168 = temp_f1_746;
            (*(f32 *) ((u8 *) &sp158 + 0x14)) = 1.0f;
            MKSetMatrix(sp1B0);
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp160));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp1F0));
            MKSetColorV(*((MKVector4 *) &sp160));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp200));
            MKSetColorV(*((MKVector4 *) &sp160));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp210));
            MKSetColorV(*((MKVector4 *) &sp160));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp220));
            MKEnd();
            var_r25_600 += 4;
            goto loop_2;
        }
    }
    MKEndPrimitive();
}
#endif

void ExplosionFX::Draw() {
    DrawTendrils();
    DrawShockwaves();
}

void *ExplosionFX::Update() {
    Matrix **temp_r4_862;
    Matrix **temp_r4_891;
    Matrix **var_r6_849;
    Matrix **var_r6_878;
    Matrix *temp_r4_874;
    Matrix *temp_r4_903;
    Matrix *temp_r5_865;
    Matrix *temp_r5_894;

    var_r6_849 = this->unk50;
loop_4:
    if (var_r6_849 != NULL) {
        temp_r4_874 = *var_r6_849;
        if (temp_r4_874 != NULL) {
            temp_r4_874->unk14 += gUpdateTimeDelta;
            if ((*var_r6_849)->unk14 >= 0.5f) {
                temp_r4_862 = this->unk50;
                this->unk50 = temp_r4_862 + 4;
                temp_r5_865 = *temp_r4_862;
                *temp_r4_862 = *var_r6_849;
                *var_r6_849 = temp_r5_865;
            }
            var_r6_849 += 4;
            goto loop_4;
        }
    }
    var_r6_878 = this->unk58;
loop_10:
    if (var_r6_878 != NULL) {
        temp_r4_903 = *var_r6_878;
        if (temp_r4_903 == NULL) {
            return;
        }
        M2C_FIELD(temp_r4_903, f32 *, 0x40) = (f32) (M2C_FIELD(temp_r4_903, f32 *, 0x40) + gUpdateTimeDelta);
        if (M2C_FIELD(*var_r6_878, f32 *, 0x40) >= 0.5f) {
            temp_r4_891 = this->unk58;
            this->unk58 = temp_r4_891 + 4;
            temp_r5_894 = *temp_r4_891;
            *temp_r4_891 = *var_r6_878;
            *var_r6_878 = temp_r5_894;
        }
        var_r6_878 += 4;
        goto loop_10;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ExplosionFX::Init() {
    Matrix **temp_r3_940;
    Matrix **temp_r3_977;
    Matrix **temp_r4_946;
    Matrix **temp_r4_983;
    Matrix **var_r3_925;
    Matrix **var_r3_962;
    Matrix **var_r5_934;
    Matrix **var_r5_971;
    s32 var_ctr_938;
    s32 var_ctr_975;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_925 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x170, NULL, 0);
    } else {
        var_r3_925 = malloc(0x170);
    }
    this->unk50 = var_r3_925;
    var_r5_934 = this->unk50;
    this->unk50 = var_r5_934 + 0x140;
    M2C_FIELD(var_r5_934, s32 *, 0x140) = 0;
    var_ctr_938 = 0xA;
    do {
        temp_r3_940 = this->unk50;
        this->unk50 = temp_r3_940 + 4;
        M2C_FIELD(temp_r3_940, Matrix ***, 4) = var_r5_934;
        var_r5_934 += 0x20;
        var_ctr_938 -= 1;
    } while (var_ctr_938 != 0);
    temp_r4_946 = this->unk50;
    this->unk50 = temp_r4_946 + 4;
    M2C_FIELD(temp_r4_946, Matrix ***, 4) = NULL;
    this->unk4C = MKMaterial_Create("fx_338");
    if (MKHeap::Current() != NULL) {
        var_r3_962 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x350, NULL, 0);
    } else {
        var_r3_962 = malloc(0x350);
    }
    this->unk58 = var_r3_962;
    var_r5_971 = this->unk58;
    this->unk58 = var_r5_971 + 0x320;
    M2C_FIELD(var_r5_971, s32 *, 0x320) = 0;
    var_ctr_975 = 0xA;
    do {
        temp_r3_977 = this->unk58;
        this->unk58 = temp_r3_977 + 4;
        M2C_FIELD(temp_r3_977, Matrix ***, 4) = var_r5_971;
        var_r5_971 += 0x50;
        var_ctr_975 -= 1;
    } while (var_ctr_975 != 0);
    temp_r4_983 = this->unk58;
    this->unk58 = temp_r4_983 + 4;
    M2C_FIELD(temp_r4_983, Matrix ***, 4) = NULL;
    this->unk54 = MKMaterial_Create("FX_007");
}
#endif
