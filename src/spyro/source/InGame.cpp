#include "spyro/source/InGame.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/Level.h"
#include "spyro/source/PropGroupVolume.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/File.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKRumble.h"
#include "common/Source/MKSystem.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKMat_MK2_Standard_GC.h"
#include "common/gc/MKMaterial_GC.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/ConnectingProps.h"
#include "spyro/source/Credits.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/Hud.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/PauseMenu.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

s32 stricmp(void *, M2C_UNK, M2C_UNK *);            /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern s32 autoLevelCutsceneNr;
extern u32 autoSwitchState_939;
#if 0 // DRAFT: identifier 'bQuit' redeclared
extern s8 bQuit;
#endif
#if 0 // DRAFT: identifier 'bShowLoading' redeclared
extern u8 bShowLoading;
#endif
extern s32 desiredChunkIndex_963;
#if 0 // DRAFT: identifier 'fingerprintData' redeclared
extern M2C_UNK fingerprintData;
#endif
extern s32 frameDelayCount_956;
extern GlowingPropManager gGlowingPropManager;
extern void **gMK;
extern M2C_UNK gMKDefaults;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern void *gpTranslation_StringArray;
extern f32 inGameTime;
extern u8 init_940;
extern u8 init_945;
extern u8 init_948;
extern u8 init_951;
extern u8 init_954;
extern u8 init_957;
extern u8 init_960;
extern u8 init_964;
extern f32 msgAlpha;
extern f32 msgTime;
extern f32 nextCheck;
extern void *pCutsceneChunkInfo_950;
extern s8 *pCutsceneInfo_953;
extern Level *pInfo_944;
extern Level *pLoadingInfo_947;
extern s8 *pMessage;
extern s32 ppChunk_959;
static M2C_UNK listenerPos;                         /* unable to generate initializer: unknown type */
static Matrix sndCameraMat = {
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
};
static ChunkInfo *pDesiredChunks_962[3];
#if 0 // DRAFT: undefined identifier 'DojoDialogMsg'
static M2C_UNK lit_903;                                /* unable to generate initializer: unknown type; const */

