#include "spyro/source/FuryFXFire2.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
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
#include "spyro/source/CameraData.h"
#include "spyro/source/ClusterBomb.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FlyingBurningBits.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GroundFire.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessageStorage.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCameraState.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK free(Explosion4 *);                         /* extern */
Explosion4 *malloc(M2C_UNK);                        /* extern */
extern s32 GS_SpyroFuryMissile1;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

void FuryFXFire2::ResetFury() {
    f64 sp18;
    f64 sp10;
    FuryFXFire2::Meteor **var_r29_55;
    FuryFXFire2::Meteor *temp_r30_100;
    FuryFXFire2::Meteor **temp_r3_88;
    FuryFXFire2::Meteor *temp_r4_91;
    MKProp *temp_r6_75;

    SetDefaults();
    var_r29_55 = this->unk150;
loop_4:
    if (var_r29_55 != NULL) {
        temp_r30_100 = *var_r29_55;
        if (temp_r30_100 == NULL) {
        } else {
            if ((s32) M2C_FIELD(temp_r30_100, s32 *, 0x44) != 2) {
                sp10 = M2C_FIELD(temp_r30_100, f64 *, 0x30);
                sp18 = M2C_FIELD(temp_r30_100, f64 *, 0x38);
                KDSound_Stop((int *) (((u8 *) temp_r30_100) + 0x48));
                temp_r6_75 = (MKProp *) (gb.unk0->GetProp());
                this->unk154->Trigger(*((MKVector3 *) &sp10), 0.4f, 1U, temp_r6_75, 0, 1U, 1U, 1U, 1U);
                M2C_FIELD(temp_r30_100, s32 *, 0x44) = 2;
                temp_r3_88 = this->unk150;
                this->unk150 = temp_r3_88 + 1;
                temp_r4_91 = *temp_r3_88;
                *temp_r3_88 = *var_r29_55;
                *var_r29_55 = temp_r4_91;
            }
            var_r29_55 += 1;
            goto loop_4;
        }
    }
loop_8:
    if (*this->unk150 != NULL) {
        this->unk150 = this->unk150 + 1;
        goto loop_8;
    }
    gb.EnableSlowMotion(0U, -1.0f, 0.5f);
    this->unk158 = -1;
}

