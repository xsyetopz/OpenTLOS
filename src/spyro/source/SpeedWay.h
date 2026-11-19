#ifndef SPYRO_SOURCE_SPEEDWAY_H
#define SPYRO_SOURCE_SPEEDWAY_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/SplineTools.h"

class KDPathSegment;
class MKIniLine;
class MKProp;
class SpeedWay;
class SplitPath;

class SpeedWay : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SpeedWay(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    void GetPathMatrix(float);
    /* 0x04c */ KDPathSegment unk4C;
    /* 0x080 */ u8 pad80[0x14];
    /* 0x094 */ KDPathSegment unk94;
    /* 0x0c8 */ u8 padC8[0x14];
    /* 0x0dc */ SplitPath unkDC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SpeedWay::~SpeedWay() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SPEEDWAY_H