void InGame_SystemMessage(MKMessage *arg0) {
    s32 spC;
    s32 sp8;
    DialogBoxContext *temp_r3_127;
    DialogBoxContext *temp_r3_237;
    DialogBoxContext *temp_r3_300;
    DialogBoxContext *temp_r3_66;
    f32 temp_f31_321;
    f32 var_f0_159;
    f32 var_f1_324;
    f32 var_f31_139;
    s32 temp_r0_18;
    s32 temp_r6_196;
    void *temp_r30_293;
    void *temp_r31_230;
    void *temp_r3_216;

    temp_r0_18 = arg0->unk0;
    if (temp_r0_18 < 0xF8) {
        switch (temp_r0_18) {                       /* irregular */
        case 0x95:
            temp_r31_230 = checked_cast<DojoDialogMsg *, MKMessage>(arg0);
            if ((DialogBoxContext *) gb.unk320 != NULL) {
                DialogBox_ReleaseContext(gb.unk320);
            }
            temp_r3_237 = DialogBox_InitContext();
            gb.unk320 = temp_r3_237;
            temp_r3_237->unk0 = (s32) gb.unk324;
            gb.unk320->unk10 = 54.0f;
            gb.unk320->unk1C = 4.0f * gb.unk318->GetHeight();
            gb.unk320->unk14 = (473.6f - gb.unk320->unk1C) - 6.0f;
            gb.unk320->unk18 = 532.0f;
            M2C_FIELD(gb.unk320, f64 *, 0x98) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 0);
            M2C_FIELD(gb.unk320, f64 *, 0xA0) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 8);
            gb.unk320->unk30 = M2C_FIELD((gpTranslation_StringArray + (M2C_FIELD(temp_r31_230, s32 *, 8) * 4)), s8 **, 0x64C);
            gb.unk320->unkC = 0x31C;
            gb.unk320->unk6C = DojoDialogCallback;
            gb.unk320->unk64 = 30.0f;
            gb.unk320->unk4 = M2C_FIELD(temp_r31_230, void **, 4);
            return;
        case 0x96:
            temp_r30_293 = checked_cast<DojoDialogButtonsMsg *, MKMessage>(arg0);
            if ((DialogBoxContext *) gb.unk320 != NULL) {
                DialogBox_ReleaseContext(gb.unk320);
            }
            temp_r3_300 = DialogBox_InitContext();
            gb.unk320 = temp_r3_300;
            temp_r3_300->unk0 = 0;
            gb.unk320->unk18 = 544.0f;
            gb.unk320->unk10 = -((0.5f * gb.unk320->unk18) - 320.0f);
            gb.unk320->unk14 = 84.399994f;
            temp_f31_321 = gb.unk31C->GetHeight();
            var_f1_324 = gb.unk318->GetHeight();
            if (var_f1_324 > temp_f31_321) {

            } else {
                var_f1_324 = temp_f31_321;
            }
            gb.unk320->unk1C = var_f1_324;
            M2C_FIELD(gb.unk320, f64 *, 0x98) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 0);
            M2C_FIELD(gb.unk320, f64 *, 0xA0) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 8);
            gb.unk320->unk30 = M2C_FIELD(temp_r30_293, s8 **, 0xC);
            gb.unk320->unkC = 0xC;
            gb.unk320->unk6C = DialogCallback;
            gb.unk320->unk64 = 0.0f;
            gb.unk320->unk4 = M2C_FIELD(temp_r30_293, void **, 4);
            return;
        case 0x7D:
            msgAlpha = 0.0f;
            /* fallthrough */
        case 0x7C:
            pMessage = M2C_FIELD(checked_cast<ShowMessage *, MKMessage>(arg0), s8 **, 8);
            msgTime = M2C_FIELD(checked_cast<ShowMessage *, MKMessage>(arg0), f32 *, 0xC);
            break;
        }
    } else if (temp_r0_18 < 0x146) {
        if (temp_r0_18 < 0x138) {
            if (temp_r0_18 < 0x104) {
                if ((DialogBoxContext *) gb.unk320 != NULL) {
                    DialogBox_ReleaseContext(gb.unk320);
                }
                temp_r3_66 = DialogBox_InitContext();
                gb.unk320 = temp_r3_66;
                temp_r3_66->unk0 = (s32) gb.unk324;
                gb.unk320->unk10 = 54.0f;
                gb.unk320->unk1C = 3.0f * gb.unk318->GetHeight();
                gb.unk320->unk14 = (473.6f - gb.unk320->unk1C) - 6.0f;
                gb.unk320->unk18 = 532.0f;
                M2C_FIELD(gb.unk320, f64 *, 0x98) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 0);
                M2C_FIELD(gb.unk320, f64 *, 0xA0) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 8);
                gb.unk320->unk30 = M2C_FIELD((gpTranslation_StringArray + (arg0->unk0 * 4)), s8 **, -0x368);
                gb.unk320->unkC = 0xC;
                gb.unk320->unk6C = DialogCallback;
                gb.unk320->unk64 = 7.5f;
                gb.unk320->unk4 = NULL;
                return;
            }
            if ((DialogBoxContext *) gb.unk320 != NULL) {
                DialogBox_ReleaseContext(gb.unk320);
            }
            temp_r3_127 = DialogBox_InitContext();
            gb.unk320 = temp_r3_127;
            temp_r3_127->unk0 = (s32) gb.unk324;
            gb.unk320->unk10 = 54.0f;
            if ((s32) arg0->unk0 == 0x12F) {
                var_f31_139 = 8.0f;
            } else {
                var_f31_139 = 3.0f;
            }
            gb.unk320->unk1C = var_f31_139 * gb.unk318->GetHeight();
            if ((s32) arg0->unk0 == 0x12F) {
                var_f0_159 = 0.5f * (512.0f - gb.unk320->unk1C);
            } else {
                var_f0_159 = (473.6f - gb.unk320->unk1C) - 6.0f;
            }
            gb.unk320->unk14 = var_f0_159;
            gb.unk320->unk18 = 532.0f;
            M2C_FIELD(gb.unk320, f64 *, 0x98) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 0);
            M2C_FIELD(gb.unk320, f64 *, 0xA0) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 8);
            gb.unk320->unk30 = M2C_FIELD((gpTranslation_StringArray + (arg0->unk0 * 4)), s8 **, 0x108);
            temp_r6_196 = (arg0->unk0 - 0x12F) - 1;
            gb.unk320->unkC = (0x10 & ((temp_r6_196 - temp_r6_196) - !M2C_CARRY)) | 0xC;
            gb.unk320->unk6C = DialogCallback;
            gb.unk320->unk64 = 7.5f;
            gb.unk320->unk4 = NULL;
            if ((s32) arg0->unk0 == 0x12F) {
                temp_r3_216 = gb.unk0->GetProp();
                spC = 0;
                sp8 = 0xA9;
                M2C_FIELD(M2C_FIELD(temp_r3_216, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            }
        } else {
            if (temp_r0_18 < 0x144) {
                return;
            }
            if ((void *) gb.unk2B0 != NULL) {
                M2C_FIELD(M2C_FIELD(gb.unk2B0, void **, 0x44), M2C_UNK (**)(MKMessage *), 0x2C)(arg0);
            }
        }
    } else {
        if (temp_r0_18 != 0x163) {
            return;
        }
        if ((DialogBoxContext *) gb.unk320 != NULL) {
            DialogBox_ReleaseContext(gb.unk320);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk320'
void DojoDialogCallback(DialogBoxContext *arg0, int arg1) {
    s32 spC;
    s32 sp8;
    void *temp_r3_409;

    if ((arg1 == 7) && ((DialogBoxContext *) gb.unk320 == arg0)) {
        gb.unk320 = NULL;
    }
    if (arg1 == 0) {
        temp_r3_409 = arg0->unk4;
        spC = 0;
        sp8 = 0x97;
        M2C_FIELD(M2C_FIELD(temp_r3_409, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_409, &sp8, 0);
        DialogBox_ReleaseContext(gb.unk320);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk320'
void DialogCallback(DialogBoxContext *arg0, int arg1) {
    s32 spC;
    s32 sp8;
    void *temp_r3_448;

    if ((DialogBoxContext *) gb.unk320 == arg0) {
        switch (arg1) {                             /* irregular */
        case 0:
            temp_r3_448 = gb.unk0->GetProp();
            spC = 0;
            sp8 = 0xAA;
            M2C_FIELD(M2C_FIELD(temp_r3_448, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            DialogBox_ReleaseContext(gb.unk320);
            return;
        case 7:
            gb.unk320 = NULL;
            break;
        }
    }
}
#endif

u8 InGame_CheckControllerRemoved() {
    s32 temp_r3_483;

    temp_r3_483 = 0 - GameVideo_Active();
    return 0 & ~((temp_r3_483 - temp_r3_483) - !M2C_CARRY);
}

void UpdateListenerPos() {
    M2C_STRUCT_COPY(&sndCameraMat, MKView_GetCameraMatrix(), 0x40);
    KDSound_SetListener(&sndCameraMat);
}

#if 0 // DRAFT: undefined identifier 'unk340'
void InGame_UpdateAutoLevelSwitch() {
    Level *temp_r29_807;
    Level *temp_r3_811;
    f32 temp_f1_648;
    f32 temp_f1_799;
    s32 temp_r0_683;
    s32 temp_r0_751;
    s32 temp_r3_620;
    s32 temp_r3_667;
    s32 temp_r3_953;
    s32 temp_r4_544;
    s32 temp_r8_842;
    s32 var_r4_627;
    s32 var_r4_675;
    s32 var_r7_673;
    s32 var_r9_624;
    s8 *temp_r29_951;
    s8 *var_r4_714;
    u32 var_r4_653;
    u8 var_r30_732;
    void *temp_r5_631;
    void *temp_r5_680;
    void *temp_r7_630;
    void *temp_r8_679;
    void *var_r3_547;

    if ((s8) init_940 == 0) {
        autoSwitchState_939 = 0;
        init_940 = 1;
    }
    if ((s32) gb.unk340 != 0) {
        if ((s8) init_945 == 0) {
            temp_r4_544 = gb.unk32C->unk18;
            if ((u32) temp_r4_544 != 0U) {
                var_r3_547 = M2C_FIELD(temp_r4_544, void **, 4);
            } else {
                var_r3_547 = M2C_FIELD(gb.unk32C->unk24, void **, 4);
            }
            pInfo_944 = M2C_FIELD(var_r3_547, Level **, 0x11C);
            init_945 = 1;
        }
        if ((s8) init_948 == 0) {
            pLoadingInfo_947 = NULL;
            init_948 = 1;
        }
        if ((s8) init_951 == 0) {
            pCutsceneChunkInfo_950 = NULL;
            init_951 = 1;
        }
        if ((s8) init_954 == 0) {
            pCutsceneInfo_953 = NULL;
            init_954 = 1;
        }
        if ((s8) init_957 == 0) {
            frameDelayCount_956 = 0;
            init_957 = 1;
        }
        if ((s8) init_960 == 0) {
            ppChunk_959 = 0;
            init_960 = 1;
        }
        if ((s8) init_964 == 0) {
            desiredChunkIndex_963 = 0;
            init_964 = 1;
        }
        switch (autoSwitchState_939) {
        case 0:
            temp_r3_620 = M2C_FIELD(*gMK, s32 (**)(void **), 0x2C)(gMK);
            var_r9_624 = 1;
            var_r4_627 = 4;
loop_24:
            if (var_r9_624 < (s32) gb.unk32C->unk78) {
                temp_r7_630 = *(temp_r3_620 + var_r4_627);
                temp_r5_631 = pDesiredChunks_962 + var_r4_627;
                var_r9_624 += 1;
                var_r4_627 += 4;
                M2C_FIELD(temp_r5_631, s32 *, -4) = (s32) M2C_FIELD(M2C_FIELD(temp_r7_630, void **, 0xC), s32 *, 4);
                goto loop_24;
            }
            autoSwitchState_939 = 1;
            return;
        case 1:
            temp_f1_648 = inGameTime + gUpdateTimeDelta;
            inGameTime = temp_f1_648;
            if (temp_f1_648 > 1.0f) {
                var_r4_653 = 7;
                if ((s32) gb.unk348 != 0) {
                    var_r4_653 = 2;
                }
                autoSwitchState_939 = var_r4_653;
                return;
            }
            break;
        case 2:
            temp_r3_667 = M2C_FIELD(*gMK, s32 (**)(void **), 0x2C)(gMK);
            ppChunk_959 = temp_r3_667;
            var_r7_673 = 0;
            pCutsceneChunkInfo_950 = NULL;
            var_r4_675 = 0;
loop_37:
            if (var_r7_673 < (s32) gb.unk32C->unk78) {
                temp_r8_679 = M2C_FIELD(*(temp_r3_667 + var_r4_675), void **, 0xC);
                temp_r5_680 = M2C_FIELD(temp_r8_679, void **, 4);
                if ((temp_r5_680 != NULL) && ((temp_r0_683 = M2C_FIELD(temp_r8_679, s32 *, 0), ((temp_r0_683 == 1) != 0)) || (temp_r0_683 == 2)) && ((u8) M2C_FIELD(temp_r5_680, u8 *, 0x35) == 0)) {
                    pCutsceneChunkInfo_950 = temp_r5_680;
                } else {
                    var_r7_673 += 1;
                    var_r4_675 += 4;
                    goto loop_37;
                }
            }
            if ((void *) pCutsceneChunkInfo_950 == NULL) {
                autoSwitchState_939 = 5;
                return;
            }
            if ((s32) gb.unk348 != 0) {
                var_r4_714 = M2C_FIELD(pCutsceneChunkInfo_950, s8 **, 0x10);
            } else {
                var_r4_714 = NULL;
            }
            pCutsceneInfo_953 = var_r4_714;
            autoSwitchState_939 = 3;
            gb.unk0->Disable();
            return;
        case 3:
            var_r30_732 = 0;
            if ((((MKVector3 *) gb.unkC->unk78 != NULL) || ((GameVideo *) gb.unkC->unk84 != NULL)) && (gb.unkC->unk24.GetState() != 0)) {
                var_r30_732 = 1;
            }
            if (var_r30_732 == 0) {
                temp_r0_751 = frameDelayCount_956 - 1;
                frameDelayCount_956 = temp_r0_751;
                if (temp_r0_751 <= 0) {
                    if ((s8 *) pCutsceneInfo_953 == NULL) {
                        autoSwitchState_939 = 4;
                        return;
                    }
                    gb.unkC->Play(pCutsceneInfo_953, 0.0f, NULL, 0U);
                    pCutsceneInfo_953 = M2C_FIELD(pCutsceneInfo_953, s8 **, 0x20);
                    frameDelayCount_956 = 0xF;
                    return;
                }
            }
            break;
        case 4:
            if ((void *) pCutsceneChunkInfo_950 != NULL) {
                M2C_FIELD(pCutsceneChunkInfo_950, s8 *, 0x35) = 1;
            }
            autoSwitchState_939 = 2;
            gb.unk0->Enable();
            return;
        case 5:
            autoSwitchState_939 = 6;
            inGameTime = 0.0f;
            return;
        case 6:
            temp_f1_799 = inGameTime + gUpdateTimeDelta;
            inGameTime = temp_f1_799;
            if (temp_f1_799 > 1.0f) {
                autoSwitchState_939 = 7;
                return;
            }
            break;
        case 7:
            temp_r29_807 = pInfo_944;
loop_60:
            temp_r3_811 = pInfo_944->GetNextChunk(M2C_ERROR(/* Read from unset register $r4 */));
            pInfo_944 = temp_r3_811;
            if (temp_r3_811 == NULL) {
                autoSwitchState_939 = 0xA;
            }
            if ((temp_r3_811 != NULL) && (((u8) M2C_FIELD(temp_r3_811->unk4, u8 *, 0x1A) != 0) || ((u8) temp_r3_811->unk34 != 0))) {
                goto loop_60;
            }
            if (temp_r3_811 != NULL) {
                pLoadingInfo_947 = temp_r3_811;
                M2C_FIELD(&gMKDefaults, s8 *, 0x1C) = 0;
                if ((void *) temp_r29_807->unk4 == (void *) temp_r3_811->unk4) {
                    temp_r8_842 = 1 - desiredChunkIndex_963;
                    desiredChunkIndex_963 = temp_r8_842;
                    M2C_FIELD(&pDesiredChunks_962[temp_r8_842], Level **, 4) = temp_r3_811;
                    gb.unk32C->SetDesiredChunks(pDesiredChunks_962, 3);
                    autoSwitchState_939 = 8;
                    return;
                }
                if ((s32) gb.unk340 == 2) {
                    autoSwitchState_939 = 0xA;
                    return;
                }
                gb.unk32C->SetEnvChunk(NULL);
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x44)(gMK, 0);
                M2C_FIELD(pDesiredChunks_962, ChunkInfo **, 0) = M2C_FIELD(pInfo_944->unk4, ChunkInfo **, 0x118);
                pDesiredChunks_962[1] = (ChunkInfo *) pInfo_944;
                gb.unk32C->SetDesiredChunks(pDesiredChunks_962, 2);
                desiredChunkIndex_963 = 0;
                autoSwitchState_939 = 8;
                return;
            }
            break;
        case 8:
            if ((u32) gb.unk32C->unk1C == 0) {
                autoSwitchState_939 = 9;
                return;
            }
            break;
        case 9:
            inGameTime = 0.0f;
            M2C_FIELD(&gMKDefaults, s8 *, 0x1C) = 1;
            gb.unk32C->EnableChunksForLevel((ChunkInfo *) pInfo_944);
            autoSwitchState_939 = 1;
            return;
        case 10:
            System_GetCommandLineParameter("OutputOrder", 0U);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                System_GetCommandLineParameter("OutputOrder", 0U);
                if (stricmp("manual", M2C_ERROR(/* Read from unset register $r3 */), "<p0><colour=0,0,0,1>...</colour>") == 0) {
                    MKArchive_OutputFileOrder();
                }
            }
            File_FileServerOutputFilename"autoswitch";
            temp_r29_951 = Str_Printf("Autoswitch ended", "<p0><colour=0, 0, 0, 1>...</colour>");
            temp_r3_953 = File_Open(M2C_ERROR(/* Read from unset register $r3 */), 2);
            if (temp_r3_953 >= 0) {
                File_Write(temp_r3_953, temp_r29_951, strlen(temp_r29_951));
                File_Close(temp_r3_953);
            }
            bQuit = 1;
            break;
        }
    } else {
    default:
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
void InGame_DrawOverlays() {
    Matrix sp40;
    M2C_UNK sp3C;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    Tools_Ortho sp10;
    u8 var_r31_1002;
    u8 var_r3_988;

    sp10.Tools_Ortho();
    var_r3_988 = 0;
    if (((MKVector3 *) gb.unkC->unk78 != NULL) && ((u8) gb.unkC->unk70 != 0)) {
        var_r3_988 = 1;
    }
    if (var_r3_988 == 0) {
        var_r31_1002 = 0;
        if ((((MKVector3 *) gb.unkC->unk78 != NULL) || ((GameVideo *) gb.unkC->unk84 != NULL)) && (gb.unkC->unk24.GetState() > 0)) {
            var_r31_1002 = 1;
        }
        if (((var_r31_1002 == 0) || ((s32) gb.unkC->unk74 == 1)) && (Credits_Active() == 0)) {
            Hud_Draw();
        }
    }
    Autosave_Draw();
    if (((s8 *) pMessage != NULL) && (msgAlpha > 0.0f) && ((u8) gb.unk32C->unk8 == 0)) {
        M2C_STRUCT_COPY((s32) &sp3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp18 = 320.0f;
        sp1C = 256.0f;
        sp20 = 0.0f;
        sp28 = (f64) sp18;
        sp30 = (f64) sp20;
        sp40.Translate(&sp40, *((MKVector3 *) &sp28));
        gb.unk318->DrawString(pMessage, 544.0f, 435.2f, &sp40, 8, ((s32) (128.0f * msgAlpha) << 0x18) | 0x800000 | 0x8080, 1.0f, 1.0f, NULL, 1U);
    }
    sp10.~Tools_Ortho(-1);
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r3_1120'
void InGame_DrawLevel() {
    CutsceneSystem *temp_r28_1119;
    CutsceneSystem *temp_r28_1139;
    MKVector3 *temp_r3_1120;
    MKVector3 *temp_r3_1143;
    f32 var_f0_1164;
    u8 var_r29_1117;
    u8 var_r29_1144;
    u8 var_r3_1188;

    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *), 0x4C)(M2C_FIELD(&gb, void **, 0x3B8));
    UpdateListenerPos();
    var_r29_1117 = 0;
    temp_r28_1119 = gb.unkC;
    temp_r3_1120 = temp_r28_1119->unk78;
    if (((temp_r3_1120 != NULL) && (((KDSynkerPlayer3 *) temp_r3_1120)->IsPlaying() != 0)) || (((s32) temp_r28_1119->unk74 == 2) && (temp_r28_1119->unk24.GetState() == 2))) {
        var_r29_1117 = 1;
    }
    if ((var_r29_1117 != 0) && (temp_r28_1139 = gb.unkC, (((s32) temp_r28_1139->unk74 == 1) == 0))) {
        temp_r3_1143 = temp_r28_1139->unk78;
        var_r29_1144 = 0;
        if (((temp_r3_1143 != NULL) && (((KDSynkerPlayer3 *) temp_r3_1143)->IsPlaying() != 0)) || (((s32) temp_r28_1139->unk74 == 2) && (temp_r28_1139->unk24.GetState() == 2))) {
            var_r29_1144 = 1;
        }
        if (var_r29_1144 != 0) {
            var_f0_1164 = M2C_FIELD(temp_r28_1139->unk78, f32 *, 0xC0);
        } else {
            var_f0_1164 = 60.0f;
        }
        gb.unk32C->unkC = var_f0_1164;
    } else {
        gb.unk32C->SetProjectionToDefaults();
        gb.unk32C->unkC = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(void *), 0x50)(M2C_FIELD(&gb, void **, 0x3B8));
    }
    var_r3_1188 = 0;
    if (((MKVector3 *) gb.unkC->unk78 != NULL) && ((u8) gb.unkC->unk70 != 0)) {
        var_r3_1188 = 1;
    }
    if (((var_r3_1188 == 0) || ((s32) gb.unkC->unk74 != 0)) && (Credits_Active() == 0)) {
        gb.unk32C->Draw();
    }
    gb.unk32C->DOFApplyEffect();
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *), 0x44)(M2C_FIELD(&gb, void **, 0x3B8));
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_903'
void InGame_Draw() {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    Tools_Ortho spC;
    Tools_Ortho sp8;
    f32 var_f1_1359;
    s32 temp_r4_1349;
    s32 temp_r6_1278;
    u32 temp_r0_1282;
    u32 temp_r6_1281;
    u8 temp_r29_1374;
    u8 var_r31_1312;
    void *var_r4_1352;

    if ((u8) M2C_FIELD(gb.unk32C, u8 *, 0x6C) == 0) {
        if (((u8) gb.unk32C->unk8 != 0) || ((u8) bShowLoading != 0)) {
            spC.Tools_Ortho();
            sp10 = M2C_FIELD(&lit_903, s32 *, 0);
            sp14 = M2C_FIELD(&lit_903, s32 *, 4);
            temp_r6_1278 = (s32) (4.0f * gb.unk30C);
            sp18 = M2C_FIELD(&lit_903, s32 *, 8);
            temp_r6_1281 = (u32) temp_r6_1278 >> 0x1FU;
            temp_r0_1282 = (temp_r6_1278 << 0x1E) - temp_r6_1281;
            sp1C = M2C_FIELD(&lit_903, s32 *, 0xC);
            ErrorMessage_Draw(Str_Printf("%s\n%s", M2C_FIELD(gpTranslation_StringArray, s32 *, 0xE8), (&sp10)[((temp_r0_1282 << 2) | (temp_r0_1282 >> 0x1EU)) + temp_r6_1281], temp_r6_1281, M2C_FIELD(&lit_903, s32 *, 0xC), M2C_FIELD(&lit_903, s32 *, 0), 4.0f));
            spC.~Tools_Ortho(-1);
            return;
        }
        if ((u8) gb.unk395 != 0) {
            sp8.Tools_Ortho();
            M2C_FIELD(&gb, M2C_UNK (**)(GameGlobals *), 0x3A8)(&gb);
            sp8.~Tools_Ortho(-1);
            return;
        }
        var_r31_1312 = 0;
        if ((((MKVector3 *) gb.unkC->unk78 != NULL) || ((GameVideo *) gb.unkC->unk84 != NULL)) && (gb.unkC->unk24.GetState() != 0)) {
            var_r31_1312 = 1;
        }
        if ((var_r31_1312 != 0) && ((s32) gb.unkC->unk74 == 2)) {
            gb.unkC->Draw();
            InGame_DrawOverlays();
            return;
        }
        InGame_DrawLevel();
        gb.unk24.Get();
        ((BoneBlurFXDescriptor *) gb.unk2AC)->DrawInstances();
        gb.unk24.Release();
        temp_r4_1349 = gb.unk32C->unk18;
        if ((u32) temp_r4_1349 != 0U) {
            var_r4_1352 = M2C_FIELD(temp_r4_1349, void **, 4);
        } else {
            var_r4_1352 = M2C_FIELD(gb.unk32C->unk24, void **, 4);
        }
        var_f1_1359 = M2C_FIELD(var_r4_1352, f32 *, 0x24);
        if ((u8) gb.unk380 != 0) {
            var_f1_1359 = gb.unk378;
        }
        MKMat_MK2_ApplyGlow(var_f1_1359, (MKMat_Glow_Viewport) 0);
        gGlowingPropManager.Draw();
        temp_r29_1374 = MKMaterial_EnableFog(0U);
        gb.unk24.Get();
        gb.unk130.Draw();
        gb.unk1C0.Draw();
        gb.unk240.Draw();
        gb.unkB8.Draw();
        gb.unk24.Release();
        gb.unkB8.DrawSpeedEffect();
        gb.unkB8.GetMotionBlurCap();
        MKMaterial_EnableFog(temp_r29_1374);
        MKMaterial_EnableFog(0U);
        InGame_DrawOverlays();
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void InGame_Update() {
    f64 sp10;
    f64 sp8;
    f32 temp_f0_1744;
    f32 temp_f1_1422;
    s32 temp_cr0_eq_1495;
    s32 var_r3_1529;
    s32 var_r6_1430;
    u32 var_r5_1428;
    u8 var_r29_1574;
    u8 var_r29_1613;
    u8 var_r29_1693;
    u8 var_r3_1515;
    u8 var_r3_1603;
    u8 var_r3_1621;
    u8 var_r3_1681;
    u8 var_r6_1617;
    u8 var_r7_1620;
    void *temp_r3_1433;
    void *temp_r4_1672;

    temp_f1_1422 = nextCheck - gUpdateTimeDelta;
    nextCheck = temp_f1_1422;
    M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
    if (temp_f1_1422 == 0.0f) {
        var_r5_1428 = 0U;
        var_r6_1430 = 0;
loop_3:
        if ((s8) M2C_FIELD((&fingerprintData + var_r6_1430), u8 *, 8) != 0) {
            temp_r3_1433 = &fingerprintData + var_r6_1430;
            var_r6_1430 += 1;
            var_r5_1428 += (s8) M2C_FIELD(temp_r3_1433, u8 *, 8);
            goto loop_3;
        }
        if (var_r5_1428 != (u32) M2C_FIELD(&fingerprintData, u32 *, 0x108)) {
            gb.unk32C->SwitchTo(NULL);
        }
        nextCheck = MKRand_Float(&gViewSeed, 300.0f, 900.0f);
    }
    gb.unk35C = 0;
    if ((u8) M2C_FIELD(gb.unk32C, u8 *, 0x6C) != 0) {
        gb.unk32C->Update();
        gb.unkC->Update();
        return;
    }
    if ((u8) gb.unk32C->unk8 != 0) {
        gb.unkC->Update();
        gb.unk30C += gUpdateTimeDelta;
        return;
    }
    Autosave_Update();
    if (InGame_CheckControllerRemoved() == 0) {
        temp_cr0_eq_1495 = (u8) gb.unk395 == 0;
        gb.unk394 = (s8) gb.unk395;
        if (temp_cr0_eq_1495 == 0) {
            M2C_FIELD(&gb, M2C_UNK (**)(), 0x3A4)();
            if ((u8) gb.unk395 != 0) {
                InGame_UpdateAutoLevelSwitch();
                return;
            }
            goto block_27;
        }
        if ((temp_cr0_eq_1495 != 0) && ((u8) gb.unk396 == 0) && (Autosave_IsActive() == 0)) {
            var_r3_1515 = 0;
            if (((u8) M2C_FIELD(gb.unk354, u8 *, 5) != 0) || ((u8) M2C_FIELD(gb.unk354, u8 *, 4) != 0)) {
                var_r3_1515 = 1;
            }
            if (var_r3_1515 != 0) {
                var_r3_1529 = 0;
            } else {
                var_r3_1529 = MKInput_Pressed(3, (MKInputDevices) M2C_FIELD(gb.unk354, s32 *, 0));
            }
            if (((u8) var_r3_1529 != 0) && (gb.unk0->IsDying() == 0)) {
                UIControls_SetDevice((MKInputDevices) M2C_FIELD(gb.unk354, s32 *, 0));
                gb.SetGamePaused(1U, (u8 (*)()) PauseMenu_Update, PauseMenu_Draw, 1U);
                PauseMenu_Reset(NULL);
                return;
            }
            goto block_27;
        }
block_27:
        M2C_FIELD(GameData::gameData, f32 *, 0x1C) = (f32) (M2C_FIELD(GameData::gameData, f32 *, 0x1C) + gUpdateTimeDelta);
        gb.unkC->Update();
        var_r29_1574 = 0;
        if ((((MKVector3 *) gb.unkC->unk78 != NULL) || ((GameVideo *) gb.unkC->unk84 != NULL)) && (gb.unkC->unk24.GetState() != 0)) {
            var_r29_1574 = 1;
        }
        if ((var_r29_1574 != 0) && ((s32) gb.unkC->unk74 == 2)) {
            gb.unk30C += gUpdateTimeDelta;
            return;
        }
        var_r3_1603 = 0;
        if (((MKVector3 *) gb.unkC->unk78 != NULL) && ((u8) gb.unkC->unk70 != 0)) {
            var_r3_1603 = 1;
        }
        var_r29_1613 = 0;
        var_r6_1617 = 0;
        var_r7_1620 = 0;
        var_r3_1621 = 0;
        if ((var_r3_1603 == 0) || ((u8) (gb.unkC->unk74 == 1) != 0)) {
            var_r3_1621 = 1;
        }
        if (var_r3_1621 != 0) {
            var_r7_1620 = 1;
        }
        if ((var_r7_1620 != 0) && ((u8) gb.unk32C->unk8 == 0)) {
            var_r6_1617 = 1;
        }
        if ((var_r6_1617 != 0) && (Credits_Active() == 0)) {
            var_r29_1613 = 1;
        }
        if (var_r29_1613 != 0) {
            gb.unk30C += gUpdateTimeDelta;
            gb.unk32C->Update();
            if (gb.unk0->IsDying() == 0) {
                temp_r4_1672 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
                sp8 = M2C_FIELD(temp_r4_1672, f64 *, 0x30);
                sp10 = M2C_FIELD(temp_r4_1672, f64 *, 0x38);
                Connector_Update(*((MKVector3 *) &sp8));
            }
        }
        var_r3_1681 = 0;
        if (((MKVector3 *) gb.unkC->unk78 != NULL) && ((u8) gb.unkC->unk70 != 0)) {
            var_r3_1681 = 1;
        }
        if (var_r3_1681 == 0) {
            var_r29_1693 = 0;
            if ((((MKVector3 *) gb.unkC->unk78 != NULL) || ((GameVideo *) gb.unkC->unk84 != NULL)) && (gb.unkC->unk24.GetState() > 0)) {
                var_r29_1693 = 1;
            }
            if (((var_r29_1693 == 0) || ((s32) gb.unkC->unk74 == 1)) && (Credits_Active() == 0)) {
                Hud_Update();
            }
        }
        InGame_UpdateAutoLevelSwitch();
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *), 0x40)(M2C_FIELD(&gb, void **, 0x3B8));
        if (((s8 *) pMessage != NULL) && ((u8) gb.unk32C->unk8 == 0)) {
            if (msgTime > 0.0f) {
                msgTime -= gUpdateTimeDelta;
                if (msgAlpha < 1.0f) {
                    temp_f0_1744 = msgAlpha + gUpdateTimeDelta;
                    msgAlpha = temp_f0_1744;
                    if (temp_f0_1744 > 1.0f) {
                        msgAlpha = 1.0f;
                    }
                }
            } else if (msgAlpha > 0.0f) {
                msgAlpha -= gUpdateTimeDelta;
            }
        }
        gb.unk334 = 0;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk320'
void InGame_Deinit() {
    SpyroHud_Deinit();
    if ((DialogBoxContext *) gb.unk320 != NULL) {
        DialogBox_ReleaseContext(gb.unk320);
    }
    KDSound_StopMusic(0.0f);
    gb.unk20->Clear();
    gb.SetGamePaused(0U, (u8 (*)()) PauseMenu_Update, PauseMenu_Draw, 1U);
    gb.unk32C->Deinit();
    gb.ResetInGameData();
    gb.unk30.Reset();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char (*)()' to
void InGame_Init() {
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    MKVector3 *temp_r4_1867;

    MKRumble_Reset();
    gb.SetGamePaused(0U, (u8 (*)()) PauseMenu_Update, PauseMenu_Draw, 1U);
    inGameTime = 0.0f;
    autoLevelCutsceneNr = 0;
    sp1C = 0;
    sp18 = 0x29;
    sp20 = gb.unk330;
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp18, 0, 1, 0, 1, 0x29, 0.0f);
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *), 0x40)(M2C_FIELD(&gb, void **, 0x3B8));
    temp_r4_1867 = M2C_FIELD(gb.unk0->GetProp(), MKVector3 **, 8);
    sp8 = M2C_FIELD(temp_r4_1867, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r4_1867, f64 *, 0x38);
    ((PropGroupVolume *) &sp8)->CullGroups(*temp_r4_1867);
    if ((s32) gb.unk340 != 0) {
        msgTime = 999.0f;
        pMessage = "Autolevelswitch running...";
    }
    Music_Update();
    SpyroHud_Init();
    bShowLoading = 0;
    nextCheck = MKRand_Float(&gViewSeed, 300.0f, 900.0f);
}
#endif

void InGame_cpp::__sinit() {
    f64 temp_f0_1925;
    f64 temp_f1_1948;
    f64 temp_f1_1956;
    f64 temp_f4_1931;
    f64 temp_f4_1947;
    f64 temp_f4_1955;
    f64 temp_f6_1935;
    f64 temp_f9_1927;

    temp_f0_1925 = __frsqrte(2014000.0);
    temp_f9_1927 = __frsqrte(380000.0);
    temp_f4_1931 = temp_f0_1925 * temp_f0_1925;
    temp_f6_1935 = 0.5 * temp_f0_1925;
    M2C_FIELD(&listenerPos, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(&listenerPos, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_f4_1947 = temp_f6_1935 * -((2014000.0 * temp_f4_1931) - 3.0);
    temp_f1_1948 = 0.5 * temp_f9_1927 * -((380000.0 * (temp_f9_1927 * temp_f9_1927)) - 3.0);
    temp_f4_1955 = 0.5 * temp_f4_1947 * -((2014000.0 * (temp_f4_1947 * temp_f4_1947)) - 3.0);
    temp_f1_1956 = 0.5 * temp_f1_1948 * -((380000.0 * (temp_f1_1948 * temp_f1_1948)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1955 * -((2014000.0 * (temp_f4_1955 * temp_f4_1955)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_1956 * -((380000.0 * (temp_f1_1956 * temp_f1_1956)) - 3.0)));
    M2C_STRUCT_COPY(&sndCameraMat, &Matrix::identity, 0x40);
}
