#include "spyro/source/CynderBreathFX.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern s32 GS_CynderBreathHitSpyro;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPtrList<MKProp> *pHitList;
static BreathHitMessage streamHitMsg;

void CynderBreathFX::SetHitList(MKPtrList<MKProp> *arg0) {
    pHitList = arg0;
}

void CynderBreathFX::End() {
    this->unkB0.unk108 = 0;
    ((ScreenWobbleFX *) (&gb + 0xB8))->EnableSpeedEffect(0U, 1.0f, 1.0f);
}

#if 0 // DRAFT: illegal explicit conversion from 'double *' to
void CynderBreathFX::UpdateBeamSpeedWay(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;

    sp48 = M2C_FIELD(&arg2, f64 *, 0);
    sp50 = M2C_FIELD(&arg2, f64 *, 8);
    sp58 = M2C_FIELD(&arg1, f64 *, 0);
    sp60 = M2C_FIELD(&arg1, f64 *, 8);
    sp68 = M2C_FIELD(&arg0, f64 *, 0);
    sp70 = M2C_FIELD(&arg0, f64 *, 8);
    this->unkB0.SetBeamPositions((MKVector3) &sp68, (MKVector3) &sp58, (MKVector3) &sp48);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp28 = sp18;
    sp20 = arg1.unk8 - arg0.unk8;
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp38 = sp8;
    sp10 = (f32) sp30 * 2.0f;
    sp40 = (f64) sp10;
    CreateCollisionTest(arg0, *((MKVector3 *) &sp38), this->unk1C8, 0x08000000U, CynderBreathFXHitCallback);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void CynderBreathFX::UpdateBeam(MKVector3 arg0, MKVector3 arg1, MKVector3 arg2) {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;

    sp48 = M2C_FIELD(arg2, f64 *, 0);
    sp50 = M2C_FIELD(arg2, f64 *, 8);
    sp58 = M2C_FIELD(arg1, f64 *, 0);
    sp60 = M2C_FIELD(arg1, f64 *, 8);
    sp68 = M2C_FIELD(arg0, f64 *, 0);
    sp70 = M2C_FIELD(arg0, f64 *, 8);
    this->unkB0.UpdateBeam((MKVector3) &sp68, (MKVector3) &sp58, (MKVector3) &sp48);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp28 = sp18;
    sp20 = (f32) M2C_FIELD(arg1, f64 *, 8) - (f32) M2C_FIELD(arg0, f64 *, 8);
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp38 = sp8;
    sp10 = (f32) sp30 * 2.0f;
    sp40 = (f64) sp10;
    CreateCollisionTest(*((MKVector3 *) arg0), *((MKVector3 *) &sp38), this->unk1C8, 0x08000000U, CynderBreathFXHitCallback);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKProp *' to
s32 CynderBreathFX::Trigger(MKProp *arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, const float &arg4, int arg5, float arg6) {
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
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    s32 sp8;
    f64 temp_f0_245;
    f64 temp_f1_243;

    this->unk1C8 = M2C_BITWISE(f32, arg0);
    this->unkAC = arg5;
    this->unk1CC = arg6;
    sp8 = -1;
    streamHitMsg.Init(M2C_BITWISE(MKProp *, this->unk1C8), 5, 0, 0, 0, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f1_243 = M2C_FIELD(&arg1, f64 *, 0);
    temp_f0_245 = M2C_FIELD(&arg1, f64 *, 8);
    sp90 = M2C_FIELD(&arg2, f64 *, 0);
    sp98 = M2C_FIELD(&arg2, f64 *, 8);
    spA0 = temp_f1_243;
    spA8 = temp_f0_245;
    spB0 = temp_f1_243;
    spB8 = temp_f0_245;
    this->unkB0.ResetBeamNodes((MKVector3) &spB0, (MKVector3) &spA0, (MKVector3) &sp90);
    this->unkB0.unk100 = 1.5f;
    this->unkB0.unk104 = 0.5f;
    this->unkB0.unk10C = 0.5f;
    this->unkB0.unk110 = 1.5f;
    this->unkB0.unk108 = 1;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp50 = sp10;
    sp18 = arg2.unk8 * &arg4;
    sp58 = (f64) sp18;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    sp60 = sp40;
    sp48 = (f32) sp58 * 1500.0f;
    sp68 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    sp70 = sp30;
    sp38 = (f32) sp68 * 1.5f;
    sp78 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp80 = sp20;
    sp28 = (f32) sp78 + arg3.unk8;
    sp88 = (f64) sp28;
    CreateCollisionTest(arg1, *((MKVector3 *) &sp80), this->unk1C8, 0x08000000U, CynderBreathFXHitCallback);
    if ((MKPtrList<MKProp> *) pHitList != NULL) {
loop_3:
        if ((void *) *pHitList->unk0 != NULL) {
            pHitList->unk0 += 4;
            goto loop_3;
        }
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void CynderBreathFXHitCallback(BreathFXCollisionSphereTest *arg0) {
    f64 temp_f1_390;
    void **temp_r3_408;
    void **var_r3_361;
    void *temp_r0_355;
    void *temp_r3_397;
    void *temp_r5_370;

    if (arg0 != NULL) {
        temp_r0_355 = arg0->unk3C;
        if (temp_r0_355 != NULL) {
            if ((MKPtrList<MKProp> *) pHitList != NULL) {
                var_r3_361 = pHitList->unk0;
loop_7:
                temp_r5_370 = *var_r3_361;
                if (temp_r5_370 == NULL) {
                    var_r3_361 = NULL;
                } else if (temp_r5_370 == temp_r0_355) {

                } else {
                    var_r3_361 += 4;
                    goto loop_7;
                }
                if (var_r3_361 == NULL) {
                    goto block_10;
                }
            } else {
block_10:
                if (((MKPtrList<MKProp> *) pHitList != NULL) && ((u32) M2C_FIELD(pHitList->unk0, u32 *, -4) != 0U)) {
                    streamHitMsg.unk50 = 0;
                    temp_f1_390 = arg0->unk0;
                    M2C_FIELD(&streamHitMsg, f64 *, 0x10) = temp_f1_390;
                    M2C_FIELD(&streamHitMsg, f64 *, 0x18) = (f64) arg0->unk8;
                    streamHitMsg.unk30 = (MKCollisionInfo *) arg0->unk40;
                    streamHitMsg.unk4C = GS_CynderBreathHitSpyro;
                    temp_r3_397 = arg0->unk3C;
                    M2C_FIELD(M2C_FIELD(temp_r3_397, void **, 0x44), M2C_UNK (**)(void *, BreathHitMessage *, f64), 0x2C)(temp_r3_397, &streamHitMsg, temp_f1_390);
                    if ((u8) streamHitMsg.unk50 != 0) {
                        temp_r3_408 = pHitList->unk0 - 4;
                        pHitList->unk0 = temp_r3_408;
                        *temp_r3_408 = arg0->unk3C;
                    }
                }
            }
        }
    }
}
#endif

void CynderBreathFX::Draw() {
    this->unkB0.Draw();
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void CynderBreathFX::BreathFire() {
    void *temp_r29_518;
    void *temp_r29_598;
    void *temp_r30_470;
    void *temp_r3_503;
    void *temp_r3_515;
    void *temp_r3_583;
    void *temp_r3_595;
    MKModel_GetRefPointMatrix(M2C_FIELD(this->unk1C8, MKModel **, 4), this->unkAC, (Matrix *) &arg_sp160, 1U);
    arg_sp50 = -arg_sp180;
    arg_sp54 = -arg_sp184;
    arg_sp58 = -arg_sp188;
    arg_sp150 = (f64) arg_sp50;
    arg_sp158 = (f64) arg_sp58;
    arg_sp140 = arg_sp190;
    arg_sp148 = arg_sp198;
    temp_r30_470 = checked_cast<CynderBreathFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    arg_sp130 = arg_sp140;
    arg_sp138 = arg_sp148;
    MKVector(1.0f, 1.0f, 1.0f);
    MKVector(-1.0f, -1.0f, -1.0f);
    KDRand_Vector(*((MKVector3 *) &arg_spE0), *((MKVector3 *) &arg_spD0));
    arg_spF0.operator*(500.0f);
    arg_sp100.operator*(3500.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_r3_503 = M2C_FIELD(temp_r30_470, void **, 0x70);
    arg_sp110 = arg_sp40;
    arg_sp48 = arg_sp108 + arg_spF8;
    arg_sp120 = arg_sp40;
    arg_sp118 = (f64) arg_sp48;
    arg_sp128 = (f64) arg_sp48;
    temp_r3_515 = M2C_FIELD(M2C_FIELD(temp_r3_503, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_503, arg_sp40);
    if (temp_r3_515 != NULL) {
        temp_r29_518 = M2C_FIELD(temp_r3_515, void **, 0x2C);
        M2C_FIELD(temp_r3_515, f64 *, 0) = arg_sp130;
        M2C_FIELD(temp_r3_515, f64 *, 8) = arg_sp138;
        M2C_FIELD(temp_r3_515, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_515, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_515, f32 *, 0x24) = (f32) (2.0f * (3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f)));
        M2C_FIELD(temp_r29_518, f64 *, 0) = arg_sp120;
        M2C_FIELD(temp_r29_518, f64 *, 8) = arg_sp128;
        M2C_FIELD(temp_r29_518, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        M2C_FIELD(temp_r29_518, f32 *, 0x10) = 0.0f;
        M2C_FIELD(temp_r29_518, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r30_470, void **, 0x70), f32 *, 0xF4);
    }
    arg_sp20 = arg_sp140;
    arg_sp28 = arg_sp148;
    MKVector(1.0f, 1.0f, 1.0f);
    MKVector(-1.0f, -1.0f, -1.0f);
    KDRand_Vector(*((MKVector3 *) &arg_sp80), *((MKVector3 *) &arg_sp70));
    arg_sp90.operator*(500.0f);
    arg_spA0.operator*(3500.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_r3_583 = M2C_FIELD(temp_r30_470, void **, 0x74);
    arg_spB0 = arg_sp30;
    arg_sp38 = arg_spA8 + arg_sp98;
    arg_sp10 = arg_sp30;
    arg_spB8 = (f64) arg_sp38;
    arg_sp18 = (f64) arg_sp38;
    temp_r3_595 = M2C_FIELD(M2C_FIELD(temp_r3_583, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_583, arg_sp30);
    if (temp_r3_595 != NULL) {
        temp_r29_598 = M2C_FIELD(temp_r3_595, void **, 0x2C);
        M2C_FIELD(temp_r3_595, f64 *, 0) = arg_sp20;
        M2C_FIELD(temp_r3_595, f64 *, 8) = arg_sp28;
        M2C_FIELD(temp_r3_595, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_595, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_595, f32 *, 0x24) = (f32) (2.0f * (3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f)));
        M2C_FIELD(temp_r29_598, f64 *, 0) = arg_sp10;
        M2C_FIELD(temp_r29_598, f64 *, 8) = arg_sp18;
        M2C_FIELD(temp_r29_598, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        M2C_FIELD(temp_r29_598, f32 *, 0x10) = 0.0f;
        M2C_FIELD(temp_r29_598, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r30_470, void **, 0x74), f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void CynderBreathFX::Update() {
    s8 spA0;
    f64 sp98;
    f64 sp90;
    s32 sp8C;
    s32 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f29_717;
    f32 temp_f30_693;
    f32 temp_f30_712;
    void *temp_r3_665;
    void *temp_r4_664;

    BaseBreathFX::Update();
    if ((u8) this->unkB0.unk108 != 0) {
        BreathFire();
        temp_r4_664 = M2C_FIELD(this->unk1C8, void **, 8);
        temp_r3_665 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        sp58 = M2C_FIELD(temp_r4_664, f64 *, 0x30);
        sp68 = M2C_FIELD(temp_r3_665, f64 *, 0x30);
        sp60 = M2C_FIELD(temp_r4_664, f64 *, 0x38);
        sp70 = M2C_FIELD(temp_r3_665, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp78 = sp18;
        sp20 = (f32) sp70 - (f32) sp60;
        sp80 = (f64) sp20;
        temp_f30_693 = ((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + (unksp7C * unksp7C));
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f30_693 == 3.6e7f) {
            ((ScreenWobbleFX *) (&gb + 0xB8))->EnableSpeedEffect(1U, 0.25f, 1.0f);
            sp8C = 0;
            temp_f30_712 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f29_717 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f29_717, temp_f30_712);
            sp38.operator*(M2C_BITWISE(f32, this->unk1CC));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp88 = 0x417;
            sp90 = sp8;
            sp10 = sp38.unk8 * (1.0f - (temp_f30_693 / 3.6e7f));
            spA0 = 1;
            sp98 = (f64) sp10;
            sp48 = sp8;
            sp50 = (f64) sp10;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp88, sp8);
        }
    }
    this->unkB0.Update();
}
#endif

void CynderBreathFX::Resolve() {
    MKProp::Resolve();
}

void CynderBreathFX::Deinit() {
    this->unkB0.Deinit();
    BaseBreathFX::Deinit();
}

void CynderBreathFX::Init() {
    BaseBreathFX::Init();
    this->unkB0.Init("fx_357", "fx_CynderBreath1Glow", "fx_CynderBreath2", "fx_CynderBreath2Glow");
    this->unk1C8 = 100.0f;
    this->unkAC = 0xFFFF;
    pHitList = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'KDEnvParticleSystem *' to
void CynderBreathFXDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk70 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("CynderFlamePS"));
    this->unk74 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("CynderFlameSubPS"));
}
#endif

void CynderBreathFX_cpp::__sinit() {
    streamHitMsg.unk4 = 0;
}
