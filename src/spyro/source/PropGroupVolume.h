#ifndef SPYRO_SOURCE_PROPGROUPVOLUME_H
#define SPYRO_SOURCE_PROPGROUPVOLUME_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/PolyRegion.h"

class MKIniLine;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class PolyRegion;
class PropGroupVolume;
class PropGroupVolumeDescriptor;

class PropGroupVolume : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~PropGroupVolume(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    u8 LoadOverlayName(MKIniLine *);
    void CullGroups(const MKVector3 &);
    static PropGroupVolume overlay;
    static u8 overlayCount[0x4];
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ PolyRegion unk50;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ u8 padA4[0x200];
    /* 0x2a4 */ s32 unk2A4;
    /* 0x2a8 */ f32 unk2A8;
    /* 0x2ac */ u8 unk2AC;
    /* 0x2ad */ u8 unk2AD;
};

class PropGroupVolumeDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    static u8 pFirstDesc[0x4];
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ void* unk60;
    /* 0x064 */ PropGroupVolumeDescriptor* unk64;
    /* 0x068 */ PropGroupVolumeDescriptor* unk68;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline PropGroupVolume::~PropGroupVolume() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_PROPGROUPVOLUME_H
