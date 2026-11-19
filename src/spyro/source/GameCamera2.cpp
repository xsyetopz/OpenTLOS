#include "spyro/source/GameCamera2.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/GameCameraMessages.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

MKSceneManager *atoi(s32);                          /* extern */
M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(s32);                               /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern u8 init_762;
extern u8 init_780;
static KDCamera deltaStageInfo;                     /* type too large by 0x290; unable to generate initializer: confusing struct layout */
static f32 GC_MIN_FLOOR_DISTANCE = 130.0f;

void GameCamera2::UpdateCamera() {
    KDCamera::UpdateCamera();
}

#if 0 // DRAFT: undefined identifier 'sp8'
u8 GameCamera2::CanLowerCamera(float *arg0) {
    s8 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    f32 sp98;
    s32 sp94;
    s8 sp93;
    s8 sp92;
    s16 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 var_f31_115;
    void *temp_r4_141;
    void *temp_r8_168;

    var_f31_115 = 0.0f;
    sp20 = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp60 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp84 = 1.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0;
    sp92 = 0;
    sp93 = 0;
    sp94 = 0;
    sp98 = 3.4028235e38f;
    sp9C = 0;
    spA0 = 0;
    spA4 = -1;
    spA8 = 0;
    temp_r4_141 = this->unk8;
    sp18 = 0.0f;
    sp1C = -2000.0f;
    sp48 = M2C_FIELD(temp_r4_141, f64 *, 0x30);
    sp50 = M2C_FIELD(temp_r4_141, f64 *, 0x38);
    sp28 = (f64) sp18;
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = (f32) sp50 + (f32) sp30;
    sp40 = (f64) sp10;
    temp_r8_168 = M2C_FIELD(this->unk0, void **, 0xA4);
    if ((RayCollide(*((MKVector3 *) &sp48), *((MKVector3 *) &sp38), (MKCollisionResult *) &sp58, (MKCollisionMode) M2C_FIELD(temp_r8_168, s32 *, 8), M2C_FIELD(temp_r8_168, s32 *, 0x18), 1U) != 0) && (((sp70 * MKVector3::up.unk8) + ((sp68 * MKVector3::up.unk0) + (sp6C * MKVector3::up.unk4))) > 0.8f)) {
        var_f31_115 = unksp4C - sp5C;
    }
    if (arg0 != NULL) {
        *arg0 = var_f31_115;
    }
    if (var_f31_115 != 0.0f) {
        return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
    }
    return 1U;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
u32 GameCamera2::PlayerRotatedCamera() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    KDCameraHeroData *temp_r4_226;
    f32 temp_f2_228;

    temp_r4_226 = this->unk50;
    temp_f2_228 = checked_cast<GameCamera2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkAC;
    sp38 = M2C_FIELD(temp_r4_226, f64 *, 0x40);
    sp40 = M2C_FIELD(temp_r4_226, f64 *, 0x48);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp18 = sp8;
    sp10 = this->unk278 - (f32) sp40;
    sp28 = sp8;
    sp20 = (f64) sp10;
    sp30 = (f64) sp10;
    return (u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDDataMessage'
void GameCamera2::MiscMessage(MKMessage *arg0) {
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;                                       /* compiler-managed */
    MKVector3 sp68;
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;                                       /* compiler-managed */
    MKVector3 sp48;
    KDCamera sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    KDCameraPoint *temp_r4_370;
    KDCameraPoint *temp_r4_429;
    f32 temp_f31_354;
    f32 temp_f31_412;
    s32 temp_r0_277;
    void *temp_r3_339;
    void *temp_r3_380;
    void *temp_r3_384;

    KDCamera::MiscMessage(arg0);
    temp_r0_277 = arg0->unk0;
    switch (temp_r0_277) {                          /* irregular */
    case 0x44C:
        this->unk240 = 1;
        return;
    case 0x449:
        this->unk2AC |= 2;
        return;
    case 0x44A:
        this->unk2AC |= 4;
        return;
    case 0x44B:
        this->unk2AC |= 0x20;
        return;
    case 0x44D:
        temp_r3_339 = checked_cast<KDDataMessage<MKVector3, 1101> *, MKMessage>(arg0);
        sp78 = M2C_FIELD(temp_r3_339, f64 *, 8);
        sp80 = M2C_FIELD(temp_r3_339, f64 *, 0x10);
        if (TryTeleport(*((MKVector3 *) &sp78), 0U) == 0) {
            temp_f31_354 = *checked_cast<GameCamera2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkA4;
            sp78.CalcPushOutPos(sp68, checked_cast<P21GameCamera2Descriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkA4, NULL, temp_f31_354, M2C_ERROR(/* Read from unset register $r7 */));
            TryTeleport(sp68, 1U);
        }
        sp38.GetUpdatedTarget();
        temp_r4_370 = this->unkA4;
        temp_r4_370->unk0 = M2C_BITWISE(f64, sp38);
        M2C_FIELD(temp_r4_370, f64 *, 8) = M2C_BITWISE(f64, sp38.unk8);
        UpdateLTW();
        return;
    case 0x44E:
        temp_r3_380 = checked_cast<TeleportCameraByOffsetMessage *, MKMessage>(arg0);
        M2C_FIELD(temp_r3_380, s8 *, 0x18) = 1;
        temp_r3_384 = this->unk8;
        sp28 = M2C_FIELD(temp_r3_384, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r3_384, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp58 = sp8;
        sp10 = (f32) sp30 + M2C_FIELD(temp_r3_380, f32 *, 0x10);
        sp60 = (f64) sp10;
        if (TryTeleport(*((MKVector3 *) &sp58), 0U) == 0) {
            temp_f31_412 = *checked_cast<GameCamera2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkA4;
            sp58.CalcPushOutPos(sp48, checked_cast<P21GameCamera2Descriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkA4, NULL, temp_f31_412, M2C_ERROR(/* Read from unset register $r7 */));
            M2C_FIELD(temp_r3_380, s8 *, 0x18) = TryTeleport(sp48, 1U);
        }
        sp18.GetUpdatedTarget();
        temp_r4_429 = this->unkA4;
        temp_r4_429->unk0 = sp18;
        M2C_FIELD(temp_r4_429, f64 *, 8) = sp20;
        UpdateLTW();
        return;
    case 0x44F:
        this->unk2A0 |= 0x40;
        return;
    case 0x450:
        this->unk2A0 &= ~0x40;
        return;
    case 0x451:
        this->unk244 |= 1;
        return;
    case 0x452:
        this->unk244 &= 0xFFFFFFFE;
        return;
    case 0x453:
        this->unk244 |= 2;
        return;
    case 0x454:
        this->unk244 &= 0xFFFFFFFD;
        return;
    case 0x458:
        this->unk2B4 = M2C_FIELD(checked_cast<KDDataMessage<float, 1112> *, MKMessage>(arg0), f32 *, 8);
        return;
    case 0x459:
        this->unk2B4 = 0.0f;
        return;
    case 0x15A:
        M2C_FIELD(this->unk54, f32 *, 0x3C) = 0.0f;
        return;
    case 0x15B:
        M2C_FIELD(this->unk54, f32 *, 0x3C) = (f32) checked_cast<GameCamera2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk7C;
        return;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void GameCamera2::HeroStateHelperMessage(MKMessage *arg0) {
    f32 sp90;
    f64 sp88;
    f64 sp80;
    void *sp7C;
    f32 sp78;
    f64 sp70;
    f64 sp68;
    Targetable *sp60;
    f32 sp5C;
    f32 sp58;
    f64 sp50;
    f64 sp48;
    M2C_UNK sp38;
    f32 sp30;
    TargetContext sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_ret_586;
    f64 temp_f2_555;
    s32 temp_r0_508;
    void *temp_r3_536;

    temp_r0_508 = arg0->unk0;
    switch (temp_r0_508) {                          /* irregular */
    case 0x434:
        sp1C = 0;
        sp18 = 0x431;
        Message(&sp18);
        return;
    case 0x435:
        temp_r3_536 = checked_cast<KDDataMessage<MKVector3, 1077> *, MKMessage>(arg0);
        sp68 = M2C_FIELD(temp_r3_536, f64 *, 8);
        sp70 = M2C_FIELD(temp_r3_536, f64 *, 0x10);
        sp7C = NULL;
        sp38.GetPos();
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        temp_f2_555 = M2C_BITWISE(f64, sp20.unk8);
        sp78 = 1.505e-42f;
        sp30 = (f32) sp70 - sp40;
        sp80 = temp_f2_555;
        sp88 = (f64) sp30;
        sp90 = 3.0f;
        sp48 = temp_f2_555;
        sp50 = (f64) sp30;
        Message(&sp78, (f64) sp30, temp_f2_555);
        return;
    case 0x436:
        sp14 = 0;
        sp10 = 0x433;
        Message(&sp10);
        return;
    case 0x15C:
        temp_ret_586 = atoi(M2C_FIELD(checked_cast<SendArgMessage *, MKMessage>(arg0), s32 *, 0xC));
        sp20.Set(temp_ret_586->PropResolver_Resolve((s32) (u32) (u64) temp_ret_586));
        if (sp20.Get() != NULL) {
            sp5C = 0.0f;
            sp60 = sp20.Get();
            sp58 = 1.525e-42f;
            Message(&sp58);
            return;
        }
        return;
    case 0x15D:
        spC = 0;
        sp8 = 0x442;
        Message(&sp8);
        break;
    }
}
#endif

void GameCamera2::UpdateSnaps() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    KDCameraHeroData *temp_r3_686;
    KDCameraHeroData *temp_r5_645;
    KDCameraHeroData *temp_r5_657;
    KDCameraHeroData *temp_r5_674;
    f64 temp_f0_688;
    f64 temp_f1_687;
    u32 temp_r0_635;
    u8 var_r4_643;

    temp_r0_635 = this->unk2AC;
    if (temp_r0_635 == 0) {
        this->unk2AC = 0;
        return;
    }
    var_r4_643 = 0;
    if (temp_r0_635 & 2) {
        temp_r5_645 = this->unk50;
        sp38 = M2C_FIELD(temp_r5_645, f64 *, 0x30);
        sp40 = M2C_FIELD(temp_r5_645, f64 *, 0x38);
        var_r4_643 = SnapToDirection(*((MKVector3 *) &sp38));
    }
    if (this->unk2AC & 4) {
        temp_r5_657 = this->unk50;
        sp28 = M2C_FIELD(temp_r5_657, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r5_657, f64 *, 0x38);
        var_r4_643 = SnapToDirectionForce(*((MKVector3 *) &sp28));
    }
    if ((this->unk2AC & 0x20) && (this->unk20C != 0.0f)) {
        temp_r5_674 = this->unk50;
        sp18 = M2C_FIELD(temp_r5_674, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r5_674, f64 *, 0x38);
        var_r4_643 = SnapToDirectionForce(*((MKVector3 *) &sp18));
    }
    if (var_r4_643 != 0) {
        temp_r3_686 = this->unk50;
        temp_f1_687 = M2C_FIELD(temp_r3_686, f64 *, 0x40);
        temp_f0_688 = M2C_FIELD(temp_r3_686, f64 *, 0x48);
        sp8 = temp_f1_687;
        this->unk270 = temp_f1_687;
        sp10 = temp_f0_688;
        M2C_FIELD(this, f64 *, 0x278) = temp_f0_688;
    }
    this->unk2AC = 0;
}

#if 0 // DRAFT: expression syntax error
void GameCamera2::TrackedShakePropUpdate() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    M2C_UNK *temp_r31_793;
    M2C_UNK *var_r30_724;
    f32 temp_f0_777;
    f32 temp_f2_785;
    f32 temp_f2_807;
    f32 temp_f3_765;
    f32 var_f0_813;
    f32 var_f1_800;
    f32 var_f1_827;
    f32 var_f30_725;
    f32 var_f31_723;
    void *temp_r3_747;
    void *temp_r4_748;

    if ((u8) this->unk180 != 0) {
        this->unk120->RumbleStop();
        return;
    }
    var_f31_723 = 0.0f;
    var_r30_724 = this->unk2A8;
    var_f30_725 = 0.0f;
loop_9:
    if (var_r30_724 != NULL) {
        temp_r31_793 = *var_r30_724;
        if (temp_r31_793 != NULL) {
            if ((M2C_FIELD(*gMK, u8 (**)(void **, M2C_UNK *, s32), 0x9C)(gMK, M2C_FIELD(temp_r31_793, M2C_UNK **, 0), *MKResource::sWorkingChunkID) != 0) && (((u8) M2C_FIELD(temp_r31_793, u8 *, 0xC) != 0) || ((u8) M2C_FIELD(temp_r31_793, u8 *, 0xD) != 0))) {
                M2C_FIELD(temp_r31_793, u8 *, 0xD) = 0U;
                temp_r3_747 = this->unk8;
                temp_r4_748 = M2C_FIELD(M2C_FIELD(temp_r31_793, M2C_UNK **, 0), void **, 8);
                sp18 = M2C_FIELD(temp_r4_748, f64 *, 0x30);
                sp28 = M2C_FIELD(temp_r3_747, f64 *, 0x30);
                sp20 = M2C_FIELD(temp_r4_748, f64 *, 0x38);
                sp30 = M2C_FIELD(temp_r3_747, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                temp_f3_765 = M2C_FIELD(temp_r31_793, f32 *, 4);
                sp38 = sp8;
                sp10 = (f32) sp30 - (f32) sp20;
                sp40 = (f64) sp10;
                temp_f0_777 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C));
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (temp_f0_777 == temp_f3_765) {
                    temp_f2_785 = 1.0f - (temp_f0_777 / temp_f3_765);
                    var_f31_723 += M2C_FIELD(temp_r31_793, f32 *, 8) * temp_f2_785;
                    var_f30_725 += M2C_FIELD(temp_r31_793, f32 *, 0x10) * temp_f2_785;
                }
            }
            var_r30_724 += 4;
            goto loop_9;
        }
    }
    if (var_f31_723 != 0.0f) {
        var_f1_800 = 100.0f;
        if (var_f1_800 < var_f31_723) {

        } else {
            var_f1_800 = var_f31_723;
        }
        temp_f2_807 = this->unk1CC;
        if (temp_f2_807 != 0.0f) {
            if (temp_f2_807 > 0.0f) {
                var_f0_813 = 1.0f;
            } else {
                var_f0_813 = -1.0f;
            }
            this->unk1CC = var_f1_800 * var_f0_813;
        } else {
            this->unk1CC = var_f1_800;
        }
    }
    if (var_f30_725 != 0.0f) {
        var_f1_827 = 1.0f;
        if (var_f1_827 < var_f30_725) {

        } else {
            var_f1_827 = var_f30_725;
        }
        this->unk120->RumblePlay(var_f1_827, var_f1_827, 0.15f, 0, 4.0f, 0U);
    }
}
#endif

void GameCamera2::CameraEffectsUpdate() {
    TrackedShakePropUpdate();
    KDCamera::CameraEffectsUpdate();
}

#if 0 // DRAFT: undefined identifier 'unk2A8'
void GameCamera2::CameraEffectsMessage(MKMessage *arg0) {
    M2C_UNK *temp_r3_945;
    M2C_UNK *temp_r4_917;
    M2C_UNK *temp_r4_948;
    M2C_UNK *temp_r4_958;
    M2C_UNK *temp_r5_910;
    M2C_UNK *temp_r5_980;
    M2C_UNK *var_r5_938;
    M2C_UNK *var_r6_896;
    M2C_UNK *var_r6_965;
    M2C_UNK *var_r7_895;
    f32 temp_f0_924;
    s32 temp_r0_881;
    void *temp_r3_894;
    void *temp_r3_937;
    void *temp_r3_964;

    KDCamera::CameraEffectsMessage(arg0);
    temp_r0_881 = arg0->unk0;
    switch (temp_r0_881) {                          /* irregular */
    case 0x455:
        temp_r3_894 = checked_cast<AddCameraTrackedShakePropMessage *, MKMessage>(arg0);
        var_r7_895 = this->unk2A8;
        var_r6_896 = NULL;
loop_10:
        if (var_r7_895 != NULL) {
            temp_r5_910 = *var_r7_895;
            if (temp_r5_910 != NULL) {
                if ((M2C_UNK *) *temp_r5_910 == (M2C_UNK *) M2C_FIELD(temp_r3_894, M2C_UNK **, 8)) {
                    var_r6_896 = temp_r5_910;
                } else {
                    var_r7_895 += 4;
                    goto loop_10;
                }
            }
        }
        if (var_r6_896 == NULL) {
            temp_r4_917 = this->unk2A8 - 4;
            this->unk2A8 = temp_r4_917;
            var_r6_896 = *temp_r4_917;
        }
        M2C_FIELD(var_r6_896, M2C_UNK **, 0) = M2C_FIELD(temp_r3_894, M2C_UNK **, 8);
        temp_f0_924 = M2C_FIELD(temp_r3_894, f32 *, 0xC);
        M2C_FIELD(var_r6_896, f32 *, 4) = (f32) (temp_f0_924 * temp_f0_924);
        M2C_FIELD(var_r6_896, f32 *, 8) = (f32) M2C_FIELD(temp_r3_894, f32 *, 0x10);
        M2C_FIELD(var_r6_896, u8 *, 0xC) = (u8) M2C_FIELD(temp_r3_894, u8 *, 0x14);
        M2C_FIELD(var_r6_896, s8 *, 0xD) = 0;
        M2C_FIELD(var_r6_896, f32 *, 0x10) = (f32) M2C_FIELD(temp_r3_894, f32 *, 0x18);
        return;
    case 0x456:
        temp_r3_937 = checked_cast<KDDataMessage<MKProp *, 1110> *, MKMessage>(arg0);
        var_r5_938 = this->unk2A8;
loop_19:
        if (var_r5_938 != NULL) {
            temp_r4_958 = *var_r5_938;
            if (temp_r4_958 == NULL) {
                return;
            }
            if ((M2C_UNK *) *temp_r4_958 == (u32) M2C_FIELD(temp_r3_937, u32 *, 8)) {
                temp_r3_945 = this->unk2A8;
                this->unk2A8 = temp_r3_945 + 4;
                temp_r4_948 = *temp_r3_945;
                *temp_r3_945 = *var_r5_938;
                *var_r5_938 = temp_r4_948;
                return;
            }
            var_r5_938 += 4;
            goto loop_19;
        }
        return;
    case 0x457:
        temp_r3_964 = checked_cast<KDDataMessage<MKProp *, 1111> *, MKMessage>(arg0);
        var_r6_965 = this->unk2A8;
loop_26:
        if ((var_r6_965 == NULL) || (temp_r5_980 = *var_r6_965, ((temp_r5_980 == NULL) != 0))) {

        } else {
            if ((M2C_UNK *) M2C_FIELD(temp_r5_980, M2C_UNK **, 0) == (u32) M2C_FIELD(temp_r3_964, u32 *, 8)) {
                M2C_FIELD(temp_r5_980, s8 *, 0xD) = 1;
                return;
            }
            var_r6_965 += 4;
            goto loop_26;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' != 'int'
void GameCamera2::SnapToSafetySetNextMode() {
    if (IsUnderwater() != 0) {
        this->unk178 = 0;
        return;
    }
    KDCamera::SnapToSafetySetNextMode();
}
#endif

void GameCamera2::AdjustPitchWithFloorUpdateFall() {
    u8 temp_r4_1022;

    temp_r4_1022 = this->unk2A0;
    if ((temp_r4_1022 >> 6U) & 1) {
        if (!((temp_r4_1022 >> 5U) & 1)) {
            this->unk2A0 = temp_r4_1022 | 0x20;
            this->unk158 &= 0xFFFFFFDF;
        }
    } else if (((u32) ((temp_r4_1022 >> 5U) & 1) == 1) && (this->unk20C == 0.0f)) {
        this->unk2A0 = temp_r4_1022 & ~0x20;
        this->unk158 |= 0x20;
    }
}

u8 GameCamera2::AdjustPitchWithFloorForPos(const MKVector3 &arg0) {
    u8 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    f32 sp48;
    s32 sp44;
    s8 sp43;
    s8 sp42;
    s16 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f31_1065;

    if (((u8) this->unk2A0 >> 5U) & 1) {
        var_f31_1065 = 700.0f;
    } else {
        var_f31_1065 = 200.0f;
    }
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp20 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    sp34 = 1.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 0;
    sp42 = 0;
    sp43 = 0;
    sp44 = 0;
    sp48 = 3.4028235e38f;
    sp4C = 0;
    sp50 = 0;
    sp54 = -1;
    sp58 = 0;
    TestFloor(arg0, (MKCollisionResult *) &sp8, var_f31_1065);
    if (sp58 == 0) {
        return 0U;
    }
    if (((MKVector3::up.unk8 * sp20) + ((MKVector3::up.unk0 * sp18) + (MKVector3::up.unk4 * sp1C))) > 0.7f) {
        if (((u8) this->unk2A0 >> 5U) & 1) {
            if (this->unk20C > 0.0f) {
                return 1U;
            }
            goto block_12;
        }
        if ((arg0.unk4 - spC) < 70.0f) {
            TestFloor(arg0, NULL, -var_f31_1065);
            if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                return 1U;
            }
        }
        goto block_12;
    }
block_12:
    return 0U;
}

#if 0 // DRAFT: undefined identifier 'unksp9C'
void GameCamera2::AdjustPitchWithFloorUpdate() {
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spE8;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
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
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    KDCameraDeltaStagesEx *temp_r4_1209;
    KDCameraDeltaStagesEx *temp_r4_1291;
    KDCameraHeroData *temp_r3_1182;
    KDCameraHeroData *temp_r3_1306;
    KDCameraPoint *temp_r3_1238;
    KDCameraPoint *temp_r3_1312;
    f32 temp_f1_1338;
    f32 temp_f31_1265;
    f32 temp_ret_1260;
    f32 var_f1_1267;
    f32 var_f31_1337;
    u8 var_r0_1186;
    u8 var_r3_1210;
    u8 var_r3_1292;
    void *temp_r4_1237;
    void *temp_r4_1311;
    void *temp_r5_1227;
    void *temp_r8_1356;

    if ((TestUserStateFlag(0x200U) == 0) || !(((u8) this->unk2A0 >> 7U) & 1)) {
        this->unk2A0 |= 0x80;
        return;
    }
    temp_r3_1182 = this->unk50;
    if ((u8) temp_r3_1182->unk94 == 0) {
        var_r0_1186 = 0;
    } else {
        spA8 = temp_r3_1182->unkC8;
        sp98 = M2C_FIELD(temp_r3_1182, f64 *, 0x40);
        spB0 = M2C_FIELD(temp_r3_1182, f64 *, 0xD0);
        spA0 = M2C_FIELD(temp_r3_1182, f64 *, 0x48);
        var_r0_1186 = unksp9C > unkspAC;
    }
    if (var_r0_1186 != 0) {
        if (this->unk54->IsUsingIdealPitch() == 0) {
            temp_r4_1209 = this->unk54;
            var_r3_1210 = 0;
            if ((M2C_FIELD(temp_r4_1209, s32 *, 0x54) & 1) && ((u8) M2C_FIELD(temp_r4_1209, u8 *, 0x44) != 0)) {
                var_r3_1210 = 1;
            }
            if (var_r3_1210 == 0) {
                AdjustPitchWithFloorExit();
            }
        }
    } else {
        AdjustPitchWithFloorUpdateFall();
        temp_r5_1227 = this->unk8;
        spF8 = M2C_FIELD(temp_r5_1227, f64 *, 0x30);
        sp100 = M2C_FIELD(temp_r5_1227, f64 *, 0x38);
        if (AdjustPitchWithFloorForPos(*((MKVector3 *) &spF8)) != 0) {
            temp_r4_1237 = this->unk8;
            temp_r3_1238 = this->unkA4;
            sp88 = M2C_FIELD(temp_r4_1237, f64 *, 0x30);
            sp78 = temp_r3_1238->unk0;
            sp90 = M2C_FIELD(temp_r4_1237, f64 *, 0x38);
            sp80 = M2C_FIELD(temp_r3_1238, f64 *, 8);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp68 = sp18;
            sp20 = (f32) sp80 - (f32) sp90;
            sp70 = (f64) sp20;
            temp_ret_1260 = KDMath_GetPitch(*((MKVector3 *) &sp68));
            temp_f31_1265 = ((KDCamera *) (M2C_BITWISE(KDCamera *, temp_ret_1260)))->GetSafePitch(0.09817477f + temp_ret_1260, 0.19634955f);
            var_f1_1267 = this->unk54->GetIdealPitch();
            if (var_f1_1267 > temp_f31_1265) {

            } else {
                var_f1_1267 = temp_f31_1265;
            }
            this->unk54->EnablePitchOverride(var_f1_1267, 5.0f);
            this->unk158 &= 0xFFFFFFDF;
            this->unk164 |= 8;
            this->unk2A4 = 0.0f;
            return;
        }
        if (this->unk54->IsUsingIdealPitch() == 0) {
            temp_r4_1291 = this->unk54;
            var_r3_1292 = 0;
            if ((M2C_FIELD(temp_r4_1291, s32 *, 0x54) & 1) && ((u8) M2C_FIELD(temp_r4_1291, u8 *, 0x44) != 0)) {
                var_r3_1292 = 1;
            }
            if (var_r3_1292 == 0) {
                this->unk164 |= 8;
                temp_r3_1306 = this->unk50;
                sp128 = temp_r3_1306->unk50;
                sp130 = temp_r3_1306->unk58;
                temp_r4_1311 = this->unk8;
                temp_r3_1312 = this->unkA4;
                sp58 = M2C_FIELD(temp_r4_1311, f64 *, 0x30);
                sp48 = temp_r3_1312->unk0;
                sp60 = M2C_FIELD(temp_r4_1311, f64 *, 0x38);
                sp50 = M2C_FIELD(temp_r3_1312, f64 *, 8);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp38 = sp8;
                sp10 = (f32) sp50 - (f32) sp60;
                sp40 = (f64) sp10;
                var_f31_1337 = KDMath_GetPitch(*((MKVector3 *) &sp38)) - 0.2945243f;
                temp_f1_1338 = this->unk54->GetIdealPitch();
                if (temp_f1_1338 > var_f31_1337) {
                    var_f31_1337 = temp_f1_1338;
                }
                spE8.GetDeltaVectorAtPitch(var_f31_1337);
                sp118 = spE8;
                sp120 = spF0;
                temp_r8_1356 = this->unk8;
                spB8 = M2C_FIELD(temp_r8_1356, f64 *, 0x20);
                spC0 = M2C_FIELD(temp_r8_1356, f64 *, 0x28);
                sp28 = -(f32) spB8;
                sp2C = -unkspBC;
                sp30 = -(f32) spC0;
                spC8 = (f64) sp28;
                spD0 = (f64) sp30;
                spD8.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &sp128), (MKVector3 *) &spC8);
                sp108 = spD8;
                sp110 = spE0;
                if ((IsPointSafeAndViewClear(*((MKVector3 *) &sp128), *((MKVector3 *) &sp108), NULL) != 0) && (AdjustPitchWithFloorForPos(*((MKVector3 *) &sp108)) == 0) && (this->unk2A4 += gUpdateTimeDelta, ((this->unk2A4 > 0.15f) != 0))) {
                    this->unk2A0 &= ~0x20;
                    if (var_f31_1337 == this->unk54->GetIdealPitch()) {
                        AdjustPitchWithFloorExit();
                        return;
                    }
                    this->unk54->EnablePitchOverride(var_f31_1337, 5.0f);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void GameCamera2::AdjustPitchWithFloorExit() {
    if (IsUnderwater() == 0) {
        this->unk54->DisablePitchOverride(5.0f);
    }
    this->unk158 |= 0x20;
    this->unk2A0 &= ~0x20;
}
#endif

void GameCamera2::AdjustPitchWithFloorDisable() {
    this->unk2A0 &= ~0x80;
}

#if 0 // DRAFT: undefined identifier 'nanf'
void GameCamera2::CollSlideUpdate(const MKVector3 &arg0) {
    s8 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    s32 sp1AC;
    s8 sp1AB;
    s8 sp1AA;
    s16 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
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
    KDCameraDeltaStagesEx *temp_r28_1955;
    KDCameraHeroData *temp_r3_1606;
    KDCameraPoint *temp_r3_1561;
    KDCollisionObject *temp_r4_1689;
    f32 *var_r0_1709;
    f32 *var_r30_1580;
    f32 temp_f1_1885;
    f32 temp_f1_1964;
    f32 temp_f28_1883;
    f32 temp_f30_1797;
    f32 temp_f30_1959;
    f32 temp_f30_1962;
    f32 temp_f3_1642;
    f32 var_f31_1650;
    f32 var_f31_1805;
    f32 var_f3_1896;
    f64 temp_f1_1808;
    f64 temp_f1_1814;
    f64 temp_f1_1818;
    f64 temp_f3_1579;
    f64 temp_f4_1577;
    s32 temp_r28_1617;
    s32 temp_r3_1691;
    s32 temp_r3_1703;
    s32 temp_r3_1837;
    s32 var_r0_1847;
    u8 temp_r4_1720;
    u8 var_r0_1735;
    u8 var_r0_1921;
    u8 var_r31_1578;
    u8 var_r5_1690;
    void **var_r0_1726;
    void **var_r3_1742;
    void **var_r3_1758;
    void *temp_r3_1723;
    void *temp_r3_1739;
    void *temp_r3_1755;
    void *temp_r3_1920;
    void *temp_r4_1573;
    void *temp_r6_2006;
    void *temp_r8_1978;

    temp_r3_1561 = this->unkA4;
    sp160 = temp_r3_1561->unk0;
    sp168 = M2C_FIELD(temp_r3_1561, f64 *, 8);
    if (((u8) this->unk29C != 0) && ((s32) this->unk200->unkC0 > 0)) {
        temp_r4_1573 = this->unk8;
        temp_f4_1577 = M2C_FIELD(temp_r4_1573, f64 *, 0x30);
        var_r31_1578 = 0;
        temp_f3_1579 = M2C_FIELD(temp_r4_1573, f64 *, 0x38);
        var_r30_1580 = NULL;
        sp150 = temp_f4_1577;
        sp158 = temp_f3_1579;
        sp170 = 0.0f;
        sp174 = 0.0f;
        sp178 = 0.0f;
        sp180 = 0.0f;
        sp184 = 0.0f;
        sp188 = 0.0f;
        sp190 = 0.0f;
        sp194 = 0.0f;
        sp198 = 0.0f;
        sp19C = 1.0f;
        sp1A0 = 0.0f;
        sp1A4 = 0.0f;
        sp1A8 = 0;
        sp1AA = 0;
        sp1AB = 0;
        sp1AC = 0;
        sp1B0 = 3.4028235e38f;
        sp1B4 = 0.0f;
        sp1B8 = 0.0f;
        sp1BC = nanf;
        sp1C0 = 0;
        temp_r3_1606 = this->unk50;
        sp140 = temp_r3_1606->unk50;
        sp148 = temp_r3_1606->unk58;
        sp130 = temp_f4_1577;
        sp138 = temp_f3_1579;
        temp_r28_1617 = M2C_FIELD(checked_cast<GameCamera2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkA4, s32 *, 0x18);
        if (SweepSphereCollide(*((MKVector3 *) &sp140), *((MKVector3 *) &sp130), *checked_cast<P21GameCamera2Descriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkA4, (MKCollisionResult *) &sp170, (MKCollisionMode) 5, temp_r28_1617, 1U) != 0) {
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f5 */);
            temp_f3_1642 = sp1B0 - 0.01f;
            sp78 = (f32) sp138 - (f32) sp148;
            sp120 = sp70;
            sp128 = (f64) sp78;
            if (0.0f > temp_f3_1642) {
                var_f31_1650 = 0.0f;
            } else {
                var_f31_1650 = temp_f3_1642;
            }
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spD0 = sp60;
            sp68 = (f32) sp128 * var_f31_1650;
            spD8 = (f64) sp68;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            sp110 = sp50;
            sp58 = (f32) sp148 + (f32) spD8;
            sp118 = (f64) sp58;
            if (IsPointSafe(*((MKVector3 *) &sp110), NULL) != 0) {
                var_r30_1580 = &sp170;
                var_r31_1578 = 1;
                sp150 = sp110;
                sp158 = sp118;
            }
        } else {
            temp_r4_1689 = this->unk200;
            var_r5_1690 = 0;
            temp_r3_1691 = temp_r4_1689->unk180;
            if ((((u32) (-temp_r3_1691 & ~temp_r3_1691) >> 0x1FU) == 0) && ((s32) M2C_FIELD(temp_r4_1689, s32 *, 0) <= 0)) {
                var_r5_1690 = 1;
            }
            var_r31_1578 = var_r5_1690;
            temp_r3_1703 = temp_r4_1689->unkC0;
            if (temp_r3_1703 != 0) {
                var_r0_1709 = &temp_r4_1689->unkC0 + (((temp_r3_1703 - 1) * 0x58) + 8);
            } else {
                var_r0_1709 = NULL;
            }
            var_r30_1580 = var_r0_1709;
        }
        if ((var_r31_1578 != 0) && (var_r30_1580 != NULL)) {
            temp_r4_1720 = M2C_FIELD(var_r30_1580, u8 *, 0x50);
            if ((temp_r4_1720 != 0) && (temp_r3_1723 = M2C_FIELD(var_r30_1580, void **, 0x48), ((temp_r3_1723 == NULL) == 0)) && (var_r0_1726 = M2C_FIELD(temp_r3_1723, void ***, 8), ((var_r0_1726 == NULL) == 0))) {

            } else {
                var_r0_1726 = NULL;
            }
            var_r0_1735 = var_r0_1726 == NULL;
            if ((u8) (var_r0_1726 == NULL) == 0) {
                if ((temp_r4_1720 != 0) && (temp_r3_1739 = M2C_FIELD(var_r30_1580, void **, 0x48), ((temp_r3_1739 == NULL) == 0)) && (var_r3_1742 = M2C_FIELD(temp_r3_1739, void ***, 8), ((var_r3_1742 == NULL) == 0))) {

                } else {
                    var_r3_1742 = NULL;
                }
                var_r0_1735 = var_r3_1742 != NULL;
                if (var_r0_1735 != 0) {
                    if ((temp_r4_1720 != 0) && (temp_r3_1755 = M2C_FIELD(var_r30_1580, void **, 0x48), ((temp_r3_1755 == NULL) == 0)) && (var_r3_1758 = M2C_FIELD(temp_r3_1755, void ***, 8), ((var_r3_1758 == NULL) == 0))) {

                    } else {
                        var_r3_1758 = NULL;
                    }
                    var_r0_1735 = (M2C_FIELD(*var_r3_1758, s32 *, 0x14) & 1) ^ 1;
                }
            }
            var_r31_1578 = var_r0_1735;
        }
        if ((var_r31_1578 != 0) && (CanLowerCamera(NULL) != 0)) {
            this->unk164 |= 4;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp100 = sp40;
            sp48 = (f32) sp168 - (f32) sp158;
            sp108 = (f64) sp48;
            temp_f30_1797 = KDMath_GetPitch(*((MKVector3 *) &sp100));
            var_f31_1805 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (unksp104 * unksp104));
            if (var_f31_1805 > 0.0f) {
                temp_f1_1808 = __frsqrte(var_f31_1805);
                temp_f1_1814 = 0.5 * temp_f1_1808 * -(((f64) var_f31_1805 * (temp_f1_1808 * temp_f1_1808)) - 3.0);
                temp_f1_1818 = 0.5 * temp_f1_1814 * -(((f64) var_f31_1805 * (temp_f1_1814 * temp_f1_1814)) - 3.0);
                var_f31_1805 = (f32) ((f64) var_f31_1805 * (0.5 * temp_f1_1818 * -(((f64) var_f31_1805 * (temp_f1_1818 * temp_f1_1818)) - 3.0)));
            } else if (var_f31_1805 < M2C_BITWISE(f32, 0.0)) {
                var_f31_1805 = __float_nan;
            } else {
                sp8 = var_f31_1805;
                temp_r3_1837 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1837) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1847 = 1;
                    } else {
                        var_r0_1847 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1847 = 5;
                    } else {
                        var_r0_1847 = 3;
                    }
                    break;
                default:
                    var_r0_1847 = 4;
                    break;
                }
                if (var_r0_1847 == 1) {
                    var_f31_1805 = __float_nan;
                }
            }
            sp28 = 0.0f;
            sp20 = 0.0f;
            sp24 = M2C_FIELD(this->unk54, f32 *, 0x1C);
            spC8 = (f64) sp28;
            spC0 = (f64) sp20;
            temp_f28_1883 = ((GameCamera2Descriptor *) (checked_cast<P21GameCamera2Descriptor))->GetDeltaStages(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0), 0)->unk4;
            temp_f1_1885 = this->unk54->GetIdealDelta();
            if (var_f31_1805 < temp_f1_1885) {

            } else {
                var_f31_1805 = temp_f1_1885;
            }
            var_f3_1896 = (var_f31_1805 - 200.0f) / (temp_f28_1883 - 200.0f);
            if (var_f3_1896 < 1.0f) {

            } else {
                var_f3_1896 = 1.0f;
            }
            if (var_f3_1896 > 0.0f) {

            } else {
                var_f3_1896 = 0.0f;
            }
            if (var_f31_1805 > 200.0f) {
                this->unk54->EnableOverride(temp_f30_1797, var_f31_1805, (var_f3_1896 * (unkspC4 - 140.0f)) + 140.0f);
                temp_r3_1920 = this->unk8;
                var_r0_1921 = 0;
                spB0 = M2C_FIELD(temp_r3_1920, f64 *, 0x30);
                spB8 = M2C_FIELD(temp_r3_1920, f64 *, 0x38);
                if (((f32) sp150 == (f32) spB0) && (unksp154 == unkspB4) && ((f32) sp158 == (f32) spB8)) {
                    var_r0_1921 = 1;
                }
                if (var_r0_1921 == 0) {
                    Teleport(*((MKVector3 *) &sp150), 0U);
                }
            }
        }
    }
    if (((s32) this->unk200->unkC0 <= 0) && (this->unk54->IsUsingIdealDelta() == 0)) {
        temp_r28_1955 = this->unk54;
        if (!(((u32) M2C_FIELD(temp_r28_1955, u32 *, 0x54) >> 1U) & 1)) {
            temp_f30_1959 = M2C_FIELD(temp_r28_1955, f32 *, 0x28);
            temp_f30_1962 = temp_r28_1955->GetZDelta() + temp_f30_1959;
            temp_f1_1964 = temp_r28_1955->GetYDelta();
            sp18 = temp_f30_1962;
            sp10 = 0.0f;
            sp14 = temp_f1_1964;
            spF8 = (f64) sp18;
            spF0 = (f64) sp10;
            temp_r8_1978 = this->unk8;
            sp80 = M2C_FIELD(temp_r8_1978, f64 *, 0x20);
            sp88 = M2C_FIELD(temp_r8_1978, f64 *, 0x28);
            sp30 = -(f32) sp80;
            sp34 = -unksp84;
            sp38 = -(f32) sp88;
            sp90 = (f64) sp30;
            sp98 = (f64) sp38;
            spA0.GetIdealSource(*((MKVector3 *) this), *((MKVector3 *) &sp160), (MKVector3 *) &sp90);
            spE0 = spA0;
            spE8 = spA8;
            temp_r6_2006 = M2C_FIELD(this->unk0, void **, 0xA4);
            if (IsPointSafeAndViewClearSweep(*((MKVector3 *) &sp160), *((MKVector3 *) &spE0), M2C_FIELD(temp_r6_2006, f32 *, 0), M2C_FIELD(temp_r6_2006, s32 *, 0x18), NULL) != 0) {
                this->unk54->DisableDeltaOverride(1.5f);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void GameCamera2::LockOnTargetableUpdate() {
    u8 sp58;
    f64 sp50;
    f64 sp48;
    s32 sp44;
    s32 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    TargetContext sp8;
    KDCameraHeroData *temp_r3_2188;
    f32 temp_f31_2220;
    f32 var_f30_2201;

    sp8.Set(this->unk298);
    if ((sp8.Get() != NULL) && ((sp44 = 0, sp40 = 0x441, sp48 = M2C_FIELD(&MKVector3::zero, f64 *, 0), sp50 = M2C_FIELD(&MKVector3::zero, f64 *, 8), sp58 = 0, M2C_FIELD(M2C_FIELD(M2C_FIELD(sp8.Get()->__vptr, void *(**)(), 8)(), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp40), ((sp58 == 0) == 0)) || (M2C_FIELD(sp8.Get()->__vptr, u8 (**)(MKVector3 *, f64 *), 0x28)(&MKVector3::zero, &sp48) != 0))) {
        temp_r3_2188 = this->unk50;
        sp20 = M2C_FIELD(temp_r3_2188, f64 *, 0x40);
        sp28 = M2C_FIELD(temp_r3_2188, f64 *, 0x48);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        var_f30_2201 = 3.0f;
        sp30 = M2C_BITWISE(f64, sp8.unk8);
        sp18 = (f32) sp50 - (f32) sp28;
        sp38 = (f64) sp18;
        if ((this->unk54->IsUsingIdealDelta() == 0) && !(M2C_FIELD(this->unk54, s32 *, 0x54) & 2)) {
            var_f30_2201 = 10.0f;
        }
        temp_f31_2220 = 3.1415927f + KDMath_GetYaw(*((MKVector3 *) &sp30));
        GetYaw();
        ((KDCamera *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetSmoothToAngleDelta(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), temp_f31_2220, var_f30_2201);
        this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
        this->unk29C = 1;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void GameCamera2::LockOnTargetableEnter() {
    this->unk298 = M2C_FIELD(checked_cast<KDDataMessage<Targetable *, 1088> *, MKMessage>(this->unk58->GetMessage(0x440)), Targetable **, 8);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void GameCamera2::StrafeUpdate() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f31_2357;
    f32 var_f30_2340;
    f64 *var_r3_2320;

    this->unk29C = 1;
    if (this->unk58->IsMessageStored(0x43E) != 0) {
        var_r3_2320 = checked_cast<KDDataMessage<MKVector3, 1086> *, MKMessage>(this->unk58->GetMessage(0x43E)) + 8;
    } else {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        var_r3_2320 = &sp18;
        sp18 = sp8;
        sp10 = this->unk50->unk10.unk28 * -1.0f;
        sp20 = (f64) sp10;
    }
    var_f30_2340 = 3.0f;
    sp28 = M2C_FIELD(var_r3_2320, f64 *, 0);
    sp30 = M2C_FIELD(var_r3_2320, f64 *, 8);
    if ((this->unk54->IsUsingIdealDelta() == 0) && !(M2C_FIELD(this->unk54, s32 *, 0x54) & 2)) {
        var_f30_2340 = 10.0f;
    }
    temp_f31_2357 = 3.1415927f + KDMath_GetYaw(*((MKVector3 *) &sp28));
    GetYaw();
    ((KDCamera *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetSmoothToAngleDelta(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), temp_f31_2357, var_f30_2340);
    this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
}
#endif

void GameCamera2::SmoothBehindHeroUpdate() {
    KDMath_GetYaw(&this->unk50->unk10);
    GetYaw();
    ((KDCamera *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetSmoothedAngleOffset(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), 3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), 3.0f);
    this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
}

#if 0 // DRAFT: undefined identifier 'unksp1C'
void GameCamera2::SlowMoAirCombatUpdate() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 var_f2_2436;
    f32 var_f2_2489;
    void *temp_r3_2434;
    void *temp_r3_2487;

    if (this->unk294 != 0.0f) {
        if (PlayerRotatedCamera() != 0) {
            KDMath_GetYaw(&this->unk50->unk10);
            temp_r3_2434 = this->unk8;
            var_f2_2436 = 0.0f;
            sp18 = M2C_FIELD(temp_r3_2434, f64 *, 0x20);
            sp20 = M2C_FIELD(temp_r3_2434, f64 *, 0x28);
            if ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C))) != 0.0f) {
                var_f2_2436 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp18)));
            }
            this->unk294 = KDMath_GetSmallestAngle(M2C_ERROR(/* Read from unset register $f1 */), var_f2_2436);
        }
        KDMath_GetYaw(&this->unk50->unk10);
        GetYaw();
        ((KDCamera *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetSmoothedAngleOffset(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), this->unk294 + (3.1415927f + M2C_ERROR(/* Read from unset register $f1 */)), 7.0f);
        this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
        return;
    }
    if (PlayerRotatedCamera() != 0) {
        KDMath_GetYaw(&this->unk50->unk10);
        temp_r3_2487 = this->unk8;
        var_f2_2489 = 0.0f;
        sp8 = M2C_FIELD(temp_r3_2487, f64 *, 0x20);
        sp10 = M2C_FIELD(temp_r3_2487, f64 *, 0x28);
        if ((((f32) sp10 * (f32) sp10) + (((f32) sp8 * (f32) sp8) + (unkspC * unkspC))) != 0.0f) {
            var_f2_2489 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp8)));
        }
        this->unk294 = KDMath_GetSmallestAngle(M2C_ERROR(/* Read from unset register $f1 */), var_f2_2489);
        return;
    }
    KDMath_GetYaw(&this->unk50->unk10);
    GetYaw();
    ((KDCamera *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetSmoothedAngleOffset(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), 3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), 7.0f);
    this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void GameCamera2::SlowMoAirCombatExit() {
    s32 spC;
    s32 sp8;

    spC = 0;
    sp8 = 0x446;
    Message(&sp8);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void GameCamera2::SlowMoAirCombatEnter() {
    s32 spC;
    s32 sp8;

    this->unk294 = 0.0f;
    spC = 0;
    sp8 = 0x445;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
void GameCamera2::GlideSetYawOffset() {
    f32 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;

    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp18 = sp8;
    sp10 = this->unk50->unk10.unk28 * -1.0f;
    sp20 = (f64) sp10;
    sp28.GetXZDir();
    if (((sp30 * (f32) sp20) + ((sp28 * (f32) sp18) + (sp2C * unksp1C))) > 0.7f) {
        KDMath_GetYaw(&this->unk50->unk10);
        GetYaw();
        ((KDCamera *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetSmoothedAngleOffset(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), 3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), 2.5f);
        this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
    }
}
#endif

void GameCamera2::GlideUpdate() {
    f32 temp_f1_2762;

    AdjustPitchWithFloorDisable();
    temp_f1_2762 = this->unk290;
    if (temp_f1_2762 > 0.0f) {
        this->unk290 = temp_f1_2762 - gUpdateTimeDelta;
        return;
    }
    GlideSetYawOffset();
}

void GameCamera2::GlideEnter() {
    this->unk290 = 0.2f;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void GameCamera2::SmoothToDirectionUpdate() {
    f32 temp_f31_2813;
    void *temp_r3_2807;

    if (this->unk58->IsMessageStored(0x432) != 0) {
        temp_r3_2807 = checked_cast<SmoothCameraToDirectionUpdateMessage *, MKMessage>(this->unk58->GetMessage(0x432));
        temp_f31_2813 = 3.1415927f + KDMath_GetYaw(*(temp_r3_2807 + 8));
        GetYaw();
        ((KDCamera *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetSmoothToAngleDelta(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), temp_f31_2813, M2C_FIELD(temp_r3_2807, f32 *, 0x18));
        this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void GameCamera2::HoldGivenDirectionUpdate() {
    KDCamera sp28;
    M2C_UNK sp18;
    f32 sp10;
    void *temp_r3_2849;
    void *temp_r3_2864;

    if (this->unk58->IsMessageStored(0x42F) != 0) {
        temp_r3_2849 = checked_cast<HoldGivenDirectionMessage *, MKMessage>(this->unk58->GetMessage(0x42F));
        M2C_FIELD(this, f64 *, 0x128) = (f64) M2C_FIELD(temp_r3_2849, f64 *, 8);
        M2C_FIELD(this, f64 *, 0x130) = (f64) M2C_FIELD(temp_r3_2849, f64 *, 0x10);
        return;
    }
    if (this->unk58->IsMessageStored(0x42E) != 0) {
        temp_r3_2864 = checked_cast<HoldGivenDirectionMessage *, MKMessage>(this->unk58->GetMessage(0x42E));
        M2C_FIELD(this, f64 *, 0x128) = (f64) M2C_FIELD(temp_r3_2864, f64 *, 8);
        M2C_FIELD(this, f64 *, 0x130) = (f64) M2C_FIELD(temp_r3_2864, f64 *, 0x10);
        return;
    }
    sp18.GetPos();
    sp28.GetTarget();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x128) = sp8;
    sp10 = M2C_BITWISE(f32, sp28.unk8) - sp20;
    sp28.unk10 = sp8;
    sp28.unk18 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x130) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'HoldGivenDirectionMessage'
void GameCamera2::HoldGivenDirectionEnter() {
    void *temp_r3_2922;

    temp_r3_2922 = checked_cast<HoldGivenDirectionMessage *, MKMessage>(this->unk58->GetMessage(0x42E));
    M2C_FIELD(this, f64 *, 0x128) = (f64) M2C_FIELD(temp_r3_2922, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x130) = (f64) M2C_FIELD(temp_r3_2922, f64 *, 0x10);
}
#endif

#if 0 // DRAFT: expression syntax error
void GameCamera2::HoldCurrentDirectionUpdate() {
    KDCamera sp28;
    M2C_UNK sp18;
    f32 sp10;

    sp18.GetPos();
    sp28.GetTarget();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x128) = sp8;
    sp10 = M2C_BITWISE(f32, sp28.unk8) - sp20;
    sp28.unk10 = sp8;
    sp28.unk18 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x130) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp24'
f32 GameCamera2::PlayerAdjustGetRotateSpeed() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    KDCameraDeltaStagesEx *temp_r3_2980;
    f32 temp_f1_2987;
    f32 temp_f31_2981;
    f32 temp_f31_2985;
    f32 var_f31_3002;
    f64 temp_f1_3005;
    f64 temp_f1_3011;
    f64 temp_f1_3015;
    s32 temp_r3_3034;
    s32 var_r0_3044;

    temp_r3_2980 = this->unk54;
    temp_f31_2981 = M2C_FIELD(temp_r3_2980, f32 *, 0x28);
    temp_f31_2985 = ((KDCameraDeltaStagesEx *) (temp_r3_2980 + 0x14))->GetZDelta() + temp_f31_2981;
    temp_f1_2987 = ((KDCameraDeltaStagesEx *) (this->unk54 + 0x14))->GetYDelta();
    sp18 = temp_f31_2985;
    sp10 = 0.0f;
    sp14 = temp_f1_2987;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    var_f31_3002 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    if (var_f31_3002 > 0.0f) {
        temp_f1_3005 = __frsqrte(var_f31_3002);
        temp_f1_3011 = 0.5 * temp_f1_3005 * -(((f64) var_f31_3002 * (temp_f1_3005 * temp_f1_3005)) - 3.0);
        temp_f1_3015 = 0.5 * temp_f1_3011 * -(((f64) var_f31_3002 * (temp_f1_3011 * temp_f1_3011)) - 3.0);
        var_f31_3002 = (f32) ((f64) var_f31_3002 * (0.5 * temp_f1_3015 * -(((f64) var_f31_3002 * (temp_f1_3015 * temp_f1_3015)) - 3.0)));
    } else if (var_f31_3002 < M2C_BITWISE(f32, 0.0)) {
        var_f31_3002 = __float_nan;
    } else {
        sp8 = var_f31_3002;
        temp_r3_3034 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_3034) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3044 = 1;
            } else {
                var_r0_3044 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3044 = 5;
            } else {
                var_r0_3044 = 3;
            }
            break;
        default:
            var_r0_3044 = 4;
            break;
        }
        if (var_r0_3044 == 1) {
            var_f31_3002 = __float_nan;
        }
    }
    return 6.2831855f * (checked_cast<GameCamera2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkB0 / (2.0f * (3.1415927f * var_f31_3002))) * gUpdateTimeDelta;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp30'
void GameCamera2::PlayerAdjustUpdate() {
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
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
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    CameraData *temp_r29_3341;
    KDCameraHeroData *temp_r3_3175;
    KDCameraHeroData *temp_r3_3181;
    KDCameraPoint *temp_r3_3371;
    KDCameraPoint *temp_r3_3406;
    KDCameraPoint *temp_r4_3342;
    f32 temp_f1_3208;
    f32 temp_f1_3211;
    f32 temp_f1_3214;
    f32 temp_f1_3368;
    f32 temp_f28_3348;
    f32 temp_f29_3235;
    f32 temp_f29_3366;
    f32 temp_f2_3239;
    f32 temp_f30_3104;
    f32 temp_f30_3378;
    f32 temp_f5_3321;
    f32 temp_f6_3302;
    f32 var_f0_3140;
    f32 var_f1_3120;
    f32 var_f1_3240;
    f32 var_f28_3146;
    f32 var_f29_3129;
    f32 var_f2_3201;
    f32 var_f31_3159;
    f32 var_f4_3288;
    f64 temp_f0_3177;
    f64 temp_f0_3184;
    f64 temp_f1_3176;
    f64 temp_f1_3183;
    u8 temp_r30_3277;
    u8 var_r0_3209;
    u8 var_r3_3108;
    u8 var_r3_3147;
    void *temp_r4_3107;
    void *temp_r4_3145;
    void *temp_r4_3369;
    void *temp_r4_3405;
    void *temp_r5_3340;

    temp_f30_3104 = PlayerAdjustGetRotateSpeed();
    if (this->unk244 & 1) {
        temp_r4_3107 = this->unk120;
        var_r3_3108 = 0;
        if (((u8) M2C_FIELD(temp_r4_3107, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r4_3107, u8 *, 4) != 0)) {
            var_r3_3108 = 1;
        }
        if (var_r3_3108 != 0) {
            var_f1_3120 = 0.0f;
        } else {
            var_f1_3120 = MKInput_GetState(0x13, (MKInputDevices) M2C_FIELD(temp_r4_3107, s32 *, 0), NULL, NULL);
        }
        var_f29_3129 = var_f1_3120;
    } else {
        var_f29_3129 = 0.0f;
    }
    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x14) != 0) {
        var_f0_3140 = -1.0f;
    } else {
        var_f0_3140 = 1.0f;
    }
    temp_r4_3145 = this->unk120;
    var_f28_3146 = var_f0_3140 * var_f29_3129;
    var_r3_3147 = 0;
    if (((u8) M2C_FIELD(temp_r4_3145, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r4_3145, u8 *, 4) != 0)) {
        var_r3_3147 = 1;
    }
    if (var_r3_3147 != 0) {
        var_f31_3159 = 0.0f;
    } else {
        var_f31_3159 = MKInput_GetState(0x12, (MKInputDevices) M2C_FIELD(temp_r4_3145, s32 *, 0), NULL, NULL);
    }
    if ((var_f28_3146 != 0.0f) || (var_f31_3159 != 0.0f)) {
        temp_r3_3175 = this->unk50;
        temp_f1_3176 = M2C_FIELD(temp_r3_3175, f64 *, 0x40);
        temp_f0_3177 = M2C_FIELD(temp_r3_3175, f64 *, 0x48);
        spE0 = temp_f1_3176;
        M2C_FIELD(this, f64 *, 0x148) = temp_f1_3176;
        M2C_FIELD(this, f64 *, 0x150) = temp_f0_3177;
        temp_r3_3181 = this->unk50;
        spE8 = temp_f0_3177;
        temp_f1_3183 = M2C_FIELD(temp_r3_3181, f64 *, 0x40);
        temp_f0_3184 = M2C_FIELD(temp_r3_3181, f64 *, 0x48);
        spD0 = temp_f1_3183;
        this->unk270 = temp_f1_3183;
        spD8 = temp_f0_3184;
        M2C_FIELD(this, f64 *, 0x278) = temp_f0_3184;
    }
    if (var_f28_3146 != 0.0f) {
        this->unk280 = var_f28_3146;
    } else {
        var_f2_3201 = 0.5f * (9.1f * gUpdateTimeDelta);
        if (var_f2_3201 < 1.0f) {

        } else {
            var_f2_3201 = 1.0f;
        }
        temp_f1_3208 = this->unk280;
        var_r0_3209 = 0;
        temp_f1_3211 = -((temp_f1_3208 * var_f2_3201) - temp_f1_3208);
        this->unk280 = -((temp_f1_3211 * var_f2_3201) - temp_f1_3211);
        temp_f1_3214 = this->unk280;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_3214 == -0.05f) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f1_3214 == 0.05f) {
                var_r0_3209 = 1;
            }
        }
        if (var_r0_3209 != 0) {
            this->unk280 = 0.0f;
        }
        var_f28_3146 = this->unk280;
    }
    temp_f29_3235 = 3.1415927f * gUpdateTimeDelta;
    temp_f2_3239 = -temp_f29_3235;
    var_f1_3240 = var_f28_3146 * temp_f30_3104 * ((CameraData *) (((GameData *) ((GameData *) GameData::gameData))->GetCameraData()))->GetPlayerRotateYawMultiplier();
    if (var_f1_3240 < temp_f29_3235) {

    } else {
        var_f1_3240 = temp_f29_3235;
    }
    if (var_f1_3240 > temp_f2_3239) {

    } else {
        var_f1_3240 = temp_f2_3239;
    }
    if (var_f1_3240 != 0.0f) {
        if (this->unk244 & 2) {
            this->unk29C = 1;
        }
        this->unk124 += var_f1_3240;
    }
    if ((this->unk244 & 2) && (var_f31_3159 != 0.0f)) {
        sp8 = 0.0f;
        temp_r30_3277 = CanLowerCamera(&sp8);
        if ((sp8 != 0.0f) && (sp8 < 500.0f)) {
            var_f4_3288 = (sp8 - GC_MIN_FLOOR_DISTANCE) / (500.0f - GC_MIN_FLOOR_DISTANCE);
            if (var_f4_3288 < 1.0f) {

            } else {
                var_f4_3288 = 1.0f;
            }
            if (var_f4_3288 > 0.0f) {

            } else {
                var_f4_3288 = 0.0f;
            }
            temp_f6_3302 = this->unk288;
            this->unk284 += (gUpdateTimeDelta * (((((0.8f * var_f4_3288) + 0.2f) - this->unk284) * 25.0f) - (2.0f * temp_f6_3302 * 5.0f))) + temp_f6_3302;
        } else {
            temp_f5_3321 = this->unk288;
            this->unk284 += (gUpdateTimeDelta * (((1.0f - this->unk284) * 25.0f) - (2.0f * temp_f5_3321 * 5.0f))) + temp_f5_3321;
        }
        temp_r5_3340 = this->unk8;
        temp_r29_3341 = ((GameData *) ((GameData *) GameData::gameData))->GetCameraData();
        temp_r4_3342 = this->unkA4;
        spC0 = M2C_FIELD(temp_r5_3340, f64 *, 0x30);
        temp_f28_3348 = this->unk284;
        spB0 = temp_r4_3342->unk0;
        spC8 = M2C_FIELD(temp_r5_3340, f64 *, 0x38);
        spB8 = M2C_FIELD(temp_r4_3342, f64 *, 8);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spA0 = sp30;
        sp38 = (f32) spB8 - (f32) spC8;
        spA8 = (f64) sp38;
        temp_f29_3366 = KDMath_GetPitch(*((MKVector3 *) &spA0));
        temp_f1_3368 = temp_r29_3341->GetPlayerRotatePitchMultiplier();
        temp_r4_3369 = this->unk8;
        temp_r3_3371 = this->unkA4;
        sp90 = M2C_FIELD(temp_r4_3369, f64 *, 0x30);
        temp_f30_3378 = (temp_f30_3104 * (var_f31_3159 * temp_f28_3348) * temp_f1_3368) + temp_f29_3366;
        sp80 = temp_r3_3371->unk0;
        sp98 = M2C_FIELD(temp_r4_3369, f64 *, 0x38);
        sp88 = M2C_FIELD(temp_r3_3371, f64 *, 8);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp70 = sp20;
        sp28 = (f32) sp88 - (f32) sp98;
        sp78 = (f64) sp28;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (((temp_f30_3378 == KDMath_GetPitch(*((MKVector3 *) &sp70))) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f30_3378 == this->unk54->GetCurrentPitch()) != 0))) || ((temp_r4_3405 = this->unk8, temp_r3_3406 = this->unkA4, sp60 = M2C_FIELD(temp_r4_3405, f64 *, 0x30), sp50 = temp_r3_3406->unk0, sp68 = M2C_FIELD(temp_r4_3405, f64 *, 0x38), sp58 = M2C_FIELD(temp_r3_3406, f64 *, 8), M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */), sp40 = sp10, sp18 = (f32) sp58 - (f32) sp68, sp48 = (f64) sp18, ((temp_f30_3378 < KDMath_GetPitch(*((MKVector3 *) &sp40))) != 0)) && (temp_r30_3277 != 0)) || (sp8 == 0.0f)) {
            this->unk54->EnablePitchOverride(temp_f30_3378, 0.0f);
        }
    }
    if ((this->unk244 & 2) && (PlayerRotatedCamera() != 0)) {
        AdjustPitchWithFloorDisable();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'DisablePitchOverride'
void GameCamera2::PlayerAdjustExit() {
    this->unk280 = 0.0f;
    this->unk54->DisablePitchOverride(5.0f);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'GameCameraEmuStateMachine'
s32 GameCamera2::CameraStatesMessage(MKMessage *arg0) {
    KDCameraStateChangeRequest *temp_r5_3534;

    if (KDCamera::CameraStatesMessage(arg0) != 0) {
        return 1;
    }
    if (this->unk26C->IsEmuStateMessage(arg0->unk0) != 0) {
        temp_r5_3534 = this->unk160;
        temp_r5_3534->unk7C += 1;
        *(temp_r5_3534 + (temp_r5_3534->unk7C * 4)) = arg0->unk0;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'GameCameraEmuStateMachine'
void GameCamera2::EmuStatesUpdate() {
    if (TestUserStateFlag(0x800U) != 0) {
        this->unk26C->UpdateStates(this);
    }
}
#endif

void GameCamera2::PostStateUpdate() {

}

#if 0 // DRAFT: undefined identifier 'sp10'
void GameCamera2::PostCameraUpdate() {
    f32 sp58;
    s32 sp54;
    s32 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    KDCameraHeroData *temp_r4_3592;
    KDCameraHeroData *temp_r4_3612;
    f32 temp_f5_3621;
    f32 temp_f6_3623;
    f32 var_f0_3619;
    f32 var_f7_3644;
    f64 temp_f2_3647;
    f64 temp_f2_3653;
    f64 temp_f2_3657;
    s32 temp_r3_3676;
    s32 var_r0_3686;
    u8 var_r3_3591;
    void *temp_r3_3613;
    void *temp_r3_3725;

    var_r3_3591 = 0;
    temp_r4_3592 = this->unk50;
    if (((void *) temp_r4_3592->unkA8 != NULL) && (temp_r4_3592->unkAC != 0.0f) && (temp_r4_3592->unkB0 != 0.0f)) {
        var_r3_3591 = 1;
    }
    if ((var_r3_3591 != 0) && (TestUserStateFlag(0x1000U) != 0)) {
        temp_r4_3612 = this->unk50;
        temp_r3_3613 = this->unk8;
        sp20 = M2C_FIELD(temp_r3_3613, f64 *, 0x30);
        var_f0_3619 = 1.0f;
        sp30 = temp_r4_3612->unk50;
        temp_f5_3621 = temp_r4_3612->unkAC;
        sp28 = M2C_FIELD(temp_r3_3613, f64 *, 0x38);
        temp_f6_3623 = temp_r4_3612->unkB0;
        sp38 = temp_r4_3612->unk58;
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
        sp40 = sp10;
        sp18 = (f32) sp38 - (f32) sp28;
        sp48 = (f64) sp18;
        var_f7_3644 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
        if (var_f7_3644 > 0.0f) {
            temp_f2_3647 = __frsqrte(var_f7_3644);
            temp_f2_3653 = 0.5 * temp_f2_3647 * -(((f64) var_f7_3644 * (temp_f2_3647 * temp_f2_3647)) - 3.0);
            temp_f2_3657 = 0.5 * temp_f2_3653 * -(((f64) var_f7_3644 * (temp_f2_3653 * temp_f2_3653)) - 3.0);
            var_f7_3644 = (f32) ((f64) var_f7_3644 * (0.5 * temp_f2_3657 * -(((f64) var_f7_3644 * (temp_f2_3657 * temp_f2_3657)) - 3.0)));
        } else if (var_f7_3644 < M2C_BITWISE(f32, 0.0)) {
            var_f7_3644 = __float_nan;
        } else {
            sp8 = var_f7_3644;
            temp_r3_3676 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_3676) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3686 = 1;
                } else {
                    var_r0_3686 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3686 = 5;
                } else {
                    var_r0_3686 = 3;
                }
                break;
            default:
                var_r0_3686 = 4;
                break;
            }
            if (var_r0_3686 == 1) {
                var_f7_3644 = __float_nan;
            }
        }
        if (var_f7_3644 < temp_f5_3621) {
            if (var_f7_3644 < temp_f6_3623) {
                var_f0_3619 = 0.0f;
            } else {
                var_f0_3619 = (var_f7_3644 - temp_f6_3623) / (temp_f5_3621 - temp_f6_3623);
            }
        }
        sp54 = 0;
        sp50 = 0x48;
        sp58 = var_f0_3619;
        temp_r3_3725 = this->unk50->unkA8;
        M2C_FIELD(M2C_FIELD(temp_r3_3725, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_3725, &sp50);
    }
    KDCamera::PostCameraUpdate();
}
#endif

void GameCamera2::PreCameraUpdate() {
    KDCameraJumpTargetOffset *temp_r4_3756;

    KDCamera::PreCameraUpdate();
    this->unk29C = 0;
    temp_r4_3756 = this->unk140;
    temp_r4_3756->unk0 = (temp_r4_3756->unk0 & ~0x80) | (((u8) (((CameraData *) (((GameData *) ((GameData *) GameData::gameData))->GetCameraData()))->GetJumpWithTy() == 0) << 7) & 0x80);
    UpdateSnaps();
    EmuStatesUpdate();
    CenterBehindHeroUpdate();
    AdjustPitchWithFloorUpdate();
}

#if 0 // DRAFT: illegal implicit conversion from 'GameCamera2' to
void GameCamera2::DeltaStagesMessage(MKMessage *arg0) {
    s32 temp_r0_3795;
    s32 temp_r0_3802;
    s32 temp_r0_3828;
    s32 temp_r0_3879;
    s32 temp_r0_3894;
    s32 temp_r4_3819;
    s32 temp_r4_3822;
    s32 temp_r5_3845;
    s32 temp_r5_3883;
    s32 temp_r8_3791;
    s32 var_ctr_3788;
    s32 var_ctr_3849;
    s32 var_r0_3863;
    s32 var_r4_3807;
    s32 var_r4_3833;
    s32 var_r4_3848;
    s32 var_r4_3874;
    s32 var_r4_3899;
    s32 var_r5_3787;
    s32 var_r6_3847;
    s32 var_r9_3783;
    u8 var_r0_3854;
    void *temp_r5_3877;
    void *temp_r7_3790;

    var_r9_3783 = 0;
    var_r5_3787 = 0;
    var_ctr_3788 = 3;
loop_1:
    temp_r7_3790 = &deltaStageInfo + var_r5_3787;
    temp_r8_3791 = arg0->unk0;
    if (temp_r8_3791 == (s32) M2C_FIELD(temp_r7_3790, s32 *, 4)) {
        temp_r0_3795 = this->unk268;
        if ((temp_r0_3795 > -1) && (temp_r0_3795 >= 0)) {
            this->unk248 = var_r9_3783;
        }
        temp_r0_3802 = this->unk268;
        if (temp_r0_3802 > -1) {
            var_r4_3807 = M2C_FIELD((this + (temp_r0_3802 * 4)), s32 *, 0x248);
        } else {
            var_r4_3807 = 0;
        }
        SetDeltaStages(var_r4_3807, 1U);
        return;
    }
    if (temp_r8_3791 == (s32) M2C_FIELD(temp_r7_3790, s32 *, 8)) {
        temp_r4_3819 = this->unk268;
        if (temp_r4_3819 < 7) {
            temp_r4_3822 = temp_r4_3819 + 1;
            this->unk268 = temp_r4_3822;
            M2C_FIELD((this + (temp_r4_3822 * 4)), s32 *, 0x248) = var_r9_3783;
        }
        temp_r0_3828 = this->unk268;
        if (temp_r0_3828 > -1) {
            var_r4_3833 = M2C_FIELD((this + (temp_r0_3828 * 4)), s32 *, 0x248);
        } else {
            var_r4_3833 = 0;
        }
        SetDeltaStages(var_r4_3833, 1U);
        return;
    }
    if (temp_r8_3791 == (s32) M2C_FIELD(temp_r7_3790, s32 *, 0xC)) {
        temp_r5_3845 = this->unk268;
        var_r6_3847 = temp_r5_3845;
        var_r4_3848 = temp_r5_3845 * 4;
        var_ctr_3849 = temp_r5_3845 + 1;
        if (temp_r5_3845 >= 0) {
loop_18:
            var_r0_3854 = 0;
            if ((temp_r5_3845 > -1) && (var_r6_3847 <= temp_r5_3845)) {
                var_r0_3854 = 1;
            }
            if (var_r0_3854 != 0) {
                var_r0_3863 = *(this + (var_r4_3848 + 0x248));
            } else {
                var_r0_3863 = 0;
            }
            if (var_r9_3783 == var_r0_3863) {
                if ((temp_r5_3845 > -1) && (var_r6_3847 <= temp_r5_3845)) {
                    var_r4_3874 = var_r6_3847 * 4;
loop_29:
                    temp_r5_3883 = this->unk268;
                    if (var_r6_3847 <= temp_r5_3883) {
                        temp_r5_3877 = this + var_r4_3874;
                        var_r6_3847 += 1;
                        temp_r0_3879 = M2C_FIELD(temp_r5_3877, s32 *, 0x24C);
                        var_r4_3874 += 4;
                        M2C_FIELD(temp_r5_3877, s32 *, 0x248) = temp_r0_3879;
                        goto loop_29;
                    }
                    this->unk268 = temp_r5_3883 - 1;
                }
            } else {
                var_r6_3847 -= 1;
                var_r4_3848 -= 4;
                var_ctr_3849 -= 1;
                if (var_ctr_3849 != 0) {
                    goto loop_18;
                }
            }
        }
        temp_r0_3894 = this->unk268;
        if (temp_r0_3894 > -1) {
            var_r4_3899 = M2C_FIELD((this + (temp_r0_3894 * 4)), s32 *, 0x248);
        } else {
            var_r4_3899 = 0;
        }
        SetDeltaStages(var_r4_3899, 1U);
        return;
    }
    var_r9_3783 += 1;
    var_r5_3787 += 0x10;
    var_ctr_3788 -= 1;
    if (var_ctr_3788 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetDeltaStages'
void GameCamera2::SetDeltaStages(int arg0, bool arg1) {
    this->unk54->SetDeltaStages(((GameCamera2Descriptor *) (checked_cast<P21GameCamera2Descriptor))->GetDeltaStages(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0), arg0), 0U, arg1);
}
#endif

void GameCamera2::DeltaUpdate() {
    KDCamera::DeltaUpdate();
    this->unk140->unk10 = 300.0f;
}

#if 0 // DRAFT: undefined identifier 'unkspC'
void GameCamera2::CenterBehindHeroUpdate() {
    f64 sp10;
    f64 sp8;
    f32 temp_ret_4064;
    f32 var_f1_3996;
    f32 var_f1_4021;
    f32 var_f1_4047;
    u8 var_r3_3984;
    u8 var_r3_4009;
    void *temp_r4_3983;
    void *temp_r4_4008;
    void *var_r3_4045;

    if (TestUserStateFlag(0x2000U) != 0) {
        if ((u8) this->unk240 == 0) {
            return;
        }
        temp_r4_3983 = this->unk120;
        var_r3_3984 = 0;
        if (((u8) M2C_FIELD(temp_r4_3983, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r4_3983, u8 *, 4) != 0)) {
            var_r3_3984 = 1;
        }
        if (var_r3_3984 != 0) {
            var_f1_3996 = 0.0f;
        } else {
            var_f1_3996 = MKInput_GetState(0x13, (MKInputDevices) M2C_FIELD(temp_r4_3983, s32 *, 0), NULL, NULL);
        }
        if (var_f1_3996 == 0.0f) {
            temp_r4_4008 = this->unk120;
            var_r3_4009 = 0;
            if (((u8) M2C_FIELD(temp_r4_4008, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r4_4008, u8 *, 4) != 0)) {
                var_r3_4009 = 1;
            }
            if (var_r3_4009 != 0) {
                var_f1_4021 = 0.0f;
            } else {
                var_f1_4021 = MKInput_GetState(0x12, (MKInputDevices) M2C_FIELD(temp_r4_4008, s32 *, 0), NULL, NULL);
            }
            if ((var_f1_4021 != 0.0f) || (this->unk50->IsMoving() != 0)) {
                goto block_18;
            }
            KDMath_GetYaw(&this->unk50->unk10);
            var_r3_4045 = this->unk8;
            var_f1_4047 = 0.0f;
            sp8 = M2C_FIELD(var_r3_4045, f64 *, 0x20);
            sp10 = M2C_FIELD(var_r3_4045, f64 *, 0x28);
            if ((((f32) sp10 * (f32) sp10) + (((f32) sp8 * (f32) sp8) + (unkspC * unkspC))) != 0.0f) {
                temp_ret_4064 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp8)));
                var_f1_4047 = temp_ret_4064;
                var_r3_4045 = M2C_BITWISE(void *, temp_ret_4064);
            }
            var_r3_4045->GetSmoothedAngleOffset(3.1415927f + var_f1_4047, 3.1415927f + M2C_ERROR(/* Read from unset register $f1 */), 2.5f);
            if (M2C_ERROR(/* Read from unset register $f1 */) != 0.0f) {
                this->unk124 += M2C_ERROR(/* Read from unset register $f1 */);
                this->unk29C = 1;
            }
            if ((this->unk54->IsUsingIdealPitch() == 0) && (this->unk54->IsUsingIdealDelta() != 0)) {
                this->unk2A0 |= 0x80;
            }
        } else {
block_18:
            this->unk240 = 0;
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void GameCamera2::CutSceneExit() {
    f64 sp10;
    f64 sp8;
    KDCameraHeroData *temp_r5_4161;

    CutSceneExit();
    if ((u8) M2C_FIELD(checked_cast<KDDataMessage<bool, 1027> *, MKMessage>(this->unk58->GetMessage(0x403)), u8 *, 8) != 0) {
        temp_r5_4161 = this->unk50;
        sp8 = M2C_FIELD(temp_r5_4161, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r5_4161, f64 *, 0x38);
        SnapToDirectionForce(*((MKVector3 *) &sp8));
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void GameCamera2::StaticPosUpdate() {
    f64 sp18;
    f64 sp10;
    f64 sp8;
    KDCameraPoint *temp_r4_4188;
    KDCameraPoint *temp_r4_4197;
    f64 temp_f0_4199;
    f64 temp_f1_4198;
    void *temp_r5_4195;

    sp18.GetUpdatedTarget();
    temp_r4_4188 = this->unkA4;
    temp_r4_4188->unk0 = sp18;
    M2C_FIELD(temp_r4_4188, f64 *, 8) = sp20;
    UpdateLTW();
    temp_r5_4195 = this->unk8;
    temp_r4_4197 = this->unkA0;
    temp_f1_4198 = M2C_FIELD(temp_r5_4195, f64 *, 0x30);
    temp_f0_4199 = M2C_FIELD(temp_r5_4195, f64 *, 0x38);
    sp8 = temp_f1_4198;
    temp_r4_4197->unk0 = temp_f1_4198;
    sp10 = temp_f0_4199;
    M2C_FIELD(temp_r4_4197, f64 *, 8) = temp_f0_4199;
    UpdateLTW();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDDataMessage'
void GameCamera2::StaticPosEnter() {
    f64 sp10;
    f64 sp8;
    void *temp_r3_4223;

    temp_r3_4223 = checked_cast<KDDataMessage<MKVector3, 1064> *, MKMessage>(this->unk58->GetMessage(0x428));
    sp8 = M2C_FIELD(temp_r3_4223, f64 *, 8);
    sp10 = M2C_FIELD(temp_r3_4223, f64 *, 0x10);
    Teleport(*((MKVector3 *) &sp8), 1U);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMessageStorage'
void GameCamera2::TrainUpdate() {
    Matrix sp80;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    KDCameraHeroData *temp_r29_4261;
    f32 temp_f2_4270;
    f32 var_f3_4349;
    f32 var_f4_4282;
    f64 temp_f1_4288;
    f64 temp_f1_4294;
    f64 temp_f1_4298;
    s32 temp_r3_4317;
    s32 var_r0_4327;
    u8 var_r0_4359;
    void *temp_r31_4259;
    void *temp_r3_4258;

    if (this->unk58->IsMessageStored(0x426) != 0) {
        temp_r3_4258 = checked_cast<TrainCameraUpdateDataMessage *, MKMessage>(this->unk58->GetMessage(0x426));
        temp_r31_4259 = temp_r3_4258;
        temp_r29_4261 = this->unk50;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        temp_f2_4270 = M2C_FIELD(temp_r3_4258, f32 *, 0x10) - M2C_FIELD(temp_r3_4258, f32 *, 0x20);
        sp58 = sp28;
        sp30 = temp_f2_4270;
        sp60 = (f64) sp30;
        var_f4_4282 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C));
        if (var_f4_4282 > 1e-12f) {
            if (var_f4_4282 > 0.0f) {
                temp_f1_4288 = __frsqrte(var_f4_4282);
                temp_f1_4294 = 0.5 * temp_f1_4288 * -(((f64) var_f4_4282 * (temp_f1_4288 * temp_f1_4288)) - 3.0);
                temp_f1_4298 = 0.5 * temp_f1_4294 * -(((f64) var_f4_4282 * (temp_f1_4294 * temp_f1_4294)) - 3.0);
                var_f4_4282 = (f32) ((f64) var_f4_4282 * (0.5 * temp_f1_4298 * -(((f64) var_f4_4282 * (temp_f1_4298 * temp_f1_4298)) - 3.0)));
            } else if (var_f4_4282 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4282 = __float_nan;
            } else {
                sp10 = var_f4_4282;
                temp_r3_4317 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_4317) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4327 = 1;
                    } else {
                        var_r0_4327 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4327 = 5;
                    } else {
                        var_r0_4327 = 3;
                    }
                    break;
                default:
                    var_r0_4327 = 4;
                    break;
                }
                if (var_r0_4327 == 1) {
                    var_f4_4282 = __float_nan;
                }
            }
            var_f3_4349 = 1.0f / var_f4_4282;
        } else {
            var_f3_4349 = 0.0f;
        }
        var_r0_4359 = 0;
        sp1C = unksp5C * var_f3_4349;
        sp18 = (f32) sp58 * var_f3_4349;
        sp20 = (f32) sp60 * var_f3_4349;
        sp68 = (f64) sp18;
        sp70 = (f64) sp20;
        if ((this->unk220 == MKVector3::zero.unk0) && (this->unk224 == MKVector3::zero.unk4) && (this->unk228 == MKVector3::zero.unk8)) {
            var_r0_4359 = 1;
        }
        if (var_r0_4359 != 0) {
            M2C_FIELD(this, f32 *, 0x220) = sp68;
            M2C_FIELD(this, f32 *, 0x228) = sp70;
        }
        KDMath_Smooth<MKVector3>(sp38, *((MKVector3 *) &this->unk220), 3.0f, gUpdateTimeDelta);
        Normalise(sp48);
        M2C_FIELD(this, f32 *, 0x220) = M2C_BITWISE(f64, sp48);
        M2C_FIELD(this, f32 *, 0x228) = (f64) sp48.unk8;
        M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r29_4261, f64 *, 0x20);
        M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r29_4261, f64 *, 0x28);
        if (KDMath_BuildMatrixFromFwd(&sp80, *((MKVector3 *) &this->unk220), &this->unk230) != 0) {
            sp80.unk30 = M2C_FIELD(temp_r31_4259, f32 *, 8);
            sp80.unk34 = M2C_FIELD(temp_r31_4259, f32 *, 0xC);
            sp80.unk38 = M2C_FIELD(temp_r31_4259, f32 *, 0x10);
            sp80.unk3C = 1.0f;
            SetLTW(sp80);
        }
    }
}
#endif

