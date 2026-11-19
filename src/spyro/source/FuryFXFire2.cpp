#include "spyro/source/FuryFXFire2.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/ClusterBomb.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/Spyro.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_SpyroFuryMissile1;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: pointer/array required
void FuryFXFire2::ResetFury() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    MKProp *temp_r6_75;
    f32 temp_r3_88;
    f32 var_r29_55;
    void *temp_r30_100;
    void *temp_r4_91;

    SetDefaults();
    var_r29_55 = this->unk14C;
loop_4:
    if (M2C_BITWISE(u32, var_r29_55) != 0U) {
        temp_r30_100 = *var_r29_55;
        if (temp_r30_100 == NULL) {

        } else {
            if ((s32) M2C_FIELD(temp_r30_100, s32 *, 0x44) != 2) {
                sp10 = M2C_FIELD(temp_r30_100, f64 *, 0x30);
                sp18 = M2C_FIELD(temp_r30_100, f64 *, 0x38);
                KDSound_Stop(temp_r30_100 + 0x48);
                temp_r6_75 = M2C_FIELD(gb.unk0->__vptr, MKProp *(**)(HeroInterface *), 0xC)(gb.unk0);
                sp8 = 1;
                this->unk150->Trigger(*((MKVector3 *) &sp10), 0.4f, 1U, temp_r6_75, 0, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                M2C_FIELD(temp_r30_100, s32 *, 0x44) = 2;
                temp_r3_88 = this->unk14C;
                this->unk14C = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_88) + 4));
                temp_r4_91 = *temp_r3_88;
                *temp_r3_88 = (void *) *var_r29_55;
                *var_r29_55 = temp_r4_91;
            }
            var_r29_55 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r29_55) + 4));
            goto loop_4;
        }
    }
loop_8:
    if ((void *) *this->unk14C != NULL) {
        this->unk14C = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk14C) + 4));
        goto loop_8;
    }
    gb.EnableSlowMotion(0U, -1.0f, 0.5f);
    this->unk154 = (Explosion4 *)-1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKModel *' to
