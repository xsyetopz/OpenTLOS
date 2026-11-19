#include "spyro/source/FuryFXFire.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
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
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/System_GC.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
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
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/ShapedTrailFX.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_enums.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(M2C_UNK *, FuryFXFire::DragonStruct *(*)(FuryFXFire::DragonStruct *, s16), M2C_UNK, M2C_UNK); /* extern */
extern s32 GS_CynderFuryBuildUp2;
extern s32 GS_CynderFuryExtra1;
extern s32 GS_CynderFuryImpact;
extern s32 GS_CynderFuryLP;
extern s32 GS_Rumble1;
extern s32 GS_SpyroFuryAttack1;
extern s32 GS_SpyroFuryAttack2;
extern s32 GS_SpyroFuryAttack3;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_761 = 0;
static u8 lit_762 = 1;

static s32 lit_766 = 0;
static u8 lit_767 = 0;
static s32 lit_774 = -1;
static s32 lit_775 = 6;

static u8 lit_845 = 1;
static u8 lit_910 = 0;

static u8 lit_1163 = 0;

#if 0 // DRAFT: undefined identifier 'unkD0'
void FuryFXFire::ResetFury() {
    s32 spC;
    s32 sp8;
    Corona *temp_r4_118;
    ManagedLight *temp_r4_63;
    s32 var_r27_97;
    s32 var_r30_96;
    void *temp_r28_100;
    void *temp_r4_107;
    void *temp_r5_102;

    SetDefaults();
    temp_r4_63 = this->unkE8;
    if (temp_r4_63 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_63, 0U);
    }
    gb.unkD0 = 0;
    gb.unk2CC.Disable(this->unk2E8);
    this->unk2E8 = -1;
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spC = 0;
        sp8 = 0x459;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    var_r30_96 = 0;
    var_r27_97 = 0;
    do {
        temp_r28_100 = this + var_r30_96;
        temp_r5_102 = M2C_FIELD(temp_r28_100, void **, 0x130);
        M2C_FIELD(temp_r5_102, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r5_102, u8 *, 0xA0) & ~0x80) | ((lit_1163 << 7) & 0x80));
        temp_r4_107 = M2C_FIELD(temp_r28_100, void **, 0x130);
        M2C_FIELD(temp_r4_107, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_107, u8 *, 0xA0) & ~0x40);
        KDSound_Stop(((u8 *) temp_r28_100) + 0x134);
        KDSound_Stop(((u8 *) temp_r28_100) + 0x15C);
        var_r27_97 += 1;
        var_r30_96 += 0x80;
    } while (var_r27_97 < 3);
    temp_r4_118 = this->unkF4;
    if (temp_r4_118 != NULL) {
        temp_r4_118->unk31 &= ~0x40;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2CC'
s32 FuryFXFire::Trigger(const MKVector3 &arg0, bool arg1, bool arg2, HeroHurtReactionType arg3) {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_198;
    f64 temp_f0_217;
    s32 temp_r0_270;
    s32 temp_r29_293;
    s32 temp_r3_268;
    s32 var_ctr_176;
    s32 var_ctr_239;
    s32 var_r30_286;
    s32 var_r3_174;
    s32 var_r3_219;
    u8 var_r3_276;
    void *temp_r4_179;
    void *temp_r4_242;
    void *temp_r5_272;

    if ((s32) this->unk104 == 0) {
        this->unk2F0 = arg1;
        this->unk2F1 = arg2;
        this->unk2EC = (s32) arg3;
        if ((u8) this->unk2F1 == 0) {
            this->unk90.unk30 = arg0.unk0;
            this->unk90.unk34 = arg0.unk4;
            this->unk90.unk38 = arg0.unk8;
            this->unk90.unk3C = 1.0f;
            this->unk2E8 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
            this->unk100 = 1.0f;
            var_r3_174 = 0;
            gb.unk381 = 1;
            var_ctr_176 = 3;
            do {
                temp_r4_179 = *(this + (var_r3_174 + 0x130));
                if (temp_r4_179 != NULL) {
                    sp38 = 1.0f;
                    sp3C = 1.0f;
                    sp40 = 1.0f;
                    sp44 = 1.0f;
                    M2C_FIELD(temp_r4_179, f64 *, 0x50) = (f64) sp38;
                    sp88 = (f64) sp38;
                    sp90 = (f64) sp40;
                    M2C_FIELD(temp_r4_179, f64 *, 0x58) = (f64) sp40;
                }
                var_r3_174 += 0x80;
                var_ctr_176 -= 1;
            } while (var_ctr_176 != 0);
        } else {
            temp_r3_198 = &this->unk90;
            sp30 = 1.0f;
            sp28 = 1.0f;
            sp2C = 3.0f;
            sp80 = (f64) sp30;
            sp78 = (f64) sp28;
            temp_r3_198->Scale3x3(temp_r3_198, *((MKVector3 *) &sp78));
            MKVector(0.0f, 600.0f, 0.0f);
            temp_f0_217 = (f64) M2C_FIELD(&arg0, f32 *, 0) - sp58;
            sp18 = temp_f0_217;
            var_r3_219 = 0;
            sp68 = temp_f0_217;
            sp20 = arg0.unk8 - sp60;
            this->unk90.unk30 = (f32) sp68;
            sp70 = (f64) sp20;
            this->unk90.unk34 = (*(f32 *) ((u8 *) &sp68 + 0x4));
            this->unk90.unk38 = (f32) sp70;
            this->unk90.unk3C = 1.0f;
            this->unk100 = 0.0f;
            var_ctr_239 = 3;
            do {
                temp_r4_242 = *(this + (var_r3_219 + 0x130));
                if (temp_r4_242 != NULL) {
                    sp8 = 1.0f;
                    spC = 0.0f;
                    sp10 = 0.0f;
                    sp14 = 1.0f;
                    M2C_FIELD(temp_r4_242, f64 *, 0x50) = (f64) sp8;
                    sp48 = (f64) sp8;
                    sp50 = (f64) sp10;
                    M2C_FIELD(temp_r4_242, f64 *, 0x58) = (f64) sp10;
                }
                var_r3_219 += 0x80;
                var_ctr_239 -= 1;
            } while (var_ctr_239 != 0);
        }
        this->unkF8 = 0.0f;
        this->unkFC = 0.0f;
        this->unk104 = 1;
        temp_r3_268 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_270 = *(&GameData::gameData[0x70] + (temp_r3_268 + 0x7C));
        temp_r5_272 = &GameData::gameData[0x70] + (temp_r3_268 + 0x64);
        if (temp_r0_270 == 3) {
            var_r3_276 = 0;
            if (((s32) M2C_FIELD(temp_r5_272, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_272, s32 *, 4) == 3)) {
                var_r3_276 = 1;
            }
            var_r30_286 = var_r3_276 != 0;
        } else {
            var_r30_286 = *(temp_r5_272 + (temp_r0_270 * 4));
        }
        temp_r29_293 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
        this->unk290.Init(gb.unk0->GetProp(), 15.0f * gb.unk37C, 3, var_r30_286, temp_r29_293, temp_r29_293, 0, -1);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FuryFXFire::SetDefaults() {
    FuryFX::SetDefaults();
    this->unk104 = 0;
    this->unk90.SetIdentity();
    this->unkD0 = 1.0f;
    this->unkD4 = 1.0f;
    this->unkD8 = 1.0f;
    this->unk100 = 0.0f;
    this->unkF8 = -1.0f;
    this->unkFC = 0.0f;
    this->unk2F0 = 0;
    this->unk2F1 = 0;
    this->unk2EC = 1;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(unsigned char *)' does not match
void FuryFXFire::Deinit() {
    Corona *temp_r4_396;
    MKMaterial *temp_r3_417;
    ManagedLight *temp_r4_382;
    s32 var_r29_368;
    s32 var_r31_369;
    void *temp_r30_371;

    var_r29_368 = 0;
    var_r31_369 = 0;
    do {
        temp_r30_371 = this + var_r31_369;
        KDSound_Stop(((u8 *) temp_r30_371) + 0x134);
        KDSound_Stop(((u8 *) temp_r30_371) + 0x15C);
        var_r29_368 += 1;
        var_r31_369 += 0x80;
    } while (var_r29_368 < 3);
    MKMaterial_Destroy(this->unkE0);
    temp_r4_382 = this->unkE8;
    if (temp_r4_382 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_382, 0U);
        ((LightManager *) gb.unk80)->FreeManagedLight(this->unkE8);
        this->unkE8 = NULL;
    }
    temp_r4_396 = this->unkF4;
    if (temp_r4_396 != NULL) {
        ((Coronas *) gb.unk64)->Free(temp_r4_396);
        this->unkF4 = NULL;
    }
    MKModel_Destroy(this->unkEC);
    MKModel_Destroy(this->unkF0);
    gb.unk2CC.Disable(this->unk2E8);
    this->unk2E8 = -1;
    temp_r3_417 = this->unkE4;
    if (temp_r3_417 != NULL) {
        MKMaterial_Destroy(temp_r3_417);
    }
    FuryFX::Deinit();
}
#endif

void FuryFXFire::Draw() {
    Matrix sp40;
    M2C_UNK sp3C;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f2_459;
    s32 temp_r0_442;

    temp_r0_442 = this->unk104;
    switch (temp_r0_442) {                          /* irregular */
    case 1:
        return;
    default:
        MKView_Push();
        MKView_GetProjection(NULL, &sp10, NULL);
        temp_f2_459 = sp10 + 10.0f;
        sp10 = temp_f2_459;
        MKView_SetProjection(0.0f, temp_f2_459, 0.0f);
        M2C_STRUCT_COPY((s32) &sp3C + 4, (s32) &this->unk8C + 4, 0x40);
        sp18 = 7.0f * this->unkD0;
        sp20 = 7.0f * this->unkD8;
        sp1C = 3.0f * this->unkD4;
        sp30 = (f64) sp20;
        sp28 = (f64) sp18;
        sp40.Scale3x3(&sp40, *((MKVector3 *) &sp28));
        MKModel_SetWorldMatrix(this->unkF0, sp40);
        if ((u8) this->unk2F1 != 0) {
            gRenderState = this->unkE4;
            MKModel_Draw(this->unkF0, NULL);
            gRenderState = NULL;
            MKModel_Draw(this->unkF0, NULL);
        } else {
            MKModel_Draw(this->unkF0, NULL);
        }
        MKView_Pop();
        /* fallthrough */
    case 0:
    case 6:
        return;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void FuryFXFire::UpdateDragons() {
    Matrix spA0;
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
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKVector3 *temp_r25_660;
    ManagedLight *temp_r3_694;
    ManagedLight *temp_r3_725;
    ManagedLight *temp_r3_741;
    f32 temp_f1_602;
    f32 temp_f1_720;
    f32 temp_f22_586;
    f32 temp_f23_591;
    f32 temp_f24_600;
    f32 var_f1_592;
    f64 temp_f0_624;
    s32 var_r26_565;
    s32 var_r28_563;
    s32 var_r4_654;
    s32 var_r4_676;
    void *temp_r30_570;
    void *temp_r3_648;
    void *temp_r3_710;
    void *temp_r3_733;
    void *temp_r3_744;

    var_r28_563 = 0;
    var_r26_565 = 0;
    do {
        temp_r30_570 = this + var_r26_565;
        M2C_FIELD(temp_r30_570, f32 *, 0x110) = (f32) ((M2C_FIELD(temp_r30_570, f32 *, 0x114) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_570, f32 *, 0x110));
        M2C_FIELD(temp_r30_570, f32 *, 0x118) = (f32) ((2.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r30_570, f32 *, 0x118));
        M2C_FIELD(temp_r30_570, f32 *, 0x11C) = (f32) (M2C_FIELD(temp_r30_570, f32 *, 0x11C) + gUpdateTimeDelta);
        temp_f22_586 = 400.0f * this->unkD0;
        temp_f23_591 = temp_f22_586 * -_table_sinf(1.5707964f + M2C_FIELD(temp_r30_570, f32 *, 0x110));
        var_f1_592 = _table_sinf(M2C_FIELD(temp_r30_570, f32 *, 0x118));
        if (var_f1_592 < 0.0f) {
            var_f1_592 = -var_f1_592;
        }
        temp_f24_600 = (50.0f * this->unkD4) + (300.0f * var_f1_592);
        temp_f1_602 = temp_f22_586 * _table_sinf(M2C_FIELD(temp_r30_570, f32 *, 0x110));
        sp48 = temp_f23_591;
        sp40 = temp_f1_602;
        sp44 = temp_f24_600;
        sp88 = (f64) sp48;
        sp80 = (f64) sp40;
        sp90 = (f64) sp40;
        sp98 = (f64) sp48;
        M2C_STRUCT_COPY((s32) &sp9C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f0_624 = (f64) sp40 + M2C_FIELD(this, f64 *, 0xC0);
        sp30 = temp_f0_624;
        spA0.unk3C = 1.0f;
        sp70 = temp_f0_624;
        sp38 = (f32) sp98 + this->unk90.unk38;
        sp78 = (f64) sp38;
        spA0.unk30 = (f32) sp70;
        spA0.unk34 = (*(f32 *) ((u8 *) &sp70 + 0x4));
        spA0.unk38 = (f32) sp78;
        MKModel_SetWorldMatrix(this->unkEC, spA0);
        ((ShapedTrailFX *) (M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)))->UpdateTrail();
        temp_r3_648 = MKModel_GetWorldMatrix(M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)->unk78);
        M2C_FIELD(temp_r30_570, f64 *, 0x120) = (f64) M2C_FIELD(temp_r3_648, f64 *, 0x30);
        M2C_FIELD(temp_r30_570, f64 *, 0x128) = (f64) M2C_FIELD(temp_r3_648, f64 *, 0x38);
        var_r4_654 = GS_SpyroFuryAttack1;
        if ((u8) this->unk2F1 != 0) {
            var_r4_654 = GS_CynderFuryLP;
        }
        temp_r25_660 = ((u8 *) temp_r30_570) + 0x120;
        sp8 = 1;
        ((KDSoundFader *) (((u8 *) temp_r30_570) + 0x134))->Update(var_r4_654, 1U, ((u8) M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)->unkA0 >> 6U) & 1, NULL, temp_r25_660, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        sp8 = 1;
        var_r4_676 = GS_SpyroFuryAttack3;
        if ((u8) this->unk2F1 != 0) {
            var_r4_676 = GS_CynderFuryExtra1;
        }
        ((KDSoundFader *) (((u8 *) temp_r30_570) + 0x15C))->Update(var_r4_676, 1U, ((u8) M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)->unkA0 >> 6U) & 1, NULL, temp_r25_660, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        var_r28_563 += 1;
        var_r26_565 += 0x80;
    } while (var_r28_563 < 3);
    temp_r3_694 = this->unkE8;
    if (temp_r3_694 != NULL) {
        sp20 = sp90 + M2C_FIELD(this, f64 *, 0xC0);
        temp_r3_694->unk10 = sp20;
        sp28 = (f32) sp98 + this->unk90.unk38;
        sp60 = sp20;
        temp_r3_694->unk18 = (f64) sp28;
        temp_r3_710 = temp_r3_694->unk3C;
        sp68 = (f64) sp28;
        if (temp_r3_710 != NULL) {
            M2C_FIELD(temp_r3_710, f64 *, 0x10) = sp20;
            M2C_FIELD(temp_r3_710, f64 *, 0x18) = (f64) sp28;
        }
        temp_f1_720 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
        sp10 = 0.75f;
        temp_r3_725 = this->unkE8;
        sp14 = temp_f1_720;
        sp18 = 0.0f;
        sp1C = 1.0f;
        temp_r3_725->unk20 = (f64) sp10;
        temp_r3_725->unk28 = (f64) sp18;
        temp_r3_733 = temp_r3_725->unk3C;
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        if (temp_r3_733 != NULL) {
            M2C_FIELD(temp_r3_733, f64 *, 0) = (f64) sp10;
            M2C_FIELD(temp_r3_733, f64 *, 8) = (f64) sp18;
        }
        temp_r3_741 = this->unkE8;
        temp_r3_741->unk38 = 1000.0f;
        temp_r3_744 = temp_r3_741->unk3C;
        if (temp_r3_744 != NULL) {
            M2C_FIELD(temp_r3_744, f32 *, 0x20) = 1000.0f;
            M2C_FIELD(temp_r3_744, f32 *, 0x24) = 1000000.0f;
            M2C_FIELD(temp_r3_744, f32 *, 0x28) = 0.001f;
            M2C_FIELD(temp_r3_744, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_744, f32 *, 0x24));
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FuryFXFire::Message(MKMessage *arg0) {
    s32 var_r29_795;
    s32 var_r31_796;
    void *temp_r30_798;

    KDProp::Message(arg0);
    var_r29_795 = 0;
    var_r31_796 = 0;
    do {
        temp_r30_798 = this + var_r31_796;
        ((KDSoundPlayer *) (((u8 *) temp_r30_798) + 0x134))->Message(arg0);
        ((KDSoundPlayer *) (((u8 *) temp_r30_798) + 0x15C))->Message(arg0);
        var_r29_795 += 1;
        var_r31_796 += 0x80;
    } while (var_r29_795 < 3);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void *FuryFXFire::Update() {
    s8 sp991;
    s8 sp990;
    s32 sp98C;
    f32 sp988;
    s32 sp984;
    s8 sp982;
    s8 sp981;
    s8 sp980;
    f32 sp978;
    f32 sp974;
    f32 sp970;
    s32 sp96C;
    s32 sp968;
    f64 sp960;
    f64 sp958;
    f64 sp950;
    f64 sp948;
    s32 sp944;
    s32 sp940;
    Matrix sp900;
    M2C_UNK sp8FC;
    s8 sp8F8;
    f64 sp8F0;
    f64 sp8E8;
    s32 sp8E4;
    s32 sp8E0;
    s8 sp8D8;
    f64 sp8D0;
    f64 sp8C8;
    s32 sp8C4;
    s32 sp8C0;
    s8 sp8B8;
    f64 sp8B0;
    f64 sp8A8;
    s32 sp8A4;
    s32 sp8A0;
    s8 sp898;
    f64 sp890;
    f64 sp888;
    s32 sp884;
    s32 sp880;
    f32 sp878;
    s32 sp874;
    s32 sp870;
    f64 sp868;
    f64 sp860;
    f64 sp858;
    f64 sp850;
    f64 sp848;
    f64 sp840;
    f32 sp838;
    s32 sp834;
    s32 sp830;
    f64 sp828;
    f64 sp820;
    f64 sp818;
    f64 sp810;
    f64 sp808;
    f64 sp800;
    f64 sp7F0;
    f64 sp7E8;
    f64 sp7E0;
    MKVector3 sp7D0;
    M2C_UNK sp7C0;
    f64 sp7B8;
    f64 sp7B0;
    MKVector3 sp7A0;
    M2C_UNK sp790;
    M2C_UNK sp780;
    f64 sp778;
    f64 sp770;
    f64 sp760;
    f64 sp758;
    f64 sp750;
    f64 sp748;
    f64 sp740;
    f64 sp738;
    f64 sp730;
    f64 sp728;
    f64 sp720;
    f64 sp718;
    f64 sp710;
    f64 sp708;
    f64 sp700;
    f64 sp6F8;
    f64 sp6F0;
    MKVector3 sp6E0;
    M2C_UNK sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    MKVector3 sp6B0;
    M2C_UNK sp6A0;
    M2C_UNK sp690;
    f64 sp688;
    f64 sp680;
    f64 sp670;
    f64 sp668;
    f64 sp660;
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
    M2C_UNK sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    MKVector3 sp5A0;
    M2C_UNK sp590;
    M2C_UNK sp580;
    MKVector3 sp570;
    M2C_UNK sp560;
    f64 sp558;
    f64 sp550;
    MKVector3 sp540;
    M2C_UNK sp530;
    M2C_UNK sp520;
    f64 sp518;
    f64 sp510;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp460;
    MKVector3 sp450;
    M2C_UNK sp440;
    f64 sp438;
    f64 sp430;
    MKVector3 sp420;
    M2C_UNK sp410;
    M2C_UNK sp400;
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
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp358;
    f32 sp354;
    f32 sp350;
    f32 sp348;
    f64 sp340;
    f32 sp338;
    f64 sp330;
    f32 sp328;
    f64 sp320;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    f32 sp30C;
    f32 sp308;
    f32 sp304;
    f32 sp300;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    f32 sp2C8;
    f64 sp2C0;
    f32 sp2B8;
    f64 sp2B0;
    f32 sp2A8;
    f64 sp2A0;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1F8;
    f64 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f64 sp160;
    MKVector3 sp150;
    f32 sp148;
    f64 sp140;
    MKVector3 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    MKVector3 sp80;
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
    s32 sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Corona *temp_r3_1342;
    Corona *temp_r3_1652;
    Corona *temp_r3_1659;
    Corona *temp_r3_2054;
    Corona *temp_r3_2060;
    Corona *temp_r4_1331;
    Corona *temp_r4_1631;
    Corona *temp_r4_2098;
    KDSynkerPlayer3 *temp_r3_2372;
    ManagedLight *temp_r3_2341;
    ManagedLight *temp_r3_2418;
    ManagedLight *temp_r3_2449;
    ManagedLight *temp_r3_2485;
    ManagedLight *temp_r4_1131;
    ManagedLight *temp_r4_2586;
    f32 temp_f19_2670;
    f32 temp_f1_1081;
    f32 temp_f1_1445;
    f32 temp_f1_1781;
    f32 temp_f1_2456;
    f32 temp_f1_2559;
    f32 temp_f1_2696;
    f32 temp_f1_869;
    f32 temp_f20_1360;
    f32 temp_f20_1433;
    f32 temp_f20_1442;
    f32 temp_f20_1498;
    f32 temp_f20_1542;
    f32 temp_f20_1696;
    f32 temp_f20_1769;
    f32 temp_f20_1778;
    f32 temp_f20_1834;
    f32 temp_f20_1878;
    f32 temp_f20_2672;
    f32 temp_f20_2681;
    f32 temp_f20_2772;
    f32 temp_f20_932;
    f32 temp_f21_1365;
    f32 temp_f21_1440;
    f32 temp_f21_1493;
    f32 temp_f21_1701;
    f32 temp_f21_1776;
    f32 temp_f21_1829;
    f32 temp_f21_2679;
    f32 temp_f21_2777;
    f32 temp_f21_2819;
    f32 temp_f22_1431;
    f32 temp_f22_1767;
    f32 temp_f22_2654;
    f32 temp_f23_1419;
    f32 temp_f23_1755;
    f32 temp_f26_2698;
    f32 temp_f2_2684;
    f32 temp_f30_1424;
    f32 temp_f30_1760;
    f32 temp_f3_860;
    f32 temp_f3_873;
    f32 temp_f4_2454;
    f32 var_f0_2850;
    f32 var_f20_1061;
    f32 var_f27_2435;
    f64 temp_f0_1265;
    f64 temp_f0_1455;
    f64 temp_f0_1465;
    f64 temp_f0_1476;
    f64 temp_f0_1604;
    f64 temp_f0_1646;
    f64 temp_f0_1791;
    f64 temp_f0_1801;
    f64 temp_f0_1812;
    f64 temp_f0_1943;
    f64 temp_f0_1989;
    f64 temp_f0_2515;
    f64 temp_f1_2717;
    f64 temp_f1_2728;
    f64 temp_f1_2740;
    f64 temp_f2_2249;
    s32 temp_r0_1041;
    s32 temp_r28_2647;
    s32 temp_r29_1403;
    s32 temp_r29_1739;
    s32 var_r24_2650;
    s32 var_r25_2640;
    s32 var_r26_1238;
    s32 var_r26_1414;
    s32 var_r26_1750;
    s32 var_r28_1141;
    s32 var_r28_2072;
    s32 var_r29_1143;
    s32 var_r31_2073;
    s32 var_r3_2323;
    u8 var_r27_2370;
    void *temp_r26_1147;
    void *temp_r26_2080;
    void *temp_r28_2371;
    void *temp_r3_1148;
    void *temp_r3_2346;
    void *temp_r3_2424;
    void *temp_r3_2458;
    void *temp_r3_2491;
    void *temp_r4_1167;
    void *temp_r4_2087;
    void *temp_r5_2082;
    void *temp_r6_1154;

    this->unk100 -= gUpdateTimeDelta;
    if ((u8) this->unk2F1 == 0) {
        temp_f3_860 = this->unkF8;
        if (temp_f3_860 >= 0.0f) {
            this->unkF8 = temp_f3_860 + gUpdateTimeDelta;
            temp_f1_869 = this->unkF8;
            if (temp_f1_869 < 1.0f) {
                this->unkFC = 0.0f;
                temp_f3_873 = this->unkF8;
                if ((temp_f3_873 > 0.0f) && (temp_f3_873 <= 0.5f)) {
                    this->unkFC = (2.0f * temp_f3_873 * 0.0625f) + 0.0f;
                } else if ((temp_f3_873 > 0.5f) && (temp_f3_873 <= 0.75f)) {
                    this->unkFC = (4.0f * (temp_f3_873 - 0.5f) * 0.0625f) + 0.0625f;
                } else if ((temp_f3_873 > 0.75f) && (temp_f3_873 <= 0.875f)) {
                    this->unkFC = (8.0f * (temp_f3_873 - 0.75f) * 0.125f) + 0.125f;
                } else if ((temp_f3_873 > 0.875f) && (temp_f3_873 <= 1.0f)) {
                    this->unkFC = (8.0f * (temp_f3_873 - 0.875f) * 0.25f) + 0.25f;
                }
                temp_f20_932 = this->unkFC;
                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(temp_f20_932, temp_f20_932, 0.033f, 0, 4.0f, 0U);
            } else if ((temp_f1_869 >= 5.1f) && (temp_f1_869 <= 5.4f) && ((u8) this->unk2F0 == 0)) {
                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.6f, 0.0f, 0.05f, 0, 4.0f, 0U);
            } else if ((temp_f1_869 >= 6.1f) && (temp_f1_869 <= 6.4f) && ((u8) this->unk2F0 == 0)) {
                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.0f, 0.4f, 0.05f, 0, 4.0f, 0U);
            } else if ((temp_f1_869 >= 7.0f) && (temp_f1_869 <= 7.4f) && ((u8) this->unk2F0 == 0)) {
                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.3f, 0.0f, 0.05f, 0, 4.0f, 0U);
            } else if (temp_f1_869 > 7.4f) {
                this->unkF8 = -1.0f;
            }
        }
    }
    if ((s32) this->unk104 != 0) {
        UpdateDragons();
    }
    temp_r0_1041 = this->unk104;
    if ((u32) temp_r0_1041 <= 6U) {
        switch (temp_r0_1041) {
            return;
        case 1:
            if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && ((u8) this->unk2F1 == 0)) {
                var_f20_1061 = this->unk100;
                if (var_f20_1061 < 1.0f) {

                } else {
                    var_f20_1061 = 1.0f;
                }
                if (var_f20_1061 > 0.0f) {

                } else {
                    var_f20_1061 = 0.0f;
                }
                sp874 = 0;
                temp_f1_1081 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                sp870 = 0x458;
                sp878 = temp_f1_1081 + (0.017453292f * (30.0f * (1.0f - var_f20_1061)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp870, 30.0f, 0.017453292f);
            }
            if (this->unk100 <= 0.0f) {
                this->unk104 = 2;
                this->unk100 = 0.25f;
                gb.unk2CC.Disable(this->unk2E8);
                this->unk2E8 = -1;
                this->unkD0 = 0.05f;
                this->unkD4 = 1.0f;
                this->unkD8 = 0.05f;
                if ((u8) this->unk2F1 != 0) {
                    KDSound_Play3d(GS_CynderFuryBuildUp2, (MKVector3 *) &this->unk90.unk30, 0U, -1, 0.0f, 0U);
                }
                temp_r4_1131 = this->unkE8;
                if (temp_r4_1131 != NULL) {
                    ((LightManager *) gb.unk80)->EnableLight(temp_r4_1131, 1U);
                }
                var_r28_1141 = 0;
                var_r29_1143 = 0;
                do {
                    temp_r26_1147 = this + var_r29_1143;
                    temp_r3_1148 = M2C_FIELD(temp_r26_1147, void **, 0x130);
                    M2C_FIELD(M2C_FIELD(temp_r3_1148, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_1148);
                    temp_r6_1154 = M2C_FIELD(temp_r26_1147, void **, 0x130);
                    M2C_FIELD(temp_r6_1154, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r6_1154, u8 *, 0xA0) & ~0x80) | ((lit_845 << 7) & 0x80));
                    temp_r4_1167 = M2C_FIELD(temp_r26_1147, void **, 0x130);
                    M2C_FIELD(temp_r4_1167, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_1167, u8 *, 0xA0) | 0x40);
                    M2C_FIELD(temp_r26_1147, f32 *, 0x110) = (f32) (6.2831855f / (f32) (var_r28_1141 + 1));
                    M2C_FIELD(temp_r26_1147, f32 *, 0x114) = 3.7699115f;
                    M2C_FIELD(temp_r26_1147, f32 *, 0x118) = MKRand_Float((int *) &gViewSeed, 0.0f, 10000.0f);
                    var_r28_1141 += 1;
                    M2C_FIELD(temp_r26_1147, f32 *, 0x11C) = MKRand_Float((int *) &gViewSeed, 0.0f, 10000.0f);
                    var_r29_1143 += 0x80;
                } while (var_r28_1141 < 3);
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    sp8E4 = 0;
                    MKVector(1.0f, 1.0f, 1.0f);
                    sp160 = sp7F0 * 5.56078426e-315;
                    sp8E0 = 0x417;
                    sp8E8 = sp160;
                    sp168 = sp7F8 * 150.0f;
                    sp8F8 = 1;
                    sp8F0 = (f64) sp168;
                    sp800 = sp160;
                    sp808 = (f64) sp168;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8E0, sp160);
                }
                sp360 = 1.0f;
                sp364 = 1.0f;
                sp368 = 1.0f;
                sp36C = 1.0f;
                sp7E0 = (f64) sp360;
                sp7E8 = (f64) sp368;
                MKModel_SetColor(this->unkF0, *((MKVector4 *) &sp7E0));
                return;
            }
            break;
        case 2:
            var_r26_1238 = 0;
            gb.unkD0 = 1;
            do {
                gb.unkB8.AddRandomWobbleForce(1.0f);
                var_r26_1238 += 1;
            } while (var_r26_1238 < 5);
            MKVector(3.0f, 5.0f, 3.0f);
            MKVector(6.0f, 0.0f, 6.0f);
            sp7A0.operator*(gUpdateTimeDelta);
            temp_f0_1265 = (f64) M2C_FIELD(this, f32 *, 0xD0) + M2C_BITWISE(f64, sp7A0);
            sp70 = temp_f0_1265;
            sp7B0 = temp_f0_1265;
            sp78 = this->unkD8 + sp7A0.unk8;
            sp7B8 = (f64) sp78;
            MKVector(0.0f, 0.0f, 0.0f);
            Min(sp150, *((MKVector3 *) &sp7B0));
            Max(sp7D0, sp150);
            M2C_FIELD(this, f32 *, 0xD0) = M2C_BITWISE(f64, sp7D0);
            M2C_FIELD(this, f32 *, 0xD8) = (f64) sp7D0.unk8;
            if (this->unk100 <= 0.0f) {
                this->unk100 = 1.5f;
                if ((u8) this->unk2F1 != 0) {
                    this->unk100 -= 0.3f;
                }
                this->unk104 += 1;
                if (((u8) this->unk2F0 == 0) && ((u8) this->unk2F1 == 0)) {
                    ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.5f, 0.5f, 0.33f, 0, 4.0f, 0U);
                }
                temp_r4_1331 = this->unkF4;
                if (temp_r4_1331 != NULL) {
                    temp_r4_1331->unk31 |= 0x40;
                    this->unkF4->unk24 = 0.0f;
                    temp_r3_1342 = this->unkF4;
                    temp_r3_1342->unk2C += 2.0f * gUpdateTimeDelta;
                    return;
                }
            } else {
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    sp8C4 = 0;
                    temp_f20_1360 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    temp_f21_1365 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f21_1365, temp_f20_1360);
                    sp140 = sp760 * 5.398241246e-315;
                    sp8C0 = 0x417;
                    sp8C8 = sp140;
                    sp148 = sp768 * 10.0f;
                    sp8D8 = 1;
                    sp8D0 = (f64) sp148;
                    sp770 = sp140;
                    sp778 = (f64) sp148;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8C0, sp140);
                }
                temp_r29_1403 = MKRand_Int((int *) &gViewSeed, 0xF, 0x1E);
                var_r26_1414 = 0;
                temp_f23_1419 = 6.2831855f / (f32) (temp_r29_1403 - 1);
