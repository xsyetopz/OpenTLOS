#ifndef SPYRO_SOURCE_CRITTERS_H
#define SPYRO_SOURCE_CRITTERS_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Volume.h"

class Critters;
class KDProp;
class MKIniLine;
class Matrix;
class Volume;

class Critters : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Critters(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0x8];
    /* 0x09c */ u8 unk9C;
    /* 0x09d */ u8 pad9D[0x3];
    /* 0x0a0 */ Matrix unkA0;
    /* 0x0e0 */ Volume unkE0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Critters::~Critters() {
    s32 temp_cr0_eq_13429;

    temp_cr0_eq_13429 = this == NULL;
    if (temp_cr0_eq_13429 == 0) {
        if (temp_cr0_eq_13429 == 0) {
            if (temp_cr0_eq_13429 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_CRITTERS_H
