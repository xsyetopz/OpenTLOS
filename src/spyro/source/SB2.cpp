#include "spyro/source/SB2.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/TargetManager.h"
#include "dolphin/os.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

f64 acos(f32, void *, f32, f64, f32, f32, f32, f64, f32, f32, f32, f32, f32, f32, f32); /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern u32 gAvailableTicksThisUpdate;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
static f32 fSBInverseWeight[0x12] = {
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    0.0f,
    2.0f,
    2.0f,
    0.0f,
    0.0f,
    0.0f,
    1.0f,
    3.0f,
    3.0f,
    0.0f,
};
#if 0 // DRAFT: identifier 'fGameTimeLastUpdate' redeclared
static M2C_UNK vBaseHeading;                        /* unable to generate initializer: unknown type */
static f32 fGameTimeLastUpdate = -1.0f;
#endif

static f32 STEER_DIR_ANGLES[5] = { 0.0f, 1.0471973f, -1.0471973f, 1.670796f, -1.670796f }; /* const */

void SteerDirection::Init() {
    this->unk0 = 0.0f;
    this->unk4 = 0.0f;
    this->unk8 = 0.0f;
    this->unk10 = 0.0f;
    this->unk90 &= ~0x80;
    this->unk90 &= ~0x40;
    this->unk90 &= ~0x20;
    this->unk90 &= ~0x10;
    this->unk18 = 0.0f;
    this->unk1C = 0.0f;
    this->unk20 = 0.0f;
    this->unk28 = 0.0f;
    this->unk2C = 0.0f;
    this->unk30 = 0.0f;
    this->unk38 = 0.0f;
    this->unk40 = 0.0f;
    this->unk44 = 0.0f;
    this->unk48 = 0.0f;
    this->unk50 = 0.0f;
    this->unk54 = 0.0f;
    this->unk58 = 0.0f;
    this->unk60 = 0.0f;
    this->unk68 = 0.0f;
    this->unk6C = 0.0f;
    this->unk70 = 0.0f;
    this->unk78 = 0.0f;
    this->unk7C = 0.0f;
    this->unk80 = 0.0f;
    this->unk88 = 0.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'SB2' to
void SB2::Arbitrate() {
    f64 spA0;                                       /* compiler-managed */
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
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f0_73;
    f32 temp_f10_125;
    f32 temp_f11_133;
    f32 temp_f7_121;
    f32 var_f2_66;
    f64 temp_f5_93;
    f64 temp_f9_89;
    s32 temp_r31_82;
    s32 var_ctr_70;
    s32 var_r3_69;
    s32 var_r4_67;
    s32 var_r5_68;
    void *temp_r3_182;
    void *temp_r3_214;
    void *temp_r3_91;
    void *temp_r5_88;

    var_f2_66 = 3.4028235e38f;
    var_r4_67 = 0;
    var_r5_68 = 0;
    var_r3_69 = 0;
    var_ctr_70 = 5;
    do {
        temp_f0_73 = *(this + (var_r3_69 + 0x110));
        if (temp_f0_73 < var_f2_66) {
            var_f2_66 = temp_f0_73;
            var_r4_67 = var_r5_68;
        }
        var_r5_68 += 1;
        var_r3_69 += 0x98;
        var_ctr_70 -= 1;
    } while (var_ctr_70 != 0);
    temp_r31_82 = var_r4_67 * 0x98;
    if (((u8) *(this + (temp_r31_82 + 0x190)) >> 6U) & 1) {
        temp_r5_88 = this + temp_r31_82;
        temp_f9_89 = M2C_FIELD(temp_r5_88, f64 *, 0x130);
        temp_r3_91 = this->unk0->unk8;
        temp_f5_93 = M2C_FIELD(temp_r5_88, f64 *, 0x128);
        sp48 = temp_f5_93;
        unksp4C = 0.0f;
        sp80 = temp_f9_89;
        sp78 = temp_f5_93;
        sp30 = -M2C_FIELD(temp_r3_91, f32 *, 0x28);
        sp28 = -M2C_FIELD(temp_r3_91, f32 *, 0x20);
        sp2C = -M2C_FIELD(temp_r3_91, f32 *, 0x24);
        temp_f7_121 = M2C_FIELD(temp_r5_88, f32 *, 0x12C);
        sp70 = (f64) sp30;
        temp_f10_125 = (f32) M2C_FIELD(temp_r5_88, f64 *, 0x128);
        sp68 = (f64) sp28;
        sp40 = (up.unk0 * unksp7C) - (up.unk4 * (f32) sp78);
        temp_f11_133 = (f32) M2C_FIELD(temp_r5_88, f64 *, 0x130);
        sp38 = (up.unk4 * (f32) sp80) - (up.unk8 * unksp7C);
        sp3C = (up.unk8 * (f32) sp78) - (up.unk0 * (f32) sp80);
        sp50 = temp_f9_89;
        sp98 = (f64) sp38;
        spA0 = (f64) sp40;
        if ((((f32) sp70 * temp_f11_133) + (((f32) sp68 * temp_f10_125) + (unksp6C * temp_f7_121))) > -0.9f) {
            temp_r3_91->ZAxis3();
            sp18 = -*M2C_ERROR(/* Read from unset register $r3 */);
            sp1C = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
            sp20 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
            sp88 = (f64) sp18;
            sp90 = (f64) sp20;
            sp58 = (f64) sp18;
            sp60 = (f64) sp20;
            if ((((f32) sp90 * (f32) spA0) + (((f32) sp88 * (f32) sp98) + (unksp8C * unksp9C))) < 0.0f) {
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                spA0 = (f32) spA0 * -1.0f;
            }
            temp_r3_182 = this + temp_r31_82;
            M2C_FIELD(temp_r3_182, f64 *, 0x100) = sp98;
            M2C_FIELD(temp_r3_182, f64 *, 0x108) = (f64) spA0;
        } else {
            sp8 = M2C_FIELD(temp_r5_88, f64 *, 0x100);
            sp10 = M2C_FIELD(temp_r5_88, f64 *, 0x108);
            if ((((f32) sp10 * temp_f11_133) + (((f32) sp8 * temp_f10_125) + (unkspC * temp_f7_121))) < 0.0f) {
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f1 */);
                spA0 *= -1.0f;
            }
            M2C_FIELD(temp_r5_88, f64 *, 0x100) = sp98;
            M2C_FIELD(temp_r5_88, f64 *, 0x108) = (f64) spA0;
        }
    }
    temp_r3_214 = this + temp_r31_82;
    this->unk3F8 = 0;
    this->unk68 = M2C_FIELD(temp_r3_214, f64 *, 0x100);
    this->unk70 = M2C_FIELD(temp_r3_214, f64 *, 0x108);
    this->unk78 = M2C_FIELD(temp_r3_214, f32 *, 0x110);
    M2C_STRUCT_COPY((s32) &this->unk7C + 4, (s32) (temp_r3_214 + 0x114) + 4, 0x28);
    M2C_STRUCT_COPY((s32) &this->unkA4 + 4, (s32) (this + temp_r31_82 + 0x13C) + 4, 0x28);
    M2C_STRUCT_COPY((s32) &this->unkCC + 4, (s32) (this + temp_r31_82 + 0x164) + 4, 0x28);
    this->unkF8 = M2C_FIELD((this + temp_r31_82), u8 *, 0x190);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SB2::Calculate(unsigned int arg0) {
    AITargetData sp90;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp60;
    f64 sp50;
    MKVector3 sp40;
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
    AITargetData *temp_r3_323;
    Character *temp_r3_279;
    Matrix *temp_r3_341;
    Matrix *temp_r3_590;
    Matrix *temp_r5_419;
    f32 temp_f0_628;
    f32 temp_f0_634;
    f32 var_f1_612;
    f32 var_f1_632;
    s32 temp_r0_568;
    s32 temp_r3_425;
    s32 temp_r5_566;
    u32 temp_r3_564;
    u32 var_r29_280;
    u8 var_r30_327;
    void *temp_r3_284;
    void *temp_r3_486;

    temp_r3_279 = M2C_FIELD(arg0, Character **, 0);
    var_r29_280 = OSGetTick();
    temp_r3_284 = M2C_FIELD(temp_r3_279->__vptr, void *(**)(Character *), 0xFC)(temp_r3_279);
    sp8 = temp_r3_284;
    if (temp_r3_284 != NULL) {
        spC = M2C_FIELD(temp_r3_284, u8 *, 4);
        M2C_FIELD(temp_r3_284, u8 *, 4) = 0U;
    }
    ((Matrix *) (M2C_FIELD(arg0, Character **, 0)->unk8))->ZAxis3();
    sp10 = -*M2C_ERROR(/* Read from unset register $r3 */);
    sp14 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
    sp18 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
    M2C_FIELD(&vBaseHeading, f64 *, 0) = (f64) sp10;
    sp90.unk20 = (f64) sp10;
    sp90.unk28 = (f64) sp18;
    M2C_FIELD(&vBaseHeading, f64 *, 8) = (f64) sp18;
    if (fGameTimeLastUpdate != M2C_FIELD(&gb, f32 *, 0x30C)) {
        fGameTimeLastUpdate = M2C_FIELD(&gb, f32 *, 0x30C);
        gAvailableTicksThisUpdate = 0x5265C;
    }
    temp_r3_323 = M2C_FIELD(arg0, AITargetData **, 0xC);
    if (temp_r3_323 != NULL) {
        var_r30_327 = 0;
        if (((u8) M2C_FIELD(temp_r3_323, u8 *, 0x48) == 2) || (((TargetContext *) (temp_r3_323 + 0x40))->Get() != NULL)) {
            var_r30_327 = 1;
        }
        if (var_r30_327 != 0) {
            temp_r3_341 = M2C_FIELD(arg0, Character **, 0)->unk8;
            sp90.unk10 = M2C_FIELD(temp_r3_341, f64 *, 0x30);
            sp90.unk18 = M2C_FIELD(temp_r3_341, f64 *, 0x38);
            ((AITargetData *) (M2C_FIELD(arg0, AITargetData **, 0xC)))->Update(*((MKVector3 *) &sp90.unk10));
            sp90.GetDir();
            if (((sp90.unk8 * (f32) M2C_FIELD(&vBaseHeading, f64 *, 8)) + ((M2C_BITWISE(f32, sp90) * (f32) M2C_FIELD(&vBaseHeading, f64 *, 0)) + (unksp94 * M2C_FIELD(&vBaseHeading, f32 *, 4)))) > 0.35f) {
                sp80.GetDir();
                M2C_FIELD(&vBaseHeading, f64 *, 0) = sp80;
                M2C_FIELD(&vBaseHeading, f64 *, 8) = sp88;
            }
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 1) {
        arg0->SeekSetGoal();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 4) {
        arg0->ArriveSetGoal();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 8) {
        arg0->PursuitSetGoal();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x10) {
        arg0->RandomPursuitSetGoal();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x40) {
        arg0->WanderSetGoal();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x80) {
        arg0->PathFollowingSetGoal();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x4000) {
        arg0->GraphFollowingSetGoal();
    }
    temp_r5_419 = M2C_FIELD(arg0, Character **, 0)->unk8;
    sp70 = M2C_FIELD(temp_r5_419, f64 *, 0x30);
    sp78 = M2C_FIELD(temp_r5_419, f64 *, 0x38);
    ((AITargetData *) (arg0 + 0x18))->Update(*((MKVector3 *) &sp70));
    temp_r3_425 = M2C_FIELD(arg0, s32 *, 0x460);
    if (((temp_r3_425 & 0x80) || (temp_r3_425 & 0x4000)) && ((temp_r3_425 & 0x4000) || (sp60.GetDir(), ((((sp68 * (f32) M2C_FIELD(&vBaseHeading, f64 *, 8)) + ((sp60 * (f32) M2C_FIELD(&vBaseHeading, f64 *, 0)) + (sp64 * M2C_FIELD(&vBaseHeading, f32 *, 4)))) > 0.35f) != 0))) && (((AITargetData *) (arg0 + 0x18))->GetDist() > 0.0f)) {
        sp50.GetDir();
        M2C_FIELD(&vBaseHeading, f64 *, 0) = sp50;
        M2C_FIELD(&vBaseHeading, f64 *, 8) = sp58;
    }
loop_32:
    ((SteerDirection *) (arg0 + ((M2C_FIELD(arg0, s32 *, 0x3F8) * 0x98) + 0x100)))->Init();
    KDMath_RotateVectorByYaw(sp40, STEER_DIR_ANGLES[M2C_FIELD(arg0, s32 *, 0x3F8)]);
    temp_r3_486 = arg0 + ((M2C_FIELD(arg0, s32 *, 0x3F8) * 0x98) + 0x100);
    M2C_FIELD(temp_r3_486, f64 *, 0) = M2C_BITWISE(f64, sp40);
    M2C_FIELD(temp_r3_486, f64 *, 8) = (f64) sp40.unk8;
    if (M2C_FIELD(arg0, s32 *, 0x460) & 1) {
        arg0->Seek();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 4) {
        arg0->Arrive();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 8) {
        arg0->Pursuit();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x10) {
        arg0->RandomPursuit();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x40) {
        arg0->Wander();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x80) {
        arg0->PathFollowing();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x4000) {
        arg0->GraphFollowing();
    }
    if ((M2C_FIELD(arg0, s32 *, 0x460) & 0x200) && ((u8) M2C_FIELD(arg0, u8 *, 0x418) == 0)) {
        arg0->ObstacleAvoidance();
    }
    if ((M2C_FIELD(arg0, s32 *, 0x460) & 0x400) && ((u8) M2C_FIELD(arg0, u8 *, 0x418) == 0)) {
        arg0->WallAvoidance();
    }
    if ((M2C_FIELD(arg0, s32 *, 0x460) & 0x8000) && ((u8) M2C_FIELD(arg0, u8 *, 0x418) == 0)) {
        arg0->Containment();
    }
    if (M2C_FIELD(arg0, s32 *, 0x460) & 0x10000) {
        arg0->HazardAvoidance();
    }
    temp_r3_564 = OSGetTick();
    temp_r5_566 = temp_r3_564 - var_r29_280;
    var_r29_280 = temp_r3_564;
    temp_r0_568 = gAvailableTicksThisUpdate - temp_r5_566;
    gAvailableTicksThisUpdate = (gAvailableTicksThisUpdate - temp_r5_566) & ~((temp_r0_568 - temp_r0_568) - !M2C_CARRY);
    M2C_FIELD(arg0, s32 *, 0x3F8) = (s32) (M2C_FIELD(arg0, s32 *, 0x3F8) + 1);
    if (((u32) gAvailableTicksThisUpdate != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x3F8) < 5)) {
        goto loop_32;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x3F8) >= 5) {
        arg0->Arbitrate();
        temp_r3_590 = M2C_FIELD(arg0, Character **, 0)->unk8;
        sp20 = -temp_r3_590->unk20;
        sp24 = -temp_r3_590->unk24;
        sp28 = -temp_r3_590->unk28;
        sp30 = (f64) sp20;
        sp38 = (f64) sp28;
        var_f1_612 = ((f32) sp38 * M2C_FIELD(arg0, f32 *, 0x70)) + (((f32) sp30 * M2C_FIELD(arg0, f32 *, 0x68)) + (unksp34 * M2C_FIELD(arg0, f32 *, 0x6C)));
        if (var_f1_612 < 1.0f) {

        } else {
            var_f1_612 = 1.0f;
        }
        if (var_f1_612 > -1.0f) {

        } else {
            var_f1_612 = -1.0f;
        }
        temp_f0_628 = (f32) acos(var_f1_612);
        if (((u8) M2C_FIELD(arg0, u8 *, 0x464) >> 4U) & 1) {
            var_f1_632 = 0.0f;
            temp_f0_634 = (1.670796f - temp_f0_628) / 1.670796f;
            if (var_f1_632 > temp_f0_634) {

            } else {
                var_f1_632 = temp_f0_634;
            }
            ((Character *) (M2C_FIELD(arg0, Character **, 0)))->SetDesiredSpeed(var_f1_632);
        } else {
            ((Character *) (M2C_FIELD(arg0, Character **, 0)))->SetDesiredSpeed(1.0f);
        }
    }
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(arg0, f32 *, 0x68);
    this->unk8 = (f64) M2C_FIELD(arg0, f32 *, 0x70);
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SB2::GraphFollowingAny() {
    CharacterGraphNode *sp1AC;
    CharacterGraphNode *sp1A8;
    s32 sp1A4;
    s32 sp1A0;
    s32 sp19C;
    CharacterGraphNode *sp198;
    CharacterGraphNode *sp194;
    s32 sp190;
    s32 sp18C;
    s32 sp188;
    CharacterGraphNode *sp184;
    CharacterGraphNode *sp180;
    s32 sp17C;
    s32 sp178;
    s32 sp174;
    CharacterGraphNode *sp170;
    CharacterGraphNode *sp16C;
    s32 sp168;
    s32 sp164;
    s32 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    M2C_UNK sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    M2C_UNK spD0;
    f64 spC0;
    MKVector3 spB0;
    MKVector3 spA0;
    M2C_UNK sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    M2C_UNK sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    Character *temp_r3_1017;
    Character *temp_r3_1040;
    Character *temp_r3_1155;
    Character *temp_r3_693;
    Character *temp_r3_708;
    Character *temp_r3_837;
    CharacterGraphNode *temp_r29_847;
    CharacterGraphNode *temp_r31_1074;
    CharacterGraphNode *temp_r3_794;
    CharacterGraphNode *temp_r3_801;
    CharacterGraphNode *temp_r3_813;
    CharacterGraphNode *temp_r4_1077;
    CharacterGraphNode *temp_r4_1099;
    CharacterGraphNode *temp_r4_1131;
    CharacterGraphNode *temp_r4_678;
    CharacterGraphNode *temp_r4_850;
    CharacterGraphNode *temp_r4_872;
    CharacterGraphNode *temp_r4_993;
    CharacterGraphNode *temp_r5_1026;
    CharacterGraphNode *temp_r5_823;
    CharacterGraphNode *temp_r6_1003;
    CharacterGraphNode *temp_r6_1141;
    f32 temp_f0_712;
    f32 temp_f0_789;
    f32 temp_f0_901;
    f32 temp_f1_710;
    f32 temp_f1_720;
    f32 temp_f1_736;
    f32 temp_f1_900;
    f32 temp_f2_752;
    f32 temp_f3_734;
    f32 temp_f3_749;
    f32 temp_f3_903;
    f32 temp_f4_747;
    f32 var_f1_975;
    f32 var_f31_698;
    f32 var_f31_711;
    f32 var_f4_740;
    f32 var_f4_908;
    f64 temp_f1_681;
    f64 temp_f1_914;
    f64 temp_f1_920;
    f64 temp_f1_924;
    s32 temp_r0_1046;
    s32 temp_r0_1162;
    s32 temp_r0_1184;
    s32 temp_r3_943;
    s32 temp_r5_1005;
    s32 temp_r5_1143;
    s32 temp_r6_1035;
    s32 temp_r6_832;
    s32 var_r0_953;
    s32 var_r29_1058;
    s32 var_r31_808;
    void *temp_r5_679;

    temp_r4_678 = this->unk448;
    temp_r5_679 = this->unk0->unk8;
    temp_f1_681 = M2C_FIELD(temp_r5_679, f64 *, 0x30);
    sp150 = temp_f1_681;
    sp158 = M2C_FIELD(temp_r5_679, f64 *, 0x38);
    M2C_FIELD(temp_r4_678->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *, void *, f64), 0x30)(&sp130, temp_r4_678, temp_r5_679, temp_f1_681);
    sp140 = sp130;
    sp148 = sp138;
    temp_r3_693 = this->unk0;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_r3_693->unk694 == 0.0f) {
        var_f31_698 = 1.0f;
    } else {
        var_f31_698 = 3.0f;
    }
    temp_r3_708 = this->unk0;
    temp_f1_710 = temp_r3_708->unk68C;
    var_f31_711 = 50.0f;
    temp_f0_712 = (temp_f1_710 * gUpdateTimeDelta) + (M2C_FIELD(temp_r3_693->__vptr, f32 (**)(), 0x100)() / var_f31_698);
    if (var_f31_711 > temp_f0_712) {

    } else {
        var_f31_711 = temp_f0_712;
    }
    temp_f1_720 = KDMath_GetTurningCircleRadius(temp_f1_710, M2C_BITWISE(f32, temp_r3_708->unk684));
    if (var_f31_711 > temp_f1_720) {

    } else {
        var_f31_711 = temp_f1_720;
    }
    if (!(((u8) this->unk464 >> 5U) & 1)) {
        temp_f3_734 = (f32) sp158 - (f32) sp148;
        temp_f1_736 = (f32) sp150 - (f32) sp140;
        unksp154 = unksp144;
        var_f4_740 = (temp_f1_736 * temp_f1_736) + (temp_f3_734 * temp_f3_734);
    } else {
        temp_f4_747 = unksp154 - unksp144;
        temp_f3_749 = (f32) sp150 - (f32) sp140;
        temp_f2_752 = (f32) sp158 - (f32) sp148;
        var_f4_740 = (temp_f2_752 * temp_f2_752) + ((temp_f3_749 * temp_f3_749) + (temp_f4_747 * temp_f4_747));
    }
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp40 = sp30;
    sp38 = (f32) sp158 - (f32) sp148;
    sp48 = (f64) sp38;
    if ((var_f4_740 < (var_f31_711 * var_f31_711)) || (((u32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1) != 0) && (temp_f0_789 = 2.0f * var_f31_711, ((var_f4_740 < (temp_f0_789 * temp_f0_789)) != 0)))) {
        temp_r3_794 = this->unk448;
        if (temp_r3_794->GetNumLinks() > 0) {
            temp_r3_801 = this->unk448;
            if (temp_r3_801->GetNumLinks() == 1) {
                var_r31_808 = 0;
loop_19:
                temp_r3_813 = this->unk448;
                if (temp_r3_813->IsFreeLink(var_r31_808) != 0) {
                    var_r31_808 += 1;
                    goto loop_19;
                }
                this->unk448->SendArriveMessage();
                temp_r5_823 = this->unk448;
                if (((u8) temp_r5_823->unk80 >> 7U) & 1) {
                    sp1A0 = 0;
                    temp_r6_832 = temp_r5_823->unk44;
                    sp19C = 0x93;
                    sp1A4 = temp_r6_832;
                    sp1A8 = this->unk44C;
                    sp1AC = temp_r5_823;
                    temp_r3_837 = this->unk0;
                    temp_r3_837->Message(&sp19C, temp_r6_832);
                }
                temp_r29_847 = this->unk448->GetLink(var_r31_808);
                if (!(((u8) this->unk464 >> 5U) & 1)) {
                    temp_r4_850 = this->unk448;
                    M2C_FIELD(temp_r4_850->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp100, temp_r4_850);
                    M2C_FIELD(temp_r29_847->__vptr, M2C_UNK (**)(MKVector3 *, CharacterGraphNode *), 0x30)(&sp110, temp_r29_847);
                    KDMath_Sub2D(sp120, sp110);
                    M2C_FIELD(this, f32 *, 0x438) = M2C_BITWISE(f64, sp120);
                    M2C_FIELD(this, f32 *, 0x440) = (f64) sp120.unk8;
                } else {
                    temp_r4_872 = this->unk448;
                    M2C_FIELD(temp_r4_872->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&spD0, temp_r4_872);
                    M2C_FIELD(temp_r29_847->__vptr, M2C_UNK (**)(MKVector3 *, CharacterGraphNode *), 0x30)(&spE0, temp_r29_847);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    M2C_FIELD(this, f32 *, 0x438) = sp20;
                    sp28 = spE0.unk8 - spD8;
                    spF0 = sp20;
                    spF8 = (f64) sp28;
                    M2C_FIELD(this, f32 *, 0x440) = (f64) sp28;
                }
                temp_f1_900 = this->unk438;
                temp_f0_901 = this->unk43C;
                temp_f3_903 = this->unk440;
                var_f4_908 = (temp_f3_903 * temp_f3_903) + ((temp_f1_900 * temp_f1_900) + (temp_f0_901 * temp_f0_901));
                if (var_f4_908 > 0.000001f) {
                    if (var_f4_908 > 0.0f) {
                        temp_f1_914 = __frsqrte(var_f4_908);
                        temp_f1_920 = 0.5 * temp_f1_914 * -(((f64) var_f4_908 * (temp_f1_914 * temp_f1_914)) - 3.0);
                        temp_f1_924 = 0.5 * temp_f1_920 * -(((f64) var_f4_908 * (temp_f1_920 * temp_f1_920)) - 3.0);
                        var_f4_908 = (f32) ((f64) var_f4_908 * (0.5 * temp_f1_924 * -(((f64) var_f4_908 * (temp_f1_924 * temp_f1_924)) - 3.0)));
                    } else if (var_f4_908 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_908 = __float_nan;
                    } else {
                        sp8 = var_f4_908;
                        temp_r3_943 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_943) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_953 = 1;
                            } else {
                                var_r0_953 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_953 = 5;
                            } else {
                                var_r0_953 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_953 = 4;
                            break;
                        }
                        if (var_r0_953 == 1) {
                            var_f4_908 = __float_nan;
                        }
                    }
                    var_f1_975 = 1.0f / var_f4_908;
                } else {
                    var_f1_975 = 0.0f;
                }
                this->unk438 *= var_f1_975;
                this->unk43C *= var_f1_975;
                this->unk440 *= var_f1_975;
                this->unk44C = this->unk448;
                this->unk448 = temp_r29_847;
                temp_r4_993 = this->unk448;
                M2C_FIELD(temp_r4_993->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&spC0, temp_r4_993);
                sp140 = spC0;
                sp148 = spC8;
                temp_r6_1003 = this->unk44C;
                temp_r5_1005 = M2C_FIELD((temp_r6_1003 + (var_r31_808 * 4)), s32 *, 0x50);
                if (temp_r5_1005 != 0) {
                    sp18C = 0;
                    sp188 = 0x92;
                    sp190 = temp_r5_1005;
                    sp194 = temp_r6_1003;
                    sp198 = this->unk448;
                    temp_r3_1017 = this->unk0;
                    temp_r3_1017->Message(&sp188);
                }
            } else {
                this->unk448->SendArriveMessage();
                temp_r5_1026 = this->unk448;
                if (((u8) temp_r5_1026->unk80 >> 7U) & 1) {
                    sp178 = 0;
                    temp_r6_1035 = temp_r5_1026->unk44;
                    sp174 = 0x93;
                    sp17C = temp_r6_1035;
                    sp180 = this->unk44C;
                    sp184 = temp_r5_1026;
                    temp_r3_1040 = this->unk0;
                    temp_r3_1040->Message(&sp174, temp_r6_1035);
                }
                temp_r0_1046 = this->unk454;
                switch (temp_r0_1046) {             /* switch 2; irregular */
                case 1:                             /* switch 2 */
                    var_r29_1058 = GraphFollowing_EvadeSelectLink();
                    break;
                case 2:                             /* switch 2 */
                    var_r29_1058 = GraphFollowing_PursuitSelectLink();
                    break;
                default:                            /* switch 2 */
                    var_r29_1058 = GraphFollowing_RandomSelectLink();
                    break;
                }
                temp_r31_1074 = this->unk448->GetLink(var_r29_1058);
                if (!(((u8) this->unk464 >> 5U) & 1)) {
                    temp_r4_1077 = this->unk448;
                    M2C_FIELD(temp_r4_1077->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp90, temp_r4_1077);
                    M2C_FIELD(temp_r31_1074->__vptr, M2C_UNK (**)(MKVector3 *, CharacterGraphNode *), 0x30)(&spA0, temp_r31_1074);
                    KDMath_Sub2D(spB0, spA0);
                    M2C_FIELD(this, f32 *, 0x438) = M2C_BITWISE(f64, spB0);
                    M2C_FIELD(this, f32 *, 0x440) = (f64) spB0.unk8;
                } else {
                    temp_r4_1099 = this->unk448;
                    M2C_FIELD(temp_r4_1099->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp60, temp_r4_1099);
                    M2C_FIELD(temp_r31_1074->__vptr, M2C_UNK (**)(MKVector3 *, CharacterGraphNode *), 0x30)(&sp70, temp_r31_1074);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    M2C_FIELD(this, f32 *, 0x438) = sp10;
                    sp18 = sp70.unk8 - sp68;
                    sp80 = sp10;
                    sp88 = (f64) sp18;
                    M2C_FIELD(this, f32 *, 0x440) = (f64) sp18;
                }
                this->unk44C = this->unk448;
                this->unk448 = temp_r31_1074;
                temp_r4_1131 = this->unk448;
                M2C_FIELD(temp_r4_1131->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&sp50, temp_r4_1131);
                sp140 = sp50;
                sp148 = sp58;
                temp_r6_1141 = this->unk44C;
                temp_r5_1143 = M2C_FIELD((temp_r6_1141 + (var_r29_1058 * 4)), s32 *, 0x50);
                if (temp_r5_1143 != 0) {
                    sp164 = 0;
                    sp160 = 0x92;
                    sp168 = temp_r5_1143;
                    sp16C = temp_r6_1141;
                    sp170 = this->unk448;
                    temp_r3_1155 = this->unk0;
                    temp_r3_1155->Message(&sp160);
                }
            }
        } else {
            temp_r0_1162 = this->unk454;
            switch (temp_r0_1162) {                 /* switch 3; irregular */
            case 1:                                 /* switch 3 */
                GraphFollowing_EvadeNoMoreNodes();
                break;
            case 2:                                 /* switch 3 */
                GraphFollowing_PursuitNoMoreNodes();
                break;
            default:                                /* switch 3 */
                GraphFollowing_RandomNoMoreNodes();
                break;
            }
        }
    } else {
        temp_r0_1184 = this->unk454;
        switch (temp_r0_1184) {                     /* switch 4; irregular */
        case 1:                                     /* switch 4 */
            GraphFollowing_EvadeMidNodeTraversal();
            break;
        case 2:                                     /* switch 4 */
            GraphFollowing_PursuitMidNodeTraversal();
            break;
        default:                                    /* switch 4 */
            GraphFollowing_RandomMidNodeTraversal();
            break;
        }
    }
    if (!(((u8) this->unk464 >> 5U) & 1)) {
        unksp144 = unksp154;
    }
    this->unk18.Set(*((MKVector3 *) &sp140), 0U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'AITargetData' to
void SB2::GraphFollowing_EvadeMidNodeTraversal() {
    f64 sp110;
    f64 sp108;
    AITargetData spB8;
    f64 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    M2C_UNK sp78;
    f64 sp70;
    f64 sp68;
    M2C_UNK sp58;
    M2C_UNK sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    CharacterGraphNode *temp_r3_1613;
    CharacterGraphNode *temp_r4_1232;
    CharacterGraphNode *temp_r4_1248;
    CharacterGraphNode *temp_r4_1474;
    CharacterGraphNode *temp_r4_1480;
    CharacterGraphNode *temp_r4_1496;
    CharacterGraphNode *temp_r4_1502;
    f32 temp_f0_1525;
    f32 temp_f1_1524;
    f32 temp_f3_1527;
    f32 temp_f4_1461;
    f32 temp_f5_1455;
    f32 temp_f6_1457;
    f32 var_f1_1599;
    f32 var_f4_1289;
    f32 var_f4_1448;
    f32 var_f4_1532;
    f32 var_f6_1359;
    f32 var_f7_1377;
    f64 temp_f1_1250;
    f64 temp_f1_1298;
    f64 temp_f1_1304;
    f64 temp_f1_1308;
    f64 temp_f1_1387;
    f64 temp_f1_1393;
    f64 temp_f1_1397;
    f64 temp_f1_1538;
    f64 temp_f1_1544;
    f64 temp_f1_1548;
    s32 temp_r3_1327;
    s32 temp_r3_1416;
    s32 temp_r3_1567;
    s32 var_r0_1337;
    s32 var_r0_1426;
    s32 var_r0_1577;
    void *temp_r5_1242;

    temp_r4_1232 = this->unk44C;
    if ((temp_r4_1232 != NULL) && (this->unk448->IsLinked(temp_r4_1232) != 0)) {
        temp_r5_1242 = this->unk0->unk8;
        sp108 = M2C_FIELD(temp_r5_1242, f64 *, 0x30);
        sp110 = M2C_FIELD(temp_r5_1242, f64 *, 0x38);
        spB8.GetPos();
        temp_r4_1248 = this->unk448;
        temp_f1_1250 = M2C_BITWISE(f64, spB8);
        spB8.unk40 = temp_f1_1250;
        spB8.unk40.unk8 = (f64) spB8.unk8;
        M2C_FIELD(temp_r4_1248->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *, f64), 0x30)(&spA8, temp_r4_1248, temp_f1_1250);
        spB8.unk30 = spA8;
        spB8.unk38 = spB0;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
        spB8.unk20 = sp38;
        sp40 = M2C_BITWISE(f32, spB8.unk40.unk8) - (f32) sp110;
        spB8.unk28 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
        sp30 = spB8.unk38 - (f32) sp110;
        var_f4_1289 = ((f32) spB8.unk28 * (f32) spB8.unk28) + (((f32) spB8.unk20 * (f32) spB8.unk20) + (unkspDC * unkspDC));
        spB8.unk10 = sp28;
        spB8.unk18 = (f64) sp30;
        if (var_f4_1289 > 0.000001f) {
            if (var_f4_1289 > 0.0f) {
                temp_f1_1298 = __frsqrte(var_f4_1289);
                temp_f1_1304 = 0.5 * temp_f1_1298 * -(((f64) var_f4_1289 * (temp_f1_1298 * temp_f1_1298)) - 3.0);
                temp_f1_1308 = 0.5 * temp_f1_1304 * -(((f64) var_f4_1289 * (temp_f1_1304 * temp_f1_1304)) - 3.0);
                var_f4_1289 = (f32) ((f64) var_f4_1289 * (0.5 * temp_f1_1308 * -(((f64) var_f4_1289 * (temp_f1_1308 * temp_f1_1308)) - 3.0)));
            } else if (var_f4_1289 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1289 = __float_nan;
            } else {
                sp10 = var_f4_1289;
                temp_r3_1327 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1327) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1337 = 1;
                    } else {
                        var_r0_1337 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1337 = 5;
                    } else {
                        var_r0_1337 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_1337 = 4;
                    break;
                }
                if (var_r0_1337 == 1) {
                    var_f4_1289 = __float_nan;
                }
            }
            var_f6_1359 = 1.0f / var_f4_1289;
        } else {
            var_f6_1359 = 0.0f;
        }
        var_f7_1377 = ((f32) spB8.unk18 * (f32) spB8.unk18) + (((f32) spB8.unk10 * (f32) spB8.unk10) + (unkspCC * unkspCC));
        spB8.unk20 = (f32) spB8.unk20 * var_f6_1359;
        unkspDC *= var_f6_1359;
        spB8.unk28 = (f32) spB8.unk28 * var_f6_1359;
        if (var_f7_1377 > 0.000001f) {
            if (var_f7_1377 > 0.0f) {
                temp_f1_1387 = __frsqrte(var_f7_1377);
                temp_f1_1393 = 0.5 * temp_f1_1387 * -(((f64) var_f7_1377 * (temp_f1_1387 * temp_f1_1387)) - 3.0);
                temp_f1_1397 = 0.5 * temp_f1_1393 * -(((f64) var_f7_1377 * (temp_f1_1393 * temp_f1_1393)) - 3.0);
                var_f7_1377 = (f32) ((f64) var_f7_1377 * (0.5 * temp_f1_1397 * -(((f64) var_f7_1377 * (temp_f1_1397 * temp_f1_1397)) - 3.0)));
            } else if (var_f7_1377 < M2C_BITWISE(f32, 0.0)) {
                var_f7_1377 = __float_nan;
            } else {
                spC = var_f7_1377;
                temp_r3_1416 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_1416) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1426 = 1;
                    } else {
                        var_r0_1426 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1426 = 5;
                    } else {
                        var_r0_1426 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1426 = 4;
                    break;
                }
                if (var_r0_1426 == 1) {
                    var_f7_1377 = __float_nan;
                }
            }
            var_f4_1448 = 1.0f / var_f7_1377;
        } else {
            var_f4_1448 = 0.0f;
        }
        temp_f5_1455 = unkspCC * var_f4_1448;
        temp_f6_1457 = (f32) spB8.unk10 * var_f4_1448;
        temp_f4_1461 = (f32) spB8.unk18 * var_f4_1448;
        spB8.unk10 = temp_f6_1457;
        unkspCC = temp_f5_1455;
        spB8.unk18 = temp_f4_1461;
        if (((spB8.unk28 * temp_f4_1461) + ((spB8.unk20 * temp_f6_1457) + (unkspDC * temp_f5_1455))) > 0.95f) {
            if (!(((u8) this->unk464 >> 5U) & 1)) {
                temp_r4_1474 = this->unk448;
                M2C_FIELD(temp_r4_1474->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp78, temp_r4_1474);
                temp_r4_1480 = this->unk44C;
                M2C_FIELD(temp_r4_1480->__vptr, M2C_UNK (**)(MKVector3 *, CharacterGraphNode *), 0x30)(&sp88, temp_r4_1480);
                KDMath_Sub2D(sp98, sp88);
                M2C_FIELD(this, f64 *, 0x438) = M2C_BITWISE(f64, sp98);
                M2C_FIELD(this, f64 *, 0x440) = (f64) sp98.unk8;
            } else {
                temp_r4_1496 = this->unk448;
                M2C_FIELD(temp_r4_1496->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp48, temp_r4_1496);
                temp_r4_1502 = this->unk44C;
                M2C_FIELD(temp_r4_1502->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp58, temp_r4_1502);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0x438) = sp18;
                sp20 = sp60 - sp50;
                sp68 = sp18;
                sp70 = (f64) sp20;
                M2C_FIELD(this, f64 *, 0x440) = (f64) sp20;
            }
            temp_f1_1524 = this->unk438;
            temp_f0_1525 = this->unk43C;
            temp_f3_1527 = this->unk440;
            var_f4_1532 = (temp_f3_1527 * temp_f3_1527) + ((temp_f1_1524 * temp_f1_1524) + (temp_f0_1525 * temp_f0_1525));
            if (var_f4_1532 > 0.000001f) {
                if (var_f4_1532 > 0.0f) {
                    temp_f1_1538 = __frsqrte(var_f4_1532);
                    temp_f1_1544 = 0.5 * temp_f1_1538 * -(((f64) var_f4_1532 * (temp_f1_1538 * temp_f1_1538)) - 3.0);
                    temp_f1_1548 = 0.5 * temp_f1_1544 * -(((f64) var_f4_1532 * (temp_f1_1544 * temp_f1_1544)) - 3.0);
                    var_f4_1532 = (f32) ((f64) var_f4_1532 * (0.5 * temp_f1_1548 * -(((f64) var_f4_1532 * (temp_f1_1548 * temp_f1_1548)) - 3.0)));
                } else if (var_f4_1532 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1532 = __float_nan;
                } else {
                    sp8 = var_f4_1532;
                    temp_r3_1567 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1567) {         /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1577 = 1;
                        } else {
                            var_r0_1577 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1577 = 5;
                        } else {
                            var_r0_1577 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_1577 = 4;
                        break;
                    }
                    if (var_r0_1577 == 1) {
                        var_f4_1532 = __float_nan;
                    }
                }
                var_f1_1599 = 1.0f / var_f4_1532;
            } else {
                var_f1_1599 = 0.0f;
            }
            this->unk438 *= var_f1_1599;
            this->unk43C *= var_f1_1599;
            this->unk440 *= var_f1_1599;
            temp_r3_1613 = this->unk44C;
            this->unk44C = this->unk448;
            this->unk448 = temp_r3_1613;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SB2::GraphFollowing_EvadeNoMoreNodes() {
    CharacterGraphNode *sp2C;
    CharacterGraphNode *sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    CharacterGraphNode *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Character *temp_r3_1652;
    Character *temp_r3_1668;
    CharacterGraphNode *temp_r6_1638;
    s32 temp_r5_1647;

    if ((u8) this->unk458 == 0) {
        this->unk448->SendArriveMessage();
        temp_r6_1638 = this->unk448;
        if (((u8) temp_r6_1638->unk80 >> 7U) & 1) {
            sp20 = 0;
            temp_r5_1647 = temp_r6_1638->unk44;
            sp1C = 0x93;
            sp24 = temp_r5_1647;
            sp28 = this->unk44C;
            sp2C = temp_r6_1638;
            temp_r3_1652 = this->unk0;
            temp_r3_1652->Message(&sp1C, temp_r5_1647);
        } else {
            spC = 0;
            sp8 = 0x93;
            sp10 = 1;
            sp14 = 0;
            sp18 = temp_r6_1638;
            temp_r3_1668 = this->unk0;
            temp_r3_1668->Message(&sp8, 0);
        }
        this->unk458 = 1;
    }
    if (((u8) this->unk464 >> 4U) & 1) {
        this->unk0->SetDesiredSpeed(0.0f);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 SB2::GraphFollowing_EvadeSelectLink() {
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;                                      /* compiler-managed */
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;                                      /* compiler-managed */
    f32 sp118;
    f32 sp108;
    f32 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    M2C_UNK spC8;
    f64 spC0;
    f64 spB8;
    M2C_UNK spA8;
    f64 spA0;
    f64 sp98;
    M2C_UNK sp88;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r3_1709;
    CharacterGraphNode *temp_r3_2025;
    CharacterGraphNode *temp_r3_2037;
    CharacterGraphNode *temp_r3_2046;
    CharacterGraphNode *temp_r3_2168;
    f32 temp_f0_1847;
    f32 temp_f0_2159;
    f32 temp_f28_1774;
    f32 temp_f2_2153;
    f32 temp_f2_2280;
    f32 temp_f30_2019;
    f32 temp_f31_2020;
    f32 temp_f3_2149;
    f32 temp_f3_2276;
    f32 temp_f4_2151;
    f32 temp_f4_2278;
    f32 var_f1_1876;
    f32 var_f27_1739;
    f32 var_f28_1848;
    f32 var_f29_1742;
    f32 var_f2_2142;
    f32 var_f2_2268;
    f32 var_f3_2009;
    f32 var_f4_1784;
    f32 var_f4_1942;
    f32 var_f4_2075;
    f32 var_f4_2201;
    f64 temp_f1_1787;
    f64 temp_f1_1793;
    f64 temp_f1_1797;
    f64 temp_f1_1948;
    f64 temp_f1_1954;
    f64 temp_f1_1958;
    f64 temp_f1_2081;
    f64 temp_f1_2087;
    f64 temp_f1_2091;
    f64 temp_f1_2207;
    f64 temp_f1_2213;
    f64 temp_f1_2217;
    f64 temp_f3_1746;
    s32 temp_r3_1816;
    s32 temp_r3_1977;
    s32 temp_r3_2110;
    s32 temp_r3_2236;
    s32 var_r0_1826;
    s32 var_r0_1987;
    s32 var_r0_2120;
    s32 var_r0_2246;
    s32 var_r30_2015;
    s32 var_r31_1735;
    void *temp_r30_1714;
    void *temp_r4_1728;
    void *temp_r4_1738;
    void *temp_r5_1736;

    temp_r3_1709 = this->unk0;
    temp_r30_1714 = M2C_FIELD(M2C_FIELD(temp_r3_1709->__vptr, void *(**)(Character *), 0xD4)(temp_r3_1709), void **, 0xA38);
    if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) < M2C_FIELD(temp_r30_1714, f32 *, 0x144)) {
        return GraphFollowing_RandomSelectLink();
    }
    temp_r4_1728 = this->unk0->unk8;
    sp178 = M2C_FIELD(temp_r4_1728, f64 *, 0x30);
    sp180 = M2C_FIELD(temp_r4_1728, f64 *, 0x38);
    var_r31_1735 = -1;
    temp_r5_1736 = M2C_FIELD(this->unk450->GetProp(), void **, 8);
    temp_r4_1738 = this->unk0->unk8;
    var_f27_1739 = 0.0f;
    var_f29_1742 = 0.0f;
    temp_f3_1746 = M2C_FIELD(temp_r5_1736, f64 *, 0x30);
    sp58 = -M2C_FIELD(temp_r4_1738, f32 *, 0x20);
    sp5C = -M2C_FIELD(temp_r4_1738, f32 *, 0x24);
    sp60 = -M2C_FIELD(temp_r4_1738, f32 *, 0x28);
    sp168 = temp_f3_1746;
    sp170 = M2C_FIELD(temp_r5_1736, f64 *, 0x38);
    sp148 = (f64) sp58;
    sp150 = (f64) sp60;
    sp118.GetVel();
    if (((sp120 * sp120) + ((sp118 * sp118) + (sp11C * sp11C))) > 0.01f) {
        temp_f28_1774 = M2C_BITWISE(f32, this->unk0->unk688);
        sp108.GetVel();
        var_f4_1784 = (sp110 * sp110) + ((sp108 * sp108) + (sp10C * sp10C));
        if (var_f4_1784 > 0.0f) {
            temp_f1_1787 = __frsqrte(var_f4_1784);
            temp_f1_1793 = 0.5 * temp_f1_1787 * -(((f64) var_f4_1784 * (temp_f1_1787 * temp_f1_1787)) - 3.0);
            temp_f1_1797 = 0.5 * temp_f1_1793 * -(((f64) var_f4_1784 * (temp_f1_1793 * temp_f1_1793)) - 3.0);
            var_f4_1784 = (f32) ((f64) var_f4_1784 * (0.5 * temp_f1_1797 * -(((f64) var_f4_1784 * (temp_f1_1797 * temp_f1_1797)) - 3.0)));
        } else if (var_f4_1784 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1784 = __float_nan;
        } else {
            sp14 = var_f4_1784;
            temp_r3_1816 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_1816) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1826 = 1;
                } else {
                    var_r0_1826 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1826 = 5;
                } else {
                    var_r0_1826 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1826 = 4;
                break;
            }
            if (var_r0_1826 == 1) {
                var_f4_1784 = __float_nan;
            }
        }
        temp_f0_1847 = temp_f28_1774 + var_f4_1784;
        var_f28_1848 = 1.0f;
        if (var_f28_1848 > temp_f0_1847) {

        } else {
            var_f28_1848 = temp_f0_1847;
        }
        var_f29_1742 = this->unk450->GetDist() / var_f28_1848;
    }
    if (M2C_BITWISE(f32, this->unk0->unk684) > 0.0f) {
        spF8.GetDir();
        var_f1_1876 = ((f32) sp150 * sp100) + (((f32) sp148 * spF8) + (unksp14C * spFC));
        if (var_f1_1876 < 1.0f) {

        } else {
            var_f1_1876 = 1.0f;
        }
        if (var_f1_1876 > -1.0f) {

        } else {
            var_f1_1876 = -1.0f;
        }
        var_f29_1742 += (f32) acos(var_f1_1876) / M2C_BITWISE(f32, this->unk0->unk684);
    }
    unksp16C = unksp17C;
    spC8.GetVel();
    spD8.operator*(var_f29_1742);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp138 = sp48;
    sp50 = (f32) sp170 + spD8.unk8;
    spE8 = sp48;
    spF0 = (f64) sp50;
    sp140 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp138 = sp38;
    sp40 = (f32) sp140 - (f32) sp180;
    spB8 = sp38;
    sp140 = (f64) sp40;
    spC0 = (f64) sp40;
    var_f4_1942 = ((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + (unksp13C * unksp13C));
    if (var_f4_1942 > 0.000001f) {
        if (var_f4_1942 > 0.0f) {
            temp_f1_1948 = __frsqrte(var_f4_1942);
            temp_f1_1954 = 0.5 * temp_f1_1948 * -(((f64) var_f4_1942 * (temp_f1_1948 * temp_f1_1948)) - 3.0);
            temp_f1_1958 = 0.5 * temp_f1_1954 * -(((f64) var_f4_1942 * (temp_f1_1954 * temp_f1_1954)) - 3.0);
            var_f4_1942 = (f32) ((f64) var_f4_1942 * (0.5 * temp_f1_1958 * -(((f64) var_f4_1942 * (temp_f1_1958 * temp_f1_1958)) - 3.0)));
        } else if (var_f4_1942 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1942 = __float_nan;
        } else {
            sp10 = var_f4_1942;
            temp_r3_1977 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1977) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1987 = 1;
                } else {
                    var_r0_1987 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1987 = 5;
                } else {
                    var_r0_1987 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1987 = 4;
                break;
            }
            if (var_r0_1987 == 1) {
                var_f4_1942 = __float_nan;
            }
        }
        var_f3_2009 = 1.0f / var_f4_1942;
    } else {
        var_f3_2009 = 0.0f;
    }
    var_r30_2015 = 0;
    temp_f30_2019 = unksp13C * var_f3_2009;
    temp_f31_2020 = (f32) sp140 * var_f3_2009;
    sp138 = (f32) sp138 * var_f3_2009;
    unksp13C = temp_f30_2019;
    sp140 = temp_f31_2020;
    do {
        temp_r3_2025 = this->unk448;
        if (temp_r3_2025->IsFreeLink(var_r30_2015) == 0) {
            if (var_r31_1735 != -1) {
                temp_r3_2037 = this->unk448->GetLink(var_r30_2015);
                M2C_FIELD(temp_r3_2037->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&spA8, temp_r3_2037);
                temp_r3_2046 = this->unk448->GetLink(var_r30_2015);
                M2C_FIELD(temp_r3_2046->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp88, temp_r3_2046);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp128 = sp28;
                sp30 = sp90 - (f32) sp180;
                sp130 = (f64) sp30;
                sp98 = sp28;
                spA0 = (f64) sp30;
                var_f4_2075 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + (unksp12C * unksp12C));
                if (var_f4_2075 > 0.000001f) {
                    if (var_f4_2075 > 0.0f) {
                        temp_f1_2081 = __frsqrte(var_f4_2075);
                        temp_f1_2087 = 0.5 * temp_f1_2081 * -(((f64) var_f4_2075 * (temp_f1_2081 * temp_f1_2081)) - 3.0);
                        temp_f1_2091 = 0.5 * temp_f1_2087 * -(((f64) var_f4_2075 * (temp_f1_2087 * temp_f1_2087)) - 3.0);
                        var_f4_2075 = (f32) ((f64) var_f4_2075 * (0.5 * temp_f1_2091 * -(((f64) var_f4_2075 * (temp_f1_2091 * temp_f1_2091)) - 3.0)));
                    } else if (var_f4_2075 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2075 = __float_nan;
                    } else {
                        spC = var_f4_2075;
                        temp_r3_2110 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_2110) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_2120 = 1;
                            } else {
                                var_r0_2120 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_2120 = 5;
                            } else {
                                var_r0_2120 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_2120 = 4;
                            break;
                        }
                        if (var_r0_2120 == 1) {
                            var_f4_2075 = __float_nan;
                        }
                    }
                    var_f2_2142 = 1.0f / var_f4_2075;
                } else {
                    var_f2_2142 = 0.0f;
                }
                temp_f3_2149 = unksp12C * var_f2_2142;
                temp_f4_2151 = (f32) sp128 * var_f2_2142;
                temp_f2_2153 = (f32) sp130 * var_f2_2142;
                sp128 = temp_f4_2151;
                unksp12C = temp_f3_2149;
                sp130 = temp_f2_2153;
                temp_f0_2159 = (temp_f2_2153 * temp_f31_2020) + ((temp_f4_2151 * sp138) + (temp_f3_2149 * temp_f30_2019));
                if (temp_f0_2159 < var_f27_1739) {
                    var_f27_1739 = temp_f0_2159;
                    var_r31_1735 = var_r30_2015;
                }
            } else {
                temp_r3_2168 = this->unk448->GetLink(var_r30_2015);
                M2C_FIELD(temp_r3_2168->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&sp78, temp_r3_2168);
                sp158 = sp78;
                unksp15C = unksp17C;
                sp160 = sp80;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp128 = sp18;
                sp20 = (f32) sp160 - (f32) sp180;
                sp130 = (f64) sp20;
                sp68 = sp18;
                sp70 = (f64) sp20;
                var_f4_2201 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + (unksp12C * unksp12C));
                if (var_f4_2201 > 0.000001f) {
                    if (var_f4_2201 > 0.0f) {
                        temp_f1_2207 = __frsqrte(var_f4_2201);
                        temp_f1_2213 = 0.5 * temp_f1_2207 * -(((f64) var_f4_2201 * (temp_f1_2207 * temp_f1_2207)) - 3.0);
                        temp_f1_2217 = 0.5 * temp_f1_2213 * -(((f64) var_f4_2201 * (temp_f1_2213 * temp_f1_2213)) - 3.0);
                        var_f4_2201 = (f32) ((f64) var_f4_2201 * (0.5 * temp_f1_2217 * -(((f64) var_f4_2201 * (temp_f1_2217 * temp_f1_2217)) - 3.0)));
                    } else if (var_f4_2201 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2201 = __float_nan;
                    } else {
                        sp8 = var_f4_2201;
                        temp_r3_2236 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_2236) {     /* switch 4; irregular */
                        case 0x7F800000:            /* switch 4 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_2246 = 1;
                            } else {
                                var_r0_2246 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 4 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_2246 = 5;
                            } else {
                                var_r0_2246 = 3;
                            }
                            break;
                        default:                    /* switch 4 */
                            var_r0_2246 = 4;
                            break;
                        }
                        if (var_r0_2246 == 1) {
                            var_f4_2201 = __float_nan;
                        }
                    }
                    var_f2_2268 = 1.0f / var_f4_2201;
                } else {
                    var_f2_2268 = 0.0f;
                }
                var_r31_1735 = var_r30_2015;
                temp_f3_2276 = unksp12C * var_f2_2268;
                temp_f4_2278 = (f32) sp128 * var_f2_2268;
                temp_f2_2280 = (f32) sp130 * var_f2_2268;
                sp128 = temp_f4_2278;
                unksp12C = temp_f3_2276;
                sp130 = temp_f2_2280;
                var_f27_1739 = (temp_f2_2280 * temp_f31_2020) + ((temp_f4_2278 * sp138) + (temp_f3_2276 * temp_f30_2019));
            }
        }
        var_r30_2015 += 1;
    } while (var_r30_2015 < 6);
    return var_r31_1735;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'AITargetData' to