loop_71:
                if (var_r26_1414 < temp_r29_1403) {
                    temp_f30_1424 = this->unkD0;
                    temp_f22_1431 = (f32) var_r26_1414 * temp_f23_1419;
                    temp_f20_1433 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                    temp_f21_1440 = -_table_sinf(1.5707964f + temp_f22_1431) * temp_f20_1433;
                    temp_f20_1442 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                    temp_f1_1445 = _table_sinf(temp_f22_1431) * temp_f20_1442;
                    sp358 = temp_f21_1440;
                    sp350 = temp_f1_1445;
                    sp354 = 0.0f;
                    sp738 = (f64) sp358;
                    sp730 = (f64) sp350;
                    temp_f0_1455 = sp730 * 5.61841903e-315;
                    sp340 = temp_f0_1455;
                    sp740 = temp_f0_1455;
                    sp348 = (f32) sp738 * 400.0f;
                    sp748 = (f64) sp348;
                    temp_f0_1465 = temp_f0_1455 * (f64) temp_f30_1424;
                    sp330 = temp_f0_1465;
                    sp750 = temp_f0_1465;
                    sp338 = (f32) sp748 * temp_f30_1424;
                    sp758 = (f64) sp338;
                    temp_f0_1476 = M2C_FIELD(this, f64 *, 0xC0) + temp_f0_1465;
                    sp320 = temp_f0_1476;
                    sp860 = temp_f0_1476;
                    sp328 = this->unk90.unk38 + (f32) sp758;
                    sp868 = (f64) sp328;
                    if ((u8) this->unk2F1 == 0) {
                        temp_f21_1493 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.2f);
                        temp_f20_1498 = MKRand_Float((int *) &gViewSeed, 0.6f, 0.8f);
                        sp300 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        sp304 = temp_f20_1498;
                        sp308 = temp_f21_1493;
                        sp30C = 1.0f;
                        sp710 = (f64) sp300;
                        sp718 = (f64) sp308;
                        sp24 = MKRand_Float((int *) &gViewSeed, 3.0f, 6.0f);
                        sp314 = MKRand_Float((int *) &gViewSeed, 100.0f, 700.0f);
                        sp310 = 0.0f;
                        sp318 = 0.0f;
                        sp720 = (f64) sp310;
                        sp728 = (f64) sp318;
                        ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp860), *((MKVector3 *) &sp720), sp24, *((MKVector4 *) &sp710), 100.0f);
                    } else {
                        temp_f20_1542 = MKRand_Float((int *) &gViewSeed, 0.3f, 1.9f);
                        sp2E4 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.2f);
                        sp2E0 = 1.0f;
                        sp2E8 = temp_f20_1542;
                        sp2EC = 1.0f;
                        sp6F0 = (f64) sp2E0;
                        sp6F8 = (f64) sp2E8;
                        sp20 = MKRand_Float((int *) &gViewSeed, 3.0f, 6.0f);
                        sp2F4 = MKRand_Float((int *) &gViewSeed, 100.0f, 700.0f);
                        sp2F0 = 0.0f;
                        sp2F8 = 0.0f;
                        sp700 = (f64) sp2F0;
                        sp708 = (f64) sp2F8;
                        ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp860), *((MKVector3 *) &sp700), sp20, *((MKVector4 *) &sp6F0), 100.0f);
                    }
                    var_r26_1414 += 1;
                    goto loop_71;
                }
                return;
            }
            break;
        case 3:
            MKVector(5.0f, 50.0f, 5.0f);
            MKVector(-1.0f, 4.0f, -1.0f);
            sp6B0.operator*(gUpdateTimeDelta);
            temp_f0_1604 = (f64) M2C_FIELD(this, f32 *, 0xD0) + M2C_BITWISE(f64, sp6B0);
            sp60 = temp_f0_1604;
            sp6C0 = temp_f0_1604;
            sp68 = this->unkD8 + sp6B0.unk8;
            sp6C8 = (f64) sp68;
            MKVector(0.1f, 0.0f, 0.1f);
            Min(sp130, *((MKVector3 *) &sp6C0));
            Max(sp6E0, sp130);
            M2C_FIELD(this, f32 *, 0xD0) = M2C_BITWISE(f64, sp6E0);
            M2C_FIELD(this, f32 *, 0xD8) = (f64) sp6E0.unk8;
            temp_r4_1631 = this->unkF4;
            if (temp_r4_1631 != NULL) {
                temp_r4_1631->unk24 = this->unkD4;
                MKVector(0.0f, 75.0f * this->unkD4, 0.0f);
                temp_f0_1646 = M2C_FIELD(this, f64 *, 0xC0) + sp670;
                sp120 = temp_f0_1646;
                temp_r3_1652 = this->unkF4;
                temp_r3_1652->unk0 = temp_f0_1646;
                sp128 = this->unk90.unk38 + sp678;
                sp680 = temp_f0_1646;
                temp_r3_1652->unk8 = (f64) sp128;
                temp_r3_1659 = this->unkF4;
                sp688 = (f64) sp128;
                temp_r3_1659->unk2C += 2.0f * gUpdateTimeDelta;
            }
            if (this->unk100 <= 0.0f) {
                if ((u8) this->unk2F0 != 0) {
                    this->unk100 = 3.0f;
                } else {
                    this->unk100 = 0.2f;
                }
                this->unk104 += 1;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp8A4 = 0;
                temp_f20_1696 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f21_1701 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f21_1701, temp_f20_1696);
                sp110 = sp650 * 5.398241246e-315;
                sp8A0 = 0x417;
                sp8A8 = sp110;
                sp118 = sp658 * 10.0f;
                sp8B8 = 1;
                sp8B0 = (f64) sp118;
                sp660 = sp110;
                sp668 = (f64) sp118;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8A0, sp110);
            }
            temp_r29_1739 = MKRand_Int((int *) &gViewSeed, 0xF, 0x1E);
            var_r26_1750 = 0;
            temp_f23_1755 = 6.2831855f / (f32) (temp_r29_1739 - 1);
