#include "common/Source/MKPackage.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "dolphin/os.h"
#include "dolphin/vi.h"
#include "common/Source/File.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/Source/Timer.h"
#include "common/Source/Utils.h"
#include <m2c_macros.h>

M2C_UNK free(s8 *);                                 /* extern */
PackageQueueInfo *malloc(s32);                      /* extern */
M2C_UNK qsort(struct _struct_pPackageEntries_0x14 (*)[], s32, M2C_UNK, s32 (*)(void *, void *)); /* extern */
M2C_UNK strcat(s8 *, s8 *);                         /* extern */
s32 strcmpi(s8 *, s8 *);                            /* extern */
s8 *strtok(s8 *, s8 *);                             /* extern */
extern s32 MKPackage_kLoadedPerSecond;
extern s32 MKPackage_memoryDelivered;
extern s32 MKPackage_misses;
extern s32 MKPackage_missesAccumulator;
extern s32 MKPackage_undelivered;
extern u8 QInterface;
extern s32 activeHandle;
extern s8 assertMisses;
extern s32 asyncState;
extern u8 bTempMemBeingUsed;
extern s32 chunkBaseOffset_486;
extern u32 chunkLength_483;
extern u8 disableAsyncPackages;
extern u8 disablePackageChunking;
extern u8 gDisablePackages;
extern s32 gMKLastIdleTime;
extern s8 *gpTempMemFilePatterns;
extern u8 init_475;
extern u8 init_481;
extern u8 init_484;
extern u8 init_487;
extern u8 init_491;
extern u8 lowMemory_490;
extern s32 nFilesInChunk_480;
extern s32 nmbrEntriesLoaded;
extern s32 nmbrOfAutoEntries;
extern s32 nmbrOfChunkReads;
extern s32 nmbrOfPackageEntries;
extern s8 *pAutoEntries;
extern s8 *pChunkBuffer_489;
extern MKHeap *pHeapToLoadInto;
extern s8 *pPackageText;
extern void *(*pPreviousHandler)(s8 *, s32 *, void *, s32 *);
extern PackageQueueInfo *pQueue;
extern u8 packageCancelled;
extern s32 packageState;
extern u32 packageTextSize;
extern s32 queueCount;
extern s32 resetState_474;
extern s32 totalBytesInPackage;
extern s32 totalBytesLoaded;
static s8 packageName[0x20];
static s8 binaryPackageName[0x20];
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_pPackageEntries_0x14'
static struct _struct_pPackageEntries_0x14 pPackageEntries[0x400];
#endif
static TimerInfo packageTime;
static s32 afd = -1;
static s32 nextQueueHandle = 0x2710;

void MKPackage_ShowStatus(int arg0) {

}

#if 0 // DRAFT: undefined identifier 'FindQueuedPackage'
s32 MKPackage_QFree(int arg0) {
    PackageQueueInfo *temp_r3_36;
    s32 temp_r3_28;
    s32 var_r31_22;

    var_r31_22 = 0;
    if (arg0 == (s32) activeHandle) {
        QInterface = 0;
        temp_r3_28 = MKPackage_Free();
        QInterface = 1;
        var_r31_22 = temp_r3_28;
        activeHandle = 0;
    }
    temp_r3_36 = FindQueuedPackage(arg0);
    if (temp_r3_36 != NULL) {
        RemoveFromQueue(temp_r3_36);
    }
    ProcessQueue();
    return var_r31_22;
}
#endif

