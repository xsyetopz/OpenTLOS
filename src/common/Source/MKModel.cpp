#include "common/Source/MKModel.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

s8 *malloc(s32);                                    /* extern */
s32 strcmpi(s8 *, s8 *);                            /* extern */
s32 stricmp(s32, s8 *);                             /* extern */
extern MKClothManager gClothManager;
extern MKDynamicBoneSystem gDynamicBones;
extern MKAttachment *pDeathRow;
extern s8 *pTemplatesList;

void MKModel_EnableClothUpdate(MKModel *arg0, bool arg1) {
    ModelCloth *temp_r3_14;

    temp_r3_14 = arg0->unk84;
    if (temp_r3_14 != NULL) {
        temp_r3_14->unk31 = (s8) arg1;
    }
}

void MKModel_UpdateCloth(MKModel *arg0) {
    ModelCloth *temp_r3_27;

    temp_r3_27 = arg0->unk84;
    if (temp_r3_27 != NULL) {
        temp_r3_27->Update();
    }
}

void MKModel_SetClothManualUpdate(MKModel *arg0, bool arg1) {
    ModelCloth *temp_r3_41;

    temp_r3_41 = arg0->unk84;
    if (temp_r3_41 != NULL) {
        temp_r3_41->unk30 = (s8) arg1;
    }
}

#if 0 // DRAFT: illegal type
MKCloth *MKModel_GetClothSubObject(const MKModel *arg0, int arg1) {
    ModelCloth *temp_r3_51;

    temp_r3_51 = arg0->unk84;
    if (temp_r3_51 != NULL) {
        return temp_r3_51->unk8 + (arg1 * 0xF8);
    }
    return NULL;
}
#endif

ModelCloth *MKModel_GetCloth(const MKModel *arg0) {
    return arg0->unk84;
}

