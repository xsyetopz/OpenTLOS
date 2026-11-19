#include "spyro/source/ExplosiveBarrel.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/BurningWick.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/ExplosiveBarrelPath.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_TNTBarrelExplode;
extern s32 GS_TNTBarrelFuseLP;
extern void **gMK;
extern s32 gViewSeed;
extern GameGlobals gb;
static u8 lit_651 = 1;

static u8 lit_750 = 1;

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ExplosiveBarrel::Ignite(float arg0) {
    f32 sp8;

    sp8 = arg0;
    M2C_FIELD(this, s8 *, 0x1BA) = 1;
    SetState((ExplosiveBarrel::States) 1);
    ((BurningWick *) (M2C_FIELD(this, BurningWick **, 0x1AC)))->Burn(lit_750, sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ExplosiveBarrel::Explode() {
    ExplosiveBarrel *spC;
    s32 sp8;
    s32 temp_r0_92;
    void *temp_r3_103;

    temp_r0_92 = this->unk1B4;
    if ((temp_r0_92 == 0) || (temp_r0_92 == 1) || (temp_r0_92 == 2)) {
        SetState((ExplosiveBarrel::States) 3);
        temp_r3_103 = M2C_FIELD(this, void **, 0x1AC);
        M2C_FIELD(M2C_FIELD(temp_r3_103, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_103);
        Shatter(0, 0, -1, 0, 1, 0);
        TriggerShatterFX();
        this->unk15C.Send(NULL);
        spC = NULL;
        sp8 = 0x162;
        spC = this;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32), 0x94)(gMK, &sp8, 0, 0, this->unk8 + 0x30, 1, 500.0f);
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
    void *temp_r3_172;
    void *temp_r3_179;

    M2C_FIELD(this, u8 *, 0x1B8) = arg0;
    if (arg0 != 0) {
        temp_r3_172 = M2C_FIELD(this, void **, 0x1AC);
        M2C_FIELD(M2C_FIELD(temp_r3_172, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_172);
        return;
    }
    temp_r3_179 = M2C_FIELD(this, void **, 0x1AC);
    M2C_FIELD(M2C_FIELD(temp_r3_179, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_179);
}

u8 ExplosiveBarrel::IsActive() {
    return M2C_FIELD(this, u8 *, 0x1B8);
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
    M2C_UNK spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    M2C_UNK sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
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
    s32 var_r29_247;
    s32 var_r29_340;
    void *temp_r3_225;
    void *temp_r3_231;
    void *temp_r4_249;
    void *temp_r4_342;

    M2C_FIELD(this, s8 *, 0x1BA) = 0;
    M2C_FIELD(M2C_FIELD(checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x16C), s32 *, 0x88) = (s32) GS_TNTBarrelExplode;
    temp_r3_225 = this->unk8;
    spD8 = M2C_FIELD(temp_r3_225, f64 *, 0x30);
    spE0 = M2C_FIELD(temp_r3_225, f64 *, 0x38);
    temp_r3_231 = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1;
    ((Explosion4 *) (M2C_FIELD(temp_r3_231, Explosion4 **, 0x16C)))->Trigger(*((MKVector3 *) &spD8), M2C_FIELD(this, f32 *, 0x1B0), 1U, (MKProp *) this, 0xF, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    var_r29_247 = 0;
    do {
        temp_r4_249 = this->unk8;
        sp118 = M2C_FIELD(temp_r4_249, f64 *, 0x30);
        sp120 = M2C_FIELD(temp_r4_249, f64 *, 0x38);
        temp_f26_258 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_263 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f27_263, temp_f26_258);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        spC8 = sp28;
        sp30 = spC0 * 100.0f;
        spD0 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp120 = (f32) sp120 + (f32) spD0;
        temp_f26_295 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_300 = MKRand_Float(&gViewSeed, 0.0f, 3.0f);
        sp68 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp6C = temp_f27_300;
        sp70 = temp_f26_295;
        spA8 = (f64) sp68;
        spB0 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp108 = sp58;
        sp60 = (f32) spB0 * 50.0f;
        sp110 = (f64) sp60;
        sp14 = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
        gb.EmitDust(*((MKVector3 *) &sp118), *((MKVector3 *) &sp108), sp14, 0.0f);
        var_r29_247 += 1;
    } while (var_r29_247 < 4);
    var_r29_340 = 0;
    do {
        temp_r4_342 = this->unk8;
        spF8 = M2C_FIELD(temp_r4_342, f64 *, 0x30);
        sp100 = M2C_FIELD(temp_r4_342, f64 *, 0x38);
        temp_f26_351 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_356 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f27_356, temp_f26_351);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp98 = sp18;
        sp20 = sp90 * 100.0f;
        spA0 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp100 = (f32) sp100 + (f32) spA0;
        temp_f31_388 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f29_393 = MKRand_Float(&gViewSeed, 0.0f, 6.0f);
        sp48 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f29_393;
        sp50 = temp_f31_388;
        sp78 = (f64) sp48;
        sp80 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spE8 = sp38;
        sp40 = (f32) sp80 * 100.0f;
        spF0 = (f64) sp40;
        sp10 = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
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

#if 0 // DRAFT: illegal explicit conversion from 'ExplosiveBarrelPath *' to
void ExplosiveBarrel::SetOwner(ExplosiveBarrelPath *arg0) {
    this->unk198 = M2C_BITWISE(f32, arg0);
}
#endif

void ExplosiveBarrel::Disable() {
    void *temp_r3_479;

    KDProp::Disable();
    temp_r3_479 = M2C_FIELD(this, void **, 0x1AC);
    M2C_FIELD(M2C_FIELD(temp_r3_479, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_479);
}

void ExplosiveBarrel::Enable() {
    void *temp_r3_500;

    KDProp::Enable();
    temp_r3_500 = M2C_FIELD(this, void **, 0x1AC);
    M2C_FIELD(M2C_FIELD(temp_r3_500, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_500);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
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
            if (((s32) M2C_FIELD(temp_r3_550, s32 *, 0x40) == 0) && (temp_r0_554 = M2C_FIELD(this, u8 *, 0x19C), ((temp_r0_554 == 0) == 0))) {
                temp_r4_557 = this->unk1B4;
                if (((temp_r4_557 == 0) || (temp_r4_557 == 1)) && (temp_r0_554 != 0)) {
                    temp_r0_565 = M2C_FIELD(temp_r3_550, s32 *, 0x38);
                    switch (temp_r0_565) {          /* switch 2; irregular */
                    case 3:                         /* switch 2 */
                        ((BurningWick *) (M2C_FIELD(this, BurningWick **, 0x1AC)))->Burn(lit_651, 0.001f);
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
            if (((s32) this->unk1B4 == 0) && ((u8) M2C_FIELD(this, u8 *, 0x19C) != 0)) {
                Ignite(1.0f);
                return;
            }
            break;
        case 0x1:                                   /* switch 1 */
            temp_r3_609 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
            if (((u32) M2C_FIELD(temp_r3_609, u32 *, 8) != this) && (temp_r3_615 = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), temp_r4_616 = this->unk8, sp8 = M2C_FIELD(temp_r4_616, f64 *, 0x30), sp10 = M2C_FIELD(temp_r4_616, f64 *, 0x38), temp_f3_625 = unkspC - M2C_FIELD(temp_r3_609, f32 *, 0x14), temp_f5_626 = (f32) sp8 - M2C_FIELD(temp_r3_609, f32 *, 0x10), temp_f4_631 = (f32) sp10 - M2C_FIELD(temp_r3_609, f32 *, 0x18), temp_f3_634 = M2C_FIELD(temp_r3_609, f32 *, 0x20) + M2C_FIELD(temp_r3_615, f32 *, 0x174), ((((temp_f4_631 * temp_f4_631) + ((temp_f5_626 * temp_f5_626) + (temp_f3_625 * temp_f3_625))) < (temp_f3_634 * temp_f3_634)) != 0))) {
                if ((u8) M2C_FIELD(this, u8 *, 0x19C) == 0) {
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
            if ((u8) M2C_FIELD(this, u8 *, 0x19C) != 0) {
                this->unk1B4 = 2;
                return;
            }
            break;
        case 0x4:                                   /* switch 1 */
            temp_r30_674 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
            if ((u8) M2C_FIELD(this, u8 *, 0x19C) != 0) {
                temp_r3_677 = M2C_FIELD(temp_r30_674, s32 *, 0x30);
                if (temp_r3_677 & 0x2000) {
                    this->unk1B4 = 2;
                } else if (temp_r3_677 & 0x400) {
                    ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.12f, 0.4f, 0.1f, 0, 4.0f, 0U);
                    KDSound_Play3d(M2C_FIELD(temp_r30_674, s32 *, 0x2C), this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                }
                goto block_50;
            }
            break;
        default:                                    /* switch 1 */
            temp_r3_710 = M2C_FIELD(this, BurningWick **, 0x1AC);
            temp_r3_710->Message();
            goto block_50;
        }
    } else {
        M2C_FIELD(checked_cast<IsExplodingBarrelMessage *, MKMessage>(arg0), s8 *, 8) = 1;
block_50:
        this->unk1AC.Message(arg0);
        Shatterable::Message(arg0);
    case 3:                                         /* switch 3 */
    case 4:                                         /* switch 3 */
    case 2:                                         /* switch 3 */
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void ExplosiveBarrel::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    BurningWick *temp_r3_797;
    BurningWick *temp_r3_832;
    MKProp *temp_r4_813;
    s32 temp_r0_776;
    void *temp_r3_809;
    void *temp_r6_757;

    Shatterable::Update();
    sp8 = 1;
    this->unk1AC.Update(GS_TNTBarrelFuseLP, 1U, M2C_FIELD(this, u8 *, 0x1BA), (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp14 = 0.0f;
    sp10 = 0.0f;
    if ((u8) M2C_FIELD(this, u8 *, 0x1B9) == 0) {
        temp_r6_757 = this->unk8;
        sp18 = M2C_FIELD(temp_r6_757, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r6_757, f64 *, 0x38);
        if ((sp18.IsWithin(*((MKVector3 *) &sp10), &sp14, (s32 *) temp_r6_757) != 0) && (M2C_BITWISE(s32, sp14) == 1)) {
            M2C_FIELD(this, u8 *, 0x1B9) = 1U;
            this->unk1B4 = 2;
        }
    }
    temp_r0_776 = this->unk1B4;
    switch (temp_r0_776) {                          /* irregular */
    case 1:
        if (((BurningWick *) (M2C_FIELD(this, BurningWick **, 0x1AC)))->Burnt() != 0) {
            Explode();
            return;
        }
        temp_r3_797 = M2C_FIELD(this, BurningWick **, 0x1AC);
        temp_r3_797->Update();
        return;
    case 2:
        Explode();
        return;
    case 3:
        temp_r3_809 = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (((s32) this->unk15C.unk0 == 0) || ((temp_r4_813 = this->unk170, ((temp_r4_813 == (s32) M2C_FIELD(temp_r3_809, s32 *, 0x160)) != 0)) && ((s32) *(this->unk158 + (((s32) (temp_r4_813 - 1) << 7) + 0x44)) == 2))) {
            SetActive(0U);
            this->unk1B4 = 4;
            return;
        }
        return;
    default:
        temp_r3_832 = M2C_FIELD(this, BurningWick **, 0x1AC);
        temp_r3_832->Update();
        break;
    }
}
#endif

void ExplosiveBarrel::Draw() {
    void *temp_r3_857;

    Shatterable::Draw();
    if ((s32) this->unk1B4 != 4) {
        temp_r3_857 = M2C_FIELD(this, void **, 0x1AC);
        M2C_FIELD(M2C_FIELD(temp_r3_857, void **, 0x44), M2C_UNK (**)(void *), 0x28)(temp_r3_857);
    }
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void ExplosiveBarrel::SetDefaults() {
    void *temp_r3_879;
    void *temp_r3_884;

    Shatterable::Reset();
    temp_r3_879 = M2C_FIELD(this, void **, 0x1AC);
    M2C_FIELD(M2C_FIELD(temp_r3_879, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_879);
    temp_r3_884 = M2C_FIELD(this, void **, 0x1AC);
    M2C_FIELD(M2C_FIELD(temp_r3_884, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_884);
    KDSound_Stop((s32 *) &this->unk1AC);
    M2C_FIELD(this, s8 *, 0x1BA) = 0;
    SetState((ExplosiveBarrel::States) 0);
    M2C_FIELD(this, s8 *, 0x1B9) = 0;
}
#endif

void ExplosiveBarrel::Resolve() {
    Shatterable::Resolve();
}

#if 0 // DRAFT: expression syntax error
void ExplosiveBarrel::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    BurningWick *temp_r3_931;

    Shatterable::LoadDone();
    temp_r3_931 = checked_cast<BurningWick *, MKProp>(gMK->CreateProp("BurningWick"));
    sp10 = 0.0f;
    sp8 = 1.0f;
    spC = 0.0f;
    M2C_FIELD(this, BurningWick **, 0x1AC) = temp_r3_931;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    ((BurningWick *) (M2C_FIELD(this, BurningWick **, 0x1AC)))->InitData(*(checked_cast<P25ExplosiveBarrelDescriptor), 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x170, *this->unk4, (MKVector3 *) &sp18);
    SetDefaults();
}
#endif

s32 ExplosiveBarrel::LoadLine(MKIniLine *arg0) {
    s32 var_r31_968;

    var_r31_968 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadFloat("fExplosionRadiusScale", (f32 *) &this->unk1A0, 0) != 0)) {
        var_r31_968 = 1;
    }
    return var_r31_968;
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void ExplosiveBarrel::Deinit() {
    KDSound_Stop((s32 *) &this->unk1AC);
    Shatterable::Deinit();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ExplosiveBarrel::Init() {
    Shatterable::Init();
    this->unk198 = 0.0f;
    M2C_FIELD(this, s8 *, 0x1B8) = 0;
    M2C_FIELD(this, s8 *, 0x1BA) = 0;
    this->unk1AC = NULL;
    SetState((ExplosiveBarrel::States) 0);
    M2C_FIELD(this, s8 *, 0x1B9) = 0;
    M2C_FIELD(this, f32 *, 0x1B0) = (f32) M2C_FIELD(checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x178);
}
#endif

#if 0 // DRAFT: expression syntax error
void ExplosiveBarrelDescriptor::LoadDone() {
    BoundingVolume *temp_r3_1064;

    ShatterableDescriptor::LoadDone();
    this->unk16C = checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
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