#if 0 // DRAFT: undefined identifier 'FindQueuedPackage'
void MKPackage_QCancel(int arg0) {
    PackageQueueInfo *temp_r3_66;

    if (arg0 == (s32) activeHandle) {
        QInterface = 0;
        MKPackage_Cancel();
        QInterface = 1;
        return;
    }
    temp_r3_66 = FindQueuedPackage(arg0);
    if (temp_r3_66 != NULL) {
        temp_r3_66->unk129 = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'FindQueuedPackage'
u8 MKPackage_QIsLoaded(int arg0, float *arg1, int *arg2) {
    PackageQueueInfo *temp_r3_97;
    u8 temp_r3_113;

    if (arg0 != (s32) activeHandle) {
        if (arg1 != NULL) {
            *arg1 = 0.0f;
        }
        if (arg2 != NULL) {
            *arg2 = 0;
        }
        temp_r3_97 = FindQueuedPackage(arg0);
        if ((temp_r3_97 != NULL) && ((u8) temp_r3_97->unk129 != 0)) {
            return 1U;
        }
        return 0U;
    }
    QInterface = 0;
    temp_r3_113 = MKPackage_IsLoaded(arg1, arg2);
    QInterface = 1;
    return temp_r3_113;
}
#endif

#if 0 // DRAFT: function call 'strcpy(unsigned char *, signed char *)' does not match 'strcpy(char *, const char *)'
s32 MKPackage_QLoadDynamic(const char *arg0, int arg1, const char *arg2) {
    s32 temp_r0_135;
    s32 temp_r3_142;
    s8 *var_r4_155;
    void *temp_r31_139;

    temp_r0_135 = queueCount * 0x12C;
    queueCount += 1;
    temp_r31_139 = pQueue + temp_r0_135;
    memset(temp_r31_139, 0, 0x12CU);
    temp_r3_142 = nextQueueHandle;
    nextQueueHandle = temp_r3_142 + 1;
    M2C_FIELD(temp_r31_139, s32 *, 0) = temp_r3_142;
    if ((s32) nextQueueHandle == 0) {
        nextQueueHandle += 1;
    }
    if (arg2 != NULL) {
        var_r4_155 = (signed char *) (arg2);
    } else {
        var_r4_155 = (signed char *) ("<Dynamic>");
    }
    strcpy(((u8 *) temp_r31_139) + 4, var_r4_155);
    strncpy(((u8 *) temp_r31_139) + 0x24, arg0, 0xFFU);
    M2C_FIELD(temp_r31_139, MKHeap **, 0x124) = MKHeap::Current();
    M2C_FIELD(temp_r31_139, s8 *, 0x128) = (s8) (*MKHeap::tempMemOverride > 0);
    ProcessQueue();
    return M2C_FIELD(temp_r31_139, s32 *, 0);
}
#endif

#if 0 // DRAFT: function call 'strcpy(unsigned char *, const char *)' does not match 'strcpy(char *, const char *)'
s32 MKPackage_QLoad(const char *arg0, int arg1) {
    s32 temp_r0_193;
    s32 temp_r3_200;
    void *temp_r31_197;

    temp_r0_193 = queueCount * 0x12C;
    queueCount += 1;
    temp_r31_197 = pQueue + temp_r0_193;
    memset(temp_r31_197, 0, 0x12CU);
    temp_r3_200 = nextQueueHandle;
    nextQueueHandle = temp_r3_200 + 1;
    M2C_FIELD(temp_r31_197, s32 *, 0) = temp_r3_200;
    if ((s32) nextQueueHandle == 0) {
        nextQueueHandle += 1;
    }
    strcpy(((u8 *) temp_r31_197) + 4, arg0);
    M2C_FIELD(temp_r31_197, MKHeap **, 0x124) = MKHeap::Current();
    M2C_FIELD(temp_r31_197, s8 *, 0x128) = (s8) (*MKHeap::tempMemOverride > 0);
    ProcessQueue();
    return M2C_FIELD(temp_r31_197, s32 *, 0);
}
#endif

void MKPackage_UseQ() {
    PackageQueueInfo *var_r3_245;

    if ((u8) QInterface == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_245 = (PackageQueueInfo *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x960, NULL, 0));
        } else {
            var_r3_245 = malloc(0x960);
        }
        pQueue = var_r3_245;
        memset(var_r3_245, 0, 0x960U);
        QInterface = 1;
    }
}