void FuryFXFire2::SpawnMeteor() {
    s8 sp138;
    s32 sp134;
    s32 sp130;
    s32 sp12C;
    f32 sp128;
    s32 sp124;
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
    MKVector3 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    M2C_UNK sp78;
    M2C_UNK sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_r3_146;
    u32 *temp_r3_155;
    u32 temp_r31_177;

    this->unk148 = M2C_BITWISE(f32, this->unk148) - gUpdateTimeDelta;
    if (!(M2C_BITWISE(f32, this->unk148) > 0.0f)) {
        this->unk148 = 0.05f;
        temp_r3_146 = this->unk14C;
        if ((u32) M2C_FIELD(temp_r3_146, u32 *, -4) != 0U) {
            spE8 = 0.0f;
            temp_r3_155 = M2C_BITWISE(s32, temp_r3_146) - 4;
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
            sp124 = 0;
            sp128 = 3.4028235e38f;
            sp12C = 0;
            sp130 = 0;
            sp134 = -1;
            sp138 = 0;
            this->unk14C = M2C_BITWISE(f32, temp_r3_155);
            temp_r31_177 = *temp_r3_155;
            if (temp_r31_177 != 0) {
                M2C_STRUCT_COPY(temp_r31_177, &identity, 0x40);
                M2C_FIELD(temp_r31_177, s32 *, 0x48) = 0;
                MKVector(0.0f, 2000.0f, 0.0f);
                MKVector(1.0f, 0.0f, 1.0f);
                MKVector(-1.0f, 0.0f, -1.0f);
                KDRand_Vector(sp98, sp88);
                spA8.operator*(1500.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spB8 = sp8;
                sp10 = this->unk90.unk38 + spA8.unk8;
                spC0 = (f64) sp10;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spC8 = sp18;
                sp20 = (f32) spC0 + sp70;
                M2C_FIELD(temp_r31_177, f32 *, 0x30) = (f32) spC8;
                spD0 = (f64) sp20;
                M2C_FIELD(temp_r31_177, f32 *, 0x34) = unkspCC;
                sp40 = 0.0f;
                M2C_FIELD(temp_r31_177, f32 *, 0x38) = (f32) spD0;
                M2C_FIELD(temp_r31_177, f32 *, 0x3C) = 1.0f;
                sp38 = 0.0f;
                sp3C = -3000.0f;
                spD8 = (f64) M2C_FIELD(temp_r31_177, f32 *, 0x30);
                spE0 = (f64) M2C_FIELD(temp_r31_177, f32 *, 0x38);
                sp48 = (f64) sp38;
                M2C_FIELD(temp_r31_177, f32 *, 0x40) = (f32) this->unk90.unk34;
                sp50 = (f64) sp40;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp58 = sp28;
                sp30 = (f32) spE0 + (f32) sp50;
                sp60 = (f64) sp30;
                if (MKCollision_RayCollide(*((MKVector3 *) &spD8), *((MKVector3 *) &sp58), (MKCollisionResult *) &spE8, (MKCollisionMode) 4, 0x0C000000) != 0) {
                    M2C_FIELD(temp_r31_177, f32 *, 0x40) = spEC;
                }
                M2C_FIELD(temp_r31_177, s32 *, 0x44) = 1;
                M2C_FIELD(temp_r31_177, s32 *, 0x48) = KDSound_Play3d(GS_SpyroFuryMissile1, temp_r31_177 + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    }
}
#endif

void FuryFXFire2::DrawMeteor(FuryFXFire2::Meteor *arg1) {
    MKModel_SetWorldMatrix(this->unk148, *((Matrix *) arg1));
    MKModel_Draw(this->unk148, NULL);
}

#if 0 // DRAFT: pointer/array required
void FuryFXFire2::DrawMeteors() {
    FuryFXFire2::Meteor *temp_r4_343;
    f32 var_r31_334;

    var_r31_334 = this->unk14C;
loop_2:
    if (M2C_BITWISE(u32, var_r31_334) != 0U) {
        temp_r4_343 = *var_r31_334;
        if (temp_r4_343 != NULL) {
            DrawMeteor(temp_r4_343);
            var_r31_334 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r31_334) + 4));
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void FuryFXFire2::UpdateMeteors() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    MKProp *temp_r6_406;
    f32 temp_f1_391;
    f32 temp_r3_421;
    f32 var_r30_362;
    s32 temp_r0_365;
    void *temp_r31_433;
    void *temp_r4_424;

    var_r30_362 = this->unk14C;
loop_9:
    if (M2C_BITWISE(u32, var_r30_362) != 0U) {
        temp_r31_433 = *var_r30_362;
        if (temp_r31_433 != NULL) {
            temp_r0_365 = M2C_FIELD(temp_r31_433, s32 *, 0x44);
            switch (temp_r0_365) {                  /* irregular */
            case 1:
                sp10 = M2C_FIELD(temp_r31_433, f64 *, 0x30);
                sp18 = M2C_FIELD(temp_r31_433, f64 *, 0x38);
                unksp14 += -3500.0f * gUpdateTimeDelta;
                M2C_FIELD(temp_r31_433, f64 *, 0x30) = (f32) sp10;
                M2C_FIELD(temp_r31_433, f32 *, 0x34) = unksp14;
                M2C_FIELD(temp_r31_433, f64 *, 0x38) = (f32) sp18;
                M2C_FIELD(temp_r31_433, f32 *, 0x3C) = 1.0f;
                temp_f1_391 = M2C_FIELD(temp_r31_433, f32 *, 0x40);
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (unksp14 == temp_f1_391) {
                    unksp14 = temp_f1_391;
                    KDSound_Stop(temp_r31_433 + 0x48);
                    temp_r6_406 = M2C_FIELD(gb.unk0->__vptr, MKProp *(**)(HeroInterface *), 0xC)(gb.unk0);
                    sp8 = 1;
                    this->unk150->Trigger(*((MKVector3 *) &sp10), 0.4f, 1U, temp_r6_406, 0, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                    M2C_FIELD(temp_r31_433, s32 *, 0x44) = 2;
                }
                break;
            case 2:
                temp_r3_421 = this->unk14C;
                this->unk14C = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_421) + 4));
                temp_r4_424 = *temp_r3_421;
                *temp_r3_421 = (void *) *var_r30_362;
                *var_r30_362 = temp_r4_424;
                break;
            }
            var_r30_362 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r30_362) + 4));
            goto loop_9;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'gameData'
s32 FuryFXFire2::Trigger(const MKVector3 &arg0) {
    s32 temp_r0_472;
    s32 temp_r29_495;
    s32 temp_r3_470;
    s32 var_r30_488;
    u8 var_r3_478;
    void *temp_r5_474;

    this->unk90.unk30 = arg0.unk0;
    this->unk90.unk34 = arg0.unk4;
    this->unk90.unk38 = arg0.unk8;
    this->unk90.unk3C = 1.0f;
    if ((s32) this->unkD0 == 0) {
        this->unkD0 = 1;
        this->unkE8 = 1.0f;
        temp_r3_470 = gameData.unk158 << 5;
        temp_r0_472 = *(&gameData.unk70 + (temp_r3_470 + 0x7C));
        temp_r5_474 = &gameData.unk70 + (temp_r3_470 + 0x64);
        if (temp_r0_472 == 3) {
            var_r3_478 = 0;
            if (((s32) M2C_FIELD(temp_r5_474, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_474, s32 *, 4) == 3)) {
                var_r3_478 = 1;
            }
            var_r30_488 = var_r3_478 != 0;
        } else {
            var_r30_488 = *(temp_r5_474 + (temp_r0_472 * 4));
        }
        temp_r29_495 = gameData.unk158;
        this->unkF0.Init(M2C_FIELD(gb.unk0->__vptr, MKProp *(**)(HeroInterface *), 0xC)(gb.unk0), 15.0f * gb.unk37C, 3, var_r30_488, temp_r29_495, temp_r29_495, 0, -1);
        gb.unk381 = 1;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void FuryFXFire2::SetDefaults() {
    SetDefaults();
    this->unkD0 = 0;
    this->unk90.SetIdentity();
    this->unkD8 = 1.0f;
    this->unkDC = 1.0f;
    this->unkE0 = 1.0f;
    this->unkE8 = 0.0f;
    this->unk148 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void FuryFXFire2::Deinit() {
    MKHeap *temp_r3_594;
    f32 var_r31_568;
    f32 var_r3_569;
    f32 var_r4_567;
    u32 temp_r0_572;
    u32 temp_r0_577;
    u32 temp_r0_591;

    var_r4_567 = this->unk14C;
    var_r31_568 = var_r4_567;
    var_r3_569 = var_r4_567;
loop_3:
    temp_r0_577 = M2C_FIELD(var_r3_569, u32 *, -4);
    var_r3_569 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r3_569) - 4));
    if (temp_r0_577 != 0U) {
        temp_r0_572 = *var_r3_569;
        if (temp_r0_572 < M2C_BITWISE(u32, var_r31_568)) {
            var_r31_568 = M2C_BITWISE(f32, temp_r0_572);
        }
        goto loop_3;
    }
    if (M2C_BITWISE(u32, var_r3_569) != &gEmptyPtrListDL) {
loop_9:
        temp_r0_591 = *var_r4_567;
        if (temp_r0_591 != 0U) {
            if (temp_r0_591 < M2C_BITWISE(u32, var_r31_568)) {
                var_r31_568 = M2C_BITWISE(f32, temp_r0_591);
            }
            var_r4_567 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r4_567) + 4));
            goto loop_9;
        }
        temp_r3_594 = ((MKHeap *) (M2C_BITWISE(MKHeap *, var_r3_569)))->Current();
        if (temp_r3_594 != NULL) {
            ((MKHeap *) (temp_r3_594->Current()))->Free(M2C_BITWISE(void *, var_r31_568), NULL, 0);
        } else {
            free(M2C_BITWISE(MKHeap *, var_r31_568));
        }
    }
    this->unk14C = 0.0f;
    MKModel_Destroy(this->unk148);
    this->unk160.Deinit();
    FuryFX::Deinit();
}
#endif

