#include "spyro/source/CharacterBreathFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

f64 acos(f64, f32);                                 /* extern */
extern s32 gViewSeed;
extern M2C_UNK gb;

void CharacterBreathFX::UpdateBreathingFX() {
    s32 *temp_r4_32;
    s32 *temp_r5_36;
    u8 temp_r3_16;

    temp_r3_16 = this->unk10;
    if ((temp_r3_16 >> 6U) & 1) {
        if ((temp_r3_16 >> 7U) & 1) {
            if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC) {
                this->unkC = M2C_FIELD(&gb, f32 *, 0x30C) + 0.15f;
                temp_r4_32 = this->unk0;
                temp_r5_36 = this->unk0;
                EmitBreathFx(M2C_FIELD(temp_r5_36, s32 *, 4), MKRand_Float((int *) &gViewSeed, M2C_FIELD(temp_r4_32, f32 *, 8), M2C_FIELD(temp_r4_32, f32 *, 0xC)), M2C_FIELD(temp_r5_36, f32 *, 0x10), M2C_FIELD(temp_r5_36, f32 *, 0x14), M2C_FIELD(temp_r5_36, f32 *, 0x18), M2C_FIELD(temp_r5_36, f32 *, 0x1C));
            }
            if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk8) {
                this->unk8 = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float((int *) &gViewSeed, 1.75f, 2.0f);
                this->unk10 &= ~0x80;
            }
        } else if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk8) {
            this->unk8 = M2C_FIELD(&gb, f32 *, 0x30C) + 1.25f;
            this->unk10 |= 0x80;
        }
    }
}

void CharacterBreathFX::EmitConeBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    MKVector3 sp140;
    MKVector3 sp130;
    MKVector3 sp120;
    MKVector3 sp80;
    MKVector3 sp70;
    MKVector3 sp20;
    Matrix spE0;
    f64 sp150;
    f64 sp158;
    void *temp_r3_268;
    void *temp_r26_271;
    f32 var_f30_185;
    f32 var_f29_215;
    s32 temp_r4_150;
    s32 var_r27_163;

    temp_r4_150 = *this->unk0;
    if ((u32) temp_r4_150 != 0xFFFF) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_150, &spE0, 1U);
        var_r27_163 = 0;
        while (var_r27_163 < arg0) {
            if (arg5 > 0.0f) {
                if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_185 = 1.0f;
                } else {
                    var_f30_185 = -1.0f;
                }
                sp80.unk0 = sp130.unk0 * var_f30_185;
                sp80.unk4 = sp130.unk4 * var_f30_185;
                sp80.unk8 = sp130.unk8 * var_f30_185;
                Tools_RotateMatrixToDirection((Matrix *) &sp120, sp140, sp80, MKRand_Float((int *) &gViewSeed, arg4, arg5));
                if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f29_215 = 1.0f;
                } else {
                    var_f29_215 = -1.0f;
                }
                sp70.unk0 = sp120.unk0 * var_f29_215;
                sp70.unk4 = sp120.unk4 * var_f29_215;
                sp70.unk8 = sp120.unk8 * var_f29_215;
                Tools_RotateMatrixToDirection((Matrix *) &sp120, sp140, sp70, MKRand_Float((int *) &gViewSeed, arg4, arg5));
            }
            sp20.unk0 = -sp140.unk0 * arg1;
            sp20.unk4 = -sp140.unk4 * arg1;
            sp20.unk8 = -sp140.unk8 * arg1;
            temp_r3_268 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), *(f64 *) &sp20, -sp140.unk0);
            if (temp_r3_268 != NULL) {
                temp_r26_271 = M2C_FIELD(temp_r3_268, void **, 0x2C);
                M2C_FIELD(temp_r3_268, f64 *, 0) = sp150;
                M2C_FIELD(temp_r3_268, f64 *, 8) = sp158;
                M2C_FIELD(temp_r3_268, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_268, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_271, f64 *, 0) = *(f64 *) &sp20;
                M2C_FIELD(temp_r26_271, f64 *, 8) = (f64) sp20.unk8;
                M2C_FIELD(temp_r26_271, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, arg2, arg3);
                M2C_FIELD(temp_r26_271, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r26_271, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
            }
            var_r27_163 += 1;
        }
    }
}

void CharacterBreathFX::EmitBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    MKVector3 sp120;
    MKVector3 sp110;
    MKVector3 sp60;
    MKVector3 sp20;
    Matrix sp7C;
    Matrix spC0;
    Matrix sp100;
    f64 sp130;
    f64 sp138;
    void *temp_r3_640;
    void *temp_r26_643;
    f32 var_f30_587;
    s32 var_r27_565;
    s32 temp_r4_552;

    sp7C = Matrix::identity;
    spC0 = sp7C;
    sp100 = sp7C;
    temp_r4_552 = *this->unk0;
    if ((u32) temp_r4_552 != 0xFFFF) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_552, &spC0, 1U);
        var_r27_565 = 0;
        while (var_r27_565 < arg0) {
            sp100 = spC0;
            if (arg5 > 0.0f) {
                if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_587 = 1.0f;
                } else {
                    var_f30_587 = -1.0f;
                }
                sp60.unk0 = sp110.unk0 * var_f30_587;
                sp60.unk4 = sp110.unk4 * var_f30_587;
                sp60.unk8 = sp110.unk8 * var_f30_587;
                Tools_RotateMatrixToDirection(&sp100, sp120, sp60, MKRand_Float((int *) &gViewSeed, arg4, arg5));
            }
            sp20.unk0 = -sp120.unk0 * arg1;
            sp20.unk4 = -sp120.unk4 * arg1;
            sp20.unk8 = -sp120.unk8 * arg1;
            temp_r3_640 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), *(f64 *) &sp20, -sp120.unk0);
            if (temp_r3_640 != NULL) {
                temp_r26_643 = M2C_FIELD(temp_r3_640, void **, 0x2C);
                M2C_FIELD(temp_r3_640, f64 *, 0) = sp130;
                M2C_FIELD(temp_r3_640, f64 *, 8) = sp138;
                M2C_FIELD(temp_r3_640, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_640, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_643, f32 *, 0) = sp20.unk0;
                M2C_FIELD(temp_r26_643, f32 *, 4) = sp20.unk4;
                M2C_FIELD(temp_r26_643, f32 *, 8) = sp20.unk8;
                M2C_FIELD(temp_r26_643, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, arg2, arg3);
                M2C_FIELD(temp_r26_643, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r26_643, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
            }
            var_r27_565 += 1;
        }
    }
}

void CharacterBreathFX::SetDefaults() {
    this->unk8 = 0.0f;
    this->unkC = 0.0f;
    this->unk10 &= ~0x80;
    this->unk10 &= ~0x40;
}

void CharacterBreathFX::Deinit() {

}

void CharacterBreathFX::Init(CharacterBreathFXDescriptor *arg0, MKModel *arg1) {
    this->unk4 = arg1;
    this->unk0 = (s32 *) arg0;
}

void CharacterBreathFXDescriptor::Init() {
    this->unk0 = 0xFFFF;
    this->unk4 = 1;
    this->unk8 = 300.0f;
    this->unkC = 400.0f;
    this->unk10 = 0.25f;
    this->unk14 = 0.4f;
    this->unk18 = 0.0f;
    this->unk1C = 0.3141592f;
}
