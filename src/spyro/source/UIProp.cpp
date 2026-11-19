#include "spyro/source/UIProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UISystem.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK free(void **);                              /* extern */
UIObject *malloc(void *);                           /* extern */
extern void **gMK;

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void UIProp::Draw() {
    void **temp_r3_54;
    MKProp::Draw();
    arg_sp10.Tools_Ortho();
    arg_sp20.RenderContext();
    temp_r3_54 = this->unk54;
    if (temp_r3_54 != NULL) {
        M2C_FIELD(*temp_r3_54, M2C_UNK (**)(M2C_UNK *), 0x1C)(&arg_sp20);
    }
    arg_sp10.~Tools_Ortho(-1);
}
#endif

void UIProp::Update() {
    void **temp_r3_83;

    MKProp::Update();
    temp_r3_83 = this->unk54;
    if (temp_r3_83 != NULL) {
        M2C_FIELD(*temp_r3_83, M2C_UNK (**)(), 0x18)();
    }
}

#if 0 // DRAFT: expression syntax error
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
        this->unk54->PushScreen(M2C_FIELD(checked_cast<ScreenMsg *, MKMessage>(arg0), s8 **, 8));
        break;
    case 0x80:
        this->unk54->ChangeScreen(M2C_FIELD(checked_cast<ScreenMsg *, MKMessage>(arg0), s8 **, 8));
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

#if 0 // DRAFT: illegal implicit conversion from 'UIStringTable *' to
void UIProp::LoadDone() {
    MKHeap *temp_r3_194;
    MKHeap *temp_r3_199;
    UIObject *var_r31_207;
    void **temp_r3_237;
    void **temp_r3_242;
    void **temp_r3_247;
    void *temp_r31_198;

    MKProp::LoadDone();
    this->unk58.Init(this->unk4C);
    temp_r3_194 = UIStringTable_SetCurrent(&this->unk58);
    temp_r31_198 = descriptor.unk8;
    temp_r3_199 = temp_r3_194->Current();
    if (temp_r3_199 != NULL) {
        var_r31_207 = ((MKHeap *) (temp_r3_199->Current()))->Alloc((s32) temp_r31_198, NULL, 0);
    } else {
        var_r31_207 = malloc(temp_r31_198);
    }
    ((M2C_UNK (*)(UIObject *, UISystem *)) descriptor.unkC)(var_r31_207, &descriptor);
    var_r31_207->unk8 = &descriptor;
    var_r31_207->Init(&descriptor);
    this->unk54 = checked_cast<UISystem *, UIObject>(var_r31_207);
    if (this->unk54->Load(this->unk50, NULL) != 0) {
        temp_r3_237 = this->unk54;
        M2C_FIELD(*temp_r3_237, M2C_UNK (**)(void **), 0x14)(temp_r3_237);
        temp_r3_242 = this->unk54;
        M2C_FIELD(*temp_r3_242, M2C_UNK (**)(void **), 0x28)(temp_r3_242);
        temp_r3_247 = this->unk54;
        M2C_FIELD(*temp_r3_247, M2C_UNK (**)(void **), 0x20)(temp_r3_247);
    }
    UIStringTable_SetCurrent((UIStringTable *) temp_r3_194);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 UIProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_271;

    var_r31_271 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("stringTableSize", &this->unk4C, 0) != 0) || (arg0->LoadString("fileName", &this->unk50, 0) != 0)) {
        var_r31_271 = 1;
    }
    return var_r31_271;
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r30_314'
void UIProp::Deinit() {
    MKHeap *temp_r3_328;
    UIStringTable *temp_r30_314;
    void **temp_r0_313;
    void **temp_r31_322;

    temp_r0_313 = this->unk54;
    temp_r30_314 = UIStringTable_SetCurrent(&this->unk58);
    if (temp_r0_313 != NULL) {
        M2C_FIELD(*temp_r0_313, M2C_UNK (**)(void **), 0x24)(temp_r0_313);
        temp_r31_322 = this->unk54;
        temp_r3_328 = ((MKHeap *) (M2C_FIELD(*temp_r31_322, MKHeap *(**)(void **), 0xC)(temp_r31_322)))->Current();
        if (temp_r3_328 != NULL) {
            ((MKHeap *) (temp_r3_328->Current()))->Free(temp_r31_322, NULL, 0);
        } else {
            free(temp_r31_322);
        }
        this->unk54 = NULL;
    }
    UIStringTable_SetCurrent(temp_r30_314);
    this->unk58.Deinit();
    MKProp::Deinit();
}
#endif

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