void GameCamera2::TrainExit() {

}

void GameCamera2::TrainEnter() {
    M2C_FIELD(this, f64 *, 0x220) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x228) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(this, f64 *, 0x220);
    M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(this, f64 *, 0x228);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'GameCameraEmuStateMachine'
u8 GameCamera2::ProcessCameraStateRequest(int arg0) {
    KDCamera::ProcessCameraStateRequest(arg0);
    if (arg0 != 0x800) {
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk26C->HandleGameCameraMessage(this, arg0);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void GameCamera2::IsUnderwater() {
    f64 sp10;
    f64 sp8;
    void *temp_r6_4572;

    temp_r6_4572 = this->unk8;
    sp8 = M2C_FIELD(temp_r6_4572, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r6_4572, f64 *, 0x38);
    sp8.IsWithin(*NULL, NULL, (s32 *) temp_r6_4572);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp24'
f32 GameCamera2::GetIdealFieldOfView() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    KDCameraDeltaStagesEx *temp_r31_4595;
    f32 temp_f1_4601;
    f32 temp_f31_4596;
    f32 temp_f31_4599;
    f32 var_f2_4686;
    f32 var_f4_4616;
    f64 temp_f1_4619;
    f64 temp_f1_4625;
    f64 temp_f1_4629;
    s32 temp_r3_4648;
    s32 var_r0_4658;

    temp_r31_4595 = this->unk54;
    temp_f31_4596 = M2C_FIELD(temp_r31_4595, f32 *, 0x28);
    temp_f31_4599 = ((KDCameraDeltaStagesEx *) (temp_r31_4595 + 0x14))->GetZDelta() + temp_f31_4596;
    temp_f1_4601 = ((KDCameraDeltaStagesEx *) (temp_r31_4595 + 0x14))->GetYDelta();
    sp18 = temp_f31_4599;
    sp10 = 0.0f;
    sp14 = temp_f1_4601;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    var_f4_4616 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    if (var_f4_4616 > 0.0f) {
        temp_f1_4619 = __frsqrte(var_f4_4616);
        temp_f1_4625 = 0.5 * temp_f1_4619 * -(((f64) var_f4_4616 * (temp_f1_4619 * temp_f1_4619)) - 3.0);
        temp_f1_4629 = 0.5 * temp_f1_4625 * -(((f64) var_f4_4616 * (temp_f1_4625 * temp_f1_4625)) - 3.0);
        var_f4_4616 = (f32) ((f64) var_f4_4616 * (0.5 * temp_f1_4629 * -(((f64) var_f4_4616 * (temp_f1_4629 * temp_f1_4629)) - 3.0)));
    } else if (var_f4_4616 < M2C_BITWISE(f32, 0.0)) {
        var_f4_4616 = __float_nan;
    } else {
        sp8 = var_f4_4616;
        temp_r3_4648 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_4648) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_4658 = 1;
            } else {
                var_r0_4658 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_4658 = 5;
            } else {
                var_r0_4658 = 3;
            }
            break;
        default:
            var_r0_4658 = 4;
            break;
        }
        if (var_r0_4658 == 1) {
            var_f4_4616 = __float_nan;
        }
    }
    var_f2_4686 = ((var_f4_4616 - M2C_FIELD(this->unk54, f32 *, 0x28)) - 563.0f) / 257.0f;
    if (var_f2_4686 < 1.0f) {

    } else {
        var_f2_4686 = 1.0f;
    }
    if (var_f2_4686 > 0.0f) {

    } else {
        var_f2_4686 = 0.0f;
    }
    return ((1.0f - var_f2_4686) * 0.17453289f) + 0.9250245f;
}
#endif

