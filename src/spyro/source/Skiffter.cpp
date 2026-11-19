#include "spyro/source/Skiffter.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: undefined identifier 'unk170'
static s8 lit_stringBase0[0x36] = {
    0x57,
    0x61,
    0x79,
    0x70,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0x73,
    0,
    0x77,
    0x61,
    0x79,
    0x70,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0,
    0x43,
    0x6C,
    0x69,
    0x6D,
    0x62,
    0,
    0x43,
    0x6C,
    0x69,
    0x6D,
    0x62,
    0x5F,
    0x49,
    0x64,
    0x6C,
    0x65,
    0,
    0x54,
    0x61,
    0x6B,
    0x65,
    0x5F,
    0x4F,
    0x66,
    0x66,
    0,
    0x46,
    0x6C,
    0x79,
    0,
    0x4C,
    0x61,
    0x6E,
    0x64,
    0,
}; /* const */

void SkiffterCritter::Deinit() {
    MKHeap *temp_r3_57;
    MKHeap *temp_r3_76;
    void *temp_r31_54;
    void *temp_r31_73;

    temp_r31_54 = this->unk170;
    if (temp_r31_54 != NULL) {
        temp_r3_57 = MKHeap::Current();
        if (temp_r3_57 != NULL) {
            ((MKHeap *) (temp_r3_57->Current()))->Free(temp_r31_54, NULL, 0);
        } else {
            free(temp_r31_54);
        }
        this->unk170 = NULL;
    }
    temp_r31_73 = this->unk174;
    if (temp_r31_73 != NULL) {
        temp_r3_76 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_76 != NULL) {
            ((MKHeap *) (temp_r3_76->Current()))->Free(temp_r31_73, NULL, 0);
        } else {
            free(temp_r31_73);
        }
        this->unk174 = NULL;
    }
    Critters::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk170'
