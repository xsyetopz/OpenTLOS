#include "spyro/source/DynamiteExplosion.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
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
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(DynamiteExplosion::Explosion **);      /* extern */
DynamiteExplosion::Explosion **malloc(M2C_UNK);     /* extern */
extern s32 GS_Explosion6;
extern s32 GS_Rumble1Soft;
extern s32 GS_TNTExplodeEarth;
extern s32 GS_TNTExplodeEarthDebris;
extern s32 GS_TNTExplodeElec;
extern s32 GS_TNTExplodeElecDebris;
extern s32 GS_TNTExplodeFire;
extern s32 GS_TNTExplodeFireDebris;
extern s32 GS_TNTExplodeIce;
extern s32 GS_TNTExplodeIceDebris;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static u8 lit_1080 = 1;

static u8 lit_1149 = 1;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
u8 DynamiteExplosion::UpdateElec(DynamiteExplosion::Explosion *arg1) {
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
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
    MKVector3 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA4;
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
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_116;
    f32 temp_f1_124;
    f32 temp_f1_252;
    f32 temp_f1_80;
    f32 temp_f30_78;
    f32 temp_f31_231;
    f32 var_f0_60;
    f32 var_f3_199;
    f32 var_f3_327;
    f32 var_f4_132;
    f32 var_f4_260;
    f64 temp_f0_346;
    f64 temp_f0_356;
    f64 temp_f1_138;
    f64 temp_f1_144;
    f64 temp_f1_148;
    f64 temp_f1_266;
    f64 temp_f1_272;
    f64 temp_f1_276;
    s32 temp_r0_54;
    s32 temp_r3_167;
    s32 temp_r3_295;
    s32 var_r0_177;
    s32 var_r0_305;

    M2C_FIELD(arg1, f32 *, 0x10) = (f32) (M2C_FIELD(arg1, f32 *, 0x10) - gUpdateTimeDelta);
    temp_r0_54 = M2C_FIELD(arg1, s32 *, 0x18);
    if (temp_r0_54 != 1) {
        if (temp_r0_54 < 1) {

        }
        goto block_51;
    }
    var_f0_60 = M2C_FIELD(arg1, f32 *, 0x10);
    if (var_f0_60 < 1.0f) {

    } else {
        var_f0_60 = 1.0f;
    }
    if (var_f0_60 > 0.0f) {

    } else {
        var_f0_60 = 0.0f;
    }
    M2C_FIELD(arg1, f32 *, 0x10) = var_f0_60;
    temp_f30_78 = M2C_FIELD(arg1, f32 *, 0x10);
    temp_f1_80 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    sp90 = -1.0f;
    sp80 = 1.0f;
    sp88 = -1.0f;
    sp8C = 0.0f;
    sp78 = 1.0f;
    sp7C = 1.0f;
    sp98 = 1.0f;
    sp9C = (0.2f * temp_f1_80) + 0.1f;
    spA0 = (0.75f * temp_f1_80) + 0.25f;
    spA4 = 1.0f;
    sp128 = (f64) sp88;
    sp130 = (f64) sp90;
    sp118 = (f64) sp78;
    sp120 = (f64) sp80;
    temp_f1_116 = M2C_FIELD(arg1, f32 *, 0x14) * MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
    sp108 = (f64) sp98;
    sp110 = (f64) spA0;
    sp10 = temp_f30_78 * temp_f1_116;
    KDRand_Vector(sp138, *((MKVector3 *) &sp128));
    temp_f1_124 = M2C_BITWISE(f32, sp138);
    var_f4_132 = (sp138.unk8 * sp138.unk8) + ((temp_f1_124 * temp_f1_124) + (sp138.unk4 * sp138.unk4));
    if (var_f4_132 > 1e-12f) {
        if (var_f4_132 > 0.0f) {
            temp_f1_138 = __frsqrte(var_f4_132);
            temp_f1_144 = 0.5 * temp_f1_138 * -(((f64) var_f4_132 * (temp_f1_138 * temp_f1_138)) - 3.0);
            temp_f1_148 = 0.5 * temp_f1_144 * -(((f64) var_f4_132 * (temp_f1_144 * temp_f1_144)) - 3.0);
            var_f4_132 = (f32) ((f64) var_f4_132 * (0.5 * temp_f1_148 * -(((f64) var_f4_132 * (temp_f1_148 * temp_f1_148)) - 3.0)));
        } else if (var_f4_132 < M2C_BITWISE(f32, 0.0)) {
            var_f4_132 = __float_nan;
        } else {
            spC = var_f4_132;
            temp_r3_167 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_167) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_177 = 1;
                } else {
                    var_r0_177 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_177 = 5;
                } else {
                    var_r0_177 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_177 = 4;
                break;
            }
            if (var_r0_177 == 1) {
                var_f4_132 = __float_nan;
            }
        }
        var_f3_199 = 1.0f / var_f4_132;
    } else {
        var_f3_199 = 0.0f;
    }
    sp68 = M2C_BITWISE(f32, sp138) * var_f3_199;
    sp6C = sp138.unk4 * var_f3_199;
    sp70 = sp138.unk8 * var_f3_199;
    sp148 = (f64) sp68;
    sp150 = (f64) sp70;
    ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) arg1), *((MKVector3 *) &sp148), sp10, lit_1149, (MKVector4) &sp108);
    temp_f31_231 = MKRand_Float((int *) &gViewSeed, 2000.0f, 3000.0f);
    sp60 = -1.0f;
    sp50 = 1.0f;
    sp58 = -1.0f;
    sp5C = 0.0f;
    sp48 = 1.0f;
    sp4C = 1.0f;
    spB8 = (f64) sp58;
    spC0 = (f64) sp60;
    spA8 = (f64) sp48;
    spB0 = (f64) sp50;
    KDRand_Vector(spC8, *((MKVector3 *) &spB8));
    temp_f1_252 = M2C_BITWISE(f32, spC8);
    var_f4_260 = (spC8.unk8 * spC8.unk8) + ((temp_f1_252 * temp_f1_252) + (spC8.unk4 * spC8.unk4));
    if (var_f4_260 > 1e-12f) {
        if (var_f4_260 > 0.0f) {
            temp_f1_266 = __frsqrte(var_f4_260);
            temp_f1_272 = 0.5 * temp_f1_266 * -(((f64) var_f4_260 * (temp_f1_266 * temp_f1_266)) - 3.0);
            temp_f1_276 = 0.5 * temp_f1_272 * -(((f64) var_f4_260 * (temp_f1_272 * temp_f1_272)) - 3.0);
            var_f4_260 = (f32) ((f64) var_f4_260 * (0.5 * temp_f1_276 * -(((f64) var_f4_260 * (temp_f1_276 * temp_f1_276)) - 3.0)));
        } else if (var_f4_260 < M2C_BITWISE(f32, 0.0)) {
            var_f4_260 = __float_nan;
        } else {
            sp8 = var_f4_260;
            temp_r3_295 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_295) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_305 = 1;
                } else {
                    var_r0_305 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_305 = 5;
                } else {
                    var_r0_305 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_305 = 4;
                break;
            }
            if (var_r0_305 == 1) {
                var_f4_260 = __float_nan;
            }
        }
        var_f3_327 = 1.0f / var_f4_260;
    } else {
        var_f3_327 = 0.0f;
    }
    sp18 = M2C_BITWISE(f32, spC8) * var_f3_327;
    sp1C = spC8.unk4 * var_f3_327;
    sp20 = spC8.unk8 * var_f3_327;
    spD8 = (f64) sp18;
    spE0 = (f64) sp20;
    temp_f0_346 = spD8 * (f64) temp_f31_231;
    sp38 = temp_f0_346;
    spE8 = temp_f0_346;
    sp40 = (f32) spE0 * temp_f31_231;
    spF0 = (f64) sp40;
    temp_f0_356 = temp_f0_346 * (f64) temp_f30_78;
    sp28 = temp_f0_356;
    spF8 = temp_f0_356;
    sp30 = (f32) spF0 * temp_f30_78;
    sp100 = (f64) sp30;
    ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) arg1), *((MKVector3 *) &spF8), temp_f30_78 * (M2C_FIELD(arg1, f32 *, 0x14) * MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f)), 1U);
    if (M2C_FIELD(arg1, f32 *, 0x10) <= 0.0f) {
        return 0U;
    }
block_51:
    return 1U;
}
#endif

u8 DynamiteExplosion::UpdateIce(DynamiteExplosion::Explosion *arg1) {
    return 1U;
}

u8 DynamiteExplosion::UpdateEarth(DynamiteExplosion::Explosion *arg1) {
    return 1U;
}

