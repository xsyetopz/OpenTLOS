#ifndef SPYRO_SOURCE_KDDROPSHADOW_H
#define SPYRO_SOURCE_KDDROPSHADOW_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class KDDropShadow;
class KDDropShadowDescriptor;
class MKHeap;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class Matrix;

class KDDropShadow : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDDropShadow(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Draw(void);
    /* 0x04c */ MKHeap* unk4C;
    /* 0x050 */ Matrix* unk50;
    /* 0x054 */ Matrix* unk54;
};

class KDDropShadowDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
};

#endif  // SPYRO_SOURCE_KDDROPSHADOW_H
