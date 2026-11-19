#ifndef SPYRO_SOURCE_LINESEGMENTTRAIL_H
#define SPYRO_SOURCE_LINESEGMENTTRAIL_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDSpline.h"

class KDSpline;
class LSTrail;
class LineSegmentTrail;
class LineSegmentTrailPool;
class MKAnimScript;
class MKMaterial;
class MKProp;
class MKVector4;

class LSTrail {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ u8 unk1C;
};

class LineSegmentTrail : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~LineSegmentTrail(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    s32 TrailActive(void);
    void EndTrail(void);
    void BeginTrail(const MKVector4 &);
    void UpdateTrail(LSTrail *);
    void FreeActiveTrail(LSTrail *);
    void SetUserData(MKAnimScript *, const int &, const int &, char *);
    /* 0x04c */ MKAnimScript* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 pad58[0x18];
    /* 0x070 */ MKMaterial* unk70;
    /* 0x074 */ KDSpline unk74;
    /* 0x088 */ KDSpline unk88;
};

class LineSegmentTrailPool {
public:
    void Free(LSTrail *);
    LineSegmentTrailPool * Alloc(void);
    void Deinit(void);
    void Init(void);
    static u8 pTrailPool[0x4];
    static u8 refCount[0x4];
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ s8 unk24;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LineSegmentTrail::~LineSegmentTrail() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_LINESEGMENTTRAIL_H
