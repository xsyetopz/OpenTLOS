#include "spyro/source/TriggerProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/CutsceneObject.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/TriggerObject.h"
#include "unplaced_templates.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern void **gMK;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal implicit conversion from 'const char[10]' to
s32 TriggerPolyProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_68;

    var_r31_68 = 0;
    if ((TriggerProp::LoadLine(arg0) != 0) || (M2C_FIELD(this->unkD0, u8 (**)(void **, M2C_UNK *, MKIniLine *), 0x38)(&this->unkD0, "waypoints", arg0) != 0)) {
        var_r31_68 = 1;
    }
    return var_r31_68;
}
#endif

void TriggerPolyProp::Init() {
    TriggerProp::Init();
    M2C_FIELD(this->unkD0, M2C_UNK (**)(void **), 8)(&this->unkD0);
    this->unkA8 = (TriggerObject *) &this->unkD0;
}

s32 TriggerPlaneGroupProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_125;

    var_r31_125 = 0;
    if ((TriggerProp::LoadLine(arg0) != 0) || (M2C_FIELD(this->unkD0, u8 (**)(void **, MKIniLine *), 0x10)(&this->unkD0, arg0) != 0)) {
        var_r31_125 = 1;
    }
    return var_r31_125;
}

void TriggerPlaneGroupProp::Init() {
    TriggerObject *temp_r3_159;

    TriggerProp::Init();
    this->unkA8 = (TriggerObject *) &this->unkD0;
    temp_r3_159 = this->unkA8;
    temp_r3_159->Init();
}

void TriggerPlaneGroupPropDescriptor::Init() {
    TriggerPropDescriptor::Init();
    this->unk80 = 0;
}

#if 0 // DRAFT: ')' expected
f32 TriggerPlaneProp::Resolve() {
    MKProp *var_r3_198;
    TriggerPlaneGroupObject *temp_r31_211;

    TriggerProp::Resolve();
    var_r3_198 = this->unk1A0;
    if (var_r3_198 != NULL) {

    } else {
        var_r3_198 = this->unk1A4->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    }
    temp_r31_211 = checked_cast<TriggerPlaneGroupObject *, TriggerObject>(M2C_FIELD(checked_cast<TriggerProp *, MKProp>(var_r3_198), TriggerObject **, 0xA8));
    temp_r31_211->AddPlane(checked_cast<P18TriggerPlaneObject, 13TriggerObject>__FP13TriggerObject(this->unkA8));
}
#endif

#if 0 // DRAFT: undefined identifier 'unkD0'
s32 TriggerPlaneProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_232;

    var_r31_232 = 0;
    if ((TriggerProp::LoadLine(arg0) != 0) || (M2C_FIELD(this->unkD0.__vptr, u8 (**)(TriggerObject *, void *, MKIniLine *), 0x38)(&this->unkD0, "box", arg0) != 0) || (((Tools_ResolvableProp *) &this->unk1A0)->LoadLine(arg0, "planeGroupID"), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0))) {
        var_r31_232 = 1;
    }
    return var_r31_232;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkD0'
