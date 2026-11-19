#include "spyro/source/Shatterable.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/FXBase.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDShatter2.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/ShatterExtendedMsg.h"
#include "spyro/source/ShatterOnCollisionMsg.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PropFlags.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

f64 ceil(s32, f32);                                 /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(void *);                                /* extern */
M2C_UNK strlwr(s8 *, M2C_UNK);                      /* extern */
u32 strstr(s8 *);                                   /* extern */
extern s32 GS_GemSpawn2;
extern s32 GS_PLACEHOLDER;
extern s32 GS_SpyroStompLand;
extern s8 gAssertBool;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
static M2C_UNK pShatterAnimNames;                   /* unable to generate initializer: unknown type */
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap ShatterableHitFXDataMap[8] = {
    { 0, "None" },
    { 1, "Metal" },
    { 2, "Rock" },
    { 3, "EarthRock" },
    { 4, "Snow" },
    { 5, "Wood" },
    { 6, "IceWood" },
    { 0, NULL },
};
#endif
static M2C_UNK unshatteredNames;

static s32 lit_1509 = 0;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
s32 Shatterable::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;
    void *temp_r4_23;

    sp18 = MKVector(0.0f, 150.0f, 0.0f);
    temp_r4_23 = ((u8 *) this->unk8) + 0x30;
    sp8 = M2C_FIELD(temp_r4_23, f64 *, 0) + M2C_BITWISE(f64, sp18);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD(temp_r4_23, f32 *, 8) + sp18.unk8;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::ResetPercentageShattered() {
    s32 temp_r0_69;
    s32 var_r0_75;
    s32 var_r31_58;
    s32 var_r3_70;

    var_r31_58 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1;
    if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (var_r31_58 * 0x17C)), u8 *, 0x178) == 0) {
        temp_r0_69 = var_r31_58 - 1;
        var_r3_70 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1;
        if (temp_r0_69 < var_r3_70) {
            var_r3_70 = temp_r0_69;
        }
        var_r0_75 = lit_1509;
        if (var_r3_70 > var_r0_75) {
            var_r0_75 = var_r3_70;
        }
        var_r31_58 = var_r0_75;
    }
    this->unk180 = (s32) (this->unk198 * (f32) var_r31_58);
}
#endif

#if 0 // DRAFT: illegal operand
void ShatterableDescriptor::EmitHitEffects(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, MKProp *arg3, int arg4) {
    f64 sp8B8;                                      /* compiler-managed */
    f64 sp8B0;                                      /* compiler-managed */
    f64 sp8A8;                                      /* compiler-managed */
    f64 sp8A0;                                      /* compiler-managed */
    f64 sp898;                                      /* compiler-managed */
    f64 sp890;                                      /* compiler-managed */
    f64 sp888;                                      /* compiler-managed */
    f64 sp880;                                      /* compiler-managed */
    f64 sp878;                                      /* compiler-managed */
    f64 sp870;                                      /* compiler-managed */
    f64 sp868;                                      /* compiler-managed */
    f64 sp860;                                      /* compiler-managed */
    MKVector3 sp850;
    f64 sp848;
    f64 sp840;
    f64 sp838;
    f64 sp830;
    f64 sp828;
    f64 sp820;
    f64 sp818;
    f64 sp810;
    MKVector3 sp800;
    f64 sp7F8;
    f64 sp7F0;
    f64 sp7E8;
    f64 sp7E0;
    f64 sp7D8;
    f64 sp7D0;
    MKVector3 sp7C0;
    f64 sp7B8;
    f64 sp7B0;
    f64 sp7A8;
    f64 sp7A0;
    MKVector3 sp790;
    f64 sp788;
    f64 sp780;
    f64 sp778;
    f64 sp770;
    f64 sp768;
    f64 sp760;
    f64 sp758;
    f64 sp750;
    MKVector3 sp740;
    f64 sp738;
    f64 sp730;
    f64 sp728;
    f64 sp720;
    f64 sp718;
    f64 sp710;
    MKVector3 sp700;
    f64 sp6F8;
    f64 sp6F0;
    f64 sp6E8;
    f64 sp6E0;
    MKVector3 sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    f64 sp6B8;
    f64 sp6B0;
    f64 sp6A8;
    f64 sp6A0;
    f64 sp698;
    f64 sp690;
    MKVector3 sp680;
    f64 sp678;
    f64 sp670;
    f64 sp668;
    f64 sp660;
    f64 sp658;
    f64 sp650;
    MKVector3 sp640;
    f64 sp638;
    f64 sp630;
    f64 sp628;
    f64 sp620;
    MKVector3 sp610;
    f64 sp608;
    f64 sp600;
    f64 sp5F8;
    f64 sp5F0;
    f64 sp5E8;
    f64 sp5E0;
    f64 sp5D8;
    f64 sp5D0;
    MKVector3 sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp598;
    f64 sp590;
    MKVector3 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp560;
    MKVector3 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    f64 sp510;
    MKVector3 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    MKVector3 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    MKVector3 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    MKVector3 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    MKVector3 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f32 sp3D8;
    f32 sp3D4;
    f32 sp3D0;
    f32 sp3C8;
    f32 sp3C4;
    f32 sp3C0;
    f32 sp3B8;
    f64 sp3B0;
    f32 sp3A8;
    f64 sp3A0;
    f32 sp398;
    f32 sp394;
    f32 sp390;
    f32 sp388;
    f32 sp384;
    f32 sp380;
    f32 sp378;
    f64 sp370;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp358;
    f32 sp354;
    f32 sp350;
    f32 sp348;
    f64 sp340;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f32 sp328;
    f32 sp324;
    f32 sp320;
    f32 sp318;
    f64 sp310;
    f32 sp308;
    f64 sp300;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f32 sp2D8;
    f64 sp2D0;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2B8;
    f32 sp2B4;
    f32 sp2B0;
    f32 sp2A8;
    f64 sp2A0;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp278;
    f64 sp270;
    f32 sp268;
    f64 sp260;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp238;
    f64 sp230;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp208;
    f64 sp200;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f64 sp1C0;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f64 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_1146;
    f32 temp_f0_1364;
    f32 temp_f0_274;
    f32 temp_f0_492;
    f32 temp_f0_710;
    f32 temp_f0_928;
    f32 temp_f28_1024;
    f32 temp_f28_152;
    f32 temp_f28_370;
    f32 temp_f28_588;
    f32 temp_f28_806;
    f32 temp_f30_1242;
    f32 var_f3_1135;
    f32 var_f3_1353;
    f32 var_f3_263;
    f32 var_f3_481;
    f32 var_f3_699;
    f32 var_f3_917;
    f32 var_f4_1068;
    f32 var_f4_1286;
    f32 var_f4_196;
    f32 var_f4_414;
    f32 var_f4_632;
    f32 var_f4_850;
    f64 temp_f0_1052;
    f64 temp_f0_1208;
    f64 temp_f0_1270;
    f64 temp_f0_1426;
    f64 temp_f0_180;
    f64 temp_f0_336;
    f64 temp_f0_398;
    f64 temp_f0_554;
    f64 temp_f0_616;
    f64 temp_f0_772;
    f64 temp_f0_834;
    f64 temp_f0_990;
    f64 temp_f1_1074;
    f64 temp_f1_1080;
    f64 temp_f1_1084;
    f64 temp_f1_1292;
    f64 temp_f1_1298;
    f64 temp_f1_1302;
    f64 temp_f1_202;
    f64 temp_f1_208;
    f64 temp_f1_212;
    f64 temp_f1_420;
    f64 temp_f1_426;
    f64 temp_f1_430;
    f64 temp_f1_638;
    f64 temp_f1_644;
    f64 temp_f1_648;
    f64 temp_f1_856;
    f64 temp_f1_862;
    f64 temp_f1_866;
    s32 temp_r0_125;
    s32 temp_r3_1103;
    s32 temp_r3_1321;
    s32 temp_r3_231;
    s32 temp_r3_449;
    s32 temp_r3_667;
    s32 temp_r3_885;
    s32 var_r0_1113;
    s32 var_r0_1331;
    s32 var_r0_241;
    s32 var_r0_459;
    s32 var_r0_677;
    s32 var_r0_895;
    s32 var_r22_1029;
    s32 var_r22_1247;
    s32 var_r22_157;
    s32 var_r22_375;
    s32 var_r22_593;
    s32 var_r22_811;

    temp_r0_125 = this->unk168;
    switch (temp_r0_125) {                          /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_f28_152 = arg1.unk8;
        var_r22_157 = 0;
loop_31:
        if (var_r22_157 < arg4) {
            sp3C8 = 1.0f;
            sp3D8 = -1.0f;
            sp3C0 = 1.0f;
            sp3C4 = 2.0f;
            sp3D0 = -1.0f;
            sp3D4 = 1.0f;
            sp830 = (f64) sp3C0;
            sp838 = (f64) sp3C8;
            sp840 = (f64) sp3D0;
            sp848 = (f64) sp3D8;
            sp850 = KDRand_Vector(*((MKVector3 *) &sp840), *((MKVector3 *) &sp830));
            temp_f0_180 = sp850 + M2C_FIELD(&arg1, f64 *, 0);
            sp3B0 = temp_f0_180;
            sp8B0 = temp_f0_180;
            sp3B8 = sp850.unk8 + temp_f28_152;
            sp8B8 = (f64) sp3B8;
            var_f4_196 = ((f32) sp8B8 * (f32) sp8B8) + (((f32) sp8B0 * (f32) sp8B0) + ((*(f32 *) ((u8 *) &sp850 + 0x64)) * (*(f32 *) ((u8 *) &sp850 + 0x64))));
            if (var_f4_196 > 0.000001f) {
                if (var_f4_196 > 0.0f) {
                    temp_f1_202 = __frsqrte(var_f4_196);
                    temp_f1_208 = 0.5 * temp_f1_202 * -(((f64) var_f4_196 * (temp_f1_202 * temp_f1_202)) - 3.0);
                    temp_f1_212 = 0.5 * temp_f1_208 * -(((f64) var_f4_196 * (temp_f1_208 * temp_f1_208)) - 3.0);
                    var_f4_196 = (f32) ((f64) var_f4_196 * (0.5 * temp_f1_212 * -(((f64) var_f4_196 * (temp_f1_212 * temp_f1_212)) - 3.0)));
                } else if (var_f4_196 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_196 = __float_nan;
                } else {
                    sp1C = var_f4_196;
                    temp_r3_231 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                    switch (temp_r3_231) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_241 = 1;
                        } else {
                            var_r0_241 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_241 = 5;
                        } else {
                            var_r0_241 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_241 = 4;
                        break;
                    }
                    if (var_r0_241 == 1) {
                        var_f4_196 = __float_nan;
                    }
                }
                var_f3_263 = 1.0f / var_f4_196;
            } else {
                var_f3_263 = 0.0f;
            }
            temp_f0_274 = (f32) sp8B8 * var_f3_263;
            sp8B0 = (f32) sp8B0 * var_f3_263;
            (*(f32 *) ((u8 *) &sp850 + 0x64)) *= var_f3_263;
            sp8B8 = temp_f0_274;
            sp3A0 = sp8B0 * 5.717499035e-315;
            sp398 = -1.0f;
            sp3A8 = temp_f0_274 * 2000.0f;
            sp388 = 1.0f;
            sp390 = -1.0f;
            sp394 = -1.0f;
            sp380 = 1.0f;
            sp384 = 1.0f;
            sp820 = sp3A0;
            sp828 = (f64) sp3A8;
            sp7F0 = (f64) sp390;
            sp7F8 = (f64) sp398;
            sp7E0 = (f64) sp380;
            sp7E8 = (f64) sp388;
            sp800 = KDRand_Vector(*((MKVector3 *) &sp7F0), *((MKVector3 *) &sp7E0));
            sp370 = sp800 * 5.370091495e-315;
            sp368 = -1.0f;
            sp358 = 1.0f;
            sp378 = sp800.unk8 * 6.2831855f;
            sp360 = -1.0f;
            sp364 = -1.0f;
            sp350 = 1.0f;
            sp354 = 1.0f;
            sp810 = sp370;
            sp818 = (f64) sp378;
            sp7B0 = (f64) sp360;
            sp7B8 = (f64) sp368;
            sp7A0 = (f64) sp350;
            sp7A8 = (f64) sp358;
            sp7C0 = KDRand_Vector(*((MKVector3 *) &sp7B0), *((MKVector3 *) &sp7A0));
            temp_f0_336 = sp7C0 * 5.370091495e-315;
            sp340 = temp_f0_336;
            sp7D0 = temp_f0_336;
            sp348 = sp7C0.unk8 * 6.2831855f;
            sp7D8 = (f64) sp348;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA0)))->Emit(arg0, *((MKVector3 *) &sp820), *((MKVector3 *) &sp810), *((MKVector3 *) &sp7D0), MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_157 += 1;
            goto loop_31;
        }
        return;
    case 2:                                         /* switch 1 */
        temp_f28_370 = arg1.unk8;
        var_r22_375 = 0;
loop_55:
        if (var_r22_375 < arg4) {
            sp328 = 1.0f;
            sp338 = -1.0f;
            sp320 = 1.0f;
            sp324 = 2.0f;
            sp330 = -1.0f;
            sp334 = 1.0f;
            sp770 = (f64) sp320;
            sp778 = (f64) sp328;
            sp780 = (f64) sp330;
            sp788 = (f64) sp338;
            sp790 = KDRand_Vector(*((MKVector3 *) &sp780), *((MKVector3 *) &sp770));
            temp_f0_398 = sp790 + M2C_FIELD(&arg1, f64 *, 0);
            sp310 = temp_f0_398;
            sp8A0 = temp_f0_398;
            sp318 = sp790.unk8 + temp_f28_370;
            sp8A8 = (f64) sp318;
            var_f4_414 = ((f32) sp8A8 * (f32) sp8A8) + (((f32) sp8A0 * (f32) sp8A0) + ((*(f32 *) ((u8 *) &sp850 + 0x54)) * (*(f32 *) ((u8 *) &sp850 + 0x54))));
            if (var_f4_414 > 0.000001f) {
                if (var_f4_414 > 0.0f) {
                    temp_f1_420 = __frsqrte(var_f4_414);
                    temp_f1_426 = 0.5 * temp_f1_420 * -(((f64) var_f4_414 * (temp_f1_420 * temp_f1_420)) - 3.0);
                    temp_f1_430 = 0.5 * temp_f1_426 * -(((f64) var_f4_414 * (temp_f1_426 * temp_f1_426)) - 3.0);
                    var_f4_414 = (f32) ((f64) var_f4_414 * (0.5 * temp_f1_430 * -(((f64) var_f4_414 * (temp_f1_430 * temp_f1_430)) - 3.0)));
                } else if (var_f4_414 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_414 = __float_nan;
                } else {
                    sp18 = var_f4_414;
                    temp_r3_449 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                    switch (temp_r3_449) {          /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_459 = 1;
                        } else {
                            var_r0_459 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_459 = 5;
                        } else {
                            var_r0_459 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_459 = 4;
                        break;
                    }
                    if (var_r0_459 == 1) {
                        var_f4_414 = __float_nan;
                    }
                }
                var_f3_481 = 1.0f / var_f4_414;
            } else {
                var_f3_481 = 0.0f;
            }
            temp_f0_492 = (f32) sp8A8 * var_f3_481;
            sp8A0 = (f32) sp8A0 * var_f3_481;
            (*(f32 *) ((u8 *) &sp850 + 0x54)) *= var_f3_481;
            sp8A8 = temp_f0_492;
            sp300 = sp8A0 * 5.717499035e-315;
            sp2F8 = -1.0f;
            sp308 = temp_f0_492 * 2000.0f;
            sp2E8 = 1.0f;
            sp2F0 = -1.0f;
            sp2F4 = -1.0f;
            sp2E0 = 1.0f;
            sp2E4 = 1.0f;
            sp760 = sp300;
            sp768 = (f64) sp308;
            sp730 = (f64) sp2F0;
            sp738 = (f64) sp2F8;
            sp720 = (f64) sp2E0;
            sp728 = (f64) sp2E8;
            sp740 = KDRand_Vector(*((MKVector3 *) &sp730), *((MKVector3 *) &sp720));
            sp2D0 = sp740 * 5.370091495e-315;
            sp2C8 = -1.0f;
            sp2B8 = 1.0f;
            sp2D8 = sp740.unk8 * 6.2831855f;
            sp2C0 = -1.0f;
            sp2C4 = -1.0f;
            sp2B0 = 1.0f;
            sp2B4 = 1.0f;
            sp750 = sp2D0;
            sp758 = (f64) sp2D8;
            sp6F0 = (f64) sp2C0;
            sp6F8 = (f64) sp2C8;
            sp6E0 = (f64) sp2B0;
            sp6E8 = (f64) sp2B8;
            sp700 = KDRand_Vector(*((MKVector3 *) &sp6F0), *((MKVector3 *) &sp6E0));
            temp_f0_554 = sp700 * 5.370091495e-315;
            sp2A0 = temp_f0_554;
            sp710 = temp_f0_554;
            sp2A8 = sp700.unk8 * 6.2831855f;
            sp718 = (f64) sp2A8;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA4)))->Emit(arg0, *((MKVector3 *) &sp760), *((MKVector3 *) &sp750), *((MKVector3 *) &sp710), MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_375 += 1;
            goto loop_55;
        }
        return;
    case 3:                                         /* switch 1 */
        temp_f28_588 = arg1.unk8;
        var_r22_593 = 0;
