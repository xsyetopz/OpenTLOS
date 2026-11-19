#include "common/Source/FileSys.h"
#include "common/Source/MKHeap.h"
#include "common/Source/File.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/Source/Translation.h"
#include "common/Source/Utils.h"
#include "common/Source/system_extras.h"
#include <m2c_macros.h>

M2C_UNK free(s8 *);                                 /* extern */
s8 *malloc(s32);                                    /* extern */
M2C_UNK qsort(s8 *, M2C_UNK, s32 (*)(void *, void *)); /* extern */
M2C_UNK strcat(s8 *, s8 *);                         /* extern */
s32 strcmpi(void *, s8 *);                          /* extern */
u32 strstr(s32, s8 *);                              /* extern */
extern s16 fileOrderId;
extern u32 gMKArchive_ArchiveOverride;
extern s32 nmbrRkvs;
extern u8 (*pExistInterceptHandler)(M2C_UNK);
extern s8 *(*pLoadInterceptHandler)(s8 *, s32 *, void *, s32 *);
extern MKHeap *pMainRkv;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_rkv_0x74'
static struct _struct_rkv_0x74 rkv[8];
#endif
static M2C_UNK asyncReg;
static s8 *key_536[6];
#if 0 // DRAFT: illegal implicit conversion from 'const char[12]' to
static s8 *gpTempMemFilePatterns = "*.gsb;*.qsm";
#endif

#if 0 // DRAFT: undefined identifier 'FindBestEntry'
u32 MKArchive_GetOffset(const char *arg0) {
    s32 sp8;
    RkvFileEntry *temp_r3_15;
    u8 var_r6_17;

    temp_r3_15 = FindBestEntry(arg0, &sp8);
    var_r6_17 = 0;
    if ((temp_r3_15 != NULL) && (sp8 == (s32) (nmbrRkvs - 1))) {
        var_r6_17 = 1;
    }
    if (var_r6_17 != 0) {
        return temp_r3_15->unk8;
    }
    return -1U;
}
#endif

