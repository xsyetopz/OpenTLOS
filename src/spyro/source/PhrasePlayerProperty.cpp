#include "spyro/source/PhrasePlayerProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */

void PhrasePlayerProperty::Command(int arg0) {
    u8 *temp_r30_51;
    s32 temp_r31_52;

    switch (arg0) {
    case 1:
        temp_r30_51 = *(u8 **) KDProperty::pInstanceMem;
        temp_r31_52 = this->unk8;
        *(s32 *) (temp_r30_51 + temp_r31_52) = PhrasePlayer_PlayEvent((const char *) this->unk4);
        return;
    case 2:
        PhrasePlayer_StopEvent(*(s32 *) (*(u8 **) KDProperty::pInstanceMem + this->unk8));
        return;
    case 3:
        PhrasePlayer_StopEvent(*(s32 *) (*(u8 **) KDProperty::pInstanceMem + this->unk8));
        return;
    }
}

s32 PhrasePlayerProperty::ResolveCommand(const char *arg0) const {
    s32 stricmp(const char *, const char *);
    s32 temp_r3_108;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    if (stricmp(arg0, "Deactivate") == 0) {
        return 2;
    }
    temp_r3_108 = stricmp(arg0, "Reset");
    return (temp_r3_108 == 0) ? 3 : 0;
}