loop_79:
        if (var_r22_593 < arg4) {
            sp288 = 1.0f;
            sp298 = -1.0f;
            sp280 = 1.0f;
            sp284 = 2.0f;
            sp290 = -1.0f;
            sp294 = 1.0f;
            sp6B0 = (f64) sp280;
            sp6B8 = (f64) sp288;
            sp6C0 = (f64) sp290;
            sp6C8 = (f64) sp298;
            sp6D0 = KDRand_Vector(*((MKVector3 *) &sp6C0), *((MKVector3 *) &sp6B0));
            temp_f0_616 = sp6D0 + M2C_FIELD(&arg1, f64 *, 0);
            sp270 = temp_f0_616;
            sp890 = temp_f0_616;
            sp278 = sp6D0.unk8 + temp_f28_588;
            sp898 = (f64) sp278;
            var_f4_632 = ((f32) sp898 * (f32) sp898) + (((f32) sp890 * (f32) sp890) + ((*(f32 *) ((u8 *) &sp850 + 0x44)) * (*(f32 *) ((u8 *) &sp850 + 0x44))));
            if (var_f4_632 > 0.000001f) {
                if (var_f4_632 > 0.0f) {
                    temp_f1_638 = __frsqrte(var_f4_632);
                    temp_f1_644 = 0.5 * temp_f1_638 * -(((f64) var_f4_632 * (temp_f1_638 * temp_f1_638)) - 3.0);
                    temp_f1_648 = 0.5 * temp_f1_644 * -(((f64) var_f4_632 * (temp_f1_644 * temp_f1_644)) - 3.0);
                    var_f4_632 = (f32) ((f64) var_f4_632 * (0.5 * temp_f1_648 * -(((f64) var_f4_632 * (temp_f1_648 * temp_f1_648)) - 3.0)));
                } else if (var_f4_632 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_632 = __float_nan;
                } else {
                    sp14 = var_f4_632;
                    temp_r3_667 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                    switch (temp_r3_667) {          /* switch 4; irregular */
                    case 0x7F800000:                /* switch 4 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_677 = 1;
                        } else {
                            var_r0_677 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 4 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_677 = 5;
                        } else {
                            var_r0_677 = 3;
                        }
                        break;
                    default:                        /* switch 4 */
                        var_r0_677 = 4;
                        break;
                    }
                    if (var_r0_677 == 1) {
                        var_f4_632 = __float_nan;
                    }
                }
                var_f3_699 = 1.0f / var_f4_632;
            } else {
                var_f3_699 = 0.0f;
            }
            temp_f0_710 = (f32) sp898 * var_f3_699;
            sp890 = (f32) sp890 * var_f3_699;
            (*(f32 *) ((u8 *) &sp850 + 0x44)) *= var_f3_699;
            sp898 = temp_f0_710;
            sp260 = sp890 * 5.717499035e-315;
            sp258 = -1.0f;
            sp268 = temp_f0_710 * 2000.0f;
            sp248 = 1.0f;
            sp250 = -1.0f;
            sp254 = -1.0f;
            sp240 = 1.0f;
            sp244 = 1.0f;
            sp6A0 = sp260;
            sp6A8 = (f64) sp268;
            sp670 = (f64) sp250;
            sp678 = (f64) sp258;
            sp660 = (f64) sp240;
            sp668 = (f64) sp248;
            sp680 = KDRand_Vector(*((MKVector3 *) &sp670), *((MKVector3 *) &sp660));
            sp230 = sp680 * 5.370091495e-315;
            sp228 = -1.0f;
            sp218 = 1.0f;
            sp238 = sp680.unk8 * 6.2831855f;
            sp220 = -1.0f;
            sp224 = -1.0f;
            sp210 = 1.0f;
            sp214 = 1.0f;
            sp690 = sp230;
            sp698 = (f64) sp238;
            sp630 = (f64) sp220;
            sp638 = (f64) sp228;
            sp620 = (f64) sp210;
            sp628 = (f64) sp218;
            sp640 = KDRand_Vector(*((MKVector3 *) &sp630), *((MKVector3 *) &sp620));
            temp_f0_772 = sp640 * 5.370091495e-315;
            sp200 = temp_f0_772;
            sp650 = temp_f0_772;
            sp208 = sp640.unk8 * 6.2831855f;
            sp658 = (f64) sp208;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xAC)))->Emit(arg0, *((MKVector3 *) &sp6A0), *((MKVector3 *) &sp690), *((MKVector3 *) &sp650), MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_593 += 1;
            goto loop_79;
        }
        return;
    case 4:                                         /* switch 1 */
        temp_f28_806 = arg1.unk8;
        var_r22_811 = 0;
loop_103:
        if (var_r22_811 < arg4) {
            sp1E8 = 1.0f;
            sp1F8 = -1.0f;
            sp1E0 = 1.0f;
            sp1E4 = 2.0f;
            sp1F0 = -1.0f;
            sp1F4 = 1.0f;
            sp5F0 = (f64) sp1E0;
            sp5F8 = (f64) sp1E8;
            sp600 = (f64) sp1F0;
            sp608 = (f64) sp1F8;
            sp610 = KDRand_Vector(*((MKVector3 *) &sp600), *((MKVector3 *) &sp5F0));
            temp_f0_834 = sp610 + M2C_FIELD(&arg1, f64 *, 0);
            sp1D0 = temp_f0_834;
            sp880 = temp_f0_834;
            sp1D8 = sp610.unk8 + temp_f28_806;
            sp888 = (f64) sp1D8;
            var_f4_850 = ((f32) sp888 * (f32) sp888) + (((f32) sp880 * (f32) sp880) + ((*(f32 *) ((u8 *) &sp850 + 0x34)) * (*(f32 *) ((u8 *) &sp850 + 0x34))));
            if (var_f4_850 > 0.000001f) {
                if (var_f4_850 > 0.0f) {
                    temp_f1_856 = __frsqrte(var_f4_850);
                    temp_f1_862 = 0.5 * temp_f1_856 * -(((f64) var_f4_850 * (temp_f1_856 * temp_f1_856)) - 3.0);
                    temp_f1_866 = 0.5 * temp_f1_862 * -(((f64) var_f4_850 * (temp_f1_862 * temp_f1_862)) - 3.0);
                    var_f4_850 = (f32) ((f64) var_f4_850 * (0.5 * temp_f1_866 * -(((f64) var_f4_850 * (temp_f1_866 * temp_f1_866)) - 3.0)));
                } else if (var_f4_850 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_850 = __float_nan;
                } else {
                    sp10 = var_f4_850;
                    temp_r3_885 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_885) {          /* switch 5; irregular */
                    case 0x7F800000:                /* switch 5 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_895 = 1;
                        } else {
                            var_r0_895 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 5 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_895 = 5;
                        } else {
                            var_r0_895 = 3;
                        }
                        break;
                    default:                        /* switch 5 */
                        var_r0_895 = 4;
                        break;
                    }
                    if (var_r0_895 == 1) {
                        var_f4_850 = __float_nan;
                    }
                }
                var_f3_917 = 1.0f / var_f4_850;
            } else {
                var_f3_917 = 0.0f;
            }
            temp_f0_928 = (f32) sp888 * var_f3_917;
            sp880 = (f32) sp880 * var_f3_917;
            (*(f32 *) ((u8 *) &sp850 + 0x34)) *= var_f3_917;
            sp888 = temp_f0_928;
            sp1C0 = sp880 * 5.717499035e-315;
            sp1B8 = -1.0f;
            sp1C8 = temp_f0_928 * 2000.0f;
            sp1A8 = 1.0f;
            sp1B0 = -1.0f;
            sp1B4 = -1.0f;
            sp1A0 = 1.0f;
            sp1A4 = 1.0f;
            sp5E0 = sp1C0;
            sp5E8 = (f64) sp1C8;
            sp5B0 = (f64) sp1B0;
            sp5B8 = (f64) sp1B8;
            sp5A0 = (f64) sp1A0;
            sp5A8 = (f64) sp1A8;
            sp5C0 = KDRand_Vector(*((MKVector3 *) &sp5B0), *((MKVector3 *) &sp5A0));
            sp190 = sp5C0 * 5.370091495e-315;
            sp188 = -1.0f;
            sp178 = 1.0f;
            sp198 = sp5C0.unk8 * 6.2831855f;
            sp180 = -1.0f;
            sp184 = -1.0f;
            sp170 = 1.0f;
            sp174 = 1.0f;
            sp5D0 = sp190;
            sp5D8 = (f64) sp198;
            sp570 = (f64) sp180;
            sp578 = (f64) sp188;
            sp560 = (f64) sp170;
            sp568 = (f64) sp178;
            sp580 = KDRand_Vector(*((MKVector3 *) &sp570), *((MKVector3 *) &sp560));
            temp_f0_990 = sp580 * 5.370091495e-315;
            sp160 = temp_f0_990;
            sp590 = temp_f0_990;
            sp168 = sp580.unk8 * 6.2831855f;
            sp598 = (f64) sp168;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA8)))->Emit(arg0, *((MKVector3 *) &sp5E0), *((MKVector3 *) &sp5D0), *((MKVector3 *) &sp590), MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_811 += 1;
            goto loop_103;
        }
        return;
    case 5:                                         /* switch 1 */
        temp_f28_1024 = arg1.unk8;
        var_r22_1029 = 0;
loop_127:
        if (var_r22_1029 < arg4) {
            sp148 = 1.0f;
            sp158 = -1.0f;
            sp140 = 1.0f;
            sp144 = 2.0f;
            sp150 = -1.0f;
            sp154 = 1.0f;
            sp530 = (f64) sp140;
            sp538 = (f64) sp148;
            sp540 = (f64) sp150;
            sp548 = (f64) sp158;
            sp550 = KDRand_Vector(*((MKVector3 *) &sp540), *((MKVector3 *) &sp530));
            temp_f0_1052 = sp550 + M2C_FIELD(&arg1, f64 *, 0);
            sp130 = temp_f0_1052;
            sp870 = temp_f0_1052;
            sp138 = sp550.unk8 + temp_f28_1024;
            sp878 = (f64) sp138;
            var_f4_1068 = ((f32) sp878 * (f32) sp878) + (((f32) sp870 * (f32) sp870) + ((*(f32 *) ((u8 *) &sp850 + 0x24)) * (*(f32 *) ((u8 *) &sp850 + 0x24))));
            if (var_f4_1068 > 0.000001f) {
                if (var_f4_1068 > 0.0f) {
                    temp_f1_1074 = __frsqrte(var_f4_1068);
                    temp_f1_1080 = 0.5 * temp_f1_1074 * -(((f64) var_f4_1068 * (temp_f1_1074 * temp_f1_1074)) - 3.0);
                    temp_f1_1084 = 0.5 * temp_f1_1080 * -(((f64) var_f4_1068 * (temp_f1_1080 * temp_f1_1080)) - 3.0);
                    var_f4_1068 = (f32) ((f64) var_f4_1068 * (0.5 * temp_f1_1084 * -(((f64) var_f4_1068 * (temp_f1_1084 * temp_f1_1084)) - 3.0)));
                } else if (var_f4_1068 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1068 = __float_nan;
                } else {
                    spC = var_f4_1068;
                    temp_r3_1103 = M2C_BITWISE(s32, spC) & 0x7F800000;
                    switch (temp_r3_1103) {         /* switch 6; irregular */
                    case 0x7F800000:                /* switch 6 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_1113 = 1;
                        } else {
                            var_r0_1113 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 6 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_1113 = 5;
                        } else {
                            var_r0_1113 = 3;
                        }
                        break;
                    default:                        /* switch 6 */
                        var_r0_1113 = 4;
                        break;
                    }
                    if (var_r0_1113 == 1) {
                        var_f4_1068 = __float_nan;
                    }
                }
                var_f3_1135 = 1.0f / var_f4_1068;
            } else {
                var_f3_1135 = 0.0f;
            }
            temp_f0_1146 = (f32) sp878 * var_f3_1135;
            sp870 = (f32) sp870 * var_f3_1135;
            (*(f32 *) ((u8 *) &sp850 + 0x24)) *= var_f3_1135;
            sp878 = temp_f0_1146;
            sp120 = sp870 * 5.717499035e-315;
            sp118 = -1.0f;
            sp128 = temp_f0_1146 * 2000.0f;
            sp108 = 1.0f;
            sp110 = -1.0f;
            sp114 = -1.0f;
            sp100 = 1.0f;
            sp104 = 1.0f;
            sp520 = sp120;
            sp528 = (f64) sp128;
            sp4F0 = (f64) sp110;
            sp4F8 = (f64) sp118;
            sp4E0 = (f64) sp100;
            sp4E8 = (f64) sp108;
            sp500 = KDRand_Vector(*((MKVector3 *) &sp4F0), *((MKVector3 *) &sp4E0));
            spF0 = sp500 * 5.370091495e-315;
            spE8 = -1.0f;
            spD8 = 1.0f;
            spF8 = sp500.unk8 * 6.2831855f;
            spE0 = -1.0f;
            spE4 = -1.0f;
            spD0 = 1.0f;
            spD4 = 1.0f;
            sp510 = spF0;
            sp518 = (f64) spF8;
            sp4B0 = (f64) spE0;
            sp4B8 = (f64) spE8;
            sp4A0 = (f64) spD0;
            sp4A8 = (f64) spD8;
            sp4C0 = KDRand_Vector(*((MKVector3 *) &sp4B0), *((MKVector3 *) &sp4A0));
            temp_f0_1208 = sp4C0 * 5.370091495e-315;
            spC0 = temp_f0_1208;
            sp4D0 = temp_f0_1208;
            spC8 = sp4C0.unk8 * 6.2831855f;
            sp4D8 = (f64) spC8;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xB0)))->Emit(arg0, *((MKVector3 *) &sp520), *((MKVector3 *) &sp510), *((MKVector3 *) &sp4D0), MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_1029 += 1;
            goto loop_127;
        }
        return;
    case 6:                                         /* switch 1 */
        temp_f30_1242 = arg1.unk8;
        var_r22_1247 = 0;
