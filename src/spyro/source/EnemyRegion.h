#ifndef SPYRO_SOURCE_ENEMYREGION_H
#define SPYRO_SOURCE_ENEMYREGION_H

#include <dolphin/types.h>

class EnemyRegion;
class KDLocalPathSegment;
class KDPathSegment;
class MKVector3;

class EnemyRegion {
public:
    EnemyRegion(void);
    u32 GetPathSegment(void);
    void GetNearestPointOnBoundingRegion(const MKVector3 &, MKVector3 *, MKVector3 *);
    s32 GetFirstIntersectionPlane(const MKVector3 &, const MKVector3 &, MKVector3 *, MKVector3 *);
    void GetRegionPos(void);
    u8 IsPointWithin(const MKVector3 &);
    s32 TryChangeRegion(const MKVector3 &);
    void SetupRegion(KDLocalPathSegment *);
    void SetupRegion(const MKVector3 &, float);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ s32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ u8 unk30;
    /* 0x031 */ u8 unk31;
    /* 0x032 */ u8 pad32[0x2];
    /* 0x034 */ f32 unk34;
};

u8 PolygonWindingOrderIsClockWise(KDPathSegment *);
void PolygonCentroid(KDPathSegment *);
f32 PolygonArea(KDPathSegment *);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk14'
inline EnemyRegion::EnemyRegion() {
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk18 = 0;
    this->unk1C = 0.0f;
    this->unk20 = 0.0f;
    this->unk24 = 0.0f;
    this->unk28 = 0.0f;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMYREGION_H
