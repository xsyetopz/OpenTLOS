#include "spyro/source/GameConsole.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKWidgetsInternal.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

f64 atof(s8 *);                                     /* extern */
s32 atoi(s8 *);                                     /* extern */
M2C_UNK free(u8 **);                                /* extern */
ConVar *malloc(s32);                                /* extern */
s32 sscanf(s8 *, f32 *, s32 *);                     /* extern */
s32 stricmp(s8 *, s8 *, u8 **);                     /* extern */
extern s32 ConsoleCmds_pSenderProp;
extern u8 bBindEnabled;
extern s32 bCtrlPressed;
extern s8 ***delayCmdData;
extern MKHeap gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern ConCmd *pCommands;
extern u8 **pKeyBind;
extern u8 **pLookup;
extern MKInputReceiver *pReceiver;
#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
static M2C_UNK *pConTypeNames[6] = {
    "int ",
    &.L_8035DD7D,
    &.L_8035DD84,
    &.L_8035DD8A,
    &.L_8035DD92,
    &.L_8035DD98,
};
#endif
static s32 asciiToKey[0x100] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x20,
    0x31,
    0xDE,
    0x33,
    0x34,
    0x35,
    0x37,
    0xDE,
    0x39,
    0x30,
    0x38,
    0xBB,
    0xBC,
    0xBD,
    0xBE,
    0xBF,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0xBA,
    0xBA,
    0xBC,
    0xBB,
    0xBE,
    0xBF,
    0x32,
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4D,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0xDB,
    0xDC,
    0xDD,
    0x36,
    0xBD,
    0xC0,
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4D,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0xDB,
    0xDC,
    0xDD,
    0xC0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
#if 0 // DRAFT: undefined identifier 'Pool'
static M2C_UNK keyNames;                            /* unable to generate initializer: unknown type */
static ConVar conCmds;                              /* extra bytes: 0xB0; unable to generate initializer: cannot parse .L_8035DEB3 as integer */
static Pool<char> commandBuffer;
#endif
static f32 fLastResult = 1.0f;
#if 0 // DRAFT: declaration syntax error
static M2C_UNK .L_8035DD7D;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035DD84;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035DD8A;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035DD92;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035DD98;                         /* unable to generate initializer: unknown type; const */
static u8 .L_8035DEAE[5] = { 0x65, 0x78, 0x65, 0x63, 0 }; /* const */

void Console_RemoveMacro(const char *arg0) {
    ConCmd *temp_r3_16;
    ConCmd *temp_ret_16;
    MKHeap *temp_r3_26;
    f32 temp_f1_16;
    u8 **temp_r3_22;

    temp_ret_16 = Console_GetVarByName(arg0);
    temp_f1_16 = M2C_BITWISE(f32, temp_ret_16);
    temp_r3_16 = temp_ret_16;
    if (temp_r3_16 != NULL) {
        if ((u8 *) temp_r3_16->unkC != NULL) {
            temp_r3_22 = temp_r3_16->unk0;
            Console_Unregister((ConVar *) temp_r3_22, 1);
            temp_r3_26 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_26 != NULL) {
                ((MKHeap *) (temp_r3_26->Current()))->Free(temp_r3_22, NULL, 0);
                return;
            }
            free(temp_r3_22);
            return;
        }
        Console_Print("Var/func '%s' is not a macro\n", arg0, temp_f1_16);
        return;
    }
    Console_Print("Unknown macro '%s'\n", arg0, temp_f1_16);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned int' to