void SB2::GraphFollowing_PursuitMidNodeTraversal() {
    f64 sp108;
    f64 sp100;
    AITargetData spB0;
    f64 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
    M2C_UNK sp70;
    f64 sp68;
    f64 sp60;
    M2C_UNK sp50;
    M2C_UNK sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    CharacterGraphNode *temp_r3_2606;
    CharacterGraphNode *temp_r4_2330;
    CharacterGraphNode *temp_r4_2556;
    CharacterGraphNode *temp_r4_2562;
    CharacterGraphNode *temp_r4_2578;
    CharacterGraphNode *temp_r4_2584;
    f32 temp_f4_2543;
    f32 temp_f5_2537;
    f32 temp_f6_2539;
    f32 var_f4_2371;
    f32 var_f4_2530;
    f32 var_f6_2441;
    f32 var_f7_2459;
    f64 temp_f1_2332;
    f64 temp_f1_2380;
    f64 temp_f1_2386;
    f64 temp_f1_2390;
    f64 temp_f1_2469;
    f64 temp_f1_2475;
    f64 temp_f1_2479;
    s32 temp_r3_2409;
    s32 temp_r3_2498;
    s32 var_r0_2419;
    s32 var_r0_2508;
    void *temp_r5_2324;

    if ((CharacterGraphNode *) this->unk44C != NULL) {
        temp_r5_2324 = this->unk0->unk8;
        sp100 = M2C_FIELD(temp_r5_2324, f64 *, 0x30);
        sp108 = M2C_FIELD(temp_r5_2324, f64 *, 0x38);
        spB0.GetPos();
        temp_r4_2330 = this->unk448;
        temp_f1_2332 = M2C_BITWISE(f64, spB0);
        spB0.unk40 = temp_f1_2332;
        spB0.unk40.unk8 = (f64) spB0.unk8;
        M2C_FIELD(temp_r4_2330->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *, f64), 0x30)(&spA0, temp_r4_2330, temp_f1_2332);
        spB0.unk30 = spA0;
        spB0.unk38 = spA8;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
        spB0.unk20 = sp30;
        sp38 = M2C_BITWISE(f32, spB0.unk40.unk8) - (f32) sp108;
        spB0.unk28 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
        sp28 = spB0.unk38 - (f32) sp108;
        var_f4_2371 = ((f32) spB0.unk28 * (f32) spB0.unk28) + (((f32) spB0.unk20 * (f32) spB0.unk20) + (unkspD4 * unkspD4));
        spB0.unk10 = sp20;
        spB0.unk18 = (f64) sp28;
        if (var_f4_2371 > 0.000001f) {
            if (var_f4_2371 > 0.0f) {
                temp_f1_2380 = __frsqrte(var_f4_2371);
                temp_f1_2386 = 0.5 * temp_f1_2380 * -(((f64) var_f4_2371 * (temp_f1_2380 * temp_f1_2380)) - 3.0);
                temp_f1_2390 = 0.5 * temp_f1_2386 * -(((f64) var_f4_2371 * (temp_f1_2386 * temp_f1_2386)) - 3.0);
                var_f4_2371 = (f32) ((f64) var_f4_2371 * (0.5 * temp_f1_2390 * -(((f64) var_f4_2371 * (temp_f1_2390 * temp_f1_2390)) - 3.0)));
            } else if (var_f4_2371 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2371 = __float_nan;
            } else {
                spC = var_f4_2371;
                temp_r3_2409 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_2409) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2419 = 1;
                    } else {
                        var_r0_2419 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2419 = 5;
                    } else {
                        var_r0_2419 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_2419 = 4;
                    break;
                }
                if (var_r0_2419 == 1) {
                    var_f4_2371 = __float_nan;
                }
            }
            var_f6_2441 = 1.0f / var_f4_2371;
        } else {
            var_f6_2441 = 0.0f;
        }
        var_f7_2459 = ((f32) spB0.unk18 * (f32) spB0.unk18) + (((f32) spB0.unk10 * (f32) spB0.unk10) + (unkspC4 * unkspC4));
        spB0.unk20 = (f32) spB0.unk20 * var_f6_2441;
        unkspD4 *= var_f6_2441;
        spB0.unk28 = (f32) spB0.unk28 * var_f6_2441;
        if (var_f7_2459 > 0.000001f) {
            if (var_f7_2459 > 0.0f) {
                temp_f1_2469 = __frsqrte(var_f7_2459);
                temp_f1_2475 = 0.5 * temp_f1_2469 * -(((f64) var_f7_2459 * (temp_f1_2469 * temp_f1_2469)) - 3.0);
                temp_f1_2479 = 0.5 * temp_f1_2475 * -(((f64) var_f7_2459 * (temp_f1_2475 * temp_f1_2475)) - 3.0);
                var_f7_2459 = (f32) ((f64) var_f7_2459 * (0.5 * temp_f1_2479 * -(((f64) var_f7_2459 * (temp_f1_2479 * temp_f1_2479)) - 3.0)));
            } else if (var_f7_2459 < M2C_BITWISE(f32, 0.0)) {
                var_f7_2459 = __float_nan;
            } else {
                sp8 = var_f7_2459;
                temp_r3_2498 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_2498) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2508 = 1;
                    } else {
                        var_r0_2508 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2508 = 5;
                    } else {
                        var_r0_2508 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2508 = 4;
                    break;
                }
                if (var_r0_2508 == 1) {
                    var_f7_2459 = __float_nan;
                }
            }
            var_f4_2530 = 1.0f / var_f7_2459;
        } else {
            var_f4_2530 = 0.0f;
        }
        temp_f5_2537 = unkspC4 * var_f4_2530;
        temp_f6_2539 = (f32) spB0.unk10 * var_f4_2530;
        temp_f4_2543 = (f32) spB0.unk18 * var_f4_2530;
        spB0.unk10 = temp_f6_2539;
        unkspC4 = temp_f5_2537;
        spB0.unk18 = temp_f4_2543;
        if (((spB0.unk28 * temp_f4_2543) + ((spB0.unk20 * temp_f6_2539) + (unkspD4 * temp_f5_2537))) < -0.95f) {
            if (!(((u8) this->unk464 >> 5U) & 1)) {
                temp_r4_2556 = this->unk448;
                M2C_FIELD(temp_r4_2556->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp70, temp_r4_2556);
                temp_r4_2562 = this->unk44C;
                M2C_FIELD(temp_r4_2562->__vptr, M2C_UNK (**)(MKVector3 *, CharacterGraphNode *), 0x30)(&sp80, temp_r4_2562);
                KDMath_Sub2D(sp90, sp80);
                M2C_FIELD(this, f64 *, 0x438) = M2C_BITWISE(f64, sp90);
                M2C_FIELD(this, f64 *, 0x440) = (f64) sp90.unk8;
            } else {
                temp_r4_2578 = this->unk448;
                M2C_FIELD(temp_r4_2578->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp40, temp_r4_2578);
                temp_r4_2584 = this->unk44C;
                M2C_FIELD(temp_r4_2584->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp50, temp_r4_2584);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0x438) = sp10;
                sp18 = sp58 - sp48;
                sp60 = sp10;
                sp68 = (f64) sp18;
                M2C_FIELD(this, f64 *, 0x440) = (f64) sp18;
            }
            temp_r3_2606 = this->unk44C;
            this->unk44C = this->unk448;
            this->unk448 = temp_r3_2606;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SB2::GraphFollowing_PursuitNoMoreNodes() {
    CharacterGraphNode *sp2C;
    CharacterGraphNode *sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    CharacterGraphNode *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Character *temp_r3_2645;
    Character *temp_r3_2661;
    CharacterGraphNode *temp_r6_2631;
    s32 temp_r5_2640;

    if ((u8) this->unk458 == 0) {
        this->unk448->SendArriveMessage();
        temp_r6_2631 = this->unk448;
        if (((u8) temp_r6_2631->unk80 >> 7U) & 1) {
            sp20 = 0;
            temp_r5_2640 = temp_r6_2631->unk44;
            sp1C = 0x93;
            sp24 = temp_r5_2640;
            sp28 = this->unk44C;
            sp2C = temp_r6_2631;
            temp_r3_2645 = this->unk0;
            temp_r3_2645->Message(&sp1C, temp_r5_2640);
        } else {
            spC = 0;
            sp8 = 0x93;
            sp10 = 1;
            sp14 = 0;
            sp18 = temp_r6_2631;
            temp_r3_2661 = this->unk0;
            temp_r3_2661->Message(&sp8, 0);
        }
        this->unk458 = 1;
    }
    if (((u8) this->unk464 >> 4U) & 1) {
        this->unk0->SetDesiredSpeed(0.0f);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
s32 SB2::GraphFollowing_PursuitSelectLink() {
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;                                      /* compiler-managed */
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;                                      /* compiler-managed */
    f32 sp118;
    f32 sp108;
    f32 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    M2C_UNK spC8;
    f64 spC0;
    f64 spB8;
    M2C_UNK spA8;
    f64 spA0;
    f64 sp98;
    M2C_UNK sp88;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    CharacterGraphNode *temp_r3_3001;
    CharacterGraphNode *temp_r3_3013;
    CharacterGraphNode *temp_r3_3022;
    CharacterGraphNode *temp_r3_3144;
    f32 temp_f0_2823;
    f32 temp_f0_3135;
    f32 temp_f28_2750;
    f32 temp_f2_3129;
    f32 temp_f2_3256;
    f32 temp_f30_2995;
    f32 temp_f31_2996;
    f32 temp_f3_3125;
    f32 temp_f3_3252;
    f32 temp_f4_3127;
    f32 temp_f4_3254;
    f32 var_f1_2852;
    f32 var_f27_2715;
    f32 var_f28_2824;
    f32 var_f29_2718;
    f32 var_f2_3118;
    f32 var_f2_3244;
    f32 var_f3_2985;
    f32 var_f4_2760;
    f32 var_f4_2918;
    f32 var_f4_3051;
    f32 var_f4_3177;
    f64 temp_f1_2763;
    f64 temp_f1_2769;
    f64 temp_f1_2773;
    f64 temp_f1_2924;
    f64 temp_f1_2930;
    f64 temp_f1_2934;
    f64 temp_f1_3057;
    f64 temp_f1_3063;
    f64 temp_f1_3067;
    f64 temp_f1_3183;
    f64 temp_f1_3189;
    f64 temp_f1_3193;
    f64 temp_f3_2722;
    s32 temp_r3_2792;
    s32 temp_r3_2953;
    s32 temp_r3_3086;
    s32 temp_r3_3212;
    s32 var_r0_2802;
    s32 var_r0_2963;
    s32 var_r0_3096;
    s32 var_r0_3222;
    s32 var_r30_2991;
    s32 var_r31_2711;
    void *temp_r4_2704;
    void *temp_r4_2714;
    void *temp_r5_2712;

    temp_r4_2704 = this->unk0->unk8;
    sp178 = M2C_FIELD(temp_r4_2704, f64 *, 0x30);
    sp180 = M2C_FIELD(temp_r4_2704, f64 *, 0x38);
    var_r31_2711 = -1;
    temp_r5_2712 = M2C_FIELD(this->unk450->GetProp(), void **, 8);
    temp_r4_2714 = this->unk0->unk8;
    var_f27_2715 = 0.0f;
    var_f29_2718 = 0.0f;
    temp_f3_2722 = M2C_FIELD(temp_r5_2712, f64 *, 0x30);
    sp58 = -M2C_FIELD(temp_r4_2714, f32 *, 0x20);
    sp5C = -M2C_FIELD(temp_r4_2714, f32 *, 0x24);
    sp60 = -M2C_FIELD(temp_r4_2714, f32 *, 0x28);
    sp168 = temp_f3_2722;
    sp170 = M2C_FIELD(temp_r5_2712, f64 *, 0x38);
    sp148 = (f64) sp58;
    sp150 = (f64) sp60;
    sp118.GetVel();
    if (((sp120 * sp120) + ((sp118 * sp118) + (sp11C * sp11C))) > 0.01f) {
        temp_f28_2750 = M2C_BITWISE(f32, this->unk0->unk688);
        sp108.GetVel();
        var_f4_2760 = (sp110 * sp110) + ((sp108 * sp108) + (sp10C * sp10C));
        if (var_f4_2760 > 0.0f) {
            temp_f1_2763 = __frsqrte(var_f4_2760);
            temp_f1_2769 = 0.5 * temp_f1_2763 * -(((f64) var_f4_2760 * (temp_f1_2763 * temp_f1_2763)) - 3.0);
            temp_f1_2773 = 0.5 * temp_f1_2769 * -(((f64) var_f4_2760 * (temp_f1_2769 * temp_f1_2769)) - 3.0);
            var_f4_2760 = (f32) ((f64) var_f4_2760 * (0.5 * temp_f1_2773 * -(((f64) var_f4_2760 * (temp_f1_2773 * temp_f1_2773)) - 3.0)));
        } else if (var_f4_2760 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2760 = __float_nan;
        } else {
            sp14 = var_f4_2760;
            temp_r3_2792 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_2792) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2802 = 1;
                } else {
                    var_r0_2802 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2802 = 5;
                } else {
                    var_r0_2802 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_2802 = 4;
                break;
            }
            if (var_r0_2802 == 1) {
                var_f4_2760 = __float_nan;
            }
        }
        temp_f0_2823 = temp_f28_2750 + var_f4_2760;
        var_f28_2824 = 1.0f;
        if (var_f28_2824 > temp_f0_2823) {

        } else {
            var_f28_2824 = temp_f0_2823;
        }
        var_f29_2718 = this->unk450->GetDist() / var_f28_2824;
    }
    if (M2C_BITWISE(f32, this->unk0->unk684) > 0.0f) {
        spF8.GetDir();
        var_f1_2852 = ((f32) sp150 * sp100) + (((f32) sp148 * spF8) + (unksp14C * spFC));
        if (var_f1_2852 < 1.0f) {

        } else {
            var_f1_2852 = 1.0f;
        }
        if (var_f1_2852 > -1.0f) {

        } else {
            var_f1_2852 = -1.0f;
        }
        var_f29_2718 += (f32) acos(var_f1_2852) / M2C_BITWISE(f32, this->unk0->unk684);
    }
    unksp16C = unksp17C;
    spC8.GetVel();
    spD8.operator*(var_f29_2718);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp138 = sp48;
    sp50 = (f32) sp170 + spD8.unk8;
    spE8 = sp48;
    spF0 = (f64) sp50;
    sp140 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp138 = sp38;
    sp40 = (f32) sp140 - (f32) sp180;
    spB8 = sp38;
    sp140 = (f64) sp40;
    spC0 = (f64) sp40;
    var_f4_2918 = ((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + (unksp13C * unksp13C));
    if (var_f4_2918 > 0.000001f) {
        if (var_f4_2918 > 0.0f) {
            temp_f1_2924 = __frsqrte(var_f4_2918);
            temp_f1_2930 = 0.5 * temp_f1_2924 * -(((f64) var_f4_2918 * (temp_f1_2924 * temp_f1_2924)) - 3.0);
            temp_f1_2934 = 0.5 * temp_f1_2930 * -(((f64) var_f4_2918 * (temp_f1_2930 * temp_f1_2930)) - 3.0);
            var_f4_2918 = (f32) ((f64) var_f4_2918 * (0.5 * temp_f1_2934 * -(((f64) var_f4_2918 * (temp_f1_2934 * temp_f1_2934)) - 3.0)));
        } else if (var_f4_2918 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2918 = __float_nan;
        } else {
            sp10 = var_f4_2918;
            temp_r3_2953 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_2953) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2963 = 1;
                } else {
                    var_r0_2963 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2963 = 5;
                } else {
                    var_r0_2963 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_2963 = 4;
                break;
            }
            if (var_r0_2963 == 1) {
                var_f4_2918 = __float_nan;
            }
        }
        var_f3_2985 = 1.0f / var_f4_2918;
    } else {
        var_f3_2985 = 0.0f;
    }
    var_r30_2991 = 0;
    temp_f30_2995 = unksp13C * var_f3_2985;
    temp_f31_2996 = (f32) sp140 * var_f3_2985;
    sp138 = (f32) sp138 * var_f3_2985;
    unksp13C = temp_f30_2995;
    sp140 = temp_f31_2996;
    do {
        temp_r3_3001 = this->unk448;
        if (temp_r3_3001->IsFreeLink(var_r30_2991) == 0) {
            if (var_r31_2711 != -1) {
                temp_r3_3013 = this->unk448->GetLink(var_r30_2991);
                M2C_FIELD(temp_r3_3013->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&spA8, temp_r3_3013);
                temp_r3_3022 = this->unk448->GetLink(var_r30_2991);
                M2C_FIELD(temp_r3_3022->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp88, temp_r3_3022);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp128 = sp28;
                sp30 = sp90 - (f32) sp180;
                sp130 = (f64) sp30;
                sp98 = sp28;
                spA0 = (f64) sp30;
                var_f4_3051 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + (unksp12C * unksp12C));
                if (var_f4_3051 > 0.000001f) {
                    if (var_f4_3051 > 0.0f) {
                        temp_f1_3057 = __frsqrte(var_f4_3051);
                        temp_f1_3063 = 0.5 * temp_f1_3057 * -(((f64) var_f4_3051 * (temp_f1_3057 * temp_f1_3057)) - 3.0);
                        temp_f1_3067 = 0.5 * temp_f1_3063 * -(((f64) var_f4_3051 * (temp_f1_3063 * temp_f1_3063)) - 3.0);
                        var_f4_3051 = (f32) ((f64) var_f4_3051 * (0.5 * temp_f1_3067 * -(((f64) var_f4_3051 * (temp_f1_3067 * temp_f1_3067)) - 3.0)));
                    } else if (var_f4_3051 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3051 = __float_nan;
                    } else {
                        spC = var_f4_3051;
                        temp_r3_3086 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_3086) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_3096 = 1;
                            } else {
                                var_r0_3096 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_3096 = 5;
                            } else {
                                var_r0_3096 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_3096 = 4;
                            break;
                        }
                        if (var_r0_3096 == 1) {
                            var_f4_3051 = __float_nan;
                        }
                    }
                    var_f2_3118 = 1.0f / var_f4_3051;
                } else {
                    var_f2_3118 = 0.0f;
                }
                temp_f3_3125 = unksp12C * var_f2_3118;
                temp_f4_3127 = (f32) sp128 * var_f2_3118;
                temp_f2_3129 = (f32) sp130 * var_f2_3118;
                sp128 = temp_f4_3127;
                unksp12C = temp_f3_3125;
                sp130 = temp_f2_3129;
                temp_f0_3135 = (temp_f2_3129 * temp_f31_2996) + ((temp_f4_3127 * sp138) + (temp_f3_3125 * temp_f30_2995));
                if (temp_f0_3135 > var_f27_2715) {
                    var_f27_2715 = temp_f0_3135;
                    var_r31_2711 = var_r30_2991;
                }
            } else {
                temp_r3_3144 = this->unk448->GetLink(var_r30_2991);
                M2C_FIELD(temp_r3_3144->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&sp78, temp_r3_3144);
                sp158 = sp78;
                unksp15C = unksp17C;
                sp160 = sp80;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp128 = sp18;
                sp20 = (f32) sp160 - (f32) sp180;
                sp130 = (f64) sp20;
                sp68 = sp18;
                sp70 = (f64) sp20;
                var_f4_3177 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + (unksp12C * unksp12C));
                if (var_f4_3177 > 0.000001f) {
                    if (var_f4_3177 > 0.0f) {
                        temp_f1_3183 = __frsqrte(var_f4_3177);
                        temp_f1_3189 = 0.5 * temp_f1_3183 * -(((f64) var_f4_3177 * (temp_f1_3183 * temp_f1_3183)) - 3.0);
                        temp_f1_3193 = 0.5 * temp_f1_3189 * -(((f64) var_f4_3177 * (temp_f1_3189 * temp_f1_3189)) - 3.0);
                        var_f4_3177 = (f32) ((f64) var_f4_3177 * (0.5 * temp_f1_3193 * -(((f64) var_f4_3177 * (temp_f1_3193 * temp_f1_3193)) - 3.0)));
                    } else if (var_f4_3177 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3177 = __float_nan;
                    } else {
                        sp8 = var_f4_3177;
                        temp_r3_3212 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_3212) {     /* switch 4; irregular */
                        case 0x7F800000:            /* switch 4 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_3222 = 1;
                            } else {
                                var_r0_3222 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 4 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_3222 = 5;
                            } else {
                                var_r0_3222 = 3;
                            }
                            break;
                        default:                    /* switch 4 */
                            var_r0_3222 = 4;
                            break;
                        }
                        if (var_r0_3222 == 1) {
                            var_f4_3177 = __float_nan;
                        }
                    }
                    var_f2_3244 = 1.0f / var_f4_3177;
                } else {
                    var_f2_3244 = 0.0f;
                }
                var_r31_2711 = var_r30_2991;
                temp_f3_3252 = unksp12C * var_f2_3244;
                temp_f4_3254 = (f32) sp128 * var_f2_3244;
                temp_f2_3256 = (f32) sp130 * var_f2_3244;
                sp128 = temp_f4_3254;
                unksp12C = temp_f3_3252;
                sp130 = temp_f2_3256;
                var_f27_2715 = (temp_f2_3256 * temp_f31_2996) + ((temp_f4_3254 * sp138) + (temp_f3_3252 * temp_f30_2995));
            }
        }
        var_r30_2991 += 1;
    } while (var_r30_2991 < 6);
    return var_r31_2711;
}
#endif

