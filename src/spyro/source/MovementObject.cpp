#include "spyro/source/MovementObject.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CollisionObject.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: identifier 'MovementObject::UpdateCollisions(MKVector3 &, bool)' redeclared was declared as: 'MKVector3 (MKVector3 &, bool)' now declared as: 'void (MKVector3 &
void MovementObject::UpdateCollisions(MKVector3 &arg2, bool arg3) {
    MKVector3 result;
    MKVector3 *sret = &result;
    f64 sp8;
    CollisionObject *temp_r3_41;
    CollisionObject *temp_r3_59;
    CollisionObject *temp_r3_66;
    CollisionObject *temp_r3_80;
    CollisionObject *temp_r3_91;
    CollisionObject *temp_r4_49;
    f32 temp_f31_114;

    M2C_FIELD(this, s32 *, 0x68) = (s32) (M2C_FIELD(this, s32 *, 0x68) & 0xFFFFFFF8);
    if (!(this->unk60 & 1)) {
        this->unk0 += M2C_FIELD(&arg2, f64 *, 0);
        M2C_FIELD(this, f32 *, 8) = (f32) (M2C_FIELD(this, f32 *, 8) + arg2.unk8);
        M2C_FIELD(sret, f64 *, 0) = (f64) M2C_FIELD(&arg2, f64 *, 0);
        M2C_FIELD(sret, f64 *, 8) = (f64) M2C_FIELD(&arg2, f32 *, 8);
        return result;
    }
    temp_r3_41 = this->unk54;
    temp_r3_41->Update(&arg2, 0, 0.0f);
    temp_r4_49 = this->unk54;
    M2C_FIELD(temp_r4_49->__vptr, M2C_UNK (**)(f64 *, CollisionObject *), 0x4C)(&sp8, temp_r4_49);
    this->unk0 = sp8;
    this->unk8 = sp10;
    temp_r3_59 = this->unk54;
    if (temp_r3_59->HasHitFloor(sp8) != 0) {
        temp_r3_66 = this->unk54;
        M2C_FIELD(this, s32 *, 0x70) = temp_r3_66->GetFloorProp();
        M2C_FIELD(this, s32 *, 0x68) = (s32) (M2C_FIELD(this, s32 *, 0x68) | 1);
    } else {
        M2C_FIELD(this, s32 *, 0x70) = 0;
    }
    temp_r3_80 = this->unk54;
    if (temp_r3_80->HasHitWall() != 0) {
        M2C_FIELD(this, s32 *, 0x68) = (s32) (M2C_FIELD(this, s32 *, 0x68) | 2);
    }
    temp_r3_91 = this->unk54;
    if (temp_r3_91->HasHitRoof() != 0) {
        M2C_FIELD(this, s32 *, 0x68) = (s32) (M2C_FIELD(this, s32 *, 0x68) | 4);
    }
    if (this->unk60 & 2) {
        M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(&arg2, f64 *, 0);
        M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&arg2, f32 *, 8);
        if (arg3 != 0) {
            temp_f31_114 = 1.0f / gUpdateTimeDelta;
            M2C_FIELD(this, f64 *, 0x10) = (f64) (M2C_FIELD(this, f64 *, 0x10) * (f64) temp_f31_114);
            this->unk18 *= temp_f31_114;
        }
    }
    M2C_FIELD(sret, f64 *, 0) = (f64) M2C_FIELD(&arg2, f64 *, 0);
    M2C_FIELD(sret, f64 *, 8) = (f64) M2C_FIELD(&arg2, f32 *, 8);
    return result;
}
#endif

