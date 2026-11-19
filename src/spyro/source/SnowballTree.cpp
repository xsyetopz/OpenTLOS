#include "spyro/source/SnowballTree.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Ball.h"
#include "spyro/source/KDProp.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern s32 GS_SnowTreeHit;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal explicit conversion from 'SnowballTree' to
void SnowballTree::DropABall() {
    s32 var_ctr_50;
    s32 var_r4_47;

    var_r4_47 = 0;
    var_ctr_50 = 3;
loop_1:
    if ((s32) M2C_FIELD(*(this + (var_r4_47 + 0x90)), s32 *, 0x270) == 1) {
        ((Ball *) (M2C_FIELD((this + var_r4_47), Ball **, 0x90)))->DropFromTree();
        return;
    }
    var_r4_47 += 4;
    var_ctr_50 -= 1;
    if (var_ctr_50 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal type
void SnowballTree::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 4) {

    } else {
        DropABall();
        if (KDSound_IsVoicePlaying(this->unkB4) == 0) {
            this->unkB4 = KDSound_Play3d(GS_SnowTreeHit, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
        this->unk80->SetAnim(M2C_FIELD(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x8C), 1.0f, 0.0f, 0, -1);
        this->unkC4 = 1;
    }
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: ')' expected
void SnowballTree::Update() {
    f32 temp_f2_134;
    f32 temp_f31_172;

    KDProp::Update();
    temp_f2_134 = this->unkBC;
    if (temp_f2_134 > 0.0f) {
        this->unkBC = temp_f2_134 - gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkBC == 0.0f) {
            this->unkB8 = KDSound_Play3d(M2C_FIELD(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x7C), &this->unkA0, 0U, -1, 0.0f, 0U);
        }
    }
    if (((s32) M2C_FIELD(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x7C) != 0) && (KDSound_IsVoicePlaying(this->unkB8) == 0)) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkBC == 0.0f) {
            temp_f31_172 = M2C_FIELD(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x84);
            this->unkBC = MKRand_Float(&gViewSeed, M2C_FIELD(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80), temp_f31_172);
        }
    }
    if (((u8) this->unkC4 != 0) && (this->unk80->unk2C & 1)) {
        this->unk80->SetAnim(M2C_FIELD(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x88), 1.0f, 0.0f, 0, -1);
        this->unkC4 = 0;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void SnowballTree::LoadDone() {
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    M2C_UNK sp18;
    f32 sp10;
    s32 temp_r29_251;
    s32 var_r28_232;
    s32 var_r31_234;
    void *temp_r3_267;

    KDProp::LoadDone();
    MKVector(0.0f, 600.0f, 0.0f);
    sp28.GetPos();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    var_r28_232 = 0;
    var_r31_234 = 0;
    M2C_FIELD(this, f64 *, 0xA0) = sp8;
    sp10 = sp30 + sp20;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0xA8) = (f64) sp10;
    do {
        temp_r29_251 = var_r31_234 + 0x90;
        *(this + temp_r29_251) = checked_cast<Ball *, MKProp>(gMK->CreateProp("BallTest"));
        MKModel_CalculateRefPointWorldPosition(this->unk4, *(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r31_234 + 0x70)), &sp48);
        ((Ball *) (*(this + temp_r29_251)))->SetParentTree(this, (s32) this->unkB0, sp48, this->unkC0);
        temp_r3_267 = *(this + temp_r29_251);
        M2C_FIELD(M2C_FIELD(temp_r3_267, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_267);
        var_r28_232 += 1;
        var_r31_234 += 4;
    } while (var_r28_232 < 3);
    this->unk80->SetAnim(M2C_FIELD(checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x88), 1.0f, 0.0f, 0, -1);
    this->unk80->unk38 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
}
#endif

#if 0 // DRAFT: identifier 'SnowballTree::LoadLine(MKIniLine *)' redeclared
u8 SnowballTree::LoadLine(MKIniLine *arg0) {
    if (KDProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->IsField("group") != 0) {
        this->unkB0 = arg0->GetInt(0);
        return 1U;
    }
    return (u8) (arg0->LoadFloat("MaxBallDistance", &this->unkC0, 0) != 0);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void SnowballTree::Deinit() {
    KDProp::Deinit();
    KDSound_Stop(&this->unkB4);
    KDSound_Stop(&this->unkB8);
}
#endif

void SnowballTree::Init() {
    KDProp::Init();
    this->unkB0 = 0xFF;
    this->unkB4 = 0;
    this->unkB8 = 0;
    this->unkBC = 0.0f;
    this->unkC4 = 0;
    this->unkC0 = 200.0f;
}

#if 0 // DRAFT: expression syntax error
void SnowballTreeDescriptor::LoadDone() {
    s8 *temp_r30_426;
    s8 *temp_r30_443;
    void *var_r3_435;
    void *var_r3_453;

    KDPropDescriptor::LoadDone();
    this->unk70 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ballspawn01");
    this->unk74 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ballspawn02");
    this->unk78 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ballspawn03");
    temp_r30_426 = this->unk34;
    if (temp_r30_426->Exists("idle") != 0) {
        var_r3_435 = temp_r30_426->GetAnim("idle");
    } else {
        var_r3_435 = NULL;
    }
    this->unk88 = (s32) var_r3_435;
    temp_r30_443 = this->unk34;
    if (temp_r30_443->Exists("hit") != 0) {
        var_r3_453 = temp_r30_443->GetAnim("hit");
    } else {
        var_r3_453 = NULL;
    }
    this->unk8C = (s32) var_r3_453;
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[16], long *)' does
s32 SnowballTreeDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_475;

    var_r31_475 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("MinSoundDelay", &this->unk80, 0) != 0) || (arg0->LoadFloat("MaxSoundDelay", &this->unk84, 0) != 0) || (KDSound_LoadLine(arg0, "OccasionalSound", &this->unk7C) != 0)) {
        var_r31_475 = 1;
    }
    return var_r31_475;
}
#endif

void SnowballTreeDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk7C = GS_PLACEHOLDER;
    this->unk80 = 10.0f;
    this->unk84 = 45.0f;
}

void SnowBallTree_InitModule() {

}

void SnowballTree_cpp::__sinit() {
    f32 temp_f0_585;
    f64 temp_f1_566;
    f64 temp_f1_574;
    f64 temp_f3_554;
    f64 temp_f4_563;
    f64 temp_f4_571;
    f64 temp_f8_556;

    temp_f3_554 = __frsqrte(2014000.0);
    temp_f8_556 = __frsqrte(380000.0);
    temp_f4_563 = 0.5 * temp_f3_554 * -((2014000.0 * (temp_f3_554 * temp_f3_554)) - 3.0);
    temp_f1_566 = 0.5 * temp_f8_556 * -((380000.0 * (temp_f8_556 * temp_f8_556)) - 3.0);
    temp_f4_571 = 0.5 * temp_f4_563 * -((2014000.0 * (temp_f4_563 * temp_f4_563)) - 3.0);
    temp_f1_574 = 0.5 * temp_f1_566 * -((380000.0 * (temp_f1_566 * temp_f1_566)) - 3.0);
    temp_f0_585 = (f32) (380000.0 * (0.5 * temp_f1_574 * -((380000.0 * (temp_f1_574 * temp_f1_574)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_571 * -((2014000.0 * (temp_f4_571 * temp_f4_571)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_585;
}