u8 DynamiteExplosion::UpdateFire(DynamiteExplosion::Explosion *arg1) {
    return 1U;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void DynamiteExplosion::TriggerElec(const MKVector3 &arg0, float arg1, bool arg2) {
    Frustum sp3B0;
    Matrix sp370;
    M2C_UNK sp36C;
    s8 sp360;
    f64 sp358;
    f64 sp350;
    s32 sp34C;
    s32 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    MKVector3 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    MKVector3 sp238;
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
    MKVector3 sp1C8;
    M2C_UNK sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    MKVector3 sp188;
    f64 sp180;
    f64 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    DynamiteExplosion::Explosion **temp_r3_1269;
    DynamiteExplosion::Explosion **temp_r3_1273;
    DynamiteExplosion::Explosion *temp_r3_1275;
    f32 temp_f0_1095;
    f32 temp_f1_519;
    f32 temp_f1_539;
    f32 temp_f1_685;
    f32 temp_f1_704;
    f32 temp_f1_721;
    f32 temp_f1_836;
    f32 temp_f1_856;
    f32 temp_f21_1103;
    f32 temp_f2_1154;
    f32 temp_f30_1157;
    f32 var_f3_613;
    f32 var_f3_795;
    f32 var_f3_930;
    f32 var_f4_1065;
    f32 var_f4_546;
    f32 var_f4_728;
    f32 var_f4_863;
    f32 var_f5_998;
    f64 temp_f0_632;
    f64 temp_f0_949;
    f64 temp_f1_1083;
    f64 temp_f1_552;
    f64 temp_f1_558;
    f64 temp_f1_562;
    f64 temp_f1_734;
    f64 temp_f1_740;
    f64 temp_f1_744;
    f64 temp_f1_869;
    f64 temp_f1_875;
    f64 temp_f1_879;
    f64 temp_f2_1004;
    f64 temp_f2_1010;
    f64 temp_f2_1014;
    s32 temp_r31_513;
    s32 temp_r3_1033;
    s32 temp_r3_581;
    s32 temp_r3_763;
    s32 temp_r3_898;
    s32 var_r0_1043;
    s32 var_r0_591;
    s32 var_r0_773;
    s32 var_r0_908;
    s32 var_r27_509;
    s32 var_r27_674;
    s32 var_r27_829;
    void *temp_r27_468;
    void *temp_r3_459;
    void *temp_r3_461;
    void *temp_r3_465;
    void *temp_r3_974;

    temp_r3_459 = checked_cast<DynamiteExplosionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_461 = M2C_FIELD(temp_r3_459, void **, 0x6C);
    temp_r3_465 = M2C_FIELD(M2C_FIELD(temp_r3_461, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_461);
    if (temp_r3_465 != NULL) {
        temp_r27_468 = M2C_FIELD(temp_r3_465, void **, 0x2C);
        M2C_FIELD(temp_r3_465, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_465, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_465, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_465, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_465, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r3_465, f32 *, 0x10) = 1.0f;
        M2C_FIELD(temp_r3_465, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r3_465, f32 *, 0x18) = 0.5f;
        M2C_FIELD(temp_r3_465, f32 *, 0x1C) = 1.0f;
        M2C_FIELD(temp_r27_468, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r27_468, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r27_468, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r27_468, f32 *, 0x18) = (f32) (3.0f * arg1);
        M2C_FIELD(temp_r27_468, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r27_468, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_459, void **, 0x6C), f32 *, 0xF4);
    }
    var_r27_509 = 0;
    temp_r31_513 = (s32) (20.0f * arg1);
loop_24:
    if (var_r27_509 < temp_r31_513) {
        temp_f1_519 = MKRand_Float((int *) &gViewSeed, 2000.0f, 3000.0f);
        sp170 = -1.0f;
        sp160 = 1.0f;
        sp168 = -1.0f;
        sp16C = 0.0f;
        sp158 = 1.0f;
        sp15C = 1.0f;
        sp2D8 = (f64) sp168;
        sp2E0 = (f64) sp170;
        sp2C8 = (f64) sp158;
        sp2D0 = (f64) sp160;
        KDRand_Vector(sp2E8, *((MKVector3 *) &sp2D8));
        temp_f1_539 = M2C_BITWISE(f32, sp2E8);
        var_f4_546 = (sp2E8.unk8 * sp2E8.unk8) + ((temp_f1_539 * temp_f1_539) + (sp2E8.unk4 * sp2E8.unk4));
        if (var_f4_546 > 1e-12f) {
            if (var_f4_546 > 0.0f) {
                temp_f1_552 = __frsqrte(var_f4_546);
                temp_f1_558 = 0.5 * temp_f1_552 * -(((f64) var_f4_546 * (temp_f1_552 * temp_f1_552)) - 3.0);
                temp_f1_562 = 0.5 * temp_f1_558 * -(((f64) var_f4_546 * (temp_f1_558 * temp_f1_558)) - 3.0);
                var_f4_546 = (f32) ((f64) var_f4_546 * (0.5 * temp_f1_562 * -(((f64) var_f4_546 * (temp_f1_562 * temp_f1_562)) - 3.0)));
            } else if (var_f4_546 < M2C_BITWISE(f32, 0.0)) {
                var_f4_546 = __float_nan;
            } else {
                sp1C = var_f4_546;
                temp_r3_581 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                switch (temp_r3_581) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_591 = 1;
                    } else {
                        var_r0_591 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_591 = 5;
                    } else {
                        var_r0_591 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_591 = 4;
                    break;
                }
                if (var_r0_591 == 1) {
                    var_f4_546 = __float_nan;
                }
            }
            var_f3_613 = 1.0f / var_f4_546;
        } else {
            var_f3_613 = 0.0f;
        }
        sp128 = M2C_BITWISE(f32, sp2E8) * var_f3_613;
        sp12C = sp2E8.unk4 * var_f3_613;
        sp130 = sp2E8.unk8 * var_f3_613;
        sp2F8 = (f64) sp128;
        sp300 = (f64) sp130;
        temp_f0_632 = sp2F8 * (f64) temp_f1_519;
        sp148 = temp_f0_632;
        sp308 = temp_f0_632;
        sp150 = (f32) sp300 * temp_f1_519;
        sp310 = (f64) sp150;
        sp24 = MKRand_Float((int *) &gViewSeed, 12.0f, 20.0f);
        sp140 = MKRand_Float((int *) &gViewSeed, 0.125f, 1.0f);
        sp144 = 1.0f;
        sp138 = 1.0f;
        sp13C = 0.0f;
        sp2C0 = (f64) sp140;
        sp2B8 = (f64) sp138;
        ((EmbersPS *) gb.unk74)->Emit(arg0, *((MKVector3 *) &sp308), sp24, *((MKVector4 *) &sp2B8), -2000.0f);
        var_r27_509 += 1;
        goto loop_24;
    }
    var_r27_674 = 0;
loop_47:
    if (var_r27_674 < temp_r31_513) {
        temp_f1_685 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        sp120 = -1.0f;
        sp110 = 1.0f;
        sp118 = -1.0f;
        sp11C = 0.0f;
        sp108 = 1.0f;
        sp10C = 1.0f;
        sp288 = (f64) sp118;
        sp290 = (f64) sp120;
        sp278 = (f64) sp108;
        sp280 = (f64) sp110;
        temp_f1_704 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
        spF8 = 1.0f;
        sp104 = 1.0f;
        spFC = (0.2f * temp_f1_685) + 0.1f;
        sp100 = (0.75f * temp_f1_685) + 0.25f;
        sp20 = arg1 * temp_f1_704;
        sp268 = (f64) spF8;
        sp270 = (f64) sp100;
        KDRand_Vector(sp298, *((MKVector3 *) &sp288));
        temp_f1_721 = M2C_BITWISE(f32, sp298);
        var_f4_728 = (sp298.unk8 * sp298.unk8) + ((temp_f1_721 * temp_f1_721) + (sp298.unk4 * sp298.unk4));
        if (var_f4_728 > 1e-12f) {
            if (var_f4_728 > 0.0f) {
                temp_f1_734 = __frsqrte(var_f4_728);
                temp_f1_740 = 0.5 * temp_f1_734 * -(((f64) var_f4_728 * (temp_f1_734 * temp_f1_734)) - 3.0);
                temp_f1_744 = 0.5 * temp_f1_740 * -(((f64) var_f4_728 * (temp_f1_740 * temp_f1_740)) - 3.0);
                var_f4_728 = (f32) ((f64) var_f4_728 * (0.5 * temp_f1_744 * -(((f64) var_f4_728 * (temp_f1_744 * temp_f1_744)) - 3.0)));
            } else if (var_f4_728 < M2C_BITWISE(f32, 0.0)) {
                var_f4_728 = __float_nan;
            } else {
                sp18 = var_f4_728;
                temp_r3_763 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_763) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_773 = 1;
                    } else {
                        var_r0_773 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_773 = 5;
                    } else {
                        var_r0_773 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_773 = 4;
                    break;
                }
                if (var_r0_773 == 1) {
                    var_f4_728 = __float_nan;
                }
            }
            var_f3_795 = 1.0f / var_f4_728;
        } else {
            var_f3_795 = 0.0f;
        }
        spE8 = M2C_BITWISE(f32, sp298) * var_f3_795;
        spEC = sp298.unk4 * var_f3_795;
        spF0 = sp298.unk8 * var_f3_795;
        sp2A8 = (f64) spE8;
        sp2B0 = (f64) spF0;
        ((ZapArcFX *) gb.unk94)->Trigger(arg0, *((MKVector3 *) &sp2A8), sp20, lit_1080, (MKVector4) &sp268);
        var_r27_674 += 1;
        goto loop_47;
    }
    var_r27_829 = 0;