loop_151:
        if (var_r22_1247 < arg4) {
            spA8 = 1.0f;
            spB8 = -1.0f;
            spA0 = 1.0f;
            spA4 = 2.0f;
            spB0 = -1.0f;
            spB4 = 1.0f;
            sp470 = (f64) spA0;
            sp478 = (f64) spA8;
            sp480 = (f64) spB0;
            sp488 = (f64) spB8;
            sp490 = KDRand_Vector(*((MKVector3 *) &sp480), *((MKVector3 *) &sp470));
            temp_f0_1270 = sp490 + M2C_FIELD(&arg1, f64 *, 0);
            sp90 = temp_f0_1270;
            sp860 = temp_f0_1270;
            sp98 = sp490.unk8 + temp_f30_1242;
            sp868 = (f64) sp98;
            var_f4_1286 = ((f32) sp868 * (f32) sp868) + (((f32) sp860 * (f32) sp860) + ((*(f32 *) ((u8 *) &sp850 + 0x14)) * (*(f32 *) ((u8 *) &sp850 + 0x14))));
            if (var_f4_1286 > 0.000001f) {
                if (var_f4_1286 > 0.0f) {
                    temp_f1_1292 = __frsqrte(var_f4_1286);
                    temp_f1_1298 = 0.5 * temp_f1_1292 * -(((f64) var_f4_1286 * (temp_f1_1292 * temp_f1_1292)) - 3.0);
                    temp_f1_1302 = 0.5 * temp_f1_1298 * -(((f64) var_f4_1286 * (temp_f1_1298 * temp_f1_1298)) - 3.0);
                    var_f4_1286 = (f32) ((f64) var_f4_1286 * (0.5 * temp_f1_1302 * -(((f64) var_f4_1286 * (temp_f1_1302 * temp_f1_1302)) - 3.0)));
                } else if (var_f4_1286 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1286 = __float_nan;
                } else {
                    sp8 = var_f4_1286;
                    temp_r3_1321 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1321) {         /* switch 7; irregular */
                    case 0x7F800000:                /* switch 7 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1331 = 1;
                        } else {
                            var_r0_1331 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 7 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1331 = 5;
                        } else {
                            var_r0_1331 = 3;
                        }
                        break;
                    default:                        /* switch 7 */
                        var_r0_1331 = 4;
                        break;
                    }
                    if (var_r0_1331 == 1) {
                        var_f4_1286 = __float_nan;
                    }
                }
                var_f3_1353 = 1.0f / var_f4_1286;
            } else {
                var_f3_1353 = 0.0f;
            }
            temp_f0_1364 = (f32) sp868 * var_f3_1353;
            sp860 = (f32) sp860 * var_f3_1353;
            (*(f32 *) ((u8 *) &sp850 + 0x14)) *= var_f3_1353;
            sp868 = temp_f0_1364;
            sp80 = sp860 * 5.717499035e-315;
            sp78 = -1.0f;
            sp88 = temp_f0_1364 * 2000.0f;
            sp68 = 1.0f;
            sp70 = -1.0f;
            sp74 = -1.0f;
            sp60 = 1.0f;
            sp64 = 1.0f;
            sp460 = sp80;
            sp468 = (f64) sp88;
            sp430 = (f64) sp70;
            sp438 = (f64) sp78;
            sp420 = (f64) sp60;
            sp428 = (f64) sp68;
            sp440 = KDRand_Vector(*((MKVector3 *) &sp430), *((MKVector3 *) &sp420));
            sp50 = sp440 * 5.370091495e-315;
            sp48 = -1.0f;
            sp38 = 1.0f;
            sp58 = sp440.unk8 * 6.2831855f;
            sp40 = -1.0f;
            sp44 = -1.0f;
            sp30 = 1.0f;
            sp34 = 1.0f;
            sp450 = sp50;
            sp458 = (f64) sp58;
            sp3F0 = (f64) sp40;
            sp3F8 = (f64) sp48;
            sp3E0 = (f64) sp30;
            sp3E8 = (f64) sp38;
            sp400 = KDRand_Vector(*((MKVector3 *) &sp3F0), *((MKVector3 *) &sp3E0));
            temp_f0_1426 = sp400 * 5.370091495e-315;
            sp20 = temp_f0_1426;
            sp410 = temp_f0_1426;
            sp28 = sp400.unk8 * 6.2831855f;
            sp418 = (f64) sp28;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xB4)))->Emit(arg0, *((MKVector3 *) &sp460), *((MKVector3 *) &sp450), *((MKVector3 *) &sp410), MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_1247 += 1;
            goto loop_151;
        }
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P21ShatterableDescriptor'
void Shatterable::SpawnGems(int arg0) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r29_1519;
    f64 temp_f0_1502;
    f64 temp_f1_1490;
    s32 temp_r29_1540;
    s32 var_r26_1532;
    s32 var_r27_1530;
    void *temp_r3_1488;

    if (arg0 != 0) {
        temp_r3_1488 = this->unk8;
        sp18 = 0.0f;
        temp_f1_1490 = M2C_FIELD(temp_r3_1488, f64 *, 0x30);
        sp1C = 150.0f;
        sp20 = 0.0f;
        sp28 = (f64) sp18;
        sp38 = temp_f1_1490;
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r3_1488, f64 *, 0x38);
        temp_f0_1502 = temp_f1_1490 + sp28;
        sp8 = temp_f0_1502;
        sp48 = temp_f0_1502;
        sp10 = (f32) sp40 + (f32) sp30;
        sp50 = (f64) sp10;
        if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk10C != 0) {
            temp_r29_1519 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
            KDSound_Play3d(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unk10C, temp_r29_1519, 0U, -1, 0.0f, 0U);
        }
        var_r27_1530 = 0;
        var_r26_1532 = 0;
loop_9:
        if (var_r26_1532 < arg0) {
            temp_r29_1540 = MKRand_Int((int *) &gViewSeed, 0, 4);
            if ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF8 != 0) || (temp_r29_1540 != 3)) && (((GameStats *) &GameData::gameData[0x70])->GetGemAvailable((StatType) temp_r29_1540) != 0)) {
                ((CollectableSpawner *) (M2C_FIELD(&(&gb)[temp_r29_1540], CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp48), 1, 200.0f, 500.0f, -1, (MKProp *) this);
                var_r27_1530 += 1;
            }
            var_r26_1532 += 1;
            goto loop_9;
        }
        if (var_r27_1530 == 0) {
            ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp48), 1, 200.0f, 500.0f, -1, (MKProp *) this);
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::TriggerShatterFX() {
    s32 spC;
    s32 sp8;
    ShatterableDescriptor *temp_r3_1601;
    s8 *temp_r3_1603;
    s8 *temp_r3_1612;

    temp_r3_1601 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_1603 = temp_r3_1601->unk110;
    if (temp_r3_1603 != NULL) {
        M2C_FIELD(temp_r3_1603, void **, 8) = (void *) this->unk8;
        ((FXBase *) temp_r3_1601->unk110)->Burst(*(this->unk8 + 0x30));
        temp_r3_1612 = temp_r3_1601->unk110;
        spC = 0;
        sp8 = 0xB5;
        M2C_FIELD(M2C_FIELD(temp_r3_1612, void **, 0x44), M2C_UNK (**)(s8 *, s32 *, M2C_UNK), 0x2C)(temp_r3_1612, &sp8, 0);
    }
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::PostShatter() {
    if (((s32) this->unk180 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x178) != 0)) {
        SetSmashPropState((SmashPropState) 0);
        this->unk178 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
        return;
    }
    SetSmashPropState((SmashPropState) 3);
    this->unk15C.Send(NULL);
    this->unk1A1 &= ~0x40;
}
#endif

#if 0 // DRAFT: undefined identifier 'P21ShatterableDescriptor'
void Shatterable::SetSmashPropState(SmashPropState arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r3_1760;

    if ((MKAnimScript *) this->unk80 != NULL) {
        if (((s32) arg0 == 0) && ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 != NULL)) {
            this->unk80->SetAnim(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkE4, 1.0f, 0.0f, 0, -1);
        } else if (((s32) this->unk17C == 0) && ((s32) arg0 == 1) && ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 != NULL)) {
            this->unk80->SetAnim(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkE8, 1.0f, 0.0f, 0, -1);
        }
    }
    if ((s32) arg0 == 2) {
        this->unk17C = (s32) arg0;
        spC = 0;
        sp8 = 0xBA;
        Message(&sp8);
        return;
    }
    if ((s32) arg0 == 1) {
        this->unk164.Send((MKProp *) this);
        this->unk190 += 1;
        if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF4 != 0) {
            temp_r3_1760 = this->unk190;
            SpawnGems((s32) ((f32) this->unk194 * (f32) ceil(temp_r3_1760, (f32) temp_r3_1760 * 0.25f)));
        }
        this->unk194 = 0;
    }
    this->unk17C = (s32) arg0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'MKMessage *'
void Shatterable::DestroyShatterable() {
    s32 spC;
    s32 sp8;
    s32 var_r30_1815;

    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
        spC = 0;
        var_r30_1815 = 0;
        sp8 = 0xBA;
loop_3:
        if (var_r30_1815 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
            this->unk17C = 2;
            Message(&sp8);
            var_r30_1815 += 1;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Shatterable::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_1850;

    temp_r3_1850 = this->unk170;
    if (temp_r3_1850 != NULL) {
        spC = 0;
        sp8 = 0x24;
        sp10 = &this->unk140;
        sp14 = 0;
        sp18 = 0;
        M2C_FIELD(temp_r3_1850->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x24, 0);
        this->unk170 = NULL;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Shatterable::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp18;
    u8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_1888;

    PlatformDetach();
    this->unk170 = arg0;
    temp_r3_1888 = this->unk170;
    if (temp_r3_1888 != NULL) {
        spC = 0;
        sp8 = 0x23;
        sp10 = &this->unk140;
        sp14 = 0;
        sp18 = arg1;
        M2C_FIELD(temp_r3_1888->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x23, 0);
        if (sp14 == 0) {
            this->unk170 = NULL;
        }
    }
}
#endif

void Shatterable::SetStateAnim(int arg0) {
    s32 temp_r31_1931;

    if ((MKAnimScript *) this->unk80 != NULL) {
        temp_r31_1931 = arg0 * 4;
        if ((u32) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + temp_r31_1931), u32 *, 0x120) != 0U) {
            this->unk80->SetAnim(M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + temp_r31_1931), MKAnim **, 0x120), 1.0f, 0.0f, 0, -1);
        }
    }
}

