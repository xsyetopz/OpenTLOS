#ifndef SPYRO_SOURCE_UIMESSAGE_H
#define SPYRO_SOURCE_UIMESSAGE_H

#include <dolphin/types.h>

class MKIni;
class UIDataLine;
class UIEvent;
class UIMessage;
class UIObject;

class UIDataLine {
public:
    /* 0x000 */ u8 pad0[0xc];
    /* 0x00c */ MKIni* unkC;
};

class UIEvent {
public:
    s32 Send(void);
    void Resolve(UIObject *);
    s32 LoadLine(const char *, UIDataLine *);
    /* 0x000 */ void** unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s8* unk8;
};

class UIMessage {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
};

s32 GetScriptArgType(int);
s32 GetMessageFromString(const char *);
extern u8 UIMessageStrings[0x40];
extern u8 UIMessageArgType[0x40];
#endif  // SPYRO_SOURCE_UIMESSAGE_H
