#include "spyro/source/KDCamera.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDCameraDeltaDrag.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessages.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCameraState.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/MKCollisionTempDisableHelper.h"
#include "spyro/source/ShakeCameraMessage.h"
#include "unplaced_templates.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK __construct_array(M2C_UNK *, void (*)(MKCollisionTempDisableHelper *), MKCollisionTempDisableHelper *(*)(MKCollisionTempDisableHelper *, s16), M2C_UNK, M2C_UNK); /* extern */
M2C_UNK __destroy_arr(M2C_UNK *, MKCollisionTempDisableHelper *(*)(MKCollisionTempDisableHelper *, s16), M2C_UNK, M2C_UNK); /* extern */
M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(s32);                               /* extern */
extern M2C_UNK lit_585;
extern s8 gAssertBool;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: identifier 'cameraCollPushOut' redeclared
static s32 cameraCollPushOut = 2;
#endif

#if 0 // DRAFT: undefined identifier 'unkA4'
void KDCamera::UpdateCamera() {
    u8 spC;
    void *sp8;
    void *temp_r4_36;

    temp_r4_36 = this->unk50->unkA4;
    sp8 = temp_r4_36;
    if (temp_r4_36 != NULL) {
        spC = M2C_FIELD(temp_r4_36, u8 *, 4);
        M2C_FIELD(temp_r4_36, u8 *, 4) = 0U;
    }
    PreCameraUpdate();
    VisibleTargetUpdate();
    this->unk15C->Update();
    CollisionUpdate();
    PostCameraUpdate();
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
}
#endif

f32 KDCamera::GetSafePitch(float arg0, float arg1) {
    f32 temp_f0_78;
    f32 temp_f0_84;
    f32 var_f1_0;

    var_f1_0 = arg0;
    temp_f0_78 = -1.5707964f + arg1;
    if (var_f1_0 < temp_f0_78) {
        var_f1_0 = temp_f0_78;
    }
    temp_f0_84 = 1.5707964f - arg1;
    if (var_f1_0 > temp_f0_84) {
        return temp_f0_84;
    }
    return var_f1_0;
}

void KDCamera::GetSmoothToAngleDelta(float arg0, float arg1, float arg2) {
    KDMath_SmoothToAngle(arg0, arg1, arg2, gUpdateTimeDelta);
    KDMath_GetSmallestAngle(arg0, M2C_ERROR(/* Read from unset register $f1 */));
}

void KDCamera::GetSmoothedAngleOffset(float arg0, float arg1, float arg2) {
    f32 temp_f29_130;

    temp_f29_130 = NormaliseAngle(arg0);
    KDMath_SmoothToAngle(temp_f29_130, NormaliseAngle(arg1), arg2, gUpdateTimeDelta);
    KDMath_GetSmallestAngle(temp_f29_130, M2C_ERROR(/* Read from unset register $f1 */));
}

#if 0 // DRAFT: undefined identifier 'unksp44'
void KDCamera::GetIdealSource(const MKVector3 &arg0, const MKVector3 &arg1, MKVector3 *arg2) {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f31_270;
    f32 var_f1_277;
    f32 var_f31_266;
    f32 var_f4_166;
    f32 var_f5_185;
    f64 temp_f1_190;
    f64 temp_f1_196;
    f64 temp_f1_200;
    s32 temp_r3_219;
    s32 var_r0_229;
    void *temp_r31_171;
    void *temp_r3_269;

    var_f4_166 = 0.0f;
    sp30 = arg2->unk0;
    temp_r31_171 = M2C_ERROR(/* Read from unset register $r7 */);
    sp34 = 0.0f;
    sp38 = arg2->unk8;
    sp40 = (f64) sp30;
    sp48 = (f64) sp38;
    var_f5_185 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
    if (var_f5_185 > 1e-12f) {
        if (var_f5_185 > 0.0f) {
            temp_f1_190 = __frsqrte(var_f5_185);
            temp_f1_196 = 0.5 * temp_f1_190 * -(((f64) var_f5_185 * (temp_f1_190 * temp_f1_190)) - 3.0);
            temp_f1_200 = 0.5 * temp_f1_196 * -(((f64) var_f5_185 * (temp_f1_196 * temp_f1_196)) - 3.0);
            var_f5_185 = (f32) ((f64) var_f5_185 * (0.5 * temp_f1_200 * -(((f64) var_f5_185 * (temp_f1_200 * temp_f1_200)) - 3.0)));
        } else if (var_f5_185 < M2C_BITWISE(f32, 0.0)) {
            var_f5_185 = __float_nan;
        } else {
            sp8 = var_f5_185;
            temp_r3_219 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_219) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_229 = 1;
                } else {
                    var_r0_229 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_229 = 5;
                } else {
                    var_r0_229 = 3;
                }
                break;
            default:
                var_r0_229 = 4;
                break;
            }
            if (var_r0_229 == 1) {
                var_f5_185 = __float_nan;
            }
        }
        var_f4_166 = 1.0f / var_f5_185;
    }
    sp24 = unksp44 * var_f4_166;
    sp20 = (f32) sp40 * var_f4_166;
    sp28 = (f32) sp48 * var_f4_166;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    if (temp_r31_171 != NULL) {
        var_f31_266 = M2C_FIELD(temp_r31_171, f32 *, 8);
    } else {
        temp_r3_269 = M2C_FIELD(&arg0, void **, 0x54);
        temp_f31_270 = M2C_FIELD(temp_r3_269, f32 *, 0x28);
        var_f31_266 = ((KDCameraDeltaStagesEx *) (temp_r3_269 + 0x14))->GetZDelta() + temp_f31_270;
    }
    if (temp_r31_171 != NULL) {
        var_f1_277 = M2C_FIELD(temp_r31_171, f32 *, 4);
    } else {
        var_f1_277 = ((KDCameraDeltaStagesEx *) (M2C_FIELD(&arg0, void **, 0x54) + 0x14))->GetYDelta();
    }
    sp14 = arg1.unk4 + var_f1_277;
    sp10 = ((f32) sp50 * var_f31_266) + arg1.unk0;
    sp18 = ((f32) sp58 * var_f31_266) + arg1.unk8;
    M2C_FIELD(this, f64 *, 0) = (f64) sp10;
    M2C_FIELD(this, f64 *, 8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKModel *' to
f32 KDCamera::GetUpdatedSourceY(const MKVector3 &arg0, const MKVector3 &arg1, int arg2) {
    return M2C_BITWISE(f32, this->unk4);
}
#endif

#if 0 // DRAFT: illegal type
void KDCamera::GetUpdatedSource(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 *arg2, float arg3) {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    M2C_UNK sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    M2C_UNK sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f0_424;
    f32 temp_f28_341;
    f32 temp_f29_336;
    f32 temp_f31_416;
    void *temp_r31_337;
    void *temp_r4_332;

    temp_r4_332 = M2C_FIELD(&arg0, void **, 0x54);
    temp_f29_336 = M2C_FIELD(temp_r4_332, f32 *, 0x28);
    temp_r31_337 = M2C_ERROR(/* Read from unset register $r7 */);
    temp_f28_341 = ((KDCameraDeltaStagesEx *) (temp_r4_332 + 0x14))->GetZDelta() + temp_f29_336;
    if (temp_r31_337 != NULL) {
        MKVector(M2C_FIELD(temp_r31_337, f32 *, 0), 0.0f, M2C_FIELD(temp_r31_337, f32 *, 8));
        Normalise(spA8);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spB8 = sp28;
        sp30 = spA8.unk8 * -temp_f28_341;
        spD8 = sp28;
        spC0 = (f64) sp30;
        spE0 = (f64) sp30;
    } else {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spD8 = sp18;
        sp20 = arg1.unk8 - arg2->unk8;
        sp88 = sp18;
        sp90 = (f64) sp20;
        spE0 = (f64) sp20;
        unkspDC = 0.0f;
        Normalise(sp68);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp78 = sp8;
        sp10 = sp68.unk8 * temp_f28_341;
        spD8 = sp8;
        sp80 = (f64) sp10;
        spE0 = (f64) sp10;
    }
    if (arg3 != 0.0f) {
        KDMath_RotateVectorByYaw(sp58, arg3);
        spD8 = M2C_BITWISE(f64, sp58);
        spE0 = (f64) sp58.unk8;
    }
    temp_f31_416 = arg2->unk8 + (f32) spE0;
    temp_f0_424 = arg2->unk4 + ((KDCameraDeltaStagesEx *) (M2C_FIELD(&arg0, void **, 0x54) + 0x14))->GetYDelta();
    sp40 = temp_f31_416;
    sp3C = temp_f0_424;
    sp38 = arg2->unk0 + (f32) spD8;
    spD0 = (f64) sp40;
    spC8 = (f64) sp38;
    sp48.GetCollisionObjectPos();
    unkspCC = spC8.GetUpdatedSourceY(*((MKVector3 *) &sp48), *(M2C_FIELD(M2C_FIELD(arg0.unk0, void **, 0xA4), MKVector3 **, 0x18)), M2C_ERROR(/* Read from unset register $r6 */));
    M2C_FIELD(this, f64 *, 0) = spC8;
    M2C_FIELD(this, f64 *, 8) = spD0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void KDCamera::GetUpdatedTarget() {
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    KDCamera *temp_r31_468;
    KDCameraHeroData *temp_r4_493;

    temp_r31_468 = M2C_ERROR(/* Read from unset register $r4 */);
    sp40 = 0.0f;
    sp38 = 0.0f;
    spC0 = (f64) sp40;
    sp3C = M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x54), f32 *, 0x1C);
    spB8 = (f64) sp38;
    if ((f32) spC0 != 0.0f) {
        temp_r31_468->GetYaw();
        KDMath_RotateVectorByYaw(spA8, M2C_ERROR(/* Read from unset register $f1 */));
        spB8 = M2C_BITWISE(f64, spA8);
        spC0 = (f64) spA8.unk8;
    }
    temp_r4_493 = temp_r31_468->unk50;
    sp30 = 0.0f;
    sp28 = 0.0f;
    sp2C = temp_r31_468->unk140->unkC;
    sp78 = temp_r4_493->unk40;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    sp68 = temp_r4_493->unk60;
    sp70 = temp_r4_493->unk68;
    sp80 = temp_r4_493->unk48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp88 = sp18;
    sp20 = (f32) sp80 + (f32) spC0;
    sp90 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp98 = sp8;
    sp10 = (f32) sp90 + (f32) sp70;
    spA0 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0) = sp48;
    sp50 = (f32) spA0 + (f32) sp60;
    M2C_FIELD(this, f64 *, 8) = (f64) sp50;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void KDCamera::MiscMessage(MKMessage *arg0) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    u8 spC;
    void *sp8;
    KDCameraDeltaStagesEx *temp_r4_715;
    KDCameraHeroData *temp_r30_585;
    KDCameraJumpTargetOffset *temp_r3_693;
    M2C_UNK *temp_r3_665;
    M2C_UNK *temp_r4_630;
    M2C_UNK *temp_r4_668;
    M2C_UNK *temp_r4_678;
    M2C_UNK *temp_r6_639;
    M2C_UNK *temp_r6_641;
    M2C_UNK *var_r5_658;
    M2C_UNK *var_r6_615;
    f32 temp_f31_694;
    s32 temp_r3_574;
    u8 var_r5_616;
    void *temp_r3_614;
    void *temp_r3_657;
    void *temp_r3_745;
    void *temp_r4_735;

    if (this->unk58->CanMessageBeStored(arg0->unk0) != 0) {
        this->unk58->StoreMessage(arg0);
    }
    temp_r3_574 = arg0->unk0;
    switch (temp_r3_574) {
    case 0x40A:
        temp_r30_585 = this->unk50;
        temp_r30_585->Copy(*(checked_cast<P15HeroDataMessage), 9MKMessage>__FP9MKMessage(arg0));
        return;
    case 0x40C:
        this->unk13D = 1;
        return;
    case 0x40D:
        this->unk13C = 1;
        return;
    case 0x40E:
        this->unk13C = 0;
        return;
    case 0x40B:
        this->unk124 += M2C_FIELD(checked_cast<KDDataMessage<float, 1035> *, MKMessage>(arg0), f32 *, 8);
        return;
    case 0x40F:
        temp_r3_614 = checked_cast<AddCameraCollisionItemMessage *, MKMessage>(arg0);
        var_r6_615 = this->unk210;
        var_r5_616 = 0;
loop_13:
        if (var_r6_615 != NULL) {
            temp_r4_630 = *var_r6_615;
            if (temp_r4_630 != NULL) {
                if ((M2C_UNK *) *temp_r4_630 == (M2C_UNK *) M2C_FIELD(temp_r3_614, M2C_UNK **, 8)) {
                    var_r5_616 = 1;
                } else {
                    var_r6_615 += 4;
                    goto loop_13;
                }
            }
        }
        if (var_r5_616 == 0) {
            temp_r6_639 = this->unk210 - 4;
            this->unk210 = temp_r6_639;
            temp_r6_641 = *temp_r6_639;
            M2C_FIELD(temp_r6_641, M2C_UNK **, 0) = M2C_FIELD(temp_r3_614, M2C_UNK **, 8);
            M2C_FIELD(temp_r6_641, u8 *, 4) = (u8) (M2C_FIELD(temp_r6_641, u8 *, 4) & ~0x20);
            M2C_FIELD(temp_r6_641, u8 *, 4) = (u8) (M2C_FIELD(temp_r6_641, u8 *, 4) | 0x80);
            M2C_FIELD(temp_r6_641, u8 *, 4) = (u8) ((M2C_FIELD(temp_r6_641, u8 *, 4) & ~0x40) | ((M2C_FIELD(temp_r3_614, u8 *, 0xC) << 6) & 0x40));
            return;
        }
    default:
        return;
    case 0x410:
        temp_r3_657 = checked_cast<KDDataMessage<MKCollisionInfo *, 1040> *, MKMessage>(arg0);
        var_r5_658 = this->unk210;
loop_21:
        if (var_r5_658 != NULL) {
            temp_r4_678 = *var_r5_658;
            if (temp_r4_678 == NULL) {
                return;
            }
            if ((M2C_UNK *) *temp_r4_678 == (u32) M2C_FIELD(temp_r3_657, u32 *, 8)) {
                temp_r3_665 = this->unk210;
                this->unk210 = temp_r3_665 + 4;
                temp_r4_668 = *temp_r3_665;
                *temp_r3_665 = *var_r5_658;
                *var_r5_658 = temp_r4_668;
                return;
            }
            var_r5_658 += 4;
            goto loop_21;
        }
        break;
    case 0x411:
        this->unk158 |= 0x20;
        return;
    case 0x412:
        this->unk158 &= 0xFFFFFFDF;
        return;
    case 0x413:
        temp_r3_693 = this->unk140;
        temp_f31_694 = temp_r3_693->unk10;
        temp_r3_693->ClearData();
        this->unk140->unk10 = temp_f31_694;
        return;
    case 0x414:
        this->unk140->unk4 = 0;
        return;
    case 0x415:
        this->unk140->unk4 = 1;
        return;
    case 0x416:
        this->unk140->unk4 = 2;
        return;
    case 0x41E:
        temp_r4_715 = this->unk54;
        M2C_FIELD(temp_r4_715, s8 *, 0x38) = 1;
        M2C_FIELD(temp_r4_715, s8 *, 0x39) = 0;
        return;
    case 0x41F:
        ((KDCameraDeltaDrag *) ((KDCameraDeltaDrag *) (this->unk54 + 0x28)))->Disable(0U);
        return;
    case 0x420:
        ((KDCameraDeltaDrag *) ((KDCameraDeltaDrag *) (this->unk54 + 0x28)))->Disable(1U);
        return;
    case 0x421:
        temp_r4_735 = this->unk50->unkA4;
        sp8 = temp_r4_735;
        if (temp_r4_735 != NULL) {
            spC = M2C_FIELD(temp_r4_735, u8 *, 4);
            M2C_FIELD(temp_r4_735, u8 *, 4) = 0U;
        }
        temp_r3_745 = checked_cast<TestCameraSnapMessage *, MKMessage>(arg0);
        if ((u8) M2C_FIELD(temp_r3_745, u8 *, 0x49) != 0) {
            sp20 = -M2C_FIELD(temp_r3_745, f32 *, 0x18);
            sp24 = -M2C_FIELD(temp_r3_745, f32 *, 0x1C);
            sp28 = -M2C_FIELD(temp_r3_745, f32 *, 0x20);
            sp40 = (f64) sp20;
            sp48 = (f64) sp28;
            M2C_FIELD(temp_r3_745, u8 *, 0x48) = GetForceSnapPos(*((MKVector3 *) &sp40), *(temp_r3_745 + 8), temp_r3_745 + 0x28, temp_r3_745 + 0x38);
        } else {
            sp10 = -M2C_FIELD(temp_r3_745, f32 *, 0x18);
            sp14 = -M2C_FIELD(temp_r3_745, f32 *, 0x1C);
            sp18 = -M2C_FIELD(temp_r3_745, f32 *, 0x20);
            sp30 = (f64) sp10;
            sp38 = (f64) sp18;
            M2C_FIELD(temp_r3_745, u8 *, 0x48) = GetSnapPos(*((MKVector3 *) &sp30), *(temp_r3_745 + 8), temp_r3_745 + 0x28, temp_r3_745 + 0x38);
        }
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk210'
void KDCamera::SetCameraCollisionInfoItems(bool arg0) {
    M2C_UNK *temp_r6_1009;
    M2C_UNK *var_r7_969;
    u8 temp_r5_972;

    var_r7_969 = this->unk210;
loop_10:
    if (var_r7_969 != NULL) {
        temp_r6_1009 = *var_r7_969;
        if (temp_r6_1009 == NULL) {
            return;
        }
        temp_r5_972 = M2C_FIELD(temp_r6_1009, u8 *, 4);
        if ((temp_r5_972 >> 7U) & 1) {
            if (arg0 != 0) {
                M2C_FIELD(temp_r6_1009, u8 *, 4) = (u8) ((temp_r5_972 & ~0x20) | ((M2C_FIELD(M2C_FIELD(temp_r6_1009, M2C_UNK **, 0), u8 *, 4) << 5) & 0x20));
                if (((u8) M2C_FIELD(temp_r6_1009, u8 *, 4) >> 6U) & 1) {
                    M2C_FIELD(M2C_FIELD(temp_r6_1009, M2C_UNK **, 0), u8 *, 4) = 1U;
                } else {
                    M2C_FIELD(M2C_FIELD(temp_r6_1009, M2C_UNK **, 0), u8 *, 4) = 0U;
                }
            } else if ((temp_r5_972 >> 5U) & 1) {
                M2C_FIELD(M2C_FIELD(temp_r6_1009, M2C_UNK **, 0), u8 *, 4) = 1U;
            } else {
                M2C_FIELD(M2C_FIELD(temp_r6_1009, M2C_UNK **, 0), u8 *, 4) = 0U;
            }
        }
        var_r7_969 += 4;
        goto loop_10;
    }
}
#endif

s32 KDCamera::SnapToDirectionForce(const MKVector3 &arg0) {
    MKVector3 sp8;
    f32 temp_f29_1038;
    s32 var_r28_1044;
    s32 var_r29_1041;

    if (SnapToDirection(arg0) != 0) {
        return 1;
    }
    temp_f29_1038 = KDMath_GetYaw(arg0);
    var_r29_1041 = 1;
loop_3:
    var_r28_1044 = -1;
loop_4:
    KDMath_GetDirection(((f32) var_r29_1041 * (0.31415927f * (f32) var_r28_1044)) + temp_f29_1038);
    if (SnapToDirection(sp8) != 0) {
        return 1;
    }
    var_r28_1044 += 2;
    if (var_r28_1044 >= 2) {
        var_r29_1041 += 1;
        if (var_r29_1041 >= 0xA) {
            return 0;
        }
        goto loop_3;
    }
    goto loop_4;
}

#if 0 // DRAFT: expression syntax error
u8 KDCamera::SnapToDirection(const MKVector3 &arg0) {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 sp38;
    KDCameraSimpleDelta sp28;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDCameraDeltaStagesEx *temp_r31_1104;
    KDCameraDeltaStagesEx *temp_r3_1100;
    KDCameraHeroData *temp_r7_1140;
    KDCameraPoint *temp_r4_1148;
    f32 temp_f1_1110;
    f32 temp_f31_1105;
    f32 temp_f31_1108;
    u8 var_r0_1168;

    temp_r3_1100 = this->unk54;
    M2C_FIELD(temp_r3_1100, f32 *, 0x28) = 0.0f;
    M2C_FIELD(temp_r3_1100, f32 *, 0x34) = 0.0f;
    temp_r31_1104 = this->unk54;
    temp_f31_1105 = M2C_FIELD(temp_r31_1104, f32 *, 0x28);
    temp_f31_1108 = temp_r31_1104->GetZDelta() + temp_f31_1105;
    temp_f1_1110 = temp_r31_1104->GetYDelta();
    sp10 = temp_f31_1108;
    sp8 = 0.0f;
    spC = temp_f1_1110;
    sp90 = (f64) sp10;
    sp88 = (f64) sp8;
    sp48.GetHeroTargetPos();
    sp78 = sp48;
    sp80 = sp50;
    sp38.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &sp78), &arg0);
    sp68 = sp38;
    sp70 = sp40;
    temp_r7_1140 = this->unk50;
    sp58 = temp_r7_1140->unk50;
    sp60 = temp_r7_1140->unk58;
    if (IsPointSafeAndViewClear(*((MKVector3 *) &sp58), *((MKVector3 *) &sp68), NULL) != 0) {
        temp_r4_1148 = this->unkA4;
        M2C_FIELD(temp_r4_1148, f64 *, 0) = sp78;
        M2C_FIELD(temp_r4_1148, f64 *, 8) = sp80;
        UpdateLTW();
        Teleport(*((MKVector3 *) &sp68), 1U);
        this->unk20C = 0.0f;
        sp18.GetCurrentDeltaVector();
        sp28.GetIdealDeltaVector();
        var_r0_1168 = 0;
        if ((M2C_BITWISE(f32, sp28) == sp18) && (sp28.unk4 == sp1C) && (sp28.unk8 == sp20)) {
            var_r0_1168 = 1;
        }
        if (var_r0_1168 == 0) {
            this->unk54->DisablePitchOverride(0.0f);
        }
        return 1U;
    }
    return 0U;
}
#endif

