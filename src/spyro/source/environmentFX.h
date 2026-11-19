#ifndef SPYRO_SOURCE_ENVIRONMENTFX_H
#define SPYRO_SOURCE_ENVIRONMENTFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class EnvironmentFX;
class MKMessage;
class MKProp;

class EnvironmentFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EnvironmentFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0x3];
    /* 0x050 */ s32 unk50;
};

#endif  // SPYRO_SOURCE_ENVIRONMENTFX_H
