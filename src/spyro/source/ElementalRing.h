#ifndef SPYRO_SOURCE_ELEMENTALRING_H
#define SPYRO_SOURCE_ELEMENTALRING_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ElementalRing;
class ElementalRingDescriptor;
class KDSoundFlangedFader;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class ElementalRing : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElementalRing(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void Trigger(const MKVector3 &, const MKVector3 &, int, bool, MKProp *, float, float, float, float);
    /* 0x04c */ KDSoundFlangedFader** unk4C;
    /* 0x050 */ f32 unk50;
};

class ElementalRingDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
};

#endif  // SPYRO_SOURCE_ELEMENTALRING_H