loop_70:
    if (var_r27_829 < temp_r31_513) {
        temp_f1_836 = MKRand_Float((int *) &gViewSeed, 2000.0f, 3000.0f);
        spE0 = -1.0f;
        spD0 = 1.0f;
        spD8 = -1.0f;
        spDC = 0.0f;
        spC8 = 1.0f;
        spCC = 1.0f;
        sp228 = (f64) spD8;
        sp230 = (f64) spE0;
        sp218 = (f64) spC8;
        sp220 = (f64) spD0;
        KDRand_Vector(sp238, *((MKVector3 *) &sp228));
        temp_f1_856 = M2C_BITWISE(f32, sp238);
        var_f4_863 = (sp238.unk8 * sp238.unk8) + ((temp_f1_856 * temp_f1_856) + (sp238.unk4 * sp238.unk4));
        if (var_f4_863 > 1e-12f) {
            if (var_f4_863 > 0.0f) {
                temp_f1_869 = __frsqrte(var_f4_863);
                temp_f1_875 = 0.5 * temp_f1_869 * -(((f64) var_f4_863 * (temp_f1_869 * temp_f1_869)) - 3.0);
                temp_f1_879 = 0.5 * temp_f1_875 * -(((f64) var_f4_863 * (temp_f1_875 * temp_f1_875)) - 3.0);
                var_f4_863 = (f32) ((f64) var_f4_863 * (0.5 * temp_f1_879 * -(((f64) var_f4_863 * (temp_f1_879 * temp_f1_879)) - 3.0)));
            } else if (var_f4_863 < M2C_BITWISE(f32, 0.0)) {
                var_f4_863 = __float_nan;
            } else {
                sp14 = var_f4_863;
                temp_r3_898 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_898) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_908 = 1;
                    } else {
                        var_r0_908 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_908 = 5;
                    } else {
                        var_r0_908 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_908 = 4;
                    break;
                }
                if (var_r0_908 == 1) {
                    var_f4_863 = __float_nan;
                }
            }
            var_f3_930 = 1.0f / var_f4_863;
        } else {
            var_f3_930 = 0.0f;
        }
        spA8 = M2C_BITWISE(f32, sp238) * var_f3_930;
        spAC = sp238.unk4 * var_f3_930;
        spB0 = sp238.unk8 * var_f3_930;
        sp248 = (f64) spA8;
        sp250 = (f64) spB0;
        temp_f0_949 = sp248 * (f64) temp_f1_836;
        spB8 = temp_f0_949;
        sp258 = temp_f0_949;
        spC0 = (f32) sp250 * temp_f1_836;
        sp260 = (f64) spC0;
        ((ElectricSparks *) gb.unk230)->Emit(arg0, *((MKVector3 *) &sp258), MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f), 1U);
        var_r27_829 += 1;
        goto loop_70;
    }
    temp_r3_974 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp338 = M2C_FIELD(temp_r3_974, f64 *, 0x30);
    sp340 = M2C_FIELD(temp_r3_974, f64 *, 0x38);
    sp98 = M2C_FIELD(&arg0, f64 *, 0) - sp338;
    sp208 = sp98;
    spA0 = arg0.unk8 - (f32) sp340;
    sp210 = (f64) spA0;
    var_f5_998 = ((f32) sp210 * (f32) sp210) + (((f32) sp208 * (f32) sp208) + ((*(f32 *) ((u8 *) &sp208 + 0x4)) * (*(f32 *) ((u8 *) &sp208 + 0x4))));
    if (var_f5_998 > 1e-12f) {
        if (var_f5_998 > 0.0f) {
            temp_f2_1004 = __frsqrte(var_f5_998);
            temp_f2_1010 = 0.5 * temp_f2_1004 * -(((f64) var_f5_998 * (temp_f2_1004 * temp_f2_1004)) - 3.0);
            temp_f2_1014 = 0.5 * temp_f2_1010 * -(((f64) var_f5_998 * (temp_f2_1010 * temp_f2_1010)) - 3.0);
            var_f5_998 = (f32) ((f64) var_f5_998 * (0.5 * temp_f2_1014 * -(((f64) var_f5_998 * (temp_f2_1014 * temp_f2_1014)) - 3.0)));
        } else if (var_f5_998 < M2C_BITWISE(f32, 0.0)) {
            var_f5_998 = __float_nan;
        } else {
            sp10 = var_f5_998;
            temp_r3_1033 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1033) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1043 = 1;
                } else {
                    var_r0_1043 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1043 = 5;
                } else {
                    var_r0_1043 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_1043 = 4;
                break;
            }
            if (var_r0_1043 == 1) {
                var_f5_998 = __float_nan;
            }
        }
        var_f4_1065 = 1.0f / var_f5_998;
    } else {
        var_f4_1065 = 0.0f;
    }
    sp8C = (*(f32 *) ((u8 *) &sp208 + 0x4)) * var_f4_1065;
    sp88 = (f32) sp208 * var_f4_1065;
    sp90 = (f32) sp210 * var_f4_1065;
    sp328 = (f64) sp88;
    sp330 = (f64) sp90;
    temp_f1_1083 = sp338 - M2C_FIELD(&arg0, f64 *, 0);
    sp78 = temp_f1_1083;
    sp1F8 = temp_f1_1083;
    sp80 = (f32) sp340 - arg0.unk8;
    temp_f0_1095 = 100.0f * (112.0f * arg1);
    sp200 = (f64) sp80;
    temp_f21_1103 = ((f32) sp200 * (f32) sp200) + (((f32) sp1F8 * (f32) sp1F8) + ((*(f32 *) ((u8 *) &sp1F8 + 0x4)) * (*(f32 *) ((u8 *) &sp1F8 + 0x4))));
    if (temp_f21_1103 <= (temp_f0_1095 * temp_f0_1095)) {
        M2C_STRUCT_COPY((s32) &sp370.unk3C + 4, (s32) (M2C_FIELD(&gb, void **, 0x3B8) + 0xAC) + 4, 0x70);
        if (sp3B0.IsVisible(arg0, 100.0f * (25.0f * arg1)) != 0) {
            sp68 = 1.0f;
            sp6C = 0.0f;
            sp70 = 0.2f;
            sp74 = 1.0f;
            sp1E8 = (f64) sp68;
            sp1F0 = (f64) sp70;
            gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp1E8), 3.0f * gUpdateTimeDelta);
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            temp_f2_1154 = 2000.0f * (1.0f + arg1);
            temp_f30_1157 = 1.0f - (temp_f21_1103 / (temp_f2_1154 * temp_f2_1154));
            if (temp_f30_1157 > 0.0f) {
                sp34C = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp1C8.operator*(500.0f);
                sp48 = sp1C8 * (f64) temp_f30_1157;
                sp348 = 0x417;
                sp350 = sp48;
                sp50 = sp1C8.unk8 * temp_f30_1157;
                sp360 = 1;
                sp358 = (f64) sp50;
                sp1D8 = sp48;
                sp1E0 = (f64) sp50;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp348, sp48);
            }
        }
    }
    M2C_STRUCT_COPY((s32) &sp36C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp60 = 0.0f;
    sp58 = 0.0f;
    sp5C = 1.0f;
    sp320 = (f64) sp60;
    sp318 = (f64) sp58;
    KDMath_BuildMatrixFromFwd(&sp370, *((MKVector3 *) &sp328), (MKVector3 *) &sp318);
    sp370.Scale3x3(&sp370, arg1);
    sp28 = -(f32) sp328;
    sp2C = -(*(f32 *) ((u8 *) &sp328 + 0x4));
    sp30 = -(f32) sp330;
    sp178 = (f64) sp28;
    sp180 = (f64) sp30;
    sp188.operator*(700.0f);
    sp198.operator*(arg1);
    sp38 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp198);
    sp1A8 = sp38;
    sp40 = arg0.unk8 + sp198.unk8;
    sp1B0 = (f64) sp40;
    sp370.unk30 = (f32) sp1A8;
    sp370.unk34 = (*(f32 *) ((u8 *) &sp1A8 + 0x4));
    sp370.unk38 = (f32) sp1B0;
    sp370.unk3C = 1.0f;
    gb.unk1C0.StartWarp(&sp370);
    temp_r3_1269 = this->unk50;
    if ((u32) M2C_FIELD(temp_r3_1269, u32 *, -4) != 0U) {
        temp_r3_1273 = temp_r3_1269 - 4;
        this->unk50 = temp_r3_1273;
        temp_r3_1275 = *temp_r3_1273;
        if (temp_r3_1275 != NULL) {
            M2C_FIELD(temp_r3_1275, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r3_1275, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r3_1275, s32 *, 0x18) = 1;
            M2C_FIELD(temp_r3_1275, f32 *, 0x10) = 1.0f;
            M2C_FIELD(temp_r3_1275, f32 *, 0x14) = arg1;
            M2C_FIELD(temp_r3_1275, s32 *, 0x1C) = 1;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void DynamiteExplosion::TriggerIce(const MKVector3 &arg0, float arg1, bool arg2) {
    Frustum sp4B0;
    Matrix sp470;
    Matrix sp430;
    M2C_UNK sp42C;
    s8 sp428;
    f64 sp420;
    f64 sp418;
    s32 sp414;
    s32 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    MKVector3 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    MKVector3 sp350;
    M2C_UNK sp340;
    f64 sp338;
    f64 sp330;
    MKVector3 sp320;
    MKVector3 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    MKVector3 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    MKVector3 sp280;
    MKVector3 sp270;
    MKVector3 sp260;
    M2C_UNK sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    MKVector3 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    MKVector3 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f64 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKPropDescriptor *temp_r3_2134;
    f32 temp_f0_1651;
    f32 temp_f1_1393;
    f32 temp_f1_1840;
    f32 temp_f1_1860;
    f32 temp_f1_2056;
    f32 temp_f20_1388;
    f32 temp_f21_1391;
    f32 temp_f21_2128;
    f32 temp_f22_1364;
    f32 temp_f22_1971;
    f32 temp_f22_2008;
    f32 temp_f23_1659;
    f32 temp_f28_1711;
    f32 temp_f29_1366;
    f32 temp_f2_1708;
    f32 temp_f30_2015;
    f32 var_f3_1934;
    f32 var_f4_1867;
    f32 var_f5_1621;
    f32 var_f7_1554;
    f64 temp_f0_1537;
    f64 temp_f0_1953;
    f64 temp_f0_2095;
    f64 temp_f1_1873;
    f64 temp_f1_1879;
    f64 temp_f1_1883;
    f64 temp_f4_1560;
    f64 temp_f4_1566;
    f64 temp_f4_1570;
    s32 temp_r24_1374;
    s32 temp_r3_1589;
    s32 temp_r3_1902;
    s32 var_r0_1599;
    s32 var_r0_1912;
    s32 var_r25_1363;
    s32 var_r27_1830;
    s32 var_r27_2127;
    s32 var_r28_2002;
    void *temp_r23_1410;
    void *temp_r23_1466;
    void *temp_r23_1501;
    void *temp_r26_1361;
    void *temp_r3_1401;
    void *temp_r3_1407;
    void *temp_r3_1459;
    void *temp_r3_1463;
    void *temp_r3_1494;
    void *temp_r3_1498;
    void *temp_r3_1530;
    void *temp_r3_2138;

    temp_r26_1361 = checked_cast<DynamiteExplosionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r25_1363 = 0;
    temp_f22_1364 = 3.0f * arg1;
    temp_f29_1366 = 5.0f * arg1;
    temp_r24_1374 = (s32) temp_f22_1364 + 1;
loop_4:
    if (var_r25_1363 < temp_r24_1374) {
        temp_f20_1388 = 6.2831855f * ((f32) var_r25_1363 / (f32) temp_r24_1374);
        temp_f21_1391 = -_table_sinf(1.5707964f + temp_f20_1388);
        temp_f1_1393 = _table_sinf(temp_f20_1388);
        sp88 = temp_f21_1391;
        sp80 = temp_f1_1393;
        sp84 = 0.0f;
        sp408 = (f64) sp88;
        sp400 = (f64) sp80;
        temp_r3_1401 = M2C_FIELD(temp_r26_1361, void **, 0x80);
        sp3C0 = (f64) sp80;
        sp3C8 = (f64) sp88;
        temp_r3_1407 = M2C_FIELD(M2C_FIELD(temp_r3_1401, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_1401, (f64) sp80);
        if (temp_r3_1407 != NULL) {
            temp_r23_1410 = M2C_FIELD(temp_r3_1407, void **, 0x2C);
            M2C_FIELD(temp_r3_1407, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r3_1407, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r3_1407, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_1407, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r3_1407, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
            M2C_FIELD(temp_r3_1407, f32 *, 0x10) = 0.25f;
            M2C_FIELD(temp_r3_1407, f32 *, 0x14) = 0.25f;
            M2C_FIELD(temp_r3_1407, f32 *, 0x18) = 0.25f;
            M2C_FIELD(temp_r3_1407, f32 *, 0x1C) = 1.0f;
            sp3A0.operator*(1000.0f);
            sp70 = sp3A0 * (f64) arg1;
            M2C_FIELD(temp_r23_1410, f64 *, 0) = sp70;
            sp78 = sp3A0.unk8 * arg1;
            sp3B0 = sp70;
            M2C_FIELD(temp_r23_1410, f64 *, 8) = (f64) sp78;
            sp3B8 = (f64) sp78;
            M2C_FIELD(temp_r23_1410, f32 *, 0x18) = temp_f29_1366;
            M2C_FIELD(temp_r23_1410, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f);
            M2C_FIELD(temp_r23_1410, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r26_1361, void **, 0x80), f32 *, 0xF4);
        }
        var_r25_1363 += 1;
        goto loop_4;
    }
    temp_r3_1459 = M2C_FIELD(temp_r26_1361, void **, 0x70);
    temp_r3_1463 = M2C_FIELD(M2C_FIELD(temp_r3_1459, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_1459);
    if (temp_r3_1463 != NULL) {
        temp_r23_1466 = M2C_FIELD(temp_r3_1463, void **, 0x2C);
        M2C_FIELD(temp_r3_1463, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_1463, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_1463, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_1463, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_1463, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r23_1466, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r23_1466, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r23_1466, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r23_1466, f32 *, 0x18) = (f32) (12.0f * arg1);
        M2C_FIELD(temp_r23_1466, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r23_1466, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r26_1361, void **, 0x70), f32 *, 0xF4);
    }
    temp_r3_1494 = M2C_FIELD(temp_r26_1361, void **, 0x74);
    temp_r3_1498 = M2C_FIELD(M2C_FIELD(temp_r3_1494, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_1494);
    if (temp_r3_1498 != NULL) {
        temp_r23_1501 = M2C_FIELD(temp_r3_1498, void **, 0x2C);
        M2C_FIELD(temp_r3_1498, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_1498, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_1498, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_1498, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_1498, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r23_1501, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r23_1501, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r23_1501, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r23_1501, f32 *, 0x18) = temp_f22_1364;
        M2C_FIELD(temp_r23_1501, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r23_1501, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r26_1361, void **, 0x74), f32 *, 0xF4);
    }
    temp_r3_1530 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp3F0 = M2C_FIELD(temp_r3_1530, f64 *, 0x30);
    sp3F8 = M2C_FIELD(temp_r3_1530, f64 *, 0x38);
    temp_f0_1537 = M2C_FIELD(&arg0, f64 *, 0) - sp3F0;
    sp190 = temp_f0_1537;
    sp390 = temp_f0_1537;
    sp198 = arg0.unk8 - (f32) sp3F8;
    sp398 = (f64) sp198;
    var_f7_1554 = ((f32) sp398 * (f32) sp398) + (((f32) sp390 * (f32) sp390) + ((*(f32 *) ((u8 *) &sp390 + 0x4)) * (*(f32 *) ((u8 *) &sp390 + 0x4))));
    if (var_f7_1554 > 1e-12f) {
        if (var_f7_1554 > 0.0f) {
            temp_f4_1560 = __frsqrte(var_f7_1554);
            temp_f4_1566 = 0.5 * temp_f4_1560 * -(((f64) var_f7_1554 * (temp_f4_1560 * temp_f4_1560)) - 3.0);
            temp_f4_1570 = 0.5 * temp_f4_1566 * -(((f64) var_f7_1554 * (temp_f4_1566 * temp_f4_1566)) - 3.0);
            var_f7_1554 = (f32) ((f64) var_f7_1554 * (0.5 * temp_f4_1570 * -(((f64) var_f7_1554 * (temp_f4_1570 * temp_f4_1570)) - 3.0)));
        } else if (var_f7_1554 < M2C_BITWISE(f32, 0.0)) {
            var_f7_1554 = __float_nan;
        } else {
            sp14 = var_f7_1554;
            temp_r3_1589 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_1589) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1599 = 1;
                } else {
                    var_r0_1599 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1599 = 5;
                } else {
                    var_r0_1599 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1599 = 4;
                break;
            }
            if (var_r0_1599 == 1) {
                var_f7_1554 = __float_nan;
            }
        }
        var_f5_1621 = 1.0f / var_f7_1554;
    } else {
        var_f5_1621 = 0.0f;
    }
    sp184 = (*(f32 *) ((u8 *) &sp390 + 0x4)) * var_f5_1621;
    sp180 = (f32) sp390 * var_f5_1621;
    sp188 = (f32) sp398 * var_f5_1621;
    sp3E0 = (f64) sp180;
    sp3E8 = (f64) sp188;
    sp170 = sp3F0 - M2C_FIELD(&arg0, f64 *, 0);
    sp380 = sp170;
    sp178 = (f32) sp3F8 - arg0.unk8;
    temp_f0_1651 = 100.0f * (112.0f * arg1);
    sp388 = (f64) sp178;
    temp_f23_1659 = ((f32) sp388 * (f32) sp388) + (((f32) sp380 * (f32) sp380) + ((*(f32 *) ((u8 *) &sp380 + 0x4)) * (*(f32 *) ((u8 *) &sp380 + 0x4))));
    if (temp_f23_1659 <= (temp_f0_1651 * temp_f0_1651)) {
        M2C_STRUCT_COPY((s32) &sp470.unk3C + 4, (s32) (M2C_FIELD(&gb, void **, 0x3B8) + 0xAC) + 4, 0x70);
        if (sp4B0.IsVisible(arg0, 100.0f * (25.0f * arg1)) != 0) {
            sp160 = 1.0f;
            sp164 = 1.0f;
            sp168 = 1.0f;
            sp16C = 1.0f;
            sp370 = (f64) sp160;
            sp378 = (f64) sp168;
            gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp370), 3.0f * gUpdateTimeDelta);
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            temp_f2_1708 = 2000.0f * (1.0f + arg1);
            temp_f28_1711 = 1.0f - (temp_f23_1659 / (temp_f2_1708 * temp_f2_1708));
            if (temp_f28_1711 > 0.0f) {
                sp414 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp350.operator*(500.0f);
                sp60 = sp350 * (f64) temp_f28_1711;
                sp410 = 0x417;
                sp418 = sp60;
                sp68 = sp350.unk8 * temp_f28_1711;
                sp428 = 1;
                sp420 = (f64) sp68;
                sp360 = sp60;
                sp368 = (f64) sp68;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp410, sp60);
            }
        }
    }
    M2C_STRUCT_COPY((s32) &sp430.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp158 = 0.0f;
    sp150 = 0.0f;
    sp154 = 1.0f;
    sp3D8 = (f64) sp158;
    sp3D0 = (f64) sp150;
    KDMath_BuildMatrixFromFwd(&sp470, *((MKVector3 *) &sp3E0), (MKVector3 *) &sp3D0);
    sp470.Scale3x3(&sp470, arg1);
    sp20 = -(f32) sp3E0;
    sp24 = -(*(f32 *) ((u8 *) &sp3E0 + 0x4));
    sp28 = -(f32) sp3E8;
    sp300 = (f64) sp20;
    sp308 = (f64) sp28;
    sp310.operator*(700.0f);
    sp320.operator*(arg1);
    sp50 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp320);
    sp330 = sp50;
    sp58 = arg0.unk8 + sp320.unk8;
    sp338 = (f64) sp58;
    sp470.unk30 = (f32) sp330;
    sp470.unk34 = (*(f32 *) ((u8 *) &sp330 + 0x4));
    sp470.unk38 = (f32) sp338;
    sp470.unk3C = 1.0f;
    gb.unk1C0.StartWarp(&sp470);
    var_r27_1830 = 0;
