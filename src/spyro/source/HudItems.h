#ifndef SPYRO_SOURCE_HUDITEMS_H
#define SPYRO_SOURCE_HUDITEMS_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class HudItem;

class HudItem {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 unk18;
    /* 0x019 */ u8 unk19;
};

void HudItem_Fixed(HudItem *, bool);
void HudItem_Modified(HudItem *);
void HudItem_Draw(HudItem *);
u8 HudItem_Update(HudItem *);
void HudItem_SetState(HudItem *, HudItemState, bool);
#endif  // SPYRO_SOURCE_HUDITEMS_H