#if 0 // DRAFT: illegal type
void Shatterable::EnableCollision() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x100000U);
    *(this->unk168 + ((this->unk180 << 7) + 0x6C)) = 1;
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::DisableCollision() {
    PropFlagsClear((unsigned int *) &this->unk10, 0x100000U);
    *(this->unk168 + ((this->unk180 << 7) + 0x6C)) = 0;
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3, bool arg4, bool arg5) {
    s8 sp70;
    f64 sp68;
    f64 sp60;
    s32 sp5C;
    s32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r29_2254;
    MKVector3 *var_r26_2164;
    MKVector3 *var_r3_2114;
    Shatterable *temp_r26_2301;
    ShatterableDescriptor *temp_r26_2263;
    ShatterableDescriptor *temp_r27_2259;
    ShatterableDescriptor *temp_r28_2256;
    f32 temp_f31_2389;
    f32 temp_f4_2379;
    f32 var_f0_2125;
    s32 temp_r0_2196;
    s32 temp_r0_2208;
    s32 temp_r0_2236;
    s32 temp_r3_2052;
    s32 temp_r4_2095;
    s32 temp_r4_2148;
    s32 temp_r4_2221;
    s32 temp_r4_2330;
    s32 var_r26_2202;
    s32 var_r28_2203;
    s32 var_r4_2174;
    void **temp_r3_2307;
    void *temp_r4_2112;
    void *temp_r5_2099;

    if (((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x178) != 0) && ((s32) this->unk180 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160)) {
        if (((u8) this->unk1A2 != 0) && ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk104 != 0)) {
            temp_r3_2052 = KDSound_Play(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unk104, 0U, -1);
            if (temp_r3_2052 != 0) {
                KDSound_SetPitch(temp_r3_2052, (0.1f * (f32) this->unk180) + 1.0f);
            }
        }
        if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 3U) & 1) {
            this->unkD0.Show(0U);
        }
        TriggerShatterFX();
        if (((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF4 != 0) && (arg5 == 0)) {
            SpawnGems(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkF4);
        }
        temp_r4_2095 = this->unk180;
        temp_r5_2099 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C;
        sp20 = 0.0f;
        sp18 = 0.0f;
        sp1C = M2C_FIELD((((u8 *) temp_r5_2099) + (temp_r4_2095 * 0x17C)), f32 *, 0x15C);
        sp50 = (f64) sp20;
        sp48 = (f64) sp18;
        temp_r4_2112 = ((u8 *) this->unk168) + ((temp_r4_2095 << 7) + 0x20);
        if (arg3 != NULL) {
            var_r3_2114 = arg3;
        } else {
            var_r3_2114 = (MKVector3 *) &sp48;
        }
        M2C_FIELD(temp_r4_2112, f64 *, 0) = (f64) M2C_FIELD(var_r3_2114, f64 *, 0);
        M2C_FIELD(temp_r4_2112, f64 *, 8) = (f64) M2C_FIELD(var_r3_2114, f64 *, 8);
        if (arg0 != 0) {
            var_f0_2125 = 0.2f;
        } else {
            var_f0_2125 = 1.0f;
        }
        M2C_FIELD((((u8 *) this->unk168) + (this->unk180 << 7)), f32 *, 0x38) = var_f0_2125;
        *(this->unk168 + ((this->unk180 << 7) + 0x6C)) = 0;
        if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk108 != 0) && (temp_r4_2148 = this->unk180, (((s32) (temp_r4_2148 + 1) < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) != 0))) {
            ((KDShatter2 *) (((u8 *) this->unk168) + (temp_r4_2148 << 7)))->Shatter(0, ((u8 *) this->unk8) + 0x30);
        } else {
            if (arg1 != NULL) {
                var_r26_2164 = arg1;
            } else {
                var_r26_2164 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
            }
            if (arg2 == -1) {
                var_r4_2174 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk15C;
            } else {
                var_r4_2174 = arg2;
            }
            ((KDShatter2 *) (((u8 *) this->unk168) + (this->unk180 << 7)))->Shatter(var_r4_2174, var_r26_2164);
        }
        *(this->unk168 + ((this->unk180 << 7) + 0x6C)) = 1;
        temp_r0_2196 = *(this->unk168 + ((this->unk180 << 7) + 0x44));
        if ((temp_r0_2196 == 1) || (temp_r0_2196 == 2)) {
            var_r26_2202 = 0;
            var_r28_2203 = 0;
loop_32:
            if (var_r28_2203 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
                temp_r0_2208 = var_r26_2202 + 0x6C;
                var_r28_2203 += 1;
                var_r26_2202 += 0x80;
                *(this->unk168 + temp_r0_2208) = 0;
                goto loop_32;
            }
            temp_r4_2221 = this->unk180;
            if (temp_r4_2221 < (s32) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1)) {
                *(this->unk168 + (((temp_r4_2221 + 1) << 7) + 0x6C)) = 1;
            }
            temp_r0_2236 = *(this->unk168 + ((this->unk180 << 7) + 0x44));
            if (temp_r0_2236 == 1) {
                this->unk16C = 2;
                SetStateAnim(1);
                if ((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk154 > 0.0f) && (arg4 != 0)) {
                    temp_r29_2254 = ((u8 *) this->unk8) + 0x30;
                    temp_r28_2256 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    temp_r27_2259 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    temp_r26_2263 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **, void ***), 0x40)(M2C_FIELD(&gb, void ***, 0), &gb)))->RumblePlay3D(temp_r26_2263->unk14C, temp_r27_2259->unk150, temp_r28_2256->unk154, temp_r29_2254, 37.0f, 0, 4.0f, 0U);
                }
            } else if (temp_r0_2236 == 2) {
                this->unk16C = 0;
                this->unk188 = 0.0f;
                SetStateAnim(2);
            }
            this->unk160.Send((MKProp *) this);
            if ((u32) M2C_FIELD((((u8 *) this->unk168) + (this->unk180 << 7)), u32 *, 0x78) != 0U) {
                temp_r26_2301 = *KDProperty::pInstanceMem;
                *KDProperty::pInstanceMem = this;
                temp_r3_2307 = M2C_FIELD((((u8 *) this->unk168) + (this->unk180 << 7)), void ***, 0x78);
                M2C_FIELD(*temp_r3_2307, M2C_UNK (**)(void **), 0x4C)(temp_r3_2307);
                *KDProperty::pInstanceMem = temp_r26_2301;
            }
        }
        ((KDShatter2 *) (((u8 *) this->unk168) + (this->unk180 << 7)))->ClearVisible();
        this->unk180 += 1;
        if (!(this->unk10 & 0x100000)) {
            DisableCollision();
        }
        temp_r4_2330 = this->unk180;
        if (temp_r4_2330 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
            ((KDShatter2 *) (((u8 *) this->unk168) + (temp_r4_2330 << 7)))->SetVisibleUnshattered();
        }
        if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) && (((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 == 0) || ((s32) this->unk180 == (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) || ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x178) == 0))) {
            this->unkC8.UnregisterTargetable();
        }
        if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk166 != 0)) {
            temp_f4_2379 = this->unk18C;
            if (temp_f4_2379 != 0.0f) {
                sp5C = 0;
                temp_f31_2389 = 100.0f * temp_f4_2379;
                sp28 = MKVector(1.0f, 1.0f, 1.0f);
                sp8 = sp28 * (f64) temp_f31_2389;
                sp58 = 0x417;
                sp60 = sp8;
                sp10 = sp28.unk8 * temp_f31_2389;
                sp70 = 1;
                sp68 = (f64) sp10;
                sp38 = sp8;
                sp40 = (f64) sp10;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp58, sp8);
            }
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Shatterable::Message(MKMessage *arg0) {
    struct __vt *vtable174;
    s32 sp170;
    s8 sp16C;
    s32 sp168;
    s32 sp164;
    s8 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    s32 sp14C;
    s32 sp148;
    f64 sp140;
    f64 sp138;                                      /* compiler-managed */
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
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
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
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSoundPlayer *temp_r3_2486;
    MKHeap **temp_r3_2890;
    MKSceneManager *temp_r0_3687;
    MKVector3 *temp_r28_2803;
    Shatterable ***temp_r4_2716;
    Shatterable **temp_r3_2738;
    Shatterable **temp_r3_2742;
    Shatterable **var_r3_2719;
    Shatterable *temp_r0_2728;
    Shatterable *temp_r28_3455;
    Shatterable *var_r0_3856;
    ShatterableDescriptor *temp_r28_3363;
    ShatterableDescriptor *temp_r28_3771;
    f32 temp_f0_2610;
    f32 temp_f0_2894;
    f32 temp_f1_2893;
    f32 temp_f1_2971;
    f32 temp_f2_2638;
    f32 temp_f2_2836;
    f32 temp_f2_2896;
    f32 temp_f2_3586;
    f32 temp_f31_3211;
    f32 temp_f3_2623;
    f32 temp_f3_2970;
    f32 temp_f3_3043;
    f32 temp_f4_2620;
    f32 temp_f4_2973;
    f32 temp_f4_3042;
    f32 temp_f5_2616;
    f32 temp_f5_3045;
    f32 var_f0_2639;
    f32 var_f0_2837;
    f32 var_f0_2904;
    f32 var_f0_3587;
    f32 var_f1_2977;
    f32 var_f4_3191;
    f32 var_f4_3237;
    f32 var_f5_3124;
    f32 var_f6_3049;
    f32 var_f6_3197;
    f64 temp_f0_3317;
    f64 temp_f0_3330;
    f64 temp_f1_3130;
    f64 temp_f1_3136;
    f64 temp_f1_3140;
    f64 temp_f1_3242;
    f64 temp_f1_3248;
    f64 temp_f1_3252;
    f64 temp_f2_2908;
    f64 temp_f2_2914;
    f64 temp_f2_2918;
    f64 temp_f3_2980;
    f64 temp_f3_2986;
    f64 temp_f3_2990;
    f64 temp_f3_3052;
    f64 temp_f3_3058;
    f64 temp_f3_3062;
    s32 temp_r0_2491;
    s32 temp_r0_3570;
    s32 temp_r3_2814;
    s32 temp_r3_2937;
    s32 temp_r3_3009;
    s32 temp_r3_3081;
    s32 temp_r3_3159;
    s32 temp_r3_3271;
    s32 temp_r3_3561;
    s32 temp_r3_3644;
    s32 var_r0_2947;
    s32 var_r0_3019;
    s32 var_r0_3091;
    s32 var_r0_3169;
    s32 var_r0_3281;
    s32 var_r28_3756;
    s32 var_r28_3783;
    u32 temp_r3_3870;
    u32 temp_r3_3881;
    void **temp_r3_3461;
    void *temp_r28_2595;
    void *temp_r28_3688;
    void *temp_r31_2713;
    void *temp_r3_2606;
    void *temp_r3_2968;
    void *temp_r3_3040;
    void *temp_r3_3209;
    void *temp_r3_3324;
    void *temp_r3_3535;
    void *temp_r3_3754;
    void *temp_r3_3854;
    void *temp_r4_2891;
    void *temp_r4_3458;
    void *temp_r4_3872;
    void *temp_r4_3882;
    void *temp_r5_2680;

    temp_r3_2486 = this->unk100;
    if (temp_r3_2486 != NULL) {
        temp_r3_2486->Message(arg0);
    }
    temp_r0_2491 = arg0->unk0;
    switch (temp_r0_2491) {                         /* switch 1; irregular */
    case 179:                                       /* switch 1 */
        EnableCollision();
    default:                                        /* switch 1 */
block_296:
        GameProp::Message(arg0);
        return;
    case 178:                                       /* switch 1 */
        DisableCollision();
        goto block_296;
    case 353:                                       /* switch 1 */
        this->unk19C = 1;
        goto block_296;
    case 352:                                       /* switch 1 */
        this->unk19C = 0;
        goto block_296;
    case 1:                                         /* switch 1 */
        if (this->unk10 & 0x160000) {
            if ((u8) this->unk19C == 0) {
                return;
            }
            if (((s32) this->unk16C == 2) && ((s32) this->unk17C == 0)) {
                temp_r28_2595 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
                if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 4U) & 1) {
                    temp_r3_2606 = this->unk8;
                    temp_f0_2610 = M2C_FIELD(temp_r28_2595, f32 *, 0x20) + GetCollisionRadius();
                    sp108 = M2C_FIELD(temp_r3_2606, f64 *, 0x30);
                    sp110 = M2C_FIELD(temp_r3_2606, f64 *, 0x38);
                    temp_f5_2616 = (*(f32 *) ((u8 *) &sp108 + 0x4)) - M2C_FIELD(temp_r28_2595, f32 *, 0x14);
                    temp_f4_2620 = (f32) sp108 - M2C_FIELD(temp_r28_2595, f32 *, 0x10);
                    temp_f3_2623 = (f32) sp110 - M2C_FIELD(temp_r28_2595, f32 *, 0x18);
                    if (((temp_f3_2623 * temp_f3_2623) + ((temp_f4_2620 * temp_f4_2620) + (temp_f5_2616 * temp_f5_2616))) < (temp_f0_2610 * temp_f0_2610)) {
                        if (this->unk178 > 0.0f) {
                            temp_f2_2638 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
                            var_f0_2639 = this->unk178 - M2C_FIELD(temp_r28_2595, f32 *, 0x2C);
                            if (var_f0_2639 < temp_f2_2638) {

                            } else {
                                var_f0_2639 = temp_f2_2638;
                            }
                            if (var_f0_2639 > 0.0f) {

                            } else {
                                var_f0_2639 = 0.0f;
                            }
                            this->unk178 = var_f0_2639;
                            this->unk194 = (s32) M2C_FIELD(temp_r28_2595, f32 *, 0x2C);
                        } else {
                            this->unk194 = 0;
                        }
                        SetSmashPropState((SmashPropState) 1);
                        return;
                    }
                }
            } else {
                if (!(((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk164 >> 6U) & 1) && ((u32) M2C_FIELD(checked_cast<ExplodeMsg *, MKMessage>(arg0), u32 *, 8) != this)) {
                    temp_r5_2680 = this->unk8;
                    spF8 = M2C_FIELD(temp_r5_2680, f64 *, 0x30);
                    sp100 = M2C_FIELD(temp_r5_2680, f64 *, 0x38);
                }
                goto block_296;
            }
        }
        break;
    case 4:                                         /* switch 1 */
        if ((this->unk10 & 0x160000) && ((u8) this->unk19C != 0)) {
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x179) == 0) {
                return;
            }
            if (((s32) this->unk16C == 2) && ((s32) this->unk17C == 0) && (temp_r31_2713 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0), (((s32) this->unk17C == 0) != 0))) {
                temp_r4_2716 = M2C_FIELD(temp_r31_2713, Shatterable ****, 0x34);
                if (temp_r4_2716 != NULL) {
                    var_r3_2719 = *temp_r4_2716;
loop_81:
                    temp_r0_2728 = *var_r3_2719;
                    if (temp_r0_2728 == NULL) {
                        var_r3_2719 = NULL;
                    } else if (temp_r0_2728 == this) {

                    } else {
                        var_r3_2719 += 4;
                        goto loop_81;
                    }
                    if (var_r3_2719 == NULL) {
                        goto block_84;
                    }
                } else {
block_84:
                    if (temp_r4_2716 != NULL) {
                        temp_r3_2738 = *temp_r4_2716;
                        if ((u32) M2C_FIELD(temp_r3_2738, u32 *, -4) != 0U) {
                            temp_r3_2742 = temp_r3_2738 - 4;
                            *temp_r4_2716 = temp_r3_2742;
                            *temp_r3_2742 = this;
                        }
                    }
                    if (((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 7U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x1FF)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 6U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x200)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 5U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x400)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 1U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x2000)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 4U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x1000))) {
                        this->unk1A1 |= 0x80;
                        M2C_FIELD(temp_r31_2713, s8 *, 0x3E) = 1;
                        if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk100 != 0) {
                            temp_r28_2803 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
                            KDSound_Play3d(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unk100, temp_r28_2803, 0U, -1, 0.0f, 0U);
                        } else {
                            temp_r3_2814 = M2C_FIELD(temp_r31_2713, s32 *, 0x2C);
                            if ((temp_r3_2814 > 0) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x400)) {
                                KDSound_Play3d(temp_r3_2814, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                            }
                        }
                        if (this->unk178 > 0.0f) {
                            temp_f2_2836 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
                            var_f0_2837 = this->unk178 - M2C_FIELD(temp_r31_2713, f32 *, 0x20);
                            if (var_f0_2837 < temp_f2_2836) {

                            } else {
                                var_f0_2837 = temp_f2_2836;
                            }
                            if (var_f0_2837 > 0.0f) {

                            } else {
                                var_f0_2837 = 0.0f;
                            }
                            this->unk178 = var_f0_2837;
                            this->unk194 = (s32) M2C_FIELD(temp_r31_2713, f32 *, 0x20);
                        } else {
                            this->unk194 = 0;
                        }
                        if ((this->unk178 <= 0.0f) && ((s32) this->unk16C == 2) && ((s32) this->unk17C == 0)) {
                            SetSmashPropState((SmashPropState) 1);
                        } else if (((s32) this->unk16C == 2) && ((s32) this->unk17C == 0)) {
                            SetSmashPropState((SmashPropState) 1);
                            temp_r3_2890 = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1);
                            temp_r4_2891 = this->unk8;
                            temp_f1_2893 = M2C_FIELD(temp_r4_2891, f32 *, 0x20);
                            temp_f0_2894 = M2C_FIELD(temp_r4_2891, f32 *, 0x24);
                            temp_f2_2896 = M2C_FIELD(temp_r4_2891, f32 *, 0x28);
                            sp138 = M2C_FIELD(temp_r3_2890, f64 *, 0x10);
                            sp140 = M2C_FIELD(temp_r3_2890, f64 *, 0x18);
                            var_f0_2904 = (temp_f2_2896 * temp_f2_2896) + ((temp_f1_2893 * temp_f1_2893) + (temp_f0_2894 * temp_f0_2894));
                            (*(f32 *) ((u8 *) &sp130 + 0xc)) = 0.0f;
                            if (var_f0_2904 > 0.0f) {
                                temp_f2_2908 = __frsqrte(var_f0_2904);
                                temp_f2_2914 = 0.5 * temp_f2_2908 * -(((f64) var_f0_2904 * (temp_f2_2908 * temp_f2_2908)) - 3.0);
                                temp_f2_2918 = 0.5 * temp_f2_2914 * -(((f64) var_f0_2904 * (temp_f2_2914 * temp_f2_2914)) - 3.0);
                                var_f0_2904 = (f32) ((f64) var_f0_2904 * (0.5 * temp_f2_2918 * -(((f64) var_f0_2904 * (temp_f2_2918 * temp_f2_2918)) - 3.0)));
                            } else if (var_f0_2904 < M2C_BITWISE(f32, 0.0)) {
                                var_f0_2904 = __float_nan;
                            } else {
                                sp18 = var_f0_2904;
                                temp_r3_2937 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                                switch (temp_r3_2937) { /* switch 2; irregular */
                                case 0x7F800000:    /* switch 2 */
                                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                        var_r0_2947 = 1;
                                    } else {
                                        var_r0_2947 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 2 */
                                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                        var_r0_2947 = 5;
                                    } else {
                                        var_r0_2947 = 3;
                                    }
                                    break;
                                default:            /* switch 2 */
                                    var_r0_2947 = 4;
                                    break;
                                }
                                if (var_r0_2947 == 1) {
                                    var_f0_2904 = __float_nan;
                                }
                            }
                            temp_r3_2968 = this->unk8;
                            temp_f3_2970 = M2C_FIELD(temp_r3_2968, f32 *, 0);
                            temp_f1_2971 = M2C_FIELD(temp_r3_2968, f32 *, 4);
                            temp_f4_2973 = M2C_FIELD(temp_r3_2968, f32 *, 8);
                            var_f1_2977 = (temp_f4_2973 * temp_f4_2973) + ((temp_f3_2970 * temp_f3_2970) + (temp_f1_2971 * temp_f1_2971));
                            if (var_f1_2977 > 0.0f) {
                                temp_f3_2980 = __frsqrte(var_f1_2977);
                                temp_f3_2986 = 0.5 * temp_f3_2980 * -(((f64) var_f1_2977 * (temp_f3_2980 * temp_f3_2980)) - 3.0);
                                temp_f3_2990 = 0.5 * temp_f3_2986 * -(((f64) var_f1_2977 * (temp_f3_2986 * temp_f3_2986)) - 3.0);
                                var_f1_2977 = (f32) ((f64) var_f1_2977 * (0.5 * temp_f3_2990 * -(((f64) var_f1_2977 * (temp_f3_2990 * temp_f3_2990)) - 3.0)));
                            } else if (var_f1_2977 < M2C_BITWISE(f32, 0.0)) {
                                var_f1_2977 = __float_nan;
                            } else {
                                sp14 = var_f1_2977;
                                temp_r3_3009 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                                switch (temp_r3_3009) { /* switch 3; irregular */
                                case 0x7F800000:    /* switch 3 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_3019 = 1;
                                    } else {
                                        var_r0_3019 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 3 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_3019 = 5;
                                    } else {
                                        var_r0_3019 = 3;
                                    }
                                    break;
                                default:            /* switch 3 */
                                    var_r0_3019 = 4;
                                    break;
                                }
                                if (var_r0_3019 == 1) {
                                    var_f1_2977 = __float_nan;
                                }
                            }
                            temp_r3_3040 = this->unk8;
                            temp_f4_3042 = M2C_FIELD(temp_r3_3040, f32 *, 0x10);
                            temp_f3_3043 = M2C_FIELD(temp_r3_3040, f32 *, 0x14);
                            temp_f5_3045 = M2C_FIELD(temp_r3_3040, f32 *, 0x18);
                            var_f6_3049 = (temp_f5_3045 * temp_f5_3045) + ((temp_f4_3042 * temp_f4_3042) + (temp_f3_3043 * temp_f3_3043));
                            if (var_f6_3049 > 0.0f) {
                                temp_f3_3052 = __frsqrte(var_f6_3049);
                                temp_f3_3058 = 0.5 * temp_f3_3052 * -(((f64) var_f6_3049 * (temp_f3_3052 * temp_f3_3052)) - 3.0);
                                temp_f3_3062 = 0.5 * temp_f3_3058 * -(((f64) var_f6_3049 * (temp_f3_3058 * temp_f3_3058)) - 3.0);
                                var_f6_3049 = (f32) ((f64) var_f6_3049 * (0.5 * temp_f3_3062 * -(((f64) var_f6_3049 * (temp_f3_3062 * temp_f3_3062)) - 3.0)));
                            } else if (var_f6_3049 < M2C_BITWISE(f32, 0.0)) {
                                var_f6_3049 = __float_nan;
                            } else {
                                sp10 = var_f6_3049;
                                temp_r3_3081 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                                switch (temp_r3_3081) { /* switch 4; irregular */
                                case 0x7F800000:    /* switch 4 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_3091 = 1;
                                    } else {
                                        var_r0_3091 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 4 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_3091 = 5;
                                    } else {
                                        var_r0_3091 = 3;
                                    }
                                    break;
                                default:            /* switch 4 */
                                    var_r0_3091 = 4;
                                    break;
                                }
                                if (var_r0_3091 == 1) {
                                    var_f6_3049 = __float_nan;
                                }
                            }
                            var_f5_3124 = ((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + ((*(f32 *) ((u8 *) &sp130 + 0xc)) * (*(f32 *) ((u8 *) &sp130 + 0xc))));
                            if (var_f5_3124 > 0.000001f) {
                                if (var_f5_3124 > 0.0f) {
                                    temp_f1_3130 = __frsqrte(var_f5_3124);
                                    temp_f1_3136 = 0.5 * temp_f1_3130 * -(((f64) var_f5_3124 * (temp_f1_3130 * temp_f1_3130)) - 3.0);
                                    temp_f1_3140 = 0.5 * temp_f1_3136 * -(((f64) var_f5_3124 * (temp_f1_3136 * temp_f1_3136)) - 3.0);
                                    var_f5_3124 = (f32) ((f64) var_f5_3124 * (0.5 * temp_f1_3140 * -(((f64) var_f5_3124 * (temp_f1_3140 * temp_f1_3140)) - 3.0)));
                                } else if (var_f5_3124 < M2C_BITWISE(f32, 0.0)) {
                                    var_f5_3124 = __float_nan;
                                } else {
                                    spC = var_f5_3124;
                                    temp_r3_3159 = M2C_BITWISE(s32, spC) & 0x7F800000;
                                    switch (temp_r3_3159) { /* switch 5; irregular */
                                    case 0x7F800000: /* switch 5 */
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_3169 = 1;
                                        } else {
                                            var_r0_3169 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 5 */
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_3169 = 5;
                                        } else {
                                            var_r0_3169 = 3;
                                        }
                                        break;
                                    default:        /* switch 5 */
                                        var_r0_3169 = 4;
                                        break;
                                    }
                                    if (var_r0_3169 == 1) {
                                        var_f5_3124 = __float_nan;
                                    }
                                }
                                var_f4_3191 = 1.0f / var_f5_3124;
                            } else {
                                var_f4_3191 = 0.0f;
                                var_f5_3124 = 0.0f;
                            }
                            var_f6_3197 = 0.0f;
                            sp60 = 0.0f;
                            temp_r3_3209 = ((u8 *) this->unk8) + 0x30;
                            sp58 = 0.0f;
                            temp_f31_3211 = 0.5f * (0.333333f * (var_f0_2904 + (var_f1_2977 + var_f6_3049)) * var_f5_3124);
                            sp5C = 200.0f;
                            sp138 = (f32) sp138 * var_f4_3191;
                            (*(f32 *) ((u8 *) &sp130 + 0xc)) *= var_f4_3191;
                            spA8 = (f64) sp58;
                            spB0 = (f64) sp60;
                            sp88 = M2C_FIELD(temp_r31_2713, f64 *, 0x10) - M2C_FIELD(temp_r3_3209, f64 *, 0);
                            spB8 = sp88;
                            sp90 = M2C_FIELD(temp_r31_2713, f32 *, 0x18) - M2C_FIELD(temp_r3_3209, f32 *, 8);
                            spC0 = (f64) sp90;
                            var_f4_3237 = ((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + ((*(f32 *) ((u8 *) &spB8 + 0x4)) * (*(f32 *) ((u8 *) &spB8 + 0x4))));
                            if (var_f4_3237 > 1e-12f) {
                                if (var_f4_3237 > 0.0f) {
                                    temp_f1_3242 = __frsqrte(var_f4_3237);
                                    temp_f1_3248 = 0.5 * temp_f1_3242 * -(((f64) var_f4_3237 * (temp_f1_3242 * temp_f1_3242)) - 3.0);
                                    temp_f1_3252 = 0.5 * temp_f1_3248 * -(((f64) var_f4_3237 * (temp_f1_3248 * temp_f1_3248)) - 3.0);
                                    var_f4_3237 = (f32) ((f64) var_f4_3237 * (0.5 * temp_f1_3252 * -(((f64) var_f4_3237 * (temp_f1_3252 * temp_f1_3252)) - 3.0)));
                                } else if (var_f4_3237 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_3237 = __float_nan;
                                } else {
                                    sp8 = var_f4_3237;
                                    temp_r3_3271 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                    switch (temp_r3_3271) { /* switch 6; irregular */
                                    case 0x7F800000: /* switch 6 */
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_3281 = 1;
                                        } else {
                                            var_r0_3281 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 6 */
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_3281 = 5;
                                        } else {
                                            var_r0_3281 = 3;
                                        }
                                        break;
                                    default:        /* switch 6 */
                                        var_r0_3281 = 4;
                                        break;
                                    }
                                    if (var_r0_3281 == 1) {
                                        var_f4_3237 = __float_nan;
                                    }
                                }
                                var_f6_3197 = 1.0f / var_f4_3237;
                            }
                            sp3C = (*(f32 *) ((u8 *) &spB8 + 0x4)) * var_f6_3197;
                            sp38 = (f32) spB8 * var_f6_3197;
                            sp40 = (f32) spC0 * var_f6_3197;
                            spC8 = (f64) sp38;
                            spD0 = (f64) sp40;
                            temp_f0_3317 = spC8 * (f64) temp_f31_3211;
                            sp78 = temp_f0_3317;
                            spD8 = temp_f0_3317;
                            temp_r3_3324 = ((u8 *) this->unk8) + 0x30;
                            sp80 = (f32) spD0 * temp_f31_3211;
                            spE0 = (f64) sp80;
                            temp_f0_3330 = M2C_FIELD(temp_r3_3324, f64 *, 0) + temp_f0_3317;
                            sp68 = temp_f0_3330;
                            spE8 = temp_f0_3330;
                            sp70 = M2C_FIELD(temp_r3_3324, f32 *, 8) + (f32) spE0;
                            spF0 = (f64) sp70;
                            sp48 = spE8 + spA8;
                            sp30 = 0.0f;
                            sp28 = 0.0f;
                            sp2C = 1.0f;
                            sp50 = (f32) spF0 + (f32) spB0;
                            sp128 = sp48;
                            sp130 = (f64) sp50;
                            sp98 = (f64) sp28;
                            spA0 = (f64) sp30;
                            temp_r28_3363 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                            temp_r28_3363->EmitHitEffects(*((MKVector3 *) &sp128), *((MKVector3 *) &sp98), *(MKModel_GetColor(this->unk4)), (MKProp *) this, 5);
                        }
                        goto block_296;
                    }
                    if ((M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x400) && !(((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 5U) & 1)) {
                        KDSound_Play3d(GS_SpyroStompLand, ((u8 *) temp_r31_2713) + 0x10, 0U, -1, 0.0f, 0U);
                        ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(0.5f, 0.7f, 0.1f, 0, 4.0f, 0U);
                        return;
                    }
                }
            } else {
                goto block_296;
            }
        }
        break;
    case 49:                                        /* switch 1 */
        if ((this->unk10 & 0x160000) && ((u8) this->unk19C != 0)) {
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x179) == 0) {
                return;
            }
            if (((s32) this->unk16C == 2) && ((s32) this->unk17C == 0) && (checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 & 1) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x178) != 0)) {
loop_223:
                if (((s32) this->unk180 < (s32) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1)) && ((u8) *(checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((this->unk180 * 0x17C) + 0x2F4)) != 0)) {
                    this->unk160.Send((MKProp *) this);
                    if ((u32) *(this->unk168 + ((this->unk180 << 7) + 0x78)) != 0U) {
                        temp_r28_3455 = (Shatterable *) (*KDProperty::pInstanceMem);
                        *KDProperty::pInstanceMem = (unsigned char) (this);
                        temp_r4_3458 = this->unk168;
                        temp_r3_3461 = *(temp_r4_3458 + ((this->unk180 << 7) + 0x78));
                        M2C_FIELD(*temp_r3_3461, M2C_UNK (**)(void **, void *), 0x4C)(temp_r3_3461, temp_r4_3458);
                        *KDProperty::pInstanceMem = (unsigned char) (temp_r28_3455);
                    }
                    this->unk180 += 1;
                    goto loop_223;
                }
                this->unk178 = 0.0f;
                SetSmashPropState((SmashPropState) 1);
                M2C_FIELD(checked_cast<ShatterOnCollisionMsg *, MKMessage>(arg0), s8 *, 0x18) = 1;
            }
            goto block_296;
        }
        break;
    case 136:                                       /* switch 1 */
        if (((s32) this->unk16C == 2) && ((s32) this->unk17C == 0) && ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk115 == 1)) {
            M2C_FIELD(checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0), s8 *, 8) = 1;
        }
        goto block_296;
    case 5:                                         /* switch 1 */
        if ((this->unk10 & 0x160000) && ((u8) this->unk19C != 0)) {
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x179) == 0) {
                return;
            }
            temp_r3_3535 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
            if ((s32) M2C_FIELD(temp_r3_3535, s32 *, 0x38) == 3) {
                if ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 2U) & 1) && ((s32) this->unk17C != 3)) {
                    DestroyShatterable();
                    return;
                }
            } else {
                if ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 1U) & 1) && (((temp_r3_3561 = M2C_FIELD(temp_r3_3535, s32 *, 0x38), ((temp_r3_3561 == 0) != 0)) && ((s32) M2C_FIELD(temp_r3_3535, s32 *, 0x40) == 3)) || ((temp_r3_3561 == 1) && ((temp_r0_3570 = M2C_FIELD(temp_r3_3535, s32 *, 0x40), ((temp_r0_3570 == 0) != 0)) || (temp_r0_3570 == 3) || (temp_r0_3570 == 2))))) {
                    if (this->unk178 > 0.0f) {
                        temp_f2_3586 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
                        var_f0_3587 = this->unk178 - M2C_FIELD(temp_r3_3535, f32 *, 0x34);
                        if (var_f0_3587 < temp_f2_3586) {

                        } else {
                            var_f0_3587 = temp_f2_3586;
                        }
                        if (var_f0_3587 > 0.0f) {

                        } else {
                            var_f0_3587 = 0.0f;
                        }
                        this->unk178 = var_f0_3587;
                        this->unk194 = (s32) M2C_FIELD(temp_r3_3535, f32 *, 0x34);
                    } else {
                        this->unk194 = 0;
                    }
                    M2C_FIELD(temp_r3_3535, s8 *, 0x50) = 1;
                    if ((this->unk178 <= 0.0f) && ((s32) this->unk16C == 2) && ((s32) this->unk17C == 0)) {
                        SetSmashPropState((SmashPropState) 2);
                    } else if (((s32) this->unk16C == 2) && ((s32) this->unk17C == 0)) {
                        SetSmashPropState((SmashPropState) 1);
                    }
                }
                goto block_296;
            }
        }
        break;
    case 186:                                       /* switch 1 */
        if (this->unk10 & 0x160000) {
            temp_r3_3644 = this->unk16C;
            if ((temp_r3_3644 == 2) && ((s32) this->unk17C == 0)) {
                SetSmashPropState((SmashPropState) 2);
                return;
            }
            if (temp_r3_3644 == 2) {
                sp14C = 0;
                vtable174 = &__vt;
                sp148 = 0x30;
                sp150 = 0.0f;
                sp154 = 0.0f;
                sp158 = 0.0f;
                sp160 = 0;
                sp164 = -1;
                sp168 = 0;
                sp16C = 0;
                sp170 = 0;
                Message(&sp148, 0x30, &__vt, 0);
            }
            goto block_296;
        }
        break;
    case 48:                                        /* switch 1 */
        if (((s32) this->unk16C == 2) && ((temp_r0_3687 = this->unk184, temp_r28_3688 = checked_cast<ShatterExtendedMsg *, MKMessage>(arg0), ((temp_r0_3687 == NULL) != 0)) || (MKSceneManager::PropResolver_Resolve((s32) temp_r0_3687) == (u32) M2C_FIELD(temp_r28_3688, u32 *, 0x28)))) {
            M2C_FIELD(temp_r28_3688, s8 *, 0x18) = 1;
            sp118 = M2C_FIELD(temp_r28_3688, f64 *, 8);
            sp120 = M2C_FIELD(temp_r28_3688, f64 *, 0x10);
            (*(f32 *) ((u8 *) &sp118 + 0x4)) = M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), f32 *, 0x15C);
            Shatter(M2C_FIELD(temp_r28_3688, u8 *, 0x24), M2C_FIELD(temp_r28_3688, s32 *, 0x20), M2C_FIELD(temp_r28_3688, s32 *, 0x1C), &sp118, 1, 0);
        }
        goto block_296;
    case 77:                                        /* switch 1 */
        if ((s32) this->unk16C == 2) {
            sp20 = 0;
            sp1C = 0xBA;
            Message(&sp1C);
        }
        goto block_296;
    case 181:                                       /* switch 1 */
        if ((s32) this->unk16C == 1) {
            this->unk16C = 2;
        }
        goto block_296;
    case 180:                                       /* switch 1 */
        if ((s32) this->unk16C == 2) {
            this->unk16C = 1;
        }
        goto block_296;
    case 139:                                       /* switch 1 */
        temp_r3_3754 = checked_cast<GetNumHitsToDestroyMsg *, MKMessage>(arg0);
        var_r28_3756 = 0x3E8;
        if (((s32) M2C_FIELD(temp_r3_3754, s32 *, 0xC) != 0) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (this->unk180 * 0x17C)), u8 *, 0x178) != 0)) {
            temp_r28_3771 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (temp_r28_3771->unk160 * 0x17C)), u8 *, -4) != 0) {
                var_r28_3783 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160;
            } else {
                var_r28_3783 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1;
            }
            var_r28_3756 = (s32) ((f32) (s32) (((f32) ((var_r28_3783 - 1) - this->unk180) * checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0) + this->unk178) / (f32) M2C_FIELD(temp_r3_3754, s32 *, 0xC));
        }
        M2C_FIELD(temp_r3_3754, s32 *, 8) = var_r28_3756;
        goto block_296;
    case -4:                                        /* switch 1 */
        if ((s32) this->unk16C == 3) {
            ((KDShatter2 *) (((u8 *) this->unk168) + (this->unk180 << 7)))->Finish();
        }
        goto block_296;
    case -3:                                        /* switch 1 */
        if (AbleToRespawn() != 0) {
            Reset();
        }
        goto block_296;
    case 38:                                        /* switch 1 */
        PlatformDetach();
        goto block_296;
    case 142:                                       /* switch 1 */
        temp_r3_3854 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_3856 = this;
        if (this != NULL) {
            var_r0_3856 = (Shatterable *) &this->unkC8;
        }
        M2C_FIELD(temp_r3_3854, Shatterable **, 8) = var_r0_3856;
        return;
    case 356:                                       /* switch 1 */
        Reset();
        return;
    case 92:                                        /* switch 1 */
        temp_r3_3870 = arg0->unk4;
        temp_r4_3872 = (void *) (temp_r3_3870 + 0x128);
        M2C_FIELD(temp_r3_3870, u8 **, 0x12C) = &this->unk150;
        M2C_FIELD(temp_r3_3870, void **, 0x130) = (void *) this->unk158;
        this->unk158 = temp_r4_3872;
        M2C_FIELD(M2C_FIELD(temp_r3_3870, void **, 0x130), void **, 4) = temp_r4_3872;
        goto block_296;
    case 93:                                        /* switch 1 */
        temp_r3_3881 = arg0->unk4;
        temp_r4_3882 = temp_r3_3881 + 0x128;
        M2C_FIELD(M2C_FIELD(temp_r3_3881, void **, 0x130), u8 **, 4) = (u8 *) M2C_FIELD(temp_r3_3881, u8 **, 0x12C);
        M2C_FIELD(M2C_FIELD(temp_r4_3882, void **, 4), void **, 8) = (void *) M2C_FIELD(temp_r4_3882, void **, 8);
        M2C_FIELD(temp_r4_3882, void **, 8) = temp_r4_3882;
        M2C_FIELD(temp_r4_3882, void **, 4) = temp_r4_3882;
        goto block_296;
    }
}
#endif

