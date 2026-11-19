#ifndef SPYRO_SOURCE_CRITTERS_H
#define SPYRO_SOURCE_CRITTERS_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"

class Critters;
class KDProp;
class MKIniLine;
class Matrix;

class Critters : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Critters(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0xc];
    /* 0x0a0 */ Matrix unkA0;
};

#endif  // SPYRO_SOURCE_CRITTERS_H
