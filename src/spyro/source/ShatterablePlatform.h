#ifndef SPYRO_SOURCE_SHATTERABLEPLATFORM_H
#define SPYRO_SOURCE_SHATTERABLEPLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKMessage;
class Shatterable;
class ShatterablePlatform;

class ShatterablePlatform : public Shatterable {  // base: vtable prefix
public:
    virtual ~ShatterablePlatform(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMove(void);
    ShatterablePlatform(void);
};

#endif  // SPYRO_SOURCE_SHATTERABLEPLATFORM_H
