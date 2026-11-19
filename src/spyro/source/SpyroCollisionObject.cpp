#include "spyro/source/SpyroCollisionObject.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CollisionObject.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
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
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroCollisionObject::PushOutOfThings(MKVector3 arg0) {
    MKCollisionResult *temp_r23_166;
    MKProp *temp_r3_259;
    MKProp *temp_r3_356;
    f32 *temp_r7_130;
    f32 temp_f0_383;
    f32 temp_f0_408;
    f32 temp_f0_439;
    f32 temp_f1_382;
    f32 temp_f30_93;
    f32 temp_f3_385;
    s32 temp_r3_137;
    s32 var_ctr_99;
    s32 var_r25_159;
    s32 var_r28_158;
    s32 var_r4_81;
    s8 *var_r3_95;
    u8 *var_r24_155;
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

    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, SpyroCollisionObject *), 0x50)(&unkspB8, this);
    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, SpyroCollisionObject *), 0x4C)(&unkspC8, this);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    var_r4_81 = 0;
    unkspF8 = unksp58;
    unksp60 = unkspD0 + unkspC0;
    unksp100 = unksp60;
    temp_f30_93 = 2.0f + M2C_FIELD(this->unk460, f32 *, 0);
    var_r3_95 = &unksp108;
    var_ctr_99 = 0x1E;
    do {
        temp_r6_103 = &unksp180 + var_r4_81;
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
    temp_r3_137 = MKCollision_SphereCollide(*((MKVector3 *) &unkspF8), temp_f30_93, (MKCollisionResult *) &unksp180, 0x1E, (MKCollisionMode) M2C_FIELD(temp_r7_130, s32 *, 8), M2C_FIELD(temp_r7_130, s32 *, 0x18));
    if (temp_r3_137 != 0) {
        Tools_UpdateSphereCollideResults((MKCollisionResult *) &unksp180, temp_r3_137, *((MKVector3 *) &unkspF8));
        Tools_PushOut((MKCollisionResult *) &unksp180, *((MKVector3 *) &unkspF8), temp_r3_137, temp_f30_93, &unksp108, 0.0009999999f + (M2C_FIELD(this->unk460, f32 *, 0) / temp_f30_93));
        var_r24_155 = &unksp108;
        var_r30_156 = 0;
        var_r29_157 = 0;
        var_r28_158 = 0;
        var_r25_159 = 0;
loop_46:
        if (var_r28_158 < temp_r3_137) {
            if ((u8) *var_r24_155 != 0) {
                temp_r23_166 = &unksp180 + var_r25_159;
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
                        unkspEC = 0;
                        unkspE8 = 0x12;
                        unkspF0 = temp_r22_182;
                        unkspF4 = this;
                        if (((u8) temp_r23_166->unk50 != 0) && (temp_r3_205 = temp_r23_166->unk48, ((temp_r3_205 == NULL) == 0)) && (var_r3_208 = M2C_FIELD(temp_r3_205, void **, 8), ((var_r3_208 == NULL) == 0))) {

                        } else {
                            var_r3_208 = NULL;
                        }
                        M2C_FIELD(M2C_FIELD(var_r3_208, void **, 0x44), M2C_UNK (**)(M2C_UNK *), 0x2C)(&unkspE8);
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
                        unksp28 = -M2C_FIELD(temp_r3_262, f32 *, 0x20);
                        unksp2C = -M2C_FIELD(temp_r3_262, f32 *, 0x24);
                        unksp30 = -M2C_FIELD(temp_r3_262, f32 *, 0x28);
                        unkspA8 = unksp28;
                        unkspB0 = unksp30;
                        unksp48 = -unkspA8;
                        unksp4C = -unkspAC;
                        unksp50 = -unkspB0;
                        unkspD8 = unksp48;
                        unkspDC = 0.2f;
                        unkspE0 = unksp50;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                        unksp12C = 0;
                        unkspE0 *= 500.0f;
                        if (((u8) temp_r23_166->unk50 != 0) && (temp_r3_303 = temp_r23_166->unk48, ((temp_r3_303 == NULL) == 0)) && (var_r4_306 = M2C_FIELD(temp_r3_303, void **, 8), ((var_r4_306 == NULL) == 0))) {

                        } else {
                            var_r4_306 = NULL;
                        }
                        unksp128 = 7;
                        unksp150 = 1;
                        unksp154 = var_r4_306;
                        unksp130 = unkspD8;
                        unksp138 = unkspE0;
                        unksp168 = 0;
                        unksp174 = 2;
                        unksp170 = 10.0f;
                        unksp169 = 0;
                        unksp16A = 1;
                        unksp16C = -1;
                        unksp140 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        unksp148 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        unksp178 = 0;
                        if (var_r4_306 != NULL) {
                            unksp38.GetPos();
                            unksp158 = unksp38;
                            unksp160 = unksp40;
                        } else {
                            unksp158 = 0.0f;
                            unksp15C = 0.0f;
                            unksp160 = 0.0f;
                        }
                        unksp179 = 0;
                        temp_r3_356 = this->unk470;
                        temp_r3_356->Message(&unksp128);
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
                M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, SpyroCollisionObject *), 0x50)(&unksp88, this);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                temp_f0_408 = unksp100 - unksp90;
                this->unk450 = unksp18;
                unksp20 = temp_f0_408;
                unksp98 = unksp18;
                unkspA0 = (f64) temp_f0_408;
                this->unk458 = (f64) temp_f0_408;
                return;
            }
            if (var_r29_157 != 0) {
                M2C_FIELD(this, f32 *, 0x454) = (f32) (unkspFC - M2C_FIELD(this->unk460, f32 *, 4));
            }
        } else {
            M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, SpyroCollisionObject *), 0x50)(&unksp68, this);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_f0_439 = unksp100 - unksp70;
            this->unk450 = unksp8;
            unksp10 = temp_f0_439;
            unksp78 = unksp8;
            unksp80 = (f64) temp_f0_439;
            this->unk458 = (f64) temp_f0_439;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