loop_87:
            if (var_r26_1750 < temp_r29_1739) {
                temp_f30_1760 = this->unkD0;
                temp_f22_1767 = (f32) var_r26_1750 * temp_f23_1755;
                temp_f20_1769 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                temp_f21_1776 = -_table_sinf(1.5707964f + temp_f22_1767) * temp_f20_1769;
                temp_f20_1778 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                temp_f1_1781 = _table_sinf(temp_f22_1767) * temp_f20_1778;
                sp2D8 = temp_f21_1776;
                sp2D0 = temp_f1_1781;
                sp2D4 = 0.0f;
                sp628 = (f64) sp2D8;
                sp620 = (f64) sp2D0;
                temp_f0_1791 = sp620 * 5.676053805e-315;
                sp2C0 = temp_f0_1791;
                sp630 = temp_f0_1791;
                sp2C8 = (f32) sp628 * 1000.0f;
                sp638 = (f64) sp2C8;
                temp_f0_1801 = temp_f0_1791 * (f64) temp_f30_1760;
                sp2B0 = temp_f0_1801;
                sp640 = temp_f0_1801;
                sp2B8 = (f32) sp638 * temp_f30_1760;
                sp648 = (f64) sp2B8;
                temp_f0_1812 = M2C_FIELD(this, f64 *, 0xC0) + temp_f0_1801;
                sp2A0 = temp_f0_1812;
                sp850 = temp_f0_1812;
                sp2A8 = this->unk90.unk38 + (f32) sp648;
                sp858 = (f64) sp2A8;
                if ((u8) this->unk2F1 == 0) {
                    temp_f21_1829 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.2f);
                    temp_f20_1834 = MKRand_Float((int *) &gViewSeed, 0.6f, 0.8f);
                    sp280 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                    sp284 = temp_f20_1834;
                    sp288 = temp_f21_1829;
                    sp28C = 1.0f;
                    sp600 = (f64) sp280;
                    sp608 = (f64) sp288;
                    sp1C = MKRand_Float((int *) &gViewSeed, 3.0f, 6.0f);
                    sp294 = MKRand_Float((int *) &gViewSeed, 100.0f, 700.0f);
                    sp290 = 0.0f;
                    sp298 = 0.0f;
                    sp610 = (f64) sp290;
                    sp618 = (f64) sp298;
                    ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp850), *((MKVector3 *) &sp610), sp1C, *((MKVector4 *) &sp600), 100.0f);
                } else {
                    temp_f20_1878 = MKRand_Float((int *) &gViewSeed, 0.3f, 1.9f);
                    sp264 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.2f);
                    sp260 = 1.0f;
                    sp268 = temp_f20_1878;
                    sp26C = 1.0f;
                    sp5E0 = (f64) sp260;
                    sp5E8 = (f64) sp268;
                    sp18 = MKRand_Float((int *) &gViewSeed, 3.0f, 6.0f);
                    sp274 = MKRand_Float((int *) &gViewSeed, 100.0f, 700.0f);
                    sp270 = 0.0f;
                    sp278 = 0.0f;
                    sp5F0 = (f64) sp270;
                    sp5F8 = (f64) sp278;
                    ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp850), *((MKVector3 *) &sp5F0), sp18, *((MKVector4 *) &sp5E0), 100.0f);
                }
                var_r26_1750 += 1;
                goto loop_87;
            }
            return;
        case 4:
            if ((u8) this->unk2F0 != 0) {
                MKVector(5.0f, 50.0f, 5.0f);
                MKVector(-2.0f, 0.0f, -2.0f);
                sp5A0.operator*(gUpdateTimeDelta);
                temp_f0_1943 = (f64) M2C_FIELD(this, f32 *, 0xD0) + M2C_BITWISE(f64, sp5A0);
                sp50 = temp_f0_1943;
                sp5B0 = temp_f0_1943;
                sp58 = this->unkD8 + sp5A0.unk8;
                sp5B8 = (f64) sp58;
                MKVector(0.05f, 0.0f, 0.05f);
                Min(sp100, *((MKVector3 *) &sp5B0));
                Max(sp5D0, sp100);
                M2C_FIELD(this, f32 *, 0xD0) = M2C_BITWISE(f64, sp5D0);
                M2C_FIELD(this, f32 *, 0xD8) = (f64) sp5D0.unk8;
            } else {
                MKVector(5.0f, 50.0f, 5.0f);
                MKVector(-2.0f, -3.0f, -2.0f);
                sp540.operator*(gUpdateTimeDelta);
                temp_f0_1989 = (f64) M2C_FIELD(this, f32 *, 0xD0) + M2C_BITWISE(f64, sp540);
                sp40 = temp_f0_1989;
                sp550 = temp_f0_1989;
                sp48 = this->unkD8 + sp540.unk8;
                sp558 = (f64) sp48;
                MKVector(0.05f, 0.0f, 0.05f);
                Min(spF0, *((MKVector3 *) &sp550));
                Max(sp570, spF0);
                M2C_FIELD(this, f32 *, 0xD0) = M2C_BITWISE(f64, sp570);
                M2C_FIELD(this, f32 *, 0xD8) = (f64) sp570.unk8;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp884 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                spE0 = sp500 * 5.634608575e-315;
                sp880 = 0x417;
                sp888 = spE0;
                spE8 = sp508 * 500.0f;
                sp898 = 1;
                sp890 = (f64) spE8;
                sp510 = spE0;
                sp518 = (f64) spE8;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp880, spE0);
            }
            temp_r3_2054 = this->unkF4;
            if (temp_r3_2054 != NULL) {
                temp_r3_2054->unk24 = this->unkD4;
                temp_r3_2060 = this->unkF4;
                temp_r3_2060->unk2C += 2.0f * gUpdateTimeDelta;
            }
            if (this->unk100 <= 0.0f) {
                var_r28_2072 = 0;
                var_r31_2073 = 0;
                this->unk100 = 0.6f;
                this->unk104 += 1;
                do {
                    temp_r26_2080 = this + var_r31_2073;
                    temp_r5_2082 = M2C_FIELD(temp_r26_2080, void **, 0x130);
                    M2C_FIELD(temp_r5_2082, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r5_2082, u8 *, 0xA0) & ~0x80) | ((lit_910 << 7) & 0x80));
                    temp_r4_2087 = M2C_FIELD(temp_r26_2080, void **, 0x130);
                    M2C_FIELD(temp_r4_2087, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_2087, u8 *, 0xA0) & ~0x40);
                    KDSound_Stop(((u8 *) temp_r26_2080) + 0x134);
                    KDSound_Stop(((u8 *) temp_r26_2080) + 0x15C);
                    var_r28_2072 += 1;
                    var_r31_2073 += 0x80;
                } while (var_r28_2072 < 3);
                temp_r4_2098 = this->unkF4;
                if (temp_r4_2098 != NULL) {
                    temp_r4_2098->unk31 &= ~0x40;
                }
                sp250 = 1.0f;
                sp254 = 1.0f;
                sp258 = 1.0f;
                sp25C = 1.0f;
                sp4F0 = (f64) sp250;
                sp4F8 = (f64) sp258;
                gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp4F0), 3.0f * gUpdateTimeDelta);
                if (((u8) this->unk2F0 == 0) && ((u8) this->unk2F1 == 0)) {
                    ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.99f, 0.99f, 0.66f, 0, 4.0f, 0U);
                }
                if ((u8) this->unk2F1 != 0) {
                    ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.99f, 0.99f, 0.66f, (MKVector3 *) &this->unk90.unk30, 50.0f, 0, 4.0f, 1U);
                }
                M2C_STRUCT_COPY((s32) &sp8FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp248 = 1.0f;
                sp238 = 0.0f;
                sp240 = 0.0f;
                sp244 = 0.0f;
                sp230 = 0.0f;
                sp234 = -1.0f;
                sp840 = (f64) sp240;
                sp848 = (f64) sp248;
                sp4E0 = (f64) sp230;
                sp4E8 = (f64) sp238;
                KDMath_BuildMatrixFromFwd(&sp900, *((MKVector3 *) &sp4E0), (MKVector3 *) &sp840);
                spD8 = 2.0f;
                spD0 = 2.0f;
                spD4 = 2.0f;
                sp4D8 = (f64) spD8;
                sp4D0 = (f64) spD0;
                sp900.Scale3x3(&sp900, *((MKVector3 *) &sp4D0));
                MKVector(0.0f, 300.0f, 0.0f);
                spC0 = M2C_FIELD(this, f64 *, 0xC0) + sp4B0;
                sp4C0 = spC0;
                spC8 = this->unk90.unk38 + sp4B8;
                sp4C8 = (f64) spC8;
                sp900.unk30 = (f32) sp4C0;
                sp900.unk34 = (*(f32 *) ((u8 *) &sp4C0 + 0x4));
                sp900.unk38 = (f32) sp4C8;
                sp900.unk3C = 1.0f;
                gb.unk1C0.StartWarp(&sp900);
                if ((u8) this->unk2F1 == 0) {
                    this->unk290.unk50 = 0;
                    temp_f2_2249 = M2C_FIELD(this, f64 *, 0xC0);
                    M2C_FIELD(this, f64 *, 0x2A0) = temp_f2_2249;
                    M2C_FIELD(this, f64 *, 0x2A8) = (f64) M2C_FIELD(this, f32 *, 0xC8);
                    M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f32 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unk290, 0, 0, &this->unk290.unk10, 1, 3000.0f, temp_f2_2249);
                } else {
                    sp944 = 0;
                    spB8 = 0.0f;
                    spB0 = 0.0f;
                    spB4 = 0.0f;
                    sp4A8 = (f64) spB8;
                    sp4A0 = (f64) spB0;
                    sp940 = 7;
                    sp968 = this->unk2EC;
                    sp96C = 0;
                    sp948 = (f64) spB0;
                    sp950 = (f64) spB8;
                    sp980 = 1;
                    sp98C = 2;
                    sp988 = 1000.0f;
                    sp981 = 0;
                    sp982 = 0;
                    sp984 = -1;
                    sp958 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                    sp960 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                    sp990 = 0;
                    sp970 = 0.0f;
                    sp974 = 0.0f;
                    sp978 = 0.0f;
                    sp991 = 0;
                    M2C_FIELD(M2C_FIELD(gb.unk0->GetProp(), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp940);
                }
                var_r3_2323 = GS_SpyroFuryAttack2;
                if ((u8) this->unk2F1 != 0) {
                    var_r3_2323 = GS_CynderFuryImpact;
                }
                KDSound_Play3d(var_r3_2323, (MKVector3 *) &this->unk290.unk10, 0U, -1, 0.0f, 0U);
                KDSound_Play3d(GS_Rumble1, (MKVector3 *) &this->unk290.unk10, 0U, -1, 0.0f, 0U);
                temp_r3_2341 = this->unkE8;
                if (temp_r3_2341 != NULL) {
                    temp_r3_2341->unk38 = 10000.0f;
                    temp_r3_2346 = temp_r3_2341->unk3C;
                    if (temp_r3_2346 != NULL) {
                        M2C_FIELD(temp_r3_2346, f32 *, 0x20) = 10000.0f;
                        M2C_FIELD(temp_r3_2346, f32 *, 0x24) = 1e8f;
                        M2C_FIELD(temp_r3_2346, f32 *, 0x28) = 0.0001f;
                        M2C_FIELD(temp_r3_2346, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2346, f32 *, 0x24));
                    }
                }
                this->unk2E8 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
                var_r27_2370 = 0;
                temp_r28_2371 = gb.unkC;
                temp_r3_2372 = M2C_FIELD(temp_r28_2371, KDSynkerPlayer3 **, 0x78);
                if (((temp_r3_2372 != NULL) && (temp_r3_2372->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_2371, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r28_2371) + 0x24))->GetState() == 2))) {
                    var_r27_2370 = 1;
                }
                if ((var_r27_2370 == 0) && ((u8) this->unk2F1 == 0)) {
                    gb.GetSpyro();
                    ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetRage(0, 15.0f);
                }
            }
            if ((ManagedLight *) this->unkE8 != NULL) {
                MKVector(0.0f, 500.0f, 0.0f);
                spA0 = M2C_FIELD(this, f64 *, 0xC0) + sp480;
                temp_r3_2418 = this->unkE8;
                sp490 = spA0;
                spA8 = this->unk90.unk38 + sp488;
                temp_r3_2418->unk10 = spA0;
                temp_r3_2418->unk18 = (f64) spA8;
                temp_r3_2424 = temp_r3_2418->unk3C;
                sp498 = (f64) spA8;
                if (temp_r3_2424 != NULL) {
                    M2C_FIELD(temp_r3_2424, f64 *, 0x10) = spA0;
                    M2C_FIELD(temp_r3_2424, f64 *, 0x18) = (f64) spA8;
                    return;
                }
            }
            break;
        case 5:
            var_f27_2435 = this->unk100 / 0.6f;
            if (var_f27_2435 < 1.0f) {

            } else {
                var_f27_2435 = 1.0f;
            }
            if (var_f27_2435 > 0.0f) {

            } else {
                var_f27_2435 = 0.0f;
            }
            temp_r3_2449 = this->unkE8;
            if (temp_r3_2449 != NULL) {
                temp_f4_2454 = 1.0f - var_f27_2435;
                temp_f1_2456 = (4000.0f * temp_f4_2454) + 10000.0f;
                temp_r3_2449->unk38 = temp_f1_2456;
                temp_r3_2458 = temp_r3_2449->unk3C;
                if (temp_r3_2458 != NULL) {
                    M2C_FIELD(temp_r3_2458, f32 *, 0x20) = temp_f1_2456;
                    M2C_FIELD(temp_r3_2458, f32 *, 0x24) = (f32) (temp_f1_2456 * temp_f1_2456);
                    M2C_FIELD(temp_r3_2458, f32 *, 0x28) = (f32) (1.0f / temp_f1_2456);
                    M2C_FIELD(temp_r3_2458, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2458, f32 *, 0x24));
                }
                MKVector(0.0f, 17000.0f * temp_f4_2454, 0.0f);
                sp90 = M2C_FIELD(this, f64 *, 0xC0) + sp460;
                temp_r3_2485 = this->unkE8;
                sp470 = sp90;
                sp98 = this->unk90.unk38 + sp468;
                temp_r3_2485->unk10 = sp90;
                temp_r3_2485->unk18 = (f64) sp98;
                temp_r3_2491 = temp_r3_2485->unk3C;
                sp478 = (f64) sp98;
                if (temp_r3_2491 != NULL) {
                    M2C_FIELD(temp_r3_2491, f64 *, 0x10) = sp90;
                    M2C_FIELD(temp_r3_2491, f64 *, 0x18) = (f64) sp98;
                }
            }
            MKVector(500.0f, 500.0f, 500.0f);
            MKVector(20.0f, -10.0f, 20.0f);
            sp420.operator*(gUpdateTimeDelta);
            temp_f0_2515 = (f64) M2C_FIELD(this, f32 *, 0xD0) + M2C_BITWISE(f64, sp420);
            sp30 = temp_f0_2515;
            sp430 = temp_f0_2515;
            sp38 = this->unkD8 + sp420.unk8;
            sp438 = (f64) sp38;
            MKVector(0.1f, 0.0f, 0.1f);
            Min(sp80, *((MKVector3 *) &sp430));
            Max(sp450, sp80);
            M2C_FIELD(this, f32 *, 0xD0) = M2C_BITWISE(f64, sp450);
            M2C_FIELD(this, f32 *, 0xD8) = (f64) sp450.unk8;
            if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && (var_f27_2435 <= 0.5f) && ((u8) this->unk2F1 == 0)) {
                sp834 = 0;
                temp_f1_2559 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                sp830 = 0x458;
                sp838 = temp_f1_2559 + (0.017453292f * (30.0f * (var_f27_2435 / 0.5f)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp830, 30.0f, 0.017453292f);
            }
            if (this->unk100 <= 0.0f) {
                this->unk104 = 6;
                this->unk100 = 1.4f;
                temp_r4_2586 = this->unkE8;
                if (temp_r4_2586 != NULL) {
                    ((LightManager *) gb.unk80)->EnableLight(temp_r4_2586, 0U);
                }
                if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && ((u8) this->unk2F1 == 0)) {
                    sp2C = 0;
                    sp28 = 0x459;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp28);
                }
                gb.unk2CC.Disable(this->unk2E8);
                this->unk2E8 = -1;
            }
            sp210 = var_f27_2435;
            sp214 = var_f27_2435;
            sp218 = var_f27_2435;
            sp21C = 1.0f;
            sp3F0 = (f64) sp210;
            sp3F8 = (f64) sp218;
            MKModel_SetColor(this->unkF0, *((MKVector4 *) &sp3F0));
            var_r25_2640 = 0;
            do {
                temp_r28_2647 = MKRand_Int((int *) &gViewSeed, 0xF, 0x1E);
                var_r24_2650 = 0;
                temp_f22_2654 = 6.2831855f / (f32) temp_r28_2647;
loop_156:
                if (var_r24_2650 < temp_r28_2647) {
                    temp_f19_2670 = (f32) var_r24_2650 * (temp_f22_2654 + MKRand_Float((int *) &gViewSeed, -0.2f, 0.2f));
                    temp_f20_2672 = MKRand_Float((int *) &gViewSeed, 0.4f, 1.0f);
                    temp_f21_2679 = -_table_sinf(1.5707964f + temp_f19_2670) * temp_f20_2672;
                    temp_f20_2681 = MKRand_Float((int *) &gViewSeed, 0.4f, 1.0f);
                    temp_f2_2684 = _table_sinf(temp_f19_2670) * temp_f20_2681;
                    sp208 = temp_f21_2679;
                    sp200 = temp_f2_2684;
                    sp204 = 0.0f;
                    sp828 = (f64) sp208;
                    sp820 = (f64) sp200;
                    temp_f1_2696 = 150.0f + MKRand_Float((int *) &gViewSeed, -100.0f, 350.0f);
                    sp1C8 = 0.0f;
                    temp_f26_2698 = this->unkD0;
                    sp1C0 = 0.0f;
                    sp1C4 = temp_f1_2696;
                    sp3B8 = (f64) sp1C8;
                    sp3B0 = (f64) sp1C0;
                    sp1F0 = sp820 * 5.5769738e-315;
                    sp3C0 = sp1F0;
                    sp1F8 = (f32) sp828 * 200.0f;
                    sp3C8 = (f64) sp1F8;
                    temp_f1_2717 = sp1F0 * (f64) temp_f26_2698;
                    sp1E0 = temp_f1_2717;
                    sp3D0 = temp_f1_2717;
                    sp1E8 = (f32) sp3C8 * temp_f26_2698;
                    sp3D8 = (f64) sp1E8;
                    temp_f1_2728 = M2C_FIELD(this, f64 *, 0xC0) + temp_f1_2717;
                    sp1D0 = temp_f1_2728;
                    sp3E0 = temp_f1_2728;
                    sp1D8 = this->unk90.unk38 + (f32) sp3D8;
                    sp3E8 = (f64) sp1D8;
                    temp_f1_2740 = sp3E0 + (f64) sp1C0;
                    sp1B0 = temp_f1_2740;
                    sp810 = temp_f1_2740;
                    sp1B8 = (f32) sp3E8 + (f32) sp3B8;
                    sp818 = (f64) sp1B8;
                    if ((u8) this->unk2F1 == 0) {
                        sp1A0 = sp820 * 5.676053805e-315;
                        sp1A8 = (f32) sp828 * 1000.0f;
                        sp3A0 = sp1A0;
                        sp3A8 = (f64) sp1A8;
                        sp14 = MKRand_Float((int *) &gViewSeed, 3.0f, 6.0f);
                        temp_f20_2772 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.2f);
                        temp_f21_2777 = MKRand_Float((int *) &gViewSeed, 0.6f, 0.8f);
                        sp190 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        sp194 = temp_f21_2777;
                        sp198 = temp_f20_2772;
                        sp19C = 1.0f;
                        sp390 = (f64) sp190;
                        sp398 = (f64) sp198;
                        ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp810), *((MKVector3 *) &sp3A0), sp14, *((MKVector4 *) &sp390), -400.0f);
                    } else {
                        sp180 = sp820 * 5.676053805e-315;
                        sp188 = (f32) sp828 * 1000.0f;
                        sp380 = sp180;
                        sp388 = (f64) sp188;
                        sp10 = MKRand_Float((int *) &gViewSeed, 3.0f, 6.0f);
                        temp_f21_2819 = MKRand_Float((int *) &gViewSeed, 0.3f, 1.9f);
                        sp174 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.2f);
                        sp170 = 1.0f;
                        sp178 = temp_f21_2819;
                        sp17C = 1.0f;
                        sp370 = (f64) sp170;
                        sp378 = (f64) sp178;
                        ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp810), *((MKVector3 *) &sp380), sp10, *((MKVector4 *) &sp370), -400.0f);
                    }
                    var_r24_2650 += 1;
                    goto loop_156;
                }
                var_r25_2640 += 1;
            } while (var_r25_2640 < 2);
            return;
        case 6:
            var_f0_2850 = this->unk100;
            if (var_f0_2850 < 1.4f) {

            } else {
                var_f0_2850 = 1.4f;
            }
            if (var_f0_2850 > 0.0f) {

            } else {
                var_f0_2850 = 0.0f;
            }
            this->unk100 = var_f0_2850;
            if (this->unk100 <= 0.0f) {
                this->unk104 = 0;
                gb.unkB8.unk18 = 0;
                gb.unk381 = 0;
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
f32 FuryFXFire::Resolve() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
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
    Corona *temp_r4_3009;
    ManagedLight *temp_r4_2975;
    s32 var_r28_3020;
    s32 var_r31_3021;
    void *temp_r29_3025;

    FuryFX::Resolve();
    sp50 = 0.0f;
    sp60 = 0.0f;
    sp38 = 1.0f;
    sp3C = 0.75f;
    sp40 = 1.0f;
    sp44 = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp98 = (f64) sp38;
    spA0 = (f64) sp40;
    spA8 = (f64) sp48;
    spB0 = (f64) sp50;
    spB8 = (f64) sp58;
    spC0 = (f64) sp60;
    this->unkE8 = ((LightManager *) gb.unk80)->AllocManagedLight(*((MKVector3 *) &spB8), *((MKVector3 *) &spA8), *((MKVector4 *) &sp98), 4000.0f, lit_761, lit_762);
    temp_r4_2975 = this->unkE8;
    if (temp_r4_2975 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_2975, 0U);
    }
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp30 = 0.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp78 = (f64) sp18;
    sp80 = (f64) sp20;
    sp88 = (f64) sp28;
    sp90 = (f64) sp30;
    this->unkF4 = ((Coronas *) gb.unk64)->Alloc(*((MKVector3 *) &sp88), *((MKVector4 *) &sp78), 1.0f, lit_766, lit_767);
    temp_r4_3009 = this->unkF4;
    if (temp_r4_3009 != NULL) {
        temp_r4_3009->unk31 &= ~0x40;
    }
    var_r28_3020 = 0;
    var_r31_3021 = 0;
    do {
        sp8 = 1.0f;
        temp_r29_3025 = this + var_r31_3021;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp68 = (f64) sp8;
        sp70 = (f64) sp10;
        ((ShapedTrailFX *) (M2C_FIELD(temp_r29_3025, ShapedTrailFX **, 0x130)))->InitData(this->unkEC, lit_774, "FX_367", lit_775, *((MKVector4 *) &sp68), 2.5f, 0U, 1.0f);
        ((KDSoundFader *) (((u8 *) temp_r29_3025) + 0x134))->Init(0.25f, 0.25f);
        ((KDSoundFader *) (((u8 *) temp_r29_3025) + 0x15C))->Init(0.25f, 0.25f);
        M2C_FIELD(temp_r29_3025, f32 *, 0x110) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r29_3025, f32 *, 0x114) = MKRand_Float((int *) &gViewSeed, 3.1415927f, 6.2831855f);
        M2C_FIELD(temp_r29_3025, f32 *, 0x118) = MKRand_Float((int *) &gViewSeed, 0.0f, 100.0f);
        var_r28_3020 += 1;
        M2C_FIELD(temp_r29_3025, f32 *, 0x11C) = MKRand_Float((int *) &gViewSeed, 0.0f, 100.0f);
        var_r31_3021 += 0x80;
    } while (var_r28_3020 < 3);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FuryFXFire::Init() {
    s32 var_r29_3123;
    s32 var_r31_3124;

    FuryFX::Init();
    SetDefaults();
    this->unkE0 = MKMaterial_Create("FX_FlameWall");
    this->unkE8 = NULL;
    this->unkF0 = MKModel_Create("Fx0019_FireFuryBlast", NULL, 2, NULL);
    this->unkF8 = -1.0f;
    this->unkFC = 0.0f;
    this->unkEC = MKModel_Create("IceShard", NULL, 2, NULL);
    var_r29_3123 = 0;
    var_r31_3124 = 0;
    do {
        ((MKSceneManager *) gMK)->CreatePropDeferred("ShapedTrailFX", this + (var_r31_3124 + 0x130));
        var_r29_3123 += 1;
        var_r31_3124 += 0x80;
    } while (var_r29_3123 < 3);
    this->unk2E8 = -1;
    this->unkE4 = MKMaterial_Create("fx_cynderFuryFlame");
}
#endif

