#include "spyro/source/LookAtProp.h"
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
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
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
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern GameGlobals gb;
static BoundingVolume volume;                       /* type too large by 0x10; unable to generate initializer: not enough data */

void LookAtProp::Message(MKMessage *arg0) {
    MKProp *var_r31_60;
    s32 temp_r0_47;

    temp_r0_47 = arg0->unk0;
    switch (temp_r0_47) {                           /* irregular */
    case 0xB5:
        gb.GetSpyro();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            var_r31_60 = this->unk4C;
            if (var_r31_60 != NULL) {

            } else {
                var_r31_60 = (MKProp *) this;
            }
            gb.GetSpyro();
            ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetForceLookAtTarget(var_r31_60);
        }
        break;
    case 0xB4:
        gb.GetSpyro();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            gb.GetSpyro();
            ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetForceLookAtTarget(NULL);
        }
        break;
    }
    MKProp::Message(arg0);
}

f32 LookAtProp::Resolve() {
    this->unk4C = checked_cast<MKProp *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk4C));
    MKProp::Resolve();
}

s32 LookAtProp::LoadDone() {
    this->unk8 = &this->unk50;
    M2C_STRUCT_COPY((s32) &this->unk4C + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
    this->unk50.SetRotationToNone();
    MKProp::LoadDone();
}

s32 LookAtProp::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadInt("PropID", (int *) &this->unk4C, 0) != 0);
}

void LookAtProp::Deinit() {
    MKProp::Deinit();
}

void LookAtProp::Init() {
    this->unk4C = NULL;
    MKProp::Init();
}

LookAtProp::LookAtProp() {
    this->unk4C = NULL;
}

void LookAtPropDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk1C = &volume;
}

void LookAtProp_cpp::__sinit() {
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f0_253;
    f64 temp_f1_284;
    f64 temp_f2_248;
    f64 temp_f4_255;
    f64 temp_f4_283;
    f64 temp_f5_250;
    f64 temp_f5_269;
    f64 temp_f9_267;

    temp_f2_248 = __frsqrte(2014000.0);
    temp_f5_250 = __frsqrte(380000.0);
    temp_f0_253 = temp_f2_248 * temp_f2_248;
    temp_f4_255 = temp_f5_250 * temp_f5_250;
    sp18 = -0.5f;
    sp20 = -0.5f;
    sp1C = -0.5f;
    sp10 = 1.0f;
    temp_f9_267 = 0.5 * temp_f2_248 * -((2014000.0 * temp_f0_253) - 3.0);
    M2C_FIELD(&volume, f64 *, 0) = (f64) sp18;
    temp_f5_269 = 0.5 * temp_f5_250 * -((380000.0 * temp_f4_255) - 3.0);
    sp8 = 1.0f;
    spC = 1.0f;
    M2C_FIELD(&volume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(&volume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(&volume, f64 *, 0x18) = (f64) sp10;
    temp_f4_283 = 0.5 * temp_f9_267 * -((2014000.0 * (temp_f9_267 * temp_f9_267)) - 3.0);
    temp_f1_284 = 0.5 * temp_f5_269 * -((380000.0 * (temp_f5_269 * temp_f5_269)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_283 * -((2014000.0 * (temp_f4_283 * temp_f4_283)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_284 * -((380000.0 * (temp_f1_284 * temp_f1_284)) - 3.0)));
}