#if 0 // DRAFT: illegal explicit conversion from 'FuryFXFire2::Meteor **' to 'float'
void FuryFXFire2::SpawnMeteor() {
    s8 sp138;
    s32 sp134;
    s32 sp130;
    s32 sp12C;
    f32 sp128;
    s32 sp124;
    s8 sp123;
    s8 sp122;
    s16 sp120;
    f32 sp11C;
    f32 sp118;
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
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Explosion4 *temp_r3_146;
    Explosion4 *temp_r3_155;
    f64 temp_f0_220;
    f64 temp_f0_232;
    f64 temp_f0_267;
    void *temp_r31_177;

    this->unk150 = M2C_BITWISE(f32, this->unk150) - gUpdateTimeDelta;
    if (!(M2C_BITWISE(f32, this->unk150) > 0.0f)) {
        this->unk150 = 0.05f;
        temp_r3_146 = this->unk154;
        if ((u32) M2C_FIELD(temp_r3_146, u32 *, -4) != 0U) {
            spE8 = 0.0f;
            temp_r3_155 = temp_r3_146 - 4;
            spEC = 0.0f;
            spF0 = 0.0f;
            spF8 = 0.0f;
            spFC = 0.0f;
            sp100 = 0.0f;
            sp108 = 0.0f;
            sp10C = 0.0f;
            sp110 = 0.0f;
            sp114 = 1.0f;
            sp118 = 0.0f;
            sp11C = 0.0f;
            sp120 = 0;
            sp122 = 0;
            sp123 = 0;
            sp124 = 0;
            sp128 = 3.4028235e38f;
            sp12C = 0;
            sp130 = 0;
            sp134 = -1;
            sp138 = 0;
            this->unk154 = temp_r3_155;
            temp_r31_177 = temp_r3_155->unk0;
            if (temp_r31_177 != NULL) {
                M2C_STRUCT_COPY(temp_r31_177, &Matrix::identity, 0x40);
                M2C_FIELD(temp_r31_177, s32 *, 0x48) = 0;
                sp68 = MKVector(0.0f, 2000.0f, 0.0f);
                sp78 = MKVector(1.0f, 0.0f, 1.0f);
                sp88 = MKVector(-1.0f, 0.0f, -1.0f);
                sp98 = KDRand_Vector(sp88, sp78);
                spA8 = sp98.operator*(1500.0f);
                temp_f0_220 = M2C_FIELD(this, f64 *, 0xC0) + M2C_BITWISE(f64, spA8);
                sp8 = temp_f0_220;
                spB8 = temp_f0_220;
                sp10 = this->unk90.unk38 + spA8.unk8;
                spC0 = (f64) sp10;
                temp_f0_232 = spB8 + M2C_BITWISE(f64, sp68);
                sp18 = temp_f0_232;
                spC8 = temp_f0_232;
                sp20 = (f32) spC0 + sp68.unk8;
                M2C_FIELD(temp_r31_177, f32 *, 0x30) = (f32) spC8;
                spD0 = (f64) sp20;
                M2C_FIELD(temp_r31_177, f32 *, 0x34) = (*(f32 *) ((u8 *) &spC8 + 0x4));
                sp40 = 0.0f;
                M2C_FIELD(temp_r31_177, f32 *, 0x38) = (f32) spD0;
                M2C_FIELD(temp_r31_177, f32 *, 0x3C) = 1.0f;
                sp38 = 0.0f;
                sp3C = -3000.0f;
                spD8 = (f64) M2C_FIELD(temp_r31_177, f32 *, 0x30);
                spE0 = (f64) M2C_FIELD(temp_r31_177, f32 *, 0x38);
                sp48 = (f64) sp38;
                M2C_FIELD(temp_r31_177, f32 *, 0x40) = (f32) this->unk90.unk34;
                sp50 = (f64) sp40;
                temp_f0_267 = spD8 + sp48;
                sp28 = temp_f0_267;
                sp58 = temp_f0_267;
                sp30 = (f32) spE0 + (f32) sp50;
                sp60 = (f64) sp30;
                if (MKCollision_RayCollide(*((MKVector3 *) &spD8), *((MKVector3 *) &sp58), (MKCollisionResult *) &spE8, (MKCollisionMode) 4, 0x0C000000) != 0) {
                    M2C_FIELD(temp_r31_177, f32 *, 0x40) = spEC;
                }
                M2C_FIELD(temp_r31_177, s32 *, 0x44) = 1;
                M2C_FIELD(temp_r31_177, s32 *, 0x48) = KDSound_Play3d(GS_SpyroFuryMissile1, ((u8 *) temp_r31_177) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    }
}
#endif

void FuryFXFire2::DrawMeteor(FuryFXFire2::Meteor *arg1) {
    MKModel_SetWorldMatrix(this->unk148, *((Matrix *) arg1));
    MKModel_Draw(this->unk148, NULL);
}

void FuryFXFire2::DrawMeteors() {
    Explosion4 *var_r31_334;
    void *temp_r4_343;

    var_r31_334 = this->unk154;
loop_2:
    if (var_r31_334 != NULL) {
        temp_r4_343 = var_r31_334->unk0;
        if (temp_r4_343 != NULL) {
            DrawMeteor((FuryFXFire2::Meteor *) temp_r4_343);
            var_r31_334 += 4;
            goto loop_2;
        }
    }
}

void FuryFXFire2::UpdateMeteors() {
    f64 sp18;
    f64 sp10;
    FuryFXFire2::Meteor **temp_r3_421;
    FuryFXFire2::Meteor **var_r30_362;
    MKProp *temp_r6_406;
    f32 temp_f1_391;
    s32 temp_r0_365;
    FuryFXFire2::Meteor *temp_r31_433;
    FuryFXFire2::Meteor *temp_r4_424;

    var_r30_362 = this->unk150;
loop_9:
    if (var_r30_362 != NULL) {
        temp_r31_433 = *var_r30_362;
        if (temp_r31_433 != NULL) {
            temp_r0_365 = M2C_FIELD(temp_r31_433, s32 *, 0x44);
            switch (temp_r0_365) {                  /* irregular */
            case 1:
                sp10 = M2C_FIELD(temp_r31_433, f64 *, 0x30);
                sp18 = M2C_FIELD(temp_r31_433, f64 *, 0x38);
                (*(f32 *) ((u8 *) &sp10 + 0x4)) += -3500.0f * gUpdateTimeDelta;
                M2C_FIELD(temp_r31_433, f32 *, 0x30) = *(f32 *) &sp10;
                M2C_FIELD(temp_r31_433, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp10 + 0x4));
                M2C_FIELD(temp_r31_433, f32 *, 0x38) = *(f32 *) &sp18;
                M2C_FIELD(temp_r31_433, f32 *, 0x3C) = 1.0f;
                temp_f1_391 = M2C_FIELD(temp_r31_433, f32 *, 0x40);
                if ((*(f32 *) ((u8 *) &sp10 + 0x4)) <= temp_f1_391) {
                    (*(f32 *) ((u8 *) &sp10 + 0x4)) = temp_f1_391;
                    KDSound_Stop((int *) (((u8 *) temp_r31_433) + 0x48));
                    temp_r6_406 = (MKProp *) (gb.unk0->GetProp());
                    this->unk154->Trigger(*((MKVector3 *) &sp10), 0.4f, 1U, temp_r6_406, 0, 1U, 1U, 1U, 1U);
                    M2C_FIELD(temp_r31_433, s32 *, 0x44) = 2;
                }
                break;
            case 2:
                temp_r3_421 = this->unk150;
                this->unk150 = temp_r3_421 + 1;
                temp_r4_424 = *temp_r3_421;
                *temp_r3_421 = *var_r30_362;
                *var_r30_362 = temp_r4_424;
                break;
            }
            var_r30_362 += 1;
            goto loop_9;
        }
    }
}

s32 FuryFXFire2::Trigger(const MKVector3 &arg0) {
    s32 temp_r0_472;
    s32 temp_r29_495;
    s32 temp_r3_470;
    s32 var_r30_488;
    u8 var_r3_478;
    u8 *temp_r5_474;

    this->unk90.unk30 = arg0.unk0;
    this->unk90.unk34 = arg0.unk4;
    this->unk90.unk38 = arg0.unk8;
    this->unk90.unk3C = 1.0f;
    if (this->unkD0 == 0) {
        this->unkD0 = 1;
        this->unkE8 = 1.0f;
        temp_r3_470 = *(s32 *) (GameData::gameData + 0x158) << 5;
        temp_r0_472 = *(s32 *) (GameData::gameData + 0x70 + temp_r3_470 + 0x7C);
        temp_r5_474 = GameData::gameData + 0x70 + temp_r3_470 + 0x64;
        if (temp_r0_472 == 3) {
            var_r3_478 = 0;
            if ((*(s32 *) temp_r5_474 == 3) && (*(s32 *) (temp_r5_474 + 4) == 3)) {
                var_r3_478 = 1;
            }
            var_r30_488 = var_r3_478 != 0;
        } else {
            var_r30_488 = *(s32 *) (temp_r5_474 + temp_r0_472 * 4);
        }
        temp_r29_495 = *(s32 *) (GameData::gameData + 0x158);
        this->unkF0.Init((MKProp *) gb.unk0->GetProp(), 15.0f * gb.unk37C, 3, var_r30_488, temp_r29_495, temp_r29_495, 0, -1);
        gb.unk381 = 1;
        return 1;
    }
    return 0;
}

void FuryFXFire2::SetDefaults() {
    FuryFX::SetDefaults();
    this->unkD0 = 0;
    this->unk90.SetIdentity();
    this->unkD8 = 1.0f;
    this->unkDC = 1.0f;
    this->unkE0 = 1.0f;
    this->unkE8 = 0.0f;
    this->unk14C = 0.0f;
}

extern "C" void free(void *);
void FuryFXFire2::Deinit() {
    void *var_r31_568;
    FuryFXFire2::Meteor **var_r3_569;
    FuryFXFire2::Meteor **var_r4_567;
    u32 temp_r0_577;
    void *temp_r0_572;
    void *temp_r0_591;

    var_r4_567 = this->unk150;
    var_r31_568 = var_r4_567;
    var_r3_569 = var_r4_567;
loop_3:
    temp_r0_577 = M2C_FIELD(var_r3_569, u32 *, -4);
    var_r3_569 -= 1;
    if (temp_r0_577 != 0U) {
        temp_r0_572 = *var_r3_569;
        if (temp_r0_572 < var_r31_568) {
            var_r31_568 = temp_r0_572;
        }
        goto loop_3;
    }
    if ((void *) var_r3_569 != (void *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_591 = *var_r4_567;
        if (temp_r0_591 != NULL) {
            if (temp_r0_591 < var_r31_568) {
                var_r31_568 = temp_r0_591;
            }
            var_r4_567 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_568, NULL, 0);
        } else {
            free(var_r31_568);
        }
    }
    this->unk150 = NULL;
    MKModel_Destroy(this->unk148);
    this->unk164.Deinit();
    FuryFX::Deinit();
}

void FuryFXFire2::Draw() {
    s32 temp_r0_628;

    temp_r0_628 = this->unkD0;
    switch (temp_r0_628) {                          /* irregular */
    case 1:
        return;
    default:
        DrawMeteors();
        /* fallthrough */
    case 0:
    case 6:
        return;
    }
}

#if 0 // DRAFT: function call 'GetProp(HeroInterface *, double, float)' does not match 'HeroInterface::GetProp()'
void *FuryFXFire2::Update() {
    MKCollisionResult sp760;
    Matrix sp720;
    f64 sp718;
    f64 sp710;
    f64 sp708;
    f64 sp700;
    f64 sp6F8;
    f64 sp6F0;
    f64 sp6E8;
    f64 sp6E0;
    f64 sp6D8;
    f64 sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    f64 sp6B8;
    f64 sp6B0;
    f64 sp6A8;
    f64 sp6A0;
    f64 sp698;
    f64 sp690;
    f64 sp688;
    f64 sp680;
    f64 sp678;
    f64 sp670;
    f64 sp668;
    f64 sp660;
    f64 sp658;
    f64 sp650;
    f64 sp648;
    f64 sp640;
    f64 sp638;
    f64 sp630;
    f64 sp628;
    f64 sp620;
    f64 sp618;
    f64 sp610;
    f64 sp608;
    f64 sp600;
    f64 sp5F8;
    f64 sp5F0;
    f64 sp5E8;
    f64 sp5E0;
    MKVector3 sp5D0;
    MKVector3 sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    MKVector3 sp5A0;
    MKVector3 sp590;
    MKVector3 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp560;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    MKVector3 sp530;
    MKVector3 sp520;
    f64 sp518;
    f64 sp510;
    MKVector3 sp500;
    MKVector3 sp4F0;
    MKVector3 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    MKVector3 sp490;
    MKVector3 sp480;
    f64 sp478;
    f64 sp470;
    MKVector3 sp460;
    MKVector3 sp450;
    MKVector3 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    MKVector3 sp400;
    MKVector3 sp3F0;
    MKVector3 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    MKVector3 sp3C0;
    MKVector3 sp3B0;
    MKVector3 sp3A0;
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
    f64 sp330;
    f64 sp328;
    f64 sp320;
    MKVector3 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f32 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp298;
    f64 sp290;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp278;
    f64 sp270;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp258;
    f64 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp238;
    f64 sp230;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp218;
    f64 sp210;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1F8;
    f64 sp1F0;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f64 sp170;
    f32 sp168;
    f64 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    MKVector3 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    MKVector3 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f22_1384;
    f32 temp_f23_1387;
    f32 var_f0_1587;
    f64 temp_f0_1034;
    f64 temp_f0_1127;
    f64 temp_f0_1176;
    f64 temp_f0_1332;
    f64 temp_f0_1405;
    f64 temp_f0_1423;
    f64 temp_f0_1435;
    f64 temp_f0_1451;
    f64 temp_f0_1497;
    f64 temp_f0_1552;
    f64 temp_f0_833;
    f64 temp_f0_898;
    f64 temp_f0_991;
    f64 temp_f1_1087;
    f64 temp_f1_1121;
    f64 temp_f1_1417;
    f64 temp_f1_1448;
    f64 temp_f1_1509;
    f64 temp_f1_726;
    f64 temp_f1_760;
    f64 temp_f1_794;
    f64 temp_f1_827;
    f64 temp_f1_951;
    f64 temp_f1_985;
    f64 temp_f2_1297;
    s32 temp_r0_688;
    s32 temp_r29_845;
    s32 temp_r4_1071;
    s32 temp_r4_935;
    s32 var_r28_1369;
    s32 var_r28_1474;
    void *temp_r3_1086;
    void *temp_r3_1120;
    void *temp_r3_1416;
    void *temp_r3_1508;
    void *temp_r3_725;
    void *temp_r3_759;
    void *temp_r3_793;
    void *temp_r3_826;
    void *temp_r3_950;
    void *temp_r3_984;

    this->unkE8 = this->unkE8 - gUpdateTimeDelta;
    this->unk164.Update();
    if ((s32) this->unkD0 != 0) {
        UpdateMeteors();
    }
    temp_r0_688 = this->unkD0;
    if ((u32) temp_r0_688 <= 6U) {
        switch (temp_r0_688) {
            return;
        case 1:
            if (this->unkE8 <= 0.0f) {
                this->unkD0 = 2;
                this->unkE8 = 0.25f;
                sp2A8 = 500.0f;
                sp2A0 = 500.0f;
                sp2A4 = -1000.0f;
                sp648 = (f64) sp2A8;
                sp640 = (f64) sp2A0;
                temp_r3_725 = M2C_FIELD(gb.unk0->GetProp((f64) sp2A0, 500.0f), void **, 8);
                temp_f1_726 = M2C_FIELD(temp_r3_725, f64 *, 0x30);
                sp650 = temp_f1_726;
                sp658 = M2C_FIELD(temp_r3_725, f64 *, 0x38);
                sp290 = temp_f1_726 + sp640;
                sp298 = (f32) sp658 + (f32) sp648;
                sp288 = 500.0f;
                sp710 = sp290;
                sp718 = (f64) sp298;
                sp280 = -500.0f;
                sp284 = -1000.0f;
                sp628 = (f64) sp288;
                sp620 = (f64) sp280;
                temp_r3_759 = M2C_FIELD(gb.unk0->GetProp((f64) sp280, -500.0f, (f64) sp298, sp290), void **, 8);
                temp_f1_760 = M2C_FIELD(temp_r3_759, f64 *, 0x30);
                sp630 = temp_f1_760;
                sp638 = M2C_FIELD(temp_r3_759, f64 *, 0x38);
                sp270 = temp_f1_760 + sp620;
                sp278 = (f32) sp638 + (f32) sp628;
                sp268 = -500.0f;
                sp700 = sp270;
                sp708 = (f64) sp278;
                sp260 = 500.0f;
                sp264 = -1000.0f;
                sp608 = (f64) sp268;
                sp600 = (f64) sp260;
                temp_r3_793 = M2C_FIELD(gb.unk0->GetProp((f64) sp260, 500.0f, (f64) sp278, sp270), void **, 8);
                temp_f1_794 = M2C_FIELD(temp_r3_793, f64 *, 0x30);
                sp610 = temp_f1_794;
                sp618 = M2C_FIELD(temp_r3_793, f64 *, 0x38);
                sp250 = temp_f1_794 + sp600;
                sp248 = -500.0f;
                sp258 = (f32) sp618 + (f32) sp608;
                sp6F0 = sp250;
                sp6F8 = (f64) sp258;
                sp240 = -500.0f;
                sp244 = -1000.0f;
                sp5E8 = (f64) sp248;
                sp5E0 = (f64) sp240;
                temp_r3_826 = M2C_FIELD(gb.unk0->GetProp((f64) sp240, -500.0f, (f64) sp258, sp250), void **, 8);
                temp_f1_827 = M2C_FIELD(temp_r3_826, f64 *, 0x30);
                sp5F0 = temp_f1_827;
                sp5F8 = M2C_FIELD(temp_r3_826, f64 *, 0x38);
                temp_f0_833 = temp_f1_827 + sp5E0;
                sp230 = temp_f0_833;
                sp6E0 = temp_f0_833;
                sp238 = (f32) sp5F8 + (f32) sp5E8;
                sp6E8 = (f64) sp238;
                temp_r29_845 = (KDSound_GetSoundEventVol(GS_SpyroFuryMissile1) >> 1U) & 0x7F;
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp710, 0U, temp_r29_845, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp700, 0U, temp_r29_845, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp6F0, 0U, temp_r29_845, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp6E0, 0U, temp_r29_845, 0.0f, 0U);
                this->unkD8 = 0.05f;
                this->unkDC = 1.0f;
                this->unkE0 = 0.05f;
                return;
            }
            break;
        case 2:
            sp580 = MKVector(3.0f, 5.0f, 3.0f);
            sp590 = MKVector(6.0f, 0.0f, 6.0f);
            sp5A0 = sp590.operator*(gUpdateTimeDelta);
            temp_f0_898 = (f64) M2C_FIELD(this, f32 *, 0xD8) + M2C_BITWISE(f64, sp5A0);
            sp40 = temp_f0_898;
            sp5B0 = temp_f0_898;
            sp48 = this->unkE0 + sp5A0.unk8;
            sp5B8 = (f64) sp48;
            sp5C0 = MKVector(0.0f, 0.0f, 0.0f);
            spA0 = Min(*((MKVector3 *) &sp5B0), sp580);
            sp5D0 = Max(spA0, sp5C0);
            *(MKVector3 *) &M2C_FIELD(this, f32 *, 0xD8) = sp5D0;
            if (this->unkE8 <= 0.0f) {
                this->unkE8 = 1.5f;
                temp_r4_935 = this->unkD0;
                sp228 = -1000.0f;
                this->unkD0 = temp_r4_935 + 1;
                sp220 = 0.0f;
                sp224 = -1000.0f;
                sp568 = (f64) sp228;
                sp560 = (f64) sp220;
                temp_r3_950 = M2C_FIELD(gb.unk0->GetProp(temp_r4_935, (f64) sp220), void **, 8);
                temp_f1_951 = M2C_FIELD(temp_r3_950, f64 *, 0x30);
                sp570 = temp_f1_951;
                sp578 = M2C_FIELD(temp_r3_950, f64 *, 0x38);
                sp210 = temp_f1_951 + sp560;
                sp218 = (f32) sp578 + (f32) sp568;
                sp208 = 1000.0f;
                sp6D0 = sp210;
                sp6D8 = (f64) sp218;
                sp200 = 0.0f;
                sp204 = -1000.0f;
                sp548 = (f64) sp208;
                sp540 = (f64) sp200;
                temp_r3_984 = M2C_FIELD(gb.unk0->GetProp((f64) sp200, 0.0f, (f64) sp218, sp210), void **, 8);
                temp_f1_985 = M2C_FIELD(temp_r3_984, f64 *, 0x30);
                sp550 = temp_f1_985;
                sp558 = M2C_FIELD(temp_r3_984, f64 *, 0x38);
                temp_f0_991 = temp_f1_985 + sp540;
                sp1F0 = temp_f0_991;
                sp6C0 = temp_f0_991;
                sp1F8 = (f32) sp558 + (f32) sp548;
                sp6C8 = (f64) sp1F8;
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp6D0, 0U, -1, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp6C0, 0U, -1, 0.0f, 0U);
                return;
            }
            break;
        case 3:
            sp4E0 = MKVector(5.0f, 50.0f, 5.0f);
            sp4F0 = MKVector(-1.0f, 4.0f, -1.0f);
            sp500 = sp4F0.operator*(gUpdateTimeDelta);
            temp_f0_1034 = (f64) M2C_FIELD(this, f32 *, 0xD8) + M2C_BITWISE(f64, sp500);
            sp30 = temp_f0_1034;
            sp510 = temp_f0_1034;
            sp38 = this->unkE0 + sp500.unk8;
            sp518 = (f64) sp38;
            sp520 = MKVector(0.1f, 0.0f, 0.1f);
            sp90 = Min(*((MKVector3 *) &sp510), sp4E0);
            sp530 = Max(sp90, sp520);
            *(MKVector3 *) &M2C_FIELD(this, f32 *, 0xD8) = sp530;
            if (this->unkE8 <= 0.0f) {
                this->unkE8 = 3.0f;
                temp_r4_1071 = this->unkD0;
                sp1E8 = 0.0f;
                this->unkD0 = temp_r4_1071 + 1;
                sp1E0 = -1000.0f;
                sp1E4 = -1000.0f;
                sp4C8 = (f64) sp1E8;
                sp4C0 = (f64) sp1E0;
                temp_r3_1086 = M2C_FIELD(gb.unk0->GetProp(temp_r4_1071, (f64) sp1E0), void **, 8);
                temp_f1_1087 = M2C_FIELD(temp_r3_1086, f64 *, 0x30);
                sp4D0 = temp_f1_1087;
                sp4D8 = M2C_FIELD(temp_r3_1086, f64 *, 0x38);
                sp1D0 = temp_f1_1087 + sp4C0;
                sp1D8 = (f32) sp4D8 + (f32) sp4C8;
                sp1C8 = 0.0f;
                sp6B0 = sp1D0;
                sp6B8 = (f64) sp1D8;
                sp1C0 = 1000.0f;
                sp1C4 = -1000.0f;
                sp4A8 = (f64) sp1C8;
                sp4A0 = (f64) sp1C0;
                temp_r3_1120 = M2C_FIELD(gb.unk0->GetProp((f64) sp1C0, 1000.0f, (f64) sp1D8, sp1D0), void **, 8);
                temp_f1_1121 = M2C_FIELD(temp_r3_1120, f64 *, 0x30);
                sp4B0 = temp_f1_1121;
                sp4B8 = M2C_FIELD(temp_r3_1120, f64 *, 0x38);
                temp_f0_1127 = temp_f1_1121 + sp4A0;
                sp1B0 = temp_f0_1127;
                sp6A0 = temp_f0_1127;
                sp1B8 = (f32) sp4B8 + (f32) sp4A8;
                sp6A8 = (f64) sp1B8;
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp6B0, 0U, -1, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &sp6A0, 0U, -1, 0.0f, 0U);
                gb.GetSpyro();
                this->unk160 = ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(0.0f);
                return;
            }
            break;
        case 4:
            sp440 = MKVector(5.0f, 50.0f, 5.0f);
            sp450 = MKVector(-2.0f, -3.0f, -2.0f);
            sp460 = sp450.operator*(gUpdateTimeDelta);
            temp_f0_1176 = (f64) M2C_FIELD(this, f32 *, 0xD8) + M2C_BITWISE(f64, sp460);
            sp20 = temp_f0_1176;
            sp470 = temp_f0_1176;
            sp28 = this->unkE0 + sp460.unk8;
            sp478 = (f64) sp28;
            sp480 = MKVector(0.05f, 0.0f, 0.05f);
            sp80 = Min(*((MKVector3 *) &sp470), sp440);
            sp490 = Max(sp80, sp480);
            *(MKVector3 *) &M2C_FIELD(this, f32 *, 0xD8) = sp490;
            SpawnMeteor();
            if (this->unkE8 <= 0.0f) {
                this->unkE8 = 0.6f;
                this->unkD0 += 1;
                M2C_STRUCT_COPY((s32) &unksp71C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp1A8 = 1.0f;
                sp198 = 0.0f;
                sp1A0 = 0.0f;
                sp1A4 = 0.0f;
                sp190 = 0.0f;
                sp194 = -1.0f;
                sp690 = (f64) sp1A0;
                sp698 = (f64) sp1A8;
                sp430 = (f64) sp190;
                sp438 = (f64) sp198;
                KDMath_BuildMatrixFromFwd(&sp720, *((MKVector3 *) &sp430), (MKVector3 *) &sp690);
                sp78 = 2.0f;
                sp70 = 2.0f;
                sp74 = 2.0f;
                sp428 = (f64) sp78;
                sp420 = (f64) sp70;
                sp720.Scale3x3(&sp720, *((MKVector3 *) &sp420));
                sp400 = MKVector(0.0f, 300.0f, 0.0f);
                sp60 = M2C_FIELD(this, f64 *, 0xC0) + M2C_BITWISE(f64, sp400);
                sp410 = sp60;
                sp68 = this->unk90.unk38 + sp400.unk8;
                sp418 = (f64) sp68;
                sp720.unk30 = (f32) sp410;
                sp720.unk34 = (*(f32 *) ((u8 *) &sp410 + 0x4));
                sp720.unk38 = (f32) sp418;
                sp720.unk3C = 1.0f;
                gb.unk1C0.StartWarp(&sp720);
                this->unkF0.unk50 = 0;
                temp_f2_1297 = M2C_FIELD(this, f64 *, 0xC0);
                sp680 = temp_f2_1297;
                sp688 = (f64) M2C_FIELD(this, f32 *, 0xC8);
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unkF0, 0, 0, &sp680, 1, 3000.0f, temp_f2_1297);
                gb.GetSpyro();
                ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(M2C_BITWISE(f32, this->unk160));
                return;
            }
            break;
        case 5:
            sp3A0 = MKVector(500.0f, 500.0f, 500.0f);
            sp3B0 = MKVector(20.0f, -10.0f, 20.0f);
            sp3C0 = sp3B0.operator*(gUpdateTimeDelta);
            temp_f0_1332 = (f64) M2C_FIELD(this, f32 *, 0xD8) + M2C_BITWISE(f64, sp3C0);
            sp10 = temp_f0_1332;
            sp3D0 = temp_f0_1332;
            sp18 = this->unkE0 + sp3C0.unk8;
            sp3D8 = (f64) sp18;
            sp3E0 = MKVector(0.1f, 0.0f, 0.1f);
            sp50 = Min(*((MKVector3 *) &sp3D0), sp3A0);
            sp3F0 = Max(sp50, sp3E0);
            *(MKVector3 *) &M2C_FIELD(this, f32 *, 0xD8) = sp3F0;
            if (this->unkE8 <= 0.0f) {
                this->unkD0 = 6;
                var_r28_1369 = 0;
                this->unkE8 = 1.4f;
                do {
                    temp_f22_1384 = 6.2831855f * ((f32) var_r28_1369 / 10.0f);
                    temp_f23_1387 = -_table_sinf(1.5707964f + temp_f22_1384);
                    sp180 = _table_sinf(temp_f22_1384);
                    sp184 = 0.0f;
                    sp188 = temp_f23_1387;
                    sp158 = 0.0f;
                    sp150 = 0.0f;
                    sp154 = 200.0f;
                    sp670 = (f64) sp180;
                    sp678 = (f64) sp188;
                    sp350 = (f64) sp150;
                    sp358 = (f64) sp158;
                    temp_f0_1405 = sp670 * 5.5769738e-315;
                    sp170 = temp_f0_1405;
                    sp360 = temp_f0_1405;
                    sp178 = (f32) sp678 * 200.0f;
                    sp368 = (f64) sp178;
                    gb.GetSpyro();
                    temp_r3_1416 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 8);
                    temp_f1_1417 = M2C_FIELD(temp_r3_1416, f64 *, 0x30);
                    sp370 = temp_f1_1417;
                    sp378 = M2C_FIELD(temp_r3_1416, f64 *, 0x38);
                    temp_f0_1423 = temp_f1_1417 + temp_f0_1405;
                    sp160 = temp_f0_1423;
                    sp380 = temp_f0_1423;
                    sp168 = (f32) sp378 + (f32) sp368;
                    sp388 = (f64) sp168;
                    temp_f0_1435 = sp380 + sp350;
                    sp140 = temp_f0_1435;
                    sp390 = temp_f0_1435;
                    sp148 = (f32) sp388 + (f32) sp358;
                    sp398 = (f64) sp148;
                    temp_f1_1448 = MKRand_Float((int *) &gViewSeed, 3000.0f, 3500.0f);
                    temp_f0_1451 = sp670 * temp_f1_1448;
                    sp130 = temp_f0_1451;
                    sp340 = temp_f0_1451;
                    sp138 = (f32) sp678 * (f32) temp_f1_1448;
                    sp348 = (f64) sp138;
                    ((ClusterBomb *) this->unk164.unk0)->SpawnClusterBomb(*((MKVector3 *) &sp390), *((MKVector3 *) &sp340));
                    var_r28_1369 += 1;
                } while (var_r28_1369 < 0xA);
                var_r28_1474 = 0;
                do {
                    sp128 = -1.0f;
                    sp118 = 1.0f;
                    sp120 = -1.0f;
                    sp124 = 0.0f;
                    sp110 = 1.0f;
                    sp114 = 0.0f;
                    sp300 = (f64) sp120;
                    sp308 = (f64) sp128;
                    sp2F0 = (f64) sp110;
                    sp2F8 = (f64) sp118;
                    sp310 = KDRand_Vector(*((MKVector3 *) &sp300), *((MKVector3 *) &sp2F0));
                    temp_f0_1497 = sp310 * 5.697262106e-315;
                    sp100 = temp_f0_1497;
                    sp320 = temp_f0_1497;
                    sp108 = sp310.unk8 * 1500.0f;
                    sp328 = (f64) sp108;
                    gb.GetSpyro();
                    temp_r3_1508 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 8);
                    temp_f1_1509 = M2C_FIELD(temp_r3_1508, f64 *, 0x30);
                    sp330 = temp_f1_1509;
                    sp338 = M2C_FIELD(temp_r3_1508, f64 *, 0x38);
                    spF0 = temp_f1_1509 + temp_f0_1497;
                    spC8 = 0.0f;
                    spC0 = 0.0f;
                    spC4 = -500.0f;
                    spF8 = (f32) sp338 + (f32) sp328;
                    sp660 = spF0;
                    sp2B0 = (f64) spC0;
                    sp668 = (f64) spF8;
                    sp2B8 = (f64) spC8;
                    spB0 = sp660 + sp2B0;
                    spE8 = 0.0f;
                    spE0 = 0.0f;
                    spE4 = 200.0f;
                    spB8 = (f32) sp668 + (f32) sp2B8;
                    sp2D0 = (f64) spE0;
                    sp2C0 = spB0;
                    sp2C8 = (f64) spB8;
                    sp2D8 = (f64) spE8;
                    temp_f0_1552 = sp660 + sp2D0;
                    spD0 = temp_f0_1552;
                    sp2E0 = temp_f0_1552;
                    spD8 = (f32) sp668 + (f32) sp2D8;
                    sp2E8 = (f64) spD8;
                    if (MKCollision_RayCollide(*((MKVector3 *) &sp2E0), *((MKVector3 *) &sp2C0), &sp760, (MKCollisionMode) 7, 0x0C000000) != 0) {
                        sp660 = M2C_BITWISE(f64, sp760);
                        sp668 = (f64) sp760.unk8;
                    }
                    this->unk164.Emit(*((MKVector3 *) &sp660), MKRand_Float((int *) &gViewSeed, 3.0f, 5.0f), 0U);
                    var_r28_1474 += 1;
                } while (var_r28_1474 < 0xA);
                return;
            }
            break;
        case 6:
            var_f0_1587 = this->unkE8;
            if (var_f0_1587 < 1.4f) {

            } else {
                var_f0_1587 = 1.4f;
            }
            if (var_f0_1587 > 0.0f) {

            } else {
                var_f0_1587 = 0.0f;
            }
            this->unkE8 = var_f0_1587;
            if (this->unkE8 <= 0.0f) {
                this->unkD0 = 0;
                gb.unk381 = 0;
            }
            break;
        }
    }
}
#endif