void SkiffterCritter::Draw() {
    s32 var_r30_112;
    s32 var_r31_113;
    void *temp_r29_117;
    var_r30_112 = 0;
    var_r31_113 = 0;
loop_4:
    if (var_r30_112 < (s32) this->unk90) {
        temp_r29_117 = this->unk170 + var_r31_113;
        if ((s32) M2C_FIELD(temp_r29_117, s32 *, 0x60) != 0) {
            this->unk80->SetAnim(M2C_FIELD(temp_r29_117, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
            this->unk80->JumpToPos(M2C_FIELD(temp_r29_117, f32 *, 0x54), -1);
            M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (temp_r29_117 - 4) + 4, 0x40);
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
            MKModel_Draw(this->unk4, NULL);
        }
        var_r30_112 += 1;
        var_r31_113 += 0x80;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: identifier 'SkiffterCritter::Update()' redeclared
SkiffterCritter *SkiffterCritter::Update() {
    s8 sp480;
    s32 sp47C;
    s32 sp478;
    s32 sp474;
    f32 sp470;
    s32 sp46C;
    s8 sp46B;
    s8 sp46A;
    s16 sp468;
    f32 sp464;
    f32 sp460;
    f32 sp45C;
    f32 sp458;
    f32 sp454;
    f32 sp450;
    f32 sp448;
    f32 sp444;
    f32 sp440;
    f32 sp438;
    f32 sp434;
    f32 sp430;
    s8 sp428;
    s32 sp424;
    s32 sp420;
    s32 sp41C;
    f32 sp418;
    s32 sp414;
    s8 sp413;
    s8 sp412;
    s16 sp410;
    f32 sp40C;
    f32 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    f32 sp3F0;
    f32 sp3EC;
    f32 sp3E8;
    f32 sp3E0;
    f32 sp3DC;
    f32 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;                                      /* compiler-managed */
    f64 sp3B8;                                      /* compiler-managed */
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;                                      /* compiler-managed */
    f64 sp378;                                      /* compiler-managed */
    f64 sp370;                                      /* compiler-managed */
    f64 sp368;                                      /* compiler-managed */
    f64 sp360;                                      /* compiler-managed */
    f64 sp358;                                      /* compiler-managed */
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;                                      /* compiler-managed */
    f64 sp328;                                      /* compiler-managed */
    f64 sp320;                                      /* compiler-managed */
    f64 sp318;                                      /* compiler-managed */
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;                                      /* compiler-managed */
    f64 sp2D8;                                      /* compiler-managed */
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp150;
    f32 sp140;
    f32 sp130;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
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
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r30_187;
    SkiffterCritter *temp_r29_180;
    SkiffterCritter *var_r3_0;
    f32 temp_f10_1234;
    f32 temp_f10_1704;
    f32 temp_f10_417;
    f32 temp_f10_648;
    f32 temp_f10_755;
    f32 temp_f11_1709;
    f32 temp_f11_422;
    f32 temp_f1_1409;
    f32 temp_f1_476;
    f32 temp_f1_927;
    f32 temp_f30_901;
    f32 temp_f3_1137;
    f32 temp_f3_1352;
    f32 temp_f4_1349;
    f32 temp_f5_1347;
    f32 temp_f6_1141;
    f32 temp_f6_871;
    f32 temp_f7_867;
    f32 temp_f8_1231;
    f32 temp_f8_649;
    f32 temp_f8_757;
    f32 temp_f8_864;
    f32 temp_f9_1229;
    f32 temp_f9_1706;
    f32 temp_f9_419;
    f32 temp_f9_653;
    f32 temp_f9_760;
    f32 temp_r3_1517;
    f32 var_f0_1053;
    f32 var_f0_560;
    f32 var_f2_1697;
    f32 var_f2_410;
    f32 var_f3_748;
    f32 var_f4_1630;
    f32 var_f4_343;
    f32 var_f4_855;
    f32 var_f5_1262;
    f32 var_f5_681;
    f32 var_f5_788;
    f32 var_f6_1151;
    f32 var_f6_1329;
    f32 var_f7_1140;
    f32 var_f8_1035;
    f32 var_f9_542;
    f64 temp_f1_1636;
    f64 temp_f1_1642;
    f64 temp_f1_1646;
    f64 temp_f1_349;
    f64 temp_f1_355;
    f64 temp_f1_359;
    f64 temp_f2_1069;
    f64 temp_f2_1075;
    f64 temp_f2_1079;
    f64 temp_f2_1164;
    f64 temp_f2_1170;
    f64 temp_f2_1174;
    f64 temp_f2_1268;
    f64 temp_f2_1274;
    f64 temp_f2_1278;
    f64 temp_f2_576;
    f64 temp_f2_582;
    f64 temp_f2_586;
    f64 temp_f2_687;
    f64 temp_f2_693;
    f64 temp_f2_697;
    f64 temp_f2_794;
    f64 temp_f2_800;
    f64 temp_f2_804;
    s32 temp_cr0_gt_477;
    s32 temp_r0_1372;
    s32 temp_r0_191;
    s32 temp_r27_1382;
    s32 temp_r27_1467;
    s32 temp_r27_1510;
    s32 temp_r27_214;
    s32 temp_r27_491;
    s32 temp_r27_984;
    s32 var_r0_1108;
    s32 var_r0_1203;
    s32 var_r0_1307;
    s32 var_r0_1675;
    s32 var_r0_388;
    s32 var_r0_615;
    s32 var_r0_726;
    s32 var_r0_833;
    s32 var_r28_182;
    s32 var_r31_181;
    void *temp_r9_1567;
    void *temp_r9_255;

    var_r3_0 = this;
    temp_r29_180 = var_r3_0;
    var_r31_181 = 0;
    var_r28_182 = 0;
loop_197:
    if (var_r31_181 < (s32) temp_r29_180->unk90) {
        temp_r30_187 = temp_r29_180->unk170 + var_r28_182;
        temp_r30_187->unk64 -= gUpdateTimeDelta;
        temp_r0_191 = temp_r30_187->unk60;
        switch (temp_r0_191) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            temp_r30_187->unk60 = 2;
            temp_r30_187->unk64 = 5.0f * MKRand_Float(&gViewSeed, 0.75f, 1.0f);
            temp_r27_214 = temp_r30_187->unk60;
            temp_r30_187->unk50 = *(checked_cast<SkiffterCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r29_180->unk0) + ((temp_r27_214 * 4) + 0x70));
            temp_r30_187->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_187->unk50, s16 *, 4) / 30.0f));
            temp_r30_187->unk54 = 0.0f;
            temp_r30_187->unk68 = M2C_BITWISE(f32, (MKRand_Int(&gViewSeed, 0, (s32) temp_r29_180->unk178 / 2) * 2));
            sp1C0 = 0.0f;
            temp_r9_255 = temp_r29_180->unk174 + (M2C_BITWISE(s32, temp_r30_187->unk68) * 0x10);
            sp1B0 = 1.0f;
            sp1A0 = 0.0f;
            sp1B8 = 1.0f;
            sp1BC = 0.0f;
            sp1A8 = 0.0f;
            sp1AC = 0.0f;
            sp198 = 0.0f;
            sp19C = 1.0f;
            sp3C8 = M2C_FIELD(temp_r9_255, f64 *, 0);
            sp3D0 = M2C_FIELD(temp_r9_255, f64 *, 8);
            sp3B8 = (f64) sp1B8;
            sp3C0 = (f64) sp1C0;
            sp3A8 = (f64) sp1A8;
            sp3B0 = (f64) sp1B0;
            sp398 = (f64) sp198;
            sp3A0 = (f64) sp1A0;
            sp430 = 0.0f;
            sp434 = 0.0f;
            sp438 = 0.0f;
            sp440 = 0.0f;
            sp444 = 0.0f;
            sp448 = 0.0f;
            sp450 = 0.0f;
            sp454 = 0.0f;
            sp458 = 0.0f;
            sp45C = 1.0f;
            sp460 = 0.0f;
            sp464 = 0.0f;
            sp468 = 0;
            sp46A = 0;
            sp46B = 0;
            sp46C = 0;
            sp470 = 3.4028235e38f;
            sp474 = 0;
            sp478 = 0;
            sp47C = -1;
            sp480 = 0;
            var_r3_0 = MKCollision_SphereCollide(*((MKVector3 *) &sp3C8), 50.0f, (MKCollisionResult *) &sp430, 1, (MKCollisionMode) 7, 0);
            if (var_r3_0 != NULL) {
                sp3A8 = (f64) sp440;
                sp3B0 = (f64) sp448;
            }
            sp9C = ((f32) sp3A0 * (f32) sp3A8) - ((f32) sp398 * (f32) sp3B0);
            sp98 = (unksp39C * (f32) sp3B0) - ((f32) sp3A0 * unksp3AC);
            spA0 = ((f32) sp398 * unksp3AC) - (unksp39C * (f32) sp3A8);
            sp3B8 = (f64) sp98;
            sp3C0 = (f64) spA0;
            sp2A8 = (f64) sp98;
            sp2B0 = (f64) spA0;
            var_f4_343 = ((f32) sp3C0 * (f32) sp3C0) + (((f32) sp3B8 * (f32) sp3B8) + (unksp3BC * unksp3BC));
            if (var_f4_343 > 0.000001f) {
                if (var_f4_343 > 0.0f) {
                    temp_f1_349 = __frsqrte(var_f4_343);
                    temp_f1_355 = 0.5 * temp_f1_349 * -(((f64) var_f4_343 * (temp_f1_349 * temp_f1_349)) - 3.0);
                    temp_f1_359 = 0.5 * temp_f1_355 * -(((f64) var_f4_343 * (temp_f1_355 * temp_f1_355)) - 3.0);
                    var_f4_343 = (f32) ((f64) var_f4_343 * (0.5 * temp_f1_359 * -(((f64) var_f4_343 * (temp_f1_359 * temp_f1_359)) - 3.0)));
                } else if (var_f4_343 < M2C_BITWISE(f32, 0.0)) {
                    var_r3_0 = &__float_nan;
                    var_f4_343 = M2C_BITWISE(f32, __float_nan.unk0);
                } else {
                    sp24 = var_f4_343;
                    var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, sp24) & 0x7F800000);
                    switch (var_r3_0) {             /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
                            var_r0_388 = 1;
                        } else {
                            var_r0_388 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
                            var_r0_388 = 5;
                        } else {
                            var_r0_388 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_388 = 4;
                        break;
                    }
                    if (var_r0_388 == 1) {
                        var_r3_0 = &__float_nan;
                        var_f4_343 = M2C_BITWISE(f32, __float_nan.unk0);
                    }
                }
                var_f2_410 = 1.0f / var_f4_343;
            } else {
                var_f2_410 = 0.0f;
            }
            temp_f10_417 = unksp3BC * var_f2_410;
            temp_f9_419 = (f32) sp3C0 * var_f2_410;
            temp_f11_422 = (f32) sp3B8 * var_f2_410;
            sp3B8 = temp_f11_422;
            unksp3BC = temp_f10_417;
            sp88 = (unksp3AC * temp_f9_419) - ((f32) sp3B0 * temp_f10_417);
            sp8C = ((f32) sp3B0 * temp_f11_422) - ((f32) sp3A8 * temp_f9_419);
            sp90 = ((f32) sp3A8 * temp_f10_417) - (unksp3AC * temp_f11_422);
            M2C_FIELD(temp_r30_187, f64 *, 0x40) = (f64) sp88;
            sp398 = (f64) sp88;
            M2C_FIELD(temp_r30_187, f32 *, 0x48) = (f64) sp90;
            temp_r30_187->unk20 = (f32) sp3A8;
            temp_r30_187->unk24 = unksp3AC;
            temp_r30_187->unk28 = (f32) sp3B0;
            temp_r30_187->unk2C = 0.0f;
            sp3A0 = (f64) sp90;
            temp_r30_187->unk10 = (f32) sp398;
            temp_r30_187->unk14 = unksp39C;
            temp_r30_187->unk18 = (f32) sp3A0;
            temp_r30_187->unk1C = 0.0f;
            temp_r30_187->unk0 = temp_f11_422;
            temp_r30_187->unk4 = temp_f10_417;
            temp_r30_187->unk8 = temp_f9_419;
            temp_r30_187->unkC = 0.0f;
            sp3C0 = temp_f9_419;
            temp_r30_187->unk30 = (f32) sp3C8;
            sp298 = (f64) sp88;
            temp_r30_187->unk34 = unksp3CC;
            sp2A0 = (f64) sp90;
            temp_r30_187->unk38 = (f32) sp3D0;
            temp_r30_187->unk3C = 1.0f;
            break;
        case 2:                                     /* switch 1 */
            temp_r30_187->unk54 += temp_r30_187->unk58 * gUpdateTimeDelta;
            temp_f1_476 = temp_r30_187->unk54;
            temp_cr0_gt_477 = temp_f1_476 > 1.0f;
            if (temp_cr0_gt_477 != 0) {
                if (temp_cr0_gt_477 != 0) {
                    temp_r30_187->unk54 = temp_f1_476 - 1.0f;
                }
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (temp_r30_187->unk64 == 0.0f) {
                    temp_r30_187->unk64 = 0.0f;
                    temp_r30_187->unk60 = 1;
                    temp_r27_491 = temp_r30_187->unk60;
                    temp_r30_187->unk50 = *(checked_cast<SkiffterCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r29_180->unk0) + ((temp_r27_491 * 4) + 0x70));
                    temp_r30_187->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_187->unk50, s16 *, 4) / 30.0f));
                    temp_r30_187->unk54 = 0.0f;
                    temp_r30_187->unk68 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r30_187->unk68) + 1));
                    if (M2C_BITWISE(s32, temp_r30_187->unk68) >= (s32) temp_r29_180->unk178) {
                        temp_r30_187->unk68 = 0.0f;
                    }
                    var_r3_0 = temp_r29_180->unk174 + (M2C_BITWISE(s32, temp_r30_187->unk68) * 0x10);
                    sp388 = M2C_FIELD(var_r3_0, f64 *, 0);
                    sp390 = M2C_FIELD(var_r3_0, f64 *, 8);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    sp358 = sp188;
                    var_f9_542 = 0.0f;
                    sp190 = (f32) sp390 - temp_r30_187->unk38;
                    sp180 = 0.0f;
                    sp360 = (f64) sp190;
                    sp170 = 1.0f;
                    sp178 = 1.0f;
                    var_f0_560 = ((f32) sp360 * (f32) sp360) + (((f32) sp358 * (f32) sp358) + (unksp35C * unksp35C));
                    sp17C = 0.0f;
                    sp168 = 0.0f;
                    sp16C = 0.0f;
                    sp288 = sp188;
                    sp290 = (f64) sp190;
                    sp378 = (f64) sp178;
                    sp380 = (f64) sp180;
                    sp368 = (f64) sp168;
                    sp370 = (f64) sp170;
                    if (var_f0_560 > 0.000001f) {
                        if (var_f0_560 > 0.0f) {
                            temp_f2_576 = __frsqrte(var_f0_560);
                            temp_f2_582 = 0.5 * temp_f2_576 * -(((f64) var_f0_560 * (temp_f2_576 * temp_f2_576)) - 3.0);
                            temp_f2_586 = 0.5 * temp_f2_582 * -(((f64) var_f0_560 * (temp_f2_582 * temp_f2_582)) - 3.0);
                            var_f0_560 = (f32) ((f64) var_f0_560 * (0.5 * temp_f2_586 * -(((f64) var_f0_560 * (temp_f2_586 * temp_f2_586)) - 3.0)));
                        } else if (var_f0_560 < M2C_BITWISE(f32, 0.0)) {
                            var_r3_0 = &__float_nan;
                            var_f0_560 = M2C_BITWISE(f32, __float_nan.unk0);
                        } else {
                            sp20 = var_f0_560;
                            var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, sp20) & 0x7F800000);
                            switch (var_r3_0) {     /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                                    var_r0_615 = 1;
                                } else {
                                    var_r0_615 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                                    var_r0_615 = 5;
                                } else {
                                    var_r0_615 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_615 = 4;
                                break;
                            }
                            if (var_r0_615 == 1) {
                                var_r3_0 = &__float_nan;
                                var_f0_560 = M2C_BITWISE(f32, __float_nan.unk0);
                            }
                        }
                        var_f9_542 = 1.0f / var_f0_560;
                    } else {
                        var_f0_560 = 0.0f;
                    }
                    sp368 = (f64) M2C_FIELD(temp_r30_187, f32 *, 0x20);
                    sp370 = (f64) M2C_FIELD(temp_r30_187, f32 *, 0x28);
                    temp_f10_648 = (f32) sp358 * var_f9_542;
                    temp_f8_649 = (f32) sp360 * var_f9_542;
                    temp_f9_653 = unksp35C * var_f9_542;
                    sp358 = temp_f10_648;
                    unksp35C = temp_f9_653;
                    sp78 = (temp_f9_653 * (f32) sp370) - (temp_f8_649 * unksp36C);
                    sp7C = (temp_f8_649 * (f32) sp368) - (temp_f10_648 * (f32) sp370);
                    sp80 = (temp_f10_648 * unksp36C) - (temp_f9_653 * (f32) sp368);
                    sp378 = (f64) sp78;
                    sp380 = (f64) sp80;
                    sp360 = temp_f8_649;
                    sp278 = (f64) sp78;
                    sp280 = (f64) sp80;
                    var_f5_681 = ((f32) sp380 * (f32) sp380) + (((f32) sp378 * (f32) sp378) + (unksp37C * unksp37C));
                    if (var_f5_681 > 0.000001f) {
                        if (var_f5_681 > 0.0f) {
                            temp_f2_687 = __frsqrte(var_f5_681);
                            temp_f2_693 = 0.5 * temp_f2_687 * -(((f64) var_f5_681 * (temp_f2_687 * temp_f2_687)) - 3.0);
                            temp_f2_697 = 0.5 * temp_f2_693 * -(((f64) var_f5_681 * (temp_f2_693 * temp_f2_693)) - 3.0);
                            var_f5_681 = (f32) ((f64) var_f5_681 * (0.5 * temp_f2_697 * -(((f64) var_f5_681 * (temp_f2_697 * temp_f2_697)) - 3.0)));
                        } else if (var_f5_681 < M2C_BITWISE(f32, 0.0)) {
                            var_r3_0 = &__float_nan;
                            var_f5_681 = M2C_BITWISE(f32, __float_nan.unk0);
                        } else {
                            sp1C = var_f5_681;
                            var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, sp1C) & 0x7F800000);
                            switch (var_r3_0) {     /* switch 4; irregular */
                            case 0x7F800000:        /* switch 4 */
                                if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                                    var_r0_726 = 1;
                                } else {
                                    var_r0_726 = 2;
                                }
                                break;
                            case 0x0:               /* switch 4 */
                                if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                                    var_r0_726 = 5;
                                } else {
                                    var_r0_726 = 3;
                                }
                                break;
                            default:                /* switch 4 */
                                var_r0_726 = 4;
                                break;
                            }
                            if (var_r0_726 == 1) {
                                var_r3_0 = &__float_nan;
                                var_f5_681 = M2C_BITWISE(f32, __float_nan.unk0);
                            }
                        }
                        var_f3_748 = 1.0f / var_f5_681;
                    } else {
                        var_f3_748 = 0.0f;
                    }
                    temp_f10_755 = (f32) sp378 * var_f3_748;
                    temp_f8_757 = (f32) sp380 * var_f3_748;
                    temp_f9_760 = unksp37C * var_f3_748;
                    sp378 = temp_f10_755;
                    unksp37C = temp_f9_760;
                    sp380 = temp_f8_757;
                    sp68 = (temp_f9_760 * sp360) - (temp_f8_757 * unksp35C);
                    sp6C = (temp_f8_757 * sp358) - (temp_f10_755 * sp360);
                    sp70 = (temp_f10_755 * unksp35C) - (temp_f9_760 * sp358);
                    sp368 = (f64) sp68;
                    sp370 = (f64) sp70;
                    sp268 = (f64) sp68;
                    sp270 = (f64) sp70;
                    var_f5_788 = ((f32) sp370 * (f32) sp370) + (((f32) sp368 * (f32) sp368) + (unksp36C * unksp36C));
                    if (var_f5_788 > 0.000001f) {
                        if (var_f5_788 > 0.0f) {
                            temp_f2_794 = __frsqrte(var_f5_788);
                            temp_f2_800 = 0.5 * temp_f2_794 * -(((f64) var_f5_788 * (temp_f2_794 * temp_f2_794)) - 3.0);
                            temp_f2_804 = 0.5 * temp_f2_800 * -(((f64) var_f5_788 * (temp_f2_800 * temp_f2_800)) - 3.0);
                            var_f5_788 = (f32) ((f64) var_f5_788 * (0.5 * temp_f2_804 * -(((f64) var_f5_788 * (temp_f2_804 * temp_f2_804)) - 3.0)));
                        } else if (var_f5_788 < M2C_BITWISE(f32, 0.0)) {
                            var_r3_0 = &__float_nan;
                            var_f5_788 = M2C_BITWISE(f32, __float_nan.unk0);
                        } else {
                            sp18 = var_f5_788;
                            var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, sp18) & 0x7F800000);
                            switch (var_r3_0) {     /* switch 5; irregular */
                            case 0x7F800000:        /* switch 5 */
                                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                    var_r0_833 = 1;
                                } else {
                                    var_r0_833 = 2;
                                }
                                break;
                            case 0x0:               /* switch 5 */
                                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                    var_r0_833 = 5;
                                } else {
                                    var_r0_833 = 3;
                                }
                                break;
                            default:                /* switch 5 */
                                var_r0_833 = 4;
                                break;
                            }
                            if (var_r0_833 == 1) {
                                var_r3_0 = &__float_nan;
                                var_f5_788 = M2C_BITWISE(f32, __float_nan.unk0);
                            }
                        }
                        var_f4_855 = 1.0f / var_f5_788;
                    } else {
                        var_f4_855 = 0.0f;
                    }
                    M2C_FIELD(temp_r30_187, f64 *, 0x40) = (f64) sp358;
                    temp_f8_864 = (f32) sp368 * var_f4_855;
                    M2C_FIELD(temp_r30_187, f32 *, 0x48) = (f64) sp360;
                    temp_f7_867 = unksp36C * var_f4_855;
                    temp_f6_871 = (f32) sp370 * var_f4_855;
                    M2C_FIELD(temp_r30_187, f64 *, 0x70) = (f64) M2C_FIELD(temp_r30_187, f32 *, 0x30);
                    M2C_FIELD(temp_r30_187, f64 *, 0x78) = (f64) M2C_FIELD(temp_r30_187, f32 *, 0x38);
                    temp_r30_187->unk20 = temp_f8_864;
                    temp_r30_187->unk24 = temp_f7_867;
                    temp_r30_187->unk28 = temp_f6_871;
                    temp_r30_187->unk2C = 0.0f;
                    temp_r30_187->unk10 = sp358;
                    temp_r30_187->unk14 = unksp35C;
                    temp_r30_187->unk18 = sp360;
                    temp_r30_187->unk1C = 0.0f;
                    temp_r30_187->unk0 = sp378;
                    temp_r30_187->unk4 = unksp37C;
                    temp_r30_187->unk8 = sp380;
                    temp_r30_187->unkC = 0.0f;
                    sp368 = temp_f8_864;
                    unksp36C = temp_f7_867;
                    sp370 = temp_f6_871;
                    temp_r30_187->unk64 = var_f0_560 / 300.0f;
                }
            }
            break;
        case 1:                                     /* switch 1 */
            temp_f30_901 = gUpdateTimeDelta;
            sp248.operator*(200.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp258 = sp58;
            sp60 = sp248.unk8 * temp_f30_901;
            sp260 = (f64) sp60;
            temp_r30_187->Translate(temp_r30_187, *((MKVector3 *) &sp258));
            temp_r30_187->unk54 += temp_r30_187->unk58 * gUpdateTimeDelta;
            temp_f1_927 = temp_r30_187->unk54;
            if (temp_f1_927 > 1.0f) {
                temp_r30_187->unk54 = temp_f1_927 - 1.0f;
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp228 = sp158;
            sp160 = temp_r30_187->unk48 * 300.0f;
            sp230 = (f64) sp160;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            var_r3_0 = (SkiffterCritter *) &temp_r30_187->unk30;
            sp238 = sp148;
            sp150 = (f32) sp230 * gUpdateTimeDelta;
            sp240 = (f64) sp150;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp348 = sp138;
            sp140 = temp_r30_187->unk38 + (f32) sp240;
            temp_r30_187->unk30 = (f32) sp348;
            sp350 = (f64) sp140;
            temp_r30_187->unk34 = unksp34C;
            temp_r30_187->unk38 = (f32) sp350;
            temp_r30_187->unk3C = 1.0f;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r30_187->unk64 == 0.0f) {
                temp_r30_187->unk60 = 3;
                temp_r27_984 = temp_r30_187->unk60;
                temp_r30_187->unk50 = *(checked_cast<SkiffterCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r29_180->unk0) + ((temp_r27_984 * 4) + 0x70));
                temp_r30_187->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_187->unk50, s16 *, 4) / 30.0f));
                temp_r30_187->unk54 = 0.0f;
                temp_r30_187->unk68 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r30_187->unk68) + 1));
                if (M2C_BITWISE(s32, temp_r30_187->unk68) >= (s32) temp_r29_180->unk178) {
                    temp_r30_187->unk68 = 0.0f;
                }
                var_r3_0 = temp_r29_180->unk174 + (M2C_BITWISE(s32, temp_r30_187->unk68) * 0x10);
                sp338 = M2C_FIELD(var_r3_0, f64 *, 0);
                sp340 = M2C_FIELD(var_r3_0, f64 *, 8);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp318 = sp128;
                var_f8_1035 = 0.0f;
                sp130 = (f32) sp340 - temp_r30_187->unk38;
                sp120 = 0.0f;
                sp320 = (f64) sp130;
                sp110 = 0.0f;
                sp118 = 1.0f;
                var_f0_1053 = ((f32) sp320 * (f32) sp320) + (((f32) sp318 * (f32) sp318) + (unksp31C * unksp31C));
                sp11C = 0.0f;
                sp108 = 0.0f;
                sp10C = 1.0f;
                sp218 = sp128;
                sp220 = (f64) sp130;
                sp328 = (f64) sp118;
                sp330 = (f64) sp120;
                sp308 = (f64) sp108;
                sp310 = (f64) sp110;
                if (var_f0_1053 > 0.000001f) {
                    if (var_f0_1053 > 0.0f) {
                        temp_f2_1069 = __frsqrte(var_f0_1053);
                        temp_f2_1075 = 0.5 * temp_f2_1069 * -(((f64) var_f0_1053 * (temp_f2_1069 * temp_f2_1069)) - 3.0);
                        temp_f2_1079 = 0.5 * temp_f2_1075 * -(((f64) var_f0_1053 * (temp_f2_1075 * temp_f2_1075)) - 3.0);
                        var_f0_1053 = (f32) ((f64) var_f0_1053 * (0.5 * temp_f2_1079 * -(((f64) var_f0_1053 * (temp_f2_1079 * temp_f2_1079)) - 3.0)));
                    } else if (var_f0_1053 < M2C_BITWISE(f32, 0.0)) {
                        var_r3_0 = &__float_nan;
                        var_f0_1053 = M2C_BITWISE(f32, __float_nan.unk0);
                    } else {
                        sp14 = var_f0_1053;
                        var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, sp14) & 0x7F800000);
                        switch (var_r3_0) {         /* switch 6; irregular */
                        case 0x7F800000:            /* switch 6 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1108 = 1;
                            } else {
                                var_r0_1108 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 6 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1108 = 5;
                            } else {
                                var_r0_1108 = 3;
                            }
                            break;
                        default:                    /* switch 6 */
                            var_r0_1108 = 4;
                            break;
                        }
                        if (var_r0_1108 == 1) {
                            var_r3_0 = &__float_nan;
                            var_f0_1053 = M2C_BITWISE(f32, __float_nan.unk0);
                        }
                    }
                    var_f8_1035 = 1.0f / var_f0_1053;
                } else {
                    var_f0_1053 = 0.0f;
                }
                temp_f3_1137 = (f32) sp318 * var_f8_1035;
                var_f7_1140 = 0.0f;
                temp_f6_1141 = (f32) sp320 * var_f8_1035;
                sp318 = temp_f3_1137;
                unksp31C *= var_f8_1035;
                sp320 = temp_f6_1141;
                var_f6_1151 = (temp_f6_1141 * temp_f6_1141) + ((temp_f3_1137 * temp_f3_1137) + (0.0f * 0.0f));
                M2C_FIELD(temp_r30_187, f64 *, 0x40) = (f64) sp318;
                unksp31C = 0.0f;
                M2C_FIELD(temp_r30_187, f32 *, 0x48) = (f64) sp320;
                M2C_FIELD(temp_r30_187, f64 *, 0x70) = (f64) M2C_FIELD(temp_r30_187, f32 *, 0x30);
                M2C_FIELD(temp_r30_187, f64 *, 0x78) = (f64) M2C_FIELD(temp_r30_187, f32 *, 0x38);
                if (var_f6_1151 > 0.000001f) {
                    if (var_f6_1151 > 0.0f) {
                        temp_f2_1164 = __frsqrte(var_f6_1151);
                        temp_f2_1170 = 0.5 * temp_f2_1164 * -(((f64) var_f6_1151 * (temp_f2_1164 * temp_f2_1164)) - 3.0);
                        temp_f2_1174 = 0.5 * temp_f2_1170 * -(((f64) var_f6_1151 * (temp_f2_1170 * temp_f2_1170)) - 3.0);
                        var_f6_1151 = (f32) ((f64) var_f6_1151 * (0.5 * temp_f2_1174 * -(((f64) var_f6_1151 * (temp_f2_1174 * temp_f2_1174)) - 3.0)));
                    } else if (var_f6_1151 < M2C_BITWISE(f32, 0.0)) {
                        var_r3_0 = &__float_nan;
                        var_f6_1151 = M2C_BITWISE(f32, __float_nan.unk0);
                    } else {
                        sp10 = var_f6_1151;
                        var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, sp10) & 0x7F800000);
                        switch (var_r3_0) {         /* switch 7; irregular */
                        case 0x7F800000:            /* switch 7 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1203 = 1;
                            } else {
                                var_r0_1203 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 7 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1203 = 5;
                            } else {
                                var_r0_1203 = 3;
                            }
                            break;
                        default:                    /* switch 7 */
                            var_r0_1203 = 4;
                            break;
                        }
                        if (var_r0_1203 == 1) {
                            var_r3_0 = &__float_nan;
                            var_f6_1151 = M2C_BITWISE(f32, __float_nan.unk0);
                        }
                    }
                    var_f7_1140 = 1.0f / var_f6_1151;
                }
                temp_f9_1229 = unksp31C * var_f7_1140;
                temp_f8_1231 = sp320 * var_f7_1140;
                temp_f10_1234 = sp318 * var_f7_1140;
                sp318 = temp_f10_1234;
                unksp31C = temp_f9_1229;
                sp320 = temp_f8_1231;
                sp48 = (unksp30C * temp_f8_1231) - ((f32) sp310 * temp_f9_1229);
                sp4C = ((f32) sp310 * temp_f10_1234) - ((f32) sp308 * temp_f8_1231);
                sp50 = ((f32) sp308 * temp_f9_1229) - (unksp30C * temp_f10_1234);
                sp328 = (f64) sp48;
                sp330 = (f64) sp50;
                sp208 = (f64) sp48;
                sp210 = (f64) sp50;
                var_f5_1262 = ((f32) sp330 * (f32) sp330) + (((f32) sp328 * (f32) sp328) + (unksp32C * unksp32C));
                if (var_f5_1262 > 0.000001f) {
                    if (var_f5_1262 > 0.0f) {
                        temp_f2_1268 = __frsqrte(var_f5_1262);
                        temp_f2_1274 = 0.5 * temp_f2_1268 * -(((f64) var_f5_1262 * (temp_f2_1268 * temp_f2_1268)) - 3.0);
                        temp_f2_1278 = 0.5 * temp_f2_1274 * -(((f64) var_f5_1262 * (temp_f2_1274 * temp_f2_1274)) - 3.0);
                        var_f5_1262 = (f32) ((f64) var_f5_1262 * (0.5 * temp_f2_1278 * -(((f64) var_f5_1262 * (temp_f2_1278 * temp_f2_1278)) - 3.0)));
                    } else if (var_f5_1262 < M2C_BITWISE(f32, 0.0)) {
                        var_r3_0 = &__float_nan;
                        var_f5_1262 = M2C_BITWISE(f32, __float_nan.unk0);
                    } else {
                        spC = var_f5_1262;
                        var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, spC) & 0x7F800000);
                        switch (var_r3_0) {         /* switch 8; irregular */
                        case 0x7F800000:            /* switch 8 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_1307 = 1;
                            } else {
                                var_r0_1307 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 8 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_1307 = 5;
                            } else {
                                var_r0_1307 = 3;
                            }
                            break;
                        default:                    /* switch 8 */
                            var_r0_1307 = 4;
                            break;
                        }
                        if (var_r0_1307 == 1) {
                            var_r3_0 = &__float_nan;
                            var_f5_1262 = M2C_BITWISE(f32, __float_nan.unk0);
                        }
                    }
                    var_f6_1329 = 1.0f / var_f5_1262;
                } else {
                    var_f6_1329 = 0.0f;
                }
                temp_r30_187->unk20 = sp318;
                temp_r30_187->unk24 = unksp31C;
                temp_r30_187->unk28 = sp320;
                temp_r30_187->unk2C = 0.0f;
                temp_f5_1347 = (f32) sp328 * var_f6_1329;
                temp_f4_1349 = unksp32C * var_f6_1329;
                temp_r30_187->unk10 = (f32) sp308;
                temp_f3_1352 = (f32) sp330 * var_f6_1329;
                temp_r30_187->unk14 = unksp30C;
                sp328 = temp_f5_1347;
                temp_r30_187->unk18 = (f32) sp310;
                temp_r30_187->unk1C = 0.0f;
                temp_r30_187->unk0 = temp_f5_1347;
                temp_r30_187->unk4 = temp_f4_1349;
                temp_r30_187->unk8 = temp_f3_1352;
                temp_r30_187->unkC = 0.0f;
                unksp32C = temp_f4_1349;
                sp330 = temp_f3_1352;
                temp_r30_187->unk64 = var_f0_1053 / 500.0f;
            }
            break;
        default:                                    /* switch 1 */
            temp_r30_187->unk54 += temp_r30_187->unk58 * gUpdateTimeDelta;
            temp_r0_1372 = temp_r30_187->unk60;
            if ((temp_r0_1372 == 3) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_r30_187->unk54 == 1.0f) != 0))) {
                temp_r30_187->unk60 = 4;
                temp_r27_1382 = temp_r30_187->unk60;
                temp_r30_187->unk50 = *(checked_cast<SkiffterCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r29_180->unk0) + ((temp_r27_1382 * 4) + 0x70));
                temp_r30_187->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_187->unk50, s16 *, 4) / 30.0f));
                temp_r30_187->unk54 = 0.0f;
            } else if (temp_r0_1372 == 4) {
                temp_f1_1409 = temp_r30_187->unk54;
                if (temp_f1_1409 > 1.0f) {
                    temp_r30_187->unk54 = temp_f1_1409 - 1.0f;
                }
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp1E8 = spF8;
            sp100 = temp_r30_187->unk48 * 500.0f;
            sp1F0 = (f64) sp100;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            var_r3_0 = (SkiffterCritter *) &temp_r30_187->unk30;
            sp1F8 = spE8;
            spF0 = (f32) sp1F0 * gUpdateTimeDelta;
            sp200 = (f64) spF0;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp2F8 = spD8;
            spE0 = temp_r30_187->unk38 + (f32) sp200;
            temp_r30_187->unk30 = (f32) sp2F8;
            sp300 = (f64) spE0;
            temp_r30_187->unk34 = unksp2FC;
            temp_r30_187->unk38 = (f32) sp300;
            temp_r30_187->unk3C = 1.0f;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r30_187->unk64 == 0.0f) {
                temp_r30_187->unk60 = 5;
                temp_r27_1467 = temp_r30_187->unk60;
                temp_r30_187->unk50 = *(checked_cast<SkiffterCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r29_180->unk0) + ((temp_r27_1467 * 4) + 0x70));
                var_r3_0 = M2C_BITWISE(SkiffterCritter *, temp_r30_187->unk50);
                temp_r30_187->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(var_r3_0, s16 *, 4) / 30.0f));
                temp_r30_187->unk54 = 0.0f;
            }
            break;
        case 5:                                     /* switch 1 */
            temp_r30_187->unk54 += temp_r30_187->unk58 * gUpdateTimeDelta;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_r30_187->unk54 == 1.0f) {
                temp_r30_187->unk60 = 2;
                temp_r30_187->unk64 = 5.0f * MKRand_Float(&gViewSeed, 0.75f, 1.0f);
                temp_r27_1510 = temp_r30_187->unk60;
                temp_r3_1517 = *(checked_cast<SkiffterCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r29_180->unk0) + ((temp_r27_1510 * 4) + 0x70));
                spD0 = 0.0f;
                temp_r30_187->unk50 = temp_r3_1517;
                spC0 = 1.0f;
                spB0 = 0.0f;
                spC8 = 1.0f;
                spCC = 0.0f;
                spB8 = 0.0f;
                spBC = 0.0f;
                spA8 = 0.0f;
                spAC = 1.0f;
                sp2D8 = (f64) spC8;
                sp2E0 = (f64) spD0;
                sp2C8 = (f64) spB8;
                sp2D0 = (f64) spC0;
                sp2B8 = (f64) spA8;
                temp_r30_187->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_187->unk50, s16 *, 4) / 30.0f));
                temp_r30_187->unk54 = 0.0f;
                sp2C0 = (f64) spB0;
                temp_r9_1567 = temp_r29_180->unk174 + (M2C_BITWISE(s32, temp_r30_187->unk68) * 0x10);
                sp2E8 = M2C_FIELD(temp_r9_1567, f64 *, 0);
                sp2F0 = M2C_FIELD(temp_r9_1567, f64 *, 8);
                sp3D8 = 0.0f;
                sp3DC = 0.0f;
                sp3E0 = 0.0f;
                sp3E8 = 0.0f;
                sp3EC = 0.0f;
                sp3F0 = 0.0f;
                sp3F8 = 0.0f;
                sp3FC = 0.0f;
                sp400 = 0.0f;
                sp404 = 1.0f;
                sp408 = 0.0f;
                sp40C = 0.0f;
                sp410 = 0;
                sp412 = 0;
                sp413 = 0;
                sp414 = 0;
                sp418 = 3.4028235e38f;
                sp41C = 0;
                sp420 = 0;
                sp424 = -1;
                sp428 = 0;
                var_r3_0 = MKCollision_SphereCollide(*((MKVector3 *) &sp2E8), 50.0f, (MKCollisionResult *) &sp3D8, 1, (MKCollisionMode) 7, 0);
                if (var_r3_0 != NULL) {
                    sp2C8 = (f64) sp3E8;
                    sp2D0 = (f64) sp3F0;
                }
                sp3C = ((f32) sp2C0 * (f32) sp2C8) - ((f32) sp2B8 * (f32) sp2D0);
                sp38 = (unksp2BC * (f32) sp2D0) - ((f32) sp2C0 * unksp2CC);
                sp40 = ((f32) sp2B8 * unksp2CC) - (unksp2BC * (f32) sp2C8);
                sp2D8 = (f64) sp38;
                sp2E0 = (f64) sp40;
                sp1D8 = (f64) sp38;
                sp1E0 = (f64) sp40;
                var_f4_1630 = ((f32) sp2E0 * (f32) sp2E0) + (((f32) sp2D8 * (f32) sp2D8) + (unksp2DC * unksp2DC));
                if (var_f4_1630 > 0.000001f) {
                    if (var_f4_1630 > 0.0f) {
                        temp_f1_1636 = __frsqrte(var_f4_1630);
                        temp_f1_1642 = 0.5 * temp_f1_1636 * -(((f64) var_f4_1630 * (temp_f1_1636 * temp_f1_1636)) - 3.0);
                        temp_f1_1646 = 0.5 * temp_f1_1642 * -(((f64) var_f4_1630 * (temp_f1_1642 * temp_f1_1642)) - 3.0);
                        var_f4_1630 = (f32) ((f64) var_f4_1630 * (0.5 * temp_f1_1646 * -(((f64) var_f4_1630 * (temp_f1_1646 * temp_f1_1646)) - 3.0)));
                    } else if (var_f4_1630 < M2C_BITWISE(f32, 0.0)) {
                        var_r3_0 = &__float_nan;
                        var_f4_1630 = M2C_BITWISE(f32, __float_nan.unk0);
                    } else {
                        sp8 = var_f4_1630;
                        var_r3_0 = (SkiffterCritter *) (M2C_BITWISE(s32, sp8) & 0x7F800000);
                        switch (var_r3_0) {         /* switch 9; irregular */
                        case 0x7F800000:            /* switch 9 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1675 = 1;
                            } else {
                                var_r0_1675 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 9 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1675 = 5;
                            } else {
                                var_r0_1675 = 3;
                            }
                            break;
                        default:                    /* switch 9 */
                            var_r0_1675 = 4;
                            break;
                        }
                        if (var_r0_1675 == 1) {
                            var_r3_0 = &__float_nan;
                            var_f4_1630 = M2C_BITWISE(f32, __float_nan.unk0);
                        }
                    }
                    var_f2_1697 = 1.0f / var_f4_1630;
                } else {
                    var_f2_1697 = 0.0f;
                }
                temp_f10_1704 = unksp2DC * var_f2_1697;
                temp_f9_1706 = (f32) sp2E0 * var_f2_1697;
                temp_f11_1709 = (f32) sp2D8 * var_f2_1697;
                sp2D8 = temp_f11_1709;
                unksp2DC = temp_f10_1704;
                sp28 = (unksp2CC * temp_f9_1706) - ((f32) sp2D0 * temp_f10_1704);
                sp2C = ((f32) sp2D0 * temp_f11_1709) - ((f32) sp2C8 * temp_f9_1706);
                sp30 = ((f32) sp2C8 * temp_f10_1704) - (unksp2CC * temp_f11_1709);
                M2C_FIELD(temp_r30_187, f64 *, 0x40) = (f64) sp28;
                sp2B8 = (f64) sp28;
                M2C_FIELD(temp_r30_187, f32 *, 0x48) = (f64) sp30;
                temp_r30_187->unk20 = (f32) sp2C8;
                temp_r30_187->unk24 = unksp2CC;
                temp_r30_187->unk28 = (f32) sp2D0;
                temp_r30_187->unk2C = 0.0f;
                sp2C0 = (f64) sp30;
                temp_r30_187->unk10 = (f32) sp2B8;
                temp_r30_187->unk14 = unksp2BC;
                temp_r30_187->unk18 = (f32) sp2C0;
                temp_r30_187->unk1C = 0.0f;
                temp_r30_187->unk0 = temp_f11_1709;
                temp_r30_187->unk4 = temp_f10_1704;
                temp_r30_187->unk8 = temp_f9_1706;
                temp_r30_187->unkC = 0.0f;
                sp2E0 = temp_f9_1706;
                temp_r30_187->unk30 = (f32) sp2E8;
                sp1C8 = (f64) sp28;
                temp_r30_187->unk34 = unksp2EC;
                sp1D0 = (f64) sp30;
                temp_r30_187->unk38 = (f32) sp2F0;
                temp_r30_187->unk3C = 1.0f;
            }
            break;
        }
        var_r31_181 += 1;
        var_r28_182 += 0x80;
        goto loop_197;
    }
    return var_r3_0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk170'
