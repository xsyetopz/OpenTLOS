#include "spyro/source/CollapsibleProp.h"
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
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CollapsibleProp::State'
void CollapsibleProp::SetState(CollapsibleProp::State arg1) {
    switch ((s32) arg1) {                           /* irregular */
    case 0:
        this->unk80->SetAnim(M2C_FIELD(checked_cast<CollapsiblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x70), 1.0f, 0.0f, 0, -1);
        break;
    case 1:
        this->unk94 = 0.0f;
        break;
    case 2:
        this->unk80->SetAnim(M2C_FIELD(checked_cast<CollapsiblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x74), 1.0f, 0.0f, 0, -1);
        break;
    case 3:
        this->unk94 = 0.0f;
        break;
    case 4:
        this->unk80->SetAnim(M2C_FIELD(checked_cast<CollapsiblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x78), 1.0f, 0.0f, 0, -1);
        break;
    }
    this->unk90 = (s32) arg1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void CollapsibleProp::Message(MKMessage *arg0) {
    u8 sp10;
    s32 spC;
    s32 sp8;
    void **temp_r3_132;
    void *temp_r3_136;

    if ((s32) arg0->unk0 != 0x12) {

    } else if ((s32) this->unk90 == 0) {
        temp_r3_132 = arg0->unkC;
        temp_r3_136 = M2C_FIELD(*temp_r3_132, void *(**)(void **), 0x2C)(temp_r3_132);
        if (temp_r3_136 != NULL) {
            spC = 0;
            sp10 = 0;
            sp8 = 0x6F;
            M2C_FIELD(M2C_FIELD(temp_r3_136, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0);
            if (sp10 != 0) {
                SetState((CollapsibleProp::State) 1);
            }
        }
    }
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'GetHeroType(HeroInterface *, float)' does not match
void *CollapsibleProp::Update() {
    MKAnimScript *temp_r3_269;
    f32 temp_f1_188;
    f32 var_f0_225;
    s32 temp_r0_175;
    u8 var_r29_203;
    u8 var_r30_192;

    KDProp::Update();
    temp_r0_175 = this->unk90;
    switch (temp_r0_175) {                          /* irregular */
    case 1:
        temp_f1_188 = this->unk94;
        var_r30_192 = 0;
        this->unk94 = temp_f1_188 + gUpdateTimeDelta;
        if (gb.unk0->GetHeroType(temp_f1_188) == 0) {
            var_r29_203 = 1;
            gb.GetSpyro();
            if (((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->IsCharging() == 0) {
                gb.GetSpyro();
                if (((KDStateMachine<Spyro> *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x7C))->GetState() != 2) {
                    var_r29_203 = 0;
                }
            }
            if (var_r29_203 != 0) {
                var_r30_192 = 1;
            }
        }
        if (var_r30_192 != 0) {
            var_f0_225 = 0.075f;
        } else {
            var_f0_225 = 0.0f;
        }
        if (this->unk94 >= var_f0_225) {
            SetState((CollapsibleProp::State) 2);
        }
        break;
    case 2:
        if (this->unk80->unk2C & 1) {
            SetState((CollapsibleProp::State) 3);
        }
        break;
    case 3:
        this->unk94 += gUpdateTimeDelta;
        if (this->unk94 >= 5.0f) {
            SetState((CollapsibleProp::State) 4);
        }
        break;
    case 4:
        if (this->unk80->unk2C & 1) {
            SetState((CollapsibleProp::State) 0);
        }
        break;
    }
    temp_r3_269 = this->unk80;
    if (temp_r3_269 != NULL) {
        this->unkC8 = KDSound_Play3d(temp_r3_269, ((u8 *) this->unk8) + 0x30, 0U, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void CollapsibleProp::Reset() {
    KDProp::Reset();
    this->unk94 = 0.0f;
    SetState((CollapsibleProp::State) 0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 CollapsibleProp::LoadDone() {
    f64 sp10;
    f64 sp8;
    void *temp_r5_327;

    KDProp::LoadDone();
    this->unk98.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unk98.Show(1U);
    temp_r5_327 = this->unk8;
    sp8 = M2C_FIELD(temp_r5_327, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_327, f64 *, 0x38);
    this->unk98.unk28 = (*(f32 *) ((u8 *) &sp8 + 0x4)) - 500.0f;
    SetState((CollapsibleProp::State) 0);
}
#endif

void CollapsibleProp::Deinit() {
    s32 temp_r3_356;

    this->unk98.Deinit();
    temp_r3_356 = this->unkC8;
    if ((temp_r3_356 != 0) && (KDSound_IsVoicePlaying(temp_r3_356) != 0)) {
        KDSound_Stop((int *) &this->unkC8);
    }
    KDProp::Deinit();
}

void CollapsibleProp::Init() {
    KDProp::Init();
    this->unk94 = 0.0f;
    this->unkC8 = 0;
}

void CollapsiblePropDescriptor::LoadDone() {
    s8 *temp_r30_406;
    s8 *temp_r30_426;
    s8 *temp_r30_444;
    void *var_r3_418;
    void *var_r3_436;
    void *var_r3_454;

    KDPropDescriptor::LoadDone();
    this->unkC |= 0x80000;
    temp_r30_406 = this->unk34;
    if (temp_r30_406 != NULL) {
        if (((MKAnimScript *) temp_r30_406)->Exists("Idle") != 0) {
            var_r3_418 = ((MKAnimScript *) temp_r30_406)->GetAnim("Idle");
        } else {
            var_r3_418 = NULL;
        }
        this->unk70 = (s32) var_r3_418;
        temp_r30_426 = this->unk34;
        if (((MKAnimScript *) temp_r30_426)->Exists("Collapsing") != 0) {
            var_r3_436 = ((MKAnimScript *) temp_r30_426)->GetAnim("Collapsing");
        } else {
            var_r3_436 = NULL;
        }
        this->unk74 = (s32) var_r3_436;
        temp_r30_444 = this->unk34;
        if (((MKAnimScript *) temp_r30_444)->Exists("Rebuilding") != 0) {
            var_r3_454 = ((MKAnimScript *) temp_r30_444)->GetAnim("Rebuilding");
        } else {
            var_r3_454 = NULL;
        }
        this->unk78 = (s32) var_r3_454;
    }
}

void CollapsiblePropDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk70 = 0;
    this->unk74 = 0;
    this->unk78 = 0;
}

void CollapsibleProp_cpp::__sinit() {
    f32 temp_f0_529;
    f64 temp_f1_510;
    f64 temp_f1_518;
    f64 temp_f3_498;
    f64 temp_f4_507;
    f64 temp_f4_515;
    f64 temp_f8_500;

    temp_f3_498 = __frsqrte(2014000.0);
    temp_f8_500 = __frsqrte(380000.0);
    temp_f4_507 = 0.5 * temp_f3_498 * -((2014000.0 * (temp_f3_498 * temp_f3_498)) - 3.0);
    temp_f1_510 = 0.5 * temp_f8_500 * -((380000.0 * (temp_f8_500 * temp_f8_500)) - 3.0);
    temp_f4_515 = 0.5 * temp_f4_507 * -((2014000.0 * (temp_f4_507 * temp_f4_507)) - 3.0);
    temp_f1_518 = 0.5 * temp_f1_510 * -((380000.0 * (temp_f1_510 * temp_f1_510)) - 3.0);
    temp_f0_529 = (f32) (380000.0 * (0.5 * temp_f1_518 * -((380000.0 * (temp_f1_518 * temp_f1_518)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_515 * -((2014000.0 * (temp_f4_515 * temp_f4_515)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_529;
}
