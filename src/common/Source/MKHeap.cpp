#include "common/Source/MKHeap.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "dolphin/os.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

s32 atoi();                                         /* extern */
void *malloc(s32);                                  /* extern */
extern s32 baddress;
extern u8 gbGoldMaster;

static s32 black = 0;                               /* const */
static s32 white = 0xFFFFFFFF;                      /* const */

void MKHeap::SetTempMemOverrideStatus(bool arg0) {
    *MKHeap::tempMemOverride = (u8) this != 0;
}

void MKHeap::DeactivateTempMemOverride() {
    *MKHeap::tempMemOverride -= 1;
}

void MKHeap::ActivateTempMemOverride() {
    *MKHeap::tempMemOverride += 1;
}

void MKHeap::GetMemoryStatistics(int *arg0, int *arg1, int *arg2) {
    *arg0 = this->unkC - (s32) this->unk0;
    *arg1 = this->unk4 - this->unk44;
    *arg2 = this->unk44 - this->unkC;
}

void MKHeap::DumpFragmentation() {

}

void MKHeap::DumpTBlocks() {
    f32 temp_r4_69;
    u32 temp_r3_71;
    u32 var_ctr_75;

    temp_r4_69 = this->unk38;
    temp_r3_71 = M2C_BITWISE(s32, temp_r4_69) + (this->unk3C * 0x10);
    var_ctr_75 = (u32) ((temp_r3_71 + 0xF) - M2C_BITWISE(s32, temp_r4_69)) >> 4U;
    if (M2C_BITWISE(u32, temp_r4_69) < temp_r3_71) {
        do {
            var_ctr_75 -= 1;
        } while (var_ctr_75 != 0);
    }
}