void SB2::GraphFollowing_RandomMidNodeTraversal() {

}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SB2::GraphFollowing_RandomNoMoreNodes() {
    CharacterGraphNode *sp2C;
    CharacterGraphNode *sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    CharacterGraphNode *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Character *temp_r3_3318;
    Character *temp_r3_3334;
    CharacterGraphNode *temp_r6_3304;
    s32 temp_r5_3313;

    if ((u8) this->unk458 == 0) {
        this->unk448->SendArriveMessage();
        temp_r6_3304 = this->unk448;
        if (((u8) temp_r6_3304->unk80 >> 7U) & 1) {
            sp20 = 0;
            temp_r5_3313 = temp_r6_3304->unk44;
            sp1C = 0x93;
            sp24 = temp_r5_3313;
            sp28 = this->unk44C;
            sp2C = temp_r6_3304;
            temp_r3_3318 = this->unk0;
            temp_r3_3318->Message(&sp1C, temp_r5_3313);
        } else {
            spC = 0;
            sp8 = 0x93;
            sp10 = 1;
            sp14 = 0;
            sp18 = temp_r6_3304;
            temp_r3_3334 = this->unk0;
            temp_r3_3334->Message(&sp8, 0);
        }
        this->unk458 = 1;
    }
    if (((u8) this->unk464 >> 4U) & 1) {
        this->unk0->SetDesiredSpeed(0.0f);
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
s32 SB2::GraphFollowing_RandomSelectLink() {
    CharacterGraphNode *temp_r3_3378;
    s32 var_r31_3369;

    var_r31_3369 = MKRand_Int(&gViewSeed, 0, 6);
loop_2:
    temp_r3_3378 = this->unk448;
    if (temp_r3_3378->IsFreeLink(var_r31_3369) != 0) {
block_1:
        var_r31_3369 = MKRand_Int(&gViewSeed, 0, 6);
        goto loop_2;
    }
    if ((this->unk448->GetLink(var_r31_3369) == (CharacterGraphNode *) this->unk44C) && (MKRand_Int(&gViewSeed, 0, 0x7F) <= 0x40)) {
        goto block_1;
    }
    return var_r31_3369;
}
#endif

void SB2::GraphFollowing() {
    Seek();
}

void SB2::GraphFollowingSetGoal() {
    CharacterGraphNode *temp_r3_3431;

    if (((CharacterGraphNode *) this->unk44C == NULL) && (((temp_r3_3431 = this->unk448, ((temp_r3_3431 == NULL) == 0)) && ((s32) temp_r3_3431->unk44 == 3)) || ((s32) temp_r3_3431->unk44 == 4)) && (((u8) this->unk464 >> 4U) & 1)) {
        this->unk0->SetDesiredSpeed(0.0f);
    }
    GraphFollowingAny();
}

#if 0 // DRAFT: undefined identifier 'zero'
void SB2::GraphFollowingOff() {
    this->unk460 &= 0xFFFFBFFF;
    this->unk448 = NULL;
    this->unk44C = NULL;
    this->unk450 = NULL;
    this->unk454 = 0;
    M2C_FIELD(this, f64 *, 0x438) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x440) = (f64) M2C_FIELD(&zero, f64 *, 8);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'GraphFollowBehaviours'
void SB2::GraphFollowingOn(CharacterGraphNode *arg0, CharacterGraphNode *arg1, GraphFollowBehaviours arg2, AITargetData *arg3) {
    MKVector3 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    M2C_UNK sp30;
    M2C_UNK sp20;
    f32 sp18;
    f32 sp8;
    Character *temp_r3_3495;
    f32 temp_f0_3547;
    f32 temp_f1_3546;
    f32 temp_f3_3549;
    f32 var_f1_3621;
    f32 var_f4_3554;
    f64 temp_f1_3503;
    f64 temp_f1_3560;
    f64 temp_f1_3566;
    f64 temp_f1_3570;
    s32 temp_r3_3486;
    s32 temp_r3_3589;
    s32 var_r0_3599;
    void *temp_r5_3501;

    temp_r3_3486 = this->unk460;
    if (!(temp_r3_3486 & 0x4000)) {
        this->unk460 = temp_r3_3486 | 0x4000;
        this->unk448 = arg0;
        this->unk44C = arg1;
        this->unk450 = arg3;
        this->unk454 = (s32) arg2;
        temp_r3_3495 = this->unk0;
        if (temp_r3_3495 != NULL) {
            if (!(((u8) this->unk464 >> 5U) & 1)) {
                temp_r5_3501 = temp_r3_3495->unk8;
                temp_f1_3503 = M2C_FIELD(temp_r5_3501, f64 *, 0x30);
                sp50 = temp_f1_3503;
                sp58 = M2C_FIELD(temp_r5_3501, f64 *, 0x38);
                M2C_FIELD(arg0->__vptr, M2C_UNK (**)(MKVector3 *, void *, f64), 0x30)(&sp60, temp_r5_3501, temp_f1_3503);
                KDMath_Sub2D(sp70, sp60);
                M2C_FIELD(this, f64 *, 0x438) = M2C_BITWISE(f64, sp70);
                M2C_FIELD(this, f64 *, 0x440) = (f64) sp70.unk8;
            } else {
                sp20.GetPos();
                M2C_FIELD(arg0->__vptr, M2C_UNK (**)(M2C_UNK *, CharacterGraphNode *), 0x30)(&sp30, arg0);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0x438) = sp10;
                sp18 = sp38 - sp28;
                sp40 = sp10;
                sp48 = (f64) sp18;
                M2C_FIELD(this, f64 *, 0x440) = (f64) sp18;
            }
            temp_f1_3546 = this->unk438;
            temp_f0_3547 = this->unk43C;
            temp_f3_3549 = this->unk440;
            var_f4_3554 = (temp_f3_3549 * temp_f3_3549) + ((temp_f1_3546 * temp_f1_3546) + (temp_f0_3547 * temp_f0_3547));
            if (var_f4_3554 > 0.000001f) {
                if (var_f4_3554 > 0.0f) {
                    temp_f1_3560 = __frsqrte(var_f4_3554);
                    temp_f1_3566 = 0.5 * temp_f1_3560 * -(((f64) var_f4_3554 * (temp_f1_3560 * temp_f1_3560)) - 3.0);
                    temp_f1_3570 = 0.5 * temp_f1_3566 * -(((f64) var_f4_3554 * (temp_f1_3566 * temp_f1_3566)) - 3.0);
                    var_f4_3554 = (f32) ((f64) var_f4_3554 * (0.5 * temp_f1_3570 * -(((f64) var_f4_3554 * (temp_f1_3570 * temp_f1_3570)) - 3.0)));
                } else if (var_f4_3554 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_3554 = __float_nan;
                } else {
                    sp8 = var_f4_3554;
                    temp_r3_3589 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_3589) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_3599 = 1;
                        } else {
                            var_r0_3599 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_3599 = 5;
                        } else {
                            var_r0_3599 = 3;
                        }
                        break;
                    default:
                        var_r0_3599 = 4;
                        break;
                    }
                    if (var_r0_3599 == 1) {
                        var_f4_3554 = __float_nan;
                    }
                }
                var_f1_3621 = 1.0f / var_f4_3554;
            } else {
                var_f1_3621 = 0.0f;
            }
            this->unk438 *= var_f1_3621;
            this->unk43C *= var_f1_3621;
            this->unk440 *= var_f1_3621;
            return;
        }
        this->unk438 = 0.0f;
        this->unk43C = 0.0f;
        this->unk440 = 1.0f;
        this->unk444 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SB2::HazardAvoidance() {
    s8 sp128;
    s32 sp124;
    s32 sp120;
    s32 sp11C;
    f32 sp118;
    s32 sp114;
    s8 sp113;
    s8 sp112;
    s16 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
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
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    Character *temp_r3_3661;
    Character *temp_r3_3667;
    f32 temp_f1_3665;
    f32 temp_f2_3690;
    void *temp_r3_3692;
    void *temp_r3_3787;

    temp_r3_3661 = this->unk0;
    temp_f1_3665 = M2C_FIELD(temp_r3_3661->__vptr, f32 (**)(Character *), 0x100)(temp_r3_3661);
    temp_r3_3667 = this->unk0;
    sp60 = 0.0f;
    sp58 = 0.0f;
    sp5C = temp_f1_3665;
    spD0 = (f64) sp60;
    spC8 = (f64) sp58;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f2_3690 = M2C_FIELD((this + ((this->unk3F8 * 0x98) + 0x100)), f32 *, 8) * (300.0f + M2C_FIELD(temp_r3_3667->__vptr, f32 (**)(Character *, f64, f32), 0x100)(temp_r3_3667, (f64) sp58, 0.0f));
    temp_r3_3692 = this->unk0->unk8;
    sp78 = sp48;
    sp50 = temp_f2_3690;
    sp88 = M2C_FIELD(temp_r3_3692, f64 *, 0x30);
    sp80 = (f64) sp50;
    sp90 = M2C_FIELD(temp_r3_3692, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp98 = sp38;
    sp40 = (f32) sp90 + (f32) sp80;
    spA0 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 500.0f;
    sp30 = (f32) spA0 + (f32) spD0;
    spB8 = sp28;
    sp68 = (f64) sp18;
    spC0 = (f64) sp30;
    sp70 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spA8 = sp8;
    spD8 = 0.0f;
    sp10 = (f32) spC0 - (f32) sp70;
    spDC = 0.0f;
    spB0 = (f64) sp10;
    spE0 = 0.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    spF0 = 0.0f;
    spF8 = 0.0f;
    spFC = 0.0f;
    sp100 = 0.0f;
    sp104 = 1.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    sp110 = 0;
    sp112 = 0;
    sp113 = 0;
    sp114 = 0;
    sp11C = 0;
    sp118 = 3.4028235e38f;
    sp120 = 0;
    sp124 = -1;
    sp128 = 0;
    if ((MKCollision_RayCollide(*((MKVector3 *) &spB8), *((MKVector3 *) &spA8), (MKCollisionResult *) &spD8, (MKCollisionMode) 7, 0) != 0) && (sp11C & 0x180)) {
        temp_r3_3787 = this + (this->unk3F8 * 0x98);
        M2C_FIELD(temp_r3_3787, f32 *, 0x110) = (f32) (M2C_FIELD(temp_r3_3787, f32 *, 0x110) + fSBInverseWeight[0x10]);
    }
}
#endif

void SB2::HazardAvoidanceOff() {
    this->unk460 &= 0xFFFEFFFF;
}

void SB2::HazardAvoidanceOn() {
    this->unk460 |= 0x10000;
}

#if 0 // DRAFT: undefined identifier 'sp40'
void SB2::Containment() {
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
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
    f32 spC;
    f32 sp8;
    Character *temp_r3_3830;
    EnemyRegion *temp_r3_3871;
    EnemyRegion *temp_r3_4018;
    f32 temp_f31_3842;
    f32 var_f3_3831;
    f32 var_f4_3900;
    f32 var_f4_4047;
    f64 temp_f1_3903;
    f64 temp_f1_3909;
    f64 temp_f1_3913;
    f64 temp_f1_4050;
    f64 temp_f1_4056;
    f64 temp_f1_4060;
    s32 temp_r3_3932;
    s32 temp_r3_4079;
    s32 var_r0_3942;
    s32 var_r0_4089;
    void *temp_r3_3838;
    void *temp_r3_3974;
    void *temp_r3_3982;
    void *temp_r3_3995;
    void *temp_r3_4010;
    void *temp_r3_4121;
    void *temp_r3_4129;
    void *temp_r3_4142;
    void *temp_r3_4157;

    temp_r3_3830 = this->unk0;
    var_f3_3831 = temp_r3_3830->unk694;
    if (var_f3_3831 > 0.1f) {

    } else {
        var_f3_3831 = 0.1f;
    }
    temp_r3_3838 = temp_r3_3830->unk8;
    temp_f31_3842 = 500.0f * var_f3_3831;
    spB0 = M2C_FIELD(temp_r3_3838, f64 *, 0x30);
    spB8 = M2C_FIELD(temp_r3_3838, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp70 = sp40;
    sp48 = M2C_FIELD((this + ((this->unk3F8 * 0x98) + 0x100)), f32 *, 8) * temp_f31_3842;
    sp78 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spA0 = sp30;
    sp38 = (f32) spB8 + (f32) sp78;
    spA8 = (f64) sp38;
    temp_r3_3871 = this->unk4;
    if ((temp_r3_3871 != NULL) && (temp_r3_3871->GetFirstIntersectionPlane(*((MKVector3 *) &spB0), *((MKVector3 *) &spA0), &sp90, &sp80) != 0)) {
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp60 = sp20;
        sp28 = (f32) spB8 - sp90.unk8;
        sp68 = (f64) sp28;
        var_f4_3900 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
        if (var_f4_3900 > 0.0f) {
            temp_f1_3903 = __frsqrte(var_f4_3900);
            temp_f1_3909 = 0.5 * temp_f1_3903 * -(((f64) var_f4_3900 * (temp_f1_3903 * temp_f1_3903)) - 3.0);
            temp_f1_3913 = 0.5 * temp_f1_3909 * -(((f64) var_f4_3900 * (temp_f1_3909 * temp_f1_3909)) - 3.0);
            var_f4_3900 = (f32) ((f64) var_f4_3900 * (0.5 * temp_f1_3913 * -(((f64) var_f4_3900 * (temp_f1_3913 * temp_f1_3913)) - 3.0)));
        } else if (var_f4_3900 < M2C_BITWISE(f32, 0.0)) {
            var_f4_3900 = __float_nan;
        } else {
            spC = var_f4_3900;
            temp_r3_3932 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_3932) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_3942 = 1;
                } else {
                    var_r0_3942 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_3942 = 5;
                } else {
                    var_r0_3942 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_3942 = 4;
                break;
            }
            if (var_r0_3942 == 1) {
                var_f4_3900 = __float_nan;
            }
        }
        M2C_FIELD((this + (this->unk3F8 * 0x98)), f32 *, 0x160) = (f32) (var_f4_3900 / temp_f31_3842);
        temp_r3_3974 = this + ((this->unk3F8 * 0x98) + 0x140);
        M2C_FIELD(temp_r3_3974, f64 *, 0) = M2C_BITWISE(f64, sp90);
        M2C_FIELD(temp_r3_3974, f64 *, 8) = (f64) sp90.unk8;
        temp_r3_3982 = this + ((this->unk3F8 * 0x98) + 0x150);
        M2C_FIELD(temp_r3_3982, f64 *, 0) = M2C_BITWISE(f64, sp80);
        M2C_FIELD(temp_r3_3982, f64 *, 8) = (f64) sp80.unk8;
        if (this->unk4->IsPointWithin(*((MKVector3 *) &spB0)) != 0) {
            temp_r3_3995 = this + (this->unk3F8 * 0x98);
            M2C_FIELD(temp_r3_3995, f32 *, 0x110) = (f32) (((1.0f - M2C_FIELD(temp_r3_3995, f32 *, 0x160)) * fSBInverseWeight[0xF]) + M2C_FIELD(temp_r3_3995, f32 *, 0x110));
        } else {
            temp_r3_4010 = this + (this->unk3F8 * 0x98);
            M2C_FIELD(temp_r3_4010, f32 *, 0x110) = (f32) -(((1.0f - M2C_FIELD(temp_r3_4010, f32 *, 0x160)) * (0.3f * fSBInverseWeight[0xF])) - M2C_FIELD(temp_r3_4010, f32 *, 0x110));
        }
    }
    temp_r3_4018 = M2C_FIELD(this, EnemyRegion **, 8);
    if ((temp_r3_4018 != NULL) && (temp_r3_4018->GetFirstIntersectionPlane(*((MKVector3 *) &spB0), *((MKVector3 *) &spA0), &sp90, &sp80) != 0)) {
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp50 = sp10;
        sp18 = (f32) spB8 - sp90.unk8;
        sp58 = (f64) sp18;
        var_f4_4047 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (unksp54 * unksp54));
        if (var_f4_4047 > 0.0f) {
            temp_f1_4050 = __frsqrte(var_f4_4047);
            temp_f1_4056 = 0.5 * temp_f1_4050 * -(((f64) var_f4_4047 * (temp_f1_4050 * temp_f1_4050)) - 3.0);
            temp_f1_4060 = 0.5 * temp_f1_4056 * -(((f64) var_f4_4047 * (temp_f1_4056 * temp_f1_4056)) - 3.0);
            var_f4_4047 = (f32) ((f64) var_f4_4047 * (0.5 * temp_f1_4060 * -(((f64) var_f4_4047 * (temp_f1_4060 * temp_f1_4060)) - 3.0)));
        } else if (var_f4_4047 < M2C_BITWISE(f32, 0.0)) {
            var_f4_4047 = __float_nan;
        } else {
            sp8 = var_f4_4047;
            temp_r3_4079 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_4079) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4089 = 1;
                } else {
                    var_r0_4089 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4089 = 5;
                } else {
                    var_r0_4089 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_4089 = 4;
                break;
            }
            if (var_r0_4089 == 1) {
                var_f4_4047 = __float_nan;
            }
        }
        M2C_FIELD((this + (this->unk3F8 * 0x98)), f32 *, 0x188) = (f32) (var_f4_4047 / temp_f31_3842);
        temp_r3_4121 = this + ((this->unk3F8 * 0x98) + 0x168);
        M2C_FIELD(temp_r3_4121, f64 *, 0) = M2C_BITWISE(f64, sp90);
        M2C_FIELD(temp_r3_4121, f64 *, 8) = (f64) sp90.unk8;
        temp_r3_4129 = this + ((this->unk3F8 * 0x98) + 0x178);
        M2C_FIELD(temp_r3_4129, f64 *, 0) = M2C_BITWISE(f64, sp80);
        M2C_FIELD(temp_r3_4129, f64 *, 8) = (f64) sp80.unk8;
        if (((EnemyRegion *) (M2C_FIELD(this, EnemyRegion **, 8)))->IsPointWithin(*((MKVector3 *) &spB0)) == 0) {
            temp_r3_4142 = this + (this->unk3F8 * 0x98);
            M2C_FIELD(temp_r3_4142, f32 *, 0x110) = (f32) (((1.0f - M2C_FIELD(temp_r3_4142, f32 *, 0x160)) * fSBInverseWeight[0xF]) + M2C_FIELD(temp_r3_4142, f32 *, 0x110));
            return;
        }
        temp_r3_4157 = this + (this->unk3F8 * 0x98);
        M2C_FIELD(temp_r3_4157, f32 *, 0x110) = (f32) -(((1.0f - M2C_FIELD(temp_r3_4157, f32 *, 0x160)) * (0.3f * fSBInverseWeight[0xF])) - M2C_FIELD(temp_r3_4157, f32 *, 0x110));
    }
}
#endif