u8 KDCamera::GetForceSnapPos(const MKVector3 &arg0, const MKVector3 &arg1, MKVector3 *arg2, MKVector3 *arg3) {
    MKVector3 sp8;
    f32 temp_f29_1296;
    s32 var_r28_1302;
    s32 var_r29_1299;

    if (GetSnapPos(arg0, arg1, arg2, arg3) != 0) {
        return 1U;
    }
    temp_f29_1296 = KDMath_GetYaw(arg0);
    var_r29_1299 = 1;
loop_3:
    var_r28_1302 = -1;
loop_4:
    KDMath_GetDirection(((f32) var_r29_1299 * (0.31415927f * (f32) var_r28_1302)) + temp_f29_1296);
    if (GetSnapPos(sp8, arg1, arg2, arg3) != 0) {
        return 1U;
    }
    var_r28_1302 += 2;
    if (var_r28_1302 >= 2) {
        var_r29_1299 += 1;
        if (var_r29_1299 >= 0xA) {
            return 0U;
        }
        goto loop_3;
    }
    goto loop_4;
}

#if 0 // DRAFT: expression syntax error
u8 KDCamera::GetSnapPos(const MKVector3 &arg0, const MKVector3 &arg1, MKVector3 *arg2, MKVector3 *arg3) {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    KDCameraDeltaStagesEx *temp_r31_1372;
    KDCameraDeltaStagesEx *temp_r3_1363;
    KDCameraDeltaStagesEx *temp_r4_1448;
    KDCameraHeroData *temp_r7_1409;
    f32 temp_f1_1378;
    f32 temp_f30_1373;
    f32 temp_f30_1376;
    f32 temp_f31_1367;
    u8 var_r30_1369;

    temp_r3_1363 = this->unk54;
    temp_f31_1367 = M2C_FIELD(temp_r3_1363, f32 *, 0x28);
    var_r30_1369 = 0;
    M2C_FIELD(temp_r3_1363, f32 *, 0x28) = 0.0f;
    M2C_FIELD(temp_r3_1363, f32 *, 0x34) = 0.0f;
    temp_r31_1372 = this->unk54;
    temp_f30_1373 = M2C_FIELD(temp_r31_1372, f32 *, 0x28);
    temp_f30_1376 = temp_r31_1372->GetZDelta() + temp_f30_1373;
    temp_f1_1378 = temp_r31_1372->GetYDelta();
    sp20 = temp_f30_1376;
    sp18 = 0.0f;
    sp1C = temp_f1_1378;
    spA0 = (f64) sp20;
    sp98 = (f64) sp18;
    sp58.GetHeroTargetPos(*((MKVector3 *) this));
    sp88 = sp58;
    sp90 = sp60;
    sp48.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &sp88), &arg0);
    sp78 = sp48;
    sp80 = sp50;
    temp_r7_1409 = this->unk50;
    sp68 = temp_r7_1409->unk50;
    sp70 = temp_r7_1409->unk58;
    if (IsPointSafeAndViewClear(*((MKVector3 *) &sp68), *((MKVector3 *) &sp78), NULL) != 0) {
        var_r30_1369 = 1;
    }
    if (arg2 != NULL) {
        M2C_FIELD(arg2, f64 *, 0) = sp78;
        M2C_FIELD(arg2, f64 *, 8) = sp80;
    }
    if (arg3 != NULL) {
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp28 = sp8;
        sp10 = (f32) sp90 - (f32) sp80;
        sp30 = (f64) sp10;
        Normalise(sp38);
        M2C_FIELD(arg3, f64 *, 0) = M2C_BITWISE(f64, sp38);
        M2C_FIELD(arg3, f64 *, 8) = (f64) sp38.unk8;
    }
    temp_r4_1448 = this->unk54;
    M2C_FIELD(temp_r4_1448, f32 *, 0x28) = temp_f31_1367;
    M2C_FIELD(temp_r4_1448, f32 *, 0x34) = 0.0f;
    return var_r30_1369;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 KDCamera::IsPointSafeAndViewClearSweep(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, int arg3, MKCollisionResult *arg4) {
    if ((IsPointSafe(arg1, NULL) != 0) && (SweepSphereCollide(arg0, arg1, arg2, arg4, (MKCollisionMode) M2C_FIELD(M2C_FIELD(this->unk0, void **, 0xA4), s32 *, 8), arg3, 1U) == 0)) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 KDCamera::IsPointSafeAndViewClear(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionResult *arg2) {
    void *temp_r8_1521;

    temp_r8_1521 = M2C_FIELD(this->unk0, void **, 0xA4);
    if ((RayCollide(arg0, arg1, arg2, (MKCollisionMode) M2C_FIELD(temp_r8_1521, s32 *, 8), M2C_FIELD(temp_r8_1521, s32 *, 0x18), 1U) == 0) && (IsPointSafe(arg1, arg2) != 0)) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 KDCamera::IsPointSafe(const MKVector3 &arg0, MKCollisionResult *arg1) {
    void *temp_r8_1554;

    temp_r8_1554 = M2C_FIELD(this->unk0, void **, 0xA4);
    return SphereCollide(arg0, M2C_FIELD(temp_r8_1554, f32 *, 0), arg1, 1, (MKCollisionMode) M2C_FIELD(temp_r8_1554, s32 *, 8), M2C_FIELD(temp_r8_1554, s32 *, 0x18), 1U) == 0;
}
#endif

void KDCamera::GetCollisionObjectPos() {
    void *temp_r4_1570;

    temp_r4_1570 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x200);
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1570, f64 *, 0x240);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1570, f64 *, 0x248);
}

void KDCamera::CameraWasTeleported(bool arg0) {
    f64 sp10;
    f64 sp8;
    KDCameraDeltaStagesEx *temp_r3_1598;
    KDCameraPoint *temp_r4_1588;
    KDCollisionObject *temp_r5_1587;
    f64 temp_f0_1590;
    f64 temp_f1_1589;

    temp_r5_1587 = this->unk200;
    temp_r4_1588 = this->unkA0;
    temp_f1_1589 = temp_r5_1587->unk240;
    temp_f0_1590 = temp_r5_1587->unk248;
    sp8 = temp_f1_1589;
    M2C_FIELD(temp_r4_1588, f64 *, 0) = temp_f1_1589;
    sp10 = temp_f0_1590;
    M2C_FIELD(temp_r4_1588, f64 *, 8) = temp_f0_1590;
    UpdateLTW();
    if (arg0 != 0) {
        temp_r3_1598 = this->unk54;
        M2C_FIELD(temp_r3_1598, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_1598, f32 *, 0x34) = 0.0f;
    }
    this->unk208 = 0.0f;
    this->unk124 = 0.0f;
    VisibleTargetDisable();
}

