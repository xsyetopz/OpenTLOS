#include "common/Source/MKMemoryCard.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "dolphin/card.h"
#include "dolphin/dvd.h"
#include "dolphin/os.h"
#include "common/Source/Crc.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

M2C_UNK CARDFormatAsync(M2C_UNK);                   /* extern */
void **TEXGet(void *, u32);                         /* extern */
M2C_UNK TEXGetPalette(void **, s8 *);               /* extern */
M2C_UNK TEXReleasePalette(void **);                 /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern s8 bIsMounted;
extern s32 fileSize_610;
extern s32 fileSize_665;
extern s32 fileSize_787;
extern s32 fileSlot_783;
extern u8 init_611;
extern u8 init_666;
extern u8 init_669;
extern u8 init_784;
extern u8 init_788;
extern void *pBuffer_613;
extern void *pBuffer_671;
extern u32 roundedFileSize_668;
static M2C_UNK staticDataBuffer;
static M2C_UNK CardTemplate;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_slotName_0x40'
static struct _struct_slotName_0x40 slotName[0xE];
#endif
static CARDStat fileStat_608;
static CARDFileInfo fileInfo_609;
static CARDStat fileStat_663;
static CARDFileInfo fileInfo_664;
static CARDStat stat_786;
#if 0 // DRAFT: undefined identifier 'SetFinishedStep'
static M2C_UNK lit_303;                                /* unable to generate initializer: unknown type; const */

void Step_CheckFileSystem() {
    s32 temp_r3_34;

    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x34)) { /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        CARDCheckAsync(M2C_FIELD(&CardTemplate, s32 *, 0x38), NULL);
        M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        temp_r3_34 = CARDGetResultCode(M2C_FIELD(&CardTemplate, s32 *, 0x38));
        switch (temp_r3_34) {                       /* switch 2; irregular */
        case -128:                                  /* switch 2 */
            SetFinishedStep(-0x12);
            return;
        case -5:                                    /* switch 2 */
            SetFinishedStep(-0x12);
            return;
        case -3:                                    /* switch 2 */
            SetFinishedStep(-2);
            return;
        case -6:                                    /* switch 2 */
            SetFinishedStep(-7);
            return;
        case -13:                                   /* switch 2 */
            SetFinishedStep(-6);
            return;
        case 0:                                     /* switch 2 */
            SetFinishedStep(0);
            /* fallthrough */
            return;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'SetFinished'
void Step_MountCard() {
    s32 temp_r28_100;
    s32 temp_r3_115;
    s32 temp_r3_151;
    s32 var_r27_108;

    temp_r28_100 = M2C_FIELD(&CardTemplate, s32 *, 0x38);
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x34)) { /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_r27_108 = 0;
        do {
            if (var_r27_108 != temp_r28_100) {
                temp_r3_115 = CARDUnmount(M2C_FIELD(&CardTemplate, s32 *, 0x38));
                if (temp_r3_115 != -2) {
                    switch (temp_r3_115) {          /* switch 2; irregular */
                    case -128:                      /* switch 2 */
                        SetFinished(-1);
                        break;
                    case 0:                         /* switch 2 */
                    case -3:                        /* switch 2 */
                        (&bIsMounted)[var_r27_108] = 0;
                        break;
                    }
                }
            }
            var_r27_108 += 1;
        } while (var_r27_108 < 2);
        CARDMountAsync(temp_r28_100, &CardTemplate + 0x100, callback_MountDetach, NULL);
        M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        temp_r3_151 = CARDGetResultCode(temp_r28_100);
        switch (temp_r3_151) {                      /* switch 3; irregular */
        case -128:                                  /* switch 3 */
            SetFinishedStep(-0x12);
            return;
        case -5:                                    /* switch 3 */
            SetFinishedStep(-0x12);
            return;
        case -2:                                    /* switch 3 */
            SetFinishedStep(-4);
            return;
        case -3:                                    /* switch 3 */
            SetFinishedStep(-2);
            return;
        case 0:                                     /* switch 3 */
        case -13:                                   /* switch 3 */
            SetFinishedStep(0);
            (&bIsMounted)[temp_r28_100] = 1;
            /* fallthrough */
            return;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'SetFinishedStep'
void Step_ProbeDevice() {
    s32 spC;
    s32 sp8;
    s32 temp_r3_218;

    temp_r3_218 = CARDProbeEx(M2C_FIELD(&CardTemplate, s32 *, 0x38), &spC, &sp8);
    switch (temp_r3_218) {                          /* irregular */
    case -128:
        SetFinishedStep(-2);
        return;
    case -3:
        SetFinishedStep(-2);
        return;
    case -2:
        SetFinishedStep(-4);
        return;
    case 0:
        if (sp8 != 0x2000) {
            SetFinishedStep(-5);
            return;
        }
        if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 0xC) != NULL) {
            *M2C_FIELD(&CardTemplate, s32 **, 0xC) = 1;
        }
        M2C_FIELD(&CardTemplate, s32 *, 0) = sp8;
        SetFinishedStep(0);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'WriteMKFileInfo'
void Step_GetDirInfo() {
    CARDFileInfo *temp_r29_305;
    s32 temp_r0_387;
    s32 temp_r0_472;
    s32 temp_r0_531;
    s32 temp_r0_644;
    s32 temp_r24_575;
    s32 temp_r27_302;
    s32 temp_r3_347;
    s32 temp_r3_423;
    s32 temp_r3_494;
    s32 temp_r3_620;
    s32 temp_r4_574;
    s32 var_r24_324;
    s32 var_r25_325;
    u32 temp_r24_553;
    u8 var_r26_306;

    if ((s8) init_784 == 0) {
        fileSlot_783 = 0;
        init_784 = 1;
    }
    if ((s8) init_788 == 0) {
        fileSize_787 = 0;
        init_788 = 1;
    }
    temp_r27_302 = M2C_FIELD(&CardTemplate, s32 *, 0x38);
    temp_r29_305 = (CARDFileInfo *) (&CardTemplate + 0xD0);
    var_r26_306 = 0;
loop_99:
    if (var_r26_306 == 0) {
        switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x34)) { /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            var_r24_324 = 0;
            var_r25_325 = 0;
            do {
                WriteMKFileInfo(M2C_FIELD(&CardTemplate, s32 *, 0x20) + var_r25_325, NULL);
                var_r24_324 += 1;
                var_r25_325 += 0xC0;
            } while (var_r24_324 < 0xE);
            fileSlot_783 = 0;
            CARDOpen(temp_r27_302, &slotName->unk0, temp_r29_305);
            M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
            break;
        case 1:                                     /* switch 1 */
            var_r26_306 = 1;
            temp_r3_347 = CARDGetResultCode(temp_r27_302);
            switch (temp_r3_347) {                  /* switch 2; irregular */
            case -128:                              /* switch 2 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 2 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 2 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 2 */
                temp_r0_387 = fileSlot_783 + 1;
                fileSlot_783 = temp_r0_387;
                if (temp_r0_387 < 0xE) {
                    var_r26_306 = 0;
                    CARDOpen(temp_r27_302, &slotName[temp_r0_387].unk0, temp_r29_305);
                    M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
                } else {
                    SetFinishedStep(0);
                }
                break;
            case -6:                                /* switch 2 */
                SetFinishedStep(-7);
                break;
            case 0:                                 /* switch 2 */
                var_r26_306 = 0;
                CARDGetStatus(temp_r27_302, M2C_FIELD(&CardTemplate, s32 *, 0xD4), &stat_786);
                M2C_FIELD(&CardTemplate, s32 *, 0x34) = 2;
                break;
            }
            break;
        case 2:                                     /* switch 1 */
            var_r26_306 = 1;
            temp_r3_423 = CARDGetResultCode(temp_r27_302);
            switch (temp_r3_423) {                  /* switch 3; irregular */
            case -128:                              /* switch 3 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 3 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 3 */
                SetFinishedStep(-2);
                break;
            case 0:                                 /* switch 3 */
                fileSize_787 = (s32) stat_786.length;
                SetDataBuffer((s32) stat_786.length);
                var_r26_306 = 0;
                CARDReadAsync(temp_r29_305, M2C_FIELD(&CardTemplate, void **, 0x48), fileSize_787, 0, NULL);
                M2C_FIELD(&CardTemplate, s32 *, 0x34) = 3;
                break;
            case -4:                                /* switch 3 */
                temp_r0_472 = fileSlot_783 + 1;
                fileSlot_783 = temp_r0_472;
                if (temp_r0_472 < 0xE) {
                    var_r26_306 = 0;
                    CARDOpen(temp_r27_302, &slotName[temp_r0_472].unk0, temp_r29_305);
                    M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
                } else {
                    SetFinishedStep(0);
                }
                break;
            }
            break;
        case 3:                                     /* switch 1 */
            var_r26_306 = 1;
            temp_r3_494 = CARDGetResultCode(temp_r27_302);
            switch (temp_r3_494) {                  /* switch 4; irregular */
            case -128:                              /* switch 4 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 4 */
            case -14:                               /* switch 4 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 4 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 4 */
                temp_r0_531 = fileSlot_783 + 1;
                fileSlot_783 = temp_r0_531;
                if (temp_r0_531 < 0xE) {
                    var_r26_306 = 0;
                    CARDOpen(temp_r27_302, &slotName[temp_r0_531].unk0, temp_r29_305);
                    M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
                } else {
                    SetFinishedStep(0);
                }
                break;
            case 0:                                 /* switch 4 */
                temp_r24_553 = M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x48), u32 *, 8);
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x48), u32 *, 8) = 0U;
                if (Crc_Calculate(M2C_FIELD(&CardTemplate, void **, 0x48), fileSize_787) != temp_r24_553) {
                    *(M2C_FIELD(&CardTemplate, s32 *, 0x20) + ((fileSlot_783 * 0xC0) + 0xA4)) = 1;
                    *(M2C_FIELD(&CardTemplate, s32 *, 0x20) + ((fileSlot_783 * 0xC0) + 0xA5)) = 1;
                } else {
                    temp_r4_574 = M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x48), s32 *, 4);
                    temp_r24_575 = M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x48), s32 *, 0);
                    if ((temp_r4_574 < 0) || (temp_r24_575 < 0) || ((s32) (temp_r4_574 + temp_r24_575) > (s32) fileSize_787)) {
                        *(M2C_FIELD(&CardTemplate, s32 *, 0x20) + ((fileSlot_783 * 0xC0) + 0xA4)) = 1;
                        *(M2C_FIELD(&CardTemplate, s32 *, 0x20) + ((fileSlot_783 * 0xC0) + 0xA5)) = 1;
                    } else {
                        WriteMKFileInfo(M2C_FIELD(&CardTemplate, s32 *, 0x20) + (fileSlot_783 * 0xC0), &stat_786);
                        *(M2C_FIELD(&CardTemplate, s32 *, 0x20) + ((fileSlot_783 * 0xC0) + 0x9C)) = temp_r24_575;
                    }
                }
                var_r26_306 = 0;
                CARDClose(temp_r29_305);
                M2C_FIELD(&CardTemplate, s32 *, 0x34) = 4;
                break;
            }
            break;
        case 4:                                     /* switch 1 */
            var_r26_306 = 1;
            temp_r3_620 = CARDGetResultCode(temp_r27_302);
            switch (temp_r3_620) {                  /* switch 5; irregular */
            case -2:                                /* switch 5 */
                break;
            case -128:                              /* switch 5 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 5 */
                SetFinishedStep(-2);
                break;
            case 0:                                 /* switch 5 */
                temp_r0_644 = fileSlot_783 + 1;
                fileSlot_783 = temp_r0_644;
                if (temp_r0_644 < 0xE) {
                    var_r26_306 = 0;
                    CARDOpen(temp_r27_302, &slotName[temp_r0_644].unk0, temp_r29_305);
                    M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
                } else {
                    SetFinishedStep(0);
                }
                break;
            }
            break;
        }
        goto loop_99;
    }
}
#endif

