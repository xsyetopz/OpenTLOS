#include "spyro/source/CutsceneSystem.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKStringCache.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BoundingRegion.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/CutsceneObject.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/PolyRegion.h"
#include "spyro/source/PropGroupVolume.h"
#include "spyro/source/SpyroEffects.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIStringTable.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKRumble.h"
#include "common/Source/Str.h"
#include "common/gc/MKView_GC.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/GameConsole.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/Music.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

M2C_UNK free(MKVector3 *);                          /* extern */
s8 *malloc(s32);                                    /* extern */
M2C_UNK strcat(s8 *, M2C_UNK *);                    /* extern */
extern s8 bIgnoreEvent;
extern s8 bShowLoading;
#if 0 // DRAFT: identifier 'gClearColor' redeclared
extern M2C_UNK gClearColor;
#endif
extern M2C_UNK gEventCreationTable;
extern GameStateMachine gGMState;
extern void **gMK;
extern MKHeap gMKDefaults;
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: identifier 'gb' redeclared
extern void **gb;
#endif
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: identifier 'pLoadChunkInfo' redeclared
extern void *pLoadChunkInfo;
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static M2C_UNK lit_752;                                /* unable to generate initializer: unknown type */
static KDStateMachine<CutsceneSystem>::State cutsceneStates; /* unable to generate initializer: confusing struct layout */

void CutsceneSystem::SetCustomSubtitle(const char *arg0, int arg1, bool arg2) {
    f32 var_f0_24;

    if ((arg0 == NULL) && (arg2 != 0)) {
        this->unk9D = arg2;
        return;
    }
    this->unk9D = 0;
    this->unk9C = arg2;
    this->unk80 = arg0;
    if (arg2 != 0) {
        var_f0_24 = 0.0f;
    } else {
        var_f0_24 = 1.0f;
    }
    this->unk90 = var_f0_24;
    this->unk8C = arg1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CutsceneSystem::SetDuckValue(float arg0) {
    f32 var_f1_0;

    var_f1_0 = arg0;
    if (var_f1_0 != 0.0f) {

    } else {
        Level::GetWorldInfo();
        var_f1_0 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x74);
    }
    this->unkA4 = var_f1_0;
}
#endif

#if 0 // DRAFT: pointer/array required
void CutsceneSystem::NotifyProps(bool arg0) {
    u8 sp38;
    s32 sp34;
    s32 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    MKVector3 *temp_r4_82;
    MKVector3 *temp_r4_98;

    if ((arg0 == 0) && ((u8) this->unk89 != 0)) {
        M2C_FIELD(*gb, M2C_UNK (**)(void **), 0x20)(gb);
    }
    if (arg0 != 0) {
        temp_r4_82 = this->unk78;
        sp20 = M2C_FIELD(temp_r4_82, f64 *, 0xB0);
        sp28 = M2C_FIELD(temp_r4_82, f64 *, 0xB8);
        ((PropGroupVolume *) &sp20)->CullGroups(*temp_r4_82);
    } else {
        temp_r4_98 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), MKVector3 **, 8);
        sp10 = M2C_FIELD(temp_r4_98, f64 *, 0x30);
        sp18 = M2C_FIELD(temp_r4_98, f64 *, 0x38);
        ((PropGroupVolume *) &sp10)->CullGroups(*temp_r4_98);
    }
    if (arg0 != 0) {
        spC = 0;
        sp8 = 0x1C;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0x20, 1, 0, 0, 0.0f);
    } else {
        sp34 = 0;
        sp38 = this->unk9F;
        sp30 = 0x1D;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp30, 0x20, 1, 0, 0, 0.0f);
    }
    if (arg0 != 0) {
        this->unk89 = (M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), s32 *, 0x18) & 0x80000000) == 0;
        M2C_FIELD(*gb, M2C_UNK (**)(void **), 0x24)(gb);
    }
}
#endif

