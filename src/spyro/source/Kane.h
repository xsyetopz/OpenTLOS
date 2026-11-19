#ifndef SPYRO_SOURCE_KANE_H
#define SPYRO_SOURCE_KANE_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"

class Enemy;
class Kane;
class MKIniLine;

class Kane : public Enemy {  // base: vtable prefix
public:
    virtual ~Kane(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(void);
    Kane(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline Kane::Kane() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline Kane::~Kane() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#endif  // SPYRO_SOURCE_KANE_H
