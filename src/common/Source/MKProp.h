#ifndef COMMON_SOURCE_MKPROP_H
#define COMMON_SOURCE_MKPROP_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"

class BoundingVolume;
class MKIni;
class MKIniLine;
class MKMessage;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKPropLoadInfo;
class MKVector3;
class MKVector4;

class MKProp {
public:
    /* 0x000 */ void* unk0;
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ BoundingVolume* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ u8 pad1C[0x2];
    /* 0x01e */ s16 unk1E;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ MKProp* unk28;
    /* 0x02c */ MKProp* unk2C;
    /* 0x030 */ MKProp* unk30;
    /* 0x034 */ MKProp* unk34;
    /* 0x038 */ MKProp* unk38;
    /* 0x03c */ MKProp* unk3C;
    /* 0x040 */ s8 unk40;
    /* 0x041 */ u8 pad41[0x3];
    virtual ~MKProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    void GetPos(void);
    void GetDir(void);
    MKProp(void);
    static MKProp loadInfo;
    /* 0x048 */ f32 unk48;
};

class MKPropDescriptor {
public:
    /* 0x000 */ s8* unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ BoundingVolume* unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ void* unk28;
    /* 0x02c */ MKModel* unk2C;
    /* 0x030 */ s8* unk30;
    /* 0x034 */ s8* unk34;
    /* 0x038 */ s8* unk38;
    /* 0x03c */ s32 unk3C;
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Resolve(void);
    void * CreateInstance(void);
    void ParseGMSection(MKIni *, MKIniLine *);
    /* 0x044 */ MKPropDescriptor* unk44;
};

class MKPropLoadInfo {
public:
    void LoadDone(void);
    s32 LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ u8 pad0[0x30];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ MKVector3 unk50;
    /* 0x060 */ MKVector3 unk60;
    /* 0x070 */ MKVector4 unk70;
};

#endif  // COMMON_SOURCE_MKPROP_H
