#include "spyro/source/SpawnEffectBox.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
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
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDVolume.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/MessageMap.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(M2C_UNK *);                             /* extern */
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'sp38'
void *SpawnEffectBox::Update() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    MKModel *temp_r3_118;
    f32 temp_f29_71;
    f32 temp_f30_77;
    f32 temp_f30_85;
    f32 temp_f31_74;
    f32 temp_f31_90;
    f64 temp_f0_104;
    s32 temp_r5_126;
    void *temp_r31_117;

    if (((u8) this->unkF0 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkFC)) {
        this->unkFC = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float((int *) &gViewSeed, this->unkF4, this->unkF8);
        temp_f29_71 = this->unk50.GetWidth();
        temp_f31_74 = this->unk50.GetHeight();
        temp_f30_77 = this->unk50.GetDepth();
        ((KDVolume *) &sp30)->GetCenterPos();
        temp_f30_85 = MKRand_Float((int *) &gViewSeed, -temp_f30_77, temp_f30_77);
        temp_f31_90 = MKRand_Float((int *) &gViewSeed, -temp_f31_74, temp_f31_74);
        sp20 = MKRand_Float((int *) &gViewSeed, -temp_f29_71, temp_f29_71);
        sp24 = temp_f31_90;
        sp28 = temp_f30_85;
        sp40 = (f64) sp20;
        sp48 = (f64) sp28;
        temp_f0_104 = (f64) sp20 + sp30;
        sp10 = temp_f0_104;
        sp50 = temp_f0_104;
        sp18 = (f32) sp48 + sp38;
        sp58 = (f64) sp18;
        temp_r31_117 = *(this->unkE4 + (this->unkEC * 4));
        temp_r3_118 = M2C_FIELD(temp_r31_117, MKModel **, 4);
        if (temp_r3_118 != NULL) {
            MKModel_SetPosition(temp_r3_118, *((MKVector3 *) &sp50));
        }
        temp_r5_126 = M2C_FIELD(checked_cast<SpawnEffectBoxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60);
        spC = 0;
        sp8 = temp_r5_126;
        M2C_FIELD(M2C_FIELD(temp_r31_117, void **, 0x44), M2C_UNK (**)(void *, s32 *, s32), 0x2C)(temp_r31_117, &sp8, temp_r5_126);
        this->unkEC += 1;
        if ((s32) this->unkEC == (s32) this->unkE8) {
            this->unkEC = 0;
        }
    }
}
#endif

void SpawnEffectBox::Message(MKMessage *arg0) {
    s32 temp_r0_411;

    temp_r0_411 = arg0->unk0;
    switch (temp_r0_411) {                          /* irregular */
    case 0xB5:
        this->unkF0 = 1;
        this->unkFC = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float((int *) &gViewSeed, this->unkF4, this->unkF8);
        break;
    case 0xB4:
        this->unkF0 = 0;
        break;
    }
    MKProp::Message(arg0);
}

#if 0 // DRAFT: function call 'stricmp(const char[1])' does not match
s32 SpawnEffectBox::LoadDone() {
    s32 temp_r30_470;
    s32 var_r29_485;
    s32 var_r30_486;
    void *var_r3_478;

    MKProp::LoadDone();
    this->unk50.Init(*((Matrix *) &MKProp::loadInfo));
    if (((s8 *) this->unkE0 != NULL) && (stricmp("") == 0)) {
        this->unkE0 = NULL;
    }
    temp_r30_470 = this->unkE8 * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_478 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_470, NULL, 0);
    } else {
        var_r3_478 = malloc(temp_r30_470);
    }
    this->unkE4 = var_r3_478;
    var_r29_485 = 0;
    var_r30_486 = 0;
loop_8:
    if (var_r29_485 < (s32) this->unkE8) {
        gMK->CreatePropDeferred(this->unkE0, ((u8 *) this->unkE4) + var_r30_486);
        var_r29_485 += 1;
        var_r30_486 += 4;
        goto loop_8;
    }
    this->unkEC = 0;
    this->unkFC = 0.0f;
    this->unkFC = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float((int *) &gViewSeed, this->unkF4, this->unkF8);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 SpawnEffectBox::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r26_592;
    u8 var_r30_604;

    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadString("SpawnEffectName", &this->unkE0, 0) != 0) || (arg0->LoadInt("createCount", (int *) &this->unkE8, 0) != 0) || (arg0->LoadFloat("minSpawnEffectTime", &this->unkF4, 0) != 0) || (arg0->LoadFloat("maxSpawnEffectTime", &this->unkF8, 0) != 0) || (arg0->LoadBool("bInitiallyEnabled", &this->unkF0, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("box") != 0) {
        var_r26_592 = arg0->unkC->GetSubLine(arg0);
loop_15:
        if (var_r26_592 != NULL) {
            var_r30_604 = 0;
            if ((var_r26_592->LoadVector3("pos", (MKVector3 *) &MKProp::loadInfo.unk40, 0) != 0) || (var_r26_592->LoadVector3("rot", &MKProp::loadInfo + 0x50, 0) != 0)) {
                var_r30_604 = 1;
            }
            if (var_r30_604 == 0) {
                var_r26_592->LoadVector3("scale", &MKProp::loadInfo + 0x60, 0);
            }
            var_r26_592 = var_r26_592->unkC->GetNextLine(var_r26_592);
            goto loop_15;
        }
        return 1;
    }
    return 0;
}
#endif

void SpawnEffectBox::Deinit() {
    void *temp_r31_658;

    temp_r31_658 = this->unkE4;
    if (temp_r31_658 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_658, NULL, 0);
        } else {
            free(temp_r31_658);
        }
    }
    this->unk50.Deinit();
    MKProp::Deinit();
}

void SpawnEffectBox::Init() {
    MKProp::Init();
    this->unkE0 = NULL;
    this->unkE4 = NULL;
    this->unkE8 = 0;
    this->unkEC = 0;
    this->unkF0 = 0;
    this->unkF4 = 0.4f;
    this->unkF8 = 0.5f;
}

s32 SpawnEffectBoxDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_720;

    var_r31_720 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (MessageMap_LoadLine(arg0, "effectOnMessageID", (int *) &this->unk60) != 0)) {
        var_r31_720 = 1;
    }
    return var_r31_720;
}
