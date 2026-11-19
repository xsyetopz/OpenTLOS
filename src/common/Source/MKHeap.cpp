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

#if 0 // DRAFT: illegal operand
void MKHeap::GetMemoryStatistics(int *arg0, int *arg1, int *arg2) {
    *arg0 = this->unkC - this->unk0;
    *arg1 = this->unk4 - this->unk44;
    *arg2 = this->unk44 - this->unkC;
}
#endif

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

#if 0 // DRAFT: type mismatch
u8 MKHeap::ExistsInHeap(const void *arg0) {
    u8 var_r5_87;

    var_r5_87 = 0;
    if ((arg0 >= (MKHeap *) this->unk0) && (arg0 < (u32) this->unk4)) {
        var_r5_87 = 1;
    }
    return var_r5_87;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void MKHeap::FreeFromAnyHeap(void *arg0, const char *arg1, int arg2) {
    MKHeap *temp_r3_115;
    s32 var_r29_111;
    s32 var_r31_113;

    if (this != NULL) {
        var_r29_111 = 9;
        var_r31_113 = 0x24;
loop_2:
        temp_r3_115 = MKHeap::heapList[var_r31_113];
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

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void MKHeap::TFree(const void *arg0, const char *arg1, int arg2) {
    f32 temp_r6_147;
    f32 var_r5_174;
    f32 var_r7_150;
    s32 temp_r0_183;
    u32 temp_r5_149;
    u32 var_ctr_154;
    u32 var_r4_182;

    temp_r6_147 = this->unk38;
    temp_r5_149 = M2C_BITWISE(s32, temp_r6_147) + (this->unk3C * 0x10);
    var_r7_150 = temp_r6_147;
    var_ctr_154 = (u32) ((temp_r5_149 + 0xF) - M2C_BITWISE(s32, temp_r6_147)) >> 4U;
    if (M2C_BITWISE(u32, temp_r6_147) < temp_r5_149) {
loop_1:
        if ((s32) M2C_FIELD(var_r7_150, s32 *, 0) == arg0) {
            this->unk48 -= M2C_FIELD(var_r7_150, s32 *, 4);
            M2C_FIELD(var_r7_150, s32 *, 4) = -1;
            M2C_FIELD(var_r7_150, s32 *, 8) = 0;
            M2C_FIELD(var_r7_150, s32 *, 0xC) = 0;
            if ((s32) this->unk44 == (s32) M2C_FIELD(var_r7_150, s32 *, 0)) {
                var_r5_174 = this->unk38;
                this->unk44 = this->unk4;
loop_9:
                if (M2C_BITWISE(u32, var_r5_174) < (u32) (M2C_BITWISE(s32, this->unk38) + (this->unk3C * 0x10))) {
                    if ((s32) M2C_FIELD(var_r5_174, s32 *, 4) != -1) {
                        var_r4_182 = M2C_FIELD(var_r5_174, u32 *, 0);
                        temp_r0_183 = this->unk44;
                        if ((u32) temp_r0_183 < var_r4_182) {
                            var_r4_182 = (u32) temp_r0_183;
                        }
                        this->unk44 = (s32) var_r4_182;
                    }
                    var_r5_174 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r5_174) + 0x10));
                    goto loop_9;
                }
            }
            UpdatePeak();
            return;
        }
        var_r7_150 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r7_150) + 0x10));
        var_ctr_154 -= 1;
        if (var_ctr_154 == 0) {

        } else {
            goto loop_1;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void *MKHeap::TReAlloc(void *arg0, int arg1, const char *arg2, int arg3) {
    f32 temp_r3_225;
    f32 var_r31_228;
    s32 temp_r0_245;
    s32 var_r5_247;
    u32 temp_r4_227;
    u32 var_ctr_232;
    void *temp_r31_246;

    if (arg0 != NULL) {
        temp_r3_225 = this->unk38;
        temp_r4_227 = M2C_BITWISE(s32, temp_r3_225) + (this->unk3C * 0x10);
        var_r31_228 = temp_r3_225;
        var_ctr_232 = (u32) ((temp_r4_227 + 0xF) - M2C_BITWISE(s32, temp_r3_225)) >> 4U;
        if (M2C_BITWISE(u32, temp_r3_225) < temp_r4_227) {
loop_2:
            if ((s32) M2C_FIELD(var_r31_228, s32 *, 0) == arg0) {
                temp_r0_245 = M2C_FIELD(var_r31_228, s32 *, 4);
                temp_r31_246 = TAlloc(arg1, arg2, arg3, 0U);
                var_r5_247 = arg1;
                if (temp_r0_245 < arg1) {
                    var_r5_247 = temp_r0_245;
                }
                memcpy(temp_r31_246, arg0, (u32) var_r5_247);
                TFree(arg0, arg2, arg3);
                return temp_r31_246;
            }
            var_r31_228 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r31_228) + 0x10));
            var_ctr_232 -= 1;
            if (var_ctr_232 == 0) {
                goto block_7;
            }
            goto loop_2;
        }
