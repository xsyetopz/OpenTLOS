#ifndef SPYRO_SOURCE_CHARACTERDESCRIPTOR_H
#define SPYRO_SOURCE_CHARACTERDESCRIPTOR_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/CollisionObject.h"

class CharacterDescriptor;
class ColObjDescriptor;
class MKIniLine;
class MKPropDescriptor;

class CharacterDescriptor : public MKPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ ColObjDescriptor unk7C;
    /* 0x0c8 */ u8 unkC8;
    /* 0x0c9 */ u8 padC9[0x3];
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ s32 unkD4;
    /* 0x0d8 */ u8 padD8[0x4];
    /* 0x0dc */ s8* unkDC;
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
};

#endif  // SPYRO_SOURCE_CHARACTERDESCRIPTOR_H