#if 0 // DRAFT: undefined identifier 'RemoveFromQueue'
void ProcessQueue() {
    s32 temp_r31_301;

    if (((s32) activeHandle == 0) && ((s32) queueCount > 0)) {
loop_4:
        if (((s32) queueCount > 0) && ((u8) pQueue->unk129 != 0)) {
            RemoveFromQueue(pQueue);
            goto loop_4;
        }
        if ((s32) queueCount != 0) {
            activeHandle = pQueue->unk0;
            pQueue->unk124->Push();
            temp_r31_301 = *MKHeap::tempMemOverride > 0;
            ((MKHeap *) pQueue->unk128)->SetTempMemOverrideStatus((u8) *MKHeap::tempMemOverride);
            if ((s8) (u8) pQueue->unk24 != 0) {
                QInterface = 0;
                MKPackage_LoadDynamic(&pQueue->unk24, 1U, &pQueue->unk4);
                QInterface = 1;
            } else {
                QInterface = 0;
                MKPackage_Load(&pQueue->unk4, 1U);
                QInterface = 1;
            }
            ((MKHeap *) temp_r31_301)->SetTempMemOverrideStatus(M2C_ERROR(/* Read from unset register $r4 */));
            MKHeap::Pop();
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'PackageQueueInfo' to 'long'
PackageQueueInfo *FindQueuedPackage(int arg0) {
    s32 var_ctr_342;
    s32 var_r4_340;

    var_r4_340 = 0;
    var_ctr_342 = queueCount;
    if ((s32) queueCount > 0) {
loop_1:
        if (arg0 == (s32) *(pQueue + var_r4_340)) {
            return pQueue + var_r4_340;
        }
        var_r4_340 += 0x12C;
        var_ctr_342 -= 1;
        if (var_ctr_342 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

void RemoveFromQueue(PackageQueueInfo *arg0) {
    PackageQueueInfo *var_r30_366;
    s32 var_r31_372;

    var_r30_366 = arg0;
    if (var_r30_366 != NULL) {
        var_r31_372 = (s32) (var_r30_366 - pQueue) / 300;
        queueCount -= 1;
loop_3:
        if (var_r31_372 < (s32) queueCount) {
            memcpy(var_r30_366, var_r30_366 + 0x12C, 0x12CU);
            var_r30_366 += 0x12C;
            var_r31_372 += 1;
            goto loop_3;
        }
    }
}

#if 0 // DRAFT: function call 'MKArchive_DeregisterArchive(signed char *)' does not match 'MKArchive_DeregisterArchive(const char *)'
s32 MKPackage_Free() {
    MKHeap *temp_r3_462;
    PackageQueueInfo *var_r3_544;
    s32 temp_r27_535;
    s32 var_r25_458;
    s32 var_r25_490;
    s32 var_r26_418;
    s32 var_r26_555;
    s32 var_r28_455;
    s32 var_r28_496;
    s32 var_r29_495;
    s32 var_r30_417;
    s32 var_r30_556;
    s8 *temp_r26_624;
    s8 *temp_r27_600;
    s8 *temp_r29_456;
    u32 temp_ret_573;

    if ((s32) packageState == 0) {
        if ((s8) M2C_FIELD(packageName, u8 *, 0x20) != 0) {
            MKArchive_DeregisterArchive(packageName + 0x20);
        }
        return 0;
    }
    var_r30_417 = 0;
    var_r26_418 = 0;
    if ((MKHeap *) pHeapToLoadInto != NULL) {
        var_r26_418 = *MKHeap::tempMemOverride > 0;
        pHeapToLoadInto->Push();
        ((MKHeap *) bTempMemBeingUsed)->SetTempMemOverrideStatus(M2C_ERROR(/* Read from unset register $r4 */));
    }
    if (((s32) packageState != 3) && (MKPackage_IsLoaded(NULL, NULL) == 0)) {
        MKPackage_Cancel();
loop_10:
        if (MKPackage_IsLoaded(NULL, NULL) == 0) {
            MKPackage_Update();
            goto loop_10;
        }
    }
    if ((MKHeap *) pHeapToLoadInto != NULL) {
        ((MKHeap *) var_r26_418)->SetTempMemOverrideStatus((u8) (u32) (u64) MKHeap::Pop());
    }
    var_r28_455 = 0;
    temp_r29_456 = packageName + 0x40;
    var_r25_458 = 0;
loop_19:
    if (var_r25_458 < (s32) nmbrOfPackageEntries) {
        temp_r3_462 = M2C_FIELD(&temp_r29_456[var_r28_455], MKHeap **, 0xC);
        if (temp_r3_462 != NULL) {
            temp_r3_462->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
            if ((u8) packageCancelled == 0) {
                MKPackage_undelivered += 1;
            }
            M2C_FIELD(&temp_r29_456[var_r28_455], s32 *, 0xC) = 0;
        }
        var_r25_458 += 1;
        var_r28_455 += 0x14;
        goto loop_19;
    }
    if (((u8) packageCancelled == 0) && ((s8 *) pAutoEntries != NULL)) {
        var_r25_490 = 0;
        if ((s32) nmbrOfPackageEntries == (s32) nmbrOfAutoEntries) {
            var_r25_490 = 0;
            var_r29_495 = 0;
            var_r28_496 = 0;
loop_26:
            if (var_r25_490 < (s32) nmbrOfPackageEntries) {
                if (strcmpi((packageName + 0x40)[var_r28_496], &pAutoEntries[var_r29_495]) == 0) {
                    var_r25_490 += 1;
                    var_r29_495 += 0x22;
                    var_r28_496 += 0x14;
                    goto loop_26;
                }
            }
        }
        if ((((s32) nmbrOfPackageEntries != (s32) nmbrOfAutoEntries) || (var_r25_490 != (s32) nmbrOfPackageEntries) || (System_GetCommandLineParameter("OutputPackages", 0U), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0))) && (strcmpi(packageName, "<Dynamic>") != 0)) {
            temp_r27_535 = (nmbrOfAutoEntries * 0x24) + 1;
            if (MKHeap::Current() != NULL) {
                var_r3_544 = (PackageQueueInfo *) (((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r27_535, NULL, 0, 0U));
            } else {
                var_r3_544 = malloc(temp_r27_535);
            }
            *var_r3_544 = 0;
            var_r26_555 = 0;
            var_r30_556 = 0;
loop_36:
            if (var_r26_555 < (s32) nmbrOfAutoEntries) {
                strcat((s8 *) var_r3_544, &pAutoEntries[var_r30_556]);
                strcat((s8 *) var_r3_544, "
\n");
                var_r26_555 += 1;
                var_r30_556 += 0x22;
                goto loop_36;
            }
            temp_ret_573 = strlen((s8 *) var_r3_544);
            MKArchive_Save(Str_Printf("%s", packageName, M2C_BITWISE(f32, temp_ret_573)), 0U, var_r3_544, temp_ret_573 + 1);
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Main()))->TFree(var_r3_544, NULL, 0);
            } else {
                free((s8 *) var_r3_544);
            }
            var_r30_417 = 1;
        }
        temp_r27_600 = pAutoEntries;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Main()))->TFree(temp_r27_600, NULL, 0);
        } else {
            free(temp_r27_600);
        }
        pAutoEntries = NULL;
        nmbrOfAutoEntries = 0;
    }
    if ((s8) M2C_FIELD(packageName, u8 *, 0x20) != 0) {
        MKArchive_DeregisterArchive(packageName + 0x20);
    }
    temp_r26_624 = pPackageText;
    if (temp_r26_624 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Main()))->TFree(temp_r26_624, NULL, 0);
        } else {
            free(temp_r26_624);
        }
    }
    pPackageText = NULL;
    packageTextSize = -1U;
    nmbrOfAutoEntries = 0;
    packageState = 0;
    return var_r30_417;
}
#endif

void MKPackage_Cancel() {
    packageCancelled = 1;
}

u8 MKPackage_IsLoaded(float *arg0, int *arg1) {
    f32 var_f0_723;

    switch ((s32) packageState) {                   /* irregular */
    case 1:
        if (arg0 != NULL) {
            *arg0 = 0.0f;
        }
        if (arg1 != NULL) {
            *arg1 = 0;
        }
        MKPackage_Update();
        return 0U;
    case 2:
        if ((s32) nmbrEntriesLoaded < (s32) nmbrOfPackageEntries) {
            MKPackage_Update();
        }
        /* fallthrough */
    case 3:
        if (arg0 != NULL) {
            if ((s32) totalBytesInPackage != 0) {
                var_f0_723 = (f32) totalBytesLoaded / (f32) totalBytesInPackage;
            } else {
                var_f0_723 = 1.0f;
            }
            *arg0 = var_f0_723;
        }
        if (arg1 != NULL) {
            *arg1 = totalBytesLoaded;
        }
        return nmbrEntriesLoaded == nmbrOfPackageEntries;
    case 0:
        /* fallthrough */
    default:
        return 1U;
    }
}