u8 MKHeap::ExistsInHeap(const void *arg0) {
    u8 var_r5_87;

    var_r5_87 = 0;
    if (((u32) arg0 >= (u32) this->unk0) && ((u32) arg0 < (u32) this->unk4)) {
        var_r5_87 = 1;
    }
    return var_r5_87;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
void MKHeap::FreeFromAnyHeap(void *arg0, const char *arg1, int arg2) {
    MKHeap *temp_r3_115;
    s32 var_r29_111;
    s32 var_r31_113;

    if (this != NULL) {
        var_r29_111 = 9;
        var_r31_113 = 0x24;
loop_2:
        temp_r3_115 = (MKHeap *) (MKHeap::heapList[var_r31_113]);
        if ((temp_r3_115 != NULL) && (temp_r3_115->ExistsInHeap(this) != 0)) {
            ((MKHeap *) (MKHeap::heapList[var_r31_113]))->Free(this, (s8 *) arg0, (s32) arg1);
            return;
        }
        var_r29_111 -= 1;
        var_r31_113 -= 4;
        if (var_r29_111 < 0) {

        } else {
            goto loop_2;
        }
    }
}
#endif

void MKHeap::TFree(const void *arg0, const char *arg1, int arg2) {
    u32 base;
    u32 end;
    u32 count;
    u32 cursor;
    u32 scan;
    u32 min;
    u32 i;

    base = *(u32 *) &this->unk38;
    end = base + (u32) (this->unk3C * 0x10);
    count = ((end + 0xF) - base) >> 4;
    cursor = base;
    if (base < end) {
        for (i = 0; i < count; i++) {
            if (*(s32 *) cursor == (s32) arg0) {
                this->unk48 -= *(s32 *) (cursor + 4);
                *(s32 *) (cursor + 4) = -1;
                *(s32 *) (cursor + 8) = 0;
                *(s32 *) (cursor + 0xC) = 0;
                if (this->unk44 == *(s32 *) cursor) {
                    scan = base;
                    this->unk44 = this->unk4;
                    while (scan < end) {
                        if (*(s32 *) (scan + 4) != -1) {
                            min = *(u32 *) scan;
                            if ((u32) this->unk44 < min) {
                                min = (u32) this->unk44;
                            }
                            this->unk44 = (s32) min;
                        }
                        scan += 0x10;
                    }
                }
                UpdatePeak();
                return;
            }
            cursor += 0x10;
        }
    }
}

void *MKHeap::TReAlloc(void *arg0, int arg1, const char *arg2, int arg3) {
    u32 base;
    u32 end;
    u32 count;
    u32 cursor;
    u32 i;
    void *fresh;
    s32 len;

    if (arg0 == NULL) {
        return TAlloc(arg1, arg2, arg3, 0);
    }
    base = *(u32 *) &this->unk38;
    end = base + (u32) (this->unk3C * 0x10);
    count = ((end + 0xF) - base) >> 4;
    cursor = base;
    if (base < end) {
        for (i = 0; i < count; i++) {
            if (*(s32 *) cursor == (s32) arg0) {
                fresh = TAlloc(arg1, arg2, arg3, 0);
                len = arg1;
                if (*(s32 *) (cursor + 4) < arg1) {
                    len = *(s32 *) (cursor + 4);
                }
                memcpy(fresh, arg0, (u32) len);
                TFree(arg0, arg2, arg3);
                return fresh;
            }
            cursor += 0x10;
        }
    }
    return NULL;
}

void *MKHeap::TAlloc(int arg0, const char *arg1, int arg2, bool arg3) {
    u32 base;
    u32 end;
    u32 count;
    u32 cursor;
    u32 i;
    u32 scan;
    u32 prev;
    u32 upper;
    u32 lower;
    u32 min;
    MKHeap *temp;
    s32 spin;
    s32 spC;
    s32 sp8;

    base = *(u32 *) &this->unk38;
    end = base + (u32) (this->unk3C * 0x10);
    count = ((end + 0xF) - base) >> 4;
    cursor = base;
    if (base < end) {
        for (i = 0; i < count; i++) {
            if (*(s32 *) (cursor + 4) == -1) {
                scan = cursor + 0x10;
                while ((scan < end) && (*(s32 *) (scan + 4) == -1)) {
                    scan += 0x10;
                }
                prev = cursor - 0x10;
                while ((prev > base) && (*(s32 *) (prev + 4) == -1)) {
                    prev -= 0x10;
                }
                if (cursor == base) {
                    upper = (u32) this->unk4;
                } else {
                    upper = *(u32 *) prev;
                }
                if (scan == end) {
                    lower = ((u32) this->unkC + 0x1F) & 0xFFFFFFE0;
                } else {
                    lower = (*(u32 *) scan + (*(u32 *) (scan + 4) + 0x1F)) & 0xFFFFFFE0;
                }
                if ((s32) (((upper - 1) & 0xFFFFFFE0) - lower) >= arg0) {
                    *(s32 *) (cursor + 8) = (s32) arg1;
                    *(s32 *) (cursor + 0xC) = arg2;
                    if (cursor == base) {
                        *(s32 *) cursor = this->unk4 - arg0;
                    } else {
                        *(s32 *) cursor = *(s32 *) prev - arg0;
                    }
                    *(u32 *) cursor = (*(u32 *) cursor - 1) & 0xFFFFFFE0;
                    *(s32 *) (cursor + 4) = arg0;
                    min = *(u32 *) cursor;
                    if ((u32) this->unk44 < min) {
                        min = (u32) this->unk44;
                    }
                    this->unk44 = (s32) min;
                    temp = this->unk48;
                    this->unk48 = (MKHeap *) ((s32) temp + *(s32 *) (cursor + 4));
                    temp->UpdatePeak();
                    return (void *) *(u32 *) cursor;
                }
            }
            cursor += 0x10;
        }
    }
    if (arg3 == 0) {
        DumpFragmentation();
        DumpTBlocks();
        spin = this->unk3C;
        if (spin > 0) {
            do {
                spin -= 1;
            } while (spin != 0);
        }
        if ((u8) gbGoldMaster == 0) {
            sp8 = black;
            spC = white;
            OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("Couldn't find room/position for temp alloc!\nsize=%d [heapsize=%d]", arg0, this->unk4 - (s32) this->unk0));
        }
    }
    return NULL;
}