s8 KDCamera::TryTeleport(const MKVector3 &arg0, bool arg1) {
    u8 spC;
    KDCamera *sp8;

    sp8 = this;
    spC = 1;
    if (1U != 0U) {
        SetCameraCollisionInfoItems(1U);
    }
    if (this->unk200->Teleport(arg0, 10.0f, 0xA, NULL) != 0) {
        CameraWasTeleported(arg1);
        if (spC != 0) {
            sp8->SetCameraCollisionInfoItems(0U);
        }
        return 1;
    }
    if (spC != 0) {
        sp8->SetCameraCollisionInfoItems(0U);
    }
    return 0;
}

void KDCamera::Teleport(const MKVector3 &arg0, bool arg1) {
    gAssertBool = TryTeleport(arg0, arg1);
}

void KDCamera::UpdateStoredCollisionData(bool arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    KDCameraPoint *temp_r3_1705;
    KDCameraPoint *temp_r3_1711;
    f64 temp_f0_1707;
    f64 temp_f0_1714;
    f64 temp_f1_1706;
    f64 temp_f1_1713;
    void *temp_r4_1704;

    if (TestUserStateFlag(4U) != 0) {
        if (arg0 != 0) {
            this->unk20C = 0.0f;
            temp_r4_1704 = this->unk8;
            temp_r3_1705 = this->unkA0;
            temp_f1_1706 = M2C_FIELD(temp_r4_1704, f64 *, 0x30);
            temp_f0_1707 = M2C_FIELD(temp_r4_1704, f64 *, 0x38);
            sp18 = temp_f1_1706;
            M2C_FIELD(temp_r3_1705, f64 *, 0x10) = temp_f1_1706;
            M2C_FIELD(temp_r3_1705, f64 *, 0x18) = temp_f0_1707;
            temp_r3_1711 = this->unkA4;
            sp20 = temp_f0_1707;
            temp_f1_1713 = M2C_FIELD(temp_r3_1711, f64 *, 0);
            temp_f0_1714 = M2C_FIELD(temp_r3_1711, f64 *, 8);
            sp8 = temp_f1_1713;
            M2C_FIELD(temp_r3_1711, f64 *, 0x10) = temp_f1_1713;
            sp10 = temp_f0_1714;
            M2C_FIELD(temp_r3_1711, f64 *, 0x18) = temp_f0_1714;
            return;
        }
        this->unk20C += gUpdateTimeDelta;
    }
}

#if 0 // DRAFT: undefined identifier 'sp10'
void KDCamera::CollisionObjectUpdate(const MKVector3 &arg0) {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    u8 spC;
    KDCamera *sp8;
    KDCameraPoint *temp_r4_1843;
    KDCollisionObject *temp_r3_1750;
    KDCollisionObject *temp_r5_1840;
    f32 var_f0_1857;
    f64 temp_f0_1846;
    f64 temp_f1_1844;
    s32 *temp_r5_1772;
    s32 temp_r4_1773;
    u32 var_r0_1791;
    u8 temp_r30_1847;
    void **var_r3_1816;
    void *temp_r3_1788;
    void *temp_r3_1813;
    void *var_r3_1780;
    void *var_r3_1805;

    sp8 = this;
    spC = 1;
    if (1U != 0U) {
        SetCameraCollisionInfoItems(1U);
    }
    temp_r3_1750 = this->unk200;
    sp40 = temp_r3_1750->unk240;
    sp48 = temp_r3_1750->unk248;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp50 = sp10;
    sp18 = arg0.unk8 - (f32) sp48;
    sp58 = (f64) sp18;
    if ((s32) cameraCollPushOut != 1) {
        if ((s32) cameraCollPushOut == 2) {
            temp_r5_1772 = &temp_r3_1750->unkC0;
            temp_r4_1773 = temp_r3_1750->unkC0;
            if (temp_r4_1773 > 0) {
                if (temp_r4_1773 != 0) {
                    var_r3_1780 = temp_r5_1772 + (((temp_r4_1773 - 1) * 0x58) + 8);
                } else {
                    var_r3_1780 = NULL;
                }
                if (((u8) M2C_FIELD(var_r3_1780, u8 *, 0x50) != 0) && (temp_r3_1788 = M2C_FIELD(var_r3_1780, void **, 0x48), ((temp_r3_1788 == NULL) == 0)) && (var_r0_1791 = M2C_FIELD(temp_r3_1788, u32 *, 8), ((var_r0_1791 == 0U) == 0))) {

                } else {
                    var_r0_1791 = 0U;
                }
                if (var_r0_1791 != 0U) {
                    if (temp_r4_1773 != 0) {
                        var_r3_1805 = temp_r5_1772 + (((temp_r4_1773 - 1) * 0x58) + 8);
                    } else {
                        var_r3_1805 = NULL;
                    }
                    if (((u8) M2C_FIELD(var_r3_1805, u8 *, 0x50) != 0) && (temp_r3_1813 = M2C_FIELD(var_r3_1805, void **, 0x48), ((temp_r3_1813 == NULL) == 0)) && (var_r3_1816 = M2C_FIELD(temp_r3_1813, void ***, 8), ((var_r3_1816 == NULL) == 0))) {

                    } else {
                        var_r3_1816 = NULL;
                    }
                    if (M2C_FIELD(*var_r3_1816, s32 *, 0x14) & 1) {
                        goto block_23;
                    }
                }
            }
        }
    } else {
block_23:
        sp30 = sp10;
        sp38 = (f64) sp18;
        this->unk200->PushOutOfThings((MKVector3) &sp30);
    }
    temp_r5_1840 = this->unk200;
    temp_r4_1843 = this->unkA0;
    temp_f1_1844 = temp_r5_1840->unk240;
    temp_f0_1846 = temp_r5_1840->unk248;
    temp_r30_1847 = this->unk200->Update((MKVector3 *) &sp50, 0.0f) == 7;
    sp20 = temp_f1_1844;
    M2C_FIELD(temp_r4_1843, f64 *, 0) = temp_f1_1844;
    sp28 = temp_f0_1846;
    M2C_FIELD(temp_r4_1843, f64 *, 8) = temp_f0_1846;
    UpdateLTW();
    if (temp_r30_1847 != 0) {
        var_f0_1857 = this->unk208 + gUpdateTimeDelta;
    } else {
        var_f0_1857 = 0.0f;
    }
    this->unk208 = var_f0_1857;
    if (spC != 0) {
        sp8->SetCameraCollisionInfoItems(0U);
    }
}
#endif

void KDCamera::CollisionObjectUpdate() {
    f64 sp10;
    f64 sp8;
    void *temp_r5_1884;

    temp_r5_1884 = this->unk8;
    sp8 = M2C_FIELD(temp_r5_1884, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_1884, f64 *, 0x38);
    CollisionObjectUpdate(*((MKVector3 *) &sp8));
}