void GameCamera2::GetFieldOfView() {
    if (this->unk2B4 != 0.0f) {
        return;
    }
    GetIdealFieldOfView();
}

void GameCamera2::Message(MKMessage *arg0) {
    if ((u8) this->unk4C != 0) {
        KDCamera::Message(arg0);
        DeltaStagesMessage(arg0);
        HeroStateHelperMessage(arg0);
    }
}

void GameCamera2::DrawCamera() {
    KDCamera::DrawCamera();
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'GameCameraEmuStateMachine'
void GameCamera2::ClearData() {
    this->unk2B0 = 1;
    KDCamera::ClearData();
    this->unk240 = 0;
    this->unk244 = 3;
    this->unk26C->ClearData(this);
    M2C_FIELD(this, f32 *, 0x270) = 0.0f;
    M2C_FIELD(this, f32 *, 0x274) = 0.0f;
    this->unk278 = 0.0f;
    this->unk280 = 0.0f;
    this->unk284 = 1.0f;
    memset(&this->unk288, 0, 4U);
    this->unk290 = 0.0f;
    this->unk298 = NULL;
    this->unk294 = 0.0f;
    this->unk29C = 0;
    this->unk2A0 &= ~0x80;
    this->unk2A0 &= ~0x40;
    this->unk2A0 &= ~0x20;
    this->unk2A4 = 0.0f;
    this->unk2AC = 0;
    this->unk2B4 = 0.0f;
    this->unk2B0 = 0;
}
#endif

void GameCamera2::ResetCamera() {
    s32 temp_r3_4843;
    s32 temp_r3_4846;

    KDCamera::ResetCamera();
    this->unk268 = -1;
    temp_r3_4843 = this->unk268;
    if (temp_r3_4843 < 7) {
        temp_r3_4846 = temp_r3_4843 + 1;
        this->unk268 = temp_r3_4846;
        M2C_FIELD((this + (temp_r3_4846 * 4)), s32 *, 0x248) = 0;
    }
    SetDeltaStages(0, 0U);
}

void GameCamera2::Resolve() {
    KDCamera::Resolve();
    if ((void *) this->unk120 == NULL) {
        this->unk120 = M2C_FIELD(&gb, void **, 0x354);
    }
}

#if 0 // DRAFT: illegal use of non-static member
void GameCamera2::LoadDone() {
    this->unk14 = 2;
    MKSceneManager::PropResolver_Add(*this->unk0, M2C_ERROR(/* Read from unset register $r5 */));
    KDCamera::LoadDone();
    if ((GameCamera2 *) M2C_FIELD(&gb, GameCamera2 **, 0x3B8) == NULL) {
        M2C_FIELD(&gb, GameCamera2 **, 0x3B8) = this;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2A8'
void GameCamera2::Deinit() {
    M2C_UNK *temp_r0_4930;
    M2C_UNK *temp_r0_4949;
    M2C_UNK *var_r31_4926;
    M2C_UNK *var_r3_4927;
    M2C_UNK *var_r4_4925;
    MKHeap *temp_r3_4952;
    u32 temp_r0_4935;

    var_r4_4925 = this->unk2A8;
    var_r31_4926 = var_r4_4925;
    var_r3_4927 = var_r4_4925;
loop_3:
    temp_r0_4935 = M2C_FIELD(var_r3_4927, u32 *, -4);
    var_r3_4927 -= 4;
    if (temp_r0_4935 != 0U) {
        temp_r0_4930 = *var_r3_4927;
        if (temp_r0_4930 < var_r31_4926) {
            var_r31_4926 = &*temp_r0_4930;
        }
        goto loop_3;
    }
    if (var_r3_4927 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_4949 = *var_r4_4925;
        if (temp_r0_4949 != NULL) {
            if (temp_r0_4949 < var_r31_4926) {
                var_r31_4926 = temp_r0_4949;
            }
            var_r4_4925 += 4;
            goto loop_9;
        }
        temp_r3_4952 = var_r3_4927->Current();
        if (temp_r3_4952 != NULL) {
            ((MKHeap *) (temp_r3_4952->Current()))->Free(var_r31_4926, NULL, 0);
        } else {
            free(var_r31_4926);
        }
    }
    this->unk2A8 = NULL;
    operator delete(this->unk26C);
    this->unk26C = NULL;
    KDCamera::Deinit();
    if ((u32) M2C_FIELD(&gb, u32 *, 0x3B8) == this) {
        M2C_FIELD(&gb, u32 *, 0x3B8) = 0U;
        return;
    }
    KDSound_SetListener((Matrix *) this->unk8);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'GameCameraEmuStateMachine'
void GameCamera2::Init() {
    GameCamera2Descriptor *temp_r3_5023;
    M2C_UNK *temp_r3_5055;
    M2C_UNK *temp_r3_5062;
    M2C_UNK *temp_r3_5069;
    M2C_UNK *var_r3_5042;
    M2C_UNK *var_r5_5054;
    MKHeap *temp_r3_5032;
    s32 temp_r30_5024;
    s32 temp_r3_5001;
    s32 temp_r3_5004;
    s32 var_ctr_5058;

    KDCamera::Init();
    temp_r3_5001 = this->unk268;
    if (temp_r3_5001 < 7) {
        temp_r3_5004 = temp_r3_5001 + 1;
        this->unk268 = temp_r3_5004;
        M2C_FIELD((this + (temp_r3_5004 * 4)), s32 *, 0x248) = 0;
    }
    this->unk2B0 = 0;
    operator new(0x10U, NULL, 0);
    this->unk26C = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk26C->Init(this, *GameCamera2::pEmuStateDescriptors);
    temp_r3_5023 = checked_cast<GameCamera2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r30_5024 = temp_r3_5023->unkB4;
    if (temp_r30_5024 == 0) {
        this->unk2A8 = &gEmptyPtrListDL + 4;
        return;
    }
    temp_r3_5032 = temp_r3_5023->Current();
    if (temp_r3_5032 != NULL) {
        var_r3_5042 = ((MKHeap *) (temp_r3_5032->Current()))->Alloc(((temp_r30_5024 + 2) * 4) + (temp_r30_5024 * 0x14), NULL, 0);
    } else {
        var_r3_5042 = malloc(((temp_r30_5024 + 2) * 4) + (temp_r30_5024 * 0x14));
    }
    this->unk2A8 = var_r3_5042;
    var_r5_5054 = this->unk2A8;
    temp_r3_5055 = var_r5_5054 + (temp_r30_5024 * 0x14);
    this->unk2A8 = temp_r3_5055;
    *temp_r3_5055 = NULL;
    var_ctr_5058 = temp_r30_5024;
    if (temp_r30_5024 > 0) {
        do {
            temp_r3_5062 = this->unk2A8;
            this->unk2A8 = temp_r3_5062 + 4;
            M2C_FIELD(temp_r3_5062, M2C_UNK **, 4) = var_r5_5054;
            var_r5_5054 += 0x14;
            var_ctr_5058 -= 1;
        } while (var_ctr_5058 != 0);
    }
    temp_r3_5069 = this->unk2A8;
    this->unk2A8 = temp_r3_5069 + 4;
    M2C_FIELD(temp_r3_5069, M2C_UNK **, 4) = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKProp **' to
void GameCamera2::InitModule() {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_5098;

    deltaStageInfo.InitModule();
    *GameCamera2::pPossibleStateChanges = &deltaStageInfo.unk30;
    if ((s8) init_762 == 0) {
        temp_r3_5098 = &deltaStageInfo + 0xDC;
        M2C_FIELD(temp_r3_5098, f32 *, 0x14) = (f32) deltaStageInfo.unk60.unk10;
        M2C_FIELD(temp_r3_5098, f32 *, 0x18) = (f32) deltaStageInfo.unk60.unk14;
        M2C_FIELD(temp_r3_5098, f32 *, 0x1C) = (f32) deltaStageInfo.unk60.unk18;
        M2C_FIELD(temp_r3_5098, s32 *, 0xF0) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xD4);
        sp14 = M2C_FIELD(&__ptmf_null, s32 *, 0);
        sp18 = M2C_FIELD(&__ptmf_null, s32 *, 4);
        sp1C = M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(temp_r3_5098, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(temp_r3_5098, s32 *, 0x24) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(temp_r3_5098, s32 *, 0x28) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(temp_r3_5098, f32 *, 0x2C) = (f32) deltaStageInfo.unk60.unk1C;
        M2C_FIELD(temp_r3_5098, f32 *, 0x30) = (f32) deltaStageInfo.unk60.unk20;
        M2C_FIELD(temp_r3_5098, f32 *, 0x34) = (f32) deltaStageInfo.unk60.unk24;
        M2C_FIELD(temp_r3_5098, f32 *, 0x54) = (f32) deltaStageInfo.unk60.unk28;
        M2C_FIELD(temp_r3_5098, f32 *, 0x58) = (f32) deltaStageInfo.unk60.unk2C;
        M2C_FIELD(temp_r3_5098, f32 *, 0x5C) = (f32) deltaStageInfo.unk60.unk30;
        M2C_FIELD(temp_r3_5098, f32 *, 0x60) = (f32) deltaStageInfo.unk60.unk34;
        M2C_FIELD(temp_r3_5098, f32 *, 0x64) = (f32) deltaStageInfo.unk60.unk38;
        M2C_FIELD(temp_r3_5098, f32 *, 0x68) = (f32) deltaStageInfo.unk60.unk3C;
        M2C_FIELD(temp_r3_5098, KDCameraPoint **, 0x6C) = (KDCameraPoint *) deltaStageInfo.unkA0;
        M2C_FIELD(temp_r3_5098, KDCameraPoint **, 0x70) = (KDCameraPoint *) deltaStageInfo.unkA4;
        M2C_FIELD(temp_r3_5098, f32 *, 0x74) = (f32) deltaStageInfo.unkA8;
        M2C_FIELD(temp_r3_5098, s32 *, 0x94) = (s32) deltaStageInfo.unkAC;
        M2C_FIELD(temp_r3_5098, s32 *, 0x98) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xB0);
        M2C_FIELD(temp_r3_5098, s32 *, 0x9C) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xB4);
        M2C_FIELD(temp_r3_5098, s32 *, 0xA0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(temp_r3_5098, s32 *, 0xA4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(temp_r3_5098, s32 *, 0xA8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(temp_r3_5098, s32 *, 0xAC) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xB8);
        M2C_FIELD(temp_r3_5098, s32 *, 0xB0) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xBC);
        M2C_FIELD(temp_r3_5098, s32 *, 0xB4) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xC0);
        M2C_FIELD(temp_r3_5098, s32 *, 0xD4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(temp_r3_5098, s32 *, 0xD8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(temp_r3_5098, s32 *, 0xDC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(temp_r3_5098, s32 *, 0xE0) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xC4);
        M2C_FIELD(temp_r3_5098, s32 *, 0xE4) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xC8);
        M2C_FIELD(temp_r3_5098, s32 *, 0xE8) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xCC);
        M2C_FIELD(temp_r3_5098, s32 *, 0xEC) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xD0);
        M2C_FIELD(temp_r3_5098, s32 *, 0xF4) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0xD8);
        init_762 = 1;
    }
    *KDCamera::pStateDescriptors = &deltaStageInfo + 0xDC;
    if ((s8) init_780 == 0) {
        sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
        spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
        sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
        deltaStageInfo.unk2A0 = M2C_FIELD(&__ptmf_null, s32 *, 0);
        deltaStageInfo.unk2A4 = M2C_FIELD(&__ptmf_null, s32 *, 4);
        deltaStageInfo.unk2A8 = M2C_FIELD(&__ptmf_null, s32 *, 8);
        deltaStageInfo.unk2AC = M2C_FIELD(&deltaStageInfo, s32 *, 0x1DC);
        deltaStageInfo.unk2B0 = deltaStageInfo.unk1E0;
        deltaStageInfo.unk2B4 = deltaStageInfo.unk1E4;
        deltaStageInfo.unk2B8 = deltaStageInfo.unk1E8;
        deltaStageInfo.unk2BC = M2C_FIELD(&deltaStageInfo, s32 *, 0x1EC);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2C0) = (s32) deltaStageInfo.unk1F0;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2D8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2DC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2E0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2E4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2E8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2EC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2F0) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0x1F4);
        M2C_FIELD(&deltaStageInfo, KDCamera **, 0x2F4) = (KDCamera *) deltaStageInfo.unk1F8;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x2F8) = (s32) deltaStageInfo.unk1FC;
        M2C_FIELD(&deltaStageInfo, KDCollisionObject **, 0x310) = (KDCollisionObject *) deltaStageInfo.unk200;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x314) = (s32) M2C_FIELD(&deltaStageInfo, s32 *, 0x204);
        M2C_FIELD(&deltaStageInfo, f32 *, 0x318) = (f32) deltaStageInfo.unk208;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x31C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x320) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x324) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, f32 *, 0x328) = (f32) deltaStageInfo.unk20C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x32C) = (s32) deltaStageInfo.unk210;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x330) = (s32) deltaStageInfo.unk214;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x348) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x34C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x350) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x354) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x358) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x35C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x360) = (s32) deltaStageInfo.unk218;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x364) = (s32) deltaStageInfo.unk21C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x368) = (s32) deltaStageInfo.unk220;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x380) = (s32) deltaStageInfo.unk224;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x384) = (s32) deltaStageInfo.unk228;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x388) = (s32) deltaStageInfo.unk22C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x38C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x390) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x394) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3F8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x404) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x430) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x43C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x474) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x398) = (s32) deltaStageInfo.unk230;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x39C) = (s32) deltaStageInfo.unk234;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3A0) = (s32) deltaStageInfo.unk238;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3B8) = (s32) deltaStageInfo.unk23C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3BC) = (s32) deltaStageInfo.unk240;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3C0) = (s32) deltaStageInfo.unk244;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3C4) = (s32) deltaStageInfo.unk248;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3C8) = (s32) deltaStageInfo.unk24C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3CC) = (s32) deltaStageInfo.unk250;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3D0) = (s32) deltaStageInfo.unk254;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3D4) = (s32) deltaStageInfo.unk258;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3D8) = (s32) deltaStageInfo.unk25C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3F0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3F4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x3FC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x400) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x408) = (s32) deltaStageInfo.unk260;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x40C) = (s32) deltaStageInfo.unk264;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x410) = (s32) deltaStageInfo.unk268;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x428) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x42C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x434) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x438) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x440) = (s32) deltaStageInfo.unk26C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x444) = (s32) deltaStageInfo.unk270;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x448) = (s32) deltaStageInfo.unk274;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x460) = (s32) deltaStageInfo.unk278;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x464) = (s32) deltaStageInfo.unk27C;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x468) = (s32) deltaStageInfo.unk280;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x46C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x470) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
        M2C_FIELD(&deltaStageInfo, s32 *, 0x478) = (s32) deltaStageInfo.unk284;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x47C) = (s32) deltaStageInfo.unk288;
        M2C_FIELD(&deltaStageInfo, s32 *, 0x480) = (s32) deltaStageInfo.unk28C;
        init_780 = 1;
    }
    *GameCamera2::pEmuStateDescriptors = &deltaStageInfo.unk290;
    *KDCamera::pMessageStorageDescriptors = &deltaStageInfo + 0x4C0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'GameCamera2Descriptor' to