#if 0 // DRAFT: illegal type
u8 Shatterable::AbleToRespawn() {
    s8 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    f32 sp88;
    s32 sp84;
    s8 sp83;
    s8 sp82;
    s16 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f31_3939;
    f32 temp_f31_3953;
    f32 temp_f3_3948;
    f64 temp_f1_3951;
    f64 temp_f1_3960;
    void *temp_r3_3959;
    void *temp_r5_3947;

    if (((s32) this->unk16C == 0) && ((u8) this->unk19D != 0) && ((u8) this->unk19E == 0)) {
        this->unk188 -= gUpdateTimeDelta;
        if (this->unk188 <= 0.0f) {
            this->unk188 = 0.5f;
            temp_f31_3939 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0x18);
            temp_r5_3947 = this->unk8;
            temp_f3_3948 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0x10) + temp_f31_3939;
            temp_f1_3951 = M2C_FIELD(temp_r5_3947, f64 *, 0x30);
            temp_f31_3953 = temp_f3_3948 * 0.5f;
            sp18 = temp_f1_3951;
            sp20 = M2C_FIELD(temp_r5_3947, f64 *, 0x38);
            temp_r3_3959 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void ***, void *, f64, f32, f32), 0xC)(gb, &gb, temp_r5_3947, temp_f1_3951, 0.5f, temp_f3_3948), void **, 8);
            temp_f1_3960 = M2C_FIELD(temp_r3_3959, f64 *, 0x30);
            sp28 = temp_f1_3960;
            sp30 = M2C_FIELD(temp_r3_3959, f64 *, 0x38);
            sp8 = temp_f1_3960 - sp18;
            sp38 = sp8;
            sp10 = (f32) sp30 - (f32) sp20;
            sp40 = (f64) sp10;
            if ((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4))))) < (temp_f31_3953 * temp_f31_3953)) {
                return 0U;
            }
            sp48 = 0.0f;
            sp4C = 0.0f;
            sp50 = 0.0f;
            sp58 = 0.0f;
            sp5C = 0.0f;
            sp60 = 0.0f;
            sp68 = 0.0f;
            sp6C = 0.0f;
            sp70 = 0.0f;
            sp74 = 1.0f;
            sp78 = 0.0f;
            sp7C = 0.0f;
            sp80 = 0;
            sp82 = 0;
            sp83 = 0;
            sp84 = 0;
            sp88 = 3.4028235e38f;
            sp8C = 0;
            sp90 = 0;
            sp94 = -1;
            sp98 = 0;
            if (MKCollision_SphereCollide(*(this->unk8 + 0x30), temp_f31_3953, (MKCollisionResult *) &sp48, 1, (MKCollisionMode) 2, 0) == 0) {
                return 1U;
            }
            goto block_8;
        }
    }