#if 0 // DRAFT: illegal implicit conversion from 'double' to
void KDCamera::CollisionUpdate() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    KDCameraHeroData *temp_r6_1925;
    void *temp_r4_1908;
    void *temp_r6_1933;

    if (TestUserStateFlag(2U) != 0) {
        temp_r4_1908 = this->unk8;
        sp28 = M2C_FIELD(temp_r4_1908, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r4_1908, f64 *, 0x38);
        CollisionObjectUpdate();
        SnapToSafetyUpdate(*((MKVector3 *) &sp28));
        CollSlideUpdate(sp28);
    }
    temp_r6_1925 = this->unk50;
    sp8 = temp_r6_1925->unk70;
    sp10 = temp_r6_1925->unk78;
    temp_r6_1933 = this->unk8;
    sp18 = M2C_FIELD(temp_r6_1933, f64 *, 0x30);
    sp20 = M2C_FIELD(temp_r6_1933, f64 *, 0x38);
    UpdateStoredCollisionData(FadeOutPropsUpdate(*((MKVector3 *) &sp18), *((MKVector3 *) &sp8)) == 0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void KDCamera::TestFloor(const MKVector3 &arg0, MKCollisionResult *arg1, float arg2) {
    void *temp_r7_1959;

    temp_r7_1959 = M2C_FIELD(this->unk0, void **, 0xA4);
    TestFloor(arg0, arg1, (MKCollisionMode) M2C_FIELD(temp_r7_1959, s32 *, 8), M2C_FIELD(temp_r7_1959, s32 *, 0x18), arg2);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
void KDCamera::TestFloor(const MKVector3 &arg0, MKCollisionResult *arg1, MKCollisionMode arg2, int arg3, float arg4) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;

    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = -arg4;
    sp30 = (f64) sp20;
    sp28 = (f64) sp18;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = (f32) sp30 + arg0.unk8;
    sp40 = (f64) sp10;
    RayCollide(arg0, *((MKVector3 *) &sp38), arg1, arg2, arg3, 1U);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
s32 KDCamera::SphereCollide(const MKVector3 &arg0, float arg1, MKCollisionResult *arg2, int arg3, MKCollisionMode arg4, int arg5, bool arg6) {
    u8 spC;
    KDCamera *sp8;
    s32 temp_r31_2038;

    sp8 = this;
    spC = arg6;
    if (arg6 != 0) {
        SetCameraCollisionInfoItems(1U);
    }
    temp_r31_2038 = MKCollision_SphereCollide(arg0, arg1, arg2, arg3, arg4, arg5);
    if (spC != 0) {
        sp8->SetCameraCollisionInfoItems(0U);
    }
    return temp_r31_2038;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 KDCamera::SweepSphereCollide(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKCollisionResult *arg3, MKCollisionMode arg4, int arg5, bool arg6) {
    u8 spC;
    KDCamera *sp8;
    u8 temp_r31_2083;

    sp8 = this;
    spC = arg6;
    if (arg6 != 0) {
        SetCameraCollisionInfoItems(1U);
    }
    temp_r31_2083 = MKCollision_SweepSphereCollide(arg0, arg1, arg2, arg3, arg4, arg5);
    if (spC != 0) {
        sp8->SetCameraCollisionInfoItems(0U);
    }
    return temp_r31_2083;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 KDCamera::RayCollide(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionResult *arg2, MKCollisionMode arg3, int arg4, bool arg5) {
    u8 spC;
    KDCamera *sp8;
    u8 temp_r31_2125;

    sp8 = this;
    spC = arg5;
    if (arg5 != 0) {
        SetCameraCollisionInfoItems(1U);
    }
    temp_r31_2125 = MKCollision_RayCollide(arg0, arg1, arg2, arg3, arg4);
    if (spC != 0) {
        sp8->SetCameraCollisionInfoItems(0U);
    }
    return temp_r31_2125;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void KDCamera::CutSceneUpdate() {
    if ((this->unk58->IsMessageStored(0x800) != 0) || (this->unk58->IsMessageStored(0x801) != 0)) {
        if (this->unk58->IsMessageStored(0x800) != 0) {
            M2C_STRUCT_COPY((s32) &arg_spC + 4, M2C_FIELD(checked_cast<KDS_Message_SetCamera *, MKMessage>(this->unk58->GetMessage(0x800)), s32 *, 8) - 4 + 4, 0x40);
        } else {
            M2C_STRUCT_COPY((s32) &arg_spC + 4, checked_cast<KDS_Message_SetCameraSimple *, MKMessage>(this->unk58->GetMessage(0x801)) + 0xC + 4, 0x40);
        }
        SetLTW(*((Matrix *) &arg_sp10));
    }
}
#endif

void KDCamera::CutSceneExit() {
    this->unkA8 = 0.0f;
}

#if 0 // DRAFT: expression syntax error
void KDCamera::ChaseUpdate() {
    f64 sp38;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    KDCameraPoint *temp_r4_2232;
    KDCameraPoint *temp_r4_2239;
    KDCameraPoint *temp_r4_2259;
    f32 temp_f31_2241;
    void *temp_r4_2246;

    sp38.GetUpdatedTarget();
    temp_r4_2232 = this->unkA4;
    M2C_FIELD(temp_r4_2232, f64 *, 0) = sp38;
    M2C_FIELD(temp_r4_2232, f64 *, 8) = sp40;
    UpdateLTW();
    temp_r4_2239 = this->unkA4;
    temp_f31_2241 = this->unk124;
    sp8 = M2C_FIELD(temp_r4_2239, f64 *, 0);
    sp10 = M2C_FIELD(temp_r4_2239, f64 *, 8);
    temp_r4_2246 = this->unk8;
    sp18 = M2C_FIELD(temp_r4_2246, f64 *, 0x30);
    sp20 = M2C_FIELD(temp_r4_2246, f64 *, 0x38);
    GetForceDirectionPtr();
    sp28.GetUpdatedSource(*((MKVector3 *) this), *((MKVector3 *) &sp18), (MKVector3 *) &sp8, temp_f31_2241);
    temp_r4_2259 = this->unkA0;
    M2C_FIELD(temp_r4_2259, f64 *, 0) = sp28;
    M2C_FIELD(temp_r4_2259, f64 *, 8) = sp30;
    UpdateLTW();
    DeltaUpdate();
}
#endif

void KDCamera::ChaseEnter() {
    this->unk13D = 1;
}

u8 KDCamera::ProcessCameraStateRequest(int arg0) {
    this->unk15C->HandleStateMessage(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'KDCameraStateChangeRequest' to
void KDCamera::UpdateCameraStateRequests() {
    KDCameraStateChangeRequest *temp_r5_2344;
    s32 var_ctr_2353;
    s32 var_r30_2331;
    s32 var_r31_2332;
    s32 var_r3_2352;

    var_r30_2331 = 0;
    var_r31_2332 = 0;
loop_2:
    temp_r5_2344 = this->unk160;
    if (var_r30_2331 < (s32) (temp_r5_2344->unk7C + 1)) {
        ProcessCameraStateRequest(*(temp_r5_2344 + var_r31_2332));
        var_r30_2331 += 1;
        var_r31_2332 += 4;
        goto loop_2;
    }
    temp_r5_2344->unk7C = -1;
    var_r3_2352 = 0;
    var_ctr_2353 = 0x1F;
    do {
        *(temp_r5_2344 + var_r3_2352) = -1;
        var_r3_2352 += 4;
        var_ctr_2353 -= 1;
    } while (var_ctr_2353 != 0);
}
#endif

void KDCamera::PreStateEnter() {
    KDCameraStateStack *temp_r3_2373;

    temp_r3_2373 = this->unk15C;
    temp_r3_2373->GetDescriptorAtIndex(temp_r3_2373->unk10);
    this->unk158 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void KDCamera::PostCameraUpdate() {
    s32 spC;
    s32 sp8;
    void *temp_r3_2410;

    CameraEffectsUpdate();
    HeroMoveYawUpdate();
    this->unk58->unk4 = -1;
    this->unk124 = 0.0f;
    this->unk128 = 0.0f;
    this->unk12C = 0.0f;
    this->unk130 = 0.0f;
    this->unk13D = 0;
    temp_r3_2410 = this->unk50->unkA8;
    if (temp_r3_2410 != NULL) {
        spC = 0;
        sp8 = 0x423;
        M2C_FIELD(M2C_FIELD(temp_r3_2410, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

void KDCamera::PreCameraUpdate() {
    this->unk164 = 0;
    UpdateCameraStateRequests();
    if (TestUserStateFlag(8U) != 0) {
        this->unk140->Update(*this->unk50);
    }
}

u8 KDCamera::TestUserStateFlag(unsigned int arg0) {
    KDCameraStateStack *temp_r3_2465;
    KDCameraStateStack *temp_r3_2478;
    u32 temp_r3_2470;

    temp_r3_2465 = this->unk15C;
    temp_r3_2465->GetDescriptorAtIndex(temp_r3_2465->unk10);
    temp_r3_2470 = this->unk158 & arg0;
    if (temp_r3_2470 != (u32) (arg0 & M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC))) {
        return temp_r3_2470 != 0;
    }
    temp_r3_2478 = this->unk15C;
    temp_r3_2478->GetDescriptorAtIndex(temp_r3_2478->unk10);
    return (arg0 & (this->unk158 | M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC))) != 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'EventCamera *' to
void KDCamera::CameraEffectsUpdate() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_2847;
    f32 temp_f1_2528;
    f32 temp_f1_2555;
    f32 temp_f1_2917;
    f32 temp_f2_2527;
    f32 temp_f2_2554;
    f32 temp_f2_2574;
    f32 temp_f2_2594;
    f32 temp_f2_2846;
    f32 temp_f2_2916;
    f32 temp_f3_2530;
    f32 temp_f3_2557;
    f32 temp_f3_2573;
    f32 temp_f3_2593;
    f32 temp_f3_2849;
    f32 temp_f4_2576;
    f32 temp_f4_2595;
    f32 temp_f4_2919;
    f32 var_f0_2544;
    f32 var_f0_2692;
    f32 var_f0_2701;
    f32 var_f0_2710;
    f32 var_f0_2828;
    f32 var_f0_2853;
    f32 var_f1_2996;
    f32 var_f1_3007;
    f32 var_f1_3018;
    f32 var_f29_2733;
    f32 var_f4_2600;
    f32 var_f4_2761;
    f32 var_f5_2924;
    f64 temp_f1_2608;
    f64 temp_f1_2614;
    f64 temp_f1_2618;
    f64 temp_f1_2764;
    f64 temp_f1_2770;
    f64 temp_f1_2774;
    f64 temp_f2_2856;
    f64 temp_f2_2862;
    f64 temp_f2_2866;
    f64 temp_f2_2927;
    f64 temp_f2_2933;
    f64 temp_f2_2937;
    s32 temp_r3_2637;
    s32 temp_r3_2793;
    s32 temp_r3_2885;
    s32 temp_r3_2956;
    s32 var_r0_2647;
    s32 var_r0_2803;
    s32 var_r0_2895;
    s32 var_r0_2966;
    u32 temp_r0_3060;
    u32 temp_r3_2551;
    u8 var_r3_2512;
    void *temp_r3_2736;

    var_r3_2512 = TestUserStateFlag(0x100U);
    if (var_r3_2512 == 0) {
        var_r3_2512 = EventCamera_GetCurrent();
        if (var_r3_2512 == 0) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            this->unk1D0 *= -0.5f;
            temp_f2_2527 = this->unk1C8;
            temp_f1_2528 = this->unk1CC;
            temp_f3_2530 = this->unk1D0;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (((temp_f3_2530 * temp_f3_2530) + ((temp_f2_2527 * temp_f2_2527) + (temp_f1_2528 * temp_f1_2528))) == 0.25f) {
                this->unk1C8 = 0.0f;
                this->unk1CC = 0.0f;
                this->unk1D0 = 0.0f;
                return (u32) var_r3_2512;
            }
            /* Duplicate return node #115. Try simplifying control flow for better match */
            return (u32) var_r3_2512;
        }
    }
    var_f0_2544 = 0.0f;
    this->unk188 = 0.0f;
    this->unk18C = 0.0f;
    this->unk190 = 0.0f;
    if ((u8) this->unk180 == 0) {
        temp_r3_2551 = this->unk17C;
        if (temp_r3_2551 & 1) {
            temp_f2_2554 = this->unk1C8;
            temp_f1_2555 = this->unk1CC;
            temp_f3_2557 = this->unk1D0;
            if (((temp_f3_2557 * temp_f3_2557) + ((temp_f2_2554 * temp_f2_2554) + (temp_f1_2555 * temp_f1_2555))) != 0.0f) {
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f28 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f1, $r31, $r3, 0x0, qr0 */);
                this->unk1D0 *= -0.5f;
                temp_f3_2573 = this->unk1C8;
                temp_f2_2574 = this->unk1CC;
                temp_f4_2576 = this->unk1D0;
                if (((temp_f4_2576 * temp_f4_2576) + ((temp_f3_2573 * temp_f3_2573) + (temp_f2_2574 * temp_f2_2574))) > 0.25f) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f2, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f1, $r31, $r0, 0x0, qr0 */);
                    this->unk190 += this->unk1D0;
                    temp_f3_2593 = this->unk188;
                    temp_f2_2594 = this->unk18C;
                    temp_f4_2595 = this->unk190;
                    var_f4_2600 = (temp_f4_2595 * temp_f4_2595) + ((temp_f3_2593 * temp_f3_2593) + (temp_f2_2594 * temp_f2_2594));
                    if (var_f4_2600 > 62500.0f) {
                        if (var_f4_2600 > 0.000001f) {
                            if (var_f4_2600 > 0.0f) {
                                temp_f1_2608 = __frsqrte(var_f4_2600);
                                temp_f1_2614 = 0.5 * temp_f1_2608 * -(((f64) var_f4_2600 * (temp_f1_2608 * temp_f1_2608)) - 3.0);
                                temp_f1_2618 = 0.5 * temp_f1_2614 * -(((f64) var_f4_2600 * (temp_f1_2614 * temp_f1_2614)) - 3.0);
                                var_f4_2600 = (f32) ((f64) var_f4_2600 * (0.5 * temp_f1_2618 * -(((f64) var_f4_2600 * (temp_f1_2618 * temp_f1_2618)) - 3.0)));
                            } else if (var_f4_2600 < M2C_BITWISE(f32, 0.0)) {
                                var_f4_2600 = __float_nan;
                            } else {
                                sp14 = var_f4_2600;
                                temp_r3_2637 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                                switch (temp_r3_2637) { /* switch 1; irregular */
                                case 0x7F800000:    /* switch 1 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_2647 = 1;
                                    } else {
                                        var_r0_2647 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 1 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_2647 = 5;
                                    } else {
                                        var_r0_2647 = 3;
                                    }
                                    break;
                                default:            /* switch 1 */
                                    var_r0_2647 = 4;
                                    break;
                                }
                                if (var_r0_2647 == 1) {
                                    var_f4_2600 = __float_nan;
                                }
                            }
                            var_f0_2544 = 1.0f / var_f4_2600;
                        }
                        this->unk188 *= var_f0_2544;
                        this->unk18C *= var_f0_2544;
                        this->unk190 *= var_f0_2544;
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
                        this->unk190 *= 250.0f;
                    }
                    if ((u8) this->unk1ED != 0) {
                        var_f0_2692 = this->unk188;
                        if (var_f0_2692 > 0.0f) {

                        } else {
                            var_f0_2692 = 0.0f;
                        }
                        this->unk188 = var_f0_2692;
                        var_f0_2701 = this->unk18C;
                        if (var_f0_2701 > 0.0f) {

                        } else {
                            var_f0_2701 = 0.0f;
                        }
                        this->unk18C = var_f0_2701;
                        var_f0_2710 = this->unk190;
                        if (var_f0_2710 > 0.0f) {

                        } else {
                            var_f0_2710 = 0.0f;
                        }
                        this->unk190 = var_f0_2710;
                    }
                } else {
                    this->unk1C8 = 0.0f;
                    this->unk1CC = 0.0f;
                    this->unk1D0 = 0.0f;
                }
            } else {
                this->unk17C = temp_r3_2551 & 0xFFFFFFFE;
            }
        }
        if (this->unk17C & 4) {
            var_f29_2733 = 1.0f;
            if ((u8) this->unk1EC != 0) {
                temp_r3_2736 = this->unk8;
                sp48 = M2C_FIELD(temp_r3_2736, f64 *, 0x30);
                sp50 = M2C_FIELD(temp_r3_2736, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp58 = sp28;
                sp30 = (f32) sp50 - this->unk1E0;
                sp60 = (f64) sp30;
                var_f4_2761 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C));
                if (var_f4_2761 > 0.0f) {
                    temp_f1_2764 = __frsqrte(var_f4_2761);
                    temp_f1_2770 = 0.5 * temp_f1_2764 * -(((f64) var_f4_2761 * (temp_f1_2764 * temp_f1_2764)) - 3.0);
                    temp_f1_2774 = 0.5 * temp_f1_2770 * -(((f64) var_f4_2761 * (temp_f1_2770 * temp_f1_2770)) - 3.0);
                    var_f4_2761 = (f32) ((f64) var_f4_2761 * (0.5 * temp_f1_2774 * -(((f64) var_f4_2761 * (temp_f1_2774 * temp_f1_2774)) - 3.0)));
                } else if (var_f4_2761 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2761 = __float_nan;
                } else {
                    sp10 = var_f4_2761;
                    temp_r3_2793 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_2793) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_2803 = 1;
                        } else {
                            var_r0_2803 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_2803 = 5;
                        } else {
                            var_r0_2803 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_2803 = 4;
                        break;
                    }
                    if (var_r0_2803 == 1) {
                        var_f4_2761 = __float_nan;
                    }
                }
                var_f0_2828 = 1.0f - (var_f4_2761 / this->unk1E8);
                if (var_f0_2828 > 0.0f) {

                } else {
                    var_f0_2828 = 0.0f;
                }
                var_f29_2733 = var_f0_2828;
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            this->unk1B0 *= -0.975f;
            temp_f2_2846 = this->unk1A8;
            temp_f0_2847 = this->unk1AC;
            temp_f3_2849 = this->unk1B0;
            var_f0_2853 = (temp_f3_2849 * temp_f3_2849) + ((temp_f2_2846 * temp_f2_2846) + (temp_f0_2847 * temp_f0_2847));
            if (var_f0_2853 > 0.0f) {
                temp_f2_2856 = __frsqrte(var_f0_2853);
                temp_f2_2862 = 0.5 * temp_f2_2856 * -(((f64) var_f0_2853 * (temp_f2_2856 * temp_f2_2856)) - 3.0);
                temp_f2_2866 = 0.5 * temp_f2_2862 * -(((f64) var_f0_2853 * (temp_f2_2862 * temp_f2_2862)) - 3.0);
                var_f0_2853 = (f32) ((f64) var_f0_2853 * (0.5 * temp_f2_2866 * -(((f64) var_f0_2853 * (temp_f2_2866 * temp_f2_2866)) - 3.0)));
            } else if (var_f0_2853 < M2C_BITWISE(f32, 0.0)) {
                var_f0_2853 = __float_nan;
            } else {
                spC = var_f0_2853;
                temp_r3_2885 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_2885) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2895 = 1;
                    } else {
                        var_r0_2895 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2895 = 5;
                    } else {
                        var_r0_2895 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_2895 = 4;
                    break;
                }
                if (var_r0_2895 == 1) {
                    var_f0_2853 = __float_nan;
                }
            }
            temp_f2_2916 = this->unk198;
            temp_f1_2917 = this->unk19C;
            temp_f4_2919 = this->unk1A0;
            var_f5_2924 = (temp_f4_2919 * temp_f4_2919) + ((temp_f2_2916 * temp_f2_2916) + (temp_f1_2917 * temp_f1_2917));
            if (var_f5_2924 > 0.0f) {
                temp_f2_2927 = __frsqrte(var_f5_2924);
                temp_f2_2933 = 0.5 * temp_f2_2927 * -(((f64) var_f5_2924 * (temp_f2_2927 * temp_f2_2927)) - 3.0);
                temp_f2_2937 = 0.5 * temp_f2_2933 * -(((f64) var_f5_2924 * (temp_f2_2933 * temp_f2_2933)) - 3.0);
                var_f5_2924 = (f32) ((f64) var_f5_2924 * (0.5 * temp_f2_2937 * -(((f64) var_f5_2924 * (temp_f2_2937 * temp_f2_2937)) - 3.0)));
            } else if (var_f5_2924 < M2C_BITWISE(f32, 0.0)) {
                var_f5_2924 = __float_nan;
            } else {
                sp8 = var_f5_2924;
                temp_r3_2956 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_2956) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2966 = 1;
                    } else {
                        var_r0_2966 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2966 = 5;
                    } else {
                        var_r0_2966 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_2966 = 4;
                    break;
                }
                if (var_r0_2966 == 1) {
                    var_f5_2924 = __float_nan;
                }
            }
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (var_f0_2853 == (var_f29_2733 * (var_f5_2924 / 1.5f))) {
                if ((u8) this->unk1ED != 0) {
                    var_f1_2996 = this->unk1A8;
                    if (var_f1_2996 > 0.0f) {

                    } else {
                        var_f1_2996 = 0.0f;
                    }
                    this->unk188 += var_f1_2996;
                    var_f1_3007 = this->unk1AC;
                    if (var_f1_3007 > 0.0f) {

                    } else {
                        var_f1_3007 = 0.0f;
                    }
                    this->unk18C += var_f1_3007;
                    var_f1_3018 = this->unk1B0;
                    if (var_f1_3018 > 0.0f) {

                    } else {
                        var_f1_3018 = 0.0f;
                    }
                    this->unk190 += var_f1_3018;
                } else {
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r3, 0x0, qr0 */);
                    this->unk190 += this->unk1B0;
                }
            } else {
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                M2C_FIELD(this, f32 *, 0x1A8) = sp18;
                sp20 = this->unk1A0 * var_f29_2733;
                sp38 = sp18;
                sp40 = (f64) sp20;
                M2C_FIELD(this, f32 *, 0x1B0) = (f64) sp20;
            }
        }
        var_r3_2512 = (u8) this->unk17C;
        if (var_r3_2512 & 2) {
            temp_r0_3060 = var_r3_2512 & 0xFFFFFFFD;
            var_r3_2512 = 0x188;
            this->unk17C = temp_r0_3060;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r3, 0x0, qr0 */);
            this->unk190 += this->unk1C0;
            this->unk1B8 = 0.0f;
            this->unk1BC = 0.0f;
            this->unk1C0 = 0.0f;
        }
    }
    return (u32) var_r3_2512;
}
#endif

