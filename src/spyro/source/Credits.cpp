#include "spyro/source/Credits.h"
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
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/TimeDeltaModifier.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

s32 atoi();                                         /* extern */
M2C_UNK free(MKIni *);                              /* extern */
MKIni *malloc(M2C_UNK);                             /* extern */
extern s8 DialogBox_bAllowOverCutscene;
extern u8 bDrawn;
extern s32 gDisplay;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern s32 gpTranslation_StringArray;
extern MKIni *pCredits;
extern s8 *platformCode;

void CreditsScreen::Draw(const RenderContext &arg0) {
    Credits_Draw();
    UIContainer::Draw(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'UISystem *' to
void CreditsScreen::Update() {
    s32 sp8;
    void **temp_r3_46;

    UIScreen::Update();
    if (((MKIni *) pCredits == NULL) || ((u8) M2C_FIELD(pCredits, u8 *, 0xF0) == 0)) {
        temp_r3_46 = ui_cast<UISystem *, UIContainer *>(GetRoot());
        sp8 = 0xF;
        M2C_FIELD(*temp_r3_46, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

void CreditsScreen::OnExit() {
    Credits_Deinit();
    UIScreen::OnExit();
}

void CreditsScreen::OnEnter() {
    s32 spC;
    s32 sp8;

    UIScreen::OnEnter();
    Credits_Init(NULL);
    spC = 0;
    sp8 = 0xB5;
    Credits_Message((MKMessage *) &sp8);
}

void CreditsProp::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xA5) {

    } else {
        this->unk4C.Send((MKProp *) this);
    }
    Credits_Message(arg0);
    MKProp::Message(arg0);
}

s32 CreditsProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_140;

    var_r31_140 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (this->unk4C.LoadLine(arg0, "onEnd") != 0)) {
        var_r31_140 = 1;
    }
    return var_r31_140;
}

void CreditsProp::Deinit() {
    Credits_Deinit();
    MKProp::Deinit();
}

void CreditsProp::Init() {
    MKProp::Init();
    Credits_Init((MKProp *) this);
}

s32 Credits_Active() {
    if (((MKIni *) pCredits != NULL) && ((u8) M2C_FIELD(pCredits, u8 *, 0xF0) != 0)) {
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier 'Credits_PopulatePage'
void Credits_Message(MKMessage *arg0) {
    MKIniLine *temp_r3_263;
    MKIniLine *temp_r4_246;
    MKIniLine *temp_r4_256;
    s32 temp_r0_220;

    temp_r0_220 = arg0->unk0;
    switch (temp_r0_220) {                          /* irregular */
    case 0xB5:
        if ((MKIni *) pCredits != NULL) {
            ((TimeDeltaModifier *) (&gb + 0x2CC))->Reset();
            M2C_FIELD(pCredits, s8 *, 0xF0) = 1;
            M2C_FIELD(pCredits, s32 *, 0xA8) = 0;
            M2C_FIELD(pCredits, MKIniLine **, 0xA0) = pCredits->GetFirstLine();
            temp_r4_246 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
            M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_246->unkC->GetSubLine(temp_r4_246);
loop_7:
            temp_r3_263 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
            if ((temp_r3_263 != NULL) && (temp_r3_263->IsField("page") == 0)) {
                temp_r4_256 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
                M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_256->unkC->GetNextLine(temp_r4_256);
                goto loop_7;
            }
            Credits_PopulatePage();
            M2C_FIELD(pCredits, f32 *, 0xEC) = 512.0f;
            M2C_FIELD(pCredits, f32 *, 0xE4) = (f32) (M2C_FIELD(pCredits, f32 *, 0xE4) + gUpdateTimeDelta);
            return;
        }
        return;
    case 0xB4:
        if ((MKIni *) pCredits != NULL) {
            M2C_FIELD(pCredits, s8 *, 0xF0) = 0;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void Credits_Draw() {
    Matrix sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKIniLine *temp_r28_486;
    MKIniLine *temp_r28_529;
    MKIniLine *temp_r3_505;
    MKIniLine *temp_r3_531;
    MKIniLine *temp_r3_545;
    MKIniLine *var_r29_333;
    f32 var_f27_363;
    f32 var_f31_362;
    s32 temp_cr0_eq_532;
    s32 var_r28_409;
    u8 temp_r0_411;

    if (((MKIni *) pCredits != NULL) && ((u8) M2C_FIELD(pCredits, u8 *, 0xF0) != 0)) {
        if ((u8) bDrawn != 0) {
            return;
        }
        bDrawn = 1;
        if ((s32) M2C_FIELD(pCredits, s32 *, 0xA8) != 1) {
            return;
        }
        var_r29_333 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
        sp90.SetIdentity();
        sp40 = 320.0f;
        sp44 = M2C_FIELD(pCredits, f32 *, 0xEC);
        sp48 = 0.0f;
        sp80 = (f64) sp40;
        sp88 = (f64) sp48;
        sp90.Translate(&sp90, *((MKVector3 *) &sp80));
loop_31:
        if ((sp90.unk34 < 512.0f) && (var_r29_333 != NULL)) {
            var_f31_362 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
            var_f27_363 = 1.0f;
            if (var_r29_333->IsField("heading") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xAC);
            } else if (var_r29_333->IsField("title") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xB0);
            } else if (var_r29_333->IsField("person") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xB4);
            } else if (var_r29_333->IsField("space") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xB8);
            }
            var_r28_409 = var_r29_333->GetString(0);
            if (var_r28_409 != 0) {
                temp_r0_411 = *var_r28_409;
                if (((s8) temp_r0_411 >= 0x30) && ((s8) temp_r0_411 <= 0x39)) {
                    var_r28_409 = *(gpTranslation_StringArray + (atoi() * 4));
                }
            }
            if ((u32) var_r28_409 != 0U) {
                var_f31_362 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString((s8 *) var_r28_409, 512.0f, 256.0f * var_f27_363, &sp90, 9, 0x80808080U, var_f27_363, var_f27_363, DummyRenderText, 0U);
                sp38 = 0.0f;
                sp30 = 0.0f;
                sp34 = 0.5f * var_f31_362;
                sp78 = (f64) sp38;
                sp70 = (f64) sp30;
                sp90.Translate(&sp90, *((MKVector3 *) &sp70));
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString((s8 *) var_r28_409, 512.0f, var_f31_362, &sp90, 9, 0x80808080U, var_f27_363, var_f27_363, NULL, 0U);
                sp28 = 0.0f;
                sp20 = 0.0f;
                sp24 = -0.5f * var_f31_362;
                sp68 = (f64) sp28;
                sp60 = (f64) sp20;
                sp90.Translate(&sp90, *((MKVector3 *) &sp60));
            }
            if ((var_f31_362 + sp90.unk34) < 0.0f) {
                temp_r28_486 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
                M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r28_486->unkC->GetNextLine(temp_r28_486);
                if (((MKIniLine *) M2C_FIELD(pCredits, MKIniLine **, 0xA0) == NULL) && ((MKIni *) temp_r28_486->unkC == (MKIni *) pCredits) && (((MKIni *) (pCredits + 0x50))->GetFirstLine() != NULL)) {
                    temp_r3_505 = ((MKIni *) (pCredits + 0x50))->GetFirstLine();
                    M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r3_505->unkC->GetSubLine(temp_r3_505);
                }
                M2C_FIELD(pCredits, f32 *, 0xEC) = (f32) (M2C_FIELD(pCredits, f32 *, 0xEC) + var_f31_362);
            }
            sp18 = 0.0f;
            sp10 = 0.0f;
            sp14 = var_f31_362;
            sp58 = (f64) sp18;
            sp50 = (f64) sp10;
            sp90.Translate(&sp90, *((MKVector3 *) &sp50));
            temp_r28_529 = var_r29_333;
            temp_r3_531 = var_r29_333->unkC->GetNextLine(var_r29_333);
            temp_cr0_eq_532 = temp_r3_531 == NULL;
            var_r29_333 = temp_r3_531;
            if ((temp_cr0_eq_532 != 0) && ((MKIni *) temp_r28_529->unkC == (MKIni *) pCredits) && (((MKIni *) (pCredits + 0x50))->GetFirstLine() != NULL)) {
                temp_r3_545 = ((MKIni *) (pCredits + 0x50))->GetFirstLine();
                var_r29_333 = temp_r3_545->unkC->GetSubLine(temp_r3_545);
            }
            goto loop_31;
        }
    }
}
#endif

void DummyRenderText(TextCharStrip **arg0, int arg1, const Matrix &arg2) {

}

#if 0 // DRAFT: illegal implicit conversion from 'MKIni' to
s32 Credits_Update() {
    s32 spC;
    s32 sp8;
    DialogBoxContext *temp_r3_630;
    MKIniLine *temp_r4_635;
    MKIniLine *temp_r4_668;
    f32 temp_f1_612;
    f32 var_f0_712;
    f32 var_f0_728;
    s32 temp_r0_601;
    s32 temp_r0_621;
    s32 var_r28_616;
    s32 var_r30_615;
    s32 var_r3_683;
    s32 var_r5_682;
    u8 var_r31_599;
    void *temp_r3_745;
    void *temp_r4_694;

    if (((MKIni *) pCredits == NULL) || ((u8) M2C_FIELD(pCredits, u8 *, 0xF0) == 0)) {
        return 0;
    }
    var_r31_599 = 0;
    bDrawn = 0;
    temp_r0_601 = M2C_FIELD(pCredits, s32 *, 0xA8);
    switch (temp_r0_601) {                          /* irregular */
    case 0:
        temp_f1_612 = M2C_FIELD(pCredits, f32 *, 0xE8) - M2C_FIELD(pCredits, f32 *, 0xE4);
        if (temp_f1_612 < 0.0f) {
            var_r30_615 = 0;
            var_r28_616 = 0;
loop_10:
            if (var_r28_616 < 0xA) {
                temp_r3_630 = *(pCredits + (var_r30_615 + 0xBC));
                if (temp_r3_630 != NULL) {
                    DialogBox_ReleaseContext(temp_r3_630);
                    temp_r0_621 = var_r30_615 + 0xBC;
                    var_r28_616 += 1;
                    var_r30_615 += 4;
                    *(pCredits + temp_r0_621) = 0;
                    goto loop_10;
                }
            }
            temp_r4_635 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
            M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_635->unkC->GetNextLine(temp_r4_635);
            if (((MKIniLine *) (M2C_FIELD(pCredits, MKIniLine **, 0xA0)))->IsField("page") != 0) {
                M2C_FIELD(pCredits, f32 *, 0xE4) = 0.0f;
                M2C_FIELD(pCredits, f32 *, 0xE8) = ((MKIniLine *) (M2C_FIELD(pCredits, MKIniLine **, 0xA0)))->GetFloat(0);
                goto block_21;
            }
            if (((MKIniLine *) (M2C_FIELD(pCredits, MKIniLine **, 0xA0)))->IsField("scroll") != 0) {
                temp_r4_668 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
                M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_668->unkC->GetNextLine(temp_r4_668);
                M2C_FIELD(pCredits, s32 *, 0xA8) = 1;
            } else {
                goto block_21;
            }
        } else {
            if (temp_f1_612 < 0.5f) {
                var_r5_682 = 0;
                var_r3_683 = 0;
loop_19:
                if (var_r5_682 < 0xA) {
                    temp_r4_694 = *(pCredits + (var_r3_683 + 0xBC));
                    if (temp_r4_694 != NULL) {
                        M2C_FIELD(temp_r4_694, f32 *, 0x2C) = (f32) (temp_f1_612 / 0.5f);
                        var_r5_682 += 1;
                        var_r3_683 += 4;
                        goto loop_19;
                    }
                }
            }
block_21:
            if (M2C_FIELD(pCredits, f32 *, 0xE4) == 0.0f) {
                Credits_PopulatePage();
            }
            if ((s32) gDisplay == 1) {
                var_f0_712 = 30.0f;
            } else {
                var_f0_712 = 25.0f;
            }
            M2C_FIELD(pCredits, f32 *, 0xE4) = (f32) (M2C_FIELD(pCredits, f32 *, 0xE4) + (1.0f / var_f0_712));
        }
        break;
    case 1:
        if ((s32) gDisplay == 1) {
            var_f0_728 = 30.0f;
        } else {
            var_f0_728 = 25.0f;
        }
        M2C_FIELD(pCredits, f32 *, 0xEC) = (f32) -((60.0f * (1.0f / var_f0_728)) - M2C_FIELD(pCredits, f32 *, 0xEC));
        var_r31_599 = M2C_FIELD(pCredits, MKIniLine **, 0xA0) == NULL;
        break;
    }
    if (var_r31_599 != 0) {
        temp_r3_745 = M2C_FIELD(pCredits, void **, 0xA4);
        if (temp_r3_745 != NULL) {
            spC = 0;
            sp8 = 0xA5;
            M2C_FIELD(M2C_FIELD(temp_r3_745, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        M2C_FIELD(pCredits, u8 *, 0xF0) = 0U;
    }
    return var_r31_599 == 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void Credits_PopulatePage() {
    MKIniLine *temp_r4_800;
    MKIniLine *temp_r4_864;
    MKIniLine *var_r29_804;
    MKIniLine *var_r30_870;
    f32 temp_f31_798;
    f32 var_f30_799;
    f32 var_f30_865;
    s32 temp_r29_1001;
    s32 temp_r29_901;
    s32 temp_r29_951;
    s32 temp_r4_1004;
    s32 temp_r4_904;
    s32 temp_r4_954;
    s32 var_r28_871;
    s32 var_r29_869;
    s32 var_r5_883;
    s32 var_r5_933;
    s32 var_r5_983;
    u8 temp_r0_885;
    u8 temp_r0_935;
    u8 temp_r0_985;

    M2C_FIELD(pCredits, f32 *, 0xE4) = 0.0f;
    M2C_FIELD(pCredits, f32 *, 0xE8) = ((MKIniLine *) (M2C_FIELD(pCredits, MKIniLine **, 0xA0)))->GetFloat(0);
    temp_f31_798 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
    var_f30_799 = 0.0f;
    temp_r4_800 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
    var_r29_804 = temp_r4_800->unkC->GetSubLine(temp_r4_800);
loop_10:
    if (var_r29_804 != NULL) {
        if (var_r29_804->IsField("heading") != 0) {
            var_f30_799 += M2C_FIELD(pCredits, f32 *, 0xAC);
        } else if (var_r29_804->IsField("title") != 0) {
            var_f30_799 += M2C_FIELD(pCredits, f32 *, 0xB0);
        } else if (var_r29_804->IsField("person") != 0) {
            var_f30_799 += M2C_FIELD(pCredits, f32 *, 0xB4);
        } else if (var_r29_804->IsField("space") != 0) {
            var_f30_799 += M2C_FIELD(pCredits, f32 *, 0xB8);
        }
        var_r29_804 = var_r29_804->unkC->GetNextLine(var_r29_804);
        goto loop_10;
    }
    temp_r4_864 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
    var_f30_865 = -((0.5f * (var_f30_799 * temp_f31_798)) - 256.0f);
    var_r29_869 = 0;
    var_r30_870 = temp_r4_864->unkC->GetSubLine(temp_r4_864);
    var_r28_871 = 0;
loop_33:
    if (var_r30_870 != NULL) {
        if (var_r30_870->IsField("heading") != 0) {
            var_r5_883 = var_r30_870->GetString(0);
            if (var_r5_883 != 0) {
                temp_r0_885 = *var_r5_883;
                if (((s8) temp_r0_885 >= 0x30) && ((s8) temp_r0_885 <= 0x39)) {
                    var_r5_883 = *(gpTranslation_StringArray + (atoi() * 4));
                }
            }
            Credits_AddPageLine((s8 *) var_r5_883, var_f30_865, M2C_FIELD(pCredits, f32 *, 0xAC));
            temp_r29_901 = var_r29_869;
            temp_r4_904 = var_r28_871 + 0xBC;
            var_r29_869 += 1;
            var_r28_871 += 4;
            *(pCredits + temp_r4_904) = M2C_ERROR(/* Read from unset register $r3 */);
            M2C_FIELD(*(pCredits + temp_r4_904), f32 *, 0x68) = (f32) (0.2f * (f32) temp_r29_901);
            var_f30_865 += M2C_FIELD(pCredits, f32 *, 0xAC) * temp_f31_798;
        } else if (var_r30_870->IsField("title") != 0) {
            var_r5_933 = var_r30_870->GetString(0);
            if (var_r5_933 != 0) {
                temp_r0_935 = *var_r5_933;
                if (((s8) temp_r0_935 >= 0x30) && ((s8) temp_r0_935 <= 0x39)) {
                    var_r5_933 = *(gpTranslation_StringArray + (atoi() * 4));
                }
            }
            Credits_AddPageLine((s8 *) var_r5_933, var_f30_865, M2C_FIELD(pCredits, f32 *, 0xB0));
            temp_r29_951 = var_r29_869;
            temp_r4_954 = var_r28_871 + 0xBC;
            var_r29_869 += 1;
            var_r28_871 += 4;
            *(pCredits + temp_r4_954) = M2C_ERROR(/* Read from unset register $r3 */);
            M2C_FIELD(*(pCredits + temp_r4_954), f32 *, 0x68) = (f32) (0.2f * (f32) temp_r29_951);
            var_f30_865 += M2C_FIELD(pCredits, f32 *, 0xB0) * temp_f31_798;
        } else if (var_r30_870->IsField("person") != 0) {
            var_r5_983 = var_r30_870->GetString(0);
            if (var_r5_983 != 0) {
                temp_r0_985 = *var_r5_983;
                if (((s8) temp_r0_985 >= 0x30) && ((s8) temp_r0_985 <= 0x39)) {
                    var_r5_983 = *(gpTranslation_StringArray + (atoi() * 4));
                }
            }
            Credits_AddPageLine((s8 *) var_r5_983, var_f30_865, M2C_FIELD(pCredits, f32 *, 0xB4));
            temp_r29_1001 = var_r29_869;
            temp_r4_1004 = var_r28_871 + 0xBC;
            var_r29_869 += 1;
            var_r28_871 += 4;
            *(pCredits + temp_r4_1004) = M2C_ERROR(/* Read from unset register $r3 */);
            M2C_FIELD(*(pCredits + temp_r4_1004), f32 *, 0x68) = (f32) (0.2f * (f32) temp_r29_1001);
            var_f30_865 += M2C_FIELD(pCredits, f32 *, 0xB4) * temp_f31_798;
        } else if (var_r30_870->IsField("space") != 0) {
            var_f30_865 += M2C_FIELD(pCredits, f32 *, 0xB8) * temp_f31_798;
        }
        var_r30_870 = var_r30_870->unkC->GetNextLine(var_r30_870);
        goto loop_33;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void Credits_AddPageLine(const char *arg0, float arg1, float arg2) {
    f32 temp_f31_1072;
    void *temp_r3_1073;

    temp_f31_1072 = arg2 * ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
    temp_r3_1073 = DialogBox_InitContext();
    M2C_FIELD(temp_r3_1073, s32 *, 0) = 0;
    M2C_FIELD(temp_r3_1073, f32 *, 0x10) = 48.0f;
    M2C_FIELD(temp_r3_1073, f32 *, 0x14) = arg1;
    M2C_FIELD(temp_r3_1073, f32 *, 0x18) = 544.0f;
    M2C_FIELD(temp_r3_1073, f32 *, 0x1C) = temp_f31_1072;
    M2C_FIELD(temp_r3_1073, s8 **, 0x30) = arg0;
    M2C_FIELD(temp_r3_1073, f32 *, 0x34) = arg2;
    M2C_FIELD(temp_r3_1073, s32 *, 0xC) = 0xC;
    M2C_FIELD(temp_r3_1073, s32 *, 0x6C) = 0;
    M2C_FIELD(temp_r3_1073, s32 *, 4) = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKIni' to
void Credits_Deinit() {
    DialogBoxContext *temp_r3_1128;
    MKIni *temp_r30_1134;
    s32 temp_r0_1119;
    s32 var_r29_1112;
    s32 var_r31_1114;

    if ((MKIni *) pCredits != NULL) {
        var_r29_1112 = 0;
        DialogBox_bAllowOverCutscene = 0;
        var_r31_1114 = 0;
loop_3:
        if (var_r29_1112 < 0xA) {
            temp_r3_1128 = *(pCredits + (var_r31_1114 + 0xBC));
            if (temp_r3_1128 != NULL) {
                DialogBox_ReleaseContext(temp_r3_1128);
                temp_r0_1119 = var_r31_1114 + 0xBC;
                var_r29_1112 += 1;
                var_r31_1114 += 4;
                *(pCredits + temp_r0_1119) = 0;
                goto loop_3;
            }
        }
        pCredits->Deinit();
        temp_r30_1134 = pCredits;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r30_1134, NULL, 0);
        } else {
            free(temp_r30_1134);
        }
        pCredits = NULL;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Credits_Init(MKProp *arg0) {
    MKIni *var_r3_1176;

    if (arg0 == NULL) {
        MKHeap::ActivateTempMemOverride();
    }
    if (MKHeap::Current() != NULL) {
        var_r3_1176 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xF4, NULL, 0);
    } else {
        var_r3_1176 = malloc(0xF4);
    }
    pCredits = var_r3_1176;
    memset(var_r3_1176, 0, 0xF4U);
    M2C_FIELD(pCredits, f32 *, 0xAC) = 1.0f;
    M2C_FIELD(pCredits, f32 *, 0xB0) = 1.0f;
    M2C_FIELD(pCredits, f32 *, 0xB4) = 1.0f;
    M2C_FIELD(pCredits, f32 *, 0xB8) = 1.0f;
    pCredits->Init("credits.ini", 0, platformCode);
    if ((s32) gDisplay == 0) {
        ((MKIni *) (pCredits + 0x50))->Init("credits-pal.ini", 0, platformCode);
    }
    M2C_FIELD(pCredits, MKProp **, 0xA4) = arg0;
    if ((s32) *MKHeap::tempMemOverride > 0) {
        MKHeap::DeactivateTempMemOverride();
    }
    DialogBox_bAllowOverCutscene = 1;
}
#endif
