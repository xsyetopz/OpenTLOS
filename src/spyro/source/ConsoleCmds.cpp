#include "spyro/source/ConsoleCmds.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/Level.h"
#include "spyro/source/MessageMap.h"
#include "unplaced_enums.h"
#include "common/Source/Debug.h"
#include "common/Source/MKRumble.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/gc/Sound_GC.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/GameConsole.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/InGame.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'ConsoleCmds_pSenderProp' redeclared
f64 atof(u8 *, f32);                                /* extern */
MKSceneManager *atoi(u8 *);                         /* extern */
s32 sscanf(s8 *, f32 *, f32 *);                     /* extern */
s32 stricmp(s8 *, u8 *);                            /* extern */
extern s32 ConsoleCmds_pSenderProp;
#endif
extern GameStateMachine gGMState;
#if 0 // DRAFT: identifier 'gb' redeclared
extern void **gb;
#endif
extern MessageMap globalMessageMap;
static ConVar cmds[2];                              /* extra bytes: 0x16C; unable to generate initializer: cannot parse CmdMenu__FiPPc as integer */

static s32 lit_750 = 0;
static s32 lit_752 = 2;
static s32 lit_765 = 0;
static s32 lit_767 = 2;

static u8 lit_stringBase0[5] = { 0x6D, 0x65, 0x6E, 0x75, 0 }; /* const */

void ConsoleCmds_Unregister() {
    Console_Unregister(cmds, 0x30);
}

void ConsoleCmds_Register() {
    Console_Register(cmds, 0x30);
}

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdMenuVideo(int arg0, char **arg1) {
    if (arg0 < 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x212), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0) == 0) {
        FrontEnd_PlayBackgroundVideo(1U);
    } else {
        FrontEnd_PlayVideo(M2C_FIELD(arg1, s8 **, 4));
    }
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdAutosave(int arg0, char **arg1) {
    if (arg0 < 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x228), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    ((GameData *) ((GameData *) GameData::gameData))->SetSaveChunk(((Level *) (M2C_FIELD(arg1, Level **, 4)))->GetChunkByName((s8 *) arg1));
    Autosave_Activate();
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdCamShake(int arg0, char **arg1) {
    s8 sp40;
    f64 sp38;
    f64 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_138;
    f32 temp_f1_143;
    f32 temp_f1_148;

    if (arg0 < 4) {
        Console_Print((s8 *) (lit_stringBase0 + 0x23E), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    temp_f1_138 = (f32) atof(M2C_FIELD(arg1, u8 **, 0xC));
    temp_f1_143 = (f32) atof(M2C_FIELD(arg1, u8 **, 8), temp_f1_138);
    temp_f1_148 = (f32) atof(M2C_FIELD(arg1, u8 **, 4), temp_f1_143);
    sp10 = 100.0f * temp_f1_138;
    spC = 100.0f * temp_f1_143;
    sp8 = 100.0f * temp_f1_148;
    sp2C = 0;
    sp28 = 0x417;
    sp30 = (f64) sp8;
    sp38 = (f64) sp10;
    sp40 = 1;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, M2C_UNK, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp28, 0x417, 0, (f64) sp8);
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, int)' does not
void CmdLangGetStr(char *arg0, int arg1) {
    GameLanguage_GetName(-1);
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x25C), M2C_ERROR(/* Read from unset register $r3 */));
}
#endif

#if 0 // DRAFT: function call 'GameLanguage_LanguageByCode(signed char *)' does not match
f32 CmdLang(int arg0, char **arg1) {
    s32 temp_r3_276;
    s32 var_r30_240;
    s32 var_r30_259;
    s32 var_r31_224;
    s8 *temp_r3_235;
    u8 temp_r0_236;
    u8 temp_ret_280;

    GameLanguage_Get();
    var_r31_224 = M2C_ERROR(/* Read from unset register $r3 */);
    if (arg0 < 2) {
        return (f32) var_r31_224;
    }
    temp_r3_235 = M2C_FIELD(arg1, s8 **, 4);
    temp_r0_236 = *temp_r3_235;
    if ((s8) temp_r0_236 == 0x2B) {
        var_r30_240 = var_r31_224 + 1;
loop_5:
        if ((GameLanguage_Available(var_r30_240) == 0) && (var_r30_240 != var_r31_224)) {
            var_r30_240 += 1;
            goto loop_5;
        }
        var_r31_224 = var_r30_240;
        GameLanguage_Set(var_r30_240);
        goto block_18;
    }
    if ((s8) temp_r0_236 == 0x2D) {
        var_r30_259 = var_r31_224 - 1;
loop_11:
        if ((GameLanguage_Available(var_r30_259) == 0) && (var_r30_259 != var_r31_224)) {
            var_r30_259 -= 1;
            goto loop_11;
        }
        var_r31_224 = var_r30_259;
        GameLanguage_Set(var_r30_259);
        goto block_18;
    }
    temp_r3_276 = GameLanguage_LanguageByCode(temp_r3_235);
    if (temp_r3_276 > -1) {
        temp_ret_280 = GameLanguage_Available(temp_r3_276);
        if (temp_ret_280 != 0) {
            GameLanguage_Set(temp_r3_276);
            return (f32) temp_r3_276;
        }
        Console_Print((s8 *) (lit_stringBase0 + 0x25F), M2C_FIELD(arg1, s8 **, 0), M2C_FIELD(arg1, s8 **, 4), M2C_BITWISE(f32, temp_ret_280));
        return 0.0f;
    }
block_18:
    Console_Print((s8 *) (lit_stringBase0 + 0x283), M2C_FIELD(arg1, s8 **, 0), M2C_FIELD(arg1, s8 **, 4));
    return (f32) var_r31_224;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdFade(int arg0, char **arg1) {
    if (arg0 < 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x2A3), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x2B9) == 0) {
        ((GameGlobals::Fade *) ((GameGlobals::Fade *) (&gb + 0x30)))->FadeIn(NULL);
        goto block_7;
    }
    if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x2BC) == 0) {
        ((GameGlobals::Fade *) ((GameGlobals::Fade *) (&gb + 0x30)))->FadeOut(NULL);
block_7:
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, char *)' does not match
f32 CmdHoldBlank(int arg0, char **arg1) {
    if (arg0 > 1) {
        Console_Print((s8 *) (lit_stringBase0 + 0x2C0), *arg1);
        return 0.0f;
    }
    M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s8 *, 0xA9) = 1;
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdPlayThrough(int arg0, char **arg1) {
    MKSceneManager *temp_r3_433;

    if (arg0 < 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x2A3), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    temp_r3_433 = atoi(M2C_FIELD(arg1, u8 **, 4));
    GameData::gameData[0x18A] = (GameData::gameData[0x18A] & ~0x40) | (((temp_r3_433 != NULL) << 6) & 0x40);
    M2C_FIELD(GameData::gameData, s32 *, 0x3C) = (s32) (temp_r3_433 != NULL);
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdGameState(int arg0, char **arg1) {
    if (arg0 < 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x2A3), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x2CD) == 0) {
        gGMState.SwitchState(6, 1, 0U);
    } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0) == 0) {
        ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SwitchTo(NULL);
    }
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char[5],
void CmdSlowMoKillBlowSpeedGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), lit_stringBase0, M2C_FIELD(&gb, f32 *, 0x388));
}
#endif

