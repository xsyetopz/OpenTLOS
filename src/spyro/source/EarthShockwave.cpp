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
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void EarthShockwave::Trigger(const MKVector3 &arg0, float arg1, bool arg2, MKVector4 arg3) {
    MKVector3 *pos;
    MKVector3 above;
    MKVector3 below;
    MKCollisionResult hit;
    Matrix sp190;
    MKVector3 spF0;
    MKVector3 vel;
    struct {
        s32 unk0;
        s32 unk4;
        MKVector3 unk8;
        u8 unk18;
    } sp170;
    f64 sp40;
    MKVector3 fwd;
    MKVector3 up;
    MKVector3 scale;
    MKVector3 negFwd;
    MKVector3 offset;

    this->unkA8 = 1;
    this->unkA0 = 0.5f;
    this->unkAC = arg2;
    *((MKVector4 *) &this->unkB0) = arg3;
    this->unkA4 = arg1;
    *((MKVector3 *) &this->unk90) = arg0;
    pos = (MKVector3 *) &this->unk90;

    above.unk0 = pos->unk0;
    above.unk4 = pos->unk4 + 200.0f;
    above.unk8 = pos->unk8;
    below.unk0 = pos->unk0;
    below.unk4 = pos->unk4 - 1000.0f;
    below.unk8 = pos->unk8;

    hit.unk0 = 0.0f;
    hit.unk4 = 0.0f;
    hit.unk8 = 0.0f;
    hit.unk10 = 0.0f;
    hit.unk14 = 0.0f;
    hit.unk18 = 0.0f;
    hit.unk20 = 0.0f;
    hit.unk24 = 0.0f;
    hit.unk28 = 0.0f;
    hit.unk2C = 1.0f;
    hit.unk30 = 0.0f;
    hit.unk34 = 0.0f;
    hit.unk38 = 0;
    hit.unk3C = 0;
    hit.unk40 = 3.4028235e38f;
    hit.unk44 = 0;
    hit.unk48 = NULL;
    hit.unk4C = -1;
    hit.unk50 = 0;
    if (MKCollision_RayCollide(above, below, &hit, (MKCollisionMode) 4, 0x0C000002) != 0) {
        *((MKVector3 *) &this->unk90) = *((MKVector3 *) &hit);
    }

    sp190 = Matrix::identity;
    sp190.Scale3x3(&sp190, 0.0f);
    sp190.unk30 = pos->unk0;
    sp190.unk34 = pos->unk4;
    sp190.unk38 = pos->unk8;
    sp190.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, sp190);
    MKModel_SetColor(this->unk4, *((MKVector4 *) &this->unkB0));

    if (M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spF0 = MKVector(1.0f, 1.0f, 1.0f);
        vel.unk0 = spF0.unk0 * 150.0f;
        vel.unk4 = spF0.unk4 * 150.0f;
        vel.unk8 = spF0.unk8 * 150.0f;
        sp170.unk0 = 0x417;
        sp170.unk4 = 0;
        sp170.unk8.unk0 = vel.unk0;
        sp170.unk8.unk4 = vel.unk4;
        sp170.unk8.unk8 = vel.unk8;
        sp170.unk18 = 1;
        sp40 = M2C_FIELD(&vel, f64 *, 0);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), (s32 *) &sp170, sp40);
    }

    sp190 = Matrix::identity;
    fwd.unk0 = 0.0f;
    fwd.unk4 = -1.0f;
    fwd.unk8 = 0.0f;
    up.unk0 = 0.0f;
    up.unk4 = 0.0f;
    up.unk8 = 1.0f;
    KDMath_BuildMatrixFromFwd(&sp190, fwd, &up);
    scale.unk0 = 2.0f * arg1;
    scale.unk4 = 2.0f * arg1;
    scale.unk8 = 0.75f;
    sp190.Scale3x3(&sp190, scale);

    negFwd.unk0 = -fwd.unk0;
    negFwd.unk4 = -fwd.unk4;
    negFwd.unk8 = -fwd.unk8;
    offset.unk0 = negFwd.unk0 * 175.0f;
    offset.unk4 = negFwd.unk4 * 175.0f;
    offset.unk8 = negFwd.unk8 * 175.0f;
    sp190.unk30 = pos->unk0 + offset.unk0;
    sp190.unk34 = pos->unk4 + offset.unk4;
    sp190.unk38 = pos->unk8 + offset.unk8;
    sp190.unk3C = 1.0f;
    ((ExplosionWarpFX *) ((u8 *) &gb + 0x1C0))->StartWarp(&sp190);
}

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