#if 0 // DRAFT: ')' expected
void KDCamera::CameraEffectsMessage(MKMessage *arg0) {
    s32 temp_r3_3101;
    void *temp_r3_3116;
    void *temp_r3_3131;
    void *temp_r3_3141;
    void *temp_r3_3161;
    void *temp_r3_3177;

    temp_r3_3101 = arg0->unk0;
    switch (temp_r3_3101) {
    case 0x417:
        this->unk17C |= 1;
        temp_r3_3116 = checked_cast<ShakeCameraMessage *, MKMessage>(arg0);
        M2C_FIELD(this, f64 *, 0x1C8) = (f64) M2C_FIELD(temp_r3_3116, f64 *, 8);
        M2C_FIELD(this, f64 *, 0x1D0) = (f64) M2C_FIELD(temp_r3_3116, f64 *, 0x10);
        this->unk1ED = M2C_FIELD(checked_cast<ShakeCameraMessage *, MKMessage>(arg0), u8 *, 0x18);
        return;
    case 0x419:
        this->unk17C |= 4;
        temp_r3_3131 = checked_cast<ShakeCameraOnMessage *, MKMessage>(arg0);
        M2C_FIELD(this, f64 *, 0x198) = (f64) M2C_FIELD(temp_r3_3131, f64 *, 0x18);
        M2C_FIELD(this, f64 *, 0x1A0) = (f64) M2C_FIELD(temp_r3_3131, f64 *, 0x20);
        M2C_FIELD(this, f64 *, 0x1A8) = (f64) M2C_FIELD(this, f64 *, 0x198);
        M2C_FIELD(this, f64 *, 0x1B0) = (f64) M2C_FIELD(this, f64 *, 0x1A0);
        temp_r3_3141 = checked_cast<ShakeCameraOnMessage *, MKMessage>(arg0);
        this->unk1D8 = M2C_FIELD(temp_r3_3141, f64 *, 8);
        M2C_FIELD(this, f64 *, 0x1E0) = (f64) M2C_FIELD(temp_r3_3141, f64 *, 0x10);
        this->unk1E8 = M2C_FIELD(checked_cast<ShakeCameraOnMessage *, MKMessage>(arg0), f32 *, 0x28);
        this->unk1EC = M2C_FIELD(checked_cast<ShakeCameraOnMessage *, MKMessage>(arg0), u8 *, 0x2D);
        this->unk1ED = M2C_FIELD(checked_cast<ShakeCameraOnMessage *, MKMessage>(arg0), u8 *, 0x2C);
        return;
    case 0x41B:
        temp_r3_3161 = checked_cast<ShakeCameraUpdatePosMessage *, MKMessage>(arg0);
        this->unk1D8 = M2C_FIELD(temp_r3_3161, f64 *, 8);
        M2C_FIELD(this, f64 *, 0x1E0) = (f64) M2C_FIELD(temp_r3_3161, f64 *, 0x10);
        return;
    case 0x41A:
        this->unk17C &= 0xFFFFFFFB;
        return;
    case 0x418:
        this->unk17C |= 2;
        temp_r3_3177 = checked_cast<KDDataMessage<MKVector3, 1048> *, MKMessage>(arg0);
        M2C_FIELD(this, f64 *, 0x1B8) = (f64) M2C_FIELD(temp_r3_3177, f64 *, 8);
        M2C_FIELD(this, f64 *, 0x1C0) = (f64) M2C_FIELD(temp_r3_3177, f64 *, 0x10);
        return;
    case 0x41C:
        this->unk180 = 1;
        return;
    case 0x41D:
        this->unk180 = 0;
        /* fallthrough */
    default:
        return;
    }
}
#endif

