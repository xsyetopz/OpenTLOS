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

#endif  // SPYRO_SOURCE_NPCGUARDIAN_H
