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
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_FIELD(&gb, f32 *, 0x30C) == this->unkC) {
                this->unkC = M2C_FIELD(&gb, f32 *, 0x30C) + 0.15f;
                temp_r4_32 = this->unk0;
                temp_r5_36 = this->unk0;
                EmitBreathFx(M2C_FIELD(temp_r5_36, s32 *, 4), MKRand_Float(&gViewSeed, M2C_FIELD(temp_r4_32, f32 *, 8), M2C_FIELD(temp_r4_32, f32 *, 0xC)), M2C_FIELD(temp_r5_36, f32 *, 0x10), M2C_FIELD(temp_r5_36, f32 *, 0x14), M2C_FIELD(temp_r5_36, f32 *, 0x18), M2C_FIELD(temp_r5_36, f32 *, 0x1C));
            }
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_FIELD(&gb, f32 *, 0x30C) == this->unk8) {
                this->unk8 = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, 1.75f, 2.0f);
                this->unk10 &= ~0x80;
            }
        } else {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_FIELD(&gb, f32 *, 0x30C) == this->unk8) {
                this->unk8 = M2C_FIELD(&gb, f32 *, 0x30C) + 1.25f;
                this->unk10 |= 0x80;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp9C'
void CharacterBreathFX::EmitConeBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    f32 temp_f2_241;
    f32 var_f29_215;
    f32 var_f30_185;
    s32 temp_r4_150;
    s32 var_r27_163;
    void *temp_r26_271;
    void *temp_r3_268;
    M2C_STRUCT_COPY((s32) &arg_sp9C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_sp11C + 4, (s32) &arg_sp9C + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) &arg_sp9C + 4, 0x40);
    temp_r4_150 = *this->unk0;
    if ((u32) temp_r4_150 != -1U) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_150, (Matrix *) &arg_spE0, 1U);
        var_r27_163 = 0;
loop_13:
        if (var_r27_163 < arg0) {
            M2C_STRUCT_COPY((s32) &arg_sp11C + 4, (s32) &arg_spDC + 4, 0x40);
            if (arg5 > 0.0f) {
                if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_185 = 1.0f;
                } else {
                    var_f30_185 = -1.0f;
                }
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                arg_sp80 = arg_sp40;
                arg_sp48 = arg_sp138 * var_f30_185;
                arg_sp88 = (f64) arg_sp48;
                Tools_RotateMatrixToDirection((Matrix *) &arg_sp120, *((MKVector3 *) &arg_sp140), *((MKVector3 *) &arg_sp80), MKRand_Float(&gViewSeed, arg4, arg5));
                if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f29_215 = 1.0f;
                } else {
                    var_f29_215 = -1.0f;
                }
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                arg_sp70 = arg_sp30;
                arg_sp38 = arg_sp128 * var_f29_215;
                arg_sp78 = (f64) arg_sp38;
                Tools_RotateMatrixToDirection((Matrix *) &arg_sp120, *((MKVector3 *) &arg_sp140), *((MKVector3 *) &arg_sp70), MKRand_Float(&gViewSeed, arg4, arg5));
            }
            temp_f2_241 = -arg_sp140;
            arg_sp10 = temp_f2_241;
            arg_sp14 = -arg_sp144;
            arg_sp18 = -arg_sp148;
            arg_sp50 = (f64) arg_sp10;
            arg_sp58 = (f64) arg_sp18;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
            arg_sp60 = arg_sp20;
            arg_sp28 = (f32) arg_sp58 * arg1;
            arg_sp90 = arg_sp20;
            arg_sp68 = (f64) arg_sp28;
            arg_sp98 = (f64) arg_sp28;
            temp_r3_268 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), arg_sp20, temp_f2_241);
            if (temp_r3_268 != NULL) {
                temp_r26_271 = M2C_FIELD(temp_r3_268, void **, 0x2C);
                M2C_FIELD(temp_r3_268, f64 *, 0) = arg_sp150;
                M2C_FIELD(temp_r3_268, f64 *, 8) = arg_sp158;
                M2C_FIELD(temp_r3_268, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_268, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_271, f64 *, 0) = arg_sp90;
                M2C_FIELD(temp_r26_271, f64 *, 8) = arg_sp98;
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

#if 0 // DRAFT: undefined identifier 'arg_sp7C'
void CharacterBreathFX::EmitBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    f32 temp_f2_613;
    f32 var_f30_587;
    s32 temp_r4_552;
    s32 var_r27_565;
    void *temp_r26_643;
    void *temp_r3_640;
    M2C_STRUCT_COPY((s32) &arg_sp7C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) &arg_sp7C + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) &arg_sp7C + 4, 0x40);
    temp_r4_552 = *this->unk0;
    if ((u32) temp_r4_552 != -1U) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_552, (Matrix *) &arg_spC0, 1U);
        var_r27_565 = 0;
loop_10:
        if (var_r27_565 < arg0) {
            M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) &arg_spBC + 4, 0x40);
            if (arg5 > 0.0f) {
                if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_587 = 1.0f;
                } else {
                    var_f30_587 = -1.0f;
                }
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                arg_sp60 = arg_sp30;
                arg_sp38 = arg_sp118 * var_f30_587;
                arg_sp68 = (f64) arg_sp38;
                Tools_RotateMatrixToDirection((Matrix *) &arg_sp100, *((MKVector3 *) &arg_sp120), *((MKVector3 *) &arg_sp60), MKRand_Float(&gViewSeed, arg4, arg5));
            }
            temp_f2_613 = -arg_sp120;
            arg_sp10 = temp_f2_613;
            arg_sp14 = -arg_sp124;
            arg_sp18 = -arg_sp128;
            arg_sp40 = (f64) arg_sp10;
            arg_sp48 = (f64) arg_sp18;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            arg_sp50 = arg_sp20;
            arg_sp28 = (f32) arg_sp48 * arg1;
            arg_sp70 = arg_sp20;
            arg_sp58 = (f64) arg_sp28;
            arg_sp78 = (f64) arg_sp28;
            temp_r3_640 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), arg_sp20, temp_f2_613);
            if (temp_r3_640 != NULL) {
                temp_r26_643 = M2C_FIELD(temp_r3_640, void **, 0x2C);
                M2C_FIELD(temp_r3_640, f64 *, 0) = arg_sp130;
                M2C_FIELD(temp_r3_640, f64 *, 8) = arg_sp138;
                M2C_FIELD(temp_r3_640, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_640, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_643, f64 *, 0) = arg_sp70;
                M2C_FIELD(temp_r26_643, f64 *, 8) = arg_sp78;
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