u8 GameCamera2Descriptor::LoadDeltaStages(MKIniLine *arg0) {
    s32 var_r28_5335;
    s32 var_r30_5338;
    s32 var_r31_5337;

    var_r28_5335 = 0;
    var_r31_5337 = 0;
    var_r30_5338 = 0;
loop_1:
    if (((KDCameraDeltaStages *) (*(this + (var_r30_5338 + 0xB8))))->LoadLine(arg0, *(&deltaStageInfo + var_r31_5337)) != 0) {
        return 1U;
    }
    var_r28_5335 += 1;
    var_r30_5338 += 4;
    var_r31_5337 += 0x10;
    if (var_r28_5335 >= 3) {
        return 0U;
    }
    goto loop_1;
}
#endif

KDCameraDeltaStages *GameCamera2Descriptor::GetDeltaStages(int arg0) {
    return M2C_FIELD((this + (arg0 * 4)), KDCameraDeltaStages **, 0xB8);
}

void GameCamera2Descriptor::LoadDone() {
    KDCameraDescriptor::LoadDone();
    this->unk94 = 4;
    this->unkA8 = this->unkB8;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 GameCamera2Descriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_5402;

    var_r31_5402 = 0;
    if ((KDCameraDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("trackedShakePropMax", &this->unkB4, 0) != 0) || (LoadDeltaStages(arg0) != 0)) {
        var_r31_5402 = 1;
    }
    return var_r31_5402;
}
#endif

