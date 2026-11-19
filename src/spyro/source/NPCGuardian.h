#ifndef SPYRO_SOURCE_NPCGUARDIAN_H
#define SPYRO_SOURCE_NPCGUARDIAN_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"

class Enemy;
class MKIniLine;
class MKMessage;
class NPCGuardian;

class NPCGuardian : public Enemy {  // base: vtable prefix
public:
    virtual ~NPCGuardian(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    NPCGuardian(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline NPCGuardian::NPCGuardian() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    this->unk110.unkA04 = 0;
    this->unk110.unkA04.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline NPCGuardian::~NPCGuardian() {
    this->unk110.unk5A8 = &__vt.unk84;
    if (&this->unk110.unkA04 != NULL) {
        this->unk110.unkA04.Deinit();
    }
}
#endif

#endif  // SPYRO_SOURCE_NPCGUARDIAN_H