s32 SpyroCollisionObject::GlueToGround() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    M2C_UNK sp60;
    f64 sp58;
    f64 sp50;
    M2C_UNK sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r4_466;
    f32 *temp_r7_509;
    f32 temp_f1_503;
    f32 temp_f2_497;

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
    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, SpyroCollisionObject *, f64, f32), 0x50)(&sp60, this, (f64) sp30, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_f2_497 = M2C_FIELD(this, f32 *, 0x458);
    temp_f1_503 = temp_f2_497 + sp68;
    sp70 = sp20;
    sp28 = temp_f1_503;
    sp78 = (f64) sp28;
    temp_r7_509 = this->unk460;
    M2C_FIELD(temp_r7_509, s32 *, 0x24) = 4;
    ResolveCollisions(&sp70, &sp80, 3, temp_r7_509, temp_f1_503, temp_f2_497);
    M2C_FIELD(this->unk460, s32 *, 0x24) = 1;
    if ((s32) this->unk16C > 0) {
        M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, SpyroCollisionObject *, f64, f32), 0x50)(&sp40, this);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
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

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void SpyroCollisionObject::Init(ColObjDescriptor *arg0, const MKVector3 &arg1, bool arg2, MKCollisionInfo *arg3, bool arg4, bool arg5, unsigned int arg6, MKProp *arg7, bool arg8) {
    f64 sp10;
    s32 spC;
    s32 sp8;

    sp8 = arg_sp8;
    spC = (s32) arg_spC;
    CollisionObject::Init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
    MKVector(0.0f, M2C_FIELD(this->unk460, f32 *, 4), 0.0f);
    this->unk480 = sp10;
    this->unk488 = sp18;
    this->unk47C = 20.0f;
    this->unk478 = 20.0f;
}
#endif