loop_57:
    if (var_r27_1830 < (s32) (20.0f * arg1)) {
        temp_f1_1840 = MKRand_Float((int *) &gViewSeed, 2000.0f, 3000.0f);
        sp148 = -1.0f;
        sp138 = 1.0f;
        sp140 = -1.0f;
        sp144 = 0.0f;
        sp130 = 1.0f;
        sp134 = 1.0f;
        sp2C0 = (f64) sp140;
        sp2C8 = (f64) sp148;
        sp2B0 = (f64) sp130;
        sp2B8 = (f64) sp138;
        KDRand_Vector(sp2D0, *((MKVector3 *) &sp2C0));
        temp_f1_1860 = M2C_BITWISE(f32, sp2D0);
        var_f4_1867 = (sp2D0.unk8 * sp2D0.unk8) + ((temp_f1_1860 * temp_f1_1860) + (sp2D0.unk4 * sp2D0.unk4));
        if (var_f4_1867 > 1e-12f) {
            if (var_f4_1867 > 0.0f) {
                temp_f1_1873 = __frsqrte(var_f4_1867);
                temp_f1_1879 = 0.5 * temp_f1_1873 * -(((f64) var_f4_1867 * (temp_f1_1873 * temp_f1_1873)) - 3.0);
                temp_f1_1883 = 0.5 * temp_f1_1879 * -(((f64) var_f4_1867 * (temp_f1_1879 * temp_f1_1879)) - 3.0);
                var_f4_1867 = (f32) ((f64) var_f4_1867 * (0.5 * temp_f1_1883 * -(((f64) var_f4_1867 * (temp_f1_1883 * temp_f1_1883)) - 3.0)));
            } else if (var_f4_1867 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1867 = __float_nan;
            } else {
                sp10 = var_f4_1867;
                temp_r3_1902 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1902) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1912 = 1;
                    } else {
                        var_r0_1912 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1912 = 5;
                    } else {
                        var_r0_1912 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1912 = 4;
                    break;
                }
                if (var_r0_1912 == 1) {
                    var_f4_1867 = __float_nan;
                }
            }
            var_f3_1934 = 1.0f / var_f4_1867;
        } else {
            var_f3_1934 = 0.0f;
        }
        sp100 = M2C_BITWISE(f32, sp2D0) * var_f3_1934;
        sp104 = sp2D0.unk4 * var_f3_1934;
        sp108 = sp2D0.unk8 * var_f3_1934;
        sp2E0 = (f64) sp100;
        sp2E8 = (f64) sp108;
        temp_f0_1953 = sp2E0 * (f64) temp_f1_1840;
        sp120 = temp_f0_1953;
        sp2F0 = temp_f0_1953;
        sp128 = (f32) sp2E8 * temp_f1_1840;
        sp2F8 = (f64) sp128;
        sp18 = MKRand_Float((int *) &gViewSeed, 12.0f, 20.0f);
        temp_f22_1971 = MKRand_Float((int *) &gViewSeed, 0.35f, 5.0f);
        sp110 = MKRand_Float((int *) &gViewSeed, 0.35f, 5.0f);
        sp114 = temp_f22_1971;
        sp118 = 1.0f;
        sp11C = 1.0f;
        sp2A0 = (f64) sp110;
        sp2A8 = (f64) sp118;
        ((EmbersPS *) gb.unk74)->Emit(arg0, *((MKVector3 *) &sp2F0), sp18, *((MKVector4 *) &sp2A0), -2000.0f);
        var_r27_1830 += 1;
        goto loop_57;
    }
    var_r28_2002 = 0;
    temp_f22_2008 = arg0.unk8;
loop_60:
    if (var_r28_2002 < (s32) temp_f29_1366) {
        temp_f30_2015 = MKRand_Float((int *) &gViewSeed, 2500.0f, 3500.0f);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.5f, -1.0f);
        KDRand_Vector(sp270, sp260);
        Normalise(sp280);
        sp40 = sp280 * (f64) temp_f30_2015;
        sp90 = 0.5f;
        sp94 = 0.5f;
        sp48 = sp280.unk8 * temp_f30_2015;
        sp98 = 0.5f;
        sp9C = 1.0f;
        sp290 = sp40;
        sp298 = (f64) sp48;
        sp400 = sp40;
        sp408 = (f64) sp48;
        sp1C0 = (f64) sp90;
        sp1C8 = (f64) sp98;
        temp_f1_2056 = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
        spF0 = 0.0f;
        spF4 = 75.0f;
        spA8 = 3.1415927f;
        spB8 = -3.1415927f;
        spC8 = 3.1415927f;
        spD8 = -3.1415927f;
        spF8 = 0.0f;
        spA0 = 3.1415927f;
        spA4 = 3.1415927f;
        spB0 = -3.1415927f;
        spB4 = -3.1415927f;
        spC0 = 3.1415927f;
        spC4 = 3.1415927f;
        spD0 = -3.1415927f;
        spD4 = -3.1415927f;
        sp230 = (f64) spF0;
        sp1D0 = (f64) spA0;
        sp1D8 = (f64) spA8;
        sp1E0 = (f64) spB0;
        sp1E8 = (f64) spB8;
        sp200 = (f64) spC0;
        sp208 = (f64) spC8;
        sp210 = (f64) spD0;
        sp218 = (f64) spD8;
        sp238 = (f64) spF8;
        temp_f0_2095 = M2C_FIELD(&arg0, f64 *, 0) + sp230;
        spE0 = temp_f0_2095;
        sp240 = temp_f0_2095;
        spE8 = temp_f22_2008 + (f32) sp238;
        sp248 = (f64) spE8;
        KDRand_Vector(sp1F0, *((MKVector3 *) &sp1E0));
        KDRand_Vector(sp220, *((MKVector3 *) &sp210));
        ((FlyingChunkPS *) gb.unkA8)->Emit(*((MKVector3 *) &sp240), *((MKVector3 *) &sp400), sp220, sp1F0, temp_f1_2056, *((MKVector4 *) &sp1C0), 0, NULL);
        var_r28_2002 += 1;
        goto loop_60;
    }
    var_r27_2127 = 0;
    temp_f21_2128 = 2.0f * arg1;
