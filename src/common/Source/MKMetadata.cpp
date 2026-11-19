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

void MKMetadata_OpenFromBuffer(const void *arg0, const void *arg1, int *arg2) {
    void *var_r3_118;
    u8 *base;
    u32 count1;
    u32 count2;
    u32 i;
    u32 j;
    u32 k;
    u32 word;
    u32 off;

    if (MKHeap::Current() != NULL) {
        var_r3_118 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
    } else {
        var_r3_118 = malloc(8);
    }
    M2C_FIELD(var_r3_118, void **, 0) = (void *) (arg0);
    M2C_FIELD(var_r3_118, void **, 4) = (void *) (arg1);
    base = (u8 *) M2C_FIELD(var_r3_118, void **, 0);
    count1 = M2C_FIELD(base, u32 *, 4);
    for (i = 0; i < count1; i++) {
        M2C_FIELD(base, u32 *, 0x14 + i * 8) += (u32) base;
    }
    count2 = M2C_FIELD(base, u32 *, 0xC);
    for (j = 0; j < count2; j++) {
        word = M2C_FIELD(base, u32 *, 0x10 + count1 * 8 + j * 4);
        for (k = 0; k < (word & 0xFF); k++) {
            off = (word >> 8) + k * 4;
            if (M2C_FIELD(base, u32 *, off) != 0) {
                M2C_FIELD(base, u32 *, off) += (u32) base;
            }
        }
    }
    if (arg2 != NULL) {
        *arg2 = (s32) count1;
    }
}

void MKMetadata_DeinitModule() {

}

void MKMetadata_InitModule() {

}