void MKHeap::Free(const void *arg0, const char *arg1, int arg2) {
    MKHeap *first;

    if (arg0 != NULL) {
        first = ((MKHeap **) MKHeap::heapList)[0];
        if (((u32) arg0 >= (u32) first->unk44) && ((u32) arg0 <= (u32) first->unk4)) {
            first->TFree(arg0, arg1, arg2);
            return;
        }
        if (((u32) arg0 < (u32) this->unk0) || ((u32) arg0 > (u32) this->unk44)) {
            OSFreeToHeap(__OSCurrHeap, (void *) arg0);
            return;
        }
        UpdatePeak();
    }
}

void *MKHeap::ReAlloc(void *arg0, int arg1, const char *arg2, int arg3) {
    s32 spC;
    s32 sp8;
    void *var_r30_478;
    void *var_r3_526;

    var_r30_478 = arg0;
    if ((s32) *MKHeap::tempMemOverride != 0) {
        return ((MKHeap **) MKHeap::heapList)[0]->TReAlloc(arg0, arg1, arg2, arg3);
    }
    if (var_r30_478 != NULL) {
        this->unkC = this->unk8 + arg1;
        if (((u8) gbGoldMaster == 0) && ((s32) this->unkC >= (s32) this->unk44)) {
            sp8 = black;
            spC = white;
            OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("Out of memory realloc'ing %d bytes", arg1));
        }
        this->UpdatePeak();
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_526 = MKHeap::Current()->Alloc(arg1, NULL, 0);
        } else {
            var_r3_526 = malloc(arg1);
        }
        var_r30_478 = var_r3_526;
    }
    return var_r30_478;
}

void *MKHeap::Alloc(int arg0, const char *arg1, int arg2) {
    s32 spC;
    s32 sp8;
    void *var_r30_560;

    if ((s32) *MKHeap::tempMemOverride != 0) {
        var_r30_560 = ((MKHeap **) MKHeap::heapList)[0]->TAlloc(arg0, arg1, arg2, 0);
    } else {
        var_r30_560 = (void *) ((this->unkC + 0x1F) & 0xFFFFFFE0);
        this->unk8 = (s32) var_r30_560;
        if (((u8) gbGoldMaster == 0) && (((s32) var_r30_560 + arg0) >= this->unk44)) {
            sp8 = black;
            spC = white;
            OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("No memory allocating %d bytes\n(%d free in heap %s)\n[heapsize=%d]", arg0, this->unk44 - (s32) var_r30_560, &this->unk4C, this->unk4 - (s32) this->unk0));
        }
        this->unkC = (s32) ((u8 *) var_r30_560 + arg0);
    }
    UpdatePeak();
    return var_r30_560;
}

s32 MKHeap::Release(int arg0) {
    M2C_FIELD(this, s32 *, 0x30) = (s32) (M2C_FIELD(this, s32 *, 0x30) - 1);
    this->unkC = arg0;
    this->unk8 = 0;
    return this->unkC;
}

s32 MKHeap::Mark() {
    s32 temp_r5_624;

    this->unk8 = 0;
    temp_r5_624 = M2C_FIELD(this, s32 *, 0x30);
    M2C_FIELD(this, s32 *, 0x30) = (s32) (temp_r5_624 + 1);
    M2C_FIELD((this + (temp_r5_624 * 4)), s32 *, 0x10) = (s32) this->unkC;
    return this->unkC;
}

u32 MKHeap::Main() {
    return *MKHeap::heapList;
}

MKHeap *MKHeap::Current() {
    if ((s32) *MKHeap::currentHeap == -1) {
        return NULL;
    }
    return (MKHeap *) (*(MKHeap::heapObjects + (*MKHeap::currentHeap * 4)));
}

s32 MKHeap::Pop() {
    s32 temp_r0_667;

    temp_r0_667 = *MKHeap::currentHeap * 4;
    *MKHeap::currentHeap -= 1;
    return MKHeap::heapObjects[temp_r0_667];
}

void MKHeap::Push() {
    s32 temp_r5_679;

    temp_r5_679 = *MKHeap::currentHeap + 1;
    *MKHeap::currentHeap = temp_r5_679;
    *(MKHeap::heapObjects + (temp_r5_679 * 4)) = (unsigned char) (this);
}

u32 MKHeap::GetPeak() {
    return *MKHeap::peak;
}

