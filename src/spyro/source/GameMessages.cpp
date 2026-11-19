#include "spyro/source/GameMessages.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
u8 FuryEventCameraMsg::IsSenderBehindWall(EventCamera *arg0) {
    MKCollisionResult spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;                                       /* compiler-managed */
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f2_185;
    f32 var_f4_126;
    f32 var_f5_59;
    f64 *var_r4_200;
    f64 temp_f0_188;
    f64 temp_f0_198;
    f64 temp_f1_33;
    f64 temp_f1_65;
    f64 temp_f1_71;
    f64 temp_f1_75;
    s32 temp_r31_147;
    s32 temp_r3_94;
    s32 var_r0_104;
    s32 var_r29_133;
    void *temp_r3_31;

    if ((void *) this->unk4 != NULL) {
        sp90 = arg0->GetSourceStart();
        temp_r3_31 = M2C_FIELD(this->unk4, void **, 8);
        temp_f1_33 = M2C_FIELD(temp_r3_31, f64 *, 0x30);
        spE0 = M2C_BITWISE(f64, sp90);
        spD0 = temp_f1_33;
        spE8 = (f64) sp90.unk8;
        spD8 = M2C_FIELD(temp_r3_31, f64 *, 0x38);
        sp40 = temp_f1_33 - spE0;
        spC0 = sp40;
        sp48 = (f32) spD8 - (f32) spE8;
        spC8 = (f64) sp48;
        var_f5_59 = ((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + ((*(f32 *) ((u8 *) &spB8 + 0xc)) * (*(f32 *) ((u8 *) &spB8 + 0xc))));
        if (var_f5_59 > 0.000001f) {
            if (var_f5_59 > 0.0f) {
                temp_f1_65 = __frsqrte(var_f5_59);
                temp_f1_71 = 0.5 * temp_f1_65 * -(((f64) var_f5_59 * (temp_f1_65 * temp_f1_65)) - 3.0);
                temp_f1_75 = 0.5 * temp_f1_71 * -(((f64) var_f5_59 * (temp_f1_71 * temp_f1_71)) - 3.0);
                var_f5_59 = (f32) ((f64) var_f5_59 * (0.5 * temp_f1_75 * -(((f64) var_f5_59 * (temp_f1_75 * temp_f1_75)) - 3.0)));
            } else if (var_f5_59 < M2C_BITWISE(f32, 0.0)) {
                var_f5_59 = __float_nan;
            } else {
                sp8 = var_f5_59;
                temp_r3_94 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_94) {               /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_104 = 1;
                    } else {
                        var_r0_104 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_104 = 5;
                    } else {
                        var_r0_104 = 3;
                    }
                    break;
                default:
                    var_r0_104 = 4;
                    break;
                }
                if (var_r0_104 == 1) {
                    var_f5_59 = __float_nan;
                }
            }
            var_f4_126 = 1.0f / var_f5_59;
        } else {
            var_f4_126 = 0.0f;
            var_f5_59 = 0.0f;
        }
        var_r29_133 = 1;
        spC0 = (f32) spC0 * var_f4_126;
        temp_r31_147 = (s32) (var_f5_59 / 500.0f) + 1;
        (*(f32 *) ((u8 *) &spB8 + 0xc)) *= var_f4_126;
        spC8 = (f32) spC8 * var_f4_126;
loop_28:
        if (var_r29_133 > temp_r31_147) {
            goto block_29;
        }
        sp70 = ((MKVector3 *) &spC0)->operator*(500.0f * (f32) (var_r29_133 - 1));
        sp30 = spE0 + M2C_BITWISE(f64, sp70);
        sp80 = sp30;
        sp38 = (f32) spE8 + sp70.unk8;
        spB0 = sp30;
        sp88 = (f64) sp38;
        spB8 = (f64) sp38;
        if (var_r29_133 != temp_r31_147) {
            temp_f2_185 = 500.0f * (f32) var_r29_133;
            temp_f0_188 = (f64) spC0 * (f64) temp_f2_185;
            sp20 = temp_f0_188;
            sp60 = temp_f0_188;
            sp28 = spC8 * temp_f2_185;
            sp68 = (f64) sp28;
            temp_f0_198 = spE0 + temp_f0_188;
            sp10 = temp_f0_198;
            var_r4_200 = &sp50;
            sp50 = temp_f0_198;
            sp18 = (f32) spE8 + (f32) sp68;
            sp58 = (f64) sp18;
        } else {
            var_r4_200 = &spD0;
        }
        spA0 = M2C_FIELD(var_r4_200, f64 *, 0);
        spA8 = M2C_FIELD(var_r4_200, f64 *, 8);
        if (MKCollision_RayCollide(*((MKVector3 *) &spB0), *((MKVector3 *) &spA0), &spF0, (MKCollisionMode) 5, 0) != 0) {
            return 1U;
        }
        var_r29_133 += 1;
        goto loop_28;
    }
