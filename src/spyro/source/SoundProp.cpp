#include "spyro/source/SoundProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDSoundProp.h"
#include "spyro/source/GameEnums.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern void **gMK;

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void SoundProp::Disable() {
    if ((s32) this->unk4C != 0) {
        KDSound_Stop((s32 *) &this->unk60.unk40);
        this->unk4C = 0;
    }
}
#endif

void SoundProp::Enable() {
    this->unk4C = 1;
}

#if 0 // DRAFT: undefined identifier 'sWorkingChunkID'
void SoundProp::Message(MKMessage *arg0) {
    s32 temp_r0_89;

    temp_r0_89 = arg0->unk0;
    switch (temp_r0_89) {                           /* irregular */
    case 0x1F:
    case 0x1C:
        if (M2C_FIELD(*gMK, u8 (**)(void **, SoundProp *, s32), 0x9C)(gMK, this, sWorkingChunkID.unk0) != 0) {
        case 0xB4:
        case 0xBF:
            Disable();
        }
        break;
    case 0x1D:
        if (M2C_FIELD(*gMK, u8 (**)(void **, SoundProp *, s32), 0x9C)(gMK, this, sWorkingChunkID.unk0) != 0) {
        case 0xBE:
        case 0xB5:
            Enable();
        }
        break;
    }
    this->unk60.unk40.Message(arg0);
    KDSoundProp::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'PropTypes_LoadLine(MKIniLine *, const char[11], long *)'
s32 SoundPropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_171;

    var_r31_171 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (PropTypes_LoadLine(arg0, "searchMask", &this->unkC) != 0)) {
        var_r31_171 = 1;
    }
    return var_r31_171;
}
#endif
