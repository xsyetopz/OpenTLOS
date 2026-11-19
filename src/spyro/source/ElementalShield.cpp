#include "spyro/source/ElementalShield.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_ElecBossFieldHurtSpyro;
extern s32 GS_ElecBossForceFieldLP;
extern s32 GS_ElecBossForceFieldStart;
extern s32 GS_ElecBossForceFieldStop;
extern s32 GS_IceBossFieldHurtSpyro;
extern s32 GS_IceBossForceFieldLP;
extern s32 GS_IceBossForceFieldStart;
extern s32 GS_IceBossForceFieldStop;
extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern void **gb;

#if 0 // DRAFT: function call 'MKMaterial_Create(signed char[17])' does not match
static s8 lit_stringBase0[0x11] = {
    0x46,
    0x58,
    0x5F,
    0x42,
    0x6F,
    0x73,
    0x73,
    0x53,
    0x68,
    0x69,
    0x65,
    0x6C,
    0x64,
    0x49,
    0x63,
    0x65,
    0,
}; /* const */

void ElementalShield::SetElement(int arg0) {
    this->unkA4 = arg0;
    if ((s32) this->unkA4 == 2) {
        this->unkB0 = MKMaterial_Create(lit_stringBase0);
        this->unkB4 = GS_IceBossForceFieldStart;
        this->unkB8 = GS_IceBossForceFieldStop;
        this->unkBC = GS_IceBossForceFieldLP;
        this->unkC0 = GS_IceBossFieldHurtSpyro;
        return;
    }
    this->unkB4 = GS_ElecBossForceFieldStart;
    this->unkB8 = GS_ElecBossForceFieldStop;
    this->unkBC = GS_ElecBossForceFieldLP;
    this->unkC0 = GS_ElecBossFieldHurtSpyro;
}
#endif

void ElementalShield::Disable() {
    this->unk90 = 0;
}

