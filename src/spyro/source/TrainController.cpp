#include "spyro/source/TrainController.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
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
#include "spyro/source/Enemy.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/LightProp.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SpyroEffects.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/SteamTrain.h"
#include "spyro/source/SteamTrainCaboose.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/TrainChaseSpyro.h"
#include "unplaced_templates.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, s8 *);                            /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;

void TrainController::SetStage(int arg0) {
    SteamTrain *temp_r3_74;
    void *temp_r3_61;

    this->unk5C = (u32) arg0;
    temp_r3_61 = checked_cast<TrainChaseSpyro *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk58));
    if (temp_r3_61 != NULL) {
        M2C_FIELD(temp_r3_61, f32 *, 0xDC) = (f32) M2C_FIELD((checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk5C * 0xC)), f32 *, 0x60);
    }
    temp_r3_74 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
    if (temp_r3_74 != NULL) {
        temp_r3_74->unk10C = M2C_FIELD((checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk5C * 0xC)), f32 *, 0x64);
    }
    this->unk60 = 0.0f;
}

void TrainController::Message(MKMessage *arg0) {
    s32 sp50[2];
    s32 sp48[2];
    s32 sp40[2];
    s32 sp38[2];
    s32 sp30[2];
    s32 sp28[2];
    s32 sp20[2];
    s32 sp18[2];
    s32 sp10[2];
    s32 sp8[2];
    SteamTrain *temp_r3_306;
    SteamTrain *temp_r3_334;
    SteamTrain *temp_r3_402;
    SteamTrain *temp_r3_411;
    s32 temp_r0_104;
    MKProp *temp_r3_166;
    MKProp *temp_r3_180;
    MKProp *temp_r3_194;
    MKProp *temp_r3_208;
    MKProp *temp_r3_227;
    MKProp *temp_r3_241;
    MKProp *temp_r3_255;
    MKProp *temp_r3_269;
    MKProp *temp_r3_355;
    MKProp *temp_r3_369;
    MKProp *temp_r3_379;
    MKProp *temp_r3_390;
    MKProp *temp_r3_419;

    MKProp::Message(arg0);
    temp_r0_104 = arg0->unk0;
    switch (temp_r0_104) {
    case 0xB5:
        Enable();
        Reset();
        temp_r3_166 = MKSceneManager::PropResolver_Resolve((s32) this->unk50);
        if (temp_r3_166 != NULL) {
            sp48[1] = 0;
            sp48[0] = 0xB5;
            temp_r3_166->Message((MKMessage *) sp48);
        }
        temp_r3_180 = MKSceneManager::PropResolver_Resolve((s32) this->unk4C);
        if (temp_r3_180 != NULL) {
            sp40[1] = 0;
            sp40[0] = 0xB5;
            temp_r3_180->Message((MKMessage *) sp40);
        }
        temp_r3_194 = MKSceneManager::PropResolver_Resolve((s32) this->unk54);
        if (temp_r3_194 != NULL) {
            sp38[1] = 0;
            sp38[0] = 0xB5;
            temp_r3_194->Message((MKMessage *) sp38);
        }
        temp_r3_208 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_208 != NULL) {
            sp30[1] = 0;
            sp30[0] = 0xB5;
            temp_r3_208->Message((MKMessage *) sp30);
        }
        this->unk68.Send(this);
        return;
    case 0xB4:
        temp_r3_227 = MKSceneManager::PropResolver_Resolve((s32) this->unk50);
        if (temp_r3_227 != NULL) {
            sp28[1] = 0;
            sp28[0] = 0xB4;
            temp_r3_227->Message((MKMessage *) sp28);
        }
        temp_r3_241 = MKSceneManager::PropResolver_Resolve((s32) this->unk4C);
        if (temp_r3_241 != NULL) {
            sp20[1] = 0;
            sp20[0] = 0xB4;
            temp_r3_241->Message((MKMessage *) sp20);
        }
        temp_r3_255 = MKSceneManager::PropResolver_Resolve((s32) this->unk54);
        if (temp_r3_255 != NULL) {
            sp18[1] = 0;
            sp18[0] = 0xB4;
            temp_r3_255->Message((MKMessage *) sp18);
        }
        temp_r3_269 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_269 != NULL) {
            sp10[1] = 0;
            sp10[0] = 0xB4;
            temp_r3_269->Message((MKMessage *) sp10);
        }
        Disable();
        return;
    case 0x138:
        SetStage(0);
        return;
    case 0x139:
        SetStage(1);
        return;
    case 0x13A:
        SetStage(2);
        return;
    case 0x13B:
        temp_r3_306 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_306 != NULL) {
            temp_r3_306->unk131 = 0;
        }
        SetStage(3);
        return;
    case 0x13C:
        SetStage(4);
        return;
    case 0x13D:
        SetStage(5);
        return;
    case 0x13E:
        SetStage(6);
        return;
    case 0x13F:
        temp_r3_334 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_334 != NULL) {
            temp_r3_334->Stop(false);
        }
        SetStage(7);
        return;
    case 0x140:
        this->unk64.Send(this);
        return;
    case 0x148:
        this->unk6C = 1;
        return;
    case 0x149:
        temp_r3_355 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_355 != NULL) {
            temp_r3_355->Message(arg0);
        }
        this->unk6C = 0;
        return;
    case 0x14A:
        temp_r3_369 = MKSceneManager::PropResolver_Resolve((s32) this->unk50);
        if (temp_r3_369 != NULL) {
            temp_r3_369->Message(arg0);
        }
        temp_r3_379 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_379 != NULL) {
            temp_r3_379->Message(arg0);
            return;
        }
        return;
    case 0x14B:
        temp_r3_390 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_390 != NULL) {
            temp_r3_390->Message(arg0);
            return;
        }
        break;
    case 0x142:
        temp_r3_402 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_402 != NULL) {
            temp_r3_402->unk131 = 1;
            return;
        }
        break;
    case 0x141:
        temp_r3_411 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_411 != NULL) {
            temp_r3_411->Stop(true);
            return;
        }
        break;
    case 0x143:
        temp_r3_419 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_419 != NULL) {
            sp50[1] = 0;
            sp50[0] = 0x148;
            temp_r3_419->Message((MKMessage *) sp50);
            return;
        }
        break;
    case 0x1C:
        sp8[1] = 0;
        sp8[0] = 0xB4;
        Message((MKMessage *) sp8);
        break;
    }
}