#if 0 // DRAFT: function call 'sscanf(signed char *, float *)' does not match
f32 CmdSlowMoKillBlowSpeed(int arg0, char **arg1) {
    f32 spC;
    f32 sp8;
    f32 var_f0_559;
    f32 var_f0_585;
    u8 temp_r0_541;

    spC = M2C_FIELD(&gb, f32 *, 0x388);
    if (arg0 > 1) {
        temp_r0_541 = *M2C_FIELD(arg1, u8 **, 4);
        if (((s8) temp_r0_541 == 0x2B) || ((s8) temp_r0_541 == 0x2D)) {
            if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
                var_f0_559 = spC + sp8;
                if (var_f0_559 < 1.0f) {

                } else {
                    var_f0_559 = 1.0f;
                }
                if (var_f0_559 > 0.0f) {

                } else {
                    var_f0_559 = 0.0f;
                }
                spC = var_f0_559;
                M2C_FIELD(&gb, f32 *, 0x388) = var_f0_559;
            }
        } else if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &spC) == 1) {
            var_f0_585 = spC;
            if (var_f0_585 < 1.0f) {

            } else {
                var_f0_585 = 1.0f;
            }
            if (var_f0_585 > 0.0f) {

            } else {
                var_f0_585 = 0.0f;
            }
            spC = var_f0_585;
            M2C_FIELD(&gb, f32 *, 0x388) = var_f0_585;
        }
    }
    return spC;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char[5],
void CmdSlowMoSpeedGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), lit_stringBase0, M2C_FIELD(&gb, f32 *, 0x384));
}
#endif

#if 0 // DRAFT: function call 'sscanf(signed char *, float *)' does not match
f32 CmdSlowMoSpeed(int arg0, char **arg1) {
    f32 spC;
    f32 sp8;
    f32 var_f0_663;
    f32 var_f0_689;
    u8 temp_r0_645;

    spC = M2C_FIELD(&gb, f32 *, 0x384);
    if (arg0 > 1) {
        temp_r0_645 = *M2C_FIELD(arg1, u8 **, 4);
        if (((s8) temp_r0_645 == 0x2B) || ((s8) temp_r0_645 == 0x2D)) {
            if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
                var_f0_663 = spC + sp8;
                if (var_f0_663 < 1.0f) {

                } else {
                    var_f0_663 = 1.0f;
                }
                if (var_f0_663 > 0.0f) {

                } else {
                    var_f0_663 = 0.0f;
                }
                spC = var_f0_663;
                M2C_FIELD(&gb, f32 *, 0x384) = var_f0_663;
            }
        } else if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &spC) == 1) {
            var_f0_689 = spC;
            if (var_f0_689 < 1.0f) {

            } else {
                var_f0_689 = 1.0f;
            }
            if (var_f0_689 > 0.0f) {

            } else {
                var_f0_689 = 0.0f;
            }
            spC = var_f0_689;
            M2C_FIELD(&gb, f32 *, 0x384) = var_f0_689;
        }
    }
    return spC;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char[5],
void CmdSlowMoChanceGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), lit_stringBase0, M2C_FIELD(GameData::gameData, f32 *, 0x40));
}
#endif

#if 0 // DRAFT: function call 'sscanf(signed char *, float *)' does not match
f32 CmdSlowMoChance(int arg0, char **arg1) {
    f32 spC;
    f32 sp8;
    f32 var_f0_767;
    f32 var_f0_793;
    u8 temp_r0_749;

    spC = M2C_FIELD(GameData::gameData, f32 *, 0x40);
    if (arg0 > 1) {
        temp_r0_749 = *M2C_FIELD(arg1, u8 **, 4);
        if (((s8) temp_r0_749 == 0x2B) || ((s8) temp_r0_749 == 0x2D)) {
            if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
                var_f0_767 = spC + sp8;
                if (var_f0_767 < 1.0f) {

                } else {
                    var_f0_767 = 1.0f;
                }
                if (var_f0_767 > 0.0f) {

                } else {
                    var_f0_767 = 0.0f;
                }
                spC = var_f0_767;
                M2C_FIELD(GameData::gameData, f32 *, 0x40) = var_f0_767;
            }
        } else if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &spC) == 1) {
            var_f0_793 = spC;
            if (var_f0_793 < 1.0f) {

            } else {
                var_f0_793 = 1.0f;
            }
            if (var_f0_793 > 0.0f) {

            } else {
                var_f0_793 = 0.0f;
            }
            spC = var_f0_793;
            M2C_FIELD(GameData::gameData, f32 *, 0x40) = var_f0_793;
        }
    }
    return spC;
}
#endif

