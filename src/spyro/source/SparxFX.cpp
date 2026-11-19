#include "spyro/source/SparxFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MKAnimScript *);                       /* extern */
MKAnimScript *malloc(M2C_UNK);                      /* extern */
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_537 = 0;
static u8 lit_538 = 0;

void SparxFX::SetColor(const MKVector4 &arg0) {
    this->unkD8 = M2C_FIELD(&arg0, f64 *, 0);
    this->unkE0 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk78 = this->unkD8;
    this->unk80 = this->unkE0;
}

#if 0 // DRAFT: undefined identifier 'arg_spD0'
void SparxFX::DrawGlow(MKMaterial *arg0, float arg1, float arg2, MKVector4 arg3, Matrix *arg4, bool arg5) {
    f32 temp_f4_343;
    f32 temp_f5_342;
    f32 temp_f6_340;
    f32 var_f3_331;
    f32 var_f4_169;
    f32 var_f6_242;
    f32 var_f7_260;
    f64 temp_f1_181;
    f64 temp_f1_187;
    f64 temp_f1_191;
    f64 temp_f1_270;
    f64 temp_f1_276;
    f64 temp_f1_280;
    s32 temp_r3_210;
    s32 temp_r3_299;
    s32 var_r0_220;
    s32 var_r0_309;
    arg_spD0 = 0.0f;
    arg_spC0 = 0.0f;
    arg_spC8 = 0.0f;
    arg_spCC = 1.0f;
    arg_spB8 = 1.0f;
    arg_spBC = 0.0f;
    arg_sp208 = (f64) arg_spC8;
    arg_sp210 = (f64) arg_spD0;
    arg_sp1F8 = (f64) arg_spB8;
    arg_sp200 = (f64) arg_spC0;
    arg_sp2A0.SetIdentity();
    arg_sp2A0.RotateRoll((Matrix *) &arg_sp2A0, arg1);
    arg_spA8 = arg_sp2D0 + (((f32) arg_sp210 * arg_sp2C0) + (((f32) arg_sp208 * arg_sp2A0) + (arg_sp20C * arg_sp2B0)));
    arg_spAC = arg_sp2D4 + (((f32) arg_sp210 * arg_sp2C4) + (((f32) arg_sp208 * arg_sp2A4) + (arg_sp20C * arg_sp2B4)));
    arg_spB0 = arg_sp2D8 + (((f32) arg_sp210 * arg_sp2C8) + (((f32) arg_sp208 * arg_sp2A8) + (arg_sp20C * arg_sp2B8)));
    arg_sp208 = (f64) arg_spA8;
    arg_sp210 = (f64) arg_spB0;
    arg_sp98 = arg_sp2D0 + (((f32) arg_sp200 * arg_sp2C0) + (((f32) arg_sp1F8 * arg_sp2A0) + (arg_sp1FC * arg_sp2B0)));
    arg_sp9C = arg_sp2D4 + (((f32) arg_sp200 * arg_sp2C4) + (((f32) arg_sp1F8 * arg_sp2A4) + (arg_sp1FC * arg_sp2B4)));
    arg_spA0 = arg_sp2D8 + (((f32) arg_sp200 * arg_sp2C8) + (((f32) arg_sp1F8 * arg_sp2A8) + (arg_sp1FC * arg_sp2B8)));
    var_f4_169 = ((f32) arg_sp210 * (f32) arg_sp210) + (((f32) arg_sp208 * (f32) arg_sp208) + (arg_sp20C * arg_sp20C));
    arg_sp1E8 = (f64) arg_spA8;
    arg_sp1F0 = (f64) arg_spB0;
    arg_sp1D8 = (f64) arg_sp98;
    arg_sp1E0 = (f64) arg_spA0;
    arg_sp1F8 = (f64) arg_sp98;
    arg_sp200 = (f64) arg_spA0;
    if (var_f4_169 > 0.000001f) {
        if (var_f4_169 > 0.0f) {
            temp_f1_181 = __frsqrte(var_f4_169);
            temp_f1_187 = 0.5 * temp_f1_181 * -(((f64) var_f4_169 * (temp_f1_181 * temp_f1_181)) - 3.0);
            temp_f1_191 = 0.5 * temp_f1_187 * -(((f64) var_f4_169 * (temp_f1_187 * temp_f1_187)) - 3.0);
            var_f4_169 = (f32) ((f64) var_f4_169 * (0.5 * temp_f1_191 * -(((f64) var_f4_169 * (temp_f1_191 * temp_f1_191)) - 3.0)));
        } else if (var_f4_169 < M2C_BITWISE(f32, 0.0)) {
            var_f4_169 = __float_nan;
        } else {
            arg_sp14 = var_f4_169;
            temp_r3_210 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
            switch (temp_r3_210) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_220 = 1;
                } else {
                    var_r0_220 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_220 = 5;
                } else {
                    var_r0_220 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_220 = 4;
                break;
            }
            if (var_r0_220 == 1) {
                var_f4_169 = __float_nan;
            }
        }
        var_f6_242 = 1.0f / var_f4_169;
    } else {
        var_f6_242 = 0.0f;
    }
    var_f7_260 = ((f32) arg_sp200 * (f32) arg_sp200) + (((f32) arg_sp1F8 * (f32) arg_sp1F8) + (arg_sp1FC * arg_sp1FC));
    arg_sp208 = (f32) arg_sp208 * var_f6_242;
    arg_sp20C *= var_f6_242;
    arg_sp210 = (f32) arg_sp210 * var_f6_242;
    if (var_f7_260 > 0.000001f) {
        if (var_f7_260 > 0.0f) {
            temp_f1_270 = __frsqrte(var_f7_260);
            temp_f1_276 = 0.5 * temp_f1_270 * -(((f64) var_f7_260 * (temp_f1_270 * temp_f1_270)) - 3.0);
            temp_f1_280 = 0.5 * temp_f1_276 * -(((f64) var_f7_260 * (temp_f1_276 * temp_f1_276)) - 3.0);
            var_f7_260 = (f32) ((f64) var_f7_260 * (0.5 * temp_f1_280 * -(((f64) var_f7_260 * (temp_f1_280 * temp_f1_280)) - 3.0)));
        } else if (var_f7_260 < M2C_BITWISE(f32, 0.0)) {
            var_f7_260 = __float_nan;
        } else {
            arg_sp10 = var_f7_260;
            temp_r3_299 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_299) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_309 = 1;
                } else {
                    var_r0_309 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_309 = 5;
                } else {
                    var_r0_309 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_309 = 4;
                break;
            }
            if (var_r0_309 == 1) {
                var_f7_260 = __float_nan;
            }
        }
        var_f3_331 = 1.0f / var_f7_260;
    } else {
        var_f3_331 = 0.0f;
    }
    temp_f6_340 = (f32) arg_sp1F8 * var_f3_331;
    temp_f5_342 = arg_sp1FC * var_f3_331;
    temp_f4_343 = (f32) arg_sp200 * var_f3_331;
    arg_sp1F8 = temp_f6_340;
    arg_sp48 = -temp_f6_340;
    arg_sp4C = -temp_f5_342;
    arg_sp50 = -temp_f4_343;
    arg_sp1FC = temp_f5_342;
    arg_sp200 = temp_f4_343;
    arg_sp198 = (f64) arg_sp48;
    arg_sp1A0 = (f64) arg_sp50;
    arg_sp1A8.operator*(arg2);
    arg_sp1B8.operator*(arg2);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp1C8 = arg_sp88;
    arg_sp90 = arg_sp1C0 + arg_sp1B0;
    arg_sp260 = arg_sp88;
    arg_sp1D0 = (f64) arg_sp90;
    arg_sp268 = (f64) arg_sp90;
    arg_sp168.operator*(arg2);
    arg_sp178.operator*(arg2);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp38 = -(f32) arg_sp1F8;
    arg_sp3C = -arg_sp1FC;
    arg_sp80 = arg_sp180 + arg_sp170;
    arg_sp40 = -(f32) arg_sp200;
    arg_sp188 = arg_sp78;
    arg_sp190 = (f64) arg_sp80;
    arg_sp270 = arg_sp78;
    arg_sp278 = (f64) arg_sp80;
    arg_sp118 = (f64) arg_sp38;
    arg_sp120 = (f64) arg_sp40;
    arg_sp128.operator*(arg2);
    arg_sp28 = -(f32) arg_sp208;
    arg_sp2C = -arg_sp20C;
    arg_sp30 = -(f32) arg_sp210;
    arg_sp138 = (f64) arg_sp28;
    arg_sp140 = (f64) arg_sp30;
    arg_sp148.operator*(arg2);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp158 = arg_sp68;
    arg_sp70 = arg_sp150 + arg_sp130;
    arg_sp280 = arg_sp68;
    arg_sp160 = (f64) arg_sp70;
    arg_sp288 = (f64) arg_sp70;
    arg_spD8.operator*(arg2);
    arg_sp18 = -(f32) arg_sp208;
    arg_sp1C = -arg_sp20C;
    arg_sp20 = -(f32) arg_sp210;
    arg_spE8 = (f64) arg_sp18;
    arg_spF0 = (f64) arg_sp20;
    arg_spF8.operator*(arg2);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp108 = arg_sp58;
    arg_sp60 = arg_sp100 + arg_spE0;
    arg_sp290 = arg_sp58;
    arg_sp110 = (f64) arg_sp60;
    arg_sp298 = (f64) arg_sp60;
    M2C_STRUCT_COPY((s32) &arg_sp2DC + 4, (s32) (arg4 - 4) + 4, 0x40);
    arg_sp310 = this->unk50;
    arg_sp314 = this->unk54;
    arg_sp318 = this->unk58;
    arg_sp31C = 1.0f;
    if ((arg5 != 0) && ((MKModel *) this->unk4 != NULL)) {
        M2C_STRUCT_COPY((s32) &arg_sp21C + 4, (s32) &arg_sp2DC + 4, 0x40);
        arg_sp250 = this->unk50;
        arg_sp254 = this->unk54;
        arg_sp258 = this->unk58;
        arg_sp25C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp220));
        MKModel_Draw(this->unk4, NULL);
    }
    MKMaterial_SetMaterial(arg0);
    MKPrimitive(0xC, 0);
    MKSetMatrix(*((Matrix *) &arg_sp2E0));
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) arg3));
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp260));
    MKSetColorV(*((MKVector4 *) arg3));
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp270));
    MKSetColorV(*((MKVector4 *) arg3));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp280));
    MKSetColorV(*((MKVector4 *) arg3));
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp290));
    MKEnd();
    MKEndPrimitive();
}
#endif

