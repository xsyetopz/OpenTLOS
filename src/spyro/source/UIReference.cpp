#include "spyro/source/UIReference.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void UIReference::Draw(const RenderContext &arg0) {
    void **temp_r3_42;
    if (((void **) this->unk60 != NULL) && ((u8) this->unk64 == 0)) {
        this->unk64 = 1;
        arg_sp10.RenderContext(arg0, this->unk18);
        temp_r3_42 = this->unk60;
        M2C_FIELD(*temp_r3_42, M2C_UNK (**)(void **, M2C_UNK *), 0x1C)(temp_r3_42, &arg_sp10);
        this->unk64 = 0;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void **' to
void UIReference::Resolve() {
    void **temp_r31_68;

    UIObject::Resolve();
    temp_r31_68 = this->unk60;
    if (temp_r31_68 != NULL) {
        this->unk60 = Find(temp_r31_68);
        UIStringTable_Remove((s8 *) temp_r31_68);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'LoadString'
s32 UIReference::LoadLine(UIDataLine *arg0) {
    s8 *sp8;

    sp8 = NULL;
    if (arg0->LoadString("target", &sp8, 0) != 0) {
        UIStringTable_Add(sp8);
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    return UIObject::LoadLine(arg0);
}
#endif

void UIReference::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk64 = 0;
}