extern "C" void *malloc(u32);
void FuryFXFire2::Init() {
    u8 *pool;
    u8 *var_r5;
    s32 var_ctr;
    FuryFXFire2::Meteor **temp_r3;
    FuryFXFire2::Meteor **temp_r4;

    FuryFX::Init();
    SetDefaults();
    if (MKHeap::Current() != NULL) {
        pool = (u8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x698, NULL, 0));
    } else {
        pool = (u8 *) malloc((u32) 0x698);
    }
    this->unk150 = (FuryFXFire2::Meteor **) pool;
    var_r5 = pool;
    this->unk150 = (FuryFXFire2::Meteor **) (var_r5 + 0x640);
    M2C_FIELD(var_r5, s32 *, 0x640) = 0;
    var_ctr = 0x14;
    do {
        temp_r3 = this->unk150 + 1;
        this->unk150 = temp_r3;
        *temp_r3 = (FuryFXFire2::Meteor *) var_r5;
        var_r5 += 0x50;
        var_ctr -= 1;
    } while (var_ctr != 0);
    temp_r4 = this->unk150 + 1;
    this->unk150 = temp_r4;
    *temp_r4 = NULL;
    this->unk148 = MKModel_Create("P0002_LavaCannonBall", NULL, 2, NULL);
    ((MKSceneManager *) gMK)->CreatePropDeferred("Explosion4", (MKProp **) &this->unk154);
    ((MKSceneManager *) gMK)->CreatePropDeferred("ClusterBomb", (MKProp **) &this->unk160);
    this->unk164.Init(0xA);
    this->unk158 = -1;
}