void CutsceneSystem::OnStop() {
    s32 spC;
    s32 sp8;
    CutsceneObject *temp_r3_189;
    CutsceneObject *temp_r3_223;
    s32 temp_r0_196;
    void *temp_r31_181;

    temp_r31_181 = this->unk1C;
    this->unk1C = NULL;
    if ((s32) this->unk74 == 0) {
        NotifyProps(0U);
    }
    temp_r3_189 = this->unk68;
    if (temp_r3_189 != NULL) {
        temp_r3_189->StopEvent();
        this->unk68->ReturnToGame();
    }
    temp_r0_196 = this->unk74;
    if (temp_r0_196 != 1) {
        if (temp_r0_196 != 2) {
            Music_UnDuck(1.0f);
            SetDuckValue(0.0f);
        }
        MKRumble_Mute(this->unkA8);
    }
    if (temp_r31_181 != NULL) {
        spC = 0;
        sp8 = 0x20;
        M2C_FIELD(M2C_FIELD(temp_r31_181, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r31_181, &sp8);
    }
    temp_r3_223 = this->unk68;
    if (temp_r3_223 != NULL) {
        temp_r3_223->End();
    }
}

void CutsceneSystem::OnPlay() {
    CutsceneObject *temp_r3_251;

    if ((s32) this->unk74 == 0) {
        this->unk70 = 0;
        NotifyProps(1U);
    }
    temp_r3_251 = this->unk68;
    if (temp_r3_251 != NULL) {
        temp_r3_251->PlayEvent();
    }
    this->unkA8 = MKRumble_IsMuted();
    MKRumble_Mute(1U);
}

#if 0 // DRAFT: pointer/array required
void CutsceneSystem::OnBeginLoad() {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_300;
    void *temp_r3_316;

    if ((s32) this->unk74 != 1) {
        Music_Duck(this->unkA4, 1.0f);
        sp1C = 0;
        sp18 = 0x1B;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp18, 0, 0, 0, 1, 0.0f);
        temp_r3_300 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
        sp14 = 0;
        sp10 = 0xA9;
        M2C_FIELD(M2C_FIELD(temp_r3_300, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        temp_r3_316 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
        spC = 0;
        sp8 = 0xAB;
        M2C_FIELD(M2C_FIELD(temp_r3_316, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void CutsceneSystem::Deactivate() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_353;
    void *temp_r3_379;

    if ((u8) this->unk20 != 0) {
        if ((s32) this->unk74 != 1) {
            temp_r3_353 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
            sp14 = 0;
            sp10 = 0xAA;
            M2C_FIELD(M2C_FIELD(temp_r3_353, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        }
        if ((EventCamera_GetCurrent() != NULL) && ((u8) this->unkA9 != 0)) {
            this->unkA9 = 0;
        }
        temp_r3_379 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
        spC = 0;
        sp8 = 0xAC;
        M2C_FIELD(M2C_FIELD(temp_r3_379, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        this->unk68 = NULL;
        this->unk20 = 0;
        this->unk9E = 0;
        this->unk70 = 0;
        this->unk1C = NULL;
        this->unkA0 = NULL;
    }
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match
s32 CutsceneSystem::Activate(const char *arg0, bool arg1) {
    s8 sp8;
    CutsceneObject *temp_r3_458;
    CutsceneObject *temp_r3_477;

    this->unk74 = 0;
    this->unk88 = 1;
    strcpy(&this->unk48, arg0);
    this->unk70 = arg1 == 0;
    strcpy(&sp8, &this->unk48);
    strcat(&sp8, ".bni");
    if (MKArchive_Exists(&sp8, NULL) == 0) {
        if ((s32) M2C_FIELD(&gb, s32 *, 0x348) != 0) {
            this->unk24.SetState(this, 3, 0U);
            goto block_8;
        }
        Abort(1U);
        return 0;
    }
    this->unk24.SetState(this, 1, 0U);
    temp_r3_458 = this->unk68;
    if ((temp_r3_458 != NULL) && ((u8) temp_r3_458->unk62 != 0) && ((s32) *gGMState.GetCurrState() != 6)) {
        this->unk70 = 1;
        LoadLevel_Activate(NULL);
        LoadLevel_Deactivate(0U);
    }
block_8:
    temp_r3_477 = this->unk68;
    if (temp_r3_477 != NULL) {
        this->unk88 = temp_r3_477->Skippable();
        this->unk68->Begin();
    }
    this->unk20 = 1;
    return 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void CutsceneSystem::Abort(bool arg0) {
    MKHeap *temp_r3_514;
    MKVector3 *temp_r3_535;

    if (arg0 != 0) {
        this->unk6C = NULL;
    }
    M2C_FIELD(&gb, s8 *, 0x396) = 0;
    temp_r3_514 = this->unk24.GetState();
    switch (temp_r3_514) {                          /* irregular */
    case 1:
        OnPlay();
        OnStop();
        /* fallthrough */
    case 2:
        bIgnoreEvent = 1;
        temp_r3_535 = this->unk78;
        if ((temp_r3_535 != NULL) && ((s32) this->unk74 != 2)) {
            ((KDSynkerPlayer3 *) temp_r3_535)->SkipToEnd(1U);
        }
        MKRumble_Reset();
        bIgnoreEvent = 0;
        return;
    case 3:
        this->unk24.SetState(this, 4, 0U);
        /* fallthrough */
    case 4:
    case 0:
        return;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void CutsceneSystem::PlayIntro(CutsceneObject &arg0, float arg1) {
    CutsceneObject *temp_r3_609;
    s32 temp_r30_615;
    s32 temp_r5_613;

    if (((u8) M2C_FIELD(&gb, u8 *, 0x334) == 0) || ((void *) pLoadChunkInfo == (u32) M2C_FIELD(M2C_FIELD(pLoadChunkInfo, void **, 4), u32 *, 0x114))) {
        this->unk68 = &arg0;
        PhrasePlayer_StopAnyEvent();
        KDSound_SoundDucking_Deinit();
        if ((u8) this->unk68->unk59 != 0) {
            M2C_FIELD(&gb, s8 *, 0x396) = 1;
            ((GameGlobals::Fade *) (&gb + 0x30))->Reset();
            Music_Clear();
            if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
                ((SpyroEffects *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), SpyroEffects *(**)(), 0x3C)()))->ResetFury();
            }
            temp_r3_609 = this->unk68;
            temp_r5_613 = 0 - temp_r3_609->unk63;
            temp_r30_615 = 2 & ((temp_r5_613 - temp_r5_613) - !M2C_CARRY);
            temp_r3_609->GetFileName(NULL);
            this->unk84 = GameVideo_Create(M2C_ERROR(/* Read from unset register $r3 */), temp_r30_615 | 1, -1);
            if ((GameVideo *) this->unk84 != NULL) {
                this->unk88 = this->unk68->Skippable();
                this->unk74 = 2;
                this->unk24.SetState(this, 2, 0U);
            }
        } else {
            SetDuckValue(arg1);
            Music_Duck(this->unkA4, 0.0f);
            this->unk68->GetFileName(NULL);
            Activate(M2C_ERROR(/* Read from unset register $r3 */), 0U);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GameGlobals *' to
s32 CutsceneSystem::Play(CutsceneObject &arg0, float arg1) {
    CutsceneObject *temp_r3_788;
    MKVector3 *temp_r3_726;
    s32 temp_r29_794;
    s32 temp_r5_792;
    u8 var_r29_704;
    u8 var_r29_727;

    if ((M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **, void ***), 0x4C)(M2C_FIELD(&gb, void ***, 0), &gb) != 0) && ((M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) != 0) || (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x60)(M2C_FIELD(&gb, void ***, 0)) != 0))) {
        arg0.ReturnToGame();
        return 0;
    }
    var_r29_704 = 0;
    if ((((MKVector3 *) this->unk78 != NULL) || ((GameVideo *) this->unk84 != NULL)) && (this->unk24.GetState() != NULL)) {
        var_r29_704 = 1;
    }
    if ((var_r29_704 != 0) || ((u8) this->unk20 != 0)) {
        Abort(0U);
        temp_r3_726 = this->unk78;
        var_r29_727 = 0;
        if (((temp_r3_726 != NULL) && (((KDSynkerPlayer3 *) temp_r3_726)->IsPlaying() != 0)) || (((s32) this->unk74 == 2) && (this->unk24.GetState() == (MKHeap *)2))) {
            var_r29_727 = 1;
        }
        if (var_r29_727 != 0) {
            this->unk70 = this->unk74 != 1;
        }
        this->unk6C = &arg0;
        return 1;
    }
    this->unk68 = &arg0;
    PhrasePlayer_StopAnyEvent();
    KDSound_SoundDucking_Deinit();
    if ((u8) this->unk68->unk59 != 0) {
        M2C_FIELD(&gb, s8 *, 0x396) = 1;
        Music_Clear();
        if (((void **) M2C_FIELD(&gb, void ***, 0) != NULL) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u32 (**)(), 0x3C)() != 0U)) {
            ((SpyroEffects *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), SpyroEffects *(**)(void **), 0x3C)(M2C_FIELD(&gb, void ***, 0))))->ResetFury();
        }
        temp_r3_788 = this->unk68;
        temp_r5_792 = 0 - temp_r3_788->unk63;
        temp_r29_794 = 2 & ((temp_r5_792 - temp_r5_792) - !M2C_CARRY);
        temp_r3_788->GetFileName(NULL);
        this->unk84 = GameVideo_Create(M2C_ERROR(/* Read from unset register $r3 */), temp_r29_794 | 1, -1);
        if ((GameVideo *) this->unk84 != NULL) {
            this->unk88 = this->unk68->Skippable();
            this->unk74 = 2;
            this->unk24.SetState(this, 2, 0U);
        }
        return this->unk84 != NULL;
    }
    SetDuckValue(arg1);
    this->unk68->GetFileName(NULL);
    return Activate(M2C_ERROR(/* Read from unset register $r3 */), 1U);
}
#endif

#if 0 // DRAFT: identifier 'arg3' redeclared
s32 CutsceneSystem::Play(const char *arg0, float arg1, void (*arg3)(const char *, MKModel **, MKAnimScript **), bool arg3) {
    u8 temp_r28_859;
    u8 temp_r29_867;
    u8 temp_r3_873;

    temp_r28_859 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **, void ***), 0x4C)(M2C_FIELD(&gb, void ***, 0), &gb);
    temp_r29_867 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **, void ***), 0x54)(M2C_FIELD(&gb, void ***, 0), &gb);
    temp_r3_873 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **, void ***), 0x60)(M2C_FIELD(&gb, void ***, 0), &gb);
    if (((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) && (temp_r28_859 != 0) && ((temp_r29_867 != 0) || (temp_r3_873 != 0))) {
        return 0;
    }
    this->unkA0 = arg2;
    PhrasePlayer_StopAnyEvent();
    KDSound_SoundDucking_Deinit();
    if (arg3 != 0) {
        M2C_FIELD(&gb, s8 *, 0x396) = 1;
        KDSound_StopAll();
        Music_Clear();
        if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
            ((SpyroEffects *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), SpyroEffects *(**)(), 0x3C)()))->ResetFury();
        }
        this->unk84 = GameVideo_Create(arg0, 1, -1);
        if ((GameVideo *) this->unk84 != NULL) {
            this->unk88 = 1;
            this->unk74 = 2;
            this->unk24.SetState(this, 2, 0U);
        }
        return this->unk84 != NULL;
    }
    SetDuckValue(arg1);
    return Activate(arg0, 1U);
}
#endif