void MKHeap::UpdatePeak() {
    MKHeap *temp_r3_708;
    s32 temp_r0_717;
    s32 temp_r4_715;
    s32 temp_r6_716;
    s32 temp_r7_718;
    s32 var_r0_733;
    s32 var_r26_705;
    s32 var_r28_706;
    s32 var_r31_701;
    u32 var_r0_746;
    u32 var_r29_704;
    u32 var_r30_703;
    u32 var_r3_739;
    void *temp_r3_714;

    var_r31_701 = 0;
    var_r30_703 = 0U;
    var_r29_704 = 0U;
    var_r26_705 = 0;
    var_r28_706 = 0;
    do {
        temp_r3_708 = (MKHeap *) (MKHeap::heapList[var_r28_706]);
        if ((temp_r3_708 != NULL) && (temp_r3_708->IsWithinAHeap() == 0)) {
            temp_r3_714 = (void *) (MKHeap::heapList[var_r28_706]);
            temp_r4_715 = M2C_FIELD(temp_r3_714, s32 *, 0xC);
            temp_r6_716 = M2C_FIELD(temp_r3_714, s32 *, 0x44);
            temp_r0_717 = M2C_FIELD(temp_r3_714, s32 *, 0);
            temp_r7_718 = M2C_FIELD(temp_r3_714, s32 *, 4);
            var_r30_703 += temp_r4_715 - temp_r0_717;
            var_r31_701 += (temp_r7_718 - temp_r0_717) - (temp_r6_716 - temp_r4_715);
            var_r29_704 += temp_r7_718 - temp_r6_716;
        }
        var_r26_705 += 1;
        var_r28_706 += 4;
    } while (var_r26_705 < 0xA);
    var_r0_733 = var_r31_701;
    if ((s32) *MKHeap::peak > var_r31_701) {
        var_r0_733 = *MKHeap::peak;
    }
    var_r3_739 = var_r30_703;
    *MKHeap::peak = var_r0_733;
    if ((u32) *MKHeap::mainHeapPeak > var_r30_703) {
        var_r3_739 = *MKHeap::mainHeapPeak;
    }
    var_r0_746 = var_r29_704;
    *MKHeap::mainHeapPeak = var_r3_739;
    if ((u32) *MKHeap::tempHeapPeak > var_r29_704) {
        var_r0_746 = *MKHeap::tempHeapPeak;
    }
    *MKHeap::tempHeapPeak = var_r0_746;
}

void MKHeap::GetHeapStatistics(int *arg0, int *arg1, int *arg2, int *arg3, int *arg4) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_800;
    s32 var_r25_798;
    s32 var_r30_796;

    if (this != NULL) {
        this->unk0 = NULL;
    }
    if (arg0 != NULL) {
        *arg0 = 0;
    }
    if (arg1 != NULL) {
        *arg1 = 0;
    }
    if (arg2 != NULL) {
        *arg2 = 0;
    }
    if (arg3 != NULL) {
        *arg3 = 0;
    }
    var_r30_796 = 0;
    var_r25_798 = 0;
    do {
        temp_r3_800 = (MKHeap *) (MKHeap::heapList[var_r25_798]);
        if ((temp_r3_800 != NULL) && (temp_r3_800->IsWithinAHeap() == 0)) {
            if (this != NULL) {
                this->unk0 += 1;
            }
            ((MKHeap *) (MKHeap::heapList[var_r25_798]))->GetMemoryStatistics((int *) &sp10, (int *) &spC, (int *) &sp8);
            if (arg0 != NULL) {
                *arg0 = sp10 + (spC + sp8 + *arg0);
            }
            if (arg1 != NULL) {
                *arg1 += sp10;
            }
            if (arg2 != NULL) {
                *arg2 += spC;
            }
        }
        var_r30_796 += 1;
        var_r25_798 += 4;
    } while (var_r30_796 < 0xA);
}

u8 MKHeap::IsWithinAHeap() {
    u32 i;
    MKHeap *heap;

    for (i = 0; i < 0xA; i++) {
        heap = ((MKHeap **) MKHeap::heapList)[i];
        if ((heap != NULL) && (heap != this) && ((u32) heap->unk0 <= (u32) this->unk0) && ((u32) heap->unk4 >= (u32) this->unk4)) {
            return 1;
        }
    }
    return 0;
}