#if 0 // DRAFT: undefined identifier 'attachmentMatrix'
void MKModel_CalculateSubObjectLocalToWorldMatrix(const MKModel *arg0, SubObjectType arg1, int arg2, Matrix *arg3) {
    s16 sp8;
    MKAttachment *temp_r7_82;
    Matrix *temp_r4_188;
    Matrix *var_r31_81;
    s16 temp_r3_173;
    s32 temp_r0_86;

    var_r31_81 = (Matrix *) (&arg0->unk10);
    temp_r7_82 = arg0->unk8;
    if (temp_r7_82 != NULL) {
        temp_r0_86 = ((u8) temp_r7_82->unk4 >> 4U) & 0xF;
        switch (temp_r0_86) {                       /* irregular */
        case 0:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, temp_r7_82->unk0, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, MKModel_GetWorldMatrix((MKModel *) temp_r7_82->unk0), 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_82->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_82, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_82->unk0, (s32) M2C_FIELD(temp_r7_82, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_82->unk0, (s32) M2C_FIELD(temp_r7_82, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        }
        if ((var_r31_81 != NULL) && (var_r31_81 != &Matrix::identity)) {
            ((Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix)->Multiply(var_r31_81, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
        }
        var_r31_81 = (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix;
    }
    temp_r3_173 = MKModel_GetSubObjectBoneIndex(arg0, arg1, arg2);
    if (temp_r3_173 > -1) {
        sp8 = temp_r3_173;
        arg0->unk70->CalculateMatrices(arg3, 1, &sp8, var_r31_81);
        return;
    }
    temp_r4_188 = M2C_FIELD((arg0 + (arg2 * 4)), Matrix **, 0x90);
    if (temp_r4_188 != NULL) {
        arg3->Multiply(temp_r4_188, var_r31_81);
        return;
    }
    M2C_STRUCT_COPY(arg3, var_r31_81, 0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'attachmentMatrix'
void MKModel_CalculateRefPointWorldPosition(const MKModel *arg0, int arg1, MKVector3 *arg2) {
    Matrix sp70;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s16 sp10;
    Animation *temp_r3_329;
    MKAttachment *temp_r7_228;
    Matrix *var_r31_227;
    s32 temp_r0_232;
    u8 temp_r0_321;
    void *temp_r3_320;

    var_r31_227 = (Matrix *) (&arg0->unk10);
    temp_r7_228 = arg0->unk8;
    if (temp_r7_228 != NULL) {
        temp_r0_232 = ((u8) temp_r7_228->unk4 >> 4U) & 0xF;
        switch (temp_r0_232) {                      /* irregular */
        case 0:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, temp_r7_228->unk0, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, MKModel_GetWorldMatrix((MKModel *) temp_r7_228->unk0), 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_228->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_228, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_228->unk0, (s32) M2C_FIELD(temp_r7_228, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_228->unk0, (s32) M2C_FIELD(temp_r7_228, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        }
        if ((var_r31_227 != NULL) && (var_r31_227 != &Matrix::identity)) {
            ((Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix)->Multiply(var_r31_227, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
        }
        var_r31_227 = (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix;
    }
    temp_r3_320 = *(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x58) + (arg1 * 4));
    temp_r0_321 = M2C_FIELD(temp_r3_320, u8 *, 0x14);
    sp58 = M2C_FIELD(temp_r3_320, f64 *, 0);
    sp60 = M2C_FIELD(temp_r3_320, f64 *, 8);
    if (((s8) temp_r0_321 == -1) || (temp_r3_329 = arg0->unk70, ((temp_r3_329 == NULL) != 0))) {
        sp28 = var_r31_227->unk30 + (((f32) sp60 * var_r31_227->unk20) + (((f32) sp58 * var_r31_227->unk0) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * var_r31_227->unk10)));
        sp2C = var_r31_227->unk34 + (((f32) sp60 * var_r31_227->unk24) + (((f32) sp58 * var_r31_227->unk4) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * var_r31_227->unk14)));
        sp30 = var_r31_227->unk38 + (((f32) sp60 * var_r31_227->unk28) + (((f32) sp58 * var_r31_227->unk8) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * var_r31_227->unk18)));
        M2C_FIELD(arg2, f64 *, 0) = (f64) sp28;
        sp48 = (f64) sp28;
        sp50 = (f64) sp30;
        M2C_FIELD(arg2, f64 *, 8) = (f64) sp30;
        return;
    }
    sp10 = (s16) (s8) temp_r0_321;
    temp_r3_329->CalculateMatrices(&sp70, 1, &sp10, var_r31_227);
    sp18 = sp70.unk30 + (((f32) sp60 * sp70.unk20) + (((f32) sp58 * M2C_BITWISE(f32, sp70)) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * sp70.unk10)));
    sp1C = sp70.unk34 + (((f32) sp60 * sp70.unk24) + (((f32) sp58 * sp70.unk4) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * sp70.unk14)));
    sp20 = sp70.unk38 + (((f32) sp60 * sp70.unk28) + (((f32) sp58 * sp70.unk8) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * sp70.unk18)));
    M2C_FIELD(arg2, f64 *, 0) = (f64) sp18;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    M2C_FIELD(arg2, f64 *, 8) = (f64) sp20;
}
#endif

#if 0 // DRAFT: undefined identifier 'attachmentMatrix'
void MKModel_CalculateNodeWorldMatrix(const MKModel *arg0, int arg1, Matrix *arg2) {
    f64 sp38;
    f64 sp30;
    MKVector3 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 sp8;
    MKAttachment *temp_r7_433;
    Matrix *var_r31_432;
    f32 temp_f6_536;
    s32 temp_r0_437;

    var_r31_432 = (Matrix *) (&arg0->unk10);
    temp_r7_433 = arg0->unk8;
    if (temp_r7_433 != NULL) {
        temp_r0_437 = ((u8) temp_r7_433->unk4 >> 4U) & 0xF;
        switch (temp_r0_437) {                      /* irregular */
        case 0:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, temp_r7_433->unk0, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, MKModel_GetWorldMatrix((MKModel *) temp_r7_433->unk0), 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_433->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_433, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_433->unk0, (s32) M2C_FIELD(temp_r7_433, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_433->unk0, (s32) M2C_FIELD(temp_r7_433, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        }
        if ((var_r31_432 != NULL) && (var_r31_432 != &Matrix::identity)) {
            ((Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix)->Multiply(var_r31_432, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
        }
        var_r31_432 = (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix;
    }
    sp8 = (s16) arg1;
    arg0->unk70->CalculateMatrices(arg2, 1, &sp8, var_r31_432);
    sp20 = arg0->unk70->GetNodeOrigin(arg1);
    temp_f6_536 = M2C_BITWISE(f32, sp20);
    sp10 = (sp20.unk8 * arg2->unk20) + ((temp_f6_536 * arg2->unk0) + (sp20.unk4 * arg2->unk10));
    sp14 = (sp20.unk8 * arg2->unk24) + ((temp_f6_536 * arg2->unk4) + (sp20.unk4 * arg2->unk14));
    sp30 = (f64) sp10;
    sp18 = (sp20.unk8 * arg2->unk28) + ((temp_f6_536 * arg2->unk8) + (sp20.unk4 * arg2->unk18));
    arg2->unk30 += (f32) sp30;
    sp38 = (f64) sp18;
    arg2->unk34 += (*(f32 *) ((u8 *) &sp30 + 0x4));
    arg2->unk38 += (f32) sp38;
}
#endif

#if 0 // DRAFT: undefined identifier 'attachmentMatrix'
void MKModel_CalculateNodeWorldPosition(const MKModel *arg0, int arg1, MKVector3 *arg2) {
    Matrix sp50;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s16 sp10;
    MKAttachment *temp_r7_593;
    Matrix *var_r31_592;
    f32 temp_f6_698;
    s32 temp_r0_597;

    var_r31_592 = (Matrix *) (&arg0->unk10);
    temp_r7_593 = arg0->unk8;
    if (temp_r7_593 != NULL) {
        temp_r0_597 = ((u8) temp_r7_593->unk4 >> 4U) & 0xF;
        switch (temp_r0_597) {                      /* irregular */
        case 0:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, temp_r7_593->unk0, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, MKModel_GetWorldMatrix((MKModel *) temp_r7_593->unk0), 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_593->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_593, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_593->unk0, (s32) M2C_FIELD(temp_r7_593, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_593->unk0, (s32) M2C_FIELD(temp_r7_593, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        }
        if ((var_r31_592 != NULL) && (var_r31_592 != &Matrix::identity)) {
            ((Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix)->Multiply(var_r31_592, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
        }
        var_r31_592 = (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix;
    }
    sp10 = (s16) arg1;
    arg0->unk70->CalculateMatrices(&sp50, 1, &sp10, var_r31_592);
    sp28 = arg0->unk70->GetNodeOrigin(arg1);
    temp_f6_698 = M2C_BITWISE(f32, sp28);
    sp18 = sp50.unk30 + ((sp28.unk8 * sp50.unk20) + ((temp_f6_698 * M2C_BITWISE(f32, sp50)) + (sp28.unk4 * sp50.unk10)));
    sp1C = sp50.unk34 + ((sp28.unk8 * sp50.unk24) + ((temp_f6_698 * sp50.unk4) + (sp28.unk4 * sp50.unk14)));
    sp20 = sp50.unk38 + ((sp28.unk8 * sp50.unk28) + ((temp_f6_698 * sp50.unk8) + (sp28.unk4 * sp50.unk18)));
    M2C_FIELD(arg2, f64 *, 0) = (f64) sp18;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    M2C_FIELD(arg2, f64 *, 8) = (f64) sp20;
}
#endif

void MKModel_CalculateCentre(const MKModel *arg0, MKVector3 *arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r5_742;

    temp_r5_742 = M2C_FIELD(arg0->unk0, void **, 0x30);
    sp8 = (0.5f * M2C_FIELD(temp_r5_742, f32 *, 0x40)) + M2C_FIELD(temp_r5_742, f32 *, 0x30);
    spC = (0.5f * M2C_FIELD(temp_r5_742, f32 *, 0x44)) + M2C_FIELD(temp_r5_742, f32 *, 0x34);
    sp10 = (0.5f * M2C_FIELD(temp_r5_742, f32 *, 0x48)) + M2C_FIELD(temp_r5_742, f32 *, 0x38);
    M2C_FIELD(arg1, f64 *, 0) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    if ((u32) (((u8) arg0->unk4 >> 5U) & 7) >= 1U) {
        M2C_FIELD(arg1, f64 *, 0) = (f64) (M2C_FIELD(arg1, f64 *, 0) + M2C_FIELD(arg0, f64 *, 0x40));
        arg1->unk8 += arg0->unk10.unk38;
    }
}

#if 0 // DRAFT: illegal function overloading
s32 MKModel_GetMaterial(const MKModel *arg0, int arg1, bool arg2) {
    u8 var_r5_783;

    var_r5_783 = 0;
    if ((arg2 == 0) && ((u32) (((u8) arg0->unk4 >> 5U) & 7) == 2)) {
        var_r5_783 = 1;
    }
    if (var_r5_783 != 0) {
        return *(arg0->unk80 + (arg1 * 4));
    }
    return *(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x54) + (arg1 * 4));
}
#endif

s16 MKModel_GetNmbrOfMaterials(const MKModel *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 6);
}

#if 0 // DRAFT: undefined identifier '__upper_map'
s32 MKModel_IsSubObjectPrefixed(const MKModel *arg0, SubObjectType arg1, int arg2, char arg3) {
    s32 var_r5_825;
    s8 *temp_r3_823;
    u8 temp_r0_836;
    u8 var_r0_840;
    u8 var_r6_828;

    temp_r3_823 = MKModel_GetSubObjectName(arg0, arg1, arg2);
    var_r5_825 = 0;
    if (arg3 == -1) {
        var_r6_828 = -1U;
    } else {
        var_r6_828 = *(&__upper_map + (u8) arg3);
    }
    temp_r0_836 = (u8) M2C_FIELD(temp_r3_823, s8 *, 0);
    if ((s8) temp_r0_836 == -1) {
        var_r0_840 = -1U;
    } else {
        var_r0_840 = *(&__upper_map + (u8) (s8) temp_r0_836);
    }
    if (((s32) var_r0_840 == (s32) var_r6_828) && ((s32) M2C_FIELD(temp_r3_823, u8 *, 1) == 0x5F)) {
        var_r5_825 = 1;
    }
    return var_r5_825;
}
#endif

void MKModel_SetSubObjectLocalMatrix(MKModel *arg0, SubObjectType arg1, int arg2, Matrix *arg3) {
    M2C_FIELD((arg0 + (arg2 * 4)), Matrix **, 0x90) = arg3;
}

s32 MKModel_GetSubObjectLocalMatrix(const MKModel *arg0, SubObjectType arg1, int arg2) {
    return M2C_FIELD((arg0 + (arg2 * 4)), s32 *, 0x90);
}

s16 MKModel_GetSubObjectBoneIndex(const MKModel *arg0, SubObjectType arg1, int arg2) {
    if (MKModel_GetAnimation(arg0) == NULL) {
        return -1;
    }
    return M2C_FIELD((M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x50) + (arg2 << 6)), s16 *, 0x3A);
}

#if 0 // DRAFT: pointer/array required
s8 *MKModel_GetSubObjectName(const MKModel *arg0, SubObjectType arg1, int arg2) {
    switch ((s32) arg1) {                           /* irregular */
    case 1:
        return *(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x44), s32 *, 4) + (arg2 * 8));
    case 2:
        return (signed char *) (((MKCloth *) (MKModel_GetClothSubObject(arg0, arg2)))->GetName());
    case 0:
        return M2C_FIELD((M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x50) + (arg2 << 6)), s8 **, 0x30);
    default:
        return NULL;
    }
}
#endif

s16 MKModel_GetNmbrOfSubObjects(const MKModel *arg0, SubObjectType arg1) {
    ModelCloth *temp_r3_984;
    void *temp_r3_975;

    switch ((s32) arg1) {                           /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4);
    case 1:
        temp_r3_975 = M2C_FIELD(arg0->unk0, void **, 0x44);
        if (temp_r3_975 != NULL) {
            return (s16) M2C_FIELD(temp_r3_975, s32 *, 8);
        }
        return 0;
    case 2:
        temp_r3_984 = arg0->unk84;
        if (temp_r3_984 != NULL) {
            return (s16) temp_r3_984->unk4;
        }
        return 0;
    default:
        return 0;
    }
}

#if 0 // DRAFT: illegal type
void MKModel_EnableOnlySubObject(MKModel *arg0, SubObjectType arg1, int arg2, bool arg3, unsigned char arg4) {
    MKCloth *temp_r3_1097;
    s16 temp_r28_1089;
    s32 temp_r3_1063;
    s32 temp_r3_1072;
    s32 var_r25_1092;
    s32 var_r7_1022;
    s32 var_r7_1052;
    void *temp_r3_1035;
    void *temp_r4_1059;
    void *temp_r4_1069;
    void *temp_r4_1079;
    void *temp_r6_1026;

    switch ((s32) arg1) {                           /* irregular */
    case 0:
        var_r7_1022 = 0;
loop_10:
        if (var_r7_1022 < (s16) M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4)) {
            temp_r6_1026 = arg0->unk88;
            *(temp_r6_1026 + var_r7_1022) = *(temp_r6_1026 + var_r7_1022) & (u8) ~(arg4 | arg4);
            if (arg3 != (u8) (var_r7_1022 == arg2)) {
                temp_r3_1035 = arg0->unk88;
                *(temp_r3_1035 + var_r7_1022) = *(temp_r3_1035 + var_r7_1022) | arg4;
            }
            var_r7_1022 += 1;
            goto loop_10;
        }
        return;
    case 1:
        var_r7_1052 = 0;
loop_16:
        temp_r4_1079 = arg0->unk0;
        if (var_r7_1052 < (s32) M2C_FIELD(M2C_FIELD(temp_r4_1079, void **, 0x44), s32 *, 8)) {
            temp_r4_1059 = arg0->unk88;
            temp_r3_1063 = M2C_FIELD(M2C_FIELD(temp_r4_1079, void **, 0x30), s16 *, 4) + var_r7_1052;
            *(temp_r4_1059 + temp_r3_1063) = *(temp_r4_1059 + temp_r3_1063) & (u8) ~(arg4 | arg4);
            if (arg3 != (u8) (var_r7_1052 == arg2)) {
                temp_r4_1069 = arg0->unk88;
                temp_r3_1072 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4) + var_r7_1052;
                *(temp_r4_1069 + temp_r3_1072) = *(temp_r4_1069 + temp_r3_1072) | arg4;
            }
            var_r7_1052 += 1;
            goto loop_16;
        }
        return;
    case 2:
        temp_r28_1089 = MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 2);
        var_r25_1092 = 0;
loop_22:
        if (var_r25_1092 < temp_r28_1089) {
            temp_r3_1097 = MKModel_GetClothSubObject(arg0, var_r25_1092);
            temp_r3_1097->unkF0 &= ~(arg4 | arg4);
            if (arg3 != (u8) (var_r25_1092 == arg2)) {
                temp_r3_1097->unkF0 |= arg4;
            }
            var_r25_1092 += 1;
            goto loop_22;
        }
        return;
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKModel_EnableSubObject(MKModel *arg0, SubObjectType arg1, int arg2, bool arg3, unsigned char arg4) {
    s32 temp_r0_1158;
    s32 temp_r3_1176;
    s32 temp_r5_1146;
    s32 temp_r5_1165;
    u8 temp_r29_1175;
    void *temp_r3_1144;
    void *temp_r4_1159;

    switch ((s32) arg1) {                           /* irregular */
    case 0:
        temp_r3_1144 = arg0->unk88;
        temp_r5_1146 = 0 - arg3;
        *(temp_r3_1144 + arg2) = (*(temp_r3_1144 + arg2) & ~arg4) | (arg4 & ~((temp_r5_1146 - temp_r5_1146) - !M2C_CARRY));
        return;
    case 1:
        temp_r0_1158 = 0 - arg3;
        temp_r4_1159 = arg0->unk88;
        temp_r5_1165 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4) + arg2;
        *(temp_r4_1159 + temp_r5_1165) = (*(temp_r4_1159 + temp_r5_1165) & ~arg4) | (arg4 & ~((temp_r0_1158 - temp_r0_1158) - !M2C_CARRY));
        return;
    case 2:
        temp_r29_1175 = MKModel_GetClothSubObject(arg0, arg2)->unkF0;
        temp_r3_1176 = 0 - arg3;
        MKModel_GetClothSubObject(arg0, arg2)->unkF0 = (arg4 & ~((temp_r3_1176 - temp_r3_1176) - !M2C_CARRY)) | (temp_r29_1175 & ~arg4);
        return;
    }
}
#endif

#if 0 // DRAFT: illegal type
u8 MKModel_GetSubObjectFlag(const MKModel *arg0, SubObjectType arg1, int arg2) {
    u8 var_r4_1198;

    var_r4_1198 = 0;
    if (((u32) (((u8) arg0->unk4 >> 5U) & 7) >= 2U) && ((void *) arg0->unk88 != NULL)) {
        var_r4_1198 = 1;
    }
    if (var_r4_1198 != 0) {
        return *(arg0->unk88 + arg2);
    }
    return 0U;
}
#endif

s32 MKModel_GetSubObjectOrigin(const MKModel *arg0, SubObjectType arg1, int arg2) {
    return M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x50) + ((arg2 << 6) + 0x20);
}

#if 0 // DRAFT: illegal type
s32 MKModel_IsSubObjectEnabled(const MKModel *arg0, SubObjectType arg1, int arg2) {
    switch ((s32) arg1) {                           /* irregular */
    case 1:
        return (*(arg0->unk88 + (M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4) + arg2)) & 0xF) == 0;
    case 2:
        return (MKModel_GetClothSubObject(arg0, arg2)->unkF0 & 0xF) == 0;
    case 0:
        return (*(arg0->unk88 + arg2) & 0xF) == 0;
    default:
        return 0;
    }
}
#endif

s32 MKModel_GetSubObjectIndex(const MKModel *arg0, SubObjectType arg1, const char *arg2) {
    s32 sp8;

    MKModel_SubObjectExists(arg0, arg1, arg2, (int *) &sp8);
    return sp8;
}

#if 0 // DRAFT: pointer/array required Too many errors printed, aborting program
s32 MKModel_SubObjectExists(const MKModel *arg0, SubObjectType arg1, const char *arg2, int *arg3) {
    s16 temp_r0_1376;
    s16 var_ctr_1377;
    s32 var_r27_1316;
    s32 var_r27_1347;
    s32 var_r27_1395;
    s32 var_r29_1317;
    s32 var_r29_1348;
    s32 var_r29_1396;
    s32 var_r3_1374;
    u16 *var_r28_1382;
    void *temp_r28_1315;
    void *temp_r28_1343;
    void *temp_r3_1337;
    void *temp_r3_1367;
    void *temp_r4_1375;

    switch ((s32) arg1) {                           /* irregular */
    case 0:
        temp_r28_1315 = arg0->unk0;
        var_r27_1316 = 0;
        var_r29_1317 = 0;
loop_12:
        temp_r3_1337 = M2C_FIELD(temp_r28_1315, void **, 0x30);
        if (var_r27_1316 >= (s16) M2C_FIELD(temp_r3_1337, s16 *, 4)) {
block_36:
        default:
            return 0;
        }
        if (strcmpi(*(M2C_FIELD(temp_r3_1337, s32 *, 0x50) + (var_r29_1317 + 0x30)), arg2) == 0) {
            if (arg3 != NULL) {
                *arg3 = var_r27_1316;
            }
            return 1;
        }
        var_r27_1316 += 1;
        var_r29_1317 += 0x40;
        goto loop_12;
    case 1:
        temp_r28_1343 = arg0->unk0;
        if ((void *) M2C_FIELD(temp_r28_1343, void **, 0x44) != NULL) {
            var_r27_1347 = 0;
            var_r29_1348 = 0;
loop_21:
            temp_r3_1367 = M2C_FIELD(temp_r28_1343, void **, 0x44);
            if (var_r27_1347 >= (s32) M2C_FIELD(temp_r3_1367, s32 *, 8)) {
                goto block_36;
            }
            if (strcmpi(*(M2C_FIELD(temp_r3_1367, s32 *, 4) + var_r29_1348), arg2) == 0) {
                if (arg3 != NULL) {
                    *arg3 = var_r27_1347;
                }
                return 1;
            }
            var_r27_1347 += 1;
            var_r29_1348 += 8;
            goto loop_21;
        }
        goto block_36;
    case 2:
        var_r3_1374 = 0;
        temp_r4_1375 = M2C_FIELD(arg0->unk0, void **, 0x30);
        temp_r0_1376 = M2C_FIELD(temp_r4_1375, s16 *, 0xC);
        var_ctr_1377 = temp_r0_1376;
        if (temp_r0_1376 > 0) {
loop_24:
            var_r28_1382 = M2C_FIELD(temp_r4_1375, s32 *, 0x60) + var_r3_1374;
            if ((u16) *var_r28_1382 == 2) {

            } else {
                var_r3_1374 += 0x10;
                var_ctr_1377 -= 1;
                if (var_ctr_1377 == 0) {
                    goto block_27;
                }
                goto loop_24;
            }
        } else {
block_27:
            var_r28_1382 = NULL;
        }
        if (var_r28_1382 != NULL) {
            var_r27_1395 = 0;
            var_r29_1396 = 0;
loop_35:
            if (var_r27_1395 >= (s32) M2C_FIELD(var_r28_1382, s32 *, 8)) {
                goto block_36;
            }
            if (stricmp(M2C_FIELD(var_r28_1382, s32 *, 4) + (var_r29_1396 + 0x30), arg2) == 0) {
                if (arg3 != NULL) {
                    *arg3 = var_r27_1395;
                }
                return 1;
            }
            var_r27_1395 += 1;
            var_r29_1396 += 0x58;
            goto loop_35;
        }
        goto block_36;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
s32 MKModel_GetRefPointMatrix(const MKModel *arg0, int arg1, Matrix *arg2, bool arg3) {
    Matrix sp20;
    s16 sp10;
    Animation *temp_r3_1571;
    MKAttachment *temp_r3_1445;
    Matrix *var_r31_1443;
    Matrix *var_r7_1588;
    s32 temp_r0_1452;
    u8 temp_r0_1578;
    u8 var_r29_1442;
    void *temp_r30_1449;

    var_r29_1442 = arg3;
    var_r31_1443 = (Matrix *) (&arg0->unk10);
    temp_r3_1445 = arg0->unk8;
    temp_r30_1449 = *(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x58) + (arg1 * 4));
    if (temp_r3_1445 != NULL) {
        temp_r0_1452 = ((u8) temp_r3_1445->unk4 >> 4U) & 0xF;
        switch (temp_r0_1452) {                     /* irregular */
        case 0:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, temp_r3_1445->unk0, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, MKModel_GetWorldMatrix((MKModel *) temp_r3_1445->unk0), 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r3_1445->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r3_1445, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r3_1445->unk0, (s32) M2C_FIELD(temp_r3_1445, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r3_1445->unk0, (s32) M2C_FIELD(temp_r3_1445, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        }
        if ((var_r31_1443 != NULL) && (var_r31_1443 != &Matrix::identity)) {
            ((Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix)->Multiply(var_r31_1443, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
        }
        var_r31_1443 = (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix;
    }
    arg2->SetIdentity();
    if ((u8) M2C_FIELD(temp_r30_1449, u8 *, 0x16) != 0) {
        arg2->CopyRotation(((u8 *) temp_r30_1449) + 0x20);
        arg2->unk30 = M2C_FIELD(temp_r30_1449, f32 *, 0);
        arg2->unk34 = M2C_FIELD(temp_r30_1449, f32 *, 4);
        arg2->unk38 = M2C_FIELD(temp_r30_1449, f32 *, 8);
        arg2->unk3C = M2C_FIELD(temp_r30_1449, f32 *, 0xC);
        arg2->unk2C = 0.0f;
        arg2->unk1C = 0.0f;
        arg2->unkC = 0.0f;
        arg2->unk3C = 1.0f;
    } else {
        arg2->unk30 = M2C_FIELD(temp_r30_1449, f32 *, 0);
        arg2->unk34 = M2C_FIELD(temp_r30_1449, f32 *, 4);
        arg2->unk38 = M2C_FIELD(temp_r30_1449, f32 *, 8);
        arg2->unk3C = M2C_FIELD(temp_r30_1449, f32 *, 0xC);
        arg2->unk3C = 1.0f;
    }
    temp_r3_1571 = arg0->unk70;
    if ((temp_r3_1571 != NULL) && ((s8) M2C_FIELD(temp_r30_1449, u8 *, 0x15) <= -1)) {
        temp_r0_1578 = M2C_FIELD(temp_r30_1449, u8 *, 0x14);
        if ((s8) temp_r0_1578 > -1) {
            sp10 = (s16) (s8) temp_r0_1578;
            if (var_r29_1442 != 0) {
                var_r7_1588 = var_r31_1443;
            } else {
                var_r7_1588 = NULL;
            }
            temp_r3_1571->CalculateMatrices(&sp20, 1, &sp10, var_r7_1588);
            arg2->Multiply4x4(arg2, &sp20);
            var_r29_1442 = 0;
        }
    }
    if (var_r29_1442 != 0) {
        arg2->Multiply(arg2, var_r31_1443);
    }
    return M2C_FIELD(temp_r30_1449, u8 *, 0x16) != 0;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 MKModel_GetRefPointData(const MKModel *arg0, int arg1) {
    return *(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x58) + (arg1 * 4));
}
#endif

#if 0 // DRAFT: pointer/array required
u8 MKModel_GetRefPointType(const MKModel *arg0, int arg1) {
    return M2C_FIELD(*(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x58) + (arg1 * 4)), u8 *, 0x16);
}
#endif

#if 0 // DRAFT: pointer/array required
f32 MKModel_GetRefPointRadius(const MKModel *arg0, int arg1) {
    return M2C_FIELD(*(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x58) + (arg1 * 4)), f32 *, 0xC);
}
#endif

#if 0 // DRAFT: pointer/array required
s8 *MKModel_GetRefPointName(const MKModel *arg0, int arg1) {
    return M2C_FIELD(*(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x58) + (arg1 * 4)), s8 **, 0x10);
}
#endif

s32 MKModel_GetRefPointIndex(const MKModel *arg0, const char *arg1) {
    s32 sp8;

    sp8 = 0;
    MKModel_RefPointExists(arg0, arg1, (int *) &sp8);
    return sp8;
}

#if 0 // DRAFT: pointer/array required
s32 MKModel_RefPointExists(const MKModel *arg0, const char *arg1, int *arg2) {
    s32 var_r29_1696;
    s32 var_r31_1697;
    void *temp_r30_1695;
    void *temp_r3_1717;

    if (arg1 == NULL) {
        return 0;
    }
    temp_r30_1695 = arg0->unk0;
    var_r29_1696 = 0;
    var_r31_1697 = 0;
loop_8:
    temp_r3_1717 = M2C_FIELD(temp_r30_1695, void **, 0x30);
    if (var_r29_1696 >= (s16) M2C_FIELD(temp_r3_1717, s16 *, 0xA)) {
        return 0;
    }
    if (strcmpi(M2C_FIELD(*(M2C_FIELD(temp_r3_1717, s32 *, 0x58) + var_r31_1697), s8 **, 0x10), arg1) == 0) {
        if (arg2 != NULL) {
            *arg2 = var_r29_1696;
        }
        return 1;
    }
    var_r29_1696 += 1;
    var_r31_1697 += 4;
    goto loop_8;
}
#endif

s16 MKModel_GetNmbrOfRefPoints(const MKModel *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 0xA);
}

#if 0 // DRAFT: illegal type
MKHeap **MKModel_GetBoundingVolume(const MKModel *arg0, SubObjectType arg1, int arg2) {
    if (arg2 < 0) {
        return M2C_FIELD(arg0->unk0, void **, 0x30) + 0x30;
    }
    return (MKHeap **) (M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x50) + (arg2 << 6));
}
#endif

void MKModel_EnableTrivialRejection(MKModel *arg0, bool arg1) {
    arg0->unk4 = (arg0->unk4 & ~1) | (arg1 & 1);
}

void MKModel_EnableScissoring(MKModel *arg0, bool arg1) {
    arg0->unk4 = (arg0->unk4 & ~2) | ((arg1 << 1) & 2);
}

Animation *MKModel_GetAnimation(const MKModel *arg0) {
    if ((u32) (((u8) arg0->unk4 >> 5U) & 7) < 1U) {
        return NULL;
    }
    return arg0->unk70;
}

void MKModel_SetPosition(MKModel *arg0, const MKVector3 &arg1) {
    arg0->unk10.unk30 = arg1.unk0;
    arg0->unk10.unk34 = arg1.unk4;
    arg0->unk10.unk38 = arg1.unk8;
    arg0->unk10.unk3C = 1.0f;
    arg0->unk5 &= ~0x40;
}

void MKModel_GetPosition(const MKModel *arg0) {

}

u8 MKModel_IsAtIdentity(const MKModel *arg0) {
    return (u8) ((((u8) arg0->unk5 >> 6U) & 1) != 0);
}

#if 0 // DRAFT: pointer/array required
void MKModel_SetRotation(MKModel *arg0, const MKVector3 &arg1) {
    Matrix sp10;
    s32 temp_r3_1837;
    s32 var_ctr_1847;
    s32 var_r4_1839;
    s32 var_r5_1844;
    s32 var_r7_1838;

    temp_r3_1837 = MKModel_GetWorldMatrix(arg0);
    var_r7_1838 = 0;
    var_r4_1839 = 0;
    do {
        var_r5_1844 = 0;
        var_ctr_1847 = 4;
loop_2:
        *(&sp10 + var_r4_1839 + var_r5_1844) = *(temp_r3_1837 + var_r4_1839 + var_r5_1844);
        var_r5_1844 += 4;
        var_ctr_1847 -= 1;
        if (var_ctr_1847 != 0) {
            goto loop_2;
        }
        var_r7_1838 += 1;
        var_r4_1839 += 0x10;
    } while (var_r7_1838 < 4);
    sp10.SetRotationPYR(arg1);
    MKModel_SetWorldMatrix(arg0, sp10);
}
#endif

MKModel *MKModel_GetAttachment(const MKModel *arg0) {
    return (MKModel *) arg0->unk8;
}

void MKModel_SetAlpha(MKModel *arg0, float arg1) {
    arg0->unk5C = arg1;
}

void MKModel_SetColor(MKModel *arg0, const MKVector4 &arg1) {
    arg0->unk50 = M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(arg0, f64 *, 0x58) = (f64) M2C_FIELD(&arg1, f64 *, 8);
}

f32 MKModel_GetAlpha(const MKModel *arg0) {
    if ((u32) (((u8) arg0->unk4 >> 5U) & 7) >= 1U) {
        return arg0->unk5C;
    }
    return 1.0f;
}

f64 *MKModel_GetColor(const MKModel *arg0) {
    if ((u32) (((u8) arg0->unk4 >> 5U) & 7) >= 1U) {
        return (double *) (&arg0->unk50);
    }
    return (f64 *) &MKVector4::one;
}

void MKModel_GetWorldMatrixWithAttachment(const MKModel *arg0, Matrix *arg1) {
    MKAttachment *temp_r7_1932;
    Matrix *var_r31_1939;
    Matrix *var_r3_2024;
    s32 temp_r0_1945;

    temp_r7_1932 = arg0->unk8;
    if (temp_r7_1932 != NULL) {
        if ((u32) (((u8) arg0->unk4 >> 5U) & 7) < 1U) {
            var_r31_1939 = NULL;
        } else {
            var_r31_1939 = (Matrix *) (&arg0->unk10);
        }
        temp_r0_1945 = ((u8) temp_r7_1932->unk4 >> 4U) & 0xF;
        switch (temp_r0_1945) {                     /* irregular */
        case 0:
            M2C_STRUCT_COPY(arg1, temp_r7_1932->unk0, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY(arg1, MKModel_GetWorldMatrix((MKModel *) temp_r7_1932->unk0), 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_1932->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_1932, u8 *, 4) & 0x0FFFFFFF, arg1);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_1932->unk0, (s32) M2C_FIELD(temp_r7_1932, u8 *, 4) & 0x0FFFFFFF, arg1, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_1932->unk0, (s32) M2C_FIELD(temp_r7_1932, u8 *, 4) & 0x0FFFFFFF, arg1);
            break;
        }
        if ((var_r31_1939 != NULL) && (var_r31_1939 != &Matrix::identity)) {
            arg1->Multiply(var_r31_1939, arg1);
        }
    } else {
        if ((u32) (((u8) arg0->unk4 >> 5U) & 7) < 1U) {
            var_r3_2024 = &Matrix::identity;
        } else {
            var_r3_2024 = (Matrix *) (&arg0->unk10);
        }
        M2C_STRUCT_COPY(arg1, var_r3_2024, 0x40);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'const Matrix' to 'float'
void MKModel_SetWorldMatrix(MKModel *arg0, const Matrix &arg1) {
    f32 temp_f0_2060;
    s32 temp_r7_2061;
    s32 var_ctr_2058;
    s32 var_r5_2051;
    s32 var_r6_2055;
    s32 var_r9_2050;

    var_r9_2050 = 0;
    var_r5_2051 = 0;
    do {
        var_r6_2055 = 0;
        var_ctr_2058 = 4;
loop_2:
        temp_f0_2060 = *(&arg1 + var_r5_2051 + var_r6_2055);
        temp_r7_2061 = var_r6_2055 + 0x10;
        var_r6_2055 += 4;
        *(arg0 + var_r5_2051 + temp_r7_2061) = temp_f0_2060;
        var_ctr_2058 -= 1;
        if (var_ctr_2058 != 0) {
            goto loop_2;
        }
        var_r9_2050 += 1;
        var_r5_2051 += 0x10;
    } while (var_r9_2050 < 4);
    arg0->unk5 &= ~0x40;
}
#endif

s32 MKModel_GetWorldMatrix(const MKModel *arg0) {
    if (((u8) arg0->unk4 >> 5U) & 7) {
        return (s32) &arg0->unk10;
    }
    return (s32) &Matrix::identity;
}

MKHeap *MKModel_GetName(const MKModel *arg0) {
    return (MKHeap *) arg0->unk0;
}

#if 0 // DRAFT: undefined identifier 'attachmentMatrix'
void MKModel_DrawModelParticles(const MKModel *arg0, const Matrix *arg1) {
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    MKAttachment *temp_r7_2114;
    Matrix *temp_r30_2207;
    Matrix *var_r29_2115;
    Matrix *var_r3_2403;
    f32 temp_f0_2208;
    f32 temp_f0_2283;
    f32 temp_f1_2206;
    f32 temp_f1_2282;
    f32 temp_f31_2434;
    f32 temp_f3_2211;
    f32 temp_f3_2285;
    f32 temp_f3_2409;
    f32 temp_f4_2216;
    f32 temp_f4_2290;
    f32 temp_f6_2415;
    f32 temp_f7_2421;
    f32 var_f29_2309;
    f32 var_f30_2235;
    f64 temp_f0_2441;
    f64 temp_f0_2451;
    f64 temp_f0_2462;
    f64 temp_f0_2472;
    f64 temp_f0_2482;
    f64 temp_f0_2492;
    f64 temp_f0_2510;
    f64 temp_f0_2522;
    f64 temp_f0_2539;
    f64 temp_f0_2551;
    f64 temp_f0_2568;
    f64 temp_f0_2580;
    f64 temp_f0_2597;
    f64 temp_f0_2609;
    f64 temp_f1_2219;
    f64 temp_f1_2225;
    f64 temp_f1_2229;
    f64 temp_f1_2293;
    f64 temp_f1_2299;
    f64 temp_f1_2303;
    s16 var_r25_2204;
    s32 temp_r0_2120;
    s32 temp_r27_2375;
    s32 temp_r3_2248;
    s32 temp_r3_2322;
    s32 var_r0_2258;
    s32 var_r0_2332;
    s32 var_r20_2359;
    s32 var_r24_2357;
    u8 temp_r4_2391;
    u8 var_r26_2116;
    u8 var_r3_2392;
    void *temp_r23_2363;
    void *temp_r28_2209;
    void *temp_r3_2626;

    temp_r7_2114 = arg0->unk8;
    var_r29_2115 = (Matrix *) (&arg0->unk10);
    var_r26_2116 = 0;
    if (temp_r7_2114 != NULL) {
        temp_r0_2120 = ((u8) temp_r7_2114->unk4 >> 4U) & 0xF;
        switch (temp_r0_2120) {                     /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, temp_r7_2114->unk0, 0x40);
            /* fallthrough */
        case 1:                                     /* switch 1 */
            M2C_STRUCT_COPY(attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, MKModel_GetWorldMatrix((MKModel *) temp_r7_2114->unk0), 0x40);
            break;
        case 2:                                     /* switch 1 */
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_2114->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_2114, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        case 3:                                     /* switch 1 */
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_2114->unk0, (s32) M2C_FIELD(temp_r7_2114, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix, 1U);
            break;
        case 4:                                     /* switch 1 */
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_2114->unk0, (s32) M2C_FIELD(temp_r7_2114, u8 *, 4) & 0x0FFFFFFF, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
            break;
        }
        if ((var_r29_2115 != NULL) && (var_r29_2115 != &Matrix::identity)) {
            ((Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix)->Multiply(var_r29_2115, (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix);
        }
        var_r29_2115 = (Matrix *) attachmentMatrix$localstatic3$GetTempLocalToWorldMatrix;
    }
    var_r25_2204 = -1;
    temp_f1_2206 = var_r29_2115->unk0;
    temp_r30_2207 = MKView_GetCameraMatrix();
    temp_f0_2208 = var_r29_2115->unk4;
    temp_r28_2209 = temp_r30_2207 + 0x10;
    temp_f3_2211 = var_r29_2115->unk8;
    temp_f4_2216 = (temp_f3_2211 * temp_f3_2211) + ((temp_f1_2206 * temp_f1_2206) + (temp_f0_2208 * temp_f0_2208));
    if (temp_f4_2216 > 0.0f) {
        temp_f1_2219 = __frsqrte(temp_f4_2216);
        temp_f1_2225 = 0.5 * temp_f1_2219 * -(((f64) temp_f4_2216 * (temp_f1_2219 * temp_f1_2219)) - 3.0);
        temp_f1_2229 = 0.5 * temp_f1_2225 * -(((f64) temp_f4_2216 * (temp_f1_2225 * temp_f1_2225)) - 3.0);
        var_f30_2235 = (f32) ((f64) temp_f4_2216 * (0.5 * temp_f1_2229 * -(((f64) temp_f4_2216 * (temp_f1_2229 * temp_f1_2229)) - 3.0)));
    } else if (temp_f4_2216 < M2C_BITWISE(f32, 0.0)) {
        var_f30_2235 = __float_nan;
    } else {
        spC = temp_f4_2216;
        temp_r3_2248 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r3_2248) {                     /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_2258 = 1;
            } else {
                var_r0_2258 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_2258 = 5;
            } else {
                var_r0_2258 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_2258 = 4;
            break;
        }
        if (var_r0_2258 == 1) {
            var_f30_2235 = __float_nan;
        } else {
            var_f30_2235 = temp_f4_2216;
        }
    }
    temp_f1_2282 = var_r29_2115->unk10;
    temp_f0_2283 = var_r29_2115->unk14;
    temp_f3_2285 = var_r29_2115->unk18;
    temp_f4_2290 = (temp_f3_2285 * temp_f3_2285) + ((temp_f1_2282 * temp_f1_2282) + (temp_f0_2283 * temp_f0_2283));
    if (temp_f4_2290 > 0.0f) {
        temp_f1_2293 = __frsqrte(temp_f4_2290);
        temp_f1_2299 = 0.5 * temp_f1_2293 * -(((f64) temp_f4_2290 * (temp_f1_2293 * temp_f1_2293)) - 3.0);
        temp_f1_2303 = 0.5 * temp_f1_2299 * -(((f64) temp_f4_2290 * (temp_f1_2299 * temp_f1_2299)) - 3.0);
        var_f29_2309 = (f32) ((f64) temp_f4_2290 * (0.5 * temp_f1_2303 * -(((f64) temp_f4_2290 * (temp_f1_2303 * temp_f1_2303)) - 3.0)));
    } else if (temp_f4_2290 < M2C_BITWISE(f32, 0.0)) {
        var_f29_2309 = __float_nan;
    } else {
        sp8 = temp_f4_2290;
        temp_r3_2322 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_2322) {                     /* switch 3; irregular */
        case 0x7F800000:                            /* switch 3 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2332 = 1;
            } else {
                var_r0_2332 = 2;
            }
            break;
        case 0x0:                                   /* switch 3 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2332 = 5;
            } else {
                var_r0_2332 = 3;
            }
            break;
        default:                                    /* switch 3 */
            var_r0_2332 = 4;
            break;
        }
        if (var_r0_2332 == 1) {
            var_f29_2309 = __float_nan;
        } else {
            var_f29_2309 = temp_f4_2290;
        }
    }
    var_r24_2357 = 0;
    var_r20_2359 = 0;
loop_68:
    temp_r3_2626 = arg0->unk0;
    if (var_r24_2357 < (s32) M2C_FIELD(temp_r3_2626, s32 *, 0x34)) {
        temp_r23_2363 = *(M2C_FIELD(temp_r3_2626, s32 *, 0x38) + var_r20_2359);
        if ((s16) M2C_FIELD(temp_r23_2363, s16 *, 0x1C) != var_r25_2204) {
            if (var_r26_2116 != 0) {
                MKEndPrimitive();
            }
            var_r25_2204 = M2C_FIELD(temp_r23_2363, s16 *, 0x1C);
            temp_r27_2375 = var_r25_2204 * 4;
            if (MKMaterial_GetParameter(*(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x54) + temp_r27_2375), (MKMaterialParameter) 6) == 0) {
                MKMaterial_SetMaterial(*(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x54) + temp_r27_2375));
                MKPrimitive(0xC, 0);
                var_r26_2116 = 1;
                goto block_60;
            }
        } else {
block_60:
            temp_r4_2391 = M2C_FIELD(temp_r23_2363, u8 *, 0x14);
            var_r3_2392 = 0;
            if (((s8) temp_r4_2391 == -1) || ((u8) (arg1 == NULL) != 0)) {
                var_r3_2392 = 1;
            }
            if (var_r3_2392 != 0) {
                var_r3_2403 = var_r29_2115;
            } else {
                var_r3_2403 = (Matrix *) (&arg1[(s8) temp_r4_2391]);
            }
            temp_f3_2409 = M2C_FIELD(temp_r23_2363, f32 *, 4);
            temp_f6_2415 = M2C_FIELD(temp_r23_2363, f32 *, 0);
            temp_f7_2421 = M2C_FIELD(temp_r23_2363, f32 *, 8);
            temp_f31_2434 = M2C_FIELD(temp_r23_2363, f32 *, 0x60);
            sp1D0 = var_r3_2403->unk30 + ((temp_f7_2421 * var_r3_2403->unk20) + ((temp_f6_2415 * var_r3_2403->unk0) + (temp_f3_2409 * var_r3_2403->unk10)));
            sp1D4 = var_r3_2403->unk34 + ((temp_f7_2421 * var_r3_2403->unk24) + ((temp_f6_2415 * var_r3_2403->unk4) + (temp_f3_2409 * var_r3_2403->unk14)));
            sp1D8 = var_r3_2403->unk38 + ((temp_f7_2421 * var_r3_2403->unk28) + ((temp_f6_2415 * var_r3_2403->unk8) + (temp_f3_2409 * var_r3_2403->unk18)));
            temp_f0_2441 = M2C_FIELD(temp_r30_2207, f64 *, 0) * (f64) var_f30_2235;
            sp20 = temp_f0_2441;
            sp190 = temp_f0_2441;
            sp28 = temp_r30_2207->unk8 * var_f30_2235;
            sp198 = (f64) sp28;
            temp_f0_2451 = temp_f0_2441 * (f64) temp_f31_2434;
            spE0 = temp_f0_2451;
            sp1A0 = temp_f0_2451;
            spE8 = (f32) sp198 * temp_f31_2434;
            sp1A8 = (f64) spE8;
            temp_f0_2462 = temp_f0_2451 * 5.222099017e-315;
            spD0 = temp_f0_2462;
            sp1C0 = temp_f0_2462;
            spD8 = (f32) sp1A8 * 0.5f;
            sp1C8 = (f64) spD8;
            temp_f0_2472 = M2C_FIELD(temp_r28_2209, f64 *, 0) * (f64) var_f29_2309;
            sp10 = temp_f0_2472;
            sp170 = temp_f0_2472;
            sp18 = M2C_FIELD(temp_r28_2209, f32 *, 8) * var_f29_2309;
            sp178 = (f64) sp18;
            temp_f0_2482 = temp_f0_2472 * (f64) temp_f31_2434;
            spC0 = temp_f0_2482;
            sp180 = temp_f0_2482;
            spC8 = (f32) sp178 * temp_f31_2434;
            sp188 = (f64) spC8;
            temp_f0_2492 = temp_f0_2482 * 5.222099017e-315;
            spB0 = temp_f0_2492;
            sp1B0 = temp_f0_2492;
            spB8 = (f32) sp188 * 0.5f;
            sp1B8 = (f64) spB8;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &arg0->unk50));
            MKSetTexCoord1F(0.0f, 0.0f);
            temp_f0_2510 = (f64) sp1D0 + temp_f0_2492;
            spA0 = temp_f0_2510;
            sp150 = temp_f0_2510;
            spA8 = sp1D8 + (f32) sp1B8;
            sp158 = (f64) spA8;
            temp_f0_2522 = sp150 - temp_f0_2462;
            sp90 = temp_f0_2522;
            sp160 = temp_f0_2522;
            sp98 = (f32) sp158 - (f32) sp1C8;
            sp168 = (f64) sp98;
            MKSetPositionV(*((MKVector3 *) &sp160));
            MKSetTexCoord1F(1.0f, 0.0f);
            temp_f0_2539 = (f64) sp1D0 + sp1B0;
            sp80 = temp_f0_2539;
            sp130 = temp_f0_2539;
            sp88 = sp1D8 + (f32) sp1B8;
            sp138 = (f64) sp88;
            temp_f0_2551 = sp130 + sp1C0;
            sp70 = temp_f0_2551;
            sp140 = temp_f0_2551;
            sp78 = (f32) sp138 + (f32) sp1C8;
            sp148 = (f64) sp78;
            MKSetPositionV(*((MKVector3 *) &sp140));
            MKSetTexCoord1F(0.0f, 1.0f);
            temp_f0_2568 = (f64) sp1D0 - sp1B0;
            sp60 = temp_f0_2568;
            sp110 = temp_f0_2568;
            sp68 = sp1D8 - (f32) sp1B8;
            sp118 = (f64) sp68;
            temp_f0_2580 = sp110 - sp1C0;
            sp50 = temp_f0_2580;
            sp120 = temp_f0_2580;
            sp58 = (f32) sp118 - (f32) sp1C8;
            sp128 = (f64) sp58;
            MKSetPositionV(*((MKVector3 *) &sp120));
            MKSetTexCoord1F(1.0f, 1.0f);
            temp_f0_2597 = (f64) sp1D0 - sp1B0;
            sp40 = temp_f0_2597;
            spF0 = temp_f0_2597;
            sp48 = sp1D8 - (f32) sp1B8;
            spF8 = (f64) sp48;
            temp_f0_2609 = spF0 + sp1C0;
            sp30 = temp_f0_2609;
            sp100 = temp_f0_2609;
            sp38 = (f32) spF8 + (f32) sp1C8;
            sp108 = (f64) sp38;
            MKSetPositionV(*((MKVector3 *) &sp100));
            MKEnd();
        }
        var_r24_2357 += 1;
        var_r20_2359 += 4;
        goto loop_68;
    }
    if (var_r26_2116 != 0) {
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKModel_RemoveDestroyedModels() {
    MKAttachment **var_r31_2656;
    MKAttachment *var_r30_2657;
    MKHeap *temp_r3_2683;
    s32 temp_r0_2669;
    s32 temp_r3_2697;
    s32 temp_r4_2667;
    s32 temp_r4_2682;
    s32 var_r28_2672;
    s32 var_r29_2673;
    s8 *temp_r4_2698;
    u8 temp_r4_2660;
    u8 temp_r4_2663;
    void *temp_r3_2687;

    var_r31_2656 = &pDeathRow;
    var_r30_2657 = pDeathRow;
loop_18:
    if (var_r30_2657 != NULL) {
        temp_r4_2660 = var_r30_2657->unk4;
        temp_r4_2663 = (temp_r4_2660 & ~0x18) | (((((temp_r4_2660 >> 3U) & 3) - 1) << 3) & 0x18);
        var_r30_2657->unk4 = temp_r4_2663;
        if (!((temp_r4_2663 >> 3U) & 3)) {
            temp_r4_2667 = var_r30_2657->unk0;
            temp_r0_2669 = M2C_FIELD(temp_r4_2667, s32 *, 0x24) - 1;
            M2C_FIELD(temp_r4_2667, s32 *, 0x24) = temp_r0_2669;
            if (temp_r0_2669 <= 0) {
                var_r28_2672 = 0;
                var_r29_2673 = 0;
loop_5:
                temp_r4_2682 = var_r30_2657->unk0;
                temp_r3_2683 = M2C_FIELD(temp_r4_2682, MKHeap **, 0x30);
                if (var_r28_2672 < (s16) M2C_FIELD(temp_r3_2683, s16 *, 6)) {
                    MKMaterial_Destroy(*(temp_r3_2683->unk54 + var_r29_2673));
                    var_r28_2672 += 1;
                    var_r29_2673 += 4;
                    goto loop_5;
                }
                temp_r3_2687 = M2C_FIELD(temp_r4_2682, void **, 0x40);
                if (temp_r3_2687 != NULL) {
                    M2C_FIELD(temp_r3_2687, s8 **, 0x3C) = (s8 *) M2C_FIELD(temp_r4_2682, s8 **, 0x3C);
                } else {
                    pTemplatesList = M2C_FIELD(temp_r4_2682, s8 **, 0x3C);
                }
                temp_r3_2697 = var_r30_2657->unk0;
                temp_r4_2698 = M2C_FIELD(temp_r3_2697, s8 **, 0x3C);
                if (temp_r4_2698 != NULL) {
                    M2C_FIELD(temp_r4_2698, void **, 0x40) = (void *) M2C_FIELD(temp_r3_2697, void **, 0x40);
                }
                if ((u32) M2C_FIELD(var_r30_2657->unk0, MKHeap **, 0x30)->unk24 != 0U) {
                    MKGrass_DestroyGrassData((MKModel *) var_r30_2657);
                }
                ((MKHeap *) (M2C_FIELD(var_r30_2657->unk0, MKHeap **, 0x30)->unk6C))->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
                ((MKHeap *) (M2C_FIELD(var_r30_2657->unk0, MKHeap **, 0x30)))->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
                ((MKHeap *) var_r30_2657->unk0)->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
            }
            *var_r31_2656 = M2C_FIELD(var_r30_2657, MKAttachment **, 8);
            if (var_r30_2657->unk5 & 1) {
                ((MKHeap *) var_r30_2657)->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
            }
        } else {
            var_r31_2656 = (MKAttachment **) (var_r30_2657 + 8);
        }
        var_r30_2657 = *var_r31_2656;
        goto loop_18;
    }
}
#endif

void MKModel_Destroy(MKModel *arg0) {
    arg0->unk4 |= 0x18;
    arg0->unk8 = pDeathRow;
    pDeathRow = (MKAttachment *) arg0;
    if (((u8) arg0->unk4 >> 2U) & 1) {
        arg0->unk70->Destroy();
        arg0->unk4 &= ~4;
    }
    if ((u8) M2C_FIELD(arg0->unk0, u8 *, 0x48) != 0) {
        MKGrass_RemoveModel(arg0);
    }
    gClothManager.RemoveModel(arg0);
    MKModel_DestroyCloth(arg0);
    gDynamicBones.RemoveModel(arg0);
}

#if 0 // DRAFT: function call 'strnicmp(signed char *, const char[7], int)' does not match 'strnicmp(const char *, const char *, int)'
void MKModel_SetupCloth(MKModel *arg0) {
    M2C_UNK sp8;
    MKCloth *temp_r31_2996;
    ModelCloth *temp_r3_2937;
    s16 temp_r0_2812;
    s16 temp_r0_2895;
    s16 temp_r0_3170;
    s16 var_ctr_2813;
    s16 var_ctr_2896;
    s16 var_ctr_3171;
    s32 temp_r15_3023;
    s32 temp_r15_3040;
    s32 temp_r15_3105;
    s32 temp_r16_3135;
    s32 temp_r3_2860;
    s32 temp_r3_2967;
    s32 temp_r3_3138;
    s32 var_r15_2832;
    s32 var_r15_2929;
    s32 var_r15_3125;
    s32 var_r18_2847;
    s32 var_r18_2949;
    s32 var_r18_3132;
    s32 var_r19_3131;
    s32 var_r20_3130;
    s32 var_r21_3128;
    s32 var_r22_2808;
    s32 var_r23_2809;
    s32 var_r24_2845;
    s32 var_r24_2989;
    s32 var_r25_2990;
    s32 var_r26_2988;
    s32 var_r27_2928;
    s32 var_r29_2931;
    s32 var_r30_2932;
    s32 var_r3_2893;
    s32 var_r3_3002;
    s32 var_r3_3168;
    s32 var_r4_2804;
    s32 var_r6_3001;
    s8 *var_r3_3031;
    s8 *var_r3_3048;
    s8 *var_r3_3073;
    s8 *var_r3_3093;
    s8 *var_r3_3114;
    u16 *var_r17_2818;
    u16 *var_r5_2901;
    u16 *var_r5_3176;
    void *temp_r21_2849;
    void *temp_r3_2811;
    void *temp_r4_2894;
    void *temp_r4_2938;
    void *temp_r4_3169;
    void *temp_r5_3009;
    void *temp_r5_3018;

    var_r4_2804 = 0;
    var_r22_2808 = 0;
    var_r23_2809 = 0;
    temp_r3_2811 = M2C_FIELD(arg0->unk0, void **, 0x30);
    temp_r0_2812 = M2C_FIELD(temp_r3_2811, s16 *, 0xC);
    var_ctr_2813 = temp_r0_2812;
    if (temp_r0_2812 > 0) {
loop_1:
        var_r17_2818 = (unsigned short *) (M2C_FIELD(temp_r3_2811, s32 *, 0x60) + var_r4_2804);
        if ((u16) *var_r17_2818 == 5) {

        } else {
            var_r4_2804 += 0x10;
            var_ctr_2813 -= 1;
            if (var_ctr_2813 == 0) {
                goto block_4;
            }
            goto loop_1;
        }
    } else {
block_4:
        var_r17_2818 = NULL;
    }
    if (var_r17_2818 != NULL) {
        var_r15_2832 = M2C_FIELD(var_r17_2818, s32 *, 0xC);
loop_19:
        if (var_r15_2832 < (s32) (M2C_FIELD(var_r17_2818, s32 *, 0xC) + M2C_FIELD(var_r17_2818, s32 *, 8))) {
            if (strnicmp(MKModel_GetRefPointName(arg0, var_r15_2832), "r_p_g_", 6) == 0) {
                var_r24_2845 = 0;
                var_r18_2847 = 0;
                do {
                    temp_r21_2849 = &MKCloth::globalCollisionPrim + var_r18_2847;
                    if ((u8) M2C_FIELD(temp_r21_2849, u8 *, 0xC) == 0) {
                        M2C_FIELD(temp_r21_2849, u8 *, 0xC) = 1U;
                        M2C_FIELD(temp_r21_2849, MKModel **, 0) = arg0;
                        M2C_FIELD(temp_r21_2849, s32 *, 4) = var_r15_2832;
                        temp_r3_2860 = MKModel_GetRefPointType(arg0, var_r15_2832);
                        switch (temp_r3_2860) {     /* switch 1; irregular */
                        case 3:                     /* switch 1 */
                            M2C_FIELD(temp_r21_2849, s32 *, 8) = MKCloth::AllocateCapsule();
                            break;
                        case 4:                     /* switch 1 */
                            M2C_FIELD(temp_r21_2849, s32 *, 8) = MKCloth::AllocatePlane();
                            break;
                        default:                    /* switch 1 */
                            M2C_FIELD(temp_r21_2849, s32 *, 8) = MKCloth::AllocateSphere();
                            break;
                        }
                    }
                    var_r24_2845 += 1;
                    var_r18_2847 += 0x10;
                } while (var_r24_2845 < 0x50);
            }
            var_r15_2832 += 1;
            goto loop_19;
        }
    }
    var_r3_2893 = 0;
    temp_r4_2894 = M2C_FIELD(arg0->unk0, void **, 0x30);
    temp_r0_2895 = M2C_FIELD(temp_r4_2894, s16 *, 0xC);
    var_ctr_2896 = temp_r0_2895;
    if (temp_r0_2895 > 0) {
loop_21:
        var_r5_2901 = (unsigned short *) (M2C_FIELD(temp_r4_2894, s32 *, 0x60) + var_r3_2893);
        if ((u16) *var_r5_2901 == 2) {

        } else {
            var_r3_2893 += 0x10;
            var_ctr_2896 -= 1;
            if (var_ctr_2896 == 0) {
                goto block_24;
            }
            goto loop_21;
        }
    } else {
block_24:
        var_r5_2901 = NULL;
    }
    if (var_r5_2901 != NULL) {
        var_r22_2808 = M2C_FIELD(var_r5_2901, s32 *, 4);
        var_r23_2809 = M2C_FIELD(var_r5_2901, s32 *, 8);
    }
    if ((var_r23_2809 > 0) && ((u8) *MKCloth::clothCreateDisabled == 0)) {
        arg0->unk84->unk31 = 1;
        var_r27_2928 = 0;
        var_r15_2929 = 0;
        var_r29_2931 = 0;
        var_r30_2932 = 0;
        arg0->unk84->unk30 = 0;
        arg0->unk84->unk0 = 0;
        temp_r3_2937 = arg0->unk84;
        temp_r4_2938 = M2C_FIELD(arg0->unk0, void **, 0x30);
        temp_r3_2937->unk10 = M2C_FIELD(temp_r4_2938, f64 *, 0x30);
        temp_r3_2937->unk18 = M2C_FIELD(temp_r4_2938, f64 *, 0x38);
        temp_r3_2937->unk20 = M2C_FIELD(temp_r4_2938, f64 *, 0x40);
        temp_r3_2937->unk28 = M2C_FIELD(temp_r4_2938, f64 *, 0x48);
        if (var_r17_2818 != NULL) {
            var_r18_2949 = M2C_FIELD(var_r17_2818, s32 *, 0xC);
loop_39:
            if (var_r18_2949 < (s32) (M2C_FIELD(var_r17_2818, s32 *, 0xC) + M2C_FIELD(var_r17_2818, s32 *, 8))) {
                if (strnicmp(MKModel_GetRefPointName(arg0, var_r18_2949), "r_p_g_", 6) != 0) {
                    *(&sp8 + var_r15_2929) = var_r18_2949;
                    var_r27_2928 += 1;
                    var_r15_2929 += 4;
                    temp_r3_2967 = MKModel_GetRefPointType(arg0, var_r18_2949);
                    switch (temp_r3_2967) {         /* switch 2; irregular */
                    case 3:                         /* switch 2 */
                        var_r29_2931 += 1;
                        break;
                    case 4:                         /* switch 2 */
                        var_r30_2932 += 1;
                        break;
                    }
                }
                var_r18_2949 += 1;
                goto loop_39;
            }
        }
        var_r26_2988 = 0;
        var_r24_2989 = 0;
        var_r25_2990 = 0;
loop_83:
        if (var_r26_2988 < var_r23_2809) {
            temp_r31_2996 = arg0->unk84->unk8 + var_r25_2990;
            temp_r31_2996->unkC = arg0;
            M2C_FIELD(temp_r31_2996, void **, 4) = (void *) (var_r22_2808 + var_r24_2989);
            temp_r31_2996->Init();
            var_r6_3001 = 0;
            var_r3_3002 = 0;
loop_43:
            temp_r5_3018 = M2C_FIELD(temp_r31_2996, void **, 4);
            if (var_r6_3001 < (s32) M2C_FIELD(temp_r5_3018, s32 *, 0x18)) {
                var_r6_3001 += 1;
                temp_r5_3009 = (void *) (M2C_FIELD(temp_r5_3018, s32 *, 0x1C) + var_r3_3002);
                var_r3_3002 += 0x10;
                M2C_FIELD(temp_r5_3009, s32 *, 0) = (s32) *(M2C_FIELD(M2C_FIELD(temp_r31_2996->unkC->unk0, void **, 0x30), s32 *, 0x54) + (M2C_FIELD(temp_r5_3009, s32 *, 4) * 4));
                goto loop_43;
            }
            temp_r15_3023 = M2C_FIELD(temp_r5_3018, s32 *, 0) * 0x38;
            if (MKHeap::Current() != NULL) {
                var_r3_3031 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r15_3023, NULL, 0));
            } else {
                var_r3_3031 = malloc(temp_r15_3023);
            }
            M2C_FIELD(temp_r31_2996, s8 **, 0) = var_r3_3031;
            temp_r15_3040 = M2C_FIELD(M2C_FIELD(temp_r31_2996, void **, 4), s32 *, 0x10) * 0xC;
            if (MKHeap::Current() != NULL) {
                var_r3_3048 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r15_3040, NULL, 0));
            } else {
                var_r3_3048 = malloc(temp_r15_3040);
            }
            temp_r31_2996->unk30 = var_r3_3048;
            memcpy(temp_r31_2996->unk30, M2C_FIELD(M2C_FIELD(temp_r31_2996, void **, 4), void **, 0x14), (u32) temp_r15_3040);
            temp_r31_2996->Create();
            if (var_r27_2928 != 0) {
                if (var_r29_2931 != 0) {
                    if (MKHeap::Current() != NULL) {
                        var_r3_3073 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(var_r29_2931 * 4, NULL, 0));
                    } else {
                        var_r3_3073 = malloc(var_r29_2931 * 4);
                    }
                    temp_r31_2996->unkC4 = var_r3_3073;
                    temp_r31_2996->CreateInternalCollisionCapsules(var_r29_2931);
                }
                if (var_r30_2932 != 0) {
                    if (MKHeap::Current() != NULL) {
                        var_r3_3093 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(var_r30_2932 * 4, NULL, 0));
                    } else {
                        var_r3_3093 = malloc(var_r30_2932 * 4);
                    }
                    temp_r31_2996->unkAC = var_r3_3093;
                    temp_r31_2996->CreateInternalCollisionPlanes(var_r30_2932);
                }
                temp_r15_3105 = var_r27_2928 - (var_r29_2931 + var_r30_2932);
                if (temp_r15_3105 != 0) {
                    if (MKHeap::Current() != NULL) {
                        var_r3_3114 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r15_3105 * 4, NULL, 0));
                    } else {
                        var_r3_3114 = malloc(temp_r15_3105 * 4);
                    }
                    temp_r31_2996->unkB8 = var_r3_3114;
                    temp_r31_2996->CreateInternalCollisionSpheres(temp_r15_3105);
                }
                var_r15_3125 = 0;
                var_r29_2931 = 0;
                var_r21_3128 = 0;
                var_r30_2932 = 0;
                var_r20_3130 = 0;
                var_r19_3131 = 0;
                var_r18_3132 = 0;
