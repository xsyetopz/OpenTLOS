#ifndef SPYRO_SOURCE_UISTRINGTABLE_H
#define SPYRO_SOURCE_UISTRINGTABLE_H

#include <dolphin/types.h>

class MKStringCache;
class UIStringTable;

class UIStringTable {
public:
    s32 Remove(const char *);
    s32 Add(const char *);
    void Deinit(void);
    void Init(int);
    UIStringTable(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ MKStringCache* unk4;
};

void UIStringTable_Remove(const char *);
void UIStringTable_Add(const char *);
UIStringTable * UIStringTable_GetCurrent(void);
UIStringTable * UIStringTable_SetCurrent(UIStringTable *);
#endif  // SPYRO_SOURCE_UISTRINGTABLE_H