void SkiffterCritter::Resolve() {
    MKHeap *temp_r3_1790;
    s32 temp_r0_1810;
    s32 temp_r31_1789;
    s32 var_r4_1803;
    s32 var_r6_1806;
    void *var_r3_1797;

    MKProp::Resolve();
    temp_r31_1789 = this->unk90 << 7;
    temp_r3_1790 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1790 != NULL) {
        var_r3_1797 = ((MKHeap *) (temp_r3_1790->Current()))->Alloc(temp_r31_1789, NULL, 0);
    } else {
        var_r3_1797 = malloc(temp_r31_1789);
    }
    var_r4_1803 = 0;
    this->unk170 = var_r3_1797;
    var_r6_1806 = 0;
loop_5:
    if (var_r6_1806 < (s32) this->unk90) {
        temp_r0_1810 = var_r4_1803 + 0x60;
        var_r6_1806 += 1;
        var_r4_1803 += 0x80;
        *(this->unk170 + temp_r0_1810) = 0;
        goto loop_5;
    }
}
#endif

void SkiffterCritter::LoadDone() {
    Critters::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 SkiffterCritter::LoadLine(MKIniLine *arg0) {
    MKHeap *temp_r3_1864;
    MKIniLine *var_r28_1883;
    s32 temp_r29_1863;
    s32 temp_r3_1860;
    s32 var_r30_1879;
    void *var_r3_1871;

    if (Critters::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField(lit_stringBase0) != 0) {
        temp_r3_1860 = arg0->GetNmbrOfSubLines();
        this->unk178 = temp_r3_1860;
        temp_r29_1863 = this->unk178 * 0x10;
        temp_r3_1864 = temp_r3_1860->Current();
        if (temp_r3_1864 != NULL) {
            var_r3_1871 = ((MKHeap *) (temp_r3_1864->Current()))->Alloc(temp_r29_1863, NULL, 0);
        } else {
            var_r3_1871 = malloc(temp_r29_1863);
        }
        this->unk174 = var_r3_1871;
        var_r30_1879 = 0;
        var_r28_1883 = arg0->unkC->GetSubLine(arg0);
loop_8:
        if (var_r28_1883 != NULL) {
            var_r28_1883->LoadVector3(&lit_stringBase0[0xA], this->unk174 + var_r30_1879, 0);
            var_r30_1879 += 0x10;
            var_r28_1883 = var_r28_1883->unkC->GetNextLine(var_r28_1883);
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk178'
void SkiffterCritter::Init() {
    Critters::Init();
    this->unk178 = 0;
    this->unk174 = NULL;
}
#endif

void SkiffterCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

#if 0 // DRAFT: expression syntax error
void SkiffterCritterDescriptor::LoadDone() {
    s8 *temp_r30_1954;
    s8 *temp_r30_1974;
    s8 *temp_r30_1992;
    s8 *temp_r30_2010;
    s8 *temp_r30_2028;
    void *var_r3_1966;
    void *var_r3_1984;
    void *var_r3_2002;
    void *var_r3_2020;
    void *var_r3_2038;

    KDPropDescriptor::LoadDone();
    temp_r30_1954 = this->unk34;
    if (temp_r30_1954->Exists(&lit_stringBase0[0x13]) != 0) {
        var_r3_1966 = temp_r30_1954->GetAnim(&lit_stringBase0[0x13]);
    } else {
        var_r3_1966 = NULL;
    }
    this->unk74 = (s32) var_r3_1966;
    temp_r30_1974 = this->unk34;
    if (temp_r30_1974->Exists(&lit_stringBase0[0x19]) != 0) {
        var_r3_1984 = temp_r30_1974->GetAnim(&lit_stringBase0[0x19]);
    } else {
        var_r3_1984 = NULL;
    }
    this->unk78 = (s32) var_r3_1984;
    temp_r30_1992 = this->unk34;
    if (temp_r30_1992->Exists(&lit_stringBase0[0x24]) != 0) {
        var_r3_2002 = temp_r30_1992->GetAnim(&lit_stringBase0[0x24]);
    } else {
        var_r3_2002 = NULL;
    }
    this->unk7C = (s32) var_r3_2002;
    temp_r30_2010 = this->unk34;
    if (temp_r30_2010->Exists(&lit_stringBase0[0x2D]) != 0) {
        var_r3_2020 = temp_r30_2010->GetAnim(&lit_stringBase0[0x2D]);
    } else {
        var_r3_2020 = NULL;
    }
    this->unk80 = (s32) var_r3_2020;
    temp_r30_2028 = this->unk34;
    if (temp_r30_2028->Exists(&lit_stringBase0[0x31]) != 0) {
        var_r3_2038 = temp_r30_2028->GetAnim(&lit_stringBase0[0x31]);
    } else {
        var_r3_2038 = NULL;
    }
    this->unk84 = (s32) var_r3_2038;
}
#endif

void SkiffterCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<SkiffterCritterDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