#if 0 // DRAFT: function call 'CARDDeleteAsync(long, signed char *, int)' does not match 'CARDDeleteAsync(long, const char *, void (*)(long, long))'
void Step_DeleteFile() {
    s32 temp_r30_682;
    s32 temp_r3_698;

    temp_r30_682 = M2C_FIELD(&CardTemplate, s32 *, 0x38);
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x34)) { /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        CARDDeleteAsync(temp_r30_682, M2C_FIELD(&CardTemplate, s8 **, 0x44), NULL);
        M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        temp_r3_698 = CARDGetResultCode(temp_r30_682);
        switch (temp_r3_698) {                      /* switch 2; irregular */
        case -128:                                  /* switch 2 */
            SetFinishedStep(-1);
            return;
        case -10:                                   /* switch 2 */
            SetFinishedStep(-1);
            return;
        case -5:                                    /* switch 2 */
            SetFinishedStep(-0x12);
            return;
        case -3:                                    /* switch 2 */
            SetFinishedStep(-2);
            return;
        case -4:                                    /* switch 2 */
        case 0:                                     /* switch 2 */
            SetFinishedStep(0);
            /* fallthrough */
            return;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'RoundUp'
void Step_WriteFile() {
    s32 sp8;
    s32 temp_r0_1089;
    s32 temp_r0_1110;
    s32 temp_r10_1082;
    s32 temp_r28_780;
    s32 temp_r3_1134;
    s32 temp_r3_1197;
    s32 temp_r3_1279;
    s32 temp_r3_1361;
    s32 temp_r3_798;
    s32 temp_r3_803;
    s32 temp_r3_859;
    s32 temp_r3_879;
    s32 temp_r3_945;
    s32 temp_r3_997;
    s32 temp_r5_1086;
    s32 temp_r6_1112;
    s32 temp_r7_1087;
    s32 temp_r9_1080;
    s32 var_ctr_1075;
    s32 var_ctr_1106;
    s32 var_r11_1069;
    s32 var_r3_1071;
    s32 var_r3_1104;
    s32 var_r4_1072;
    u32 temp_r3_806;
    u32 temp_r6_1323;
    u8 var_r29_785;
    void *temp_r3_816;
    void *temp_r3_833;
    void *temp_r3_853;

    if ((s8) init_666 == 0) {
        fileSize_665 = 0;
        init_666 = 1;
    }
    if ((s8) init_669 == 0) {
        roundedFileSize_668 = 0;
        init_669 = 1;
    }
    temp_r28_780 = M2C_FIELD(&CardTemplate, s32 *, 0x38);
    var_r29_785 = 0;
loop_156:
    if (var_r29_785 == 0) {
        switch (M2C_FIELD(&CardTemplate, u32 *, 0x34)) { /* switch 1 */
        case 0:                                     /* switch 1 */
            temp_r3_798 = MKMemoryCard_CalculateFileSize();
            fileSize_665 = temp_r3_798;
            temp_r3_803 = temp_r3_798 + M2C_FIELD(&CardTemplate, u32 *, 0x40);
            fileSize_665 = temp_r3_803;
            temp_r3_806 = RoundUp(temp_r3_803, M2C_FIELD(&CardTemplate, s32 *, 0));
            roundedFileSize_668 = temp_r3_806;
            SetDataBuffer((s32) temp_r3_806);
            pBuffer_671 = M2C_FIELD(&CardTemplate, void **, 0x48);
            memcpy(M2C_FIELD(&CardTemplate, void **, 0x48), &CardTemplate + 0x50, 0xCU);
            temp_r3_816 = pBuffer_671 + 0xC;
            pBuffer_671 = temp_r3_816;
            if ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x4C) > 0) {
                memcpy(temp_r3_816, M2C_FIELD(&CardTemplate, void **, 0x10), (u32) M2C_FIELD(&CardTemplate, s32 *, 0x4C));
                pBuffer_671 += M2C_FIELD(&CardTemplate, s32 *, 0x4C);
            }
            memcpy(pBuffer_671, &CardTemplate + 0x90, 0x40U);
            temp_r3_833 = pBuffer_671 + 0x40;
            pBuffer_671 = temp_r3_833;
            if (((void *) M2C_FIELD(&CardTemplate, void **, 0x60) != NULL) && ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x5C) > 0)) {
                memcpy(temp_r3_833, M2C_FIELD(&CardTemplate, void **, 0x60), (u32) M2C_FIELD(&CardTemplate, s32 *, 0x5C));
                pBuffer_671 += M2C_FIELD(&CardTemplate, s32 *, 0x5C);
            }
            memcpy(pBuffer_671, M2C_FIELD(&CardTemplate, void **, 0x68), M2C_FIELD(&CardTemplate, u32 *, 0x64));
            temp_r3_853 = pBuffer_671 + M2C_FIELD(&CardTemplate, u32 *, 0x64);
            pBuffer_671 = temp_r3_853;
            memcpy(temp_r3_853, M2C_FIELD(&CardTemplate, void **, 0x10), M2C_FIELD(&CardTemplate, u32 *, 0x40));
            temp_r3_859 = Crc_Calculate(M2C_FIELD(&CardTemplate, void **, 0x48), (s32) roundedFileSize_668);
            M2C_FIELD(&CardTemplate, s32 *, 0x58) = temp_r3_859;
            M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x48), s32 *, 8) = temp_r3_859;
            CARDCreateAsync(temp_r28_780, M2C_FIELD(&CardTemplate, s8 **, 0x44), roundedFileSize_668, &fileInfo_664, NULL);
            M2C_FIELD(&CardTemplate, u32 *, 0x34) = 1U;
            DCFlushRange(M2C_FIELD(&CardTemplate, void **, 0x48), roundedFileSize_668);
            break;
        case 1:                                     /* switch 1 */
            var_r29_785 = 1;
            temp_r3_879 = CARDGetResultCode(temp_r28_780);
            switch (temp_r3_879) {                  /* switch 2; irregular */
            case -128:                              /* switch 2 */
                SetFinishedStep(-1);
                break;
            case -5:                                /* switch 2 */
                SetFinishedStep(-0x12);
                break;
            case -3:                                /* switch 2 */
                SetFinishedStep(-2);
                break;
            case -7:                                /* switch 2 */
                SetFinishedStep(-8);
                break;
            case -8:                                /* switch 2 */
                SetFinishedStep(-0xA);
                break;
            case -9:                                /* switch 2 */
                SetFinishedStep(-0xB);
                break;
            case 0:                                 /* switch 2 */
                var_r29_785 = 0;
                CARDGetStatus(temp_r28_780, fileInfo_664.fileNo, &fileStat_663);
                M2C_FIELD(&CardTemplate, u32 *, 0x34) = 2U;
                break;
            }
            break;
        case 2:                                     /* switch 1 */
            var_r29_785 = 1;
            temp_r3_945 = CARDGetResultCode(temp_r28_780);
            switch (temp_r3_945) {                  /* switch 3; irregular */
            case -128:                              /* switch 3 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 3 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 3 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 3 */
                SetFinishedStep(-9);
                break;
            case 0:                                 /* switch 3 */
                var_r29_785 = 0;
                CARDWriteAsync(&fileInfo_664, M2C_FIELD(&CardTemplate, void **, 0x48), (s32) roundedFileSize_668, 0, NULL);
                M2C_FIELD(&CardTemplate, u32 *, 0x34) = 3U;
                break;
            }
            break;
        case 3:                                     /* switch 1 */
            var_r29_785 = 1;
            temp_r3_997 = CARDGetResultCode(temp_r28_780);
            switch (temp_r3_997) {                  /* switch 4; irregular */
            case -128:                              /* switch 4 */
                SetFinishedStep(-1);
                break;
            case -4:                                /* switch 4 */
            case -14:                               /* switch 4 */
                SetFinishedStep(-1);
                break;
            case -5:                                /* switch 4 */
                SetFinishedStep(-0x12);
                break;
            case -3:                                /* switch 4 */
                SetFinishedStep(-2);
                break;
            case 0:                                 /* switch 4 */
                var_r29_785 = 0;
                fileStat_663.commentAddr = M2C_FIELD(&CardTemplate, s32 *, 0x4C) + 0xC;
                if (((void *) M2C_FIELD(&CardTemplate, void **, 0x60) != NULL) && ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x5C) > 0)) {
                    fileStat_663.bannerFormat = (fileStat_663.bannerFormat & 0xFFFFFFFC) | 2;
                } else {
                    fileStat_663.bannerFormat &= 0xFC;
                }
                var_r11_1069 = 0;
                fileStat_663.iconAddr = M2C_FIELD(&CardTemplate, s32 *, 0x4C) + 0x4C;
                var_r3_1071 = 0;
                var_r4_1072 = 0;
                fileStat_663.bannerFormat &= 0xFFFFFFFB;
                var_ctr_1075 = M2C_FIELD(&CardTemplate, s32 *, 0x6C);
                if ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x6C) > 0) {
                    do {
                        temp_r9_1080 = 3 << var_r4_1072;
                        temp_r10_1082 = ~(temp_r9_1080 | temp_r9_1080);
                        var_r11_1069 += 1;
                        temp_r5_1086 = M2C_FIELD((&CardTemplate + var_r3_1071), s32 *, 0x70) << var_r4_1072;
                        temp_r7_1087 = fileStat_663.iconFormat & temp_r10_1082;
                        var_r3_1071 += 4;
                        temp_r0_1089 = fileStat_663.iconSpeed & temp_r10_1082;
                        var_r4_1072 += 2;
                        fileStat_663.iconFormat = temp_r7_1087 | temp_r5_1086;
                        fileStat_663.iconSpeed = temp_r0_1089 | temp_r9_1080;
                        var_ctr_1075 -= 1;
                    } while (var_ctr_1075 != 0);
                }
                var_r3_1104 = M2C_FIELD(&CardTemplate, s32 *, 0x6C) * 2;
                fileStat_663.iconSpeed &= ~(3 << (var_r11_1069 * 2));
                var_ctr_1106 = 8 - M2C_FIELD(&CardTemplate, s32 *, 0x6C);
                if ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x6C) < 8) {
                    do {
                        temp_r0_1110 = 3 << var_r3_1104;
                        temp_r6_1112 = ~(temp_r0_1110 | temp_r0_1110);
                        fileStat_663.iconFormat &= temp_r6_1112;
                        var_r3_1104 += 2;
                        fileStat_663.iconSpeed &= temp_r6_1112;
                        var_ctr_1106 -= 1;
                    } while (var_ctr_1106 != 0);
                }
                CARDSetStatusAsync(temp_r28_780, fileInfo_664.fileNo, &fileStat_663, NULL);
                M2C_FIELD(&CardTemplate, u32 *, 0x34) = 4U;
                break;
            }
            break;
        case 4:                                     /* switch 1 */
            var_r29_785 = 1;
            temp_r3_1134 = CARDGetResultCode(temp_r28_780);
            switch (temp_r3_1134) {                 /* switch 5; irregular */
            case -128:                              /* switch 5 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 5 */
                SetFinishedStep(-1);
                break;
            case -5:                                /* switch 5 */
                SetFinishedStep(-0x12);
                break;
            case -3:                                /* switch 5 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 5 */
                SetFinishedStep(-9);
                break;
            case 0:                                 /* switch 5 */
                var_r29_785 = 0;
                SetDataBuffer((s32) roundedFileSize_668);
                pBuffer_671 = M2C_FIELD(&CardTemplate, void **, 0x48);
                CARDReadAsync(&fileInfo_664, M2C_FIELD(&CardTemplate, void **, 0x48), (s32) roundedFileSize_668, 0, NULL);
                M2C_FIELD(&CardTemplate, u32 *, 0x34) = 5U;
                break;
            }
            break;
        case 5:                                     /* switch 1 */
            var_r29_785 = 1;
            temp_r3_1197 = CARDGetResultCode(temp_r28_780);
            switch (temp_r3_1197) {                 /* switch 6; irregular */
            case -128:                              /* switch 6 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 6 */
            case -14:                               /* switch 6 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 6 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 6 */
                SetFinishedStep(-9);
                break;
            case -11:                               /* switch 6 */
                SetFinishedStep(-0x10);
                break;
            case 0:                                 /* switch 6 */
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x48), s32 *, 8) = 0;
                if (Crc_Calculate(M2C_FIELD(&CardTemplate, void **, 0x48), (s32) roundedFileSize_668) != (u32) M2C_FIELD(&CardTemplate, s32 *, 0x58)) {
                    SetFinishedStep(-0x10);
                } else {
                    var_r29_785 = 0;
                    if ((void *) M2C_FIELD(&CardTemplate, void **, 0x24) != NULL) {
                        CARDGetStatus(temp_r28_780, fileInfo_664.fileNo, &fileStat_663);
                        M2C_FIELD(&CardTemplate, u32 *, 0x34) = 6U;
                    } else {
                        CARDClose(&fileInfo_664);
                        M2C_FIELD(&CardTemplate, u32 *, 0x34) = 7U;
                    }
                }
                break;
            }
            break;
        case 6:                                     /* switch 1 */
            var_r29_785 = 1;
            temp_r3_1279 = CARDGetResultCode(temp_r28_780);
            switch (temp_r3_1279) {                 /* switch 7; irregular */
            case -128:                              /* switch 7 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 7 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 7 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 7 */
                SetFinishedStep(-9);
                break;
            case 0:                                 /* switch 7 */
                temp_r6_1323 = (u32) *(u32 *)0x800000F8 >> 2U;
                OSTicksToCalendarTime(MULTU_HI(fileStat_663.time, temp_r6_1323) + (0 * temp_r6_1323) + (fileStat_663.time * 0), (OSCalendarTime *) (fileStat_663.time * temp_r6_1323));
                var_r29_785 = 0;
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x24), s32 *, 0) = sp10;
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x24), s32 *, 4) = spC;
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x24), s32 *, 8) = sp8;
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x24), s32 *, 0xC) = sp28;
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x24), s32 *, 0x10) = sp14;
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x24), s32 *, 0x14) = sp18;
                M2C_FIELD(M2C_FIELD(&CardTemplate, void **, 0x24), s32 *, 0x18) = sp1C;
                CARDClose(&fileInfo_664);
                M2C_FIELD(&CardTemplate, u32 *, 0x34) = 7U;
                break;
            }
            break;
        case 7:                                     /* switch 1 */
            var_r29_785 = 1;
            temp_r3_1361 = CARDGetResultCode(temp_r28_780);
            switch (temp_r3_1361) {                 /* switch 8; irregular */
            case -2:                                /* switch 8 */
                break;
            case -128:                              /* switch 8 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 8 */
                SetFinishedStep(-2);
                break;
            case 0:                                 /* switch 8 */
                SetFinishedStep(0);
                break;
            }
            break;
        }
        goto loop_156;
    }
}
#endif

