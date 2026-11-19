#include "spyro/source/MineCart.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
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
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

f64 pow(f64, f32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'float' to 'signed char *'
void MineCart::UpdateWheelBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 temp_r31_95;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = -arg0->unk0;
    sp14 = -arg0->unk4;
    sp18 = -arg0->unk8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30.Translate(&sp30, *((MKVector3 *) &sp20));
    sp30.RotatePitch(&sp30, arg0->unk10);
    sp30.Translate(&sp30, *((MKVector3 *) arg0));
    temp_r31_95 = M2C_FIELD(this->unk20, s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix((s32) temp_r31_95, &sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: ')' expected
void MineCart::Message(MKMessage *arg0) {
    s8 sp129;
    s8 sp128;
    s32 sp124;
    f32 sp120;
    s32 sp11C;
    s8 sp11A;
    s8 sp119;
    s8 sp118;
    f64 sp110;                                      /* compiler-managed */
    f64 sp108;                                      /* compiler-managed */
    MineCart *sp104;
    s32 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    s32 spDC;
    s32 spD8;
    s8 spD0;
    s32 spCC;
    s32 spC8;
    f64 *spC4;
    f64 *spC0;
    s32 spBC;
    s32 spB8;
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
    f32 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f2_274;
    f64 temp_f1_251;
    s32 temp_r0_123;
    void **temp_r3_155;
    void *temp_r3_159;
    void *temp_r3_167;
    void *temp_r4_166;
    void *temp_r4_248;

    ((KDSoundPlayer *) &this->unk17C)->Message(arg0);
    temp_r0_123 = arg0->unk0;
    switch (temp_r0_123) {                          /* irregular */
    case 191:
    case -4:
        KDSound_Stop((int *) &this->unk17C);
        this->unkE8.Show(0U);
        break;
    case 190:
    case -3:
        this->unkE8.Show(1U);
        break;
    case 18:
        temp_r3_155 = M2C_FIELD(checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0), void ***, 0xC);
        temp_r3_159 = M2C_FIELD(*temp_r3_155, void *(**)(void **), 0x2C)(temp_r3_155);
        if (temp_r3_159 != NULL) {
            if (M2C_FIELD(M2C_FIELD(temp_r3_159, void **, 0), s32 *, 0xC) & 0x40) {
                temp_r4_166 = M2C_FIELD(temp_r3_159, void **, 8);
                temp_r3_167 = this->unk8;
                spA8 = M2C_FIELD(temp_r4_166, f64 *, 0x30);
                sp98 = M2C_FIELD(temp_r3_167, f64 *, 0x30);
                spB0 = M2C_FIELD(temp_r4_166, f64 *, 0x38);
                spA0 = M2C_FIELD(temp_r3_167, f64 *, 0x38);
                sp38 = spA8 - sp98;
                sp88 = sp38;
                spDC = 0;
                sp40 = (f32) spB0 - (f32) spA0;
                (*(f32 *) ((u8 *) &sp88 + 0x4)) = 0.0f;
                sp90 = (f64) sp40;
                spD8 = 7;
                sp100 = 2;
                sp104 = this;
                spE0 = sp38;
                spE8 = (f64) sp40;
                sp118 = 1;
                sp124 = 2;
                sp120 = 10.0f;
                sp119 = 0;
                sp11A = 1;
                sp11C = -1;
                spF0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                spF8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp128 = 0;
                if (this != NULL) {
                    sp28 = GetPos();
                    *(MKVector3 *) &sp108 = sp28;
                } else {
                    sp108 = 0.0f;
                    (*(f32 *) ((u8 *) &sp104 + 0x8)) = 0.0f;
                    sp110 = 0.0f;
                }
                sp129 = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_159, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_159, &spD8);
            } else {
                spBC = 0;
                sp18 = this->unkD8 * 5.222099017e-315;
                temp_r4_248 = M2C_FIELD(temp_r3_159, void **, 8);
                temp_f1_251 = M2C_FIELD(temp_r4_248, f64 *, 0x30);
                sp20 = this->unkE0 * 0.5f;
                sp48 = sp18;
                sp58 = temp_f1_251;
                sp50 = (f64) sp20;
                sp60 = M2C_FIELD(temp_r4_248, f64 *, 0x38);
                sp8 = temp_f1_251 + sp48;
                sp78 = sp8;
                temp_f2_274 = (f32) sp60 + (f32) sp50;
                sp68 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                sp10 = temp_f2_274;
                sp70 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
                sp80 = (f64) sp10;
                spB8 = 0x22;
                spC0 = &sp78;
                spC4 = &sp68;
                spC8 = 0;
                spCC = 0;
                spD0 = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_159, void **, 0x44), M2C_UNK (**)(s32 *, f64 *, M2C_UNK, M2C_UNK, f64, f32, f32, f32), 0x2C)(&spB8, &sp78, 0x22, 0, (f64) sp10, temp_f2_274, (f32) sp50, (f32) sp60);
            }
        }
        break;
    }
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void MineCart::UpdateEffects() {
    f64 sp158;                                      /* compiler-managed */
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
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f1_529;
    f32 temp_f25_454;
    f32 temp_f26_459;
    f32 temp_f26_503;
    f32 temp_f3_368;
    f32 temp_f6_349;
    f32 temp_f6_360;
    f32 temp_f7_352;
    f64 temp_f0_392;
    f64 temp_f0_414;
    f64 temp_f0_441;
    f64 temp_f0_473;
    f64 temp_f0_484;
    f64 temp_f0_534;
    s32 temp_r3_342;
    s32 var_r30_436;
    void *temp_r3_347;
    void *temp_r3_389;
    void *temp_r3_411;
    void *temp_r4_344;
    void *temp_r4_530;
    void *temp_r5_531;

    this->unk118 -= gUpdateTimeDelta;
    if (this->unk118 <= 0.0f) {
        this->unk118 = MKRand_Float((int *) &gViewSeed, 0.125f, 0.25f);
        temp_r3_342 = MKRand_Int((int *) &gViewSeed, 0, 2);
        temp_r4_344 = this->unk8;
        temp_r3_347 = this + (temp_r3_342 * 0x18);
        temp_f6_349 = M2C_FIELD(temp_r3_347, f32 *, 0x124);
        temp_f7_352 = M2C_FIELD(temp_r3_347, f32 *, 0x120);
        temp_f6_360 = M2C_FIELD(temp_r3_347, f32 *, 0x128);
        temp_f3_368 = M2C_FIELD(temp_r4_344, f32 *, 0x34);
        spA0 = M2C_FIELD(temp_r4_344, f32 *, 0x30) + ((temp_f6_360 * M2C_FIELD(temp_r4_344, f32 *, 0x20)) + ((temp_f7_352 * M2C_FIELD(temp_r4_344, f32 *, 0)) + (temp_f6_349 * M2C_FIELD(temp_r4_344, f32 *, 0x10))));
        spA4 = temp_f3_368 + ((temp_f6_360 * M2C_FIELD(temp_r4_344, f32 *, 0x24)) + ((temp_f7_352 * M2C_FIELD(temp_r4_344, f32 *, 4)) + (temp_f6_349 * M2C_FIELD(temp_r4_344, f32 *, 0x14))));
        spA8 = M2C_FIELD(temp_r4_344, f32 *, 0x38) + ((temp_f6_360 * M2C_FIELD(temp_r4_344, f32 *, 0x28)) + ((temp_f7_352 * M2C_FIELD(temp_r4_344, f32 *, 8)) + (temp_f6_349 * M2C_FIELD(temp_r4_344, f32 *, 0x18))));
        sp150 = (f64) spA0;
        sp158 = (f64) spA8;
        (*(f32 *) ((u8 *) &sp150 + 0x4)) = temp_f3_368;
        if (temp_r3_342 == 1) {
            if (MKRand_Int((int *) &gViewSeed, -1, 1) != 0) {
                temp_r3_389 = this->unk8;
                temp_f0_392 = (f64) M2C_FIELD(temp_r3_389, f32 *, 0) * 5.55430844e-315;
                sp40 = temp_f0_392;
                sp140 = temp_f0_392;
                sp48 = M2C_FIELD(temp_r3_389, f32 *, 8) * 130.0f;
                sp148 = (f64) sp48;
                sp150 += temp_f0_392;
                sp158 = (f32) sp158 + (f32) sp148;
            } else {
                temp_r3_411 = this->unk8;
                temp_f0_414 = (f64) M2C_FIELD(temp_r3_411, f32 *, 0) * 5.55430844e-315;
                sp30 = temp_f0_414;
                sp130 = temp_f0_414;
                sp38 = M2C_FIELD(temp_r3_411, f32 *, 8) * 130.0f;
                sp138 = (f64) sp38;
                sp150 -= temp_f0_414;
                sp158 -= (f32) sp138;
            }
        }
        var_r30_436 = 0;
        do {
            temp_f0_441 = this->unkD8 * 5.398241246e-315;
            sp70 = temp_f0_441;
            spF0 = temp_f0_441;
            sp78 = this->unkE0 * 10.0f;
            spF8 = (f64) sp78;
            temp_f25_454 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f26_459 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            sp90 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp94 = temp_f26_459;
            sp98 = temp_f25_454;
            sp100 = (f64) sp90;
            sp108 = (f64) sp98;
            temp_f0_473 = sp100 * 5.65986426e-315;
            sp80 = temp_f0_473;
            sp110 = temp_f0_473;
            sp88 = (f32) sp108 * 800.0f;
            sp118 = (f64) sp88;
            temp_f0_484 = sp110 + temp_f0_441;
            sp60 = temp_f0_484;
            sp120 = temp_f0_484;
            sp68 = (f32) sp118 + (f32) spF8;
            sp128 = (f64) sp68;
            sp8 = MKRand_Float((int *) &gViewSeed, 5.0f, 8.0f);
            temp_f26_503 = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
            sp50 = MKRand_Float((int *) &gViewSeed, 0.85f, 1.0f);
            sp54 = temp_f26_503;
            sp58 = 0.5f;
            sp5C = 1.0f;
            spE0 = (f64) sp50;
            spE8 = (f64) sp58;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp150), *((MKVector3 *) &sp120), sp8, *((MKVector4 *) &spE0), -1000.0f);
            var_r30_436 += 1;
        } while (var_r30_436 < 5);
        temp_f1_529 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_r4_530 = this->unk8;
        temp_r5_531 = ((u8 *) temp_r4_530) + 0x20;
        temp_f0_534 = (f64) M2C_FIELD(temp_r4_530, f32 *, 0) + M2C_FIELD(temp_r5_531, f64 *, 0);
        sp10 = temp_f0_534;
        spB0 = temp_f0_534;
        sp18 = M2C_FIELD(temp_r4_530, f32 *, 8) + M2C_FIELD(temp_r5_531, f32 *, 8);
        spB8 = (f64) sp18;
        spC0 = ((MKVector3 *) &spB0)->operator*(temp_f1_529);
        sp20 = spC0 * 5.398241246e-315;
        this->unk168 = sp20;
        sp28 = spC0.unk8 * 10.0f;
        spD0 = sp20;
        spD8 = (f64) sp28;
        this->unk170 = (f64) sp28;
    }
}
#endif

