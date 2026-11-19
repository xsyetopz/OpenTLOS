#include "spyro/source/WaterDripPS.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/PuddleSplash.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_WaterDrop;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: ')' expected
void WaterDripPS::Message(MKMessage *arg0) {
    void *temp_r3_58;
    void *temp_r4_60;

    if ((s32) arg0->unk0 != 0xA1) {

    } else {
        temp_r3_58 = ((u8 *) this->unk4C) + (M2C_FIELD(checked_cast<PathDestroyedMsg *, MKMessage>(arg0), s32 *, 8) * 0x58);
        M2C_FIELD(temp_r3_58, s8 *, 0x3C) = 0;
        temp_r4_60 = M2C_FIELD(temp_r3_58, void **, 0x38);
        if (temp_r4_60 != NULL) {
            M2C_FIELD(temp_r4_60, s32 *, 0x14) = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_58, void **, 0x38), s32 *, 0x14) = 0;
        }
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKProp' to
void WaterDripPS::Draw() {
    f64 sp288;                                      /* compiler-managed */
    f64 sp280;
    f64 sp278;                                      /* compiler-managed */
    f64 sp270;
    f64 sp268;                                      /* compiler-managed */
    f64 sp260;
    f64 sp258;                                      /* compiler-managed */
    f64 sp250;
    f64 sp248;
    f64 sp240;
    MKProp sp1F0;
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
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
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
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_282;
    f32 temp_f1_160;
    f32 temp_f1_303;
    f32 temp_f1_544;
    f32 temp_f29_385;
    f32 temp_f2_176;
    f32 temp_f2_285;
    f32 temp_f2_302;
    f32 temp_f30_152;
    f32 temp_f30_409;
    f32 temp_f31_155;
    f32 temp_f31_397;
    f32 temp_f3_140;
    f32 temp_f3_177;
    f32 temp_f3_284;
    f32 temp_f3_391;
    f32 temp_f4_390;
    f32 temp_f5_286;
    f32 temp_f5_307;
    f32 temp_f5_388;
    f32 temp_f7_289;
    f32 var_f2_379;
    f32 var_f4_251;
    f32 var_f4_312;
    f32 var_f5_184;
    f64 temp_f1_190;
    f64 temp_f1_196;
    f64 temp_f1_200;
    f64 temp_f1_318;
    f64 temp_f1_324;
    f64 temp_f1_328;
    f64 temp_f2_540;
    s32 temp_r3_219;
    s32 temp_r3_347;
    s32 var_r0_229;
    s32 var_r0_357;
    s32 var_r25_113;
    s32 var_r27_112;
    void *temp_r3_171;
    void *temp_r3_538;
    void *temp_r4_119;

    spC0 = 0.7f;
    spC4 = 0.7f;
    spC8 = 1.0f;
    spCC = 1.0f;
    sp240 = (f64) spC0;
    sp248 = (f64) spC8;
    MKMaterial_SetMaterial(M2C_FIELD(this->unk0, MKMaterial **, 0x38));
    MKPrimitive(0xC, 0);
    var_r27_112 = 0;
    var_r25_113 = 0;
    do {
        sp1F0.GetPos();
        temp_r4_119 = ((u8 *) this->unk4C) + var_r25_113;
        spB0 = M2C_FIELD(temp_r4_119, f64 *, 0) - M2C_BITWISE(f64, sp1F0);
        sp1F0.unk10 = spB0;
        spB8 = M2C_FIELD(temp_r4_119, f32 *, 8) - M2C_BITWISE(f32, sp1F0.unk8);
        sp1F0.unk20 = spB0;
        sp1F0.unk18 = (f64) spB8;
        sp1F0.unk28 = (f64) spB8;
        if ((u8) M2C_FIELD(temp_r4_119, u8 *, 0x3C) != 0) {
            temp_f3_140 = M2C_BITWISE(f32, sp1F0.unk28);
            if (((temp_f3_140 * temp_f3_140) + ((sp1F0.unk20 * sp1F0.unk20) + (sp1F0.unk24 * sp1F0.unk24))) > 90000.0f) {
                temp_f30_152 = 3.0f * M2C_FIELD(temp_r4_119, f32 *, 0x30);
                temp_f31_155 = temp_f30_152 / 1.5f;
                temp_f1_160 = 1.0f - MKRand_Float((int *) &gViewSeed, 0.0f, 0.5f);
                spA8 = 1.0f;
                spAC = 1.0f;
                spA0 = temp_f1_160;
                spA4 = temp_f1_160;
                sp248 = (f64) spA8;
                sp240 = (f64) spA0;
                sp1E0 = (f64) spA0;
                temp_r3_171 = ((u8 *) this->unk4C) + (var_r25_113 + 0x20);
                sp1E8 = (f64) spA8;
                sp1F0.unk40 = M2C_FIELD(temp_r3_171, f64 *, 0);
                temp_f2_176 = M2C_BITWISE(f32, sp1F0.unk40);
                temp_f3_177 = M2C_BITWISE(f32, sp1F0.__vptr);
                sp1F0.unk48 = M2C_FIELD(temp_r3_171, f64 *, 8);
                var_f5_184 = (sp1F0.unk48 * sp1F0.unk48) + ((temp_f2_176 * temp_f2_176) + (temp_f3_177 * temp_f3_177));
                if (var_f5_184 > 0.000001f) {
                    if (var_f5_184 > 0.0f) {
                        temp_f1_190 = __frsqrte(var_f5_184);
                        temp_f1_196 = 0.5 * temp_f1_190 * -(((f64) var_f5_184 * (temp_f1_190 * temp_f1_190)) - 3.0);
                        temp_f1_200 = 0.5 * temp_f1_196 * -(((f64) var_f5_184 * (temp_f1_196 * temp_f1_196)) - 3.0);
                        var_f5_184 = (f32) ((f64) var_f5_184 * (0.5 * temp_f1_200 * -(((f64) var_f5_184 * (temp_f1_200 * temp_f1_200)) - 3.0)));
                    } else if (var_f5_184 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_184 = __float_nan;
                    } else {
                        spC = var_f5_184;
                        temp_r3_219 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_219) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_229 = 1;
                            } else {
                                var_r0_229 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_229 = 5;
                            } else {
                                var_r0_229 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_229 = 4;
                            break;
                        }
                        if (var_r0_229 == 1) {
                            var_f5_184 = __float_nan;
                        }
                    }
                    var_f4_251 = 1.0f / var_f5_184;
                } else {
                    var_f4_251 = 0.0f;
                    var_f5_184 = 0.0f;
                }
                sp1F0.unk40 = M2C_BITWISE(f32, sp1F0.unk40) * var_f4_251;
                sp1F0.__vptr = M2C_BITWISE(f32, sp1F0.__vptr) * var_f4_251;
                sp1F0.unk48 *= var_f4_251;
                if (var_f5_184 < 300.0f) {

                } else {
                    var_f5_184 = 300.0f;
                }
                if (var_f5_184 > 0.0f) {

                } else {
                    var_f5_184 = 0.0f;
                }
                temp_r3_282 = MKView_GetCameraMatrix();
                temp_f3_284 = temp_r3_282->unk20;
                temp_f2_285 = temp_r3_282->unk28;
                temp_f5_286 = M2C_BITWISE(f32, sp1F0.__vptr);
                temp_f7_289 = temp_r3_282->unk24;
                sp94 = (temp_f2_285 * sp1F0.unk40) - (temp_f3_284 * sp1F0.unk48);
                sp90 = (temp_f7_289 * sp1F0.unk48) - (temp_f2_285 * temp_f5_286);
                sp98 = (temp_f3_284 * temp_f5_286) - (temp_f7_289 * sp1F0.unk40);
                sp1F0.unk30 = (f64) sp90;
                temp_f2_302 = M2C_BITWISE(f32, sp1F0.unk30);
                temp_f1_303 = M2C_BITWISE(f32, sp1F0.unk34);
                sp1F0.unk38 = (f64) sp98;
                temp_f5_307 = M2C_BITWISE(f32, sp1F0.unk38);
                sp1D0 = (f64) sp90;
                sp1D8 = (f64) sp98;
                var_f4_312 = (temp_f5_307 * temp_f5_307) + ((temp_f2_302 * temp_f2_302) + (temp_f1_303 * temp_f1_303));
                if (var_f4_312 > 0.000001f) {
                    if (var_f4_312 > 0.0f) {
                        temp_f1_318 = __frsqrte(var_f4_312);
                        temp_f1_324 = 0.5 * temp_f1_318 * -(((f64) var_f4_312 * (temp_f1_318 * temp_f1_318)) - 3.0);
                        temp_f1_328 = 0.5 * temp_f1_324 * -(((f64) var_f4_312 * (temp_f1_324 * temp_f1_324)) - 3.0);
                        var_f4_312 = (f32) ((f64) var_f4_312 * (0.5 * temp_f1_328 * -(((f64) var_f4_312 * (temp_f1_328 * temp_f1_328)) - 3.0)));
                    } else if (var_f4_312 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_312 = __float_nan;
                    } else {
                        sp8 = var_f4_312;
                        temp_r3_347 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_347) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_357 = 1;
                            } else {
                                var_r0_357 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_357 = 5;
                            } else {
                                var_r0_357 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_357 = 4;
                            break;
                        }
                        if (var_r0_357 == 1) {
                            var_f4_312 = __float_nan;
                        }
                    }
                    var_f2_379 = 1.0f / var_f4_312;
                } else {
                    var_f2_379 = 0.0f;
                }
                temp_f29_385 = temp_f31_155 * (var_f5_184 / 300.0f);
                temp_f5_388 = M2C_BITWISE(f32, sp1F0.unk30) * var_f2_379;
                temp_f4_390 = M2C_BITWISE(f32, sp1F0.unk34) * var_f2_379;
                temp_f3_391 = M2C_BITWISE(f32, sp1F0.unk38) * var_f2_379;
                sp1F0.unk30 = temp_f5_388;
                temp_f31_397 = temp_f30_152 - temp_f29_385;
                sp40 = -temp_f5_388;
                sp44 = -temp_f4_390;
                sp48 = -temp_f3_391;
                sp1F0.unk34 = temp_f4_390;
                sp1F0.unk38 = temp_f3_391;
                sp190 = (f64) sp40;
                sp198 = (f64) sp48;
                sp1A0.operator*(temp_f31_397);
                temp_f30_409 = temp_f30_152 + temp_f29_385;
                sp1B0.operator*(temp_f30_409);
                sp80 = sp1B0 + M2C_BITWISE(f64, sp1A0);
                sp1C0 = sp80;
                sp88 = sp1B0.unk8 + sp1A0.unk8;
                sp250 = sp80;
                sp1C8 = (f64) sp88;
                sp258 = (f64) sp88;
                sp160.operator*(temp_f31_397);
                sp170.operator*(temp_f30_409);
                sp70 = sp170 + M2C_BITWISE(f64, sp160);
                sp30 = -sp1F0.unk30;
                sp34 = -M2C_BITWISE(f32, sp1F0.unk34);
                sp78 = sp170.unk8 + sp160.unk8;
                sp38 = -sp1F0.unk38;
                sp180 = sp70;
                sp188 = (f64) sp78;
                sp260 = sp70;
                sp268 = (f64) sp78;
                sp110 = (f64) sp30;
                sp118 = (f64) sp38;
                sp120.operator*(temp_f31_397);
                sp20 = -sp1F0.unk40;
                sp24 = -M2C_BITWISE(f32, sp1F0.__vptr);
                sp28 = -sp1F0.unk48;
                sp130 = (f64) sp20;
                sp138 = (f64) sp28;
                sp140.operator*(temp_f30_409);
                sp60 = sp140 + M2C_BITWISE(f64, sp120);
                sp150 = sp60;
                sp68 = sp140.unk8 + sp120.unk8;
                sp270 = sp60;
                sp158 = (f64) sp68;
                sp278 = (f64) sp68;
                spD0.operator*(temp_f31_397);
                sp10 = -sp1F0.unk40;
                sp14 = -M2C_BITWISE(f32, sp1F0.__vptr);
                sp18 = -sp1F0.unk48;
                spE0 = (f64) sp10;
                spE8 = (f64) sp18;
                spF0.operator*(temp_f30_409);
                sp50 = spF0 + M2C_BITWISE(f64, spD0);
                sp280 = sp50;
                sp58 = spF0.unk8 + spD0.unk8;
                sp100 = sp50;
                sp288 = (f64) sp58;
                sp108 = (f64) sp58;
                temp_r3_538 = ((u8 *) this->unk4C) + var_r25_113;
                temp_f2_540 = M2C_FIELD(temp_r3_538, f64 *, 0);
                sp250 += temp_f2_540;
                temp_f1_544 = M2C_FIELD(temp_r3_538, f32 *, 8);
                sp258 = (f32) sp258 + temp_f1_544;
                sp260 += temp_f2_540;
                sp268 = (f32) sp268 + temp_f1_544;
                sp270 += temp_f2_540;
                sp278 = (f32) sp278 + temp_f1_544;
                sp280 += temp_f2_540;
                sp288 = (f32) sp288 + temp_f1_544;
                MKSetMatrix(Matrix::identity);
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &sp240));
                MKSetTexCoord1F(0.0f, 0.0f);
                MKSetPositionV(*((MKVector3 *) &sp250));
                MKSetColorV(*((MKVector4 *) &sp240));
                MKSetTexCoord1F(1.0f, 0.0f);
                MKSetPositionV(*((MKVector3 *) &sp260));
                MKSetColorV(*((MKVector4 *) &sp240));
                MKSetTexCoord1F(0.0f, 1.0f);
                MKSetPositionV(*((MKVector3 *) &sp270));
                MKSetColorV(*((MKVector4 *) &sp240));
                MKSetTexCoord1F(1.0f, 1.0f);
                MKSetPositionV(*((MKVector3 *) &sp280));
                MKEnd();
            }
        }
        var_r27_112 += 1;
        var_r25_113 += 0x58;
    } while (var_r27_112 < 0x14);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void WaterDripPS::Update() {
    MKVector3 spB0;
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
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
    f64 sp10;
    s32 spC;
    f32 sp8;
    MKVector3 *temp_r4_755;
    f32 temp_f1_756;
    f32 temp_f30_669;
    f32 temp_f3_844;
    f32 var_f0_736;
    f32 var_f0_977;
    f32 var_f1_951;
    f32 var_f4_871;
    f64 temp_f0_675;
    f64 temp_f0_705;
    f64 temp_f0_854;
    f64 temp_f1_874;
    f64 temp_f1_880;
    f64 temp_f1_884;
    s32 temp_r0_949;
    s32 temp_r0_973;
    s32 temp_r3_699;
    s32 temp_r3_797;
    s32 temp_r3_903;
    s32 var_r0_913;
    void *temp_r0_700;
    void *temp_r3_642;
    void *temp_r3_653;
    void *temp_r3_686;
    void *temp_r3_771;
    void *temp_r3_829;
    void *temp_r3_941;
    void *temp_r3_995;
    void *temp_r4_638;
    void *temp_r4_660;
    void *temp_r4_703;
    void *temp_r4_796;
    void *temp_r4_835;
    void *temp_r4_945;
    void *temp_r4_970;
    void *temp_r5_707;
    void *temp_r5_798;
    void *temp_r5_806;
    void *temp_r6_799;

    spC = 0;
loop_48:
    if (spC < 0x14) {
        temp_r4_638 = ((u8 *) this->unk4C) + (spC * 0x58);
        if ((u8) M2C_FIELD(temp_r4_638, u8 *, 0x3C) != 0) {
            temp_r3_642 = M2C_FIELD(temp_r4_638, void **, 0x38);
            if (temp_r3_642 == NULL) {
                M2C_FIELD(temp_r4_638, f32 *, 0x40) = (f32) (M2C_FIELD(temp_r4_638, f32 *, 0x40) + gUpdateTimeDelta);
                temp_r3_653 = ((u8 *) this->unk4C) + (spC * 0x58);
                if (M2C_FIELD(temp_r3_653, f32 *, 0x40) >= 3.0f) {
                    M2C_FIELD(temp_r3_653, s8 *, 0x3C) = 0;
                    temp_r4_660 = M2C_FIELD(temp_r3_653, void **, 0x38);
                    if (temp_r4_660 != NULL) {
                        M2C_FIELD(temp_r4_660, s32 *, 0x14) = 0;
                        M2C_FIELD(M2C_FIELD(temp_r3_653, void **, 0x38), s32 *, 0x14) = 0;
                    }
                }
                temp_f30_669 = gUpdateTimeDelta;
                MKVector(0.0f, -2000.0f, 0.0f);
                temp_f0_675 = sp70 * (f64) temp_f30_669;
                sp30 = temp_f0_675;
                sp80 = temp_f0_675;
                sp38 = sp78 * temp_f30_669;
                temp_r3_686 = ((u8 *) this->unk4C) + ((spC * 0x58) + 0x20);
                sp88 = (f64) sp38;
                M2C_FIELD(temp_r3_686, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_686, f64 *, 0) + temp_f0_675);
                M2C_FIELD(temp_r3_686, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_686, f32 *, 8) + (f32) sp88);
                temp_r3_699 = spC * 0x58;
                temp_r0_700 = this->unk4C;
                temp_r4_703 = ((u8 *) temp_r0_700) + (temp_r3_699 + 0x20);
                temp_f0_705 = M2C_FIELD(temp_r4_703, f64 *, 0) * (f64) gUpdateTimeDelta;
                sp20 = temp_f0_705;
                temp_r5_707 = ((u8 *) temp_r0_700) + temp_r3_699;
                sp60 = temp_f0_705;
                sp28 = M2C_FIELD(temp_r4_703, f32 *, 8) * gUpdateTimeDelta;
                sp68 = (f64) sp28;
                M2C_FIELD(temp_r5_707, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_707, f64 *, 0) + temp_f0_705);
                M2C_FIELD(temp_r5_707, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_707, f32 *, 8) + (f32) sp68);
                UpdateCollision(spC);
            } else {
                var_f0_736 = (gUpdateTimeDelta * (M2C_FIELD(temp_r4_638, f32 *, 0x44) / M2C_FIELD(M2C_FIELD(temp_r3_642, void **, 0x24), f32 *, 0xC))) + M2C_FIELD(temp_r4_638, f32 *, 0x40);
                if (var_f0_736 < 1.0f) {

                } else {
                    var_f0_736 = 1.0f;
                }
                if (var_f0_736 > 0.0f) {

                } else {
                    var_f0_736 = 0.0f;
                }
                M2C_FIELD(temp_r4_638, f32 *, 0x40) = var_f0_736;
                temp_r4_755 = ((u8 *) this->unk4C) + (spC * 0x58);
                temp_f1_756 = M2C_FIELD(temp_r4_755, f32 *, 0x40);
                if (temp_f1_756 == 1.0f) {
                    ((KDPathSegment *) (M2C_FIELD(temp_r4_755, KDPathSegment **, 0x38)))->GetPositionAlongPath(temp_f1_756, *temp_r4_755);
                    *(this->unk4C + ((spC * 0x58) + 0x40)) = 0.0f;
                    temp_r3_771 = *(this->unk4C + ((spC * 0x58) + 0x38));
                    if (temp_r3_771 != NULL) {
                        M2C_FIELD(temp_r3_771, s32 *, 0x10) = 0;
                        M2C_FIELD(*(this->unk4C + ((spC * 0x58) + 0x38)), s32 *, 0x14) = 0;
                    }
                    *(this->unk4C + ((spC * 0x58) + 0x38)) = 0;
                    *(this->unk4C + ((spC * 0x58) + 0x34)) = 1;
                    temp_r4_796 = this->unk4C;
                    temp_r3_797 = spC * 0x58;
                    temp_r5_798 = ((u8 *) temp_r4_796) + temp_r3_797;
                    temp_r6_799 = ((u8 *) temp_r5_798) + 0x20;
                    sp10 = M2C_FIELD(temp_r5_798, f64 *, 0) - M2C_FIELD(temp_r6_799, f64 *, 0);
                    temp_r5_806 = ((u8 *) temp_r4_796) + (temp_r3_797 + 0x10);
                    M2C_FIELD(temp_r5_806, f64 *, 0) = sp10;
                    sp18 = M2C_FIELD(temp_r5_798, f32 *, 8) - M2C_FIELD(temp_r6_799, f32 *, 8);
                    sp50 = sp10;
                    sp58 = (f64) sp18;
                    M2C_FIELD(temp_r5_806, f64 *, 8) = (f64) sp18;
                    UpdateCollision(spC);
                } else {
                    ((KDPathSegment *) (M2C_FIELD(temp_r4_755, KDPathSegment **, 0x38)))->GetPositionAlongPath(temp_f1_756, spB0);
                    temp_r3_829 = ((u8 *) this->unk4C) + (spC * 0x58);
                    M2C_FIELD(temp_r3_829, f64 *, 0) = M2C_BITWISE(f64, spB0);
                    M2C_FIELD(temp_r3_829, f64 *, 8) = (f64) spB0.unk8;
                    temp_r4_835 = ((u8 *) this->unk4C) + (spC * 0x58);
                    sp40 = M2C_FIELD(temp_r4_835, f64 *, 0) - *(temp_r4_835 + 0x10);
                    temp_f3_844 = 1.0f / gUpdateTimeDelta;
                    spA0 = sp40;
                    sp48 = M2C_FIELD(temp_r4_835, f32 *, 8) - M2C_FIELD(temp_r4_835, f32 *, 0x18);
                    spA8 = (f64) sp48;
                    temp_f0_854 = spA0 * (f64) temp_f3_844;
                    spA0 = temp_f0_854;
                    sp90 = temp_f0_854;
                    spA8 = (f32) spA8 * temp_f3_844;
                    (*(f32 *) ((u8 *) &sp90 + 0x4)) = 0.0f;
                    sp98 = (f64) spA8;
                    var_f4_871 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + (0.0f * 0.0f));
                    if (var_f4_871 > 0.0f) {
                        temp_f1_874 = __frsqrte(var_f4_871);
                        temp_f1_880 = 0.5 * temp_f1_874 * -(((f64) var_f4_871 * (temp_f1_874 * temp_f1_874)) - 3.0);
                        temp_f1_884 = 0.5 * temp_f1_880 * -(((f64) var_f4_871 * (temp_f1_880 * temp_f1_880)) - 3.0);
                        var_f4_871 = (f32) ((f64) var_f4_871 * (0.5 * temp_f1_884 * -(((f64) var_f4_871 * (temp_f1_884 * temp_f1_884)) - 3.0)));
                    } else if (var_f4_871 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_871 = __float_nan;
                    } else {
                        sp8 = var_f4_871;
                        temp_r3_903 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_903) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_913 = 1;
                            } else {
                                var_r0_913 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_913 = 5;
                            } else {
                                var_r0_913 = 3;
                            }
                            break;
                        default:
                            var_r0_913 = 4;
                            break;
                        }
                        if (var_r0_913 == 1) {
                            var_f4_871 = __float_nan;
                        }
                    }
                    temp_r3_941 = ((u8 *) this->unk4C) + ((spC * 0x58) + 0x20);
                    M2C_FIELD(temp_r3_941, f64 *, 0) = spA0;
                    M2C_FIELD(temp_r3_941, f64 *, 8) = (f64) spA8;
                    temp_r4_945 = this->unk4C;
                    temp_r0_949 = (spC * 0x58) + 0x44;
                    var_f1_951 = (2000.0f * gUpdateTimeDelta) + *(temp_r4_945 + temp_r0_949);
                    if (var_f1_951 < 3000.0f) {

                    } else {
                        var_f1_951 = 3000.0f;
                    }
                    if (var_f1_951 > 0.0f) {

                    } else {
                        var_f1_951 = 0.0f;
                    }
                    *(temp_r4_945 + temp_r0_949) = var_f1_951;
                    temp_r4_970 = this->unk4C;
                    temp_r0_973 = (spC * 0x58) + 0x44;
                    var_f0_977 = -((15000.0f * (var_f4_871 / 1000.0f) * gUpdateTimeDelta) - *(temp_r4_970 + temp_r0_973));
                    if (var_f0_977 < 30000.0f) {

                    } else {
                        var_f0_977 = 30000.0f;
                    }
                    if (var_f0_977 > 10.0f) {

                    } else {
                        var_f0_977 = 10.0f;
                    }
                    *(temp_r4_970 + temp_r0_973) = var_f0_977;
                    temp_r3_995 = ((u8 *) this->unk4C) + (spC * 0x58);
                    M2C_FIELD(temp_r3_995, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_995, f64 *, 0);
                    M2C_FIELD(temp_r3_995, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_995, f64 *, 8);
                }
            }
        }
        spC += 1;
        goto loop_48;
    }
}
#endif

