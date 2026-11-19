#ifndef SPYRO_SOURCE_CONVEXITYDEBRIS_H
#define SPYRO_SOURCE_CONVEXITYDEBRIS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/KDSpline.h"

class ConvexityDebris;
class ConvexityDebrisDescriptor;
class KDSpline;
class MKHeap;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector4;

class ConvexityDebris : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ConvexityDebris(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ MKHeap* unk4C;
    /* 0x050 */ KDSpline unk50;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ MKVector4 unk80;
};

class ConvexityDebrisDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ConvexityDebris::~ConvexityDebris() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_CONVEXITYDEBRIS_H