#if 0 // DRAFT: '(' expected
u8 KDCamera::FadeOutPropsUpdate(const MKVector3 &arg0, const MKVector3 &arg1) {
    M2C_UNK sp6C;
    s32 sp68;
    u8 sp60;
    s32 sp5C;
    void *sp58;
    s32 sp54;
    f32 sp50;
    s32 sp4C;
    s8 sp4B;
    s8 sp4A;
    s16 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r3_3283;
    s32 var_r29_3234;
    u8 var_r30_3224;
    u8 var_r3_3305;
    void *temp_r3_3289;
    void *temp_r4_3287;
    void *var_r0_3317;
    void *var_r3_3336;

    if (TestUserStateFlag(0x40U) == 0) {
        return 0U;
    }
    var_r30_3224 = 1;
    __construct_array(&sp6C, &MKCollisionTempDisableHelper::__defctor, &MKCollisionTempDisableHelper::~MKCollisionTempDisableHelper, 8, 8);
    sp68 = 0;
    var_r29_3234 = 0;
loop_3:
    sp10 = 0.0f;
    sp14 = 0.0f;
    sp18 = 0.0f;
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp28 = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp38 = 0.0f;
    sp3C = 1.0f;
    sp40 = 0.0f;
    sp44 = 0.0f;
    sp48 = 0;
    sp4A = 0;
    sp4B = 0;
    sp4C = 0;
    sp50 = 3.4028235e38f;
    sp54 = 0;
    sp58 = NULL;
    sp5C = -1;
    sp60 = 0;
    if (RayCollide(arg0, arg1, (MKCollisionResult *) &sp10, (MKCollisionMode) 7, 0, 0U) != 0) {
        if (sp58 == NULL) {
            var_r30_3224 = 0;
        } else {
            if ((sp68 < 8) && (sp58 != NULL)) {
                temp_r3_3283 = sp68 * 8;
                sp68 += 1;
                temp_r4_3287 = &sp68 + (temp_r3_3283 + 4);
                M2C_FIELD(temp_r4_3287, void **, 0) = sp58;
                temp_r3_3289 = M2C_FIELD(temp_r4_3287, void **, 0);
                if (temp_r3_3289 != NULL) {
                    M2C_FIELD(temp_r4_3287, u8 *, 4) = (u8) M2C_FIELD(temp_r3_3289, u8 *, 4);
                    M2C_FIELD(M2C_FIELD(temp_r4_3287, void **, 0), u8 *, 4) = 0U;
                }
            }
            if (var_r30_3224 != 0) {
                var_r3_3305 = IgnoreCollision(sp10);
            } else {
                var_r3_3305 = 0;
            }
            var_r30_3224 = var_r3_3305;
            if ((sp60 != 0) && (sp58 != NULL) && (var_r0_3317 = M2C_FIELD(sp58, void **, 8), ((var_r0_3317 == NULL) == 0))) {

            } else {
                var_r0_3317 = NULL;
            }
            if ((var_r0_3317 != NULL) && (sp54 & M2C_FIELD(this->unk0, s32 *, 0x60))) {
                if ((sp60 != 0) && (sp58 != NULL) && (var_r3_3336 = M2C_FIELD(sp58, void **, 8), ((var_r3_3336 == NULL) == 0))) {

                } else {
                    var_r3_3336 = NULL;
                }
                spC = 0;
                sp8 = 0x422;
                M2C_FIELD(M2C_FIELD(var_r3_3336, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            }
            var_r29_3234 += 1;
            if (var_r29_3234 < 8) {
                goto loop_3;
            }
        }
    }
    __destroy_arr(&sp6C, &MKCollisionTempDisableHelper::~MKCollisionTempDisableHelper, 8, 8);
    return var_r30_3224 == 0;
}
#endif

void KDCamera::SnapToSafetySetNextMode() {
    this->unk178 += 1;
    if ((s32) this->unk178 >= 3) {
        this->unk178 = 0;
    }
}

#if 0 // DRAFT: undefined identifier 'sp28'
void KDCamera::SnapToSafetyTryForceSnap(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDCameraDeltaStagesEx *temp_r31_3426;
    f32 temp_f1_3432;
    f32 temp_f31_3427;
    f32 temp_f31_3430;
    f32 temp_f6_3455;

    if (this->unk20C > 1.0f) {
        temp_r31_3426 = this->unk54;
        temp_f31_3427 = M2C_FIELD(temp_r31_3426, f32 *, 0x28);
        temp_f31_3430 = temp_r31_3426->GetZDelta() + temp_f31_3427;
        temp_f1_3432 = temp_r31_3426->GetYDelta();
        sp10 = temp_f31_3430;
        sp8 = 0.0f;
        spC = temp_f1_3432;
        sp60 = (f64) sp10;
        sp58 = (f64) sp8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f5, $f1, $f0 */);
        temp_f6_3455 = arg0.unk8 - arg1.unk8;
        sp48 = sp28;
        sp30 = temp_f6_3455;
        sp50 = (f64) sp30;
        if (((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) - (((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C)))) > 200.0f) {
            sp20 = temp_f6_3455;
            sp38 = sp18;
            sp40 = (f64) sp20;
            SnapToDirectionForce(*((MKVector3 *) &sp38));
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IsUsingIdealStages'
void KDCamera::SnapToSafetyTryIdealPos(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    KDCameraDeltaStagesEx *temp_r31_3512;
    KDCameraDeltaStagesEx *temp_r31_3527;
    f32 temp_f1_3518;
    f32 temp_f1_3533;
    f32 temp_f31_3513;
    f32 temp_f31_3516;
    f32 temp_f31_3528;
    f32 temp_f31_3531;
    void *temp_r6_3645;

    spD8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    spE0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (this->unk54->IsUsingIdealStages() == 0) {
        temp_r31_3512 = this->unk54;
        temp_f31_3513 = M2C_FIELD(temp_r31_3512, f32 *, 0x28);
        temp_f31_3516 = temp_r31_3512->GetZDelta() + temp_f31_3513;
        temp_f1_3518 = temp_r31_3512->GetYDelta();
        sp50 = temp_f31_3516;
        sp48 = 0.0f;
        sp4C = temp_f1_3518;
        spD0 = (f64) sp50;
        spC8 = (f64) sp48;
        temp_r31_3527 = this->unk54;
        temp_f31_3528 = M2C_FIELD(temp_r31_3527, f32 *, 0x28);
        temp_f31_3531 = ((KDCameraDeltaStagesEx *) (temp_r31_3527 + 0x14))->GetZDelta() + temp_f31_3528;
        temp_f1_3533 = ((KDCameraDeltaStagesEx *) (temp_r31_3527 + 0x14))->GetYDelta();
        sp38 = 0.0f;
        sp3C = temp_f1_3533;
        sp40 = temp_f31_3531;
        spB8 = (f64) sp38;
        spC0 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp58 = sp28;
        sp30 = (f32) spC0 - (f32) spD0;
        sp68 = sp28;
        sp60 = (f64) sp30;
        sp70 = (f64) sp30;
        if ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU) == 0) && ((((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + (unkspBC * unkspBC))) > (((f32) spD0 * (f32) spD0) + (((f32) spC8 * (f32) spC8) + (unkspCC * unkspCC))))) {
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp98 = sp18;
            sp20 = arg0.unk8 - arg1.unk8;
            spA0 = (f64) sp20;
            spA8.GetIdealSource(*((MKVector3 *) this), arg1, (MKVector3 *) &sp98);
            spD8 = spA8;
            spE0 = spB0;
        }
    } else {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp78 = sp8;
        sp10 = arg0.unk8 - arg1.unk8;
        sp80 = (f64) sp10;
        sp88.GetIdealSource(*((MKVector3 *) this), arg1, (MKVector3 *) &sp78);
        spD8 = sp88;
        spE0 = sp90;
    }
    if ((((f32) spE0 * (f32) spE0) + (((f32) spD8 * (f32) spD8) + (unkspDC * unkspDC))) != 0.0f) {
        temp_r6_3645 = M2C_FIELD(this->unk0, void **, 0xA4);
        if (IsPointSafeAndViewClearSweep(arg1, *((MKVector3 *) &spD8), M2C_FIELD(temp_r6_3645, f32 *, 0), M2C_FIELD(temp_r6_3645, s32 *, 0x18), NULL) != 0) {
            this->unk54->DisableOverride(0.0f, 0.0f);
            Teleport(*((MKVector3 *) &spD8), 1U);
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void KDCamera::SnapToSafetyTryDesiredPos(const MKVector3 &arg0, const MKVector3 &arg1) {
    void *temp_r6_3709;

    temp_r6_3709 = M2C_FIELD(this->unk0, void **, 0xA4);
    if (IsPointSafeAndViewClearSweep(arg1, arg0, M2C_FIELD(temp_r6_3709, f32 *, 0), M2C_FIELD(temp_r6_3709, s32 *, 0x18), NULL) != 0) {
        Teleport(arg0, 1U);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void KDCamera::SnapToSafetyUpdate(const MKVector3 &arg0) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    KDCameraHeroData *temp_r3_3783;
    f32 temp_f2_3749;
    s32 temp_r0_3788;
    void *temp_r3_3744;

    if ((TestUserStateFlag(0x80U) != 0) && (this->unk20C != 0.0f) && ((temp_r3_3744 = this->unk8, sp38 = M2C_FIELD(temp_r3_3744, f64 *, 0x30), temp_f2_3749 = M2C_FIELD(this->unk0, f32 *, 0x90), sp40 = M2C_FIELD(temp_r3_3744, f64 *, 0x38), M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */), M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */), sp18 = sp8, sp10 = arg0.unk8 - (f32) sp40, sp28 = sp8, sp20 = (f64) sp10, sp30 = (f64) sp10, (((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C))) < (temp_f2_3749 * temp_f2_3749)) == 0)) || (this->unk54->IsUsingIdealDelta() == 0))) {
        this->unk164 |= 2;
        temp_r3_3783 = this->unk50;
        sp48 = temp_r3_3783->unk50;
        sp50 = temp_r3_3783->unk58;
        temp_r0_3788 = this->unk178;
        switch (temp_r0_3788) {                     /* irregular */
        case 0:
            SnapToSafetyTryDesiredPos(arg0, *((MKVector3 *) &sp48));
            break;
        case 1:
            SnapToSafetyTryIdealPos(arg0, *((MKVector3 *) &sp48));
            break;
        case 2:
            SnapToSafetyTryForceSnap(arg0, *((MKVector3 *) &sp48));
            break;
        }
        SnapToSafetySetNextMode();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk16C'
void KDCamera::VisibleTargetDisable() {
    this->unk168 = 0.0f;
    memset(&this->unk16C, 0, 4U);
    this->unk174 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'nanf'
void KDCamera::VisibleTargetUpdate() {
    u8 sp138;
    f32 sp134;
    s32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    s8 sp123;
    s8 sp122;
    s16 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDCameraHeroData *temp_r8_3908;
    f32 temp_f1_4131;
    f32 temp_f6_4095;
    f32 temp_f6_4114;
    s32 temp_r31_3917;
    s32 var_r27_3965;
    u8 temp_r29_4016;
    u8 temp_r3_4058;
    u8 var_r0_4115;
    u8 var_r28_3868;
    void *temp_r11_3914;
    void *temp_r4_3892;
    void *temp_r4_4014;
    void *temp_r5_3970;
    void *temp_r8_3913;

    var_r28_3868 = 0;
    if ((PlayerRotatedCamera() != 0) && (this->unk50->IsMoving() == 0)) {
        var_r28_3868 = 1;
    }
    if ((TestUserStateFlag(0x20U) == 0) || (var_r28_3868 != 0)) {
        this->unk174 = 0;
        return;
    }
    temp_r4_3892 = this->unk8;
    spD8 = M2C_FIELD(temp_r4_3892, f64 *, 0x30);
    spE0 = M2C_FIELD(temp_r4_3892, f64 *, 0x38);
    temp_r8_3908 = this->unk50;
    spC8 = temp_r8_3908->unk50;
    spD0 = temp_r8_3908->unk58;
    temp_r8_3913 = this->unk0;
    temp_r11_3914 = M2C_FIELD(temp_r8_3913, void **, 0xA4);
    temp_r31_3917 = M2C_FIELD(temp_r11_3914, s32 *, 0x18) | M2C_FIELD(temp_r8_3913, s32 *, 0x64);
    spE8 = 0.0f;
    spEC = 0.0f;
    spF0 = 0.0f;
    spF8 = 0.0f;
    spFC = 0.0f;
    sp100 = 0.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    sp110 = 0.0f;
    sp114 = 1.0f;
    sp118 = 0.0f;
    sp11C = 0.0f;
    sp120 = 0;
    sp122 = 0;
    sp123 = 0;
    sp124 = 0.0f;
    sp128 = 3.4028235e38f;
    sp12C = 0.0f;
    sp130 = 0;
    sp134 = nanf;
    sp138 = 0;
    SweepSphereCollide(*((MKVector3 *) &spC8), *((MKVector3 *) &spD8), 25.0f, (MKCollisionResult *) &spE8, (MKCollisionMode) M2C_FIELD(temp_r11_3914, s32 *, 8), temp_r31_3917, 1U);
    if ((sp138 != 0) && (IgnoreCollision(spE8) != 0)) {
        sp138 = 0;
    }
    if (((u8) this->unk174 == 0) && (sp138 == 1)) {
        this->unk174 = 1;
        var_r27_3965 = 1;
loop_12:
        temp_r5_3970 = this->unk8;
        sp68 = M2C_FIELD(temp_r5_3970, f64 *, 0x20);
        sp70 = M2C_FIELD(temp_r5_3970, f64 *, 0x28);
        sp18 = -(f32) sp68;
        sp1C = -unksp6C;
        sp20 = -(f32) sp70;
        sp78 = (f64) sp18;
        sp80 = (f64) sp20;
        KDMath_RotateVectorByYaw(sp88, -0.31415927f * (f32) var_r27_3965);
        sp98.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &spC8), &sp88);
        spB8 = sp98;
        spC0 = spA0;
        temp_r4_4014 = this->unk8;
        temp_r29_4016 = IsPointSafeAndViewClearSweep(*((MKVector3 *) &spC8), *((MKVector3 *) &spB8), 25.0f, temp_r31_3917, NULL);
        sp28 = M2C_FIELD(temp_r4_4014, f64 *, 0x20);
        sp30 = M2C_FIELD(temp_r4_4014, f64 *, 0x28);
        sp8 = -(f32) sp28;
        spC = -unksp2C;
        sp10 = -(f32) sp30;
        sp38 = (f64) sp8;
        sp40 = (f64) sp10;
        KDMath_RotateVectorByYaw(sp48, 0.31415927f * (f32) var_r27_3965);
        sp58.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &spC8), &sp48);
        spA8 = sp58;
        spB0 = sp60;
        temp_r3_4058 = IsPointSafeAndViewClearSweep(*((MKVector3 *) &spC8), *((MKVector3 *) &spA8), 25.0f, temp_r31_3917, NULL);
        if ((temp_r29_4016 == 0) && (temp_r3_4058 == 0)) {
            var_r27_3965 += 1;
            if (var_r27_3965 < 5) {
                goto loop_12;
            }
        }
        if ((temp_r29_4016 == 0) && (temp_r3_4058 == 0)) {
            this->unk174 = 0;
        } else if (temp_r29_4016 != 0) {
            this->unk170 = -1.0f;
        } else if (temp_r3_4058 != 0) {
            this->unk170 = 1.0f;
        }
    }
    if ((u8) this->unk174 != 0) {
        this->unk164 |= 1;
        if (sp138 != 0) {
            temp_f6_4095 = M2C_FIELD(this, f32 *, 0x16C);
            this->unk168 += (gUpdateTimeDelta * ((((0.5f * this->unk170) - this->unk168) * 9.0f) - (2.0f * temp_f6_4095 * 3.0f))) + temp_f6_4095;
        } else {
            temp_f6_4114 = M2C_FIELD(this, f32 *, 0x16C);
            var_r0_4115 = 0;
            this->unk168 += (gUpdateTimeDelta * (((0.0f - this->unk168) * 6.25f) - (2.0f * temp_f6_4114 * 2.5f))) + temp_f6_4114;
            temp_f1_4131 = this->unk168;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f1_4131 == -0.01f) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (temp_f1_4131 == 0.01f) {
                    var_r0_4115 = 1;
                }
            }
            if (var_r0_4115 != 0) {
                VisibleTargetDisable();
            }
        }
        this->unk124 += gUpdateTimeDelta * (this->unk168 * M2C_FIELD(this->unk0, f32 *, 0x88));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
void KDCamera::GetDeltaTargetVelocity() {
    M2C_UNK sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    void *temp_r5_4177;

    temp_r5_4177 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x50);
    sp18 = M2C_FIELD(temp_r5_4177, f64 *, 0xC8);
    sp20 = M2C_FIELD(temp_r5_4177, f64 *, 0xD0);
    sp28 = M2C_FIELD(temp_r5_4177, f64 *, 0x40);
    sp30 = M2C_FIELD(temp_r5_4177, f64 *, 0x48);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = (f32) sp30 - (f32) sp20;
    sp40 = (f64) sp10;
    sp48.GetXZDir();
    KDMath_LocaliseVector(*((MKVector3 *) this), (MKVector3 *) &sp48, *NULL);
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCamera::DeltaUpdate() {
    M2C_UNK sp8;

    sp8.GetDeltaTargetVelocity();
    this->unk54->Update(*((MKVector3 *) &sp8));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void KDCamera::HeroMoveYawUpdate() {
    f64 sp20;
    f64 sp18;
    s32 sp14;
    f32 sp10;
    s32 spC;                                        /* compiler-managed */
    f32 sp8;
    f32 var_f1_4311;
    u8 var_r30_4249;
    u8 var_r3_4257;
    u8 var_r3_4284;
    void *temp_r3_4310;
    void *temp_r4_4256;
    void *temp_r4_4283;

    if ((TestUserStateFlag(1U) != 0) || ((u8) this->unk13C != 0)) {
        var_r30_4249 = this->unk13C;
        if (var_r30_4249 == 0) {
            var_r30_4249 = this->unk13D;
        }
        if (var_r30_4249 == 0) {
            temp_r4_4256 = this->unk120;
            var_r3_4257 = 0;
            if (((u8) M2C_FIELD(temp_r4_4256, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r4_4256, u8 *, 4) != 0)) {
                var_r3_4257 = 1;
            }
            if (var_r3_4257 != 0) {

            } else {
                MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(temp_r4_4256, s32 *, 0), NULL, NULL);
            }
            var_r30_4249 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
            if (var_r30_4249 != 0) {
                temp_r4_4283 = this->unk120;
                var_r3_4284 = 0;
                if (((u8) M2C_FIELD(temp_r4_4283, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r4_4283, u8 *, 4) != 0)) {
                    var_r3_4284 = 1;
                }
                if (var_r3_4284 != 0) {

                } else {
                    MKInput_GetState(0x10, (MKInputDevices) M2C_FIELD(temp_r4_4283, s32 *, 0), NULL, NULL);
                }
                var_r30_4249 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
            }
        }
        temp_r3_4310 = this->unk8;
        var_f1_4311 = 0.0f;
        sp18 = M2C_FIELD(temp_r3_4310, f64 *, 0x20);
        sp20 = M2C_FIELD(temp_r3_4310, f64 *, 0x28);
        if ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C))) != 0.0f) {
            var_f1_4311 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp18)));
        }
        sp8 = M2C_FIELD(&lit_585, f32 *, 0);
        spC = M2C_FIELD(&lit_585, s32 *, 4);
        sp8 = var_f1_4311;
        spC = var_r30_4249;
        sp10 = sp8;
        sp14 = (s32) spC;
        this->unk138->Update(*((KDCameraHeroMoveYaw::UpdateData *) &sp10));
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void KDCamera::GetHeroTargetPos() {
    f64 sp10;
    f64 sp8;
    void *temp_r6_4456;

    temp_r6_4456 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x50);
    sp8 = M2C_FIELD(temp_r6_4456, f64 *, 0x40);
    sp10 = M2C_FIELD(temp_r6_4456, f64 *, 0x48);
    GetHeroTargetPos(*(M2C_ERROR(/* Read from unset register $r4 */)));
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCamera::GetHeroTargetPos(const MKVector3 &arg0) {
    M2C_UNK sp18;
    f32 sp10;

    sp18.GetCurrentTargetOffset();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0) = sp8;
    sp10 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8) + sp20;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: illegal operand