#if 0 // DRAFT: declaration syntax error
void *MineCart::Update() {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    KDSynkerPlayer3 *temp_r3_627;
    f32 temp_f0_724;
    f32 temp_f31_736;
    s32 temp_r0_719;
    s32 var_ctr_717;
    s32 var_r3_699;
    u8 var_r25_623;
    u8 var_r26_608;
    u8 var_r29_626;
    u8 var_r31_595;
    u8 var_r31_666;
    u8 var_r3_596;
    u8 var_r3_609;
    void *temp_r27_625;
    void *temp_r3_692;
    void *temp_r3_744;
    void *temp_r4_594;
    void *temp_r4_676;
    void *temp_r4_708;

    GameProp::Update();
    temp_r4_594 = this->unk178;
    var_r31_595 = 1;
    var_r3_596 = 0;
    if ((temp_r4_594 == NULL) || ((u8) M2C_FIELD(temp_r4_594, u8 *, 0x4C) == 0)) {
        var_r3_596 = 1;
    }
    if (var_r3_596 == 0) {
        var_r26_608 = 0;
        var_r3_609 = 0;
        if ((temp_r4_594 != NULL) && ((u8) M2C_FIELD(temp_r4_594, u8 *, 0x4C) != 0) && (M2C_FIELD(temp_r4_594, f32 *, 0x88) < 0.9f)) {
            var_r3_609 = 1;
        }
        if (var_r3_609 != 0) {
            var_r25_623 = 0;
            temp_r27_625 = M2C_FIELD(&gb, void **, 0xC);
            var_r29_626 = 0;
            temp_r3_627 = M2C_FIELD(temp_r27_625, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_627 != NULL) && (temp_r3_627->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r27_625, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r27_625) + 0x24))->GetState() == 2))) {
                var_r29_626 = 1;
            }
            if ((var_r29_626 != 0) && ((s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s32 *, 0x74) == 0)) {
                var_r25_623 = 1;
            }
            if (var_r25_623 == 0) {
                var_r26_608 = 1;
            }
        }
        if (var_r26_608 == 0) {
            var_r31_595 = 0;
        }
    }
    if ((s32) M2C_FIELD(checked_cast<MineCartDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4) != 0) {
        var_r31_666 = 0;
        if ((var_r31_595 != 0) && (this->unk10 & 0x160000)) {
            var_r31_666 = 1;
        }
        temp_r4_676 = checked_cast<MineCartDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk17C)->Update(M2C_FIELD(temp_r4_676, s32 *, 0xE4), 1U, var_r31_666, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((void *) this->unk178 != NULL) {
        temp_r3_692 = ((u8 *) this->unk8) + 0x30;
        sp10 = M2C_FIELD(temp_r3_692, f64 *, 0) - this->unkC8;
        var_r3_699 = 0;
        this->unkD8 = sp10;
        sp18 = M2C_FIELD(temp_r3_692, f32 *, 8) - this->unkD0;
        sp30 = sp10;
        M2C_FIELD(this, f64 *, 0xE0) = (f64) sp18;
        temp_r4_708 = this->unk8;
        sp38 = (f64) sp18;
        this->unkC8 = M2C_FIELD(temp_r4_708, f64 *, 0x30);
        M2C_FIELD(this, f32 *, 0xD0) = (f64) M2C_FIELD(temp_r4_708, f64 *, 0x38);
        var_ctr_717 = 3;
        do {
            temp_r0_719 = var_r3_699 + 0x130;
            *(this + temp_r0_719) = (20.0f * gUpdateTimeDelta) + *(this + temp_r0_719);
            temp_f0_724 = *(this + temp_r0_719);
            if (temp_f0_724 >= 6.2831855f) {
                *(this + temp_r0_719) = temp_f0_724 - 6.2831855f;
            }
            var_r3_699 += 0x18;
            var_ctr_717 -= 1;
        } while (var_ctr_717 != 0);
        temp_f31_736 = (f32) pow(0.125, gUpdateTimeDelta);
        this->unk168 *= (f64) temp_f31_736;
        M2C_FIELD(this, f32 *, 0x170) = (f32) (M2C_FIELD(this, f32 *, 0x170) * temp_f31_736);
        temp_r3_744 = this->unk8;
        sp20 = M2C_FIELD(temp_r3_744, f64 *, 0x30);
        sp28 = M2C_FIELD(temp_r3_744, f64 *, 0x38);
        this->unkE8.unk28 = (*(f32 *) ((u8 *) &sp20 + 0x4));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
f32 MineCart::Resolve() {
    MKVector3 sp8;
    s32 var_r27_776;
    s32 var_r31_778;
    s8 *temp_r29_784;
    s8 temp_r26_791;
    void *temp_r29_798;

    KDPropEx::Resolve();
    if ((void *) this->unk178 != NULL) {
        var_r27_776 = 0;
        var_r31_778 = 0;
        do {
            temp_r29_784 = Str_Printf("d_minecart_wheel_%.2d", var_r27_776 + 1);
            temp_r26_791 = (const char *) (((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeIndex(temp_r29_784));
            sp8 = ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeOrigin((s32) temp_r26_791);
            temp_r29_798 = this + var_r31_778;
            M2C_FIELD(temp_r29_798, MKVector3 *, 0x120) = sp8;
            MKDynamicBone_SetUpdater(MKDynamicBone_GetDynamicBone(this->unk4, (s32) temp_r26_791), (void (*)(MKDynamicBone *, void *)) &MineCart::UpdateWheelBone, ((u8 *) temp_r29_798) + 0x120);
            var_r27_776 += 1;
            var_r31_778 += 0x18;
        } while (var_r27_776 < 3);
    }
}
#endif

s32 MineCart::LoadDone() {
    GameProp::LoadDone();
    this->unkE8.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unkE8.Show(1U);
    ((Animation *) (MKModel_GetAnimation(this->unk4)))->EnableCustomMatrices(1U);
}

void MineCart::Deinit() {
    this->unkE8.Deinit();
    KDSound_Stop((int *) &this->unk17C);
    GameProp::Deinit();
}

void MineCart::Init() {
    MKVector3 sp8;
    MKVector3 sp18;
    s32 var_ctr_890;
    s32 var_r3_885;
    s32 temp_r0_892;
    MineCartDescriptor *temp_r31_911;
    MineCartDescriptor *temp_r3_913;

    GameProp::Init();
    var_r3_885 = 0;
    this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xD0) = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkD8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xE0) = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_ctr_890 = 3;
    do {
        temp_r0_892 = var_r3_885 + 0x130;
        var_r3_885 += 0x18;
        M2C_FIELD(this, f32 *, temp_r0_892) = 0.0f;
        var_ctr_890 -= 1;
    } while (var_ctr_890 != 0);
    sp8.unk0 = 0.0f;
    sp8.unk4 = 0.0f;
    sp8.unk8 = 0.0f;
    this->unk118 = 0.0f;
    this->unk168 = M2C_FIELD(&sp8, f64 *, 0);
    this->unk170 = M2C_FIELD(&sp8, f64 *, 8);
    this->unk178 = NULL;
    sp18 = sp8;
    temp_r31_911 = checked_cast<MineCartDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_913 = checked_cast<MineCartDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk17C)->Init(M2C_FIELD(temp_r3_913, f32 *, 0xE8), M2C_FIELD(temp_r31_911, f32 *, 0xEC));
}

s32 MineCartDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_934;

    var_r31_934 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "travelSound", (int *) &M2C_FIELD(this, s32 *, 0xE4)) != 0) || (arg0->LoadFloat("soundfadeIn", &this->unkE8, 0) != 0) || (arg0->LoadFloat("soundfadeOut", &this->unkEC, 0) != 0)) {
        var_r31_934 = 1;
    }
    return var_r31_934;
}

void MineCartDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, s32 *, 0xE4) = 0;
    this->unkE8 = 0.25f;
    this->unkEC = 0.25f;
}
