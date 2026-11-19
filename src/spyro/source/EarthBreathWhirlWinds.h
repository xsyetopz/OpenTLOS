#ifndef SPYRO_SOURCE_EARTHBREATHWHIRLWINDS_H
#define SPYRO_SOURCE_EARTHBREATHWHIRLWINDS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class EarthBreathWhirlWinds;
class EarthBreathWhirlWindsDescriptor;
class MKHeap;
class MKMessage;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Upgrade;

class EarthBreathWhirlWinds : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EarthBreathWhirlWinds(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void SpawnWhirlWind(const MKVector3 &, const MKVector3 &, Upgrade, bool, float);
    /* 0x04c */ MKHeap* unk4C;
    /* 0x050 */ MKModel* unk50;
    /* 0x054 */ MKProp* unk54;
    /* 0x058 */ f32 unk58;
};

class EarthBreathWhirlWindsDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline EarthBreathWhirlWinds::~EarthBreathWhirlWinds() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_EARTHBREATHWHIRLWINDS_H