block_7:
        return NULL;
    }
    return TAlloc(arg1, arg2, arg3, 0U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void *MKHeap::TAlloc(int arg0, const char *arg1, int arg2, bool arg3) {
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_378;
    f32 temp_r8_292;
    f32 var_r31_295;
    s32 temp_r0_372;
    s32 temp_r0_395;
    s32 var_ctr_396;
    s32 var_r0_341;
    s32 var_r3_330;
    u32 temp_r10_294;
    u32 var_ctr_299;
    u32 var_r0_359;
    u32 var_r3_371;
    void *var_r11_317;
    void *var_r4_306;

    temp_r8_292 = this->unk38;
    temp_r10_294 = M2C_BITWISE(s32, temp_r8_292) + (this->unk3C * 0x10);
    var_r31_295 = temp_r8_292;
    var_ctr_299 = (u32) ((temp_r10_294 + 0xF) - M2C_BITWISE(s32, temp_r8_292)) >> 4U;
    if (M2C_BITWISE(u32, temp_r8_292) < temp_r10_294) {
loop_1:
        if ((s32) M2C_FIELD(var_r31_295, s32 *, 4) == -1) {
            var_r4_306 = M2C_BITWISE(s32, var_r31_295) + 0x10;
loop_4:
            if ((var_r4_306 < temp_r10_294) && ((s32) M2C_FIELD(var_r4_306, s32 *, 4) == -1)) {
                var_r4_306 += 0x10;
                goto loop_4;
            }
            var_r11_317 = M2C_BITWISE(s32, var_r31_295) - 0x10;
loop_8:
            if ((var_r11_317 > M2C_BITWISE(u32, temp_r8_292)) && ((s32) M2C_FIELD(var_r11_317, s32 *, 4) == -1)) {
                var_r11_317 -= 0x10;
                goto loop_8;
            }
            if (M2C_BITWISE(u32, var_r31_295) == M2C_BITWISE(u32, temp_r8_292)) {
                var_r3_330 = this->unk4;
            } else {
                var_r3_330 = M2C_FIELD(var_r11_317, s32 *, 0);
            }
            if (var_r4_306 == temp_r10_294) {
                var_r0_341 = (this->unkC + 0x1F) & 0xFFFFFFE0;
            } else {
                var_r0_341 = (M2C_FIELD(var_r4_306, s32 *, 0) + (M2C_FIELD(var_r4_306, s32 *, 4) + 0x1F)) & 0xFFFFFFE0;
            }
            if ((s32) (((var_r3_330 - 1) & 0xFFFFFFE0) - var_r0_341) >= arg0) {
                M2C_FIELD(var_r31_295, s8 **, 8) = arg1;
                M2C_FIELD(var_r31_295, s32 *, 0xC) = arg2;
                if (M2C_BITWISE(u32, var_r31_295) == M2C_BITWISE(u32, this->unk38)) {
                    var_r0_359 = this->unk4 - arg0;
                } else {
                    var_r0_359 = M2C_FIELD(var_r11_317, s32 *, 0) - arg0;
                }
                M2C_FIELD(var_r31_295, u32 *, 0) = var_r0_359;
                M2C_FIELD(var_r31_295, u32 *, 0) = (u32) ((M2C_FIELD(var_r31_295, u32 *, 0) - 1) & 0xFFFFFFE0);
                M2C_FIELD(var_r31_295, s32 *, 4) = arg0;
                var_r3_371 = M2C_FIELD(var_r31_295, u32 *, 0);
                temp_r0_372 = this->unk44;
                if ((u32) temp_r0_372 < var_r3_371) {
                    var_r3_371 = (u32) temp_r0_372;
                }
                this->unk44 = (s32) var_r3_371;
                temp_r3_378 = this->unk48;
                this->unk48 = temp_r3_378 + M2C_FIELD(var_r31_295, s32 *, 4);
                temp_r3_378->UpdatePeak();
                return (void *) M2C_FIELD(var_r31_295, u32 *, 0);
            }
            goto block_23;
        }
block_23:
        var_r31_295 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r31_295) + 0x10));
        var_ctr_299 -= 1;
        if (var_ctr_299 == 0) {
            goto block_24;
        }
        goto loop_1;
    }