block_29:
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
s32 FuryEventCameraMsg::AddCamera(EventCamera *arg0) {
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_297;
    s32 temp_r0_280;
    s32 var_ctr_328;
    s32 var_r30_325;
    s32 var_r3_327;
    s32 var_r6_326;
    void *temp_r3_357;
    void *temp_r5_289;
    void *temp_r5_345;

    if (IsSenderBehindWall(arg0) == 0) {
        temp_r0_280 = this->unk58;
        if (temp_r0_280 < 0xA) {
            M2C_FIELD((this + (temp_r0_280 * 4)), EventCamera **, 8) = arg0;
            temp_r5_289 = M2C_FIELD(this->unk4, void **, 8);
            sp58 = M2C_FIELD(temp_r5_289, f64 *, 0x30);
            sp60 = M2C_FIELD(temp_r5_289, f64 *, 0x38);
            sp68 = arg0->GetSourceStart();
            temp_f0_297 = M2C_BITWISE(f64, sp68) - sp58;
            sp18 = temp_f0_297;
            sp78 = temp_f0_297;
            sp20 = sp68.unk8 - (f32) sp60;
            sp80 = (f64) sp20;
            M2C_FIELD((this + (this->unk58 * 4)), f32 *, 0x30) = (f32) (((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * (*(f32 *) ((u8 *) &sp78 + 0x4)))));
            this->unk58 += 1;
            return 1;
        }
        var_r30_325 = 0;
        var_r6_326 = 1;
        var_r3_327 = 4;
        var_ctr_328 = 9;
        do {
            if (*(this + (var_r3_327 + 0x30)) > *(this + ((var_r30_325 * 4) + 0x30))) {
                var_r30_325 = var_r6_326;
            }
            var_r6_326 += 1;
            var_r3_327 += 4;
            var_ctr_328 -= 1;
        } while (var_ctr_328 != 0);
        temp_r5_345 = M2C_FIELD(this->unk4, void **, 8);
        sp28 = M2C_FIELD(temp_r5_345, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r5_345, f64 *, 0x38);
        sp38 = arg0->GetSourceStart();
        sp8 = M2C_BITWISE(f64, sp38) - sp28;
        temp_r3_357 = this + (var_r30_325 * 4);
        sp48 = sp8;
        sp10 = sp38.unk8 - (f32) sp30;
        sp50 = (f64) sp10;
        if ((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp48 + 0x4))))) < M2C_FIELD(temp_r3_357, f32 *, 0x30)) {
            M2C_FIELD(temp_r3_357, EventCamera **, 8) = arg0;
            return 1;
        }
        return 0;
    }
    return 0;
}
#endif

void GetNearestEventCameraMsg::Test(MKProp *arg0, const MKVector3 &arg1) {
    f32 temp_f1_410;
    f32 temp_f2_403;
    f32 temp_f3_400;
    f32 temp_f4_397;

    temp_f4_397 = this->unkC - arg1.unk4;
    temp_f3_400 = this->unk8 - arg1.unk0;
    temp_f2_403 = this->unk10 - arg1.unk8;
    temp_f1_410 = (temp_f2_403 * temp_f2_403) + ((temp_f3_400 * temp_f3_400) + (temp_f4_397 * temp_f4_397));
    if ((M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x10000) && (temp_f1_410 < this->unk20) && (((MKProp *) this->unk18 == NULL) || (temp_f1_410 < this->unk1C))) {
        this->unk18 = arg0;
        this->unk1C = temp_f1_410;
    }
}

