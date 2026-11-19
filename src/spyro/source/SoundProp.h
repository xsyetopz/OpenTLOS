#ifndef SPYRO_SOURCE_SOUNDPROP_H
#define SPYRO_SOURCE_SOUNDPROP_H

#include <dolphin/types.h>
#include "spyro/source/KDSoundProp.h"

class KDSoundProp;
class KDSoundPropDescriptor;
class MKIniLine;
class MKMessage;
class SoundProp;
class SoundPropDescriptor;

class SoundProp : public KDSoundProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SoundProp(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
};

class SoundPropDescriptor : public KDSoundPropDescriptor {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    /* 0x004 */ u8 pad4[0x8];
    /* 0x00c */ s32 unkC;
};

#endif  // SPYRO_SOURCE_SOUNDPROP_H
