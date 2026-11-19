#ifndef SPYRO_SOURCE_CLUSTERBOMB_H
#define SPYRO_SOURCE_CLUSTERBOMB_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ClusterBomb;
class ClusterBombDescriptor;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class ClusterBomb : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ClusterBomb(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void DrawClusterBombs(void);
    void UpdateClusterBombs(void);
    void SpawnClusterBomb(const MKVector3 &, const MKVector3 &);
    /* 0x04c */ MKVector3** unk4C;
    /* 0x050 */ MKModel* unk50;
};

class ClusterBombDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ MKProp* unk60;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ClusterBomb::~ClusterBomb() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_CLUSTERBOMB_H
