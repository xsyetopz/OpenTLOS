#ifndef SPYRO_SOURCE_PLATFORMOBJECT_H
#define SPYRO_SOURCE_PLATFORMOBJECT_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/SeeSaw.h"

class MKCollisionInfo;
class MKMessage;
class MKProp;
class MKVector3;
class PlatformAttachment;
class PlatformObject;
class PlatformObjectDesc;

class PlatformObject {
public:
    void GetNumActorsAttached(void);
    void SimpleMessageAttached(int);
    void DetachAll(void);
    s8 Detach(PlatformAttachment *);
    s8 Attach(PlatformAttachment *);
    void UpdateAttached(void);
    void UpdateRotationMatrix(void);
    void UpdateTilt(void);
    void EndUpdate(void);
    void BeginUpdate(void);
    void Message(MKMessage *);
    void Reset(void);
    void LoadDone(MKProp *, MKVector3 *);
    void Deinit(void);
    void Init(PlatformObjectDesc *, MKCollisionInfo *);
    /* 0x000 */ PlatformObjectDesc* unk0;
    /* 0x004 */ MKCollisionInfo* unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ MKVector3 unk18;
    /* 0x028 */ PlatformAttachment unk28;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ void* unk3C;
    /* 0x040 */ MKProp* unk40;
};

class PlatformObjectDesc {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 unk11;
};

#endif  // SPYRO_SOURCE_PLATFORMOBJECT_H
