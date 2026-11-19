#ifndef SPYRO_SOURCE_TORCH_H
#define SPYRO_SOURCE_TORCH_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/GameProp.h"

class Corona;
class GameProp;
class MKVector3;
class ManagedLight;
class Torch;

class Torch : public GameProp {  // base: base ctor call
public:
    virtual ~Torch(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Enable(void);
    virtual void Disable(void);
    Torch(void);
    /* 0x0c8 */ u8 padC8[0x8];
    /* 0x0d0 */ u8 unkD0;
    /* 0x0d1 */ u8 padD1[0x7];
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ u8 padF4[0x4];
    /* 0x0f8 */ MKVector3 unkF8;
    /* 0x108 */ Corona* unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ ManagedLight* unk11C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Torch::Torch() {
}

inline Torch::~Torch() {
}

#endif  // SPYRO_SOURCE_TORCH_H
