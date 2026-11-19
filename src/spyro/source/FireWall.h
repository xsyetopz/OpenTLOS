#ifndef SPYRO_SOURCE_FIREWALL_H
#define SPYRO_SOURCE_FIREWALL_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class FireWall;
class FireWallDescriptor;
class MKHeap;
class MKIniLine;
class MKMaterial;
class MKProp;
class MKPropDescriptor;

class FireWall : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FireWall(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ MKHeap* unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
};

class FireWallDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ MKMaterial* unk60;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FireWall::~FireWall() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_FIREWALL_H
