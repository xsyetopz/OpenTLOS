#include "spyro/source/IceBreathFX.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/FuryFXIce.h"
#include "spyro/source/FuryFXIce2.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/IceExplosion.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(Matrix **);                            /* extern */
Matrix **malloc(M2C_UNK);                           /* extern */
extern s32 GS_SpyroBreathIceRico1;
extern s32 GS_SpyroBreathIceRico2;
extern s32 GS_SpyroBreathIceRico3;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_732 = 0;
static u8 lit_733 = 1;
static s32 lit_872 = 3;

static s32 lit_875 = 3;

static s32 lit_877 = 3;

static s32 lit_880 = 3;

static s32 lit_882 = 3;

static s32 lit_885 = 3;

static s32 lit_887 = 3;

static s32 lit_889 = 3;

#if 0 // DRAFT: undefined identifier 'ResetFury'
void IceBreathFX::ResetFury() {
    this->unk168->ResetFury();
    ((FuryFXIce2 *) (M2C_BITWISE(FuryFXIce2 *, this->unk16C)))->ResetFury();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spC'
void IceBreathFX::DrawWallIceShards() {
    FuryFXIce2 *var_r31_87;
    f32 var_f0_97;
    void *temp_r6_128;
    var_r31_87 = this->unk174;
loop_4:
    if (var_r31_87 != NULL) {
        temp_r6_128 = var_r31_87->unk0;
        if (temp_r6_128 != NULL) {
            var_f0_97 = 2.0f * ((M2C_FIELD(temp_r6_128, f32 *, 0x40) / 0.25f) - 0.5f);
            if (var_f0_97 < 0.0f) {
                var_f0_97 = -var_f0_97;
            }
            M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (temp_r6_128 - 4) + 4, 0x40);
            arg_sp10.Scale3x3((Matrix *) &arg_sp10, M2C_FIELD(temp_r6_128, f32 *, 0x44) * (1.0f - var_f0_97));
            MKModel_SetWorldMatrix(this->unkB4, *((Matrix *) &arg_sp10));
            MKModel_Draw(this->unkB4, NULL);
            var_r31_87 += 4;
            goto loop_4;
        }
    }
}
#endif

void IceBreathFX::UpdateWallIceShards() {
    FuryFXIce2 *temp_r4_179;
    FuryFXIce2 *var_r6_153;
    f32 var_f1_160;
    void *temp_r4_191;
    void *temp_r5_182;

    var_r6_153 = this->unk174;
loop_10:
    if (var_r6_153 != NULL) {
        temp_r4_191 = var_r6_153->unk0;
        if (temp_r4_191 == NULL) {
            return;
        }
        var_f1_160 = M2C_FIELD(temp_r4_191, f32 *, 0x40) - gUpdateTimeDelta;
        if (var_f1_160 < 0.25f) {

        } else {
            var_f1_160 = 0.25f;
        }
        if (var_f1_160 > 0.0f) {

        } else {
            var_f1_160 = 0.0f;
        }
        M2C_FIELD(temp_r4_191, f32 *, 0x40) = var_f1_160;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r4_191, f32 *, 0x40) == 0.0f) {
            temp_r4_179 = this->unk174;
            this->unk174 = (FuryFXIce2 *) &temp_r4_179->unk4;
            temp_r5_182 = temp_r4_179->unk0;
            temp_r4_179->unk0 = var_r6_153->unk0;
            var_r6_153->unk0 = temp_r5_182;
        }
        var_r6_153 += 4;
        goto loop_10;
    }
}

#if 0 // DRAFT: undefined identifier 'sp18'
void IceBreathFX::SpawnWallIceShard(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    u8 sp108;
    s32 sp104;
    void *sp100;
    s32 spFC;
    f32 spF8;
    s32 spF4;
    s8 spF3;
    s8 spF2;
    s16 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    FuryFXIce2 *temp_r3_210;
    FuryFXIce2 *temp_r3_216;
    f32 temp_f5_274;
    void *temp_r30_218;
    void *var_r3_352;

    temp_r3_210 = this->unk174;
    if ((u32) M2C_FIELD(temp_r3_210, u32 *, -4) != 0U) {
        temp_r3_216 = temp_r3_210 - 4;
        this->unk174 = temp_r3_216;
        temp_r30_218 = temp_r3_216->unk0;
        if (temp_r30_218 != NULL) {
            KDSound_Play3d(GS_SpyroBreathIceRico3, &arg0, 0U, -1, 0.0f, 0U);
            M2C_STRUCT_COPY(temp_r30_218, &Matrix::identity, 0x40);
            sp50 = 0.0f;
            sp48 = 0.0f;
            sp4C = 1.0f;
            spB0 = (f64) sp50;
            spA8 = (f64) sp48;
            KDMath_BuildMatrixFromFwd((Matrix *) temp_r30_218, arg1, (MKVector3 *) &spA8);
            sp8 = -arg1.unk0;
            spC = -arg1.unk4;
            sp10 = -arg1.unk8;
            sp78 = (f64) sp8;
            sp80 = (f64) sp10;
            sp88.operator*(150.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f6, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f6, $f0 */);
            temp_f5_274 = arg0.unk8;
            sp98 = sp18;
            sp20 = temp_f5_274 + sp88.unk8;
            M2C_FIELD(temp_r30_218, f32 *, 0x30) = (f32) sp98;
            spA0 = (f64) sp20;
            M2C_FIELD(temp_r30_218, f32 *, 0x34) = unksp9C;
            M2C_FIELD(temp_r30_218, f32 *, 0x38) = (f32) spA0;
            M2C_FIELD(temp_r30_218, f32 *, 0x3C) = 1.0f;
            M2C_FIELD(temp_r30_218, f32 *, 0x44) = arg2;
            M2C_FIELD(temp_r30_218, f32 *, 0x40) = 0.25f;
            spB8 = 0.0f;
            spBC = 0.0f;
            spC0 = 0.0f;
            spC8 = 0.0f;
            spCC = 0.0f;
            spD0 = 0.0f;
            spD8 = 0.0f;
            spDC = 0.0f;
            spE0 = 0.0f;
            spE4 = 1.0f;
            spE8 = 0.0f;
            spEC = 0.0f;
            spF0 = 0;
            spF2 = 0;
            spF3 = 0;
            spF4 = 0;
            spF8 = 3.4028235e38f;
            spFC = 0;
            sp100 = NULL;
            sp104 = -1;
            sp108 = 0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp58 = sp38;
            sp40 = arg1.unk8 * 200.0f;
            sp60 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f6, $f0 */);
            sp68 = sp28;
            sp30 = temp_f5_274 + (f32) sp60;
            sp70 = (f64) sp30;
            if (MKCollision_RayCollide(arg0, *((MKVector3 *) &sp68), (MKCollisionResult *) &spB8, (MKCollisionMode) 2, 0x04000000) != 0) {
                if ((sp108 != 0) && (sp100 != NULL) && (var_r3_352 = M2C_FIELD(sp100, void **, 8), ((var_r3_352 == NULL) == 0))) {

                } else {
                    var_r3_352 = NULL;
                }
                if (var_r3_352 != NULL) {
                    this->unkB8.unk50 = 0;
                    M2C_FIELD(M2C_FIELD(var_r3_352, void **, 0x44), M2C_UNK (**)(BreathHitMessage *), 0x2C)(&this->unkB8);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
u8 IceBreathFX::ShootIceShard(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    u8 sp4D8;
    s32 sp4D4;
    MKCollisionInfo *sp4D0;
    s32 sp4CC;
    f32 sp4C8;
    s32 sp4C4;
    s8 sp4C3;
    s8 sp4C2;
    s16 sp4C0;
    f32 sp4BC;
    f32 sp4B8;
    f32 sp4B4;
    f32 sp4B0;
    f32 sp4AC;
    f32 sp4A8;
    f32 sp4A0;
    f32 sp49C;
    f32 sp498;
    f32 sp490;
    f32 sp48C;
    f32 sp488;
    f64 sp480;                                      /* compiler-managed */
    f64 sp478;                                      /* compiler-managed */
    M2C_UNK sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;                                      /* compiler-managed */
    f64 sp448;                                      /* compiler-managed */
    f64 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    MKVector3 sp408;
    MKVector3 sp3F8;
    MKVector3 sp3E8;
    M2C_UNK sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    M2C_UNK sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    MKVector3 sp2D8;
    MKVector3 sp2C8;
    M2C_UNK sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    MKVector3 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    MKVector3 sp228;
    MKVector3 sp218;
    MKVector3 sp208;
    M2C_UNK sp1F8;
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
    f32 sp1A0;
    f32 sp190;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp160;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp100;
    f32 spF0;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spC0;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    LiquidFX *temp_r0_606;
    LiquidFX *temp_r0_634;
    MKProp *var_r3_722;
    ManagedLight *temp_r3_1725;
    ManagedLight *temp_r3_1744;
    ManagedLight *temp_r3_1761;
    ManagedLight *temp_r4_1717;
    Matrix **temp_r5_1514;
    TargetManager ***var_r27_846;
    TargetManager **temp_r30_1033;
    f32 temp_f0_467;
    f32 temp_f0_916;
    f32 temp_f1_1393;
    f32 temp_f1_1523;
    f32 temp_f1_1693;
    f32 temp_f1_802;
    f32 temp_f22_1280;
    f32 temp_f22_759;
    f32 temp_f23_1285;
    f32 temp_f23_764;
    f32 temp_f26_1635;
    f32 temp_f29_1630;
    f32 temp_f2_1392;
    f32 temp_f2_1522;
    f32 temp_f3_1394;
    f32 temp_f3_1525;
    f32 temp_f3_1686;
    f32 temp_f4_1003;
    f32 temp_f4_1175;
    f32 temp_f4_1399;
    f32 temp_f5_999;
    f32 temp_f6_1001;
    f32 var_f24_499;
    f32 var_f29_1418;
    f32 var_f2_944;
    f32 var_f31_850;
    f32 var_f3_1128;
    f32 var_f4_1061;
    f32 var_f4_1183;
    f32 var_f4_1250;
    f32 var_f4_1529;
    f32 var_f4_1596;
    f32 var_f4_992;
    f64 temp_f1_1067;
    f64 temp_f1_1073;
    f64 temp_f1_1077;
    f64 temp_f1_1189;
    f64 temp_f1_1195;
    f64 temp_f1_1199;
    f64 temp_f1_1402;
    f64 temp_f1_1408;
    f64 temp_f1_1412;
    f64 temp_f1_1535;
    f64 temp_f1_1541;
    f64 temp_f1_1545;
    f64 temp_f2_928;
    f64 temp_f2_934;
    f64 temp_f2_938;
    s32 temp_r0_522;
    s32 temp_r3_1096;
    s32 temp_r3_1218;
    s32 temp_r3_1431;
    s32 temp_r3_1564;
    s32 temp_r3_520;
    s32 temp_r3_957;
    s32 temp_r4_1334;
    s32 temp_r4_1503;
    s32 var_ctr_834;
    s32 var_r0_1106;
    s32 var_r0_1228;
    s32 var_r0_1441;
    s32 var_r0_1574;
    s32 var_r0_538;
    s32 var_r0_967;
    s32 var_r22_833;
    s32 var_r25_1624;
    s32 var_r27_753;
    s32 var_r29_501;
    u32 temp_r3_607;
    u32 temp_r3_635;
    u8 var_r28_662;
    u8 var_r3_528;
    void *temp_r28_422;
    void *temp_r3_1321;
    void *temp_r3_1339;
    void *temp_r3_1347;
    void *temp_r3_1382;
    void *temp_r3_1508;
    void *temp_r3_1728;
    void *temp_r3_1752;
    void *temp_r3_1767;
    void *temp_r3_417;
    void *temp_r3_891;
    void *temp_r4_1391;
    void *temp_r4_1762;
    void *temp_r4_524;
    void *temp_r5_1520;
    void *var_r26_848;

    temp_r3_417 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, M2C_UNK *), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), &gb);
    if (temp_r3_417 != NULL) {
        temp_r28_422 = M2C_FIELD(temp_r3_417, void **, 0x2C);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(sp3F8, sp3E8);
        sp408.operator*(5.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r24, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_417, f64 *, 0) = spC8;
        spD0 = arg0.unk8 + sp408.unk8;
        sp418 = spC8;
        M2C_FIELD(temp_r3_417, f64 *, 8) = (f64) spD0;
        M2C_FIELD(temp_r3_417, f32 *, 0x20) = 0.0f;
        sp420 = (f64) spD0;
        M2C_FIELD(temp_r3_417, f32 *, 0x28) = 0.0f;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
        temp_f0_467 = arg1.unk8 * MKRand_Float(&gViewSeed, 500.0f, 2000.0f);
        M2C_FIELD(temp_r28_422, f64 *, 0) = spB8;
        spC0 = temp_f0_467;
        sp3C8 = spB8;
        sp3D0 = (f64) spC0;
        M2C_FIELD(temp_r28_422, f64 *, 8) = (f64) spC0;
        M2C_FIELD(temp_r28_422, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.125f, 0.5f);
        M2C_FIELD(temp_r28_422, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r28_422, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
    }
    if (this->unkAC > 0.0f) {
        return 0U;
    }
    sp478 = M2C_FIELD(&arg1, f64 *, 0);
    var_f24_499 = 0.0f;
    var_r29_501 = 0;
    sp480 = (f64) M2C_FIELD(&arg1, f32 *, 8);
    this->unk188 += 1;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) - this->unk18C) > 0.5f) {
        this->unk188 = NULL;
    }
    this->unk18C = M2C_FIELD(&gb, f32 *, 0x30C);
    temp_r3_520 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_522 = *(&GameData::gameData[0x70] + (temp_r3_520 + 0x7C));
    temp_r4_524 = &GameData::gameData[0x70] + (temp_r3_520 + 0x64);
    if (temp_r0_522 == 3) {
        var_r3_528 = 0;
        if (((s32) M2C_FIELD(temp_r4_524, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_524, s32 *, 4) == 3)) {
            var_r3_528 = 1;
        }
        var_r0_538 = var_r3_528 != 0;
    } else {
        var_r0_538 = *(temp_r4_524 + (temp_r0_522 * 4));
    }
    switch (var_r0_538) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        this->unkAC = 0.2f;
        var_r29_501 = 0;
        var_f24_499 = 0.0f;
        this->unk198 = 0.5f;
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **, f32), 0x40)(M2C_FIELD(&gb, void ***, 0), 0.2f)))->RumblePlay(0.02f, 0.3f, 0.04f, 0, 4.0f, 0U);
        break;
    case 1:                                         /* switch 1 */
        this->unkAC = 0.2f;
        var_r29_501 = 1;
        var_f24_499 = 0.0f;
        this->unk198 = 0.8f;
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **, f32), 0x40)(M2C_FIELD(&gb, void ***, 0), 0.2f)))->RumblePlay(0.02f, 0.5f, 0.04f, 0, 4.0f, 0U);
        break;
    case 2:                                         /* switch 1 */
        var_r29_501 = 2;
        this->unkAC = 0.13f;
        var_f24_499 = 0.01f;
        this->unk198 = 1.2f;
        temp_r0_606 = this->unk188;
        temp_r3_607 = (u32) temp_r0_606 >> 0x1FU;
        if (((((s32) temp_r0_606 & 1) ^ temp_r3_607) - temp_r3_607) == 0) {
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.8f, 0.8f, 0.04f, 0, 4.0f, 0U);
        }
        break;
    case 3:                                         /* switch 1 */
        var_r29_501 = 0xA;
        this->unkAC = 0.1f;
        var_f24_499 = 0.022f;
        this->unk198 = 1.6f;
        temp_r0_634 = this->unk188;
        temp_r3_635 = (u32) temp_r0_634 >> 0x1FU;
        if (((((s32) temp_r0_634 & 1) ^ temp_r3_635) - temp_r3_635) == 0) {
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(1.0f, 1.0f, 0.04f, 0, 4.0f, 0U);
        }
        break;
    }
    sp488 = 0.0f;
    var_r28_662 = 0;
    sp48C = 0.0f;
    sp490 = 0.0f;
    sp498 = 0.0f;
    sp49C = 0.0f;
    sp4A0 = 0.0f;
    sp4A8 = 0.0f;
    sp4AC = 0.0f;
    sp4B0 = 0.0f;
    sp4B4 = 1.0f;
    sp4B8 = 0.0f;
    sp4BC = 0.0f;
    sp4C0 = 0;
    sp4C2 = 0;
    sp4C3 = 0;
    sp4C4 = 0;
    sp4C8 = 3.4028235e38f;
    sp4CC = 0;
    sp4D0 = NULL;
    sp4D4 = -1;
    sp4D8 = 0;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp3A8 = sp198;
    sp1A0 = arg1.unk8 * 300.0f;
    sp3B0 = (f64) sp1A0;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r24, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp3B8 = sp188;
    sp190 = arg0.unk8 + (f32) sp3B0;
    sp3C0 = (f64) sp190;
    if (MKCollision_RayCollide(arg0, *((MKVector3 *) &sp3B8), (MKCollisionResult *) &sp488, (MKCollisionMode) 7, 0x04000004) != 0) {
        var_r28_662 = 1;
        if ((sp4D8 != 0) && (sp4D0 != NULL) && (var_r3_722 = sp4D0->unk8, ((var_r3_722 == NULL) == 0))) {

        } else {
            var_r3_722 = NULL;
        }
        if (var_r3_722 != NULL) {
            this->unkB8.unk50 = 0;
            M2C_FIELD(this, f64 *, 0xC8) = (f64) sp488;
            M2C_FIELD(this, f64 *, 0xD0) = (f64) sp490;
            this->unkB8.unk30 = sp4D0;
            M2C_FIELD(var_r3_722->__vptr, M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(&this->unkB8, (f64) sp488);
        }
        this->unk170->Trigger(*((MKVector3 *) &sp488), this->unk198);
        var_r27_753 = 0;
        do {
            temp_f22_759 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f23_764 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp178 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp17C = temp_f23_764;
            sp180 = temp_f22_759;
            sp378 = (f64) sp178;
            sp380 = (f64) sp180;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp388 = sp168;
            sp170 = (f32) sp380 + sp4A0;
            sp390 = (f64) sp170;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp398 = sp158;
            sp160 = (f32) sp390 * 800.0f;
            sp3A0 = (f64) sp160;
            temp_f1_802 = MKRand_Float(&gViewSeed, 6.0f, 10.0f);
            sp148 = 0.5f;
            sp14C = 0.5f;
            sp150 = 1.0f;
            sp154 = 1.0f;
            sp20 = this->unk198 * temp_f1_802;
            sp368 = (f64) sp148;
            sp370 = (f64) sp150;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp488), *((MKVector3 *) &sp398), sp20, *((MKVector4 *) &sp368), -2160.0f);
            var_r27_753 += 1;
        } while (var_r27_753 < 5);
    }
    if ((var_r28_662 != 0) && (var_r29_501 == 0)) {
        return 1U;
    }
    var_r22_833 = 0;
    var_ctr_834 = 0x19;
