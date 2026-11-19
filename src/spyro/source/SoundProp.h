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

class SoundPropDescriptor : public KDSoundPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline SoundProp::~SoundProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (&this->unkA0 != NULL) {
                KDSound_Stop(&this->unkA0);
            }
            if (this != NULL) {
            }
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_SOUNDPROP_H