block_8:
    return 0U;
}
#endif

void *Shatterable::Update() {
    s32 sp8;
    ShatterableDescriptor *temp_r29_4050;
    ShatterableDescriptor *temp_r4_4082;
    s32 var_r28_4051;
    s32 var_r30_4052;

    GameProp::Update();
    temp_r29_4050 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r28_4051 = 0;
    var_r30_4052 = 0;
loop_2:
    if (var_r28_4051 < (s32) temp_r29_4050->unk160) {
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r30_4052))->Update();
        var_r28_4051 += 1;
        var_r30_4052 += 0x80;
        goto loop_2;
    }
    if (AbleToRespawn() != 0) {
        Reset();
    }
    this->unk19E = 0;
    if ((KDSoundPlayer *) this->unk100 != NULL) {
        temp_r4_4082 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) this->unk100)->Update(temp_r4_4082->unkFC, 1U, ((u8) this->unk1A1 >> 6U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) this->unk17C == 1) {
        if (this->unk178 <= 0.0f) {
            SetSmashPropState((SmashPropState) 2);
        } else if (((MKAnimScript *) this->unk80 != NULL) && ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 != NULL) && (this->unk80->unk2C & 1)) {
            PostShatter();
        }
    }
    if ((s32) this->unk17C == 2) {
        PostShatter();
    }
    if (((s32) this->unk17C == 1) && (((MKAnimScript *) this->unk80 == NULL) || ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 == NULL) || ((this->unk80->unk2C & 1) && !(((u8) this->unk1A1 >> 7U) & 1)))) {
        SetSmashPropState((SmashPropState) 0);
    }
    this->unk1A1 &= ~0x80;
}

#if 0 // DRAFT: illegal type
void Shatterable::Draw() {
    ShatterableDescriptor *temp_r29_4189;
    f32 var_f1_4197;
    s32 temp_r0_4205;
    s32 temp_r0_4215;
    s32 var_ctr_4209;
    s32 var_r27_4206;
    s32 var_r28_4230;
    s32 var_r28_4247;
    s32 var_r30_4231;
    s32 var_r30_4248;
    s32 var_r3_4208;
    s32 var_r5_4207;

    if ((u8) this->unk1A0 != 0) {
        this->unk118.BeginGlowingPropDraw((MKProp *) this);
    }
    this->unk19E = 1;
    temp_r29_4189 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_EnableScissoring(this->unk4, ((u32) this->unk10 >> 0xFU) & 1);
    if (((u8) this->unk88 >> 7U) & 1) {
        var_f1_4197 = 1.0f;
    } else {
        var_f1_4197 = this->unk20 * this->unk84;
    }
    MKModel_SetAlpha(this->unk4, var_f1_4197);
    temp_r0_4205 = temp_r29_4189->unk160;
    var_r27_4206 = 0;
    var_r5_4207 = 0;
    var_r3_4208 = 0;
    var_ctr_4209 = temp_r0_4205;
    if (temp_r0_4205 > 0) {
        do {
            temp_r0_4215 = *(this->unk168 + (var_r3_4208 + 0x44));
            if ((temp_r0_4215 == 1) || (temp_r0_4215 == 2) || (var_r5_4207 < (s32) this->unk180)) {
                var_r27_4206 = var_r5_4207 + 1;
            }
            var_r5_4207 += 1;
            var_r3_4208 += 0x80;
            var_ctr_4209 -= 1;
        } while (var_ctr_4209 != 0);
    }
    var_r28_4230 = 0;
    var_r30_4231 = 0;
loop_15:
    if (var_r28_4230 < (s32) temp_r29_4189->unk160) {
        if (var_r28_4230 == var_r27_4206) {
            ((KDShatter2 *) (((u8 *) this->unk168) + var_r30_4231))->Draw(1U);
        }
        var_r28_4230 += 1;
        var_r30_4231 += 0x80;
        goto loop_15;
    }
    var_r28_4247 = 0;
    var_r30_4248 = 0;
loop_18:
    if (var_r28_4247 < (s32) temp_r29_4189->unk160) {
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r30_4248))->Draw(0U);
        var_r28_4247 += 1;
        var_r30_4248 += 0x80;
        goto loop_18;
    }
    if ((u8) this->unk1A0 != 0) {
        this->unk118.EndGlowingPropDraw();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKProp *' to 'MKCollisionInfo *'
f32 Shatterable::Resolve() {
    MKProp *temp_r3_4287;
    MKSceneManager *temp_r3_4283;

    KDPropEx::Resolve();
    temp_r3_4283 = this->unk174;
    if (temp_r3_4283 != NULL) {
        temp_r3_4287 = checked_cast<KDProp *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) temp_r3_4283));
        PlatformAttach(temp_r3_4287, temp_r3_4287 + 0x70);
    }
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::Reset() {
    s32 var_r29_4329;
    s32 var_r30_4328;

    GameProp::Reset();
    this->unk178 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
    this->unk1A1 &= ~0x80;
    this->unk1A1 |= 0x40;
    SetSmashPropState((SmashPropState) 0);
    this->unk16C = 2;
    var_r30_4328 = 0;
    var_r29_4329 = 0;
    this->unk188 = 0.0f;
    this->unk19E = 0;
loop_2:
    if (var_r29_4329 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
        *(this->unk168 + (var_r30_4328 + 0x3C)) = M2C_FIELD(this->unk0, f32 *, 0x20);
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r30_4328))->Reset();
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r30_4328))->ClearVisible();
        var_r29_4329 += 1;
        var_r30_4328 += 0x80;
        goto loop_2;
    }
    ResetPercentageShattered();
    ((KDShatter2 *) (((u8 *) this->unk168) + (this->unk180 << 7)))->SetVisibleUnshattered();
    EnableCollision();
    this->unk70.unk4 = 0;
    if ((u8) this->unk19F == 0) {
        this->unk16C = 1;
    }
    SetStateAnim(0);
    this->unk190 = 0;
    this->unk194 = 0;
    if ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) {
        this->unkC8.RegisterTargetable();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P21ShatterableDescriptor'
s32 Shatterable::LoadDone() {
    f64 sp10;
    f64 sp8;
    ShatterableDescriptor *temp_r31_4474;
    f32 var_f0_4400;
    s32 var_r25_4482;
    s32 var_r26_4485;
    s32 var_r27_4477;
    s32 var_r28_4476;
    s32 var_r30_4475;
    s8 *temp_r4_4575;
    void *temp_r3_4550;
    void *temp_r4_4484;
    void *temp_r4_4503;
    void *temp_r4_4549;
    void *temp_r5_4428;

    GameProp::LoadDone();
    var_f0_4400 = this->unk198;
    if (var_f0_4400 < 1.0f) {

    } else {
        var_f0_4400 = 1.0f;
    }
    if (var_f0_4400 > 0.0f) {

    } else {
        var_f0_4400 = 0.0f;
    }
    this->unk198 = var_f0_4400;
    ResetPercentageShattered();
    this->unkD0.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unkD0.Show(1U);
    temp_r5_4428 = this->unk8;
    sp8 = M2C_FIELD(temp_r5_4428, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_4428, f64 *, 0x38);
    this->unkD0.unk28 = (*(f32 *) ((u8 *) &sp8 + 0x4));
    SetSmashPropState((SmashPropState) 0);
    if ((MKAnimScript *) this->unk80 != NULL) {
        this->unk80->SetAnim(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkE4, 1.0f, 0.0f, 0, -1);
    }
    if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkFC != 0) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk100 = M2C_ERROR(/* Read from unset register $r3 */);
        ((KDSoundFader *) this->unk100)->Init(0.25f, 0.25f);
    }
    temp_r31_4474 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r30_4475 = 0;
    var_r28_4476 = 0;
    var_r27_4477 = 0;
loop_19:
    if (var_r30_4475 < (s32) temp_r31_4474->unk160) {
        var_r25_4482 = 0;
        temp_r4_4484 = ((u8 *) this->unk168) + (var_r27_4477 + 0x68);
        var_r26_4485 = 0;
        M2C_FIELD(temp_r4_4484, s32 *, 0) = 0;
        M2C_FIELD(temp_r4_4484, s8 *, 4) = 1;
        M2C_FIELD(temp_r4_4484, Shatterable **, 8) = this;
        M2C_FIELD(temp_r4_4484, s32 *, 0xC) = 0;
loop_15:
        temp_r4_4503 = var_r28_4476 + temp_r31_4474->unk11C;
        if (var_r26_4485 < (s32) M2C_FIELD(temp_r4_4503, u16 *, 0x110)) {
            AddCollisionSubObject((s32) *(temp_r4_4503 + (var_r25_4482 + 0x112)), ((u8 *) this->unk168) + (var_r27_4477 + 0x68));
            var_r26_4485 += 1;
            var_r25_4482 += 2;
            goto loop_15;
        }
        *(this->unk168 + (var_r27_4477 + 0x6C)) = 0;
        *(this->unk168 + var_r27_4477) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x168));
        *(this->unk168 + (var_r27_4477 + 4)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x164));
        *(this->unk168 + (var_r27_4477 + 0x10)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x16C));
        *(this->unk168 + (var_r27_4477 + 8)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x170));
        *(this->unk168 + (var_r27_4477 + 0x14)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x174));
        *(this->unk168 + (var_r27_4477 + 0x18)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x160));
        temp_r4_4549 = temp_r31_4474->unk11C + var_r28_4476;
        temp_r3_4550 = ((u8 *) this->unk168) + var_r27_4477;
        M2C_FIELD(temp_r3_4550, void **, 0x54) = temp_r4_4549;
        M2C_FIELD(temp_r3_4550, void **, 0x58) = (void *) (((u8 *) temp_r4_4549) + 0x44);
        M2C_FIELD(temp_r3_4550, void **, 0x5C) = (void *) (((u8 *) temp_r4_4549) + 0x88);
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r27_4477))->LoadDone(this->unk4, temp_r31_4474->unk11C + (var_r28_4476 + 0xCC));
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r27_4477))->ClearVisible();
        *(this->unk168 + (var_r27_4477 + 0x30)) = temp_r31_4474->unk158;
        *(this->unk168 + (var_r27_4477 + 0x60)) = temp_r31_4474->unk165;
        temp_r4_4575 = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x158));
        if (temp_r4_4575 != NULL) {
            *(this->unk168 + (var_r27_4477 + 0x78)) = property_cast<KDScriptProperty *, KDProperty *>(temp_r31_4474->unk74.Find(temp_r4_4575));
        }
        var_r30_4475 += 1;
        var_r28_4476 += 0x17C;
        var_r27_4477 += 0x80;
        goto loop_19;
    }
    ((KDShatter2 *) (((u8 *) this->unk168) + (this->unk180 << 7)))->SetVisibleUnshattered();
    *(this->unk168 + ((this->unk180 << 7) + 0x6C)) = 1;
    this->unk130 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk138 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if ((u8) this->unk19F == 0) {
        this->unk16C = 1;
    }
    if ((u8) this->unk1A0 != 0) {
        this->unk118.Init();
    }
    if ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) {
        this->unkC8.RegisterTargetable();
    }
    this->unk178 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