loop_39:
    if ((u8) *(this->unkA8 + (var_r22_833 + 0x20)) == 0) {
        var_r27_846 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
        var_r26_848 = NULL;
        sp458 = M2C_FIELD(&arg1, f64 *, 0);
        var_f31_850 = 3.4028235e38f;
        sp460 = (f64) M2C_FIELD(&arg1, f32 *, 8);
loop_71:
        if (var_r27_846 != NULL) {
            temp_r30_1033 = *var_r27_846;
            if (temp_r30_1033 != NULL) {
                if (((*temp_r30_1033)->unk8.unk0(temp_r30_1033) != NULL) && (M2C_FIELD(*temp_r30_1033, u8 (**)(TargetManager **), 0x18)(temp_r30_1033) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r30_1033)->unk8.unk4)(temp_r30_1033) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r30_1033)->unk8.unk4)(temp_r30_1033)))->IsActive() != 0))) {
                    temp_r3_891 = M2C_FIELD((*temp_r30_1033)->unk8.unk0(temp_r30_1033), void **, 8);
                    sp358 = M2C_FIELD(temp_r3_891, f64 *, 0x30);
                    sp360 = M2C_FIELD(temp_r3_891, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    sp448 = sp138;
                    sp140 = (f32) sp360 - arg0.unk8;
                    sp450 = (f64) sp140;
                    temp_f0_916 = ((f32) sp450 * (f32) sp450) + (((f32) sp448 * (f32) sp448) + (unksp44C * unksp44C));
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if ((temp_f0_916 == 2.5e7f) && (temp_f0_916 < var_f31_850)) {
                        if (temp_f0_916 > 0.000001f) {
                            if (temp_f0_916 > 0.0f) {
                                temp_f2_928 = __frsqrte(temp_f0_916);
                                temp_f2_934 = 0.5 * temp_f2_928 * -(((f64) temp_f0_916 * (temp_f2_928 * temp_f2_928)) - 3.0);
                                temp_f2_938 = 0.5 * temp_f2_934 * -(((f64) temp_f0_916 * (temp_f2_934 * temp_f2_934)) - 3.0);
                                var_f2_944 = (f32) ((f64) temp_f0_916 * (0.5 * temp_f2_938 * -(((f64) temp_f0_916 * (temp_f2_938 * temp_f2_938)) - 3.0)));
                            } else if (temp_f0_916 < M2C_BITWISE(f32, 0.0)) {
                                var_f2_944 = __float_nan;
                            } else {
                                sp18 = temp_f0_916;
                                temp_r3_957 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                                switch (temp_r3_957) { /* switch 2; irregular */
                                case 0x7F800000:    /* switch 2 */
                                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                        var_r0_967 = 1;
                                    } else {
                                        var_r0_967 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 2 */
                                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                        var_r0_967 = 5;
                                    } else {
                                        var_r0_967 = 3;
                                    }
                                    break;
                                default:            /* switch 2 */
                                    var_r0_967 = 4;
                                    break;
                                }
                                if (var_r0_967 == 1) {
                                    var_f2_944 = __float_nan;
                                } else {
                                    var_f2_944 = temp_f0_916;
                                }
                            }
                            var_f4_992 = 1.0f / var_f2_944;
                        } else {
                            var_f4_992 = 0.0f;
                        }
                        temp_f5_999 = unksp44C * var_f4_992;
                        temp_f6_1001 = (f32) sp448 * var_f4_992;
                        temp_f4_1003 = (f32) sp450 * var_f4_992;
                        sp448 = temp_f6_1001;
                        unksp44C = temp_f5_999;
                        sp450 = temp_f4_1003;
                        if (((temp_f4_1003 * (f32) sp460) + ((temp_f6_1001 * (f32) sp458) + (temp_f5_999 * unksp45C))) > 0.98f) {
                            var_f31_850 = temp_f0_916;
                            var_r26_848 = (*temp_r30_1033)->unk8.unk0(temp_r30_1033);
                            M2C_FIELD(*temp_r30_1033, M2C_UNK (**)(TargetManager **, MKVector3 *, M2C_UNK *), 0x2C)(temp_r30_1033, &arg0, &sp468);
                        }
                    }
                }
                var_r27_846 += 4;
                goto loop_71;
            }
        }
        if (var_r26_848 != NULL) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp478 = spA8;
            spB0 = sp470 - arg0.unk8;
            sp480 = (f64) spB0;
            sp348 = spA8;
            sp350 = (f64) spB0;
            var_f4_1061 = ((f32) sp480 * (f32) sp480) + (((f32) sp478 * (f32) sp478) + (unksp47C * unksp47C));
            if (var_f4_1061 > 0.000001f) {
                if (var_f4_1061 > 0.0f) {
                    temp_f1_1067 = __frsqrte(var_f4_1061);
                    temp_f1_1073 = 0.5 * temp_f1_1067 * -(((f64) var_f4_1061 * (temp_f1_1067 * temp_f1_1067)) - 3.0);
                    temp_f1_1077 = 0.5 * temp_f1_1073 * -(((f64) var_f4_1061 * (temp_f1_1073 * temp_f1_1073)) - 3.0);
                    var_f4_1061 = (f32) ((f64) var_f4_1061 * (0.5 * temp_f1_1077 * -(((f64) var_f4_1061 * (temp_f1_1077 * temp_f1_1077)) - 3.0)));
                } else if (var_f4_1061 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1061 = __float_nan;
                } else {
                    sp14 = var_f4_1061;
                    temp_r3_1096 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                    switch (temp_r3_1096) {         /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1106 = 1;
                        } else {
                            var_r0_1106 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1106 = 5;
                        } else {
                            var_r0_1106 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_1106 = 4;
                        break;
                    }
                    if (var_r0_1106 == 1) {
                        var_f4_1061 = __float_nan;
                    }
                }
                var_f3_1128 = 1.0f / var_f4_1061;
            } else {
                var_f3_1128 = 0.0f;
            }
            sp478 = (f32) sp478 * var_f3_1128;
            unksp47C *= var_f3_1128;
            sp480 = (f32) sp480 * var_f3_1128;
        }
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(sp328, sp318);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
        sp338 = sp98;
        spA0 = sp328.unk8 * var_f24_499;
        sp340 = (f64) spA0;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f4_1175 = sp480 + (f32) sp340;
        sp480 = temp_f4_1175;
        var_f4_1183 = (temp_f4_1175 * temp_f4_1175) + ((sp478 * sp478) + (unksp47C * unksp47C));
        if (var_f4_1183 > 0.000001f) {
            if (var_f4_1183 > 0.0f) {
                temp_f1_1189 = __frsqrte(var_f4_1183);
                temp_f1_1195 = 0.5 * temp_f1_1189 * -(((f64) var_f4_1183 * (temp_f1_1189 * temp_f1_1189)) - 3.0);
                temp_f1_1199 = 0.5 * temp_f1_1195 * -(((f64) var_f4_1183 * (temp_f1_1195 * temp_f1_1195)) - 3.0);
                var_f4_1183 = (f32) ((f64) var_f4_1183 * (0.5 * temp_f1_1199 * -(((f64) var_f4_1183 * (temp_f1_1199 * temp_f1_1199)) - 3.0)));
            } else if (var_f4_1183 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1183 = __float_nan;
            } else {
                sp10 = var_f4_1183;
                temp_r3_1218 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1218) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1228 = 1;
                    } else {
                        var_r0_1228 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1228 = 5;
                    } else {
                        var_r0_1228 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_1228 = 4;
                    break;
                }
                if (var_r0_1228 == 1) {
                    var_f4_1183 = __float_nan;
                }
            }
            var_f4_1250 = 1.0f / var_f4_1183;
        } else {
            var_f4_1250 = 0.0f;
        }
        sp478 *= var_f4_1250;
        unksp47C *= var_f4_1250;
        sp480 *= var_f4_1250;
        M2C_FIELD((this->unkA8 + var_r22_833), s8 *, 0x20) = 1;
        sp298.operator*(350.0f);
        sp2A8.operator*(this->unk198);
        temp_f22_1280 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f23_1285 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f23_1285, temp_f22_1280);
        sp2C8.operator*(20.0f);
        sp2D8.operator*(this->unk198);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r24, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp2E8 = sp38;
        sp40 = arg0.unk8 + sp2D8.unk8;
        sp2F0 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_1321 = this->unkA8 + var_r22_833;
        sp2F8 = sp88;
        M2C_FIELD(temp_r3_1321, f64 *, 0) = sp88;
        sp90 = (f32) sp2F0 + sp2A8.unk8;
        M2C_FIELD(temp_r3_1321, f64 *, 8) = (f64) sp90;
        sp300 = (f64) sp90;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
        temp_r4_1334 = var_r22_833 + 0x10;
        temp_r3_1339 = this->unkA8 + temp_r4_1334;
        M2C_FIELD(temp_r3_1339, f64 *, 0) = sp78;
        sp80 = sp480 * 6000.0f;
        sp288 = sp78;
        M2C_FIELD(temp_r3_1339, f64 *, 8) = (f64) sp80;
        sp290 = (f64) sp80;
        temp_r3_1347 = this->unkA8 + temp_r4_1334;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_FIELD(temp_r3_1347, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_1347, f32 *, 8) + arg2.unk8);
        M2C_FIELD((this->unkA8 + var_r22_833), s32 *, 0x28) = var_r29_501;
        if (var_r28_662 != 0) {
            KDSound_Play3d(GS_SpyroBreathIceRico2, (MKVector3 *) &sp488, 0U, -1, 0.0f, 0U);
            sp268.operator*(10.0f);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r3_1382 = this->unkA8 + var_r22_833;
            M2C_FIELD(temp_r3_1382, f64 *, 0) = sp68;
            sp70 = sp490 + sp268.unk8;
            sp278 = sp68;
            M2C_FIELD(temp_r3_1382, f64 *, 8) = (f64) sp70;
            sp280 = (f64) sp70;
            temp_r4_1391 = this->unkA8 + (var_r22_833 + 0x10);
            temp_f2_1392 = M2C_FIELD(temp_r4_1391, f32 *, 0);
            temp_f1_1393 = M2C_FIELD(temp_r4_1391, f32 *, 4);
            temp_f3_1394 = M2C_FIELD(temp_r4_1391, f32 *, 8);
            temp_f4_1399 = (temp_f3_1394 * temp_f3_1394) + ((temp_f2_1392 * temp_f2_1392) + (temp_f1_1393 * temp_f1_1393));
            if (temp_f4_1399 > 0.0f) {
                temp_f1_1402 = __frsqrte(temp_f4_1399);
                temp_f1_1408 = 0.5 * temp_f1_1402 * -(((f64) temp_f4_1399 * (temp_f1_1402 * temp_f1_1402)) - 3.0);
                temp_f1_1412 = 0.5 * temp_f1_1408 * -(((f64) temp_f4_1399 * (temp_f1_1408 * temp_f1_1408)) - 3.0);
                var_f29_1418 = (f32) ((f64) temp_f4_1399 * (0.5 * temp_f1_1412 * -(((f64) temp_f4_1399 * (temp_f1_1412 * temp_f1_1412)) - 3.0)));
            } else if (temp_f4_1399 < M2C_BITWISE(f32, 0.0)) {
                var_f29_1418 = __float_nan;
            } else {
                spC = temp_f4_1399;
                temp_r3_1431 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_1431) {             /* switch 5; irregular */
                case 0x7F800000:                    /* switch 5 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1441 = 1;
                    } else {
                        var_r0_1441 = 2;
                    }
                    break;
                case 0x0:                           /* switch 5 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1441 = 5;
                    } else {
                        var_r0_1441 = 3;
                    }
                    break;
                default:                            /* switch 5 */
                    var_r0_1441 = 4;
                    break;
                }
                if (var_r0_1441 == 1) {
                    var_f29_1418 = __float_nan;
                } else {
                    var_f29_1418 = temp_f4_1399;
                }
            }
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp218, sp208);
            sp228.operator*(1.5f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp238 = sp28;
            sp30 = sp228.unk8 + sp218.unk8;
            sp240 = (f64) sp30;
            Normalise(sp248);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            temp_r4_1503 = var_r22_833 + 0x10;
            temp_r3_1508 = this->unkA8 + temp_r4_1503;
            M2C_FIELD(temp_r3_1508, f64 *, 0) = sp58;
            sp60 = sp248.unk8 * var_f29_1418;
            sp258 = sp58;
            M2C_FIELD(temp_r3_1508, f64 *, 8) = (f64) sp60;
            temp_r5_1514 = this->unkA8;
            sp260 = (f64) sp60;
            if ((s32) M2C_FIELD((temp_r5_1514 + var_r22_833), s32 *, 0x28) >= 3) {
                temp_r5_1520 = temp_r5_1514 + temp_r4_1503;
                temp_f2_1522 = M2C_FIELD(temp_r5_1520, f32 *, 0);
                temp_f1_1523 = M2C_FIELD(temp_r5_1520, f32 *, 4);
                temp_f3_1525 = M2C_FIELD(temp_r5_1520, f32 *, 8);
                var_f4_1529 = (temp_f3_1525 * temp_f3_1525) + ((temp_f2_1522 * temp_f2_1522) + (temp_f1_1523 * temp_f1_1523));
                if (var_f4_1529 > 1e-12f) {
                    if (var_f4_1529 > 0.0f) {
                        temp_f1_1535 = __frsqrte(var_f4_1529);
                        temp_f1_1541 = 0.5 * temp_f1_1535 * -(((f64) var_f4_1529 * (temp_f1_1535 * temp_f1_1535)) - 3.0);
                        temp_f1_1545 = 0.5 * temp_f1_1541 * -(((f64) var_f4_1529 * (temp_f1_1541 * temp_f1_1541)) - 3.0);
                        var_f4_1529 = (f32) ((f64) var_f4_1529 * (0.5 * temp_f1_1545 * -(((f64) var_f4_1529 * (temp_f1_1545 * temp_f1_1545)) - 3.0)));
                    } else if (var_f4_1529 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1529 = __float_nan;
                    } else {
                        sp8 = var_f4_1529;
                        temp_r3_1564 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_1564) {     /* switch 6; irregular */
                        case 0x7F800000:            /* switch 6 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1574 = 1;
                            } else {
                                var_r0_1574 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 6 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1574 = 5;
                            } else {
                                var_r0_1574 = 3;
                            }
                            break;
                        default:                    /* switch 6 */
                            var_r0_1574 = 4;
                            break;
                        }
                        if (var_r0_1574 == 1) {
                            var_f4_1529 = __float_nan;
                        }
                    }
                    var_f4_1596 = 1.0f / var_f4_1529;
                } else {
                    var_f4_1596 = 0.0f;
                }
                sp128 = M2C_FIELD(temp_r5_1520, f32 *, 0) * var_f4_1596;
                sp12C = M2C_FIELD(temp_r5_1520, f32 *, 4) * var_f4_1596;
                sp130 = M2C_FIELD(temp_r5_1520, f32 *, 8) * var_f4_1596;
                sp438 = (f64) sp128;
                sp440 = (f64) sp130;
                SpawnWallIceShard(*((MKVector3 *) &sp488), *((MKVector3 *) &sp438), 1.0f);
            }
        }
        var_r25_1624 = 0;
        do {
            temp_f29_1630 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f26_1635 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp118 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp11C = temp_f26_1635;
            sp120 = temp_f29_1630;
            sp1D8 = (f64) sp118;
            sp1E0 = (f64) sp120;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp1E8 = sp108;
            sp110 = (f32) sp1E0 * 10.0f;
            sp1F0 = (f64) sp110;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp428 = spF8;
            sp100 = M2C_FIELD((this->unkA8 + var_r22_833), f32 *, 8) + (f32) sp1F0;
            sp430 = (f64) sp100;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            temp_f3_1686 = M2C_FIELD((this->unkA8 + (var_r22_833 + 0x10)), f32 *, 8) * MKRand_Float(&gViewSeed, 0.1f, 0.4f);
            sp1C8 = spE8;
            spF0 = temp_f3_1686;
            sp1D0 = (f64) spF0;
            temp_f1_1693 = MKRand_Float(&gViewSeed, 3.0f, 3.5f);
            spD8 = 0.5f;
            spDC = 0.5f;
            sp1C = temp_f1_1693;
            spE0 = 1.0f;
            spE4 = 1.0f;
            sp1B8 = (f64) spD8;
            sp1C0 = (f64) spE0;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp428), *((MKVector3 *) &sp1C8), sp1C, *((MKVector4 *) &sp1B8), 0.0f);
            var_r25_1624 += 1;
        } while (var_r25_1624 < 5);
        M2C_FIELD((this->unkA8 + var_r22_833), f32 *, 0x24) = 0.7f;
        temp_r4_1717 = this->unk168;
        if (temp_r4_1717 != NULL) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1717, 1U);
            temp_r3_1725 = this->unk168;
            temp_r3_1725->unk38 = 500.0f;
            temp_r3_1728 = temp_r3_1725->unk3C;
            if (temp_r3_1728 != NULL) {
                M2C_FIELD(temp_r3_1728, f32 *, 0x20) = 500.0f;
                M2C_FIELD(temp_r3_1728, f32 *, 0x24) = 250000.0f;
                M2C_FIELD(temp_r3_1728, f32 *, 0x28) = 0.002f;
                M2C_FIELD(temp_r3_1728, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1728, f32 *, 0x24));
            }
            sp48 = 0.3f;
            temp_r3_1744 = this->unk168;
            sp4C = 0.3f;
            sp50 = 1.0f;
            sp54 = 1.0f;
            temp_r3_1744->unk20 = (f64) sp48;
            temp_r3_1744->unk28 = (f64) sp50;
            temp_r3_1752 = temp_r3_1744->unk3C;
            sp1A8 = (f64) sp48;
            sp1B0 = (f64) sp50;
            if (temp_r3_1752 != NULL) {
                M2C_FIELD(temp_r3_1752, f64 *, 0) = (f64) sp48;
                M2C_FIELD(temp_r3_1752, f64 *, 8) = (f64) sp50;
            }
            temp_r3_1761 = this->unk168;
            temp_r4_1762 = this->unkA8 + var_r22_833;
            temp_r3_1761->unk10 = M2C_FIELD(temp_r4_1762, f64 *, 0);
            temp_r3_1761->unk18 = M2C_FIELD(temp_r4_1762, f64 *, 8);
            temp_r3_1767 = temp_r3_1761->unk3C;
            if (temp_r3_1767 != NULL) {
                M2C_FIELD(temp_r3_1767, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_1762, f64 *, 0);
                M2C_FIELD(temp_r3_1767, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_1762, f64 *, 8);
            }
            this->unk16C = 0.05f;
        }
        return 1U;
    }
    var_r22_833 += 0x30;
    var_ctr_834 -= 1;
    if (var_ctr_834 == 0) {
        return 0U;
    }
    goto loop_39;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const int *' to
