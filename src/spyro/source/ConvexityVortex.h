#ifndef SPYRO_SOURCE_CONVEXITYVORTEX_H
#define SPYRO_SOURCE_CONVEXITYVORTEX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ConvexityVortex;
class MKHeap;
class MKMessage;
class MKProp;
class MKVector3;

class ConvexityVortex : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ConvexityVortex(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void SpawnElement(const MKVector3 &);
    /* 0x04c */ MKHeap* unk4C;
    /* 0x050 */ MKHeap* unk50;
    /* 0x054 */ u8 pad54[0x8];
    /* 0x05c */ u8 unk5C;
    /* 0x05d */ u8 pad5D[0x3];
    /* 0x060 */ u8 unk60;
    /* 0x061 */ u8 pad61[0x2f];
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ MKVector3** unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ u8 unkA8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ConvexityVortex::~ConvexityVortex() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_CONVEXITYVORTEX_H
