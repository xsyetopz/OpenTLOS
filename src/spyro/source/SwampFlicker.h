#ifndef SPYRO_SOURCE_SWAMPFLICKER_H
#define SPYRO_SOURCE_SWAMPFLICKER_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class SwampFlicker;
class SwampFlickerDescriptor;

class SwampFlicker : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~SwampFlicker(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    SwampFlicker(void);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
};

class SwampFlickerDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SwampFlickerDescriptor(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
};

#endif  // SPYRO_SOURCE_SWAMPFLICKER_H
