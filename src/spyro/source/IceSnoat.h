#ifndef SPYRO_SOURCE_ICESNOAT_H
#define SPYRO_SOURCE_ICESNOAT_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class IceSnoat;
class IceSnoatCritter;
class IceSnoatCritterDescriptor;

class IceSnoat {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ u8 pad40[0x10];
    /* 0x050 */ void* unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
};

class IceSnoatCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~IceSnoatCritter(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    IceSnoatCritter(void);
    void FindNewBounceParameters(IceSnoat *);
    void SetAlertState(IceSnoat *);
    void FindNewRunParameters(IceSnoat *);
    void SetRunState(IceSnoat *);
    void SetBounceState(IceSnoat *);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
};

class IceSnoatCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    IceSnoatCritterDescriptor(void);
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline IceSnoatCritter::IceSnoatCritter() {
}

inline IceSnoatCritter::~IceSnoatCritter() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

inline IceSnoatCritterDescriptor::IceSnoatCritterDescriptor() {
}

#endif  // SPYRO_SOURCE_ICESNOAT_H
