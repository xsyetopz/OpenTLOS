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

class NPCGuardian : public Enemy {  // base: base ctor call
public:
    virtual ~NPCGuardian(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    NPCGuardian(void);
    /* 0xb10 */ s8 unkB10;
    /* 0xb11 */ u8 padB11[0x3];
    /* 0xb14 */ EventMessage unkB14;
    /* 0xb18 */ MKSceneManager* unkB18;
    /* 0xb1c */ s32 unkB1C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline NPCGuardian::NPCGuardian() {
    this->unk6B8 = &__vt + 0x84;
    this->unkB14.unk0 = 0;
    this->unkB14.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline NPCGuardian::~NPCGuardian() {
    this->unk6B8 = &__vt.unk84;
    if (&this->unkB14 != NULL) {
        this->unkB14.Deinit();
    }
}
#endif

#endif  // SPYRO_SOURCE_NPCGUARDIAN_H
