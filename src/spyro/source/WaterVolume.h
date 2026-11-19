#ifndef SPYRO_SOURCE_WATERVOLUME_H
#define SPYRO_SOURCE_WATERVOLUME_H

#include <dolphin/types.h>
#include "common/Source/MKCollision.h"
#include "spyro/source/KDWaterVolume.h"

class KDWaterVolume;
class KDWaterVolumeDescriptor;
class MKCollisionInfo;
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
    /* 0x0d8 */ u8 padD8[0x8];
    /* 0x0e0 */ MKCollisionInfo unkE0;
};

class WaterVolumeDescriptor : public KDWaterVolumeDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline WaterVolume::~WaterVolume() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_WATERVOLUME_H
