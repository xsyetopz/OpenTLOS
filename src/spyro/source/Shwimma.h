#ifndef SPYRO_SOURCE_SHWIMMA_H
#define SPYRO_SOURCE_SHWIMMA_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class Shwimma;
class ShwimmaCritter;
class ShwimmaCritterDescriptor;

class ShwimmaCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~ShwimmaCritter(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    ShwimmaCritter(void);
    void SetAlertState(Shwimma *);
    void FindNewMoveParameters(Shwimma *, float);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
};

class Shwimma {
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
    /* 0x030 */ ShwimmaCritter unk30;
};

class ShwimmaCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    ShwimmaCritterDescriptor(void);
    /* 0x06d */ u8 pad6D[0x7];
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ShwimmaCritter::ShwimmaCritter() {
    return this;
}
#endif

inline ShwimmaCritter::~ShwimmaCritter() {
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
inline ShwimmaCritterDescriptor::ShwimmaCritterDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHWIMMA_H