s32 Shatterable::LoadLine(MKIniLine *arg0) {
    s32 var_r31_4647;

    var_r31_4647 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (this->unk15C.LoadLine(arg0, "onDestruction") != 0) || (arg0->LoadInt("shattererID", (int *) &this->unk184, 0) != 0) || (arg0->LoadBool("bRespawnWhenNotInView", &this->unk19D, 0) != 0) || (arg0->LoadBool("bStartActive", &this->unk19F, 0) != 0) || (this->unk160.LoadLine(arg0, "onShatter") != 0) || (this->unk164.LoadLine(arg0, "onHit") != 0) || (arg0->LoadBool("bGlowHint", &this->unk1A0, 0) != 0) || (arg0->LoadBool("bPlayShatterNote", &this->unk1A2, 0) != 0) || (arg0->LoadInt("platformAttachID", (int *) &this->unk174, 0) != 0) || (arg0->LoadFloat("shakeCameraStrength", &this->unk18C, 0) != 0) || (arg0->LoadFloat("ShatteredPercentage", &this->unk198, 0) != 0) || (arg0->LoadBool("Hitable", &this->unk19C, 0) != 0)) {
        var_r31_4647 = 1;
    }
    return var_r31_4647;
}
#endif

#if 0 // DRAFT: type mismatch 'Attachment *' and 'unsigned char *'
void Shatterable::Deinit() {
    Attachment *temp_r30_4779;
    Attachment *var_r3_4776;
    KDSoundPlayer *temp_r30_4795;
    KDSoundPlayer *temp_r3_4791;
    s32 temp_cr0_eq_4796;
    s32 var_r30_4805;
    s32 var_r31_4806;
    void *temp_r30_4820;

    var_r3_4776 = this->unk154;
loop_3:
    if (var_r3_4776 != &this->unk150) {
        temp_r30_4779 = var_r3_4776->unk4;
        if (Shatterable_ParentDestroyed(var_r3_4776, this) != 0) {
            var_r3_4776 = temp_r30_4779;
            goto loop_3;
        }
    }
    this->unkD0.Deinit();
    temp_r3_4791 = this->unk100;
    if (temp_r3_4791 != NULL) {
        KDSound_Stop((int *) &temp_r3_4791->unk0);
        temp_r30_4795 = this->unk100;
        temp_cr0_eq_4796 = temp_r30_4795 == NULL;
        if (temp_cr0_eq_4796 == 0) {
            if (temp_cr0_eq_4796 == 0) {
                KDSound_Stop((int *) &temp_r30_4795->unk0);
            }
            operator delete(temp_r30_4795);
        }
    }
    var_r30_4805 = 0;
    var_r31_4806 = 0;
loop_11:
    if (var_r30_4805 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r31_4806))->Deinit();
        var_r30_4805 += 1;
        var_r31_4806 += 0x80;
        goto loop_11;
    }
    temp_r30_4820 = this->unk168;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r30_4820, NULL, 0);
    } else {
        free(temp_r30_4820);
    }
    if ((u8) this->unk1A0 != 0) {
        this->unk118.Deinit();
    }
    PlatformDetach();
    if ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) {
        this->unkC8.UnregisterTargetable();
    }
    GameProp::Deinit();
}
#endif

u8 Shatterable_ParentDestroyed(Attachment *arg0, void *arg1) {
    void *spC;
    s32 sp8;
    void *temp_r3_4871;

    spC = NULL;
    spC = arg1;
    sp8 = 0x5E;
    temp_r3_4871 = arg0->unk0;
    M2C_FIELD(M2C_FIELD(temp_r3_4871, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_4871, &sp8, 0);
    return 1U;
}

#if 0 // DRAFT: illegal type
void Shatterable::Init() {
    s32 temp_r0_4935;
    s32 temp_r29_4911;
    s32 var_r28_4928;
    s32 var_r30_4925;
    void *var_r3_4919;

    GameProp::Init();
    this->unk1A1 &= ~0x80;
    this->unk100 = NULL;
    this->unk1A1 |= 0x40;
    this->unk10 |= 0x10;
    this->unk188 = 0.0f;
    this->unk184 = NULL;
    this->unk19D = 0;
    temp_r29_4911 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 << 7;
    if (MKHeap::Current() != NULL) {
        var_r3_4919 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_4911, NULL, 0);
    } else {
        var_r3_4919 = malloc(temp_r29_4911);
    }
    var_r30_4925 = 0;
    this->unk168 = var_r3_4919;
    var_r28_4928 = 0;
    do {
        ((KDShatter2 *) (((u8 *) this->unk168) + var_r30_4925))->Init();
        var_r28_4928 += 1;
        temp_r0_4935 = var_r30_4925 + 0x78;
        var_r30_4925 += 0x80;
        *(this->unk168 + temp_r0_4935) = 0;
    } while (var_r28_4928 < 0xA);
    this->unk19F = 1;
    this->unk1A0 = 0;
    this->unk1A2 = 0;
    this->unk170 = NULL;
    this->unk18C = 0.0f;
    this->unk174 = NULL;
    M2C_FIELD(this, Shatterable **, 0x140) = this;
    this->unk190 = 0;
    this->unk194 = 0;
    this->unk198 = 0.0f;
    this->unk19C = 1;
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableDescriptor::LoadDone() {
    s8 sp3C;
    s8 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f32 temp_f2_5334;
    s16 temp_r30_5171;
    s32 temp_cr0_eq_5324;
    s32 temp_r0_5324;
    s32 temp_r24_5302;
    s32 var_r23_5030;
    s32 var_r23_5069;
    s32 var_r23_5109;
    s32 var_r23_5215;
    s32 var_r23_5255;
    s32 var_r23_5299;
    s32 var_r24_5022;
    s32 var_r25_5021;
    s32 var_r26_5032;
    s32 var_r26_5071;
    s32 var_r26_5111;
    s32 var_r26_5173;
    s32 var_r26_5217;
    s32 var_r26_5257;
    s32 var_r26_5300;
    s32 var_r27_5020;
    s32 var_r28_5033;
    s32 var_r28_5072;
    s32 var_r28_5112;
    s32 var_r28_5218;
    s32 var_r28_5258;
    s32 var_r4_5315;
    s8 *temp_r24_4996;
    s8 *temp_r25_4993;
    s8 *temp_r3_5152;
    s8 *temp_r3_5179;
    s8 *temp_r4_5010;
    s8 *temp_r4_5303;
    s8 *var_r3_4984;
    s8 *var_r3_5004;
    u16 *temp_r5_5055;
    u32 temp_r26_5158;
    u8 temp_r0_5191;
    void *temp_r3_5046;
    void *temp_r3_5051;
    void *temp_r3_5085;
    void *temp_r3_5090;
    void *temp_r3_5125;
    void *temp_r3_5130;
    void *temp_r3_5144;
    void *temp_r3_5231;
    void *temp_r3_5236;
    void *temp_r3_5271;
    void *temp_r3_5276;
    void *temp_r4_5204;
    void *temp_r5_5095;
    void *temp_r5_5135;
    void *temp_r5_5241;
    void *temp_r5_5281;

    GamePropDescriptor::LoadDone();
    if ((s8 *) this->unk110 != NULL) {
        if (stricmp"none" != 0) {
            var_r3_4984 = checked_cast<FXBase *, MKProp>(gMK->CreateProp(this->unk110));
        } else {
            var_r3_4984 = NULL;
        }
    } else {
        var_r3_4984 = NULL;
    }
    this->unk110 = var_r3_4984;
    temp_r25_4993 = this->unk34;
    if (temp_r25_4993 != NULL) {
        temp_r24_4996 = this->unkE4;
        if (((MKAnimScript *) temp_r25_4993)->Exists(temp_r24_4996) != 0) {
            var_r3_5004 = ((MKAnimScript *) temp_r25_4993)->GetAnim(temp_r24_4996);
        } else {
            var_r3_5004 = NULL;
        }
        this->unkE4 = var_r3_5004;
        temp_r4_5010 = this->unkE8;
        if (temp_r4_5010 != NULL) {
            this->unkE8 = ((MKAnimScript *) this->unk34)->GetAnim(temp_r4_5010);
        }
        this->unkEC = this->unkE4;
    }
    var_r27_5020 = 0;
    var_r25_5021 = 0;
    var_r24_5022 = 0;
loop_48:
    if (var_r27_5020 < (s32) this->unk160) {
        if ((u16) *(this->unk11C + var_r24_5022) != 0) {
            var_r23_5030 = 0;
            var_r26_5032 = 0;
            var_r28_5033 = 0;
loop_16:
            temp_r3_5051 = this->unk11C;
            if (var_r23_5030 < (s32) *(var_r24_5022 + temp_r3_5051)) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + var_r25_5021 + var_r28_5033), (int *) &sp18);
                var_r23_5030 += 1;
                var_r28_5033 += 4;
                temp_r3_5046 = ((u8 *) this->unk11C) + var_r26_5032;
                var_r26_5032 += 2;
                *(var_r24_5022 + (((u8 *) temp_r3_5046) + 2)) = (s16) sp18;
                goto loop_16;
            }
            temp_r5_5055 = ((u8 *) temp_r3_5051) + var_r24_5022;
            *(temp_r5_5055 + ((*temp_r5_5055 * 2) + 2)) = 0xFFFF;
        }
        if ((u16) *(this->unk11C + (var_r24_5022 + 0x44)) != 0) {
            var_r23_5069 = 0;
            var_r26_5071 = 0;
            var_r28_5072 = 0;
loop_21:
            temp_r3_5090 = this->unk11C;
            if (var_r23_5069 < (s32) *(var_r24_5022 + (((u8 *) temp_r3_5090) + 0x44))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0x500 + var_r25_5021 + var_r28_5072), (int *) &sp14);
                var_r23_5069 += 1;
                var_r28_5072 += 4;
                temp_r3_5085 = ((u8 *) this->unk11C) + var_r26_5071;
                var_r26_5071 += 2;
                *(var_r24_5022 + (((u8 *) temp_r3_5085) + 0x46)) = (s16) sp14;
                goto loop_21;
            }
            temp_r5_5095 = ((u8 *) temp_r3_5090) + var_r24_5022;
            *(temp_r5_5095 + ((M2C_FIELD(temp_r5_5095, u16 *, 0x44) * 2) + 0x46)) = 0xFFFF;
        }
        if ((u16) *(this->unk11C + (var_r24_5022 + 0x88)) != 0) {
            var_r23_5109 = 0;
            var_r26_5111 = 0;
            var_r28_5112 = 0;
loop_26:
            temp_r3_5130 = this->unk11C;
            if (var_r23_5109 < (s32) *(var_r24_5022 + (((u8 *) temp_r3_5130) + 0x88))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0xA00 + var_r25_5021 + var_r28_5112), (int *) &sp10);
                var_r23_5109 += 1;
                var_r28_5112 += 4;
                temp_r3_5125 = ((u8 *) this->unk11C) + var_r26_5111;
                var_r26_5111 += 2;
                *(var_r24_5022 + (((u8 *) temp_r3_5125) + 0x8A)) = (s16) sp10;
                goto loop_26;
            }
            temp_r5_5135 = ((u8 *) temp_r3_5130) + var_r24_5022;
            *(temp_r5_5135 + ((M2C_FIELD(temp_r5_5135, u16 *, 0x88) * 2) + 0x8A)) = 0xFFFF;
        }
        temp_r3_5144 = ((u8 *) this->unk11C) + var_r24_5022;
        if (((u16) M2C_FIELD(temp_r3_5144, u16 *, 0xCC) != 0) || ((s8 *) M2C_FIELD(temp_r3_5144, s8 **, 0x154) != NULL)) {
            temp_r3_5152 = M2C_FIELD(temp_r3_5144, s8 **, 0x154);
            if (temp_r3_5152 != NULL) {
                temp_r26_5158 = strlen(temp_r3_5152);
                strcpy(&sp1C, *(this->unk11C + (var_r24_5022 + 0x154)));
                M2C_FIELD(&(&sp1C)[temp_r26_5158], s8 *, -1) = 0;
                strlwr(&sp1C, 0);
                temp_r30_5171 = MKModel_GetNmbrOfSubObjects(this->unk2C, (SubObjectType) 0);
                var_r26_5173 = 0;
loop_37:
                if (var_r26_5173 < temp_r30_5171) {
                    temp_r3_5179 = MKModel_GetSubObjectName(this->unk2C, (SubObjectType) 0, var_r26_5173);
                    strcpy(&sp3C, temp_r3_5179);
                    strlwr(&sp3C);
                    if ((strstr(&sp1C) != 0U) && ((temp_r0_5191 = (u8) *temp_r3_5179, (((s8) temp_r0_5191 == 0x66) != 0)) || ((s8) temp_r0_5191 == 0x46))) {
                        *(&unshatteredNames + 0xF00 + var_r25_5021 + (*(var_r24_5022 + (((u8 *) this->unk11C) + 0xCC)) * 4)) = temp_r3_5179;
                        temp_r4_5204 = ((u8 *) this->unk11C) + 0xCC;
                        *(var_r24_5022 + temp_r4_5204) = *(var_r24_5022 + temp_r4_5204) + 1;
                    }
                    var_r26_5173 += 1;
                    goto loop_37;
                }
            }
            var_r23_5215 = 0;
            var_r26_5217 = 0;
            var_r28_5218 = 0;
loop_40:
            temp_r3_5236 = this->unk11C;
            if (var_r23_5215 < (s32) *(var_r24_5022 + (((u8 *) temp_r3_5236) + 0xCC))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0xF00 + var_r25_5021 + var_r28_5218), (int *) &spC);
                var_r23_5215 += 1;
                var_r28_5218 += 4;
                temp_r3_5231 = ((u8 *) this->unk11C) + var_r26_5217;
                var_r26_5217 += 2;
                *(var_r24_5022 + (((u8 *) temp_r3_5231) + 0xCE)) = (s16) spC;
                goto loop_40;
            }
            temp_r5_5241 = ((u8 *) temp_r3_5236) + var_r24_5022;
            *(temp_r5_5241 + ((M2C_FIELD(temp_r5_5241, u16 *, 0xCC) * 2) + 0xCE)) = 0xFFFF;
        }
        if ((u16) *(this->unk11C + (var_r24_5022 + 0x110)) != 0) {
            var_r23_5255 = 0;
            var_r26_5257 = 0;
            var_r28_5258 = 0;
loop_45:
            temp_r3_5276 = this->unk11C;
            if (var_r23_5255 < (s32) *(var_r24_5022 + (((u8 *) temp_r3_5276) + 0x110))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0x1400 + var_r25_5021 + var_r28_5258), (int *) &sp8);
                var_r23_5255 += 1;
                var_r28_5258 += 4;
                temp_r3_5271 = ((u8 *) this->unk11C) + var_r26_5257;
                var_r26_5257 += 2;
                *(var_r24_5022 + (((u8 *) temp_r3_5271) + 0x112)) = (s16) sp8;
                goto loop_45;
            }
            temp_r5_5281 = ((u8 *) temp_r3_5276) + var_r24_5022;
            *(temp_r5_5281 + ((M2C_FIELD(temp_r5_5281, u16 *, 0x110) * 2) + 0x112)) = 0xFFFF;
        }
        var_r27_5020 += 1;
        var_r25_5021 += 0x80;
        var_r24_5022 += 0x17C;
        goto loop_48;
    }
    if ((s8 *) this->unk34 != NULL) {
        var_r23_5299 = 0;
        var_r26_5300 = 0;
        do {
            temp_r24_5302 = var_r26_5300 + 0x120;
            temp_r4_5303 = *(this + temp_r24_5302);
            if (temp_r4_5303 != NULL) {
                *(this + temp_r24_5302) = ((MKAnimScript *) this->unk34)->GetAnim(temp_r4_5303);
            }
            var_r23_5299 += 1;
            var_r26_5300 += 4;
        } while (var_r23_5299 < 3);
    }
    var_r4_5315 = this->unk160;
    if ((u8) M2C_FIELD((((u8 *) this->unk11C) + (var_r4_5315 * 0x17C)), u8 *, -4) != 0) {

    } else {
        temp_r0_5324 = var_r4_5315 - 1;
        temp_cr0_eq_5324 = temp_r0_5324 == 0;
        var_r4_5315 = 1;
        if (temp_cr0_eq_5324 == 0) {
            var_r4_5315 = temp_r0_5324;
        }
    }
    temp_f2_5334 = this->unkF0;
    this->unkF0 = (f32) ceil(M2C_BITWISE(s32, (temp_f2_5334 / (f32) var_r4_5315)), temp_f2_5334);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