void SB2::ContainmentOff() {
    this->unk460 &= 0xFFFF7FFF;
}

void SB2::ContainmentOn() {
    this->unk460 |= 0x8000;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SB2::WallAvoidance() {
    s8 sp178;
    s32 sp174;
    s32 sp170;
    s32 sp16C;
    f32 sp168;
    s32 sp164;
    s8 sp163;
    s8 sp162;
    s16 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
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
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f64 sp10;
    f64 sp8;
    Character *temp_r3_4209;
    Character *temp_r3_4214;
    Character *temp_r3_4231;
    f32 temp_f0_4223;
    f32 temp_f1_4253;
    f32 temp_f29_4217;
    f32 var_f2_4222;
    s32 temp_r4_4245;
    s32 temp_r5_4390;
    void *temp_r3_4266;
    void *temp_r3_4421;
    void *temp_r5_4382;
    void *temp_r5_4404;

    temp_r3_4209 = this->unk0;
    temp_r3_4214 = this->unk0;
    temp_f29_4217 = 0.5f * M2C_FIELD(temp_r3_4209->__vptr, f32 (**)(Character *), 0x100)(temp_r3_4209);
    var_f2_4222 = 75.0f;
    temp_f0_4223 = 0.75f * M2C_FIELD(temp_r3_4214->__vptr, f32 (**)(Character *), 0x100)(temp_r3_4214);
    if (var_f2_4222 > temp_f0_4223) {

    } else {
        var_f2_4222 = temp_f0_4223;
    }
    temp_r3_4231 = this->unk0;
    sp80 = 0.0f;
    sp78 = 0.0f;
    sp7C = var_f2_4222;
    sp120 = (f64) sp80;
    sp118 = (f64) sp78;
    temp_r4_4245 = this->unk3F8 * 0x98;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    temp_f1_4253 = M2C_FIELD((this + (temp_r4_4245 + 0x100)), f32 *, 8) * M2C_FIELD(temp_r3_4231->__vptr, f32 (**)(Character *, f64), 0x100)(temp_r3_4231, (f64) sp78);
    spB8 = sp68;
    sp70 = temp_f1_4253;
    spC0 = (f64) sp70;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_r3_4266 = this->unk0->unk8;
    spC8 = sp58;
    sp60 = (f32) spC0 * 0.0f;
    spD8 = M2C_FIELD(temp_r3_4266, f64 *, 0x30);
    spD0 = (f64) sp60;
    spE0 = M2C_FIELD(temp_r3_4266, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spE8 = sp48;
    sp50 = (f32) spE0 + (f32) spD0;
    spF0 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp108 = sp38;
    sp40 = (f32) spF0 + (f32) sp120;
    sp110 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    spA8 = sp28;
    sp30 = M2C_FIELD((this + (temp_r4_4245 + 0x100)), f32 *, 8) * 300.0f;
    spB0 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp128 = 0.0f;
    spF8 = sp18;
    sp20 = (f32) sp110 + (f32) spB0;
    sp12C = 0.0f;
    sp100 = (f64) sp20;
    sp130 = 0.0f;
    sp138 = 0.0f;
    sp13C = 0.0f;
    sp140 = 0.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp150 = 0.0f;
    sp154 = 1.0f;
    sp158 = 0.0f;
    sp15C = 0.0f;
    sp160 = 0;
    sp162 = 0;
    sp163 = 0;
    sp164 = 0;
    sp168 = 3.4028235e38f;
    sp16C = 0;
    sp170 = 0;
    sp174 = -1;
    sp178 = 0;
    if ((MKCollision_SweepSphereCollide(*((MKVector3 *) &sp108), *((MKVector3 *) &spF8), temp_f29_4217, (MKCollisionResult *) &sp128, (MKCollisionMode) 5, 0) != 0) && (((sp140 * up.unk8) + ((sp138 * up.unk0) + (sp13C * up.unk4))) < 0.6f)) {
        temp_r5_4382 = this + (this->unk3F8 * 0x98);
        M2C_FIELD(temp_r5_4382, f32 *, 0x110) = (f32) (((1.0f - sp168) * fSBInverseWeight[0xA]) + M2C_FIELD(temp_r5_4382, f32 *, 0x110));
        temp_r5_4390 = (this->unk3F8 * 0x98) + 0x190;
        *(this + temp_r5_4390) = *(this + temp_r5_4390) | 0x40;
        M2C_FIELD((this + (this->unk3F8 * 0x98)), f32 *, 0x138) = sp168;
        temp_r5_4404 = this + ((this->unk3F8 * 0x98) + 0x118);
        M2C_FIELD(temp_r5_4404, f64 *, 0) = (f64) sp128;
        M2C_FIELD(temp_r5_4404, f64 *, 8) = (f64) sp130;
        sp8 = (f64) sp138;
        unkspC = 0.0f;
        sp10 = (f64) sp140;
        sp88 = sp8;
        sp90 = (f64) sp140;
        Normalise(sp98);
        temp_r3_4421 = this + ((this->unk3F8 * 0x98) + 0x128);
        M2C_FIELD(temp_r3_4421, f64 *, 0) = M2C_BITWISE(f64, sp98);
        M2C_FIELD(temp_r3_4421, f64 *, 8) = (f64) sp98.unk8;
    }
}
#endif

void SB2::WallAvoidanceOff() {
    this->unk460 &= 0xFFFFFBFF;
}

void SB2::WallAvoidanceOn() {
    this->unk460 |= 0x400;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SB2::ObstacleAvoidance() {
    u8 sp150;
    s32 sp14C;
    void *sp148;
    s32 sp144;
    f32 sp140;
    s32 sp13C;
    s8 sp13B;
    s8 sp13A;
    s16 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
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
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    u8 spC;
    void *sp8;
    AITargetData *temp_r3_4628;
    Character *temp_r3_4474;
    Character *temp_r3_4479;
    Character *temp_r3_4486;
    Character *temp_r3_4494;
    f32 temp_f1_4492;
    f32 temp_f1_4516;
    f32 temp_f29_4489;
    f32 temp_f30_4482;
    s32 temp_r3_4712;
    s32 temp_r4_4508;
    u32 temp_r3_4612;
    u32 var_r29_4600;
    u8 var_r30_4633;
    void **var_r3_4686;
    void *temp_r3_4529;
    void *temp_r3_4706;
    void *var_r28_4629;

    temp_r3_4474 = this->unk0;
    temp_r3_4479 = this->unk0;
    temp_f30_4482 = 300.0f + M2C_FIELD(temp_r3_4474->__vptr, f32 (**)(Character *), 0x100)(temp_r3_4474);
    temp_r3_4486 = this->unk0;
    temp_f29_4489 = 0.5f * M2C_FIELD(temp_r3_4479->__vptr, f32 (**)(Character *), 0x100)(temp_r3_4479);
    temp_f1_4492 = M2C_FIELD(temp_r3_4486->__vptr, f32 (**)(Character *), 0x100)(temp_r3_4486);
    temp_r3_4494 = this->unk0;
    sp78 = 0.0f;
    sp70 = 0.0f;
    sp74 = temp_f1_4492;
    spF8 = (f64) sp78;
    spF0 = (f64) sp70;
    temp_r4_4508 = this->unk3F8 * 0x98;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    temp_f1_4516 = M2C_FIELD((this + (temp_r4_4508 + 0x100)), f32 *, 8) * M2C_FIELD(temp_r3_4494->__vptr, f32 (**)(Character *, f64, f32), 0x100)(temp_r3_4494, (f64) sp70, 0.0f);
    sp90 = sp60;
    sp68 = temp_f1_4516;
    sp98 = (f64) sp68;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_r3_4529 = this->unk0->unk8;
    spA0 = sp50;
    sp58 = (f32) sp98 * 0.0f;
    spB0 = M2C_FIELD(temp_r3_4529, f64 *, 0x30);
    spA8 = (f64) sp58;
    spB8 = M2C_FIELD(temp_r3_4529, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spC0 = sp40;
    sp48 = (f32) spB8 + (f32) spA8;
    spC8 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spE0 = sp30;
    sp38 = (f32) spC8 + (f32) spF8;
    spE8 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    sp80 = sp20;
    sp28 = M2C_FIELD((this + (temp_r4_4508 + 0x100)), f32 *, 8) * temp_f30_4482;
    sp88 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp100 = 0.0f;
    spD0 = sp10;
    sp18 = (f32) spE8 + (f32) sp88;
    sp104 = 0.0f;
    spD8 = (f64) sp18;
    sp108 = 0.0f;
    sp110 = 0.0f;
    sp114 = 0.0f;
    sp118 = 0.0f;
    sp120 = 0.0f;
    sp124 = 0.0f;
    sp128 = 0.0f;
    sp12C = 1.0f;
    var_r29_4600 = 0U;
    sp130 = 0.0f;
    sp134 = 0.0f;
    sp138 = 0;
    sp13A = 0;
    sp13B = 0;
    sp13C = 0;
    sp140 = 3.4028235e38f;
    sp144 = 0;
    sp148 = NULL;
    sp14C = -1;
    sp150 = 0;
    temp_r3_4612 = M2C_FIELD(this, u32 *, 0xC);
    if ((temp_r3_4612 != 0U) && (((TargetContext *) (temp_r3_4612 + 0x40))->Get() != NULL)) {
        var_r29_4600 = M2C_FIELD(((TargetContext *) (M2C_FIELD(this, u32 *, 0xC) + 0x40))->Get()->__vptr, u32 (**)(), 0x34)();
    }
    temp_r3_4628 = this->unk10;
    var_r28_4629 = NULL;
    if (temp_r3_4628 != NULL) {
        var_r30_4633 = 0;
        if (((u8) M2C_FIELD(temp_r3_4628, u8 *, 0x48) == 2) || (temp_r3_4628->unk40.Get() != NULL)) {
            var_r30_4633 = 1;
        }
        if ((var_r30_4633 != 0) && (this->unk10->unk40.Get() != NULL)) {
            var_r28_4629 = M2C_FIELD(this->unk10->unk40.Get()->__vptr, void *(**)(), 0x34)();
        }
    }
    sp8 = var_r28_4629;
    if (var_r28_4629 != NULL) {
        spC = M2C_FIELD(var_r28_4629, u8 *, 4);
        M2C_FIELD(var_r28_4629, u8 *, 4) = 0U;
    }
    if ((MKCollision_SweepSphereCollide(*((MKVector3 *) &spE0), *((MKVector3 *) &spD0), temp_f29_4489, (MKCollisionResult *) &sp100, (MKCollisionMode) 2, 0) != 0) && (sp148 != NULL) && (sp148 != var_r29_4600)) {
        if ((sp150 != 0) && (sp148 != NULL) && (var_r3_4686 = M2C_FIELD(sp148, void ***, 8), ((var_r3_4686 == NULL) == 0))) {

        } else {
            var_r3_4686 = NULL;
        }
        if (!(M2C_FIELD(*var_r3_4686, s32 *, 0xC) & 0x20000)) {
            temp_r3_4706 = this + (this->unk3F8 * 0x98);
            M2C_FIELD(temp_r3_4706, f32 *, 0x110) = (f32) (((1.0f - sp140) * fSBInverseWeight[9]) + M2C_FIELD(temp_r3_4706, f32 *, 0x110));
            temp_r3_4712 = (this->unk3F8 * 0x98) + 0x190;
            *(this + temp_r3_4712) = *(this + temp_r3_4712) | 0x80;
        }
    }
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
}
#endif

void SB2::ObstacleAvoidanceOff() {
    this->unk460 &= 0xFFFFFDFF;
}

void SB2::ObstacleAvoidanceOn(AITargetData *arg0) {
    this->unk460 |= 0x200;
    this->unk10 = arg0;
}

void SB2::PathFollowing() {
    Seek();
}

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void SB2::PathFollowingSetGoal() {
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    KDUniformSpline spF8;
    f64 spE8;
    KDUniformSpline spC8;
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
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r30_4840;
    Character *temp_r3_4859;
    Character *temp_r3_5183;
    Character *temp_r3_5196;
    Character *temp_r4_4781;
    KDSplinePathSegment *temp_r6_5141;
    MKVector3 *var_r7_5144;
    f32 temp_f0_4885;
    f32 temp_f0_5033;
    f32 temp_f0_5089;
    f32 temp_f0_5222;
    f32 temp_f1_5032;
    f32 temp_f1_5088;
    f32 temp_f1_5114;
    f32 temp_f1_5125;
    f32 temp_f1_5281;
    f32 temp_f2_4879;
    f32 temp_f2_5216;
    f32 temp_f30_4786;
    f32 temp_f30_5198;
    f32 temp_f31_4853;
    f32 temp_f31_4860;
    f32 temp_f3_4876;
    f32 temp_f3_5034;
    f32 temp_f3_5090;
    f32 temp_f3_5180;
    f32 temp_f3_5213;
    f32 temp_f7_4942;
    f32 var_f0_4792;
    f32 var_f1_4863;
    f32 var_f1_4982;
    f32 var_f1_5200;
    s32 temp_r3_5159;
    s32 temp_r4_5143;
    s32 temp_r5_5142;
    u32 temp_r0_5001;
    u32 temp_r5_4884;
    u32 var_r6_4910;
    u8 temp_r3_5045;
    u8 temp_r3_5101;
    u8 var_r0_5246;
    u8 var_r30_5011;
    u8 var_r30_5068;
    void *temp_r3_4784;
    void *temp_r3_5147;
    void *var_r3_5167;

    temp_r4_4781 = this->unk0;
    temp_r3_4784 = temp_r4_4781->unk8;
    temp_f30_4786 = M2C_BITWISE(f32, temp_r4_4781->unk688);
    sp138 = M2C_FIELD(temp_r3_4784, f64 *, 0x30);
    sp140 = M2C_FIELD(temp_r3_4784, f64 *, 0x38);
    if (!(((u8) this->unk434 >> 4U) & 1)) {
        var_f0_4792 = this->unk424;
        if (var_f0_4792 < 1.0f) {

        } else {
            var_f0_4792 = 1.0f;
        }
        if (var_f0_4792 > 0.0f) {

        } else {
            var_f0_4792 = 0.0f;
        }
        this->unk424 = var_f0_4792;
        sp10 = 0.0f;
        spF8.GetMeasure(this->unk424, (Matrix *) &this->unk420->unk30, KDSpline_PositionMixer);
        sp128 = M2C_BITWISE(f64, spF8);
        sp130 = (f64) spF8.unk8;
        sp14 = 0.0f;
        spC8.GetMeasure(this->unk424, (Matrix *) &this->unk420->unk30, KDSpline_VelocityMixer);
        spB8 = M2C_BITWISE(f64, spC8);
        spC0 = (f64) spC8.unk8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r30_4840 = this->unk0;
        sp70 = (f32) spC0 * sp14;
        sp118 = sp68;
        sp120 = (f64) sp70;
        temp_f31_4853 = M2C_FIELD(temp_r30_4840->__vptr, f32 (**)(Character *, f64, f32), 0x100)(temp_r30_4840, sp68, sp14);
        temp_r3_4859 = this->unk0;
        temp_f31_4860 = (temp_r30_4840->unk694 * M2C_FIELD(temp_r30_4840->__vptr, f32 (**)(Character *, f64, f32), 0x100)(temp_r30_4840)) + temp_f31_4853;
        var_f1_4863 = KDMath_GetTurningCircleRadius(temp_r3_4859->unk68C, M2C_BITWISE(f32, temp_r3_4859->unk684));
        if (temp_f31_4860 > var_f1_4863) {
            var_f1_4863 = temp_f31_4860;
        }
        this->unk434 &= ~0x40;
        temp_f3_4876 = (f32) sp140 - (f32) sp130;
        temp_f2_4879 = (f32) sp138 - (f32) sp128;
        this->unk434 &= ~8;
        temp_r5_4884 = ((u8) this->unk434 >> 5U) & 1;
        temp_f0_4885 = (temp_f2_4879 * temp_f2_4879) + (temp_f3_4876 * temp_f3_4876);
        if (temp_r5_4884 != 0) {
            M2C_ERROR(/* unknown instruction: ps_sub $f2, $f3, $f2 */);
            spA8 = sp58;
            sp60 = (f32) sp140 - (f32) sp130;
            spB0 = (f64) sp60;
            var_r6_4910 = (u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU;
        } else {
            M2C_ERROR(/* unknown instruction: ps_sub $f2, $f3, $f2 */);
            sp98 = sp48;
            sp50 = (f32) sp140 - (f32) sp130;
            spA0 = (f64) sp50;
            var_r6_4910 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        }
        temp_f7_4942 = 2.0f * var_f1_4863;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((temp_f0_4885 < (var_f1_4863 * var_f1_4863)) || (((u8) var_r6_4910 != 0) && (temp_f0_4885 < (temp_f7_4942 * temp_f7_4942)))) {
            var_f1_4982 = temp_f30_4786 * this->unk428;
            if (temp_r5_4884 != 0) {
                var_f1_4982 = -var_f1_4982;
            }
            this->unk424 += 5.0f * (var_f1_4982 * gUpdateTimeDelta);
            if (((u8) this->unk420->unk45 == 0) || !(((u8) this->unk434 >> 7U) & 1)) {
                temp_r0_5001 = ((u8) this->unk434 >> 5U) & 1;
                if ((temp_r0_5001 == 0) && ((this->unk424 > 1.0f) || ((u32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) != 0))) {
                    var_r30_5011 = 1;
                    this->unk424 = 1.0f;
                    if (this->unk42C > 0.0f) {
                        spC = 0.0f;
                        spE8.GetMeasure(this->unk424, (Matrix *) &this->unk420->unk30, KDSpline_PositionMixer);
                        sp128 = spE8;
                        sp130 = spF0;
                        temp_f1_5032 = (f32) sp138 - (f32) sp128;
                        temp_f0_5033 = this->unk42C;
                        temp_f3_5034 = (f32) sp140 - (f32) sp130;
                        if (((temp_f1_5032 * temp_f1_5032) + (temp_f3_5034 * temp_f3_5034)) > (temp_f0_5033 * temp_f0_5033)) {
                            var_r30_5011 = 0;
                        }
                    }
                    if (var_r30_5011 != 0) {
                        temp_r3_5045 = this->unk434;
                        if ((temp_r3_5045 >> 7U) & 1) {
                            this->unk434 = temp_r3_5045 | 0x20;
                        }
                        this->unk434 |= 0x40;
                    }
                } else if ((temp_r0_5001 != 0) && ((this->unk424 < 0.0f) || ((u32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) != 0))) {
                    var_r30_5068 = 1;
                    this->unk424 = 0.0f;
                    if (this->unk42C > 0.0f) {
                        sp8 = 0.0f;
                        spC8.unk10.GetMeasure(this->unk424, (Matrix *) &this->unk420->unk30, KDSpline_PositionMixer);
                        sp128 = M2C_BITWISE(f64, spC8.unk10);
                        sp130 = spE0;
                        temp_f1_5088 = (f32) sp138 - (f32) sp128;
                        temp_f0_5089 = this->unk42C;
                        temp_f3_5090 = (f32) sp140 - (f32) sp130;
                        if (((temp_f1_5088 * temp_f1_5088) + (temp_f3_5090 * temp_f3_5090)) > (temp_f0_5089 * temp_f0_5089)) {
                            var_r30_5068 = 0;
                        }
                    }
                    if (var_r30_5068 != 0) {
                        temp_r3_5101 = this->unk434;
                        if ((temp_r3_5101 >> 7U) & 1) {
                            this->unk434 = temp_r3_5101 & ~0x20;
                        }
                        this->unk434 |= 0x40;
                    }
                }
            } else {
                temp_f1_5114 = this->unk424;
                if (temp_f1_5114 > 1.0f) {
                    this->unk424 = temp_f1_5114 - 1.0f;
                    this->unk434 |= 0x40;
                }
                temp_f1_5125 = this->unk424;
                if (temp_f1_5125 < 0.0f) {
                    this->unk424 = temp_f1_5125 + 1.0f;
                    this->unk434 |= 0x40;
                }
            }
        }
        unksp12C = unksp13C;
    } else {
        temp_r6_5141 = this->unk420;
        temp_r5_5142 = this->unk430;
        temp_r4_5143 = temp_r6_5141->unk1C;
        var_r7_5144 = temp_r6_5141->unk24;
        temp_r3_5147 = var_r7_5144 + (temp_r5_5142 * temp_r4_5143);
        sp128 = M2C_FIELD(temp_r3_5147, f64 *, 0);
        sp130 = M2C_FIELD(temp_r3_5147, f64 *, 8);
        if (temp_r5_5142 < 1) {

        } else {
            var_r7_5144 += (temp_r5_5142 - 1) * temp_r4_5143;
        }
        temp_r3_5159 = temp_r6_5141->unk20;
        if (temp_r5_5142 > (s32) (temp_r3_5159 - 2)) {
            var_r3_5167 = temp_r6_5141->unk24 + ((temp_r3_5159 - 1) * temp_r6_5141->unk1C);
        } else {
            var_r3_5167 = temp_r6_5141->unk24 + ((temp_r5_5142 + 1) * temp_r6_5141->unk1C);
        }
        temp_f3_5180 = M2C_FIELD(var_r3_5167, f32 *, 0) - var_r7_5144->unk0;
        temp_r3_5183 = this->unk0;
        sp38 = temp_f3_5180;
        sp3C = 0.0f;
        sp40 = M2C_FIELD(var_r3_5167, f32 *, 8) - var_r7_5144->unk8;
        spF8.unk10 = (f64) sp38;
        sp110 = (f64) sp40;
        temp_r3_5196 = this->unk0;
        temp_f30_5198 = M2C_FIELD(temp_r3_5183->__vptr, f32 (**)(Character *, f64, f32, f32), 0x100)(temp_r3_5183, (f64) sp38, 0.0f, temp_f3_5180);
        var_f1_5200 = KDMath_GetTurningCircleRadius(temp_r3_5196->unk68C, M2C_BITWISE(f32, temp_r3_5196->unk684));
        if (temp_f30_5198 > var_f1_5200) {
            var_f1_5200 = temp_f30_5198;
        }
        this->unk434 &= ~0x40;
        temp_f3_5213 = (f32) sp140 - (f32) sp130;
        temp_f2_5216 = (f32) sp138 - (f32) sp128;
        this->unk434 &= ~8;
        temp_f0_5222 = (temp_f2_5216 * temp_f2_5216) + (temp_f3_5213 * temp_f3_5213);
        if (((u8) this->unk434 >> 5U) & 1) {
            M2C_ERROR(/* unknown instruction: ps_sub $f2, $f3, $f2 */);
            sp88 = sp28;
            sp30 = (f32) sp140 - (f32) sp130;
            sp90 = (f64) sp30;
            var_r0_5246 = (((f32) sp90 * (f32) sp110) + (((f32) sp88 * M2C_BITWISE(f32, spF8.unk10)) + (unksp8C * sp10C))) < 0.0f;
        } else {
            M2C_ERROR(/* unknown instruction: ps_sub $f2, $f3, $f2 */);
            sp78 = sp18;
            sp20 = (f32) sp140 - (f32) sp130;
            sp80 = (f64) sp20;
            var_r0_5246 = (((f32) sp80 * (f32) sp110) + (((f32) sp78 * M2C_BITWISE(f32, spF8.unk10)) + (unksp7C * sp10C))) > 0.0f;
        }
        if ((temp_f0_5222 < (var_f1_5200 * var_f1_5200)) || ((var_r0_5246 != 0) && (temp_f1_5281 = 2.0f * var_f1_5200, ((temp_f0_5222 < (temp_f1_5281 * temp_f1_5281)) != 0)))) {
            this->unk430 += 1;
            if ((s32) this->unk430 >= (s32) this->unk420->unk20) {
                this->unk430 = 0;
            }
            this->unk434 |= 8;
        }
        unksp12C = unksp13C;
    }
    this->unk18.Set(*((MKVector3 *) &sp128), 0U);
}
#endif

s32 SB2::PathFollowingHasReachedNextPoint() {
    return ((u8) this->unk434 >> 3U) & 1;
}

s32 SB2::PathFollowingHasLooped() {
    return ((u8) this->unk434 >> 6U) & 1;
}

void SB2::PathFollowingOff() {
    this->unk460 &= 0xFFFFFF7F;
    this->unk434 &= ~0x40;
    this->unk434 &= ~8;
}

#if 0 // DRAFT: undefined identifier 'GetIndexOf'
void SB2::PathFollowingOn(KDSplinePathSegment *arg0, bool arg1, bool arg2, bool arg3, bool arg4, float arg5) {
    f64 sp60;
    f64 sp58;
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
    Character *temp_r3_5462;
    Character *temp_r3_5475;
    KDSplinePathSegment *temp_r7_5420;
    MKVector3 *var_r5_5423;
    f32 temp_f0_5521;
    f32 temp_f2_5489;
    f32 temp_f31_5477;
    f32 temp_f3_5459;
    f32 temp_f3_5488;
    f32 temp_f6_5492;
    f32 var_f1_5479;
    s32 temp_r3_5422;
    s32 temp_r3_5438;
    s32 temp_r6_5421;
    void *temp_r4_5367;
    void *temp_r4_5426;
    void *var_r3_5446;

    temp_r4_5367 = this->unk0->unk8;
    sp58 = M2C_FIELD(temp_r4_5367, f64 *, 0x30);
    sp60 = M2C_FIELD(temp_r4_5367, f64 *, 0x38);
    this->unk460 |= 0x80;
    ResetSteerDirections();
    this->unk420 = arg0;
    this->unk434 = (this->unk434 & ~0x80) | ((arg1 << 7) & 0x80);
    this->unk434 &= ~0x40;
    Tools_GetClosestSplineTimeXZ(&arg0->unk30, *((MKVector3 *) &sp58), 0x14);
    this->unk424 = M2C_ERROR(/* Read from unset register $f1 */);
    this->unk42C = arg5;
    this->unk428 = 1.0f / arg0->unk30.unk8;
    if (arg3 != 0) {
        this->unk434 = (this->unk434 & ~0x20) | ((arg4 << 5) & 0x20);
    }
    this->unk434 = (this->unk434 & ~0x10) | ((arg2 << 4) & 0x10);
    this->unk434 &= ~8;
    if (((u8) this->unk434 >> 4U) & 1) {
        this->unk430 = arg0->GetIndexOf(arg0->GetNearestPointXZ(*((MKVector3 *) &sp58)));
        temp_r7_5420 = this->unk420;
        temp_r6_5421 = this->unk430;
        temp_r3_5422 = temp_r7_5420->unk1C;
        var_r5_5423 = temp_r7_5420->unk24;
        temp_r4_5426 = var_r5_5423 + (temp_r6_5421 * temp_r3_5422);
        sp48 = M2C_FIELD(temp_r4_5426, f64 *, 0);
        sp50 = M2C_FIELD(temp_r4_5426, f64 *, 8);
        if (temp_r6_5421 < 1) {

        } else {
            var_r5_5423 += (temp_r6_5421 - 1) * temp_r3_5422;
        }
        temp_r3_5438 = temp_r7_5420->unk20;
        if (temp_r6_5421 > (s32) (temp_r3_5438 - 2)) {
            var_r3_5446 = temp_r7_5420->unk24 + ((temp_r3_5438 - 1) * temp_r7_5420->unk1C);
        } else {
            var_r3_5446 = temp_r7_5420->unk24 + ((temp_r6_5421 + 1) * temp_r7_5420->unk1C);
        }
        temp_f3_5459 = M2C_FIELD(var_r3_5446, f32 *, 0) - var_r5_5423->unk0;
        temp_r3_5462 = this->unk0;
        sp18 = temp_f3_5459;
        sp1C = 0.0f;
        sp20 = M2C_FIELD(var_r3_5446, f32 *, 8) - var_r5_5423->unk8;
        sp38 = (f64) sp18;
        sp40 = (f64) sp20;
        temp_r3_5475 = this->unk0;
        temp_f31_5477 = M2C_FIELD(temp_r3_5462->__vptr, f32 (**)(Character *, f64, f32, f32), 0x100)(temp_r3_5462, (f64) sp18, 0.0f, temp_f3_5459);
        var_f1_5479 = KDMath_GetTurningCircleRadius(temp_r3_5475->unk68C, M2C_BITWISE(f32, temp_r3_5475->unk684));
        if (temp_f31_5477 > var_f1_5479) {
            var_f1_5479 = temp_f31_5477;
        }
        temp_f3_5488 = (f32) sp60 - (f32) sp50;
        temp_f2_5489 = (f32) sp58 - (f32) sp48;
        temp_f6_5492 = (temp_f2_5489 * temp_f2_5489) + (temp_f3_5488 * temp_f3_5488);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f0 */);
        sp10 = temp_f3_5488;
        sp28 = sp8;
        sp30 = (f64) sp10;
        if ((temp_f6_5492 < (var_f1_5479 * var_f1_5479)) || (((u32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1) != 0) && (temp_f0_5521 = 2.0f * var_f1_5479, ((temp_f6_5492 < (temp_f0_5521 * temp_f0_5521)) != 0)))) {
            this->unk430 += 1;
            if ((s32) this->unk430 >= (s32) this->unk420->unk20) {
                this->unk430 = 0;
            }
        }
    }
}
#endif

void SB2::Wander() {
    Seek();
}

#if 0 // DRAFT: undefined identifier 'zero'
void SB2::WanderSetGoal() {
    f64 sp3C0;                                      /* compiler-managed */
    f64 sp3B8;
    f64 sp3B0;                                      /* compiler-managed */
    f64 sp3A8;                                      /* compiler-managed */
    f64 sp3A0;
    f64 sp398;
    f64 sp390;                                      /* compiler-managed */
    f64 sp388;
    MKProp sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    f64 sp310;                                      /* compiler-managed */
    f64 sp308;                                      /* compiler-managed */
    MKProp sp2E8;
    MKVector3 sp2D8;
    M2C_UNK sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f32 sp160;
    f32 sp150;
    f32 sp140;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    s32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    Character *temp_r3_5601;
    Character *temp_r3_5663;
    Character *temp_r3_5668;
    Character *temp_r3_5890;
    f32 temp_f0_5709;
    f32 temp_f10_5977;
    f32 temp_f10_6143;
    f32 temp_f11_6141;
    f32 temp_f12_6139;
    f32 temp_f1_5906;
    f32 temp_f25_5671;
    f32 temp_f26_5679;
    f32 temp_f5_6023;
    f32 temp_f5_6182;
    f32 temp_f7_5713;
    f32 temp_f7_5981;
    f32 temp_f7_6003;
    f32 temp_f7_6078;
    f32 temp_f7_6160;
    f32 temp_f8_5999;
    f32 temp_f9_5979;
    f32 temp_f9_6158;
    f64 temp_f1_5892;
    s32 temp_r0_5783;
    void *temp_r3_5633;
    void *temp_r3_5715;
    void *temp_r3_5806;
    void *temp_r3_5819;
    void *temp_r3_5852;
    void *temp_r3_5919;
    void *temp_r3_6049;
    void *temp_r3_6062;
    void *temp_r3_6101;
    void *temp_r3_6135;
    void *temp_r4_5891;
    void *temp_r4_5973;

    sp3B8 = M2C_FIELD(&zero, f64 *, 0);
    sp3C0 = M2C_FIELD(&zero, f64 *, 8);
    sp3A8 = M2C_FIELD(&zero, f64 *, 0);
    sp3B0 = M2C_FIELD(&zero, f64 *, 8);
    sp398 = M2C_FIELD(&zero, f64 *, 0);
    sp3A0 = M2C_FIELD(&zero, f64 *, 8);
    sp388 = M2C_FIELD(&zero, f64 *, 0);
    sp390 = M2C_FIELD(&zero, f64 *, 8);
    sp18 = M2C_FIELD(&zero, f64 *, 0);
    sp20 = M2C_FIELD(&zero, f64 *, 8);
    if ((s32) this->unk3F8 == 0) {
        if ((u8) this->unk418 != 0) {
            temp_r3_5601 = this->unk0;
            sp318.operator*(M2C_FIELD(temp_r3_5601->__vptr, f32 (**)(Character *), 0x100)(temp_r3_5601));
            sp328.operator*(1.5f);
            sp338.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp3B8 = sp108;
            sp110 = M2C_BITWISE(f32, sp338.unk8) + sp328.unk8;
            sp338.unk10 = sp108;
            sp3C0 = (f64) sp110;
            temp_r3_5633 = this->unk0->unk8;
            sp338.unk18 = (f64) sp110;
            spF8 = -M2C_FIELD(temp_r3_5633, f32 *, 0x20);
            spFC = -M2C_FIELD(temp_r3_5633, f32 *, 0x24);
            sp100 = -M2C_FIELD(temp_r3_5633, f32 *, 0x28);
            sp308 = (f64) spF8;
            sp310 = (f64) sp100;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((((f32) sp310 * this->unk408) + (((f32) sp308 * M2C_FIELD(this, f32 *, 0x400)) + (unksp30C * this->unk404))) == 0.5f) {
                this->unk418 = 0;
            }
        } else {
            temp_r3_5663 = this->unk0;
            temp_r3_5668 = this->unk0;
            temp_f25_5671 = 200.0f + M2C_FIELD(temp_r3_5663->__vptr, f32 (**)(Character *), 0x100)(temp_r3_5663);
            temp_f26_5679 = (0.5f * M2C_FIELD(temp_r3_5668->__vptr, f32 (**)(Character *), 0x100)(temp_r3_5668)) + 300.0f;
            sp2C8.GetDir();
            sp2D8.operator*(temp_f25_5671);
            sp2E8.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp3B8 = spE8;
            spF0 = M2C_BITWISE(f32, sp2E8.unk8) + sp2D8.unk8;
            sp2E8.unk10 = spE8;
            sp3C0 = (f64) spF0;
            sp2E8.unk18 = (f64) spF0;
            _table_sincosf(this->unk410, *((f32 *) &sp3A8), *((f32 *) &sp3B0));
            temp_f0_5709 = -(f32) sp3A8;
            sp3A8 = temp_f0_5709;
            temp_f7_5713 = (f32) temp_f0_5709;
            temp_r3_5715 = this->unk0->unk8;
            sp28 = ((f32) sp3B0 * M2C_FIELD(temp_r3_5715, f32 *, 0x20)) + ((temp_f7_5713 * M2C_FIELD(temp_r3_5715, f32 *, 0)) + (unksp3AC * M2C_FIELD(temp_r3_5715, f32 *, 0x10)));
            sp2C = ((f32) sp3B0 * M2C_FIELD(temp_r3_5715, f32 *, 0x24)) + ((temp_f7_5713 * M2C_FIELD(temp_r3_5715, f32 *, 4)) + (unksp3AC * M2C_FIELD(temp_r3_5715, f32 *, 0x14)));
            sp30 = ((f32) sp3B0 * M2C_FIELD(temp_r3_5715, f32 *, 0x28)) + ((temp_f7_5713 * M2C_FIELD(temp_r3_5715, f32 *, 8)) + (unksp3AC * M2C_FIELD(temp_r3_5715, f32 *, 0x18)));
            sp2A8 = (f64) sp28;
            sp2B0 = (f64) sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            sp3A8 = spD8;
            spE0 = (f32) sp2B0 * -1.0f;
            sp2B8 = spD8;
            sp2C0 = (f64) spE0;
            sp3B0 = (f64) spE0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            sp298 = spC8;
            spD0 = (f32) sp3B0 * temp_f26_5679;
            sp2A0 = (f64) spD0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp3C0 = (f32) sp3C0 + (f32) sp2A0;
            this->unk410 += 0.15f * KDRand_Gaussian();
            if ((f32) fabs(this->unk410) > 1.0471973f) {
                temp_r0_5783 = this->unk414 + 1;
                this->unk414 = temp_r0_5783;
                if (temp_r0_5783 >= 0x14) {
                    this->unk410 = 0.0f;
                    this->unk414 = 0;
                }
            } else {
                this->unk414 = 0;
            }
            if (this->unk460 & 0x8000) {
                if (this->unk4->IsPointWithin(*((MKVector3 *) &sp3B8)) == 0) {
                    temp_r3_5806 = this->unk0->unk8;
                    sp288 = M2C_FIELD(temp_r3_5806, f64 *, 0x30);
                    sp290 = M2C_FIELD(temp_r3_5806, f64 *, 0x38);
                    if (this->unk4->IsPointWithin(*((MKVector3 *) &sp288)) != 0) {
                        temp_r3_5819 = this->unk0->unk8;
                        sp278 = M2C_FIELD(temp_r3_5819, f64 *, 0x30);
                        sp280 = M2C_FIELD(temp_r3_5819, f64 *, 0x38);
                        this->unk4->GetFirstIntersectionPlane(*((MKVector3 *) &sp278), *((MKVector3 *) &sp3B8), (MKVector3 *) &sp398, (MKVector3 *) &sp388);
                        spB8 = (up.unk4 * (f32) sp390) - (up.unk8 * unksp38C);
                        spBC = (up.unk8 * (f32) sp388) - (up.unk0 * (f32) sp390);
                        spC0 = (up.unk0 * unksp38C) - (up.unk4 * (f32) sp388);
                        sp3A8 = (f64) spB8;
                        sp3B0 = (f64) spC0;
                        temp_r3_5852 = this->unk0->unk8;
                        sp268 = (f64) spB8;
                        spA8 = -M2C_FIELD(temp_r3_5852, f32 *, 0x20);
                        spAC = -M2C_FIELD(temp_r3_5852, f32 *, 0x24);
                        spB0 = -M2C_FIELD(temp_r3_5852, f32 *, 0x28);
                        sp258 = (f64) spA8;
                        sp260 = (f64) spB0;
                        sp270 = (f64) spC0;
                        if ((((f32) sp260 * (f32) sp3B0) + (((f32) sp258 * (f32) sp3A8) + (unksp25C * unksp3AC))) < 0.0f) {
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                            sp3B0 = (f32) sp3B0 * -1.0f;
                        }
                        sp338.unk40 = M2C_FIELD(&zero, f64 *, 0);
                        sp338.unk48 = M2C_FIELD(&zero, f64 *, 8);
                        temp_r3_5890 = this->unk0;
                        temp_r4_5891 = temp_r3_5890->unk8;
                        temp_f1_5892 = M2C_FIELD(temp_r4_5891, f64 *, 0x30);
                        sp248 = temp_f1_5892;
                        sp250 = M2C_FIELD(temp_r4_5891, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                        temp_f1_5906 = sp3B0 * M2C_FIELD(temp_r3_5890->__vptr, f32 (**)(Character *, void *, f64), 0x100)(temp_r3_5890, temp_r4_5891, temp_f1_5892);
                        sp208 = sp158;
                        sp160 = temp_f1_5906;
                        sp210 = (f64) sp160;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                        temp_r3_5919 = this->unk0->unk8;
                        sp218 = sp148;
                        sp150 = (f32) sp210 * 1.5f;
                        sp228 = M2C_FIELD(temp_r3_5919, f64 *, 0x30);
                        sp220 = (f64) sp150;
                        sp230 = M2C_FIELD(temp_r3_5919, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        sp238 = sp138;
                        sp140 = (f32) sp230 + (f32) sp220;
                        sp240 = (f64) sp140;
                        if (this->unk4->GetFirstIntersectionPlane(*((MKVector3 *) &sp248), *((MKVector3 *) &sp238), (MKVector3 *) &sp398, (MKVector3 *) &sp338.unk40) != 0) {
                            this->unk418 = 1;
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            sp1E8 = sp98;
                            spA0 = (f32) sp390 + sp338.unk48;
                            sp1F0 = (f64) spA0;
                            Normalise(sp1F8);
                            M2C_FIELD(this, f32 *, 0x400) = M2C_BITWISE(f64, sp1F8);
                            M2C_FIELD(this, f32 *, 0x408) = (f64) sp1F8.unk8;
                        }
                        temp_r4_5973 = this->unk0->unk8;
                        temp_f10_5977 = -M2C_FIELD(temp_r4_5973, f32 *, 0x20);
                        temp_f9_5979 = -M2C_FIELD(temp_r4_5973, f32 *, 0x24);
                        temp_f7_5981 = -M2C_FIELD(temp_r4_5973, f32 *, 0x28);
                        sp88 = temp_f10_5977;
                        sp8C = temp_f9_5979;
                        sp90 = temp_f7_5981;
                        sp1D8 = (f64) sp88;
                        sp1E0 = (f64) sp90;
                        sp80 = temp_f7_5981;
                        temp_f8_5999 = (up.unk4 * (f32) sp1E0) - (up.unk8 * unksp1DC);
                        sp78 = temp_f10_5977;
                        temp_f7_6003 = (up.unk8 * (f32) sp1D8) - (up.unk0 * (f32) sp1E0);
                        sp1D0 = (f64) sp80;
                        sp7C = temp_f9_5979;
                        sp130 = (up.unk0 * unksp1DC) - (up.unk4 * (f32) sp1D8);
                        sp1C8 = (f64) sp78;
                        sp128 = temp_f8_5999;
                        sp12C = temp_f7_6003;
                        sp338.unk38 = (f64) sp130;
                        sp338.unk30 = (f64) sp128;
                        temp_f5_6023 = (f32) acos(M2C_BITWISE(f32, &up), temp_r4_5973, ((f32) sp1D0 * sp3B0) + (((f32) sp1C8 * (f32) sp3A8) + (unksp1CC * unksp3AC)), (f64) sp128, (f32) sp1C8, sp3B0, (f32) sp1D0, (f64) sp130, temp_f7_6003, temp_f8_5999, temp_f9_5979, temp_f10_5977, up.unk8, up.unk4, unksp1DC);
                        sp10 = (M2C_BITWISE(f32, sp338.unk38) * sp3B0) + ((M2C_BITWISE(f32, sp338.unk30) * (f32) sp3A8) + (M2C_BITWISE(f32, sp338.unk34) * unksp3AC));
                        sp14 = (M2C_BITWISE(s32, sp10) & 0x80000000) | 0x3F800000;
                        this->unk410 = -M2C_BITWISE(f32, sp14) * temp_f5_6023;
                    }
                }
                if (((EnemyRegion *) (M2C_FIELD(this, EnemyRegion **, 8)))->IsPointWithin(*((MKVector3 *) &sp3B8)) != 0) {
                    temp_r3_6049 = this->unk0->unk8;
                    sp1B8 = M2C_FIELD(temp_r3_6049, f64 *, 0x30);
                    sp1C0 = M2C_FIELD(temp_r3_6049, f64 *, 0x38);
                    if (((EnemyRegion *) (M2C_FIELD(this, EnemyRegion **, 8)))->IsPointWithin(*((MKVector3 *) &sp1B8)) == 0) {
                        temp_r3_6062 = this->unk0->unk8;
                        sp1A8 = M2C_FIELD(temp_r3_6062, f64 *, 0x30);
                        sp1B0 = M2C_FIELD(temp_r3_6062, f64 *, 0x38);
                        ((EnemyRegion *) (M2C_FIELD(this, EnemyRegion **, 8)))->GetFirstIntersectionPlane(*((MKVector3 *) &sp1A8), *((MKVector3 *) &sp3B8), (MKVector3 *) &sp398, (MKVector3 *) &sp388);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                        temp_f7_6078 = (f32) sp390 * -1.0f;
                        sp390 = temp_f7_6078;
                        sp70 = (up.unk0 * unksp38C) - (up.unk4 * (f32) sp388);
                        sp68 = (up.unk4 * temp_f7_6078) - (up.unk8 * unksp38C);
                        sp6C = (up.unk8 * (f32) sp388) - (up.unk0 * temp_f7_6078);
                        sp3B0 = (f64) sp70;
                        sp3A8 = (f64) sp68;
                        temp_r3_6101 = this->unk0->unk8;
                        sp198 = (f64) sp68;
                        sp58 = -M2C_FIELD(temp_r3_6101, f32 *, 0x20);
                        sp5C = -M2C_FIELD(temp_r3_6101, f32 *, 0x24);
                        sp60 = -M2C_FIELD(temp_r3_6101, f32 *, 0x28);
                        sp188 = (f64) sp58;
                        sp190 = (f64) sp60;
                        sp1A0 = (f64) sp70;
                        if ((((f32) sp190 * (f32) sp3B0) + (((f32) sp188 * (f32) sp3A8) + (unksp18C * unksp3AC))) < 0.0f) {
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f3, $f3, $f28 */);
                            sp3B0 = (f32) sp3B0 * -1.0f;
                        }
                        temp_r3_6135 = this->unk0->unk8;
                        temp_f12_6139 = -M2C_FIELD(temp_r3_6135, f32 *, 0x20);
                        temp_f11_6141 = -M2C_FIELD(temp_r3_6135, f32 *, 0x24);
                        temp_f10_6143 = -M2C_FIELD(temp_r3_6135, f32 *, 0x28);
                        sp48 = temp_f12_6139;
                        sp4C = temp_f11_6141;
                        sp50 = temp_f10_6143;
                        sp178 = (f64) sp48;
                        sp180 = (f64) sp50;
                        sp40 = temp_f10_6143;
                        temp_f9_6158 = (up.unk4 * (f32) sp180) - (up.unk8 * unksp17C);
                        temp_f7_6160 = (up.unk8 * (f32) sp178) - (up.unk0 * (f32) sp180);
                        sp170 = (f64) sp40;
                        sp38 = temp_f12_6139;
                        sp3C = temp_f11_6141;
                        sp120 = (up.unk0 * unksp17C) - (up.unk4 * (f32) sp178);
                        sp168 = (f64) sp38;
                        sp118 = temp_f9_6158;
                        sp11C = temp_f7_6160;
                        sp338.unk28 = (f64) sp120;
                        sp338.unk20 = (f64) sp118;
                        temp_f5_6182 = (f32) acos(M2C_BITWISE(f32, temp_r3_6135), M2C_BITWISE(void *, (((f32) sp170 * sp3B0) + (((f32) sp168 * (f32) sp3A8) + (unksp16C * unksp3AC)))), (f32) sp170, (f64) sp118, (f32) sp3A8, sp3B0, (f32) (f64) sp120, (f64) temp_f7_6160, (f32) sp178, temp_f9_6158, temp_f10_6143, temp_f11_6141, temp_f12_6139, (f32) sp180);
                        sp8 = (M2C_BITWISE(f32, sp338.unk28) * sp3B0) + (((f32) (f64) sp118 * (f32) sp3A8) + (sp338.unk24 * unksp3AC));
                        spC = (M2C_BITWISE(s32, sp8) & 0x80000000) | 0x3F800000;
                        this->unk410 = -M2C_BITWISE(f32, spC) * temp_f5_6182;
                    }
                }
            }
        }
        this->unk18.Set(*((MKVector3 *) &sp3B8), 0U);
    }
}
#endif

void SB2::WanderOff() {
    this->unk460 &= 0xFFFFFFBF;
    this->unk418 = 0;
}

void SB2::WanderOn() {
    this->unk460 |= 0x40;
    ResetSteerDirections();
    this->unk410 = 0.0f;
    this->unk414 = 0;
    this->unk418 = 0;
    M2C_FIELD(this, f32 *, 0x400) = 0.0f;
    this->unk404 = 0.0f;
    this->unk408 = 0.0f;
}

#if 0 // DRAFT: expression syntax error
void SB2::RandomPursuit() {
    f32 sp8;
    f32 var_f1_6289;
    void *temp_r3_6283;
    void *temp_r3_6312;

    sp8.GetDir();
    temp_r3_6283 = this + ((this->unk3F8 * 0x98) + 0x100);
    var_f1_6289 = (M2C_FIELD(temp_r3_6283, f32 *, 8) * sp10) + ((M2C_FIELD(temp_r3_6283, f32 *, 0) * sp8) + (M2C_FIELD(temp_r3_6283, f32 *, 4) * spC));
    if (var_f1_6289 < 1.0f) {

    } else {
        var_f1_6289 = 1.0f;
    }
    if (var_f1_6289 > -1.0f) {

    } else {
        var_f1_6289 = -1.0f;
    }
    temp_r3_6312 = this + (this->unk3F8 * 0x98);
    M2C_FIELD(temp_r3_6312, f32 *, 0x110) = (f32) ((fSBInverseWeight[4] * ((f32) acos(var_f1_6289) / 3.1415927f)) + M2C_FIELD(temp_r3_6312, f32 *, 0x110));
}
#endif

#if 0 // DRAFT: expression syntax error
void SB2::RandomPursuitSetGoal() {
    f64 sp20;
    f64 sp18;
    f64 sp8;
    void *temp_r4_6349;

    sp8.GetPos();
    sp18 = sp8;
    sp20 = sp10;
    if (PursuitPredictPos((MKVector3 *) &sp18) != 0) {
        this->unk18.Set(*((MKVector3 *) &sp18), 0U);
        return;
    }
    temp_r4_6349 = M2C_FIELD(this, void **, 0xC);
    this->unk18.unk0 = M2C_FIELD(temp_r4_6349, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(temp_r4_6349, f64 *, 8);
    this->unk18.unk10 = M2C_FIELD(temp_r4_6349, f64 *, 0x10);
    this->unk18.unk18 = M2C_FIELD(temp_r4_6349, f64 *, 0x18);
    this->unk18.unk20 = M2C_FIELD(temp_r4_6349, f64 *, 0x20);
    this->unk18.unk28 = M2C_FIELD(temp_r4_6349, f64 *, 0x28);
    this->unk18.unk30 = M2C_FIELD(temp_r4_6349, f32 *, 0x30);
    this->unk18.unk34 = M2C_FIELD(temp_r4_6349, f32 *, 0x34);
    this->unk18.unk38 = M2C_FIELD(temp_r4_6349, f32 *, 0x38);
    this->unk18.unk3C = M2C_FIELD(temp_r4_6349, f32 *, 0x3C);
    this->unk18.unk40.unk0 = M2C_FIELD(temp_r4_6349, s32 *, 0x40);
    this->unk18.unk40.unk4 = M2C_FIELD(temp_r4_6349, Targetable **, 0x44);
    M2C_FIELD(this, u8 *, 0x60) = (u8) M2C_FIELD(temp_r4_6349, u8 *, 0x48);
    M2C_FIELD(this, u8 *, 0x61) = (u8) M2C_FIELD(temp_r4_6349, u8 *, 0x49);
}
#endif

void SB2::RandomPursuitOff() {
    this->unk460 &= 0xFFFFFFEF;
    M2C_FIELD(this, s32 *, 0xC) = 0;
}

void SB2::RandomPursuitOn(AITargetData *arg0) {
    this->unk460 |= 0x10;
    M2C_FIELD(this, AITargetData **, 0xC) = arg0;
    ResetSteerDirections();
}

#if 0 // DRAFT: expression syntax error
void SB2::Pursuit() {
    f32 sp8;
    f32 var_f1_6438;
    void *temp_r3_6432;
    void *temp_r3_6461;

    sp8.GetDir();
    temp_r3_6432 = this + ((this->unk3F8 * 0x98) + 0x100);
    var_f1_6438 = (M2C_FIELD(temp_r3_6432, f32 *, 8) * sp10) + ((M2C_FIELD(temp_r3_6432, f32 *, 0) * sp8) + (M2C_FIELD(temp_r3_6432, f32 *, 4) * spC));
    if (var_f1_6438 < 1.0f) {

    } else {
        var_f1_6438 = 1.0f;
    }
    if (var_f1_6438 > -1.0f) {

    } else {
        var_f1_6438 = -1.0f;
    }
    temp_r3_6461 = this + (this->unk3F8 * 0x98);
    M2C_FIELD(temp_r3_6461, f32 *, 0x110) = (f32) ((fSBInverseWeight[3] * ((f32) acos(var_f1_6438) / 3.1415927f)) + M2C_FIELD(temp_r3_6461, f32 *, 0x110));
}
#endif

#if 0 // DRAFT: undefined identifier 'unkspD4'
u8 SB2::PursuitPredictPos(MKVector3 *arg0) {
    AITargetData spB0;
    f32 sp90;
    f32 sp80;
    AITargetData sp60;
    MKVector3 sp50;
    M2C_UNK sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    f32 temp_f0_6656;
    f32 var_f30_6564;
    f32 var_f30_6654;
    f32 var_f31_6484;
    f32 var_f4_6590;
    f64 temp_f1_6593;
    f64 temp_f1_6599;
    f64 temp_f1_6603;
    s32 temp_r3_6622;
    s32 var_r0_6632;
    void *temp_r3_6507;
    void *temp_r4_6488;

    var_f31_6484 = -1.0f;
    temp_r4_6488 = this->unk0->unk8;
    sp30 = -M2C_FIELD(temp_r4_6488, f32 *, 0x20);
    sp34 = -M2C_FIELD(temp_r4_6488, f32 *, 0x24);
    sp38 = -M2C_FIELD(temp_r4_6488, f32 *, 0x28);
    spB0.unk20 = (f64) sp30;
    spB0.unk28 = (f64) sp38;
    if (((AITargetData *) (M2C_FIELD(this, AITargetData **, 0xC)))->GetProp() != NULL) {
        temp_r3_6507 = M2C_FIELD(((AITargetData *) (M2C_FIELD(this, AITargetData **, 0xC)))->GetProp(), void **, 8);
        sp20 = -M2C_FIELD(temp_r3_6507, f32 *, 0x20);
        sp24 = -M2C_FIELD(temp_r3_6507, f32 *, 0x24);
        sp28 = -M2C_FIELD(temp_r3_6507, f32 *, 0x28);
        spB0.unk10 = (f64) sp20;
        spB0.unk18 = (f64) sp28;
        var_f31_6484 = ((f32) spB0.unk28 * (f32) spB0.unk18) + (((f32) spB0.unk20 * (f32) spB0.unk10) + (unkspD4 * unkspC4));
    }
    spB0.GetDir();
    if ((((AITargetData *) (M2C_FIELD(this, AITargetData **, 0xC)))->GetProp() == NULL) || (((((f32) spB0.unk28 * spB0.unk8) + (((f32) spB0.unk20 * M2C_BITWISE(f32, spB0)) + (unkspD4 * unkspB4))) > 0.0f) && (var_f31_6484 < -0.95f))) {
        sp60.unk40.GetPos();
        M2C_FIELD(arg0, f64 *, 0) = M2C_BITWISE(f64, sp60.unk40);
        M2C_FIELD(arg0, f64 *, 8) = M2C_BITWISE(f64, sp60.unk40.unk8);
        return 0U;
    }
    var_f30_6564 = 0.0f;
    sp90.GetVel();
    if (((sp98 * sp98) + ((sp90 * sp90) + (sp94 * sp94))) > 0.01f) {
        sp80.GetVel();
        var_f4_6590 = (sp88 * sp88) + ((sp80 * sp80) + (sp84 * sp84));
        if (var_f4_6590 > 0.0f) {
            temp_f1_6593 = __frsqrte(var_f4_6590);
            temp_f1_6599 = 0.5 * temp_f1_6593 * -(((f64) var_f4_6590 * (temp_f1_6593 * temp_f1_6593)) - 3.0);
            temp_f1_6603 = 0.5 * temp_f1_6599 * -(((f64) var_f4_6590 * (temp_f1_6599 * temp_f1_6599)) - 3.0);
            var_f4_6590 = (f32) ((f64) var_f4_6590 * (0.5 * temp_f1_6603 * -(((f64) var_f4_6590 * (temp_f1_6603 * temp_f1_6603)) - 3.0)));
        } else if (var_f4_6590 < M2C_BITWISE(f32, 0.0)) {
            var_f4_6590 = __float_nan;
        } else {
            sp8 = var_f4_6590;
            temp_r3_6622 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_6622) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_6632 = 1;
                } else {
                    var_r0_6632 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_6632 = 5;
                } else {
                    var_r0_6632 = 3;
                }
                break;
            default:
                var_r0_6632 = 4;
                break;
            }
            if (var_r0_6632 == 1) {
                var_f4_6590 = __float_nan;
            }
        }
        var_f30_6654 = 1.0f;
        temp_f0_6656 = M2C_BITWISE(f32, this->unk0->unk688) + var_f4_6590;
        if (var_f30_6654 > temp_f0_6656) {

        } else {
            var_f30_6654 = temp_f0_6656;
        }
        var_f30_6564 = ((AITargetData *) (M2C_FIELD(this, AITargetData **, 0xC)))->GetDist() / var_f30_6654;
    }
    sp40.GetVel();
    sp50.operator*(var_f30_6564);
    sp60.GetPos();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(arg0, f64 *, 0) = sp10;
    sp18 = sp60.unk8 + sp50.unk8;
    sp60.unk10 = sp10;
    sp60.unk18 = (f64) sp18;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp18;
    return 1U;
}
#endif

#if 0 // DRAFT: expression syntax error
void SB2::PursuitSetGoal() {
    f64 sp20;
    f64 sp18;
    f64 sp8;
    void *temp_r4_6731;

    sp8.GetPos();
    sp18 = sp8;
    sp20 = sp10;
    if (PursuitPredictPos((MKVector3 *) &sp18) != 0) {
        this->unk18.Set(*((MKVector3 *) &sp18), 0U);
        return;
    }
    temp_r4_6731 = M2C_FIELD(this, void **, 0xC);
    this->unk18.unk0 = M2C_FIELD(temp_r4_6731, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(temp_r4_6731, f64 *, 8);
    this->unk18.unk10 = M2C_FIELD(temp_r4_6731, f64 *, 0x10);
    this->unk18.unk18 = M2C_FIELD(temp_r4_6731, f64 *, 0x18);
    this->unk18.unk20 = M2C_FIELD(temp_r4_6731, f64 *, 0x20);
    this->unk18.unk28 = M2C_FIELD(temp_r4_6731, f64 *, 0x28);
    this->unk18.unk30 = M2C_FIELD(temp_r4_6731, f32 *, 0x30);
    this->unk18.unk34 = M2C_FIELD(temp_r4_6731, f32 *, 0x34);
    this->unk18.unk38 = M2C_FIELD(temp_r4_6731, f32 *, 0x38);
    this->unk18.unk3C = M2C_FIELD(temp_r4_6731, f32 *, 0x3C);
    this->unk18.unk40.unk0 = M2C_FIELD(temp_r4_6731, s32 *, 0x40);
    this->unk18.unk40.unk4 = M2C_FIELD(temp_r4_6731, Targetable **, 0x44);
    M2C_FIELD(this, u8 *, 0x60) = (u8) M2C_FIELD(temp_r4_6731, u8 *, 0x48);
    M2C_FIELD(this, u8 *, 0x61) = (u8) M2C_FIELD(temp_r4_6731, u8 *, 0x49);
}
#endif

void SB2::PursuitOff() {
    this->unk460 &= 0xFFFFFFF7;
    M2C_FIELD(this, s32 *, 0xC) = 0;
}

void SB2::PursuitOn(AITargetData *arg0) {
    this->unk460 |= 8;
    M2C_FIELD(this, AITargetData **, 0xC) = arg0;
    ResetSteerDirections();
}

#if 0 // DRAFT: expression syntax error
void SB2::Arrive() {
    f32 sp8;
    f32 var_f1_6820;
    void *temp_r3_6814;
    void *temp_r3_6843;

    sp8.GetDir();
    temp_r3_6814 = this + ((this->unk3F8 * 0x98) + 0x100);
    var_f1_6820 = (M2C_FIELD(temp_r3_6814, f32 *, 8) * sp10) + ((M2C_FIELD(temp_r3_6814, f32 *, 0) * sp8) + (M2C_FIELD(temp_r3_6814, f32 *, 4) * spC));
    if (var_f1_6820 < 1.0f) {

    } else {
        var_f1_6820 = 1.0f;
    }
    if (var_f1_6820 > -1.0f) {

    } else {
        var_f1_6820 = -1.0f;
    }
    temp_r3_6843 = this + (this->unk3F8 * 0x98);
    M2C_FIELD(temp_r3_6843, f32 *, 0x110) = (f32) ((fSBInverseWeight[2] * ((f32) acos(var_f1_6820) / 3.1415927f)) + M2C_FIELD(temp_r3_6843, f32 *, 0x110));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void SB2::ArriveSetGoal() {
    void *temp_r5_6860;

    temp_r5_6860 = M2C_FIELD(this, void **, 0xC);
    if (temp_r5_6860 != NULL) {
        this->unk18.unk0 = M2C_FIELD(temp_r5_6860, f64 *, 0);
        M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(temp_r5_6860, f64 *, 8);
        this->unk18.unk10 = M2C_FIELD(temp_r5_6860, f64 *, 0x10);
        this->unk18.unk18 = M2C_FIELD(temp_r5_6860, f64 *, 0x18);
        this->unk18.unk20 = M2C_FIELD(temp_r5_6860, f64 *, 0x20);
        this->unk18.unk28 = M2C_FIELD(temp_r5_6860, f64 *, 0x28);
        this->unk18.unk30 = M2C_FIELD(temp_r5_6860, f32 *, 0x30);
        this->unk18.unk34 = M2C_FIELD(temp_r5_6860, f32 *, 0x34);
        this->unk18.unk38 = M2C_FIELD(temp_r5_6860, f32 *, 0x38);
        this->unk18.unk3C = M2C_FIELD(temp_r5_6860, f32 *, 0x3C);
        this->unk18.unk40.unk0 = M2C_FIELD(temp_r5_6860, s32 *, 0x40);
        this->unk18.unk40.unk4 = M2C_FIELD(temp_r5_6860, Targetable **, 0x44);
        M2C_FIELD(this, u8 *, 0x60) = (u8) M2C_FIELD(temp_r5_6860, u8 *, 0x48);
        M2C_FIELD(this, u8 *, 0x61) = (u8) M2C_FIELD(temp_r5_6860, u8 *, 0x49);
        return;
    }
    this->unk18.SetDefaults();
}
#endif

void SB2::ArriveOff() {
    this->unk460 &= 0xFFFFFFFB;
    M2C_FIELD(this, s32 *, 0xC) = 0;
}

void SB2::ArriveOn(AITargetData *arg0) {
    this->unk460 |= 4;
    M2C_FIELD(this, AITargetData **, 0xC) = arg0;
    ResetSteerDirections();
}

#if 0 // DRAFT: expression syntax error
void SB2::Seek() {
    f32 sp8;
    f32 var_f1_6954;
    void *temp_r3_6948;
    void *temp_r3_6976;

    sp8.GetDir();
    temp_r3_6948 = this + ((this->unk3F8 * 0x98) + 0x100);
    var_f1_6954 = (M2C_FIELD(temp_r3_6948, f32 *, 8) * sp10) + ((M2C_FIELD(temp_r3_6948, f32 *, 0) * sp8) + (M2C_FIELD(temp_r3_6948, f32 *, 4) * spC));
    if (var_f1_6954 < 1.0f) {

    } else {
        var_f1_6954 = 1.0f;
    }
    if (var_f1_6954 > -1.0f) {

    } else {
        var_f1_6954 = -1.0f;
    }
    temp_r3_6976 = this + (this->unk3F8 * 0x98);
    M2C_FIELD(temp_r3_6976, f32 *, 0x110) = (f32) ((*fSBInverseWeight * ((f32) acos(var_f1_6954) / 3.1415927f)) + M2C_FIELD(temp_r3_6976, f32 *, 0x110));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void SB2::SeekSetGoal() {
    void *temp_r5_6993;

    temp_r5_6993 = M2C_FIELD(this, void **, 0xC);
    if (temp_r5_6993 != NULL) {
        this->unk18.unk0 = M2C_FIELD(temp_r5_6993, f64 *, 0);
        M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(temp_r5_6993, f64 *, 8);
        this->unk18.unk10 = M2C_FIELD(temp_r5_6993, f64 *, 0x10);
        this->unk18.unk18 = M2C_FIELD(temp_r5_6993, f64 *, 0x18);
        this->unk18.unk20 = M2C_FIELD(temp_r5_6993, f64 *, 0x20);
        this->unk18.unk28 = M2C_FIELD(temp_r5_6993, f64 *, 0x28);
        this->unk18.unk30 = M2C_FIELD(temp_r5_6993, f32 *, 0x30);
        this->unk18.unk34 = M2C_FIELD(temp_r5_6993, f32 *, 0x34);
        this->unk18.unk38 = M2C_FIELD(temp_r5_6993, f32 *, 0x38);
        this->unk18.unk3C = M2C_FIELD(temp_r5_6993, f32 *, 0x3C);
        this->unk18.unk40.unk0 = M2C_FIELD(temp_r5_6993, s32 *, 0x40);
        this->unk18.unk40.unk4 = M2C_FIELD(temp_r5_6993, Targetable **, 0x44);
        M2C_FIELD(this, u8 *, 0x60) = (u8) M2C_FIELD(temp_r5_6993, u8 *, 0x48);
        M2C_FIELD(this, u8 *, 0x61) = (u8) M2C_FIELD(temp_r5_6993, u8 *, 0x49);
        return;
    }
    this->unk18.SetDefaults();
}
#endif

void SB2::SeekOff() {
    this->unk460 &= 0xFFFFFFFE;
    M2C_FIELD(this, s32 *, 0xC) = 0;
}

void SB2::SeekOn(AITargetData *arg0) {
    this->unk460 |= 1;
    M2C_FIELD(this, AITargetData **, 0xC) = arg0;
    ResetSteerDirections();
}

#if 0 // DRAFT: expression syntax error
void SB2::ResetSteerDirections() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r3_7079;

    this->unk3F8 = 0;
    this->unk78 = 0.0f;
    M2C_FIELD(this, f32 *, 0x68) = 1.0f;
    M2C_FIELD(this, f32 *, 0x6C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x70) = 0.0f;
    temp_r3_7079 = this->unk0;
    if (temp_r3_7079 != NULL) {
        temp_r3_7079->unk8->ZAxis3();
        sp8 = -*M2C_ERROR(/* Read from unset register $r3 */);
        spC = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
        sp10 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        this->unk68 = (f64) sp8;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        this->unk70 = (f64) sp10;
    }
    memset(&this->unk100, 0, 0x2F8U);
}
#endif

void SB2::SetExclusionRegion(EnemyRegion *arg0) {
    M2C_FIELD(this, EnemyRegion **, 8) = arg0;
}

void SB2::SetRegion(EnemyRegion *arg0) {
    this->unk4 = arg0;
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void SB2::SetVehicle(Targetable *arg0) {
    this->unk0 = arg0->Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk400'
void SB2::SetDefaults() {
    this->unk4 = NULL;
    M2C_FIELD(this, s32 *, 8) = 0;
    M2C_FIELD(this, s32 *, 0xC) = 0;
    this->unk10 = NULL;
    this->unk18.SetDefaults();
    this->unk460 = 0;
    this->unk464 &= ~0x80;
    this->unk464 &= ~0x20;
    this->unk464 |= 0x10;
    memset(&this->unk400, 0, 0x20U);
    memset(&this->unk420, 0, 0x18U);
    memset(&this->unk438, 0, 0x28U);
    ResetSteerDirections();
}
#endif

void SB2::Deinit() {
    this->unk0 = NULL;
}

void SB2::Init() {
    this->unk0 = NULL;
    SetDefaults();
}

#if 0 // DRAFT: undefined identifier 'vBaseHeading'
void SB2_cpp::__sinit() {
    M2C_FIELD(&vBaseHeading, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(&vBaseHeading, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
}
#endif