void *TrainController::Update() {
    SteamTrainCaboose *temp_r3_482;

    MKProp::Update();
    if ((M2C_FIELD((checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk5C * 0xC)), f32 *, 0x68) >= 0.0f) && (this->unk60 >= M2C_FIELD((checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk5C * 0xC)), f32 *, 0x68))) {
        temp_r3_482 = checked_cast<SteamTrainCaboose *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk54));
        if ((temp_r3_482 != NULL) && (temp_r3_482->IsBlownUp() == 0)) {
            temp_r3_482->BlowUp();
        }
    }
    this->unk60 += gUpdateTimeDelta;
}

void TrainController::Reset() {
    s32 sp8[2];
    TrainChaseSpyro *temp_r3_522;
    SteamTrain *temp_r3_532;

    MKProp::Reset();
    if ((u8) ((MKSceneManager *) gMK)->IsEnabled(this, *(s32 *) MKResource::sWorkingChunkID) != 0) {
        temp_r3_522 = checked_cast<TrainChaseSpyro *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk58));
        if (temp_r3_522 != NULL) {
            temp_r3_522->Reset();
        }
        temp_r3_532 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_532 != NULL) {
            temp_r3_532->Reset();
        }
        SetStage(0);
        sp8[0] = 0xD5;
        sp8[1] = 0;
        ((MKSceneManager *) gMK)->SendMessage((MKMessage *) sp8, 0x40000, true, NULL, 0.0f, true);
    }
    this->unk6C = 0;
}

s32 TrainController::LoadDone() {
    void *temp_r4_577;

    MKProp::LoadDone();
    temp_r4_577 = this->unk0;
    M2C_FIELD(temp_r4_577, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r4_577, s32 *, 0xC) | 0x20);
    Disable();
}

s32 TrainController::LoadLine(MKIniLine *arg0) {
    s32 var_r31_602;

    var_r31_602 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("trackID", (int *) &this->unk4C, 0) != 0) || (arg0->LoadInt("trainID", (int *) &this->unk50, 0) != 0) || (arg0->LoadInt("cabooseID", (int *) &this->unk54, 0) != 0) || (arg0->LoadInt("spyroCartID", (int *) &this->unk58, 0) != 0) || (this->unk64.LoadLine(arg0, "OnFinish") != 0) || (this->unk68.LoadLine(arg0, "OnReset") != 0)) {
        var_r31_602 = 1;
    }
    return var_r31_602;
}

