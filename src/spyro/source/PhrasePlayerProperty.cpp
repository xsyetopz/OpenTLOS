#include "spyro/source/PhrasePlayerProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

#if 0 // DRAFT: expression syntax error
s32 stricmp(s8 *, M2C_UNK *);                       /* extern */

void PhrasePlayerProperty::Command(int arg0) {
    s32 temp_r31_52;
    void *temp_r30_51;

    switch (arg0) {                                 /* irregular */
    case 1:
        temp_r30_51 = KDProperty::pInstanceMem.__vptr;
        temp_r31_52 = this->unk8;
        *(temp_r30_51 + temp_r31_52) = PhrasePlayer_PlayEvent(this->unk4);
        return;
    case 2:
        PhrasePlayer_StopEvent(*(KDProperty::pInstanceMem.__vptr + this->unk8));
        return;
    case 3:
        PhrasePlayer_StopEvent(*(KDProperty::pInstanceMem.__vptr + this->unk8));
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 PhrasePlayerProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_108;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    if (stricmp(arg0, "Deactivate") == 0) {
        return 2;
    }
    temp_r3_108 = stricmp(arg0, "Reset") - 1;
    return 3 & ((temp_r3_108 - temp_r3_108) - !M2C_CARRY);
}
#endif