void BreathHitMessage::Init(MKProp *arg0, float arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_457;
    f64 temp_f1_456;
    u32 temp_r4_450;
    void *temp_r4_453;

    this->unk0 = 5;
    this->unk8 = (u32) arg0;
    this->unk34 = arg1;
    this->unk38 = arg2;
    this->unk3C = arg3;
    this->unk40 = arg4;
    this->unk44 = arg5;
    this->unk50 = 0;
    this->unk48 = arg6;
    this->unk4C = arg7;
    this->unk20.unk0 = 0.0f;
    this->unk20.unk4 = 0.0f;
    this->unk20.unk8 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    temp_r4_450 = this->unk8;
    if (temp_r4_450 != 0) {
        temp_r4_453 = M2C_FIELD(temp_r4_450, void **, 8);
        if (temp_r4_453 != NULL) {
            temp_f1_456 = M2C_FIELD(temp_r4_453, f64 *, 0x30);
            temp_f0_457 = M2C_FIELD(temp_r4_453, f64 *, 0x38);
            sp8 = temp_f1_456;
            M2C_FIELD(this, f32 *, 0x10) = temp_f1_456;
            sp10 = temp_f0_457;
            M2C_FIELD(this, f32 *, 0x18) = temp_f0_457;
        }
    }
    this->unk30 = NULL;
}

void BreathHitMessage::Init(MKProp *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    Init(arg0, (f32) arg1, arg2, arg3, arg4, arg5, arg6, -1);
}

void IsInAlertRangeMsg::Test(Enemy *arg0) {
    f64 sp10;
    f64 sp8;
    f32 temp_f1_518;
    f32 temp_f3_514;
    f32 temp_f4_509;
    f32 temp_f5_508;
    void *temp_r5_499;

    temp_r5_499 = arg0->unk8;
    sp8 = M2C_FIELD(temp_r5_499, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_499, f64 *, 0x38);
    temp_f5_508 = (*(f32 *) ((u8 *) &sp8 + 0x4)) - this->unkC;
    temp_f4_509 = (f32) sp8 - this->unk8;
    temp_f3_514 = (f32) sp10 - this->unk10;
    temp_f1_518 = (temp_f3_514 * temp_f3_514) + ((temp_f4_509 * temp_f4_509) + (temp_f5_508 * temp_f5_508));
    if ((temp_f1_518 < this->unk18) && (((Enemy *) this->unk1C == NULL) || (temp_f1_518 < this->unk20))) {
        this->unk1C = arg0;
        this->unk20 = temp_f1_518;
    }
}

void IsInAlertRangeMsg::Init(const MKVector3 &arg0, float arg1) {
    this->unk0 = 0x72;
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk18 = arg1 * arg1;
    this->unk1C = NULL;
    this->unk20 = 3.4028235e38f;
}

void FindNearestCollectableMsg::Test(Collectable *arg0) {
    f32 sp8[3];
    f32 temp_f1_599;
    f32 temp_f3_595;
    f32 temp_f4_591;
    f32 temp_f5_589;
    s32 temp_r5_576;

    if ((arg0 != NULL) && (this->unk18 & (1 << arg0->GetItemType())) && ((s32) arg0->unkD4 == 6)) {
        temp_r5_576 = this->unk1C;
        this->unk1C = temp_r5_576 + 1;
        /* The asm loads the vptr from offset 0x44, then slot 0x44 writes the position as three f32 at sp8. */
        M2C_FIELD(M2C_FIELD(arg0, void ***, 0x44), M2C_UNK (**)(f32 *, Collectable *, s32), 0x44)(sp8, arg0, temp_r5_576);
        temp_f5_589 = sp8[1] - this->unkC;
        temp_f4_591 = sp8[0] - this->unk8;
        temp_f3_595 = sp8[2] - this->unk10;
        temp_f1_599 = (temp_f3_595 * temp_f3_595) + ((temp_f4_591 * temp_f4_591) + (temp_f5_589 * temp_f5_589));
        if (temp_f1_599 < this->unk20) {
            this->unk24 = arg0;
            this->unk20 = temp_f1_599;
        }
    }
}

HitHeroSndMsg::HitHeroSndMsg() {
    this->unk4 = 0;
    this->unk8 = GS_PLACEHOLDER;
    this->unk0 = 0x16;
}
