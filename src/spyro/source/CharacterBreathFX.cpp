#include "spyro/source/CharacterBreathFX.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 acos(f64, f32);                                 /* extern */
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
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
                EmitBreathFx(M2C_FIELD(temp_r5_36, s32 *, 4), MKRand_Float(&gViewSeed, M2C_FIELD(temp_r4_32, f32 *, 8), M2C_FIELD(temp_r4_32, f32 *, 0xC)), M2C_FIELD(temp_r5_36, f32 *, 0x10), M2C_FIELD(temp_r5_36, f32 *, 0x14), M2C_FIELD(temp_r5_36, f32 *, 0x18), M2C_FIELD(temp_r5_36, f32 *, 0x1C));
            }
            if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk8) {
                this->unk8 = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, 1.75f, 2.0f);
                this->unk10 &= ~0x80;
            }
        } else if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk8) {
            this->unk8 = M2C_FIELD(&gb, f32 *, 0x30C) + 1.25f;
            this->unk10 |= 0x80;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void CharacterBreathFX::EmitConeBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    MKVector3 sp140;
    f64 sp130;
    f64 sp120;
    Matrix spE0;
    M2C_UNK spDC;
    M2C_UNK sp9C;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f2_241;
    f64 temp_f0_191;
    f64 temp_f0_221;
    f64 var_f29_215;
    f64 var_f30_185;
    s32 temp_r4_150;
    s32 var_r27_163;
    void *temp_r26_271;
    void *temp_r3_268;

    M2C_STRUCT_COPY((s32) &sp9C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &spE0.unk3C + 4, (s32) &sp9C + 4, 0x40);
    M2C_STRUCT_COPY((s32) &spDC + 4, (s32) &sp9C + 4, 0x40);
    temp_r4_150 = *this->unk0;
    if ((u32) temp_r4_150 != -1U) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_150, &spE0, 1U);
        var_r27_163 = 0;
loop_13:
        if (var_r27_163 < arg0) {
            M2C_STRUCT_COPY((s32) &spE0.unk3C + 4, (s32) &spDC + 4, 0x40);
            if (arg5 > 0.0f) {
                if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_185 = 5.263544247e-315;
                } else {
                    var_f30_185 = 1.58735232e-314;
                }
                temp_f0_191 = sp130 * var_f30_185;
                sp40 = temp_f0_191;
                sp80 = temp_f0_191;
                sp48 = sp138 * (f32) var_f30_185;
                sp88 = (f64) sp48;
                Tools_RotateMatrixToDirection((Matrix *) &sp120, sp140, *((MKVector3 *) &sp80), MKRand_Float(&gViewSeed, arg4, arg5));
                if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f29_215 = 5.263544247e-315;
                } else {
                    var_f29_215 = 1.58735232e-314;
                }
                temp_f0_221 = sp120 * var_f29_215;
                sp30 = temp_f0_221;
                sp70 = temp_f0_221;
                sp38 = sp128 * (f32) var_f29_215;
                sp78 = (f64) sp38;
                Tools_RotateMatrixToDirection((Matrix *) &sp120, sp140, *((MKVector3 *) &sp70), MKRand_Float(&gViewSeed, arg4, arg5));
            }
            temp_f2_241 = -sp140.unk0;
            sp10 = temp_f2_241;
            sp14 = -sp140.unk4;
            sp18 = -sp140.unk8;
            sp50 = (f64) sp10;
            sp58 = (f64) sp18;
            sp20 = sp50 * (f64) arg1;
            sp60 = sp20;
            sp28 = (f32) sp58 * arg1;
            sp90 = sp20;
            sp68 = (f64) sp28;
            sp98 = (f64) sp28;
            temp_r3_268 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), sp20, temp_f2_241);
            if (temp_r3_268 != NULL) {
                temp_r26_271 = M2C_FIELD(temp_r3_268, void **, 0x2C);
                M2C_FIELD(temp_r3_268, f64 *, 0) = sp150;
                M2C_FIELD(temp_r3_268, f64 *, 8) = sp158;
                M2C_FIELD(temp_r3_268, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_268, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_271, f64 *, 0) = sp90;
                M2C_FIELD(temp_r26_271, f64 *, 8) = sp98;
                M2C_FIELD(temp_r26_271, f32 *, 0x18) = MKRand_Float(&gViewSeed, arg2, arg3);
                M2C_FIELD(temp_r26_271, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r26_271, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
            }
            var_r27_163 += 1;
            goto loop_13;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void CharacterBreathFX::EmitBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    MKVector3 sp120;
    f64 sp110;
    M2C_UNK sp100;
    Matrix spC0;
    M2C_UNK spBC;
    M2C_UNK sp7C;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f2_613;
    f64 temp_f0_593;
    f64 var_f30_587;
    s32 temp_r4_552;
    s32 var_r27_565;
    void *temp_r26_643;
    void *temp_r3_640;

    M2C_STRUCT_COPY((s32) &sp7C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &spC0.unk3C + 4, (s32) &sp7C + 4, 0x40);
    M2C_STRUCT_COPY((s32) &spBC + 4, (s32) &sp7C + 4, 0x40);
    temp_r4_552 = *this->unk0;
    if ((u32) temp_r4_552 != -1U) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_552, &spC0, 1U);
        var_r27_565 = 0;
loop_10:
        if (var_r27_565 < arg0) {
            M2C_STRUCT_COPY((s32) &spC0.unk3C + 4, (s32) &spBC + 4, 0x40);
            if (arg5 > 0.0f) {
                if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_587 = 5.263544247e-315;
                } else {
                    var_f30_587 = 1.58735232e-314;
                }
                temp_f0_593 = sp110 * var_f30_587;
                sp30 = temp_f0_593;
                sp60 = temp_f0_593;
                sp38 = sp118 * (f32) var_f30_587;
                sp68 = (f64) sp38;
                Tools_RotateMatrixToDirection((Matrix *) &sp100, sp120, *((MKVector3 *) &sp60), MKRand_Float(&gViewSeed, arg4, arg5));
            }
            temp_f2_613 = -sp120.unk0;
            sp10 = temp_f2_613;
            sp14 = -sp120.unk4;
            sp18 = -sp120.unk8;
            sp40 = (f64) sp10;
            sp48 = (f64) sp18;
            sp20 = sp40 * (f64) arg1;
            sp50 = sp20;
            sp28 = (f32) sp48 * arg1;
            sp70 = sp20;
            sp58 = (f64) sp28;
            sp78 = (f64) sp28;
            temp_r3_640 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), sp20, temp_f2_613);
            if (temp_r3_640 != NULL) {
                temp_r26_643 = M2C_FIELD(temp_r3_640, void **, 0x2C);
                M2C_FIELD(temp_r3_640, f64 *, 0) = sp130;
                M2C_FIELD(temp_r3_640, f64 *, 8) = sp138;
                M2C_FIELD(temp_r3_640, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_640, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_643, f64 *, 0) = sp70;
                M2C_FIELD(temp_r26_643, f64 *, 8) = sp78;
                M2C_FIELD(temp_r26_643, f32 *, 0x18) = MKRand_Float(&gViewSeed, arg2, arg3);
                M2C_FIELD(temp_r26_643, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r26_643, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
            }
            var_r27_565 += 1;
            goto loop_10;
        }
    }
}
#endif

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