void MKHeap::RemoveHeapFromGlobalList() {
    u32 i;

    for (i = 0; i < 0xA; i++) {
        if ((u32) ((MKHeap **) MKHeap::heapList)[i] == (u32) this) {
            ((MKHeap **) MKHeap::heapList)[i] = NULL;
            return;
        }
    }
}

void MKHeap::AddHeapToGlobalList() {
    s32 var_ctr_912;
    s32 var_r4_911;

    var_r4_911 = 0;
    var_ctr_912 = 0xA;
loop_1:
    if ((u32) MKHeap::heapList[var_r4_911] == 0U) {
        MKHeap::heapList[var_r4_911] = (unsigned char) (this);
        return;
    }
    var_r4_911 += 4;
    var_ctr_912 -= 1;
    if (var_ctr_912 == 0) {
        return;
    }
    goto loop_1;
}

void MKHeap::DeInit() {
    if ((u8) M2C_FIELD(this, u8 *, 0x34) == 0) {
        OSFreeToHeap(__OSCurrHeap, this->unk0);
    }
    RemoveHeapFromGlobalList();
}

void MKHeap::Init(int arg0, int arg1, const char *arg2, void *arg3) {
    s32 spC;
    s32 sp8;
    s32 var_r6_1024;

    if (arg3 != NULL) {
        this->unk0 = (MKHeap *) arg3;
        this->unk4 = (s32) ((u8 *) this->unk0 + arg0) - (arg1 * 0x10);
        M2C_FIELD(this, s8 *, 0x34) = 1;
    } else {
        this->unk0 = (MKHeap *) OSAllocFromHeap(__OSCurrHeap, arg0 + (arg1 * 0x10));
        this->unk4 = (s32) ((u8 *) this->unk0 + arg0);
        M2C_FIELD(this, s8 *, 0x34) = 0;
        memset(this->unk0, 0xCD, (u32) arg0);
    }
    this->unkC = (s32) this->unk0;
    M2C_FIELD(this, s32 *, 0x30) = 0;
    strcpy((char *) &this->unk4C, arg2);
    if (((u8) gbGoldMaster == 0) && (this->unk0 == NULL)) {
        sp8 = black;
        spC = white;
        OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("MKHeap::Init couldn't grab %d bytes!", arg0));
    }
    this->unk3C = arg1;
    *(s32 *) &this->unk38 = this->unk4;
    this->unk44 = this->unk4;
    this->unk48 = NULL;
    var_r6_1024 = this->unk4;
    while ((u32) var_r6_1024 < (u32) (*(s32 *) &this->unk38 + (arg1 * 0x10))) {
        M2C_FIELD(var_r6_1024, s32 *, 0) = -1;
        M2C_FIELD(var_r6_1024, s32 *, 4) = -1;
        M2C_FIELD(var_r6_1024, s32 *, 8) = 0;
        M2C_FIELD(var_r6_1024, s32 *, 0xC) = 0;
        var_r6_1024 += 0x10;
    }
    AddHeapToGlobalList();
}

void MKHeap::InitModule() {
    s32 var_ctr_1069;
    s32 var_r3_1064;

    *MKHeap::currentHeap = -1;
    System_GetCommandLineParameter("breakon", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        baddress = atoi();
    }
    var_r3_1064 = 0;
    var_ctr_1069 = 0xA;
    do {
        MKHeap::heapList[var_r3_1064] = 0;
        var_r3_1064 += 4;
        var_ctr_1069 -= 1;
    } while (var_ctr_1069 != 0);
}

void __nwa(unsigned long arg0, const char *arg1, int arg2) {
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Alloc((s32) arg0, arg1, arg2);
        return;
    }
    malloc((s32) arg0);
}

void __nw(unsigned long arg0, const char *arg1, int arg2) {
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Alloc((s32) arg0, arg1, arg2);
        return;
    }
    malloc((s32) arg0);
}

void __dla(void *arg0) {
    ((MKHeap *) arg0)->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
}

void __dl(void *arg0) {
    ((MKHeap *) arg0)->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
}