#if 0 // DRAFT: function call 'CARDOpen(long, signed char *, CARDFileInfo *)' does not match 'CARDOpen(long, const char *, CARDFileInfo *)'
void Step_ReadFile() {
    s32 temp_r28_1417;
    s32 temp_r3_1451;
    s32 temp_r3_1510;
    s32 temp_r3_1566;
    s32 temp_r3_1658;
    s32 temp_r5_1632;
    s32 temp_r6_1631;
    u32 temp_r26_1619;
    u8 var_r27_1421;

    if ((s8) init_611 == 0) {
        fileSize_610 = 0;
        init_611 = 1;
    }
    temp_r28_1417 = M2C_FIELD(&CardTemplate, s32 *, 0x38);
    var_r27_1421 = 0;
loop_90:
    if (var_r27_1421 == 0) {
        switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x34)) { /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            CARDOpen(temp_r28_1417, M2C_FIELD(&CardTemplate, s8 **, 0x44), &fileInfo_609);
            M2C_FIELD(&CardTemplate, s32 *, 0x34) = 1;
            break;
        case 1:                                     /* switch 1 */
            var_r27_1421 = 1;
            temp_r3_1451 = CARDGetResultCode(temp_r28_1417);
            switch (temp_r3_1451) {                 /* switch 2; irregular */
            case -128:                              /* switch 2 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 2 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 2 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 2 */
                SetFinishedStep(-9);
                break;
            case -6:                                /* switch 2 */
                SetFinishedStep(-7);
                break;
            case 0:                                 /* switch 2 */
                var_r27_1421 = 0;
                CARDGetStatus(temp_r28_1417, fileInfo_609.fileNo, &fileStat_608);
                M2C_FIELD(&CardTemplate, s32 *, 0x34) = 2;
                break;
            }
            break;
        case 2:                                     /* switch 1 */
            var_r27_1421 = 1;
            temp_r3_1510 = CARDGetResultCode(temp_r28_1417);
            switch (temp_r3_1510) {                 /* switch 3; irregular */
            case -128:                              /* switch 3 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 3 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 3 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 3 */
                SetFinishedStep(-9);
                break;
            case 0:                                 /* switch 3 */
                fileSize_610 = (s32) fileStat_608.length;
                SetDataBuffer((s32) fileStat_608.length);
                pBuffer_613 = M2C_FIELD(&CardTemplate, void **, 0x48);
                var_r27_1421 = 0;
                CARDReadAsync(&fileInfo_609, M2C_FIELD(&CardTemplate, void **, 0x48), fileSize_610, 0, NULL);
                M2C_FIELD(&CardTemplate, s32 *, 0x34) = 3;
                break;
            }
            break;
        case 3:                                     /* switch 1 */
            var_r27_1421 = 1;
            temp_r3_1566 = CARDGetResultCode(temp_r28_1417);
            switch (temp_r3_1566) {                 /* switch 4; irregular */
            case -128:                              /* switch 4 */
                SetFinishedStep(-1);
                break;
            case -10:                               /* switch 4 */
            case -14:                               /* switch 4 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 4 */
                SetFinishedStep(-2);
                break;
            case -4:                                /* switch 4 */
                SetFinishedStep(-9);
                break;
            case -11:                               /* switch 4 */
                SetFinishedStep(-1);
                /* fallthrough */
            case 0:                                 /* switch 4 */
                var_r27_1421 = 0;
                M2C_FIELD(&CardTemplate, s32 *, 0x34) = 4;
                break;
            }
            break;
        case 4:                                     /* switch 1 */
            temp_r26_1619 = M2C_FIELD(pBuffer_613, u32 *, 8);
            M2C_FIELD(pBuffer_613, u32 *, 8) = 0U;
            if (Crc_Calculate(pBuffer_613, fileSize_610) != temp_r26_1619) {
                SetFinishedStep(-0x10);
            } else {
                temp_r6_1631 = M2C_FIELD(pBuffer_613, s32 *, 4);
                temp_r5_1632 = M2C_FIELD(pBuffer_613, s32 *, 0);
                if ((temp_r6_1631 < 0) || (temp_r5_1632 < 0) || ((s32) (temp_r6_1631 + temp_r5_1632) > (s32) fileSize_610)) {
                    SetFinishedStep(-0x10);
                } else {
                    memcpy(M2C_FIELD(&CardTemplate, void **, 0x10), pBuffer_613 + temp_r6_1631, (u32) temp_r5_1632);
                    CARDClose(&fileInfo_609);
                    M2C_FIELD(&CardTemplate, s32 *, 0x34) = 5;
                }
            }
            break;
        case 5:                                     /* switch 1 */
            var_r27_1421 = 1;
            temp_r3_1658 = CARDGetResultCode(temp_r28_1417);
            switch (temp_r3_1658) {                 /* switch 5; irregular */
            case -2:                                /* switch 5 */
                break;
            case -128:                              /* switch 5 */
                SetFinishedStep(-1);
                break;
            case -3:                                /* switch 5 */
                SetFinishedStep(-2);
                break;
            case 0:                                 /* switch 5 */
                SetFinishedStep(0);
                break;
            }
            break;
        }
        goto loop_90;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MULTU_HI'
