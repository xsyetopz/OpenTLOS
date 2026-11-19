#ifndef SPYRO_SOURCE_KANE_H
#define SPYRO_SOURCE_KANE_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"

class Enemy;
class Kane;
class MKIniLine;

class Kane : public Enemy {  // base: base ctor call
public:
    virtual ~Kane(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual f32 Resolve(void);
    Kane(void);
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline Kane::Kane() {
    this->unk6B8 = &__vt + 0x84;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline Kane::~Kane() {
    this->unk6B8 = &__vt.unk84;
}
#endif

#endif  // SPYRO_SOURCE_KANE_H