loop_73:
                if (var_r15_3125 < var_r27_2928) {
                    temp_r16_3135 = *(&sp8 + var_r18_3132);
                    temp_r3_3138 = MKModel_GetRefPointType(arg0, temp_r16_3135);
                    if (temp_r3_3138 == 3) {
                        var_r29_2931 += 1;
                        temp_r31_2996->unkC4[var_r21_3128] = temp_r16_3135;
                        var_r21_3128 += 4;
                    } else if (temp_r3_3138 == 4) {
                        var_r30_2932 += 1;
                        temp_r31_2996->unkAC[var_r20_3130] = temp_r16_3135;
                        var_r20_3130 += 4;
                    } else {
                        temp_r31_2996->unkB8[var_r19_3131] = temp_r16_3135;
                        var_r19_3131 += 4;
                    }
                    var_r15_3125 += 1;
                    var_r18_3132 += 4;
                    goto loop_73;
                }
                temp_r31_2996->UpdateCollisionPrims();
            }
            var_r3_3168 = 0;
            temp_r4_3169 = M2C_FIELD(arg0->unk0, void **, 0x30);
            temp_r0_3170 = M2C_FIELD(temp_r4_3169, s16 *, 0xC);
            var_ctr_3171 = temp_r0_3170;
            if (temp_r0_3170 > 0) {
loop_76:
                var_r5_3176 = (unsigned short *) (M2C_FIELD(temp_r4_3169, s32 *, 0x60) + var_r3_3168);
                if ((u16) *var_r5_3176 == 0xA) {

                } else {
                    var_r3_3168 += 0x10;
                    var_ctr_3171 -= 1;
                    if (var_ctr_3171 == 0) {
                        goto block_79;
                    }
                    goto loop_76;
                }
            } else {
block_79:
                var_r5_3176 = NULL;
            }
            if (var_r5_3176 != NULL) {
                temp_r31_2996->unkCC = M2C_FIELD(var_r5_3176, s32 *, 4);
                temp_r31_2996->unkD0 = M2C_FIELD(var_r5_3176, s32 *, 8);
            }
            var_r26_2988 += 1;
            var_r24_2989 += 0x58;
            var_r25_2990 += 0xF8;
            goto loop_83;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKModel_DestroyCloth(MKModel *arg0) {
    ModelCloth *temp_r3_3219;
    s32 var_r29_3222;
    s32 var_r31_3223;

    if ((u32) (((u8) arg0->unk4 >> 5U) & 7) >= 2U) {
        temp_r3_3219 = MKModel_GetCloth(arg0);
        if (temp_r3_3219 != NULL) {
            var_r29_3222 = 0;
            var_r31_3223 = 0;
loop_4:
            if (var_r29_3222 < (s32) temp_r3_3219->unk4) {
                ((MKCloth *) (temp_r3_3219->unk8 + var_r31_3223))->Deinit();
                var_r29_3222 += 1;
                var_r31_3223 += 0xF8;
                goto loop_4;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal operand
void MKModelTemplateData::UnpackTemplatePointers(bool arg0) {
    MKModelTemplateData *var_r30_3253;
    MKModelTemplateData::CustomDataEntry *temp_r3_3404;
    s32 temp_r3_3458;
    s32 temp_r5_3270;
    s32 temp_r5_3278;
    s32 temp_r5_3439;
    s32 var_r27_3400;
    s32 var_r31_3399;
    s32 var_r3_3266;
    s32 var_r3_3308;
    s32 var_r3_3342;
    s32 var_r3_3438;
    s32 var_r5_3307;
    s32 var_r6_3265;
    s32 var_r6_3341;
    s32 var_r6_3437;
    u16 temp_r0_3405;
    u32 temp_r0_3271;
    u32 temp_r0_3279;
    u32 temp_r0_3312;
    u32 temp_r0_3348;
    u32 temp_r0_3365;
    u32 temp_r0_3442;
    u32 temp_r0_3459;
    void *temp_r0_3259;
    void *temp_r0_3293;
    void *temp_r0_3301;
    void *temp_r0_3326;
    void *temp_r0_3334;
    void *temp_r0_3356;
    void *temp_r0_3379;
    void *temp_r0_3385;
    void *temp_r0_3393;
    void *temp_r0_3429;
    void *temp_r0_3466;
    void *temp_r0_3480;
    void *temp_r0_3486;
    void *temp_r0_3492;
    void *temp_r4_3269;
    void *temp_r4_3277;
    void *temp_r4_3311;
    void *temp_r4_3347;
    void *temp_r4_3355;
    void *temp_r4_3364;
    void *temp_r4_3451;

    var_r30_3253 = this;
    if (arg0 != 0) {
        var_r30_3253 = (MKModelTemplateData *) -(s32) var_r30_3253;
    }
    if (arg0 == 0) {
        temp_r0_3259 = this->unk50;
        if (temp_r0_3259 != NULL) {
            this->unk50 = ((u8 *) temp_r0_3259) + var_r30_3253;
        }
    }
    var_r6_3265 = 0;
    var_r3_3266 = 0;
loop_11:
    if (var_r6_3265 < (s16) this->unk4) {
        temp_r4_3269 = this->unk50;
        temp_r5_3270 = var_r3_3266 + 0x30;
        temp_r0_3271 = *(temp_r4_3269 + temp_r5_3270);
        if (temp_r0_3271 != 0U) {
            *(temp_r4_3269 + temp_r5_3270) = temp_r0_3271 + var_r30_3253;
        }
        temp_r4_3277 = this->unk50;
        temp_r5_3278 = var_r3_3266 + 0x34;
        temp_r0_3279 = *(temp_r4_3277 + temp_r5_3278);
        if (temp_r0_3279 != 0U) {
            *(temp_r4_3277 + temp_r5_3278) = temp_r0_3279 + var_r30_3253;
        }
        var_r6_3265 += 1;
        var_r3_3266 += 0x40;
        goto loop_11;
    }
    if (arg0 != 0) {
        temp_r0_3293 = this->unk50;
        if (temp_r0_3293 != NULL) {
            this->unk50 = ((u8 *) temp_r0_3293) + var_r30_3253;
        }
    }
    if (arg0 == 0) {
        temp_r0_3301 = this->unk54;
        if (temp_r0_3301 != NULL) {
            this->unk54 = ((u8 *) temp_r0_3301) + var_r30_3253;
        }
    }
    var_r5_3307 = 0;
    var_r3_3308 = 0;
loop_22:
    if (var_r5_3307 < (s16) this->unk6) {
        temp_r4_3311 = this->unk54;
        temp_r0_3312 = *(temp_r4_3311 + var_r3_3308);
        if (temp_r0_3312 != 0U) {
            *(temp_r4_3311 + var_r3_3308) = temp_r0_3312 + var_r30_3253;
        }
        var_r5_3307 += 1;
        var_r3_3308 += 4;
        goto loop_22;
    }
    if (arg0 != 0) {
        temp_r0_3326 = this->unk54;
        if (temp_r0_3326 != NULL) {
            this->unk54 = ((u8 *) temp_r0_3326) + var_r30_3253;
        }
    }
    if (arg0 == 0) {
        temp_r0_3334 = this->unk58;
        if (temp_r0_3334 != NULL) {
            this->unk58 = ((u8 *) temp_r0_3334) + var_r30_3253;
        }
    }
    var_r6_3341 = 0;
    var_r3_3342 = 0;
loop_39:
    if (var_r6_3341 < (s16) this->unkA) {
        if (arg0 == 0) {
            temp_r4_3347 = this->unk58;
            temp_r0_3348 = *(temp_r4_3347 + var_r3_3342);
            if (temp_r0_3348 != 0U) {
                *(temp_r4_3347 + var_r3_3342) = temp_r0_3348 + var_r30_3253;
            }
        }
        temp_r4_3355 = *(this->unk58 + var_r3_3342);
        temp_r0_3356 = M2C_FIELD(temp_r4_3355, void **, 0x10);
        if (temp_r0_3356 != NULL) {
            M2C_FIELD(temp_r4_3355, void **, 0x10) = (void *) (((u8 *) temp_r0_3356) + var_r30_3253);
        }
        if (arg0 != 0) {
            temp_r4_3364 = this->unk58;
            temp_r0_3365 = *(temp_r4_3364 + var_r3_3342);
            if (temp_r0_3365 != 0U) {
                *(temp_r4_3364 + var_r3_3342) = temp_r0_3365 + var_r30_3253;
            }
        }
        var_r6_3341 += 1;
        var_r3_3342 += 4;
        goto loop_39;
    }
    if (arg0 != 0) {
        temp_r0_3379 = this->unk58;
        if (temp_r0_3379 != NULL) {
            this->unk58 = ((u8 *) temp_r0_3379) + var_r30_3253;
        }
    }
    temp_r0_3385 = this->unk5C;
    if (temp_r0_3385 != NULL) {
        this->unk5C = ((u8 *) temp_r0_3385) + var_r30_3253;
    }
    if (arg0 == 0) {
        temp_r0_3393 = this->unk60;
        if (temp_r0_3393 != NULL) {
            this->unk60 = ((u8 *) temp_r0_3393) + var_r30_3253;
        }
    }
    var_r31_3399 = 0;
    var_r27_3400 = 0;
loop_71:
    if (var_r31_3399 < (s16) this->unkC) {
        temp_r3_3404 = ((u8 *) this->unk60) + var_r27_3400;
        temp_r0_3405 = M2C_FIELD(temp_r3_3404, u16 *, 0);
        switch ((s32) temp_r0_3405) {               /* irregular */
        case 2:
            UnpackCustomDataEntry_Cloth(temp_r3_3404, arg0, (s32) var_r30_3253);
            break;
        case 10:
            UnpackCustomDataEntry_ConvexHull(temp_r3_3404, arg0, (s32) var_r30_3253);
            break;
        case 8:
            if (arg0 == 0) {
                temp_r0_3429 = M2C_FIELD(temp_r3_3404, void **, 4);
                if (temp_r0_3429 != NULL) {
                    M2C_FIELD(temp_r3_3404, void **, 4) = (void *) (((u8 *) temp_r0_3429) + var_r30_3253);
                }
            }
            var_r6_3437 = 0;
            var_r3_3438 = 0;
            temp_r5_3439 = *(this->unk60 + (var_r27_3400 + 4));
loop_64:
            temp_r4_3451 = this->unk60;
            if (var_r6_3437 < (s32) *(var_r27_3400 + (((u8 *) temp_r4_3451) + 8))) {
                temp_r0_3442 = *(temp_r5_3439 + var_r3_3438);
                if (temp_r0_3442 != 0U) {
                    *(temp_r5_3439 + var_r3_3438) = temp_r0_3442 + var_r30_3253;
                }
                var_r6_3437 += 1;
                var_r3_3438 += 8;
                goto loop_64;
            }
            if (arg0 != 0) {
                temp_r3_3458 = var_r27_3400 + 4;
                temp_r0_3459 = *(temp_r4_3451 + temp_r3_3458);
                if (temp_r0_3459 != 0U) {
                    *(temp_r4_3451 + temp_r3_3458) = temp_r0_3459 + var_r30_3253;
                }
            }
            break;
        default:
            temp_r0_3466 = M2C_FIELD(temp_r3_3404, void **, 4);
            if (temp_r0_3466 != NULL) {
                M2C_FIELD(temp_r3_3404, void **, 4) = (void *) (((u8 *) temp_r0_3466) + var_r30_3253);
            }
            break;
        }
        var_r31_3399 += 1;
        var_r27_3400 += 0x10;
        goto loop_71;
    }
    if (arg0 != 0) {
        temp_r0_3480 = this->unk60;
        if (temp_r0_3480 != NULL) {
            this->unk60 = ((u8 *) temp_r0_3480) + var_r30_3253;
        }
    }
    temp_r0_3486 = this->unk64;
    if (temp_r0_3486 != NULL) {
        this->unk64 = ((u8 *) temp_r0_3486) + var_r30_3253;
    }
    temp_r0_3492 = this->unk68;
    if (temp_r0_3492 != NULL) {
        this->unk68 = ((u8 *) temp_r0_3492) + var_r30_3253;
    }
}
#endif

void UnpackCustomDataEntry_ConvexHull(MKModelTemplateData::CustomDataEntry *arg0, bool arg1, int arg2) {
    u16 var_r8_3519;
    u32 temp_r0_3513;
    u32 temp_r0_3526;
    u32 temp_r0_3539;
    void *temp_r6_3525;

    if (arg2 != 0) {
        if (arg1 == 0) {
            temp_r0_3513 = M2C_FIELD(arg0, u32 *, 4);
            if (temp_r0_3513 != 0U) {
                M2C_FIELD(arg0, u32 *, 4) = (u32) (temp_r0_3513 + arg2);
            }
        }
        var_r8_3519 = 0;
loop_8:
        if ((s32) var_r8_3519 < (s32) M2C_FIELD(arg0, s32 *, 8)) {
            temp_r6_3525 = (void *) (M2C_FIELD(arg0, u32 *, 4) + (var_r8_3519 * 0x30));
            temp_r0_3526 = M2C_FIELD(temp_r6_3525, u32 *, 0x24);
            if (temp_r0_3526 != 0U) {
                M2C_FIELD(temp_r6_3525, u32 *, 0x24) = (u32) (temp_r0_3526 + arg2);
            }
            var_r8_3519 += 1;
            goto loop_8;
        }
        if (arg1 != 0) {
            temp_r0_3539 = M2C_FIELD(arg0, u32 *, 4);
            if (temp_r0_3539 != 0U) {
                M2C_FIELD(arg0, u32 *, 4) = (u32) (temp_r0_3539 + arg2);
            }
        }
    }
}

void UnpackCustomDataEntry_Cloth(MKModelTemplateData::CustomDataEntry *arg0, bool arg1, int arg2) {
    u16 var_r8_3561;
    u32 temp_r0_3555;
    u32 temp_r0_3568;
    u32 temp_r0_3574;
    u32 temp_r0_3580;
    u32 temp_r0_3586;
    u32 temp_r0_3592;
    u32 temp_r0_3598;
    u32 temp_r0_3604;
    u32 temp_r0_3617;
    void *temp_r6_3567;

    if (arg2 != 0) {
        if (arg1 == 0) {
            temp_r0_3555 = M2C_FIELD(arg0, u32 *, 4);
            if (temp_r0_3555 != 0U) {
                M2C_FIELD(arg0, u32 *, 4) = (u32) (temp_r0_3555 + arg2);
            }
        }
        var_r8_3561 = 0;
loop_20:
        if ((s32) var_r8_3561 < (s32) M2C_FIELD(arg0, s32 *, 8)) {
            temp_r6_3567 = (void *) (M2C_FIELD(arg0, u32 *, 4) + (var_r8_3561 * 0x58));
            temp_r0_3568 = M2C_FIELD(temp_r6_3567, u32 *, 4);
            if (temp_r0_3568 != 0U) {
                M2C_FIELD(temp_r6_3567, u32 *, 4) = (u32) (temp_r0_3568 + arg2);
            }
            temp_r0_3574 = M2C_FIELD(temp_r6_3567, u32 *, 0xC);
            if (temp_r0_3574 != 0U) {
                M2C_FIELD(temp_r6_3567, u32 *, 0xC) = (u32) (temp_r0_3574 + arg2);
            }
            temp_r0_3580 = M2C_FIELD(temp_r6_3567, u32 *, 0x14);
            if (temp_r0_3580 != 0U) {
                M2C_FIELD(temp_r6_3567, u32 *, 0x14) = (u32) (temp_r0_3580 + arg2);
            }
            temp_r0_3586 = M2C_FIELD(temp_r6_3567, u32 *, 0x1C);
            if (temp_r0_3586 != 0U) {
                M2C_FIELD(temp_r6_3567, u32 *, 0x1C) = (u32) (temp_r0_3586 + arg2);
            }
            temp_r0_3592 = M2C_FIELD(temp_r6_3567, u32 *, 0x24);
            if (temp_r0_3592 != 0U) {
                M2C_FIELD(temp_r6_3567, u32 *, 0x24) = (u32) (temp_r0_3592 + arg2);
            }
            temp_r0_3598 = M2C_FIELD(temp_r6_3567, u32 *, 0x2C);
            if (temp_r0_3598 != 0U) {
                M2C_FIELD(temp_r6_3567, u32 *, 0x2C) = (u32) (temp_r0_3598 + arg2);
            }
            temp_r0_3604 = M2C_FIELD(temp_r6_3567, u32 *, 0x54);
            if (temp_r0_3604 != 0U) {
                M2C_FIELD(temp_r6_3567, u32 *, 0x54) = (u32) (temp_r0_3604 + arg2);
            }
            var_r8_3561 += 1;
            goto loop_20;
        }
        if (arg1 != 0) {
            temp_r0_3617 = M2C_FIELD(arg0, u32 *, 4);
            if (temp_r0_3617 != 0U) {
                M2C_FIELD(arg0, u32 *, 4) = (u32) (temp_r0_3617 + arg2);
            }
        }
    }
}

#if 0 // DRAFT: function call 'strcmpi(const char *, signed char *)' does not match 'strcmpi(signed char *, signed char *)'
MKModel *MKModel_Create(const char *arg0, const char *arg1, int arg2, MKModelSLW *arg3) {
    s8 *sp8;
    MKModelSLW *var_r24_3803;
    s16 temp_r0_3861;
    s16 temp_r0_3891;
    s16 temp_r0_4053;
    s16 temp_r5_3851;
    s16 var_ctr_3866;
    s16 var_ctr_3892;
    s16 var_ctr_4054;
    s32 temp_r26_3913;
    s32 temp_r29_3799;
    s32 var_r23_3909;
    s32 var_r23_4098;
    s32 var_r25_3710;
    s32 var_r25_3850;
    s32 var_r25_4097;
    s32 var_r26_3854;
    s32 var_r26_3865;
    s32 var_r28_3709;
    s32 var_r3_3764;
    s32 var_r3_3864;
    s32 var_r3_3890;
    s32 var_r3_4051;
    s32 var_r5_3763;
    s32 var_r5_3946;
    s8 *temp_r3_3745;
    s8 *temp_r3_3964;
    s8 *temp_r3_4109;
    s8 *temp_r4_3794;
    s8 *temp_ret_3689;
    s8 *var_r25_3668;
    s8 *var_r27_3636;
    s8 *var_r30_3927;
    s8 *var_r3_3813;
    u16 *temp_r3_3883;
    u16 *temp_r3_3943;
    u16 *var_r28_3897;
    u16 *var_r5_3871;
    u8 temp_r0_3770;
    void *temp_r3_4118;
    void *temp_r4_3769;
    void *temp_r4_3848;
    void *temp_r4_3889;
    void *temp_r4_4011;
    void *temp_r5_4052;

    var_r27_3636 = pTemplatesList;
loop_2:
    if ((var_r27_3636 != NULL) && ((strcmpi(arg0, var_r27_3636) != 0) || (((MKResource *) var_r27_3636)->IsResourceAvailable() == 0))) {
        var_r27_3636 = M2C_FIELD(var_r27_3636, s8 **, 0x3C);
        goto loop_2;
    }
    if (var_r27_3636 != NULL) {
        M2C_FIELD(var_r27_3636, s32 *, 0x24) = (s32) (M2C_FIELD(var_r27_3636, s32 *, 0x24) + 1);
    } else {
        if (MKHeap::Current() != NULL) {
            var_r25_3668 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x4C, NULL, 0));
        } else {
            var_r25_3668 = malloc(0x4C);
        }
        var_r27_3636 = var_r25_3668;
        temp_ret_3689 = MKArchive_Load(Str_Printf("%s.mdl", arg0, M2C_BITWISE(f32, memset(var_r25_3668, 0, 0x4CU))), (s32 *) (var_r25_3668 + 0x28), NULL, -1);
        M2C_FIELD(var_r25_3668, s8 **, 0x30) = temp_ret_3689;
        M2C_FIELD(M2C_FIELD(var_r25_3668, s8 **, 0x30), s8 **, 0x6C) = MKArchive_Load(Str_Printf("%s.mdg", arg0, M2C_BITWISE(f32, temp_ret_3689)), (s32 *) (var_r25_3668 + 0x28), NULL, -1);
        strcpy(var_r25_3668, arg0);
        ((MKModelTemplateData *) M2C_FIELD(var_r25_3668, s8 **, 0x30))->UnpackTemplatePointers(0U);
        var_r28_3709 = 0;
        var_r25_3710 = 0;
loop_16:
        temp_r3_3745 = M2C_FIELD(var_r27_3636, s8 **, 0x30);
        if (var_r28_3709 < (s16) M2C_FIELD(temp_r3_3745, s16 *, 6)) {
            *(M2C_FIELD(M2C_FIELD(var_r27_3636, s8 **, 0x30), s32 *, 0x54) + var_r25_3710) = MKMaterial_Create(*(M2C_FIELD(temp_r3_3745, s32 *, 0x54) + var_r25_3710));
            sp8 = NULL;
            if ((u8) M2C_FIELD(var_r27_3636, u8 *, 0x48) == 0) {
                MKMaterial_GetEffectType(*(M2C_FIELD(M2C_FIELD(var_r27_3636, s8 **, 0x30), s32 *, 0x54) + var_r25_3710), &sp8);
                if ((strcmpi() == 0) && (MKGrass_GetGrassTypeId(sp8) >= 0)) {
                    M2C_FIELD(var_r27_3636, u8 *, 0x48) = 1U;
                }
            }
            var_r28_3709 += 1;
            var_r25_3710 += 4;
            goto loop_16;
        }
        MKModel_UnpackTemplatePlatformSpecific((MKModelTemplate *) var_r27_3636);
        M2C_FIELD(var_r27_3636, s32 *, 0x24) = 1;
        ((MKResource *) var_r27_3636)->InitialiseResource();
        M2C_FIELD(var_r27_3636, s8 **, 0x3C) = (s8 *) pTemplatesList;
        if ((s8 *) pTemplatesList != NULL) {
            M2C_FIELD(pTemplatesList, s8 **, 0x40) = var_r27_3636;
        }
        pTemplatesList = var_r27_3636;
        var_r5_3763 = 0;
        var_r3_3764 = 0;
loop_26:
        temp_r4_3794 = M2C_FIELD(var_r27_3636, s8 **, 0x30);
        if (var_r5_3763 < (s16) M2C_FIELD(temp_r4_3794, s16 *, 0xA)) {
            temp_r4_3769 = M2C_FIELD(*(M2C_FIELD(temp_r4_3794, s32 *, 0x58) + var_r3_3764), void **, 0x10);
            temp_r0_3770 = M2C_FIELD(temp_r4_3769, u8 *, 0);
            if ((((s8) temp_r0_3770 == 0x62) || ((s8) temp_r0_3770 == 0x42)) && ((s32) M2C_FIELD(temp_r4_3769, u8 *, 1) == 0x5F)) {
                M2C_FIELD(var_r27_3636, s32 *, 0x34) = (s32) (M2C_FIELD(var_r27_3636, s32 *, 0x34) + 1);
                if ((u32) M2C_FIELD(var_r27_3636, u32 *, 0x38) == 0U) {
                    M2C_FIELD(var_r27_3636, u32 *, 0x38) = (u32) (M2C_FIELD(M2C_FIELD(var_r27_3636, s8 **, 0x30), s32 *, 0x58) + var_r3_3764);
                }
            }
            var_r5_3763 += 1;
            var_r3_3764 += 4;
            goto loop_26;
        }
    }
    temp_r29_3799 = arg2 & 7;
    if (temp_r29_3799 == 0) {
        if (arg3 != NULL) {
            var_r24_3803 = arg3;
        } else {
            if (MKHeap::Current() != NULL) {
                var_r3_3813 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x10, NULL, 0));
            } else {
                var_r3_3813 = malloc(0x10);
            }
            var_r24_3803 = (MKModelSLW *) var_r3_3813;
        }
        memset(var_r24_3803, 0, 0x10U);
        var_r24_3803->unk5 = (var_r24_3803->unk5 & ~1) | ((u8) (arg3 == NULL) & 1);
        var_r24_3803->unk4 = (var_r24_3803->unk4 & ~0xE0) | ((temp_r29_3799 << 5) & 0xE0);
        var_r24_3803->unk5 |= 0x40;
        var_r24_3803->unk0 = var_r27_3636;
        if ((u8) M2C_FIELD(var_r24_3803->unk0, u8 *, 0x48) != 0) {
            MKGrass_AddModel((MKModel *) var_r24_3803);
        }
        return (MKModel *) var_r24_3803;
    }
    temp_r4_3848 = M2C_FIELD(var_r27_3636, void **, 0x30);
    var_r25_3850 = 0;
    temp_r5_3851 = M2C_FIELD(temp_r4_3848, s16 *, 4);
    var_r26_3854 = ((temp_r5_3851 - 1) * 4) + 0xA0;
    if (arg2 & 0x40) {
        var_r25_3850 = var_r26_3854;
        var_r26_3854 += M2C_FIELD(temp_r4_3848, s16 *, 6) * 4;
    }
    temp_r0_3861 = M2C_FIELD(temp_r4_3848, s16 *, 0xC);
    var_r3_3864 = 0;
    var_r26_3865 = var_r26_3854 + temp_r5_3851 + temp_r5_3851;
    var_ctr_3866 = temp_r0_3861;
    if (temp_r0_3861 > 0) {
loop_40:
        var_r5_3871 = (unsigned short *) (M2C_FIELD(temp_r4_3848, s32 *, 0x60) + var_r3_3864);
        if ((u16) *var_r5_3871 == 8) {

        } else {
            var_r3_3864 += 0x10;
            var_ctr_3866 -= 1;
            if (var_ctr_3866 == 0) {
                goto block_43;
            }
            goto loop_40;
        }
    } else {
block_43:
        var_r5_3871 = NULL;
    }
    M2C_FIELD(var_r27_3636, u16 **, 0x44) = var_r5_3871;
    temp_r3_3883 = M2C_FIELD(var_r27_3636, u16 **, 0x44);
    if (temp_r3_3883 != NULL) {
        var_r26_3865 += M2C_FIELD(temp_r3_3883, s32 *, 8);
    }
    temp_r4_3889 = M2C_FIELD(var_r27_3636, void **, 0x30);
    var_r3_3890 = 0;
    temp_r0_3891 = M2C_FIELD(temp_r4_3889, s16 *, 0xC);
    var_ctr_3892 = temp_r0_3891;
    if (temp_r0_3891 > 0) {
loop_47:
        var_r28_3897 = (unsigned short *) (M2C_FIELD(temp_r4_3889, s32 *, 0x60) + var_r3_3890);
        if ((u16) *var_r28_3897 == 2) {

        } else {
            var_r3_3890 += 0x10;
            var_ctr_3892 -= 1;
            if (var_ctr_3892 == 0) {
                goto block_50;
            }
            goto loop_47;
        }
    } else {
block_50:
        var_r28_3897 = NULL;
    }
    var_r23_3909 = 0;
    if (var_r28_3897 != NULL) {
        temp_r26_3913 = (var_r26_3865 + 0xF) & 0xFFFFFFF0;
        var_r23_3909 = temp_r26_3913;
        var_r26_3865 = (M2C_FIELD(var_r28_3897, s32 *, 8) << 8) + temp_r26_3913 + 0x40;
    }
    if (MKHeap::Current() != NULL) {
        var_r30_3927 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(var_r26_3865, NULL, 0));
    } else {
        var_r30_3927 = malloc(var_r26_3865);
    }
    memset(var_r30_3927, 0, (u32) var_r26_3865);
    M2C_FIELD(var_r30_3927, u8 *, 4) = (u8) ((M2C_FIELD(var_r30_3927, u8 *, 4) & ~0xE0) | ((temp_r29_3799 << 5) & 0xE0));
    M2C_FIELD(var_r30_3927, s8 **, 0x88) = &var_r30_3927[var_r26_3854];
    temp_r3_3943 = M2C_FIELD(var_r27_3636, u16 **, 0x44);
    if (temp_r3_3943 != NULL) {
        var_r5_3946 = M2C_FIELD(temp_r3_3943, s32 *, 8);
    } else {
        var_r5_3946 = 0;
    }
    M2C_FIELD(var_r30_3927, s8 **, 0x8C) = &(&M2C_FIELD(var_r30_3927, s8 **, 0x88)[var_r5_3946])[M2C_FIELD(M2C_FIELD(var_r27_3636, void **, 0x30), s16 *, 4)];
    memset(M2C_FIELD(var_r30_3927, s8 **, 0x8C), -1, (u32) M2C_FIELD(M2C_FIELD(var_r27_3636, void **, 0x30), s16 *, 4));
    if (var_r28_3897 != NULL) {
        temp_r3_3964 = &var_r30_3927[var_r23_3909];
        M2C_FIELD(var_r30_3927, s8 **, 0x84) = temp_r3_3964;
        M2C_FIELD(M2C_FIELD(var_r30_3927, s8 **, 0x84), s8 **, 8) = (s8 *) (temp_r3_3964 + 0x40);
        M2C_FIELD(M2C_FIELD(var_r30_3927, s8 **, 0x84), s32 *, 4) = (s32) M2C_FIELD(var_r28_3897, s32 *, 8);
    }
    M2C_STRUCT_COPY((s32) (var_r30_3927 + 0xC) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_FIELD(var_r30_3927, f32 *, 0x60) = 1.0f;
    M2C_FIELD(var_r30_3927, f32 *, 0x64) = 1.0f;
    M2C_FIELD(var_r30_3927, f32 *, 0x68) = 1.0f;
    M2C_FIELD(var_r30_3927, f32 *, 0x6C) = 1.0f;
    M2C_FIELD(var_r30_3927, f64 *, 0x50) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 0);
    M2C_FIELD(var_r30_3927, f64 *, 0x58) = (f64) M2C_FIELD(&MKVector4::one, f64 *, 8);
    M2C_FIELD(var_r30_3927, s8 **, 0) = var_r27_3636;
    M2C_FIELD(var_r30_3927, s8 **, 0x80) = (s8 *) M2C_FIELD(M2C_FIELD(var_r27_3636, void **, 0x30), s8 **, 0x54);
    M2C_FIELD(var_r30_3927, u8 *, 5) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 5) | 0x40);
    M2C_FIELD(var_r30_3927, u8 *, 4) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 4) | 1);
    if (var_r25_3850 != 0) {
        M2C_FIELD(var_r30_3927, s8 **, 0x80) = &var_r30_3927[var_r25_3850];
        temp_r4_4011 = M2C_FIELD(var_r27_3636, void **, 0x30);
        memcpy(M2C_FIELD(var_r30_3927, s8 **, 0x80), M2C_FIELD(temp_r4_4011, s8 **, 0x54), M2C_FIELD(temp_r4_4011, s16 *, 6) * 4);
    }
    if (arg1 != NULL) {
        M2C_FIELD(var_r30_3927, Animation **, 0x70) = ((Animation *) arg1)->Create(NULL, M2C_ERROR(/* Read from unset register $r5 */));
        M2C_FIELD(var_r30_3927, u8 *, 4) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 4) | 4);
        MKModelInternal_FixUpBlendShapes((MKModel *) var_r30_3927);
    }
    M2C_FIELD(var_r30_3927, u8 *, 5) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 5) | 0x20);
    M2C_FIELD(var_r30_3927, u8 *, 5) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 5) | 0x10);
    M2C_FIELD(var_r30_3927, u8 *, 5) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 5) | 8);
    if ((Animation *) M2C_FIELD(var_r30_3927, Animation **, 0x70) != NULL) {
        M2C_FIELD(var_r30_3927, u8 *, 5) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 5) & ~0x20);
    } else {
        var_r3_4051 = 0;
        temp_r5_4052 = M2C_FIELD(M2C_FIELD(var_r30_3927, s8 **, 0), void **, 0x30);
        temp_r0_4053 = M2C_FIELD(temp_r5_4052, s16 *, 4);
        var_ctr_4054 = temp_r0_4053;
        if (temp_r0_4053 > 0) {
loop_68:
            if ((s16) *(M2C_FIELD(temp_r5_4052, s32 *, 0x50) + (var_r3_4051 + 0x3A)) != -1) {
                M2C_FIELD(var_r30_3927, u8 *, 5) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 5) & ~0x20);
            } else {
                var_r3_4051 += 0x40;
                var_ctr_4054 -= 1;
                if (var_ctr_4054 != 0) {
                    goto loop_68;
                }
            }
        }
    }
    MKModel_SetupCloth((MKModel *) var_r30_3927);
    if ((s8 *) M2C_FIELD(var_r30_3927, s8 **, 0x84) != NULL) {
        gClothManager.AddModel((MKModel *) var_r30_3927);
    }
    gDynamicBones.AddModel((MKModel *) var_r30_3927);
    if ((u8) M2C_FIELD(M2C_FIELD(var_r30_3927, s8 **, 0), u8 *, 0x48) != 0) {
        MKGrass_AddModel((MKModel *) var_r30_3927);
    }
    M2C_FIELD(var_r30_3927, u8 *, 5) = (u8) (M2C_FIELD(var_r30_3927, u8 *, 5) | 1);
    var_r25_4097 = 0;
    var_r23_4098 = 0;