void WriteMKFileInfo(MKMemoryCardFileInfo *arg0, CARDStat *arg1) {
    s32 sp8;
    u32 temp_r6_1709;
    u32 temp_r8_1704;

    if (arg1 != NULL) {
        temp_r8_1704 = arg1->time;
        temp_r6_1709 = (u32) *(u32 *)0x800000F8 >> 2U;
        OSTicksToCalendarTime(MULTU_HI(temp_r8_1704, temp_r6_1709) + (0 * temp_r6_1709) + (temp_r8_1704 * 0), (OSCalendarTime *) (temp_r8_1704 * temp_r6_1709));
        arg0->unk80 = sp10;
        arg0->unk84 = spC;
        arg0->unk88 = sp8;
        arg0->unk8C = sp28;
        arg0->unk90 = sp14;
        arg0->unk94 = sp18;
        arg0->unk98 = sp1C;
        arg0->unkA4 = 1;
        arg0->unkA5 = 0;
        arg0->unk9C = arg1->length;
        arg0->unkA0 = (u32) arg1->length / (u32) M2C_FIELD(&CardTemplate, u32 *, 0);
        memcpy(arg0, M2C_FIELD(&CardTemplate, s32 *, 0x48) + 0xC, 0x80U);
        return;
    }
    arg0->unkA0 = 0;
    arg0->unkA4 = 0;
    arg0->unk9C = 0;
    arg0->unk80 = 0;
    arg0->unk84 = 0;
    arg0->unk88 = 0;
    arg0->unk8C = 0;
    arg0->unk90 = 0;
    arg0->unk94 = 0;
    arg0->unk98 = 0;
    arg0->unkA5 = 0;
}
#endif

