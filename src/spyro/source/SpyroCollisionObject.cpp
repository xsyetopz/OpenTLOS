#include "spyro/source/SpyroCollisionObject.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

u8 SpyroCollisionObject::IsFloorCollision(MKCollisionResult *arg0) {
    f32 *temp_r5_21;
    s32 temp_r6_22;

    temp_r5_21 = this->unk460;
    temp_r6_22 = arg0->unk44;
    if (!(temp_r6_22 & M2C_FIELD(temp_r5_21, s32 *, 0x38)) && ((((MKVector3::up.unk8 * arg0->unk18) + ((MKVector3::up.unk0 * arg0->unk10) + (MKVector3::up.unk4 * arg0->unk14))) > M2C_FIELD(temp_r5_21, f32 *, 0x1C)) || (temp_r6_22 & M2C_FIELD(temp_r5_21, s32 *, 0x28)))) {
        return 1U;
    }
    return 0U;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroCollisionObject::PushOutOfThings(MKVector3 arg0) {
    MKCollisionResult sp180;
    s8 sp179;
    s8 sp178;
    s32 sp174;
    f32 sp170;
    s32 sp16C;
    s8 sp16A;
    s8 sp169;
    s8 sp168;
    f64 sp160;                                      /* compiler-managed */
    f64 sp158;                                      /* compiler-managed */
    void *sp154;
    s32 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    s32 sp12C;
    s32 sp128;
    u8 sp108;
    f64 sp100;
    f64 spF8;
    SpyroCollisionObject *spF4;
    void *spF0;
    s32 spEC;
    s32 spE8;
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;
    f64 spC8;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKCollisionResult *temp_r23_166;
    MKProp *temp_r3_259;
    MKProp *temp_r3_356;
    f32 *temp_r7_130;
    f32 temp_f0_383;
    f32 temp_f1_382;
    f32 temp_f30_93;
    f32 temp_f3_385;
    f64 temp_f0_79;
    s32 temp_r3_137;
    s32 var_ctr_99;
    s32 var_r25_159;
    s32 var_r28_158;
    s32 var_r4_81;
    u8 *var_r24_155;
    u8 *var_r3_95;
    u8 temp_r3_187;
    u8 var_r29_157;
    u8 var_r30_156;
    void *temp_r22_182;
    void *temp_r3_170;
    void *temp_r3_205;
    void *temp_r3_226;
    void *temp_r3_244;
    void *temp_r3_262;
    void *temp_r3_303;
    void *temp_r6_103;
    void *var_r0_173;
    void *var_r0_247;
    void *var_r3_208;
    void *var_r3_229;
    void *var_r4_306;

    M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, SpyroCollisionObject *), 0x50)(&spB8, this);
    M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, SpyroCollisionObject *), 0x4C)(&spC8, this);
    temp_f0_79 = spC8 + spB8;
    sp58 = temp_f0_79;
    var_r4_81 = 0;
    spF8 = temp_f0_79;
    sp60 = spD0 + spC0;
    sp100 = (f64) sp60;
    temp_f30_93 = 2.0f + M2C_FIELD(this->unk460, f32 *, 0);
    var_r3_95 = &sp108;
    var_ctr_99 = 0x1E;
    do {
        temp_r6_103 = &sp180 + var_r4_81;
        *var_r3_95 = 0;
        var_r3_95 += 1;
        M2C_FIELD(temp_r6_103, f32 *, 0) = 0.0f;
        var_r4_81 += 0x58;
        M2C_FIELD(temp_r6_103, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x10) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x24) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x2C) = 1.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x30) = 0.0f;
        M2C_FIELD(temp_r6_103, f32 *, 0x34) = 0.0f;
        M2C_FIELD(temp_r6_103, s16 *, 0x38) = 0;
        M2C_FIELD(temp_r6_103, s8 *, 0x3A) = 0;
        M2C_FIELD(temp_r6_103, s8 *, 0x3B) = 0;
        M2C_FIELD(temp_r6_103, s32 *, 0x3C) = 0;
        M2C_FIELD(temp_r6_103, f32 *, 0x40) = 3.4028235e38f;
        M2C_FIELD(temp_r6_103, s32 *, 0x44) = 0;
        M2C_FIELD(temp_r6_103, s32 *, 0x48) = 0;
        M2C_FIELD(temp_r6_103, s32 *, 0x4C) = -1;
        M2C_FIELD(temp_r6_103, s8 *, 0x50) = 0;
        var_ctr_99 -= 1;
    } while (var_ctr_99 != 0);
    temp_r7_130 = this->unk460;
    temp_r3_137 = MKCollision_SphereCollide(*((MKVector3 *) &spF8), temp_f30_93, &sp180, 0x1E, (MKCollisionMode) M2C_FIELD(temp_r7_130, s32 *, 8), M2C_FIELD(temp_r7_130, s32 *, 0x18));
    if (temp_r3_137 != 0) {
        Tools_UpdateSphereCollideResults(&sp180, temp_r3_137, *((MKVector3 *) &spF8));
        Tools_PushOut(&sp180, *((MKVector3 *) &spF8), temp_r3_137, temp_f30_93, &sp108, 0.0009999999f + (M2C_FIELD(this->unk460, f32 *, 0) / temp_f30_93));
        var_r24_155 = &sp108;
        var_r30_156 = 0;
        var_r29_157 = 0;
        var_r28_158 = 0;
        var_r25_159 = 0;
loop_46:
        if (var_r28_158 < temp_r3_137) {
            if ((u8) *var_r24_155 != 0) {
                temp_r23_166 = &sp180 + var_r25_159;
                if (((u8) temp_r23_166->unk50 != 0) && (temp_r3_170 = temp_r23_166->unk48, ((temp_r3_170 == NULL) == 0)) && (var_r0_173 = M2C_FIELD(temp_r3_170, void **, 8), ((var_r0_173 == NULL) == 0))) {

                } else {
                    var_r0_173 = NULL;
                }
                if (var_r0_173 != NULL) {
                    temp_r22_182 = temp_r23_166->unk48;
                    if (temp_r22_182 != NULL) {
                        temp_r3_187 = IsFloorCollision(temp_r23_166);
                        if (temp_r3_187 != 0) {
                            var_r29_157 = 1;
                        }
                        if (temp_r3_187 == 0) {
                            var_r30_156 = 1;
                        }
                        spEC = 0;
                        spE8 = 0x12;
                        spF0 = temp_r22_182;
                        spF4 = this;
                        if (((u8) temp_r23_166->unk50 != 0) && (temp_r3_205 = temp_r23_166->unk48, ((temp_r3_205 == NULL) == 0)) && (var_r3_208 = M2C_FIELD(temp_r3_205, void **, 8), ((var_r3_208 == NULL) == 0))) {

                        } else {
                            var_r3_208 = NULL;
                        }
                        M2C_FIELD(M2C_FIELD(var_r3_208, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spE8);
                        if ((MKMessage *) this->unk440 != NULL) {
                            if (((u8) temp_r23_166->unk50 != 0) && (temp_r3_226 = temp_r23_166->unk48, ((temp_r3_226 == NULL) == 0)) && (var_r3_229 = M2C_FIELD(temp_r3_226, void **, 8), ((var_r3_229 == NULL) == 0))) {

                            } else {
                                var_r3_229 = NULL;
                            }
                            M2C_FIELD(M2C_FIELD(var_r3_229, void **, 0x44), M2C_UNK (**)(), 0x2C)();
                        }
                    }
                }
                if (((u8) temp_r23_166->unk50 != 0) && (temp_r3_244 = temp_r23_166->unk48, ((temp_r3_244 == NULL) == 0)) && (var_r0_247 = M2C_FIELD(temp_r3_244, void **, 8), ((var_r0_247 == NULL) == 0))) {

                } else {
                    var_r0_247 = NULL;
                }
                if ((var_r0_247 != NULL) && (temp_r23_166->unk44 & 0x40000000)) {
                    temp_r3_259 = this->unk470;
                    if (temp_r3_259 != NULL) {
                        temp_r3_262 = temp_r3_259->unk8;
                        sp28 = -M2C_FIELD(temp_r3_262, f32 *, 0x20);
                        sp2C = -M2C_FIELD(temp_r3_262, f32 *, 0x24);
                        sp30 = -M2C_FIELD(temp_r3_262, f32 *, 0x28);
                        spA8 = (f64) sp28;
                        spB0 = (f64) sp30;
                        sp48 = -(f32) spA8;
                        sp4C = -(*(f32 *) ((u8 *) &spA8 + 0x4));
                        sp50 = -(f32) spB0;
                        spD8 = (f64) sp48;
                        (*(f32 *) ((u8 *) &spD8 + 0x4)) = 0.2f;
                        spE0 = (f64) sp50;
                        spD8 *= 5.634608575e-315;
                        sp12C = 0;
                        spE0 = (f32) spE0 * 500.0f;
                        if (((u8) temp_r23_166->unk50 != 0) && (temp_r3_303 = temp_r23_166->unk48, ((temp_r3_303 == NULL) == 0)) && (var_r4_306 = M2C_FIELD(temp_r3_303, void **, 8), ((var_r4_306 == NULL) == 0))) {

                        } else {
                            var_r4_306 = NULL;
                        }
                        sp128 = 7;
                        sp150 = 1;
                        sp154 = var_r4_306;
                        sp130 = spD8;
                        sp138 = (f64) spE0;
                        sp168 = 0;
                        sp174 = 2;
                        sp170 = 10.0f;
                        sp169 = 0;
                        sp16A = 1;
                        sp16C = -1;
                        sp140 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        sp148 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        sp178 = 0;
                        if (var_r4_306 != NULL) {
                            ((MKProp *) &sp38)->GetPos();
                            sp158 = sp38;
                            sp160 = sp40;
                        } else {
                            sp158 = 0.0f;
                            (*(f32 *) ((u8 *) &sp154 + 0x8)) = 0.0f;
                            sp160 = 0.0f;
                        }
                        sp179 = 0;
                        temp_r3_356 = this->unk470;
                        temp_r3_356->Message(&sp128);
                    }
                }
            }
            var_r28_158 += 1;
            var_r25_159 += 0x58;
            var_r24_155 += 1;
            goto loop_46;
        }
        if ((HasHitWall() == 0) && (HasHitRoof() == 0) && (temp_f1_382 = M2C_FIELD(arg0, f32 *, 0), temp_f0_383 = M2C_FIELD(arg0, f32 *, 4), temp_f3_385 = M2C_FIELD(arg0, f32 *, 8), ((((temp_f3_385 * temp_f3_385) + ((temp_f1_382 * temp_f1_382) + (temp_f0_383 * temp_f0_383))) < 0.01f) != 0))) {
            if (var_r30_156 != 0) {
                M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, SpyroCollisionObject *), 0x50)(&sp88, this);
                sp18 = spF8 - sp88;
                this->unk450 = sp18;
                sp20 = (f32) sp100 - sp90;
                sp98 = sp18;
                spA0 = (f64) sp20;
                this->unk458 = (f64) sp20;
                return;
            }
            if (var_r29_157 != 0) {
                M2C_FIELD(this, f32 *, 0x454) = (f32) ((*(f32 *) ((u8 *) &spF8 + 0x4)) - M2C_FIELD(this->unk460, f32 *, 4));
            }
        } else {
            M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, SpyroCollisionObject *), 0x50)(&sp68, this);
            sp8 = spF8 - sp68;
            this->unk450 = sp8;
            sp10 = (f32) sp100 - sp70;
            sp78 = sp8;
            sp80 = (f64) sp10;
            this->unk458 = (f64) sp10;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 SpyroCollisionObject::GlueToGround() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r4_466;
    f32 *temp_r7_509;
    f32 temp_f1_503;
    f32 temp_f2_497;
    f64 temp_f0_494;

    temp_r4_466 = this->unk464;
    sp8 = temp_r4_466;
    if (temp_r4_466 != NULL) {
        spC = temp_r4_466->unk4;
        temp_r4_466->unk4 = 0;
    }
    sp38 = 0.0f;
    sp30 = 0.0f;
    sp34 = -this->unk47C;
    sp88 = (f64) sp38;
    sp80 = (f64) sp30;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, SpyroCollisionObject *, f64, f32), 0x50)(&sp60, this, (f64) sp30, 0.0f);
    temp_f0_494 = this->unk450 + sp60;
    sp20 = temp_f0_494;
    temp_f2_497 = M2C_FIELD(this, f32 *, 0x458);
    temp_f1_503 = temp_f2_497 + sp68;
    sp70 = temp_f0_494;
    sp28 = temp_f1_503;
    sp78 = (f64) sp28;
    temp_r7_509 = this->unk460;
    M2C_FIELD(temp_r7_509, s32 *, 0x24) = 4;
    ResolveCollisions(&sp70, &sp80, 3, temp_r7_509, temp_f1_503, temp_f2_497);
    M2C_FIELD(this->unk460, s32 *, 0x24) = 1;
    if ((s32) this->unk16C > 0) {
        M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, SpyroCollisionObject *, f64, f32), 0x50)(&sp40, this);
        sp10 = sp70 - sp40;
        this->unk450 = sp10;
        sp18 = (f32) sp78 - sp48;
        sp50 = sp10;
        sp58 = (f64) sp18;
        this->unk458 = (f64) sp18;
    }
    if (sp8 != NULL) {
        sp8->unk4 = spC;
    }
    return 8;
}
#endif