loop_66:
    if (var_r27_2127 < (s32) temp_f21_2128) {
        temp_r3_2134 = this->unk4C;
        if (temp_r3_2134 != NULL) {
            temp_r3_2138 = checked_cast<PooledShatterProp *, MKProp>(temp_r3_2134->CreateInstance());
            if (temp_r3_2138 != NULL) {
                M2C_FIELD(M2C_FIELD(temp_r3_2138, void **, 0x44), M2C_UNK (**)(), 0x20)();
                M2C_FIELD(M2C_FIELD(temp_r3_2138, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_2138);
                M2C_STRUCT_COPY((s32) &sp42C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp430.Scale3x3(&sp430, temp_f21_2128);
                MKVector(0.0f, 50.0f, 0.0f);
                sp30 = M2C_FIELD(&arg0, f64 *, 0) + sp1A0;
                sp1B0 = sp30;
                sp38 = arg0.unk8 + sp1A8;
                sp1B8 = (f64) sp38;
                sp430.unk30 = (f32) sp1B0;
                sp430.unk34 = (*(f32 *) ((u8 *) &sp1B0 + 0x4));
                sp430.unk38 = (f32) sp1B8;
                sp430.unk3C = 1.0f;
                MKModel_SetWorldMatrix(M2C_FIELD(temp_r3_2138, MKModel **, 4), sp430);
                M2C_FIELD(M2C_FIELD(temp_r3_2138, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r3_2138, 0, 0, -1, 0, 1, 0);
            }
        }
        var_r27_2127 += 1;
        goto loop_66;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void DynamiteExplosion::TriggerEarth(const MKVector3 &arg0, float arg1, bool arg2) {
    Frustum sp4C0;
    Matrix sp480;
    M2C_UNK sp47C;
    s8 sp470;
    f64 sp468;
    f64 sp460;
    s32 sp45C;
    s32 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    MKVector3 sp3C8;
    M2C_UNK sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    MKVector3 sp398;
    MKVector3 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    MKVector3 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    MKVector3 sp2F8;
    MKVector3 sp2E8;
    MKVector3 sp2D8;
    M2C_UNK sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    MKVector3 sp288;
    M2C_UNK sp278;
    f64 sp270;
    f64 sp268;
    MKVector3 sp258;
    MKVector3 sp248;
    MKVector3 sp238;
    M2C_UNK sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f32 sp190;
    f64 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f64 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f64 spD8;
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
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_2471;
    f32 temp_f1_2661;
    f32 temp_f1_2681;
    f32 temp_f1_2978;
    f32 temp_f22_2792;
    f32 temp_f23_2871;
    f32 temp_f24_2827;
    f32 temp_f24_2928;
    f32 temp_f25_2479;
    f32 temp_f26_2532;
    f32 temp_f2_2529;
    f32 temp_f31_2937;
    f32 var_f3_2755;
    f32 var_f4_2688;
    f32 var_f5_2441;
    f32 var_f7_2374;
    f64 temp_f0_2357;
    f64 temp_f0_2774;
    f64 temp_f0_3017;
    f64 temp_f1_2694;
    f64 temp_f1_2700;
    f64 temp_f1_2704;
    f64 temp_f4_2380;
    f64 temp_f4_2386;
    f64 temp_f4_2390;
    s32 temp_r31_2655;
    s32 temp_r3_2409;
    s32 temp_r3_2723;
    s32 var_r0_2419;
    s32 var_r0_2733;
    s32 var_r26_2651;
    s32 var_r26_2820;
    s32 var_r29_2924;
    void *temp_r26_2284;
    void *temp_r26_2319;
    void *temp_r3_2275;
    void *temp_r3_2277;
    void *temp_r3_2281;
    void *temp_r3_2312;
    void *temp_r3_2316;
    void *temp_r3_2350;

    temp_r3_2275 = checked_cast<DynamiteExplosionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_2277 = M2C_FIELD(temp_r3_2275, void **, 0x78);
    temp_r3_2281 = M2C_FIELD(M2C_FIELD(temp_r3_2277, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2277);
    if (temp_r3_2281 != NULL) {
        temp_r26_2284 = M2C_FIELD(temp_r3_2281, void **, 0x2C);
        M2C_FIELD(temp_r3_2281, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_2281, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_2281, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_2281, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_2281, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r26_2284, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r26_2284, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r26_2284, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r26_2284, f32 *, 0x18) = (f32) (12.0f * arg1);
        M2C_FIELD(temp_r26_2284, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r26_2284, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2275, void **, 0x78), f32 *, 0xF4);
    }
    temp_r3_2312 = M2C_FIELD(temp_r3_2275, void **, 0x7C);
    temp_r3_2316 = M2C_FIELD(M2C_FIELD(temp_r3_2312, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2312);
    if (temp_r3_2316 != NULL) {
        temp_r26_2319 = M2C_FIELD(temp_r3_2316, void **, 0x2C);
        M2C_FIELD(temp_r3_2316, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_2316, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_2316, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_2316, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_2316, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r26_2319, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r26_2319, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r26_2319, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r26_2319, f32 *, 0x18) = (f32) (3.0f * arg1);
        M2C_FIELD(temp_r26_2319, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r26_2319, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2275, void **, 0x7C), f32 *, 0xF4);
    }
    temp_r3_2350 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp438 = M2C_FIELD(temp_r3_2350, f64 *, 0x30);
    sp440 = M2C_FIELD(temp_r3_2350, f64 *, 0x38);
    temp_f0_2357 = M2C_FIELD(&arg0, f64 *, 0) - sp438;
    sp188 = temp_f0_2357;
    sp408 = temp_f0_2357;
    sp190 = arg0.unk8 - (f32) sp440;
    sp410 = (f64) sp190;
    var_f7_2374 = ((f32) sp410 * (f32) sp410) + (((f32) sp408 * (f32) sp408) + ((*(f32 *) ((u8 *) &sp408 + 0x4)) * (*(f32 *) ((u8 *) &sp408 + 0x4))));
    if (var_f7_2374 > 1e-12f) {
        if (var_f7_2374 > 0.0f) {
            temp_f4_2380 = __frsqrte(var_f7_2374);
            temp_f4_2386 = 0.5 * temp_f4_2380 * -(((f64) var_f7_2374 * (temp_f4_2380 * temp_f4_2380)) - 3.0);
            temp_f4_2390 = 0.5 * temp_f4_2386 * -(((f64) var_f7_2374 * (temp_f4_2386 * temp_f4_2386)) - 3.0);
            var_f7_2374 = (f32) ((f64) var_f7_2374 * (0.5 * temp_f4_2390 * -(((f64) var_f7_2374 * (temp_f4_2390 * temp_f4_2390)) - 3.0)));
        } else if (var_f7_2374 < M2C_BITWISE(f32, 0.0)) {
            var_f7_2374 = __float_nan;
        } else {
            sp14 = var_f7_2374;
            temp_r3_2409 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_2409) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2419 = 1;
                } else {
                    var_r0_2419 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2419 = 5;
                } else {
                    var_r0_2419 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_2419 = 4;
                break;
            }
            if (var_r0_2419 == 1) {
                var_f7_2374 = __float_nan;
            }
        }
        var_f5_2441 = 1.0f / var_f7_2374;
    } else {
        var_f5_2441 = 0.0f;
    }
    sp17C = (*(f32 *) ((u8 *) &sp408 + 0x4)) * var_f5_2441;
    sp178 = (f32) sp408 * var_f5_2441;
    sp180 = (f32) sp410 * var_f5_2441;
    sp428 = (f64) sp178;
    sp430 = (f64) sp180;
    sp168 = sp438 - M2C_FIELD(&arg0, f64 *, 0);
    sp3F8 = sp168;
    sp170 = (f32) sp440 - arg0.unk8;
    temp_f0_2471 = 100.0f * (112.0f * arg1);
    sp400 = (f64) sp170;
    temp_f25_2479 = ((f32) sp400 * (f32) sp400) + (((f32) sp3F8 * (f32) sp3F8) + ((*(f32 *) ((u8 *) &sp3F8 + 0x4)) * (*(f32 *) ((u8 *) &sp3F8 + 0x4))));
    if (temp_f25_2479 <= (temp_f0_2471 * temp_f0_2471)) {
        M2C_STRUCT_COPY((s32) &sp480.unk3C + 4, (s32) (M2C_FIELD(&gb, void **, 0x3B8) + 0xAC) + 4, 0x70);
        if (sp4C0.IsVisible(arg0, 100.0f * (25.0f * arg1)) != 0) {
            sp158 = 0.5f;
            sp15C = 1.0f;
            sp160 = 0.5f;
            sp164 = 1.0f;
            sp3E8 = (f64) sp158;
            sp3F0 = (f64) sp160;
            gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp3E8), 3.0f * gUpdateTimeDelta);
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            temp_f2_2529 = 2000.0f * (1.0f + arg1);
            temp_f26_2532 = 1.0f - (temp_f25_2479 / (temp_f2_2529 * temp_f2_2529));
            if (temp_f26_2532 > 0.0f) {
                sp45C = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp3C8.operator*(500.0f);
                sp78 = sp3C8 * (f64) temp_f26_2532;
                sp458 = 0x417;
                sp460 = sp78;
                sp80 = sp3C8.unk8 * temp_f26_2532;
                sp470 = 1;
                sp468 = (f64) sp80;
                sp3D8 = sp78;
                sp3E0 = (f64) sp80;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp458, sp78);
            }
        }
    }
    M2C_STRUCT_COPY((s32) &sp47C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp150 = 0.0f;
    sp148 = 0.0f;
    sp14C = 1.0f;
    sp420 = (f64) sp150;
    sp418 = (f64) sp148;
    KDMath_BuildMatrixFromFwd(&sp480, *((MKVector3 *) &sp428), (MKVector3 *) &sp418);
    sp480.Scale3x3(&sp480, arg1);
    sp28 = -(f32) sp428;
    sp2C = -(*(f32 *) ((u8 *) &sp428 + 0x4));
    sp30 = -(f32) sp430;
    sp378 = (f64) sp28;
    sp380 = (f64) sp30;
    sp388.operator*(700.0f);
    sp398.operator*(arg1);
    sp68 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp398);
    sp3A8 = sp68;
    sp70 = arg0.unk8 + sp398.unk8;
    sp3B0 = (f64) sp70;
    sp480.unk30 = (f32) sp3A8;
    sp480.unk34 = (*(f32 *) ((u8 *) &sp3A8 + 0x4));
    sp480.unk38 = (f32) sp3B0;
    sp480.unk3C = 1.0f;
    gb.unk1C0.StartWarp(&sp480);
    var_r26_2651 = 0;
    temp_r31_2655 = (s32) (20.0f * arg1);
