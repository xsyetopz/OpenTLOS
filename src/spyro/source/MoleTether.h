#ifndef SPYRO_SOURCE_MOLETETHER_H
#define SPYRO_SOURCE_MOLETETHER_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKMessage;
class MKVector3;
class Matrix;
class MoleTether;
class MoleTetherDescriptor;
class Shatterable;
class ShatterableDescriptor;

class MoleTether : public Shatterable {  // base: vtable prefix
public:
    virtual ~MoleTether(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *, bool);
    MoleTether(void);
    void SetWorldMatrix(Matrix &);
};

class MoleTetherDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    MoleTetherDescriptor(void);
    /* 0x16c */ s32 unk16C;
};

#endif  // SPYRO_SOURCE_MOLETETHER_H
