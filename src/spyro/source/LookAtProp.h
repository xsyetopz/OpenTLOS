#ifndef SPYRO_SOURCE_LOOKATPROP_H
#define SPYRO_SOURCE_LOOKATPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class LookAtProp;
class LookAtPropDescriptor;
class LookAtProp_cpp;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class Matrix;

class LookAtProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~LookAtProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    LookAtProp(void);
    /* 0x04c */ MKProp* unk4C;
    /* 0x050 */ Matrix unk50;
};

class LookAtPropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
};

class LookAtProp_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_LOOKATPROP_H
