#ifndef SPYRO_SOURCE_CUTSCENEOBJECT_H
#define SPYRO_SOURCE_CUTSCENEOBJECT_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/EventMessage.h"

class CutsceneObject;
class EventMessage;
class MKIniLine;
class MKVector3;

class CutsceneObject {
public:
    s32 Skippable(void);
    void GetFileName(char *);
    void StopEvent(void);
    void PlayEvent(void);
    void End(void);
    void ReturnToGame(void);
    void Begin(void);
    s32 GetNumber(void);
    void Update(void);
    void Resolve(void);
    s32 LoadSubLine(MKIniLine *);
    s32 LoadLine(MKIniLine *);
    ~CutsceneObject(void);
    CutsceneObject(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ MKVector3 unk20;
    /* 0x030 */ EventMessage unk30;
    /* 0x034 */ EventMessage unk34;
    /* 0x038 */ EventMessage unk38;
    /* 0x03c */ EventMessage unk3C;
    /* 0x040 */ EventMessage unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s8* unk54;
    /* 0x058 */ u8 unk58;
    /* 0x059 */ u8 unk59;
    /* 0x05a */ s8 unk5A;
    /* 0x05b */ u8 unk5B;
    /* 0x05c */ u8 unk5C;
    /* 0x05d */ u8 unk5D;
    /* 0x05e */ u8 unk5E;
    /* 0x05f */ u8 unk5F;
    /* 0x060 */ u8 unk60;
    /* 0x061 */ u8 unk61;
    /* 0x062 */ u8 unk62;
    /* 0x063 */ u8 unk63;
};

s8 * MakeCutsceneFilename(int, const char *, char *, bool);
#endif  // SPYRO_SOURCE_CUTSCENEOBJECT_H