#if 0 // DRAFT: undefined identifier 'GetBreathType'
f32 CmdDojoLesson(int arg0, char **arg1) {
    if (arg0 == 1) {
        return (f32) M2C_FIELD(GameData::gameData, s32 *, 0x18C);
    }
    M2C_FIELD(GameData::gameData, s32 *, 0x18C) = GetBreathType(M2C_FIELD(arg1, s8 **, 4));
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdTeleport(int arg0, char **arg1) {
    s8 sp4A;
    s8 sp49;
    s8 sp48;
    s8 sp44;
    f32 sp40;
    f64 sp38;
    f64 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKSceneManager *temp_ret_876;
    f32 temp_f1_898;
    f32 temp_f2_909;
    f32 temp_f30_892;
    f32 temp_f31_895;
    void *temp_r3_877;
    void *temp_ret_877;

    if (arg0 < 6) {
        Console_Print((s8 *) (lit_stringBase0 + 0x2DD), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    temp_ret_876 = atoi(M2C_FIELD(arg1, u8 **, 4));
    temp_ret_877 = temp_ret_876->PropResolver_Resolve((s32) (u32) (u64) temp_ret_876);
    temp_r3_877 = temp_ret_877;
    if (temp_r3_877 == NULL) {
        Console_Print((s8 *) (lit_stringBase0 + 0x30E), M2C_FIELD(arg1, s8 **, 0), M2C_FIELD(arg1, u8 **, 4), M2C_BITWISE(f32, temp_ret_877));
        return 0.0f;
    }
    temp_f30_892 = (f32) atof(M2C_FIELD(arg1, u8 **, 0x10));
    temp_f31_895 = (f32) atof(M2C_FIELD(arg1, u8 **, 0xC));
    temp_f1_898 = (f32) atof(M2C_FIELD(arg1, u8 **, 8));
    sp10 = temp_f30_892;
    sp8 = temp_f1_898;
    spC = temp_f31_895;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    temp_f2_909 = (f32) atof(M2C_FIELD(arg1, u8 **, 0x14), (f32) (f64) sp8);
    sp49 = 1;
    sp2C = 0;
    sp28 = 0xE;
    sp30 = (f64) sp8;
    sp38 = (f64) sp10;
    sp40 = temp_f2_909;
    sp44 = 0;
    sp48 = 0;
    sp4A = 1;
    sp49 = 1;
    M2C_FIELD(M2C_FIELD(temp_r3_877, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, M2C_UNK, f64, f32), 0x2C)(temp_r3_877, &sp28, 0xE, 0, (f64) sp8, temp_f2_909);
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, char *)' does not match
f32 CmdHeroActive(int arg0, char **arg1) {
    if (arg0 > 1) {
        Console_Print((s8 *) (lit_stringBase0 + 0x332), *arg1);
        return 0.0f;
    }
    if (M2C_FIELD(*gb, u8 (**)(void **), 0x4C)(gb) != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, char *)' does not match
f32 CmdHeroAlive(int arg0, char **arg1) {
    if (arg0 > 1) {
        Console_Print((s8 *) (lit_stringBase0 + 0x332), *arg1);
        return 0.0f;
    }
    if (M2C_FIELD(*gb, u8 (**)(void **), 0x54)(gb) != 0) {
        return 0.0f;
    }
    return 1.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'char **' to
f32 CmdChunkLoad(int arg0, char **arg1) {
    ChunkInfo *sp8;
    Level *temp_r29_1072;
    f32 temp_f1_1047;
    s32 temp_r30_1040;
    s32 var_r28_1041;
    s32 var_r31_1042;
    s8 **temp_r27_1025;
    s8 **var_r4_0;
    u8 var_r3_1084;
    void *temp_r3_1047;
    void *temp_r4_1090;
    void *temp_ret_1047;

    var_r4_0 = arg1;
    temp_r27_1025 = var_r4_0;
    if ((arg0 < 2) || (arg0 > 4)) {
        Console_Print((s8 *) (lit_stringBase0 + 0x33E), *temp_r27_1025);
        return 0.0f;
    }
    temp_r30_1040 = arg0 - 1;
    var_r28_1041 = 0;
    var_r31_1042 = 0;
loop_7:
    if (var_r28_1041 >= temp_r30_1040) {
        temp_r29_1072 = M2C_FIELD(&gb, Level **, 0x32C);
        temp_r29_1072->unk8 = temp_r29_1072->SetDesiredChunks(&sp8, temp_r30_1040) == 0;
        if ((u8) M2C_FIELD(&gb, Level **, 0x32C)->unk8 != 0) {
            var_r3_1084 = 0;
            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u8 *, 0xAA) != 0) || ((temp_r4_1090 = M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), void **, 0x68), ((temp_r4_1090 == NULL) == 0)) && ((u8) M2C_FIELD(temp_r4_1090, u8 *, 0x5D) != 0))) {
                var_r3_1084 = 1;
            }
            if (var_r3_1084 == 0) {
                M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s8 *, 0xA9) = 0;
                Music_Pause(1U);
            }
        }
        if ((u8) M2C_FIELD(&gb, Level **, 0x32C)->unk8 != 0) {
            return 0.0f;
        }
        return 1.0f;
    }
    temp_ret_1047 = ((Level *) (*(temp_r27_1025 + (var_r31_1042 + 4))))->GetChunkByName((s8 *) var_r4_0);
    temp_f1_1047 = M2C_BITWISE(f32, temp_ret_1047);
    temp_r3_1047 = temp_ret_1047;
    var_r4_0 = (s8 **) (u32) (u64) temp_ret_1047;
    *(&sp8 + var_r31_1042) = temp_r3_1047;
    if ((u32) *(&sp8 + var_r31_1042) == 0U) {
        Console_Print((s8 *) (lit_stringBase0 + 0x367), *temp_r27_1025, M2C_FIELD((temp_r27_1025 + var_r31_1042), s32 *, 4), lit_stringBase0, temp_f1_1047);
        return 0.0f;
    }
    var_r28_1041 += 1;
    var_r31_1042 += 4;
    goto loop_7;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char[5],
void CmdStatFuryGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), lit_stringBase0, M2C_FIELD(GameData::gameData, f32 *, 0xB8));
}
#endif

#if 0 // DRAFT: undefined identifier 'StatAccessor'
void CmdStatFury(int arg0, char **arg1) {
    StatAccessor(arg0, arg1, (Stat *) &GameData::gameData[0xB8]);
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char[5],
void CmdStatMagicGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), lit_stringBase0, M2C_FIELD(GameData::gameData, f32 *, 0xA0));
}
#endif

#if 0 // DRAFT: undefined identifier 'StatAccessor'
void CmdStatMagic(int arg0, char **arg1) {
    StatAccessor(arg0, arg1, (Stat *) &GameData::gameData[0xA0]);
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char[5],
void CmdStatSpiritGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), lit_stringBase0, M2C_FIELD(GameData::gameData, f32 *, 0x88));
}
#endif