void Console_AddMacro(const char *arg0, const char *arg1) {
    ConCmd *temp_r31_112;
    ConVar *var_r31_86;
    MKHeap *temp_r3_75;
    MKHeap *temp_r3_78;
    s32 temp_r31_77;
    s8 *temp_r30_93;
    u32 temp_r31_73;

    temp_r31_73 = strlen(arg1);
    temp_r3_75 = strlen(arg0);
    temp_r31_77 = temp_r3_75 + temp_r31_73 + 0x1A;
    temp_r3_78 = temp_r3_75->Current();
    if (temp_r3_78 != NULL) {
        var_r31_86 = ((MKHeap *) (temp_r3_78->Current()))->Alloc(temp_r31_77, NULL, 0);
    } else {
        var_r31_86 = malloc(temp_r31_77);
    }
    temp_r30_93 = &var_r31_86->unk18;
    var_r31_86->unk0 = strcpy(temp_r30_93, arg0);
    var_r31_86->unk4 = CmdPlayMacro;
    var_r31_86->unk8 = 4;
    var_r31_86->unkC = 0;
    var_r31_86->unk10 = 0;
    var_r31_86->unk14 = 0;
    Console_Register(var_r31_86, 1);
    temp_r31_112 = Console_GetVarByName(arg0);
    temp_r31_112->unkC = strcpy(&M2C_FIELD(&temp_r30_93[strlen(arg0)], s8 *, 1), arg1);
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
void Console_PurgeDelayedCmds() {
    s8 ***temp_r3_148;
    s8 ***var_r30_136;
    s8 **temp_r3_157;
    s8 **temp_r4_151;

    var_r30_136 = delayCmdData;
loop_2:
    temp_r3_157 = *var_r30_136;
    if (temp_r3_157 != NULL) {
        ConsoleCmds_pSenderProp = M2C_FIELD(temp_r3_157, s32 *, 8);
        Console_Execute(M2C_FIELD(*var_r30_136, s8 **, 0));
        commandBuffer.Free(M2C_FIELD(*var_r30_136, s8 **, 0));
        temp_r3_148 = delayCmdData;
        delayCmdData = temp_r3_148 + 4;
        temp_r4_151 = *temp_r3_148;
        *temp_r3_148 = *var_r30_136;
        *var_r30_136 = temp_r4_151;
        var_r30_136 += 4;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
void Console_UpdateDelayedCmds() {
    s8 ***temp_r3_199;
    s8 ***var_r31_176;
    s8 **temp_r3_184;
    s8 **temp_r3_209;
    s8 **temp_r4_202;

    var_r31_176 = delayCmdData;
loop_4:
    temp_r3_209 = *var_r31_176;
    if (temp_r3_209 != NULL) {
        M2C_FIELD(temp_r3_209, f32 *, 4) = (f32) (M2C_FIELD(temp_r3_209, f32 *, 4) - gUpdateTimeDelta);
        temp_r3_184 = *var_r31_176;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r3_184, f32 *, 4) == 0.0f) {
            ConsoleCmds_pSenderProp = M2C_FIELD(temp_r3_184, s32 *, 8);
            Console_Execute(M2C_FIELD(*var_r31_176, s8 **, 0));
            commandBuffer.Free(M2C_FIELD(*var_r31_176, s8 **, 0));
            temp_r3_199 = delayCmdData;
            delayCmdData = temp_r3_199 + 4;
            temp_r4_202 = *temp_r3_199;
            *temp_r3_199 = *var_r31_176;
            *var_r31_176 = temp_r4_202;
        }
        var_r31_176 += 4;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Console_DiscardDelayedCmds() {
    s8 ***var_r30_230;
    s8 **temp_r3_238;

    var_r30_230 = delayCmdData;
loop_2:
    temp_r3_238 = *var_r30_230;
    if (temp_r3_238 != NULL) {
        commandBuffer.Free(*temp_r3_238);
        var_r30_230 += 4;
        goto loop_2;
    }
loop_5:
    if ((s8 **) *delayCmdData != NULL) {
        delayCmdData += 4;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__lower_map'
s32 Console_GetLookupIndex(const char *arg0) {
    s32 temp_r3_273;
    u8 temp_r0_261;
    u8 var_r3_265;

    temp_r0_261 = (u8) *arg0;
    if ((s8) temp_r0_261 == -1) {
        var_r3_265 = -1U;
    } else {
        var_r3_265 = *(&__lower_map + (u8) (s8) temp_r0_261);
    }
    temp_r3_273 = var_r3_265 - 0x40;
    if ((temp_r3_273 < 0) || (temp_r3_273 >= 0x40)) {
        return -1;
    }
    return temp_r3_273;
}
#endif

#if 0 // DRAFT: function call 'Console_GetLookupIndex(signed char *)' does not match
void Console_RemoveCommand(ConCmd *arg0) {
    ConCmd *temp_r3_296;
    ConCmd *temp_r3_302;
    ConCmd *temp_r7_318;
    s32 temp_r3_310;

    if (arg0 == (ConCmd *) pCommands) {
        pCommands = arg0->unk4;
    }
    temp_r3_296 = arg0->unk4;
    if (temp_r3_296 != NULL) {
        temp_r3_296->unk8 = arg0->unk8;
    }
    temp_r3_302 = arg0->unk8;
    if (temp_r3_302 != NULL) {
        temp_r3_302->unk4 = arg0->unk4;
    }
    temp_r3_310 = Console_GetLookupIndex((s8 *) *arg0->unk0);
    if ((temp_r3_310 >= 0) && ((u8 *) pLookup[temp_r3_310] == arg0)) {
        temp_r7_318 = arg0->unk4;
        if ((temp_r7_318 != NULL) && ((s8) **arg0->unk0 == (s8) **temp_r7_318->unk0)) {
            pLookup[temp_r3_310] = (u8 *) temp_r7_318;
        } else {
            pLookup[temp_r3_310] = NULL;
        }
    }
    arg0->unk4 = NULL;
    arg0->unk8 = NULL;
}
#endif

#if 0 // DRAFT: function call 'Console_GetLookupIndex(signed char *)' does not match
void Console_AddCommand(ConCmd *arg0) {
    ConCmd *temp_r3_395;
    s32 var_r30_376;
    s32 var_r3_357;
    u32 var_r0_443;
    u8 *temp_r0_377;
    u8 *var_r29_411;
    u8 *var_r29_468;
    u8 *var_r30_412;
    u8 *var_r30_469;

    var_r3_357 = Console_GetLookupIndex((s8 *) *arg0->unk0);
    if (var_r3_357 < 0) {
        arg0->unk4 = pCommands;
        arg0->unk8 = NULL;
        if ((ConCmd *) pCommands != NULL) {
            pCommands->unk8 = arg0;
        }
        pCommands = arg0;
        return;
    }
    if ((ConCmd *) pCommands != NULL) {
        var_r30_376 = var_r3_357 * 4;
        temp_r0_377 = pLookup[var_r3_357];
        if (temp_r0_377 != NULL) {
            temp_r0_377->Compare(arg0);
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) < 0) {
                arg0->unk4 = (ConCmd *) pLookup[var_r3_357];
                arg0->unk8 = M2C_FIELD(pLookup[var_r3_357], ConCmd **, 8);
                M2C_FIELD(pLookup[var_r3_357], ConCmd **, 8) = arg0;
                temp_r3_395 = arg0->unk8;
                if (temp_r3_395 != NULL) {
                    temp_r3_395->unk4 = arg0;
                }
                if ((u8 *) pLookup[var_r3_357] == (ConCmd *) pCommands) {
                    pCommands = arg0;
                }
                pLookup[var_r3_357] = (u8 *) arg0;
                return;
            }
            var_r29_411 = NULL;
            var_r30_412 = pLookup[var_r3_357];
loop_14:
            if (var_r30_412 != NULL) {
                arg0->Compare((ConCmd *) var_r30_412);
                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) < 0) {
                    var_r29_411 = var_r30_412;
                    var_r30_412 = M2C_FIELD(var_r30_412, u8 **, 4);
                    goto loop_14;
                }
            }
            if (var_r30_412 == NULL) {
                arg0->unk8 = (ConCmd *) var_r29_411;
                arg0->unk4 = NULL;
                M2C_FIELD(var_r29_411, ConCmd **, 4) = arg0;
                return;
            }
            arg0->unk4 = (ConCmd *) var_r30_412;
            arg0->unk8 = M2C_FIELD(var_r30_412, ConCmd **, 8);
            M2C_FIELD(var_r30_412, ConCmd **, 8) = arg0;
            arg0->unk8->unk4 = arg0;
            return;
        }
        pLookup[var_r3_357] = (u8 *) arg0;
        var_r0_443 = 0U;
loop_21:
        if ((var_r3_357 > 0) && (var_r0_443 == 0U)) {
            var_r30_376 -= 4;
            var_r3_357 -= 1;
            var_r0_443 = *(pLookup + var_r30_376);
            goto loop_21;
        }
        if (var_r0_443 == 0U) {
            arg0->unk4 = pCommands;
            arg0->unk8 = NULL;
            pCommands->unk8 = arg0;
            pCommands = arg0;
            return;
        }
        var_r29_468 = NULL;
        var_r30_469 = pLookup[var_r3_357];
loop_27:
        if (var_r30_469 != NULL) {
            arg0->Compare((ConCmd *) var_r30_469);
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) < 0) {
                var_r29_468 = var_r30_469;
                var_r30_469 = M2C_FIELD(var_r30_469, u8 **, 4);
                goto loop_27;
            }
        }
        if (var_r30_469 == NULL) {
            arg0->unk8 = (ConCmd *) var_r29_468;
            arg0->unk4 = NULL;
            M2C_FIELD(var_r29_468, ConCmd **, 4) = arg0;
            return;
        }
        arg0->unk4 = (ConCmd *) var_r30_469;
        arg0->unk8 = M2C_FIELD(var_r30_469, ConCmd **, 8);
        M2C_FIELD(var_r30_469, ConCmd **, 8) = arg0;
        arg0->unk8->unk4 = arg0;
        return;
    }
    pCommands = arg0;
    arg0->unk4 = NULL;
    arg0->unk8 = NULL;
    pLookup[var_r3_357] = (u8 *) arg0;
}
#endif

s32 Console_InputReceiver(MKInputEvent *arg0, void *arg1) {
    Console_ProcessInputEvent(arg0);
    return 1;
}

