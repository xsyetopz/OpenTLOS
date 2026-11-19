#ifndef SPYRO_SOURCE_KDWATERVOLUME_H
#define SPYRO_SOURCE_KDWATERVOLUME_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDVolume.h"

class KDVolume;
class KDWaterVolume;
class KDWaterVolumeDescriptor;
class MKCollisionResult;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class KDWaterVolume : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDWaterVolume(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual s32 IsEnabled(void);
    f32 GetWaterSurface(const MKVector3 &);
    s32 GetWaterHeight(const MKVector3 &, float, float *, MKCollisionResult *, int);
    s32 IsWithin(const MKVector3 &, float *, int *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ KDVolume unk50;
};

class KDWaterVolumeDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    static u8 pFirstDesc[0x4];
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u32 unk64;
    /* 0x068 */ KDWaterVolumeDescriptor* unk68;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline KDWaterVolume::~KDWaterVolume() {
    s32 temp_cr0_eq_12554;

    temp_cr0_eq_12554 = this == NULL;
    if (temp_cr0_eq_12554 == 0) {
        if (temp_cr0_eq_12554 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_KDWATERVOLUME_H
