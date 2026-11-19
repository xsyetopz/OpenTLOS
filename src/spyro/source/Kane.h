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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Kane::Kane() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline Kane::~Kane() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#endif  // SPYRO_SOURCE_KANE_H
