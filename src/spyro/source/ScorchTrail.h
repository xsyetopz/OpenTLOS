#ifndef SPYRO_SOURCE_SCORCHTRAIL_H
#define SPYRO_SOURCE_SCORCHTRAIL_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKHeap;
class MKMaterial;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class ScorchTrail;
class ScorchTrailDescriptor;

class ScorchTrail : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ScorchTrail(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    void SpawnScorchMark(const MKVector3 &, const MKVector3 &, float);
    void DrawScorchMarks(void);
    void UpdateScorchMarks(void);
    void SpawnPlasmaBubble(const MKVector3 &, const MKVector3 &, float);
    void DrawPlasmaBubbles(void);
    void UpdatePlasmaBubbles(void);
    void EndTrail(void);
    void AddNode(const MKVector3 &, const MKVector3 &);
    /* 0x04c */ MKHeap* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ f32 unk58;
};

class ScorchTrailDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ MKMaterial* unk60;
    /* 0x064 */ MKModel* unk64;
    /* 0x068 */ MKMaterial* unk68;
    /* 0x06c */ MKMaterial* unk6C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ScorchTrail::~ScorchTrail() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SCORCHTRAIL_H