loop_52:
    if (var_r26_2651 < temp_r31_2655) {
        temp_f1_2661 = MKRand_Float((int *) &gViewSeed, 2000.0f, 3000.0f);
        sp140 = -1.0f;
        sp130 = 1.0f;
        sp138 = -1.0f;
        sp13C = 0.0f;
        sp128 = 1.0f;
        sp12C = 1.0f;
        sp338 = (f64) sp138;
        sp340 = (f64) sp140;
        sp328 = (f64) sp128;
        sp330 = (f64) sp130;
        KDRand_Vector(sp348, *((MKVector3 *) &sp338));
        temp_f1_2681 = M2C_BITWISE(f32, sp348);
        var_f4_2688 = (sp348.unk8 * sp348.unk8) + ((temp_f1_2681 * temp_f1_2681) + (sp348.unk4 * sp348.unk4));
        if (var_f4_2688 > 1e-12f) {
            if (var_f4_2688 > 0.0f) {
                temp_f1_2694 = __frsqrte(var_f4_2688);
                temp_f1_2700 = 0.5 * temp_f1_2694 * -(((f64) var_f4_2688 * (temp_f1_2694 * temp_f1_2694)) - 3.0);
                temp_f1_2704 = 0.5 * temp_f1_2700 * -(((f64) var_f4_2688 * (temp_f1_2700 * temp_f1_2700)) - 3.0);
                var_f4_2688 = (f32) ((f64) var_f4_2688 * (0.5 * temp_f1_2704 * -(((f64) var_f4_2688 * (temp_f1_2704 * temp_f1_2704)) - 3.0)));
            } else if (var_f4_2688 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2688 = __float_nan;
            } else {
                sp10 = var_f4_2688;
                temp_r3_2723 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2723) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2733 = 1;
                    } else {
                        var_r0_2733 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2733 = 5;
                    } else {
                        var_r0_2733 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2733 = 4;
                    break;
                }
                if (var_r0_2733 == 1) {
                    var_f4_2688 = __float_nan;
                }
            }
            var_f3_2755 = 1.0f / var_f4_2688;
        } else {
            var_f3_2755 = 0.0f;
        }
        spF8 = M2C_BITWISE(f32, sp348) * var_f3_2755;
        spFC = sp348.unk4 * var_f3_2755;
        sp100 = sp348.unk8 * var_f3_2755;
        sp358 = (f64) spF8;
        sp360 = (f64) sp100;
        temp_f0_2774 = sp358 * (f64) temp_f1_2661;
        sp118 = temp_f0_2774;
        sp368 = temp_f0_2774;
        sp120 = (f32) sp360 * temp_f1_2661;
        sp370 = (f64) sp120;
        sp20 = MKRand_Float((int *) &gViewSeed, 12.0f, 20.0f);
        temp_f22_2792 = MKRand_Float((int *) &gViewSeed, 0.35f, 5.0f);
        sp108 = MKRand_Float((int *) &gViewSeed, 0.35f, 5.0f);
        sp10C = 1.0f;
        sp110 = temp_f22_2792;
        sp114 = 1.0f;
        sp318 = (f64) sp108;
        sp320 = (f64) sp110;
        ((EmbersPS *) gb.unk74)->Emit(arg0, *((MKVector3 *) &sp368), sp20, *((MKVector4 *) &sp318), -2000.0f);
        var_r26_2651 += 1;
        goto loop_52;
    }
    var_r26_2820 = 0;
loop_55:
    if (var_r26_2820 < temp_r31_2655) {
        temp_f24_2827 = MKRand_Float((int *) &gViewSeed, 500.0f, 1500.0f);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.5f, -1.0f);
        KDRand_Vector(sp2E8, sp2D8);
        Normalise(sp2F8);
        sp58 = sp2F8 * (f64) temp_f24_2827;
        sp308 = sp58;
        sp60 = sp2F8.unk8 * temp_f24_2827;
        sp448 = sp58;
        sp310 = (f64) sp60;
        sp450 = (f64) sp60;
        sp1C = MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f);
        gb.EmitCrud(arg0, *((MKVector3 *) &sp448), sp1C);
        temp_f23_2871 = MKRand_Float((int *) &gViewSeed, 500.0f, 1500.0f);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.5f, -1.0f);
        KDRand_Vector(sp298, sp288);
        Normalise(sp2A8);
        sp48 = sp2A8 * (f64) temp_f23_2871;
        sp2B8 = sp48;
        sp50 = sp2A8.unk8 * temp_f23_2871;
        sp448 = sp48;
        sp2C0 = (f64) sp50;
        sp450 = (f64) sp50;
        sp18 = MKRand_Float((int *) &gViewSeed, 0.5f, 0.75f);
        gb.EmitSmallRocks(arg0, *((MKVector3 *) &sp448), sp18);
        var_r26_2820 += 1;
        goto loop_55;
    }
    var_r29_2924 = 0;
    temp_f24_2928 = arg0.unk8;
loop_58:
    if (var_r29_2924 < (s32) (5.0f * arg1)) {
        temp_f31_2937 = MKRand_Float((int *) &gViewSeed, 2500.0f, 3500.0f);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.5f, -1.0f);
        KDRand_Vector(sp248, sp238);
        Normalise(sp258);
        sp38 = sp258 * (f64) temp_f31_2937;
        sp88 = 0.5f;
        sp8C = 0.5f;
        sp40 = sp258.unk8 * temp_f31_2937;
        sp90 = 0.5f;
        sp94 = 1.0f;
        sp268 = sp38;
        sp270 = (f64) sp40;
        sp448 = sp38;
        sp450 = (f64) sp40;
        sp198 = (f64) sp88;
        sp1A0 = (f64) sp90;
        temp_f1_2978 = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
        spE8 = 0.0f;
        spEC = 75.0f;
        spA0 = 3.1415927f;
        spB0 = -3.1415927f;
        spC0 = 3.1415927f;
        spD0 = -3.1415927f;
        spF0 = 0.0f;
        sp98 = 3.1415927f;
        sp9C = 3.1415927f;
        spA8 = -3.1415927f;
        spAC = -3.1415927f;
        spB8 = 3.1415927f;
        spBC = 3.1415927f;
        spC8 = -3.1415927f;
        spCC = -3.1415927f;
        sp208 = (f64) spE8;
        sp1A8 = (f64) sp98;
        sp1B0 = (f64) spA0;
        sp1B8 = (f64) spA8;
        sp1C0 = (f64) spB0;
        sp1D8 = (f64) spB8;
        sp1E0 = (f64) spC0;
        sp1E8 = (f64) spC8;
        sp1F0 = (f64) spD0;
        sp210 = (f64) spF0;
        temp_f0_3017 = M2C_FIELD(&arg0, f64 *, 0) + sp208;
        spD8 = temp_f0_3017;
        sp218 = temp_f0_3017;
        spE0 = temp_f24_2928 + (f32) sp210;
        sp220 = (f64) spE0;
        KDRand_Vector(sp1C8, *((MKVector3 *) &sp1B8));
        KDRand_Vector(sp1F8, *((MKVector3 *) &sp1E8));
        ((FlyingChunkPS *) gb.unkAC)->Emit(*((MKVector3 *) &sp218), *((MKVector3 *) &sp448), sp1F8, sp1C8, temp_f1_2978, *((MKVector4 *) &sp198), 0, NULL);
        var_r29_2924 += 1;
        goto loop_58;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void DynamiteExplosion::TriggerFire(const MKVector3 &arg0, float arg1, bool arg2) {
    Frustum sp470;
    Matrix sp430;
    M2C_UNK sp42C;
    s8 sp428;
    f64 sp420;
    f64 sp418;
    s32 sp414;
    s32 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    MKVector3 sp3A0;
    f64 sp398;
    f64 sp390;
    MKVector3 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    MKVector3 sp330;
    M2C_UNK sp320;
    f64 sp318;
    f64 sp310;
    MKVector3 sp300;
    MKVector3 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    MKVector3 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    MKVector3 sp260;
    MKVector3 sp250;
    MKVector3 sp240;
    M2C_UNK sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    MKVector3 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f64 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_3445;
    f32 temp_f19_3183;
    f32 temp_f1_3188;
    f32 temp_f1_3636;
    f32 temp_f1_3656;
    f32 temp_f1_3849;
    f32 temp_f20_3186;
    f32 temp_f21_3506;
    f32 temp_f21_3799;
    f32 temp_f22_3119;
    f32 temp_f25_3453;
    f32 temp_f2_3503;
    f32 temp_f31_3808;
    f32 var_f3_3730;
    f32 var_f4_3415;
    f32 var_f4_3663;
    f32 var_f5_3348;
    f64 temp_f0_3749;
    f64 temp_f0_3888;
    f64 temp_f1_3433;
    f64 temp_f1_3669;
    f64 temp_f1_3675;
    f64 temp_f1_3679;
    f64 temp_f2_3354;
    f64 temp_f2_3360;
    f64 temp_f2_3364;
    s32 temp_r25_3125;
    s32 temp_r3_3383;
    s32 temp_r3_3698;
    s32 temp_r4_3124;
    s32 var_r0_3393;
    s32 var_r0_3708;
    s32 var_r26_3163;
    s32 var_r28_3625;
    s32 var_r29_3795;
    void *temp_r24_3205;
    void *temp_r24_3251;
    void *temp_r24_3295;
    void *temp_r26_3130;
    void *temp_r3_3115;
    void *temp_r3_3118;
    void *temp_r3_3127;
    void *temp_r3_3196;
    void *temp_r3_3202;
    void *temp_r3_3244;
    void *temp_r3_3248;
    void *temp_r3_3288;
    void *temp_r3_3292;
    void *temp_r3_3324;

    temp_r3_3115 = checked_cast<DynamiteExplosionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_3118 = M2C_FIELD(temp_r3_3115, void **, 0x60);
    temp_f22_3119 = 3.0f * arg1;
    temp_r4_3124 = (s32) temp_f22_3119;
    temp_r25_3125 = temp_r4_3124 + 1;
    temp_r3_3127 = M2C_FIELD(M2C_FIELD(temp_r3_3118, void **, 0x44), void *(**)(void *, s32), 0x3C)(temp_r3_3118, temp_r4_3124);
    if (temp_r3_3127 != NULL) {
        temp_r26_3130 = M2C_FIELD(temp_r3_3127, void **, 0x2C);
        M2C_FIELD(temp_r3_3127, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_3127, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_3127, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_3127, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_3127, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r26_3130, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r26_3130, f32 *, 4) = (f32) (1000.0f * arg1);
        M2C_FIELD(temp_r26_3130, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r26_3130, f32 *, 0x18) = (f32) (2.0f * arg1);
        M2C_FIELD(temp_r26_3130, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f);
        M2C_FIELD(temp_r26_3130, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_3115, void **, 0x60), f32 *, 0xF4);
    }
    var_r26_3163 = 0;
