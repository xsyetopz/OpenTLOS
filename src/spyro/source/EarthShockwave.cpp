#include "spyro/source/EarthShockwave.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/ExplosionWarpFX.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/KDProp.h"
#include "unplaced_enums.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector4' to 'signed char *'
void EarthShockwave::Trigger(const MKVector3 &arg0, float arg1, bool arg2, MKVector4 arg3) {
    s8 sp220;
    s32 sp21C;
    s32 sp218;
    s32 sp214;
    f32 sp210;
    s32 sp20C;
    s8 sp20B;
    s8 sp20A;
    s16 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    Matrix sp190;
    M2C_UNK sp18C;
    s8 sp188;
    f64 sp180;
    f64 sp178;
    s32 sp174;
    s32 sp170;
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
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_255;
    f32 temp_f4_112;
    f64 temp_f0_128;
    f64 temp_f5_107;

    this->unkA8 = 1;
    this->unkA0 = 0.5f;
    this->unkAC = arg2;
    this->unkB0 = M2C_FIELD(arg3, f64 *, 0);
    this->unkB8 = M2C_FIELD(arg3, f64 *, 8);
    this->unkA4 = arg1;
    this->unk90 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk98 = M2C_FIELD(&arg0, f64 *, 8);
    sp88 = 0.0f;
    sp80 = 0.0f;
    sp84 = -1000.0f;
    sp1D0 = 0.0f;
    sp1D4 = 0.0f;
    sp1D8 = 0.0f;
    sp1E0 = 0.0f;
    sp1E4 = 0.0f;
    sp1E8 = 0.0f;
    sp1F0 = 0.0f;
    sp1F4 = 0.0f;
    sp1F8 = 0.0f;
    sp1FC = 1.0f;
    sp200 = 0.0f;
    sp204 = 0.0f;
    sp208 = 0;
    sp20A = 0;
    sp20B = 0;
    sp20C = 0;
    sp210 = 3.4028235e38f;
    sp214 = 0;
    sp218 = 0;
    sp21C = -1;
    sp220 = 0;
    sp110 = (f64) sp80;
    sp118 = (f64) sp88;
    temp_f5_107 = this->unk90;
    sp70 = temp_f5_107 + sp110;
    temp_f4_112 = (f32) M2C_FIELD(this, f64 *, 0x98);
    spA8 = 0.0f;
    spA0 = 0.0f;
    spA4 = 200.0f;
    sp78 = temp_f4_112 + (f32) sp118;
    sp130 = (f64) spA0;
    sp120 = sp70;
    sp128 = (f64) sp78;
    sp138 = (f64) spA8;
    temp_f0_128 = temp_f5_107 + sp130;
    sp90 = temp_f0_128;
    sp140 = temp_f0_128;
    sp98 = temp_f4_112 + (f32) sp138;
    sp148 = (f64) sp98;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp140), *((MKVector3 *) &sp120), (MKCollisionResult *) &sp1D0, (MKCollisionMode) 4, 0x0C000002) != 0) {
        this->unk90 = (f64) sp1D0;
        this->unk98 = (f64) sp1D8;
    }
    M2C_STRUCT_COPY((s32) &sp18C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp190.Scale3x3(&sp190, 0.0f);
    sp190.unk30 = (f32) M2C_FIELD(this, f64 *, 0x90);
    sp190.unk34 = M2C_FIELD(this, f32 *, 0x94);
    sp190.unk38 = (f32) M2C_FIELD(this, f64 *, 0x98);
    sp190.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, sp190);
    MKModel_SetColor(this->unk4, *((MKVector4 *) &this->unkB0));
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        sp174 = 0;
        MKVector(1.0f, 1.0f, 1.0f);
        sp40 = spF0 * 5.56078426e-315;
        sp170 = 0x417;
        sp178 = sp40;
        sp48 = spF8 * 150.0f;
        sp188 = 1;
        sp180 = (f64) sp48;
        sp100 = sp40;
        sp108 = (f64) sp48;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp170, sp40);
    }
    M2C_STRUCT_COPY((s32) &sp18C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp68 = 0.0f;
    sp58 = 1.0f;
    sp60 = 0.0f;
    sp64 = -1.0f;
    sp50 = 0.0f;
    sp54 = 0.0f;
    sp160 = (f64) sp60;
    sp168 = (f64) sp68;
    sp150 = (f64) sp50;
    sp158 = (f64) sp58;
    KDMath_BuildMatrixFromFwd(&sp190, *((MKVector3 *) &sp160), (MKVector3 *) &sp150);
    temp_f1_255 = 2.0f * arg1;
    sp38 = 0.75f;
    sp30 = temp_f1_255;
    sp34 = temp_f1_255;
    spE8 = (f64) sp38;
    spE0 = (f64) sp30;
    sp190.Scale3x3(&sp190, *((MKVector3 *) &spE0));
    sp10 = -(f32) sp160;
    sp14 = -(*(f32 *) ((u8 *) &sp160 + 0x4));
    sp18 = -(f32) sp168;
    spB0 = (f64) sp10;
    spB8 = (f64) sp18;
    spC0.operator*(175.0f);
    sp20 = this->unk90 + M2C_BITWISE(f64, spC0);
    spD0 = sp20;
    sp28 = (f32) M2C_FIELD(this, f64 *, 0x98) + spC0.unk8;
    spD8 = (f64) sp28;
    sp190.unk30 = (f32) spD0;
    sp190.unk34 = (*(f32 *) ((u8 *) &spD0 + 0x4));
    sp190.unk38 = (f32) spD8;
    sp190.unk3C = 1.0f;
    ((ExplosionWarpFX *) (&gb + 0x1C0))->StartWarp(&sp190);
}
#endif

