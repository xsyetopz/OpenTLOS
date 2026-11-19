#ifndef SPYRO_SOURCE_BOUNDINGREGION_H
#define SPYRO_SOURCE_BOUNDINGREGION_H

#include <dolphin/types.h>

class BoundingRegion;
class KDLocalPathSegment;
class MKVector3;

class BoundingRegion {
public:
    void GetPos(int);
    u32 GetIntersectCount(const MKVector3 &, const MKVector3 &);
    u8 IsPointInBoundaryRect(const MKVector3 &);
    s32 IsPointWithin(const MKVector3 &);
    void InitBoundaryRect(void);
    void Init(MKVector3 *, int);
    void Init(KDLocalPathSegment *);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
};

#endif  // SPYRO_SOURCE_BOUNDINGREGION_H
