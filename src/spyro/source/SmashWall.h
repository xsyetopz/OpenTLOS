#ifndef SPYRO_SOURCE_SMASHWALL_H
#define SPYRO_SOURCE_SMASHWALL_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKMessage;
class Shatterable;
class SmashWall;

class SmashWall : public Shatterable {  // base: base ctor call
public:
    virtual ~SmashWall(void);
    virtual void Message(MKMessage *);
    SmashWall(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SmashWall::SmashWall() {
    this->unkC8 = &__vt + 0x48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SmashWall::~SmashWall() {
    this->unkC8 = &__vt.unk48;
}
#endif

#endif  // SPYRO_SOURCE_SMASHWALL_H
