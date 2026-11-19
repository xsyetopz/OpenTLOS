#include "spyro/source/MovementObject.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CollisionObject.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: undefined identifier 'sp10'
void MovementObject::UpdateCollisions(MKVector3 &arg0, bool arg1) {
    f64 sp8;
    f32 temp_f31_114;
    void **temp_r3_41;
    void **temp_r3_59;
    void **temp_r3_66;
    void **temp_r3_80;
    void **temp_r3_91;
    void **temp_r4_49;

    M2C_FIELD(&arg0, s32 *, 0x68) = (s32) (M2C_FIELD(&arg0, s32 *, 0x68) & 0xFFFFFFF8);
    if (!(M2C_FIELD(&arg0, s32 *, 0x60) & 1)) {
        M2C_FIELD(&arg0, f64 *, 0) = (f64) (M2C_FIELD(&arg0, f64 *, 0) + M2C_FIELD(arg1, f64 *, 0));
        arg0.unk8 += M2C_FIELD(arg1, f32 *, 8);
        this->unk0 = M2C_FIELD(arg1, f64 *, 0);
        this->unk8 = (f64) M2C_FIELD(arg1, f32 *, 8);
        return;
    }
    temp_r3_41 = M2C_FIELD(&arg0, void ***, 0x54);
    M2C_FIELD(*temp_r3_41, M2C_UNK (**)(void **, u8, M2C_UNK, f32), 0x10)(temp_r3_41, arg1, 0, 0.0f);
    temp_r4_49 = M2C_FIELD(&arg0, void ***, 0x54);
    M2C_FIELD(*temp_r4_49, M2C_UNK (**)(f64 *, void **), 0x4C)(&sp8, temp_r4_49);
    M2C_FIELD(&arg0, f64 *, 0) = sp8;
    M2C_FIELD(&arg0, f32 *, 8) = sp10;
    temp_r3_59 = M2C_FIELD(&arg0, void ***, 0x54);
    if (M2C_FIELD(*temp_r3_59, u8 (**)(void **, f64), 0x18)(temp_r3_59, sp8) != 0) {
        temp_r3_66 = M2C_FIELD(&arg0, void ***, 0x54);
        M2C_FIELD(&arg0, s32 *, 0x70) = M2C_FIELD(*temp_r3_66, s32 (**)(void **), 0x28)(temp_r3_66);
        M2C_FIELD(&arg0, s32 *, 0x68) = (s32) (M2C_FIELD(&arg0, s32 *, 0x68) | 1);
    } else {
        M2C_FIELD(&arg0, s32 *, 0x70) = 0;
    }
    temp_r3_80 = M2C_FIELD(&arg0, void ***, 0x54);
    if (M2C_FIELD(*temp_r3_80, u8 (**)(void **), 0x1C)(temp_r3_80) != 0) {
        M2C_FIELD(&arg0, s32 *, 0x68) = (s32) (M2C_FIELD(&arg0, s32 *, 0x68) | 2);
    }
    temp_r3_91 = M2C_FIELD(&arg0, void ***, 0x54);
    if (M2C_FIELD(*temp_r3_91, u8 (**)(void **), 0x20)(temp_r3_91) != 0) {
        M2C_FIELD(&arg0, s32 *, 0x68) = (s32) (M2C_FIELD(&arg0, s32 *, 0x68) | 4);
    }
    if (M2C_FIELD(&arg0, s32 *, 0x60) & 2) {
        M2C_FIELD(&arg0, f64 *, 0x10) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(&arg0, f64 *, 0x18) = (f64) M2C_FIELD(arg1, f32 *, 8);
        if ((u8) M2C_ERROR(/* Read from unset register $r6 */) != 0) {
            temp_f31_114 = 1.0f / gUpdateTimeDelta;
            M2C_FIELD(&arg0, f64 *, 0x10) = (f64) (M2C_FIELD(&arg0, f64 *, 0x10) * (f64) temp_f31_114);
            M2C_FIELD(&arg0, f64 *, 0x18) = (f32) ((f32) M2C_FIELD(&arg0, f64 *, 0x18) * temp_f31_114);
        }
    }
    this->unk0 = M2C_FIELD(arg1, f64 *, 0);
    this->unk8 = (f64) M2C_FIELD(arg1, f32 *, 8);
}
#endif

#if 0 // DRAFT: illegal type
void MovementObject::Update(bool arg0) {
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
    f32 temp_f3_288;
    f32 temp_f4_245;
    f32 temp_f4_284;
    f32 temp_f5_282;
    f64 temp_f0_261;
    f64 temp_f2_159;
    f64 temp_f5_241;
    s32 temp_r3_179;
    s32 temp_r5_178;
    u32 var_r0_196;
    void **var_r3_220;
    void *temp_r3_177;
    void *temp_r3_217;
    void *temp_r4_193;
    void *var_r3_209;
    void *var_r4_185;

    if ((u32) M2C_FIELD(arg0, u32 *, 0x64) == 1U) {
        this->unk0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        this->unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        return;
    }
    temp_f2_159 = M2C_FIELD(arg0, f64 *, 0x18);
    sp48 = M2C_FIELD(arg0, f64 *, 0x10);
    spB0 = temp_f2_159;
    (*(f32 *) ((u8 *) &sp48 + 0x4)) = 0.0f;
    sp50 = temp_f2_159;
    spA8 = sp48;
    if ((((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * (*(f32 *) ((u8 *) &spA8 + 0x4))))) < 1.0f) {
        temp_r3_177 = M2C_FIELD(arg0, void **, 0x54);
        temp_r5_178 = temp_r3_177 + 8;
        temp_r3_179 = M2C_FIELD(temp_r3_177, s32 *, 0x16C);
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
            temp_f5_241 = M2C_FIELD(arg0, f64 *, 0);
            sp8 = temp_f5_241 - sp58;
            temp_f4_245 = M2C_FIELD(arg0, f32 *, 8);
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
                temp_f5_282 = spB8.unk4 - M2C_FIELD(arg0, f32 *, 4);
                temp_f4_284 = M2C_BITWISE(f32, spB8) - (f32) M2C_FIELD(arg0, f64 *, 0);
                temp_f3_288 = spB8.unk8 - M2C_FIELD(arg0, f32 *, 8);
                if (((temp_f3_288 * temp_f3_288) + ((temp_f4_284 * temp_f4_284) + (temp_f5_282 * temp_f5_282))) < 20.0f) {
                    this->unk0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                    this->unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
                    return;
                }
            }
            goto block_25;
        }
    }
block_25:
    sp98 = M2C_FIELD(arg0, f64 *, 0x10);
    spA0 = M2C_FIELD(arg0, f64 *, 0x18);
    if ((u8) M2C_ERROR(/* Read from unset register $r5 */) != 0) {
        sp98 *= (f64) gUpdateTimeDelta;
        spA0 = (f32) spA0 * gUpdateTimeDelta;
    }
    UpdateCollisions(*((MKVector3 *) arg0), (u8) &sp98);
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

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MovementObject::MovementObject() {
    memset(this, 0, 0x78U);
    return this;
}
#endif