#if 0 // DRAFT: function call 'strcpy(signed char *, char *)' does not match 'strcpy(char *, const char *)'
void MKPackage_LoadDynamic(char *arg0, bool arg1, char *arg2) {
    PackageQueueInfo *var_r3_784;
    s32 temp_r30_775;
    u32 temp_r3_773;

    pHeapToLoadInto = MKHeap::Current();
    *binaryPackageName = 0;
    bTempMemBeingUsed = *MKHeap::tempMemOverride > 0;
    temp_r3_773 = strlen(arg0);
    packageTextSize = temp_r3_773;
    temp_r30_775 = temp_r3_773 + 1;
    if (MKHeap::Current() != NULL) {
        var_r3_784 = (PackageQueueInfo *) (((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r30_775, NULL, 0, 0U));
    } else {
        var_r3_784 = malloc(temp_r30_775);
    }
    pPackageText = (s8 *) var_r3_784;
    strcpy((s8 *) var_r3_784, arg0);
    if (arg2 == NULL) {
        strcpy(packageName, "<Dynamic>");
    } else {
        strcpy(packageName, arg2);
    }
    MKPackage_LoadInternal(arg1);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap *' to 'float'
void MKPackage_Load(char *arg0, bool arg1) {
    MKHeap *temp_ret_825;
    PackageQueueInfo *var_r3_901;
    s32 temp_r30_892;
    s32 temp_ret_856;
    s32 var_r3_927;
    s8 *temp_r3_872;
    u8 temp_r7_834;

    temp_ret_825 = MKHeap::Current();
    temp_r7_834 = *MKHeap::tempMemOverride > 0;
    pHeapToLoadInto = temp_ret_825;
    bTempMemBeingUsed = temp_r7_834;
    *binaryPackageName = 0;
    pPackageText = NULL;
    packageTextSize = -1U;
    strncpy(packageName, Str_Printf("%s.pkg", arg0, binaryPackageName, 0, temp_r7_834, *MKHeap::tempMemOverride, M2C_BITWISE(f32, temp_ret_825)), 0x20U);
    if (((u8) gDisablePackages != 0) || (temp_ret_856 = MKArchive_Exists(packageName, (int *) &packageTextSize), ((temp_ret_856 == 0) != 0)) || ((s32) packageTextSize == 0)) {
        MKPackage_LoadInternal(arg1);
        return;
    }
    temp_r3_872 = Str_Printf("%s.bpk", arg0, M2C_BITWISE(f32, temp_ret_856));
    if (MKArchive_Exists(temp_r3_872, NULL) != 0) {
        MKHeap::ActivateTempMemOverride();
        if (MKArchive_RegisterArchive(temp_r3_872, arg1) != 0) {
            strcpy(binaryPackageName, temp_r3_872);
        }
        MKHeap::DeactivateTempMemOverride();
    }
    temp_r30_892 = packageTextSize + 1;
    if (MKHeap::Current() != NULL) {
        var_r3_901 = (PackageQueueInfo *) (((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r30_892, NULL, 0, 0U));
    } else {
        var_r3_901 = malloc(temp_r30_892);
    }
    pPackageText = (s8 *) var_r3_901;
    if (arg1 == 0) {
        MKArchive_Load(packageName, (int *) &packageTextSize, var_r3_901, -1);
        pPackageText[packageTextSize] = 0;
        MKPackage_LoadInternal(arg1);
        return;
    }
    var_r3_927 = 2;
    packageState = 1;
    if ((s8) (u8) *binaryPackageName != 0) {
        var_r3_927 = 1;
    }
    asyncState = var_r3_927;
}
#endif

#if 0 // DRAFT: undefined identifier 'ProcessPackageFilenames'
void MKPackage_LoadInternal(bool arg0) {
    PackageQueueInfo *var_r3_1048;
    s32 var_r28_1005;
    s32 var_r31_1007;
    u8 var_r28_952;
    void *temp_r29_1010;

    var_r28_952 = arg0;
    MKPackage_kLoadedPerSecond = 0;
    MKPackage_memoryDelivered = 0;
    Timer_GetSystemTime(&packageTime);
    if ((u8) disableAsyncPackages != 0) {
        var_r28_952 = 0;
    }
    nmbrOfPackageEntries = 0;
    nmbrOfAutoEntries = 0;
    nmbrEntriesLoaded = 0;
    totalBytesInPackage = 0;
    totalBytesLoaded = 0;
    if ((s8 *) pPackageText != NULL) {
        ProcessPackageFilenames();
    }
    if ((s32) nmbrOfPackageEntries != 0) {
        System_GetCommandLineParameter("OutputPackages", 0U);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
            System_GetCommandLineParameter("OutputOrder", 0U);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
                qsort((struct _struct_pPackageEntries_0x14 (*)[]) pPackageEntries, nmbrOfPackageEntries, 0x14, PackageSort);
            }
        }
        if (var_r28_952 != 0) {
            asyncState = 5;
        } else {
            var_r28_1005 = 0;
            var_r31_1007 = 0;
loop_12:
            if (var_r28_1005 < (s32) nmbrOfPackageEntries) {
                temp_r29_1010 = pPackageEntries + var_r31_1007;
                M2C_FIELD(temp_r29_1010, s8 **, 0xC) = MKArchive_Load(M2C_FIELD(temp_r29_1010, s8 **, 0), NULL, NULL, -1);
                var_r28_1005 += 1;
                var_r31_1007 += 0x14;
                nmbrEntriesLoaded += 1;
                totalBytesLoaded += M2C_FIELD(temp_r29_1010, s32 *, 8);
                goto loop_12;
            }
            LogLoadStats();
        }
    }
    System_GetCommandLineParameter("OutputPackages", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        if (MKHeap::Current() != NULL) {
            var_r3_1048 = (PackageQueueInfo *) (((MKHeap *) (MKHeap::Main()))->TAlloc(0x8800, NULL, 0, 0U));
        } else {
            var_r3_1048 = malloc(0x8800);
        }
        pAutoEntries = (s8 *) var_r3_1048;
        nmbrOfAutoEntries = 0;
    }
    packageState = 2;
    packageCancelled = 0;
    MKPackage_missesAccumulator += MKPackage_misses;
    MKPackage_misses = 0;
    MKPackage_undelivered = 0;
    nmbrOfChunkReads = 0;
}
#endif

#if 0 // DRAFT: illegal string constant
void ProcessPackageFilenames() {
    s8 *var_r30_1097;
    s8 *var_r4_1119;
    u32 var_r3_1117;
    u8 temp_r0_1104;
    u8 var_r29_1111;

    System_GetCommandLineParameter("OutputPackages", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
        var_r30_1097 = strtok(pPackageText, "
\n");
loop_15:
        if (var_r30_1097 != NULL) {
loop_4:
            temp_r0_1104 = (u8) *var_r30_1097;
            if ((s8) temp_r0_1104 == 0x20) {
block_3:
                var_r30_1097 += 1;
                goto loop_4;
            }
            if ((s8) temp_r0_1104 == 9) {
                goto block_3;
            }
            var_r29_1111 = 0;
            if ((s8) temp_r0_1104 == 0x2B) {
                var_r29_1111 = 1;
                var_r30_1097 += 1;
            }
            var_r3_1117 = strlen(var_r30_1097);
            var_r4_1119 = &var_r30_1097[var_r3_1117];
loop_10:
            if (((s32) var_r3_1117 != 0) && ((s8) M2C_FIELD(&var_r30_1097[var_r3_1117], u8 *, -1) == 0x20)) {
                var_r4_1119 -= 1;
                M2C_FIELD(var_r4_1119, s8 *, -1) = 0;
                var_r3_1117 -= 1;
                goto loop_10;
            }
            if ((s8) (u8) *var_r30_1097 != 0) {
                AddToPackage(var_r30_1097, var_r29_1111);
            }
            var_r30_1097 = strtok(NULL, "
\n");
            goto loop_15;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'strcmpi(signed char, char *)' does not match 'strcmpi(signed char *, signed char *)'
void AddToPackage(char *arg0, bool arg1) {
    s32 temp_r6_1223;
    s32 var_r27_1165;
    s32 var_r29_1167;
    s8 var_r29_1204;
    struct _struct_pPackageEntries_0x14 *temp_r4_1207;
    void *temp_r4_1226;

    var_r27_1165 = 0;
    var_r29_1167 = 0;
loop_3:
    if (var_r27_1165 < (s32) nmbrOfPackageEntries) {
        if (strcmpi(*(pPackageEntries + var_r29_1167), arg0) != 0) {
            var_r27_1165 += 1;
            var_r29_1167 += 0x14;
            goto loop_3;
        }
    }
    if ((var_r27_1165 == (s32) nmbrOfPackageEntries) && (MKArchive_Exists(arg0, (int *) &pPackageEntries[nmbrOfPackageEntries].unk8) != 0)) {
        pPackageEntries[nmbrOfPackageEntries].unk0 = arg0;
        var_r29_1204 = 0;
        temp_r4_1207 = (_struct_pPackageEntries_0x14 *) (&pPackageEntries[nmbrOfPackageEntries]);
        temp_r4_1207->unk4 = MKArchive_GetOffset(arg0);
        temp_r4_1207->unkC = 0;
        if ((arg1 != 0) || (Util_WildcardPatternMatch(arg0, gpTempMemFilePatterns) != 0)) {
            var_r29_1204 = 1;
        }
        temp_r6_1223 = nmbrOfPackageEntries * 0x14;
        nmbrOfPackageEntries += 1;
        temp_r4_1226 = pPackageEntries + temp_r6_1223;
        M2C_FIELD(temp_r4_1226, s8 *, 0x10) = var_r29_1204;
        totalBytesInPackage += M2C_FIELD(temp_r4_1226, s32 *, 8);
    }
}
#endif

s32 PackageSort(const void *arg0, const void *arg1) {
    return M2C_FIELD(arg0, s32 *, 4) - M2C_FIELD(arg1, s32 *, 4);
}

#if 0 // DRAFT: function call 'MKArchive_Open(signed char[32], int, unsigned int)' does not match 'MKArchive_Open(const char *, int *, bool)' Too many errors printed, aborting 
void MKPackage_Update() {
    PackageQueueInfo *var_r3_1494;
    PackageQueueInfo *var_r3_1595;
    PackageQueueInfo *var_r3_1638;
    s32 temp_cr0_eq_1692;
    s32 temp_r0_1428;
    s32 temp_r0_1553;
    s32 temp_r27_1586;
    s32 temp_r27_1603;
    s32 temp_r28_1629;
    s32 temp_r29_1485;
    s32 temp_r29_1502;
    s32 temp_r3_1337;
    s32 temp_r3_1548;
    s32 temp_r3_1682;
    s32 temp_r5_1527;
    s32 temp_r6_1424;
    s32 temp_r9_1434;
    s32 var_r28_1571;
    s32 var_r30_1314;
    s8 *temp_r28_1695;
    u32 temp_r11_1439;
    void *temp_r28_1477;
    void *temp_r29_1578;
    void *temp_r3_1433;
    void *temp_r4_1526;
    void *temp_r5_1673;

    if ((s8) init_475 == 0) {
        resetState_474 = 0;
        init_475 = 1;
    }
    if (((s32) resetState_474 != OSGetResetButtonState()) || ((u32) (OSGetTick() - gMKLastIdleTime) > 0x0269FB20U)) {
        VIWaitForRetrace();
        resetState_474 = OSGetResetButtonState();
    }
    if ((s8) init_481 == 0) {
        nFilesInChunk_480 = 0;
        init_481 = 1;
    }
    if ((s8) init_484 == 0) {
        chunkLength_483 = 0;
        init_484 = 1;
    }
    if ((s8) init_487 == 0) {
        chunkBaseOffset_486 = 0;
        init_487 = 1;
    }
    if ((s8) init_491 == 0) {
        lowMemory_490 = 0;
        init_491 = 1;
    }
    var_r30_1314 = 0;
    if ((MKHeap *) pHeapToLoadInto != NULL) {
        var_r30_1314 = *MKHeap::tempMemOverride > 0;
        pHeapToLoadInto->Push();
        ((MKHeap *) bTempMemBeingUsed)->SetTempMemOverrideStatus(M2C_ERROR(/* Read from unset register $r4 */));
    }
loop_86:
    if (((s32) asyncState != 0) && (File_IsAnyBusy() == 0)) {
        if ((u32) asyncState <= 9U) {
            switch (asyncState) {                   /* switch 1 */
            case 1:                                 /* switch 1 */
                MKHeap::ActivateTempMemOverride();
                temp_r3_1337 = MKArchive_GetAsyncRegistrationStatus();
                switch (temp_r3_1337) {             /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    break;
                case -1:                            /* switch 2 */
                    M2C_FIELD(packageName, u8 *, 0x20) = 0U;
                    /* fallthrough */
                default:                            /* switch 2 */
                    asyncState = 2;
                    break;
                }
                MKHeap::DeactivateTempMemOverride();
                break;
            case 2:                                 /* switch 1 */
                afd = MKArchive_Open(packageName, NULL, 1U);
                asyncState = 3;
                break;
            case 3:                                 /* switch 1 */
                File_Read(afd, pPackageText, (s32) packageTextSize, (s32) packageTextSize);
                asyncState = 4;
                break;
            case 4:                                 /* switch 1 */
                File_Sync(afd, -1);
                MKArchive_Close(afd);
                pPackageText[packageTextSize] = 0;
                asyncState = 0;
                MKPackage_LoadInternal(1U);
                break;
            case 5:                                 /* switch 1 */
                if ((u8) packageCancelled != 0) {
                    asyncState = 0;
                    nmbrEntriesLoaded = nmbrOfPackageEntries;
                } else {
                    afd = MKArchive_Open(*(packageName + 0x40 + (nmbrEntriesLoaded * 0x14)), NULL, 1U);
                    asyncState = 6;
                    if (((u8) disablePackageChunking == 0) && ((u8) lowMemory_490 == 0)) {
                        chunkLength_483 = 0;
                        nFilesInChunk_480 = 0;
                        temp_r6_1424 = *(packageName + 0x40 + ((nmbrEntriesLoaded * 0x14) + 4));
                        chunkBaseOffset_486 = temp_r6_1424;
loop_34:
                        temp_r0_1428 = nmbrEntriesLoaded + nFilesInChunk_480;
                        if (temp_r0_1428 < (s32) nmbrOfPackageEntries) {
                            temp_r3_1433 = packageName + 0x40 + (temp_r0_1428 * 0x14);
                            temp_r9_1434 = M2C_FIELD(temp_r3_1433, s32 *, 4);
                            if (temp_r9_1434 >= 0) {
                                temp_r11_1439 = (temp_r9_1434 + M2C_FIELD(temp_r3_1433, s32 *, 8)) - temp_r6_1424;
                                if ((temp_r11_1439 <= 0x100000U) && (((s32) nFilesInChunk_480 == 0) || ((s32) (temp_r9_1434 - (M2C_FIELD(temp_r3_1433, s32 *, -0x10) + M2C_FIELD(temp_r3_1433, s32 *, -0xC))) <= 0x10000))) {
                                    chunkLength_483 = temp_r11_1439;
                                    nFilesInChunk_480 += 1;
                                    goto loop_34;
                                }
                            }
                        }
                        if (((s32) chunkLength_483 != 0) && (((s8) M2C_FIELD(packageName, u8 *, 0x20) != 0) || ((s32) nFilesInChunk_480 > 2))) {
                            asyncState = 8;
                            chunkLength_483 = (chunkLength_483 + 0x1F) & 0xFFFFFFE0;
                        }
                    }
                }
                break;
            case 6:                                 /* switch 1 */
                temp_r28_1477 = packageName + 0x40 + (nmbrEntriesLoaded * 0x14);
                if ((PackageQueueInfo *) M2C_FIELD(temp_r28_1477, PackageQueueInfo **, 0xC) == NULL) {
                    if ((u8) M2C_FIELD(temp_r28_1477, u8 *, 0x10) != 0) {
                        temp_r29_1485 = M2C_FIELD(temp_r28_1477, s32 *, 8) + 1;
                        if (MKHeap::Current() != NULL) {
                            var_r3_1494 = ((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r29_1485, NULL, 0, 0U);
                        } else {
                            var_r3_1494 = malloc(temp_r29_1485);
                        }
                    } else {
                        temp_r29_1502 = M2C_FIELD(temp_r28_1477, s32 *, 8) + 1;
                        if (MKHeap::Current() != NULL) {
                            var_r3_1494 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_1502, NULL, 0);
                        } else {
                            var_r3_1494 = malloc(temp_r29_1502);
                        }
                    }
                    M2C_FIELD(temp_r28_1477, PackageQueueInfo **, 0xC) = var_r3_1494;
                    *(M2C_FIELD(temp_r28_1477, s32 *, 8) + M2C_FIELD(temp_r28_1477, PackageQueueInfo **, 0xC)) = 0;
                }
                temp_r4_1526 = packageName + 0x40 + (nmbrEntriesLoaded * 0x14);
                temp_r5_1527 = M2C_FIELD(temp_r4_1526, s32 *, 8);
                File_Read(afd, M2C_FIELD(temp_r4_1526, void **, 0xC), temp_r5_1527, temp_r5_1527);
                asyncState = 7;
                nmbrOfChunkReads += 1;
                break;
            case 7:                                 /* switch 1 */
                File_Sync(afd, -1);
                MKArchive_Close(afd);
                temp_r3_1548 = nmbrEntriesLoaded + 1;
                afd = -1;
                temp_r0_1553 = *(packageName + 0x40 + ((nmbrEntriesLoaded * 0x14) + 8));
                nmbrEntriesLoaded = temp_r3_1548;
                totalBytesLoaded += temp_r0_1553;
                if (temp_r3_1548 < (s32) nmbrOfPackageEntries) {
                    asyncState = 5;
                } else {
                    asyncState = 0;
                    lowMemory_490 = 0;
                    packageState = 3;
                }
                LogLoadStats();
                break;
            case 8:                                 /* switch 1 */
                var_r28_1571 = 0;
loop_69:
                if (var_r28_1571 < (s32) nFilesInChunk_480) {
                    temp_r29_1578 = packageName + 0x40 + ((nmbrEntriesLoaded + var_r28_1571) * 0x14);
                    if ((PackageQueueInfo *) M2C_FIELD(temp_r29_1578, PackageQueueInfo **, 0xC) == NULL) {
                        if ((u8) M2C_FIELD(temp_r29_1578, u8 *, 0x10) != 0) {
                            temp_r27_1586 = M2C_FIELD(temp_r29_1578, s32 *, 8) + 1;
                            if (MKHeap::Current() != NULL) {
                                var_r3_1595 = ((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r27_1586, NULL, 0, 0U);
                            } else {
                                var_r3_1595 = malloc(temp_r27_1586);
                            }
                        } else {
                            temp_r27_1603 = M2C_FIELD(temp_r29_1578, s32 *, 8) + 1;
                            if (MKHeap::Current() != NULL) {
                                var_r3_1595 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_1603, NULL, 0);
                            } else {
                                var_r3_1595 = malloc(temp_r27_1603);
                            }
                        }
                        M2C_FIELD(temp_r29_1578, PackageQueueInfo **, 0xC) = var_r3_1595;
                        *(M2C_FIELD(temp_r29_1578, s32 *, 8) + M2C_FIELD(temp_r29_1578, PackageQueueInfo **, 0xC)) = 0;
                    }
                    var_r28_1571 += 1;
                    goto loop_69;
                }
                temp_r28_1629 = chunkLength_483 + 0x2000;
                if (MKHeap::Current() != NULL) {
                    var_r3_1638 = ((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r28_1629, NULL, 0, 1U);
                } else {
                    var_r3_1638 = malloc(temp_r28_1629);
                }
                pChunkBuffer_489 = (s8 *) var_r3_1638;
                if (var_r3_1638 == NULL) {
                    lowMemory_490 = 1;
                    asyncState = 6;
                } else {
                    File_Read(afd, var_r3_1638, (s32) chunkLength_483, chunkLength_483 + 0x2000);
                    asyncState = 9;
                    nmbrOfChunkReads += 1;
                }
                break;
            case 9:                                 /* switch 1 */
loop_78:
                temp_cr0_eq_1692 = (s32) nFilesInChunk_480 == 0;
                nFilesInChunk_480 -= 1;
                if (temp_cr0_eq_1692 == 0) {
                    temp_r5_1673 = packageName + 0x40 + (nmbrEntriesLoaded * 0x14);
                    memcpy(M2C_FIELD(temp_r5_1673, void **, 0xC), &pChunkBuffer_489[M2C_FIELD(temp_r5_1673, s32 *, 4) - chunkBaseOffset_486], M2C_FIELD(temp_r5_1673, u32 *, 8));
                    temp_r3_1682 = nmbrEntriesLoaded * 0x14;
                    nmbrEntriesLoaded += 1;
                    totalBytesLoaded += M2C_FIELD(&(packageName + 0x40)[temp_r3_1682], s32 *, 8);
                    goto loop_78;
                }
                temp_r28_1695 = pChunkBuffer_489;
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Main()))->TFree(temp_r28_1695, NULL, 0);
                } else {
                    free(temp_r28_1695);
                }
                File_Sync(afd, -1);
                MKArchive_Close(afd);
                afd = -1;
                if ((s32) nmbrEntriesLoaded < (s32) nmbrOfPackageEntries) {
                    asyncState = 5;
                } else {
                    asyncState = 0;
                    lowMemory_490 = 0;
                }
                LogLoadStats();
                break;
            }
        }
        goto loop_86;
    }
    if ((MKHeap *) pHeapToLoadInto != NULL) {
        ((MKHeap *) var_r30_1314)->SetTempMemOverrideStatus((u8) (u32) (u64) MKHeap::Pop());
    }
}
#endif

void LogLoadStats() {

}

#if 0 // DRAFT: function call 'MKArchive_SetLoadInterceptHandler(void * (*)(signed char *, long *, void *, long *))' does not match 'MKArchive_SetLoadInterceptHandler(void * (*
void MKPackage_DeinitModule() {
    MKArchive_SetLoadInterceptHandler(pPreviousHandler);
    pPreviousHandler = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'PackageIntercept'
void MKPackage_InitModule() {
    u8 var_r31_1792;

    pPreviousHandler = MKArchive_SetLoadInterceptHandler(PackageIntercept);
    System_GetCommandLineParameter("disablePackages", 0U);
    var_r31_1792 = 0;
    gDisablePackages = M2C_ERROR(/* Read from unset register $r3 */) != 0;
    System_GetCommandLineParameter("outputOrder", 0U);
    if (((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) || (System_GetCommandLineParameter("outputPackages", 0U), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0))) {
        var_r31_1792 = 1;
    }
    disablePackageChunking = var_r31_1792;
    System_GetCommandLineParameter("AssertPackageMisses", 0U);
    assertMisses = M2C_ERROR(/* Read from unset register $r3 */) != 0;
    MKPackage_UseQ();
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match 'strcpy(char *, const char *)'
void *PackageIntercept(const char *arg0, int *arg1, void *arg2, int *arg3) {
    s32 temp_r0_1856;
    s32 temp_r0_1865;
    s32 var_r25_1872;
    s32 var_r27_1874;
    s8 *temp_r26_1900;
    s8 *temp_r4_1854;
    s8 *temp_r4_1885;
    void *temp_r28_1884;
    void *var_r30_1836;

    var_r30_1836 = arg2;
    if ((s32) packageState != 0) {
        if ((s8 *) pAutoEntries != NULL) {
            if ((s32) *MKHeap::tempMemOverride > 0) {
                temp_r4_1854 = Str_Printf("+%s", arg0, pAutoEntries);
                temp_r0_1856 = nmbrOfAutoEntries * 0x22;
                nmbrOfAutoEntries += 1;
                strcpy(&pAutoEntries[temp_r0_1856], temp_r4_1854);
            } else {
                temp_r0_1865 = nmbrOfAutoEntries * 0x22;
                nmbrOfAutoEntries += 1;
                strcpy(&pAutoEntries[temp_r0_1865], arg0);
            }
        }
        var_r25_1872 = 0;
        var_r27_1874 = 0;
loop_20:
        if (var_r25_1872 >= (s32) nmbrOfPackageEntries) {
            MKPackage_misses += 1;
            if ((s32) totalBytesInPackage != 0) {
                strcmp(packageName, "<Dynamic>");
            }
            goto block_23;
        }
        if (strcmpi(arg0, *(pPackageEntries + var_r27_1874)) == 0) {
            temp_r28_1884 = pPackageEntries + var_r27_1874;
            temp_r4_1885 = M2C_FIELD(temp_r28_1884, s8 **, 0xC);
            if (temp_r4_1885 == NULL) {
                MKPackage_misses += 1;
                return NULL;
            }
            if (var_r30_1836 != NULL) {
                memcpy(var_r30_1836, temp_r4_1885, M2C_FIELD((pPackageEntries + var_r27_1874), u32 *, 8));
                temp_r26_1900 = M2C_FIELD(temp_r28_1884, s8 **, 0xC);
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Current()))->Free(temp_r26_1900, NULL, 0);
                } else {
                    free(temp_r26_1900);
                }
            } else {
                var_r30_1836 = temp_r4_1885;
            }
            M2C_FIELD(temp_r28_1884, s8 **, 0xC) = NULL;
            if (arg1 != NULL) {
                *arg1 = M2C_FIELD((pPackageEntries + var_r27_1874), s32 *, 8);
            }
            if (arg3 != NULL) {
                *arg3 = 2;
            }
            MKPackage_memoryDelivered += M2C_FIELD((pPackageEntries + var_r27_1874), s32 *, 8);
            return var_r30_1836;
        }
        var_r25_1872 += 1;
        var_r27_1874 += 0x14;
        goto loop_20;
    }
block_23:
    if (((void *(*)(s8 *, s32 *, void *, s32 *)) pPreviousHandler) != NULL) {
        return (signed char *) (pPreviousHandler(arg0, arg1, var_r30_1836, arg3));
    }
    return NULL;
}
#endif