#if 0 // DRAFT: identifier 'MovementObject::Update(bool)' redeclared was declared as: 'MKVector3 (bool)' now declared as: 'void (bool)'
void MovementObject::Update(bool arg2) {
    MKVector3 result;
    MKVector3 *sret = &result;
    MKCollisionResult spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    CollisionObject *temp_r3_177;
    f32 temp_f3_288;
    f32 temp_f4_245;
    f32 temp_f4_284;
    f32 temp_f5_282;
    f64 *temp_r5_178;
    f64 temp_f0_261;
    f64 temp_f2_159;
    f64 temp_f5_241;
    s32 temp_r3_179;
    u32 var_r0_196;
    void **var_r3_220;
    void *temp_r3_217;
    void *temp_r4_193;
    void *var_r3_209;
    void *var_r4_185;

    if ((u32) this->unk64 == 1U) {
        M2C_FIELD(sret, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
        M2C_FIELD(sret, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
        return result;
    }
    temp_f2_159 = M2C_FIELD(this, f64 *, 0x18);
    sp48 = M2C_FIELD(this, f64 *, 0x10);
    spB0 = temp_f2_159;
    (*(f32 *) ((u8 *) &sp48 + 0x4)) = 0.0f;
    sp50 = temp_f2_159;
    spA8 = sp48;
    if ((((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * (*(f32 *) ((u8 *) &spA8 + 0x4))))) < 1.0f) {
        temp_r3_177 = this->unk54;
        temp_r5_178 = &temp_r3_177->unk8;
        temp_r3_179 = temp_r3_177->unk16C;
        if (temp_r3_179 > 0) {
            if (temp_r3_179 != 0) {
                var_r4_185 = temp_r5_178 + ((temp_r3_179 - 1) * 0x58);
            } else {
                var_r4_185 = NULL;
            }
            if (((u8) M2C_FIELD(var_r4_185, u8 *, 0x50) != 0) && (temp_r4_193 = M2C_FIELD(var_r4_185, void **, 0x48), ((temp_r4_193 == NULL) == 0)) && (var_r0_196 = M2C_FIELD(temp_r4_193, u32 *, 8), ((var_r0_196 == 0U) == 0))) {

            } else {
                var_r0_196 = 0U;
            }
            if (var_r0_196 != 0U) {
                if (temp_r3_179 != 0) {
                    var_r3_209 = temp_r5_178 + ((temp_r3_179 - 1) * 0x58);
                } else {
                    var_r3_209 = NULL;
                }
                if (((u8) M2C_FIELD(var_r3_209, u8 *, 0x50) != 0) && (temp_r3_217 = M2C_FIELD(var_r3_209, void **, 0x48), ((temp_r3_217 == NULL) == 0)) && (var_r3_220 = M2C_FIELD(temp_r3_217, void ***, 8), ((var_r3_220 == NULL) == 0))) {

                } else {
                    var_r3_220 = NULL;
                }
                if (!(M2C_FIELD(*var_r3_220, s32 *, 0xC) & 0x20000)) {
                    goto block_22;
                }
                goto block_25;
            }
block_22:
            sp18 = 0.0f;
            sp1C = 50.0f;
            sp20 = 0.0f;
            sp58 = (f64) sp18;
            sp60 = (f64) sp20;
            temp_f5_241 = this->unk0;
            sp8 = temp_f5_241 - sp58;
            temp_f4_245 = M2C_FIELD(this, f32 *, 8);
            sp40 = 0.0f;
            sp38 = 0.0f;
            sp3C = 50.0f;
            sp10 = temp_f4_245 - (f32) sp60;
            sp78 = (f64) sp38;
            sp68 = sp8;
            sp70 = (f64) sp10;
            sp80 = (f64) sp40;
            temp_f0_261 = temp_f5_241 + sp78;
            sp28 = temp_f0_261;
            sp88 = temp_f0_261;
            sp30 = temp_f4_245 + (f32) sp80;
            sp90 = (f64) sp30;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp88), *((MKVector3 *) &sp68), &spB8, (MKCollisionMode) 5, 0) != 0) {
                temp_f5_282 = spB8.unk4 - M2C_FIELD(this, f32 *, 4);
                temp_f4_284 = M2C_BITWISE(f32, spB8) - (f32) M2C_FIELD(this, f64 *, 0);
                temp_f3_288 = spB8.unk8 - M2C_FIELD(this, f32 *, 8);
                if (((temp_f3_288 * temp_f3_288) + ((temp_f4_284 * temp_f4_284) + (temp_f5_282 * temp_f5_282))) < 20.0f) {
                    M2C_FIELD(sret, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
                    M2C_FIELD(sret, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
                    return result;
                }
            }
            goto block_25;
        }
    }
block_25:
    sp98 = M2C_FIELD(this, f64 *, 0x10);
    spA0 = M2C_FIELD(this, f64 *, 0x18);
    if (arg2 != 0) {
        sp98 *= (f64) gUpdateTimeDelta;
        spA0 = (f32) spA0 * gUpdateTimeDelta;
    }
    *(sret) = UpdateCollisions(*((MKVector3 *) &sp98), arg2);
    return result;
}
#endif

s32 MovementObject::LoadLine(MKIniLine *arg0) {
    s32 var_r31_344;

    var_r31_344 = 0;
    if ((arg0->LoadVector3("pos", &this->unk30, 0) != 0) || (arg0->LoadVector3("rot", &this->unk40, 0) != 0)) {
        var_r31_344 = 1;
    }
    return var_r31_344;
}

void MovementObject::Init(MovementObjectDescriptor *arg0, CollisionObject *arg1) {
    this->unk50 = arg0;
    this->unk54 = arg1;
    this->unk58 = arg0->unk4;
    this->unk5C = arg0->unk8;
    this->unk60 = arg0->unkC;
    this->unk64 = 0;
}

MovementObject::MovementObject() {
    memset(this, 0, 0x78U);
}