#if 0 // DRAFT: undefined identifier 'StatAccessor'
void CmdStatSpirit(int arg0, char **arg1) {
    StatAccessor(arg0, arg1, (Stat *) &GameData::gameData[0x88]);
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char[5],
void CmdStatHealthGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), lit_stringBase0, M2C_FIELD(GameData::gameData, f32 *, 0x70));
}
#endif

#if 0 // DRAFT: undefined identifier 'StatAccessor'
void CmdStatHealth(int arg0, char **arg1) {
    StatAccessor(arg0, arg1, (Stat *) &GameData::gameData[0x70]);
}
#endif

#if 0 // DRAFT: function call 'sscanf(signed char *, float *)' does not match
f32 StatAccessor(int arg0, char **arg1, Stat *arg2) {
    f32 spC;
    f32 sp8;
    u8 temp_r0_1279;

    spC = arg2->unk0;
    if (arg0 > 1) {
        temp_r0_1279 = *M2C_FIELD(arg1, u8 **, 4);
        if (((s8) temp_r0_1279 == 0x2B) || ((s8) temp_r0_1279 == 0x2D)) {
            if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
                arg2->SetValue(spC + sp8, 0U);
            }
        } else if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &spC) == 1) {
            arg2->SetValue(spC, 0U);
        }
    }
    return spC;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdTask(int arg0, char **arg1) {
    MKSceneManager *temp_r31_1346;
    MKSceneManager *temp_r3_1361;
    u8 *temp_r4_1373;
    u8 temp_r0_1363;

    if (arg0 == 1) {
        Console_Print((s8 *) (lit_stringBase0 + 0x37F), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    temp_r31_1346 = atoi(M2C_FIELD(arg1, u8 **, 4));
    if (arg0 == 2) {
        return (f32) M2C_FIELD(&GameData::gameData[temp_r31_1346], u8 *, 0x16A);
    }
    temp_r3_1361 = atoi(M2C_FIELD(arg1, u8 **, 8));
    temp_r0_1363 = *M2C_FIELD(arg1, u8 **, 8);
    if (((s8) temp_r0_1363 == 0x2B) || ((s8) temp_r0_1363 == 0x2D)) {
        temp_r4_1373 = &(&GameData::gameData[0x70])[temp_r31_1346];
        M2C_FIELD(temp_r4_1373, u8 *, 0xFA) = (u8) (temp_r3_1361 + M2C_FIELD(temp_r4_1373, u8 *, 0xFA));
    } else {
        M2C_FIELD(&GameData::gameData[temp_r31_1346], u8 *, 0x16A) = (u8) temp_r3_1361;
    }
    return 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
f32 CmdActionGive(int arg0, char **arg1) {
    s32 temp_r3_1460;
    s32 temp_r3_1466;
    s32 temp_r3_1496;
    s32 temp_r3_1520;
    s32 temp_r4_1465;

    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x39C) == 0)) {
        GameData::gameData[0x168] |= 1;
        goto block_22;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x3A7) == 0)) {
        GameData::gameData[0x168] |= 2;
        goto block_22;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x3B2) == 0)) {
        GameData::gameData[0x168] |= 4;
        goto block_22;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x3B9) == 0)) {
        temp_r3_1460 = GetBreathType(M2C_FIELD(arg1, s8 **, 8));
        temp_r4_1465 = temp_r3_1460;
        temp_r3_1466 = temp_r3_1460 << 5;
        GameData::gameData[0x168] |= 8;
        M2C_FIELD(&(&GameData::gameData[0x70])[temp_r3_1466], s32 *, 0x60) = (s32) (M2C_FIELD(&(&GameData::gameData[0x70])[temp_r3_1466], s32 *, 0x60) | 1);
        ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->SetCurrentBreath((BreathElement) temp_r4_1465);
        ((Stat *) ((Stat *) (&GameData::gameData[0x70] + 0x30)))->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0xA4), 0U);
        goto block_22;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x3C0) == 0)) {
        temp_r3_1496 = (GetBreathType(M2C_FIELD(arg1, s8 **, 8)) << 5) + 0x60;
        GameData::gameData[0x168] |= 8;
        (&GameData::gameData[0x70])[temp_r3_1496] = (s32) ((&GameData::gameData[0x70])[temp_r3_1496] | 2);
        goto block_22;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x3C8) == 0)) {
        temp_r3_1520 = (GetBreathType(M2C_FIELD(arg1, s8 **, 8)) << 5) + 0x60;
        GameData::gameData[0x168] |= 0x10;
        (&GameData::gameData[0x70])[temp_r3_1520] = (s32) ((&GameData::gameData[0x70])[temp_r3_1520] | 8);
        goto block_22;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x3CD) == 0)) {
        GameData::gameData[0x168] |= 0x20;
block_22:
        return 1.0f;
    }
    Console_Print((s8 *) (lit_stringBase0 + 0x3DB), M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
s32 GetBreathType(const char *arg0) {
    s32 var_r3_1616;

    if (stricmp((s8 *) (lit_stringBase0 + 0x42A)) == 0) {
        return 0;
    }
    if (stricmp(arg0, lit_stringBase0 + 0x42F) == 0) {
        return 2;
    }
    if (stricmp(arg0, lit_stringBase0 + 0x433) == 0) {
        return 1;
    }
    if (stricmp(arg0, lit_stringBase0 + 0x438) == 0) {
        return 1;
    }
    var_r3_1616 = -1;
    if (stricmp(arg0, lit_stringBase0 + 0x444) == 0) {
        var_r3_1616 = 3;
    }
    return var_r3_1616;
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
f32 CmdGemGive(int arg0, char **arg1) {
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x44A) == 0)) {
        GameData::gameData[0x169] |= 4;
        goto block_13;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x450) == 0)) {
        GameData::gameData[0x169] |= 2;
        goto block_13;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x3C8) == 0)) {
        GameData::gameData[0x169] |= 8;
        goto block_13;
    }
    if ((arg0 > 1) && (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x457) == 0)) {
        GameData::gameData[0x169] |= 1;
block_13:
        return 1.0f;
    }
    Console_Print((s8 *) (lit_stringBase0 + 0x45E), M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

f32 CmdMusicResume(int arg0, char **arg1) {
    Music_Resume();
    return 1.0f;
}

f32 CmdMusicPause(int arg0, char **arg1) {
    Music_Pause(1U);
    return 1.0f;
}

#if 0 // DRAFT: function call 'Console_Print(signed char *, char *)' does not match
f32 CmdMusicStop(int arg0, char **arg1) {
    if (arg0 != 1) {
        Console_Print((s8 *) (lit_stringBase0 + 0x332), *arg1);
        return 0.0f;
    }
    Music_Stop(-1.0f);
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdMusicPlay(int arg0, char **arg1) {
    f32 var_f1_1802;
    s32 temp_ret_1802;
    s32 temp_ret_1808;
    s32 var_r31_1803;

    if (arg0 < 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x487), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    if (arg0 > 2) {
        temp_ret_1802 = Music_Play(M2C_FIELD(arg1, s8 **, 4), stricmp(M2C_FIELD(arg1, s8 **, 8), lit_stringBase0 + 0x4A5) != 0);
        var_f1_1802 = M2C_BITWISE(f32, temp_ret_1802);
        var_r31_1803 = temp_ret_1802;
    } else {
        temp_ret_1808 = Music_Play(M2C_FIELD(arg1, s8 **, 4), 1U);
        var_f1_1802 = M2C_BITWISE(f32, temp_ret_1808);
        var_r31_1803 = temp_ret_1808;
    }
    if ((u8) var_r31_1803 == 0) {
        Console_Print((s8 *) (lit_stringBase0 + 0x4AB), M2C_FIELD(arg1, s8 **, 4), var_f1_1802);
    }
    if ((u8) var_r31_1803 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdPhrasePlay(int arg0, char **arg1) {
    s32 temp_r3_1854;
    s32 temp_ret_1854;

    if (arg0 != 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x4CC), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    temp_ret_1854 = PhrasePlayer_PlayEvent(M2C_FIELD(arg1, s8 **, 4));
    temp_r3_1854 = temp_ret_1854;
    if (temp_r3_1854 == 0) {
        Console_Print((s8 *) (lit_stringBase0 + 0x4E8), M2C_FIELD(arg1, s8 **, 4), M2C_BITWISE(f32, temp_ret_1854));
    }
    if (temp_r3_1854 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

f32 CmdSoundStopAll(int arg0, char **arg1) {
    KDSound_StopAll();
    return 1.0f;
}

f32 CmdSoundResumeAll(int arg0, char **arg1) {
    KDSound_PauseAll(0U);
    return 1.0f;
}

f32 CmdSoundPauseAll(int arg0, char **arg1) {
    KDSound_PauseAll(1U);
    return 1.0f;
}

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdSoundPlay(int arg0, char **arg1) {
    f32 sp30;                                       /* compiler-managed */
    f32 sp2C;
    f32 sp28;                                       /* compiler-managed */
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKSceneManager *temp_ret_1984;
    f32 temp_f1_1953;
    f32 temp_f1_2018;
    f32 temp_f30_2012;
    f32 temp_f31_2015;
    s32 temp_r3_1953;
    s32 temp_ret_1953;
    s32 temp_ret_2029;
    s32 var_r30_1947;
    u32 temp_r4_1988;
    void *temp_r3_1985;
    void *temp_ret_1985;

    if (arg0 < 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x509), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    var_r30_1947 = 0;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    temp_ret_1953 = KDSound_ResolveSound(M2C_FIELD(arg1, s8 **, 4), NULL);
    temp_f1_1953 = M2C_BITWISE(f32, temp_ret_1953);
    temp_r3_1953 = temp_ret_1953;
    if (temp_r3_1953 == 0) {
        Console_Print((s8 *) (lit_stringBase0 + 0x535), M2C_FIELD(arg1, s8 **, 4), temp_f1_1953);
        return 0.0f;
    }
    switch (arg0) {                                 /* irregular */
    case 2:
        var_r30_1947 = KDSound_Play(temp_r3_1953, 0U, -1);
        break;
    case 3:
        temp_ret_1984 = atoi(M2C_FIELD(arg1, u8 **, 8));
        temp_ret_1985 = temp_ret_1984->PropResolver_Resolve((s32) (u32) (u64) temp_ret_1984);
        temp_r3_1985 = temp_ret_1985;
        if ((temp_r3_1985 != NULL) && (temp_r4_1988 = M2C_FIELD(temp_r3_1985, u32 *, 8), ((temp_r4_1988 == 0U) == 0))) {
            var_r30_1947 = KDSound_Play3d(temp_r3_1953, temp_r4_1988 + 0x30, 0U, -1, 0.0f, 0U);
        } else {
            Console_Print((s8 *) (lit_stringBase0 + 0x572), M2C_FIELD(arg1, u8 **, 8), M2C_FIELD(arg1, s8 **, 0), M2C_BITWISE(f32, temp_ret_1985));
        }
        break;
    case 5:
        temp_f30_2012 = (f32) atof(M2C_FIELD(arg1, u8 **, 0x10));
        temp_f31_2015 = (f32) atof(M2C_FIELD(arg1, u8 **, 0xC));
        temp_f1_2018 = (f32) atof(M2C_FIELD(arg1, u8 **, 8));
        sp10 = temp_f30_2012;
        sp8 = temp_f1_2018;
        spC = temp_f31_2015;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        sp28 = (f64) sp8;
        sp30 = (f64) sp10;
        temp_ret_2029 = ValidateVector(*((MKVector3 *) &sp28));
        if (temp_ret_2029 != 0) {
            var_r30_1947 = KDSound_Play3d(temp_r3_1953, (MKVector3 *) &sp28, 0U, -1, 0.0f, 0U);
        } else {
            Console_Print((s8 *) (lit_stringBase0 + 0x5D4), M2C_FIELD(arg1, s8 **, 0), M2C_FIELD(arg1, u8 **, 8), M2C_FIELD(arg1, u8 **, 0xC), M2C_FIELD(arg1, u8 **, 0x10), M2C_BITWISE(f32, temp_ret_2029));
        }
        break;
    default:
    case 4:
        Console_Print((s8 *) (lit_stringBase0 + 0x61F), (u32) (u64) temp_ret_1953, temp_f1_1953);
        break;
    }
    if (var_r30_1947 == 0) {
        Console_Print((s8 *) (lit_stringBase0 + 0x63D), M2C_FIELD(arg1, s8 **, 4));
    }
    if (var_r30_1947 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdSparx(int arg0, char **arg1) {
    s32 temp_ret_2139;
    s8 var_r0_2112;

    if (arg0 < 1) {
        Console_Print((s8 *) (lit_stringBase0 + 0x65D), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x684) == 0) {
        var_r0_2112 = 1;
        goto block_11;
    }
    if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x687) == 0) {
        var_r0_2112 = 0;
        goto block_11;
    }
    if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x68B) == 0) {
        var_r0_2112 = 1;
        goto block_11;
    }
    temp_ret_2139 = stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x690);
    if (temp_ret_2139 == 0) {
        var_r0_2112 = 0;
block_11:
        M2C_FIELD(&gb, s8 *, 0x35E) = var_r0_2112;
        return 1.0f;
    }
    Console_Print((s8 *) (lit_stringBase0 + 0x65D), M2C_FIELD(arg1, s8 **, 0), M2C_BITWISE(f32, temp_ret_2139));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, char *)' does not match
f32 CmdEnableDisable(int arg0, char **arg1) {
    MKSceneManager *temp_r3_2201;
    MKSceneManager *temp_ret_2201;
    f32 var_f31_2189;
    s32 var_r29_2195;
    s32 var_r31_2197;
    u8 temp_r30_2196;
    void *temp_r3_2204;
    void *temp_ret_2204;

    if (arg0 <= 1) {
        Console_Print((s8 *) (lit_stringBase0 + 0x696), *arg1);
        return 0.0f;
    }
    var_f31_2189 = 1.0f;
    var_r29_2195 = 1;
    temp_r30_2196 = stricmp(*arg1, lit_stringBase0 + 0x8C) == 0;
    var_r31_2197 = 4;
loop_10:
    if (var_r29_2195 < arg0) {
        temp_ret_2201 = atoi(*(arg1 + var_r31_2197));
        temp_r3_2201 = temp_ret_2201;
        if (temp_r3_2201 > 0) {
            temp_ret_2204 = temp_r3_2201->PropResolver_Resolve((s32) (u32) (u64) temp_ret_2201);
            temp_r3_2204 = temp_ret_2204;
            if (temp_r3_2204 != NULL) {
                if (temp_r30_2196 != 0) {
                    M2C_FIELD(M2C_FIELD(temp_r3_2204, void **, 0x44), M2C_UNK (**)(), 0x30)();
                } else {
                    M2C_FIELD(M2C_FIELD(temp_r3_2204, void **, 0x44), M2C_UNK (**)(), 0x34)();
                }
            } else {
                Console_Print((s8 *) (lit_stringBase0 + 0x30E), *arg1, *(arg1 + var_r31_2197), M2C_BITWISE(f32, temp_ret_2204));
                var_f31_2189 = 0.0f;
            }
        }
        var_r29_2195 += 1;
        var_r31_2197 += 4;
        goto loop_10;
    }
    return var_f31_2189;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdSendArg(int arg0, char **arg1) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_r3_2292;
    MKSceneManager *temp_ret_2292;
    f32 var_f31_2269;
    s32 temp_r0_2274;
    s32 temp_r3_2272;
    s32 var_ctr_2282;
    s32 var_r3_2279;
    void *temp_r3_2295;
    void *temp_ret_2295;

    if (arg0 <= 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x6B8), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    var_f31_2269 = 1.0f;
    temp_r3_2272 = globalMessageMap.GetIdFromString(M2C_FIELD(arg1, s8 **, 4));
    temp_r0_2274 = arg0 - 3;
    spC = 0;
    sp8 = temp_r3_2272;
    var_r3_2279 = 0xC;
    spC = ConsoleCmds_pSenderProp;
    sp10 = temp_r0_2274;
    var_ctr_2282 = temp_r0_2274;
    if (arg0 > 3) {
        do {
            *(&sp8 + var_r3_2279) = *(arg1 + var_r3_2279);
            var_r3_2279 += 4;
            var_ctr_2282 -= 1;
        } while (var_ctr_2282 != 0);
    }
    temp_ret_2292 = atoi(M2C_FIELD(arg1, u8 **, 8));
    temp_r3_2292 = temp_ret_2292;
    if (temp_r3_2292 > 0) {
        temp_ret_2295 = temp_r3_2292->PropResolver_Resolve((s32) (u32) (u64) temp_ret_2292);
        temp_r3_2295 = temp_ret_2295;
        if (temp_r3_2295 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_2295, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        } else {
            Console_Print((s8 *) (lit_stringBase0 + 0x30E), M2C_FIELD(arg1, s8 **, 0), M2C_FIELD(arg1, u8 **, 8), M2C_BITWISE(f32, temp_ret_2295));
            var_f31_2269 = 0.0f;
        }
    } else {
        InGame_SystemMessage((MKMessage *) &sp8);
    }
    return var_f31_2269;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdSend(int arg0, char **arg1) {
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_r3_2366;
    MKSceneManager *temp_ret_2366;
    f32 var_f31_2352;
    s32 temp_r3_2355;
    s32 var_r30_2359;
    s32 var_r31_2360;
    void *temp_r3_2369;
    void *temp_ret_2369;

    if (arg0 <= 2) {
        Console_Print((s8 *) (lit_stringBase0 + 0x6E7), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    var_f31_2352 = 1.0f;
    temp_r3_2355 = globalMessageMap.GetIdFromString(M2C_FIELD(arg1, s8 **, 4));
    spC = 0;
    var_r30_2359 = 2;
    var_r31_2360 = 8;
    sp8 = temp_r3_2355;
    spC = ConsoleCmds_pSenderProp;
loop_9:
    if (var_r30_2359 < arg0) {
        temp_ret_2366 = atoi(*(arg1 + var_r31_2360));
        temp_r3_2366 = temp_ret_2366;
        if (temp_r3_2366 > 0) {
            temp_ret_2369 = temp_r3_2366->PropResolver_Resolve((s32) (u32) (u64) temp_ret_2366);
            temp_r3_2369 = temp_ret_2369;
            if (temp_r3_2369 != NULL) {
                M2C_FIELD(M2C_FIELD(temp_r3_2369, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            } else {
                Console_Print((s8 *) (lit_stringBase0 + 0x30E), M2C_FIELD(arg1, s8 **, 0), *(arg1 + var_r31_2360), M2C_BITWISE(f32, temp_ret_2369));
                var_f31_2352 = 0.0f;
            }
        } else {
            InGame_SystemMessage((MKMessage *) &sp8);
        }
        var_r30_2359 += 1;
        var_r31_2360 += 4;
        goto loop_9;
    }
    return var_f31_2352;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char *)'
void CmdCutsceneSubtitlesGetStr(char *arg0, int arg1) {
    u8 *var_r6_2424;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r6_2424 = lit_stringBase0 + 0x690;
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x10) != 0) {
        var_r6_2424 = lit_stringBase0 + 0x68B;
    }
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x25C), var_r6_2424);
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
f32 CmdCutsceneSubtitles(int arg0, char **arg1) {
    f32 sp8;
    u8 var_r31_2455;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r31_2455 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x10);
    if (arg0 > 1) {
        if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x684) == 0) {
            var_r31_2455 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x687) == 0) {
            var_r31_2455 = 0;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x68B) == 0) {
            var_r31_2455 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x690) == 0) {
            var_r31_2455 = 0;
        } else if (sscanf(M2C_FIELD(arg1, s8 **, 4), (f32 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
            var_r31_2455 = sp8 != 0.0f;
        }
        ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x10) = var_r31_2455;
    }
    if (var_r31_2455 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char *,
void CmdScrWideGetStr(char *arg0, int arg1) {
    u8 *var_r6_2545;
    u8 temp_ret_2541;

    temp_ret_2541 = System_IsWideScreenEnabled();
    var_r6_2545 = lit_stringBase0 + 0x690;
    if (temp_ret_2541 != 0) {
        var_r6_2545 = lit_stringBase0 + 0x68B;
    }
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x25C), var_r6_2545, M2C_BITWISE(f32, temp_ret_2541));
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
f32 CmdScrWide(int arg0, char **arg1) {
    f32 sp8;
    u8 var_r31_2574;

    var_r31_2574 = System_IsWideScreenEnabled();
    if (arg0 > 1) {
        if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x684) == 0) {
            var_r31_2574 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x687) == 0) {
            var_r31_2574 = 0;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x68B) == 0) {
            var_r31_2574 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x690) == 0) {
            var_r31_2574 = 0;
        } else if (sscanf(M2C_FIELD(arg1, s8 **, 4), (f32 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
            var_r31_2574 = sp8 != 0.0f;
        }
        Tools_EnableWideScreen(var_r31_2574);
        ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x11) = var_r31_2574;
    }
    if (var_r31_2574 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char *)'