#if 0 // DRAFT: function call 'Console_SetVarAsBool(signed char *, unsigned int)' does not
void Console_ProcessInputEvent(MKInputEvent *arg0) {
    u8 *temp_r3_545;

    if ((s32) arg0->unk0 != 6) {
        return;
    }
    if ((u8) bBindEnabled != 0) {
        temp_r3_545 = Console_GetBind(arg0->unk4);
        if ((u8) arg0->unk9 != 0) {
            if (temp_r3_545 != NULL) {
                if ((s32) *temp_r3_545 == 0x2B) {
                    Console_SetVarAsBool((s8 *) (temp_r3_545 + 1), 1U);
                    return;
                }
                Console_Execute((s8 *) temp_r3_545);
            }
        } else if ((temp_r3_545 != NULL) && ((s32) *temp_r3_545 == 0x2B)) {
            Console_SetVarAsBool((s8 *) (temp_r3_545 + 1), 0U);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'char *' to
s32 ReadString(char **arg0, char *arg1, int arg2, int arg3) {
    s32 var_r30_587;
    s8 *temp_r3_590;
    s8 *var_r29_586;
    s8 *var_r4_605;
    u8 temp_r3_615;
    u8 temp_r3_629;

    var_r29_586 = arg1;
    var_r30_587 = arg2;
    if (arg0 != NULL) {
        temp_r3_590 = *arg0;
        if ((temp_r3_590 != NULL) && (var_r29_586 != NULL) && (strlen(temp_r3_590) != 0)) {
            *var_r29_586 = 0;
            if ((var_r30_587 > 0) && (arg3 >= 0)) {
                var_r4_605 = &(*arg0)[arg3];
loop_8:
                if (var_r4_605 != NULL) {
                    temp_r3_615 = (u8) *var_r4_605;
                    if (((s8) temp_r3_615 != 0) && ((s8) temp_r3_615 != 0xD)) {
                        if (var_r30_587 <= 0) {

                        } else {
                            *var_r29_586 = (s8) temp_r3_615;
                            var_r29_586 += 1;
                            var_r4_605 += 1;
                            var_r30_587 -= 1;
                            goto loop_8;
                        }
                    }
                }
loop_14:
                if (var_r4_605 != NULL) {
                    temp_r3_629 = (u8) *var_r4_605;
                    if (((s8) temp_r3_629 != 0) && (((s8) temp_r3_629 == 0xA) || ((s8) temp_r3_629 == 0xD))) {
                        var_r4_605 += 2;
                        goto loop_14;
                    }
                }
                *var_r29_586 = 0;
                *arg0 = var_r4_605;
                return 1;
            }
            return -5;
        }
    }
    return -0xA;
}
#endif

void Console_SetVarAsBool(const char *arg0, bool arg1) {
    ConCmd *temp_r3_664;

    temp_r3_664 = Console_GetVarByName(arg0);
    if (temp_r3_664 != NULL) {
        temp_r3_664->SetAsBool(arg1);
    }
}

void Console_BindEnable(bool arg0) {
    bBindEnabled = arg0;
}

void Console_UnbindAll() {
    u32 var_r31_691;

    var_r31_691 = 0;
    do {
        Console_Unbind(var_r31_691);
        var_r31_691 += 1;
    } while ((s32) var_r31_691 < 0x100);
}

#if 0 // DRAFT: pointer/array required
void Console_Unbind(unsigned long arg0) {
    MKHeap *temp_r3_719;
    u8 *temp_r31_716;

    if (arg0 < 0x100U) {
        temp_r31_716 = pKeyBind[arg0];
        if (temp_r31_716 != NULL) {
            temp_r3_719 = arg0->Current();
            if (temp_r3_719 != NULL) {
                ((MKHeap *) (temp_r3_719->Current()))->Free(temp_r31_716, NULL, 0);
            } else {
                free((u8 **) temp_r31_716);
            }
            pKeyBind[arg0] = NULL;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned int' to
void Console_Bind(unsigned long arg0, const char *arg1) {
    ConVar *var_r3_765;
    MKHeap *temp_r3_756;
    MKHeap *temp_r3_758;
    s32 temp_r31_757;

    if (arg0 < 0x100U) {
        Console_Unbind(arg0);
        temp_r3_756 = strlen(arg1);
        temp_r31_757 = temp_r3_756 + 1;
        temp_r3_758 = temp_r3_756->Current();
        if (temp_r3_758 != NULL) {
            var_r3_765 = ((MKHeap *) (temp_r3_758->Current()))->Alloc(temp_r31_757, NULL, 0);
        } else {
            var_r3_765 = malloc(temp_r31_757);
        }
        pKeyBind[arg0] = (u8 *) var_r3_765;
        strcpy((s8 *) pKeyBind[arg0], arg1);
    }
}
#endif

u8 *Console_GetBind(unsigned long arg0) {
    if (arg0 < 0x100U) {
        return pKeyBind[arg0];
    }
    return NULL;
}

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
ConCmd *Console_GetVarByName(const char *arg0) {
    u8 *var_r30_816;
    u8 *var_r31_808;

    var_r31_808 = NULL;
    if (arg0 == NULL) {
        return NULL;
    }
    var_r30_816 = pLookup[Console_GetLookupIndex(arg0)];
loop_4:
    if ((var_r30_816 != NULL) && (stricmp(*M2C_FIELD(var_r30_816, s8 ***, 0), arg0) < 0)) {
        var_r30_816 = M2C_FIELD(var_r30_816, u8 **, 4);
        goto loop_4;
    }
    if ((var_r30_816 != NULL) && (stricmp(*M2C_FIELD(var_r30_816, s8 ***, 0), arg0) == 0)) {
        var_r31_808 = var_r30_816;
    }
    return (ConCmd *) var_r31_808;
}
#endif

void Console_Write(const char *arg0, int arg1) {

}

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
f32 Console_ExecuteBuffer(const char *arg0) {
    s8 spC;
    s8 *sp8;

    sp8 = arg0;
    fLastResult = 1.0f;
loop_2:
    if (ReadString(&sp8, &spC, 0x100, 0) == 1) {
        fLastResult = Console_Execute(&spC);
        goto loop_2;
    }
    return fLastResult;
}
#endif

#if 0 // DRAFT: illegal operand
f32 Console_Execute(const char *arg0) {
    s8 *spC;
    s8 *sp8;
    M2C_UNK (*temp_r12_1172)(f32 (*)(s32, s8 **));
    f32 temp_f31_1058;
    f32 temp_f31_1091;
    f32 temp_f31_1200;
    f32 temp_f31_932;
    f32 temp_f31_949;
    f32 var_f1_1103;
    s32 temp_r0_1034;
    s32 temp_r0_1150;
    s32 temp_r3_1103;
    s32 temp_ret_1103;
    s32 temp_ret_1118;
    s32 temp_ret_1127;
    s32 var_ctr_1037;
    s32 var_r29_913;
    s32 var_r5_961;
    s32 var_r6_914;
    s8 *temp_r3_904;
    s8 *var_r30_1035;
    s8 *var_r3_908;
    s8 *var_r4_912;
    s8 var_r28_960;
    s8 var_r3_1036;
    u8 *var_r27_1102;
    u8 temp_r0_1074;
    u8 temp_r5_925;
    u8 temp_r8_1027;
    u8 var_r9_959;
    void *temp_r3_1149;
    void *temp_r3_1171;

    ExecuteDepth::iDepth += 1;
    fLastResult = 1.0f;
    temp_r3_904 = commandBuffer.Alloc(strlen(arg0) + 1);
    sp8 = temp_r3_904;
    strcpy(temp_r3_904, arg0);
    var_r3_908 = temp_r3_904;
loop_70:
    if ((s8) (u8) *var_r3_908 == 0) {
        temp_f31_1200 = fLastResult;
        commandBuffer.Free(sp8);
        ExecuteDepth::iDepth -= 1;
        return temp_f31_1200;
    }
    var_r4_912 = var_r3_908;
    var_r29_913 = 0;
    var_r6_914 = 0;
loop_5:
    temp_r5_925 = (u8) M2C_FIELD(var_r4_912, s8 *, 0);
    switch ((s8) temp_r5_925) {                     /* switch 1; irregular */
    case 0x0:                                       /* switch 1 */
        break;
    case 0x20:                                      /* switch 1 */
    case 0x3B:                                      /* switch 1 */
        var_r4_912 += 1;
        goto loop_5;
    }
    if ((s8) temp_r5_925 == 0) {
        temp_f31_932 = fLastResult;
        commandBuffer.Free(sp8);
        ExecuteDepth::iDepth -= 1;
        return temp_f31_932;
    }
    if (((s8) temp_r5_925 == 0x2F) && ((s32) M2C_FIELD(var_r4_912, u8 *, 1) == 0x2F)) {
        temp_f31_949 = fLastResult;
        commandBuffer.Free(sp8);
        ExecuteDepth::iDepth -= 1;
        return temp_f31_949;
    }
    var_r9_959 = 0;
    var_r28_960 = 0x20;
    var_r5_961 = 0;
loop_33:
    temp_r8_1027 = (u8) *var_r4_912;
    if (((s8) temp_r8_1027 != 0) && (var_r28_960 != 0x3B)) {
        switch ((s8) temp_r8_1027) {                /* switch 2 */
        case 0x20:                                  /* switch 2 */
        case 0x3B:                                  /* switch 2 */
            var_r28_960 = (s8) temp_r8_1027;
            if ((var_r9_959 == 0) && (var_r5_961 == 0)) {
                *var_r4_912 = 0;
            }
            break;
        case 0x22:                                  /* switch 2 */
            if (var_r5_961 == 0) {
                *var_r4_912 = 0;
            }
            var_r9_959 = var_r9_959 == 0;
            break;
        case 0x28:                                  /* switch 2 */
            if (var_r9_959 == 0) {
                if (var_r5_961 == 0) {
                    *var_r4_912 = 0;
                }
                var_r5_961 += 1;
            }
            break;
        case 0x29:                                  /* switch 2 */
            if (var_r9_959 == 0) {
                var_r5_961 -= 1;
                if (var_r5_961 == 0) {
                    *var_r4_912 = 0;
                }
            }
            break;
        }
        if (((var_r9_959 != 0) || (var_r5_961 != 0)) && (var_r28_960 == 0x3B)) {
            var_r28_960 = 0x20;
        }
        if (var_r28_960 != 0x3B) {
            var_r4_912 += 1;
        }
        goto loop_33;
    }
    temp_r0_1034 = var_r4_912 - var_r3_908;
    var_r30_1035 = var_r3_908;
    var_r3_1036 = 0;
    var_ctr_1037 = temp_r0_1034;
    if (temp_r0_1034 > 0) {
loop_36:
        if (((s8) (u8) *var_r30_1035 == 0) || (var_r3_1036 != 0) || (var_r29_913 += 1, *(&spC + var_r6_914) = var_r30_1035, var_r6_914 += 4, ((var_r29_913 == 0xE) == 0))) {
            var_r3_1036 = (s8) (u8) *var_r30_1035;
            var_r30_1035 += 1;
            var_ctr_1037 -= 1;
            if (var_ctr_1037 != 0) {
                goto loop_36;
            }
        }
    }
    if (var_r29_913 == 0) {
        temp_f31_1058 = fLastResult;
        commandBuffer.Free(sp8);
        ExecuteDepth::iDepth -= 1;
        return temp_f31_1058;
    }
loop_44:
    temp_r0_1074 = (u8) *spC;
    if ((s8) temp_r0_1074 == 0x20) {
        spC += 1;
        goto loop_44;
    }
    if (((s8) temp_r0_1074 >= 0x30) && ((s8) temp_r0_1074 <= 0x39) && (sscanf("%f", &fLastResult) == 1)) {
        temp_f31_1091 = fLastResult;
        commandBuffer.Free(sp8);
        ExecuteDepth::iDepth -= 1;
        return temp_f31_1091;
    }
    var_r27_1102 = NULL;
    temp_ret_1103 = Console_GetLookupIndex(spC);
    var_f1_1103 = M2C_BITWISE(f32, temp_ret_1103);
    temp_r3_1103 = temp_ret_1103;
    if (temp_r3_1103 >= 0) {
        var_r27_1102 = pLookup[temp_r3_1103];
    }
loop_52:
    if (var_r27_1102 != NULL) {
        temp_ret_1118 = stricmp(M2C_FIELD(M2C_FIELD(var_r27_1102, void **, 0), s8 **, 0), spC);
        var_f1_1103 = M2C_BITWISE(f32, temp_ret_1118);
        if (temp_ret_1118 < 0) {
            var_r27_1102 = M2C_FIELD(var_r27_1102, u8 **, 4);
            goto loop_52;
        }
    }
    if ((var_r27_1102 == NULL) || (temp_ret_1127 = stricmp(M2C_FIELD(M2C_FIELD(var_r27_1102, void **, 0), s8 **, 0), spC), var_f1_1103 = M2C_BITWISE(f32, temp_ret_1127), ((temp_ret_1127 > 0) != 0))) {
        Console_Print("Unknown command '%s'\n", spC, var_f1_1103);
        fLastResult = 0.0f;
        commandBuffer.Free(sp8);
        ExecuteDepth::iDepth -= 1;
        return 0.0f;
    }
    temp_r3_1149 = M2C_FIELD(var_r27_1102, void **, 0);
    temp_r0_1150 = M2C_FIELD(temp_r3_1149, s32 *, 8);
    switch (temp_r0_1150) {                         /* switch 3; irregular */
    case 5:                                         /* switch 3 */
        if (var_r29_913 == 1) {
            fLastResult = var_r27_1102->AsFloat();
        } else {
            var_r27_1102->SetAsString(sp10);
            temp_r3_1171 = M2C_FIELD(var_r27_1102, void **, 0);
            temp_r12_1172 = M2C_FIELD(temp_r3_1171, M2C_UNK (**)(f32 (*)(s32, s8 **)), 0x10);
            if (temp_r12_1172 != NULL) {
                temp_r12_1172(M2C_FIELD(temp_r3_1171, f32 (**)(s32, s8 **), 4));
            }
            fLastResult = 1.0f;
        }
        break;
    case 4:                                         /* switch 3 */
        fLastResult = M2C_FIELD(temp_r3_1149, f32 (**)(s32, s8 **), 4)(var_r29_913, &spC);
        break;
    }
    var_r3_908 = var_r30_1035;
    if (var_r28_960 == 0x3B) {
        var_r3_908 = var_r30_1035 + 1;
    }
    goto loop_70;
}
#endif

#if 0 // DRAFT: function call 'Console_GetVarByName(ConVar)' does not match
void Console_Unregister(ConVar *arg0, int arg1) {
    ConCmd *temp_r3_1231;
    s32 var_r30_1225;
    s32 var_r31_1226;

    var_r30_1225 = arg1 - 1;
    var_r31_1226 = var_r30_1225 * 0x18;
loop_3:
    if (var_r30_1225 >= 0) {
        temp_r3_1231 = Console_GetVarByName(*(arg0 + var_r31_1226));
        if (temp_r3_1231 != NULL) {
            Console_RemoveCommand(temp_r3_1231);
            temp_r3_1231->Deinit();
            operator delete(temp_r3_1231);
            var_r30_1225 -= 1;
            var_r31_1226 -= 0x18;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'strlen(unsigned char *)' does not match
void Console_Register(ConVar *arg0, int arg1) {
    ConVar *temp_r30_1265;
    s32 var_r29_1261;
    s32 var_r31_1262;

    var_r29_1261 = 0;
    var_r31_1262 = 0;
loop_6:
    if (var_r29_1261 >= arg1) {
        return;
    }
    temp_r30_1265 = arg0 + var_r31_1262;
    if (strlen(temp_r30_1265->unk0) == 0) {
        Console_Write("Invalid name for command/variable\n", 0);
        return;
    }
    if (Console_GetVarByName(temp_r30_1265->unk0) != NULL) {
        Console_Write("Command/variable already registered as '", 0);
        Console_Write(temp_r30_1265->unk0, 0);
        Console_Write("'\n", 0);
        return;
    }
    operator new(0x14U, NULL, 0);
    ((ConCmd *) (M2C_ERROR(/* Read from unset register $r3 */)))->Init(temp_r30_1265);
    Console_AddCommand(M2C_ERROR(/* Read from unset register $r3 */));
    var_r29_1261 += 1;
    var_r31_1262 += 0x18;
    goto loop_6;
}
#endif

#if 0 // DRAFT: ')' expected
void Console_Print(const char *arg0, ... arg1) {
    s8 sp74;
    s8 **sp70;
    M2C_UNK *sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s8 *sp8;

    if (M2C_ERROR(/* Read from unset register $cr0_eq */)) {
        sp28 = farg0;
        sp30 = farg1;
        sp38 = farg2;
        sp40 = farg3;
        sp48 = farg4;
        sp50 = farg5;
        sp58 = farg6;
        sp60 = farg7;
    }
    sp8 = arg0;
    spC = arg1;
    sp10 = arg2;
    sp14 = arg3;
    sp18 = arg4;
    sp1C = arg5;
    sp20 = arg6;
    sp24 = arg7;
    sp68 = 0x01000000;
    sp6C = &arg_sp8;
    sp70 = &sp8;
    vsprintf(&sp74, arg0, (struct _anonymous *) &sp68);
    Console_Write(&sp74, 1);
}
#endif

#if 0 // DRAFT: undefined identifier 'commandBuffer'
void Console_Deinit() {
    MKHeap *temp_r3_1413;
    MKHeap *temp_r3_1430;
    MKHeap *temp_r3_1446;
    s8 ***var_r31_1387;
    s8 ***var_r3_1388;
    s8 ***var_r4_1386;
    s8 **temp_r0_1391;
    s8 **temp_r0_1410;
    u32 temp_r0_1396;
    u8 **temp_r31_1429;
    u8 **temp_r31_1444;

    MKInputReceiver_Destroy(pReceiver);
loop_2:
    if ((ConCmd *) pCommands != NULL) {
        Console_Unregister((ConVar *) pCommands->unk0, 1);
        goto loop_2;
    }
    commandBuffer.Deinit();
    var_r4_1386 = delayCmdData;
    var_r31_1387 = var_r4_1386;
    var_r3_1388 = var_r4_1386;
loop_6:
    temp_r0_1396 = M2C_FIELD(var_r3_1388, u32 *, -4);
    var_r3_1388 -= 4;
    if (temp_r0_1396 != 0U) {
        temp_r0_1391 = *var_r3_1388;
        if (temp_r0_1391 < var_r31_1387) {
            var_r31_1387 = (s8 ***) temp_r0_1391;
        }
        goto loop_6;
    }
    if (var_r3_1388 != &gEmptyPtrListDL) {
loop_12:
        temp_r0_1410 = *var_r4_1386;
        if (temp_r0_1410 != NULL) {
            if (temp_r0_1410 < var_r31_1387) {
                var_r31_1387 = (s8 ***) temp_r0_1410;
            }
            var_r4_1386 += 4;
            goto loop_12;
        }
        temp_r3_1413 = var_r3_1388->Current();
        if (temp_r3_1413 != NULL) {
            ((MKHeap *) (temp_r3_1413->Current()))->Free(var_r31_1387, NULL, 0);
        } else {
            free((u8 **) var_r31_1387);
        }
    }
    delayCmdData = NULL;
    Console_UnbindAll();
    temp_r31_1429 = pKeyBind;
    temp_r3_1430 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1430 != NULL) {
        ((MKHeap *) (temp_r3_1430->Current()))->Free(temp_r31_1429, NULL, 0);
    } else {
        free(temp_r31_1429);
    }
    temp_r31_1444 = pLookup;
    pKeyBind = NULL;
    temp_r3_1446 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1446 != NULL) {
        ((MKHeap *) (temp_r3_1446->Current()))->Free(temp_r31_1444, NULL, 0);
    } else {
        free(temp_r31_1444);
    }
    pLookup = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Console_Init() {
    ConVar *var_r3_1481;
    ConVar *var_r3_1495;
    ConVar *var_r3_1517;
    MKHeap *temp_r3_1474;
    MKHeap *temp_r3_1488;
    MKHeap *temp_r3_1510;
    s32 var_ctr_1529;

    temp_r3_1474 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1474 != NULL) {
        var_r3_1481 = ((MKHeap *) (temp_r3_1474->Current()))->Alloc(0x400, NULL, 0);
    } else {
        var_r3_1481 = malloc(0x400);
    }
    pKeyBind = &var_r3_1481->unk0;
    temp_r3_1488 = var_r3_1481->Current();
    if (temp_r3_1488 != NULL) {
        var_r3_1495 = ((MKHeap *) (temp_r3_1488->Current()))->Alloc(0x100, NULL, 0);
    } else {
        var_r3_1495 = malloc(0x100);
    }
    pLookup = &var_r3_1495->unk0;
    memset(pKeyBind, 0, 0x400U);
    temp_r3_1510 = ((MKHeap *) (memset(pLookup, 0, 0x100U)))->Current();
    if (temp_r3_1510 != NULL) {
        var_r3_1517 = ((MKHeap *) (temp_r3_1510->Current()))->Alloc(0x208, NULL, 0);
    } else {
        var_r3_1517 = malloc(0x208);
    }
    delayCmdData = (s8 ***) var_r3_1517;
    delayCmdData = (s8 ***) &var_r3_1517->unk180;
    var_r3_1517->unk180 = NULL;
    var_ctr_1529 = 0x20;
    do {
        delayCmdData += 4;
        M2C_FIELD(delayCmdData, ConVar **, 4) = var_r3_1517;
        var_r3_1517 += 0xC;
        var_ctr_1529 -= 1;
    } while (var_ctr_1529 != 0);
    delayCmdData += 4;
    M2C_FIELD(delayCmdData, ConVar **, 4) = NULL;
    commandBuffer.Init(0x4000, 0x40);
    bCtrlPressed = 0;
    bBindEnabled = 0;
    Console_Register(&conCmds, 0x18);
    Console_BindEnable(1U);
    pReceiver = MKInputReceiver_Create((u8 (*)(MKInputEvent *, void *)) Console_InputReceiver, -1, 5, NULL);
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(signed char *, long, const char[3], bool,
void ConCmd::SetAsBool(bool arg0) {
    f32 var_f0_1600;
    s32 temp_r0_1576;
    s32 temp_r7_1614;
    u8 **temp_r3_1575;

    temp_r3_1575 = this->unk0;
    temp_r0_1576 = M2C_FIELD(temp_r3_1575, s32 *, 8);
    switch (temp_r0_1576) {                         /* irregular */
    case 0:
        *M2C_FIELD(temp_r3_1575, s8 **, 4) = (s32) (arg0 != 0);
        return;
    case 1:
        if (arg0 != 0) {
            var_f0_1600 = 1.0f;
        } else {
            var_f0_1600 = 0.0f;
        }
        *M2C_FIELD(temp_r3_1575, s8 **, 4) = var_f0_1600;
        return;
    case 2:
        *M2C_FIELD(temp_r3_1575, s8 **, 4) = arg0;
        return;
    case 3:
        temp_r7_1614 = M2C_FIELD(temp_r3_1575, s32 *, 0x14);
        Str_snPrintf(M2C_FIELD(temp_r3_1575, s8 **, 4), temp_r7_1614 - 1, "%d", arg0 != 0, temp_r7_1614);
        return;
    case 5:
        *M2C_FIELD(temp_r3_1575, s8 **, 4) = (s32) (arg0 != 0);
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(signed char *, long, const char[6], unsigned
void ConCmd::SetAsFloat(float arg0) {
    s32 temp_r0_1645;
    s32 temp_r3_1704;
    s32 var_r0_1702;
    s32 var_r3_1692;
    s32 var_r5_1691;
    u8 **temp_r6_1644;

    temp_r6_1644 = this->unk0;
    temp_r0_1645 = M2C_FIELD(temp_r6_1644, s32 *, 8);
    switch (temp_r0_1645) {                         /* irregular */
    case 0:
        *M2C_FIELD(temp_r6_1644, s8 **, 4) = (s32) arg0;
        return;
    case 1:
        *M2C_FIELD(temp_r6_1644, s8 **, 4) = arg0;
        return;
    case 2:
        *M2C_FIELD(temp_r6_1644, s8 **, 4) = (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) ^ 1;
        return;
    case 3:
        Str_snPrintf(M2C_FIELD(temp_r6_1644, s8 **, 4), M2C_FIELD(temp_r6_1644, s32 *, 0x14) - 1, "%3.4f", temp_r6_1644);
        return;
    case 5:
        var_r5_1691 = 0;
        var_r3_1692 = 0;
loop_14:
        if ((u32) *(M2C_FIELD(temp_r6_1644, s32 *, 0x14) + var_r3_1692) != 0U) {
            var_r5_1691 += 1;
            var_r3_1692 += 4;
            goto loop_14;
        }
        var_r0_1702 = var_r5_1691;
        temp_r3_1704 = (s32) arg0;
        if (temp_r3_1704 < var_r5_1691) {
            var_r0_1702 = temp_r3_1704;
        }
        *M2C_FIELD(temp_r6_1644, s8 **, 4) = var_r0_1702;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'Str_snPrintf(signed char *, long, const char[3], int,
void ConCmd::SetAsInt(int arg0) {
    s32 temp_r0_1725;
    s32 temp_r7_1761;
    s32 var_r0_1784;
    s32 var_r3_1774;
    s32 var_r7_1773;
    u8 **temp_r6_1724;

    temp_r6_1724 = this->unk0;
    temp_r0_1725 = M2C_FIELD(temp_r6_1724, s32 *, 8);
    switch (temp_r0_1725) {                         /* irregular */
    case 0:
        *M2C_FIELD(temp_r6_1724, s8 **, 4) = arg0;
        return;
    case 1:
        *M2C_FIELD(temp_r6_1724, s8 **, 4) = (f32) arg0;
        return;
    case 2:
        *M2C_FIELD(temp_r6_1724, s8 **, 4) = arg0 != 0;
        return;
    case 3:
        temp_r7_1761 = M2C_FIELD(temp_r6_1724, s32 *, 0x14);
        Str_snPrintf(M2C_FIELD(temp_r6_1724, s8 **, 4), temp_r7_1761 - 1, "%d", arg0, temp_r7_1761);
        return;
    case 5:
        var_r7_1773 = 0;
        var_r3_1774 = 0;
loop_14:
        if ((u32) *(M2C_FIELD(temp_r6_1724, s32 *, 0x14) + var_r3_1774) != 0U) {
            var_r7_1773 += 1;
            var_r3_1774 += 4;
            goto loop_14;
        }
        var_r0_1784 = var_r7_1773;
        if (arg0 < var_r7_1773) {
            var_r0_1784 = arg0;
        }
        *M2C_FIELD(temp_r6_1724, s8 **, 4) = var_r0_1784;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'atoi(const char *)' does not match
void ConCmd::SetAsString(const char *arg0) {
    s32 sp8;
    s32 temp_r0_1808;
    s8 *temp_r3_1857;
    s8 *temp_r4_1833;
    s8 var_r29_1874;
    u8 **temp_r3_1807;
    u8 **temp_r5_1895;
    u8 temp_r0_1823;
    u8 temp_r0_1846;

    if (arg0 != NULL) {
        temp_r3_1807 = this->unk0;
        temp_r0_1808 = M2C_FIELD(temp_r3_1807, s32 *, 8);
        switch (temp_r0_1808) {                     /* irregular */
        case 0:
            temp_r0_1823 = (u8) *arg0;
            if (((s8) temp_r0_1823 == 0x2B) || ((s8) temp_r0_1823 == 0x2D)) {
                temp_r4_1833 = M2C_FIELD(this->unk0, s8 **, 4);
                *temp_r4_1833 = (s32) (*temp_r4_1833 + atoi(arg0));
                return;
            }
            *M2C_FIELD(this->unk0, s8 **, 4) = atoi(arg0);
            return;
        case 1:
            temp_r0_1846 = (u8) *arg0;
            if (((s8) temp_r0_1846 == 0x2B) || ((s8) temp_r0_1846 == 0x2D)) {
                temp_r3_1857 = M2C_FIELD(this->unk0, s8 **, 4);
                *temp_r3_1857 = (f32) (*temp_r3_1857 + (f32) atof(arg0));
                return;
            }
            *M2C_FIELD(this->unk0, s8 **, 4) = (f32) atof(arg0);
            return;
        case 2:
            var_r29_1874 = 0;
            if ((stricmp(arg0, "true") == 0) || (atoi(arg0) != 0)) {
                var_r29_1874 = 1;
            }
            *M2C_FIELD(this->unk0, s8 **, 4) = var_r29_1874;
            return;
        case 3:
            strncpy(M2C_FIELD(temp_r3_1807, s8 **, 4), arg0, M2C_FIELD(temp_r3_1807, s32 *, 0x14) - 1);
            temp_r5_1895 = this->unk0;
            M2C_FIELD(&M2C_FIELD(temp_r5_1895, s8 **, 4)[M2C_FIELD(temp_r5_1895, s32 *, 0x14)], s8 *, -1) = 0;
            return;
        case 5:
            if (sscanf(arg0, "%d", &sp8) == 1) {
                *M2C_FIELD(this->unk0, s8 **, 4) = sp8;
                return;
            }
            sp8 = 0;
loop_28:
            if ((u32) *(M2C_FIELD(this->unk0, s32 *, 0x14) + (sp8 * 4)) == 0U) {

            } else {
                if (stricmp(arg0) == 0) {
                    *M2C_FIELD(this->unk0, s8 **, 4) = sp8;
                    return;
                }
                sp8 += 1;
                goto loop_28;
            }
            break;
        }
    }
}
#endif

void ConCmd::Compare(ConCmd *arg0) {
    u8 **temp_r5_1957;

    temp_r5_1957 = arg0->unk0;
    stricmp((s8 *) *temp_r5_1957, (s8 *) *this->unk0, temp_r5_1957);
}

#if 0 // DRAFT: function call 'sscanf(signed char *, const char[3], long *)' does not
s32 ConCmd::AsInt() {
    f32 sp8;                                        /* compiler-managed */
    s32 temp_r0_1977;
    u8 **temp_r3_1976;

    sp8 = 0.0f;
    temp_r3_1976 = this->unk0;
    temp_r0_1977 = M2C_FIELD(temp_r3_1976, s32 *, 8);
    switch (temp_r0_1977) {                         /* irregular */
    case 0:
        sp8 = *M2C_FIELD(temp_r3_1976, s8 **, 4);
        break;
    case 1:
        sp8 = (s32) *M2C_FIELD(temp_r3_1976, s8 **, 4);
        break;
    case 2:
        sp8 = M2C_BITWISE(u8, *M2C_FIELD(temp_r3_1976, s8 **, 4)) != 0;
        break;
    case 3:
        sscanf(M2C_FIELD(temp_r3_1976, s8 **, 4), "%d", (s32 *) &sp8);
        break;
    case 5:
        sp8 = *M2C_FIELD(temp_r3_1976, s8 **, 4);
        break;
    }
    return M2C_BITWISE(s32, sp8);
}
#endif

#if 0 // DRAFT: function call 'sscanf(signed char *, const char[3], long *)' does not
f32 ConCmd::AsFloat() {
    f32 sp8;
    f32 var_f0_2037;
    s32 temp_r0_2041;
    u8 **temp_r3_2040;

    var_f0_2037 = 0.0f;
    sp8 = 0.0f;
    temp_r3_2040 = this->unk0;
    temp_r0_2041 = M2C_FIELD(temp_r3_2040, s32 *, 8);
    switch (temp_r0_2041) {                         /* irregular */
    case 0:
        sp8 = (f32) *M2C_FIELD(temp_r3_2040, s8 **, 4);
        break;
    case 1:
        sp8 = M2C_BITWISE(f32, *M2C_FIELD(temp_r3_2040, s8 **, 4));
        break;
    case 2:
        if ((u8) *M2C_FIELD(temp_r3_2040, s8 **, 4) != 0) {
            var_f0_2037 = 1.0f;
        }
        sp8 = var_f0_2037;
        break;
    case 3:
        sscanf(M2C_FIELD(temp_r3_2040, s8 **, 4), "%f", (s32 *) &sp8);
        break;
    case 5:
        sp8 = (f32) *M2C_FIELD(temp_r3_2040, s8 **, 4);
        break;
    }
    return sp8;
}
#endif

void ConCmd::Deinit() {

}

void ConCmd::Init(ConVar *arg0) {
    this->unk0 = &arg0->unk0;
    this->unk10 = 0;
    this->unk4 = NULL;
    this->unk8 = NULL;
}

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdPlayMacro(int arg0, char **arg1) {
    ConCmd *temp_r3_2133;
    u8 *temp_r3_2136;

    temp_r3_2133 = Console_GetVarByName(*arg1);
    if (temp_r3_2133 != NULL) {
        temp_r3_2136 = temp_r3_2133->unkC;
        if (temp_r3_2136 != NULL) {
            return Console_Execute((s8 *) temp_r3_2136);
        }
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_RemoveMacro(signed char *)' does not match
f32 CmdMacro(int arg0, char **arg1) {
    if (arg0 == 1) {
        Console_Print("Syntax: %s <<name>> [command]\n", M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    if (arg0 == 2) {
        Console_RemoveMacro(M2C_FIELD(arg1, s8 **, 4));
    } else {
        Console_AddMacro(M2C_FIELD(arg1, s8 **, 4), M2C_FIELD(arg1, s8 **, 8));
    }
    return 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'commandBuffer'
f32 CmdDelay(int arg0, char **arg1) {
    f32 temp_f1_2197;
    s8 ***temp_r3_2212;
    s8 **temp_r31_2214;
    s8 *temp_r30_2220;

    if (arg0 == 3) {
        temp_f1_2197 = (f32) atof(M2C_FIELD(arg1, s8 **, 4));
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_2197 == 0.0f) {
            Console_Print("%s: 'delay' should be greater than zero\n", M2C_FIELD(arg1, s8 **, 0), temp_f1_2197);
            return 0.0f;
        }
        temp_r3_2212 = delayCmdData - 4;
        delayCmdData = temp_r3_2212;
        temp_r31_2214 = *temp_r3_2212;
        if (temp_r31_2214 != NULL) {
            M2C_FIELD(temp_r31_2214, s32 *, 8) = (s32) ConsoleCmds_pSenderProp;
            M2C_FIELD(temp_r31_2214, f32 *, 4) = temp_f1_2197;
            temp_r30_2220 = M2C_FIELD(arg1, s8 **, 8);
            M2C_FIELD(temp_r31_2214, s8 **, 0) = commandBuffer.Alloc(strlen(temp_r30_2220) + 1);
            strcpy(M2C_FIELD(temp_r31_2214, s8 **, 0), temp_r30_2220);
        }
        return 1.0f;
    }
    Console_Print("Syntax: %s <<delay>> <<command>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdDiv(int arg0, char **arg1) {
    f32 temp_f31_2265;

    if (arg0 == 3) {
        temp_f31_2265 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        return Console_Execute(M2C_FIELD(arg1, s8 **, 4)) / temp_f31_2265;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdMul(int arg0, char **arg1) {
    f32 temp_f31_2302;

    if (arg0 == 3) {
        temp_f31_2302 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        return Console_Execute(M2C_FIELD(arg1, s8 **, 4)) * temp_f31_2302;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdSub(int arg0, char **arg1) {
    f32 temp_f31_2339;

    if (arg0 == 3) {
        temp_f31_2339 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        return Console_Execute(M2C_FIELD(arg1, s8 **, 4)) - temp_f31_2339;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdAdd(int arg0, char **arg1) {
    f32 temp_f31_2376;

    if (arg0 == 3) {
        temp_f31_2376 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        return Console_Execute(M2C_FIELD(arg1, s8 **, 4)) + temp_f31_2376;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdOr(int arg0, char **arg1) {
    u8 var_r31_2410;

    if (arg0 == 3) {
        var_r31_2410 = 0;
        if ((Console_Execute(M2C_FIELD(arg1, s8 **, 4)) != 0.0f) || (Console_Execute(M2C_FIELD(arg1, s8 **, 8)) != 0.0f)) {
            var_r31_2410 = 1;
        }
        if (var_r31_2410 != 0) {
            return 1.0f;
        }
        return 0.0f;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdAnd(int arg0, char **arg1) {
    u8 var_r31_2457;

    if (arg0 == 3) {
        var_r31_2457 = 0;
        if ((Console_Execute(M2C_FIELD(arg1, s8 **, 4)) != 0.0f) && (Console_Execute(M2C_FIELD(arg1, s8 **, 8)) != 0.0f)) {
            var_r31_2457 = 1;
        }
        if (var_r31_2457 != 0) {
            return 1.0f;
        }
        return 0.0f;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdLessEqual(int arg0, char **arg1) {
    f32 temp_f31_2506;

    if (arg0 == 3) {
        temp_f31_2506 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (Console_Execute(M2C_FIELD(arg1, s8 **, 4)) == temp_f31_2506) {
            return 1.0f;
        }
        return 0.0f;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdLess(int arg0, char **arg1) {
    f32 temp_f31_2549;

    if (arg0 == 3) {
        temp_f31_2549 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        if (Console_Execute(M2C_FIELD(arg1, s8 **, 4)) < temp_f31_2549) {
            return 1.0f;
        }
        return 0.0f;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdGreaterEqual(int arg0, char **arg1) {
    f32 temp_f31_2591;

    if (arg0 == 3) {
        temp_f31_2591 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (Console_Execute(M2C_FIELD(arg1, s8 **, 4)) == temp_f31_2591) {
            return 1.0f;
        }
        return 0.0f;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdGreater(int arg0, char **arg1) {
    f32 temp_f31_2634;

    if (arg0 == 3) {
        temp_f31_2634 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        if (Console_Execute(M2C_FIELD(arg1, s8 **, 4)) > temp_f31_2634) {
            return 1.0f;
        }
        return 0.0f;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdEqual(int arg0, char **arg1) {
    f32 temp_f31_2676;

    if (arg0 == 3) {
        temp_f31_2676 = Console_Execute(M2C_FIELD(arg1, s8 **, 8));
        if (Console_Execute(M2C_FIELD(arg1, s8 **, 4)) == temp_f31_2676) {
            return 1.0f;
        }
        return 0.0f;
    }
    Console_Print("Syntax: %s <<value>> <<value>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdNot(int arg0, char **arg1) {
    f32 var_f0_2714;

    if (arg0 == 2) {
        var_f0_2714 = 0.0f;
        if (Console_Execute(M2C_FIELD(arg1, s8 **, 4)) == 0.0f) {
            var_f0_2714 = 1.0f;
        }
        return var_f0_2714;
    }
    Console_Print("Syntax: %s <<condition>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_GetVarByName(signed char *)' does not match
f32 CmdFor(int arg0, char **arg1) {
    ConCmd *temp_r3_2764;
    ConCmd *temp_ret_2764;
    f32 temp_f1_2764;
    f32 temp_f30_2872;
    f32 var_f31_2877;
    s32 temp_r0_2777;
    s32 temp_r0_2823;
    s32 temp_r0_2887;
    s32 temp_r27_2808;
    s32 var_r28_2814;

    if ((arg0 < 5) || (arg0 > 6)) {
        Console_Print("Syntax: %s <<variable>> <<start>> <<end>> [step] <<command>>\n", M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    temp_ret_2764 = Console_GetVarByName(M2C_FIELD(arg1, s8 **, 4));
    temp_f1_2764 = M2C_BITWISE(f32, temp_ret_2764);
    temp_r3_2764 = temp_ret_2764;
    if (temp_r3_2764 == NULL) {
        Console_Print("'%s' is not a console variable\n", M2C_FIELD(arg1, s8 **, 4), temp_f1_2764);
        return 0.0f;
    }
    temp_r0_2777 = M2C_FIELD(temp_r3_2764->unk0, s32 *, 8);
    if ((temp_r0_2777 != 0) && (temp_r0_2777 != 1)) {
        Console_Print("'%s' is an incorrect type (%s) to be used as a loop variable\n", M2C_FIELD(arg1, s8 **, 4), pConTypeNames[temp_r0_2777], "int ", temp_f1_2764);
        return 0.0f;
    }
    temp_r3_2764->SetAsFloat(Console_Execute(M2C_FIELD(arg1, s8 **, 8)));
    if ((s32) M2C_FIELD(temp_r3_2764->unk0, s32 *, 8) == 0) {
        temp_r27_2808 = (s32) Console_Execute(M2C_FIELD(arg1, s8 **, 0xC));
        if (arg0 == 6) {
            var_r28_2814 = (s32) Console_Execute(M2C_FIELD(arg1, s8 **, 0x10));
        } else {
            var_r28_2814 = 1;
        }
        temp_r0_2823 = (arg0 == 6) + 4;
        if (var_r28_2814 > 0) {
loop_15:
            if (temp_r3_2764->AsInt() <= temp_r27_2808) {
                Console_Execute(arg1[temp_r0_2823]);
                temp_r3_2764->SetAsInt(var_r28_2814 + temp_r3_2764->AsInt());
                goto loop_15;
            }
            goto block_37;
        }
        if (var_r28_2814 < 0) {
loop_20:
            if (temp_r3_2764->AsInt() >= temp_r27_2808) {
                Console_Execute(arg1[temp_r0_2823]);
                temp_r3_2764->SetAsInt(var_r28_2814 + temp_r3_2764->AsInt());
                goto loop_20;
            }
            goto block_37;
        }
        Console_Write("Error: step cannot be zero\n", 0);
        return 0.0f;
    }
    temp_f30_2872 = Console_Execute(M2C_FIELD(arg1, s8 **, 0xC));
    if (arg0 == 6) {
        var_f31_2877 = Console_Execute(M2C_FIELD(arg1, s8 **, 0x10));
    } else {
        var_f31_2877 = 1.0f;
    }
    temp_r0_2887 = (arg0 == 6) + 4;
    if (var_f31_2877 > 0.0f) {
loop_29:
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_r3_2764->AsFloat() == temp_f30_2872) {
            Console_Execute(arg1[temp_r0_2887]);
            temp_r3_2764->SetAsFloat(var_f31_2877 + temp_r3_2764->AsFloat());
            goto loop_29;
        }
        goto block_37;
    }
    if (var_f31_2877 < 0.0f) {
loop_34:
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_r3_2764->AsFloat() == temp_f30_2872) {
            Console_Execute(arg1[temp_r0_2887]);
            temp_r3_2764->SetAsFloat(var_f31_2877 + temp_r3_2764->AsFloat());
            goto loop_34;
        }
block_37:
        return fLastResult;
    }
    Console_Write("Error: step cannot be zero\n", 0);
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 CmdIf(int arg0, char **arg1) {
    if ((arg0 < 3) || (arg0 > 4)) {
        Console_Print("Syntax: %s <<condition>> <<truecommand>> [falsecommand]\n", M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    fLastResult = 1.0f;
    if (Console_Execute(M2C_FIELD(arg1, s8 **, 4)) != 0.0f) {
        Console_Execute(M2C_FIELD(arg1, s8 **, 8));
    } else if (arg0 == 4) {
        Console_Execute(M2C_FIELD(arg1, s8 **, 0xC));
    }
    return fLastResult;
}
#endif

#if 0 // DRAFT: function call 'Console_Print(signed char *)' does not match
f32 CmdEcho(int arg0, char **arg1) {
    if (arg0 > 1) {
        Console_Print(M2C_FIELD(arg1, s8 **, 4));
    }
    Console_Print"\n";
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char[5])' does not match
f32 CmdUnbind(int arg0, char **arg1) {
    s32 var_r3_3045;

    if (arg0 > 1) {
        if (stricmp(M2C_FIELD(arg1, s8 **, 4), "-all") == 0) {
            Console_UnbindAll();
        } else {
            if (strlen(M2C_FIELD(arg1, s8 **, 4)) == 1) {
                var_r3_3045 = AsciiToKey((s8) (u8) *M2C_FIELD(arg1, s8 **, 4));
            } else {
                var_r3_3045 = KeyByName(M2C_FIELD(arg1, s8 **, 4));
            }
            if (var_r3_3045 != 0) {
                Console_Unbind((u32) var_r3_3045);
            }
        }
        return 1.0f;
    }
    Console_Print("Syntax: %s <<key|-all>>\n", M2C_FIELD(arg1, s8 **, 0));
    return 0.0f;
}
#endif

#if 0 // DRAFT: function call 'strlen(signed char *)' does not match
f32 CmdBind(int arg0, char **arg1) {
    s32 var_r3_3100;

    if (arg0 < 2) {
        Console_Print("Syntax: %s <<key>> [command]\n", M2C_FIELD(arg1, s8 **, 0));
        return 0.0f;
    }
    if (strlen(M2C_FIELD(arg1, s8 **, 4)) == 1) {
        var_r3_3100 = AsciiToKey((s8) (u8) *M2C_FIELD(arg1, s8 **, 4));
    } else {
        var_r3_3100 = KeyByName(M2C_FIELD(arg1, s8 **, 4));
    }
    if (arg0 > 2) {
        if (var_r3_3100 != 0) {
            Console_Bind((u32) var_r3_3100, M2C_FIELD(arg1, s8 **, 8));
        }
    } else if (arg0 == 2) {
        Console_Write(Console_GetBind((u32) var_r3_3100), 0);
        Console_Write("\n", 0);
    }
    return 1.0f;
}
#endif

#if 0 // DRAFT: function call 'MKArchive_Exists(signed char *, long *)' does not match
f32 CmdExec(int arg0, char **arg1) {
    s32 sp8;
    ConVar *var_r31_3173;
    MKHeap *temp_r3_3164;
    MKHeap *temp_r3_3190;
    s32 temp_r31_3163;

    fLastResult = 1.0f;
    if (arg0 == 1) {
        Console_Print("Syntax: %s <<filename>>\n", M2C_FIELD(arg1, s8 **, 0));
        fLastResult = 0.0f;
    } else {
        sp8 = 0;
        if (MKArchive_Exists(M2C_FIELD(arg1, s8 **, 4), &sp8) != 0) {
            temp_r31_3163 = sp8 + 1;
            temp_r3_3164 = sp8->Current();
            if (temp_r3_3164 != NULL) {
                var_r31_3173 = ((MKHeap *) (temp_r3_3164->Main()))->TAlloc(temp_r31_3163, NULL, 0, 0U);
            } else {
                var_r31_3173 = malloc(temp_r31_3163);
            }
            MKArchive_Load(M2C_FIELD(arg1, s8 **, 4), &sp8, var_r31_3173, -1);
            *(var_r31_3173 + sp8) = 0;
            temp_r3_3190 = ((MKHeap *) (M2C_BITWISE(MKHeap *, Console_ExecuteBuffer((s8 *) var_r31_3173))))->Current();
            if (temp_r3_3190 != NULL) {
                ((MKHeap *) (temp_r3_3190->Main()))->TFree(var_r31_3173, NULL, 0);
            } else {
                free(&var_r31_3173->unk0);
            }
        } else {
            Console_Write("Could not open file '", 0);
            Console_Write(M2C_FIELD(arg1, s8 **, 4), 0);
            Console_Write("'\n", 0);
            fLastResult = 0.0f;
        }
    }
    return fLastResult;
}
#endif

#if 0 // DRAFT: undefined identifier 'keyNames'
s32 KeyByName(char *arg0) {
    M2C_UNK *var_r31_3238;

    var_r31_3238 = &keyNames;
loop_4:
    if ((u32) M2C_FIELD(var_r31_3238, u32 *, 0) == 0U) {
        return 0;
    }
    if (stricmp(arg0) == 0) {
        return M2C_FIELD(var_r31_3238, s32 *, 4);
    }
    var_r31_3238 += 8;
    goto loop_4;
}
#endif

s32 AsciiToKey(char arg0) {
    return asciiToKey[arg0];
}
