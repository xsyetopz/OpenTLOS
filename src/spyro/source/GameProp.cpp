#include "spyro/source/GameProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
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
#include "spyro/source/SpyroTools.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/GameEnums.h"
#include "spyro/source/PropFlags.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern f32 gUpdateTimeDelta;
extern void **gb;
#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
static s8 *pLoopingSoundEvents[4] = { "soundLoop01", "soundLoop02", "soundLoop03", NULL };
#endif

#if 0 // DRAFT: ')' expected
void GameProp::Message(MKMessage *arg0) {
    MKAnim *temp_r3_124;
    MKModel *temp_r0_176;
    s32 temp_r0_23;
    s32 temp_r4_177;
    u8 temp_r29_146;
    void *temp_r29_187;
    void *temp_r29_196;

    if ((MKAnimScript *) this->unk80 != NULL) {
        this->unk90.Message(arg0);
    }
    temp_r0_23 = arg0->unk0;
    switch (temp_r0_23) {                           /* irregular */
    case 0xBF:
        Deactivate();
        break;
    case 0xBE:
        Activate();
        break;
    case 0xB5:
        if (((MKAnimScript *) this->unk80 != NULL) && ((u32) M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0xC4) != 0U)) {
            this->unk80->SetAnim(M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xC4), 1.0f, 0.0f, 0, -1);
        }
        break;
    case 0xB4:
        if ((MKAnimScript *) this->unk80 != NULL) {
            if ((u32) M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0xC8) != 0U) {
                this->unk80->SetAnim(M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xC8), 1.0f, 0.0f, 0, -1);
            } else {
                temp_r3_124 = this->unk80->GetAnim("");
                if (temp_r3_124 != NULL) {
                    this->unk80->SetAnim(temp_r3_124, 1.0f, 0.0f, 0, -1);
                }
            }
        }
        break;
    default:
        if (this->unk10 & 0x100000) {
            this->unk70.unk4 = 1;
        } else {
            this->unk70.unk4 = 0;
        }
        break;
    case 0x52:
        temp_r29_146 = this->unk70.unk4;
        M2C_FIELD(checked_cast<CollisionMsg *, MKMessage>(arg0), u8 *, 8) = temp_r29_146;
        this->unk70.unk4 = 0;
        break;
    case 0x53:
        if ((u8) M2C_FIELD(checked_cast<CollisionMsg *, MKMessage>(arg0), u8 *, 8) != 0) {
            this->unk70.unk4 = 1;
        } else {
            this->unk70.unk4 = 0;
        }
        break;
    case 0xD5:
        Reset();
        break;
    case 0x47:
        temp_r0_176 = this->unk4;
        temp_r4_177 = checked_cast<SetLTWMessage *, MKMessage>(arg0);
        if (temp_r0_176 != NULL) {
            MKModel_SetWorldMatrix(temp_r0_176, *(temp_r4_177 + 0x10));
        }
        break;
    case 0x16:
        temp_r29_187 = checked_cast<HitHeroSndMsg *, MKMessage>(arg0);
        M2C_FIELD(temp_r29_187, s32 *, 8) = (s32) M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xDC);
        break;
    case 0x5B:
        temp_r29_196 = ((u8 *) this->unk8) + 0x30;
        M2C_FIELD(checked_cast<GetPosMsg *, MKMessage>(arg0), void **, 8) = temp_r29_196;
        break;
    case 0xF5:
        Tools_ResetEachInstance((MKPropDescriptor *) this->unk0);
        break;
    }
    PropFlagsMessage((unsigned int *) &this->unk10, arg0);
    KDPropEx::Message(arg0);
}
#endif

void GameProp::PostDraw() {

}

void GameProp::PreDraw() {

}

void GameProp::Draw() {
    FireAndIceFX *temp_r3_241;
    FireAndIceFX *temp_r3_252;

    if (this->unk10 & 0x40000) {
        PreDraw();
        temp_r3_241 = this->unkC0;
        if ((temp_r3_241 == NULL) || (temp_r3_241->Draw(NULL) == 0)) {
            KDProp::Draw();
        }
        temp_r3_252 = this->unkC0;
        if (temp_r3_252 != NULL) {
            temp_r3_252->DrawCleanup();
        }
        PostDraw();
    }
}

#if 0 // DRAFT: ')' expected
void GameProp::Deactivate() {
    PropFlagsClear((unsigned int *) &this->unk10, 0x160000U);
    this->unk70.unk4 = 0;
    if ((u32) M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0xC8) != 0U) {
        this->unk80->SetAnim(M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xC8), 1.0f, 0.0f, 0, -1);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void GameProp::Activate() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
    if (this->unk10 & 0x100000) {
        this->unk70.unk4 = 1;
    }
    if ((u32) M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0xC4) != 0U) {
        this->unk80->SetAnim(M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xC4), 1.0f, 0.0f, 0, -1);
    }
}
#endif

