#include "spyro/source/EarthShockwave.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/ExplosionWarpFX.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/KDProp.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector4' to
void EarthShockwave::Trigger(const MKVector3 &arg0, float arg1, bool arg2, MKVector4 arg3) {
    f32 temp_f1_255;
    f32 temp_f4_112;
    this->unkA8 = 1;
    this->unkA0 = 0.5f;
    this->unkAC = arg2;
    this->unkB0 = M2C_FIELD(arg3, f64 *, 0);
    this->unkB8 = M2C_FIELD(arg3, f64 *, 8);
    this->unkA4 = arg1;
    this->unk90 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk98 = M2C_FIELD(&arg0, f64 *, 8);
    arg_sp88 = 0.0f;
    arg_sp80 = 0.0f;
    arg_sp84 = -1000.0f;
    arg_sp1D0 = 0.0f;
    arg_sp1D4 = 0.0f;
    arg_sp1D8 = 0.0f;
    arg_sp1E0 = 0.0f;
    arg_sp1E4 = 0.0f;
    arg_sp1E8 = 0.0f;
    arg_sp1F0 = 0.0f;
    arg_sp1F4 = 0.0f;
    arg_sp1F8 = 0.0f;
    arg_sp1FC = 1.0f;
    arg_sp200 = 0.0f;
    arg_sp204 = 0.0f;
    arg_sp208 = 0;
    arg_sp208 = 0;
    (s8) arg_sp208 = 0;
    arg_sp20C = 0;
    arg_sp210 = 3.4028235e38f;
    arg_sp214 = 0;
    arg_sp218 = 0;
    arg_sp21C = -1;
    arg_sp220 = 0;
    arg_sp110 = (f64) arg_sp80;
    arg_sp118 = (f64) arg_sp88;
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    temp_f4_112 = (f32) M2C_FIELD(this, f64 *, 0x98);
    arg_spA8 = 0.0f;
    arg_spA0 = 0.0f;
    arg_spA4 = 200.0f;
    arg_sp78 = temp_f4_112 + (f32) arg_sp118;
    arg_sp130 = (f64) arg_spA0;
    arg_sp120 = arg_sp70;
    arg_sp128 = (f64) arg_sp78;
    arg_sp138 = (f64) arg_spA8;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    arg_sp140 = arg_sp90;
    arg_sp98 = temp_f4_112 + (f32) arg_sp138;
    arg_sp148 = (f64) arg_sp98;
    if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp140), *((MKVector3 *) &arg_sp120), (MKCollisionResult *) &arg_sp1D0, (MKCollisionMode) 4, 0x0C000002) != 0) {
        this->unk90 = (f64) arg_sp1D0;
        this->unk98 = (f64) arg_sp1D8;
    }
    M2C_STRUCT_COPY((s32) &arg_sp18C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp190.Scale3x3((Matrix *) &arg_sp190, 0.0f);
    arg_sp1C0 = (f32) M2C_FIELD(this, f64 *, 0x90);
    arg_sp1C4 = M2C_FIELD(this, f32 *, 0x94);
    arg_sp1C8 = (f32) M2C_FIELD(this, f64 *, 0x98);
    arg_sp1CC = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp190));
    MKModel_SetColor(this->unk4, *((MKVector4 *) &this->unkB0));
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        arg_sp174 = 0;
        MKVector(1.0f, 1.0f, 1.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp170 = 0x417;
        arg_sp178 = arg_sp40;
        arg_sp48 = arg_spF8 * 150.0f;
        arg_sp188 = 1;
        arg_sp180 = (f64) arg_sp48;
        arg_sp100 = arg_sp40;
        arg_sp108 = (f64) arg_sp48;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp170, arg_sp40);
    }
    M2C_STRUCT_COPY((s32) &arg_sp18C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp68 = 0.0f;
    arg_sp58 = 1.0f;
    arg_sp60 = 0.0f;
    arg_sp64 = -1.0f;
    arg_sp50 = 0.0f;
    arg_sp54 = 0.0f;
    arg_sp160 = (f64) arg_sp60;
    arg_sp168 = (f64) arg_sp68;
    arg_sp150 = (f64) arg_sp50;
    arg_sp158 = (f64) arg_sp58;
    KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp190, *((MKVector3 *) &arg_sp160), (MKVector3 *) &arg_sp150);
    temp_f1_255 = 2.0f * arg1;
    arg_sp38 = 0.75f;
    arg_sp30 = temp_f1_255;
    arg_sp34 = temp_f1_255;
    arg_spE8 = (f64) arg_sp38;
    arg_spE0 = (f64) arg_sp30;
    arg_sp190.Scale3x3((Matrix *) &arg_sp190, *((MKVector3 *) &arg_spE0));
    arg_sp10 = -(f32) arg_sp160;
    arg_sp14 = -arg_sp164;
    arg_sp18 = -(f32) arg_sp168;
    arg_spB0 = (f64) arg_sp10;
    arg_spB8 = (f64) arg_sp18;
    arg_spC0.operator*(175.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spD0 = arg_sp20;
    arg_sp28 = (f32) M2C_FIELD(this, f64 *, 0x98) + arg_spC8;
    arg_spD8 = (f64) arg_sp28;
    arg_sp1C0 = (f32) arg_spD0;
    arg_sp1C4 = arg_spD4;
    arg_sp1C8 = (f32) arg_spD8;
    arg_sp1CC = 1.0f;
    ((ExplosionWarpFX *) (&gb + 0x1C0))->StartWarp((Matrix *) &arg_sp190);
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

#if 0 // DRAFT: undefined identifier 'arg_spBC'
void EarthShockwave::Update() {
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
        M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f2_442 = this->unkA4;
        temp_f28_444 = 1.0f - temp_f29_432;
        temp_f1_451 = 15.0f * (temp_f28_444 * temp_f2_442);
        arg_sp2C = 20.0f * (temp_f29_432 * temp_f2_442);
        arg_sp28 = temp_f1_451;
        arg_sp30 = temp_f1_451;
        arg_sp88 = (f64) arg_sp28;
        arg_sp90 = (f64) arg_sp30;
        arg_spC0.Scale3x3((Matrix *) &arg_spC0, *((MKVector3 *) &arg_sp88));
        arg_spF0 = M2C_FIELD(this, f32 *, 0x90);
        arg_spF4 = M2C_FIELD(this, f32 *, 0x94);
        arg_spF8 = M2C_FIELD(this, f32 *, 0x98);
        arg_spFC = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_spC0));
        arg_sp48 = M2C_FIELD(this, f32 *, 0xB0) * temp_f29_432;
        arg_sp4C = M2C_FIELD(this, f32 *, 0xB4) * temp_f29_432;
        arg_sp50 = M2C_FIELD(this, f32 *, 0xB8) * temp_f29_432;
        arg_sp54 = 1.0f;
        arg_sp78 = (f64) arg_sp48;
        arg_sp80 = (f64) arg_sp50;
        MKModel_SetColor(this->unk4, *((MKVector4 *) &arg_sp78));
        if ((u8) this->unkAC != 0) {
            temp_r28_496 = MKRand_Int(&gViewSeed, 0xA, 0xF);
            var_r27_507 = 0;
            temp_f25_510 = 200.0f * (temp_f28_444 * this->unkA4);
            temp_f26_516 = 6.2831855f / (f32) (temp_r28_496 - 1);
loop_14:
            if (var_r27_507 < temp_r28_496) {
                temp_f23_524 = temp_f26_516 * (f32) var_r27_507;
                temp_f24_527 = -_table_sinf(1.5707964f + temp_f23_524);
                arg_sp18 = _table_sinf(temp_f23_524);
                arg_sp1C = 0.25f;
                arg_sp20 = temp_f24_527;
                arg_sp68 = (f64) arg_sp18;
                arg_sp70 = (f64) arg_sp20;
                arg_sp98 = (f64) arg_sp18;
                arg_spA0 = (f64) arg_sp20;
                temp_f2_547 = (f32) arg_spA0 * temp_f25_510;
                arg_spAC = 100.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
                arg_spA8 = (f32) arg_sp98 * temp_f25_510;
                arg_spB0 = temp_f2_547;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_spB0 = temp_f2_547 + M2C_FIELD(this, f32 *, 0x98);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                arg_sp58 = arg_sp38;
                arg_sp40 = (f32) arg_spA0 * 300.0f;
                arg_sp60 = (f64) arg_sp40;
                arg_sp14 = MKRand_Float(&gViewSeed, 1.0f, 1.5f);
                arg_sp10 = MKRand_Int(&gViewSeed, 0, 3);
                ((FallingLeaves *) (M2C_FIELD(&gb, FallingLeaves **, 0x234)))->Emit(*((MKVector3 *) &arg_spA8), *((MKVector3 *) &arg_sp58), arg_sp14, arg_sp10, 1U);
                var_r27_507 += 1;
                goto loop_14;
            }
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkA0 == 0.0f) {
            this->unkA8 = 0;
        }
    }
}
#endif

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
