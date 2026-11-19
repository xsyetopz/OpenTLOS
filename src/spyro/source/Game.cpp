#include "spyro/source/Game.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector4.h"
#include "common/Source/MKView.h"
#include "common/Source/Texture.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/ExplosionWarpFX.h"
#include "spyro/source/GameCamera2.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDShatter2.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/Level.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/ShotgunWarpFX.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/TimeDeltaModifier.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKPackage.h"
#include "common/Source/MKRumble.h"
#include "common/Source/MKSplineTube.h"
#include "common/Source/MKSystem.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Ball.h"
#include "spyro/source/BoulderRamp.h"
#include "spyro/source/Catapult.h"
#include "spyro/source/Cheats.h"
#include "spyro/source/ConsoleCmds.h"
#include "spyro/source/Credits.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/GameConsole.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/GameProperties.h"
#include "spyro/source/GameSounds.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/Music.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Points.h"
#include "spyro/source/RumbleTimer.h"
#include "spyro/source/SiegeTower.h"
#include "spyro/source/SnowballTree.h"
#include "spyro/source/Subtitles.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UITools.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'DialogBox_bAllowOverCutscene' redeclared
M2C_UNK free(TargetManager *);                      /* extern */
TargetManager *malloc(s32);                         /* extern */
extern u8 DialogBox_bAllowOverCutscene;
#endif
extern s8 Dialog_bEnableDraw;
extern s8 Hud_bDisableDraw;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern u8 bQuit;
extern M2C_UNK gDynamicBones;
extern void **gMK;
extern M2C_UNK gMKDefaults;
extern s8 gShowCursor;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: identifier 'gbGoldMaster' redeclared
extern s8 gbGoldMaster;
#endif
extern s8 *gpBuildVersion;
extern M2C_UNK input;
extern Level *pStartChunkName;
extern Level *pStartLevelName;
#if 0 // DRAFT: identifier 'gClearColor' redeclared
static M2C_UNK gClearColor;                         /* unable to generate initializer: unknown type */
static GameStateMachineState gameStates[0x48] = {
    { 0 },
    { (s32) &.L_803580AE },
    { 0 },
    { -1 },
    { 0 },
    { (s32) LoadGlobalResources_Update__Fv },
    { 0 },
    { (s32) LoadGlobalResources_Deinit__Fv },
    { 1 },
    { (s32) &.L_803580C2 },
    { 0 },
    { -1 },
    { 0 },
    { (s32) ControllerInit_Update__Fv },
    { 0 },
    { 0 },
    { 2 },
    { (s32) &.L_803580D1 },
    { 0 },
    { -1 },
    { 0 },
    { (s32) NoController_Update__Fv },
    { (s32) NoController_Draw__Fv },
    { 0 },
    { 3 },
    { (s32) &.L_803580DE },
    { 3 },
    { -1 },
    { (s32) Language_Init__Fv },
    { (s32) Language_Update__Fv },
    { (s32) Language_Draw__Fv },
    { (s32) Language_Deinit__Fv },
    { 4 },
    { (s32) &.L_803580E7 },
    { 1 },
    { -1 },
    { (s32) LoadLevel_Init__Fv },
    { (s32) LoadLevel_Update__Fv },
    { (s32) LoadLevel_Draw__Fv },
    { (s32) LoadLevel_Deinit__Fv },
    { 5 },
    { (s32) &.L_803580F4 },
    { 2 },
    { -1 },
    { (s32) FrontEnd_Init__Fv },
    { (s32) FrontEnd_Update__Fv },
    { (s32) FrontEnd_Draw__Fv },
    { (s32) FrontEnd_Deinit__Fv },
    { 6 },
    { (s32) &.L_803580FD },
    { 1 },
    { -1 },
    { (s32) LoadLevel_Init__Fv },
    { (s32) LoadLevel_Update__Fv },
    { (s32) LoadLevel_Draw__Fv },
    { (s32) LoadLevel_Deinit__Fv },
    { 7 },
    { (s32) &.L_80358107 },
    { 2 },
    { -1 },
    { (s32) InGame_Init__Fv },
    { (s32) InGame_Update__Fv },
    { (s32) InGame_Draw__Fv },
    { (s32) InGame_Deinit__Fv },
    { -1 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
};
#endif
static GameStateMachineInit gameStateInit = { 0, 0.5f, 0.5f, 0x80000000 };
#if 0 // DRAFT: identifier 'gb' redeclared
static M2C_UNK *gb[0xF0];
#endif
#if 0 // DRAFT: identifier 'cutsceneSys' redeclared
static M2C_UNK cutsceneSys;
#endif
#if 0 // DRAFT: identifier 'homeDir' redeclared
static s8 homeDir[0x20];
#endif
#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
static GameStateMachine gGMState;                   /* extra bytes: 0x11 */
static s8 *buildNumber = lit_stringBase0;
#endif
#if 0 // DRAFT: identifier 'platformCode' redeclared
static M2C_UNK *platformCode = &.L_803580AB;
#endif

#if 0 // DRAFT: declaration syntax error
static Level lit_877;                                  /* type too large by 0xD8; unable to generate initializer: non-zero padding; const */
static M2C_UNK lit_934;                                /* unable to generate initializer: unknown type; const */
static s8 lit_stringBase0[0xB] = { 0x30, 0x35, 0x33, 0x62, 0x33, 0x28, 0x72, 0x65, 0x74, 0x29, 0 }; /* const */
static M2C_UNK .L_803580AB;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_803580AE;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_803580C2;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_803580D1;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_803580DE;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_803580E7;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_803580F4;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_803580FD;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_80358107;                         /* unable to generate initializer: unknown type; const */

s32 SpawnerType_ResolveFromStatType(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        return 0;
    }
}
#endif

