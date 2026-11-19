#ifndef SPYRO_SOURCE_FLYINGCHUNKPS_H
#define SPYRO_SOURCE_FLYINGCHUNKPS_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GamePropColored.h"

class FlyingChunkPS;
class FlyingChunkPSDescriptor;
class GameProp;
class GamePropColoredDescriptor;
class MKIniLine;
class MKProp;
class MKVector3;
class MKVector4;
class Matrix;

class FlyingChunkPS : public GameProp {  // base: vtable prefix
public:
    virtual ~FlyingChunkPS(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    FlyingChunkPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const MKVector3 &, const MKVector3 &, float, const MKVector4 &, int, MKProp *);
    /* 0x0c8 */ u8 padC8[0x10];
    /* 0x0d8 */ Matrix** unkD8;
};

class FlyingChunkPSDescriptor : public GamePropColoredDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    FlyingChunkPSDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ MKVector3 unkF8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FlyingChunkPS::FlyingChunkPS() {
}

inline FlyingChunkPS::~FlyingChunkPS() {
}

inline FlyingChunkPSDescriptor::FlyingChunkPSDescriptor() {
}

#endif  // SPYRO_SOURCE_FLYINGCHUNKPS_H