void EarthShockwave::Deinit() {
    KDProp::Deinit();
}

void EarthShockwave::Draw() {
    f32 sp8;
    f32 temp_f2_352;

    if ((s32) this->unkA8 != 0) {
        MKView_Push();
        MKView_GetProjection(NULL, &sp8, NULL);
        temp_f2_352 = sp8 + 5.0f;
        sp8 = temp_f2_352;
        MKView_SetProjection(0.0f, temp_f2_352, 0.0f);
        MKModel_Draw(this->unk4, NULL);
        MKView_Pop();
    }
}

void *EarthShockwave::Update() {
    Matrix spC0;
    M2C_UNK spBC;
    f32 spB0;
    f32 spAC;
    f32 spA8;                                       /* compiler-managed */
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    f32 temp_f1_451;
    f32 temp_f23_524;
    f32 temp_f24_527;
    f32 temp_f25_510;
    f32 temp_f26_516;
    f32 temp_f28_444;
    f32 temp_f29_432;
    f32 temp_f2_442;
    f32 temp_f2_547;
    f32 var_f0_410;
    f64 temp_f0_561;
    s32 temp_r0_397;
    s32 temp_r28_496;
    s32 var_r27_507;

    temp_r0_397 = this->unkA8;
    if (temp_r0_397 != 1) {
        if ((temp_r0_397 < 1) && (temp_r0_397 < 0)) {

        }
    } else {
        var_f0_410 = -((3.0f * gUpdateTimeDelta) - this->unkA0);
        if (var_f0_410 < 0.5f) {

        } else {
            var_f0_410 = 0.5f;
        }
        if (var_f0_410 > 0.0f) {

        } else {
            var_f0_410 = 0.0f;
        }
        this->unkA0 = var_f0_410;
        temp_f29_432 = this->unkA0 / 0.5f;
        M2C_STRUCT_COPY((s32) &spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f2_442 = this->unkA4;
        temp_f28_444 = 1.0f - temp_f29_432;
        temp_f1_451 = 15.0f * (temp_f28_444 * temp_f2_442);
        sp2C = 20.0f * (temp_f29_432 * temp_f2_442);
        sp28 = temp_f1_451;
        sp30 = temp_f1_451;
        sp88 = (f64) sp28;
        sp90 = (f64) sp30;
        spC0.Scale3x3(&spC0, *((MKVector3 *) &sp88));
        spC0.unk30 = M2C_FIELD(this, f32 *, 0x90);
        spC0.unk34 = M2C_FIELD(this, f32 *, 0x94);
        spC0.unk38 = M2C_FIELD(this, f32 *, 0x98);
        spC0.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, spC0);
        sp48 = M2C_FIELD(this, f32 *, 0xB0) * temp_f29_432;
        sp4C = M2C_FIELD(this, f32 *, 0xB4) * temp_f29_432;
        sp50 = M2C_FIELD(this, f32 *, 0xB8) * temp_f29_432;
        sp54 = 1.0f;
        sp78 = (f64) sp48;
        sp80 = (f64) sp50;
        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp78));
        if ((u8) this->unkAC != 0) {
            temp_r28_496 = MKRand_Int((int *) &gViewSeed, 0xA, 0xF);
            var_r27_507 = 0;
            temp_f25_510 = 200.0f * (temp_f28_444 * this->unkA4);
            temp_f26_516 = 6.2831855f / (f32) (temp_r28_496 - 1);
loop_14:
            if (var_r27_507 < temp_r28_496) {
                temp_f23_524 = temp_f26_516 * (f32) var_r27_507;
                temp_f24_527 = -_table_sinf(1.5707964f + temp_f23_524);
                sp18 = _table_sinf(temp_f23_524);
                sp1C = 0.25f;
                sp20 = temp_f24_527;
                sp68 = (f64) sp18;
                sp70 = (f64) sp20;
                sp98 = (f64) sp18;
                spA0 = (f64) sp20;
                temp_f2_547 = (f32) spA0 * temp_f25_510;
                spAC = 100.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
                spA8 = (f32) sp98 * temp_f25_510;
                spB0 = temp_f2_547;
                spA8 = (f64) spA8 + this->unk90;
                spB0 = temp_f2_547 + M2C_FIELD(this, f32 *, 0x98);
                temp_f0_561 = sp98 * 5.60222949e-315;
                sp38 = temp_f0_561;
                sp58 = temp_f0_561;
                sp40 = (f32) spA0 * 300.0f;
                sp60 = (f64) sp40;
                sp14 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                sp10 = MKRand_Int((int *) &gViewSeed, 0, 3);
                ((FallingLeaves *) (M2C_FIELD(&gb, FallingLeaves **, 0x234)))->Emit(*((MKVector3 *) &spA8), *((MKVector3 *) &sp58), sp14, sp10, 1U);
                var_r27_507 += 1;
                goto loop_14;
            }
        }
        if (this->unkA0 <= 0.0f) {
            this->unkA8 = 0;
        }
    }
}

void EarthShockwave::Init() {
    KDProp::Init();
    this->unkA8 = 0;
    this->unkA0 = 0.0f;
    this->unkA4 = 1.0f;
    this->unkAC = 0;
    M2C_FIELD(this, f32 *, 0xB0) = 1.0f;
    M2C_FIELD(this, f32 *, 0xB4) = 1.0f;
    M2C_FIELD(this, f32 *, 0xB8) = 1.0f;
    M2C_FIELD(this, f32 *, 0xBC) = 1.0f;
}
