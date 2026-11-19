#ifndef SPYRO_SOURCE_WAKE_H
#define SPYRO_SOURCE_WAKE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class MKMaterial;
class MKProp;
class Matrix;
class Wake;

class Wake : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Wake(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    s32 GetWakeLength(int);
    /* 0x04c */ MKMaterial* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ void* unk5C;
    /* 0x060 */ Matrix unk60;
};

#endif  // SPYRO_SOURCE_WAKE_H
