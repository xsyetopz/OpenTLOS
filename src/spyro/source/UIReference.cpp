#include "spyro/source/UIReference.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

void UIReference::Draw(const RenderContext &arg0) {
    RenderContext sp10;
    void **temp_r3_42;

    if (((void **) this->unk60 != NULL) && ((u8) this->unk64 == 0)) {
        this->unk64 = 1;
        sp10.RenderContext(arg0, this->unk18);
        temp_r3_42 = this->unk60;
        M2C_FIELD(*temp_r3_42, M2C_UNK (**)(void **, RenderContext *), 0x1C)(temp_r3_42, &sp10);
        this->unk64 = 0;
    }
}

void UIReference::Resolve() {
    void **temp_r31_68;

    UIObject::Resolve();
    temp_r31_68 = this->unk60;
    if (temp_r31_68 != NULL) {
        this->unk60 = (void **) (Find((const char *) temp_r31_68));
        UIStringTable_Remove((const char *) temp_r31_68);
    }
}

s32 UIReference::LoadLine(UIDataLine *arg0) {
    const char *sp8;

    sp8 = NULL;
    if (((MKIniLine *) arg0)->LoadString("target", &sp8, 0) != 0) {
        this->unk60 = (void **) ((s32 (*)(const char *)) UIStringTable_Add)(sp8);
        return 1;
    }
    return UIObject::LoadLine(arg0);
}

void UIReference::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk64 = 0;
}