u8 IceBreathFX::Trigger(MKProp *arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, const float &arg4, const int &arg5) {
    f32 temp_f28_3324;
    f32 temp_f30_2493;
    f32 temp_f30_2909;
    f32 temp_f31_3460;
    f32 var_f1_1852;
    f32 var_f3_2174;
    f32 var_f3_2378;
    f32 var_f3_2588;
    f32 var_f3_2793;
    f32 var_f3_3004;
    f32 var_f3_3209;
    f32 var_f4_2107;
    f32 var_f4_2311;
    f32 var_f4_2521;
    f32 var_f4_2726;
    f32 var_f4_2937;
    f32 var_f4_3142;
    f64 temp_f1_2113;
    f64 temp_f1_2119;
    f64 temp_f1_2123;
    f64 temp_f1_2317;
    f64 temp_f1_2323;
    f64 temp_f1_2327;
    f64 temp_f1_2527;
    f64 temp_f1_2533;
    f64 temp_f1_2537;
    f64 temp_f1_2732;
    f64 temp_f1_2738;
    f64 temp_f1_2742;
    f64 temp_f1_2943;
    f64 temp_f1_2949;
    f64 temp_f1_2953;
    f64 temp_f1_3148;
    f64 temp_f1_3154;
    f64 temp_f1_3158;
    s32 temp_r0_1839;
    s32 temp_r0_1891;
    s32 temp_r0_1978;
    s32 temp_r25_3532;
    s32 temp_r26_3535;
    s32 temp_r3_1889;
    s32 temp_r3_1944;
    s32 temp_r3_1976;
    s32 temp_r3_2142;
    s32 temp_r3_2346;
    s32 temp_r3_2556;
    s32 temp_r3_2761;
    s32 temp_r3_2972;
    s32 temp_r3_3177;
    s32 temp_r4_3533;
    s32 temp_r5_1865;
    s32 temp_r5_1946;
    s32 temp_r6_1863;
    s32 var_r0_1907;
    s32 var_r0_1994;
    s32 var_r0_2152;
    s32 var_r0_2356;
    s32 var_r0_2566;
    s32 var_r0_2771;
    s32 var_r0_2982;
    s32 var_r0_3187;
    s32 var_r24_3570;
    s32 var_r25_1853;
    s32 var_r6_1881;
    s32 var_r6_1962;
    s32 var_r6_3551;
    u8 var_r3_1897;
    u8 var_r3_1952;
    u8 var_r3_1984;
    u8 var_r3_3596;
    u8 var_r4_3541;
    u8 var_r4_3560;
    u8 var_r6_1871;
    void *temp_r24_3422;
    void *temp_r3_3417;
    void *temp_r4_1893;
    void *temp_r4_1948;
    void *temp_r4_1980;
    void *temp_r4_3602;
    void *temp_r5_3537;
    void *temp_r7_1867;
    this->unkB0 = &arg5;
    temp_r0_1839 = this->unkB0;
    switch (temp_r0_1839) {                         /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_f1_1852 = 0.0f;
        var_r25_1853 = 0;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(this, f32 *, 0x1A4) == 0.0f) {
            temp_r6_1863 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
            temp_r5_1865 = *(&GameData::gameData[0x70] + (temp_r6_1863 + 0x7C));
            temp_r7_1867 = &GameData::gameData[0x70] + (temp_r6_1863 + 0x64);
            if (temp_r5_1865 == 3) {
                var_r6_1871 = 0;
                if (((s32) M2C_FIELD(temp_r7_1867, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r7_1867, s32 *, 4) == 3)) {
                    var_r6_1871 = 1;
                }
                var_r6_1881 = var_r6_1871 != 0;
            } else {
                var_r6_1881 = *(temp_r7_1867 + (temp_r5_1865 * 4));
            }
            var_f1_1852 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(M2C_FIELD(GameData::gameData, s32 *, 0x158), temp_r5_1865, var_r6_1881);
            temp_r3_1889 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
            temp_r0_1891 = *(&GameData::gameData[0x70] + (temp_r3_1889 + 0x7C));
            temp_r4_1893 = &GameData::gameData[0x70] + (temp_r3_1889 + 0x64);
            if (temp_r0_1891 == 3) {
                var_r3_1897 = 0;
                if (((s32) M2C_FIELD(temp_r4_1893, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1893, s32 *, 4) == 3)) {
                    var_r3_1897 = 1;
                }
                var_r0_1907 = var_r3_1897 != 0;
            } else {
                var_r0_1907 = *(temp_r4_1893 + (temp_r0_1891 * 4));
            }
            switch (var_r0_1907) {                  /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                M2C_FIELD(this, f32 *, 0x1A4) = 0.125f;
                break;
            case 1:                                 /* switch 2 */
                M2C_FIELD(this, f32 *, 0x1A4) = 0.125f;
                break;
            case 2:                                 /* switch 2 */
                M2C_FIELD(this, f32 *, 0x1A4) = 0.125f;
                break;
            case 3:                                 /* switch 2 */
                M2C_FIELD(this, f32 *, 0x1A4) = 0.125f;
                break;
            }
        }
        temp_r3_1944 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r5_1946 = *(&GameData::gameData[0x70] + (temp_r3_1944 + 0x7C));
        temp_r4_1948 = &GameData::gameData[0x70] + (temp_r3_1944 + 0x64);
        if (temp_r5_1946 == 3) {
            var_r3_1952 = 0;
            if (((s32) M2C_FIELD(temp_r4_1948, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1948, s32 *, 4) == 3)) {
                var_r3_1952 = 1;
            }
            var_r6_1962 = var_r3_1952 != 0;
        } else {
            var_r6_1962 = *(temp_r4_1948 + (temp_r5_1946 * 4));
        }
        this->unk110.Init(arg0, var_f1_1852, temp_r5_1946, var_r6_1962, M2C_FIELD(GameData::gameData, s32 *, 0x158), M2C_FIELD(GameData::gameData, s32 *, 0x158), 0, -1);
        temp_r3_1976 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_1978 = *(&GameData::gameData[0x70] + (temp_r3_1976 + 0x7C));
        temp_r4_1980 = &GameData::gameData[0x70] + (temp_r3_1976 + 0x64);
        if (temp_r0_1978 == 3) {
            var_r3_1984 = 0;
            if (((s32) M2C_FIELD(temp_r4_1980, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1980, s32 *, 4) == 3)) {
                var_r3_1984 = 1;
            }
            var_r0_1994 = var_r3_1984 != 0;
        } else {
            var_r0_1994 = *(temp_r4_1980 + (temp_r0_1978 * 4));
        }
        switch (var_r0_1994) {                      /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            arg_sp2D8 = 0.0f;
            arg_sp2DC = 0.5f;
            arg_sp2E0 = 0.0f;
            arg_sp668 = (f64) arg_sp2D8;
            arg_sp670 = (f64) arg_sp2E0;
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            arg_sp678 = arg_sp2C8;
            arg_sp2D0 = arg2.unk8 + (f32) arg_sp670;
            arg_sp680 = (f64) arg_sp2D0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp2A0 = 1.75f;
            arg_sp2C0 = (f32) arg_sp680 * 1500.0f;
            arg_sp298 = 0.75f;
            arg_sp29C = 0.75f;
            arg_sp6B8 = arg_sp2B8;
            arg_sp6C0 = (f64) arg_sp2C0;
            arg_sp648 = (f64) arg_sp298;
            arg_sp650 = (f64) arg_sp2A0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            arg_sp658 = arg_sp2A8;
            arg_sp2B0 = (f32) arg_sp6C0 + arg3.unk8;
            arg_sp660 = (f64) arg_sp2B0;
            arg_sp8 = 0;
            arg_spC = 0;
            var_r25_1853 = this->unk178->Emit(lit_872, arg1, *((MKVector3 *) &arg_sp658), *((MKVector3 *) &arg_sp648), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            break;
        case 1:                                     /* switch 3 */
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp6A8 = arg_sp1A8;
            arg_sp1B0 = arg2.unk8 + arg_sp630;
            arg_sp6B0 = (f64) arg_sp1B0;
            arg_sp638 = arg_sp1A8;
            arg_sp640 = (f64) arg_sp1B0;
            var_f4_2107 = ((f32) arg_sp6B0 * (f32) arg_sp6B0) + (((f32) arg_sp6A8 * (f32) arg_sp6A8) + (arg_sp6AC * arg_sp6AC));
            if (var_f4_2107 > 0.000001f) {
                if (var_f4_2107 > 0.0f) {
                    temp_f1_2113 = __frsqrte(var_f4_2107);
                    temp_f1_2119 = 0.5 * temp_f1_2113 * -(((f64) var_f4_2107 * (temp_f1_2113 * temp_f1_2113)) - 3.0);
                    temp_f1_2123 = 0.5 * temp_f1_2119 * -(((f64) var_f4_2107 * (temp_f1_2119 * temp_f1_2119)) - 3.0);
                    var_f4_2107 = (f32) ((f64) var_f4_2107 * (0.5 * temp_f1_2123 * -(((f64) var_f4_2107 * (temp_f1_2123 * temp_f1_2123)) - 3.0)));
                } else if (var_f4_2107 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2107 = __float_nan;
                } else {
                    arg_sp24 = var_f4_2107;
                    temp_r3_2142 = M2C_BITWISE(s32, arg_sp24) & 0x7F800000;
                    switch (temp_r3_2142) {         /* switch 4; irregular */
                    case 0x7F800000:                /* switch 4 */
                        if (M2C_BITWISE(s32, arg_sp24) & 0x7FFFFF) {
                            var_r0_2152 = 1;
                        } else {
                            var_r0_2152 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 4 */
                        if (M2C_BITWISE(s32, arg_sp24) & 0x7FFFFF) {
                            var_r0_2152 = 5;
                        } else {
                            var_r0_2152 = 3;
                        }
                        break;
                    default:                        /* switch 4 */
                        var_r0_2152 = 4;
                        break;
                    }
                    if (var_r0_2152 == 1) {
                        var_f4_2107 = __float_nan;
                    }
                }
                var_f3_2174 = 1.0f / var_f4_2107;
            } else {
                var_f3_2174 = 0.0f;
            }
            arg_sp6A8 = (f32) arg_sp6A8 * var_f3_2174;
            arg_sp6AC *= var_f3_2174;
            arg_sp6B0 = (f32) arg_sp6B0 * var_f3_2174;
            M2C_STRUCT_COPY((s32) &arg_sp74C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp750.SetRotationYaw(0.2617994f);
            arg_spB8 = arg_sp780 + (((f32) arg_sp6B0 * arg_sp770) + (((f32) arg_sp6A8 * arg_sp750) + (arg_sp6AC * arg_sp760)));
            arg_spBC = arg_sp784 + (((f32) arg_sp6B0 * arg_sp774) + (((f32) arg_sp6A8 * arg_sp754) + (arg_sp6AC * arg_sp764)));
            arg_spC0 = arg_sp788 + (((f32) arg_sp6B0 * arg_sp778) + (((f32) arg_sp6A8 * arg_sp758) + (arg_sp6AC * arg_sp768)));
            arg_sp608 = (f64) arg_spB8;
            arg_sp610 = (f64) arg_spC0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp278 = 0.75f;
            arg_sp27C = 0.75f;
            arg_sp1A0 = (f32) arg_sp610 * 1500.0f;
            arg_sp280 = 1.75f;
            arg_sp6A8 = arg_sp198;
            arg_sp618 = arg_sp198;
            arg_sp620 = (f64) arg_sp1A0;
            arg_sp6B0 = (f64) arg_sp1A0;
            arg_sp5E8 = (f64) arg_sp278;
            arg_sp5F0 = (f64) arg_sp280;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp5F8 = arg_sp288;
            arg_sp290 = (f32) arg_sp6B0 + arg3.unk8;
            arg_sp600 = (f64) arg_sp290;
            arg_sp8 = 0;
            arg_spC = 0;
            this->unk178->Emit(lit_875, arg1, *((MKVector3 *) &arg_sp5F8), *((MKVector3 *) &arg_sp5E8), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp6A8 = arg_sp188;
            arg_sp190 = arg2.unk8 + arg_sp5D0;
            arg_sp6B0 = (f64) arg_sp190;
            arg_sp5D8 = arg_sp188;
            arg_sp5E0 = (f64) arg_sp190;
            var_f4_2311 = ((f32) arg_sp6B0 * (f32) arg_sp6B0) + (((f32) arg_sp6A8 * (f32) arg_sp6A8) + (arg_sp6AC * arg_sp6AC));
            if (var_f4_2311 > 0.000001f) {
                if (var_f4_2311 > 0.0f) {
                    temp_f1_2317 = __frsqrte(var_f4_2311);
                    temp_f1_2323 = 0.5 * temp_f1_2317 * -(((f64) var_f4_2311 * (temp_f1_2317 * temp_f1_2317)) - 3.0);
                    temp_f1_2327 = 0.5 * temp_f1_2323 * -(((f64) var_f4_2311 * (temp_f1_2323 * temp_f1_2323)) - 3.0);
                    var_f4_2311 = (f32) ((f64) var_f4_2311 * (0.5 * temp_f1_2327 * -(((f64) var_f4_2311 * (temp_f1_2327 * temp_f1_2327)) - 3.0)));
                } else if (var_f4_2311 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2311 = __float_nan;
                } else {
                    arg_sp20 = var_f4_2311;
                    temp_r3_2346 = M2C_BITWISE(s32, arg_sp20) & 0x7F800000;
                    switch (temp_r3_2346) {         /* switch 5; irregular */
                    case 0x7F800000:                /* switch 5 */
                        if (M2C_BITWISE(s32, arg_sp20) & 0x7FFFFF) {
                            var_r0_2356 = 1;
                        } else {
                            var_r0_2356 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 5 */
                        if (M2C_BITWISE(s32, arg_sp20) & 0x7FFFFF) {
                            var_r0_2356 = 5;
                        } else {
                            var_r0_2356 = 3;
                        }
                        break;
                    default:                        /* switch 5 */
                        var_r0_2356 = 4;
                        break;
                    }
                    if (var_r0_2356 == 1) {
                        var_f4_2311 = __float_nan;
                    }
                }
                var_f3_2378 = 1.0f / var_f4_2311;
            } else {
                var_f3_2378 = 0.0f;
            }
            arg_sp6A8 = (f32) arg_sp6A8 * var_f3_2378;
            arg_sp6AC *= var_f3_2378;
            arg_sp6B0 = (f32) arg_sp6B0 * var_f3_2378;
            M2C_STRUCT_COPY((s32) &arg_sp74C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp750.SetRotationYaw(-0.2617994f);
            arg_spA8 = arg_sp780 + (((f32) arg_sp6B0 * arg_sp770) + (((f32) arg_sp6A8 * arg_sp750) + (arg_sp6AC * arg_sp760)));
            arg_spAC = arg_sp784 + (((f32) arg_sp6B0 * arg_sp774) + (((f32) arg_sp6A8 * arg_sp754) + (arg_sp6AC * arg_sp764)));
            arg_spB0 = arg_sp788 + (((f32) arg_sp6B0 * arg_sp778) + (((f32) arg_sp6A8 * arg_sp758) + (arg_sp6AC * arg_sp768)));
            arg_sp5A8 = (f64) arg_spA8;
            arg_sp5B0 = (f64) arg_spB0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            arg_sp258 = 0.75f;
            arg_sp25C = 0.75f;
            arg_sp180 = (f32) arg_sp5B0 * 1500.0f;
            arg_sp260 = 1.75f;
            arg_sp6A8 = arg_sp178;
            arg_sp5B8 = arg_sp178;
            arg_sp5C0 = (f64) arg_sp180;
            arg_sp6B0 = (f64) arg_sp180;
            arg_sp588 = (f64) arg_sp258;
            arg_sp590 = (f64) arg_sp260;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp598 = arg_sp268;
            arg_sp270 = (f32) arg_sp6B0 + arg3.unk8;
            arg_sp5A0 = (f64) arg_sp270;
            arg_sp8 = 0;
            arg_spC = 0;
            var_r25_1853 = this->unk17C->Emit(lit_877, arg1, *((MKVector3 *) &arg_sp598), *((MKVector3 *) &arg_sp588), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            break;
        case 2:                                     /* switch 3 */
            temp_f30_2493 = _table_sinf(M2C_BITWISE(f32, this->unk184));
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp698 = arg_sp168;
            arg_sp170 = arg2.unk8 + arg_sp570;
            arg_sp6A0 = (f64) arg_sp170;
            arg_sp578 = arg_sp168;
            arg_sp580 = (f64) arg_sp170;
            var_f4_2521 = ((f32) arg_sp6A0 * (f32) arg_sp6A0) + (((f32) arg_sp698 * (f32) arg_sp698) + (arg_sp69C * arg_sp69C));
            if (var_f4_2521 > 0.000001f) {
                if (var_f4_2521 > 0.0f) {
                    temp_f1_2527 = __frsqrte(var_f4_2521);
                    temp_f1_2533 = 0.5 * temp_f1_2527 * -(((f64) var_f4_2521 * (temp_f1_2527 * temp_f1_2527)) - 3.0);
                    temp_f1_2537 = 0.5 * temp_f1_2533 * -(((f64) var_f4_2521 * (temp_f1_2533 * temp_f1_2533)) - 3.0);
                    var_f4_2521 = (f32) ((f64) var_f4_2521 * (0.5 * temp_f1_2537 * -(((f64) var_f4_2521 * (temp_f1_2537 * temp_f1_2537)) - 3.0)));
                } else if (var_f4_2521 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2521 = __float_nan;
                } else {
                    arg_sp1C = var_f4_2521;
                    temp_r3_2556 = M2C_BITWISE(s32, arg_sp1C) & 0x7F800000;
                    switch (temp_r3_2556) {         /* switch 6; irregular */
                    case 0x7F800000:                /* switch 6 */
                        if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                            var_r0_2566 = 1;
                        } else {
                            var_r0_2566 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 6 */
                        if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                            var_r0_2566 = 5;
                        } else {
                            var_r0_2566 = 3;
                        }
                        break;
                    default:                        /* switch 6 */
                        var_r0_2566 = 4;
                        break;
                    }
                    if (var_r0_2566 == 1) {
                        var_f4_2521 = __float_nan;
                    }
                }
                var_f3_2588 = 1.0f / var_f4_2521;
            } else {
                var_f3_2588 = 0.0f;
            }
            arg_sp698 = (f32) arg_sp698 * var_f3_2588;
            arg_sp69C *= var_f3_2588;
            arg_sp6A0 = (f32) arg_sp6A0 * var_f3_2588;
            M2C_STRUCT_COPY((s32) &arg_sp70C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp710.SetRotationYaw(temp_f30_2493 * 0.61086524f);
            arg_sp98 = arg_sp740 + (((f32) arg_sp6A0 * arg_sp730) + (((f32) arg_sp698 * arg_sp710) + (arg_sp69C * arg_sp720)));
            arg_sp9C = arg_sp744 + (((f32) arg_sp6A0 * arg_sp734) + (((f32) arg_sp698 * arg_sp714) + (arg_sp69C * arg_sp724)));
            arg_spA0 = arg_sp748 + (((f32) arg_sp6A0 * arg_sp738) + (((f32) arg_sp698 * arg_sp718) + (arg_sp69C * arg_sp728)));
            arg_sp548 = (f64) arg_sp98;
            arg_sp550 = (f64) arg_spA0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            arg_sp238 = 0.75f;
            arg_sp23C = 0.75f;
            arg_sp160 = (f32) arg_sp550 * 1500.0f;
            arg_sp240 = 1.75f;
            arg_sp698 = arg_sp158;
            arg_sp558 = arg_sp158;
            arg_sp560 = (f64) arg_sp160;
            arg_sp6A0 = (f64) arg_sp160;
            arg_sp528 = (f64) arg_sp238;
            arg_sp530 = (f64) arg_sp240;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp538 = arg_sp248;
            arg_sp250 = (f32) arg_sp6A0 + arg3.unk8;
            arg_sp540 = (f64) arg_sp250;
            arg_sp8 = 0;
            arg_spC = 0;
            this->unk178->Emit(lit_880, arg1, *((MKVector3 *) &arg_sp538), *((MKVector3 *) &arg_sp528), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp698 = arg_sp148;
            arg_sp150 = arg2.unk8 + arg_sp510;
            arg_sp6A0 = (f64) arg_sp150;
            arg_sp518 = arg_sp148;
            arg_sp520 = (f64) arg_sp150;
            var_f4_2726 = ((f32) arg_sp6A0 * (f32) arg_sp6A0) + (((f32) arg_sp698 * (f32) arg_sp698) + (arg_sp69C * arg_sp69C));
            if (var_f4_2726 > 0.000001f) {
                if (var_f4_2726 > 0.0f) {
                    temp_f1_2732 = __frsqrte(var_f4_2726);
                    temp_f1_2738 = 0.5 * temp_f1_2732 * -(((f64) var_f4_2726 * (temp_f1_2732 * temp_f1_2732)) - 3.0);
                    temp_f1_2742 = 0.5 * temp_f1_2738 * -(((f64) var_f4_2726 * (temp_f1_2738 * temp_f1_2738)) - 3.0);
                    var_f4_2726 = (f32) ((f64) var_f4_2726 * (0.5 * temp_f1_2742 * -(((f64) var_f4_2726 * (temp_f1_2742 * temp_f1_2742)) - 3.0)));
                } else if (var_f4_2726 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2726 = __float_nan;
                } else {
                    arg_sp18 = var_f4_2726;
                    temp_r3_2761 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                    switch (temp_r3_2761) {         /* switch 7; irregular */
                    case 0x7F800000:                /* switch 7 */
                        if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                            var_r0_2771 = 1;
                        } else {
                            var_r0_2771 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 7 */
                        if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                            var_r0_2771 = 5;
                        } else {
                            var_r0_2771 = 3;
                        }
                        break;
                    default:                        /* switch 7 */
                        var_r0_2771 = 4;
                        break;
                    }
                    if (var_r0_2771 == 1) {
                        var_f4_2726 = __float_nan;
                    }
                }
                var_f3_2793 = 1.0f / var_f4_2726;
            } else {
                var_f3_2793 = 0.0f;
            }
            arg_sp698 = (f32) arg_sp698 * var_f3_2793;
            arg_sp69C *= var_f3_2793;
            arg_sp6A0 = (f32) arg_sp6A0 * var_f3_2793;
            M2C_STRUCT_COPY((s32) &arg_sp70C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp710.SetRotationYaw(temp_f30_2493 * -0.61086524f);
            arg_sp88 = arg_sp740 + (((f32) arg_sp6A0 * arg_sp730) + (((f32) arg_sp698 * arg_sp710) + (arg_sp69C * arg_sp720)));
            arg_sp8C = arg_sp744 + (((f32) arg_sp6A0 * arg_sp734) + (((f32) arg_sp698 * arg_sp714) + (arg_sp69C * arg_sp724)));
            arg_sp90 = arg_sp748 + (((f32) arg_sp6A0 * arg_sp738) + (((f32) arg_sp698 * arg_sp718) + (arg_sp69C * arg_sp728)));
            arg_sp4E8 = (f64) arg_sp88;
            arg_sp4F0 = (f64) arg_sp90;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            arg_sp218 = 0.75f;
            arg_sp21C = 0.75f;
            arg_sp140 = (f32) arg_sp4F0 * 1500.0f;
            arg_sp220 = 1.75f;
            arg_sp698 = arg_sp138;
            arg_sp4F8 = arg_sp138;
            arg_sp500 = (f64) arg_sp140;
            arg_sp6A0 = (f64) arg_sp140;
            arg_sp4C8 = (f64) arg_sp218;
            arg_sp4D0 = (f64) arg_sp220;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp4D8 = arg_sp228;
            arg_sp230 = (f32) arg_sp6A0 + arg3.unk8;
            arg_sp4E0 = (f64) arg_sp230;
            arg_sp8 = 0;
            arg_spC = 0;
            var_r25_1853 = this->unk17C->Emit(lit_882, arg1, *((MKVector3 *) &arg_sp4D8), *((MKVector3 *) &arg_sp4C8), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            break;
        case 3:                                     /* switch 3 */
            temp_f30_2909 = _table_sinf(M2C_BITWISE(f32, this->unk184));
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp688 = arg_sp128;
            arg_sp130 = arg2.unk8 + arg_sp4B0;
            arg_sp690 = (f64) arg_sp130;
            arg_sp4B8 = arg_sp128;
            arg_sp4C0 = (f64) arg_sp130;
            var_f4_2937 = ((f32) arg_sp690 * (f32) arg_sp690) + (((f32) arg_sp688 * (f32) arg_sp688) + (arg_sp68C * arg_sp68C));
            if (var_f4_2937 > 0.000001f) {
                if (var_f4_2937 > 0.0f) {
                    temp_f1_2943 = __frsqrte(var_f4_2937);
                    temp_f1_2949 = 0.5 * temp_f1_2943 * -(((f64) var_f4_2937 * (temp_f1_2943 * temp_f1_2943)) - 3.0);
                    temp_f1_2953 = 0.5 * temp_f1_2949 * -(((f64) var_f4_2937 * (temp_f1_2949 * temp_f1_2949)) - 3.0);
                    var_f4_2937 = (f32) ((f64) var_f4_2937 * (0.5 * temp_f1_2953 * -(((f64) var_f4_2937 * (temp_f1_2953 * temp_f1_2953)) - 3.0)));
                } else if (var_f4_2937 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2937 = __float_nan;
                } else {
                    arg_sp14 = var_f4_2937;
                    temp_r3_2972 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                    switch (temp_r3_2972) {         /* switch 8; irregular */
                    case 0x7F800000:                /* switch 8 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                            var_r0_2982 = 1;
                        } else {
                            var_r0_2982 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 8 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                            var_r0_2982 = 5;
                        } else {
                            var_r0_2982 = 3;
                        }
                        break;
                    default:                        /* switch 8 */
                        var_r0_2982 = 4;
                        break;
                    }
                    if (var_r0_2982 == 1) {
                        var_f4_2937 = __float_nan;
                    }
                }
                var_f3_3004 = 1.0f / var_f4_2937;
            } else {
                var_f3_3004 = 0.0f;
            }
            arg_sp688 = (f32) arg_sp688 * var_f3_3004;
            arg_sp68C *= var_f3_3004;
            arg_sp690 = (f32) arg_sp690 * var_f3_3004;
            M2C_STRUCT_COPY((s32) &arg_sp6CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp6D0.SetRotationYaw(temp_f30_2909 * 0.61086524f);
            arg_sp78 = arg_sp700 + (((f32) arg_sp690 * arg_sp6F0) + (((f32) arg_sp688 * arg_sp6D0) + (arg_sp68C * arg_sp6E0)));
            arg_sp7C = arg_sp704 + (((f32) arg_sp690 * arg_sp6F4) + (((f32) arg_sp688 * arg_sp6D4) + (arg_sp68C * arg_sp6E4)));
            arg_sp80 = arg_sp708 + (((f32) arg_sp690 * arg_sp6F8) + (((f32) arg_sp688 * arg_sp6D8) + (arg_sp68C * arg_sp6E8)));
            arg_sp488 = (f64) arg_sp78;
            arg_sp490 = (f64) arg_sp80;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            arg_sp1F8 = 0.75f;
            arg_sp1FC = 0.75f;
            arg_sp120 = (f32) arg_sp490 * 1500.0f;
            arg_sp200 = 1.75f;
            arg_sp688 = arg_sp118;
            arg_sp498 = arg_sp118;
            arg_sp4A0 = (f64) arg_sp120;
            arg_sp690 = (f64) arg_sp120;
            arg_sp468 = (f64) arg_sp1F8;
            arg_sp470 = (f64) arg_sp200;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp478 = arg_sp208;
            arg_sp210 = (f32) arg_sp690 + arg3.unk8;
            arg_sp480 = (f64) arg_sp210;
            arg_sp8 = 0;
            arg_spC = 0;
            this->unk178->Emit(lit_885, arg1, *((MKVector3 *) &arg_sp478), *((MKVector3 *) &arg_sp468), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp688 = arg_sp108;
            arg_sp110 = arg2.unk8 + arg_sp450;
            arg_sp690 = (f64) arg_sp110;
            arg_sp458 = arg_sp108;
            arg_sp460 = (f64) arg_sp110;
            var_f4_3142 = ((f32) arg_sp690 * (f32) arg_sp690) + (((f32) arg_sp688 * (f32) arg_sp688) + (arg_sp68C * arg_sp68C));
            if (var_f4_3142 > 0.000001f) {
                if (var_f4_3142 > 0.0f) {
                    temp_f1_3148 = __frsqrte(var_f4_3142);
                    temp_f1_3154 = 0.5 * temp_f1_3148 * -(((f64) var_f4_3142 * (temp_f1_3148 * temp_f1_3148)) - 3.0);
                    temp_f1_3158 = 0.5 * temp_f1_3154 * -(((f64) var_f4_3142 * (temp_f1_3154 * temp_f1_3154)) - 3.0);
                    var_f4_3142 = (f32) ((f64) var_f4_3142 * (0.5 * temp_f1_3158 * -(((f64) var_f4_3142 * (temp_f1_3158 * temp_f1_3158)) - 3.0)));
                } else if (var_f4_3142 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_3142 = __float_nan;
                } else {
                    arg_sp10 = var_f4_3142;
                    temp_r3_3177 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_3177) {         /* switch 9; irregular */
                    case 0x7F800000:                /* switch 9 */
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_3187 = 1;
                        } else {
                            var_r0_3187 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 9 */
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_3187 = 5;
                        } else {
                            var_r0_3187 = 3;
                        }
                        break;
                    default:                        /* switch 9 */
                        var_r0_3187 = 4;
                        break;
                    }
                    if (var_r0_3187 == 1) {
                        var_f4_3142 = __float_nan;
                    }
                }
                var_f3_3209 = 1.0f / var_f4_3142;
            } else {
                var_f3_3209 = 0.0f;
            }
            arg_sp688 = (f32) arg_sp688 * var_f3_3209;
            arg_sp68C *= var_f3_3209;
            arg_sp690 = (f32) arg_sp690 * var_f3_3209;
            M2C_STRUCT_COPY((s32) &arg_sp6CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp6D0.SetRotationYaw(temp_f30_2909 * -0.61086524f);
            arg_sp68 = arg_sp700 + (((f32) arg_sp690 * arg_sp6F0) + (((f32) arg_sp688 * arg_sp6D0) + (arg_sp68C * arg_sp6E0)));
            arg_sp6C = arg_sp704 + (((f32) arg_sp690 * arg_sp6F4) + (((f32) arg_sp688 * arg_sp6D4) + (arg_sp68C * arg_sp6E4)));
            arg_sp70 = arg_sp708 + (((f32) arg_sp690 * arg_sp6F8) + (((f32) arg_sp688 * arg_sp6D8) + (arg_sp68C * arg_sp6E8)));
            arg_sp428 = (f64) arg_sp68;
            arg_sp430 = (f64) arg_sp70;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            arg_sp1D8 = 0.75f;
            arg_sp1DC = 0.75f;
            arg_sp100 = (f32) arg_sp430 * 1500.0f;
            arg_sp1E0 = 1.75f;
            arg_sp688 = arg_spF8;
            arg_sp438 = arg_spF8;
            arg_sp440 = (f64) arg_sp100;
            arg_sp690 = (f64) arg_sp100;
            arg_sp408 = (f64) arg_sp1D8;
            arg_sp410 = (f64) arg_sp1E0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp418 = arg_sp1E8;
            arg_sp1F0 = (f32) arg_sp690 + arg3.unk8;
            arg_sp420 = (f64) arg_sp1F0;
            arg_sp8 = 0;
            arg_spC = 0;
            this->unk17C->Emit(lit_887, arg1, *((MKVector3 *) &arg_sp418), *((MKVector3 *) &arg_sp408), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            temp_f28_3324 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), 0.0f, temp_f28_3324);
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp3D8 = arg_sp58;
            arg_sp60 = arg2.unk8 + arg_sp3D0;
            arg_sp3E0 = (f64) arg_sp60;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp3E8 = arg_sp48;
            arg_sp50 = (f32) arg_sp3E0 + arg_sp3C0;
            arg_sp3F0 = (f64) arg_sp50;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            arg_sp1B8 = 0.75f;
            arg_sp1BC = 0.75f;
            arg_spF0 = (f32) arg_sp3F0 * 1500.0f;
            arg_sp1C0 = 1.75f;
            arg_sp688 = arg_spE8;
            arg_sp3F8 = arg_spE8;
            arg_sp400 = (f64) arg_spF0;
            arg_sp690 = (f64) arg_spF0;
            arg_sp398 = (f64) arg_sp1B8;
            arg_sp3A0 = (f64) arg_sp1C0;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp3A8 = arg_sp1C8;
            arg_sp1D0 = (f32) arg_sp690 + arg3.unk8;
            arg_sp3B0 = (f64) arg_sp1D0;
            arg_sp8 = 0;
            arg_spC = 0;
            var_r25_1853 = this->unk180->Emit(lit_889, arg1, *((MKVector3 *) &arg_sp3A8), *((MKVector3 *) &arg_sp398), 1.5f, 0.0f, 0U, (BreathHitMessage *) &this->unk110, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            break;
        }
        temp_r3_3417 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0));
        if (temp_r3_3417 != NULL) {
            temp_r24_3422 = M2C_FIELD(temp_r3_3417, void **, 0x2C);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp368), *((MKVector3 *) &arg_sp358));
            arg_sp378.operator*(5.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(temp_r3_3417, f64 *, 0) = arg_spD8;
            arg_spE0 = arg1.unk8 + arg_sp380;
            arg_sp388 = arg_spD8;
            M2C_FIELD(temp_r3_3417, f64 *, 8) = (f64) arg_spE0;
            M2C_FIELD(temp_r3_3417, f32 *, 0x20) = 0.0f;
            arg_sp390 = (f64) arg_spE0;
            M2C_FIELD(temp_r3_3417, f32 *, 0x28) = 0.0f;
            temp_f31_3460 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            MKVector(0.0f, 0.5f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp2F8 = arg_sp38;
            arg_sp40 = arg2.unk8 + arg_sp2F0;
            arg_sp300 = (f64) arg_sp40;
            arg_sp308.operator*(1500.0f);
            arg_sp318.operator*(0.5f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp328 = arg_sp28;
            arg_sp30 = arg_sp320 + arg3.unk8;
            arg_sp330 = (f64) arg_sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_FIELD(temp_r24_3422, f64 *, 0) = arg_spC8;
            arg_spD0 = (f32) arg_sp330 * temp_f31_3460;
            arg_sp338 = arg_spC8;
            arg_sp340 = (f64) arg_spD0;
            M2C_FIELD(temp_r24_3422, f64 *, 8) = (f64) arg_spD0;
            M2C_FIELD(temp_r24_3422, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.125f, 0.5f);
            M2C_FIELD(temp_r24_3422, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
            M2C_FIELD(temp_r24_3422, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
        }
        M2C_FIELD(this, s8 *, 0x19C) = (s8) var_r25_1853;
        return (u8) var_r25_1853;
    case 1:                                         /* switch 1 */
        temp_r25_3532 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
        temp_r4_3533 = temp_r25_3532 << 5;
        temp_r26_3535 = *(&GameData::gameData[0x70] + (temp_r4_3533 + 0x7C));
        temp_r5_3537 = &GameData::gameData[0x70] + (temp_r4_3533 + 0x64);
        if (temp_r26_3535 == 3) {
            var_r4_3541 = 0;
            if (((s32) M2C_FIELD(temp_r5_3537, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_3537, s32 *, 4) == 3)) {
                var_r4_3541 = 1;
            }
            var_r6_3551 = var_r4_3541 != 0;
        } else {
            var_r6_3551 = *(temp_r5_3537 + (temp_r26_3535 * 4));
        }
        if (temp_r26_3535 == 3) {
            var_r4_3560 = 0;
            if (((s32) M2C_FIELD(temp_r5_3537, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_3537, s32 *, 4) == 3)) {
                var_r4_3560 = 1;
            }
            var_r24_3570 = var_r4_3560 != 0;
        } else {
            var_r24_3570 = *(temp_r5_3537 + (temp_r26_3535 * 4));
        }
        this->unkB8.Init(arg0, ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(temp_r25_3532, temp_r26_3535, var_r6_3551), temp_r26_3535, var_r24_3570, temp_r25_3532, temp_r25_3532, 0, -1);
        return ShootIceShard(arg1, arg2, arg3);
    case 3:                                         /* switch 1 */
        var_r3_3596 = 0;
        temp_r4_3602 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
        if (((s32) M2C_FIELD(temp_r4_3602, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_3602, s32 *, 4) == 3)) {
            var_r3_3596 = 1;
        }
        if (var_r3_3596 == 0) {
            return this->unk168->Trigger(arg1, 0U);
        }
        this->unk168->Trigger(arg1, 1U);
        return ((FuryFXIce2 *) (M2C_BITWISE(FuryFXIce2 *, this->unk16C)))->Trigger(arg1);
    case 2:                                         /* switch 1 */
        /* fallthrough */
    default:                                        /* switch 1 */
        return 0U;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void IceBreathFX::Deinit() {
    FuryFXIce2 *var_r31_3687;
    FuryFXIce2 *var_r3_3688;
    FuryFXIce2 *var_r4_3686;
    MKHeap *temp_r3_3657;
    MKHeap *temp_r3_3713;
    ManagedLight *temp_r4_3672;
    Matrix **temp_r31_3656;
    u32 temp_r0_3696;
    void *temp_r0_3691;
    void *temp_r0_3710;

    temp_r31_3656 = this->unkA8;
    temp_r3_3657 = MKHeap::Current();
    if (temp_r3_3657 != NULL) {
        ((MKHeap *) (temp_r3_3657->Current()))->Free(temp_r31_3656, NULL, 0);
    } else {
        free(temp_r31_3656);
    }
    MKModel_Destroy(this->unkB4);
    temp_r4_3672 = this->unk168;
    if (temp_r4_3672 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_3672, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unk168);
        this->unk168 = NULL;
    }
    var_r4_3686 = this->unk174;
    var_r31_3687 = var_r4_3686;
    var_r3_3688 = var_r4_3686;
loop_8:
    temp_r0_3696 = M2C_FIELD(var_r3_3688, u32 *, -4);
    var_r3_3688 -= 4;
    if (temp_r0_3696 != 0U) {
        temp_r0_3691 = var_r3_3688->unk0;
        if (temp_r0_3691 < var_r31_3687) {
            var_r31_3687 = (FuryFXIce2 *) temp_r0_3691;
        }
        goto loop_8;
    }
    if (var_r3_3688 != &gEmptyPtrListDL) {
loop_14:
        temp_r0_3710 = var_r4_3686->unk0;
        if (temp_r0_3710 != NULL) {
            if (temp_r0_3710 < var_r31_3687) {
                var_r31_3687 = (FuryFXIce2 *) temp_r0_3710;
            }
            var_r4_3686 += 4;
            goto loop_14;
        }
        temp_r3_3713 = var_r3_3688->Current();
        if (temp_r3_3713 != NULL) {
            ((MKHeap *) (temp_r3_3713->Current()))->Free(var_r31_3687, NULL, 0);
        } else {
            free((Matrix **) var_r31_3687);
        }
    }
    this->unk174 = NULL;
    BaseBreathFX::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp88'
void IceBreathFX::Draw() {
    f32 temp_f5_3851;
    f32 temp_f6_3849;
    f32 temp_f7_3847;
    f32 var_f2_3838;
    f32 var_f4_3771;
    f64 temp_f1_3777;
    f64 temp_f1_3783;
    f64 temp_f1_3787;
    s32 temp_r3_3806;
    s32 var_r0_3816;
    s32 var_r29_3752;
    s32 var_r31_3751;
    void *temp_r3_3755;
    if (EventCamera_GetCurrent() == NULL) {
        var_r31_3751 = 0;
        var_r29_3752 = 0;
        do {
            temp_r3_3755 = this->unkA8 + var_r29_3752;
            if ((u8) M2C_FIELD(temp_r3_3755, u8 *, 0x20) != 0) {
                arg_sp88 = M2C_FIELD(temp_r3_3755, f64 *, 0x10);
                arg_sp90 = M2C_FIELD(temp_r3_3755, f64 *, 0x18);
                var_f4_3771 = ((f32) arg_sp90 * (f32) arg_sp90) + (((f32) arg_sp88 * (f32) arg_sp88) + (arg_sp8C * arg_sp8C));
                if (var_f4_3771 > 0.000001f) {
                    if (var_f4_3771 > 0.0f) {
                        temp_f1_3777 = __frsqrte(var_f4_3771);
                        temp_f1_3783 = 0.5 * temp_f1_3777 * -(((f64) var_f4_3771 * (temp_f1_3777 * temp_f1_3777)) - 3.0);
                        temp_f1_3787 = 0.5 * temp_f1_3783 * -(((f64) var_f4_3771 * (temp_f1_3783 * temp_f1_3783)) - 3.0);
                        var_f4_3771 = (f32) ((f64) var_f4_3771 * (0.5 * temp_f1_3787 * -(((f64) var_f4_3771 * (temp_f1_3787 * temp_f1_3787)) - 3.0)));
                    } else if (var_f4_3771 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3771 = __float_nan;
                    } else {
                        arg_sp10 = var_f4_3771;
                        temp_r3_3806 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_3806) {     /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_3816 = 1;
                            } else {
                                var_r0_3816 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_3816 = 5;
                            } else {
                                var_r0_3816 = 3;
                            }
                            break;
                        default:
                            var_r0_3816 = 4;
                            break;
                        }
                        if (var_r0_3816 == 1) {
                            var_f4_3771 = __float_nan;
                        }
                    }
                    var_f2_3838 = 1.0f / var_f4_3771;
                } else {
                    var_f2_3838 = 0.0f;
                }
                temp_f7_3847 = (f32) arg_sp88 * var_f2_3838;
                temp_f6_3849 = arg_sp8C * var_f2_3838;
                temp_f5_3851 = (f32) arg_sp90 * var_f2_3838;
                arg_sp40 = 0.0f;
                arg_sp38 = 0.0f;
                arg_sp3C = 1.0f;
                arg_sp30 = -temp_f5_3851;
                arg_sp28 = -temp_f7_3847;
                arg_sp2C = -temp_f6_3849;
                arg_sp88 = temp_f7_3847;
                arg_sp8C = temp_f6_3849;
                arg_sp90 = temp_f5_3851;
                arg_sp78 = (f64) arg_sp38;
                arg_sp80 = (f64) arg_sp40;
                arg_sp68 = (f64) arg_sp28;
                arg_sp70 = (f64) arg_sp30;
                KDMath_BuildMatrixFromFwd((Matrix *) &arg_spA0, *((MKVector3 *) &arg_sp68), (MKVector3 *) &arg_sp78);
                arg_spA0.Scale3x3((Matrix *) &arg_spA0, this->unk198);
                arg_sp48.operator*(100.0f * this->unk198);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp58 = arg_sp18;
                arg_sp20 = M2C_FIELD((this->unkA8 + var_r29_3752), f32 *, 8) + arg_sp50;
                arg_sp60 = (f64) arg_sp20;
                arg_spD0 = (f32) arg_sp58;
                arg_spD4 = arg_sp5C;
                arg_spD8 = (f32) arg_sp60;
                arg_spDC = 1.0f;
                MKModel_SetWorldMatrix(this->unkB4, *((Matrix *) &arg_spA0));
                MKModel_Draw(this->unkB4, NULL);
            }
            var_r31_3751 += 1;
            var_r29_3752 += 0x30;
        } while (var_r31_3751 < 0x19);
        DrawWallIceShards();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'LiquidFX *' to
void IceBreathFX::Update() {
    MKProp *var_r3_4211;
    ManagedLight *temp_r3_4595;
    ManagedLight *temp_r3_4614;
    ManagedLight *temp_r3_4631;
    ManagedLight *temp_r4_4589;
    Matrix **temp_r0_4058;
    Matrix **temp_r3_4012;
    Matrix **temp_r5_4312;
    f32 temp_f0_4486;
    f32 temp_f1_4145;
    f32 temp_f1_4289;
    f32 temp_f1_4358;
    f32 temp_f1_4485;
    f32 temp_f23_4119;
    f32 temp_f23_4246;
    f32 temp_f24_4114;
    f32 temp_f24_4251;
    f32 temp_f2_4357;
    f32 temp_f31_4031;
    f32 temp_f3_4359;
    f32 temp_f3_4488;
    f32 temp_f4_4364;
    f32 var_f27_4383;
    f32 var_f4_4493;
    f32 var_f4_4560;
    f64 temp_f1_4367;
    f64 temp_f1_4373;
    f64 temp_f1_4377;
    f64 temp_f1_4499;
    f64 temp_f1_4505;
    f64 temp_f1_4509;
    s32 temp_r0_4013;
    s32 temp_r0_4710;
    s32 temp_r3_4314;
    s32 temp_r3_4396;
    s32 temp_r3_4528;
    s32 temp_r3_4708;
    s32 temp_r4_4313;
    s32 var_r0_4406;
    s32 var_r0_4538;
    s32 var_r0_4726;
    s32 var_r25_4235;
    s32 var_r26_3966;
    s32 var_r28_3964;
    u8 var_r29_4000;
    u8 var_r3_4716;
    void *temp_r3_3986;
    void *temp_r3_4003;
    void *temp_r3_4020;
    void *temp_r3_4045;
    void *temp_r3_4100;
    void *temp_r3_4347;
    void *temp_r3_4473;
    void *temp_r3_4598;
    void *temp_r3_4622;
    void *temp_r3_4637;
    void *temp_r4_4356;
    void *temp_r4_4632;
    void *temp_r4_4712;
    void *temp_r5_4481;
    void *temp_r6_4060;
    var_r28_3964 = 0;
    var_r26_3966 = 0;
    this->unkAC -= gUpdateTimeDelta;
    this->unk1A0 -= gUpdateTimeDelta;
    this->unk16C -= gUpdateTimeDelta;
    this->unk184 = (5.0f * gUpdateTimeDelta) + M2C_BITWISE(f32, this->unk184);
    M2C_FIELD(this, f32 *, 0x1A4) = (f32) (M2C_FIELD(this, f32 *, 0x1A4) - gUpdateTimeDelta);
    do {
        temp_r3_3986 = this->unkA8 + var_r26_3966;
        if ((u8) M2C_FIELD(temp_r3_3986, u8 *, 0x20) != 0) {
            arg_sp250 = M2C_FIELD(temp_r3_3986, f64 *, 0);
            arg_sp258 = M2C_FIELD(temp_r3_3986, f64 *, 8);
            if (EventCamera_GetCurrent() != NULL) {
                var_r29_4000 = 1;
                *(this->unkA8 + (var_r26_3966 + 0x24)) = 0.0f;
                temp_r3_4003 = this->unkA8 + var_r26_3966;
                arg_sp250 = M2C_FIELD(temp_r3_4003, f64 *, 0);
                arg_sp258 = M2C_FIELD(temp_r3_4003, f64 *, 8);
            } else {
                var_r29_4000 = 0;
            }
            temp_r3_4012 = this->unkA8;
            temp_r0_4013 = var_r26_3966 + 0x24;
            *(temp_r3_4012 + temp_r0_4013) = *(temp_r3_4012 + temp_r0_4013) - gUpdateTimeDelta;
            temp_r3_4020 = this->unkA8 + var_r26_3966;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r3_4020, f32 *, 0x24) == 0.0f) {
                var_r29_4000 = 1;
                M2C_FIELD(temp_r3_4020, s8 *, 0x20) = 0;
            } else {
                temp_f31_4031 = gUpdateTimeDelta;
                MKVector(0.0f, -700.0f, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp230 = arg_sp70;
                temp_r3_4045 = this->unkA8 + (var_r26_3966 + 0x10);
                arg_sp78 = arg_sp228 * temp_f31_4031;
                arg_sp238 = (f64) arg_sp78;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_FIELD(temp_r3_4045, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_4045, f32 *, 8) + (f32) arg_sp238);
                temp_r0_4058 = this->unkA8;
                temp_r6_4060 = temp_r0_4058 + var_r26_3966;
                arg_sp260 = M2C_FIELD(temp_r6_4060, f64 *, 0);
                arg_sp268 = M2C_FIELD(temp_r6_4060, f64 *, 8);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                arg_sp210 = arg_sp60;
                arg_sp68 = M2C_FIELD((temp_r0_4058 + (var_r26_3966 + 0x10)), f32 *, 8) * gUpdateTimeDelta;
                arg_sp218 = (f64) arg_sp68;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r6, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r6, 0x0, qr0 */);
                M2C_FIELD(temp_r6_4060, f64 *, 8) = (f32) ((f32) M2C_FIELD(temp_r6_4060, f64 *, 8) + (f32) arg_sp218);
                M2C_STRUCT_COPY((s32) &arg_sp26C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_r3_4100 = this->unkA8 + var_r26_3966;
                arg_sp2A0 = M2C_FIELD(temp_r3_4100, f32 *, 0);
                arg_sp2A4 = M2C_FIELD(temp_r3_4100, f32 *, 4);
                arg_sp2A8 = M2C_FIELD(temp_r3_4100, f32 *, 8);
                arg_sp2AC = 1.0f;
                MKModel_SetWorldMatrix(this->unkB4, *((Matrix *) &arg_sp270));
                temp_f24_4114 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f23_4119 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_spF0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_spF4 = temp_f23_4119;
                arg_spF8 = temp_f24_4114;
                arg_sp1F0 = (f64) arg_spF0;
                arg_sp1F8 = (f64) arg_spF8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                arg_sp200 = arg_spE0;
                arg_spE8 = (f32) arg_sp1F8 * 30.000002f;
                arg_sp208 = (f64) arg_spE8;
                temp_f1_4145 = MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                arg_spD0 = 0.5f;
                arg_spD4 = 0.5f;
                arg_spD8 = 1.0f;
                arg_spDC = 1.0f;
                arg_sp1C = this->unk198 * temp_f1_4145;
                arg_sp1E0 = (f64) arg_spD0;
                arg_sp1E8 = (f64) arg_spD8;
                ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*(this->unkA8 + var_r26_3966), *((MKVector3 *) &arg_sp200), arg_sp1C, *((MKVector4 *) &arg_sp1E0), 0.0f);
            }
            arg_sp2B0 = 0.0f;
            arg_sp2B4 = 0.0f;
            arg_sp2B8 = 0.0f;
            arg_sp2C0 = 0.0f;
            arg_sp2C4 = 0.0f;
            arg_sp2C8 = 0.0f;
            arg_sp2D0 = 0.0f;
            arg_sp2D4 = 0.0f;
            arg_sp2D8 = 0.0f;
            arg_sp2DC = 1.0f;
            arg_sp2E0 = 0.0f;
            arg_sp2E4 = 0.0f;
            arg_sp2E8 = 0;
            arg_sp2E8 = 0;
            (s8) arg_sp2E8 = 0;
            arg_sp2EC = 0;
            arg_sp2F0 = 3.4028235e38f;
            arg_sp2F4 = 0;
            arg_sp2F8 = NULL;
            arg_sp2FC = -1;
            arg_sp300 = 0U;
            if ((var_r29_4000 == 0) && (MKCollision_RayCollide(*((MKVector3 *) &arg_sp260), *(this->unkA8 + var_r26_3966), (MKCollisionResult *) &arg_sp2B0, (MKCollisionMode) 7, 4) != 0)) {
                if ((arg_sp300 != 0) && (arg_sp2F8 != NULL) && (var_r3_4211 = arg_sp2F8->unk8, ((var_r3_4211 == NULL) == 0))) {

                } else {
                    var_r3_4211 = NULL;
                }
                if (var_r3_4211 != NULL) {
                    this->unkB8.unk50 = 0;
                    M2C_FIELD(this, f64 *, 0xC8) = (f64) arg_sp2B0;
                    M2C_FIELD(this, f64 *, 0xD0) = (f64) arg_sp2B8;
                    this->unkB8.unk30 = arg_sp2F8;
                    M2C_FIELD(var_r3_4211->__vptr, M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(&this->unkB8, (f64) arg_sp2B0);
                }
                var_r25_4235 = 0;
                arg_sp250 = (f64) arg_sp2B0;
                arg_sp258 = (f64) arg_sp2B8;
                do {
                    temp_f23_4246 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f24_4251 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_spC0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_spC4 = temp_f24_4251;
                    arg_spC8 = temp_f23_4246;
                    arg_sp1B0 = (f64) arg_spC0;
                    arg_sp1B8 = (f64) arg_spC8;
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp1C0 = arg_spB0;
                    arg_spB8 = (f32) arg_sp1B8 + arg_sp2C8;
                    arg_sp1C8 = (f64) arg_spB8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                    arg_sp1D0 = arg_spA0;
                    arg_spA8 = (f32) arg_sp1C8 * 800.0f;
                    arg_sp1D8 = (f64) arg_spA8;
                    temp_f1_4289 = MKRand_Float(&gViewSeed, 6.0f, 10.0f);
                    arg_sp90 = 0.5f;
                    arg_sp94 = 0.5f;
                    arg_sp98 = 1.0f;
                    arg_sp9C = 1.0f;
                    arg_sp18 = this->unk198 * temp_f1_4289;
                    arg_sp1A0 = (f64) arg_sp90;
                    arg_sp1A8 = (f64) arg_sp98;
                    ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*(this->unkA8 + var_r26_3966), *((MKVector3 *) &arg_sp1D0), arg_sp18, *((MKVector4 *) &arg_sp1A0), -2160.0f);
                    var_r25_4235 += 1;
                } while (var_r25_4235 < 5);
                temp_r5_4312 = this->unkA8;
                temp_r4_4313 = var_r26_3966 + 0x28;
                temp_r3_4314 = *(temp_r5_4312 + temp_r4_4313);
                *(temp_r5_4312 + temp_r4_4313) = temp_r3_4314 - 1;
                if (temp_r3_4314 <= 0) {
                    var_r29_4000 = 1;
                    *(this->unkA8 + (var_r26_3966 + 0x20)) = 0;
                } else {
                    KDSound_Play3d(GS_SpyroBreathIceRico2, (MKVector3 *) &arg_sp2B0, 0U, -1, 0.0f, 0U);
                    arg_sp180.operator*(10.0f);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    temp_r3_4347 = this->unkA8 + var_r26_3966;
                    M2C_FIELD(temp_r3_4347, f64 *, 0) = arg_sp50;
                    arg_sp58 = arg_sp2B8 + arg_sp188;
                    arg_sp190 = arg_sp50;
                    M2C_FIELD(temp_r3_4347, f64 *, 8) = (f64) arg_sp58;
                    arg_sp198 = (f64) arg_sp58;
                    temp_r4_4356 = this->unkA8 + (var_r26_3966 + 0x10);
                    temp_f2_4357 = M2C_FIELD(temp_r4_4356, f32 *, 0);
                    temp_f1_4358 = M2C_FIELD(temp_r4_4356, f32 *, 4);
                    temp_f3_4359 = M2C_FIELD(temp_r4_4356, f32 *, 8);
                    temp_f4_4364 = (temp_f3_4359 * temp_f3_4359) + ((temp_f2_4357 * temp_f2_4357) + (temp_f1_4358 * temp_f1_4358));
                    if (temp_f4_4364 > 0.0f) {
                        temp_f1_4367 = __frsqrte(temp_f4_4364);
                        temp_f1_4373 = 0.5 * temp_f1_4367 * -(((f64) temp_f4_4364 * (temp_f1_4367 * temp_f1_4367)) - 3.0);
                        temp_f1_4377 = 0.5 * temp_f1_4373 * -(((f64) temp_f4_4364 * (temp_f1_4373 * temp_f1_4373)) - 3.0);
                        var_f27_4383 = (f32) ((f64) temp_f4_4364 * (0.5 * temp_f1_4377 * -(((f64) temp_f4_4364 * (temp_f1_4377 * temp_f1_4377)) - 3.0)));
                    } else if (temp_f4_4364 < M2C_BITWISE(f32, 0.0)) {
                        var_f27_4383 = __float_nan;
                    } else {
                        arg_sp14 = temp_f4_4364;
                        temp_r3_4396 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                        switch (temp_r3_4396) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_4406 = 1;
                            } else {
                                var_r0_4406 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_4406 = 5;
                            } else {
                                var_r0_4406 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_4406 = 4;
                            break;
                        }
                        if (var_r0_4406 == 1) {
                            var_f27_4383 = __float_nan;
                        } else {
                            var_f27_4383 = temp_f4_4364;
                        }
                    }
                    MKVector(1.0f, 1.0f, 1.0f);
                    MKVector(-1.0f, -1.0f, -1.0f);
                    KDRand_Vector(*((MKVector3 *) &arg_sp130), *((MKVector3 *) &arg_sp120));
                    arg_sp140.operator*(1.5f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp150 = arg_sp20;
                    arg_sp28 = arg_sp148 + arg_sp138;
                    arg_sp158 = (f64) arg_sp28;
                    Normalise(*((MKVector3 *) &arg_sp160));
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                    temp_r3_4473 = this->unkA8 + (var_r26_3966 + 0x10);
                    M2C_FIELD(temp_r3_4473, f64 *, 0) = arg_sp40;
                    arg_sp48 = arg_sp168 * var_f27_4383;
                    arg_sp170 = arg_sp40;
                    M2C_FIELD(temp_r3_4473, f64 *, 8) = (f64) arg_sp48;
                    arg_sp178 = (f64) arg_sp48;
                    temp_r5_4481 = this->unkA8 + var_r26_3966;
                    if ((s32) M2C_FIELD(temp_r5_4481, s32 *, 0x28) >= 3) {
                        temp_f1_4485 = M2C_FIELD(temp_r5_4481, f32 *, 0x10);
                        temp_f0_4486 = M2C_FIELD(temp_r5_4481, f32 *, 0x14);
                        temp_f3_4488 = M2C_FIELD(temp_r5_4481, f32 *, 0x18);
                        var_f4_4493 = (temp_f3_4488 * temp_f3_4488) + ((temp_f1_4485 * temp_f1_4485) + (temp_f0_4486 * temp_f0_4486));
                        if (var_f4_4493 > 1e-12f) {
                            if (var_f4_4493 > 0.0f) {
                                temp_f1_4499 = __frsqrte(var_f4_4493);
                                temp_f1_4505 = 0.5 * temp_f1_4499 * -(((f64) var_f4_4493 * (temp_f1_4499 * temp_f1_4499)) - 3.0);
                                temp_f1_4509 = 0.5 * temp_f1_4505 * -(((f64) var_f4_4493 * (temp_f1_4505 * temp_f1_4505)) - 3.0);
                                var_f4_4493 = (f32) ((f64) var_f4_4493 * (0.5 * temp_f1_4509 * -(((f64) var_f4_4493 * (temp_f1_4509 * temp_f1_4509)) - 3.0)));
                            } else if (var_f4_4493 < M2C_BITWISE(f32, 0.0)) {
                                var_f4_4493 = __float_nan;
                            } else {
                                arg_sp10 = var_f4_4493;
                                temp_r3_4528 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                                switch (temp_r3_4528) { /* switch 2; irregular */
                                case 0x7F800000:    /* switch 2 */
                                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                        var_r0_4538 = 1;
                                    } else {
                                        var_r0_4538 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 2 */
                                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                        var_r0_4538 = 5;
                                    } else {
                                        var_r0_4538 = 3;
                                    }
                                    break;
                                default:            /* switch 2 */
                                    var_r0_4538 = 4;
                                    break;
                                }
                                if (var_r0_4538 == 1) {
                                    var_f4_4493 = __float_nan;
                                }
                            }
                            var_f4_4560 = 1.0f / var_f4_4493;
                        } else {
                            var_f4_4560 = 0.0f;
                        }
                        arg_sp80 = M2C_FIELD(temp_r5_4481, f32 *, 0x10) * var_f4_4560;
                        arg_sp84 = M2C_FIELD(temp_r5_4481, f32 *, 0x14) * var_f4_4560;
                        arg_sp88 = M2C_FIELD(temp_r5_4481, f32 *, 0x18) * var_f4_4560;
                        arg_sp240 = (f64) arg_sp80;
                        arg_sp248 = (f64) arg_sp88;
                        SpawnWallIceShard(*((MKVector3 *) &arg_sp2B0), *((MKVector3 *) &arg_sp240), 1.0f);
                    }
                    this->unk170->Trigger(*((MKVector3 *) &arg_sp2B0), this->unk198);
                }
                temp_r4_4589 = this->unk168;
                if (temp_r4_4589 != NULL) {
                    ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_4589, 1U);
                    temp_r3_4595 = this->unk168;
                    temp_r3_4595->unk38 = 500.0f;
                    temp_r3_4598 = temp_r3_4595->unk3C;
                    if (temp_r3_4598 != NULL) {
                        M2C_FIELD(temp_r3_4598, f32 *, 0x20) = 500.0f;
                        M2C_FIELD(temp_r3_4598, f32 *, 0x24) = 250000.0f;
                        M2C_FIELD(temp_r3_4598, f32 *, 0x28) = 0.002f;
                        M2C_FIELD(temp_r3_4598, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_4598, f32 *, 0x24));
                    }
                    arg_sp30 = 0.3f;
                    temp_r3_4614 = this->unk168;
                    arg_sp34 = 0.3f;
                    arg_sp38 = 1.0f;
                    arg_sp3C = 1.0f;
                    temp_r3_4614->unk20 = (f64) arg_sp30;
                    temp_r3_4614->unk28 = (f64) arg_sp38;
                    temp_r3_4622 = temp_r3_4614->unk3C;
                    arg_sp100 = (f64) arg_sp30;
                    arg_sp108 = (f64) arg_sp38;
                    if (temp_r3_4622 != NULL) {
                        M2C_FIELD(temp_r3_4622, f64 *, 0) = (f64) arg_sp30;
                        M2C_FIELD(temp_r3_4622, f64 *, 8) = (f64) arg_sp38;
                    }
                    temp_r3_4631 = this->unk168;
                    temp_r4_4632 = this->unkA8 + var_r26_3966;
                    temp_r3_4631->unk10 = M2C_FIELD(temp_r4_4632, f64 *, 0);
                    temp_r3_4631->unk18 = M2C_FIELD(temp_r4_4632, f64 *, 8);
                    temp_r3_4637 = temp_r3_4631->unk3C;
                    if (temp_r3_4637 != NULL) {
                        M2C_FIELD(temp_r3_4637, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_4632, f64 *, 0);
                        M2C_FIELD(temp_r3_4637, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_4632, f64 *, 8);
                    }
                    this->unk16C = 0.25f;
                }
            }
            if (var_r29_4000 != 0) {
                this->unk170->Trigger(*((MKVector3 *) &arg_sp250), this->unk198);
                KDSound_Play3d(GS_SpyroBreathIceRico1, (MKVector3 *) &arg_sp2B0, 0U, -1, 0.0f, 0U);
            }
        }
        var_r28_3964 += 1;
        var_r26_3966 += 0x30;
    } while (var_r28_3964 < 0x19);
    if (((ManagedLight *) this->unk168 != NULL) && ((M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk16C == 0.0f) != 0)) || (EventCamera_GetCurrent() != NULL))) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unk168, 0U);
    }
    UpdateWallIceShards();
    if (((u8) M2C_FIELD(this, u8 *, 0x19C) != 0) && (EventCamera_GetCurrent() == NULL)) {
        M2C_FIELD(this, u8 *, 0x19C) = 0U;
        this->unk190 = M2C_BITWISE(f32, this->unk190) + gUpdateTimeDelta;
        if (M2C_BITWISE(f32, this->unk190) > 3.5f) {
            this->unk190 = -1.0f;
        }
        temp_r3_4708 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_4710 = *(&GameData::gameData[0x70] + (temp_r3_4708 + 0x7C));
        temp_r4_4712 = &GameData::gameData[0x70] + (temp_r3_4708 + 0x64);
        if (temp_r0_4710 == 3) {
            var_r3_4716 = 0;
            if (((s32) M2C_FIELD(temp_r4_4712, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_4712, s32 *, 4) == 3)) {
                var_r3_4716 = 1;
            }
            var_r0_4726 = var_r3_4716 != 0;
        } else {
            var_r0_4726 = *(temp_r4_4712 + (temp_r0_4710 * 4));
        }
        switch (var_r0_4726) {                      /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_BITWISE(f32, this->unk190) == 0.0f) {
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.02f, 0.3f, 0.04f, 0, 4.0f, 0U);
                return;
            }
            break;
        case 1:                                     /* switch 3 */
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_BITWISE(f32, this->unk190) == 0.0f) {
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.02f, 0.5f, 0.04f, 0, 4.0f, 0U);
                return;
            }
            break;
        case 2:                                     /* switch 3 */
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_BITWISE(f32, this->unk190) == 0.0f) {
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.3f, 0.5f, 0.04f, 0, 4.0f, 0U);
                return;
            }
            break;
        case 3:                                     /* switch 3 */
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_BITWISE(f32, this->unk190) == 0.0f) {
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.3f, 0.7f, 0.04f, 0, 4.0f, 0U);
                return;
            }
            break;
        }
    } else {
        this->unk190 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void IceBreathFX::Resolve() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_4901;

    MKProp::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unk168 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_732, lit_733);
    temp_r4_4901 = this->unk168;
    if (temp_r4_4901 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_4901, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FuryFXIce *' to
void IceBreathFX::Init() {
    FuryFXIce *temp_r3_4974;
    FuryFXIce2 *temp_r3_5003;
    FuryFXIce2 *temp_r4_5009;
    FuryFXIce2 *var_r5_4997;
    MKHeap *temp_r3_4935;
    MKHeap *temp_r3_4937;
    MKHeap *temp_r3_4981;
    Matrix **var_r3_4944;
    Matrix **var_r3_4988;
    s32 temp_r0_4965;
    s32 var_ctr_4962;
    s32 var_ctr_5001;
    s32 var_r28_5011;
    s32 var_r30_5012;
    s32 var_r4_4958;

    BaseBreathFX::Init();
    this->unk168 = checked_cast<FuryFXIce *, MKProp>(gMK->CreateProp("FuryFXIce"));
    temp_r3_4935 = checked_cast<FuryFXIce2 *, MKProp>(gMK->CreateProp("FuryFXIce2"));
    this->unk16C = M2C_BITWISE(f32, temp_r3_4935);
    temp_r3_4937 = temp_r3_4935->Current();
    if (temp_r3_4937 != NULL) {
        var_r3_4944 = ((MKHeap *) (temp_r3_4937->Current()))->Alloc(0x4B0, NULL, 0);
    } else {
        var_r3_4944 = malloc(0x4B0);
    }
    this->unkA8 = var_r3_4944;
    var_r4_4958 = 0;
    this->unkB4 = MKModel_Create("FX0027_IceSpear", NULL, 2, NULL);
    var_ctr_4962 = 0x19;
    do {
        temp_r0_4965 = var_r4_4958 + 0x20;
        var_r4_4958 += 0x30;
        *(this->unkA8 + temp_r0_4965) = 0;
        var_ctr_4962 -= 1;
    } while (var_ctr_4962 != 0);
    temp_r3_4974 = checked_cast<IceExplosion *, MKProp>(gMK->CreateProp("IceExplosion"));
    this->unk170 = temp_r3_4974;
    this->unkAC = 0.0f;
    this->unk168 = NULL;
    this->unk16C = 0.0f;
    temp_r3_4981 = temp_r3_4974->Current();
    if (temp_r3_4981 != NULL) {
        var_r3_4988 = ((MKHeap *) (temp_r3_4981->Current()))->Alloc(0x698, NULL, 0);
    } else {
        var_r3_4988 = malloc(0x698);
    }
    this->unk174 = (FuryFXIce2 *) var_r3_4988;
    var_r5_4997 = this->unk174;
    this->unk174 = var_r5_4997 + 0x640;
    M2C_FIELD(var_r5_4997, s32 *, 0x640) = 0;
    var_ctr_5001 = 0x14;
    do {
        temp_r3_5003 = this->unk174;
        this->unk174 = (FuryFXIce2 *) &temp_r3_5003->unk4;
        temp_r3_5003->unk4 = (MKModel *) var_r5_4997;
        var_r5_4997 += 0x50;
        var_ctr_5001 -= 1;
    } while (var_ctr_5001 != 0);
    temp_r4_5009 = this->unk174;
    var_r28_5011 = 0;
    var_r30_5012 = 0;
    this->unk174 = (FuryFXIce2 *) &temp_r4_5009->unk4;
    temp_r4_5009->unk4 = NULL;
    do {
        var_r28_5011 += 1;
        *(this + (var_r30_5012 + 0x180)) = checked_cast<LiquidFX *, MKProp>(gMK->CreateProp("LiquidIceFX"));
        var_r30_5012 += 4;
    } while (var_r28_5011 < 3);
    this->unk184 = 0.0f;
    this->unk190 = 0.0f;
    M2C_FIELD(this, s8 *, 0x19C) = 0;
    this->unk198 = 1.0f;
    M2C_FIELD(this, f32 *, 0x1A4) = 0.0f;
    this->unk188 = NULL;
    this->unk18C = 0.0f;
    this->unk1A0 = 0.0f;
}
#endif
