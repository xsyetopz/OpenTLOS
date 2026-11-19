#include "common/Source/MKAttachment.h"
#include "common/Source/MKModel.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

#if 0 // DRAFT: function call 'memcpy(Matrix *, const long, int)' does not match
void MKAttachment_CalculateMatrix(const MKAttachment *arg0, Matrix *arg1, const Matrix *arg2) {
    s32 temp_r0_17;

    temp_r0_17 = ((u8) arg0->unk4 >> 4U) & 0xF;
    switch (temp_r0_17) {                           /* irregular */
    case 0:
        M2C_STRUCT_COPY(arg1, arg0->unk0, 0x40);
        /* fallthrough */
    case 1:
        M2C_STRUCT_COPY(arg1, MKModel_GetWorldMatrix((MKModel *) arg0->unk0), 0x40);
        break;
    case 2:
        MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) arg0->unk0, (SubObjectType) 0, (s32) M2C_FIELD(arg0, u8 *, 4) & 0x0FFFFFFF, arg1);
        break;
    case 3:
        MKModel_GetRefPointMatrix((MKModel *) arg0->unk0, (s32) M2C_FIELD(arg0, u8 *, 4) & 0x0FFFFFFF, arg1, 1U);
        break;
    case 4:
        MKModel_CalculateNodeWorldMatrix((MKModel *) arg0->unk0, (s32) M2C_FIELD(arg0, u8 *, 4) & 0x0FFFFFFF, arg1);
        break;
    }
    if ((arg2 != NULL) && (arg2 != &Matrix::identity)) {
        arg1->Multiply(arg2, arg1);
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKAttachmentType'
void MKAttachment_Init(MKAttachment *arg0, const void *arg1, MKAttachmentType arg2, int arg3) {
    arg0->unk0 = (s32) arg1;
    arg0->unk4 = (arg0->unk4 & ~0xF0) | (((s32) arg2 << 4) & 0xF0);
    M2C_FIELD(arg0, u8 *, 4) = (s32) (((s32) M2C_FIELD(arg0, u8 *, 4) & ~0x0FFFFFFF) | (arg3 & 0x0FFFFFFF));
}
#endif
