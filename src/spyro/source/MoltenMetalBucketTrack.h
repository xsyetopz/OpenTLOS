#ifndef SPYRO_SOURCE_MOLTENMETALBUCKETTRACK_H
#define SPYRO_SOURCE_MOLTENMETALBUCKETTRACK_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class MKIniLine;
class MKMaterial;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class Matrix;
class MoltenMetalBucketTrack;
class MoltenMetalBucketTrackDescriptor;

class MoltenMetalBucketTrack : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~MoltenMetalBucketTrack(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ Matrix unk4C;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ u8 unkA0;
    /* 0x0a1 */ u8 padA1[0x3f];
    /* 0x0e0 */ u8 unkE0;
    /* 0x0e1 */ u8 padE1[0x3];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ f32 unkE8;
};

class MoltenMetalBucketTrackDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ u8 unk60;
    /* 0x061 */ u8 pad61[0x7];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ MKMaterial* unk80;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline MoltenMetalBucketTrack::~MoltenMetalBucketTrack() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_MOLTENMETALBUCKETTRACK_H
