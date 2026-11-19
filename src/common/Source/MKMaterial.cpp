#include "common/Source/MKMaterial.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/MKResource.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "unplaced_templates.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKMat_MK2_FFTWater.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MatInfo *);                            /* extern */
MKMaterialUpdater *malloc(M2C_UNK);                 /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
extern s8 bMaterialDeiniting;
extern s8 bMaterialIniting;
extern M2C_UNK gMKDefaults;
extern s32 gpCurrentMaterial;
extern void *gpMKMaterialTypeInfoList;
extern MKMaterial *gpMKWhiteMaterial;
extern s32 materialIdCount;
extern s8 materialList;
extern s32 numberOfLoadedMaterials;
extern MatInfo *pMKWhiteMaterialData;
extern Texture *pMKWhiteTexture;
extern s8 *pMatIDTable;
extern MKMaterialUpdater *pMaterialUpdaters;

#if 0 // DRAFT: ')' expected
s32 MKMaterial_GetMaterialIDMask(const char *arg0) {
    s32 var_r30_27;
    s32 var_r31_28;

    if (stricmp"NONE" == 0) {
        return 0;
    }
    var_r30_27 = 0;
    var_r31_28 = 0;
loop_6:
    if (var_r30_27 >= (s32) materialIdCount) {
        return 0;
    }
    if (stricmp(arg0, &pMatIDTable[var_r31_28]) == 0) {
        return 1 << M2C_FIELD(&pMatIDTable[var_r31_28], u8 *, 0x40);
    }
    var_r30_27 += 1;
    var_r31_28 += 0x41;
    goto loop_6;
}
#endif