#if 0 // DRAFT: illegal type
void CutsceneSystem::DrawSubtitles() {
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKHeap *temp_ret_1043;
    MKVector3 *temp_r3_991;
    f32 temp_f1_1084;
    s32 var_r30_1063;
    s8 *temp_r4_1081;
    s8 *temp_r4_1172;

    sp30.SetIdentity();
    sp30.unk30 = 320.0f;
    sp30.unk34 = 256.0f;
    sp30.unk38 = 0.0f;
    sp30.unk3C = 1.0f;
    if (this->unk10 > 0.0f) {
        ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(*(gpTranslation_StringArray + (this->unk4 * 4)), 544.0f, 435.2f, &sp30, 8, 1U, 1.0f, 1.0f, NULL, 1U);
    }
    temp_r3_991 = this->unk78;
    if ((temp_r3_991 != NULL) && (((KDSynkerPlayer3 *) temp_r3_991)->IsPlaying() != 0) && ((u8) M2C_FIELD(this->unk78, u8 *, 0x240) != 0)) {
        ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(M2C_FIELD(gpTranslation_StringArray, s8 **, 0xE8), 544.0f, 435.2f, &sp30, 5, 0x80808080U, 1.0f, 1.0f, NULL, 1U);
    }
    ((GameData *) GameData::gameData)->GetGameSettings();
    if (((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x10) == 0) || ((s32) this->unk74 == 1)) {
        if ((s8 *) this->unk80 != NULL) {
            if ((s32) this->unk8C != 5) {
                return;
            }
            goto block_11;
        }
    } else {
block_11:
        *this->unk7C = 0;
        if ((MKVector3 *) this->unk78 != NULL) {
            temp_ret_1043 = this->unk24.GetState();
            if (temp_ret_1043 == (MKHeap *)3) {
                ErrorMessage_Draw(Str_Printf("Cutscene %s not found. Press <font=font_buttons:0>!</font> to continue.", &this->unk48, M2C_BITWISE(f32, temp_ret_1043)));
            } else if ((((KDSynkerPlayer3 *) this->unk78)->IsPlaying() != 0) && ((u8) M2C_FIELD(this->unk78, u8 *, 0x240) == 0)) {
                var_r30_1063 = 0;
loop_20:
                if (var_r30_1063 < ((KDSynkerPlayer3 *) this->unk78)->GetSubTitleCount()) {
                    if (((KDSynkerPlayer3 *) this->unk78)->GetSubTitle(var_r30_1063) != 0) {
                        strcat(this->unk7C);
                    }
                    var_r30_1063 += 1;
                    goto loop_20;
                }
            }
        }
        temp_r4_1081 = this->unk80;
        if (temp_r4_1081 != NULL) {
            temp_f1_1084 = this->unk90;
            if (temp_f1_1084 > 0.0f) {
                sp1C = temp_f1_1084;
                sp18 = 1.0f;
                sp10 = 1.0f;
                sp14 = 1.0f;
                sp28 = (f64) sp18;
                sp20 = (f64) sp10;
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(temp_r4_1081, 544.0f, 435.2f, &sp30, this->unk8C, (s32) (128.0f * (f32) sp20) | (((s32) (128.0f * (*(f32 *) ((u8 *) &sp20 + 0x4))) << 8) | (((s32) (128.0f * (*(f32 *) ((u8 *) &sp28 + 0x4))) << 0x18) | ((s32) (128.0f * (f32) sp28) << 0x10))), 1.15f, 1.15f, NULL, 1U);
            }
            if ((u8) this->unk9C != 0) {
                this->unk90 += gUpdateTimeDelta;
                if (this->unk90 >= 1.0f) {
                    this->unk90 = 1.0f;
                    this->unk9C = 0;
                }
            } else if ((u8) this->unk9D != 0) {
                this->unk90 -= gUpdateTimeDelta;
                if (this->unk90 <= 0.0f) {
                    this->unk90 = 0.0f;
                    this->unk9D = 0;
                    this->unk80 = NULL;
                }
            }
        } else {
            temp_r4_1172 = this->unk7C;
            if ((s8) (u8) *temp_r4_1172 != 0) {
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(temp_r4_1172, 544.0f, 435.2f, &sp30, 9, 0x80808080U, 1.15f, 1.15f, NULL, 1U);
            }
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void CutsceneSystem::Draw() {
    Tools_Ortho sp8;
    MKVector3 *temp_r3_1219;

    if ((s32) this->unk74 == 2) {
        sp8.Tools_Ortho();
        GameVideo_Draw(this->unk84);
        sp8.~Tools_Ortho(-1);
        return;
    }
    temp_r3_1219 = this->unk78;
    if ((temp_r3_1219 == NULL) || (((KDSynkerPlayer3 *) temp_r3_1219)->IsPlaying() == 0)) {
        if ((this->unk24.GetState() == (MKHeap *)4) || ((u8) this->unkA9 != 0)) {
            MKView_Clear(3, this->unk38, 0.0f, 0U);
        }
    } else {
        ((KDSynkerPlayer3 *) this->unk78)->Draw();
    }
}
#endif

void CutsceneSystem::Location::SetTextID(int arg1) {
    M2C_FIELD(this, s32 *, 8) = arg1;
    if ((s32) M2C_FIELD(this, s32 *, 0) != 0) {
        M2C_FIELD(this, f32 *, 0x14) = 0.0f;
        M2C_FIELD(this, f32 *, 0xC) = 0.0f;
        M2C_FIELD(this, s32 *, 0) = 1;
    }
}

void CutsceneSystem::Location::Update() {
    f32 temp_f0_1299;
    f32 temp_f1_1298;
    f32 temp_f1_1306;
    f32 temp_f1_1321;
    s32 temp_r0_1274;
    s32 temp_r0_1286;
    u8 var_r31_1339;
    void *temp_r3_1338;

    temp_r0_1274 = M2C_FIELD(this, s32 *, 0);
    switch (temp_r0_1274) {                         /* irregular */
    case 0:
        temp_r0_1286 = M2C_FIELD(this, s32 *, 8);
        if (temp_r0_1286 > 0) {
            M2C_FIELD(this, s32 *, 4) = temp_r0_1286;
            M2C_FIELD(this, s32 *, 8) = 0;
            M2C_FIELD(this, s32 *, 0) = 1;
            M2C_FIELD(this, f32 *, 0x14) = 1.0f;
            return;
        }
        return;
    case 1:
        temp_f1_1298 = M2C_FIELD(this, f32 *, 0x10);
        temp_f0_1299 = M2C_FIELD(this, f32 *, 0x14);
        if (temp_f1_1298 < temp_f0_1299) {
            M2C_FIELD(this, f32 *, 0x10) = (f32) (temp_f1_1298 + gUpdateTimeDelta);
            temp_f1_1306 = M2C_FIELD(this, f32 *, 0x14);
            if (M2C_FIELD(this, f32 *, 0x10) > temp_f1_1306) {
                M2C_FIELD(this, f32 *, 0x10) = temp_f1_1306;
                M2C_FIELD(this, s32 *, 0) = 2;
                M2C_FIELD(this, f32 *, 0xC) = 3.0f;
                return;
            }
        } else if (temp_f1_1298 > temp_f0_1299) {
            M2C_FIELD(this, f32 *, 0x10) = (f32) (temp_f1_1298 - gUpdateTimeDelta);
            temp_f1_1321 = M2C_FIELD(this, f32 *, 0x14);
            if (M2C_FIELD(this, f32 *, 0x10) < temp_f1_1321) {
                M2C_FIELD(this, f32 *, 0x10) = temp_f1_1321;
                M2C_FIELD(this, s32 *, 0) = 0;
                return;
            }
        }
        break;
    case 2:
        M2C_FIELD(this, f32 *, 0xC) = (f32) (M2C_FIELD(this, f32 *, 0xC) - gUpdateTimeDelta);
        if (!(M2C_FIELD(this, f32 *, 0xC) <= 0.0f)) {
            temp_r3_1338 = M2C_FIELD(this, void **, 0x18);
            var_r31_1339 = 0;
            if ((((u32) M2C_FIELD(temp_r3_1338, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(temp_r3_1338, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r3_1338) + 0x24))->GetState() != NULL)) {
                var_r31_1339 = 1;
            }
            if (var_r31_1339 != 0) {
                goto block_20;
            }
        } else {
block_20:
            M2C_FIELD(this, f32 *, 0xC) = 0.0f;
            M2C_FIELD(this, s32 *, 0) = 1;
            M2C_FIELD(this, f32 *, 0x14) = 0.0f;
        }
        break;
    }
}

void CutsceneSystem::Location::Deinit() {

}

void CutsceneSystem::Location::Init(CutsceneSystem *arg1) {
    M2C_FIELD(this, s32 *, 0) = 0;
    M2C_FIELD(this, f32 *, 0xC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x10) = 0.0f;
    M2C_FIELD(this, f32 *, 0x14) = 0.0f;
    M2C_FIELD(this, s32 *, 4) = 0;
    M2C_FIELD(this, s32 *, 8) = 0;
    M2C_FIELD(this, CutsceneSystem **, 0x18) = arg1;
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void CutsceneSystem::UnloadingDeinit() {
    MKVector3 *temp_r3_1401;
    MKVector3 *temp_r3_1407;

    if ((s32) this->unk74 != 2) {
        temp_r3_1401 = this->unk78;
        if ((temp_r3_1401 != NULL) && (((KDSynkerPlayer3 *) temp_r3_1401)->IsActive() != 0)) {
            temp_r3_1407 = this->unk78;
            M2C_FIELD(temp_r3_1407->unk0, M2C_UNK (**)(MKVector3 *), 0xC)(temp_r3_1407);
        }
        Deactivate();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'GameGlobals' to
void CutsceneSystem::UnloadingUpdate() {
    CutsceneObject *temp_r0_1462;
    CutsceneObject *temp_r3_1482;
    s32 temp_r30_1488;
    s32 temp_r3_1446;
    s32 temp_r5_1486;
    u8 temp_r30_1460;

    this->unk98 = this->unk98 + 1;
    if ((((s32) this->unk74 != 2) && ((((KDSynkerPlayer3 *) this->unk78)->IsActive() == 0) || (((KDSynkerPlayer3 *) this->unk78)->IsUnloaded() != 0))) || ((temp_r3_1446 = this->unk74, ((temp_r3_1446 == 2) != 0)) && ((s32) this->unk98 >= 5))) {
        temp_r30_1460 = this->unk74 == 1;
        this->unk24.SetState(this, 0, 0U);
        temp_r0_1462 = this->unk6C;
        if (temp_r0_1462 != NULL) {
            this->unk68 = temp_r0_1462;
            if ((u8) this->unk68->unk59 != 0) {
                Music_Clear();
                if ((void **) gb != NULL) {
                    ((SpyroEffects *) (M2C_FIELD(*gb, SpyroEffects *(**)(), 0x3C)()))->ResetFury();
                }
                temp_r3_1482 = this->unk68;
                temp_r5_1486 = 0 - temp_r3_1482->unk63;
                temp_r30_1488 = 2 & ((temp_r5_1486 - temp_r5_1486) - !M2C_CARRY);
                temp_r3_1482->GetFileName(NULL);
                this->unk84 = GameVideo_Create(M2C_ERROR(/* Read from unset register $r3 */), temp_r30_1488 | 1, -1);
                if ((GameVideo *) this->unk84 != NULL) {
                    this->unk88 = this->unk68->Skippable();
                    this->unk74 = 2;
                    this->unk24.SetState(this, 2, 0U);
                }
            } else {
                this->unk6C->GetFileName(NULL);
                Activate(M2C_ERROR(/* Read from unset register $r3 */), temp_r30_1460);
            }
            this->unk6C = NULL;
            this->unk70 = 0;
        }
    } else if (temp_r3_1446 != 2) {
        ((KDSynkerPlayer3 *) this->unk78)->Update();
    }
}
#endif

void CutsceneSystem::UnloadingInit() {
    MKVector3 *temp_r3_1553;

    this->unk98 = 0;
    if ((s32) this->unk74 == 2) {
        GameVideo_Destroy(this->unk84);
        this->unk84 = NULL;
        return;
    }
    temp_r3_1553 = this->unk78;
    if ((temp_r3_1553 != NULL) && (((KDSynkerPlayer3 *) temp_r3_1553)->IsActive() != 0)) {
        ((KDSynkerPlayer3 *) this->unk78)->Unload();
    }
}

void CutsceneSystem::MissingCutsceneDeinit() {
    OnStop();
    Deactivate();
}

void CutsceneSystem::MissingCutsceneUpdate() {
    s32 var_r3_1610;
    u8 var_r3_1597;

    var_r3_1597 = 0;
    if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
        var_r3_1597 = 1;
    }
    if (var_r3_1597 != 0) {
        var_r3_1610 = 0;
    } else {
        var_r3_1610 = MKInput_Pressed(0xA, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
    }
    if ((u8) var_r3_1610 != 0) {
        this->unk24.SetState(this, 0, 0U);
    }
}

void CutsceneSystem::MissingCutsceneInit() {
    this->unk70 = 1;
    OnBeginLoad();
    OnPlay();
    this->unk9E = 1;
}

void CutsceneSystem::PlayCutsceneDeinit() {
    s8 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    CutsceneObject *temp_r3_1688;
    s32 temp_cr0_eq_1689;
    s32 temp_r0_1662;

    temp_r0_1662 = this->unk74;
    if (temp_r0_1662 == 0) {
        sp2C = 0;
        sp28 = 0x403;
        sp30 = 1;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp28, 0x403);
    } else if (temp_r0_1662 == 2) {
        M2C_FIELD(&gb, s8 *, 0x396) = 0;
    }
    temp_r3_1688 = this->unk68;
    temp_cr0_eq_1689 = temp_r3_1688 == NULL;
    if ((temp_cr0_eq_1689 != 0) || ((temp_cr0_eq_1689 == 0) && ((u8) temp_r3_1688->unk5C == 0))) {
        sp8 = 0.0f;
        spC = 0.0f;
        sp10 = 0.0f;
        sp14 = 0.0f;
        M2C_FIELD(&gClearColor, f64 *, 0) = (f64) sp8;
        M2C_FIELD(&gClearColor, f64 *, 8) = (f64) sp10;
        M2C_FIELD(this, f64 *, 0x38) = (f64) sp8;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        M2C_FIELD(this, f64 *, 0x40) = (f64) sp10;
    }
    OnStop();
}

void CutsceneSystem::PlayCutsceneUpdate() {
    f64 sp80;
    f64 sp78;
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
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    CutsceneObject *temp_r3_1859;
    CutsceneObject *temp_r3_1906;
    CutsceneObject *temp_r4_1814;
    CutsceneObject *temp_r4_1833;
    CutsceneObject *temp_r4_1868;
    CutsceneObject *temp_r4_1915;
    MKVector3 *temp_r4_1953;
    f64 temp_f0_1834;
    f64 temp_f0_1869;
    f64 temp_f0_1916;
    f64 temp_f2_1835;
    f64 temp_f2_1870;
    f64 temp_f2_1917;
    s32 temp_r3_1782;
    s32 var_r3_1744;
    u8 var_r30_1729;
    u8 var_r3_1731;

    var_r30_1729 = 0;
    var_r3_1731 = 0;
    if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
        var_r3_1731 = 1;
    }
    if (var_r3_1731 != 0) {
        var_r3_1744 = 0;
    } else {
        var_r3_1744 = MKInput_Pressed(0xA, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
    }
    if (((u8) var_r3_1744 != 0) && ((u8) this->unk88 != 0)) {
        var_r30_1729 = 1;
    }
    this->unk9F = var_r30_1729;
    if ((u8) this->unk9F != 0) {
        if ((s32) this->unk74 == 2) {
            if (GameVideo_GetElapsedTime(this->unk84) < 3.0f) {
                this->unk9F = 0;
            }
        } else if (M2C_FIELD(this->unk78, f32 *, 0x244) < 3.0f) {
            this->unk9F = 0;
        }
    }
    temp_r3_1782 = this->unk74;
    if (((temp_r3_1782 != 1) && ((u8) this->unk9F != 0)) || ((temp_r3_1782 != 2) && (((KDSynkerPlayer3 *) this->unk78)->IsAtEnd() != 0))) {
        bIgnoreEvent = 1;
        if ((s32) this->unk74 != 2) {
            ((KDSynkerPlayer3 *) this->unk78)->SkipToEnd(1U);
        }
        Console_PurgeDelayedCmds();
        MKRumble_Reset();
        bIgnoreEvent = 0;
        this->unk24.SetState(this, 4, 0U);
        temp_r4_1814 = this->unk68;
        if ((temp_r4_1814 != NULL) && (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) == 0) || ((u8) temp_r4_1814->unk5D != 0))) {
            this->unkA9 = temp_r4_1814->unk5C;
            this->unkAA = this->unk68->unk5D;
            temp_r4_1833 = this->unk68;
            temp_f0_1834 = temp_r4_1833->unk0;
            temp_f2_1835 = temp_r4_1833->unk8;
            sp78 = temp_f0_1834;
            M2C_FIELD(this, f64 *, 0x38) = temp_f0_1834;
            M2C_FIELD(this, f64 *, 0x40) = temp_f2_1835;
            sp80 = temp_f2_1835;
            M2C_FIELD(&gClearColor, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x38);
            M2C_FIELD(&gClearColor, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x40);
        }
    } else if ((s32) this->unk74 == 2) {
        if (GameVideo_Update(this->unk84) == 0) {
            MKRumble_Reset();
            this->unk24.SetState(this, 4, 0U);
            temp_r3_1859 = this->unk68;
            if (temp_r3_1859 != NULL) {
                this->unkA9 = temp_r3_1859->unk5C;
                this->unkAA = this->unk68->unk5D;
                temp_r4_1868 = this->unk68;
                temp_f0_1869 = temp_r4_1868->unk0;
                temp_f2_1870 = temp_r4_1868->unk8;
                sp68 = temp_f0_1869;
                M2C_FIELD(this, f64 *, 0x38) = temp_f0_1869;
                M2C_FIELD(this, f64 *, 0x40) = temp_f2_1870;
                sp70 = temp_f2_1870;
                M2C_FIELD(&gClearColor, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x38);
                M2C_FIELD(&gClearColor, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x40);
            }
        } else if ((u8) this->unkA9 != 0) {
            this->unkA9 = 0;
            sp18 = 0.0f;
            sp1C = 0.0f;
            this->unkAA = 0;
            sp20 = 0.0f;
            sp24 = 0.0f;
            M2C_FIELD(this, f64 *, 0x38) = (f64) sp18;
            sp58 = (f64) sp18;
            sp60 = (f64) sp20;
            M2C_FIELD(this, f64 *, 0x40) = (f64) sp20;
        }
    } else {
        ((KDSynkerPlayer3 *) this->unk78)->Update();
        if ((((KDSynkerPlayer3 *) this->unk78)->IsAtEnd() != 0) && (temp_r3_1906 = this->unk68, ((temp_r3_1906 == NULL) == 0))) {
            this->unkA9 = temp_r3_1906->unk5C;
            this->unkAA = this->unk68->unk5D;
            temp_r4_1915 = this->unk68;
            temp_f0_1916 = temp_r4_1915->unk0;
            temp_f2_1917 = temp_r4_1915->unk8;
            sp48 = temp_f0_1916;
            M2C_FIELD(this, f64 *, 0x38) = temp_f0_1916;
            M2C_FIELD(this, f64 *, 0x40) = temp_f2_1917;
            sp50 = temp_f2_1917;
            M2C_FIELD(&gClearColor, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x38);
            M2C_FIELD(&gClearColor, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x40);
        } else if ((u8) this->unkA9 != 0) {
            this->unkA9 = 0;
            sp8 = 0.0f;
            spC = 0.0f;
            this->unkAA = 0;
            sp10 = 0.0f;
            sp14 = 0.0f;
            M2C_FIELD(this, f64 *, 0x38) = (f64) sp8;
            sp38 = (f64) sp8;
            sp40 = (f64) sp10;
            M2C_FIELD(this, f64 *, 0x40) = (f64) sp10;
        }
        if ((((KDSynkerPlayer3 *) this->unk78)->IsPlaying() != 0) && ((s32) this->unk74 == 0)) {
            temp_r4_1953 = this->unk78;
            sp28 = M2C_FIELD(temp_r4_1953, f64 *, 0xB0);
            sp30 = M2C_FIELD(temp_r4_1953, f64 *, 0xB8);
            ((PropGroupVolume *) &sp28)->CullGroups(*temp_r4_1953);
        }
    }
}

void CutsceneSystem::PlayCutsceneInit() {
    s32 spC;
    s32 sp8;
    CutsceneObject *temp_r3_1979;
    MKVector3 *temp_r3_2015;

    if ((s32) this->unk74 == 2) {
        temp_r3_1979 = this->unk68;
        if (temp_r3_1979 != NULL) {
            temp_r3_1979->Begin();
            M2C_FIELD(&gb, s8 *, 0x396) = 1;
        }
    }
    this->unk9F = 0;
    OnPlay();
    ((GameGlobals::Fade *) (&gb + 0x30))->Reset();
    if ((s32) this->unk74 == 0) {
        spC = 0;
        sp8 = 0x402;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8);
    }
    if ((s32) this->unk74 != 2) {
        temp_r3_2015 = this->unk78;
        ((KDSynkerPlayer3 *) temp_r3_2015)->Play(M2C_FIELD(temp_r3_2015, s32 *, 0xE8) != 0);
        if ((s32) M2C_FIELD(&gb, s32 *, 0x344) != 0) {
            ((KDSynkerPlayer3 *) this->unk78)->SetPlaySpeed(4.0f);
        }
    }
    bShowLoading = 0;
}

void CutsceneSystem::LoadingDeinit() {
    M2C_FIELD(&gb, s8 *, 0x396) = 0;
}

void CutsceneSystem::LoadingUpdate() {
    ((KDSynkerPlayer3 *) this->unk78)->Update();
    if (((KDSynkerPlayer3 *) this->unk78)->IsLoading() == 0) {
        if (((KDSynkerPlayer3 *) this->unk78)->IsReadyToPlay() == 0) {
            return;
        }
        if (((s32) M2C_FIELD(&gb, s32 *, 0x50) != 2) && ((u8) M2C_FIELD(&gb, u8 *, 0x381) == 0)) {
            if (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) == 0) {
                this->unk24.SetState(this, 2, 0U);
                return;
            }
            Abort(1U);
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void CutsceneSystem::LoadingInit() {
    MKVector3 *temp_r3_2115;
    s32 var_r0_2136;

    M2C_FIELD(&gb, s8 *, 0x396) = 1;
    OnBeginLoad();
    ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->ActivateTempMemOverride();
    temp_r3_2115 = this->unk78;
    ((MKHeap *) (M2C_FIELD(temp_r3_2115->unk0, MKHeap *(**)(MKVector3 *, s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 8)(temp_r3_2115, &this->unk48, 0, 0, 0)))->DeactivateTempMemOverride();
    M2C_FIELD(this->unk78, void (**)(s8 *, MKModel **, MKAnimScript **), 0x108) = (void (*)(s8 *, MKModel **, MKAnimScript **)) this->unkA0;
    M2C_FIELD(this->unk78, s32 *, 0x238) = (s32) M2C_FIELD(&gb, s32 *, 0x354);
    if ((s32) this->unk74 == 0) {
        var_r0_2136 = M2C_FIELD(&gb, s32 *, 0x3B8);
    } else {
        var_r0_2136 = 0;
    }
    *KDSynkerPlayer3::pCameraProp = var_r0_2136;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void CutsceneSystem::Update() {
    MKHeap *temp_r3_2159;
    u8 var_r31_2157;

    var_r31_2157 = 0;
    temp_r3_2159 = this->unk24.GetState();
    if (temp_r3_2159 > 0) {
        var_r31_2157 = 1;
        temp_r3_2159->ActivateTempMemOverride();
    }
    if ((MKVector3 *) this->unk78 != NULL) {
        this->unk24.Update(this, 0);
    }
    if (var_r31_2157 != 0) {
        ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->DeactivateTempMemOverride();
    }
    CutsceneSystem::Location::Update();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void CutsceneSystem::Deinit() {
    MKHeap *temp_r3_2237;
    MKVector3 *temp_r31_2234;
    MKVector3 *temp_r3_2226;
    s32 var_r3_2200;

    Deactivate();
    M2C_FIELD(&gb, s8 *, 0x396) = 0;
    var_r3_2200 = ((KDSynkerPlayer3 *) this->unk78)->IsActive();
    if ((u8) var_r3_2200 != 0) {
        if (((KDSynkerPlayer3 *) this->unk78)->IsUnloading() == 0) {
            bIgnoreEvent = 1;
            ((KDSynkerPlayer3 *) this->unk78)->SkipToEnd(1U);
            ((KDSynkerPlayer3 *) this->unk78)->Unload();
            MKRumble_Reset();
            bIgnoreEvent = 0;
        }
loop_4:
        if (((KDSynkerPlayer3 *) this->unk78)->IsUnloading() != 0) {
            ((KDSynkerPlayer3 *) this->unk78)->Update();
            goto loop_4;
        }
        temp_r3_2226 = this->unk78;
        var_r3_2200 = M2C_FIELD(temp_r3_2226->unk0, s32 (**)(MKVector3 *), 0xC)(temp_r3_2226);
    }
    this->unk68 = NULL;
    temp_r31_2234 = this->unk78;
    if (temp_r31_2234 != NULL) {
        temp_r3_2237 = ((MKHeap *) var_r3_2200)->Current();
        if (temp_r3_2237 != NULL) {
            ((MKHeap *) (temp_r3_2237->Current()))->Free(temp_r31_2234, NULL, 0);
        } else {
            free(temp_r31_2234);
        }
    }
    this->unk78 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'cutsceneStates'
void CutsceneSystem::Init() {
    MKVector3 *temp_r31_2281;

    this->unk24.Init(&cutsceneStates, NULL);
    this->unk24.SetState(this, 0, 0U);
    operator new(0x270U, NULL, 0);
    temp_r31_2281 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_2281 != NULL) {
        temp_r31_2281->unk0 = &__vt;
        M2C_FIELD(temp_r31_2281, s32 *, 0x4C) = 0;
        temp_r31_2281->unk0 = &__vt;
        ((UIStringTable *) (temp_r31_2281 + 0x260))->UIStringTable();
    }
    this->unk78 = temp_r31_2281;
    *KDSynkerPlayer3::pEventCreationTable = &gEventCreationTable;
    this->unk68 = NULL;
    this->unk6C = NULL;
    this->unk70 = 0;
    this->unk89 = 1;
    this->unk20 = 0;
    this->unk9E = 0;
    this->unk9F = 0;
    this->unk1C = NULL;
    this->unkA0 = NULL;
    NULL->GetWorldInfo();
    this->unkA4 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x74);
    this->unk84 = NULL;
    this->unk88 = 1;
    this->unkA9 = 0;
    this->unkAA = 0;
    this->unkAB = 1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CutsceneSystem::DeinitModule() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_2336;
    s8 *temp_r31_2335;

    CutsceneSystem::Location::Deinit();
    temp_r31_2335 = this->unk7C;
    temp_r3_2336 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_2336 != NULL) {
        ((MKHeap *) (temp_r3_2336->Current()))->Free(temp_r31_2335, NULL, 0);
    } else {
        free((MKVector3 *) temp_r31_2335);
    }
    this->unk7C = NULL;
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    M2C_FIELD(&gClearColor, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&gClearColor, f64 *, 8) = (f64) sp10;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void CutsceneSystem::InitModule() {
    MKHeap *temp_r3_2390;
    f32 temp_r31_2389;
    s8 *var_r3_2397;

    this->unk68 = NULL;
    this->unk6C = NULL;
    this->unk70 = 0;
    this->unk89 = 1;
    this->unk20 = 0;
    this->unk9E = 0;
    this->unk9F = 0;
    temp_r31_2389 = gMKDefaults.unkAC;
    temp_r3_2390 = gMKDefaults.Current();
    if (temp_r3_2390 != NULL) {
        var_r3_2397 = ((MKHeap *) (temp_r3_2390->Current()))->Alloc(M2C_BITWISE(s32, temp_r31_2389), NULL, 0);
    } else {
        var_r3_2397 = malloc(M2C_BITWISE(s32, temp_r31_2389));
    }
    this->unk7C = var_r3_2397;
    CutsceneSystem::Location::Init(this);
    this->unk1C = NULL;
    this->unkA0 = NULL;
    ((Level *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetWorldInfo();
    this->unkA4 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x74);
    this->unk84 = NULL;
    this->unk88 = 1;
    this->unkA9 = 0;
    this->unkAA = 0;
    this->unk9C = 0;
    this->unk9D = 0;
    this->unk90 = 0.0f;
    this->unk8C = 9;
    this->unk80 = NULL;
}
#endif

void GameSynkerPlayer::Deinit() {
    KDSynkerPlayer3::Deinit();
    this->unk260.Deinit();
}

void GameSynkerPlayer::Init(const char *arg0, bool arg1, bool arg2, MKIni *arg3) {
    this->unk260.Init(0x800);
    KDSynkerPlayer3::Init(arg0, arg1, arg2, arg3);
}

#if 0 // DRAFT: undefined identifier 'lit_752'
void CutsceneSystem_cpp::__sinit() {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r20_2655;

    temp_r20_2655 = &lit_752 + 0x90;
    sp44 = M2C_FIELD(&lit_752, s32 *, 0x5C);
    M2C_FIELD(temp_r20_2655, s32 *, 0x78) = (s32) M2C_FIELD(&lit_752, s32 *, 0x54);
    sp14 = M2C_FIELD(&lit_752, s32 *, 0x60);
    M2C_FIELD(temp_r20_2655, s32 *, 0x80) = sp44;
    sp18 = M2C_FIELD(&lit_752, s32 *, 0x64);
    M2C_FIELD(temp_r20_2655, s32 *, 0x84) = sp14;
    sp1C = M2C_FIELD(&lit_752, s32 *, 0x68);
    M2C_FIELD(temp_r20_2655, s32 *, 0x88) = sp18;
    sp20 = M2C_FIELD(&lit_752, s32 *, 0x6C);
    M2C_FIELD(temp_r20_2655, s32 *, 0x8C) = sp1C;
    sp24 = M2C_FIELD(&lit_752, s32 *, 0x70);
    M2C_FIELD(temp_r20_2655, s32 *, 0x90) = sp20;
    sp28 = M2C_FIELD(&lit_752, s32 *, 0x74);
    M2C_FIELD(temp_r20_2655, s32 *, 0x94) = sp24;
    sp2C = M2C_FIELD(&lit_752, s32 *, 0x78);
    M2C_FIELD(temp_r20_2655, s32 *, 0x98) = sp28;
    sp30 = M2C_FIELD(&lit_752, s32 *, 0x7C);
    M2C_FIELD(temp_r20_2655, s32 *, 0x9C) = sp2C;
    sp34 = M2C_FIELD(&lit_752, s32 *, 0x80);
    M2C_FIELD(temp_r20_2655, s32 *, 0xA0) = sp30;
    sp38 = M2C_FIELD(&lit_752, s32 *, 0x84);
    M2C_FIELD(temp_r20_2655, s32 *, 0xA4) = sp34;
    sp3C = M2C_FIELD(&lit_752, s32 *, 0x88);
    M2C_FIELD(temp_r20_2655, s32 *, 0xA8) = sp38;
    M2C_FIELD(temp_r20_2655, s32 *, 0xAC) = sp3C;
    sp40 = M2C_FIELD(&lit_752, s32 *, 0x8C);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(&lit_752, s32 *, 0x90) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_752, s32 *, 0x94) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_752, s32 *, 0x98) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_2655, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_2655, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_2655, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_2655, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_2655, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_2655, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_2655, s32 *, 0x24) = (s32) M2C_FIELD(&lit_752, s32 *, 0);
    M2C_FIELD(temp_r20_2655, s32 *, 0x28) = (s32) M2C_FIELD(&lit_752, s32 *, 4);
    M2C_FIELD(temp_r20_2655, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_752, s32 *, 8);
    M2C_FIELD(temp_r20_2655, s32 *, 0x30) = (s32) M2C_FIELD(&lit_752, s32 *, 0xC);
    M2C_FIELD(temp_r20_2655, s32 *, 0x34) = (s32) M2C_FIELD(&lit_752, s32 *, 0x10);
    M2C_FIELD(temp_r20_2655, s32 *, 0x38) = (s32) M2C_FIELD(&lit_752, s32 *, 0x14);
    M2C_FIELD(temp_r20_2655, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_752, s32 *, 0x18);
    M2C_FIELD(temp_r20_2655, s32 *, 0x40) = (s32) M2C_FIELD(&lit_752, s32 *, 0x1C);
    M2C_FIELD(temp_r20_2655, s32 *, 0x44) = (s32) M2C_FIELD(&lit_752, s32 *, 0x20);
    M2C_FIELD(temp_r20_2655, s32 *, 0x48) = (s32) M2C_FIELD(&lit_752, s32 *, 0x24);
    M2C_FIELD(temp_r20_2655, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_752, s32 *, 0x28);
    M2C_FIELD(temp_r20_2655, s32 *, 0x50) = (s32) M2C_FIELD(&lit_752, s32 *, 0x2C);
    M2C_FIELD(temp_r20_2655, s32 *, 0x54) = (s32) M2C_FIELD(&lit_752, s32 *, 0x30);
    M2C_FIELD(temp_r20_2655, s32 *, 0x58) = (s32) M2C_FIELD(&lit_752, s32 *, 0x34);
    M2C_FIELD(temp_r20_2655, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_752, s32 *, 0x38);
    M2C_FIELD(temp_r20_2655, s32 *, 0x60) = (s32) M2C_FIELD(&lit_752, s32 *, 0x3C);
    M2C_FIELD(temp_r20_2655, s32 *, 0x64) = (s32) M2C_FIELD(&lit_752, s32 *, 0x40);
    M2C_FIELD(temp_r20_2655, s32 *, 0x68) = (s32) M2C_FIELD(&lit_752, s32 *, 0x44);
    M2C_FIELD(temp_r20_2655, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_752, s32 *, 0x48);
    M2C_FIELD(temp_r20_2655, s32 *, 0x70) = (s32) M2C_FIELD(&lit_752, s32 *, 0x4C);
    M2C_FIELD(temp_r20_2655, s32 *, 0x74) = (s32) M2C_FIELD(&lit_752, s32 *, 0x50);
    M2C_FIELD(temp_r20_2655, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_752, s32 *, 0x58);
    M2C_FIELD(temp_r20_2655, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_752, s32 *, 0x8C);
}
#endif
