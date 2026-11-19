#ifndef SPYRO_SOURCE_CHECKPOINT_H
#define SPYRO_SOURCE_CHECKPOINT_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/KDProp.h"

class CheckPoint;
class CheckPointDescriptor;
class ChunkInfo;
class KDProp;
class KDPropDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class checkpoint_cpp;

class CheckPoint : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CheckPoint(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void SetCurrentCheckPoint(CheckPoint *);
    /* 0x089 */ u8 pad89[0x47];
    /* 0x0d0 */ MKVector3 unkD0;
    /* 0x0e0 */ MKVector3 unkE0;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f64 unkF8;
    /* 0x100 */ u8 pad100[0x50];
    /* 0x150 */ s32 unk150;
    /* 0x154 */ u8 pad154[0x3c];
    /* 0x190 */ s32 unk190;
    /* 0x194 */ u8 pad194[0x24];
    /* 0x1b8 */ ChunkInfo* unk1B8;
    /* 0x1bc */ s32 unk1BC;
    /* 0x1c0 */ u8 unk1C0;
    /* 0x1c1 */ u8 unk1C1;
    /* 0x1c2 */ u8 unk1C2;
};

class CheckPointDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
};

class checkpoint_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_CHECKPOINT_H