loop_8:
    if (var_r26_3163 < temp_r25_3125) {
        temp_f19_3183 = 6.2831855f * ((f32) var_r26_3163 / (f32) temp_r25_3125);
        temp_f20_3186 = -_table_sinf(1.5707964f + temp_f19_3183);
        temp_f1_3188 = _table_sinf(temp_f19_3183);
        sp88 = temp_f20_3186;
        sp80 = temp_f1_3188;
        sp84 = 0.0f;
        sp408 = (f64) sp88;
        sp400 = (f64) sp80;
        temp_r3_3196 = M2C_FIELD(temp_r3_3115, void **, 0x60);
        sp3C0 = (f64) sp80;
        sp3C8 = (f64) sp88;
        temp_r3_3202 = M2C_FIELD(M2C_FIELD(temp_r3_3196, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_3196, (f64) sp80);
        if (temp_r3_3202 != NULL) {
            temp_r24_3205 = M2C_FIELD(temp_r3_3202, void **, 0x2C);
            M2C_FIELD(temp_r3_3202, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r3_3202, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r3_3202, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_3202, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r3_3202, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
            sp3A0.operator*(1000.0f);
            sp70 = sp3A0 * (f64) arg1;
            M2C_FIELD(temp_r24_3205, f64 *, 0) = sp70;
            sp78 = sp3A0.unk8 * arg1;
            sp3B0 = sp70;
            M2C_FIELD(temp_r24_3205, f64 *, 8) = (f64) sp78;
            sp3B8 = (f64) sp78;
            M2C_FIELD(temp_r24_3205, f32 *, 0x18) = (f32) (2.0f * arg1);
            M2C_FIELD(temp_r24_3205, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f);
            M2C_FIELD(temp_r24_3205, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_3115, void **, 0x60), f32 *, 0xF4);
        }
        temp_r3_3244 = M2C_FIELD(temp_r3_3115, void **, 0x68);
        temp_r3_3248 = M2C_FIELD(M2C_FIELD(temp_r3_3244, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_3244);
        if (temp_r3_3248 != NULL) {
            temp_r24_3251 = M2C_FIELD(temp_r3_3248, void **, 0x2C);
            M2C_FIELD(temp_r3_3248, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r3_3248, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r3_3248, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_3248, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r3_3248, f32 *, 0x24) = 0.0f;
            sp380.operator*(500.0f);
            sp60 = sp380 * (f64) arg1;
            M2C_FIELD(temp_r24_3251, f64 *, 0) = sp60;
            sp68 = sp380.unk8 * arg1;
            sp390 = sp60;
            M2C_FIELD(temp_r24_3251, f64 *, 8) = (f64) sp68;
            M2C_FIELD(temp_r24_3251, f32 *, 0x18) = (f32) (4.5f * arg1);
            M2C_FIELD(temp_r24_3251, f32 *, 0x10) = 0.0f;
            sp398 = (f64) sp68;
            M2C_FIELD(temp_r24_3251, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_3115, void **, 0x68), f32 *, 0xF4);
        }
        var_r26_3163 += 1;
        goto loop_8;
    }
    temp_r3_3288 = M2C_FIELD(temp_r3_3115, void **, 0x64);
    temp_r3_3292 = M2C_FIELD(M2C_FIELD(temp_r3_3288, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_3288);
    if (temp_r3_3292 != NULL) {
        temp_r24_3295 = M2C_FIELD(temp_r3_3292, void **, 0x2C);
        M2C_FIELD(temp_r3_3292, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_3292, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_3292, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_3292, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_3292, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r24_3295, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r24_3295, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r24_3295, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r24_3295, f32 *, 0x18) = temp_f22_3119;
        M2C_FIELD(temp_r24_3295, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r24_3295, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_3115, void **, 0x64), f32 *, 0xF4);
    }
    temp_r3_3324 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp3F0 = M2C_FIELD(temp_r3_3324, f64 *, 0x30);
    sp3F8 = M2C_FIELD(temp_r3_3324, f64 *, 0x38);
    sp190 = M2C_FIELD(&arg0, f64 *, 0) - sp3F0;
    sp370 = sp190;
    sp198 = arg0.unk8 - (f32) sp3F8;
    sp378 = (f64) sp198;
    var_f5_3348 = ((f32) sp378 * (f32) sp378) + (((f32) sp370 * (f32) sp370) + ((*(f32 *) ((u8 *) &sp370 + 0x4)) * (*(f32 *) ((u8 *) &sp370 + 0x4))));
    if (var_f5_3348 > 1e-12f) {
        if (var_f5_3348 > 0.0f) {
            temp_f2_3354 = __frsqrte(var_f5_3348);
            temp_f2_3360 = 0.5 * temp_f2_3354 * -(((f64) var_f5_3348 * (temp_f2_3354 * temp_f2_3354)) - 3.0);
            temp_f2_3364 = 0.5 * temp_f2_3360 * -(((f64) var_f5_3348 * (temp_f2_3360 * temp_f2_3360)) - 3.0);
            var_f5_3348 = (f32) ((f64) var_f5_3348 * (0.5 * temp_f2_3364 * -(((f64) var_f5_3348 * (temp_f2_3364 * temp_f2_3364)) - 3.0)));
        } else if (var_f5_3348 < M2C_BITWISE(f32, 0.0)) {
            var_f5_3348 = __float_nan;
        } else {
            sp14 = var_f5_3348;
            temp_r3_3383 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_3383) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_3393 = 1;
                } else {
                    var_r0_3393 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_3393 = 5;
                } else {
                    var_r0_3393 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_3393 = 4;
                break;
            }
            if (var_r0_3393 == 1) {
                var_f5_3348 = __float_nan;
            }
        }
        var_f4_3415 = 1.0f / var_f5_3348;
    } else {
        var_f4_3415 = 0.0f;
    }
    sp184 = (*(f32 *) ((u8 *) &sp370 + 0x4)) * var_f4_3415;
    sp180 = (f32) sp370 * var_f4_3415;
    sp188 = (f32) sp378 * var_f4_3415;
    sp3E0 = (f64) sp180;
    sp3E8 = (f64) sp188;
    temp_f1_3433 = sp3F0 - M2C_FIELD(&arg0, f64 *, 0);
    sp170 = temp_f1_3433;
    sp360 = temp_f1_3433;
    sp178 = (f32) sp3F8 - arg0.unk8;
    temp_f0_3445 = 100.0f * (112.0f * arg1);
    sp368 = (f64) sp178;
    temp_f25_3453 = ((f32) sp368 * (f32) sp368) + (((f32) sp360 * (f32) sp360) + ((*(f32 *) ((u8 *) &sp360 + 0x4)) * (*(f32 *) ((u8 *) &sp360 + 0x4))));
    if (temp_f25_3453 <= (temp_f0_3445 * temp_f0_3445)) {
        M2C_STRUCT_COPY((s32) &sp430.unk3C + 4, (s32) (M2C_FIELD(&gb, void **, 0x3B8) + 0xAC) + 4, 0x70);
        if (sp470.IsVisible(arg0, 100.0f * (25.0f * arg1)) != 0) {
            sp160 = 1.0f;
            sp164 = 1.0f;
            sp168 = 0.0f;
            sp16C = 1.0f;
            sp350 = (f64) sp160;
            sp358 = (f64) sp168;
            gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp350), 3.0f * gUpdateTimeDelta);
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            temp_f2_3503 = 2000.0f * (1.0f + arg1);
            temp_f21_3506 = 1.0f - (temp_f25_3453 / (temp_f2_3503 * temp_f2_3503));
            if (temp_f21_3506 > 0.0f) {
                sp414 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp330.operator*(500.0f);
                sp50 = sp330 * (f64) temp_f21_3506;
                sp410 = 0x417;
                sp418 = sp50;
                sp58 = sp330.unk8 * temp_f21_3506;
                sp428 = 1;
                sp420 = (f64) sp58;
                sp340 = sp50;
                sp348 = (f64) sp58;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp410, sp50);
            }
        }
    }
    M2C_STRUCT_COPY((s32) &sp42C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp158 = 0.0f;
    sp150 = 0.0f;
    sp154 = 1.0f;
    sp3D8 = (f64) sp158;
    sp3D0 = (f64) sp150;
    KDMath_BuildMatrixFromFwd(&sp430, *((MKVector3 *) &sp3E0), (MKVector3 *) &sp3D0);
    sp430.Scale3x3(&sp430, arg1);
    sp20 = -(f32) sp3E0;
    sp24 = -(*(f32 *) ((u8 *) &sp3E0 + 0x4));
    sp28 = -(f32) sp3E8;
    sp2E0 = (f64) sp20;
    sp2E8 = (f64) sp28;
    sp2F0.operator*(700.0f);
    sp300.operator*(arg1);
    sp40 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp300);
    sp310 = sp40;
    sp48 = arg0.unk8 + sp300.unk8;
    sp318 = (f64) sp48;
    sp430.unk30 = (f32) sp310;
    sp430.unk34 = (*(f32 *) ((u8 *) &sp310 + 0x4));
    sp430.unk38 = (f32) sp318;
    sp430.unk3C = 1.0f;
    gb.unk1C0.StartWarp(&sp430);
    var_r28_3625 = 0;
loop_59:
    if (var_r28_3625 < (s32) (20.0f * arg1)) {
        temp_f1_3636 = MKRand_Float((int *) &gViewSeed, 2000.0f, 3000.0f);
        sp148 = -1.0f;
        sp138 = 1.0f;
        sp140 = -1.0f;
        sp144 = 0.0f;
        sp130 = 1.0f;
        sp134 = 1.0f;
        sp2A0 = (f64) sp140;
        sp2A8 = (f64) sp148;
        sp290 = (f64) sp130;
        sp298 = (f64) sp138;
        KDRand_Vector(sp2B0, *((MKVector3 *) &sp2A0));
        temp_f1_3656 = M2C_BITWISE(f32, sp2B0);
        var_f4_3663 = (sp2B0.unk8 * sp2B0.unk8) + ((temp_f1_3656 * temp_f1_3656) + (sp2B0.unk4 * sp2B0.unk4));
        if (var_f4_3663 > 1e-12f) {
            if (var_f4_3663 > 0.0f) {
                temp_f1_3669 = __frsqrte(var_f4_3663);
                temp_f1_3675 = 0.5 * temp_f1_3669 * -(((f64) var_f4_3663 * (temp_f1_3669 * temp_f1_3669)) - 3.0);
                temp_f1_3679 = 0.5 * temp_f1_3675 * -(((f64) var_f4_3663 * (temp_f1_3675 * temp_f1_3675)) - 3.0);
                var_f4_3663 = (f32) ((f64) var_f4_3663 * (0.5 * temp_f1_3679 * -(((f64) var_f4_3663 * (temp_f1_3679 * temp_f1_3679)) - 3.0)));
            } else if (var_f4_3663 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3663 = __float_nan;
            } else {
                sp10 = var_f4_3663;
                temp_r3_3698 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_3698) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3708 = 1;
                    } else {
                        var_r0_3708 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3708 = 5;
                    } else {
                        var_r0_3708 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3708 = 4;
                    break;
                }
                if (var_r0_3708 == 1) {
                    var_f4_3663 = __float_nan;
                }
            }
            var_f3_3730 = 1.0f / var_f4_3663;
        } else {
            var_f3_3730 = 0.0f;
        }
        sp100 = M2C_BITWISE(f32, sp2B0) * var_f3_3730;
        sp104 = sp2B0.unk4 * var_f3_3730;
        sp108 = sp2B0.unk8 * var_f3_3730;
        sp2C0 = (f64) sp100;
        sp2C8 = (f64) sp108;
        temp_f0_3749 = sp2C0 * (f64) temp_f1_3636;
        sp120 = temp_f0_3749;
        sp2D0 = temp_f0_3749;
        sp128 = (f32) sp2C8 * temp_f1_3636;
        sp2D8 = (f64) sp128;
        sp18 = MKRand_Float((int *) &gViewSeed, 12.0f, 20.0f);
        sp114 = MKRand_Float((int *) &gViewSeed, 0.35f, 1.0f);
        sp110 = 1.0f;
        sp118 = 0.125f;
        sp11C = 1.0f;
        sp280 = (f64) sp110;
        sp288 = (f64) sp118;
        ((EmbersPS *) gb.unk74)->Emit(arg0, *((MKVector3 *) &sp2D0), sp18, *((MKVector4 *) &sp280), -2000.0f);
        var_r28_3625 += 1;
        goto loop_59;
    }
    var_r29_3795 = 0;
    temp_f21_3799 = arg0.unk8;