s32 ShatterableDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *spC;
    u8 sp8;
    MKIniLine *temp_r3_5938;
    MKIniLine *var_r25_5901;
    MKIniLine *var_r25_5940;
    MKIniLine *var_r25_6004;
    MKIniLine *var_r25_6070;
    MKIniLine *var_r29_5889;
    MKIniLine *var_r30_5882;
    s32 temp_r0_5968;
    s32 temp_r0_6009;
    s32 temp_r0_6047;
    s32 temp_r0_6075;
    s32 temp_r23_5792;
    s32 temp_r4_6060;
    s32 temp_r5_5917;
    s32 temp_r5_5981;
    s32 temp_r5_6022;
    s32 temp_r5_6088;
    s32 temp_r6_5906;
    s32 var_ctr_5810;
    s32 var_r24_5604;
    s32 var_r26_5606;
    s32 var_r4_5809;
    u8 var_r26_6158;
    void *temp_r25_6159;
    void *temp_r3_5859;
    void *temp_r5_6058;
    void *temp_r6_5916;
    void *temp_r6_5979;
    void *temp_r6_6020;
    void *temp_r6_6086;
    void *var_r3_5800;

    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("gemCount", (int *) &this->unkF4, 0) != 0) || (arg0->LoadBool("SpawnFuryGems", &this->unkF8, 0) != 0) || (KDSound_LoadLine(arg0, "sndAmbient", (int *) &this->unkFC) != 0) || (KDSound_LoadLine(arg0, "sndHit", (int *) &this->unk100) != 0) || (KDSound_LoadLine(arg0, "sndSpawnGems", (int *) &this->unk10C) != 0) || (arg0->LoadBool("bPlayShatterOnLastStage", &this->unk108, 0) != 0) || (arg0->LoadFloat("hitPoints", &this->unkF0, 0) != 0) || (arg0->LoadString("hitAnimation", &this->unkE8, 0) != 0) || (arg0->LoadString("idleAnimation", &this->unkE4, 0) != 0) || (arg0->LoadString("shatterFX", &this->unk110, 0) != 0) || (arg0->LoadFloat("upVel", &this->unk130, 0) != 0) || (arg0->LoadFloat("power", &this->unk134, 0) != 0) || (arg0->LoadFloat("bounce", &this->unk13C, 0) != 0) || (arg0->LoadFloat("gravity", &this->unk140, 0) != 0) || (arg0->LoadFloat("life", &this->unk144, 0) != 0) || (arg0->LoadFloat("airResistance", &this->unk148, 0) != 0) || (arg0->LoadFloat("spinRate", &this->unk138, 0) != 0) || (arg0->LoadFloat("controlerLrg", &this->unk14C, 0) != 0) || (arg0->LoadFloat("controlerSml", &this->unk150, 0) != 0) || (arg0->LoadFloat("controlerRmbl", &this->unk154, 0) != 0) || (KDSound_LoadLine(arg0, "sndShatter", (int *) &this->unk15C) != 0) || (KDSound_LoadLine(arg0, "sndShatterNote", (int *) &this->unk104) != 0) || (KDProp_LoadMaterialID(arg0, "ignoreMaterialID", (int *) &this->unk158) != 0) || (arg0->LoadBool("ShrinkFade", &this->unk165, 0) != 0) || (arg0->LoadBool("shakeCameraOnDamage", &this->unk166, 0) != 0) || (arg0->LoadBool("Targetable", &this->unk114, 0) != 0) || (arg0->LoadBool("hitable", &this->unk115, 0) != 0)) {
        return 1;
    }
    var_r24_5604 = 0;
    var_r26_5606 = 0;
loop_30:
    if (arg0->LoadString(*(&pShatterAnimNames + var_r26_5606), this + (var_r26_5606 + 0x120), 0) != 0) {
        return 1;
    }
    var_r24_5604 += 1;
    var_r26_5606 += 4;
    if (var_r24_5604 >= 3) {
        if (arg0->LoadBool("bIgnoreExplosion", &sp8, 0) != 0) {
            this->unk164 = (this->unk164 & ~0x40) | ((sp8 << 6) & 0x40);
            return 1;
        }
        if (arg0->IsField("cartIgnore") != 0) {
            if (arg0->GetBool(0) != 0) {
                this->unkC |= 0x80;
            } else {
                this->unkC &= 0xFFFFFF7F;
            }
            return 1;
        }
        if (arg0->LoadBool("TakeMeleeDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x80) | ((sp8 << 7) & 0x80);
            goto block_109;
        }
        if (arg0->LoadBool("TakeTailSweepDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x40) | ((sp8 << 6) & 0x40);
            goto block_109;
        }
        if (arg0->LoadBool("TakeTailStrikeDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x20) | ((sp8 << 5) & 0x20);
            goto block_109;
        }
        if (arg0->LoadBool("TakeExplosiveDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x10) | ((sp8 << 4) & 0x10);
            goto block_109;
        }
        if (arg0->LoadBool("TakeProjectileDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~2) | ((sp8 << 1) & 2);
            goto block_109;
        }
        if (arg0->LoadBool("TakeCollisionDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~1) | (sp8 & 1);
            goto block_109;
        }
        if (arg0->LoadBool("TakeFuryDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~4) | ((sp8 << 2) & 4);
            goto block_109;
        }
        if (arg0->LoadBool("disableShadowOnShatter", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~8) | ((sp8 << 3) & 8);
            goto block_109;
        }
        if (arg0->IsField("multiStageShatter") != 0) {
            temp_r23_5792 = arg0->GetNmbrOfSubLines();
            if (MKHeap::Current() != NULL) {
                var_r3_5800 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r23_5792 * 0x17C, NULL, 0);
            } else {
                var_r3_5800 = malloc(temp_r23_5792 * 0x17C);
            }
            this->unk11C = var_r3_5800;
            var_r4_5809 = 0;
            var_ctr_5810 = temp_r23_5792;
            if (temp_r23_5792 > 0) {
                do {
                    *(this->unk11C + var_r4_5809) = 0;
                    *(this->unk11C + (var_r4_5809 + 2)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x44)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x46)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x88)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x8A)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0xCC)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0xCE)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x110)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x112)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x178)) = 1;
                    *(this->unk11C + (var_r4_5809 + 0x154)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x158)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x179)) = 1;
                    temp_r3_5859 = ((u8 *) this->unk11C) + var_r4_5809;
                    var_r4_5809 += 0x17C;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x15C) = (f32) this->unk130;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x160) = (f32) this->unk134;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x164) = (f32) this->unk13C;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x168) = (f32) this->unk140;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x16C) = (f32) this->unk144;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x170) = (f32) this->unk148;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x174) = (f32) this->unk138;
                    var_ctr_5810 -= 1;
                } while (var_ctr_5810 != 0);
            }
            this->unk160 = 0;
            var_r30_5882 = arg0->unkC->GetSubLine(arg0);
loop_107:
            if (var_r30_5882 != NULL) {
                var_r29_5889 = var_r30_5882->unkC->GetSubLine(var_r30_5882);
loop_105:
                if (var_r29_5889 != NULL) {
                    if (var_r29_5889->IsField("meshes") != 0) {
                        var_r25_5901 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
loop_67:
                        if (var_r25_5901 != NULL) {
                            temp_r6_5906 = this->unk160;
                            *(&unshatteredNames + ((temp_r6_5906 << 7) + (*(this->unk11C + (temp_r6_5906 * 0x17C)) * 4))) = var_r25_5901->GetFieldName();
                            temp_r6_5916 = this->unk11C;
                            temp_r5_5917 = this->unk160 * 0x17C;
                            *(temp_r6_5916 + temp_r5_5917) = *(temp_r6_5916 + temp_r5_5917) + 1;
                            var_r25_5901 = var_r25_5901->unkC->GetNextLine(var_r25_5901);
                            goto loop_67;
                        }
                    } else if (var_r29_5889->IsField("frags") != 0) {
                        temp_r3_5938 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
                        var_r25_5940 = temp_r3_5938;
                        temp_r3_5938->GetFieldName();
                        if (strstr"*" != 0U) {
                            *(this->unk11C + ((this->unk160 * 0x17C) + 0x154)) = temp_r3_5938->GetFieldName();
                        }
                        if ((u32) *(this->unk11C + ((this->unk160 * 0x17C) + 0x154)) == 0U) {
loop_75:
                            if (var_r25_5940 != NULL) {
                                temp_r0_5968 = this->unk160;
                                *(&unshatteredNames + 0xF00 + ((temp_r0_5968 << 7) + (*(this->unk11C + ((temp_r0_5968 * 0x17C) + 0xCC)) * 4))) = var_r25_5940->GetFieldName();
                                temp_r6_5979 = this->unk11C;
                                temp_r5_5981 = (this->unk160 * 0x17C) + 0xCC;
                                *(temp_r6_5979 + temp_r5_5981) = *(temp_r6_5979 + temp_r5_5981) + 1;
                                var_r25_5940 = var_r25_5940->unkC->GetNextLine(var_r25_5940);
                                goto loop_75;
                            }
                        }
                    } else if (var_r29_5889->IsField("remnants") != 0) {
                        var_r25_6004 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
loop_80:
                        if (var_r25_6004 != NULL) {
                            temp_r0_6009 = this->unk160;
                            *(&unshatteredNames + 0xA00 + ((temp_r0_6009 << 7) + (*(this->unk11C + ((temp_r0_6009 * 0x17C) + 0x88)) * 4))) = var_r25_6004->GetFieldName();
                            temp_r6_6020 = this->unk11C;
                            temp_r5_6022 = (this->unk160 * 0x17C) + 0x88;
                            *(temp_r6_6020 + temp_r5_6022) = *(temp_r6_6020 + temp_r5_6022) + 1;
                            var_r25_6004 = var_r25_6004->unkC->GetNextLine(var_r25_6004);
                            goto loop_80;
                        }
                    } else if (var_r29_5889->IsField("collision") != 0) {
                        if ((s16) var_r29_5889->unk0 > 0) {
                            temp_r0_6047 = this->unk160;
                            *(&unshatteredNames + 0x1400 + ((temp_r0_6047 << 7) + (*(this->unk11C + ((temp_r0_6047 * 0x17C) + 0x110)) * 4))) = var_r29_5889->GetString(0);
                            temp_r5_6058 = this->unk11C;
                            temp_r4_6060 = (this->unk160 * 0x17C) + 0x110;
                            *(temp_r5_6058 + temp_r4_6060) = *(temp_r5_6058 + temp_r4_6060) + 1;
                        } else {
                            var_r25_6070 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
loop_87:
                            if (var_r25_6070 != NULL) {
                                temp_r0_6075 = this->unk160;
                                *(&unshatteredNames + 0x1400 + ((temp_r0_6075 << 7) + (*(this->unk11C + ((temp_r0_6075 * 0x17C) + 0x110)) * 4))) = var_r25_6070->GetFieldName();
                                temp_r6_6086 = this->unk11C;
                                temp_r5_6088 = (this->unk160 * 0x17C) + 0x110;
                                *(temp_r6_6086 + temp_r5_6088) = *(temp_r6_6086 + temp_r5_6088) + 1;
                                var_r25_6070 = var_r25_6070->unkC->GetNextLine(var_r25_6070);
                                goto loop_87;
                            }
                        }
                    } else if (var_r29_5889->IsField("destructible") != 0) {
                        *(this->unk11C + ((this->unk160 * 0x17C) + 0x178)) = var_r29_5889->GetBool(0);
                    } else if (var_r29_5889->IsField("shatterScript") != 0) {
                        *(this->unk11C + ((this->unk160 * 0x17C) + 0x158)) = var_r29_5889->GetString(0);
                    } else if (var_r29_5889->IsField("hitable") != 0) {
                        *(this->unk11C + ((this->unk160 * 0x17C) + 0x179)) = var_r29_5889->GetBool(0);
                    } else {
                        var_r26_6158 = 0;
                        temp_r25_6159 = ((u8 *) this->unk11C) + (this->unk160 * 0x17C);
                        if ((var_r29_5889->LoadFloat("upVel", ((u8 *) temp_r25_6159) + 0x15C, 0) != 0) || (var_r29_5889->LoadFloat("power", ((u8 *) temp_r25_6159) + 0x160, 0) != 0) || (var_r29_5889->LoadFloat("bounce", ((u8 *) temp_r25_6159) + 0x164, 0) != 0) || (var_r29_5889->LoadFloat("gravity", ((u8 *) temp_r25_6159) + 0x168, 0) != 0) || (var_r29_5889->LoadFloat("life", ((u8 *) temp_r25_6159) + 0x16C, 0) != 0) || (var_r29_5889->LoadFloat("airResistance", ((u8 *) temp_r25_6159) + 0x170, 0) != 0)) {
                            var_r26_6158 = 1;
                        }
                        if (var_r26_6158 == 0) {
                            var_r29_5889->LoadFloat("spinRate", ((u8 *) temp_r25_6159) + 0x174, 0);
                        }
                    }
                    var_r29_5889 = var_r29_5889->unkC->GetNextLine(var_r29_5889);
                    goto loop_105;
                }
                this->unk160 += 1;
                var_r30_5882 = var_r30_5882->unkC->GetNextLine(var_r30_5882);
                goto loop_107;
            }
            return 1;
        }
block_109:
        if (arg0->IsField("HitFX") != 0) {
            arg0->AsString(0, &spC);
            this->unk168 = DataMap_GetValue(ShatterableHitFXDataMap, spC);
        }
        return 0;
    }
    goto loop_30;
}
#endif

void ShatterableDescriptor::Deinit() {
    void *temp_r31_6277;

    temp_r31_6277 = this->unk11C;
    if (temp_r31_6277 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_6277, NULL, 0);
        } else {
            free(temp_r31_6277);
        }
        this->unk11C = NULL;
    }
    KDPropExDescriptor::Deinit();
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void ShatterableDescriptor::Init() {
    s32 temp_r0_6383;
    s32 var_ctr_6381;
    s32 var_r3_6331;

    GamePropDescriptor::Init();
    memset(&this->unk118, 0, 4U);
    this->unkF4 = 0;
    this->unkF8 = 0;
    this->unkF0 = 1.0f;
    var_r3_6331 = 0;
    this->unkE4 = "idle";
    this->unkE8 = NULL;
    this->unk118 &= ~0x80;
    this->unk118 &= ~0x20;
    this->unk118 &= ~0x10;
    this->unk118 |= 4;
    this->unk118 |= 8;
    this->unk118 |= 2;
    this->unk118 |= 1;
    this->unkFC = 0;
    this->unk100 = 0;
    this->unk10C = GS_GemSpawn2;
    this->unk108 = 0;
    this->unk104 = GS_PLACEHOLDER;
    this->unk110 = NULL;
    this->unk12C = 0;
    this->unkC = 0x202;
    this->unk11C = NULL;
    this->unk160 = 1;
    this->unk15C = GS_PLACEHOLDER;
    this->unkC |= 0x80;
    this->unk164 &= ~0x40;
    this->unk14C = 0.65f;
    this->unk150 = 0.8f;
    this->unk154 = 0.15f;
    this->unk166 = 0;
    this->unk158 = 0;
    var_ctr_6381 = 3;
    do {
        temp_r0_6383 = var_r3_6331 + 0x120;
        var_r3_6331 += 4;
        *(this + temp_r0_6383) = 0;
        var_ctr_6381 -= 1;
    } while (var_ctr_6381 != 0);
    this->unk165 = 0;
    this->unk168 = 0;
    this->unk114 = 0;
    this->unk115 = 1;
}
#endif
