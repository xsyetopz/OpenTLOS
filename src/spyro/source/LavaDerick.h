#ifndef SPYRO_SOURCE_LAVADERICK_H
#define SPYRO_SOURCE_LAVADERICK_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class LavaDerick;
class LavaDerickDescriptor;
class LavaDerick_cpp;
class MKMessage;
class Shatterable;
class ShatterableDescriptor;

class LavaDerick : public Shatterable {  // base: vtable prefix
public:
    virtual ~LavaDerick(void);
    virtual void Message(MKMessage *);
    LavaDerick(void);
};

class LavaDerickDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Resolve(void);
    LavaDerickDescriptor(void);
    void * CalcBounds(void);
};

class LavaDerick_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_LAVADERICK_H
