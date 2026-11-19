#ifndef SPYRO_SOURCE_LIGHTPROP_H
#define SPYRO_SOURCE_LIGHTPROP_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class GameProp;
class LightProp;
class ManagedLight;
class Matrix;

class LightProp : public GameProp {  // base: vtable prefix
public:
    virtual ~LightProp(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    LightProp(void);
    void SetOrientation(Matrix *);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ ManagedLight* unkC8;
    /* 0x0cc */ u8 padCC[0x8];
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ s32 unkE0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LightProp::LightProp() {
    return this;
}
#endif

inline LightProp::~LightProp() {
}

#endif  // SPYRO_SOURCE_LIGHTPROP_H