loop_79:
    temp_r3_4118 = M2C_FIELD(M2C_FIELD(var_r30_3927, s8 **, 0), void **, 0x30);
    if (var_r25_4097 < (s16) M2C_FIELD(temp_r3_4118, s16 *, 4)) {
        if (strnicmp(*(M2C_FIELD(temp_r3_4118, s32 *, 0x50) + (var_r23_4098 + 0x30)), "c_", 2) == 0) {
            temp_r3_4109 = M2C_FIELD(var_r30_3927, s8 **, 0x88);
            temp_r3_4109[var_r25_4097] = (u8) temp_r3_4109[var_r25_4097] | 0x4F;
        }
        var_r25_4097 += 1;
        var_r23_4098 += 0x40;
        goto loop_79;
    }
    return (MKModel *) var_r30_3927;
}
#endif

#if 0 // DRAFT: pointer/array required
void MKModelInternal_FixUpBlendShapes(MKModel *arg0) {
    s32 var_r25_4139;
    s32 var_r30_4161;
    s32 var_r31_4140;
    s8 *temp_r24_4160;
    s8 temp_r26_4147;
    s8 var_r23_4159;
    void *temp_r27_4144;
    void *temp_r28_4145;

    var_r25_4139 = 0;
    var_r31_4140 = 0;
    temp_r27_4144 = M2C_FIELD(arg0->unk0, void **, 0x30);
    temp_r28_4145 = M2C_FIELD(arg0->unk70->unk0, void **, 0x28);
    temp_r26_4147 = (s8) M2C_FIELD(temp_r28_4145, u8 *, 8);
loop_8:
    if (var_r25_4139 < MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0)) {
        if ((s32) *(M2C_FIELD(temp_r27_4144, s32 *, 0x50) + (var_r31_4140 + 0x3E)) != 0) {
            var_r23_4159 = 0;
            temp_r24_4160 = MKModel_GetSubObjectName(arg0, (SubObjectType) 0, var_r25_4139);
            var_r30_4161 = 0;
loop_5:
            if (var_r23_4159 < temp_r26_4147) {
                if (stricmp(*(M2C_FIELD(temp_r28_4145, s32 *, 0x1C) + var_r30_4161), temp_r24_4160) != 0) {
                    var_r23_4159 += 1;
                    var_r30_4161 += 0x10;
                    goto loop_5;
                }
            }
            *(arg0->unk8C + var_r25_4139) = var_r23_4159;
        }
        var_r25_4139 += 1;
        var_r31_4140 += 0x40;
        goto loop_8;
    }
}
#endif

void MKModel_DeinitModule() {
    MKModel_DenitModulePlatformSpecific();
}

void MKModel_InitModule() {
    MKModel_InitModulePlatformSpecific();
}

void MKModel_DenitModulePlatformSpecific() {

}
