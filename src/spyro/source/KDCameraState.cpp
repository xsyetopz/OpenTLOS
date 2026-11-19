#include "spyro/source/KDCameraState.h"
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
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessageStorage.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void KDCameraStateStack::StateUpdate() {
    KDCamera *temp_r3_16;
    KDCamera *temp_r3_37;

    temp_r3_16 = this->unk14;
    temp_r3_16->PreStateUpdate();
    GetDescriptorAtIndex(this->unk10);
    if (__ptmf_test(M2C_ERROR(/* Read from unset register $r3 */) + 0x2C) != 0) {
        GetDescriptorAtIndex(this->unk10);
        __ptmf_scall(this->unk14, M2C_ERROR(/* Read from unset register $r3 */));
    }
    temp_r3_37 = this->unk14;
    temp_r3_37->PostStateUpdate();
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void KDCameraStateStack::StateExit() {
    KDCamera *temp_r3_57;
    KDCamera *temp_r3_78;

    temp_r3_57 = this->unk14;
    temp_r3_57->PreStateExit();
    GetDescriptorAtIndex(this->unk10);
    if (__ptmf_test(M2C_ERROR(/* Read from unset register $r3 */) + 0x20) != 0) {
        GetDescriptorAtIndex(this->unk10);
        __ptmf_scall(this->unk14, M2C_ERROR(/* Read from unset register $r3 */));
    }
    temp_r3_78 = this->unk14;
    temp_r3_78->PostStateExit();
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void KDCameraStateStack::StateEnter() {
    KDCamera *temp_r3_119;
    KDCamera *temp_r3_98;

    temp_r3_98 = this->unk14;
    temp_r3_98->PreStateEnter();
    GetDescriptorAtIndex(this->unk10);
    if (__ptmf_test(M2C_ERROR(/* Read from unset register $r3 */) + 0x14) != 0) {
        GetDescriptorAtIndex(this->unk10);
        __ptmf_scall(this->unk14, M2C_ERROR(/* Read from unset register $r3 */));
    }
    temp_r3_119 = this->unk14;
    temp_r3_119->PostStateEnter();
}
#endif

void *KDCameraStateStack::GetDescriptor(int arg0) {
    s32 count = this->unk1C;
    s32 offset = 0;
    void *desc;

    if (count > 0) {
        do {
            desc = (u8 *) this->unk18 + offset;
            if (arg0 == M2C_FIELD(desc, s32 *, 4)) {
                return desc;
            }
            offset += 0x40;
        } while (--count != 0);
    }
    return NULL;
}

#if 0 // DRAFT: illegal explicit conversion from 'KDCameraStateStack' to 'signed char *'
void KDCameraStateStack::GetDescriptorAtIndex(int arg0) {
    GetDescriptor(M2C_FIELD(*(this + (arg0 * 4)), s32 *, 4));
}
#endif

void KDCameraStateStack::GetObjectAtIndex(int arg0) {

}

void KDCameraStateStack::Object::ClearData() {
    M2C_FIELD(this, s32 *, 0) = 0;
}

s32 KDCameraStateStack::IsStateMessage(MKMessage *arg0) {
    s32 count = this->unk1C;
    s32 id = arg0->unk0;
    s32 offset = 0;

    if (count > 0) {
        do {
            void *desc = (u8 *) this->unk18 + offset;
            if (M2C_FIELD(desc, s32 *, 0x38) == id || M2C_FIELD(desc, s32 *, 0x3C) == id) {
                return 1;
            }
            offset += 0x40;
        } while (--count != 0);
    }
    return 0;
}

s32 KDCameraStateStack::HandleStateMessage(int arg0) {
    s32 count = this->unk1C;
    s32 offset = 0;
    void *desc;

    if (count > 0) {
        do {
            desc = (u8 *) this->unk18 + offset;
            if (M2C_FIELD(desc, s32 *, 0x38) == arg0) {
                Push(M2C_FIELD(desc, s32 *, 4));
                return 1;
            }
            if (M2C_FIELD(desc, s32 *, 0x3C) == arg0) {
                Pop(M2C_FIELD(desc, s32 *, 4));
                return 1;
            }
            offset += 0x40;
        } while (--count != 0);
    }
    return 0;
}

#if 0 // DRAFT: pointer/array required
void *KDCameraStateStack::PopObjectOffStack() {
    void *sp8;

    GetObjectAtIndex(this->unk10);
    sp8 = *M2C_ERROR(/* Read from unset register $r3 */);
    StateExit();
    GetObjectAtIndex(this->unk10);
    ((KDCameraStateStack::Object *) (M2C_ERROR(/* Read from unset register $r3 */)))->ClearData();
    this->unk10 -= 1;
    return sp8;
}
#endif

s32 KDCameraStateStack::Pop(int arg0) {
    s32 var_r30_311;
    s32 var_r31_295;

    var_r31_295 = -1;
    GetDescriptorAtIndex(this->unk10);
    if (arg0 == (s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4)) {
        GetDescriptorAtIndex(this->unk10);
        var_r31_295 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4);
        GetDescriptorAtIndex(this->unk10);
        if (M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 1) {
            var_r30_311 = this->unk10;
loop_5:
            if (var_r30_311 < 0) {

            } else {
                GetDescriptorAtIndex(var_r30_311);
                if (!(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 2)) {
                    PopObjectOffStack();
                    var_r30_311 -= 1;
                    goto loop_5;
                }
            }
        } else {
            PopObjectOffStack();
        }
    }
    GetDescriptorAtIndex(this->unk10);
    if (M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 4) {
        StateEnter();
    }
    return var_r31_295;
}

#if 0 // DRAFT: pointer/array required
void KDCameraStateStack::Push(int arg0) {
    s32 temp_r4_357;

    temp_r4_357 = this->unk10;
    if ((temp_r4_357 + 1) != 0) {
        GetDescriptorAtIndex(temp_r4_357);
        if (M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 8) {
            StateExit();
        }
    }
    this->unk10 += 1;
    GetObjectAtIndex(this->unk10);
    *M2C_ERROR(/* Read from unset register $r3 */) = GetDescriptor(arg0);
    StateEnter();
}
#endif

void KDCameraStateStack::Update() {
    StateUpdate();
}

void KDCameraStateStack::Reset() {
    s32 var_r31_408;

    var_r31_408 = 0;
    do {
        GetObjectAtIndex(var_r31_408);
        ((KDCameraStateStack::Object *) (M2C_ERROR(/* Read from unset register $r3 */)))->ClearData();
        var_r31_408 += 1;
    } while (var_r31_408 < 4);
    this->unk10 = -1;
}

void KDCameraStateStack::Deinit() {

}

void KDCameraStateStack::Init(KDCamera *arg0, KDCameraStateDescriptor *arg1, int arg2) {
    this->unk14 = arg0;
    this->unk18 = arg1;
    this->unk1C = arg2;
    Reset();
}

KDCameraStateStack::KDCameraStateStack() {
    this->unk18 = NULL;
    this->unk1C = -1;
    this->unk10 = -1;
}