s32 SpyroCollisionObject::Teleport(const MKVector3 &arg0, float arg1, int arg2) {
    CollisionObject::Teleport(arg0, arg1, arg2);
}

s32 SpyroCollisionObject::Update(MKVector3 *arg0, float arg1, bool arg2) {
    f32 temp_f1_599;
    f32 temp_f1_602;
    f32 temp_f3_600;
    f32 var_f2_592;

    CollisionObject::Update(arg0, arg1, arg2);
    if ((arg2 != 0) && ((s32) this->unk16C <= 0)) {
        GlueToGround();
    }
    var_f2_592 = 0.5f * (6.0f * gUpdateTimeDelta);
    if (var_f2_592 < 1.0f) {

    } else {
        var_f2_592 = 1.0f;
    }
    temp_f1_599 = this->unk47C;
    temp_f3_600 = this->unk478;
    temp_f1_602 = (var_f2_592 * (temp_f3_600 - temp_f1_599)) + temp_f1_599;
    this->unk47C = (var_f2_592 * (temp_f3_600 - temp_f1_602)) + temp_f1_602;
}

void SpyroCollisionObject::Init(ColObjDescriptor *arg0, const MKVector3 &arg1, bool arg2, MKCollisionInfo *arg3, bool arg4, bool arg5, unsigned int arg6, MKProp *arg7, bool arg8) {
    MKVector3 sp10;

    CollisionObject::Init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    sp10 = MKVector(0.0f, M2C_FIELD(this->unk460, f32 *, 4), 0.0f);
    *(MKVector3 *) &this->unk480 = sp10;
    this->unk47C = 20.0f;
    this->unk478 = 20.0f;
}