s32 KDCamera::CameraStatesMessage(MKMessage *arg0) {
    KDCameraStateChangeRequest *temp_r5_4530;

    if (this->unk15C->IsStateMessage(arg0) != 0) {
        temp_r5_4530 = this->unk160;
        temp_r5_4530->unk7C += 1;
        *(temp_r5_4530 + (temp_r5_4530->unk7C * 4)) = arg0->unk0;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
u32 KDCamera::PlayerRotatedCamera() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    KDCameraHeroData *temp_r4_4555;

    temp_r4_4555 = this->unk50;
    sp38 = temp_r4_4555->unk40;
    sp40 = temp_r4_4555->unk48;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp18 = sp8;
    sp10 = this->unk150 - (f32) sp40;
    sp28 = sp8;
    sp20 = (f64) sp10;
    sp30 = (f64) sp10;
    return (u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp80'
void KDCamera::UpdateLTW() {
    KDCameraPoint *temp_r3_4602;
    KDCameraPoint *temp_r4_4601;
    KDCameraPoint *temp_r6_4646;
    Matrix *temp_r31_4600;
    f32 temp_f1_4652;
    f64 temp_f2_4608;
    f64 temp_f3_4604;
    f64 temp_f4_4606;
    f64 temp_f5_4603;
    temp_r31_4600 = &this->unk60;
    temp_r4_4601 = this->unkA4;
    temp_r3_4602 = this->unkA0;
    temp_f5_4603 = M2C_FIELD(temp_r4_4601, f64 *, 0);
    temp_f3_4604 = M2C_FIELD(temp_r3_4602, f64 *, 0);
    arg_sp80 = temp_f5_4603;
    temp_f4_4606 = M2C_FIELD(temp_r4_4601, f64 *, 8);
    arg_sp90 = temp_f3_4604;
    temp_f2_4608 = M2C_FIELD(temp_r3_4602, f64 *, 8);
    arg_sp20 = temp_f5_4603;
    arg_sp28 = temp_f4_4606;
    arg_sp88 = temp_f4_4606;
    arg_sp10 = temp_f3_4604;
    arg_sp18 = temp_f2_4608;
    arg_sp98 = temp_f2_4608;
    if ((f32) arg_sp90 == (f32) arg_sp80) {
        arg_sp68 = temp_f4_4606;
        arg_sp78 = temp_f2_4608;
        arg_sp60 = temp_f5_4603;
        arg_sp70 = temp_f3_4604;
        if ((f32) arg_sp78 == (f32) arg_sp68) {
            arg_sp50 = temp_f3_4604;
            arg_sp58 = temp_f2_4608;
            this->unk60.unk30 = (f32) arg_sp50;
            this->unk60.unk34 = arg_sp54;
            this->unk60.unk38 = (f32) arg_sp58;
            this->unk60.unk3C = 1.0f;
            return;
        }
    }
    arg_sp30 = arg_sp20;
    arg_sp38 = arg_sp28;
    temp_r6_4646 = this->unkA0;
    arg_sp40 = M2C_FIELD(temp_r6_4646, f64 *, 0);
    arg_sp48 = M2C_FIELD(temp_r6_4646, f64 *, 8);
    temp_r31_4600->SetLookAt(*((MKVector3 *) &arg_sp40), *((MKVector3 *) &arg_sp30));
    temp_f1_4652 = this->unkA8;
    if (temp_f1_4652 != 0.0f) {
        arg_spA0.SetRotationRoll(temp_f1_4652);
        temp_r31_4600->Multiply3x3((Matrix *) &arg_spA0, temp_r31_4600);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5C'
void KDCamera::SetLTW(const Matrix &arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    KDCameraPoint *temp_r3_4698;
    KDCameraPoint *temp_r3_4711;
    KDCameraPoint *temp_r5_4689;

    M2C_STRUCT_COPY((s32) &this->unk5C + 4, (s32) (&arg0 - 4) + 4, 0x40);
    temp_r5_4689 = this->unkA0;
    M2C_FIELD(temp_r5_4689, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x90);
    M2C_FIELD(temp_r5_4689, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x98);
    sp18.operator*(200.0f);
    temp_r3_4698 = this->unkA0;
    sp28 = M2C_FIELD(temp_r3_4698, f64 *, 0);
    sp30 = M2C_FIELD(temp_r3_4698, f64 *, 8);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_r3_4711 = this->unkA4;
    sp38 = sp8;
    sp10 = (f32) sp30 + sp18.unk8;
    M2C_FIELD(temp_r3_4711, f64 *, 0) = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(temp_r3_4711, f64 *, 8) = (f64) sp10;
}
#endif

f32 KDCamera::GetMoveYaw() {
    return 3.1415927f + M2C_FIELD(this->unk138, f32 *, 4);
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
KDCamera::KDCamera() {
    this->unk4C = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp2C'
void KDCamera::Use() {
    Frustum *temp_r3_4795;
    M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp20 = arg_sp10;
    arg_sp18 = arg_sp68 + this->unk190;
    arg_sp28 = (f64) arg_sp18;
    arg_sp60 = (f32) arg_sp20;
    arg_sp64 = arg_sp24;
    arg_sp68 = (f32) arg_sp28;
    arg_sp6C = 1.0f;
    MKView_SetCameraMatrix(*((Matrix *) &arg_sp30));
    temp_r3_4795 = MKView_GetWorldFrustum();
    this->unkB0 = M2C_FIELD(temp_r3_4795, f64 *, 0);
    this->unkB8 = M2C_FIELD(temp_r3_4795, f64 *, 8);
    this->unkC0 = M2C_FIELD(temp_r3_4795, f64 *, 0x10);
    this->unkC8 = M2C_FIELD(temp_r3_4795, f64 *, 0x18);
    this->unkD0 = M2C_FIELD(temp_r3_4795, f64 *, 0x20);
    this->unkD8 = M2C_FIELD(temp_r3_4795, f64 *, 0x28);
    this->unkE0 = M2C_FIELD(temp_r3_4795, f64 *, 0x30);
    this->unkE8 = M2C_FIELD(temp_r3_4795, f64 *, 0x38);
    this->unkF0 = M2C_FIELD(temp_r3_4795, f64 *, 0x40);
    this->unkF8 = M2C_FIELD(temp_r3_4795, f64 *, 0x48);
    this->unk100 = temp_r3_4795->unk50;
    this->unk108 = M2C_FIELD(temp_r3_4795, f64 *, 0x58);
    this->unk110 = temp_r3_4795->unk60;
    this->unk114 = temp_r3_4795->unk64;
    this->unk118 = M2C_FIELD(temp_r3_4795, f32 *, 0x68);
    this->unk11C = M2C_FIELD(temp_r3_4795, f32 *, 0x6C);
}
#endif

void KDCamera::Message(MKMessage *arg0) {
    if ((u8) this->unk4C != 0) {
        MKProp::Message(arg0);
        CameraStatesMessage(arg0);
        CameraEffectsMessage(arg0);
        MiscMessage(arg0);
    }
}

void KDCamera::DrawText() {

}

void KDCamera::DrawCamera() {

}

#if 0 // DRAFT: undefined identifier 'ClearData'
void KDCamera::ClearData() {
    KDCameraDeltaStagesEx *temp_r5_4908;
    KDCameraHeroMoveYaw *temp_r3_4923;
    KDCameraStateChangeRequest *temp_r5_4916;
    s32 var_ctr_4918;
    s32 var_r4_4907;
    void *temp_r6_4906;

    this->unkA8 = 0.0f;
    this->unk124 = 0.0f;
    this->unk128 = 0.0f;
    this->unk12C = 0.0f;
    this->unk130 = 0.0f;
    this->unk148 = 0.0f;
    this->unk14C = 0.0f;
    this->unk150 = 0.0f;
    this->unk54->ClearData();
    temp_r6_4906 = this->unk0;
    var_r4_4907 = 0;
    temp_r5_4908 = this->unk54;
    M2C_FIELD(temp_r5_4908, f32 *, 0x30) = (f32) M2C_FIELD(temp_r6_4906, f32 *, 0x78);
    M2C_FIELD(temp_r5_4908, f32 *, 0x2C) = (f32) M2C_FIELD(temp_r6_4906, f32 *, 0x74);
    this->unk158 = 0;
    temp_r5_4916 = this->unk160;
    temp_r5_4916->unk7C = -1;
    var_ctr_4918 = 0x1F;
    do {
        *(temp_r5_4916 + var_r4_4907) = -1;
        var_r4_4907 += 4;
        var_ctr_4918 -= 1;
    } while (var_ctr_4918 != 0);
    temp_r3_4923 = this->unk138;
    M2C_FIELD(temp_r3_4923, s32 *, 0) = 0;
    M2C_FIELD(temp_r3_4923, f32 *, 4) = 0.0f;
    this->unk13D = 0;
    this->unk13C = 0;
    this->unk140->ClearData();
    this->unk164 = 0;
    this->unk174 = 0;
    this->unk170 = 1.0f;
    this->unk168 = 0.0f;
    memset(&this->unk16C, 0, 4U);
    this->unk178 = 0;
    this->unk180 = 0;
    this->unk17C = 0;
    this->unk188 = 0.0f;
    this->unk18C = 0.0f;
    this->unk190 = 0.0f;
    this->unk1B8 = 0.0f;
    this->unk1BC = 0.0f;
    this->unk1C0 = 0.0f;
    this->unk1C8 = 0.0f;
    this->unk1CC = 0.0f;
    this->unk1D0 = 0.0f;
    this->unk1A8 = 0.0f;
    this->unk1AC = 0.0f;
    this->unk1B0 = 0.0f;
    this->unk1ED = 0;
    this->unk208 = 0.0f;
    this->unk20C = 0.0f;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCamera::ResetCamera() {
    f64 sp190;
    KDCamera sp170;
    f64 sp168;                                      /* compiler-managed */
    f64 sp160;                                      /* compiler-managed */
    f64 sp158;                                      /* compiler-managed */
    f64 sp150;                                      /* compiler-managed */
    M2C_UNK sp140;
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;                                      /* compiler-managed */
    f64 sp110;
    KDCamera spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    M2C_UNK spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp90;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    s32 spC;
    s32 sp8;
    KDCameraDeltaStagesEx *temp_r5_5068;
    KDCameraHeroData *temp_r8_5170;
    KDCameraPoint *temp_r4_4995;
    KDCameraPoint *temp_r4_5005;
    KDCameraPoint *temp_r4_5042;
    KDCameraPoint *temp_r4_5075;
    KDCameraPoint *temp_r4_5085;
    KDCameraPoint *temp_r4_5122;
    KDCameraPoint *temp_r4_5201;
    KDCameraPoint *temp_r7_5189;
    KDCameraPoint *temp_r8_5029;
    KDCameraPoint *temp_r8_5109;
    KDCameraPoint *temp_r8_5175;
    f32 temp_f28_5158;
    s32 var_r29_5145;
    void *temp_r3_5226;
    void *temp_r6_5053;
    void *temp_r6_5066;
    void *temp_r6_5133;
    void *temp_r6_5236;

    MKProp::Reset();
    ClearData();
    sp190.GetUpdatedTarget();
    temp_r4_4995 = this->unkA4;
    M2C_FIELD(temp_r4_4995, f64 *, 0) = sp190;
    M2C_FIELD(temp_r4_4995, f64 *, 8) = sp198;
    M2C_FIELD(temp_r4_4995, f64 *, 0x10) = sp190;
    M2C_FIELD(temp_r4_4995, f64 *, 0x18) = sp198;
    temp_r4_5005 = this->unkA4;
    sp160 = M2C_FIELD(temp_r4_5005, f64 *, 0);
    sp168 = M2C_FIELD(temp_r4_5005, f64 *, 8);
    sp140.GetDir();
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    sp150 = sp20;
    sp28 = sp148 * -1.0f;
    sp158 = (f64) sp28;
    temp_r8_5029 = this->unkA4;
    sp130 = M2C_FIELD(temp_r8_5029, f64 *, 0);
    sp138 = M2C_FIELD(temp_r8_5029, f64 *, 8);
    sp170.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &sp160), (MKVector3 *) &sp150);
    sp170.unk10.GetUpdatedSource(*((MKVector3 *) this), *((MKVector3 *) &sp170), (MKVector3 *) &sp130, 0.0f);
    temp_r4_5042 = this->unkA0;
    M2C_FIELD(temp_r4_5042, f64 *, 0) = M2C_BITWISE(f64, sp170.unk10);
    M2C_FIELD(temp_r4_5042, f64 *, 8) = M2C_BITWISE(f64, sp170.unk18);
    M2C_FIELD(temp_r4_5042, f64 *, 0x10) = M2C_BITWISE(f64, sp170.unk10);
    M2C_FIELD(temp_r4_5042, f64 *, 0x18) = M2C_BITWISE(f64, sp170.unk18);
    UpdateLTW();
    temp_r6_5053 = this->unk8;
    sp120 = M2C_FIELD(temp_r6_5053, f64 *, 0x30);
    sp128 = M2C_FIELD(temp_r6_5053, f64 *, 0x38);
    if (IsPointSafe(*((MKVector3 *) &sp120), (MKCollisionResult *) &sp170.unk50) == 0) {
        this->unk54->ClearData();
        temp_r6_5066 = this->unk0;
        temp_r5_5068 = this->unk54;
        M2C_FIELD(temp_r5_5068, f32 *, 0x30) = (f32) M2C_FIELD(temp_r6_5066, f32 *, 0x78);
        M2C_FIELD(temp_r5_5068, f32 *, 0x2C) = (f32) M2C_FIELD(temp_r6_5066, f32 *, 0x74);
        sp110.GetUpdatedTarget();
        temp_r4_5075 = this->unkA4;
        M2C_FIELD(temp_r4_5075, f64 *, 0) = sp110;
        M2C_FIELD(temp_r4_5075, f64 *, 8) = sp118;
        M2C_FIELD(temp_r4_5075, f64 *, 0x10) = sp110;
        M2C_FIELD(temp_r4_5075, f64 *, 0x18) = sp118;
        temp_r4_5085 = this->unkA4;
        spE0 = M2C_FIELD(temp_r4_5085, f64 *, 0);
        spE8 = M2C_FIELD(temp_r4_5085, f64 *, 8);
        spC0.GetDir();
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spD0 = sp10;
        sp18 = spC8 * -1.0f;
        spD8 = (f64) sp18;
        temp_r8_5109 = this->unkA4;
        spB0 = M2C_FIELD(temp_r8_5109, f64 *, 0);
        spB8 = M2C_FIELD(temp_r8_5109, f64 *, 8);
        spF0.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &spE0), (MKVector3 *) &spD0);
        spF0.unk10.GetUpdatedSource(*((MKVector3 *) this), *((MKVector3 *) &spF0), (MKVector3 *) &spB0, 0.0f);
        temp_r4_5122 = this->unkA0;
        M2C_FIELD(temp_r4_5122, f64 *, 0) = M2C_BITWISE(f64, spF0.unk10);
        M2C_FIELD(temp_r4_5122, f64 *, 8) = M2C_BITWISE(f64, spF0.unk18);
        M2C_FIELD(temp_r4_5122, f64 *, 0x10) = M2C_BITWISE(f64, spF0.unk10);
        M2C_FIELD(temp_r4_5122, f64 *, 0x18) = M2C_BITWISE(f64, spF0.unk18);
        UpdateLTW();
        temp_r6_5133 = this->unk8;
        spA0 = M2C_FIELD(temp_r6_5133, f64 *, 0x30);
        spA8 = M2C_FIELD(temp_r6_5133, f64 *, 0x38);
        if (IsPointSafe(*((MKVector3 *) &spA0), NULL) == 0) {
            var_r29_5145 = 0;
loop_3:
            temp_f28_5158 = 3.1415927f * (f32) var_r29_5145 * 0.25f;
            sp90.GetDeltaVectorAtPitch(temp_f28_5158);
            spF0.unkC0 = sp90;
            spF0.unkC8 = sp98;
            temp_r8_5170 = this->unk50;
            sp60 = temp_r8_5170->unk30;
            sp68 = temp_r8_5170->unk38;
            temp_r8_5175 = this->unkA4;
            sp70 = M2C_FIELD(temp_r8_5175, f64 *, 0);
            sp78 = M2C_FIELD(temp_r8_5175, f64 *, 8);
            sp80.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &sp70), (MKVector3 *) &sp60);
            spF0.unkB0 = sp80;
            spF0.unkB8 = sp88;
            temp_r7_5189 = this->unkA4;
            sp50 = M2C_FIELD(temp_r7_5189, f64 *, 0);
            sp58 = M2C_FIELD(temp_r7_5189, f64 *, 8);
            if (IsPointSafeAndViewClear(*((MKVector3 *) &sp50), *((MKVector3 *) &spF0.unkB0), NULL) != 0) {
                this->unk54->EnablePitchOverride(temp_f28_5158, 0.0f);
                temp_r4_5201 = this->unkA0;
                M2C_FIELD(temp_r4_5201, f64 *, 0) = spF0.unkB0;
                M2C_FIELD(temp_r4_5201, f64 *, 8) = spF0.unkB8;
                M2C_FIELD(temp_r4_5201, f64 *, 0x10) = spF0.unkB0;
                M2C_FIELD(temp_r4_5201, f64 *, 0x18) = spF0.unkB8;
                UpdateLTW();
            } else {
                var_r29_5145 += 1;
                if (var_r29_5145 < 0x14) {
                    goto loop_3;
                }
            }
        }
    }
    if ((u8) this->unk204 == 0) {
        this->unk204 = 1;
        temp_r3_5226 = this->unk8;
        sp40 = M2C_FIELD(temp_r3_5226, f64 *, 0x30);
        sp48 = M2C_FIELD(temp_r3_5226, f64 *, 0x38);
        this->unk200->Init(M2C_FIELD(this->unk0, KDColObjDescriptor **, 0xA4), *((MKVector3 *) &sp40), NULL, NULL);
    }
    temp_r6_5236 = this->unk8;
    sp30 = M2C_FIELD(temp_r6_5236, f64 *, 0x30);
    sp38 = M2C_FIELD(temp_r6_5236, f64 *, 0x38);
    Teleport(*((MKVector3 *) &sp30), 1U);
    this->unk15C->Reset();
    spC = 0;
    sp8 = 0x401;
    Message(&sp8);
    UpdateCameraStateRequests();
    HeroMoveYawUpdate();
    memset(&this->unkB0, 0, 0x70U);
}
#endif

void KDCamera::Resolve() {
    MKProp::Resolve();
}

void KDCamera::LoadDone() {
    MKProp::LoadDone();
    ClearData();
    this->unk10 |= 0xC;
    KDSound_SetListener((Matrix *) this->unk8);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void KDCamera::Deinit() {
    M2C_UNK *temp_r0_5382;
    M2C_UNK *temp_r0_5401;
    M2C_UNK *var_r31_5378;
    M2C_UNK *var_r3_5379;
    M2C_UNK *var_r4_5377;
    MKHeap *temp_r3_5404;
    u32 temp_r0_5387;

    this->unk4C = 0;
    KDSound_SetListener(NULL);
    safe_delete<KDCameraPoint>(this->unkA0);
    safe_delete<KDCameraPoint>(this->unkA4);
    safe_delete<KDCameraHeroData>(this->unk50);
    safe_delete<KDCameraSimpleDelta>(*((KDCameraSimpleDelta **) &this->unk54));
    safe_delete<KDCameraHeroMoveYaw>(this->unk138);
    safe_delete<KDCameraJumpTargetOffset>(this->unk140);
    this->unk15C->Deinit();
    safe_delete<KDCameraStateStack>(this->unk15C);
    safe_delete<KDCameraStateChangeRequest>(this->unk160);
    this->unk58->Deinit();
    safe_delete<KDMessageStorage>(this->unk58);
    this->unk200->Deinit();
    safe_delete<KDCollisionObject>(this->unk200);
    var_r4_5377 = this->unk210;
    var_r31_5378 = var_r4_5377;
    var_r3_5379 = var_r4_5377;
loop_3:
    temp_r0_5387 = M2C_FIELD(var_r3_5379, u32 *, -4);
    var_r3_5379 -= 4;
    if (temp_r0_5387 != 0U) {
        temp_r0_5382 = *var_r3_5379;
        if (temp_r0_5382 < var_r31_5378) {
            var_r31_5378 = &*temp_r0_5382;
        }
        goto loop_3;
    }
    if (var_r3_5379 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_5401 = *var_r4_5377;
        if (temp_r0_5401 != NULL) {
            if (temp_r0_5401 < var_r31_5378) {
                var_r31_5378 = temp_r0_5401;
            }
            var_r4_5377 += 4;
            goto loop_9;
        }
        temp_r3_5404 = var_r3_5379->Current();
        if (temp_r3_5404 != NULL) {
            ((MKHeap *) (temp_r3_5404->Current()))->Free(var_r31_5378, NULL, 0);
        } else {
            free(var_r31_5378);
        }
    }
    this->unk210 = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void KDCamera::Init() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDCameraDeltaStagesEx *temp_r6_5473;
    KDCameraHeroData *temp_r30_5443;
    KDCameraHeroData *temp_r30_5450;
    KDCameraHeroMoveYaw *temp_r6_5550;
    KDCameraPoint *temp_r6_5507;
    KDCameraStateChangeRequest *temp_r4_5585;
    KDCameraStateStack *var_r0_5565;
    KDCollisionObject *temp_r4_5599;
    M2C_UNK *temp_r3_5635;
    M2C_UNK *temp_r3_5642;
    M2C_UNK *temp_r3_5649;
    M2C_UNK *var_r3_5622;
    M2C_UNK *var_r5_5634;
    MKHeap *temp_r3_5612;
    Matrix *temp_r3_5487;
    s32 temp_r30_5604;
    s32 var_ctr_5587;
    s32 var_ctr_5638;
    s32 var_r5_5584;
    void *temp_r29_5675;
    void *temp_r30_5665;
    void *temp_r3_5603;
    void *temp_r5_5465;
    void *temp_r7_5471;

    this->unk4C = 1;
    MKProp::Init();
    operator new(0xE0U, NULL, 0);
    temp_r30_5443 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r30_5443 != NULL) {
        temp_r30_5443->unk4 = 0;
        ((HeroDataMessage *) (M2C_ERROR(/* Read from unset register $r3 */)))->ClearData();
    }
    this->unk50 = temp_r30_5443;
    temp_r30_5450 = this->unk50;
    temp_r30_5450->ClearData();
    temp_r30_5450->unkC0 = NULL;
    M2C_FIELD(temp_r30_5450, f32 *, 0xC8) = 0.0f;
    M2C_FIELD(temp_r30_5450, f32 *, 0xCC) = 0.0f;
    temp_r30_5450->unkD0 = 0.0f;
    M2C_FIELD(temp_r30_5450, f32 *, 0xD8) = 0.0f;
    operator new(0x58U, NULL, 0);
    this->unk54 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r5_5465 = this->unk0;
    this->unk54->Init(*(M2C_FIELD(temp_r5_5465, KDCameraDeltaStages **, 0xA8)), M2C_FIELD(temp_r5_5465, f32 *, 0x7C), M2C_FIELD(temp_r5_5465, f32 *, 0x80));
    temp_r7_5471 = this->unk0;
    temp_r6_5473 = this->unk54;
    M2C_FIELD(temp_r6_5473, f32 *, 0x30) = (f32) M2C_FIELD(temp_r7_5471, f32 *, 0x78);
    M2C_FIELD(temp_r6_5473, f32 *, 0x2C) = (f32) M2C_FIELD(temp_r7_5471, f32 *, 0x74);
    operator new(0x14U, NULL, 0);
    this->unk58 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk58->Init(*KDCamera::pMessageStorageDescriptors, M2C_FIELD(this->unk0, s32 *, 0x98));
    temp_r3_5487 = &this->unk60;
    this->unk8 = temp_r3_5487;
    temp_r3_5487->SetIdentity();
    operator new(0x20U, NULL, 0);
    sp30 = 0.0f;
    sp28 = 100.0f;
    sp2C = 0.0f;
    this->unkA0 = M2C_ERROR(/* Read from unset register $r3 */);
    sp70 = (f64) sp30;
    sp68 = (f64) sp28;
    this->unkA0->Init(*((MKVector3 *) &sp68));
    temp_r6_5507 = this->unkA0;
    sp58 = M2C_FIELD(temp_r6_5507, f64 *, 0);
    sp60 = M2C_FIELD(temp_r6_5507, f64 *, 8);
    this->unk60.unk30 = (f32) sp58;
    this->unk60.unk34 = unksp5C;
    this->unk60.unk38 = (f32) sp60;
    this->unk60.unk3C = 1.0f;
    operator new(0x20U, NULL, 0);
    this->unkA4 = M2C_ERROR(/* Read from unset register $r3 */);
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp50 = (f64) sp20;
    sp48 = (f64) sp18;
    this->unkA4->Init(*((MKVector3 *) &sp48));
    this->unkA8 = 0.0f;
    UpdateLTW();
    this->unk120 = NULL;
    operator new(8U, NULL, 0);
    this->unk138 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r6_5550 = this->unk138;
    M2C_FIELD(temp_r6_5550, s32 *, 0) = 0;
    M2C_FIELD(temp_r6_5550, f32 *, 4) = 0.0f;
    operator new(0x1CU, NULL, 0);
    this->unk140 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk140->Init(M2C_FIELD(this->unk0, f32 *, 0x84));
    operator new(0x20U, NULL, 0);
    var_r0_5565 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r0_5565 != NULL) {
        var_r0_5565 = ((KDCameraStateStack *) (M2C_ERROR(/* Read from unset register $r3 */)))->KDCameraStateStack();
    }
    this->unk15C = var_r0_5565;
    this->unk15C->Init(this, *KDCamera::pStateDescriptors, M2C_FIELD(this->unk0, s32 *, 0x94));
    operator new(0x80U, NULL, 0);
    this->unk160 = M2C_ERROR(/* Read from unset register $r3 */);
    var_r5_5584 = 0;
    temp_r4_5585 = this->unk160;
    temp_r4_5585->unk7C = -1;
    var_ctr_5587 = 0x1F;
    do {
        *(temp_r4_5585 + var_r5_5584) = -1;
        var_r5_5584 += 4;
        var_ctr_5587 -= 1;
    } while (var_ctr_5587 != 0);
    operator new(0x258U, NULL, 0);
    this->unk200 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r4_5599 = this->unk200;
    temp_r4_5599->unk240 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    temp_r4_5599->unk248 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_r3_5603 = this->unk0;
    temp_r30_5604 = M2C_FIELD(temp_r3_5603, s32 *, 0x6C);
    if (temp_r30_5604 == 0) {
        this->unk210 = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_5612 = temp_r3_5603->Current();
        if (temp_r3_5612 != NULL) {
            var_r3_5622 = ((MKHeap *) (temp_r3_5612->Current()))->Alloc(((temp_r30_5604 + 2) * 4) + (temp_r30_5604 * 8), NULL, 0);
        } else {
            var_r3_5622 = malloc(((temp_r30_5604 + 2) * 4) + (temp_r30_5604 * 8));
        }
        this->unk210 = var_r3_5622;
        var_r5_5634 = this->unk210;
        temp_r3_5635 = var_r5_5634 + (temp_r30_5604 * 8);
        this->unk210 = temp_r3_5635;
        *temp_r3_5635 = NULL;
        var_ctr_5638 = temp_r30_5604;
        if (temp_r30_5604 > 0) {
            do {
                temp_r3_5642 = this->unk210;
                this->unk210 = temp_r3_5642 + 4;
                M2C_FIELD(temp_r3_5642, M2C_UNK **, 4) = var_r5_5634;
                var_r5_5634 += 8;
                var_ctr_5638 -= 1;
            } while (var_ctr_5638 != 0);
        }
        temp_r3_5649 = this->unk210;
        this->unk210 = temp_r3_5649 + 4;
        M2C_FIELD(temp_r3_5649, M2C_UNK **, 4) = NULL;
    }
    this->unk204 = 0;
    this->unk1F0 = 0;
    this->unk1F4 = 1;
    this->unk1F8 = this;
    this->unk1FC = 0;
    this->unk1F4 = 0;
    sp8 = 1.0f;
    temp_r30_5665 = this->unk0;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    temp_r29_5675 = M2C_FIELD(temp_r30_5665, void **, 0xA4);
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **, f64), 0x84)(gMK, (f64) sp8)))->AddSphere((MKVector3 *) &this->unk200->unk240, M2C_FIELD(temp_r29_5675, f32 *, 0), M2C_FIELD(temp_r29_5675, f32 *, 4), *((MKVector4 *) &sp38), (MKCollisionMode) M2C_FIELD(M2C_FIELD(temp_r30_5665, void **, 0xA4), s32 *, 8), (MKCollisionInfo *) &this->unk1F0, 0U);
    memset(&this->unkB0, 0, 0x70U);
}
#endif

