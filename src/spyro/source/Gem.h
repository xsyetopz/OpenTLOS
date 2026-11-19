#ifndef SPYRO_SOURCE_GEM_H
#define SPYRO_SOURCE_GEM_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/Collectable.h"

class Collectable;
class CollectableState;
class Gem;
class GemDescriptor;
class Gem_cpp;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKPropDescriptor;
class MKVector3;

class Gem : public Collectable {  // base: ctor/dtor vtable stores
public:
    virtual ~Gem(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void GetDescriptor(void);
    virtual void Spawn(const MKVector3 *, const MKVector3 *, bool);
    virtual void CollectEffects(void);
    virtual void SetState(CollectableState);
    virtual void CollectingStateInit(void);
    /* 0x145 */ u8 pad145[0x3];
    /* 0x148 */ s32 unk148;
};

class GemDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x1e];
    /* 0x066 */ s8 unk66;
    /* 0x067 */ u8 pad67[0x5];
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ u8 pad70[0x4];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x1c];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ u8 padA0[0x28];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ MKMaterial* unkD4;
};

class Gem_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_GEM_H
