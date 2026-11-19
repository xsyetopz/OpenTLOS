#include "common/Source/DiscErrors.h"
#include "dolphin/os.h"
#include "dolphin/vi.h"
#include "common/Source/GPInit.h"
#include "common/Source/MKInput.h"
#include "common/Source/Translation.h"
#include "common/Source/xFont.h"
#include <m2c_macros.h>

M2C_UNK strupr(s8 *);                               /* extern */
extern M2C_UNK gGameCubeDiscErrors;
static s32 nCurrErr = -1;

#if 0 // DRAFT: function call 'strlen(signed char *)' does not match 'strlen(const char *)'
void DiscErr_DrawString(char *arg0) {
    s8 sp8;
    s16 var_r29_27;
    s32 temp_r3_30;
    s8 *temp_r3_59;
    s8 *var_r30_35;
    s8 *var_r31_20;
    u32 temp_r26_66;
    u32 temp_ret_76;
    u8 temp_r4_43;
    u8 temp_r5_41;

    MKInput_Update();
    VIWaitForRetrace();
    XFONTClearScreen(7U);
    var_r31_20 = (signed char *) (arg0);
    var_r29_27 = 0xB - (strlen(arg0) / 48);
loop_1:
    temp_r3_30 = strlen(var_r31_20);
    if (temp_r3_30 > 0x18) {
        var_r30_35 = var_r31_20 + 0x18;
loop_4:
        temp_r5_41 = (u8) *var_r30_35;
        temp_r4_43 = *(&__ctype_map + temp_r5_41);
        if ((temp_r4_43 & 0xD0) || (temp_r4_43 & 8) || (temp_r5_41 > 0xC0U)) {
            if (var_r30_35 <= var_r31_20) {

            } else {
                var_r30_35 -= 1;
                goto loop_4;
            }
        }
    } else {
        var_r30_35 = &var_r31_20[temp_r3_30];
    }
    temp_r3_59 = strchr(var_r31_20, 0xA);
    if ((temp_r3_59 != NULL) && (temp_r3_59 < var_r30_35)) {
        var_r30_35 = temp_r3_59;
    }
    temp_r26_66 = var_r30_35 - var_r31_20;
    strncpy(&sp8, var_r31_20, temp_r26_66);
    (&sp8)[temp_r26_66] = 0;
    strupr(&sp8);
    temp_ret_76 = strlen(&sp8);
    XFONTPrintf((s16) (0x14 - (temp_ret_76 / 2)), var_r29_27, &sp8, M2C_BITWISE(f32, temp_ret_76));
    if (&var_r31_20[temp_r3_30] > var_r30_35) {
        var_r31_20 = var_r30_35 + 1;
        var_r29_27 += 2;
        if ((var_r31_20 != NULL) && ((s8) M2C_FIELD(var_r30_35, u8 *, 1) != 0)) {
            goto loop_1;
        }
    }
    GPGetCurrentBuffer();
    DCFlushRange(M2C_ERROR(/* Read from unset register $r3 */), 0xA5000U);
}
#endif

#if 0 // DRAFT: function call 'DiscErr_DrawString(signed char *)' does not match 'DiscErr_DrawString(char *)'
void DiscErr_DrawErrorString() {
    DiscErr_DrawString(DiscErr_GetErrorString());
}
#endif

s8 *DiscErr_GetErrorString() {
    s32 var_r31_139;
    u8 temp_r3_140;

    if (((s32) nCurrErr <= -1) || ((s32) nCurrErr > 5)) {
        return NULL;
    }
    if (Translation_GetLanguage() == -1) {
        var_r31_139 = 0;
        temp_r3_140 = OSGetLanguage();
        switch ((s32) temp_r3_140) {                /* irregular */
        case 0:
            var_r31_139 = 0;
            break;
        case 1:
            var_r31_139 = 4;
            break;
        case 2:
            var_r31_139 = 2;
            break;
        case 3:
            var_r31_139 = 3;
            break;
        case 4:
            var_r31_139 = 5;
            break;
        case 5:
            var_r31_139 = 6;
            break;
        }
        return (signed char *) (*(&gGameCubeDiscErrors + (var_r31_139 * 0x14) + (nCurrErr * 4)));
    }
    return (signed char *) (*(&gGameCubeDiscErrors + (Translation_GetLanguage() * 0x14) + (nCurrErr * 4)));
}

void DiscErr_ClearError() {
    nCurrErr = -1;
}

s32 DiscErr_IsError() {
    return nCurrErr != -1;
}

void DiscErr_SetError(int arg0) {
    nCurrErr = arg0;
}
