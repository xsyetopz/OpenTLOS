#ifndef SPYRO_SOURCE_NPCGUARDIAN_H
#define SPYRO_SOURCE_NPCGUARDIAN_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EventMessage.h"

class Enemy;
class EventMessage;
class MKIniLine;
class MKMessage;
class MKSceneManager;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ s8 unkB10;
    /* 0xb11 */ u8 padB11[0x3];
    /* 0xb14 */ EventMessage unkB14;
    /* 0xb18 */ MKSceneManager* unkB18;
    /* 0xb1c */ s32 unkB1C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline NPCGuardian::NPCGuardian() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    this->unkAFC = 0;
    this->unkAFC.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline NPCGuardian::~NPCGuardian() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
    if (&this->unkAFC != NULL) {
        this->unkAFC.Deinit();
    }
}
#endif

#endif  // SPYRO_SOURCE_NPCGUARDIAN_H