u32 RoundUp(int arg0, int arg1) {
    return ((s32) (arg0 + (arg1 - 1)) / arg1) * arg1;
}

void SetDataBuffer(int arg0) {
    M2C_FIELD(&CardTemplate, M2C_UNK **, 0x48) = &staticDataBuffer;
    memset(&staticDataBuffer, 0, (u32) arg0);
}

#if 0 // DRAFT: undefined identifier 'SetFinished'
void callback_MountDetach(long arg0, long arg1) {
    (&bIsMounted)[arg0] = 0;
    if (((s32) M2C_FIELD(&CardTemplate, s32 *, 0x2C) != 0) && (arg0 == (s32) M2C_FIELD(&CardTemplate, s32 *, 0x38))) {
        SetFinished(-3);
    }
}
#endif

void SetStarted(int arg0, int arg1) {
    M2C_FIELD(&CardTemplate, s32 *, 0x38) = arg0;
    M2C_FIELD(&CardTemplate, s32 *, 0x2C) = arg1;
    M2C_FIELD(&CardTemplate, s32 *, 0x28) = 1;
}

void SetFinished(int arg0) {
    M2C_FIELD(&CardTemplate, s32 *, 0x28) = arg0;
    M2C_FIELD(&CardTemplate, s32 *, 0x2C) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x34) = 0;
}