loop_62:
    if (var_r29_3795 < (s32) (5.0f * arg1)) {
        temp_f31_3808 = MKRand_Float((int *) &gViewSeed, 2500.0f, 3500.0f);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.5f, -1.0f);
        KDRand_Vector(sp250, sp240);
        Normalise(sp260);
        sp30 = sp260 * (f64) temp_f31_3808;
        sp90 = 0.5f;
        sp94 = 0.5f;
        sp38 = sp260.unk8 * temp_f31_3808;
        sp98 = 0.5f;
        sp9C = 1.0f;
        sp270 = sp30;
        sp278 = (f64) sp38;
        sp400 = sp30;
        sp408 = (f64) sp38;
        sp1A0 = (f64) sp90;
        sp1A8 = (f64) sp98;
        temp_f1_3849 = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
        spF0 = 0.0f;
        spF4 = 75.0f;
        spA8 = 3.1415927f;
        spB8 = -3.1415927f;
        spC8 = 3.1415927f;
        spD8 = -3.1415927f;
        spF8 = 0.0f;
        spA0 = 3.1415927f;
        spA4 = 3.1415927f;
        spB0 = -3.1415927f;
        spB4 = -3.1415927f;
        spC0 = 3.1415927f;
        spC4 = 3.1415927f;
        spD0 = -3.1415927f;
        spD4 = -3.1415927f;
        sp210 = (f64) spF0;
        sp1B0 = (f64) spA0;
        sp1B8 = (f64) spA8;
        sp1C0 = (f64) spB0;
        sp1C8 = (f64) spB8;
        sp1E0 = (f64) spC0;
        sp1E8 = (f64) spC8;
        sp1F0 = (f64) spD0;
        sp1F8 = (f64) spD8;
        sp218 = (f64) spF8;
        temp_f0_3888 = M2C_FIELD(&arg0, f64 *, 0) + sp210;
        spE0 = temp_f0_3888;
        sp220 = temp_f0_3888;
        spE8 = temp_f21_3799 + (f32) sp218;
        sp228 = (f64) spE8;
        KDRand_Vector(sp1D0, *((MKVector3 *) &sp1C0));
        KDRand_Vector(sp200, *((MKVector3 *) &sp1F0));
        ((FlyingChunkPS *) gb.unkA4)->Emit(*((MKVector3 *) &sp220), *((MKVector3 *) &sp400), sp200, sp1D0, temp_f1_3849, *((MKVector4 *) &sp1A0), 0xA, NULL);
        var_r29_3795 += 1;
        goto loop_62;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
void DynamiteExplosion::Trigger(const MKVector3 &arg0, float arg1, bool arg2, int arg3, MKProp *arg4) {
    s32 sp48;
    f32 sp44;
    s8 sp42;
    s8 sp41;
    s8 sp40;
    s32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f3_4119;
    f64 temp_f4_4120;
    f64 temp_f5_4117;
    s32 var_r3_3987;
    u8 var_r31_4080;

    switch (arg3) {                                 /* irregular */
    case 0:
        var_r3_3987 = GS_TNTExplodeFire;
        if (gb.unk0->GetHeroType() == 2) {
            var_r3_3987 = GS_Explosion6;
        }
        KDSound_Play3d(var_r3_3987, &arg0, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_TNTExplodeFireDebris, &arg0, 0U, -1, 0.0f, 0U);
        TriggerFire(arg0, arg1, arg2);
block_14:
        KDSound_Play3d(GS_Rumble1Soft, &arg0, 0U, -1, 0.0f, 0U);
        var_r31_4080 = 0;
        if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
            var_r31_4080 = 1;
        }
        if (var_r31_4080 == 0) {
            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(arg1, arg1, 0.5f, &arg0, 30.0f, 0, 4.0f, 0U);
        }
        temp_f5_4117 = M2C_FIELD(&arg0, f64 *, 0);
        temp_f3_4119 = 400.0f * arg1;
        temp_f4_4120 = M2C_FIELD(&arg0, f64 *, 8);
        sp1C = 0;
        sp18 = 1;
        sp20 = 0;
        sp28 = temp_f5_4117;
        sp30 = temp_f4_4120;
        sp38 = temp_f3_4119;
        sp40 = 0;
        sp41 = 0;
        sp42 = 1;
        sp3C = 0;
        sp44 = 10.0f;
        sp48 = arg3;
        sp8 = temp_f5_4117;
        sp10 = temp_f4_4120;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, M2C_UNK, f32, f32, f32, f64, f64), 0x94)(gMK, &sp18, 0x248, 0, &sp8, 1, 0, 500.0f * arg1, 10.0f, temp_f3_4119, temp_f4_4120, temp_f5_4117);
        return;
    case 1:
        KDSound_Play3d(GS_TNTExplodeElec, &arg0, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_TNTExplodeElecDebris, &arg0, 0U, -1, 0.0f, 0U);
        TriggerElec(arg0, arg1, arg2);
        goto block_14;
    case 2:
        KDSound_Play3d(GS_TNTExplodeIce, &arg0, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_TNTExplodeIceDebris, &arg0, 0U, -1, 0.0f, 0U);
        TriggerIce(arg0, arg1, arg2);
        goto block_14;
    case 3:
        KDSound_Play3d(GS_TNTExplodeEarth, &arg0, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_TNTExplodeEarthDebris, &arg0, 0U, -1, 0.0f, 0U);
        TriggerEarth(arg0, arg1, arg2);
        goto block_14;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void DynamiteExplosion::Deinit() {
    DynamiteExplosion::Explosion **var_r31_4167;
    DynamiteExplosion::Explosion **var_r3_4168;
    DynamiteExplosion::Explosion **var_r4_4166;
    DynamiteExplosion::Explosion *temp_r0_4171;
    DynamiteExplosion::Explosion *temp_r0_4190;
    MKHeap *temp_r3_4193;
    u32 temp_r0_4176;

    var_r4_4166 = this->unk50;
    var_r31_4167 = var_r4_4166;
    var_r3_4168 = var_r4_4166;
loop_3:
    temp_r0_4176 = M2C_FIELD(var_r3_4168, u32 *, -4);
    var_r3_4168 -= 4;
    if (temp_r0_4176 != 0U) {
        temp_r0_4171 = *var_r3_4168;
        if (temp_r0_4171 < var_r31_4167) {
            var_r31_4167 = (DynamiteExplosion::Explosion **) temp_r0_4171;
        }
        goto loop_3;
    }
    if (var_r3_4168 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_4190 = *var_r4_4166;
        if (temp_r0_4190 != NULL) {
            if (temp_r0_4190 < var_r31_4167) {
                var_r31_4167 = (DynamiteExplosion::Explosion **) temp_r0_4190;
            }
            var_r4_4166 += 4;
            goto loop_9;
        }
        temp_r3_4193 = ((MKHeap *) var_r3_4168)->Current();
        if (temp_r3_4193 != NULL) {
            ((MKHeap *) (temp_r3_4193->Current()))->Free(var_r31_4167, NULL, 0);
        } else {
            free(var_r31_4167);
        }
    }
    this->unk50 = NULL;
    MKProp::Deinit();
}
#endif

void DynamiteExplosion::Draw() {

}

void *DynamiteExplosion::Update() {
    DynamiteExplosion::Explosion **temp_r3_4251;
    DynamiteExplosion::Explosion **temp_r3_4264;
    DynamiteExplosion::Explosion **temp_r3_4277;
    DynamiteExplosion::Explosion **temp_r3_4290;
    DynamiteExplosion::Explosion **var_r31_4231;
    DynamiteExplosion::Explosion *temp_r4_4254;
    DynamiteExplosion::Explosion *temp_r4_4267;
    DynamiteExplosion::Explosion *temp_r4_4280;
    DynamiteExplosion::Explosion *temp_r4_4293;
    DynamiteExplosion::Explosion *temp_r4_4302;
    s32 temp_r0_4234;

    var_r31_4231 = this->unk50;
loop_17:
    if (var_r31_4231 != NULL) {
        temp_r4_4302 = *var_r31_4231;
        if (temp_r4_4302 != NULL) {
            temp_r0_4234 = M2C_FIELD(temp_r4_4302, s32 *, 0x1C);
            switch (temp_r0_4234) {                 /* irregular */
            case 0:
                if (UpdateFire(temp_r4_4302) == 0) {
                    temp_r3_4251 = this->unk50;
                    this->unk50 = temp_r3_4251 + 4;
                    temp_r4_4254 = *temp_r3_4251;
                    *temp_r3_4251 = *var_r31_4231;
                    *var_r31_4231 = temp_r4_4254;
                }
                break;
            case 1:
                if (UpdateElec(temp_r4_4302) == 0) {
                    temp_r3_4264 = this->unk50;
                    this->unk50 = temp_r3_4264 + 4;
                    temp_r4_4267 = *temp_r3_4264;
                    *temp_r3_4264 = *var_r31_4231;
                    *var_r31_4231 = temp_r4_4267;
                }
                break;
            case 2:
                if (UpdateIce(temp_r4_4302) == 0) {
                    temp_r3_4277 = this->unk50;
                    this->unk50 = temp_r3_4277 + 4;
                    temp_r4_4280 = *temp_r3_4277;
                    *temp_r3_4277 = *var_r31_4231;
                    *var_r31_4231 = temp_r4_4280;
                }
                break;
            case 3:
                if (UpdateEarth(temp_r4_4302) == 0) {
                    temp_r3_4290 = this->unk50;
                    this->unk50 = temp_r3_4290 + 4;
                    temp_r4_4293 = *temp_r3_4290;
                    *temp_r3_4290 = *var_r31_4231;
                    *var_r31_4231 = temp_r4_4293;
                }
                break;
            }
            var_r31_4231 += 4;
            goto loop_17;
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'const char[8]' to
f32 DynamiteExplosion::Resolve() {
    MKProp::Resolve();
    this->unk4C = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "IceCube"));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void DynamiteExplosion::Init() {
    DynamiteExplosion::Explosion **temp_r3_4369;
    DynamiteExplosion::Explosion **temp_r3_4375;
    DynamiteExplosion::Explosion **var_r3_4354;
    DynamiteExplosion::Explosion **var_r5_4363;
    MKHeap *temp_r3_4347;
    s32 var_ctr_4367;

    MKProp::Init();
    temp_r3_4347 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4347 != NULL) {
        var_r3_4354 = ((MKHeap *) (temp_r3_4347->Current()))->Alloc(0xBC, NULL, 0);
    } else {
        var_r3_4354 = malloc(0xBC);
    }
    this->unk50 = var_r3_4354;
    var_r5_4363 = this->unk50;
    this->unk50 = var_r5_4363 + 0xA0;
    M2C_FIELD(var_r5_4363, s32 *, 0xA0) = 0;
    var_ctr_4367 = 5;
    do {
        temp_r3_4369 = this->unk50;
        this->unk50 = temp_r3_4369 + 4;
        M2C_FIELD(temp_r3_4369, DynamiteExplosion::Explosion ***, 4) = var_r5_4363;
        var_r5_4363 += 0x20;
        var_ctr_4367 -= 1;
    } while (var_ctr_4367 != 0);
    temp_r3_4375 = this->unk50;
    this->unk50 = temp_r3_4375 + 4;
    M2C_FIELD(temp_r3_4375, DynamiteExplosion::Explosion ***, 4) = NULL;
}
#endif

void DynamiteExplosionDescriptor::Deinit() {
    MKPropDescriptor::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'KDEnvParticleSystem *' to
void DynamiteExplosionDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpFireFlames"));
    this->unk64 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpFireShock"));
    this->unk68 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpSmoke"));
    this->unk6C = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpElecShock"));
    this->unk70 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpIceFlash"));
    this->unk74 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpIceShock"));
    this->unk78 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpEarthFlash"));
    this->unk7C = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpEarthShock"));
    this->unk80 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DynamiteExpIceSnow"));
}
#endif
