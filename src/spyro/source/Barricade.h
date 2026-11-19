#ifndef SPYRO_SOURCE_BARRICADE_H
#define SPYRO_SOURCE_BARRICADE_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class BarricadeProp;
class MKMessage;
class MKVector3;
class Shatterable;

class BarricadeProp : public Shatterable {  // base: vtable prefix
public:
    virtual ~BarricadeProp(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    BarricadeProp(void);
};

#endif  // SPYRO_SOURCE_BARRICADE_H
