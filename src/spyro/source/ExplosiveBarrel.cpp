#include "spyro/source/ExplosiveBarrel.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BurningWick.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/ExplosiveBarrelPath.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingBurningBits.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDVolume.h"
#include "spyro/source/KDWaterVolume.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_TNTBarrelExplode;
extern s32 GS_TNTBarrelFuseLP;
extern void **gMK;
extern s32 gViewSeed;
extern GameGlobals gb;
static u8 lit_651 = 1;

static u8 lit_750 = 1;

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'ExplosiveBarrel::States'
void ExplosiveBarrel::Ignite(float arg0) {
    f32 sp8;

    sp8 = arg0;
    this->unk1BA = 1;
    SetState((ExplosiveBarrel::States) 1);
    this->unk1AC->Burn(lit_750, sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'ExplosiveBarrel::States'
void ExplosiveBarrel::Explode() {
    ExplosiveBarrel *spC;
    s32 sp8;
    BurningWick *temp_r3_103;
    s32 temp_r0_92;

    temp_r0_92 = this->unk1B4;
    if ((temp_r0_92 == 0) || (temp_r0_92 == 1) || (temp_r0_92 == 2)) {
        SetState((ExplosiveBarrel::States) 3);
        temp_r3_103 = this->unk1AC;
        temp_r3_103->Disable();
        Shatter(0, 0, -1, 0, 1, 0);
        TriggerShatterFX();
        this->unk15C.Send(NULL);
        spC = NULL;
        sp8 = 0x162;
        spC = this;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32), 0x94)(gMK, &sp8, 0, 0, ((u8 *) this->unk8) + 0x30, 1, 500.0f);
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'ExplosiveBarrel::States'
void ExplosiveBarrel::SetState(ExplosiveBarrel::States arg1) {
    this->unk1B4 = (s32) arg1;
}
#endif

s32 ExplosiveBarrel::GetState() {
    return this->unk1B4;
}

void ExplosiveBarrel::SetActive(bool arg0) {
    BurningWick *temp_r3_172;
    BurningWick *temp_r3_179;

    this->unk1B8 = arg0;
    if (arg0 != 0) {
        temp_r3_172 = this->unk1AC;
        temp_r3_172->Enable();
        return;
    }
    temp_r3_179 = this->unk1AC;
    temp_r3_179->Disable();
}

u8 ExplosiveBarrel::IsActive() {
    return this->unk1B8;
}

#if 0 // DRAFT: ')' expected
void ExplosiveBarrel::TriggerShatterFX() {
    f64 sp120;                                      /* compiler-managed */
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    f32 temp_f26_258;
    f32 temp_f26_295;
    f32 temp_f26_351;
    f32 temp_f27_263;
    f32 temp_f27_300;
    f32 temp_f27_356;
    f32 temp_f29_393;
    f32 temp_f31_388;
    f64 temp_f0_274;
    f64 temp_f0_314;
    f64 temp_f0_367;
    f64 temp_f0_407;
    s32 var_r29_247;
    s32 var_r29_340;
    void *temp_r3_225;
    void *temp_r3_231;
    void *temp_r4_249;
    void *temp_r4_342;

    this->unk1BA = 0;
    M2C_FIELD(M2C_FIELD(checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x16C), s32 *, 0x88) = (s32) GS_TNTBarrelExplode;
    temp_r3_225 = this->unk8;
    spD8 = M2C_FIELD(temp_r3_225, f64 *, 0x30);
    spE0 = M2C_FIELD(temp_r3_225, f64 *, 0x38);
    temp_r3_231 = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1;
    ((Explosion4 *) (M2C_FIELD(temp_r3_231, Explosion4 **, 0x16C)))->Trigger(*((MKVector3 *) &spD8), this->unk1B0, 1U, (MKProp *) this, 0xF, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    var_r29_247 = 0;
    do {
        temp_r4_249 = this->unk8;
        sp118 = M2C_FIELD(temp_r4_249, f64 *, 0x30);
        sp120 = M2C_FIELD(temp_r4_249, f64 *, 0x38);
        temp_f26_258 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f27_263 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        spB8 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f27_263, temp_f26_258);
        temp_f0_274 = spB8 * 5.53552857e-315;
        sp28 = temp_f0_274;
        spC8 = temp_f0_274;
        sp30 = spB8.unk8 * 100.0f;
        spD0 = (f64) sp30;
        sp118 += temp_f0_274;
        sp120 = (f32) sp120 + (f32) spD0;
        temp_f26_295 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f27_300 = MKRand_Float((int *) &gViewSeed, 0.0f, 3.0f);
        sp68 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp6C = temp_f27_300;
        sp70 = temp_f26_295;
        spA8 = (f64) sp68;
        spB0 = (f64) sp70;
        temp_f0_314 = spA8 * 5.49408334e-315;
        sp58 = temp_f0_314;
        sp108 = temp_f0_314;
        sp60 = (f32) spB0 * 50.0f;
        sp110 = (f64) sp60;
        sp14 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
        gb.EmitDust(*((MKVector3 *) &sp118), *((MKVector3 *) &sp108), sp14, 0.0f);
        var_r29_247 += 1;
    } while (var_r29_247 < 4);
    var_r29_340 = 0;
    do {
        temp_r4_342 = this->unk8;
        spF8 = M2C_FIELD(temp_r4_342, f64 *, 0x30);
        sp100 = M2C_FIELD(temp_r4_342, f64 *, 0x38);
        temp_f26_351 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f27_356 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        sp88 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f27_356, temp_f26_351);
        temp_f0_367 = sp88 * 5.53552857e-315;
        sp18 = temp_f0_367;
        sp98 = temp_f0_367;
        sp20 = sp88.unk8 * 100.0f;
        spA0 = (f64) sp20;
        spF8 += temp_f0_367;
        sp100 = (f32) sp100 + (f32) spA0;
        temp_f31_388 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f29_393 = MKRand_Float((int *) &gViewSeed, 0.0f, 6.0f);
        sp48 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f29_393;
        sp50 = temp_f31_388;
        sp78 = (f64) sp48;
        sp80 = (f64) sp50;
        temp_f0_407 = sp78 * 5.53552857e-315;
        sp38 = temp_f0_407;
        spE8 = temp_f0_407;
        sp40 = (f32) sp80 * 100.0f;
        spF0 = (f64) sp40;
        sp10 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
        gb.EmitCrud(*((MKVector3 *) &spF8), *((MKVector3 *) &spE8), sp10);
        var_r29_340 += 1;
    } while (var_r29_340 < 8);
}
#endif

#if 0 // DRAFT: ')' expected
f32 ExplosiveBarrel::GetRadius() {
    return M2C_FIELD(checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x174);
}
#endif

void ExplosiveBarrel::SetOwner(ExplosiveBarrelPath *arg0) {
    this->unk1A8 = arg0;
}

void ExplosiveBarrel::Disable() {
    BurningWick *temp_r3_479;

    KDProp::Disable();
    temp_r3_479 = this->unk1AC;
    temp_r3_479->Disable();
}

void ExplosiveBarrel::Enable() {
    BurningWick *temp_r3_500;

    KDProp::Enable();
    temp_r3_500 = this->unk1AC;
    temp_r3_500->Enable();
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'ExplosiveBarrel::States'
void ExplosiveBarrel::Message(MKMessage *arg0) {
    f64 sp10;
    f64 sp8;
    BurningWick *temp_r3_710;
    f32 temp_f3_625;
    f32 temp_f3_634;
    f32 temp_f4_631;
    f32 temp_f5_626;
    s32 temp_r0_521;
    s32 temp_r0_565;
    s32 temp_r0_646;
    s32 temp_r3_677;
    s32 temp_r4_557;
    u8 temp_r0_554;
    void *temp_r30_674;
    void *temp_r3_550;
    void *temp_r3_609;
    void *temp_r3_615;
    void *temp_r4_616;

    temp_r0_521 = arg0->unk0;
    if (temp_r0_521 != 0x70) {
        switch (temp_r0_521) {                      /* switch 1; irregular */
        case 0x5:                                   /* switch 1 */
            temp_r3_550 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
            if (((s32) M2C_FIELD(temp_r3_550, s32 *, 0x40) == 0) && (temp_r0_554 = this->unk19C, ((temp_r0_554 == 0) == 0))) {
                temp_r4_557 = this->unk1B4;
                if (((temp_r4_557 == 0) || (temp_r4_557 == 1)) && (temp_r0_554 != 0)) {
                    temp_r0_565 = M2C_FIELD(temp_r3_550, s32 *, 0x38);
                    switch (temp_r0_565) {          /* switch 2; irregular */
                    case 3:                         /* switch 2 */
                        this->unk1AC->Burn(lit_651, 0.001f);
                        SetState((ExplosiveBarrel::States) 1);
                        return;
                    default:                        /* switch 2 */
                    case 2:                         /* switch 2 */
                        if (temp_r4_557 == 0) {
                            Ignite(5.0f);
                            return;
                        }
                        break;
                    }
                }
            } else {
                goto block_50;
            }
            break;
        case 0x162:                                 /* switch 1 */
            if (((s32) this->unk1B4 == 0) && ((u8) this->unk19C != 0)) {
                Ignite(1.0f);
                return;
            }
            break;
        case 0x1:                                   /* switch 1 */
            temp_r3_609 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
            if (((u32) M2C_FIELD(temp_r3_609, u32 *, 8) != this) && (temp_r3_615 = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), temp_r4_616 = this->unk8, sp8 = M2C_FIELD(temp_r4_616, f64 *, 0x30), sp10 = M2C_FIELD(temp_r4_616, f64 *, 0x38), temp_f3_625 = (*(f32 *) ((u8 *) &sp8 + 0x4)) - M2C_FIELD(temp_r3_609, f32 *, 0x14), temp_f5_626 = (f32) sp8 - M2C_FIELD(temp_r3_609, f32 *, 0x10), temp_f4_631 = (f32) sp10 - M2C_FIELD(temp_r3_609, f32 *, 0x18), temp_f3_634 = M2C_FIELD(temp_r3_609, f32 *, 0x20) + M2C_FIELD(temp_r3_615, f32 *, 0x174), ((((temp_f4_631 * temp_f4_631) + ((temp_f5_626 * temp_f5_626) + (temp_f3_625 * temp_f3_625))) < (temp_f3_634 * temp_f3_634)) != 0))) {
                if ((u8) this->unk19C == 0) {
                    return;
                }
                temp_r0_646 = this->unk1B4;
                switch (temp_r0_646) {              /* switch 3; irregular */
                case 1:                             /* switch 3 */
                    this->unk1B4 = 2;
                    return;
                default:                            /* switch 3 */
                    Ignite(0.25f);
                    return;
                }
            }
            break;
        case 0xBA:                                  /* switch 1 */
            if ((u8) this->unk19C != 0) {
                this->unk1B4 = 2;
                return;
            }
            break;
        case 0x4:                                   /* switch 1 */
            temp_r30_674 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
            if ((u8) this->unk19C != 0) {
                temp_r3_677 = M2C_FIELD(temp_r30_674, s32 *, 0x30);
                if (temp_r3_677 & 0x2000) {
                    this->unk1B4 = 2;
                } else if (temp_r3_677 & 0x400) {
                    ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.12f, 0.4f, 0.1f, 0, 4.0f, 0U);
                    KDSound_Play3d(M2C_FIELD(temp_r30_674, s32 *, 0x2C), ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                }
                goto block_50;
            }
            break;
        default:                                    /* switch 1 */
            temp_r3_710 = this->unk1AC;
            temp_r3_710->Message();
            goto block_50;
        }
    } else {
        M2C_FIELD(checked_cast<IsExplodingBarrelMessage *, MKMessage>(arg0), s8 *, 8) = 1;
block_50:
        ((KDSoundPlayer *) &this->unk1BC)->Message(arg0);
        Shatterable::Message(arg0);
    case 3:                                         /* switch 3 */
    case 4:                                         /* switch 3 */
    case 2:                                         /* switch 3 */
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'int *'
void *ExplosiveBarrel::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    BurningWick *temp_r3_797;
    BurningWick *temp_r3_832;
    s32 temp_r0_776;
    s32 temp_r4_813;
    void *temp_r3_809;
    void *temp_r6_757;

    Shatterable::Update();
    sp8 = 1;
    ((KDSoundPlayer *) &this->unk1BC)->Update(GS_TNTBarrelFuseLP, 1U, this->unk1BA, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp14 = 0.0f;
    sp10 = 0.0f;
    if ((u8) this->unk1B9 == 0) {
        temp_r6_757 = this->unk8;
        sp18 = M2C_FIELD(temp_r6_757, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r6_757, f64 *, 0x38);
        if ((((KDWaterVolume *) &sp18)->IsWithin(*((MKVector3 *) &sp10), &sp14, (s32 *) temp_r6_757) != 0) && (M2C_BITWISE(s32, sp14) == 1)) {
            this->unk1B9 = 1;
            this->unk1B4 = 2;
        }
    }
    temp_r0_776 = this->unk1B4;
    switch (temp_r0_776) {                          /* irregular */
    case 1:
        if (this->unk1AC->Burnt() != 0) {
            Explode();
            return;
        }
        temp_r3_797 = this->unk1AC;
        temp_r3_797->Update();
        return;
    case 2:
        Explode();
        return;
    case 3:
        temp_r3_809 = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (((s32) this->unk16C == 0) || ((temp_r4_813 = this->unk180, ((temp_r4_813 == (s32) M2C_FIELD(temp_r3_809, s32 *, 0x160)) != 0)) && ((s32) *(this->unk168 + (((temp_r4_813 - 1) << 7) + 0x44)) == 2))) {
            SetActive(0U);
            this->unk1B4 = 4;
            return;
        }
        return;
    default:
        temp_r3_832 = this->unk1AC;
        temp_r3_832->Update();
        break;
    }
}
#endif

void ExplosiveBarrel::Draw() {
    BurningWick *temp_r3_857;

    Shatterable::Draw();
    if ((s32) this->unk1B4 != 4) {
        temp_r3_857 = this->unk1AC;
        temp_r3_857->Draw();
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'ExplosiveBarrel::States'
void ExplosiveBarrel::SetDefaults() {
    BurningWick *temp_r3_879;
    BurningWick *temp_r3_884;

    Shatterable::Reset();
    temp_r3_879 = this->unk1AC;
    temp_r3_879->Enable();
    temp_r3_884 = this->unk1AC;
    temp_r3_884->Reset();
    KDSound_Stop((int *) &this->unk1BC);
    this->unk1BA = 0;
    SetState((ExplosiveBarrel::States) 0);
    this->unk1B9 = 0;
}
#endif

f32 ExplosiveBarrel::Resolve() {
    Shatterable::Resolve();
}

#if 0 // DRAFT: undefined identifier 'P25ExplosiveBarrelDescriptor'
s32 ExplosiveBarrel::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    BurningWick *temp_r3_931;

    Shatterable::LoadDone();
    temp_r3_931 = checked_cast<BurningWick *, MKProp>(((MKSceneManager *) gMK)->CreateProp("BurningWick"));
    sp10 = 0.0f;
    sp8 = 1.0f;
    spC = 0.0f;
    this->unk1AC = temp_r3_931;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    this->unk1AC->InitData(*(checked_cast<P25ExplosiveBarrelDescriptor), 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x170, *this->unk4, (MKVector3 *) &sp18);
    SetDefaults();
}
#endif

s32 ExplosiveBarrel::LoadLine(MKIniLine *arg0) {
    s32 var_r31_968;

    var_r31_968 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadFloat("fExplosionRadiusScale", &this->unk1B0, 0) != 0)) {
        var_r31_968 = 1;
    }
    return var_r31_968;
}

void ExplosiveBarrel::Deinit() {
    KDSound_Stop((int *) &this->unk1BC);
    Shatterable::Deinit();
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'ExplosiveBarrel::States'
void ExplosiveBarrel::Init() {
    Shatterable::Init();
    this->unk1A8 = NULL;
    this->unk1B8 = 0;
    this->unk1BA = 0;
    this->unk1BC = 0;
    SetState((ExplosiveBarrel::States) 0);
    this->unk1B9 = 0;
    this->unk1B0 = M2C_FIELD(checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x178);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk16C'
void ExplosiveBarrelDescriptor::LoadDone() {
    BoundingVolume *temp_r3_1064;

    ShatterableDescriptor::LoadDone();
    this->unk16C = checked_cast<Explosion4 *, MKProp>(((MKSceneManager *) gMK)->CreateProp("Explosion4"));
    this->unk170 = MKModel_GetRefPointIndex(this->unk2C, "r_wick");
    temp_r3_1064 = this->unk1C;
    this->unk174 = 0.5f * (temp_r3_1064->unk10 - temp_r3_1064->unk0);
}
#endif

s32 ExplosiveBarrelDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1086;

    var_r31_1086 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("fExplosionRadiusScale", &this->unk178, 0) != 0)) {
        var_r31_1086 = 1;
    }
    return var_r31_1086;
}

void ExplosiveBarrelDescriptor::Init() {
    ShatterableDescriptor::Init();
    memset(&this->unk14, 0, 4U);
    this->unk164 |= 0x40;
    this->unk178 = 1.0f;
}