void FuryFXFire2_cpp::__sinit() {
    f32 temp_f0_1752;
    f64 temp_f1_1733;
    f64 temp_f1_1741;
    f64 temp_f3_1721;
    f64 temp_f4_1730;
    f64 temp_f4_1738;
    f64 temp_f8_1723;

    temp_f3_1721 = __frsqrte(2014000.0);
    temp_f8_1723 = __frsqrte(380000.0);
    temp_f4_1730 = 0.5 * temp_f3_1721 * -((2014000.0 * (temp_f3_1721 * temp_f3_1721)) - 3.0);
    temp_f1_1733 = 0.5 * temp_f8_1723 * -((380000.0 * (temp_f8_1723 * temp_f8_1723)) - 3.0);
    temp_f4_1738 = 0.5 * temp_f4_1730 * -((2014000.0 * (temp_f4_1730 * temp_f4_1730)) - 3.0);
    temp_f1_1741 = 0.5 * temp_f1_1733 * -((380000.0 * (temp_f1_1733 * temp_f1_1733)) - 3.0);
    temp_f0_1752 = (f32) (380000.0 * (0.5 * temp_f1_1741 * -((380000.0 * (temp_f1_1741 * temp_f1_1741)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1738 * -((2014000.0 * (temp_f4_1738 * temp_f4_1738)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1752;
}
