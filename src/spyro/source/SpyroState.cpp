#include "spyro/source/SpyroState.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
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
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;

#if 0 // DRAFT: illegal type
s32 SpyroStateMachine::GetMedium(int arg0) {
    if ((arg0 >= 0) && (arg0 < (s32) this->unk10)) {
        return M2C_FIELD(*(this->unk4 + (arg0 * 4)), s32 *, 0xC);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
void SpyroStateMachine::ProcessAnimEvent(unsigned int arg0) {
    s32 temp_r0_32;
    void **temp_r3_37;

    temp_r0_32 = this->unk8;
    if (temp_r0_32 >= 0) {
        temp_r3_37 = *(this->unk4 + (temp_r0_32 * 4));
        M2C_FIELD(*temp_r3_37, M2C_UNK (**)(void **), 0x20)(temp_r3_37);
    }
}
#endif

#if 0 // DRAFT: illegal type
void SpyroStateMachine::Message(MKMessage *arg0) {
    s32 temp_r0_55;
    void **temp_r3_60;

    temp_r0_55 = this->unk8;
    if (temp_r0_55 >= 0) {
        temp_r3_60 = *(this->unk4 + (temp_r0_55 * 4));
        M2C_FIELD(*temp_r3_60, M2C_UNK (**)(void **), 0x24)(temp_r3_60);
    }
}
#endif

#if 0 // DRAFT: illegal type
void SpyroStateMachine::Update() {
    s32 temp_r0_80;
    void **temp_r3_85;
    void **temp_r3_93;

    temp_r0_80 = this->unk8;
    if (temp_r0_80 >= 0) {
        temp_r3_85 = *(this->unk4 + (temp_r0_80 * 4));
        M2C_FIELD(*temp_r3_85, M2C_UNK (**)(void **), 0x18)(temp_r3_85);
        temp_r3_93 = *(this->unk4 + (this->unk8 * 4));
        M2C_FIELD(*temp_r3_93, M2C_UNK (**)(void **), 0x1C)(temp_r3_93);
    }
}
#endif

void SpyroStateMachine::SetState(int arg0, MKMessage *arg1) {
    SpyroStateMessages sp8;

    sp8.unk50 = 0;
    if (arg1 != NULL) {
        sp8.AddMessage(arg1);
    }
    SetState(arg0, sp8);
}

#if 0 // DRAFT: illegal type
void SpyroStateMachine::SetState(int arg0, SpyroStateMessages &arg1) {
    s32 temp_r0_144;
    s32 temp_r0_162;
    void **temp_r3_149;
    void **temp_r3_168;

    temp_r0_144 = this->unk8;
    if (temp_r0_144 >= 0) {
        temp_r3_149 = *(this->unk4 + (temp_r0_144 * 4));
        M2C_FIELD(*temp_r3_149, M2C_UNK (**)(void **), 0x14)(temp_r3_149);
    }
    this->unkC = this->unk8;
    this->unk8 = arg0;
    this->unk0->OnStateChange(this->unkC, this->unk8);
    temp_r0_162 = this->unk8;
    if (temp_r0_162 >= 0) {
        temp_r3_168 = *(this->unk4 + (temp_r0_162 * 4));
        M2C_FIELD(*temp_r3_168, M2C_UNK (**)(void **, SpyroStateMessages *), 0x10)(temp_r3_168, &arg1);
    }
}
#endif

#if 0 // DRAFT: illegal type
void SpyroStateMachine::Reset(int arg0, SpyroStateMessages &arg1) {
    s32 temp_r0_191;
    void **temp_r3_196;

    temp_r0_191 = this->unk8;
    if (temp_r0_191 >= 0) {
        temp_r3_196 = *(this->unk4 + (temp_r0_191 * 4));
        M2C_FIELD(*temp_r3_196, M2C_UNK (**)(void **), 0x14)(temp_r3_196);
    }
    this->unk8 = -1;
    SetState(arg0, arg1);
}
#endif

#if 0 // DRAFT: illegal type
void SpyroStateMachine::Deinit() {
    MKHeap *temp_r3_264;
    s32 temp_r0_223;
    s32 var_r30_234;
    s32 var_r30_250;
    s32 var_r31_235;
    s32 var_r31_251;
    void **temp_r3_228;
    void **temp_r3_239;
    void *temp_r31_263;

    temp_r0_223 = this->unk8;
    if (temp_r0_223 >= 0) {
        temp_r3_228 = *(this->unk4 + (temp_r0_223 * 4));
        M2C_FIELD(*temp_r3_228, M2C_UNK (**)(void **), 0x14)(temp_r3_228);
    }
    var_r30_234 = 0;
    var_r31_235 = 0;
loop_4:
    if (var_r30_234 < (s32) this->unk10) {
        temp_r3_239 = *(this->unk4 + var_r31_235);
        M2C_FIELD(*temp_r3_239, M2C_UNK (**)(void **), 0xC)(temp_r3_239);
        var_r30_234 += 1;
        var_r31_235 += 4;
        goto loop_4;
    }
    var_r30_250 = 0;
    var_r31_251 = 0;
loop_7:
    if (var_r30_250 < (s32) this->unk10) {
        operator delete(*(this->unk4 + var_r31_251));
        var_r30_250 += 1;
        var_r31_251 += 4;
        goto loop_7;
    }
    temp_r31_263 = this->unk4;
    temp_r3_264 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_264 != NULL) {
        ((MKHeap *) (temp_r3_264->Current()))->Free(temp_r31_263, NULL, 0);
        return;
    }
    free(temp_r31_263);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpyroStateMachine::Init(Spyro *arg0, SpyroStateCreatorTableEntry *arg1, int arg2) {
    MKHeap *temp_r3_300;
    s32 temp_r30_299;
    s32 var_r29_314;
    s32 var_r30_316;
    s32 var_r30_335;
    s32 var_r31_315;
    s32 var_r31_336;
    void **temp_r3_341;
    void *temp_r5_319;
    void *var_r3_307;

    this->unk0 = arg0;
    this->unk8 = -1;
    this->unkC = -1;
    this->unk10 = arg2;
    temp_r30_299 = this->unk10 * 4;
    temp_r3_300 = MKHeap::Current();
    if (temp_r3_300 != NULL) {
        var_r3_307 = ((MKHeap *) (temp_r3_300->Current()))->Alloc(temp_r30_299, NULL, 0);
    } else {
        var_r3_307 = malloc(temp_r30_299);
    }
    this->unk4 = var_r3_307;
    var_r29_314 = 0;
    var_r31_315 = 0;
    var_r30_316 = 0;
loop_5:
    if (var_r29_314 < (s32) this->unk10) {
        temp_r5_319 = arg1 + var_r30_316;
        var_r29_314 += 1;
        var_r30_316 += 0x10;
        *(this->unk4 + var_r31_315) = M2C_FIELD(temp_r5_319, s32 (**)(s32, s32, s32), 0)(M2C_FIELD(temp_r5_319, s32 *, 4), M2C_FIELD(temp_r5_319, s32 *, 8), M2C_FIELD(temp_r5_319, s32 *, 0xC));
        var_r31_315 += 4;
        goto loop_5;
    }
    var_r30_335 = 0;
    var_r31_336 = 0;
loop_8:
    if (var_r30_335 < (s32) this->unk10) {
        temp_r3_341 = *(this->unk4 + var_r31_336);
        M2C_FIELD(*temp_r3_341, M2C_UNK (**)(void **, Spyro *), 8)(temp_r3_341, this->unk0);
        var_r30_335 += 1;
        var_r31_336 += 4;
        goto loop_8;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'SpyroStateMessages' to
s32 SpyroStateMessages::IsMessageOnList(int arg0) {
    u32 temp_r7_362;
    u32 var_r0_368;
    u32 var_r0_388;
    u32 var_r8_363;

    temp_r7_362 = this->unk50;
    var_r8_363 = 0U;
loop_6:
    var_r0_388 = 0xA;
    if (temp_r7_362 < 0xAU) {
        var_r0_388 = temp_r7_362;
    }
    if (var_r8_363 >= var_r0_388) {
        return 0;
    }
    var_r0_368 = 0xA;
    if (temp_r7_362 < 0xAU) {
        var_r0_368 = temp_r7_362;
    }
    if (arg0 == (s32) *(this + ((((var_r8_363 + (temp_r7_362 - var_r0_368)) % 10) * 8) + 4))) {
        return 1;
    }
    var_r8_363 += 1;
    goto loop_6;
}
#endif

#if 0 // DRAFT: identifier 'SpyroStateMessages::GetMessage(int)' redeclared
s32 SpyroStateMessages::GetMessage(int arg0) {
    u32 temp_r7_401;
    u32 var_r0_407;
    u32 var_r0_422;
    u32 var_r0_439;
    u32 var_r8_402;

    temp_r7_401 = this->unk50;
    var_r8_402 = 0U;
loop_8:
    var_r0_439 = 0xA;
    if (temp_r7_401 < 0xAU) {
        var_r0_439 = temp_r7_401;
    }
    if (var_r8_402 >= var_r0_439) {
        return 0;
    }
    var_r0_407 = 0xA;
    if (temp_r7_401 < 0xAU) {
        var_r0_407 = temp_r7_401;
    }
    if (arg0 == (s32) *(this + ((((var_r8_402 + (temp_r7_401 - var_r0_407)) % 10) * 8) + 4))) {
        var_r0_422 = 0xA;
        if (temp_r7_401 < 0xAU) {
            var_r0_422 = temp_r7_401;
        }
        return *(this + (((var_r8_402 + (temp_r7_401 - var_r0_422)) % 10) * 8));
    }
    var_r8_402 += 1;
    goto loop_8;
}
#endif

void SpyroStateMessages::AddMessage(int arg0) {
    void *temp_r5_459;

    temp_r5_459 = this + ((this->unk50 % 10) * 8);
    M2C_FIELD(temp_r5_459, s32 *, 0) = 0;
    M2C_FIELD(temp_r5_459, s32 *, 4) = arg0;
    this->unk50 += 1;
}

void SpyroStateMessages::AddMessage(MKMessage *arg0) {
    void *temp_r5_480;

    if (arg0 != NULL) {
        temp_r5_480 = this + ((this->unk50 % 10) * 8);
        M2C_FIELD(temp_r5_480, MKMessage **, 0) = arg0;
        M2C_FIELD(temp_r5_480, s32 *, 4) = (s32) arg0->unk0;
        this->unk50 += 1;
    }
}

void SpyroState_cpp::__sinit() {
    f32 temp_f0_524;
    f64 temp_f1_505;
    f64 temp_f1_513;
    f64 temp_f3_493;
    f64 temp_f4_502;
    f64 temp_f4_510;
    f64 temp_f8_495;

    temp_f3_493 = __frsqrte(2014000.0);
    temp_f8_495 = __frsqrte(380000.0);
    temp_f4_502 = 0.5 * temp_f3_493 * -((2014000.0 * (temp_f3_493 * temp_f3_493)) - 3.0);
    temp_f1_505 = 0.5 * temp_f8_495 * -((380000.0 * (temp_f8_495 * temp_f8_495)) - 3.0);
    temp_f4_510 = 0.5 * temp_f4_502 * -((2014000.0 * (temp_f4_502 * temp_f4_502)) - 3.0);
    temp_f1_513 = 0.5 * temp_f1_505 * -((380000.0 * (temp_f1_505 * temp_f1_505)) - 3.0);
    temp_f0_524 = (f32) (380000.0 * (0.5 * temp_f1_513 * -((380000.0 * (temp_f1_513 * temp_f1_513)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_510 * -((2014000.0 * (temp_f4_510 * temp_f4_510)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_524;
}
