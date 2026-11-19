#ifndef SPYRO_SOURCE_FURYFX_H
#define SPYRO_SOURCE_FURYFX_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class FuryFX;
class KDProp;

class FuryFX : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    void SetDefaults(void);
};

#endif  // SPYRO_SOURCE_FURYFX_H