block_24:
    if (arg3 == 0) {
        DumpFragmentation();
        DumpTBlocks();
        temp_r0_395 = this->unk3C;
        var_ctr_396 = temp_r0_395;
        if (temp_r0_395 > 0) {
            do {
                var_ctr_396 -= 1;
            } while (var_ctr_396 != 0);
        }
        if ((u8) gbGoldMaster == 0) {
            sp8 = black;
            spC = white;
            OSFatal((GXColor) &spC, (GXColor) &sp8, Str_Printf("Couldn't find room/position for temp alloc!
size=%d [heapsize=%d]", arg0, this->unk4 - this->unk0));
        }
    }
    return NULL;
}
#endif

#if 0 // DRAFT: pointer/array required
void MKHeap::Free(const void *arg0, const char *arg1, int arg2) {
    if (arg0 != NULL) {
        if ((arg0 >= (u32) (*MKHeap::heapList)->unk44) && (arg0 <= (u32) (*MKHeap::heapList)->unk4)) {
            ((MKHeap *) (*MKHeap::heapList))->TFree(arg0, arg1, arg2);
            return;
        }
        if ((arg0 < (MKHeap *) this->unk0) || (arg0 > (u32) this->unk44)) {
            OSFreeToHeap(__OSCurrHeap, arg0);
            return;
        }
        UpdatePeak();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long *' to
void *MKHeap::ReAlloc(void *arg0, int arg1, const char *arg2, int arg3) {
    s32 spC;
    s32 sp8;
    void *var_r30_478;
    void *var_r3_526;

    var_r30_478 = arg0;
    if ((s32) *MKHeap::tempMemOverride != 0) {
        return ((MKHeap *) (*MKHeap::heapList))->TReAlloc(arg0, arg1, arg2, arg3);
    }
    if (var_r30_478 != NULL) {
        this->unkC = this->unk8 + arg1;
        if (((u8) gbGoldMaster == 0) && ((s32) this->unkC >= (s32) this->unk44)) {
            sp8 = black;
            spC = white;
            OSFatal((GXColor) &spC, (GXColor) &sp8, Str_Printf("Out of memory realloc'ing %d bytes", arg1));
        }
        ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->UpdatePeak();
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_526 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg1, NULL, 0);
        } else {
            var_r3_526 = malloc(arg1);
        }
        var_r30_478 = var_r3_526;
    }
    return var_r30_478;
}
#endif

#if 0 // DRAFT: type mismatch
void *MKHeap::Alloc(int arg0, const char *arg1, int arg2) {
    s32 spC;
    s32 sp8;
    void *var_r30_560;

    if ((s32) *MKHeap::tempMemOverride != 0) {
        var_r30_560 = ((MKHeap *) (*MKHeap::heapList))->TAlloc(arg0, arg1, arg2, 0U);
    } else {
        var_r30_560 = (void *) ((this->unkC + 0x1F) & 0xFFFFFFE0);
        this->unk8 = (s32) var_r30_560;
        if (((u8) gbGoldMaster == 0) && ((void *) (((u8 *) var_r30_560) + arg0) >= (s32) this->unk44)) {
            sp8 = black;
            spC = white;
            OSFatal((GXColor) &spC, (GXColor) &sp8, Str_Printf("No memory allocating %d bytes\n(%d free in heap %s)\n[heapsize=%d]", this->unk44 - var_r30_560, &this->unk4C, this->unk4 - this->unk0));
        }
        this->unkC = (s32) (((u8 *) var_r30_560) + arg0);
    }
    ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->UpdatePeak();
    return var_r30_560;
}
#endif

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

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
MKHeap *MKHeap::Current() {
    if ((s32) *MKHeap::currentHeap == -1) {
        return NULL;
    }
    return *(MKHeap::heapObjects + (*MKHeap::currentHeap * 4));
}
#endif

s32 MKHeap::Pop() {
    s32 temp_r0_667;

    temp_r0_667 = *MKHeap::currentHeap * 4;
    *MKHeap::currentHeap -= 1;
    return MKHeap::heapObjects[temp_r0_667];
}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void MKHeap::Push() {
    s32 temp_r5_679;

    temp_r5_679 = *MKHeap::currentHeap + 1;
    *MKHeap::currentHeap = temp_r5_679;
    *(MKHeap::heapObjects + (temp_r5_679 * 4)) = this;
}
#endif

u32 MKHeap::GetPeak() {
    return *MKHeap::peak;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
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
        temp_r3_708 = MKHeap::heapList[var_r28_706];
        if ((temp_r3_708 != NULL) && (temp_r3_708->IsWithinAHeap() == 0)) {
            temp_r3_714 = MKHeap::heapList[var_r28_706];
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
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
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
        temp_r3_800 = MKHeap::heapList[var_r25_798];
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
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
u8 MKHeap::IsWithinAHeap() {
    s32 var_ctr_860;
    s32 var_r4_859;
    void *temp_r7_862;

    var_r4_859 = 0;
    var_ctr_860 = 0xA;
loop_1:
    temp_r7_862 = MKHeap::heapList[var_r4_859];
    if ((temp_r7_862 != NULL) && (temp_r7_862 != this) && ((u32) M2C_FIELD(temp_r7_862, u32 *, 0) <= (MKHeap *) this->unk0) && ((u32) M2C_FIELD(temp_r7_862, u32 *, 4) >= (u32) this->unk4)) {
        return 1U;
    }
    var_r4_859 += 4;
    var_ctr_860 -= 1;
    if (var_ctr_860 == 0) {
        return 0U;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal operand
void MKHeap::RemoveHeapFromGlobalList() {
    s32 var_ctr_891;
    s32 var_r4_890;

    var_r4_890 = 0;
    var_ctr_891 = 0xA;
loop_1:
    if ((u32) MKHeap::heapList[var_r4_890] == this) {
        MKHeap::heapList[var_r4_890] = 0;
        return;
    }
    var_r4_890 += 4;
    var_ctr_891 -= 1;
    if (var_ctr_891 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void MKHeap::AddHeapToGlobalList() {
    s32 var_ctr_912;
    s32 var_r4_911;

    var_r4_911 = 0;
    var_ctr_912 = 0xA;
loop_1:
    if ((u32) MKHeap::heapList[var_r4_911] == 0U) {
        MKHeap::heapList[var_r4_911] = this;
        return;
    }
    var_r4_911 += 4;
    var_ctr_912 -= 1;
    if (var_ctr_912 == 0) {
        return;
    }
    goto loop_1;
}
#endif

void MKHeap::DeInit() {
    if ((u8) M2C_FIELD(this, u8 *, 0x34) == 0) {
        OSFreeToHeap(__OSCurrHeap, this->unk0);
    }
    RemoveHeapFromGlobalList();
}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void MKHeap::Init(int arg0, int arg1, const char *arg2, void *arg3) {
    s32 spC;
    s32 sp8;
    f32 temp_f1_993;
    s32 var_r6_1024;

    if (arg3 != NULL) {
        this->unk0 = (MKHeap *) arg3;
        this->unk4 = (this->unk0 + arg0) - (arg1 * 0x10);
        M2C_FIELD(this, s8 *, 0x34) = 1;
    } else {
        this->unk0 = OSAllocFromHeap(__OSCurrHeap, arg0 + (arg1 * 0x10));
        this->unk4 = (s32) (this->unk0 + arg0);
        M2C_FIELD(this, s8 *, 0x34) = 0;
        memset(this->unk0, 0xCD, (u32) arg0);
    }
    this->unkC = (s32) this->unk0;
    M2C_FIELD(this, s32 *, 0x30) = 0;
    temp_f1_993 = M2C_BITWISE(f32, strcpy(&this->unk4C, arg2));
    if (((u8) gbGoldMaster == 0) && ((MKHeap *) this->unk0 == NULL)) {
        sp8 = black;
        spC = white;
        OSFatal((GXColor) &spC, (GXColor) &sp8, Str_Printf("MKHeap::Init couldn't grab %d bytes!", arg0, temp_f1_993));
    }
    this->unk3C = arg1;
    this->unk38 = M2C_BITWISE(f32, this->unk4);
    this->unk44 = this->unk4;
    this->unk48 = NULL;
    var_r6_1024 = this->unk4;
loop_8:
    if ((u32) var_r6_1024 < (u32) (M2C_BITWISE(s32, this->unk38) + (arg1 * 0x10))) {
        M2C_FIELD(var_r6_1024, s32 *, 0) = -1;
        M2C_FIELD(var_r6_1024, s32 *, 4) = -1;
        M2C_FIELD(var_r6_1024, s32 *, 8) = 0;
        M2C_FIELD(var_r6_1024, s32 *, 0xC) = 0;
        var_r6_1024 += 0x10;
        goto loop_8;
    }
    AddHeapToGlobalList();
}
#endif

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
