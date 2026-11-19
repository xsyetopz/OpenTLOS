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

#endif  // SPYRO_SOURCE_KANE_H
