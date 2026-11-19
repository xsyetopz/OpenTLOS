#ifndef SPYRO_SOURCE_WATERVOLUME_H
#define SPYRO_SOURCE_WATERVOLUME_H

#include <dolphin/types.h>
#include "spyro/source/KDWaterVolume.h"

class KDWaterVolume;
class KDWaterVolumeDescriptor;
class MKIniLine;
class MKMessage;
class WaterVolume;
class WaterVolumeDescriptor;

class WaterVolume : public KDWaterVolume {  // base: ctor/dtor vtable stores
public:
    virtual ~WaterVolume(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    virtual s32 IsEnabled(void);
};

class WaterVolumeDescriptor : public KDWaterVolumeDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x004 */ u8 pad4[0x8];
    /* 0x00c */ s32 unkC;
};

#endif  // SPYRO_SOURCE_WATERVOLUME_H
