#include "spyro/source/checkpoint.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Level.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern s32 GS_CrystalLP1;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern GameStateMachine gGMState;
extern void **gMK;
extern M2C_UNK gb;
#if 0 // DRAFT: illegal implicit conversion from 'CheckPoint *' to
static BoundingVolume unitVolume;                   /* type too large by 0x10; unable to generate initializer: not enough data */

void CheckPoint::SetCurrentCheckPoint(CheckPoint *arg0) {
    ChunkInfo *temp_r4_63;
    u8 var_r3_64;
    void *temp_r5_65;

    if ((CheckPoint *) *CheckPoint::pCurrentCheckPoint != this) {
        *CheckPoint::pCurrentCheckPoint = this;
        if (this != NULL) {
            temp_r4_63 = this->unk1B8;
            var_r3_64 = 0;
            temp_r5_65 = temp_r4_63->unk4;
            if ((temp_r5_65 != NULL) && ((u32) M2C_FIELD(temp_r5_65, u32 *, 0x118) == temp_r4_63)) {
                var_r3_64 = 1;
            }
            if (var_r3_64 == 0) {
                ((GameData *) GameData::gameData)->SetSaveChunk(temp_r4_63);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk100'
void CheckPoint::Resolve() {
    MKProp::Resolve();
    M2C_FIELD(M2C_FIELD(this, void **, 0x100), M2C_UNK (**)(M2C_UNK *), 0x20)(&this->unk100);
}
#endif

#if 0 // DRAFT: undefined identifier 'LevelStartMessage'
void CheckPoint::Message(MKMessage *arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r0_121;
    void *temp_r3_134;

    temp_r0_121 = arg0->unk0;
    switch (temp_r0_121) {                          /* irregular */
    case 0x29:
        temp_r3_134 = checked_cast<LevelStartMessage *, MKMessage>(arg0);
        if (((u8) this->unk1C0 != 0) && ((u32) M2C_FIELD(temp_r3_134, u32 *, 8) == (ChunkInfo *) this->unk1B8)) {
        case 0xB5:
            if ((void *) *CheckPoint::pCurrentCheckPoint != this) {
                if ((void *) *CheckPoint::pCurrentCheckPoint != NULL) {
                    spC = 0;
                    sp8 = 0xB4;
                    M2C_FIELD(M2C_FIELD(*CheckPoint::pCurrentCheckPoint, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                }
                if ((MKAnimScript *) this->unk80 != NULL) {
                    if ((s32) arg0->unk0 == 0x29) {
                        this->unk80->SetAnim(M2C_FIELD(checked_cast<CheckPointDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x78), 1.0f, 0.0f, 0, -1);
                    } else {
                        this->unk80->SetAnim(M2C_FIELD(checked_cast<CheckPointDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x74), 1.0f, 0.0f, 0, -1);
                    }
                }
                SetCurrentCheckPoint(M2C_ERROR(/* Read from unset register $r4 */));
            }
        }
        break;
    case 0xB4:
        if ((void *) *CheckPoint::pCurrentCheckPoint == this) {
            if ((MKAnimScript *) this->unk80 != NULL) {
                this->unk80->SetAnim(M2C_FIELD(checked_cast<CheckPointDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x70), 1.0f, 0.0f, 0, -1);
            }
            NULL->SetCurrentCheckPoint(M2C_ERROR(/* Read from unset register $r4 */));
        }
        break;
    }
    ((KDSoundPlayer *) &this->unk190)->Message(arg0);
    M2C_FIELD(M2C_FIELD(this, void **, 0x100), M2C_UNK (**)(M2C_UNK *, MKMessage *), 0x1C)(&this->unk100, arg0);
    KDProp::Message(arg0);
}
#endif

void CheckPoint::Draw() {
    if ((MKAnimScript *) this->unk80 != NULL) {
        KDProp::Draw();
    }
}

#if 0 // DRAFT: illegal operand
void CheckPoint::Update() {
    s32 sp14;
    s32 sp10;
    s32 sp8;
    MKAnimScript *temp_r3_282;
    MKAnimScript *temp_r4_258;
    u32 temp_r3_262;
    u8 var_r6_263;
    void *temp_r30_259;

    KDProp::Update();
    temp_r4_258 = this->unk80;
    temp_r30_259 = checked_cast<CheckPointDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (temp_r4_258 != NULL) {
        temp_r3_262 = temp_r4_258->unk20;
        var_r6_263 = 1;
        if ((temp_r3_262 != (u32) M2C_FIELD(temp_r30_259, u32 *, 0x74)) && (temp_r3_262 != (MKAnim *) M2C_FIELD(temp_r30_259, MKAnim **, 0x78))) {
            var_r6_263 = 0;
        }
        sp8 = 1;
        ((KDSoundFader *) &this->unk190)->Update(GS_CrystalLP1, 1U, var_r6_263, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        temp_r3_282 = this->unk80;
        if (((u32) temp_r3_282->unk20 == (u32) M2C_FIELD(temp_r30_259, u32 *, 0x74)) && (temp_r3_282->unk2C & 1)) {
            temp_r3_282->SetAnim(M2C_FIELD(temp_r30_259, MKAnim **, 0x78), 1.0f, 0.0f, 0, -1);
        }
        this->unk1BC = KDSound_Play3d(this->unk80, this->unk8 + 0x30, 0U, 0.0f, 0U);
    }
    if ((u8) this->unk1C0 == 0) {
        M2C_FIELD(M2C_FIELD(this, void **, 0x100), M2C_UNK (**)(M2C_UNK *), 0x24)(&this->unk100);
        if (this->unk150 & 2) {
            sp14 = 0;
            sp10 = 0xB5;
            Message(&sp10);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk100'
void CheckPoint::Reset() {
    KDProp::Reset();
    M2C_FIELD(M2C_FIELD(this, void **, 0x100), M2C_UNK (**)(M2C_UNK *), 0x18)(&this->unk100);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[18]' to
void CheckPoint::LoadDone() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKModel *temp_r3_391;
    f64 temp_f0_413;
    f64 temp_f1_412;
    f64 temp_f1_439;
    s32 *temp_ret_479;
    void *temp_r3_410;
    void *temp_r3_518;
    void *temp_r4_383;
    void *temp_r4_428;
    void *temp_r5_436;
    void *var_r4_386;

    if ((u8) this->unk1C0 != 0) {
        this->unk1C2 = 0;
    }
    if ((u8) this->unk1C2 != 0) {
        *KDProp::pCustomAnimScrName = "P0037_SaveCrystal";
    }
    KDProp::LoadDone();
    temp_r4_383 = &MKProp::loadInfo - 4;
    M2C_STRUCT_COPY((s32) &this->unk8C + 4, (s32) temp_r4_383 + 4, 0x40);
    var_r4_386 = temp_r4_383 + 0x40;
    temp_r3_391 = this->unk4;
    if (temp_r3_391 != NULL) {
        var_r4_386 = this->unk0;
        M2C_FIELD(var_r4_386, MKHeap ***, 0x1C) = MKModel_GetBoundingVolume(temp_r3_391, (SubObjectType) 0, -1);
    }
    if ((u8) this->unk1C2 == 0) {
        this->unk10 &= 0xFFFFFFFC;
    }
    if ((u8) this->unk1C0 != 0) {
        temp_r3_410 = this->unk8;
        temp_f1_412 = M2C_FIELD(temp_r3_410, f64 *, 0x30);
        temp_f0_413 = M2C_FIELD(temp_r3_410, f64 *, 0x38);
        sp58 = temp_f1_412;
        this->unkF0 = temp_f1_412;
        this->unkF8 = temp_f0_413;
        this->unk1C1 = 1;
        sp60 = temp_f0_413;
        this->unk10 |= 0xC;
    }
    temp_r4_428 = M2C_FIELD(M2C_FIELD(*gMK, void *(**)(void **, void *), 0x7C)(gMK, var_r4_386), void **, 0xC);
    this->unk1B8 = M2C_FIELD(temp_r4_428, ChunkInfo **, 4);
    M2C_FIELD(M2C_FIELD(this, void **, 0x100), M2C_UNK (**)(M2C_UNK *, void *), 0x14)(&this->unk100, temp_r4_428);
    temp_r5_436 = this->unk8;
    temp_f1_439 = M2C_FIELD(temp_r5_436, f64 *, 0x30);
    sp48 = temp_f1_439;
    sp50 = M2C_FIELD(temp_r5_436, f64 *, 0x38);
    M2C_FIELD(M2C_FIELD(this, void **, 0x100), M2C_UNK (**)(M2C_UNK *, f64 *, void *, f64), 0x28)(&this->unk100, &sp48, temp_r5_436, temp_f1_439);
    if ((u8) this->unk1C1 == 0) {
        MKVector(300.0f, 0.0f, 0.0f);
        ((MKProp *) &sp28)->GetPos();
        sp8 = sp28 - sp18;
        this->unkF0 = sp8;
        sp10 = sp30 - sp20;
        sp38 = sp8;
        sp40 = (f64) sp10;
        this->unkF8 = (f64) sp10;
    }
    if (((u8) this->unk1C0 != 0) && ((temp_ret_479 = gGMState.GetCurrState(), (((s32) *temp_ret_479 == 6) != 0)) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) != 0)) && ((u32) *CheckPoint::pCurrentCheckPoint == 0U)) {
        SetCurrentCheckPoint((CheckPoint *) (u32) (u64) temp_ret_479);
        if ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) != 0) {
            ((Spyro *) (*Spyro::pInstance))->Spawn();
        }
    }
    if ((u8) this->unk1C0 != 0) {
        Disable();
        return;
    }
    if ((MKAnimScript *) this->unk80 != NULL) {
        temp_r3_518 = checked_cast<CheckPointDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if ((void *) M2C_FIELD(temp_r3_518, void **, 0x70) == NULL) {
            M2C_FIELD(temp_r3_518, void **, 0x70) = this->unk80->GetAnim("Idle_Off");
        }
        if ((void *) M2C_FIELD(temp_r3_518, void **, 0x74) == NULL) {
            M2C_FIELD(temp_r3_518, void **, 0x74) = this->unk80->GetAnim("Activate");
        }
        if ((void *) M2C_FIELD(temp_r3_518, void **, 0x78) == NULL) {
            M2C_FIELD(temp_r3_518, void **, 0x78) = this->unk80->GetAnim("Idle_On");
        }
        this->unk80->SetAnim(M2C_FIELD(checked_cast<CheckPointDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x70), 1.0f, 0.0f, 0, -1);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk100'
s32 CheckPoint::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r29_664;

    if ((KDProp::LoadLine(arg0) != 0) || (M2C_FIELD(M2C_FIELD(this, void **, 0x100), u8 (**)(M2C_UNK *, void *, MKIniLine *), 0x3C)(&this->unk100, "sphere", arg0) != 0) || (arg0->LoadBool("bLevelSpawn", &this->unk1C0, 0) != 0) || (arg0->LoadBool("bVisible", &this->unk1C2, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("camera") != 0) {
        var_r29_664 = arg0->unkC->GetSubLine(arg0);
loop_10:
        if (var_r29_664 != NULL) {
            if (var_r29_664->LoadVector3("cameraSource", &this->unkD0, 0) == 0) {
                var_r29_664->LoadVector3("cameraTarget", &this->unkE0, 0);
            }
            var_r29_664 = var_r29_664->unkC->GetNextLine(var_r29_664);
            goto loop_10;
        }
        return 1;
    }
    if (arg0->LoadVector3("spawnPos", (MKVector3 *) &this->unkF0, 0) != 0) {
        this->unk1C1 = 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void CheckPoint::Deinit() {
    s32 temp_r3_722;

    KDSound_Stop(&this->unk190);
    temp_r3_722 = this->unk1BC;
    if ((temp_r3_722 != 0) && (KDSound_IsVoicePlaying(temp_r3_722) != 0)) {
        KDSound_Stop(&this->unk1BC);
    }
    if ((u32) *CheckPoint::pCurrentCheckPoint == this) {
        NULL->SetCurrentCheckPoint(M2C_ERROR(/* Read from unset register $r4 */));
    }
    KDProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk100'
void CheckPoint::Init() {
    KDProp::Init();
    M2C_FIELD(M2C_FIELD(this, void **, 0x100), M2C_UNK (**)(M2C_UNK *, f32), 0x38)(&this->unk100, 1200.0f);
    this->unkD0.unk0 = 0.0f;
    this->unkD0.unk4 = 0.0f;
    this->unkD0.unk8 = 0.0f;
    this->unk1C0 = 1;
    this->unk1B8 = NULL;
    this->unk8 = &this->unk90;
    M2C_FIELD(this, f32 *, 0xF0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF4) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF8) = 0.0f;
    this->unk1C1 = 0;
    ((KDSoundFader *) &this->unk190)->Init(0.25f, 0.25f);
    this->unk1BC = 0;
    this->unk1C2 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unitVolume'
void CheckPointDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk1C = &unitVolume;
    this->unkC = 2;
    this->unk70 = 0;
    this->unk74 = 0;
    this->unk78 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unitVolume'
void checkpoint_cpp::__sinit() {
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f0_837;
    f64 temp_f1_868;
    f64 temp_f2_832;
    f64 temp_f4_839;
    f64 temp_f4_867;
    f64 temp_f5_834;
    f64 temp_f5_853;
    f64 temp_f9_851;

    temp_f2_832 = __frsqrte(2014000.0);
    temp_f5_834 = __frsqrte(380000.0);
    temp_f0_837 = temp_f2_832 * temp_f2_832;
    temp_f4_839 = temp_f5_834 * temp_f5_834;
    sp18 = -0.5f;
    sp20 = -0.5f;
    sp1C = -0.5f;
    sp10 = 1.0f;
    temp_f9_851 = 0.5 * temp_f2_832 * -((2014000.0 * temp_f0_837) - 3.0);
    M2C_FIELD(&unitVolume, f64 *, 0) = (f64) sp18;
    temp_f5_853 = 0.5 * temp_f5_834 * -((380000.0 * temp_f4_839) - 3.0);
    sp8 = 1.0f;
    spC = 1.0f;
    M2C_FIELD(&unitVolume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(&unitVolume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(&unitVolume, f64 *, 0x18) = (f64) sp10;
    temp_f4_867 = 0.5 * temp_f9_851 * -((2014000.0 * (temp_f9_851 * temp_f9_851)) - 3.0);
    temp_f1_868 = 0.5 * temp_f5_853 * -((380000.0 * (temp_f5_853 * temp_f5_853)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_867 * -((2014000.0 * (temp_f4_867 * temp_f4_867)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_868 * -((380000.0 * (temp_f1_868 * temp_f1_868)) - 3.0)));
}
#endif