void FuryFXFire_cpp::__sinit() {
    f32 temp_f0_3184;
    f64 temp_f1_3165;
    f64 temp_f1_3173;
    f64 temp_f3_3153;
    f64 temp_f4_3162;
    f64 temp_f4_3170;
    f64 temp_f8_3155;

    temp_f3_3153 = __frsqrte(2014000.0);
    temp_f8_3155 = __frsqrte(380000.0);
    temp_f4_3162 = 0.5 * temp_f3_3153 * -((2014000.0 * (temp_f3_3153 * temp_f3_3153)) - 3.0);
    temp_f1_3165 = 0.5 * temp_f8_3155 * -((380000.0 * (temp_f8_3155 * temp_f8_3155)) - 3.0);
    temp_f4_3170 = 0.5 * temp_f4_3162 * -((2014000.0 * (temp_f4_3162 * temp_f4_3162)) - 3.0);
    temp_f1_3173 = 0.5 * temp_f1_3165 * -((380000.0 * (temp_f1_3165 * temp_f1_3165)) - 3.0);
    temp_f0_3184 = (f32) (380000.0 * (0.5 * temp_f1_3173 * -((380000.0 * (temp_f1_3173 * temp_f1_3173)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_3170 * -((2014000.0 * (temp_f4_3170 * temp_f4_3170)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_3184;
}