void SetFinishedStep(int arg0) {
    if (arg0 == 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x34) = 0;
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = (s32) (M2C_FIELD(&CardTemplate, s32 *, 0x30) + 1);
        return;
    }
    SetFinished(arg0);
}

s32 MKMemoryCard_CalculateFileSize() {
    return M2C_FIELD(&CardTemplate, s32 *, 0x4C) + 0x4C + M2C_FIELD(&CardTemplate, s32 *, 0x5C) + M2C_FIELD(&CardTemplate, s32 *, 0x64);
}

void *LoadIconFile(const char *arg0, int *arg1, int *arg2, unsigned long *arg3) {
    M2C_UNK spC;
    void *sp8;
    s32 temp_r26_1981;
    s32 var_ctr_1967;
    s32 var_r23_1996;
    s32 var_r26_1917;
    s32 var_r27_1998;
    s32 var_r31_1999;
    s32 var_r3_1966;
    u32 temp_r0_1930;
    u32 temp_r0_1938;
    u32 var_r24_1997;
    u32 var_r30_1912;
    u32 var_r31_1918;
    void **temp_r3_1924;
    void *temp_r25_2004;
    void *temp_r5_1929;
    void *temp_r5_1972;
    void *temp_r6_1927;
    void *var_r3_1989;

    sp8 = NULL;
    TEXGetPalette(&sp8, Str_Printf("%s%s", "/icons/", "icon.tpl"));
    var_r30_1912 = M2C_FIELD(sp8, u32 *, 4);
    if (var_r30_1912 > 8U) {
        var_r30_1912 = 8U;
    }
    var_r26_1917 = 0;
    var_r31_1918 = 0;
    *arg1 = 0;
loop_10:
    if (var_r31_1918 < var_r30_1912) {
        temp_r3_1924 = TEXGet(sp8, var_r31_1918);
        if (temp_r3_1924 != NULL) {
            temp_r6_1927 = *temp_r3_1924;
            temp_r5_1929 = &spC + var_r26_1917;
            temp_r0_1930 = M2C_FIELD(temp_r6_1927, u32 *, 4);
            M2C_FIELD(temp_r5_1929, u32 *, 0) = temp_r0_1930;
            if (temp_r0_1930 >= 3U) {
                M2C_FIELD(temp_r5_1929, u32 *, 0) = (u32) (M2C_FIELD(temp_r5_1929, u32 *, 0) - 3);
            }
            temp_r0_1938 = M2C_FIELD(temp_r5_1929, u32 *, 0);
            if ((temp_r0_1938 != 1U) && (temp_r0_1938 == 2U)) {
                M2C_FIELD(temp_r5_1929, s32 *, 0x10) = 0x800;
                M2C_FIELD(temp_r5_1929, s32 *, 0xC) = 0;
                *arg1 += M2C_FIELD(temp_r5_1929, s32 *, 0x10);
            }
            var_r31_1918 += 1;
            var_r26_1917 += 0x14;
            M2C_FIELD(temp_r5_1929, s32 *, 8) = (s32) M2C_FIELD(temp_r6_1927, s32 *, 8);
            M2C_FIELD(temp_r5_1929, u16 *, 4) = (u16) M2C_FIELD(temp_r6_1927, u16 *, 2);
            M2C_FIELD(temp_r5_1929, u16 *, 6) = (u16) M2C_FIELD(temp_r6_1927, u16 *, 0);
            goto loop_10;
        }
    }
    var_r3_1966 = var_r31_1918 * 0x14;
    var_ctr_1967 = 8 - var_r31_1918;
    if (var_r31_1918 < 8U) {
        do {
            temp_r5_1972 = &spC + var_r3_1966;
            var_r3_1966 += 0x14;
            M2C_FIELD(temp_r5_1972, s32 *, 0) = 0;
            M2C_FIELD(temp_r5_1972, s32 *, 8) = 0;
            M2C_FIELD(temp_r5_1972, s32 *, 0xC) = 0;
            M2C_FIELD(temp_r5_1972, s16 *, 4) = 0;
            M2C_FIELD(temp_r5_1972, s16 *, 6) = 0;
            var_ctr_1967 -= 1;
        } while (var_ctr_1967 != 0);
    }
    temp_r26_1981 = *arg1;
    if (MKHeap::Current() != NULL) {
        var_r3_1989 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r26_1981, NULL, 0);
    } else {
        var_r3_1989 = malloc(temp_r26_1981);
    }
    var_r23_1996 = 0;
    var_r24_1997 = 0U;
    var_r27_1998 = 0;
    var_r31_1999 = 0;