#if 0 // DRAFT: illegal type
void ElementalShield::Trigger(MKVector3 *arg0, float arg1, bool arg2) {
    if ((s32) this->unk90 == 0) {
        this->unk90 = 1;
        KDSound_Play3d(this->unkB4, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        this->unk98 = arg1;
        this->unk9C = 0.0f;
        this->unk94 = 1.0f;
        this->unkA8 = arg2;
        this->unkAC = arg0;
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void ElementalShield::Deinit() {
    MKMaterial *temp_r3_152;

    temp_r3_152 = this->unkB0;
    if (temp_r3_152 != NULL) {
        MKMaterial_Destroy(temp_r3_152);
        this->unkB0 = NULL;
    }
    KDSound_Stop(&this->unkC4);
    KDProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spC'
void ElementalShield::Draw() {
    MKMaterial *temp_r0_222;
    MKVector3 *temp_r3_210;
    if ((s32) this->unk90 != 0) {
        if ((MKVector3 *) this->unkAC == NULL) {
            return;
        }
        M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (&identity - 4) + 4, 0x40);
        arg_sp10.SetRotationYaw(this->unkA0);
        arg_sp10.Scale3x3((Matrix *) &arg_sp10, this->unk9C * this->unk98);
        temp_r3_210 = this->unkAC;
        arg_sp40 = temp_r3_210->unk0;
        arg_sp44 = temp_r3_210->unk4;
        arg_sp48 = temp_r3_210->unk8;
        arg_sp4C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
        temp_r0_222 = this->unkB0;
        if (temp_r0_222 != NULL) {
            gRenderState = temp_r0_222;
        }
        KDProp::Draw();
        if ((MKMaterial *) this->unkB0 != NULL) {
            gRenderState = NULL;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void ElementalShield::Message(MKMessage *arg0) {
    this->unkC4.Message(arg0);
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void ElementalShield::Update() {
    s8 spC1;
    s8 spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    ElementalShield *sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKVector3 *temp_r30_400;
    f32 temp_f0_434;
    f32 temp_f1_293;
    f32 var_f0_320;
    f32 var_f0_365;
    s32 temp_r0_306;
    void *temp_r3_410;

    sp8 = 1;
    this->unkC4.Update(this->unkBC, 1U, this->unk90 != 0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unkA0 += 6.0f * gUpdateTimeDelta;
    temp_f1_293 = this->unkA0;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_293 == 6.2831855f) {
        this->unkA0 = temp_f1_293 - 6.2831855f;
    }
    KDProp::Update();
    this->unk94 -= gUpdateTimeDelta;
    temp_r0_306 = this->unk90;
    switch (temp_r0_306) {                          /* irregular */
    case 0:
        break;
    case 1:
        var_f0_320 = this->unk94;
        if (var_f0_320 < 1.0f) {

        } else {
            var_f0_320 = 1.0f;
        }
        if (var_f0_320 > 0.0f) {

        } else {
            var_f0_320 = 0.0f;
        }
        this->unk94 = var_f0_320;
        this->unk9C = 1.0f - this->unk94;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk94 == 0.0f) {
            this->unk94 = 10.0f;
            this->unk90 = 2;
        }
    default:
block_29:
        temp_r30_400 = this->unkAC;
        if (temp_r30_400 != NULL) {
            temp_r3_410 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
            sp50 = M2C_FIELD(temp_r3_410, f64 *, 0x30);
            sp58 = M2C_FIELD(temp_r3_410, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp60 = sp30;
            sp38 = (f32) sp58 - temp_r30_400->unk8;
            sp68 = (f64) sp38;
            temp_f0_434 = 50.0f * this->unk9C * this->unk98;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64))) == (temp_f0_434 * temp_f0_434)) {
                sp18 = 0.0f;
                sp10 = 0.0f;
                sp14 = 0.0f;
                sp74 = 0;
                sp40 = (f64) sp10;
                sp48 = (f64) sp18;
                sp70 = 7;
                sp98 = 2;
                sp9C = this;
                sp78 = (f64) sp10;
                sp80 = (f64) sp18;
                spB0 = 1;
                spBC = 2;
                spB8 = 10.0f;
                spB1 = 0;
                spB2 = 1;
                spB4 = -1;
                sp88 = M2C_FIELD(&one, f64 *, 0);
                sp90 = M2C_FIELD(&one, f64 *, 8);
                spC0 = 0;
                if (this != NULL) {
                    sp20.GetPos();
                    spA0 = sp20;
                    spA8 = sp28;
                } else {
                    spA0 = 0.0f;
                    unkspA4 = 0.0f;
                    spA8 = 0.0f;
                }
                spC1 = 0;
                KDSound_Play3d(this->unkC0, M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
                M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp70);
            }
        }
        break;
    case 2:
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((this->unk94 == 0.0f) && ((u8) this->unkA8 == 0)) {
            this->unk94 = 1.0f;
            this->unk90 = 3;
        }
        goto block_29;
    case 3:
        var_f0_365 = this->unk94;
        if (var_f0_365 < 1.0f) {

        } else {
            var_f0_365 = 1.0f;
        }
        if (var_f0_365 > 0.0f) {

        } else {
            var_f0_365 = 0.0f;
        }
        this->unk94 = var_f0_365;
        this->unk9C = this->unk94;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk94 == 0.0f) {
            this->unk90 = 0;
            KDSound_Play3d(this->unkB8, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            this->unkAC = NULL;
        }
        goto block_29;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void ElementalShield::Init() {
    KDProp::Init();
    this->unk90 = 0;
    this->unk94 = 0.0f;
    this->unk98 = 1.0f;
    this->unk9C = 0.0f;
    this->unkA8 = 0;
    this->unkAC = NULL;
    this->unkA4 = 1;
    this->unkB4 = GS_ElecBossForceFieldStart;
    this->unkB8 = GS_ElecBossForceFieldStop;
    this->unkBC = GS_ElecBossForceFieldLP;
    this->unkC0 = GS_ElecBossFieldHurtSpyro;
    this->unkB0 = NULL;
    this->unkC4.Init(0.75f, 0.75f);
    this->unkA0 = 0.0f;
}
#endif
