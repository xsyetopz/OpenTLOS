#ifndef SPYRO_SOURCE_GAMECONSOLE_H
#define SPYRO_SOURCE_GAMECONSOLE_H

#include <dolphin/types.h>

class ConCmd;
class ConVar;
class MKInputEvent;

class ConCmd {
public:
    void SetAsBool(bool);
    void SetAsFloat(float);
    void SetAsInt(int);
    void SetAsString(const char *);
    void Compare(ConCmd *);
    s32 AsInt(void);
    f32 AsFloat(void);
    void Deinit(void);
    void Init(ConVar *);
    /* 0x000 */ u8** unk0;
    /* 0x004 */ ConCmd* unk4;
    /* 0x008 */ ConCmd* unk8;
    /* 0x00c */ u8* unkC;
    /* 0x010 */ s8 unk10;
};

class ConVar {
public:
    /* 0x000 */ u8* unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s8 unk18;
    /* 0x019 */ u8 pad19[0x167];
    /* 0x180 */ u8** unk180;
};

void Console_RemoveMacro(const char *);
void Console_AddMacro(const char *, const char *);
void Console_PurgeDelayedCmds(void);
void Console_UpdateDelayedCmds(void);
void Console_DiscardDelayedCmds(void);
s32 Console_GetLookupIndex(const char *);
void Console_RemoveCommand(ConCmd *);
void Console_AddCommand(ConCmd *);
s32 Console_InputReceiver(MKInputEvent *, void *);
void Console_ProcessInputEvent(MKInputEvent *);
s32 ReadString(char **, char *, int, int);
void Console_SetVarAsBool(const char *, bool);
void Console_BindEnable(bool);
void Console_UnbindAll(void);
void Console_Unbind(unsigned long);
void Console_Bind(unsigned long, const char *);
u8 * Console_GetBind(unsigned long);
ConCmd * Console_GetVarByName(const char *);
void Console_Write(const char *, int);
f32 Console_ExecuteBuffer(const char *);
f32 Console_Execute(const char *);
void Console_Unregister(ConVar *, int);
void Console_Register(ConVar *, int);
void Console_Print(const char *, ...);
void Console_Deinit(void);
void Console_Init(void);
#endif  // SPYRO_SOURCE_GAMECONSOLE_H