f32 GameGlobals::KillRate::GetRate() {
    return (f32) M2C_FIELD(this, s32 *, 4) / M2C_FIELD(this, f32 *, 0x10);
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void GameGlobals::KillRate::Update() {
    f32 *var_r4_87;
    s32 temp_r0_69;
    s32 temp_r4_70;
    s32 temp_r6_80;

loop_5:
    temp_r6_80 = M2C_FIELD(this, s32 *, 4);
    if (temp_r6_80 != 0) {
        if (temp_r6_80 > 0) {
            var_r4_87 = M2C_FIELD(this, s32 *, 0xC) + (M2C_FIELD(this, s32 *, 8) * 4);
        } else {
            var_r4_87 = NULL;
        }
        if (!(*var_r4_87 < (M2C_BITWISE(f32, gb[0xC3]) - M2C_FIELD(this, f32 *, 0x10)))) {
            return;
        }
        if (temp_r6_80 > 0) {
            M2C_FIELD(this, s32 *, 8) = (s32) (M2C_FIELD(this, s32 *, 8) + 1);
            temp_r0_69 = M2C_FIELD(this, s32 *, 8);
            temp_r4_70 = M2C_FIELD(this, s32 *, 0);
            if (temp_r0_69 >= temp_r4_70) {
                M2C_FIELD(this, s32 *, 8) = (s32) (temp_r0_69 - temp_r4_70);
            }
            M2C_FIELD(this, s32 *, 4) = (s32) (M2C_FIELD(this, s32 *, 4) - 1);
        }
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void GameGlobals::KillRate::AddKill() {
    s32 temp_r0_113;
    s32 temp_r4_104;
    s32 temp_r4_114;
    s32 temp_r5_126;
    s32 var_r0_127;

    temp_r4_104 = M2C_FIELD(this, s32 *, 4);
    if ((temp_r4_104 == (s32) M2C_FIELD(this, s32 *, 0)) && (temp_r4_104 > 0)) {
        M2C_FIELD(this, s32 *, 8) = (s32) (M2C_FIELD(this, s32 *, 8) + 1);
        temp_r0_113 = M2C_FIELD(this, s32 *, 8);
        temp_r4_114 = M2C_FIELD(this, s32 *, 0);
        if (temp_r0_113 >= temp_r4_114) {
            M2C_FIELD(this, s32 *, 8) = (s32) (temp_r0_113 - temp_r4_114);
        }
        M2C_FIELD(this, s32 *, 4) = (s32) (M2C_FIELD(this, s32 *, 4) - 1);
    }
    temp_r5_126 = M2C_FIELD(this, s32 *, 0);
    var_r0_127 = M2C_FIELD(this, s32 *, 8) + M2C_FIELD(this, s32 *, 4);
    if (var_r0_127 >= temp_r5_126) {
        var_r0_127 -= temp_r5_126;
    }
    M2C_FIELD(this, s32 *, 4) = (s32) (M2C_FIELD(this, s32 *, 4) + 1);
    *(M2C_FIELD(this, s32 *, 0xC) + (var_r0_127 * 4)) = M2C_BITWISE(f32, gb[0xC3]);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GameGlobals::KillRate::Deinit() {
    MKHeap *temp_r3_155;
    TargetManager *temp_r31_152;

    temp_r31_152 = M2C_FIELD(this, TargetManager **, 0xC);
    if (temp_r31_152 != NULL) {
        temp_r3_155 = MKHeap::Current();
        if (temp_r3_155 != NULL) {
            ((MKHeap *) (temp_r3_155->Current()))->Free(temp_r31_152, NULL, 0);
        } else {
            free(temp_r31_152);
        }
        M2C_FIELD(this, TargetManager **, 0xC) = NULL;
    }
    M2C_FIELD(this, s32 *, 0) = 0;
    M2C_FIELD(this, s32 *, 8) = 0;
    M2C_FIELD(this, s32 *, 4) = 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GameGlobals::KillRate::Init(int arg1, float farg0) {
    MKHeap *temp_r3_193;
    TargetManager *var_r3_200;

    temp_r3_193 = MKHeap::Current();
    if (temp_r3_193 != NULL) {
        var_r3_200 = ((MKHeap *) (temp_r3_193->Current()))->Alloc(arg1 * 4, NULL, 0);
    } else {
        var_r3_200 = malloc(arg1 * 4);
    }
    M2C_FIELD(this, TargetManager **, 0xC) = var_r3_200;
    M2C_FIELD(this, s32 *, 0) = arg1;
    M2C_FIELD(this, f32 *, 0x10) = farg0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKVector4 *' to
void GameGlobals::Fade::FadeOut(const MKVector4 *arg1) {
    MKVector4 *var_r4_0;

    var_r4_0 = arg1;
    if ((s32) M2C_FIELD(this, s32 *, 0x20) < 2) {
        if (var_r4_0 != NULL) {

        } else {
            var_r4_0 = &zero;
        }
        M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(var_r4_0, f64 *, 0);
        M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(var_r4_0, f64 *, 8);
        M2C_FIELD(this, f32 *, 0xC) = 0.0f;
        M2C_FIELD(this, s32 *, 0x20) = 2;
    }
}
#endif

void GameGlobals::Fade::FadeIn(const MKVector4 *arg1) {
    if ((s32) M2C_FIELD(this, s32 *, 0x20) != 1) {
        if (arg1 != NULL) {
            M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(arg1, f64 *, 0);
            M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(arg1, f64 *, 8);
        }
        if ((s32) M2C_FIELD(this, s32 *, 0x20) != 2) {
            M2C_FIELD(this, f32 *, 0xC) = 1.0f;
        }
        M2C_FIELD(this, s32 *, 0x20) = 1;
    }
}

#if 0 // DRAFT: pointer/array required
void GameGlobals::Fade::Draw() {
    if (((s32) M2C_FIELD(this, s32 *, 0x20) > 0) || (M2C_FIELD(this, f32 *, 0x1C) > 0.0f)) {
        MKMaterial_SetMaterial((MKMaterial *) gb[0xCA]);
        MKSetBaseColorV(one);
        MKPrimitive(0xC, 3);
        MKBegin(4);
        if (M2C_FIELD(this, f32 *, 0x1C) > 0.0f) {
            MKSetColorV(*(MKVector4 *) (this + 0x10));
        } else {
            MKSetColorV(*((MKVector4 *) this));
        }
        MKSetPositionF(-108.0f, 0.0f, 0.0f);
        MKSetPositionF(748.0f, 0.0f, 0.0f);
        MKSetPositionF(-108.0f, 512.0f, 0.0f);
        MKSetPositionF(748.0f, 512.0f, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: function call 'PhrasePlayer_PlayEvent(signed char *)' does not match
void GameGlobals::Fade::Update() {
    s32 temp_r0_338;

    temp_r0_338 = M2C_FIELD(this, s32 *, 0x20);
    switch (temp_r0_338) {                          /* irregular */
    case 1:
        M2C_FIELD(this, f32 *, 0xC) = (f32) (M2C_FIELD(this, f32 *, 0xC) - gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(this, f32 *, 0xC) == 0.0f) {
            M2C_FIELD(this, f32 *, 0xC) = 0.0f;
            M2C_FIELD(this, s32 *, 0x20) = 0;
            if (((u8) M2C_FIELD(this, u8 *, 0x28) != 0) && ((u8) M2C_FIELD(this, u8 *, 0x29) == 0)) {
                M2C_FIELD(this, u8 *, 0x28) = 0U;
                M2C_FIELD(this, s32 *, 0x24) = PhrasePlayer_PlayEvent(lit_stringBase0 + 0x6E);
                return;
            }
        }
        return;
    case 2:
        M2C_FIELD(this, f32 *, 0xC) = (f32) (M2C_FIELD(this, f32 *, 0xC) + gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(this, f32 *, 0xC) == 1.0f) {
            M2C_FIELD(this, f32 *, 0xC) = 1.0f;
            M2C_FIELD(this, s32 *, 0x20) = 3;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void GameGlobals::Fade::Reset() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 8);
    M2C_FIELD(this, s32 *, 0x20) = 0;
}
#endif

void GameGlobals::Fade::Deinit() {
    s32 temp_r3_415;

    temp_r3_415 = M2C_FIELD(this, s32 *, 0x24);
    if (temp_r3_415 != 0) {
        PhrasePlayer_StopEvent(temp_r3_415);
    }
}

#if 0 // DRAFT: undefined identifier 'zero'
void GameGlobals::Fade::Init() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, s32 *, 0x20) = 0;
    M2C_FIELD(this, s8 *, 0x28) = 0;
    M2C_FIELD(this, s8 *, 0x29) = 0;
    M2C_FIELD(this, s32 *, 0x24) = 0;
}
#endif

void GameGlobals::EnableSlowMotion(bool arg0, float arg1, float arg2) {
    f32 var_f1_0;
    f32 var_f2_0;
    s32 var_r4_446;

    var_f1_0 = arg1;
    var_f2_0 = arg2;
    var_r4_446 = -1;
    if (arg0 != 0) {
        var_r4_446 = 1;
    }
    this->unk364 += var_r4_446;
    if ((s32) this->unk364 < 0) {
        this->unk364 = 0;
    }
    if ((s32) this->unk364 == 1) {

    } else {
        var_f1_0 = -1.0f;
    }
    this->unk36C = var_f1_0;
    this->unk368 = var_f1_0;
    if (var_f2_0 < 1.0f) {

    } else {
        var_f2_0 = 1.0f;
    }
    if (var_f2_0 > -100.0f) {

    } else {
        var_f2_0 = -100.0f;
    }
    this->unk374 = var_f2_0;
}

void GameGlobals::Capture::Release() {

}

void GameGlobals::Capture::Get() {
    Lock();
    ((Texture *) (M2C_FIELD(this, Texture **, 4)))->CaptureDrawBuffer(0.0f, 0.0f, 640.0f, 512.0f);
}

void GameGlobals::Capture::Lock() {

}

void GameGlobals::Capture::Deinit() {
    MKMaterial_Destroy(M2C_FIELD(this, MKMaterial **, 0));
    ((Texture *) (M2C_FIELD(this, Texture **, 4)))->Destroy();
}

#if 0 // DRAFT: expression syntax error
void GameGlobals::Capture::Init(char *arg1, int arg2) {
    arg1->CreateRenderTarget((s8 *) arg2, arg2, 0, M2C_ERROR(/* Read from unset register $r7 */));
    M2C_FIELD(this, s32 *, 4) = (s32) M2C_ERROR(/* Read from unset register $r3 */);
    M2C_FIELD(this, MKResource **, 0) = MKMaterial_Create(arg1);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void GameGlobals::EmitFairyDandruf(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, const MKVector4 &arg3) {
    void *temp_r3_575;
    void *temp_r3_579;
    void *temp_r4_582;

    temp_r3_575 = this->unk8C;
    temp_r3_579 = M2C_FIELD(M2C_FIELD(temp_r3_575, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_575);
    if (temp_r3_579 != NULL) {
        temp_r4_582 = M2C_FIELD(temp_r3_579, void **, 0x2C);
        M2C_FIELD(temp_r3_579, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_579, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_579, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_579, f64 *, 0x10) = (f64) M2C_FIELD(&arg3, f64 *, 0);
        M2C_FIELD(temp_r3_579, f64 *, 0x18) = (f64) M2C_FIELD(&arg3, f64 *, 8);
        M2C_FIELD(temp_r4_582, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_582, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4_582, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r4_582, f32 *, 0x10) = 0.0f;
        M2C_FIELD(temp_r4_582, f32 *, 0x14) = (f32) M2C_FIELD(this->unk78, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void GameGlobals::EmitSnowCrud(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r31_629;
    void *temp_r3_622;
    void *temp_r3_626;

    temp_r3_622 = this->unk2A0;
    temp_r3_626 = M2C_FIELD(M2C_FIELD(temp_r3_622, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_622);
    if (temp_r3_626 != NULL) {
        temp_r31_629 = M2C_FIELD(temp_r3_626, void **, 0x2C);
        M2C_FIELD(temp_r3_626, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_626, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_626, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_626, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r31_629, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_629, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_629, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r31_629, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r31_629, f32 *, 0x14) = (f32) M2C_FIELD(this->unk78, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void GameGlobals::EmitDust(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, float arg3) {
    void *temp_r31_680;
    void *temp_r3_670;
    void *temp_r3_677;

    temp_r3_670 = this->unk7C;
    temp_r3_677 = M2C_FIELD(M2C_FIELD(temp_r3_670, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_670);
    if (temp_r3_677 != NULL) {
        temp_r31_680 = M2C_FIELD(temp_r3_677, void **, 0x2C);
        M2C_FIELD(temp_r3_677, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_677, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_677, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_677, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r31_680, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_680, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_680, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r31_680, f32 *, 0x10) = (f32) (arg3 * MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f));
        M2C_FIELD(temp_r31_680, f32 *, 0x14) = (f32) M2C_FIELD(this->unk7C, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void GameGlobals::EmitSmallRocks(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r31_731;
    void *temp_r3_724;
    void *temp_r3_728;

    temp_r3_724 = this->unk2B4;
    temp_r3_728 = M2C_FIELD(M2C_FIELD(temp_r3_724, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_724);
    if (temp_r3_728 != NULL) {
        temp_r31_731 = M2C_FIELD(temp_r3_728, void **, 0x2C);
        M2C_FIELD(temp_r3_728, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_728, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_728, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_728, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r31_731, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_731, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_731, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r31_731, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r31_731, f32 *, 0x14) = (f32) M2C_FIELD(this->unk2B4, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void GameGlobals::EmitCrud(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r31_779;
    void *temp_r3_772;
    void *temp_r3_776;

    temp_r3_772 = this->unk78;
    temp_r3_776 = M2C_FIELD(M2C_FIELD(temp_r3_772, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_772);
    if (temp_r3_776 != NULL) {
        temp_r31_779 = M2C_FIELD(temp_r3_776, void **, 0x2C);
        M2C_FIELD(temp_r3_776, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_776, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_776, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_776, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r31_779, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_779, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_779, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r31_779, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r31_779, f32 *, 0x14) = (f32) M2C_FIELD(this->unk78, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void GameGlobals::GetSpyro() {
    checked_cast<Spyro *, MKProp>(M2C_FIELD(**gb, MKProp *(**)(M2C_UNK *), 0xC)(*gb));
}
#endif

#if 0 // DRAFT: identifier 'arg3' redeclared
void GameGlobals::SetGamePaused(bool arg0, bool (*arg3)(void), void (*arg2)(void), unsigned int arg3) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u32 temp_r0_842;

    if ((u8) this->unk396 == 0) {
        if (arg0 == 0) {
            temp_r0_842 = this->unk39C;
            if ((arg3 != temp_r0_842) && (temp_r0_842 != 0)) {
                this->unk398 = temp_r0_842;
                M2C_FIELD(this, u8 (**)(), 0x3A4) = (u8 (*)()) M2C_FIELD(this, u8 (**)(), 0x3AC);
                M2C_FIELD(this, void (**)(), 0x3A8) = (void (*)()) M2C_FIELD(this, void (**)(), 0x3B0);
                this->unk39C = 0;
                return;
            }
        }
        if ((arg0 != 0) && (arg3 != (u32) this->unk39C)) {
            this->unk395 = arg0;
            M2C_FIELD(this, u8 (**)(), 0x3AC) = (u8 (*)()) M2C_FIELD(this, u8 (**)(), 0x3A4);
            M2C_FIELD(this, void (**)(), 0x3B0) = (void (*)()) M2C_FIELD(this, void (**)(), 0x3A8);
            M2C_FIELD(this, u8 (**)(), 0x3A4) = arg1;
            M2C_FIELD(this, void (**)(), 0x3A8) = arg2;
            this->unk39C = this->unk398;
            this->unk398 = arg3;
            this->unk3A1 = KDSound_IsChronoSoundWarpEnabled();
            this->unk3A2 = KDSound_IsChronoSoundWarpActive();
            KDSound_EnableChronoSoundWarp(0U, 0U);
            this->unk3A0 = MKRumble_IsMuted();
            MKRumble_Mute(0U);
            M2C_FIELD(&gDynamicBones, s8 *, 4) = 1;
            MKRumble_Push();
            sp14 = 0;
            sp10 = 0x3D;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp10, 0, 0, 0, 1, 0.0f);
            return;
        }
        if ((arg0 == 0) && (arg3 != (u32) this->unk39C) && ((u32) this->unk398 != 0)) {
            this->unk395 = arg0;
            M2C_FIELD(this, u8 (**)(), 0x3AC) = (u8 (*)()) M2C_FIELD(this, u8 (**)(), 0x3A4);
            M2C_FIELD(this, void (**)(), 0x3B0) = (void (*)()) M2C_FIELD(this, void (**)(), 0x3A8);
            M2C_FIELD(this, u8 (**)(), 0x3A4) = arg1;
            M2C_FIELD(this, void (**)(), 0x3A8) = arg2;
            this->unk39C = 0;
            this->unk398 = 0;
            MKRumble_Pop();
            M2C_FIELD(&gDynamicBones, s8 *, 4) = 0;
            MKRumble_Mute(this->unk3A0);
            KDSound_EnableChronoSoundWarp(this->unk3A1, this->unk3A2);
            spC = 0;
            sp8 = 0x3E;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0, 0, 0, 1, 0.0f);
        }
    }
}
#endif

void GameGlobals::InfiniteMagicOff() {
    this->unkB = 0;
}

#if 0 // DRAFT: undefined identifier 'gameData'
void GameGlobals::InfiniteMagicOn() {
    this->unkB = 1;
    gameData.unkA0.SetValue(30.0f, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
HeroInterface *GameGlobals::SetHero(HeroInterface *arg0) {
    s32 spC;
    s32 sp8;
    HeroInterface *temp_r3_990;
    void *temp_r3_997;

    temp_r3_990 = this->unk0;
    if (temp_r3_990 != NULL) {
        temp_r3_997 = M2C_FIELD(temp_r3_990->__vptr, void *(**)(), 0xC)();
        spC = 0;
        sp8 = 0xA7;
        M2C_FIELD(M2C_FIELD(temp_r3_997, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    this->unk0 = arg0;
    return temp_r3_990;
}
#endif

void GameGlobals::ResetInGameData() {
    this->unk395 = 0;
    this->unk394 = 0;
    this->unk0 = NULL;
    this->unk60 = 0;
    this->unk64 = 0;
    this->unk68 = 0;
    this->unk6C = 0;
    this->unk70 = 0;
    this->unk74 = 0;
    this->unk78 = NULL;
    this->unk7C = NULL;
    this->unk80 = 0;
    this->unk84 = 0;
    this->unk88 = 0;
    this->unk90 = 0;
    this->unk8C = NULL;
    this->unk94 = 0;
    this->unk98 = 0;
    this->unk9C = 0;
    this->unkA0 = 0;
    this->unkA4 = 0;
    this->unkA8 = 0;
    this->unkAC = 0;
    this->unkB0 = 0;
    this->unkB4 = 0;
    this->unk230 = 0;
    this->unk234 = 0;
    this->unk238 = 0;
    this->unk2A0 = NULL;
    this->unk2AC = 0;
    this->unk2B4 = NULL;
    this->unk2C0 = 0;
    this->unk2C8 = 0;
    this->unk2F4 = 0;
    this->unk364 = 0;
    this->unk398 = 0;
    this->unk39C = 0;
    M2C_FIELD(this, s32 *, 0x3AC) = 0;
    M2C_FIELD(this, s32 *, 0x3B0) = 0;
    M2C_FIELD(this, s32 *, 0x3A4) = 0;
    M2C_FIELD(this, s32 *, 0x3A8) = 0;
}

#if 0 // DRAFT: pointer/array required
void GameGlobals::Deinit() {
    MKHeap *temp_r3_1105;
    TargetManager *temp_r30_1104;

    RumbleTimer_Deinit();
    ((GameGlobals::KillRate *) ((GameGlobals::KillRate *) &gb[0xBE]))->Deinit();
    ((GameGlobals::Fade *) ((GameGlobals::Fade *) &gb[0xC]))->Deinit();
    ((HeatDistortPS *) ((HeatDistortPS *) &gb[0x90]))->Deinit();
    ((ExplosionWarpFX *) ((ExplosionWarpFX *) &gb[0x70]))->Deinit();
    ((ShotgunWarpFX *) ((ShotgunWarpFX *) &gb[0x4C]))->Deinit();
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) &gb[0x2E]))->Deinit();
    this->unk24.Deinit();
    this->unk354 = NULL;
    this->unk20->Deinit();
    temp_r30_1104 = this->unk20;
    temp_r3_1105 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1105 != NULL) {
        ((MKHeap *) (temp_r3_1105->Current()))->Free(temp_r30_1104, NULL, 0);
    } else {
        free(temp_r30_1104);
    }
    this->unk20 = NULL;
    MKMaterial_Destroy((MKMaterial *) gb[0xCA]);
    gb[0xCA] = NULL;
    DialogBox_FreeTheme(this->unk324);
    this->unk31C->Destroy();
    this->unk318->Destroy();
    operator delete(gMK);
    gMK = NULL;
    ((Level *) (M2C_ERROR(/* Read from unset register $r3 */)))->DeinitModule();
    operator delete(this->unk32C);
}
#endif

#if 0 // DRAFT: pointer/array required
void GameGlobals::Init() {
    DialogBoxTheme *temp_r3_1216;
    MKHeap *temp_r3_1226;
    TargetManager *var_r3_1233;

    memset(this, 0, 0x3C0U);
    this->unk384 = 0.75f;
    this->unk388 = 0.2f;
    this->unk38C = 0.2f;
    operator new(0xF0U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x24) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 0;
    }
    this->unk32C = M2C_ERROR(/* Read from unset register $r3 */);
    ((Level *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitModule();
    operator new(0xF8U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 0xE4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xF4) = 0;
    }
    gMK = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk358 = -1;
    this->unk396 = 0;
    this->unk35C = 0;
    this->unk35E = 1;
    this->unk318 = ((MKFont *) ((MKFont *) (lit_stringBase0 + 0x80)))->Create(NULL);
    this->unk31C = ((MKFont *) ((MKFont *) (lit_stringBase0 + 0x8A)))->Create(lit_stringBase0);
    temp_r3_1216 = DialogBox_LoadTheme(NULL, lit_stringBase0 + 0x80, 4.0f, 0.0f);
    this->unk324 = temp_r3_1216;
    this->unk398 = 0;
    this->unk39C = 0;
    M2C_FIELD(this, s32 *, 0x3AC) = 0;
    M2C_FIELD(this, s32 *, 0x3B0) = 0;
    M2C_FIELD(this, s32 *, 0x3A4) = 0;
    M2C_FIELD(this, s32 *, 0x3A8) = 0;
    this->unk382 = 0;
    temp_r3_1226 = temp_r3_1216->Current();
    if (temp_r3_1226 != NULL) {
        var_r3_1233 = ((MKHeap *) (temp_r3_1226->Current()))->Alloc(0x10, NULL, 0);
    } else {
        var_r3_1233 = malloc(0x10);
    }
    this->unk20 = var_r3_1233;
    this->unk20->Init();
    gb[0xCA] = MKMaterial_Create(lit_stringBase0 + 0x97);
    this->unk354 = &input;
    M2C_FIELD(&input, s32 *, 0) = 0;
    M2C_FIELD(&input, s8 *, 4) = 0;
    M2C_FIELD(&input, s8 *, 5) = 0;
    this->unk24.Init(lit_stringBase0 + 0xA0, 0x100);
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) &gb[0x2E]))->Init();
    gb[0x32] = 0.9f;
    gb[0x33] = NULL;
    ((ShotgunWarpFX *) ((ShotgunWarpFX *) &gb[0x4C]))->Init();
    ((ExplosionWarpFX *) ((ExplosionWarpFX *) &gb[0x70]))->Init();
    ((HeatDistortPS *) ((HeatDistortPS *) &gb[0x90]))->Init();
    ((GameGlobals::Fade *) ((GameGlobals::Fade *) &gb[0xC]))->Init();
    ((GameGlobals::KillRate *) ((GameGlobals::KillRate *) &gb[0xBE]))->Init(0x14, 10.0f);
    ((TimeDeltaModifier *) ((TimeDeltaModifier *) &gb[0xB3]))->Init();
    RumbleTimer_Init();
    this->unkA = 0;
    this->unk4 = 1;
    this->unk5 = 1;
    this->unk6 = 1;
    this->unk7 = 1;
    this->unk8 = 1;
    this->unkB = 0;
    this->unk35D = 0;
    this->unk9 = 1;
    this->unk378 = 0.0f;
    this->unk37C = 1.0f;
    this->unk380 = 0;
    this->unk381 = 0;
    gb[0xE4] = 0.5f;
}
#endif

void LoadGlobalResources_Deinit() {

}

#if 0 // DRAFT: pointer/array required
void LoadGlobalResources_Update() {
    MemoryCard_InitModule();
    if ((M2C_UNK *) gb[0xCF] != NULL) {
        gameData.ClearData();
        ((Level *) ((Level *) gb[0xCB]))->SwitchTo((ChunkInfo *) gb[0xCC]);
        return;
    }
    gGMState.SwitchState(1, 0, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void Game_CheckCommandLineParameters() {
    M2C_UNK *var_r0_1418;

    System_GetCommandLineParameter(lit_stringBase0 + 0xA8, 0U);
    pStartLevelName = M2C_ERROR(/* Read from unset register $r3 */);
    System_GetCommandLineParameter(lit_stringBase0 + 0xAE, 0U);
    pStartChunkName = M2C_ERROR(/* Read from unset register $r3 */);
    System_GetCommandLineParameter(lit_stringBase0 + 0xB4, 0U);
    gb[0xCE] = (M2C_UNK *) (M2C_ERROR(/* Read from unset register $r3 */) != 0);
    System_GetCommandLineParameter(lit_stringBase0 + 0xBD, 1U);
    gb[0xCF] = (M2C_UNK *) (M2C_ERROR(/* Read from unset register $r3 */) == 0);
    System_GetCommandLineParameter(lit_stringBase0 + 0xC6, 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        System_GetCommandLineParameter(lit_stringBase0 + 0xD6, 0U);
        var_r0_1418 = (M2C_ERROR(/* Read from unset register $r3 */) != 0) + 1;
    } else {
        var_r0_1418 = NULL;
    }
    gb[0xD0] = var_r0_1418;
    System_GetCommandLineParameter(lit_stringBase0 + 0xDF, 0U);
    gb[0xD1] = (M2C_UNK *) (M2C_ERROR(/* Read from unset register $r3 */) != 0);
    System_GetCommandLineParameter(lit_stringBase0 + 0xED, 1U);
    gb[0xD2] = (M2C_UNK *) (M2C_ERROR(/* Read from unset register $r3 */) != 0);
    System_GetCommandLineParameter(lit_stringBase0 + 0xF7, 1U);
    gb[0xD3] = (M2C_UNK *) (M2C_ERROR(/* Read from unset register $r3 */) != 0);
    System_GetCommandLineParameter(lit_stringBase0 + 0x104, 1U);
    Hud_bDisableDraw = (M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0;
    System_GetCommandLineParameter(lit_stringBase0 + 0x108, 1U);
    Dialog_bEnableDraw = (M2C_ERROR(/* Read from unset register $r3 */) != 0) != 0;
    System_GetCommandLineParameter(lit_stringBase0 + 0x10F, 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        System_GetCommandLineParameter(lit_stringBase0 + 0xD6, 0U);
        gb[0xD1] = (M2C_UNK *)1;
        gb[0xD0] = (M2C_ERROR(/* Read from unset register $r3 */) != 0) + 1;
    }
    System_GetCommandLineParameter(lit_stringBase0 + 0x117, 1U);
    gb[0xD4] = (M2C_UNK *) (M2C_ERROR(/* Read from unset register $r3 */) != 0);
    if ((M2C_UNK *) gb[0xD0] != NULL) {
        gb[0xD4] = NULL;
    }
    System_GetCommandLineParameter(lit_stringBase0 + 0x11E, 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        MKGrass_Enable(0U);
    }
    System_GetCommandLineParameter(lit_stringBase0 + 0x124, 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        M2C_FIELD(&gMKDefaults, s8 *, 0x10) = 0;
    }
    Cheats_CheckCommandLineParameters();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void Game_InitSystem() {
    M2C_FIELD(&gMKDefaults, s32 *, 8) = 0x100000;
    M2C_FIELD(&gMKDefaults, s32 *, 0x48) = 0x10000;
    M2C_FIELD(&gMKDefaults, s32 *, 0x30) = 0x200;
    M2C_FIELD(&gMKDefaults, s32 *, 0x38) = 0x800;
    M2C_FIELD(&gMKDefaults, s32 *, 0x3C) = 0x200;
    M2C_FIELD(&gMKDefaults, s32 *, 0x54) = 0x400;
    M2C_FIELD(&gMKDefaults, s8 *, 0x10) = 1;
    M2C_FIELD(&gMKDefaults, s32 *, 0x18) = 1;
    M2C_FIELD(&gMKDefaults, s32 *, 0x94) = 0x30;
    M2C_FIELD(&gMKDefaults, s32 *, 0x8C) = 0x400;
    M2C_FIELD(&gMKDefaults, s32 *, 0x98) = 4;
    M2C_FIELD(&gMKDefaults, s32 *, 0x9C) = 0x12C;
    M2C_FIELD(&gMKDefaults, s32 *, 0xA0) = 0x50;
    M2C_FIELD(&gMKDefaults, s32 *, 0xAC) = 0x23A;
    M2C_FIELD(&gMKDefaults, s32 *, 0xDC) = 0x200;
    M2C_FIELD(&gMKDefaults, f32 *, 0x14) = 0.01f;
    M2C_FIELD(&gMKDefaults, s8 **, 0x28) = (s8 *) (lit_stringBase0 + 0x12D);
    strcpy(homeDir, Str_Printf(lit_stringBase0 + 0x132, platformCode, 0x23A, 0x50, 0x12C, 4, 0x30, 1));
    M2C_FIELD(&gMKDefaults, s8 **, 0x2C) = homeDir;
    M2C_FIELD(&gMKDefaults, s32 *, 0x64) = 0x300;
    M2C_FIELD(&gMKDefaults, s32 *, 0x84) = 0x400;
    M2C_FIELD(&gMKDefaults, s32 *, 0x24) = 1;
    gbGoldMaster = 1;
    gpBuildVersion = buildNumber;
    gShowCursor = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_934'
void Game_Draw() {
    s32 sp18;
    f32 sp14;
    s32 sp10;
    f32 spC;
    Tools_Ortho sp8;
    KDSynkerPlayer3 *temp_r3_1671;
    M2C_UNK *temp_r29_1668;
    f32 var_f0_1644;
    f32 var_f0_1652;
    f32 var_f1_1626;
    u8 temp_r3_1622;
    u8 var_r30_1672;

    temp_r3_1622 = System_IsWideScreenEnabled();
    if (temp_r3_1622 != 0) {
        var_f1_1626 = 1.7777778f;
    } else {
        var_f1_1626 = 1.3333334f;
    }
    MKView_SetAspectRatio(var_f1_1626);
    spC = M2C_FIELD(&lit_934, f32 *, 0);
    sp10 = M2C_FIELD(&lit_934, s32 *, 4);
    sp14 = M2C_FIELD(&lit_934, f32 *, 8);
    sp18 = M2C_FIELD(&lit_934, s32 *, 0xC);
    if (temp_r3_1622 != 0) {
        var_f0_1644 = -108.0f;
    } else {
        var_f0_1644 = 0.0f;
    }
    spC = var_f0_1644;
    if (temp_r3_1622 != 0) {
        var_f0_1652 = 856.0f;
    } else {
        var_f0_1652 = 640.0f;
    }
    sp14 = var_f0_1652;
    MKView_SetOrthoRect((MKRect *) &spC);
    ((GameStateMachine *) ((GameStateMachine *) (gb + 0x490)))->Draw();
    sp8.Tools_Ortho();
    if (((u8) DialogBox_bAllowOverCutscene == 0) && (temp_r29_1668 = gb[3], (((u32) temp_r29_1668 == 0U) == 0))) {
        temp_r3_1671 = M2C_FIELD(temp_r29_1668, KDSynkerPlayer3 **, 0x78);
        var_r30_1672 = 0;
        if (((temp_r3_1671 != NULL) && (temp_r3_1671->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_1668, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) ((KDStateMachine<CutsceneSystem> *) (temp_r29_1668 + 0x24)))->GetState() == 2))) {
            var_r30_1672 = 1;
        }
        if (var_r30_1672 == 0) {
            goto block_17;
        }
    } else {
block_17:
        DialogBox_Draw();
    }
    if ((u8) M2C_FIELD(gb, u8 *, 0x395) == 0) {
        ((GameGlobals::Fade *) ((GameGlobals::Fade *) &gb[0xC]))->Draw();
    }
    if ((u8) M2C_FIELD(gb, u8 *, 0x395) == 0) {
        Credits_Draw();
        ((CutsceneSystem *) ((CutsceneSystem *) (gb + 0x3C0)))->DrawSubtitles();
        Subtitles_Draw();
    }
    sp8.~Tools_Ortho(-1);
}
#endif

#if 0 // DRAFT: pointer/array required
u8 Game_Update() {
    KDSynkerPlayer3 *temp_r3_1785;
    M2C_UNK *temp_r29_1782;
    f32 temp_f31_1729;
    u8 var_r31_1786;

    temp_f31_1729 = gUpdateTimeDelta;
    MKInput_DespatchEvents();
    M2C_FIELD(*gMK, M2C_UNK (**)(void **), 0x20)(gMK);
    ((Level *) ((Level *) gb[0xCB]))->UpdateState();
    gGMState.Update();
    GameSounds_Update();
    if (((u8) M2C_FIELD(gb, u8 *, 0x395) == 0) && ((M2C_UNK *) gb[0xD6] == (M2C_UNK *)-1)) {
        ((TimeDeltaModifier *) ((TimeDeltaModifier *) &gb[0xB3]))->Begin();
        Console_UpdateDelayedCmds();
        ((TimeDeltaModifier *) ((TimeDeltaModifier *) &gb[0xB3]))->End();
    }
    gUpdateTimeDelta = temp_f31_1729;
    if (((u8) M2C_FIELD(gb[0xCB], u8 *, 8) == 0) && ((u8) M2C_FIELD(gb, u8 *, 0x395) == 0)) {
        ((GameGlobals::Fade *) ((GameGlobals::Fade *) &gb[0xC]))->Update();
        ((GameGlobals::KillRate *) ((GameGlobals::KillRate *) &gb[0xBE]))->Update();
    }
    MKRumble_Update();
    if (((u8) DialogBox_bAllowOverCutscene == 0) && (temp_r29_1782 = gb[3], (((u32) temp_r29_1782 == 0U) == 0))) {
        temp_r3_1785 = M2C_FIELD(temp_r29_1782, KDSynkerPlayer3 **, 0x78);
        var_r31_1786 = 0;
        if (((temp_r3_1785 != NULL) && (temp_r3_1785->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_1782, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) ((KDStateMachine<CutsceneSystem> *) (temp_r29_1782 + 0x24)))->GetState() == 2))) {
            var_r31_1786 = 1;
        }
        if (var_r31_1786 == 0) {
            goto block_14;
        }
    } else {
block_14:
        DialogBox_Update();
    }
    if ((u8) M2C_FIELD(gb, u8 *, 0x395) == 0) {
        Credits_Update();
        Subtitles_Update();
    }
    Music_Update();
    PhrasePlayer_Update();
    RumbleTimer_Update();
    if ((u32) gb[0xD5] != 0U) {
        M2C_FIELD(gb[0xD5], s8 *, 5) = 0;
    }
    UIControls_Ignore(0U);
    return bQuit;
}
#endif

#if 0 // DRAFT: illegal operand
void Game_Deinit() {
    Subtitles_DeinitModule();
    ((CutsceneSystem *) ((CutsceneSystem *) (gb + 0x3C0)))->DeinitModule();
    PhrasePlayer_Deinit();
    Music_Deinit();
    Cheats_Deinit();
    EnemySettings_DeinitModule();
    LoadLevel_FreeResources();
    ((GameStateMachine *) ((GameStateMachine *) (gb + 0x490)))->Deinit();
    KDSound_DeinitModule();
    ((GameData *) (M2C_ERROR(/* Read from unset register $r3 */)))->ModuleDeinit();
    ((KDShatter2 *) (M2C_ERROR(/* Read from unset register $r3 */)))->DeinitModule();
    WindPoints_DeinitModule();
    FogPoints_DeinitModule();
    ConsoleCmds_Unregister();
    Console_Deinit();
    gb->Deinit();
    DialogBox_DeinitModule();
    MemoryCard_DeinitModule();
}
#endif

#if 0 // DRAFT: pointer/array required
void Game_Init() {
    KDPropModuleInfo sp8;
    M2C_UNK sp4;
    ChunkInfo *temp_r4_1957;
    Level *var_r3_1950;
    M2C_UNK *var_r3_1978;

    MKMaterial_InitMaterialIDs();
    MKPackage_UseQ();
    DialogBox_InitModule();
    gb->Init();
    Console_Init();
    ConsoleCmds_Register();
    Game_CheckCommandLineParameters();
    M2C_STRUCT_COPY((s32) &sp4 + 4, (s32) (&lit_877 - 4) + 4, 0x18);
    lit_877.GetWorldInfo();
    sp8.unkC = M2C_ERROR(/* Read from unset register $r3 */) + 8;
    KDProp_InitModule(&sp8);
    GameProperties_RegisterAll();
    GameLanguage_InitModule();
    GameVideo_Init(Game_VideoEventCallback);
    UIControls_Init();
    UITools_RegisterAll();
    LoadLevel_LoadResources();
    Subtitles_InitModule();
    FogPoints_InitModule();
    WindPoints_InitModule();
    ((KDShatter2 *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitModule();
    Ball_InitModule();
    Catapult_InitModule();
    BoulderRamp_InitModule();
    SnowBallTree_InitModule();
    SiegeTower_InitModule();
    MKSplineTube_InitModule(3000.0f, 20.0f, 1.5f);
    KDRand_SetSeed(Tools_GetTimeInSeconds());
    ((GameCamera2 *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitModule();
    gb[0xEE] = NULL;
    GameSounds_InitModule();
    gb[0xCC] = NULL;
    if ((M2C_UNK *) gb[0xD0] != NULL) {
        if (((Level *) pStartChunkName == NULL) && ((Level *) pStartLevelName == NULL)) {
            NULL->GetNextLevel(M2C_ERROR(/* Read from unset register $r4 */));
            var_r3_1950 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Level **, 0x11C);
loop_5:
            if (var_r3_1950 != NULL) {
                temp_r4_1957 = var_r3_1950->unk4;
                if ((u8) M2C_FIELD(temp_r4_1957, u8 *, 0x1A) != 0) {
                    var_r3_1950 = var_r3_1950->GetNextChunk(temp_r4_1957);
                    goto loop_5;
                }
            }
            gb[0xCC] = (M2C_UNK *) var_r3_1950;
        } else if ((Level *) pStartChunkName != NULL) {
            gb[0xCC] = pStartChunkName->GetChunkByName(M2C_ERROR(/* Read from unset register $r4 */));
        } else if ((Level *) pStartLevelName != NULL) {
            gb[0xCC] = M2C_FIELD(pStartLevelName->GetLevelByName(M2C_ERROR(/* Read from unset register $r4 */)), M2C_UNK **, 0x11C);
        }
        var_r3_1978 = gb[0xCC];
        if ((s32) M2C_FIELD(var_r3_1978, s32 *, 0xC) == 2) {
            var_r3_1978 = var_r3_1978->GetNextChunk(M2C_ERROR(/* Read from unset register $r4 */));
            gb[0xCC] = var_r3_1978;
        }
    } else if ((Level *) pStartChunkName != NULL) {
        var_r3_1978 = pStartChunkName->GetChunkByName(M2C_ERROR(/* Read from unset register $r4 */));
        gb[0xCC] = var_r3_1978;
        gb[0xCF] = (M2C_UNK *)1;
        M2C_FIELD(gb, s8 *, 0x334) = 1;
    } else if ((Level *) pStartLevelName != NULL) {
        var_r3_1978 = pStartLevelName->GetLevelByName(M2C_ERROR(/* Read from unset register $r4 */));
        gb[0xCC] = M2C_FIELD(var_r3_1978, M2C_UNK **, 0x114);
        gb[0xCF] = (M2C_UNK *)1;
        M2C_FIELD(gb, s8 *, 0x334) = 1;
    } else {
        var_r3_1978 = pStartLevelName->GetStartLevelInfo();
        if ((u32) var_r3_1978 != 0U) {
            gb[0xCC] = M2C_FIELD(var_r3_1978, M2C_UNK **, 0x114);
        }
    }
    var_r3_1978->ModuleInit();
    gameData.GetGameSettings();
    Tools_EnableWideScreen(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x11));
    EnemySettings_InitModule();
    gb->ResetInGameData();
    gb[0xC3] = 0.0f;
    gb[0xC4] = -200.0f;
    gb[0xC5] = 0.72f;
    Cheats_Init();
    Music_Init();
    PhrasePlayer_Init();
    ((CutsceneSystem *) ((CutsceneSystem *) (gb + 0x3C0)))->InitModule();
    gb[3] = &*(gb + 0x3C0);
    ((GameStateMachine *) ((GameStateMachine *) (gb + 0x490)))->Init(gameStates, &gameStateInit);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'GameVideoEvent'
void Game_VideoEventCallback(GameVideoEvent arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<Spyro *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: pointer/array required
void Game_cpp::__sinit() {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f10_2096;
    f64 temp_f1_2100;
    f64 temp_f2_2104;
    f64 temp_f3_2094;
    f64 temp_f3_2117;
    f64 temp_f5_2130;
    f64 temp_f6_2106;
    f64 temp_f6_2115;
    f64 temp_f6_2136;

    temp_f3_2094 = __frsqrte(2014000.0);
    temp_f10_2096 = __frsqrte(380000.0);
    temp_f1_2100 = temp_f3_2094 * temp_f3_2094;
    temp_f2_2104 = temp_f10_2096 * temp_f10_2096;
    temp_f6_2106 = 0.5 * temp_f3_2094;
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    temp_f6_2115 = temp_f6_2106 * -((2014000.0 * temp_f1_2100) - 3.0);
    sp14 = 0.0f;
    temp_f3_2117 = 0.5 * temp_f10_2096 * -((380000.0 * temp_f2_2104) - 3.0);
    M2C_FIELD(&gClearColor, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&gClearColor, f64 *, 8) = (f64) sp10;
    gb[0xC1] = NULL;
    gb[0xC0] = NULL;
    gb[0xBE] = NULL;
    gb[0xBF] = NULL;
    temp_f5_2130 = 0.5 * temp_f6_2115 * -((2014000.0 * (temp_f6_2115 * temp_f6_2115)) - 3.0);
    M2C_FIELD(&cutsceneSys, s32 *, 0x24) = -1;
    M2C_FIELD(&cutsceneSys, s32 *, 0x28) = -1;
    M2C_FIELD(&cutsceneSys, s32 *, 0x2C) = 0;
    temp_f6_2136 = 0.5 * temp_f3_2117 * -((380000.0 * (temp_f3_2117 * temp_f3_2117)) - 3.0);
    M2C_FIELD(&cutsceneSys, s32 *, 0x30) = 0;
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f5_2130 * -((2014000.0 * (temp_f5_2130 * temp_f5_2130)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f6_2136 * -((380000.0 * (temp_f6_2136 * temp_f6_2136)) - 3.0)));
}
#endif
