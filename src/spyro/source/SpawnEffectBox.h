#ifndef SPYRO_SOURCE_SPAWNEFFECTBOX_H
#define SPYRO_SOURCE_SPAWNEFFECTBOX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDVolume.h"

class KDVolume;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class SpawnEffectBox;
class SpawnEffectBoxDescriptor;

class SpawnEffectBox : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SpawnEffectBox(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ KDVolume unk50;
};

class SpawnEffectBoxDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
};

#endif  // SPYRO_SOURCE_SPAWNEFFECTBOX_H