void TrainController::Init() {
    MKProp::Init();
    this->unk5C = 0;
    this->unk60 = 0.0f;
    this->unk4C = NULL;
    this->unk50 = NULL;
    this->unk54 = NULL;
    this->unk58 = NULL;
    this->unk6C = 0;
}

s32 TrainControllerDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *name;
    MKIniLine *var_r22;
    f32 *var_r23;
    f32 *var_r24;
    f32 *var_r25;
    s32 var_r26;
    MKIniLine *var_r28;
    u8 var_r29;
    s32 var_r30;

    var_r28 = arg0;
    if (MKPropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (var_r28->IsField("Stage_01") == 0) {
        return 0;
    }
    var_r30 = 0;
    var_r26 = 0;
    var_r29 = 0;
    while (var_r29 == 0) {
        var_r22 = var_r28->unkC->GetSubLine(var_r28);
        var_r25 = (f32 *) ((u8 *) this + var_r26 + 0x60);
        var_r24 = (f32 *) ((u8 *) this + var_r26 + 0x64);
        var_r23 = (f32 *) ((u8 *) this + var_r26 + 0x68);
        while (var_r22 != NULL) {
            name = var_r22->GetFieldName();
            if (stricmp(name, (s8 *) "SpyroMaxSpeed") == 0) {
                var_r22->AsFloat(0, var_r25);
                *var_r25 = *var_r25 * 100.0f;
            } else if (stricmp(name, (s8 *) "TrainMaxSpeed") == 0) {
                var_r22->AsFloat(0, var_r24);
                *var_r24 = *var_r24 * 100.0f;
            } else if (stricmp(name, (s8 *) "DestroyCaboose") == 0) {
                var_r22->AsFloat(0, var_r23);
            }
            var_r22 = var_r22->unkC->GetNextLine(var_r22);
        }
        var_r30 += 1;
        var_r26 += 0xC;
        var_r28 = var_r28->unkC->GetNextLine(var_r28);
        if (var_r28->IsField((const char *) Str_Printf("Stage_%02d", var_r30 + 1)) == 0) {
            var_r29 = 1;
        }
    }
    return 1;
}

void TrainControllerDescriptor::Init() {
    s32 var_ctr_829;
    s32 var_r3_828;
    void *temp_r4_831;

    MKPropDescriptor::Init();
    var_r3_828 = 0;
    var_ctr_829 = 8;
    do {
        temp_r4_831 = this + var_r3_828;
        var_r3_828 += 0xC;
        M2C_FIELD(temp_r4_831, f32 *, 0x60) = 1.0f;
        M2C_FIELD(temp_r4_831, f32 *, 0x64) = 1.0f;
        M2C_FIELD(temp_r4_831, f32 *, 0x68) = -1.0f;
        var_ctr_829 -= 1;
    } while (var_ctr_829 != 0);
}

void TrainController_cpp::__sinit() {
    f32 temp_f0_891;
    f64 temp_f1_872;
    f64 temp_f1_880;
    f64 temp_f3_860;
    f64 temp_f4_869;
    f64 temp_f4_877;
    f64 temp_f8_862;

    temp_f3_860 = __frsqrte(2014000.0);
    temp_f8_862 = __frsqrte(380000.0);
    temp_f4_869 = 0.5 * temp_f3_860 * -((2014000.0 * (temp_f3_860 * temp_f3_860)) - 3.0);
    temp_f1_872 = 0.5 * temp_f8_862 * -((380000.0 * (temp_f8_862 * temp_f8_862)) - 3.0);
    temp_f4_877 = 0.5 * temp_f4_869 * -((2014000.0 * (temp_f4_869 * temp_f4_869)) - 3.0);
    temp_f1_880 = 0.5 * temp_f1_872 * -((380000.0 * (temp_f1_872 * temp_f1_872)) - 3.0);
    temp_f0_891 = (f32) (380000.0 * (0.5 * temp_f1_880 * -((380000.0 * (temp_f1_880 * temp_f1_880)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_877 * -((2014000.0 * (temp_f4_877 * temp_f4_877)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_891;
}
