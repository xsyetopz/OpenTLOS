#ifndef SPYRO_SOURCE_CONSOLEPROP_H
#define SPYRO_SOURCE_CONSOLEPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ConsoleProp;
class MKIniLine;
class MKProp;

class ConsoleProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ConsoleProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x04c */ void* unk4C;
    /* 0x050 */ s32 unk50;
};

#endif  // SPYRO_SOURCE_CONSOLEPROP_H