void GameProp::PropUpdate() {

}

#if 0 // DRAFT: ')' expected
void *GameProp::Update() {
    void *sp34;
    s32 sp30;
    s32 sp2C;
    s8 sp28;
    s32 sp24;
    s32 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    FireAndIceFX *temp_r3_483;
    FireAndIceFX *temp_r4_487;
    MKAnimScript *temp_r3_442;
    f32 temp_f1_433;
    f64 temp_f1_470;
    s32 temp_r3_422;
    u8 var_r3_488;
    void *temp_r30_468;
    void *temp_r5_466;

    if ((((u8) this->unk88 >> 6U) & 1) && (M2C_FIELD(checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) & 1)) {
        sp30 = 0;
        sp2C = 0x61;
        sp34 = NULL;
        Message(&sp2C, 0);
        sp24 = 0;
        sp20 = 0x52;
        sp28 = 1;
        if (sp34 != NULL) {
            M2C_FIELD(M2C_FIELD(sp34, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp20);
        }
        if ((MKModel *) this->unk4 != NULL) {
            SetColorToGround();
        }
        spC = 0;
        sp8 = 0x60;
        Message(&sp8);
        this->unk88 &= ~0x40;
        sp20 = 0x53;
        if (sp34 != NULL) {
            M2C_FIELD(M2C_FIELD(sp34, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp20);
        }
    }
    temp_r3_422 = this->unk10;
    if (!(temp_r3_422 & 0x20000)) {
        if (temp_r3_422 & 0x40000) {
            UpdateCameraAlpha();
        }
    } else {
        KDPropEx::Update();
        temp_f1_433 = this->unkB8;
        this->unkB8 = temp_f1_433 + gUpdateTimeDelta;
        PropUpdate(temp_f1_433);
        temp_r3_442 = this->unk80;
        if (temp_r3_442 != NULL) {
            this->unkBC = KDSound_Play3d(temp_r3_442, ((u8 *) this->unk8) + 0x30, 0U, 0.0f, 0U);
            this->unk90.Update(((u8 *) this->unk8) + 0x30, 0U);
        }
        if (M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xCC) != 0.0f) {
            temp_r5_466 = this->unk8;
            temp_r30_468 = checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_f1_470 = M2C_FIELD(temp_r5_466, f64 *, 0x30);
            sp10 = temp_f1_470;
            sp18 = M2C_FIELD(temp_r5_466, f64 *, 0x38);
            ((SpyroLighting *) (M2C_FIELD(*gb, SpyroLighting *(**)(void **, void ***, void *, f64), 0x38)(gb, &gb, temp_r5_466, temp_f1_470)))->ApplyPointLight((MKVector3) &sp10, M2C_FIELD(temp_r30_468, f32 *, 0xCC), 1.0f);
        }
        temp_r3_483 = this->unkC0;
        if (temp_r3_483 != NULL) {
            temp_r3_483->Update();
            temp_r4_487 = this->unkC0;
            var_r3_488 = 0;
            if (((s32) temp_r4_487->unk78 == 0) && ((u8) temp_r4_487->unkA4 != 0)) {
                var_r3_488 = 1;
            }
            if (var_r3_488 != 0) {
                Disable();
            }
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void GameProp::Reset() {
    KDProp::Reset();
    this->unkB8 = 0.0f;
    if (!(this->unk10 & 0x100000)) {
        this->unk70.unk4 = 0;
    }
    if (this->unk10 & 0x80000) {
        if ((u32) M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0xC4) != 0U) {
            this->unk80->SetAnim(M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xC4), 1.0f, 0.0f, 0, -1);
        }
    } else if ((u32) M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0xC8) != 0U) {
        this->unk80->SetAnim(M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xC8), 1.0f, 0.0f, 0, -1);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'pLoopingSoundEvents'
s32 GameProp::LoadDone() {
    MKAnimScript *temp_r3_581;
    MKModel *temp_r0_590;
    void *temp_r30_591;
    void *temp_r30_626;
    void *temp_r31_629;

    KDPropEx::LoadDone();
    temp_r3_581 = this->unk80;
    if (temp_r3_581 != NULL) {
        temp_r3_581->InitEvents(pLoopingSoundEvents);
    }
    temp_r0_590 = this->unk4;
    temp_r30_591 = checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((temp_r0_590 != NULL) && (MKModel_GetNmbrOfSubObjects(temp_r0_590, (SubObjectType) 2) != 0)) {
        MKModel_SetClothManualUpdate(this->unk4, 1U);
    }
    if (((u8) M2C_FIELD(temp_r30_591, u8 *, 0xE0) != 0) || ((u8) M2C_FIELD(temp_r30_591, u8 *, 0xE1) != 0)) {
        operator new(0xB0U, NULL, 0);
        this->unkC0 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unkC0->Init(this->unk4, 8.0f, 1.0f);
    }
    if ((MKAnimScript *) this->unk80 != NULL) {
        temp_r30_626 = checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r31_629 = checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk90.Init(this->unk80, 0, M2C_FIELD(checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xD0), 1, M2C_FIELD(temp_r31_629, s32 *, 0xD4), 2, M2C_FIELD(temp_r30_626, s32 *, 0xD8));
    }
}
#endif

s32 GameProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_658;

    var_r31_658 = 0;
    if ((KDPropEx::LoadLine(arg0) != 0) || (PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0)) {
        var_r31_658 = 1;
    }
    return var_r31_658;
}

void GameProp::Deinit() {
    FireAndIceFX *temp_r3_686;
    s32 temp_r3_695;

    temp_r3_686 = this->unkC0;
    if (temp_r3_686 != NULL) {
        temp_r3_686->Deinit();
        operator delete(this->unkC0);
        this->unkC0 = NULL;
    }
    temp_r3_695 = this->unkBC;
    if ((temp_r3_695 != 0) && (KDSound_IsVoicePlaying(temp_r3_695) != 0)) {
        KDSound_Stop((int *) &this->unkBC);
    }
    if ((MKAnimScript *) this->unk80 != NULL) {
        this->unk90.Deinit();
    }
    KDPropEx::Deinit();
}

void GameProp::Init() {
    KDPropEx::Init();
    PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
    this->unkB8 = 0.0f;
    this->unkBC = 0;
    this->unkC0 = NULL;
}

#if 0 // DRAFT: function call 'GetAnim(signed char *)' does not match
void GamePropDescriptor::LoadDone() {
    s8 *temp_r3_752;
    s8 *temp_r4_755;
    s8 *temp_r4_761;
    s8 *temp_r4_768;

    KDPropExDescriptor::LoadDone();
    temp_r3_752 = this->unk34;
    if (temp_r3_752 != NULL) {
        temp_r4_755 = this->unkC0;
        if (temp_r4_755 != NULL) {
            this->unkC0 = ((MKAnimScript *) temp_r3_752)->GetAnim(temp_r4_755);
        }
        temp_r4_761 = this->unkC4;
        if (temp_r4_761 != NULL) {
            this->unkC4 = ((MKAnimScript *) this->unk34)->GetAnim(temp_r4_761);
        }
        temp_r4_768 = this->unkC8;
        if (temp_r4_768 != NULL) {
            this->unkC8 = ((MKAnimScript *) this->unk34)->GetAnim(temp_r4_768);
        }
    }
    this->unkC |= 0x20;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 GamePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_794;

    var_r31_794 = 0;
    if ((KDPropExDescriptor::LoadLine(arg0) != 0) || (PropTypes_LoadLine(arg0, "", (int *) &this->unkC) != 0) || (arg0->LoadString("", &this->unkC0, 0) != 0) || (KDSound_LoadLine(arg0, "", (int *) &this->unkDC) != 0) || (arg0->LoadString("", &this->unkC4, 0) != 0) || (arg0->LoadString("", &this->unkC8, 0) != 0) || (KDSound_LoadLine(arg0, "soundLoop01", (int *) &this->unkD0.unk0) != 0) || (KDSound_LoadLine(arg0, "", (int *) &this->unkD4) != 0) || (KDSound_LoadLine(arg0, "", (int *) &this->unkD8) != 0) || (arg0->LoadBool("", this + 0xE1, 0) != 0) || (arg0->LoadBool("", (u8 *) &this->unkE0, 0) != 0) || (arg0->LoadFloat("", (f32 *) &this->unkCC, 0) != 0)) {
        var_r31_794 = 1;
    }
    return var_r31_794;
}
#endif

void GamePropDescriptor::Init() {
    KDPropExDescriptor::Init();
    M2C_FIELD(this, s8 *, 0xE0) = 0;
    M2C_FIELD(this, s8 *, 0xE1) = 0;
    this->unkC0 = NULL;
    this->unkC4 = NULL;
    this->unkC8 = NULL;
    this->unkD0.unk0 = 0;
    this->unkD4 = 0;
    this->unkD8 = 0;
    this->unkDC = GS_PLACEHOLDER;
    this->unkCC.unk0 = 0.0f;
}
