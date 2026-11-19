#include "spyro/source/UIProp.h"
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
#include "common/Source/MKStringCache.h"
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
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UISystem.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK free(void **);                              /* extern */
UIObject *malloc(s32);                              /* extern */
extern void **gMK;

#if 0 // DRAFT: ')' expected
void UIProp::Draw() {
    RenderContext sp20;
    Tools_Ortho sp10;
    void **temp_r3_54;

    MKProp::Draw();
    sp10.Tools_Ortho();
    sp20.RenderContext();
    temp_r3_54 = this->unk54;
    if (temp_r3_54 != NULL) {
        M2C_FIELD(*temp_r3_54, M2C_UNK (**)(RenderContext *), 0x1C)(&sp20);
    }
    sp10.~Tools_Ortho(-1);
}
#endif

void *UIProp::Update() {
    void **temp_r3_83;

    MKProp::Update();
    temp_r3_83 = this->unk54;
    if (temp_r3_83 != NULL) {
        M2C_FIELD(*temp_r3_83, M2C_UNK (**)(), 0x18)();
    }
}

#if 0 // DRAFT: ')' expected
void UIProp::Message(MKMessage *arg0) {
    s32 sp8;
    s32 temp_r0_107;
    void **temp_r3_117;

    temp_r0_107 = arg0->unk0;
    switch (temp_r0_107) {                          /* irregular */
    case 0x7E:
        temp_r3_117 = this->unk54;
        sp8 = 0xF;
        M2C_FIELD(*temp_r3_117, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_117, &sp8);
        break;
    case 0x7F:
        ((UISystem *) this->unk54)->PushScreen(M2C_FIELD(checked_cast<ScreenMsg *, MKMessage>(arg0), s8 **, 8));
        break;
    case 0x80:
        ((UISystem *) this->unk54)->ChangeScreen(M2C_FIELD(checked_cast<ScreenMsg *, MKMessage>(arg0), s8 **, 8));
        break;
    }
    MKProp::Message(arg0);
}
#endif

void UIProp::Reset() {
    s32 spC;
    s32 sp8;
    void **temp_r3_161;

    MKProp::Reset();
    temp_r3_161 = this->unk54;
    if (temp_r3_161 != NULL) {
        sp8 = 1;
        spC = 0;
        M2C_FIELD(*temp_r3_161, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}

#if 0 // DRAFT: function call 'Init(UIObject *, unsigned char[20])' does not match 'UIObject::Init()'
s32 UIProp::LoadDone() {
    UIObject *var_r31_207;
    UIStringTable *temp_r30_196;
    s32 temp_r31_198;
    void **temp_r3_237;
    void **temp_r3_242;
    void **temp_r3_247;

    MKProp::LoadDone();
    this->unk58.Init(this->unk4C);
    temp_r30_196 = UIStringTable_SetCurrent(&this->unk58);
    temp_r31_198 = M2C_FIELD(UISystem::descriptor, s32 *, 8);
    if (MKHeap::Current() != NULL) {
        var_r31_207 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_198, NULL, 0));
    } else {
        var_r31_207 = malloc(temp_r31_198);
    }
    M2C_FIELD(UISystem::descriptor, M2C_UNK (**)(UIObject *, u8 *), 0xC)(var_r31_207, UISystem::descriptor);
    var_r31_207->unk8 = UISystem::descriptor;
    var_r31_207->Init(UISystem::descriptor);
    this->unk54 = (void **) (checked_cast<UISystem *, UIObject>(var_r31_207));
    if (((UIObject *) this->unk54)->Load(this->unk50, NULL) != 0) {
        temp_r3_237 = this->unk54;
        M2C_FIELD(*temp_r3_237, M2C_UNK (**)(void **), 0x14)(temp_r3_237);
        temp_r3_242 = this->unk54;
        M2C_FIELD(*temp_r3_242, M2C_UNK (**)(void **), 0x28)(temp_r3_242);
        temp_r3_247 = this->unk54;
        M2C_FIELD(*temp_r3_247, M2C_UNK (**)(void **), 0x20)(temp_r3_247);
    }
    UIStringTable_SetCurrent(temp_r30_196);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
s32 UIProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_271;

    var_r31_271 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("stringTableSize", (int *) &this->unk4C, 0) != 0) || (arg0->LoadString("fileName", &this->unk50, 0) != 0)) {
        var_r31_271 = 1;
    }
    return var_r31_271;
}
#endif

void UIProp::Deinit() {
    UIStringTable *temp_r30_314;
    void **temp_r0_313;
    void **temp_r31_322;

    temp_r0_313 = this->unk54;
    temp_r30_314 = UIStringTable_SetCurrent(&this->unk58);
    if (temp_r0_313 != NULL) {
        M2C_FIELD(*temp_r0_313, M2C_UNK (**)(void **), 0x24)(temp_r0_313);
        temp_r31_322 = this->unk54;
        M2C_FIELD(*temp_r31_322, M2C_UNK (**)(void **), 0xC)(temp_r31_322);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_322, NULL, 0);
        } else {
            free(temp_r31_322);
        }
        this->unk54 = NULL;
    }
    UIStringTable_SetCurrent(temp_r30_314);
    this->unk58.Deinit();
    MKProp::Deinit();
}

#if 0 // DRAFT: undefined identifier 'unk8'
void UIProp::Init() {
    MKProp::Init();
    this->unk54 = NULL;
    this->unk50 = NULL;
    this->unk4C = 0x800;
    this->unk58.unk8 = M2C_FIELD(*gMK, s32 (**)(void **), 0x7C)(gMK);
}
#endif

void UIPropDescriptor::Init() {
    MKPropDescriptor::Init();
}
