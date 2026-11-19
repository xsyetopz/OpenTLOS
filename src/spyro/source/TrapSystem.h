#ifndef SPYRO_SOURCE_TRAPSYSTEM_H
#define SPYRO_SOURCE_TRAPSYSTEM_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class MKMessage;
class MKProp;
class MKPropDescriptor;
class Matrix;
class TrapSystem;
class TrapSystemDescriptor;

class TrapSystem : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TrapSystem(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void Add(MKProp *);
    /* 0x04c */ MKProp* unk4C;
    /* 0x050 */ Matrix unk50;
};

class TrapSystemDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
};

#endif  // SPYRO_SOURCE_TRAPSYSTEM_H
