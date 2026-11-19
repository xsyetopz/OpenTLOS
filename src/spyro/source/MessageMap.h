#ifndef SPYRO_SOURCE_MESSAGEMAP_H
#define SPYRO_SOURCE_MESSAGEMAP_H

#include <dolphin/types.h>

class MKIniLine;
class MessageMap;

class MessageMap {
public:
    s32 GetIdFromString(const char *) const;
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
};

s32 MessageMap_LoadLine(MKIniLine *, char *, int *);
extern u8 globalMessageStrings[0x310];
extern MessageMap globalMessageMap;
#endif  // SPYRO_SOURCE_MESSAGEMAP_H