void TriggerPlaneProp::Init() {
    TriggerObject *temp_r3_277;

    TriggerProp::Init();
    this->unkA8 = &this->unkD0;
    temp_r3_277 = this->unkA8;
    temp_r3_277->Init();
    this->unk1A0 = NULL;
    this->unk1A4 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[7]' to
s32 TriggerSphereProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_301;

    var_r31_301 = 0;
    if ((TriggerProp::LoadLine(arg0) != 0) || (M2C_FIELD(M2C_FIELD(this, void **, 0xD0), u8 (**)(void *, void *, MKIniLine *), 0x3C)(this + 0xD0, "sphere", arg0) != 0)) {
        var_r31_301 = 1;
    }
    return var_r31_301;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'TriggerSphereProp *' to
void TriggerSphereProp::Init() {
    TriggerProp::Init();
    M2C_FIELD(M2C_FIELD(this, void **, 0xD0), M2C_UNK (**)(void *, f32), 0x38)(this + 0xD0, 0.0f);
    this->unkA8 = this + 0xD0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkD0'
s32 TriggerBoxProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_360;

    var_r31_360 = 0;
    if ((TriggerProp::LoadLine(arg0) != 0) || (M2C_FIELD(this->unkD0.__vptr, u8 (**)(TriggerObject *, void *, MKIniLine *), 0x38)(&this->unkD0, "box", arg0) != 0)) {
        var_r31_360 = 1;
    }
    return var_r31_360;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkD0'
void TriggerBoxProp::Init() {
    TriggerProp::Init();
    this->unkD0.Init();
    this->unkA8 = &this->unkD0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void TriggerProp::UpdateActiveList() {
    void *temp_r29_423;
    void *var_r30_418;

    var_r30_418 = *TriggerProp::pFirstActiveTrigger;
loop_5:
    if (var_r30_418 != NULL) {
        temp_r29_423 = M2C_FIELD(var_r30_418, void **, 0x90);
        if ((M2C_FIELD(var_r30_418, f32 *, 0xA4) < M2C_FIELD(&gb, f32 *, 0x30C)) && (M2C_FIELD(M2C_FIELD(var_r30_418, void **, 0xA0), s32 *, 0x138) & 2)) {
            M2C_FIELD(*gMK, M2C_UNK (**)(void **), 0x74)(gMK);
            M2C_FIELD(M2C_FIELD(var_r30_418, void **, 0x44), M2C_UNK (**)(void *), 0x24)(var_r30_418);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x74)(gMK, 0);
        }
        var_r30_418 = temp_r29_423;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void TriggerProp::RemoveFromActiveList(TriggerProp *arg0) {
    MKPropDescriptor *temp_r4_467;
    TriggerProp *temp_r4_473;

    if ((MKPropDescriptor *) *TriggerProp::pFirstActiveTrigger == this) {
        *TriggerProp::pFirstActiveTrigger = this->unk90;
    }
    temp_r4_467 = this->unk90;
    if (temp_r4_467 != NULL) {
        M2C_FIELD(temp_r4_467, TriggerProp **, 0x94) = (TriggerProp *) this->unk94;
    }
    temp_r4_473 = this->unk94;
    if (temp_r4_473 != NULL) {
        temp_r4_473->unk90 = this->unk90;
    }
    this->unk90 = NULL;
    this->unk94 = NULL;
}
#endif

#if 0 // DRAFT: ')' expected
void TriggerProp::AddToActiveList(TriggerProp *arg0) {
    if ((u8) M2C_FIELD(checked_cast<TriggerPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x80) != 0) {
        if ((MKPropDescriptor *) *TriggerProp::pFirstActiveTrigger != NULL) {
            M2C_FIELD(*TriggerProp::pFirstActiveTrigger, TriggerProp **, 0x94) = this;
            this->unk90 = *TriggerProp::pFirstActiveTrigger;
            this->unk94 = NULL;
            *TriggerProp::pFirstActiveTrigger = (MKPropDescriptor *) this;
            return;
        }
        *TriggerProp::pFirstActiveTrigger = (MKPropDescriptor *) this;
        this->unk90 = NULL;
        this->unk94 = NULL;
    }
}
#endif

void TriggerProp::Disable() {
    TriggerObject *temp_r3_530;

    this->unk18 |= 0x80000000;
    temp_r3_530 = this->unkA8;
    if (temp_r3_530 != NULL) {
        temp_r3_530->EnableTrigger(0U);
    }
}

void TriggerProp::Enable() {
    TriggerObject *temp_r3_551;

    this->unk18 &= 0x7FFFFFFF;
    temp_r3_551 = this->unkA8;
    if (temp_r3_551 != NULL) {
        temp_r3_551->EnableTrigger(1U);
    }
}

f32 TriggerProp::Resolve() {
    TriggerObject *temp_r3_572;

    MKProp::Resolve();
    temp_r3_572 = this->unkA8;
    temp_r3_572->Resolve();
    this->unk10 |= 0x01000000;
    this->unk10 |= 0x04000000;
    this->unk10 |= 0x02000000;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void TriggerProp::Message(MKMessage *arg0) {
    TriggerObject *temp_r3_628;
    TriggerObject *temp_r3_635;
    TriggerObject *temp_r3_645;
    s32 temp_r0_602;

    temp_r0_602 = arg0->unk0;
    switch (temp_r0_602) {                          /* irregular */
    case 0xB5:
    case 0xBE:
        temp_r3_628 = this->unkA8;
        if (temp_r3_628 != NULL) {
            temp_r3_628->EnableTrigger(1U);
        }
        break;
    case 0xBF:
    case 0xB4:
        temp_r3_635 = this->unkA8;
        if (temp_r3_635 != NULL) {
            temp_r3_635->EnableTrigger(0U);
        }
        RemoveFromActiveList(M2C_ERROR(/* Read from unset register $r4 */));
        break;
    case 0xD:
        temp_r3_645 = this->unkA8;
        if (temp_r3_645 != NULL) {
            M2C_FIELD(temp_r3_645->__vptr, M2C_UNK (**)(), 0x1C)();
        }
        break;
    case 0x9D:
        this->unk4C = 0;
        break;
    case 0xD5:
        Reset();
        break;
    }
    MKProp::Message(arg0);
    PropFlagsMessage((unsigned int *) &this->unk10, arg0);
}
#endif

s32 TriggerProp::CheckQueue() {
    s16 temp_r3_696;
    s16 temp_r3_708;
    s16 temp_r4_685;
    s32 var_r31_684;

    var_r31_684 = 0;
    temp_r4_685 = this->unk4C;
    if (temp_r4_685 & 1) {
        var_r31_684 = 1;
        this->unk4C = temp_r4_685 & 0xFFFFFFFE;
        OnEnter();
    }
    temp_r3_696 = this->unk4C;
    if (temp_r3_696 & 2) {
        this->unk4C = temp_r3_696 & 0xFFFFFFFD;
        var_r31_684 = 1;
        OnExit();
    }
    temp_r3_708 = this->unk4C;
    if (temp_r3_708 & 4) {
        this->unk4C = temp_r3_708 & 0xFFFFFFFB;
        var_r31_684 = 1;
        OnAction();
    }
    return var_r31_684;
}

void TriggerProp::OnAction() {
    s32 temp_r3_743;

    M2C_FIELD(&gb, s8 *, 0x35C) = 1;
    this->unkB0.Send((MKProp *) this);
    temp_r3_743 = this->unk10;
    if (temp_r3_743 & 0x10000000) {
        this->unk10 = temp_r3_743 & 0xFBFFFFFF;
    }
}

void TriggerProp::OnExit() {
    s32 temp_r3_770;

    if (this->unk10 & 0x02000000) {
        this->unkB4.Send((MKProp *) this);
        temp_r3_770 = this->unk10;
        if (temp_r3_770 & 0x20000000) {
            this->unk10 = temp_r3_770 & 0xFDFFFFFF;
        }
    }
}

void TriggerProp::OnEnter() {
    s32 temp_r3_797;
    s32 temp_r4_803;

    if (this->unk10 & 0x01000000) {
        this->unkAC.Send((MKProp *) this);
        temp_r3_797 = this->unk10;
        if (temp_r3_797 & 0x08000000) {
            this->unk10 = temp_r3_797 & 0xFEFFFFFF;
        }
    }
    temp_r4_803 = this->unkBC;
    if (temp_r4_803 != 0) {
        ((CutsceneSystem::Location *) (M2C_FIELD(&gb, CutsceneSystem::Location **, 0xC)))->SetTextID(temp_r4_803);
    }
}

void *TriggerProp::Update() {
    TriggerObject *temp_r3_834;
    s32 temp_cr0_eq_1015;
    s32 temp_cr0_eq_933;
    s32 temp_r3_879;
    u32 var_r4_838;
    u64 temp_ret_838;
    u64 temp_ret_851;
    u64 temp_ret_860;
    u64 temp_ret_869;

    this->unkA4 = M2C_FIELD(&gb, f32 *, 0x30C);
    MKProp::Update();
    if (this->unk10 & 0x20000) {
        temp_r3_834 = this->unkA8;
        temp_ret_838 = temp_r3_834->Update();
        var_r4_838 = (u32) temp_ret_838;
        if (temp_ret_838 != 0) {
            if ((s32) this->unkA8->unk54 == 0) {
                temp_ret_851 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u64 (**)(void **), 0x4C)(M2C_FIELD(&gb, void ***, 0));
                var_r4_838 = (u32) temp_ret_851;
                if (temp_ret_851 != 0) {
                    temp_ret_860 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u64 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0));
                    var_r4_838 = (u32) temp_ret_860;
                    if (temp_ret_860 == 0) {
                        temp_ret_869 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u64 (**)(void **), 0x60)(M2C_FIELD(&gb, void ***, 0));
                        var_r4_838 = (u32) temp_ret_869;
                        if (temp_ret_869 == 0) {
                            var_r4_838 = (u32) CheckQueue();
                        }
                    }
                }
            }
            temp_r3_879 = this->unkA8->unk50;
            if (temp_r3_879 & 2) {
                AddToActiveList((TriggerProp *) var_r4_838);
                if ((u8) this->unkC0 != 0) {
                    if (((s32) this->unkA8->unk54 == 0) && ((M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x4C)(M2C_FIELD(&gb, void ***, 0)) == 0) || (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) != 0) || (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x60)(M2C_FIELD(&gb, void ***, 0)) != 0))) {
                        this->unk4C |= 1;
                        return;
                    }
                    OnEnter();
                    return;
                }
                temp_cr0_eq_933 = (s32) this->unkA8->unk54 == 0;
                if ((temp_cr0_eq_933 == 0) || ((temp_cr0_eq_933 != 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x4C)(M2C_FIELD(&gb, void ***, 0)) != 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) == 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x60)(M2C_FIELD(&gb, void ***, 0)) == 0))) {
                    OnEnter();
                }
            } else if (temp_r3_879 & 4) {
                RemoveFromActiveList((TriggerProp *) var_r4_838);
                if ((u8) this->unkC0 != 0) {
                    if (((s32) this->unkA8->unk54 == 0) && ((M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x4C)(M2C_FIELD(&gb, void ***, 0)) == 0) || (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) != 0))) {
                        this->unk4C |= 2;
                        return;
                    }
                    OnExit();
                    return;
                }
                temp_cr0_eq_1015 = (s32) this->unkA8->unk54 == 0;
                if ((temp_cr0_eq_1015 == 0) || ((temp_cr0_eq_1015 != 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x4C)(M2C_FIELD(&gb, void ***, 0)) != 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) == 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x60)(M2C_FIELD(&gb, void ***, 0)) == 0))) {
                    OnExit();
                }
            }
        } else {
            this->unk4C = 0;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void TriggerProp::Reset() {
    TriggerObject *temp_r3_1072;

    MKProp::Reset();
    temp_r3_1072 = this->unkA8;
    RemoveFromActiveList((TriggerProp *) (u32) temp_r3_1072->Reset());
    this->unk4C = 0;
}
#endif

s32 TriggerProp::LoadDone() {
    TriggerObject *temp_r3_1100;
    TriggerObject *temp_r3_1108;

    this->unk10 |= 8;
    MKProp::LoadDone();
    temp_r3_1100 = this->unkA8;
    temp_r3_1100->LoadDone();
    if ((u32) this->unkB0.unk0 != 0U) {
        temp_r3_1108 = this->unkA8;
        temp_r3_1108->unk50 |= 0x10;
    }
    M2C_STRUCT_COPY((s32) &this->unk4C + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
    this->unk8 = &this->unk50;
    this->unkC = (BoundingVolume *) &this->unkA8->unk60;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 TriggerProp::LoadLine(MKIniLine *arg0) {
    TriggerObject *temp_r3_1155;
    s32 temp_r3_1188;
    s32 temp_r3_1209;
    s32 temp_r3_1230;
    s32 temp_r3_1251;
    s32 temp_r3_1272;
    u8 var_r29_1290;

    if ((MKProp::LoadLine(arg0) != 0) || (temp_r3_1155 = this->unkA8, ((temp_r3_1155->LoadLine(arg0) == 0) == 0)) || (arg0->LoadInt("textID", (int *) &this->unkBC, 0) != 0)) {
        return 1U;
    }
    if (arg0->IsField("bEnterOnceOnly") != 0) {
        temp_r3_1188 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x09000000 & ((temp_r3_1188 - temp_r3_1188) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bExitOnceOnly") != 0) {
        temp_r3_1209 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x22000000 & ((temp_r3_1209 - temp_r3_1209) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bActionOnceOnly") != 0) {
        temp_r3_1230 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x14000000 & ((temp_r3_1230 - temp_r3_1230) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bSaveEnterOnceOnly") != 0) {
        temp_r3_1251 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x49000000 & ((temp_r3_1251 - temp_r3_1251) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bExclaim") != 0) {
        temp_r3_1272 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x80000000 & ((temp_r3_1272 - temp_r3_1272) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->LoadBool("bAllowQueuedActions", &this->unkC0, 0) != 0) {
        var_r29_1290 = 1;
    } else {
        var_r29_1290 = 0;
        if ((this->unkAC.LoadLine(arg0, "OnEnter") != 0) || (this->unkB0.LoadLine(arg0, "OnAction") != 0) || (this->unkB4.LoadLine(arg0, "OnExit") != 0) || (PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0)) {
            var_r29_1290 = 1;
        }
    }
    return var_r29_1290;
}
#endif

#if 0 // DRAFT: type mismatch
void TriggerProp::Deinit() {
    MKPropDescriptor *temp_r3_1349;
    TriggerObject *temp_r3_1366;
    TriggerProp *temp_r3_1355;

    if ((MKPropDescriptor *) *TriggerProp::pFirstTrigger == this) {
        *TriggerProp::pFirstTrigger = this->unk98;
    }
    temp_r3_1349 = this->unk98;
    if (temp_r3_1349 != NULL) {
        M2C_FIELD(temp_r3_1349, TriggerProp **, 0x9C) = (TriggerProp *) this->unk9C;
    }
    temp_r3_1355 = this->unk9C;
    if (temp_r3_1355 != NULL) {
        temp_r3_1355->unk98 = this->unk98;
    }
    this->unk98 = NULL;
    this->unk9C = NULL;
    RemoveFromActiveList(M2C_ERROR(/* Read from unset register $r4 */));
    temp_r3_1366 = this->unkA8;
    temp_r3_1366->Deinit();
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void TriggerProp::Init() {
    MKProp::Init();
    PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
    this->unkA8 = NULL;
    this->unkBC = 0;
    this->unk4C = 0;
    this->unkC0 = 1;
    this->unk94 = NULL;
    this->unk90 = NULL;
    this->unkA0 = M2C_FIELD(*gMK, s32 (**)(void **), 0x7C)(gMK);
    this->unkA4 = 0.0f;
    if ((MKPropDescriptor *) *TriggerProp::pFirstTrigger != NULL) {
        M2C_FIELD(*TriggerProp::pFirstTrigger, TriggerProp **, 0x9C) = this;
        this->unk98 = *TriggerProp::pFirstTrigger;
        this->unk9C = NULL;
        *TriggerProp::pFirstTrigger = (MKPropDescriptor *) this;
        return;
    }
    *TriggerProp::pFirstTrigger = (MKPropDescriptor *) this;
    this->unk98 = NULL;
    this->unk9C = NULL;
}
#endif

void TriggerPropDescriptor::Deinit() {
    MKPropDescriptor::Deinit();
}

void TriggerPropDescriptor::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKPropDescriptor::Init();
    this->unk60 = -100.0f;
    this->unk64 = 0.0f;
    this->unk68 = -100.0f;
    sp8 = (f64) M2C_FIELD(this, f32 *, 0x60) * 1.591496843e-314;
    this->unk70 = sp8;
    sp10 = this->unk68 * -2.0f;
    sp18 = sp8;
    this->unk78 = (f64) sp10;
    M2C_FIELD(this, f32 *, 0x74) = 200.0f;
    this->unk1C = (BoundingVolume *) &this->unk60;
    this->unk80 = 1;
    sp20 = (f64) sp10;
    this->unkC = this->unkC | 0x40000 | 2;
}