loop_18:
    if (var_r24_1997 < var_r30_1912) {
        temp_r25_2004 = &spC + var_r31_1999;
        memcpy(((u8 *) var_r3_1989) + var_r23_1996, M2C_FIELD(temp_r25_2004, void **, 8), M2C_FIELD(temp_r25_2004, u32 *, 0x10));
        var_r24_1997 += 1;
        var_r31_1999 += 0x14;
        *(arg3 + var_r27_1998) = M2C_FIELD(temp_r25_2004, s32 *, 0);
        var_r27_1998 += 4;
        var_r23_1996 += M2C_FIELD(temp_r25_2004, u32 *, 0x10);
        goto loop_18;
    }
    *arg2 = (s32) var_r30_1912;
    TEXReleasePalette(&sp8);
    return var_r3_1989;
}

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_GetDirInfo(bool arg0) {
    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* irregular */
    case 0:
        Step_ProbeDevice();
        return;
    case 1:
        Step_MountCard();
        return;
    case 2:
        Step_CheckFileSystem();
        return;
    case 3:
        Step_GetDirInfo();
        return;
    case 4:
        SetFinished(0);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_CalculateBlocks(bool arg0) {
    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* irregular */
    case 0:
        Step_ProbeDevice();
        return;
    case 1:
        if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 0x18) != NULL) {
            *M2C_FIELD(&CardTemplate, s32 **, 0x18) = (s32) (MKMemoryCard_CalculateFileSize() + M2C_FIELD(&CardTemplate, s32 *, 0x40) + (M2C_FIELD(&CardTemplate, s32 *, 0) - 1)) / (s32) M2C_FIELD(&CardTemplate, s32 *, 0);
        }
        SetFinished(0);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_GetInfo(bool arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r30_2141;
    s32 temp_r3_2179;
    s32 temp_r3_2271;

    temp_r30_2141 = M2C_FIELD(&CardTemplate, s32 *, 0x38);
    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        Step_ProbeDevice();
        return;
    case 1:                                         /* switch 1 */
        Step_MountCard();
        return;
    case 2:                                         /* switch 1 */
        CARDCheckAsync(temp_r30_2141, NULL);
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = (s32) (M2C_FIELD(&CardTemplate, s32 *, 0x30) + 1);
        return;
    case 3:                                         /* switch 1 */
        temp_r3_2179 = CARDGetResultCode(temp_r30_2141);
        switch (temp_r3_2179) {                     /* switch 2; irregular */
        case -128:                                  /* switch 2 */
            SetFinished(-0x12);
            return;
        case -5:                                    /* switch 2 */
            SetFinished(-0x12);
            return;
        case -3:                                    /* switch 2 */
            SetFinished(-2);
            return;
        case -6:                                    /* switch 2 */
            SetFinished(-7);
            return;
        case -13:                                   /* switch 2 */
            if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 4) != NULL) {
                *M2C_FIELD(&CardTemplate, s32 **, 4) = 0;
            }
            if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 8) != NULL) {
                *M2C_FIELD(&CardTemplate, s32 **, 8) = 0;
            }
            if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 0x1C) != NULL) {
                *M2C_FIELD(&CardTemplate, s32 **, 0x1C) = 0;
            }
            SetFinished(0);
            return;
        case 0:                                     /* switch 2 */
            if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 0x1C) != NULL) {
                *M2C_FIELD(&CardTemplate, s32 **, 0x1C) = 1;
            }
            M2C_FIELD(&CardTemplate, s32 *, 0x30) = (s32) (M2C_FIELD(&CardTemplate, s32 *, 0x30) + 1);
            return;
            return;
        }
        break;
    case 4:                                         /* switch 1 */
        CARDFreeBlocks(temp_r30_2141, &spC, &sp8);
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = (s32) (M2C_FIELD(&CardTemplate, s32 *, 0x30) + 1);
        /* fallthrough */
    case 5:                                         /* switch 1 */
        temp_r3_2271 = CARDGetResultCode(temp_r30_2141);
        switch (temp_r3_2271) {                     /* switch 3; irregular */
        case -128:                                  /* switch 3 */
            SetFinished(-1);
            return;
        case -3:                                    /* switch 3 */
            SetFinished(-2);
            return;
        case 0:                                     /* switch 3 */
            if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 4) != NULL) {
                *M2C_FIELD(&CardTemplate, s32 **, 4) = spC / (s32) M2C_FIELD(&CardTemplate, s32 *, 0);
            }
            if ((s32 *) M2C_FIELD(&CardTemplate, s32 **, 8) != NULL) {
                *M2C_FIELD(&CardTemplate, s32 **, 8) = sp8;
            }
            SetFinished(0);
            return;
        case -6:                                    /* switch 3 */
            SetFinished(-7);
            break;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_Format(bool arg0) {
    s32 temp_r3_2370;

    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        Step_ProbeDevice();
        return;
    case 1:                                         /* switch 1 */
        Step_MountCard();
        return;
    case 2:                                         /* switch 1 */
        CARDFormatAsync(0);
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = (s32) (M2C_FIELD(&CardTemplate, s32 *, 0x30) + 1);
        return;
    case 3:                                         /* switch 1 */
        temp_r3_2370 = CARDGetResultCode(M2C_FIELD(&CardTemplate, s32 *, 0x38));
        switch (temp_r3_2370) {                     /* switch 2; irregular */
        case -128:                                  /* switch 2 */
            SetFinished(-1);
            return;
        case -5:                                    /* switch 2 */
            SetFinished(-0x12);
            return;
        case -3:                                    /* switch 2 */
            SetFinished(-2);
            return;
        case 0:                                     /* switch 2 */
            SetFinished(0);
            return;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_Load(bool arg0) {
    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* irregular */
    case 0:
        Step_ProbeDevice();
        return;
    case 1:
        Step_MountCard();
        return;
    case 2:
        Step_CheckFileSystem();
        return;
    case 3:
        Step_ReadFile();
        return;
    case 4:
        SetFinished(0);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_Save(bool arg0) {
    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* irregular */
    case 0:
        Step_ProbeDevice();
        return;
    case 1:
        Step_MountCard();
        return;
    case 2:
        Step_CheckFileSystem();
        return;
    case 3:
        Step_DeleteFile();
        return;
    case 4:
        Step_WriteFile();
        return;
    case 5:
        SetFinished(0);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_Prepared(bool arg0) {
    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* irregular */
    case 0:
        Step_ProbeDevice();
        return;
    case 1:
        Step_MountCard();
        return;
    case 2:
        Step_CheckFileSystem();
        return;
    case 3:
        SetFinished(0);
        return;
    }
}
#endif

void Proccess_IsAttached(bool arg0) {
    s32 temp_r3_2577;

    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    temp_r3_2577 = CARDProbeEx(M2C_FIELD(&CardTemplate, s32 *, 0x38), NULL, NULL);
    switch (temp_r3_2577) {                         /* irregular */
    case -128:
        SetFinished(-2);
        return;
    case -3:
        SetFinished(-2);
        return;
    case -2:
        SetFinished(-4);
        return;
    case 0:
        SetFinished(0);
        return;
    }
}

#if 0 // DRAFT: undefined identifier 'Step_ProbeDevice'
void Proccess_Delete(bool arg0) {
    if (arg0 != 0) {
        M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    }
    switch ((s32) M2C_FIELD(&CardTemplate, s32 *, 0x30)) { /* irregular */
    case 0:
        Step_ProbeDevice();
        return;
    case 1:
        Step_MountCard();
        return;
    case 2:
        Step_CheckFileSystem();
        return;
    case 3:
        Step_DeleteFile();
        return;
    case 4:
        SetFinished(0);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Proccess_CalculateBlocks'
void MKMemoryCard_Update() {
    switch (M2C_FIELD(&CardTemplate, u32 *, 0x2C)) {
    case 7:
        Proccess_CalculateBlocks(0U);
        return;
    case 5:
        Proccess_GetDirInfo(0U);
        return;
    case 4:
        Proccess_GetInfo(0U);
        return;
    case 3:
        Proccess_Format(0U);
        return;
    case 1:
        Proccess_Save(0U);
        return;
    case 2:
        Proccess_Load(0U);
        return;
    case 6:
        Proccess_Prepared(0U);
        return;
    case 8:
        Proccess_IsAttached(0U);
        return;
    case 9:
        Proccess_Delete(0U);
        /* fallthrough */
    default:
        return;
    }
}
#endif

s32 MKMemoryCard_GetStatus(int arg0) {
    return M2C_FIELD(&CardTemplate, s32 *, 0x28);
}

void MKMemoryCard_DeinitModule() {
    void *temp_r31_2740;

    temp_r31_2740 = M2C_FIELD(&CardTemplate, void **, 0x68);
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2740, NULL, 0);
        return;
    }
    free(temp_r31_2740);
}

#if 0 // DRAFT: illegal explicit conversion from 'void *' to 'float'
void MKMemoryCard_InitModule() {
    f32 temp_f1_2796;
    s32 var_ctr_2809;
    s32 var_ctr_2818;
    s32 var_r3_2802;
    s8 *var_r3_2816;
    void *temp_r4_2811;

    M2C_FIELD(&CardTemplate, s32 *, 0) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 4) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 8) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0xC) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x30) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x34) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x38) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x28) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x2C) = 0;
    memset(&CardTemplate + 0x100, 0, 0xA000U);
    M2C_FIELD(&CardTemplate, s32 *, 0x44) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x10) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x40) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x3C) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x48) = 0;
    temp_f1_2796 = M2C_BITWISE(f32, memset(&CardTemplate + 0x90, 0, 0x40U));
    var_r3_2802 = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x5C) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x60) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x64) = 0;
    M2C_FIELD(&CardTemplate, void **, 0x68) = NULL;
    M2C_FIELD(&CardTemplate, s32 *, 0x6C) = 0;
    var_ctr_2809 = 8;
    do {
        temp_r4_2811 = &CardTemplate + var_r3_2802;
        var_r3_2802 += 4;
        M2C_FIELD(temp_r4_2811, s32 *, 0x70) = 0;
        var_ctr_2809 -= 1;
    } while (var_ctr_2809 != 0);
    var_r3_2816 = &bIsMounted;
    var_ctr_2818 = 2;
    do {
        *var_r3_2816 = 0;
        var_r3_2816 += 1;
        var_ctr_2818 -= 1;
    } while (var_ctr_2818 != 0);
    if (DVDConvertPathToEntrynum(Str_Printf("%s%s", "/icons/", "icon.tpl", temp_f1_2796)) != -1) {
        M2C_FIELD(&CardTemplate, void **, 0x68) = LoadIconFile("icon.tpl", (int *) &CardTemplate + 0x64, (int *) &CardTemplate + 0x6C, &CardTemplate + 0x70);
    }
    CARDInit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Proccess_GetDirInfo'