#if 0 // DRAFT: undefined identifier 'rkv'
void MKArchive_Close(int arg0) {
    s32 var_ctr_51;
    s32 var_r4_50;

    if (arg0 >= 0) {
        var_r4_50 = 0;
        var_ctr_51 = nmbrRkvs;
        if ((s32) nmbrRkvs > 0) {
loop_2:
            if (arg0 == (s32) M2C_FIELD((rkv + var_r4_50), s32 *, 0x6C)) {
                M2C_FIELD((rkv + var_r4_50), s8 *, 0x70) = 1;
                return;
            }
            var_r4_50 += 0x74;
            var_ctr_51 -= 1;
            if (var_ctr_51 == 0) {
                goto block_5;
            }
            goto loop_2;
        }
block_5:
        File_Close(arg0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'FindBestEntry'
s32 MKArchive_Open(const char *arg0, int *arg1, bool arg2) {
    s32 sp8;
    RkvFileEntry *temp_r3_88;
    s32 var_r30_87;
    s32 var_r3_99;

    var_r30_87 = -1;
    temp_r3_88 = FindBestEntry(arg0, &sp8);
    if (temp_r3_88 != NULL) {
        MKArchive_SetOrder(temp_r3_88);
        if (arg2 != 0) {
            var_r3_99 = ((RkvTOC *) ((RkvTOC *) &rkv[sp8]))->GetAsyncHandle();
        } else {
            var_r3_99 = File_Open(&rkv[sp8].unk0, 0);
        }
        var_r30_87 = var_r3_99;
        if (var_r3_99 != -1) {
            if (arg1 != NULL) {
                *arg1 = (s32) temp_r3_88->unk4;
            }
            File_Seek(var_r30_87, (s32) temp_r3_88->unk8, 0);
        }
    }
    return var_r30_87;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKArchive_OutputFileOrder() {
    MKHeap *temp_r3_141;
    MKHeap *temp_r3_217;
    MKHeap *temp_r3_296;
    MKHeap *temp_r3_309;
    f32 var_f1_239;
    s16 temp_r5_252;
    s32 temp_r0_163;
    s32 temp_r26_140;
    s32 temp_ret_239;
    s32 var_r26_245;
    s32 var_r3_157;
    s32 var_r3_239;
    s32 var_r5_158;
    s8 *temp_r3_260;
    s8 *var_r26_226;
    s8 *var_r27_186;
    s8 *var_r3_149;
    u32 temp_r0_191;
    u32 temp_r5_214;
    u32 temp_ret_267;
    u32 var_r26_177;
    u32 var_r27_243;
    u32 var_r31_242;
    u32 var_r7_156;
    void *temp_r4_248;

    temp_r26_140 = pMainRkv->unk64 * 4;
    temp_r3_141 = pMainRkv->Current();
    if (temp_r3_141 != NULL) {
        var_r3_149 = ((MKHeap *) (temp_r3_141->Main()))->TAlloc(temp_r26_140, NULL, 0, 0U);
    } else {
        var_r3_149 = malloc(temp_r26_140);
    }
    var_r7_156 = 0U;
    var_r3_157 = 0;
    var_r5_158 = 0;
loop_5:
    if (var_r7_156 < (u32) pMainRkv->unk64) {
        var_r7_156 += 1;
        temp_r0_163 = pMainRkv->unk68 + var_r5_158;
        var_r5_158 += 0x18;
        var_r3_149[var_r3_157] = temp_r0_163;
        var_r3_157 += 4;
        goto loop_5;
    }
    qsort(var_r3_149, 4, FileOrderSortCompare);
    var_r26_177 = 0;
loop_16:
    temp_r5_214 = pMainRkv->unk64;
    if (var_r26_177 < temp_r5_214) {
        if ((u8) M2C_FIELD(*(var_r3_149 + (var_r26_177 * 4)), u8 *, 0x12) != 0) {
            var_r27_186 = (s8 *)1U;
loop_10:
            temp_r0_191 = var_r26_177 + var_r27_186;
            if ((temp_r0_191 < temp_r5_214) && ((u8) M2C_FIELD(*(var_r3_149 + (temp_r0_191 * 4)), u8 *, 0x12) != 0)) {
                var_r27_186 += 1;
                goto loop_10;
            }
            if (var_r27_186 > 1U) {
                qsort(var_r27_186, 4, LanguageSortCompare);
            }
            var_r26_177 = (u32) &var_r27_186[var_r26_177];
        } else {
            var_r26_177 += 1;
        }
        goto loop_16;
    }
    temp_r3_217 = pMainRkv->Current();
    if (temp_r3_217 != NULL) {
        var_r26_226 = ((MKHeap *) (temp_r3_217->Main()))->TAlloc(0x400, NULL, 0, 0U);
    } else {
        var_r26_226 = malloc(0x400);
    }
    File_FileServerOutputFilename"order.txt";
    temp_ret_239 = File_Open(M2C_ERROR(/* Read from unset register $r3 */), 2);
    var_f1_239 = M2C_BITWISE(f32, temp_ret_239);
    var_r3_239 = temp_ret_239;
    if (var_r3_239 >= 0) {
        var_r31_242 = 0U;
        var_r27_243 = 0U;
        *var_r26_226 = 0;
        var_r26_245 = 0;
loop_29:
        if (var_r31_242 < (u32) pMainRkv->unk64) {
            temp_r4_248 = var_r3_149[var_r26_245];
            if ((s32) M2C_FIELD(temp_r4_248, s32 *, 8) != -1) {
                temp_r5_252 = M2C_FIELD(temp_r4_248, s16 *, 0x10);
                if (temp_r5_252 != 0) {
                    temp_r3_260 = Str_Printf("%s // %d
\n", M2C_FIELD(temp_r4_248, s32 *, 0), temp_r5_252, var_f1_239);
                    strcat(var_r26_226, temp_r3_260);
                    temp_ret_267 = strlen(temp_r3_260);
                    var_f1_239 = M2C_BITWISE(f32, temp_ret_267);
                    var_r27_243 += temp_ret_267;
                }
            }
            if (((u32) (var_r31_242 + 1) == (u32) pMainRkv->unk64) || (var_r27_243 > 0x380U)) {
                var_f1_239 = M2C_BITWISE(f32, File_Write(var_r3_239, var_r26_226, (s32) var_r27_243));
                var_r27_243 = 0U;
                *var_r26_226 = 0;
            }
            var_r31_242 += 1;
            var_r26_245 += 4;
            goto loop_29;
        }
        var_r3_239 = File_Close(var_r3_239);
    }
    temp_r3_296 = var_r3_239->Current();
    if (temp_r3_296 != NULL) {
        ((MKHeap *) (temp_r3_296->Main()))->TFree(var_r26_226, NULL, 0);
    } else {
        free(var_r26_226);
    }
    temp_r3_309 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_309 != NULL) {
        ((MKHeap *) (temp_r3_309->Main()))->TFree(var_r3_149, NULL, 0);
        return;
    }
    free(var_r3_149);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const void' to
s32 LanguageSortCompare(const void *arg0, const void *arg1) {
    s32 temp_r3_336;
    void *temp_r4_333;
    void *temp_r5_332;

    temp_r5_332 = *arg0;
    temp_r4_333 = *arg1;
    temp_r3_336 = M2C_FIELD(temp_r5_332, u8 *, 0x12) - M2C_FIELD(temp_r4_333, u8 *, 0x12);
    if (temp_r3_336 == 0) {
        return M2C_FIELD(temp_r5_332, s16 *, 0x10) - M2C_FIELD(temp_r4_333, s16 *, 0x10);
    }
    return temp_r3_336;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const void' to
s32 FileOrderSortCompare(const void *arg0, const void *arg1) {
    return M2C_FIELD(*arg0, s16 *, 0x10) - M2C_FIELD(*arg1, s16 *, 0x10);
}
#endif

s32 MKArchive_Save(const char *arg0, bool arg1, void *arg2, int arg3) {
    s32 temp_r3_370;

    File_FileServerOutputFilename(arg0);
    temp_r3_370 = File_Open(M2C_ERROR(/* Read from unset register $r3 */), (arg1 != 0) + 2);
    if (temp_r3_370 >= 0) {
        File_Write(temp_r3_370, arg2, arg3);
        File_Close(temp_r3_370);
    }
    return temp_r3_370 >> 0x1F;
}

#if 0 // DRAFT: undefined identifier 'FindBestEntry'
s8 *MKArchive_Load(const char *arg0, int *arg1, void *arg2, int arg3) {
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_442;
    MKHeap *temp_r3_457;
    RkvFileEntry *temp_r3_400;
    s32 var_r29_397;
    s32 var_r31_399;
    s8 *temp_r3_420;
    s8 *var_r3_450;
    u8 temp_r3_439;
    void *var_r28_396;

    var_r28_396 = arg2;
    var_r29_397 = arg3;
    var_r31_399 = -1;
    temp_r3_400 = FindBestEntry(arg0, &spC);
    if (temp_r3_400 != NULL) {
        var_r31_399 = rkv[spC].unk60;
    }
    if (((s8 *(*)(s8 *, s32 *, void *, s32 *)) pLoadInterceptHandler) != NULL) {
        sp8 = 0;
        temp_r3_420 = pLoadInterceptHandler(arg0, arg1, var_r28_396, &sp8);
        if (temp_r3_420 != NULL) {
            return temp_r3_420;
        }
    }
    if (temp_r3_400 != NULL) {
        if (arg1 != NULL) {
            *arg1 = (s32) temp_r3_400->unk4;
        }
        if (var_r28_396 == NULL) {
            var_r29_397 = (temp_r3_400->unk4 + 0x20) & 0xFFFFFFE0;
            temp_r3_439 = Util_WildcardPatternMatch(temp_r3_400->unk0, gpTempMemFilePatterns);
            if (temp_r3_439 != 0) {
                temp_r3_442 = temp_r3_439->Current();
                if (temp_r3_442 != NULL) {
                    var_r3_450 = ((MKHeap *) (temp_r3_442->Main()))->TAlloc(var_r29_397, NULL, 0, 0U);
                } else {
                    var_r3_450 = malloc(var_r29_397);
                }
            } else {
                temp_r3_457 = temp_r3_439->Current();
                if (temp_r3_457 != NULL) {
                    var_r3_450 = ((MKHeap *) (temp_r3_457->Current()))->Alloc(var_r29_397, NULL, 0);
                } else {
                    var_r3_450 = malloc(var_r29_397);
                }
            }
            var_r28_396 = var_r3_450;
            var_r3_450[temp_r3_400->unk4] = 0;
        } else if (var_r29_397 < 0) {
            var_r29_397 = (s32) temp_r3_400->unk4;
        }
        if ((u32) temp_r3_400->unk4 != 0) {
            File_Seek(var_r31_399, (s32) temp_r3_400->unk8, 0);
            File_Read(var_r31_399, var_r28_396, (s32) temp_r3_400->unk4, var_r29_397);
        }
        MKArchive_SetOrder(temp_r3_400);
        return (s8 *) var_r28_396;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: function call 'Str_Upper(signed char *)' does not match
void MKArchive_SetOrder(RkvFileEntry *arg0) {
    RkvFileEntry *temp_r3_564;
    RkvFileEntry *temp_r3_612;
    s16 temp_r4_572;
    s16 temp_r4_620;
    s16 temp_r5_521;
    s32 temp_r0_534;
    s8 var_r27_552;
    s8 var_r28_598;
    u32 temp_r3_546;
    u32 temp_r3_592;

    if (((MKHeap *) pMainRkv != NULL) && ((s16) arg0->unk10 <= 0)) {
        temp_r5_521 = fileOrderId;
        fileOrderId = temp_r5_521 + 1;
        arg0->unk10 = temp_r5_521;
        System_GetCommandLineParameter("languageOrder", 0U);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            Str_Upper(arg0->unk0);
            temp_r0_534 = M2C_ERROR(/* Read from unset register $r3 */);
            Translation_GetLanguageName((TranslationLanguage) 0);
            temp_r3_546 = strstr(temp_r0_534, Str_Printf(".%s", M2C_ERROR(/* Read from unset register $r3 */), "*.gsb;*.qsm"));
            if (temp_r3_546 != 0U) {
                var_r27_552 = 2;
                do {
                    Translation_GetLanguageName((TranslationLanguage) var_r27_552);
                    temp_r3_564 = pMainRkv->GetEntry(Str_Printf("%.*s.%s", temp_r3_546 - temp_r0_534, arg0->unk0, M2C_ERROR(/* Read from unset register $r3 */)));
                    if ((temp_r3_564 != NULL) && ((s16) temp_r3_564->unk10 <= 0)) {
                        arg0->unk12 = 1;
                        temp_r4_572 = fileOrderId;
                        fileOrderId = temp_r4_572 + 1;
                        temp_r3_564->unk10 = temp_r4_572;
                        temp_r3_564->unk12 = var_r27_552;
                    }
                    var_r27_552 += 1;
                } while (var_r27_552 < 0xD);
            }
            Translation_GetLanguageCode((TranslationLanguage) 0);
            temp_r3_592 = strstr(temp_r0_534, Str_Printf("%s.", M2C_ERROR(/* Read from unset register $r3 */), "*.gsb;*.qsm"));
            if (temp_r3_592 != 0U) {
                var_r28_598 = 2;
                do {
                    Translation_GetLanguageCode((TranslationLanguage) var_r28_598);
                    temp_r3_612 = pMainRkv->GetEntry(Str_Printf("%.*s%s.%s", temp_r3_592 - temp_r0_534, arg0->unk0, M2C_ERROR(/* Read from unset register $r3 */), temp_r3_592 + 3));
                    if ((temp_r3_612 != NULL) && ((s16) temp_r3_612->unk10 <= 0)) {
                        arg0->unk12 = 1;
                        temp_r4_620 = fileOrderId;
                        fileOrderId = temp_r4_620 + 1;
                        temp_r3_612->unk10 = temp_r4_620;
                        temp_r3_612->unk12 = var_r28_598;
                    }
                    var_r28_598 += 1;
                } while (var_r28_598 < 0xD);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'FindBestEntry'
s32 MKArchive_Exists(const char *arg0, int *arg1) {
    RkvFileEntry *temp_r3_659;

    if ((((u8 (*)(M2C_UNK)) pExistInterceptHandler) != NULL) && (pExistInterceptHandler(0) != 0)) {
        return 1;
    }
    temp_r3_659 = FindBestEntry(arg0, NULL);
    if ((temp_r3_659 != NULL) && (arg1 != NULL)) {
        *arg1 = (s32) temp_r3_659->unk4;
    }
    if ((temp_r3_659 != NULL) && ((s16) temp_r3_659->unk10 == 0)) {
        temp_r3_659->unk10 = -1;
    }
    return temp_r3_659 != NULL;
}
#endif

#if 0 // DRAFT: ')' expected
s8 *(*MKArchive_SetLoadInterceptHandler(void *(*arg0)(const char *, int *, void *, int *)) {
    s8 *(*temp_r0_688)(s8 *, s32 *, void *, s32 *);

    temp_r0_688 = pLoadInterceptHandler;
    pLoadInterceptHandler = (s8 *(*)(s8 *, s32 *, void *, s32 *)) arg0;
    return temp_r0_688;
}
#endif

#if 0 // DRAFT: function call 'File_Open(signed char *, int)' does not match
s32 RkvTOC::GetAsyncHandle() {
    if ((u8) this->unk70 == 0) {
        this->unk6C = File_Open(&this->unk0, 1);
    }
    this->unk70 = 0;
    return this->unk6C;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
RkvFileEntry *RkvTOC::GetEntry(const char *arg0) {
    RkvFileEntry *var_r3_725;
    s8 *temp_r0_727;

    var_r3_725 = NULL;
    temp_r0_727 = this->unk68;
    if (temp_r0_727 != NULL) {
        *key_536 = arg0;
        var_r3_725 = Util_BinarySearch(key_536, temp_r0_727, this->unk64, 0x18, (s32 (*)(void *, void *)) EntryCompare);
        if ((var_r3_725 != NULL) && ((s32) var_r3_725->unk8 < 0)) {
            var_r3_725 = NULL;
        }
    }
    return var_r3_725;
}
#endif

s32 RkvTOC::Deinit() {
    MKHeap *temp_r3_772;
    s8 *temp_r31_771;

    if ((u8) this->unk70 != 0) {
        File_Close(this->unk6C);
        this->unk70 = 0;
        this->unk6C = -1;
    }
    temp_r31_771 = this->unk68;
    temp_r3_772 = ((MKHeap *) (File_Close(this->unk60)))->Current();
    if (temp_r3_772 != NULL) {
        ((MKHeap *) (temp_r3_772->Current()))->Free(temp_r31_771, NULL, 0);
    } else {
        free(temp_r31_771);
    }
    this->unk68 = NULL;
    return 1;
}

#if 0 // DRAFT: expression syntax error
s32 MKArchive_GetAsyncRegistrationStatus() {
    if ((s32) M2C_FIELD(&asyncReg, s32 *, 0x80) != 0) {
        ((RkvTOC *) ((RkvTOC *) &rkv[nmbrRkvs]))->AsyncRegUpdate();
    }
    switch ((s32) M2C_FIELD(&asyncReg, s32 *, 0x80)) { /* irregular */
    case 0:
        return 2;
    case 6:
        M2C_FIELD(&asyncReg, s32 *, 0x80) = 0;
        return -1;
    case 7:
        M2C_FIELD(&asyncReg, s32 *, 0x80) = 0;
        if (strnicmp(&rkv[nmbrRkvs].unk40, "Data_", 5) == 0) {
            pMainRkv = (MKHeap *) &rkv[nmbrRkvs];
        }
        nmbrRkvs += 1;
        return 1;
    default:
        return 0;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void RkvTOC::AsyncRegUpdate() {
    u32 *sp8;
    MKHeap *temp_r3_1022;
    MKHeap *temp_r3_1037;
    MKHeap *temp_r3_1125;
    MKHeap *temp_r3_985;
    s32 temp_r0_1093;
    s32 temp_r11_1096;
    s32 temp_r16_1020;
    s32 temp_r16_984;
    s32 temp_r3_1017;
    s32 temp_r3_1098;
    s32 temp_r3_981;
    s32 temp_r4_1092;
    s32 temp_r5_1088;
    s32 temp_r7_1105;
    s32 temp_r9_1099;
    s32 var_r16_1065;
    s32 var_r30_1067;
    s32 var_r31_1066;
    s8 *temp_r16_1124;
    s8 *temp_r6_1090;
    s8 *var_r3_1030;
    s8 *var_r3_1064;
    s8 *var_r3_993;

    sp8 = &asyncReg + 0xC;
loop_1:
    switch (M2C_FIELD(&asyncReg, u32 *, 0x80)) {
        return;
    case 1:
        if (File_IsBusy(this->unk60) == 0) {
            File_Seek(this->unk60, M2C_FIELD(&asyncReg, s32 *, 0x84), 0);
            M2C_FIELD(&asyncReg, u32 *, 0x80) = 2U;
        default:
block_34:
            if (((u8) M2C_FIELD(&asyncReg, u8 *, 0x90) != 0) && (File_IsBusy(this->unk60) != 0)) {

            } else {
                goto loop_1;
            }
        } else {
            return;
        }
        break;
    case 2:
        if (File_IsBusy(this->unk60) == 0) {
            File_Read(this->unk60, &asyncReg, 0x80, 0);
            M2C_FIELD(&asyncReg, u32 *, 0x80) = 3U;
            goto block_34;
        }
        break;
    case 3:
        if (File_IsBusy(this->unk60) == 0) {
            FlipEndian(&asyncReg + 4);
            FlipEndian(&asyncReg + 8);
            FlipEndian(sp8);
            FlipEndian(&asyncReg + 0x10);
            FlipEndian(&asyncReg + 0x14);
            FlipEndian(&asyncReg + 0x18);
            FlipEndian(&asyncReg + 0x1C);
            FlipEndian(&asyncReg + 0x1E);
            FlipEndian(&asyncReg + 0x20);
            FlipEndian(&asyncReg + 0x22);
            FlipEndian(&asyncReg + 0x24);
            FlipEndian(&asyncReg + 0x26);
            FlipEndian(&asyncReg + 0x28);
            FlipEndian(&asyncReg + 0x2A);
            if ((u32) M2C_FIELD(&asyncReg, u32 *, 0x14) != 0x80U) {
                File_Seek(this->unk60, M2C_FIELD(&asyncReg, s32 *, 0x84) + M2C_FIELD(&asyncReg, u32 *, 0x14), 0);
            }
            M2C_FIELD(&asyncReg, u32 *, 0x80) = 4U;
            goto block_34;
        }
        break;
    case 4:
        temp_r3_981 = File_IsBusy(this->unk60);
        if (temp_r3_981 == 0) {
            temp_r16_984 = M2C_FIELD(&asyncReg, s32 *, 0x18);
            temp_r3_985 = temp_r3_981->Current();
            if (temp_r3_985 != NULL) {
                var_r3_993 = ((MKHeap *) (temp_r3_985->Main()))->TAlloc(temp_r16_984, NULL, 0, 0U);
            } else {
                var_r3_993 = malloc(temp_r16_984);
            }
            M2C_FIELD(&asyncReg, s8 **, 0x8C) = var_r3_993;
            File_Read(this->unk60, var_r3_993, M2C_FIELD(&asyncReg, s32 *, 0x18), 0);
            M2C_FIELD(&asyncReg, u32 *, 0x80) = 5U;
            goto block_34;
        }
        break;
    case 5:
        if (File_IsBusy(this->unk60) == 0) {
            this->unk64 = M2C_FIELD(&asyncReg, s32 *, 4);
            temp_r3_1017 = this->unk64 * 0x18;
            temp_r16_1020 = M2C_FIELD(&asyncReg, u32 *, 8) + temp_r3_1017;
            if ((u8) M2C_FIELD(&asyncReg, u8 *, 0x90) != 0) {
                temp_r3_1022 = temp_r3_1017->Current();
                if (temp_r3_1022 != NULL) {
                    var_r3_1030 = ((MKHeap *) (temp_r3_1022->Main()))->TAlloc(temp_r16_1020, NULL, 0, 0U);
                } else {
                    var_r3_1030 = malloc(temp_r16_1020);
                }
            } else {
                temp_r3_1037 = temp_r3_1017->Current();
                if (temp_r3_1037 != NULL) {
                    var_r3_1030 = ((MKHeap *) (temp_r3_1037->Current()))->Alloc(temp_r16_1020, NULL, 0);
                } else {
                    var_r3_1030 = malloc(temp_r16_1020);
                }
            }
            this->unk68 = var_r3_1030;
            memset(this->unk68, 0, (u32) temp_r16_1020);
            var_r3_1064 = memcpy(this->unk68 + (this->unk64 * 0x18), M2C_FIELD(&asyncReg, s8 **, 0x8C) + (M2C_FIELD(&asyncReg, s32 *, 4) * 0x14), M2C_FIELD(&asyncReg, u32 *, 8));
            var_r16_1065 = 0;
            var_r31_1066 = 0;
            var_r30_1067 = 0;
loop_27:
            if (var_r16_1065 < (s32) this->unk64) {
                FlipEndian((s32 *) &M2C_FIELD(&asyncReg, s8 **, 0x8C)[var_r30_1067]);
                FlipEndian(&M2C_FIELD(&M2C_FIELD(&asyncReg, s8 **, 0x8C)[var_r30_1067], s32 *, 8));
                FlipEndian(&M2C_FIELD(&M2C_FIELD(&asyncReg, s8 **, 0x8C)[var_r30_1067], u32 *, 0xC));
                FlipEndian(&M2C_FIELD(&M2C_FIELD(&asyncReg, s8 **, 0x8C)[var_r30_1067], u32 *, 0x10));
                temp_r5_1088 = var_r31_1066 + 4;
                temp_r6_1090 = this->unk68;
                temp_r4_1092 = var_r30_1067 + 0xC;
                temp_r0_1093 = var_r30_1067 + 0x10;
                temp_r11_1096 = var_r31_1066 + 0x14;
                temp_r6_1090[var_r31_1066] = &temp_r6_1090[(this->unk64 * 0x18) + M2C_FIELD(&asyncReg, s8 **, 0x8C)[var_r30_1067]];
                temp_r3_1098 = var_r31_1066 + 8;
                temp_r9_1099 = var_r31_1066 + 0xC;
                var_r16_1065 += 1;
                var_r31_1066 += 0x18;
                temp_r7_1105 = M2C_FIELD(&M2C_FIELD(&asyncReg, s8 **, 0x8C)[var_r30_1067], s32 *, 8);
                var_r30_1067 += 0x14;
                this->unk68[temp_r5_1088] = temp_r7_1105;
                this->unk68[temp_r3_1098] = (s32) (M2C_FIELD(&asyncReg, s32 *, 0x84) + M2C_FIELD(&asyncReg, s8 **, 0x8C)[temp_r4_1092]);
                this->unk68[temp_r11_1096] = (s32) M2C_FIELD(&asyncReg, s8 **, 0x8C)[temp_r0_1093];
                var_r3_1064 = this->unk68;
                var_r3_1064[temp_r9_1099] = 0;
                goto loop_27;
            }
            temp_r16_1124 = M2C_FIELD(&asyncReg, s8 **, 0x8C);
            temp_r3_1125 = var_r3_1064->Current();
            if (temp_r3_1125 != NULL) {
                ((MKHeap *) (temp_r3_1125->Main()))->TFree(temp_r16_1124, NULL, 0);
            } else {
                free(temp_r16_1124);
            }
            if ((u8) M2C_FIELD(&asyncReg, u8 *, 0x90) != 0) {
                File_Close(this->unk60);
                this->unk60 = File_Open(&this->unk0, 0);
            }
            M2C_FIELD(&asyncReg, u32 *, 0x80) = 7U;
            goto block_34;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match
s32 RkvTOC::Init(const char *arg0, bool arg1, unsigned int arg2, int arg3, const char *arg4) {
    s32 var_r30_1177;
    s8 *var_r3_1182;

    var_r30_1177 = arg3;
    strcpy(&this->unk0, arg0);
    if (arg4 != NULL) {
        var_r3_1182 = arg4;
    } else {
        var_r3_1182 = Str_GetFilenameFromPath(arg0);
    }
    strcpy(&this->unk40, var_r3_1182);
    this->unk60 = -1;
    this->unk64 = -1;
    this->unk68 = NULL;
    this->unk6C = -1;
    this->unk70 = 0;
    if (var_r30_1177 == 0) {
        var_r30_1177 = File_Length(arg0);
    }
    if (var_r30_1177 <= 0) {
        M2C_FIELD(&asyncReg, s32 *, 0x80) = 6;
        return 0;
    }
    M2C_FIELD(&asyncReg, u8 *, 0x90) = arg1;
    M2C_FIELD(&asyncReg, u32 *, 0x84) = arg2;
    M2C_FIELD(&asyncReg, s32 *, 0x88) = var_r30_1177;
    this->unk60 = File_Open(arg0, arg1 != 0);
    M2C_FIELD(&asyncReg, s32 *, 0x80) = 1;
    return 1;
}
#endif

#if 0 // DRAFT: function call 'Str_CompareIgnoreCase(const void, const void)' does not
void EntryCompare(const void *arg0, const void *arg1) {
    Str_CompareIgnoreCase(*arg0, *arg1);
}
#endif

void MKArchive_Update() {

}

#if 0 // DRAFT: undefined identifier 'rkv'
s32 MKArchive_DeregisterArchive(const char *arg0) {
    RkvTOC *temp_r29_1272;
    s32 temp_r5_1290;
    s32 var_r28_1268;
    s32 var_r31_1269;

    var_r28_1268 = 0;
    var_r31_1269 = 0;
loop_8:
    if (var_r28_1268 >= (s32) nmbrRkvs) {
        return 0;
    }
    temp_r29_1272 = rkv + var_r31_1269;
    if (strcmpi(temp_r29_1272 + 0x40, arg0) == 0) {
        if (temp_r29_1272 == (MKHeap *) pMainRkv) {
            pMainRkv = NULL;
        }
        temp_r29_1272->Deinit();
        if (var_r28_1268 < (s32) (nmbrRkvs - 1)) {
            temp_r5_1290 = var_r28_1268 + 1;
            memcpy(temp_r29_1272, &rkv[temp_r5_1290], (nmbrRkvs - temp_r5_1290) * 0x74);
        }
        nmbrRkvs -= 1;
        return 1;
    }
    var_r28_1268 += 1;
    var_r31_1269 += 0x74;
    goto loop_8;
}
#endif

#if 0 // DRAFT: undefined identifier 'FindBestEntry'
s32 MKArchive_RegisterArchive(const char *arg0, bool arg1) {
    s32 sp8;
    RkvFileEntry *temp_r3_1331;
    s32 temp_r3_1365;

    temp_r3_1331 = FindBestEntry(arg0, &sp8);
    if (temp_r3_1331 != NULL) {
        MKArchive_SetOrder(temp_r3_1331);
        ((RkvTOC *) ((RkvTOC *) &rkv[nmbrRkvs]))->Init(&rkv[sp8].unk0, arg1, temp_r3_1331->unk8, (s32) temp_r3_1331->unk4, arg0);
    } else {
        ((RkvTOC *) ((RkvTOC *) &rkv[nmbrRkvs]))->Init(arg0, arg1, 0U, 0, NULL);
    }
    if (arg1 == 0) {
        do {
            temp_r3_1365 = MKArchive_GetAsyncRegistrationStatus();
        } while (temp_r3_1365 == 0);
        return temp_r3_1365 == 1;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'rkv'
RkvFileEntry *FindBestEntry(const char *arg0, int *arg1) {
    RkvFileEntry *temp_r3_1410;
    RkvFileEntry *var_r30_1391;
    s32 var_r29_1392;
    s32 var_r31_1393;

    var_r30_1391 = NULL;
    var_r29_1392 = 0;
    var_r31_1393 = 0;
loop_10:
    if (var_r29_1392 < (s32) nmbrRkvs) {
        if (((u32) gMKArchive_ArchiveOverride == 0U) || (strcmpi(rkv + var_r31_1393) == 0)) {
            temp_r3_1410 = ((RkvTOC *) (rkv + var_r31_1393))->GetEntry(arg0);
            if ((temp_r3_1410 != NULL) && ((var_r30_1391 == NULL) || (((u32) var_r30_1391->unk14 == (u32) temp_r3_1410->unk14) && ((u32) var_r30_1391->unk4 == (u32) temp_r3_1410->unk4)))) {
                var_r30_1391 = temp_r3_1410;
                if (arg1 != NULL) {
                    *arg1 = var_r29_1392;
                }
            }
        }
        var_r29_1392 += 1;
        var_r31_1393 += 0x74;
        goto loop_10;
    }
    return var_r30_1391;
}
#endif

void MKArchive_DeinitModule() {

}

void MKArchive_InitModule() {
    nmbrRkvs = 0;
    pLoadInterceptHandler = NULL;
    pExistInterceptHandler = NULL;
    fileOrderId = 1;
}