void CmdCamInvertXGetStr(char *arg0, int arg1) {
    u8 *var_r6_2669;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r6_2669 = lit_stringBase0 + 0x690;
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x14) != 0) {
        var_r6_2669 = lit_stringBase0 + 0x68B;
    }
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x25C), var_r6_2669);
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
f32 CmdCamInvertX(int arg0, char **arg1) {
    f32 sp8;
    u8 var_r31_2700;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r31_2700 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x14);
    if (arg0 > 1) {
        if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x684) == 0) {
            var_r31_2700 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x687) == 0) {
            var_r31_2700 = 0;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x68B) == 0) {
            var_r31_2700 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x690) == 0) {
            var_r31_2700 = 0;
        } else if (sscanf(M2C_FIELD(arg1, s8 **, 4), (f32 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
            var_r31_2700 = sp8 != 0.0f;
        }
        ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x14) = var_r31_2700;
    }
    if (var_r31_2700 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char *)'
void CmdSpeedwayInvertYGetStr(char *arg0, int arg1) {
    u8 *var_r6_2793;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r6_2793 = lit_stringBase0 + 0x690;
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x13) != 0) {
        var_r6_2793 = lit_stringBase0 + 0x68B;
    }
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x25C), var_r6_2793);
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
f32 CmdSpeedwayInvertY(int arg0, char **arg1) {
    f32 sp8;
    u8 var_r31_2824;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r31_2824 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x13);
    if (arg0 > 1) {
        if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x684) == 0) {
            var_r31_2824 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x687) == 0) {
            var_r31_2824 = 0;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x68B) == 0) {
            var_r31_2824 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x690) == 0) {
            var_r31_2824 = 0;
        } else if (sscanf(M2C_FIELD(arg1, s8 **, 4), (f32 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
            var_r31_2824 = sp8 != 0.0f;
        }
        ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x13) = var_r31_2824;
    }
    if (var_r31_2824 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *, signed char *)' does not match