#if 0 // DRAFT: function call 'MKArchive_Load(const char[19], long *, int, int)' does not
void MKMaterial_InitMaterialIDs() {
    s32 sp8;

    sp8 = 0;
    pMatIDTable = MKArchive_Load("[_lastupdate_].tmp", &sp8, NULL, 0);
    materialIdCount = sp8 / 65;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
s32 StringHash(const char *arg0, int arg1) {
    s8 *var_r4_96;
    u32 temp_r3_95;
    u32 var_ctr_97;
    u32 var_r31_94;
    u8 temp_r0_101;

    var_r31_94 = 0;
    temp_r3_95 = strlen(arg0);
    var_r4_96 = arg0;
    var_ctr_97 = temp_r3_95;
    if (temp_r3_95 > 0U) {
        do {
            temp_r0_101 = (u8) *var_r4_96;
            var_r4_96 += 1;
            var_r31_94 = (var_r31_94 * 0x11) + ((s8) temp_r0_101 | 0x20);
            var_ctr_97 -= 1;
        } while (var_ctr_97 != 0);
    }
    return var_r31_94 % arg1;
}
#endif

void MKMaterial_SetWhite() {
    MKMaterial_SetMaterial(gpMKWhiteMaterial);
}

#if 0 // DRAFT: undefined identifier 'unk4'
void MKMaterialInternal_Update() {
    MKMaterialUpdater *var_r31_140;

    var_r31_140 = pMaterialUpdaters;
loop_2:
    if (var_r31_140 != NULL) {
        var_r31_140->unk4(var_r31_140->unk0, var_r31_140->unk8);
        var_r31_140 = var_r31_140->unk10;
        goto loop_2;
    }
}
#endif

void MKMaterialInternal_RemoveUpdatersForMaterial(MKMaterial *arg0) {
    MKMaterialUpdater *temp_r31_171;
    MKMaterialUpdater *var_r4_167;

    var_r4_167 = pMaterialUpdaters;
loop_4:
    if (var_r4_167 != NULL) {
        temp_r31_171 = var_r4_167->unk10;
        if ((MKMaterial *) var_r4_167->unk0 == arg0) {
            MKMaterialInternal_RemoveUpdater(var_r4_167);
        }
        var_r4_167 = temp_r31_171;
        goto loop_4;
    }
}

#if 0 // DRAFT: undefined identifier 'FreeFromAnyHeap'
void MKMaterialInternal_RemoveUpdater(MKMaterialUpdater *arg0) {
    MKHeap *temp_r3_219;
    MKMaterialUpdater *temp_r3_199;
    MKMaterialUpdater *temp_r3_207;
    MKMaterialUpdater *temp_r3_213;

    if (arg0 == (MKMaterialUpdater *) pMaterialUpdaters) {
        temp_r3_199 = arg0->unk10;
        pMaterialUpdaters = temp_r3_199;
        if (temp_r3_199 != NULL) {
            temp_r3_199->unkC = NULL;
        }
    } else {
        temp_r3_207 = arg0->unkC;
        if (temp_r3_207 != NULL) {
            temp_r3_207->unk10 = arg0->unk10;
        }
        temp_r3_213 = arg0->unk10;
        if (temp_r3_213 != NULL) {
            temp_r3_213->unkC = arg0->unkC;
        }
    }
    temp_r3_219 = arg0->unk8;
    if (temp_r3_219 != NULL) {
        temp_r3_219->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
    }
    arg0->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
}
#endif

#if 0 // DRAFT: identifier 'arg2' redeclared
void MKMaterialInternal_AddUpdater(MKMaterial *arg0, void (*arg2)(MKMaterial *, void *), void *arg2) {
    MKHeap *temp_r3_247;
    MKMaterialUpdater *temp_r0_275;
    MKMaterialUpdater *var_r3_254;
    MKMaterialUpdater *var_r4_265;

    temp_r3_247 = arg0->Current();
    if (temp_r3_247 != NULL) {
        var_r3_254 = ((MKHeap *) (temp_r3_247->Current()))->Alloc(0x14, NULL, 0);
    } else {
        var_r3_254 = malloc(0x14);
    }
    var_r3_254->unk0 = arg0;
    var_r3_254->unk8 = (MKHeap *) arg2;
    var_r3_254->unk4 = (void (*)(MKMaterial *, MKHeap *)) arg1;
    var_r3_254->unk10 = NULL;
    var_r4_265 = pMaterialUpdaters;
    if (var_r4_265 == NULL) {
        pMaterialUpdaters = var_r3_254;
        var_r3_254->unkC = NULL;
        return;
    }
loop_7:
    temp_r0_275 = var_r4_265->unk10;
    if (temp_r0_275 != NULL) {
        var_r4_265 = temp_r0_275;
        goto loop_7;
    }
    var_r4_265->unk10 = var_r3_254;
    var_r3_254->unkC = var_r4_265;
}
#endif

s32 MKMaterialInternal_GetCurrent() {
    return gpCurrentMaterial;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char' to
s8 *MKMaterialInternal_Find(const char *arg0) {
    s8 *var_r31_308;

    var_r31_308 = *(&materialList + (StringHash(arg0, 0x200) * 4));
loop_5:
    if (var_r31_308 == NULL) {
        return NULL;
    }
    if ((stricmp(var_r31_308, arg0) == 0) && (var_r31_308->IsResourceAvailable() != 0)) {
        return var_r31_308;
    }
    var_r31_308 = M2C_FIELD(var_r31_308, s8 **, 0x2C);
    goto loop_5;
}
#endif

void *MKMaterialInternal_GetMaterialTypeInfoFromID(int arg0) {
    void *temp_r4_342;
    void *var_r5_339;

    var_r5_339 = gpMKMaterialTypeInfoList;
loop_4:
    if (var_r5_339 == NULL) {
        return NULL;
    }
    temp_r4_342 = M2C_FIELD(var_r5_339, void **, 0);
    if ((s32) M2C_FIELD(temp_r4_342, s32 *, 4) == arg0) {
        return temp_r4_342;
    }
    var_r5_339 = M2C_FIELD(var_r5_339, void **, 4);
    goto loop_4;
}

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
s32 MKMaterialInternal_GetMaterialTypeIDFromName(const char *arg0) {
    void *var_r31_365;

    var_r31_365 = gpMKMaterialTypeInfoList;
loop_4:
    if (var_r31_365 == NULL) {
        return -1;
    }
    if (stricmp(M2C_FIELD(M2C_FIELD(var_r31_365, void **, 0), s8 **, 0), arg0) == 0) {
        return M2C_FIELD(M2C_FIELD(var_r31_365, void **, 0), s32 *, 4);
    }
    var_r31_365 = M2C_FIELD(var_r31_365, void **, 4);
    goto loop_4;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKMaterialParameter'
s8 MKMaterial_GetParameter(MKMaterial *arg0, MKMaterialParameter arg1) {
    if ((u32) arg1 <= 7U) {
        switch ((s32) arg1) {
        case 0:
            return (s8) M2C_FIELD(arg0->unk24, u8 *, 0xE0);
        case 1:
            return (s8) M2C_FIELD(arg0->unk24, u8 *, 0xE2);
        case 2:
            return (s8) M2C_FIELD(arg0->unk24, u8 *, 0xE3);
        case 3:
            return (s8) M2C_FIELD(arg0->unk24, s32 *, 0x24);
        case 4:
            return (s8) M2C_FIELD(arg0->unk24, u8 *, 0xE5);
        case 5:
            return (s8) M2C_FIELD(arg0->unk24, u8 *, 0xE4);
        case 6:
            return (s8) M2C_FIELD(arg0->unk24, u8 *, 0xE1);
        case 7:
            return (s8) M2C_FIELD(arg0->unk24, u8 *, 0x1DE);
        }
    } else {
        return -1;
    }
}
#endif

MKHeap *MKMaterial_GetName(MKMaterial *arg0) {
    return (MKHeap *) arg0->unk24;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKMaterialParameter'
void MKMaterial_SetParameter(MKMaterial *arg0, MKMaterialParameter arg1, int arg2) {
    if ((u32) arg1 <= 7U) {
        switch ((s32) arg1) {
        case 0:
            M2C_FIELD(arg0->unk24, s8 *, 0xE0) = (s8) arg2;
            MKDirtyState_Dirty((MKDirtyStateType) 5);
            return;
        case 1:
            M2C_FIELD(arg0->unk24, s8 *, 0xE2) = (s8) arg2;
            return;
        case 2:
            M2C_FIELD(arg0->unk24, s8 *, 0xE3) = (s8) arg2;
            return;
        case 3:
            M2C_FIELD(arg0->unk24, s32 *, 0x24) = arg2;
            return;
        case 4:
            M2C_FIELD(arg0->unk24, s8 *, 0xE5) = (s8) arg2;
            return;
        case 5:
            M2C_FIELD(arg0->unk24, s8 *, 0xE4) = (s8) arg2;
            return;
        case 6:
            M2C_FIELD(arg0->unk24, s8 *, 0xE1) = (s8) arg2;
            return;
        case 7:
            M2C_FIELD(arg0->unk24, s8 *, 0x1DE) = (s8) arg2;
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
f64 *MKMaterial_GetColor(MKMaterial *arg0) {
    return arg0->unk24 + 0x30;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void MKMaterial_SetColor(MKMaterial *arg0, const MKVector4 &arg1) {
    void *temp_r5_523;

    temp_r5_523 = arg0->unk24;
    M2C_FIELD(temp_r5_523, f64 *, 0x30) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r5_523, f64 *, 0x38) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    MKDirtyState_Dirty((MKDirtyStateType) 5);
}
#endif

#if 0 // DRAFT: illegal type
void MKMaterial_SetTextureMatrix(MKMaterial *arg0, const Matrix *arg1) {
    M2C_STRUCT_COPY((s32) (arg0->unk24 + 0x3C) + 4, (s32) (arg1 - 4) + 4, 0x40);
    MKDirtyState_Dirty((MKDirtyStateType) 5);
}
#endif

#if 0 // DRAFT: illegal type
void MKMaterial_GetEffectType(MKMaterial *arg0, const char **arg1) {
    if (arg1 != NULL) {
        *arg1 = arg0->unk24 + 0xC0;
    }
    if ((arg0->unk24 + 0xA0) == NULL) {

    }
}
#endif

s32 MKMaterial_GetMaterialID(MKMaterial *arg0) {
    return M2C_FIELD(arg0->unk24, s32 *, 0x1E4);
}

#if 0 // DRAFT: illegal use of non-static member
s8 *MKMaterial::Create(const char *arg0) {
    MKHeap *temp_r3_592;
    MKHeap *temp_r3_634;
    MKMaterialUpdater *var_r31_600;
    MatInfo *temp_r3_627;
    s32 temp_r3_648;
    s8 *temp_r3_616;
    s8 *temp_r3_655;
    u8 temp_r3_619;
    void *temp_r3_650;

    temp_r3_592 = MKHeap::Current();
    if (temp_r3_592 != NULL) {
        var_r31_600 = ((MKHeap *) (temp_r3_592->Current()))->Alloc(0x1EC, NULL, 0);
    } else {
        var_r31_600 = malloc(0x1EC);
    }
    MKMatInfo_Init((MatInfo *) var_r31_600, (s8 *) this);
    temp_r3_616 = Str_Printf("%s.min", this);
    temp_r3_619 = MKArchive_Exists(temp_r3_616, NULL);
    if (temp_r3_619 != 0) {
        temp_r3_619->ActivateTempMemOverride();
        temp_r3_627 = MKArchive_Load(temp_r3_616, NULL, NULL, -1);
        MKMatInfo_Endian(temp_r3_627);
        MKMatInfo_Merge((MatInfo *) var_r31_600, temp_r3_627);
        ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->DeactivateTempMemOverride();
        temp_r3_634 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_634 != NULL) {
            ((MKHeap *) (temp_r3_634->Current()))->Free(temp_r3_627, NULL, 0);
        } else {
            free(temp_r3_627);
        }
    }
    temp_r3_648 = MKMaterialInternal_GetMaterialTypeIDFromName(&var_r31_600->unk1BC);
    temp_r3_650 = MKMaterialInternal_GetMaterialTypeInfoFromID(temp_r3_648);
    temp_r3_655 = M2C_FIELD(temp_r3_650, s8 *(**)(MKMaterialUpdater *, void *), 0x10)(var_r31_600, temp_r3_650);
    strcpy(temp_r3_655, (s8 *) this);
    M2C_FIELD(temp_r3_655, s32 *, 0x30) = temp_r3_648;
    M2C_FIELD(temp_r3_655, void **, 0x34) = MKMaterialInternal_GetMaterialTypeInfoFromID(temp_r3_648);
    return temp_r3_655;
}
#endif

#if 0 // DRAFT: undefined identifier 'StringHash'
void MKMaterial_Destroy(MKMaterial *arg0) {
    M2C_UNK (*temp_r31_717)(MKMaterial *);
    s32 temp_r5_688;
    void *temp_r6_713;
    void *var_r4_691;
    void *var_r6_690;

    arg0->unk28 -= 1;
    if ((s32) arg0->unk28 <= 0) {
        temp_r5_688 = StringHash((s8 *) arg0, 0x200) * 4;
        var_r6_690 = NULL;
        var_r4_691 = *(&materialList + temp_r5_688);
loop_4:
        if (var_r4_691 != NULL) {
            if (var_r4_691 != arg0) {
                var_r6_690 = var_r4_691;
                var_r4_691 = M2C_FIELD(var_r4_691, void **, 0x2C);
                goto loop_4;
            }
        }
        if (var_r6_690 != NULL) {
            M2C_FIELD(var_r6_690, void **, 0x2C) = (void *) M2C_FIELD(var_r4_691, void **, 0x2C);
        } else {
            *(&materialList + temp_r5_688) = M2C_FIELD(var_r4_691, void **, 0x2C);
        }
        MKMaterialInternal_RemoveUpdatersForMaterial(arg0);
        temp_r6_713 = arg0->unk34;
        temp_r31_717 = M2C_FIELD(temp_r6_713, M2C_UNK (**)(MKMaterial *), 0x14);
        arg0->unk24->FreeFromAnyHeap(NULL, NULL, (s32) temp_r6_713);
        if (temp_r31_717 != NULL) {
            temp_r31_717(arg0);
        } else {
            arg0->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
        }
        numberOfLoadedMaterials -= 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'StringHash'
MKResource *MKMaterial_Create(const char *arg0) {
    MKResource *temp_r3_775;
    MKResource *temp_r3_783;
    MKResource *temp_r4_768;
    MKResource *var_r30_756;
    MKResource *var_r31_757;
    s32 temp_ret_761;
    s32 temp_ret_765;
    s8 *var_r4_753;

    var_r4_753 = &materialList;
    var_r30_756 = NULL;
    var_r31_757 = &materialList + (StringHash(arg0, 0x200) * 4);
loop_5:
    if ((MKResource *) var_r31_757->unk0 == NULL) {
        temp_r3_783 = arg0->Create(var_r4_753);
        var_r31_757->unk0 = temp_r3_783;
        temp_r3_783->unk28 = 1;
        temp_r3_783->InitialiseResource();
        if (var_r30_756 != NULL) {
            M2C_FIELD(var_r30_756, MKResource **, 0x2C) = temp_r3_783;
        }
        numberOfLoadedMaterials += 1;
        return temp_r3_783;
    }
    temp_ret_761 = stricmp(arg0);
    var_r4_753 = (s8 *) (u32) (u64) temp_ret_761;
    if (temp_ret_761 == 0) {
        temp_ret_765 = var_r31_757->unk0->IsResourceAvailable();
        var_r4_753 = (s8 *) (u32) (u64) temp_ret_765;
        if (temp_ret_765 != 0) {
            temp_r4_768 = var_r31_757->unk0;
            temp_r4_768->unk28 += 1;
            return var_r31_757->unk0;
        }
    }
    temp_r3_775 = var_r31_757->unk0;
    var_r30_756 = temp_r3_775;
    var_r31_757 = temp_r3_775 + 0x2C;
    goto loop_5;
}
#endif

void MKMaterial_DeinitModule() {
    MKHeap *temp_r3_819;
    MatInfo *temp_r31_818;

    bMaterialDeiniting = 1;
    MKMaterial_Destroy(gpMKWhiteMaterial);
    pMKWhiteTexture->Destroy();
    temp_r31_818 = pMKWhiteMaterialData;
    temp_r3_819 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_819 != NULL) {
        ((MKHeap *) (temp_r3_819->Current()))->Free(temp_r31_818, NULL, 0);
    } else {
        free(temp_r31_818);
    }
    MKMaterial_DeinitModule_PlatformSpecific();
    bMaterialDeiniting = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKMaterial_InitModule() {
    MKHeap *temp_r3_859;
    MKMaterial *temp_r3_889;
    MKMaterialUpdater *var_r3_866;

    bMaterialIniting = 1;
    memset(&materialList, 0, 0x800U);
    MKMaterial_LinkMaterial_MK2_Standard(1U);
    MKMaterial_LinkMaterial_MK2_FFTWater();
    MKMaterial_InitModule_PlatformSpecific();
    temp_r3_859 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_859 != NULL) {
        var_r3_866 = ((MKHeap *) (temp_r3_859->Current()))->Alloc(0x400, NULL, 0);
    } else {
        var_r3_866 = malloc(0x400);
    }
    pMKWhiteMaterialData = (MatInfo *) var_r3_866;
    memset(var_r3_866, 0xFF, 0x400U);
    pMKWhiteTexture = ((Texture *) ("MKWhite"))->CreateFromRawData(&pMKWhiteMaterialData->unk0, NULL, 0x10, 0x10, 0, M2C_ERROR(/* Read from unset register $r9 */));
    temp_r3_889 = MKMaterial_Create"MKWhite";
    gpMKWhiteMaterial = temp_r3_889;
    MKMat_MK2_SetMaterialType(temp_r3_889, (MKMat_MK2_Standard_MaterialType) 3);
    MKMaterial_SetParameter(gpMKWhiteMaterial, (MKMaterialParameter) 0, 0);
    bMaterialIniting = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1E0'
void MKMatInfo_Merge(MatInfo *arg0, MatInfo *arg1) {
    if (arg1->unk1E0 & 1) {
        strcpy((s8 *) &arg0->unk40.unk40, (s8 *) &arg1->unk40.unk40);
        arg0->unk1E4 = arg1->unk1E4;
    }
    if (arg1->unk1E0 & 2) {
        arg0->unk24 = arg1->unk24;
    }
    if (arg1->unk1E0 & 4) {
        arg0->unk28 = arg1->unk28;
    }
    if (arg1->unk1E0 & 8) {
        arg0->unk30 = arg1->unk30;
        arg0->unk38 = arg1->unk38;
    }
    if (arg1->unk1E0 & 0x10) {
        M2C_STRUCT_COPY((s32) (arg0 + 0x3C) + 4, (s32) (arg1 + 0x3C) + 4, 0x40);
    }
    if (arg1->unk1E0 & 0x20) {
        strcpy((s8 *) &arg0->unk40.unk60, (s8 *) &arg1->unk40.unk60);
    }
    if (arg1->unk1E0 & 0x40) {
        strcpy(&arg0->unk40.unk80, &arg1->unk40.unk80);
    }
    if (arg1->unk1E0 & 0x80) {
        arg0->unk2C = arg1->unk2C;
    }
    if (arg1->unk1E0 & 0x100) {
        arg0->unkE0 = arg1->unkE0;
    }
    if (arg1->unk1E0 & 0x200) {
        arg0->unkE1 = arg1->unkE1;
    }
    if (arg1->unk1E0 & 0x400) {
        arg0->unkE2 = arg1->unkE2;
        arg0->unkE3 = arg1->unkE3;
    }
    if (arg1->unk1E0 & 0x800) {
        arg0->unkE4 = (s8) (u8) arg1->unkE4;
    }
    if (arg1->unk1E0 & 0x1000) {
        arg0->unkE5 = arg1->unkE5;
    }
    if (arg1->unk1E0 & 0x2000) {
        arg0->unkE6 = arg1->unkE6;
    }
    if (arg1->unk1E0 & 0x8000) {
        strcpy(&arg0->unkE8.unk0, &arg1->unkE8.unk0);
    }
    if (arg1->unk1E0 & 0x10000) {
        strcpy(&arg0->unkE8.unk20, &arg1->unkE8.unk20);
    }
    if (arg1->unk1E0 & 0x20000) {
        memcpy(&arg0->unkE8.unk40, &arg1->unkE8.unk40, 0xCU);
    }
    if (arg1->unk1E0 & 0x40000) {
        memcpy(&arg0->unkE8.unk4C, &arg1->unkE8.unk4C, 0xCU);
    }
    if (arg1->unk1E0 & 0x80000) {
        memcpy(&arg0->unkE8.unk58, &arg1->unkE8.unk58, 0x10U);
    }
    if (arg1->unk1E0 & 0x100000) {
        memcpy(&arg0->unkE8.unk60.dummy[2], &arg1->unkE8.unk60.dummy[2], 0x10U);
    }
    if (arg1->unk1E0 & 0x200000) {
        memcpy(&arg0->unkE8.unk60.dummy[6], &arg1->unkE8.unk60.dummy[6], 0x10U);
    }
    if (arg1->unk1E0 & 0x400000) {
        memcpy(&arg0->unkE8.unk88, &arg1->unkE8.unk88, 0x24U);
    }
    if (arg1->unk1E0 & 0x800000) {
        arg0->unk174 = arg1->unk174;
    }
    if (arg1->unk1E0 & 0x01000000) {
        M2C_FIELD(arg0, u8 *, 0x198) = (u8) M2C_FIELD(arg1, u8 *, 0x198);
    }
    if (arg1->unk1E0 & 0x04000000) {
        M2C_FIELD(arg0, u8 *, 0x19A) = (u8) M2C_FIELD(arg1, u8 *, 0x19A);
    }
    if (arg1->unk1E0 & 0x02000000) {
        M2C_FIELD(arg0, u8 *, 0x199) = (u8) M2C_FIELD(arg1, u8 *, 0x199);
    }
    if (arg1->unk1E0 & 0x4000) {
        arg0->unkE7 = arg1->unkE7;
    }
    if (arg1->unk1E0 & 0x10000000) {
        strcpy(&arg0->unk1BC, &arg1->unk1BC);
    }
    if (arg1->unk1E0 & 0x40000000) {
        arg0->unk1DC = arg1->unk1DC;
    }
    if (arg1->unk1E0 & 0x80000000) {
        arg0->unk1DD = arg1->unk1DD;
    }
    arg0->unk1DE = 0;
    arg0->unk1E0 = arg1->unk1E0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk20'
void MKMatInfo_Endian(MatInfo *arg0) {
    s32 var_r29_1161;
    s32 var_r29_1173;
    s32 var_r30_1187;
    s32 var_r31_1162;
    s32 var_r31_1174;
    s32 var_r31_1188;
    void *temp_r30_1164;
    void *temp_r30_1176;

    ByteReverse<int unsigned>(arg0->unk20);
    ByteReverse<int>(arg0->unk24);
    ByteReverse<int>(arg0->unk28);
    ByteReverse<float>(arg0->unk2C);
    ByteReverse<float>(*((f32 *) &arg0->unk30));
    ByteReverse<float>(*(arg0 + 0x34));
    ByteReverse<float>(*((f32 *) &arg0->unk38));
    ByteReverse<float>(*(arg0 + 0x3C));
    var_r29_1161 = 0;
    var_r31_1162 = 0;
    do {
        temp_r30_1164 = arg0 + var_r31_1162;
        ByteReverse<float>(*(temp_r30_1164 + 0x128));
        ByteReverse<float>(*(temp_r30_1164 + 0x134));
        var_r29_1161 += 1;
        var_r31_1162 += 4;
    } while (var_r29_1161 < 3);
    var_r29_1173 = 0;
    var_r31_1174 = 0;
    do {
        temp_r30_1176 = arg0 + var_r31_1174;
        ByteReverse<float>(*(temp_r30_1176 + 0x140));
        ByteReverse<float>(*(temp_r30_1176 + 0x150));
        ByteReverse<float>(*(temp_r30_1176 + 0x160));
        var_r29_1173 += 1;
        var_r31_1174 += 4;
    } while (var_r29_1173 < 4);
    var_r30_1187 = 0;
    var_r31_1188 = 0;
    do {
        ByteReverse<float>(*(arg0 + (var_r31_1188 + 0x170)));
        var_r30_1187 += 1;
        var_r31_1188 += 4;
    } while (var_r30_1187 < 9);
    ByteReverse<float>(arg0->unk174);
    ByteReverse<int unsigned>(arg0->unk1E0);
    ByteReverse<int unsigned>(arg0->unk1E4);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void MKMatInfo_Init(MatInfo *arg0, const char *arg1) {
    strcpy(&arg0->unk0, arg1);
    arg0->unk20 = 0;
    arg0->unk24 = 3;
    arg0->unk28 = 3;
    arg0->unk2C = 0.0f;
    arg0->unk30 = M2C_FIELD(&one, f64 *, 0);
    arg0->unk38 = M2C_FIELD(&one, f64 *, 8);
    arg0->unk40.SetIdentity();
    M2C_FIELD(arg0, s8 *, 0x80) = 0;
    arg0->unk1E4 = 0;
    M2C_FIELD(arg0, s8 *, 0xA0) = 0;
    arg0->unk40.unk80 = 0;
    arg0->unkE0 = (u8) M2C_FIELD(&gMKDefaults, s32 *, 0x90);
    arg0->unkE1 = 0;
    arg0->unkE3 = 0;
    arg0->unkE2 = 0;
    arg0->unkE4 = 1;
    arg0->unkE5 = 1;
    arg0->unk1DE = 0;
    arg0->unkE6 = 0;
    arg0->unkE7 = 0;
    strcpy(&arg0->unkE8.unk0, arg1);
    arg0->unkE8.unk20 = 0;
    memset(&arg0->unkE8.unk40, 0, 0xCU);
    memset(&arg0->unkE8.unk4C, 0, 0xCU);
    memset(&arg0->unkE8.unk58, 0, 0x10U);
    memset(&arg0->unkE8.unk60.dummy[2], 0, 0x10U);
    memset(&arg0->unkE8.unk60.dummy[6], 0, 0x10U);
    memset(&arg0->unkE8.unk88, 0, 0x24U);
    arg0->unk174 = 0.0f;
    M2C_FIELD(arg0, s8 *, 0x198) = 0;
    M2C_FIELD(arg0, s8 *, 0x199) = 0;
    M2C_FIELD(arg0, s8 *, 0x19A) = 0;
    M2C_FIELD(arg0, s8 *, 0x19B) = 0;
    M2C_FIELD(arg0, s8 *, 0x19C) = 0;
    strcpy(&arg0->unk1BC, "MK2_Standard");
    arg0->unk1E0 = 0;
    arg0->unk1DC = 0;
    arg0->unk1DD = 0;
    arg0->unk1E8 = 0.0f;
}
#endif
