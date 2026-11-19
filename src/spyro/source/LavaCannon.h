#ifndef SPYRO_SOURCE_LAVACANNON_H
#define SPYRO_SOURCE_LAVACANNON_H

#include <dolphin/types.h>
#include "spyro/source/AnimUtils.h"
#include "spyro/source/Shatterable.h"

class AnimEventDesc;
class AnimEventEntry;
class LavaCannon;
class LavaCannonDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;

class AnimEventEntry {
public:
    /* 0x000 */ s8* unk0;
};

class LavaCannon : public Shatterable {  // base: vtable prefix
public:
    virtual ~LavaCannon(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *);
    LavaCannon(void);
    void EmitExplodingEffects(void);
    void EmitFiringEffects(void);
    void SetState(int);
};

class LavaCannonDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    LavaCannonDescriptor(void);
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ s32 unk178;
    /* 0x17c */ s32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ s32 unk198;
    /* 0x19c */ s32 unk19C;
    /* 0x1a0 */ u8 pad1A0[0x4];
    /* 0x1a4 */ AnimEventDesc unk1A4;
    /* 0x1ac */ AnimEventEntry unk1AC;
    /* 0x1b0 */ u8 pad1B0[0x4];
    /* 0x1b4 */ s8* unk1B4;
};

#endif  // SPYRO_SOURCE_LAVACANNON_H
