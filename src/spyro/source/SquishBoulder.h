#ifndef SPYRO_SOURCE_SQUISHBOULDER_H
#define SPYRO_SOURCE_SQUISHBOULDER_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKMessage;
class MKProp;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;
class SquishBoulder;
class SquishBoulderDescriptor;

class SquishBoulder : public Shatterable {  // base: vtable prefix
public:
    virtual ~SquishBoulder(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    SquishBoulder(void);
    void EmitLandingEffects(void);
    void Trigger(const MKVector3 &, const MKVector3 &, float, MKProp *);
};

class SquishBoulderDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    SquishBoulderDescriptor(void);
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ void* unk170;
};

#endif  // SPYRO_SOURCE_SQUISHBOULDER_H
