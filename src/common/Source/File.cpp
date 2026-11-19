#include "common/Source/File.h"
#include "dolphin/dvd.h"
#include "dolphin/os.h"
#include "dolphin/vi.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

extern M2C_UNK gMKDefaults;
extern s32 jobListHead;
extern s32 jobListTail;
static OSSemaphore semaJobCount;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_openFiles_0x58'
static struct _struct_openFiles_0x58 openFiles[0x14];
#endif
static M2C_UNK lit_438;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_564;                                /* unable to generate initializer: unknown type; const */

void File_FileServerOutputFilename(const char *arg0) {
    Str_Printf("%s%s", M2C_FIELD(&gMKDefaults, s32 *, 0x2C), arg0, "%s%s");
}

void File_FileServerFilename(const char *arg0) {

}

#if 0 // DRAFT: undefined identifier 'openFiles'
s32 File_IsAnyBusy() {
    s32 var_r28_45;
    s32 var_r29_43;
    s32 var_r31_46;

    OSYieldThread();
    var_r29_43 = 0;
    var_r28_45 = 0;
    var_r31_46 = 0;
    do {
        if ((s32) M2C_FIELD((openFiles + var_r31_46), s32 *, 0x3C) != -1) {
            var_r29_43 += File_IsBusy(var_r28_45);
        }
        var_r28_45 += 1;
        var_r31_46 += 0x58;
    } while (var_r28_45 < 0x14);
    return var_r29_43;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 File_Sync(int arg0, int arg1) {
loop_2:
    if ((s32) openFiles[arg0].unk44 != 0) {
        VIWaitForRetrace();
        goto loop_2;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 File_IsBusy(int arg0) {
    struct _struct_openFiles_0x58 *temp_r3_105;

    if ((arg0 != -1) && (arg0 < 0x14)) {
        temp_r3_105 = &openFiles[arg0];
        if ((s32) temp_r3_105->unk3C != -1) {
            return temp_r3_105->unk44;
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match
u32 File_Length(const char *arg0) {
    s8 sp44;
    DVDFileInfo sp8;
    s8 *var_r5_138;
    u32 var_r31_154;
    u8 temp_r4_149;

    M2C_STRUCT_COPY((s32) &sp8.callback + 4, (s32) (&lit_564 - 4) + 4, 0x200);
    strcpy(&sp44, arg0);
    var_r5_138 = &sp44;
loop_4:
    temp_r4_149 = (u8) *var_r5_138;
    if ((s8) temp_r4_149 != 0) {
        if ((s8) temp_r4_149 == 0x5C) {
            *var_r5_138 = 0x2F;
        }
        var_r5_138 += 1;
        goto loop_4;
    }
    var_r31_154 = 0;
    if (DVDOpen(&sp44, &sp8) == 1) {
        var_r31_154 = sp8.length;
        DVDClose(&sp8);
    }
    return var_r31_154;
}
#endif

#if 0 // DRAFT: illegal type
s32 File_Seek(int arg0, int arg1, int arg2) {
    u32 temp_r0_216;
    u32 temp_r4_213;
    u32 temp_r4_215;
    void *temp_r31_185;
    void *temp_r7_190;

    if ((arg0 != -1) && (arg0 < 0x14)) {
        temp_r31_185 = &semaJobCount + 0x1340 + (arg0 * 0x58);
        if ((s32) M2C_FIELD(temp_r31_185, s32 *, 0x3C) != -1) {
            temp_r7_190 = &semaJobCount + 0x1A20;
            *(temp_r7_190 + (jobListHead * 0x4C)) = 4;
            M2C_FIELD((((u8 *) temp_r7_190) + (jobListHead * 0x4C)), s32 *, 4) = arg0;
            M2C_FIELD((((u8 *) temp_r7_190) + (jobListHead * 0x4C)), s32 *, 8) = arg1;
            M2C_FIELD((((u8 *) temp_r7_190) + (jobListHead * 0x4C)), s32 *, 0xC) = arg2;
            M2C_FIELD(temp_r31_185, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r31_185, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r31_185, s32 *, 0x44) + 1);
            temp_r4_213 = jobListHead + 1;
            temp_r4_215 = temp_r4_213 >> 0x1FU;
            temp_r0_216 = (temp_r4_213 << 0x1C) - temp_r4_215;
            jobListHead = ((temp_r0_216 << 4) | (temp_r0_216 >> 0x1CU)) + temp_r4_215;
            OSSignalSemaphore(&semaJobCount);
            if ((u8) M2C_FIELD(temp_r31_185, u8 *, 0x50) == 0) {
loop_6:
                if ((s32) M2C_FIELD(temp_r31_185, s32 *, 0x44) != 0) {
                    VIWaitForRetrace();
                    goto loop_6;
                }
            }
        }
    }
    return -1;
}
#endif

#if 0 // DRAFT: illegal type
s32 File_Write(int arg0, const void *arg1, int arg2) {
    u32 temp_r0_290;
    u32 temp_r4_287;
    u32 temp_r4_289;
    void *temp_r31_255;
    void *temp_r7_260;

    if ((arg0 != -1) && (arg0 < 0x14)) {
        temp_r31_255 = &semaJobCount + 0x1340 + (arg0 * 0x58);
        if ((s32) M2C_FIELD(temp_r31_255, s32 *, 0x3C) != -1) {
            temp_r7_260 = &semaJobCount + 0x1A20;
            *(temp_r7_260 + (jobListHead * 0x4C)) = 3;
            M2C_FIELD((((u8 *) temp_r7_260) + (jobListHead * 0x4C)), s32 *, 4) = arg0;
            M2C_FIELD((((u8 *) temp_r7_260) + (jobListHead * 0x4C)), void **, 8) = arg1;
            M2C_FIELD((((u8 *) temp_r7_260) + (jobListHead * 0x4C)), s32 *, 0xC) = arg2;
            M2C_FIELD((((u8 *) temp_r7_260) + (jobListHead * 0x4C)), s32 *, 0x10) = arg2;
            M2C_FIELD(temp_r31_255, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r31_255, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r31_255, s32 *, 0x44) + 1);
            temp_r4_287 = jobListHead + 1;
            temp_r4_289 = temp_r4_287 >> 0x1FU;
            temp_r0_290 = (temp_r4_287 << 0x1C) - temp_r4_289;
            jobListHead = ((temp_r0_290 << 4) | (temp_r0_290 >> 0x1CU)) + temp_r4_289;
            OSSignalSemaphore(&semaJobCount);
            if ((u8) M2C_FIELD(temp_r31_255, u8 *, 0x50) == 0) {
loop_6:
                if ((s32) M2C_FIELD(temp_r31_255, s32 *, 0x44) != 0) {
                    VIWaitForRetrace();
                    goto loop_6;
                }
                return M2C_FIELD(temp_r31_255, s32 *, 0x4C);
            }
        }
    }
    return -1;
}
#endif

#if 0 // DRAFT: illegal type
s32 File_Read(int arg0, void *arg1, int arg2, int arg3) {
    s32 var_r6_0;
    u32 temp_r0_372;
    u32 temp_r4_369;
    u32 temp_r4_371;
    void *temp_r31_332;
    void *temp_r8_337;

    var_r6_0 = arg3;
    if ((arg0 != -1) && (arg0 < 0x14)) {
        temp_r31_332 = &semaJobCount + 0x1340 + (arg0 * 0x58);
        if ((s32) M2C_FIELD(temp_r31_332, s32 *, 0x3C) != -1) {
            temp_r8_337 = &semaJobCount + 0x1A20;
            *(temp_r8_337 + (jobListHead * 0x4C)) = 2;
            M2C_FIELD((((u8 *) temp_r8_337) + (jobListHead * 0x4C)), s32 *, 4) = arg0;
            M2C_FIELD((((u8 *) temp_r8_337) + (jobListHead * 0x4C)), void **, 8) = arg1;
            M2C_FIELD((((u8 *) temp_r8_337) + (jobListHead * 0x4C)), s32 *, 0xC) = arg2;
            if (var_r6_0 < arg2) {
                var_r6_0 = arg2;
            }
            M2C_FIELD((&semaJobCount + 0x1A20 + (jobListHead * 0x4C)), s32 *, 0x10) = var_r6_0;
            M2C_FIELD(temp_r31_332, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r31_332, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r31_332, s32 *, 0x44) + 1);
            temp_r4_369 = jobListHead + 1;
            temp_r4_371 = temp_r4_369 >> 0x1FU;
            temp_r0_372 = (temp_r4_369 << 0x1C) - temp_r4_371;
            jobListHead = ((temp_r0_372 << 4) | (temp_r0_372 >> 0x1CU)) + temp_r4_371;
            OSSignalSemaphore(&semaJobCount);
            if ((u8) M2C_FIELD(temp_r31_332, u8 *, 0x50) == 0) {
loop_8:
                if ((s32) M2C_FIELD(temp_r31_332, s32 *, 0x44) != 0) {
                    VIWaitForRetrace();
                    goto loop_8;
                }
                return M2C_FIELD(temp_r31_332, s32 *, 0x4C);
            }
            return 0;
        }
    }
    return -1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'OSSemaphore' to
s32 File_Close(int arg0) {
    u32 temp_r0_434;
    u32 temp_r4_431;
    u32 temp_r4_433;
    void *temp_r4_421;

    if ((arg0 != -1) && (arg0 < 0x14) && ((s32) *(&semaJobCount + 0x1340 + ((arg0 * 0x58) + 0x3C)) != -1)) {
        temp_r4_421 = &semaJobCount + 0x1A20;
        *(temp_r4_421 + (jobListHead * 0x4C)) = 1;
        M2C_FIELD((((u8 *) temp_r4_421) + (jobListHead * 0x4C)), s32 *, 4) = arg0;
        temp_r4_431 = jobListHead + 1;
        temp_r4_433 = temp_r4_431 >> 0x1FU;
        temp_r0_434 = (temp_r4_431 << 0x1C) - temp_r4_433;
        jobListHead = ((temp_r0_434 << 4) | (temp_r0_434 >> 0x1CU)) + temp_r4_433;
        OSSignalSemaphore(&semaJobCount);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'OSSemaphore' to
s32 File_Open(const char *arg0, int arg1) {
    s32 temp_r30_476;
    s32 var_ctr_461;
    s32 var_r29_458;
    s32 var_r3_535;
    s32 var_r4_460;
    u32 temp_r0_519;
    u32 temp_r4_516;
    u32 temp_r4_518;
    void *temp_r5_507;
    void *temp_r6_483;
    void *temp_r8_480;

    var_r29_458 = 0;
    var_r4_460 = 0;
    var_ctr_461 = 0x14;
loop_1:
    if ((s32) *(&semaJobCount + 0x1340 + (var_r4_460 + 0x3C)) != -1) {
        var_r29_458 += 1;
        var_r4_460 += 0x58;
        var_ctr_461 -= 1;
        if (var_ctr_461 != 0) {
            goto loop_1;
        }
    }
    if (var_r29_458 == 0x14) {
        return -1;
    }
    temp_r30_476 = var_r29_458 * 0x58;
    temp_r8_480 = &semaJobCount + 0x1340 + temp_r30_476;
    M2C_FIELD(temp_r8_480, s32 *, 0x3C) = -1;
    temp_r6_483 = &semaJobCount + 0x1A20;
    M2C_FIELD(temp_r8_480, s32 *, 0x40) = 0;
    M2C_FIELD(temp_r8_480, s8 *, 0x50) = 0;
    M2C_FIELD(temp_r8_480, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r8_480, s32 *, 0x3C) = 1;
    *(temp_r6_483 + (jobListHead * 0x4C)) = 0;
    M2C_FIELD((((u8 *) temp_r6_483) + (jobListHead * 0x4C)), s32 *, 4) = var_r29_458;
    strncpy(((u8 *) temp_r6_483) + ((jobListHead * 0x4C) + 8), arg0, 0x3FU);
    temp_r5_507 = &semaJobCount + 0x1340 + temp_r30_476;
    M2C_FIELD((&semaJobCount + 0x1A20 + (jobListHead * 0x4C)), s32 *, 0x48) = arg1;
    M2C_FIELD(temp_r5_507, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r5_507, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r5_507, s32 *, 0x44) + 1);
    temp_r4_516 = jobListHead + 1;
    temp_r4_518 = temp_r4_516 >> 0x1FU;
    temp_r0_519 = (temp_r4_516 << 0x1C) - temp_r4_518;
    jobListHead = ((temp_r0_519 << 4) | (temp_r0_519 >> 0x1CU)) + temp_r4_518;
    OSSignalSemaphore(&semaJobCount);
loop_7:
    if ((s32) *(&semaJobCount + 0x1340 + (temp_r30_476 + 0x44)) != 0) {
        VIWaitForRetrace();
        goto loop_7;
    }
    var_r3_535 = -1;
    if ((s32) M2C_FIELD((&semaJobCount + 0x1340 + (var_r29_458 * 0x58)), s32 *, 0x3C) != -1) {
        var_r3_535 = var_r29_458;
    }
    return var_r3_535;
}
#endif

void File_DeinitModule() {

}

#if 0 // DRAFT: illegal type
void File_InitModule() {
    s32 temp_r0_577;
    s32 temp_r5_576;
    s32 temp_r7_574;
    s32 var_ctr_571;
    s32 var_r3_560;
    void *temp_r9_570;

    var_r3_560 = 0;
    temp_r9_570 = &semaJobCount + 0x1340;
    var_ctr_571 = 0x14;
    do {
        temp_r7_574 = var_r3_560 + 0x44;
        *(temp_r9_570 + (var_r3_560 + 0x3C)) = -1;
        temp_r5_576 = var_r3_560 + 0x48;
        temp_r0_577 = var_r3_560 + 0x50;
        var_r3_560 += 0x58;
        *(temp_r9_570 + temp_r7_574) = 0;
        *(temp_r9_570 + temp_r5_576) = 0;
        *(temp_r9_570 + temp_r0_577) = 0;
        var_ctr_571 -= 1;
    } while (var_ctr_571 != 0);
    jobListTail = 0;
    jobListHead = 0;
    OSInitSemaphore(&semaJobCount, 0);
    OSCreateThread(&semaJobCount + 0x10, File_JobThread, NULL, &semaJobCount + 0x340 + 0x1000, 0x1000U, 0xF, 1U);
    OSResumeThread(&semaJobCount + 0x10);
}
#endif

#if 0 // DRAFT: undefined identifier 'saved_reg_r27'
void *File_JobThread(void *arg0) {
    s8 sp8;
    M2C_UNK sp4;
    DVDFileInfo *temp_r28_634;
    s32 temp_r0_647;
    s32 temp_r0_689;
    s32 temp_r0_765;
    s32 temp_r0_812;
    s32 temp_r22_747;
    s32 temp_r22_776;
    s32 temp_r26_740;
    s8 *var_r5_675;
    u32 temp_r0_856;
    u32 temp_r23_748;
    u32 temp_r3_759;
    u32 temp_r3_784;
    u32 temp_r3_853;
    u32 temp_r3_855;
    u32 temp_r5_745;
    u32 var_r24_766;
    u32 var_r25_749;
    u8 temp_r4_686;
    u8 var_r27_0;
    void *temp_r29_629;
    void *temp_r31_617;

    var_r27_0 = saved_reg_r27;
    temp_r31_617 = &semaJobCount + 0x1A20;
loop_1:
    OSWaitSemaphore(&semaJobCount);
    if ((s32) *(temp_r31_617 + (jobListTail * 0x4C)) != 5) {
        temp_r29_629 = ((u8 *) temp_r31_617) + (jobListTail * 0x4C);
        temp_r28_634 = &semaJobCount + 0x1340 + (M2C_FIELD(temp_r29_629, s32 *, 4) * 0x58);
        if (((s32) M2C_FIELD(temp_r29_629, s32 *, 0) != 0) && (((DVDFileInfo *) M2C_FIELD(temp_r28_634, DVDFileInfo **, 0x3C) == (DVDFileInfo *)-1) || ((DVDFileInfo *) M2C_FIELD(temp_r28_634, DVDFileInfo **, 0x3C) == (DVDFileInfo *)1))) {
            M2C_FIELD(temp_r28_634, s32 *, 0x48) = -1;
        } else {
            temp_r0_647 = M2C_FIELD(temp_r29_629, s32 *, 0);
            switch (temp_r0_647) {                  /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                M2C_STRUCT_COPY((s32) &sp4 + 4, (s32) (&lit_438 - 4) + 4, 0x200);
                strcpy(&sp8, ((u8 *) temp_r29_629) + 8);
                var_r5_675 = &sp8;
loop_17:
                temp_r4_686 = (u8) *var_r5_675;
                if ((s8) temp_r4_686 != 0) {
                    if ((s8) temp_r4_686 == 0x5C) {
                        *var_r5_675 = 0x2F;
                    }
                    var_r5_675 += 1;
                    goto loop_17;
                }
                temp_r0_689 = M2C_FIELD(temp_r29_629, s32 *, 0x48);
                switch (temp_r0_689) {              /* switch 2; irregular */
                case 1:                             /* switch 2 */
                    M2C_FIELD(temp_r28_634, s8 *, 0x50) = 1;
                    /* fallthrough */
                case 0:                             /* switch 2 */
                    var_r27_0 = DVDOpen(&sp8, temp_r28_634) != 0;
                    break;
                }
                if (var_r27_0 == 0) {
                    M2C_FIELD(temp_r28_634, DVDFileInfo **, 0x3C) = (DVDFileInfo *)-1;
                    M2C_FIELD(temp_r28_634, s32 *, 0x48) = DVDGetCommandBlockStatus(&temp_r28_634->cb);
                    M2C_FIELD(temp_r28_634, s32 *, 0x54) = -1;
                } else {
                    M2C_FIELD(temp_r28_634, DVDFileInfo **, 0x3C) = temp_r28_634;
                    M2C_FIELD(temp_r28_634, s32 *, 0x54) = 0;
                }
                break;
            case 1:                                 /* switch 1 */
                if (DVDClose(temp_r28_634) == 0) {
                    M2C_FIELD(temp_r28_634, s32 *, 0x48) = DVDGetCommandBlockStatus(&temp_r28_634->cb);
                }
                M2C_FIELD(temp_r28_634, DVDFileInfo **, 0x3C) = (DVDFileInfo *)-1;
                break;
            case 2:                                 /* switch 1 */
                temp_r26_740 = M2C_FIELD(temp_r28_634, s32 *, 0x54) & 0xFFFFFFE0;
                temp_r5_745 = M2C_FIELD(temp_r29_629, s32 *, 0x10) & 0xFFFFFFE0;
                temp_r22_747 = M2C_FIELD(temp_r28_634, s32 *, 0x54) & 0x1F;
                temp_r23_748 = ((M2C_FIELD(temp_r28_634, s32 *, 0x54) + (M2C_FIELD(temp_r29_629, s32 *, 0xC) + 0x1F)) & 0xFFFFFFE0) - temp_r26_740;
                var_r25_749 = temp_r5_745;
                if (temp_r23_748 < temp_r5_745) {
                    var_r25_749 = temp_r23_748;
                }
                temp_r3_759 = DVDReadPrio(temp_r28_634, (void *) M2C_FIELD(temp_r29_629, s32 *, 8), (s32) var_r25_749, temp_r26_740, 2);
                if (temp_r3_759 < var_r25_749) {
                    M2C_FIELD(temp_r28_634, s32 *, 0x48) = (s32) temp_r3_759;
                } else {
                    temp_r0_765 = M2C_FIELD(temp_r29_629, s32 *, 0xC);
                    var_r24_766 = var_r25_749 - temp_r22_747;
                    if ((u32) temp_r0_765 < var_r24_766) {
                        var_r24_766 = (u32) temp_r0_765;
                    }
                    memmove((void *) M2C_FIELD(temp_r29_629, s32 *, 8), M2C_FIELD(temp_r29_629, s32 *, 8) + temp_r22_747, var_r24_766);
                    temp_r22_776 = temp_r23_748 - var_r25_749;
                    if (temp_r22_776 != 0) {
                        temp_r3_784 = DVDReadPrio(temp_r28_634, &semaJobCount + 0x1EE0, temp_r22_776, temp_r26_740 + var_r25_749, 2);
                        if (temp_r3_784 < (u32) temp_r22_776) {
                            M2C_FIELD(temp_r28_634, s32 *, 0x48) = (s32) temp_r3_784;
                        } else {
                            memcpy(M2C_FIELD(temp_r29_629, s32 *, 8) + var_r24_766, &semaJobCount + 0x1EE0, M2C_FIELD(temp_r29_629, s32 *, 0xC) - var_r24_766);
                            M2C_FIELD(temp_r28_634, s32 *, 0x4C) = (s32) M2C_FIELD(temp_r29_629, s32 *, 0xC);
                            M2C_FIELD(temp_r28_634, s32 *, 0x54) = (s32) (M2C_FIELD(temp_r28_634, s32 *, 0x54) + M2C_FIELD(temp_r29_629, s32 *, 0xC));
                        }
                    } else {
                        M2C_FIELD(temp_r28_634, s32 *, 0x4C) = (s32) M2C_FIELD(temp_r29_629, s32 *, 0xC);
                        M2C_FIELD(temp_r28_634, s32 *, 0x54) = (s32) (M2C_FIELD(temp_r28_634, s32 *, 0x54) + M2C_FIELD(temp_r29_629, s32 *, 0xC));
                    }
                }
                break;
            case 4:                                 /* switch 1 */
                temp_r0_812 = M2C_FIELD(temp_r29_629, s32 *, 0xC);
                switch (temp_r0_812) {              /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    M2C_FIELD(temp_r28_634, s32 *, 0x54) = (s32) M2C_FIELD(temp_r29_629, s32 *, 8);
                    break;
                case 1:                             /* switch 3 */
                    M2C_FIELD(temp_r28_634, s32 *, 0x54) = (s32) (M2C_FIELD(temp_r28_634, s32 *, 0x54) + M2C_FIELD(temp_r29_629, s32 *, 8));
                    break;
                case 2:                             /* switch 3 */
                    M2C_FIELD(temp_r28_634, s32 *, 0x54) = (s32) (temp_r28_634->length + M2C_FIELD(temp_r29_629, s32 *, 8));
                    break;
                }
                M2C_FIELD(temp_r28_634, s32 *, 0x4C) = (s32) M2C_FIELD(temp_r28_634, s32 *, 0x54);
                if (DVDSeekPrio(temp_r28_634, M2C_FIELD(temp_r28_634, s32 *, 0x54) & 0xFFFFFFFC, 2) < 0) {
                    M2C_FIELD(temp_r28_634, s32 *, 0x48) = DVDGetCommandBlockStatus(&temp_r28_634->cb);
                }
                break;
            }
        }
        temp_r3_853 = jobListTail + 1;
        temp_r3_855 = temp_r3_853 >> 0x1FU;
        temp_r0_856 = (temp_r3_853 << 0x1C) - temp_r3_855;
        jobListTail = ((temp_r0_856 << 4) | (temp_r0_856 >> 0x1CU)) + temp_r3_855;
        M2C_FIELD(temp_r28_634, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r28_634, s32 *, 0x44) - 1);
        goto loop_1;
    }
    return NULL;
}
#endif
