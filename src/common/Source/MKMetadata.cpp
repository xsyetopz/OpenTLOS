#include "common/Source/MKMetadata.h"
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
#include "common/Source/FileSys.h"
#include <m2c_macros.h>

M2C_UNK free(MKMetadata *);                         /* extern */
void *malloc(M2C_UNK);                              /* extern */

void *MKMetadata_Resolve(MKMetadata *arg0, int arg1, const char **arg2) {
    MKMetadata *temp_r3_11;
    MKMetadata *temp_r4_14;
    void *temp_r3_16;

    temp_r3_11 = arg0->unk0;
    temp_r4_14 = &temp_r3_11[arg1];
    temp_r3_16 = temp_r3_11 + M2C_FIELD(temp_r4_14, s32 *, 0x10);
    if (arg2 != NULL) {
        *arg2 = (const char *) (M2C_FIELD(temp_r4_14, s8 **, 0x14));
        return temp_r3_16;
    }
    return temp_r3_16;
}

void MKMetadata_Close(MKMetadata *arg0) {
    MKMetadata *temp_r31_31;
    MKMetadata *temp_r31_45;

    temp_r31_31 = arg0->unk0;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_31, NULL, 0);
    } else {
        free(temp_r31_31);
    }
    temp_r31_45 = arg0->unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_45, NULL, 0);
    } else {
        free(temp_r31_45);
    }
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(arg0, NULL, 0);
        return;
    }
    free(arg0);
}

void MKMetadata_Open(const char *arg0, const char *arg1, int *arg2) {
    MKMetadata_OpenFromBuffer(MKArchive_Load(arg0, NULL, NULL, -1), NULL, arg2);
}

#if 0 // DRAFT: illegal type
void MKMetadata_OpenFromBuffer(const void *arg0, const void *arg1, int *arg2) {
    s32 temp_r0_134;
    s32 temp_r5_132;
    s32 var_r4_126;
    s32 var_r4_145;
    s32 var_r5_151;
    u32 temp_r0_139;
    u32 temp_r0_157;
    u32 temp_r6_166;
    u32 var_r11_150;
    u32 var_r6_125;
    u32 var_r8_144;
    void *temp_r6_156;
    void *temp_r7_129;
    void *temp_r7_154;
    void *temp_r9_128;
    void *var_r3_118;

    if (MKHeap::Current() != NULL) {
        var_r3_118 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
    } else {
        var_r3_118 = malloc(8);
    }
    M2C_FIELD(var_r3_118, void **, 0) = (void *) (arg0);
    var_r6_125 = 0U;
    var_r4_126 = 0;
    M2C_FIELD(var_r3_118, void **, 4) = (void *) (arg1);
    temp_r9_128 = M2C_FIELD(var_r3_118, void **, 0);
    temp_r7_129 = ((u8 *) temp_r9_128) + 0x10;
loop_5:
    temp_r0_139 = M2C_FIELD(temp_r9_128, u32 *, 4);
    if (var_r6_125 < temp_r0_139) {
        temp_r5_132 = var_r4_126 + 4;
        var_r6_125 += 1;
        temp_r0_134 = *(temp_r7_129 + temp_r5_132);
        var_r4_126 += 8;
        *(temp_r7_129 + temp_r5_132) = temp_r0_134 + temp_r9_128;
        goto loop_5;
    }
    var_r8_144 = 0U;
    var_r4_145 = 0;
loop_13:
    if (var_r8_144 < (u32) M2C_FIELD(temp_r9_128, u32 *, 0xC)) {
        var_r11_150 = 0U;
        var_r5_151 = 0;
loop_11:
        temp_r6_166 = *((temp_r0_139 * 8) + M2C_FIELD(var_r3_118, void **, 0) + 0x10 + var_r4_145);
        if (var_r11_150 < (u8) temp_r6_166) {
            temp_r7_154 = M2C_FIELD(var_r3_118, void **, 0);
            temp_r6_156 = (temp_r6_166 >> 8U) + temp_r7_154;
            temp_r0_157 = *(var_r5_151 + temp_r6_156);
            if (temp_r0_157 != 0U) {
                *(var_r5_151 + temp_r6_156) = temp_r0_157 + temp_r7_154;
            }
            var_r11_150 += 1;
            var_r5_151 += 4;
            goto loop_11;
        }
        var_r8_144 += 1;
        var_r4_145 += 4;
        goto loop_13;
    }
    if (arg2 != NULL) {
        *arg2 = (s32) M2C_FIELD(temp_r9_128, u32 *, 4);
    }
}
#endif

void MKMetadata_DeinitModule() {

}

void MKMetadata_InitModule() {

}
