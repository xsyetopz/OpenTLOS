#include "spyro/source/DragonBustDoor.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/Door.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
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
#include "spyro/source/Trap.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

void DragonBustDoor::Deinit() {
    GameProp::Deinit();
}

void DragonBustDoor::Message(MKMessage *arg0) {
    u8 sp18;
    s32 sp14;
    s32 sp10;
    DragonBustDoor *spC;
    s32 sp8;
    s32 var_r28_67;
    s32 var_r29_65;
    s32 var_r31_64;
    void *temp_r30_69;
    void *temp_r3_71;

    if ((s32) arg0->unk0 != 0xB5) {
        Door::Message(arg0);
    } else {
        var_r31_64 = 0;
        var_r29_65 = 0;
        sp14 = 0;
        var_r28_67 = 0;
        do {
            temp_r30_69 = this + var_r31_64;
            temp_r3_71 = MKSceneManager::PropResolver_Resolve(M2C_FIELD(temp_r30_69, s32 *, 0xE8));
            if (temp_r3_71 != NULL) {
                sp10 = 0x4F;
                sp18 = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_71, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
                if (sp18 != 0) {
                    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r30_69, s32 *, 0xEC), 1U, 1U);
                    var_r29_65 += 1;
                }
            }
            var_r28_67 += 1;
            var_r31_64 += 8;
        } while (var_r28_67 < 4);
        if (var_r29_65 == 4) {
            spC = NULL;
            sp8 = 0xB5;
            spC = this;
            Door::Message((MKMessage *) &sp8);
        }
    }
}

void DragonBustDoor::Draw() {
    GameProp::Draw();
}

void *DragonBustDoor::Update() {
    Door::Update();
}

#if 0 // DRAFT: identifier 'DragonBustDoor::LoadDone()' redeclared was declared as: 'long ()' now declared as: 'void ()'
void DragonBustDoor::LoadDone() {
    s32 var_r30_184;
    s32 var_r31_186;

    Trap::LoadDone();
    this->unkEC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightYellow");
    this->unkF4 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightRed");
    this->unkFC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightGreen");
    var_r30_184 = 0;
    this->unk104 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightBlue");
    var_r31_186 = 0;
    do {
        MKModel_EnableSubObject((MKModel *) this->unk4, (SubObjectType) 0, *(s32 *) ((u8 *) this + var_r31_186 + 0xEC), 0, 1U);
        var_r30_184 += 1;
        var_r31_186 += 8;
    } while (var_r30_184 < 4);
}
#endif

s32 DragonBustDoor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_215;

    var_r31_215 = 0;
    if ((Trap::LoadLine(arg0) != 0) || (arg0->LoadInt("YellowSwitchID", (int *) &this->unkE8, 0) != 0) || (arg0->LoadInt("RedSwitchID", (int *) &this->unkF0, 0) != 0) || (arg0->LoadInt("GreenSwitchID", (int *) &this->unkF8, 0) != 0) || (arg0->LoadInt("BlueSwitchID", (int *) &this->unk100, 0) != 0)) {
        var_r31_215 = 1;
    }
    return var_r31_215;
}

void DragonBustDoor::Init() {
    s32 var_ctr_278;
    s32 var_r3_276;
    void *temp_r5_280;

    Door::Init();
    var_r3_276 = 0;
    var_ctr_278 = 4;
    do {
        temp_r5_280 = this + var_r3_276;
        var_r3_276 += 8;
        M2C_FIELD(temp_r5_280, s32 *, 0xE8) = -1;
        M2C_FIELD(temp_r5_280, s32 *, 0xEC) = -1;
        var_ctr_278 -= 1;
    } while (var_ctr_278 != 0);
}