void FuryFXFire2::Draw() {
    s32 temp_r0_628;

    temp_r0_628 = this->unkD0;
    switch (temp_r0_628) {                          /* irregular */
    case 1:
        return;
    default:
        DrawMeteors();
        /* fallthrough */
    case 0:
    case 6:
        return;
    }
}

#if 0 // DRAFT: expression syntax error
void FuryFXFire2::Update() {
    f32 temp_f1_1457;
    f32 temp_f22_1384;
    f32 temp_f23_1387;
    f32 var_f0_1587;
    f64 temp_f2_1297;
    s32 temp_r0_688;
    s32 temp_r29_845;
    s32 temp_r4_1071;
    s32 temp_r4_935;
    s32 var_r28_1369;
    s32 var_r28_1474;
    void *temp_r3_1086;
    void *temp_r3_1120;
    void *temp_r3_1416;
    void *temp_r3_1508;
    void *temp_r3_725;
    void *temp_r3_759;
    void *temp_r3_793;
    void *temp_r3_826;
    void *temp_r3_950;
    void *temp_r3_984;
    this->unkE8 = this->unkE8 - gUpdateTimeDelta;
    this->unk160.Update();
    if ((s32) this->unkD0 != 0) {
        UpdateMeteors();
    }
    temp_r0_688 = this->unkD0;
    if ((u32) temp_r0_688 <= 6U) {
        switch (temp_r0_688) {
            return;
        case 1:
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unkE8 == 0.0f) {
                this->unkD0 = 2;
                this->unkE8 = 0.25f;
                arg_sp2A8 = 500.0f;
                arg_sp2A0 = 500.0f;
                arg_sp2A4 = -1000.0f;
                arg_sp648 = (f64) arg_sp2A8;
                arg_sp640 = (f64) arg_sp2A0;
                temp_r3_725 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f64, f32), 0xC)(gb.unk0, (f64) arg_sp2A0, 500.0f), void **, 8);
                arg_sp650 = M2C_FIELD(temp_r3_725, f64 *, 0x30);
                arg_sp658 = M2C_FIELD(temp_r3_725, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp298 = (f32) arg_sp658 + (f32) arg_sp648;
                arg_sp288 = 500.0f;
                arg_sp710 = arg_sp290;
                arg_sp718 = (f64) arg_sp298;
                arg_sp280 = -500.0f;
                arg_sp284 = -1000.0f;
                arg_sp628 = (f64) arg_sp288;
                arg_sp620 = (f64) arg_sp280;
                temp_r3_759 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f64, f32, f64, f64), 0xC)(gb.unk0, (f64) arg_sp280, -500.0f, (f64) arg_sp298, arg_sp290), void **, 8);
                arg_sp630 = M2C_FIELD(temp_r3_759, f64 *, 0x30);
                arg_sp638 = M2C_FIELD(temp_r3_759, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp278 = (f32) arg_sp638 + (f32) arg_sp628;
                arg_sp268 = -500.0f;
                arg_sp700 = arg_sp270;
                arg_sp708 = (f64) arg_sp278;
                arg_sp260 = 500.0f;
                arg_sp264 = -1000.0f;
                arg_sp608 = (f64) arg_sp268;
                arg_sp600 = (f64) arg_sp260;
                temp_r3_793 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f64, f32, f64, f64), 0xC)(gb.unk0, (f64) arg_sp260, 500.0f, (f64) arg_sp278, arg_sp270), void **, 8);
                arg_sp610 = M2C_FIELD(temp_r3_793, f64 *, 0x30);
                arg_sp618 = M2C_FIELD(temp_r3_793, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp248 = -500.0f;
                arg_sp258 = (f32) arg_sp618 + (f32) arg_sp608;
                arg_sp6F0 = arg_sp250;
                arg_sp6F8 = (f64) arg_sp258;
                arg_sp240 = -500.0f;
                arg_sp244 = -1000.0f;
                arg_sp5E8 = (f64) arg_sp248;
                arg_sp5E0 = (f64) arg_sp240;
                temp_r3_826 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f64, f32, f64, f64), 0xC)(gb.unk0, (f64) arg_sp240, -500.0f, (f64) arg_sp258, arg_sp250), void **, 8);
                arg_sp5F0 = M2C_FIELD(temp_r3_826, f64 *, 0x30);
                arg_sp5F8 = M2C_FIELD(temp_r3_826, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp6E0 = arg_sp230;
                arg_sp238 = (f32) arg_sp5F8 + (f32) arg_sp5E8;
                arg_sp6E8 = (f64) arg_sp238;
                temp_r29_845 = (KDSound_GetSoundEventVol(GS_SpyroFuryMissile1) >> 1U) & 0x7F;
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp710, 0U, temp_r29_845, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp700, 0U, temp_r29_845, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp6F0, 0U, temp_r29_845, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp6E0, 0U, temp_r29_845, 0.0f, 0U);
                this->unkD8 = 0.05f;
                this->unkDC = 1.0f;
                this->unkE0 = 0.05f;
                return;
            }
            break;
        case 2:
            MKVector(3.0f, 5.0f, 3.0f);
            MKVector(6.0f, 0.0f, 6.0f);
            arg_sp5A0.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp5B0 = arg_sp40;
            arg_sp48 = this->unkE0 + arg_sp5A8;
            arg_sp5B8 = (f64) arg_sp48;
            MKVector(0.0f, 0.0f, 0.0f);
            Min(*((MKVector3 *) &arg_spA0), *((MKVector3 *) &arg_sp5B0));
            Max(*((MKVector3 *) &arg_sp5D0), *((MKVector3 *) &arg_spA0));
            M2C_FIELD(this, f32 *, 0xD8) = arg_sp5D0;
            M2C_FIELD(this, f32 *, 0xE0) = arg_sp5D8;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unkE8 == 0.0f) {
                this->unkE8 = 1.5f;
                temp_r4_935 = this->unkD0;
                arg_sp228 = -1000.0f;
                this->unkD0 = temp_r4_935 + 1;
                arg_sp220 = 0.0f;
                arg_sp224 = -1000.0f;
                arg_sp568 = (f64) arg_sp228;
                arg_sp560 = (f64) arg_sp220;
                temp_r3_950 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, s32, f64), 0xC)(gb.unk0, temp_r4_935, (f64) arg_sp220), void **, 8);
                arg_sp570 = M2C_FIELD(temp_r3_950, f64 *, 0x30);
                arg_sp578 = M2C_FIELD(temp_r3_950, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp218 = (f32) arg_sp578 + (f32) arg_sp568;
                arg_sp208 = 1000.0f;
                arg_sp6D0 = arg_sp210;
                arg_sp6D8 = (f64) arg_sp218;
                arg_sp200 = 0.0f;
                arg_sp204 = -1000.0f;
                arg_sp548 = (f64) arg_sp208;
                arg_sp540 = (f64) arg_sp200;
                temp_r3_984 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f64, f32, f64, f64), 0xC)(gb.unk0, (f64) arg_sp200, 0.0f, (f64) arg_sp218, arg_sp210), void **, 8);
                arg_sp550 = M2C_FIELD(temp_r3_984, f64 *, 0x30);
                arg_sp558 = M2C_FIELD(temp_r3_984, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp6C0 = arg_sp1F0;
                arg_sp1F8 = (f32) arg_sp558 + (f32) arg_sp548;
                arg_sp6C8 = (f64) arg_sp1F8;
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp6D0, 0U, -1, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp6C0, 0U, -1, 0.0f, 0U);
                return;
            }
            break;
        case 3:
            MKVector(5.0f, 50.0f, 5.0f);
            MKVector(-1.0f, 4.0f, -1.0f);
            arg_sp500.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp510 = arg_sp30;
            arg_sp38 = this->unkE0 + arg_sp508;
            arg_sp518 = (f64) arg_sp38;
            MKVector(0.1f, 0.0f, 0.1f);
            Min(*((MKVector3 *) &arg_sp90), *((MKVector3 *) &arg_sp510));
            Max(*((MKVector3 *) &arg_sp530), *((MKVector3 *) &arg_sp90));
            M2C_FIELD(this, f32 *, 0xD8) = arg_sp530;
            M2C_FIELD(this, f32 *, 0xE0) = arg_sp538;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unkE8 == 0.0f) {
                this->unkE8 = 3.0f;
                temp_r4_1071 = this->unkD0;
                arg_sp1E8 = 0.0f;
                this->unkD0 = temp_r4_1071 + 1;
                arg_sp1E0 = -1000.0f;
                arg_sp1E4 = -1000.0f;
                arg_sp4C8 = (f64) arg_sp1E8;
                arg_sp4C0 = (f64) arg_sp1E0;
                temp_r3_1086 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, s32, f64), 0xC)(gb.unk0, temp_r4_1071, (f64) arg_sp1E0), void **, 8);
                arg_sp4D0 = M2C_FIELD(temp_r3_1086, f64 *, 0x30);
                arg_sp4D8 = M2C_FIELD(temp_r3_1086, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp1D8 = (f32) arg_sp4D8 + (f32) arg_sp4C8;
                arg_sp1C8 = 0.0f;
                arg_sp6B0 = arg_sp1D0;
                arg_sp6B8 = (f64) arg_sp1D8;
                arg_sp1C0 = 1000.0f;
                arg_sp1C4 = -1000.0f;
                arg_sp4A8 = (f64) arg_sp1C8;
                arg_sp4A0 = (f64) arg_sp1C0;
                temp_r3_1120 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f64, f32, f64, f64), 0xC)(gb.unk0, (f64) arg_sp1C0, 1000.0f, (f64) arg_sp1D8, arg_sp1D0), void **, 8);
                arg_sp4B0 = M2C_FIELD(temp_r3_1120, f64 *, 0x30);
                arg_sp4B8 = M2C_FIELD(temp_r3_1120, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp6A0 = arg_sp1B0;
                arg_sp1B8 = (f32) arg_sp4B8 + (f32) arg_sp4A8;
                arg_sp6A8 = (f64) arg_sp1B8;
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp6B0, 0U, -1, 0.0f, 0U);
                KDSound_Play3d(GS_SpyroFuryMissile1, (MKVector3 *) &arg_sp6A0, 0U, -1, 0.0f, 0U);
                gb.GetSpyro();
                this->unk158 = ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(0.0f);
                return;
            }
            break;
        case 4:
            MKVector(5.0f, 50.0f, 5.0f);
            MKVector(-2.0f, -3.0f, -2.0f);
            arg_sp460.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp470 = arg_sp20;
            arg_sp28 = this->unkE0 + arg_sp468;
            arg_sp478 = (f64) arg_sp28;
            MKVector(0.05f, 0.0f, 0.05f);
            Min(*((MKVector3 *) &arg_sp80), *((MKVector3 *) &arg_sp470));
            Max(*((MKVector3 *) &arg_sp490), *((MKVector3 *) &arg_sp80));
            M2C_FIELD(this, f32 *, 0xD8) = arg_sp490;
            M2C_FIELD(this, f32 *, 0xE0) = arg_sp498;
            SpawnMeteor();
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unkE8 == 0.0f) {
                this->unkE8 = 0.6f;
                this->unkD0 += 1;
                M2C_STRUCT_COPY((s32) &arg_sp71C + 4, (s32) (&identity - 4) + 4, 0x40);
                arg_sp1A8 = 1.0f;
                arg_sp198 = 0.0f;
                arg_sp1A0 = 0.0f;
                arg_sp1A4 = 0.0f;
                arg_sp190 = 0.0f;
                arg_sp194 = -1.0f;
                arg_sp690 = (f64) arg_sp1A0;
                arg_sp698 = (f64) arg_sp1A8;
                arg_sp430 = (f64) arg_sp190;
                arg_sp438 = (f64) arg_sp198;
                KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp720, *((MKVector3 *) &arg_sp430), (MKVector3 *) &arg_sp690);
                arg_sp78 = 2.0f;
                arg_sp70 = 2.0f;
                arg_sp74 = 2.0f;
                arg_sp428 = (f64) arg_sp78;
                arg_sp420 = (f64) arg_sp70;
                arg_sp720.Scale3x3((Matrix *) &arg_sp720, *((MKVector3 *) &arg_sp420));
                MKVector(0.0f, 300.0f, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp410 = arg_sp60;
                arg_sp68 = this->unk90.unk38 + arg_sp408;
                arg_sp418 = (f64) arg_sp68;
                arg_sp750 = (f32) arg_sp410;
                arg_sp754 = arg_sp414;
                arg_sp758 = (f32) arg_sp418;
                arg_sp75C = 1.0f;
                gb.unk1C0.StartWarp((Matrix *) &arg_sp720);
                this->unkF0.unk50 = 0;
                temp_f2_1297 = M2C_FIELD(this, f64 *, 0xC0);
                arg_sp680 = temp_f2_1297;
                arg_sp688 = (f64) M2C_FIELD(this, f32 *, 0xC8);
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unkF0, 0, 0, &arg_sp680, 1, 3000.0f, temp_f2_1297);
                gb.GetSpyro();
                ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(M2C_BITWISE(f32, this->unk158));
                return;
            }
            break;
        case 5:
            MKVector(500.0f, 500.0f, 500.0f);
            MKVector(20.0f, -10.0f, 20.0f);
            arg_sp3C0.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp3D0 = arg_sp10;
            arg_sp18 = this->unkE0 + arg_sp3C8;
            arg_sp3D8 = (f64) arg_sp18;
            MKVector(0.1f, 0.0f, 0.1f);
            Min(*((MKVector3 *) &arg_sp50), *((MKVector3 *) &arg_sp3D0));
            Max(*((MKVector3 *) &arg_sp3F0), *((MKVector3 *) &arg_sp50));
            M2C_FIELD(this, f32 *, 0xD8) = arg_sp3F0;
            M2C_FIELD(this, f32 *, 0xE0) = arg_sp3F8;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unkE8 == 0.0f) {
                this->unkD0 = 6;
                var_r28_1369 = 0;
                this->unkE8 = 1.4f;
                do {
                    temp_f22_1384 = 6.2831855f * ((f32) var_r28_1369 / 10.0f);
                    temp_f23_1387 = -_table_sinf(1.5707964f + temp_f22_1384);
                    arg_sp180 = _table_sinf(temp_f22_1384);
                    arg_sp184 = 0.0f;
                    arg_sp188 = temp_f23_1387;
                    arg_sp158 = 0.0f;
                    arg_sp150 = 0.0f;
                    arg_sp154 = 200.0f;
                    arg_sp670 = (f64) arg_sp180;
                    arg_sp678 = (f64) arg_sp188;
                    arg_sp350 = (f64) arg_sp150;
                    arg_sp358 = (f64) arg_sp158;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                    arg_sp360 = arg_sp170;
                    arg_sp178 = (f32) arg_sp678 * 200.0f;
                    arg_sp368 = (f64) arg_sp178;
                    gb.GetSpyro();
                    temp_r3_1416 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 8);
                    arg_sp370 = M2C_FIELD(temp_r3_1416, f64 *, 0x30);
                    arg_sp378 = M2C_FIELD(temp_r3_1416, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp380 = arg_sp160;
                    arg_sp168 = (f32) arg_sp378 + (f32) arg_sp368;
                    arg_sp388 = (f64) arg_sp168;
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp390 = arg_sp140;
                    arg_sp148 = (f32) arg_sp388 + (f32) arg_sp358;
                    arg_sp398 = (f64) arg_sp148;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                    temp_f1_1457 = (f32) arg_sp678 * MKRand_Float(&gViewSeed, 3000.0f, 3500.0f);
                    arg_sp340 = arg_sp130;
                    arg_sp138 = temp_f1_1457;
                    arg_sp348 = (f64) arg_sp138;
                    ((ClusterBomb *) (M2C_BITWISE(ClusterBomb *, this->unk15C)))->SpawnClusterBomb(*((MKVector3 *) &arg_sp390), *((MKVector3 *) &arg_sp340));
                    var_r28_1369 += 1;
                } while (var_r28_1369 < 0xA);
                var_r28_1474 = 0;
                do {
                    arg_sp128 = -1.0f;
                    arg_sp118 = 1.0f;
                    arg_sp120 = -1.0f;
                    arg_sp124 = 0.0f;
                    arg_sp110 = 1.0f;
                    arg_sp114 = 0.0f;
                    arg_sp300 = (f64) arg_sp120;
                    arg_sp308 = (f64) arg_sp128;
                    arg_sp2F0 = (f64) arg_sp110;
                    arg_sp2F8 = (f64) arg_sp118;
                    KDRand_Vector(*((MKVector3 *) &arg_sp310), *((MKVector3 *) &arg_sp300));
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                    arg_sp320 = arg_sp100;
                    arg_sp108 = arg_sp318 * 1500.0f;
                    arg_sp328 = (f64) arg_sp108;
                    gb.GetSpyro();
                    temp_r3_1508 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 8);
                    arg_sp330 = M2C_FIELD(temp_r3_1508, f64 *, 0x30);
                    arg_sp338 = M2C_FIELD(temp_r3_1508, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_spC8 = 0.0f;
                    arg_spC0 = 0.0f;
                    arg_spC4 = -500.0f;
                    arg_spF8 = (f32) arg_sp338 + (f32) arg_sp328;
                    arg_sp660 = arg_spF0;
                    arg_sp2B0 = (f64) arg_spC0;
                    arg_sp668 = (f64) arg_spF8;
                    arg_sp2B8 = (f64) arg_spC8;
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
                    arg_spE8 = 0.0f;
                    arg_spE0 = 0.0f;
                    arg_spE4 = 200.0f;
                    arg_spB8 = (f32) arg_sp668 + (f32) arg_sp2B8;
                    arg_sp2D0 = (f64) arg_spE0;
                    arg_sp2C0 = arg_spB0;
                    arg_sp2C8 = (f64) arg_spB8;
                    arg_sp2D8 = (f64) arg_spE8;
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
                    arg_sp2E0 = arg_spD0;
                    arg_spD8 = (f32) arg_sp668 + (f32) arg_sp2D8;
                    arg_sp2E8 = (f64) arg_spD8;
                    if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp2E0), *((MKVector3 *) &arg_sp2C0), (MKCollisionResult *) &arg_sp760, (MKCollisionMode) 7, 0x0C000000) != 0) {
                        arg_sp660 = arg_sp760;
                        arg_sp668 = arg_sp768;
                    }
                    this->unk160.Emit(*((MKVector3 *) &arg_sp660), MKRand_Float(&gViewSeed, 3.0f, 5.0f), 0U);
                    var_r28_1474 += 1;
                } while (var_r28_1474 < 0xA);
                return;
            }
            break;
        case 6:
            var_f0_1587 = this->unkE8;
            if (var_f0_1587 < 1.4f) {

            } else {
                var_f0_1587 = 1.4f;
            }
            if (var_f0_1587 > 0.0f) {

            } else {
                var_f0_1587 = 0.0f;
            }
            this->unkE8 = var_f0_1587;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unkE8 == 0.0f) {
                this->unkD0 = 0;
                gb.unk381 = 0;
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void FuryFXFire2::Init() {
    MKHeap *temp_r3_1653;
    f32 temp_r3_1675;
    f32 temp_r4_1681;
    f32 var_r5_1669;
    s32 var_ctr_1673;
    void *var_r3_1660;

    FuryFX::Init();
    SetDefaults();
    temp_r3_1653 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1653 != NULL) {
        var_r3_1660 = ((MKHeap *) (temp_r3_1653->Current()))->Alloc(0x698, NULL, 0);
    } else {
        var_r3_1660 = malloc(0x698);
    }
    this->unk14C = M2C_BITWISE(f32, var_r3_1660);
    var_r5_1669 = this->unk14C;
    this->unk14C = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r5_1669) + 0x640));
    M2C_FIELD(var_r5_1669, s32 *, 0x640) = 0;
    var_ctr_1673 = 0x14;
    do {
        temp_r3_1675 = this->unk14C;
        this->unk14C = M2C_BITWISE(f32, (M2C_BITWISE(void *, temp_r3_1675) + 4));
        M2C_FIELD(M2C_BITWISE(void *, temp_r3_1675), f32 *, 4) = var_r5_1669;
        var_r5_1669 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r5_1669) + 0x50));
        var_ctr_1673 -= 1;
    } while (var_ctr_1673 != 0);
    temp_r4_1681 = this->unk14C;
    this->unk14C = M2C_BITWISE(f32, (M2C_BITWISE(void *, temp_r4_1681) + 4));
    M2C_FIELD(M2C_BITWISE(void *, temp_r4_1681), s32 *, 4) = 0;
    this->unk148 = MKModel_Create("P0002_LavaCannonBall", NULL, 2, NULL);
    gMK->CreatePropDeferred("Explosion4", (MKProp **) &this->unk150);
    gMK->CreatePropDeferred("ClusterBomb", (MKProp **) &this->unk15C);
    this->unk160.Init(0xA);
    this->unk154 = (Explosion4 *)-1;
}
#endif

