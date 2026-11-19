#ifndef SPYRO_SOURCE_BIGBEETLEHIVE_H
#define SPYRO_SOURCE_BIGBEETLEHIVE_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class BigBeetleHive;
class BigBeetleHiveDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;

class BigBeetleHive : public Shatterable {  // base: vtable prefix
public:
    virtual ~BigBeetleHive(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *);
    BigBeetleHive(void);
    void EmitGoopDrips(void);
    void UpdateAttachedNests(void);
};

class BigBeetleHiveDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    BigBeetleHiveDescriptor(void);
    /* 0x16c */ s32 unk16C;
};

#endif  // SPYRO_SOURCE_BIGBEETLEHIVE_H
