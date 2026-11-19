#ifndef SPYRO_SOURCE_FIREMOLEPRISON_H
#define SPYRO_SOURCE_FIREMOLEPRISON_H

#include <dolphin/types.h>
#include "spyro/source/shatterwaypointspawn.h"

class FireMolePrison;
class MKMessage;
class ShatterWaypointSpawn;

class FireMolePrison : public ShatterWaypointSpawn {  // base: vtable prefix
public:
    virtual ~FireMolePrison(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    FireMolePrison(void);
    /* 0x204 */ u8 pad204[0x4];
    /* 0x208 */ s32 unk208;
    /* 0x20c */ f32 unk20C;
    /* 0x210 */ u8 unk210;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline FireMolePrison::FireMolePrison() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline FireMolePrison::~FireMolePrison() {
    this->unkC8 = &__vt.unk48;
}
#endif

#endif  // SPYRO_SOURCE_FIREMOLEPRISON_H
