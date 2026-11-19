#ifndef SPYRO_SOURCE_CYNDERBARRACKS_H
#define SPYRO_SOURCE_CYNDERBARRACKS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/Shatterable.h"

class CynderBarracks;
class CynderBarracksDescriptor;
class CynderBarracksState;
class EnemyGeneratorDescriptor;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class Shatterable;

class CynderBarracks : public Shatterable {  // base: vtable prefix
public:
    virtual ~CynderBarracks(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    CynderBarracks(void);
    void SetState(CynderBarracksState);
};

class CynderBarracksDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderBarracksDescriptor(void);
    /* 0x048 */ u8 pad48[0x1c];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x104];
    /* 0x16c */ EnemyGeneratorDescriptor unk16C;
};

#endif  // SPYRO_SOURCE_CYNDERBARRACKS_H
