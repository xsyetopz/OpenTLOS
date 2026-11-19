#ifndef SPYRO_SOURCE_BEETLENESTSMALL_H
#define SPYRO_SOURCE_BEETLENESTSMALL_H

#include <dolphin/types.h>
#include "spyro/source/shatterwaypointspawn.h"

class BeetleNestSmall;
class BeetleNestSmallDescriptor;
class MKMessage;
class ShatterWaypointSpawn;
class ShatterWaypointSpawnDescriptor;

class BeetleNestSmall : public ShatterWaypointSpawn {  // base: base ctor call
public:
    virtual ~BeetleNestSmall(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    BeetleNestSmall(void);
    /* 0x208 */ u32 unk208;
};

class BeetleNestSmallDescriptor : public ShatterWaypointSpawnDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual s32 GetSpawnEnemyType(void);
    BeetleNestSmallDescriptor(void);
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ s32 unk178;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BeetleNestSmall::~BeetleNestSmall() {
    this->unkC8 = &__vt.unk48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BeetleNestSmall::BeetleNestSmall() {
    this->unkC8 = &__vt + 0x48;
}
#endif

inline s32 BeetleNestSmallDescriptor::GetSpawnEnemyType() {
    return 0x11;
}

inline BeetleNestSmallDescriptor::BeetleNestSmallDescriptor() {
}

#endif  // SPYRO_SOURCE_BEETLENESTSMALL_H
