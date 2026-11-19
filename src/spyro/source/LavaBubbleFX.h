#ifndef SPYRO_SOURCE_LAVABUBBLEFX_H
#define SPYRO_SOURCE_LAVABUBBLEFX_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class GameProp;
class LavaBubbleFX;
class MKHeap;
class MKMaterial;
class MKVector3;

class LavaBubbleFX : public GameProp {  // base: vtable prefix
public:
    virtual ~LavaBubbleFX(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    LavaBubbleFX(void);
    void CreateBubble(const MKVector3 &, const MKVector3 &);
    void DrawBubbleRings(void);
    /* 0x0c8 */ MKHeap* unkC8;
    /* 0x0cc */ MKMaterial* unkCC;
    /* 0x0d0 */ MKMaterial* unkD0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LavaBubbleFX::LavaBubbleFX() {
}

inline LavaBubbleFX::~LavaBubbleFX() {
}

#endif  // SPYRO_SOURCE_LAVABUBBLEFX_H