#if 0 // DRAFT: illegal operand
f64 WaterDripPS::UpdateCollision(const int &arg0) {
    u8 sp278;
    s32 sp274;
    void *sp270;
    u32 sp26C;
    f32 sp268;
    s32 sp264;
    s8 sp263;
    s8 sp262;
    s16 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;                                      /* compiler-managed */
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
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
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r3_1540;
    f32 temp_f0_1058;
    f32 temp_f1_1178;
    f32 temp_f23_1252;
    f32 temp_f24_1257;
    f32 temp_f28_1073;
    f32 temp_f5_1114;
    f32 var_f29_1482;
    f32 var_f4_1344;
    f32 var_f5_1386;
    f64 temp_f0_1197;
    f64 temp_f0_1239;
    f64 temp_f0_1271;
    f64 temp_f0_1282;
    f64 temp_f0_1305;
    f64 temp_f0_1530;
    f64 temp_f0_1545;
    f64 temp_f0_1568;
    f64 temp_f1_1054;
    f64 temp_f1_1138;
    f64 temp_f1_1391;
    f64 temp_f1_1397;
    f64 temp_f1_1401;
    f64 temp_f1_1466;
    f64 temp_f1_1472;
    f64 temp_f1_1476;
    f64 temp_f3_1110;
    f64 temp_f3_1120;
    f64 temp_f3_1130;
    s32 temp_r3_1420;
    s32 temp_r3_1495;
    s32 temp_r4_1226;
    s32 temp_r4_1564;
    s32 temp_r6_1181;
    s32 var_r0_1430;
    s32 var_r0_1505;
    s32 var_r27_1234;
    u32 var_r0_1161;
    void *temp_r3_1374;
    void *temp_r3_1565;
    void *temp_r4_1051;
    void *temp_r4_1084;
    void *temp_r4_1333;
    void *var_r3_1052;

    temp_r4_1051 = ((u8 *) this->unk4C) + (&arg0 * 0x58);
    var_r3_1052 = ((u8 *) temp_r4_1051) + 0x10;
    temp_f1_1054 = M2C_FIELD(temp_r4_1051, f64 *, 0);
    sp108 = M2C_FIELD(var_r3_1052, f64 *, 0) - temp_f1_1054;
    temp_f0_1058 = M2C_FIELD(temp_r4_1051, f32 *, 8);
    sp1E8 = sp108;
    sp110 = M2C_FIELD(var_r3_1052, f32 *, 8) - temp_f0_1058;
    sp1F0 = (f64) sp110;
    temp_f28_1073 = ((f32) sp1F0 * (f32) sp1F0) + (((f32) sp1E8 * (f32) sp1E8) + ((*(f32 *) ((u8 *) &sp1E8 + 0x4)) * (*(f32 *) ((u8 *) &sp1E8 + 0x4))));
    if (((u8) M2C_FIELD(temp_r4_1051, u8 *, 0x48) != 0) && (temp_f28_1073 >= M2C_FIELD(temp_r4_1051, f32 *, 0x4C))) {
        temp_r4_1084 = ((u8 *) temp_r4_1051) + 0x20;
        sp228 = 0.0f;
        sp22C = 0.0f;
        sp230 = 0.0f;
        sp238 = 0.0f;
        sp23C = 0.0f;
        sp240 = 0.0f;
        sp248 = 0.0f;
        sp24C = 0.0f;
        sp250 = 0.0f;
        sp254 = 1.0f;
        sp258 = 0.0f;
        sp25C = 0.0f;
        sp260 = 0;
        sp262 = 0;
        sp263 = 0;
        sp264 = 0;
        sp268 = 3.4028235e38f;
        sp26C = 0;
        sp270 = NULL;
        sp274 = -1;
        sp278 = 0;
        temp_f3_1110 = M2C_FIELD(temp_r4_1084, f64 *, 0) * (f64) gUpdateTimeDelta;
        spF8 = temp_f3_1110;
        temp_f5_1114 = M2C_FIELD(temp_r4_1084, f32 *, 8) * gUpdateTimeDelta;
        sp1C8 = temp_f3_1110;
        sp100 = temp_f5_1114;
        sp1D0 = (f64) sp100;
        temp_f3_1120 = temp_f1_1054 - temp_f3_1110;
        spE8 = temp_f3_1120;
        sp1D8 = temp_f3_1120;
        spF0 = temp_f0_1058 - (f32) sp1D0;
        sp1E0 = (f64) spF0;
        temp_f3_1130 = M2C_FIELD(temp_r4_1084, f64 *, 0) * (f64) gUpdateTimeDelta;
        spD8 = temp_f3_1130;
        spE0 = temp_f5_1114;
        sp1A8 = temp_f3_1130;
        sp1B0 = (f64) spE0;
        temp_f1_1138 = temp_f1_1054 + sp1A8;
        spC8 = temp_f1_1138;
        spD0 = temp_f0_1058 + (f32) sp1B0;
        sp1B8 = temp_f1_1138;
        sp1C0 = (f64) spD0;
        var_r3_1052 = MKCollision_RayCollide(*((MKVector3 *) &sp1D8), *((MKVector3 *) &sp1B8), (MKCollisionResult *) &sp228, (MKCollisionMode) 7, 0);
        if ((u8) var_r3_1052 != 0) {
            if ((sp278 != 0) && (sp270 != NULL) && (var_r0_1161 = M2C_FIELD(sp270, u32 *, 8), ((var_r0_1161 == 0U) == 0))) {

            } else {
                var_r0_1161 = 0U;
            }
            if ((var_r0_1161 == 0U) && (sp23C >= 0.5f)) {
                temp_f1_1178 = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                temp_r6_1181 = &arg0 * 0x58;
                spC0 = 0.0f;
                spB8 = 0.0f;
                spBC = 0.05f;
                sp14 = M2C_FIELD((((u8 *) this->unk4C) + temp_r6_1181), f32 *, 0x30) * temp_f1_1178;
                sp188 = (f64) spB8;
                sp190 = (f64) spC0;
                temp_f0_1197 = (f64) sp228 + sp188;
                spA8 = temp_f0_1197;
                sp198 = temp_f0_1197;
                spB0 = sp230 + (f32) sp190;
                sp1A0 = (f64) spB0;
                ((PuddleSplash *) (M2C_FIELD(&gb, PuddleSplash **, 0x70)))->Emit(*((MKVector3 *) &sp198), sp14, M2C_FIELD((((u8 *) this->unk4C) + temp_r6_1181), u8 *, 0x50));
                KDSound_Play3d(GS_WaterDrop, (MKVector3 *) &sp228, sp26C, -1, 0.0f, 0U);
            }
            temp_r4_1226 = &arg0 * 0x58;
            if ((u8) M2C_FIELD((((u8 *) this->unk4C) + temp_r4_1226), u8 *, 0x34) != 0) {
                var_r27_1234 = 0;
                do {
                    temp_f0_1239 = sp238 * 5.5769738e-315;
                    sp78 = temp_f0_1239;
                    sp158 = temp_f0_1239;
                    sp80 = sp240 * 200.0f;
                    sp160 = (f64) sp80;
                    temp_f23_1252 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    temp_f24_1257 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    sp98 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    sp9C = temp_f24_1257;
                    spA0 = temp_f23_1252;
                    sp168 = (f64) sp98;
                    sp170 = (f64) spA0;
                    temp_f0_1271 = sp168 * 5.53552857e-315;
                    sp88 = temp_f0_1271;
                    sp178 = temp_f0_1271;
                    sp90 = (f32) sp170 * 100.0f;
                    sp180 = (f64) sp90;
                    temp_f0_1282 = sp178 + temp_f0_1239;
                    sp68 = temp_f0_1282;
                    sp60 = 0.0f;
                    sp218 = temp_f0_1282;
                    sp70 = (f32) sp180 + (f32) sp160;
                    sp58 = 0.0f;
                    sp220 = (f64) sp70;
                    sp5C = 2.0f;
                    sp140 = (f64) sp60;
                    sp138 = (f64) sp58;
                    sp10 = *(this->unk4C + (temp_r4_1226 + 0x30)) / 3.0f;
                    temp_f0_1305 = (f64) sp228 + sp138;
                    sp48 = temp_f0_1305;
                    sp148 = temp_f0_1305;
                    sp50 = sp230 + (f32) sp140;
                    sp150 = (f64) sp50;
                    Emit(*((MKVector3 *) &sp148), *((MKVector3 *) &sp218), sp10, 0U, 0U, NULL);
                    var_r27_1234 += 1;
                } while (var_r27_1234 < 3);
            }
            var_r3_1052 = ((u8 *) this->unk4C) + (&arg0 * 0x58);
            M2C_FIELD(var_r3_1052, s8 *, 0x3C) = 0;
            temp_r4_1333 = M2C_FIELD(var_r3_1052, void **, 0x38);
            if (temp_r4_1333 != NULL) {
                M2C_FIELD(temp_r4_1333, s32 *, 0x14) = 0;
                var_r3_1052 = M2C_FIELD(var_r3_1052, void **, 0x38);
                M2C_FIELD(var_r3_1052, s32 *, 0x14) = 0;
            }
        }
    }
    if (temp_f28_1073 >= 900.0001f) {
        var_f4_1344 = 0.0f;
        sp228 = 0.0f;
        sp22C = 0.0f;
        sp230 = 0.0f;
        sp238 = 0.0f;
        sp23C = 0.0f;
        sp240 = 0.0f;
        sp248 = 0.0f;
        sp24C = 0.0f;
        sp250 = 0.0f;
        sp254 = 1.0f;
        sp258 = 0.0f;
        sp25C = 0.0f;
        sp260 = 0;
        sp262 = 0;
        sp263 = 0;
        sp264 = 0;
        sp268 = 3.4028235e38f;
        sp26C = 0;
        sp270 = NULL;
        sp274 = -1;
        sp278 = 0;
        temp_r3_1374 = ((u8 *) this->unk4C) + (&arg0 * 0x58);
        sp208 = M2C_FIELD(temp_r3_1374, f64 *, 0x20);
        sp210 = M2C_FIELD(temp_r3_1374, f64 *, 0x28);
        var_f5_1386 = ((f32) sp210 * (f32) sp210) + (((f32) sp208 * (f32) sp208) + ((*(f32 *) ((u8 *) &sp200 + 0xc)) * (*(f32 *) ((u8 *) &sp200 + 0xc))));
        if (var_f5_1386 > 0.000001f) {
            if (var_f5_1386 > 0.0f) {
                temp_f1_1391 = __frsqrte(var_f5_1386);
                temp_f1_1397 = 0.5 * temp_f1_1391 * -(((f64) var_f5_1386 * (temp_f1_1391 * temp_f1_1391)) - 3.0);
                temp_f1_1401 = 0.5 * temp_f1_1397 * -(((f64) var_f5_1386 * (temp_f1_1397 * temp_f1_1397)) - 3.0);
                var_f5_1386 = (f32) ((f64) var_f5_1386 * (0.5 * temp_f1_1401 * -(((f64) var_f5_1386 * (temp_f1_1401 * temp_f1_1401)) - 3.0)));
            } else if (var_f5_1386 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1386 = __float_nan;
            } else {
                spC = var_f5_1386;
                temp_r3_1420 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_1420) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1430 = 1;
                    } else {
                        var_r0_1430 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1430 = 5;
                    } else {
                        var_r0_1430 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_1430 = 4;
                    break;
                }
                if (var_r0_1430 == 1) {
                    var_f5_1386 = __float_nan;
                }
            }
            var_f4_1344 = 1.0f / var_f5_1386;
        }
        sp208 = (f32) sp208 * var_f4_1344;
        (*(f32 *) ((u8 *) &sp200 + 0xc)) *= var_f4_1344;
        sp210 = (f32) sp210 * var_f4_1344;
        if (temp_f28_1073 > 0.0f) {
            temp_f1_1466 = __frsqrte(temp_f28_1073);
            temp_f1_1472 = 0.5 * temp_f1_1466 * -(((f64) temp_f28_1073 * (temp_f1_1466 * temp_f1_1466)) - 3.0);
            temp_f1_1476 = 0.5 * temp_f1_1472 * -(((f64) temp_f28_1073 * (temp_f1_1472 * temp_f1_1472)) - 3.0);
            var_f29_1482 = (f32) ((f64) temp_f28_1073 * (0.5 * temp_f1_1476 * -(((f64) temp_f28_1073 * (temp_f1_1476 * temp_f1_1476)) - 3.0)));
        } else if (temp_f28_1073 < M2C_BITWISE(f32, 0.0)) {
            var_f29_1482 = __float_nan;
        } else {
            sp8 = temp_f28_1073;
            temp_r3_1495 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1495) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1505 = 1;
                } else {
                    var_r0_1505 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1505 = 5;
                } else {
                    var_r0_1505 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1505 = 4;
                break;
            }
            if (var_r0_1505 == 1) {
                var_f29_1482 = __float_nan;
            } else {
                var_f29_1482 = temp_f28_1073;
            }
        }
        temp_f0_1530 = (f64) sp208 * (f64) var_f29_1482;
        sp38 = temp_f0_1530;
        sp118 = temp_f0_1530;
        sp40 = sp210 * var_f29_1482;
        temp_r3_1540 = ((u8 *) this->unk4C) + (&arg0 * 0x58);
        sp120 = (f64) sp40;
        temp_f0_1545 = M2C_FIELD(temp_r3_1540, f64 *, 0) + temp_f0_1530;
        sp28 = temp_f0_1545;
        sp128 = temp_f0_1545;
        sp30 = temp_r3_1540->unk8 + (f32) sp120;
        sp130 = (f64) sp30;
        if (MKCollision_RayCollide(*temp_r3_1540, *((MKVector3 *) &sp128), (MKCollisionResult *) &sp228, (MKCollisionMode) 7, 0) != 0) {
            temp_r4_1564 = &arg0 * 0x58;
            temp_r3_1565 = ((u8 *) this->unk4C) + temp_r4_1564;
            temp_f0_1568 = (f64) sp228 - M2C_FIELD(temp_r3_1565, f64 *, 0);
            sp18 = temp_f0_1568;
            M2C_FIELD(temp_r3_1565, s8 *, 0x48) = 1;
            sp1F8 = temp_f0_1568;
            sp20 = sp230 - M2C_FIELD(temp_r3_1565, f32 *, 8);
            sp200 = (f64) sp20;
            M2C_FIELD((((u8 *) this->unk4C) + temp_r4_1564), f32 *, 0x4C) = (f32) (((f32) sp200 * (f32) sp200) + (((f32) sp1F8 * (f32) sp1F8) + ((*(f32 *) ((u8 *) &sp1F8 + 0x4)) * (*(f32 *) ((u8 *) &sp1F8 + 0x4)))));
        } else {
            M2C_FIELD((((u8 *) this->unk4C) + (&arg0 * 0x58)), s8 *, 0x48) = 0;
        }
        var_r3_1052 = ((u8 *) this->unk4C) + (&arg0 * 0x58);
        M2C_FIELD(var_r3_1052, f64 *, 0x10) = (f64) M2C_FIELD(var_r3_1052, f64 *, 0);
        M2C_FIELD(var_r3_1052, f64 *, 0x18) = (f64) M2C_FIELD(var_r3_1052, f64 *, 8);
    }
    return M2C_BITWISE(f64, var_r3_1052);
}
#endif