f32 CmdInputVibrate(int arg0, char **arg1) {
    f32 temp_f30_2926;
    f32 temp_f31_2929;

    if (arg0 != 4) {
        Console_Print((s8 *) (lit_stringBase0 + 0x715), M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    temp_f30_2926 = (f32) atof(M2C_FIELD(arg1, u8 **, 0xC));
    temp_f31_2929 = (f32) atof(M2C_FIELD(arg1, u8 **, 8));
    ((KDInput *) (M2C_FIELD(&gb, KDInput **, 0x354)))->RumblePlay((f32) atof(M2C_FIELD(arg1, u8 **, 4)), temp_f31_2929, temp_f30_2926, 0, 4.0f, 0U);
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, unsigned char *)'
void CmdInputVibrationGetStr(char *arg0, int arg1) {
    u8 *var_r6_2971;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r6_2971 = lit_stringBase0 + 0x690;
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x12) != 0) {
        var_r6_2971 = lit_stringBase0 + 0x68B;
    }
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x25C), var_r6_2971);
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
f32 CmdInputVibration(int arg0, char **arg1) {
    f32 sp8;
    u8 var_r31_3002;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    var_r31_3002 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x12);
    if (arg0 > 1) {
        if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x684) == 0) {
            var_r31_3002 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x687) == 0) {
            var_r31_3002 = 0;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x68B) == 0) {
            var_r31_3002 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x690) == 0) {
            var_r31_3002 = 0;
        } else if (sscanf(M2C_FIELD(arg1, s8 **, 4), (f32 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
            var_r31_3002 = sp8 != 0.0f;
        }
        ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x12) = var_r31_3002;
        MKRumble_Enable(var_r31_3002);
    }
    if (var_r31_3002 != 0) {
        return 1.0f;
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, float)' does not
void CmdSndModeGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), (f32) Sound_GetSystemAudioMode());
}
#endif

