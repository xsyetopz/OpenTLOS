#ifndef SPYRO_SOURCE_GAMECAMERAMESSAGES_H
#define SPYRO_SOURCE_GAMECAMERAMESSAGES_H

#include <dolphin/types.h>

class AddCameraTrackedShakePropMessage;
class MKProp;

class AddCameraTrackedShakePropMessage {
public:
    void Init(MKProp *, float, float, bool, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKProp* unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s8 unk14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ f32 unk18;
};

#endif  // SPYRO_SOURCE_GAMECAMERAMESSAGES_H