#if 0 // DRAFT: illegal type
void WaterDripPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, bool arg3, bool arg4, KDPathSegment *arg5) {
    MKVector3 *temp_r4_1703;
    f64 temp_f2_1665;
    f64 temp_f3_1663;
    s32 var_ctr_1645;
    s32 var_r31_1643;
    s32 var_r3_1644;
    void *temp_r4_1678;
    void *temp_r4_1682;
    void *temp_r4_1686;
    void *temp_r9_1647;

    var_r31_1643 = 0;
    var_r3_1644 = 0;
    var_ctr_1645 = 0x14;
loop_1:
    temp_r9_1647 = this->unk4C;
    if ((u8) *(temp_r9_1647 + (var_r3_1644 + 0x3C)) == 0) {
        M2C_FIELD((((u8 *) temp_r9_1647) + var_r3_1644), s8 *, 0x3C) = 1;
        temp_f3_1663 = M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), u8 *, 0x34) = arg3;
        temp_f2_1665 = M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), f32 *, 0x40) = 0.0f;
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), f32 *, 0x30) = (f32) &arg2;
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), KDPathSegment **, 0x38) = arg5;
        temp_r4_1678 = ((u8 *) this->unk4C) + var_r3_1644;
        M2C_FIELD(temp_r4_1678, f64 *, 0) = temp_f3_1663;
        M2C_FIELD(temp_r4_1678, f64 *, 8) = temp_f2_1665;
        temp_r4_1682 = ((u8 *) this->unk4C) + (var_r3_1644 + 0x10);
        M2C_FIELD(temp_r4_1682, f64 *, 0) = temp_f3_1663;
        M2C_FIELD(temp_r4_1682, f64 *, 8) = temp_f2_1665;
        temp_r4_1686 = ((u8 *) this->unk4C) + (var_r3_1644 + 0x20);
        M2C_FIELD(temp_r4_1686, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_1686, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), f32 *, 0x44) = 0.0f;
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), s8 *, 0x48) = 0;
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), f32 *, 0x4C) = 0.0f;
        M2C_FIELD((((u8 *) this->unk4C) + var_r3_1644), u8 *, 0x50) = arg4;
        if (arg5 != NULL) {
            temp_r4_1703 = ((u8 *) this->unk4C) + var_r3_1644;
            ((KDPathSegment *) (M2C_FIELD(temp_r4_1703, KDPathSegment **, 0x38)))->GetPositionAlongPath(M2C_FIELD(temp_r4_1703, f32 *, 0x40), *temp_r4_1703);
            arg5->unk10 = (MKHeap *) this;
            arg5->unk14 = var_r31_1643;
        }
    } else {
        var_r31_1643 += 1;
        var_r3_1644 += 0x58;
        var_ctr_1645 -= 1;
        if (var_ctr_1645 == 0) {
            return;
        }
        goto loop_1;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void WaterDripPS::Deinit() {
    MKHeap *temp_r3_1733;
    void *temp_r31_1730;

    temp_r31_1730 = this->unk4C;
    if (temp_r31_1730 != NULL) {
        temp_r3_1733 = MKHeap::Current();
        if (temp_r3_1733 != NULL) {
            ((MKHeap *) (temp_r3_1733->Current()))->Free(temp_r31_1730, NULL, 0);
        } else {
            free(temp_r31_1730);
        }
        this->unk4C = NULL;
    }
    MKProp::Deinit();
}
#endif

void WaterDripPS::Init() {
    MKHeap *temp_r3_1767;
    void *var_r3_1774;

    MKProp::Init();
    temp_r3_1767 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1767 != NULL) {
        var_r3_1774 = ((MKHeap *) (temp_r3_1767->Current()))->Alloc(0x6E0, NULL, 0);
    } else {
        var_r3_1774 = malloc(0x6E0);
    }
    this->unk4C = var_r3_1774;
    memset(this->unk4C, 0, 0x6E0U);
}