void SparxFX::SetSparxPos(const MKVector3 &arg0) {
    this->unkB8 = M2C_FIELD(this, f64 *, 0x50);
    this->unkC0 = M2C_FIELD(this, f64 *, 0x58);
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x58) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk50 += 20.0f * _table_sinf(this->unk98);
    this->unk54 += 10.0f * _table_sinf(1.5707964f + this->unk9C);
    this->unk58 += 10.0f * _table_sinf(this->unkA0);
}

#if 0 // DRAFT: pointer/array required
void SparxFX::Deinit() {
    MKAnimScript *temp_r31_662;
    MKHeap *temp_r3_663;

    MKMaterial_Destroy(this->unk90);
    MKMaterial_Destroy(this->unk94);
    gb.unk80->FreeManagedLight(this->unkD0);
    this->unkE8->Deinit();
    temp_r31_662 = this->unkE8;
    temp_r3_663 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_663 != NULL) {
        ((MKHeap *) (temp_r3_663->Current()))->Free(temp_r31_662, NULL, 0);
    } else {
        free(temp_r31_662);
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: pointer/array required
void SparxFX::Disable() {
    ManagedLight *temp_r4_698;

    this->unk18 |= 0x80000000;
    this->unk8C &= ~0x80;
    temp_r4_698 = this->unkD0;
    if (temp_r4_698 != NULL) {
        gb.unk80->EnableLight(temp_r4_698, 0U);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void SparxFX::Enable() {
    ManagedLight *temp_r4_726;

    this->unk18 &= 0x7FFFFFFF;
    this->unk8C |= 0x80;
    temp_r4_726 = this->unkD0;
    if (temp_r4_726 != NULL) {
        gb.unk80->EnableLight(temp_r4_726, 1U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void SparxFX::GetGlowDrawParams(float &arg0, float &arg1) {
    f32 temp_f31_755;

    temp_f31_755 = _table_sinf(this->unkB0);
    &arg0 = 0.25f * ((8.0f * (_table_sinf(this->unkAC) * this->unkCC)) + 100.0f);
    &arg1 = (8.0f * temp_f31_755) + 75.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp18'
void SparxFX::Draw() {
    f32 temp_f2_802;
    if ((u8) gb.unk35E != 0) {
        MKView_Push();
        MKView_GetProjection(NULL, &arg_sp18, NULL);
        temp_f2_802 = arg_sp18 + 3.0f;
        arg_sp18 = temp_f2_802;
        MKView_SetProjection(0.0f, temp_f2_802, 0.0f);
        M2C_STRUCT_COPY((s32) &arg_sp6C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
        GetGlowDrawParams(arg_sp14, arg_sp10);
        arg_sp2C = 1.0f;
        arg_sp20 = 0.75f * this->unk68;
        arg_sp24 = 0.75f * this->unk6C;
        arg_sp28 = 0.75f * this->unk70;
        arg_sp60 = (f64) arg_sp20;
        arg_sp68 = (f64) arg_sp28;
        arg_sp30 = 1.0f;
        arg_sp34 = 1.0f;
        arg_sp38 = 1.0f;
        arg_sp3C = 1.0f;
        DrawGlow(this->unk94, this->unkA8, arg_sp10 * this->unkC8, (MKVector4) &arg_sp60, (Matrix *) &arg_sp70, 0U);
        arg_sp50 = (f64) arg_sp20;
        arg_sp58 = (f64) arg_sp28;
        DrawGlow(this->unk94, -this->unkA8, arg_sp10 * this->unkC8, (MKVector4) &arg_sp50, (Matrix *) &arg_sp70, 0U);
        arg_sp40 = (f64) arg_sp30;
        arg_sp48 = (f64) arg_sp38;
        DrawGlow(this->unk90, 0.0f, arg_sp14 * this->unkC8, (MKVector4) &arg_sp40, (Matrix *) &arg_sp70, 1U);
        MKView_Pop();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'spA0'
void SparxFX::Update() {
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
    MKVector4 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKAnimScript *temp_r3_1354;
    ManagedLight *temp_r3_1267;
    ManagedLight *temp_r3_1293;
    ManagedLight *temp_r3_1312;
    f32 temp_f0_1313;
    f32 temp_f1_1238;
    f32 temp_f24_1094;
    f32 temp_f24_1126;
    f32 temp_f24_1143;
    f32 temp_f25_1089;
    f32 temp_f25_1121;
    f32 temp_f25_1148;
    f32 temp_f26_1009;
    f32 temp_f27_1081;
    f32 temp_f2_1020;
    f32 temp_f3_1018;
    f32 temp_f4_1017;
    f32 var_f0_1192;
    f32 var_f0_1214;
    f32 var_f4_944;
    f64 temp_f1_947;
    f64 temp_f1_953;
    f64 temp_f1_957;
    s32 temp_r3_976;
    s32 var_r0_986;
    s32 var_r29_1082;
    void *temp_r29_1036;
    void *temp_r3_1021;
    void *temp_r3_1033;
    void *temp_r3_1274;
    void *temp_r3_1300;
    void *temp_r3_1315;

    if ((u8) gb.unk35E != 0) {
        this->unk88 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp100 = spA0;
        spA8 = M2C_FIELD(this, f32 *, 0xC0) - this->unk58;
        sp108 = (f64) spA8;
        var_f4_944 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (unksp104 * unksp104));
        if (var_f4_944 > 0.0f) {
            temp_f1_947 = __frsqrte(var_f4_944);
            temp_f1_953 = 0.5 * temp_f1_947 * -(((f64) var_f4_944 * (temp_f1_947 * temp_f1_947)) - 3.0);
            temp_f1_957 = 0.5 * temp_f1_953 * -(((f64) var_f4_944 * (temp_f1_953 * temp_f1_953)) - 3.0);
            var_f4_944 = (f32) ((f64) var_f4_944 * (0.5 * temp_f1_957 * -(((f64) var_f4_944 * (temp_f1_957 * temp_f1_957)) - 3.0)));
        } else if (var_f4_944 < M2C_BITWISE(f32, 0.0)) {
            var_f4_944 = __float_nan;
        } else {
            sp8 = var_f4_944;
            temp_r3_976 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_976) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_986 = 1;
                } else {
                    var_r0_986 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_986 = 5;
                } else {
                    var_r0_986 = 3;
                }
                break;
            default:
                var_r0_986 = 4;
                break;
            }
            if (var_r0_986 == 1) {
                var_f4_944 = __float_nan;
            }
        }
        temp_f26_1009 = var_f4_944 / 100.0f;
        if (this->unk88 < 0.125f) {
            temp_f4_1017 = 0.5f * this->unk68;
            temp_f3_1018 = 0.5f * this->unk6C;
            temp_f2_1020 = 0.5f * this->unk70;
            temp_r3_1021 = this->unkD4;
            sp90 = temp_f4_1017;
            sp94 = temp_f3_1018;
            sp98 = temp_f2_1020;
            sp9C = 1.0f;
            sp150 = (f64) sp90;
            sp158 = (f64) sp98;
            temp_r3_1033 = M2C_FIELD(M2C_FIELD(temp_r3_1021, void **, 0x44), void *(**)(void *, f64, f32, f32, f32, f32), 0x3C)(temp_r3_1021, (f64) sp90, temp_f2_1020, temp_f3_1018, temp_f4_1017, 0.5f);
            if (temp_r3_1033 != NULL) {
                temp_r29_1036 = M2C_FIELD(temp_r3_1033, void **, 0x2C);
                M2C_FIELD(temp_r3_1033, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x50);
                M2C_FIELD(temp_r3_1033, f64 *, 8) = (f64) M2C_FIELD(this, f32 *, 0x58);
                M2C_FIELD(temp_r3_1033, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1033, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_1033, f64 *, 0x10) = sp150;
                M2C_FIELD(temp_r3_1033, f64 *, 0x18) = sp158;
                M2C_FIELD(temp_r3_1033, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                M2C_FIELD(temp_r29_1036, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
                M2C_FIELD(temp_r29_1036, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
                M2C_FIELD(temp_r29_1036, f32 *, 0x18) = (f32) (0.8f * this->unkC8);
                M2C_FIELD(temp_r29_1036, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r29_1036, f32 *, 0x14) = (f32) M2C_FIELD(this->unkD4, f32 *, 0xF4);
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk88 == 0.0f) {
                temp_f27_1081 = 5.0f * temp_f26_1009;
                var_r29_1082 = 0;
loop_24:
                var_f0_1192 = 10.0f;
                if (temp_f27_1081 < var_f0_1192) {
                    var_f0_1192 = temp_f27_1081;
                }
                if (var_f0_1192 > 0.0f) {

                } else {
                    var_f0_1192 = 0.0f;
                }
                if (var_r29_1082 < (s32) ((s32) var_f0_1192 + 1)) {
                    temp_f25_1089 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f24_1094 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    sp80 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    sp84 = temp_f24_1094;
                    sp88 = temp_f25_1089;
                    spF0 = (f64) sp80;
                    spF8 = (f64) sp88;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                    sp140 = sp70;
                    sp78 = (f32) spF8 * 40.0f;
                    sp148 = (f64) sp78;
                    temp_f25_1121 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                    temp_f24_1126 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                    sp60 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                    sp64 = temp_f24_1126;
                    sp68 = temp_f25_1121;
                    sp6C = 1.0f;
                    sp130 = (f64) sp60;
                    sp138 = (f64) sp68;
                    temp_f24_1143 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f25_1148 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    sp50 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    sp54 = temp_f25_1148;
                    sp58 = temp_f24_1143;
                    spD0 = (f64) sp50;
                    spD8 = (f64) sp58;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                    spE0 = sp40;
                    sp48 = (f32) spD8 * 12.5f;
                    spE8 = (f64) sp48;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    sp120 = sp30;
                    sp38 = this->unk58 + (f32) spE8;
                    sp128 = (f64) sp38;
                    gb.EmitFairyDandruf(*((MKVector3 *) &sp120), *((MKVector3 *) &sp140), 0.4f, *((MKVector4 *) &sp130));
                    var_r29_1082 += 1;
                    goto loop_24;
                }
                var_f0_1214 = -((2.0f * (0.25f * temp_f26_1009)) - 0.25f);
                if (var_f0_1214 < 1000.0f) {

                } else {
                    var_f0_1214 = 1000.0f;
                }
                if (var_f0_1214 > 0.0f) {

                } else {
                    var_f0_1214 = 0.0f;
                }
                this->unk88 = var_f0_1214;
            }
        }
        this->unkA8 += gUpdateTimeDelta * ((3.1415927f * temp_f26_1009) + 0.25f);
        temp_f1_1238 = this->unkA8;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_1238 == 6.2831855f) {
            this->unkA8 = temp_f1_1238 - 6.2831855f;
        }
        this->unkAC += 10.0f * gUpdateTimeDelta * this->unkCC;
        this->unkB0 += 2.0f * gUpdateTimeDelta;
        KDMath_Smooth<MKVector4>(spC0, *((MKVector4 *) &this->unk68), 0.5f, gUpdateTimeDelta);
        M2C_FIELD(this, f32 *, 0x68) = M2C_BITWISE(f64, spC0);
        M2C_FIELD(this, f32 *, 0x70) = (f64) spC0.unk8;
        temp_r3_1267 = this->unkD0;
        if (temp_r3_1267 != NULL) {
            temp_r3_1267->unk10 = M2C_FIELD(this, f64 *, 0x50);
            temp_r3_1267->unk18 = (f64) M2C_FIELD(this, f32 *, 0x58);
            temp_r3_1274 = temp_r3_1267->unk3C;
            if (temp_r3_1274 != NULL) {
                M2C_FIELD(temp_r3_1274, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0x50);
                M2C_FIELD(temp_r3_1274, f64 *, 0x18) = (f64) M2C_FIELD(this, f32 *, 0x58);
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            temp_r3_1293 = this->unkD0;
            sp118 = sp28;
            unksp11C = 1.0f;
            temp_r3_1293->unk20 = sp20;
            sp110 = sp20;
            temp_r3_1293->unk28 = sp28;
            temp_r3_1300 = temp_r3_1293->unk3C;
            if (temp_r3_1300 != NULL) {
                M2C_FIELD(temp_r3_1300, f64 *, 0) = sp20;
                M2C_FIELD(temp_r3_1300, f64 *, 8) = sp28;
            }
            temp_r3_1312 = this->unkD0;
            temp_f0_1313 = this->unkC8 * ((50.0f * _table_sinf(this->unkAC)) + 800.0f);
            temp_r3_1312->unk38 = temp_f0_1313;
            temp_r3_1315 = temp_r3_1312->unk3C;
            if (temp_r3_1315 != NULL) {
                M2C_FIELD(temp_r3_1315, f32 *, 0x20) = temp_f0_1313;
                M2C_FIELD(temp_r3_1315, f32 *, 0x24) = (f32) (temp_f0_1313 * temp_f0_1313);
                M2C_FIELD(temp_r3_1315, f32 *, 0x28) = (f32) (1.0f / temp_f0_1313);
                M2C_FIELD(temp_r3_1315, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1315, f32 *, 0x24));
            }
        }
        sp10 = 1.5707964f * gUpdateTimeDelta;
        sp14 = 6.2831855f * gUpdateTimeDelta;
        sp18 = 3.1415927f * gUpdateTimeDelta;
        spB0 = (f64) sp10;
        spB8 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unkA0 += (f32) spB8;
        if ((MKModel *) this->unk4 != NULL) {
            temp_r3_1354 = this->unkE8;
            temp_r3_1354->Animate(temp_r3_1354->unkC, -1, NULL);
        }
    }
}
#endif

#if 0 // DRAFT: function call 'MKModel_Create(const char[21], MKHeap *, int, int)' does
void SparxFX::LoadDone() {
    MKAnimScript *var_r3_1491;
    MKHeap *temp_r3_1484;
    MKModel *temp_r3_1482;

    MKProp::LoadDone();
    temp_r3_1482 = MKModel_Create("A002_sparx_Billboard", ((Animation *) (M2C_FIELD(this->unk0, Animation **, 0x30)))->GetName(), 2, NULL);
    this->unk4 = temp_r3_1482;
    temp_r3_1484 = temp_r3_1482->Current();
    if (temp_r3_1484 != NULL) {
        var_r3_1491 = ((MKHeap *) (temp_r3_1484->Current()))->Alloc(0x58, NULL, 0);
    } else {
        var_r3_1491 = malloc(0x58);
    }
    this->unkE8 = var_r3_1491;
    this->unkE8->Init(M2C_FIELD(this->unk0, MKAnimScript **, 0x34), this->unk4);
    this->unkE8->SetAnimation(MKModel_GetAnimation(this->unk4));
    this->unkE8->SetAnim(this->unkE8->GetAnim(1), 1.0f, 0.0f, 0, -1);
}
#endif

#if 0 // DRAFT: pointer/array required
void SparxFX::Resolve() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_1560;

    MKProp::Resolve();
    sp10 = 0.0f;
    sp20 = 0.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unkD0 = gb.unk80->AllocManagedLight(*((MKVector3 *) &sp38), *((MKVector3 *) &sp28), *((MKVector4 *) &this->unk68), 700.0f, lit_537, lit_538);
    temp_r4_1560 = this->unkD0;
    if (temp_r4_1560 != NULL) {
        gb.unk80->EnableLight(temp_r4_1560, 1U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void SparxFX::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    MKProp::Init();
    this->unk50 = 0.0f;
    this->unk54 = 0.0f;
    this->unk58 = 0.0f;
    this->unk88 = 0.0f;
    this->unk8C |= 0x80;
    this->unk90 = MKMaterial_Create("fx_317");
    this->unk94 = MKMaterial_Create("fx_386");
    this->unkA8 = 0.0f;
    this->unkAC = 0.0f;
    this->unkB0 = 0.7853982f;
    M2C_FIELD(this, f32 *, 0xB8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xBC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xC0) = 0.0f;
    this->unk98 = 0.0f;
    this->unk9C = 3.1415927f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    this->unkA0 = 6.2831855f;
    sp20 = 0.4f;
    sp24 = 1.0f;
    this->unk78 = (f64) sp18;
    this->unk80 = (f64) sp20;
    sp8 = 1.0f;
    M2C_FIELD(this, f64 *, 0x68) = (f64) this->unk78;
    spC = 1.0f;
    M2C_FIELD(this, f64 *, 0x70) = (f64) this->unk80;
    sp10 = 0.4f;
    sp14 = 1.0f;
    this->unkD8 = (f64) sp8;
    this->unkE0 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unkD4 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("SparxTrailPS"));
    this->unkC8 = 1.0f;
    this->unkCC = 1.0f;
}
#endif