void KDCamera::InitModule() {
    *KDCamera::bModuleInitialised = 1;
}

void KDCameraDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 KDCameraDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_5742;

    var_r31_5742 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("collisionRadius", this->unkA4, 0) != 0) || (arg0->LoadInt("maxCameraCollisionInfoItems", &this->unk6C, 0) != 0) || (arg0->LoadFloat("fieldOfView", &this->unk70, 0) != 0) || (arg0->LoadFloat("dragTowardCamera", &this->unk74, 0) != 0) || (arg0->LoadFloat("dragAwayFromCamera", &this->unk78, 0) != 0) || (arg0->LoadFloat("maxHeroJumpHeight", &this->unk84, 0) != 0) || (arg0->LoadFloat("playerRotateDefaultSpeed", &this->unk88, 0) != 0) || (arg0->LoadFloat("visibleTargetIgnoreRatio", &this->unk8C, 0) != 0) || (arg0->LoadFloat("snapToSafetyDistance", &this->unk90, 0) != 0) || (arg0->LoadInt("maxCameraStates", &this->unk94, 0) != 0) || (arg0->LoadInt("maxStateMessagesStored", &this->unk98, 0) != 0) || (KDProp_LoadMaterialID(arg0, "noCollideMaterialID", (s32 *) (this->unkA4 + 0x18)) != 0) || (KDProp_LoadMaterialID(arg0, "fadeMaterialID", &this->unk60) != 0) || (KDProp_LoadMaterialID(arg0, "noVisibleTargetMaterialID", &this->unk64) != 0)) {
        var_r31_5742 = 1;
    }
    return var_r31_5742;
}
#endif

void KDCameraDescriptor::Deinit() {
    operator delete(this->unkA4);
    MKPropDescriptor::Deinit();
}

void KDCameraDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 0;
    this->unk64 = 0;
    this->unk68 = 0;
    this->unk6C = 0x14;
    this->unk70 = 0.87266463f;
    this->unk74 = -70.0f;
    this->unk78 = 100.0f;
    this->unk7C = -1.3744465f;
    this->unk80 = 1.3744465f;
    this->unk84 = 225.0f;
    this->unk88 = 4.0f;
    this->unk8C = 1.0f;
    this->unk90 = 100.0f;
    this->unk94 = 4;
    this->unk98 = 8;
    this->unk9C = 0;
    this->unkA0 = 0;
    this->unkA8 = 0;
    operator new(0x44U, NULL, 0);
    this->unkA4 = M2C_ERROR(/* Read from unset register $r3 */);
    M2C_FIELD(this->unkA4, s8 *, 0x40) = 0;
    M2C_FIELD(this->unkA4, s32 *, 0xC) = 1;
    M2C_FIELD(this->unkA4, s32 *, 0x24) = 0;
    M2C_FIELD(this->unkA4, s32 *, 0x30) = 4;
    M2C_FIELD(this->unkA4, s32 *, 0x3C) = 0;
    M2C_FIELD(this->unkA4, f32 *, 0) = 50.0f;
    M2C_FIELD(this->unkA4, s8 *, 0x14) = 0;
    M2C_FIELD(this->unkA4, s32 *, 8) = 7;
    M2C_FIELD(this->unkA4, f32 *, 0x1C) = 0.8f;
    M2C_FIELD(this->unkA4, f32 *, 0x20) = -1.0f;
    M2C_FIELD(this->unkA4, s32 *, 0x18) = 0;
    M2C_FIELD(this->unkA4, s32 *, 0x10) = 5;
    M2C_FIELD(this->unkA4, f32 *, 4) = 0.0f;
    M2C_FIELD(this->unkA4, f32 *, 0x28) = 0.0f;
    M2C_FIELD(this->unkA4, f32 *, 0x2C) = -1.0f;
    M2C_FIELD(this->unkA4, f32 *, 0x34) = -0.8f;
    M2C_FIELD(this->unkA4, f32 *, 0x38) = -1.0f;
}
