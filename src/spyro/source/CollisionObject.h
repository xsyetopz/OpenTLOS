#ifndef SPYRO_SOURCE_COLLISIONOBJECT_H
#define SPYRO_SOURCE_COLLISIONOBJECT_H

#include <dolphin/types.h>
#include "spyro/source/TargetManager.h"

class ColObjDescriptor;
class CollisionObject;
class ContextInfo;
class MKCollisionInfo;
class MKCollisionMode;
class MKCollisionResult;
class MKMessage;
class MKProp;
class MKVector3;
class Targetable;

class ColObjDescriptor {
public:
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s8 unk14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ s32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
};

class ContextInfo {
public:
    s32 HitID(unsigned int);
    /* 0x000 */ u8 pad0[0x160];
    /* 0x160 */ s32 unk160;
    /* 0x164 */ s32 unk164;
};

class CollisionObject : public Targetable {  // base: ctor/dtor vtable stores
public:
    virtual void Init(ColObjDescriptor *, const MKVector3 &, bool, MKCollisionInfo *, bool, bool, unsigned int, MKProp *, bool);
    virtual void Deinit(void);
    virtual s32 Update(MKVector3 *, float, bool);
    virtual s32 Teleport(const MKVector3 &, float, int);
    virtual s32 HasHitFloor(void);
    virtual s32 HasHitWall(void);
    virtual s32 HasHitRoof(void);
    virtual s32 HasHitAnything(void);
    virtual u32 GetFloorProp(void);
    virtual s32 GetOwner(void);
    virtual void SetOwner(MKProp *);
    virtual s32 GetFloorMaterialID(void);
    virtual u32 GetProp(void);
    virtual void SetRotation(MKVector3 *, MKVector3);
    virtual void SetScale(float);
    virtual void Reset(const MKVector3 &, const MKVector3 &);
    virtual void IgnoreAll(bool);
    virtual void GetPos(void);
    virtual void GetOffset(void);
    virtual s32 SphereCheck(const MKVector3 &, const MKVector3 &, float, MKCollisionResult *, MKCollisionMode, int);
    virtual void ResolveCollisions(MKVector3 *, MKVector3 *, int);
    virtual void ResolveCollisionsQuick(MKVector3 *, MKVector3 *, int);
    void CalculateNewVelocity(MKVector3 *, const MKVector3 *, float, ContextInfo *, MKCollisionResult *, const MKVector3 &);
    void SortResults(void);
    void PerformPushOut(MKVector3 *);
    void ResetResults(void);
    ContextInfo * StoreResult(MKCollisionResult *, MKVector3 *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0x40];
    /* 0x050 */ void* unk50;
    /* 0x054 */ u8 pad54[0x4];
    /* 0x058 */ u8 unk58;
    /* 0x059 */ u8 pad59[0x113];
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ ContextInfo unk170;
    /* 0x2d8 */ ContextInfo unk2D8;
    /* 0x440 */ MKMessage* unk440;
    /* 0x444 */ u8 pad444[0x4];
    /* 0x448 */ s32 unk448;
    /* 0x44c */ s32 unk44C;
    /* 0x450 */ f64 unk450;
    /* 0x458 */ f64 unk458;
    /* 0x460 */ f32* unk460;
    /* 0x464 */ MKCollisionInfo* unk464;
    /* 0x468 */ s32 unk468;
    /* 0x46c */ s32 unk46C;
    /* 0x470 */ MKProp* unk470;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 CollisionObject::HasHitFloor() {
    return this->unk16C > 0;
}

inline s32 CollisionObject::HasHitWall() {
    return this->unk170.unk164 > 0;
}

inline s32 CollisionObject::HasHitRoof() {
    return this->unk2D8.unk164 > 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
inline s32 CollisionObject::HasHitAnything() {
    s32 var_r31_46;

    var_r31_46 = 0;
    if ((M2C_FIELD(this->__vptr, u8 (**)(CollisionObject *), 0x18)(this) != 0) || (M2C_FIELD(this->__vptr, u8 (**)(CollisionObject *), 0x1C)(this) != 0) || (M2C_FIELD(this->__vptr, u8 (**)(CollisionObject *), 0x20)(this) != 0)) {
        var_r31_46 = 1;
    }
    return var_r31_46;
}
#endif

inline u32 CollisionObject::GetFloorProp() {
    u32 temp_r3_87;
    void *temp_r3_84;

    if (((u8) this->unk58 == 0) || (temp_r3_84 = this->unk50, ((temp_r3_84 == NULL) != 0)) || (temp_r3_87 = M2C_FIELD(temp_r3_84, u32 *, 8), ((temp_r3_87 == 0) != 0))) {
        return 0U;
    }
    return temp_r3_87;
}

inline void CollisionObject::SetOwner(MKProp *arg0) {
    this->unk470 = arg0;
}

inline s32 CollisionObject::GetFloorMaterialID() {
    s32 temp_r4_105;
    void *var_r3_112;

    temp_r4_105 = this->unk16C;
    if (temp_r4_105 > 0) {
        if (temp_r4_105 != 0) {
            var_r3_112 = this + ((temp_r4_105 - 1) * 0x58) + 8;
        } else {
            var_r3_112 = NULL;
        }
        return M2C_FIELD(var_r3_112, s32 *, 0x44);
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier 'unk50'
inline u32 CollisionObject::GetProp() {
    u32 temp_r3_150;
    u32 var_r0_136;
    u8 temp_r5_130;
    void *temp_r3_147;
    void *temp_r4_133;

    if ((s32) this->unk170.unk164 > 0) {
        temp_r5_130 = this->unk170.unk50;
        if ((temp_r5_130 != 0) && (temp_r4_133 = this->unk170.unk48, ((temp_r4_133 == NULL) == 0)) && (var_r0_136 = M2C_FIELD(temp_r4_133, u32 *, 8), ((var_r0_136 == 0) == 0))) {

        } else {
            var_r0_136 = 0;
        }
        if (var_r0_136 != 0) {
            if ((temp_r5_130 == 0) || (temp_r3_147 = this->unk170.unk48, ((temp_r3_147 == NULL) != 0)) || (temp_r3_150 = M2C_FIELD(temp_r3_147, u32 *, 8), ((temp_r3_150 == 0) != 0))) {
                return 0U;
            }
            return temp_r3_150;
        }
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return 0U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
inline void CollisionObject::SetRotation(MKVector3 *arg0, MKVector3 arg1) {

}
#endif

inline void CollisionObject::SetScale(float arg0) {

}

inline void CollisionObject::Reset(const MKVector3 &arg0, const MKVector3 &arg1) {

}

inline void CollisionObject::GetPos() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x450);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x458);
}

inline void CollisionObject::GetOffset() {
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.0f;
    sp10 = 0.0f;
    spC = M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x460), f32 *, 4);
    M2C_FIELD(this, f64 *, 0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}

inline s32 CollisionObject::GetOwner() {
    return (s32) this->unk470;
}

#endif  // SPYRO_SOURCE_COLLISIONOBJECT_H