void MKMemoryCard_GetDirInfo(int arg0, MKMemoryCardFileInfo *arg1) {
    M2C_FIELD(&CardTemplate, MKMemoryCardFileInfo **, 0x20) = arg1;
    SetStarted(arg0, 5);
    Proccess_GetDirInfo(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'Proccess_GetInfo'
void MKMemoryCard_GetInfo(int arg0, int *arg1, int *arg2, int *arg3, int *arg4) {
    SetStarted(arg0, 4);
    M2C_FIELD(&CardTemplate, s32 **, 4) = (long *) (arg1);
    M2C_FIELD(&CardTemplate, s32 **, 8) = (long *) (arg2);
    M2C_FIELD(&CardTemplate, s32 **, 0xC) = (long *) (arg3);
    M2C_FIELD(&CardTemplate, s32 **, 0x1C) = (long *) (arg4);
    Proccess_GetInfo(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'slotName'
void MKMemoryCard_Load(int arg0, int arg1, void *arg2, int arg3) {
    SetStarted(arg0, 2);
    M2C_FIELD(&CardTemplate, void **, 0x10) = arg2;
    M2C_FIELD(&CardTemplate, struct _struct_slotName_0x40 **, 0x44) = &slotName[arg1];
    M2C_FIELD(&CardTemplate, s32 *, 0x3C) = arg3;
    Proccess_Load(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_303'
void MKMemoryCard_Save(int arg0, int arg1, void *arg2, int arg3, const char *arg4, TimerInfo *arg5) {
    s8 sp8;
    M2C_UNK sp4;
    s8 *temp_r27_2964;
    s8 *var_r25_2945;

    var_r25_2945 = (signed char *) (arg4);
    M2C_STRUCT_COPY((s32) &sp4 + 4, (s32) (&lit_303 - 4) + 4, 0x20);
    if (var_r25_2945 == NULL) {
        var_r25_2945 = &sp8;
    }
    temp_r27_2964 = (signed char *) (&CardTemplate + 0xB0);
    memset(temp_r27_2964, 0, 0x20U);
    strcpy(temp_r27_2964, var_r25_2945);
    M2C_FIELD(&CardTemplate, s32 *, 0x40) = arg3;
    M2C_FIELD(&CardTemplate, struct _struct_slotName_0x40 **, 0x44) = &slotName[arg1];
    M2C_FIELD(&CardTemplate, void **, 0x10) = arg2;
    M2C_FIELD(&CardTemplate, TimerInfo **, 0x24) = arg5;
    SetStarted(arg0, 1);
    M2C_FIELD(&CardTemplate, s32 *, 0x50) = arg3;
    M2C_FIELD(&CardTemplate, s32 *, 0x58) = 0;
    M2C_FIELD(&CardTemplate, s32 *, 0x54) = (s32) (M2C_FIELD(&CardTemplate, s32 *, 0x4C) + M2C_FIELD(&CardTemplate, s32 *, 0x64) + 0x4C);
    Proccess_Save(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'Proccess_Format'
void MKMemoryCard_Format(int arg0) {
    SetStarted(arg0, 3);
    Proccess_Format(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'Proccess_Prepared'
void MKMemoryCard_IsPrepared(int arg0) {
    SetStarted(arg0, 6);
    Proccess_Prepared(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'Proccess_Prepared'
void MKMemoryCard_Prepare(int arg0) {
    SetStarted(arg0, 6);
    Proccess_Prepared(1U);
}
#endif

#if 0 // DRAFT: function call 'strcpy(long *, const char *)' does not match 'strcpy(char *, const char *)'
void MKMemoryCard_SetAppInfo(const char *arg0, const char *arg1, int *arg2) {
    f32 var_f1_3056;
    s32 var_r28_3064;
    s32 var_r31_3066;

    var_f1_3056 = M2C_BITWISE(f32, strcpy(&CardTemplate + 0x90, arg1));
    M2C_FIELD(&CardTemplate, s32 *, 0x4C) = 0x80;
    var_r28_3064 = 0;
    var_r31_3066 = 0;
    do {
        var_f1_3056 = M2C_BITWISE(f32, strcpy(slotName + var_r31_3066, Str_Printf("Data%d", var_r28_3064, var_f1_3056)));
        var_r28_3064 += 1;
        var_r31_3066 += 0x40;
    } while (var_r28_3064 < 0xE);
}
#endif

void MKMemoryCard_IsAttached(int arg0) {
    SetStarted(arg0, 8);
    Proccess_IsAttached(1U);
}

#if 0 // DRAFT: undefined identifier 'slotName'
void MKMemoryCard_Delete(int arg0, int arg1) {
    M2C_FIELD(&CardTemplate, struct _struct_slotName_0x40 **, 0x44) = &slotName[arg1];
    SetStarted(arg0, 9);
    Proccess_Delete(1U);
}
#endif