#if 0 // DRAFT: function call 'operator delete(GameCamera2Descriptor)' does not match
void GameCamera2Descriptor::Deinit() {
    s32 temp_r29_5443;
    s32 var_r28_5440;
    s32 var_r31_5438;

    var_r31_5438 = 0;
    var_r28_5440 = 0;
    do {
        temp_r29_5443 = var_r31_5438 + 0xB8;
        operator delete(*(this + temp_r29_5443));
        var_r28_5440 += 1;
        *(this + temp_r29_5443) = 0;
        var_r31_5438 += 4;
    } while (var_r28_5440 < 3);
    KDCameraDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal operand
void GameCamera2Descriptor::Init() {
    s32 temp_r0_5479;
    s32 var_r30_5472;
    s32 var_r31_5473;
    void *temp_r3_5484;

    KDCameraDescriptor::Init();
    var_r30_5472 = 0;
    var_r31_5473 = 0;
    do {
        operator new(0xCU, NULL, 0);
        temp_r0_5479 = var_r31_5473 + 0xB8;
        var_r30_5472 += 1;
        *(this + temp_r0_5479) = M2C_ERROR(/* Read from unset register $r3 */);
        var_r31_5473 += 4;
        temp_r3_5484 = *(this + temp_r0_5479);
        M2C_FIELD(temp_r3_5484, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r3_5484, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r3_5484, f32 *, 0) = 0.0f;
    } while (var_r30_5472 < 3);
    this->unkAC = 1.0f;
    this->unkB0 = 1600.0f;
    this->unk9C = 0x40;
    this->unkA0 = 8;
    this->unkB4 = 0x20;
}
#endif