void FuryFXFire2_cpp::__sinit() {
    f32 temp_f0_1752;
    f64 temp_f1_1733;
    f64 temp_f1_1741;
    f64 temp_f3_1721;
    f64 temp_f4_1730;
    f64 temp_f4_1738;
    f64 temp_f8_1723;

    temp_f3_1721 = __frsqrte(2014000.0);
    temp_f8_1723 = __frsqrte(380000.0);
    temp_f4_1730 = 0.5 * temp_f3_1721 * -((2014000.0 * (temp_f3_1721 * temp_f3_1721)) - 3.0);
    temp_f1_1733 = 0.5 * temp_f8_1723 * -((380000.0 * (temp_f8_1723 * temp_f8_1723)) - 3.0);
    temp_f4_1738 = 0.5 * temp_f4_1730 * -((2014000.0 * (temp_f4_1730 * temp_f4_1730)) - 3.0);
    temp_f1_1741 = 0.5 * temp_f1_1733 * -((380000.0 * (temp_f1_1733 * temp_f1_1733)) - 3.0);
    temp_f0_1752 = (f32) (380000.0 * (0.5 * temp_f1_1741 * -((380000.0 * (temp_f1_1741 * temp_f1_1741)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1738 * -((2014000.0 * (temp_f4_1738 * temp_f4_1738)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1752;
}
