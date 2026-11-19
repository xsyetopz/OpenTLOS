#include "spyro/source/GameLanguage.h"
#include "unplaced_enums.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Translation.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK);                         /* extern */
extern s32 gDisplay;
static M2C_UNK langAvailable;                       /* unable to generate initializer: unknown type */
static s32 audioTrack[0xD] = { 0, 0, 1, 2, 3, 4, 5, 0, 0, 6, 0, 0, 1 };

s32 GameLanguage_GetPrev(int *arg0, bool arg1) {
    s32 temp_r3_28;

    *arg0 = *arg0 - 1;
loop_2:
    if (arg1 == 0) {
        temp_r3_28 = *arg0;
        if ((temp_r3_28 > -1) && (GameLanguage_Available(temp_r3_28) == 0)) {
            *arg0 -= 1;
            goto loop_2;
        }
    }
    return *arg0 > -1;
}

s32 GameLanguage_GetLast(int *arg0, bool arg1) {
    s32 temp_r3_68;

    *arg0 = 0xC;
loop_2:
    if (arg1 == 0) {
        temp_r3_68 = *arg0;
        if ((temp_r3_68 > -1) && (GameLanguage_Available(temp_r3_68) == 0)) {
            *arg0 -= 1;
            goto loop_2;
        }
    }
    return *arg0 > -1;
}

u8 GameLanguage_GetNext(int *arg0, bool arg1) {
    s32 temp_r3_109;

    *arg0 = *arg0 + 1;
loop_2:
    if (arg1 == 0) {
        temp_r3_109 = *arg0;
        if ((temp_r3_109 < 0xD) && (GameLanguage_Available(temp_r3_109) == 0)) {
            *arg0 += 1;
            goto loop_2;
        }
    }
    return *arg0 < 0xD;
}

u8 GameLanguage_GetFirst(int *arg0, bool arg1) {
    s32 temp_r3_149;

    *arg0 = 0;
loop_2:
    if (arg1 == 0) {
        temp_r3_149 = *arg0;
        if ((temp_r3_149 < 0xD) && (GameLanguage_Available(temp_r3_149) == 0)) {
            *arg0 += 1;
            goto loop_2;
        }
    }
    return *arg0 < 0xD;
}

void GameLanguage_GetAudioCode(int arg0) {
    GameLanguage_GetCode(arg0);
}

s32 GameLanguage_GetAudioTrack(int arg0) {
    s32 var_r3_0;

    var_r3_0 = arg0;
    if (var_r3_0 == -1) {
        var_r3_0 = Translation_GetLanguage();
    }
    return audioTrack[var_r3_0];
}

void GameLanguage_GetName(int arg0) {
    s32 var_r3_0;

    var_r3_0 = arg0;
    if (var_r3_0 == -1) {
        var_r3_0 = Translation_GetLanguage();
    }
    Translation_GetLanguageLocalName((TranslationLanguage) var_r3_0);
}

void GameLanguage_GetCode(int arg0) {
    s32 var_r3_0;

    var_r3_0 = arg0;
    if (var_r3_0 == -1) {
        var_r3_0 = Translation_GetLanguage();
    }
    Translation_GetLanguageCode((TranslationLanguage) var_r3_0);
}

#if 0 // DRAFT: function call 'stricmp(const char *, int)' does not match
s32 GameLanguage_LanguageByCode(const char *arg0) {
    s32 var_r31_245;

    var_r31_245 = 0;
loop_1:
    Translation_GetLanguageCode((TranslationLanguage) var_r31_245);
    if (stricmp(arg0, M2C_ERROR(/* Read from unset register $r3 */)) == 0) {
        return var_r31_245;
    }
    var_r31_245 += 1;
    if (var_r31_245 >= 0xD) {
        return -1;
    }
    goto loop_1;
}
#endif

s32 GameLanguage_Count() {
    s32 sp8;
    s32 var_r31_278;

    var_r31_278 = 0;
    if (GameLanguage_GetFirst((int *) &sp8, 0) != 0) {
        do {
            var_r31_278 += 1;
        } while (GameLanguage_GetNext((int *) &sp8, 0) != 0);
    }
    return var_r31_278;
}

u8 GameLanguage_Available(int arg0) {
    s32 var_r30_305;
    u8 var_r31_312;

    var_r30_305 = arg0;
    if (var_r30_305 == -1) {
        var_r30_305 = Translation_GetLanguage();
    }
    var_r31_312 = 0;
    if ((Translation_IsLanguageAvailable((TranslationLanguage) var_r30_305) != 0) && ((u8) *(&langAvailable + var_r30_305) != 0)) {
        var_r31_312 = 1;
    }
    return var_r31_312;
}

void GameLanguage_Set(int arg0) {
    Translation_SetLanguage((TranslationLanguage) arg0);
}

s32 GameLanguage_GetDefault() {
    if ((s32) gDisplay == 1) {
        return 0;
    }
    return Translation_GetDefaultLanguage();
}

void GameLanguage_Get() {
    Translation_GetLanguage();
}

void GameLanguage_InitModule() {
    s32 temp_r3_394;
    s32 var_r31_387;

    var_r31_387 = GameLanguage_GetDefault();
    System_GetCommandLineParameter("lang", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        temp_r3_394 = GameLanguage_LanguageByCode(M2C_ERROR(/* Read from unset register $r3 */));
        var_r31_387 = temp_r3_394;
        if ((var_r31_387 > -1) && (GameLanguage_Available(temp_r3_394) == 0)) {
            var_r31_387 = -1;
        }
    }
    Translation_SetLanguage((TranslationLanguage) var_r31_387);
}
