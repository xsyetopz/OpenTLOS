#ifndef COMMON_SOURCE_MKANIMSCRIPT_H
#define COMMON_SOURCE_MKANIMSCRIPT_H

#include <dolphin/types.h>

class Animation;
class MKAnim;
class MKAnimScript;
class MKAnimScriptTemplate;
class MKAnimScript_AnimInfo;
class MKAnimScript_LVECalc;
class MKAnimScriptedEvent;
class MKIni;
class MKIniLine;
class MKModel;
class MKResource;
class MKVector3;

class MKAnimScriptedEvent {
public:
    class AnimationSwitch;
    class EventType;
    void FreeMaterial(void);
    s32 GetStringSizeOfEvent(MKIniLine *);
    u8 ParseEvent(MKIniLine *, char *);
    u8 ParseAliasMaterialEvent(MKIniLine *, char *);
    u8 ParseSubObjectEvent(MKIniLine *, char *);
    u8 ParseSoundEvent(MKIniLine *, char *);
    u8 ParseCodeEvent(MKIniLine *, char *);
    u8 ParseFrameNo(MKIniLine *);
    u8 ParseEventType(MKIniLine *);
    static u8 pSrcAnim[0x4];
    static u8 pSoundEventKeyWord[0x4];
    static u8 pSubObjectEnableEventKeyWord[0x4];
    static u8 pSubObjectDisableEventKeyWord[0x4];
    static u8 pSubObjectEnableAllEventKeyWord[0x4];
    static u8 pSubObjectDisableAllEventKeyWord[0x4];
    static u8 pAliasMaterialEventKeyWord[0x4];
    static u8 pOnEnterKeyWord[0x4];
    static u8 pOnExitKeyWord[0x4];
    /* 0x000 */ MKAnim* unk0;
    /* 0x004 */ s16 unk4;
    /* 0x006 */ s16 unk6;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
};

class MKAnim {
public:
    s16 GetNumberOfEvents(MKAnimScriptedEvent::EventType);
    MKAnimScriptedEvent * GetFirstEvent(MKAnimScriptedEvent::EventType);
    /* 0x000 */ s8 unk0;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ s16 unk4;
    /* 0x006 */ s16 unk6;
    /* 0x008 */ s8 unk8;
    /* 0x009 */ u8 pad9[0x1];
    /* 0x00a */ s16 unkA;
    /* 0x00c */ s16 unkC;
    /* 0x00e */ s16 unkE;
    /* 0x010 */ MKAnimScriptedEvent* unk10;
    /* 0x014 */ s16 unk14;
    /* 0x016 */ u8 pad16[0x2];
    /* 0x018 */ MKAnimScriptedEvent* unk18;
    /* 0x01c */ s16 unk1C;
    /* 0x01e */ u8 pad1E[0x2];
    /* 0x020 */ MKAnimScriptedEvent* unk20;
    /* 0x024 */ s16 unk24;
    /* 0x026 */ u8 pad26[0x2];
    /* 0x028 */ MKAnimScriptedEvent* unk28;
    /* 0x02c */ s32 unk2C;
};

class MKAnimScript {
public:
    void SetCurrentFrame(float, bool);
    MKResource * GetName(void);
    void SetAnimation(Animation *);
    void SetCurrentFrame(int);
    s32 GetCurrentFrame(void);
    void GetStartAndEnd(MKAnim *, short *, short *);
    void JumpToPos(float, int);
    void Destroy(void);
    MKAnimScript * Create(const char *, int);
    void Apply(Animation *, int);
    void Animate(Animation *, int, MKVector3 *);
    void Check(int, int, MKAnimScriptedEvent &);
    void CheckSwitch(MKAnimScriptedEvent::AnimationSwitch);
    void CheckEvents(void);
    u8 CheckEvent(int);
    void InitEvents(const char **);
    s32 GetEvent(int, MKAnimScriptedEvent::EventType);
    s8 * GetEventByName(const char *, MKAnimScriptedEvent::EventType);
    void SetAnim(MKAnim *, float, float, int, int);
    void ReadBinary(const char *);
    void Init(const char *, MKModel *);
    s8 * GetAnimName(void);
    s8 * GetMeshName(void);
    s32 Exists(const char *);
    void * GetAnim(int);
    void * GetAnim(const char *);
    void Deinit(void);
    void Init(MKAnimScript *, MKModel *);
    void SetupAliasMaterials(void);
    void CalculateSubObjectIndices(void);
    MKAnimScript(void);
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ MKResource* unk4;
    /* 0x008 */ MKModel* unk8;
    /* 0x00c */ Animation* unkC;
    /* 0x010 */ MKAnim* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ u32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
};

class MKAnimScriptTemplate {
public:
    void DeinitMKAnimScriptData(void);
    /* 0x000 */ u8 pad0[0x34];
    /* 0x034 */ void* unk34;
};

class MKAnimScript_AnimInfo {
public:
    u8 Animate(float, MKAnimScript_LVECalc *);
    /* 0x000 */ void* unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
};

class MKAnimScript_LVECalc {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ s8 unk10;
};

MKResource * ParseBadFile(MKIni *, const char *, MKModel *);
void MKAnimScript_DeinitModule(void);
void MKAnimScript_InitModule(void);
extern MKResource ** mkAnimScriptTemplates;
#endif  // COMMON_SOURCE_MKANIMSCRIPT_H
