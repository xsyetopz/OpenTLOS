#ifndef SPYRO_SOURCE_SWAMPFLUTTER_H
#define SPYRO_SOURCE_SWAMPFLUTTER_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class SwampFlutter;
class SwampFlutterCritter;
class SwampFlutterCritterDescriptor;

class SwampFlutter {
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
    /* 0x030 */ u8 unk30;
    /* 0x031 */ u8 pad31[0x3];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 pad40[0x10];
    /* 0x050 */ void* unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
};

class SwampFlutterCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~SwampFlutterCritter(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    SwampFlutterCritter(void);
    void FindNewFlyParameters(SwampFlutter *);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
};

class SwampFlutterCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SwampFlutterCritterDescriptor(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampFlutterCritter::SwampFlutterCritter() {
    return this;
}
#endif

inline SwampFlutterCritter::~SwampFlutterCritter() {
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

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampFlutterCritterDescriptor::SwampFlutterCritterDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SWAMPFLUTTER_H