#if 0 // DRAFT: undefined identifier 'sscanf'
f32 CmdSndMode(int arg0, char **arg1) {
    f32 spC;
    f32 sp8;
    s32 temp_r0_3149;
    s32 temp_r0_3154;
    s32 temp_r0_3209;
    s32 var_r0_3159;
    s32 var_r0_3214;
    s32 var_r0_3228;
    s32 var_r31_3123;
    s32 var_r3_3153;
    s32 var_r3_3206;
    u8 temp_r0_3131;

    var_r31_3123 = Sound_GetSystemAudioMode();
    if (arg0 > 1) {
        if (var_r31_3123 == 0) {
            return 1.0f;
        }
        temp_r0_3131 = *M2C_FIELD(arg1, s8 **, 4);
        if (((s8) temp_r0_3131 == 0x2B) || ((s8) temp_r0_3131 == 0x2D)) {
            if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &spC) == 1) {
                temp_r0_3149 = (s32) spC;
                var_r31_3123 += temp_r0_3149;
                if (var_r31_3123 > 2) {
                    var_r3_3153 = lit_752;
                    temp_r0_3154 = var_r31_3123 + temp_r0_3149;
                    if (temp_r0_3154 < var_r3_3153) {
                        var_r3_3153 = temp_r0_3154;
                    }
                    var_r0_3159 = lit_750;
                    if (var_r3_3153 > var_r0_3159) {
                        var_r0_3159 = var_r3_3153;
                    }
                    var_r31_3123 = var_r0_3159;
                }
            }
        } else if (stricmp((s8 *) (lit_stringBase0 + 0x748)) == 0) {
            var_r31_3123 = 0;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x74D) == 0) {
            var_r31_3123 = 1;
        } else if (stricmp(M2C_FIELD(arg1, s8 **, 4), lit_stringBase0 + 0x754) == 0) {
            var_r31_3123 = 2;
        } else if (sscanf(M2C_FIELD(arg1, s8 **, 4), (f32 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
            var_r3_3206 = lit_767;
            temp_r0_3209 = (s32) sp8;
            if (temp_r0_3209 < var_r3_3206) {
                var_r3_3206 = temp_r0_3209;
            }
            var_r0_3214 = lit_765;
            if (var_r3_3206 > var_r0_3214) {
                var_r0_3214 = var_r3_3206;
            }
            var_r31_3123 = var_r0_3214;
        }
        Sound_SetSystemAudioMode(var_r31_3123);
        M2C_FIELD(GameData::gameData, s32 *, 0x4C) = var_r31_3123;
        goto block_25;
    }
block_25:
    var_r0_3228 = 1;
    if (var_r31_3123 != 0) {
        var_r0_3228 = var_r31_3123;
    }
    return (f32) var_r0_3228;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, float)' does not
void CmdSndSoundVolGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), KDSound_GetMasterSoundVolume());
}
#endif

#if 0 // DRAFT: undefined identifier 'sscanf'
f32 CmdSndSoundVol(int arg0, char **arg1) {
    f32 spC;
    f32 sp8;
    f32 var_f1_3305;
    f32 var_f1_3336;
    u8 temp_r0_3287;

    spC = KDSound_GetMasterSoundVolume();
    if (arg0 > 1) {
        temp_r0_3287 = *M2C_FIELD(arg1, u8 **, 4);
        if (((s8) temp_r0_3287 == 0x2B) || ((s8) temp_r0_3287 == 0x2D)) {
            if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
                var_f1_3305 = spC + sp8;
                if (var_f1_3305 < 1.0f) {

                } else {
                    var_f1_3305 = 1.0f;
                }
                if (var_f1_3305 > 0.0f) {

                } else {
                    var_f1_3305 = 0.0f;
                }
                spC = var_f1_3305;
                KDSound_SetMasterSoundVolume(var_f1_3305);
                ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4) = spC;
            }
        } else if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &spC) == 1) {
            var_f1_3336 = spC;
            if (var_f1_3336 < 1.0f) {

            } else {
                var_f1_3336 = 1.0f;
            }
            if (var_f1_3336 > 0.0f) {

            } else {
                var_f1_3336 = 0.0f;
            }
            spC = var_f1_3336;
            KDSound_SetMasterSoundVolume(var_f1_3336);
            ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4) = spC;
        }
    }
    return spC;
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(char *, int, signed char *, float)' does not
void CmdSndMusicVolGetStr(char *arg0, int arg1) {
    Str_snPrintf(arg0, arg1, (s8 *) (lit_stringBase0 + 0x2D4), KDSound_GetMasterMusicVolume());
}
#endif

#if 0 // DRAFT: undefined identifier 'sscanf'
f32 CmdSndMusicVol(int arg0, char **arg1) {
    f32 spC;
    f32 sp8;
    f32 var_f1_3430;
    f32 var_f1_3461;
    u8 temp_r0_3412;

    ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
    spC = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
    if (arg0 > 1) {
        temp_r0_3412 = *M2C_FIELD(arg1, u8 **, 4);
        if (((s8) temp_r0_3412 == 0x2B) || ((s8) temp_r0_3412 == 0x2D)) {
            if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &sp8) == 1) {
                var_f1_3430 = spC + sp8;
                if (var_f1_3430 < 1.0f) {

                } else {
                    var_f1_3430 = 1.0f;
                }
                if (var_f1_3430 > 0.0f) {

                } else {
                    var_f1_3430 = 0.0f;
                }
                spC = var_f1_3430;
                Music_SetMasterVolume(var_f1_3430);
                ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8) = spC;
            }
        } else if (sscanf((s8 *) (lit_stringBase0 + 0x2DA), &spC) == 1) {
            var_f1_3461 = spC;
            if (var_f1_3461 < 1.0f) {

            } else {
                var_f1_3461 = 1.0f;
            }
            if (var_f1_3461 > 0.0f) {

            } else {
                var_f1_3461 = 0.0f;
            }
            spC = var_f1_3461;
            Music_SetMasterVolume(var_f1_3461);
            ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8) = spC;
        }
    }
    return spC;
}
#endif

f32 CmdMenu(int arg0, char **arg1) {
    ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SwitchTo(NULL);
    return 1.0f;
}
