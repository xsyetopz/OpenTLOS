#include "common/Source/MKWidgets.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/MKWidgetsInternal.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/MKCommonDialogs.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

s8 *malloc(M2C_UNK);                                /* extern */
s32 stricmp(s32, s8 *);                             /* extern */
extern MKWidgetAttributes *MKWidgetIdentityAttributes;
extern M2C_UNK gDisplay;
#if 0 // DRAFT: identifier 'gMKWidgetMetrics' redeclared was declared as: 'unsigned char[736]' now declared as: 'long'
extern M2C_UNK gMKWidgetMetrics;
#endif
extern f32 gWidgetOrthoHeight;
extern f32 gWidgetOrthoWidth;
extern s8 *pBlankData;
#if 0 // DRAFT: identifier 'pDescriptorList' redeclared was declared as: 'MKWidgetDescriptor *' now declared as: 'void *'
extern void *pDescriptorList;
#endif
extern void **pMKWidgetSystem;
#if 0 // DRAFT: identifier 'pWidgetBlank' redeclared was declared as: 'MKMaterial *' now declared as: 'MKResource *'
extern MKResource *pWidgetBlank;
#endif
extern u32 systemStackDepth;
#if 0 // DRAFT: identifier 'pSystemStack' redeclared was declared as: 'unsigned char[64]' now declared as: 'MKWidgetSystem *[16]'
static MKWidgetSystem *pSystemStack[0x10] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};
#endif

f32 MKWidget_GetMetricF(int arg0) {
    return *(f32 *) (gMKWidgetMetrics + (arg0 * 0x10));
}

void *MKWidget_GetMetric(int arg0) {
    return &gMKWidgetMetrics + (arg0 * 0x10);
}

void MKWidget_SetUserData(MKWidget *arg0, void *arg1) {
    MKWidget_SendMessage(arg0, 0xFU, (u32) arg1);
}

void MKWidget_SetCustomMessageHook(MKWidget *arg0, int (*arg1)(MKWidget *, unsigned int, unsigned int, void *)) {
    MKWidget_SendMessage(arg0, 0xEU, (u32) arg1);
}

void MKWidget_GetWidgetUnderPoint(MKWidgetSystem *arg0, const MKVector3 &arg1) {
    arg0->GetWidgetUnderPoint(arg1);
}

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to 'double'
f32 MKWidget_GetLocalMousePos(MKWidget *arg0, MKVector3 *arg1) {
    Matrix sp10;
    f32 temp_f28_110;
    f64 temp_f1_123;
    f64 temp_f2_117;

    MKWidget_GetMousePos(arg1);
    arg0->GetLocalToWorldMatrix(&sp10);
    sp10.Inverse(&sp10);
    temp_f28_110 = arg1->unk8;
    temp_f2_117 = M2C_FIELD(arg1, f64 *, 0);
    temp_f1_123 = M2C_BITWISE(f64, sp10);
    arg1->unk8 = (f32) (((f64) sp10.unk8 * temp_f2_117) + (((f64) sp10.unk18 * temp_f2_117) + (((f64) sp10.unk28 * (f64) temp_f28_110) + (f64) sp10.unk38)));
    M2C_FIELD(arg1, f64 *, 0) = (f64) ((temp_f1_123 * temp_f2_117) + (((f64) sp10.unk10 * temp_f2_117) + (((f64) sp10.unk20 * (f64) temp_f28_110) + (f64) sp10.unk30)));
    return (f32) temp_f1_123;
}
#endif

void MKWidget_BringToFront(MKWidget *arg0) {
    MKWidget *temp_r3_151;

    temp_r3_151 = arg0->unk18;
    if (temp_r3_151 != NULL) {
        MKWidget_SendMessage(temp_r3_151, 0x3EU, (u32) arg0);
    }
}

MKWidget *MKWidget_GetFocus() {
    return M2C_FIELD(MKWidget_GetCurrentSystem(), MKWidget **, 0x4C);
}

void MKWidget_GetMousePos(MKVector3 *arg0) {
    arg0->unk0 = (f32) (s32) ((gWidgetOrthoWidth / M2C_FIELD(&gDisplay, f32 *, 0x68)) * MKInput_GetState(8, (MKInputDevices) 6, NULL, NULL));
    arg0->unk4 = (f32) (s32) ((gWidgetOrthoHeight / M2C_FIELD(&gDisplay, f32 *, 0x6C)) * MKInput_GetState(9, (MKInputDevices) 6, NULL, NULL));
    arg0->unk8 = 0.0f;
}

MKWidget *MKWidget_ReleaseMouseFocus() {
    MKWidget *temp_r31_246;

    temp_r31_246 = M2C_FIELD(MKWidget_GetCurrentSystem(), MKWidget **, 0x54);
    if (temp_r31_246 != NULL) {
        MKWidget_SendMessage(temp_r31_246, 0x21U, 0U);
    }
    return temp_r31_246;
}

MKWidget *MKWidget_SetMouseFocus(MKWidget *arg0) {
    MKWidget *temp_r31_271;

    MKWidget_GetSystem(arg0);
    temp_r31_271 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), MKWidget **, 0x54);
    if (temp_r31_271 != NULL) {
        MKWidget_SendMessage(temp_r31_271, 0x21U, 0U);
    }
    MKWidget_SendMessage(arg0, 0x21U, 1U);
    return temp_r31_271;
}

MKWidget *MKWidget_SetFocus(MKWidget *arg0) {
    MKWidget *sp8;
    MKWidget *temp_r0_300;
    MKWidget *temp_r30_304;

    sp8 = arg0;
    MKWidget_GetSystem(arg0);
    temp_r0_300 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r30_304 = M2C_FIELD(temp_r0_300, MKWidget **, 0x4C);
    MKWidget_SendMessage(arg0, 0x22U, (u32) &sp8);
    if ((sp8 == NULL) || (temp_r30_304 == sp8)) {
        return NULL;
    }
    sp8->unk20 = 0;
    MKWidget_SendMessage(sp8, 0x23U, 0U);
    MKWidget_SendMessage(sp8, 0x25U, 1U);
    if (temp_r30_304 != NULL) {
        MKWidget_SendMessage(temp_r30_304, 0x25U, 0U);
        MKWidget_SendMessage(temp_r30_304, 0x20U, 0U);
        MKWidget_SendMessage(temp_r30_304, 0x24U, 0U);
    } else {
        MKWidget_SendMessage(temp_r0_300, 0x24U, 1U);
    }
    MKWidget_SendMessage(sp8, 0x20U, 1U);
    return temp_r30_304;
}

void MKWidget_GetNumChildren(MKWidget *arg0) {
    MKWidget_SendMessage(arg0, 0x3CU, 0U);
}

void MKWidget_DisableFlag(MKWidget *arg0, unsigned int arg1) {
    MKWidget_SendMessage(arg0, 0x1EU, arg1);
}

void MKWidget_EnableFlag(MKWidget *arg0, unsigned int arg1) {
    MKWidget_SendMessage(arg0, 0x1DU, arg1);
}

void MKWidget_SetFlags(MKWidget *arg0, unsigned int arg1) {
    MKWidget_SendMessage(arg0, 0x1BU, arg1);
}

void MKWidget_Show(MKWidget *arg0, int arg1) {
    MKWidget_SendMessage(arg0, 0x19U, (u32) arg1);
}

void MKWidget_GetBoundingVolume(MKWidget *arg0, MKWidgetBoundingVolume *arg1) {
    MKWidget_SendMessage(arg0, 0x11U, (u32) arg1);
}

void MKWidget_GetClientVolume(MKWidget *arg0, MKWidgetBoundingVolume *arg1) {
    MKWidget_SendMessage(arg0, 0x12U, (u32) arg1);
}

void MKWidget_GetSize(MKWidget *arg0, MKVector3 *arg1) {
    MKWidget_SendMessage(arg0, 0xAU, (u32) arg1);
}

void MKWidget_GetPos(MKWidget *arg0, MKVector3 *arg1) {
    MKWidget_SendMessage(arg0, 9U, (u32) arg1);
}

void MKWidget_SetColor(MKWidget *arg0, const MKVector4 &arg1) {
    MKWidget_SendMessage(arg0, 8U, (u32) &arg1);
}

void MKWidget_Scale(MKWidget *arg0, const MKVector3 &arg1) {
    MKWidget_SendMessage(arg0, 6U, (u32) &arg1);
}

void MKWidget_Resize(MKWidget *arg0, const MKVector3 &arg1) {
    MKWidget_SendMessage(arg0, 5U, (u32) &arg1);
}

void MKWidget_Move(MKWidget *arg0, const MKVector3 &arg1) {
    MKWidget_SendMessage(arg0, 4U, (u32) &arg1);
}

void MKWidget_SetName(MKWidget *arg0, const char *arg1) {
    MKWidget_SendMessage(arg0, 0x14U, (u32) arg1);
}

u8 MKWidget_IsDescendant(MKWidget *arg0, MKWidget *arg1) {
    MKWidget *var_r3_0;

    var_r3_0 = arg0;
loop_3:
    var_r3_0 = var_r3_0->unk18;
    if (var_r3_0 == NULL) {
        return 0U;
    }
    if (var_r3_0 == arg1) {
        return 1U;
    }
    goto loop_3;
}

s32 MKWidget_IsType(MKWidget *arg0, const char *arg1) {
    void *var_r31_595;

    var_r31_595 = arg0->unkC;
loop_4:
    if (var_r31_595 == NULL) {
        return 0;
    }
    if (strcmp(arg1, (const char *) M2C_FIELD(var_r31_595, s8 **, 0)) == 0) {
        return 1;
    }
    var_r31_595 = M2C_FIELD(var_r31_595, void **, 8);
    goto loop_4;
}

void MKWidget_GetSystem(MKWidget *arg0) {
    MKWidget *temp_r0_626;
    MKWidget *var_r3_0;

    var_r3_0 = arg0;
loop_2:
    temp_r0_626 = var_r3_0->unk18;
    if (temp_r0_626 != NULL) {
        var_r3_0 = temp_r0_626;
        goto loop_2;
    }
}

s32 MKWidget_SendMessage(MKWidget *arg0, unsigned int arg1, unsigned int arg2) {
    u32 temp_r12_642;

    temp_r12_642 = arg0->unk10;
    if ((temp_r12_642 != 0) && (((s32 (*)(s32)) temp_r12_642)(arg0->unk14) == 0)) {
        return 0;
    }
    return arg0->MessageHandler(arg1, arg2);
}

#if 0 // DRAFT: identifier 'arg5' redeclared
void MKWidget_CreateEditable(const char *arg0, const char *arg1, const MKWidgetAttributes *arg2, MKWidget *arg3, int (*arg5)(MKWidget *, unsigned int, unsigned int, void *), void *arg5) {
    s32 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;                                       /* compiler-managed */
    f64 sp58;
    f32 sp50;                                       /* compiler-managed */
    f64 sp48;
    M2C_UNK sp44;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKWidget *temp_r3_760;
    MKWidgetAttributes *var_r28_675;
    f32 temp_f1_727;
    f32 temp_f4_738;
    f64 temp_f2_722;

    var_r28_675 = (MKWidgetAttributes *) (arg2);
    if (var_r28_675 == NULL) {
        var_r28_675 = MKWidgetIdentityAttributes;
    }
    M2C_STRUCT_COPY((s32) &sp44 + 4, (s32) (var_r28_675 - 4) + 4, 0x58);
    sp18 = 4.0f;
    sp1C = 4.0f;
    sp20 = 0.0f;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp48 -= sp38;
    sp10 = 0.0f;
    sp8 = 8.0f;
    spC = 8.0f;
    sp50 -= (f32) sp40;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    temp_f2_722 = sp78 + sp28;
    sp78 = temp_f2_722;
    temp_f1_727 = sp80 + (f32) sp30;
    sp80 = temp_f1_727;
    sp78 = temp_f2_722 * sp58;
    temp_f4_738 = temp_f1_727 * sp60;
    sp80 = temp_f4_738;
    sp58 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    sp60 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp88 = M2C_FIELD(&MKVector4::one, f64 *, 0);
    sp90 = M2C_FIELD(&MKVector4::one, f64 *, 8);
    temp_r3_760 = MKWidget_Create("MKWidgetEditable", Str_Printf("%s Editable", arg1, &MKVector3::one, M2C_FIELD(&MKVector4::one, f64 *, 0), M2C_FIELD(&MKVector3::one, f64 *, 8), M2C_FIELD(&MKVector3::one, f64 *, 0), temp_f4_738), (MKWidgetAttributes *) &sp48, arg3, NULL, NULL);
    M2C_FIELD(temp_r3_760, s32 (**)(MKWidget *, u32, u32, void *), 0x60) = arg4;
    M2C_FIELD(temp_r3_760, void **, 0x64) = arg5;
    sp48 = var_r28_675->unk0;
    sp50 = var_r28_675->unk8;
    sp58 = var_r28_675->unk10;
    sp60 = var_r28_675->unk18;
    sp68 = var_r28_675->unk20;
    sp70 = var_r28_675->unk28;
    sp78 = var_r28_675->unk30;
    sp80 = var_r28_675->unk38;
    sp88 = var_r28_675->unk40;
    sp90 = var_r28_675->unk48;
    sp98 = var_r28_675->unk50;
    sp48 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp50 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    MKWidget_Create(arg0, arg1, (MKWidgetAttributes *) &sp48, temp_r3_760, (s32 (*)(MKWidget *, u32, u32, void *)) &MKWidgetEditable::EditableMessageHook, temp_r3_760);
}
#endif

void MKWidget_Destroy(MKWidget *arg0) {
    MKWidget *temp_r29_815;
    MKWidget *temp_r3_814;
    u8 var_r31_818;

    temp_r3_814 = MKWidget_GetFocus();
    temp_r29_815 = arg0->unk18;
    var_r31_818 = 0;
    if ((MKWidget_IsDescendant(temp_r3_814, arg0) != 0) || (temp_r3_814 == arg0)) {
        var_r31_818 = 1;
    }
    if (var_r31_818 != 0) {
        if (temp_r29_815->unk20 == (u32) arg0) {
            temp_r29_815->unk20 = 0;
        }
        MKWidget_SendMessage(temp_r3_814, 0x20U, 0U);
        MKWidget_SendMessage(temp_r29_815, 0x20U, 1U);
    }
    MKWidget_SendMessage(arg0, 3U, 0U);
}

#if 0 // DRAFT: identifier 'arg5' redeclared
MKWidget *MKWidget_Create(const char *arg0, const char *arg1, const MKWidgetAttributes *arg2, MKWidget *arg3, int (*arg5)(MKWidget *, unsigned int, unsigned int, void *), void *arg5) {
    MKWidget *temp_r3_886;
    MKWidget *var_r28_862;
    MKWidgetAttributes *var_r27_865;
    s8 **temp_r3_900;
    void *var_r31_876;

    var_r28_862 = arg3;
    var_r27_865 = (MKWidgetAttributes *) (arg2);
    if (var_r28_862 == NULL) {
        var_r28_862 = MKWidget_GetCurrentSystem();
    }
    if (var_r27_865 == NULL) {
        var_r27_865 = MKWidgetIdentityAttributes;
    }
    var_r31_876 = pDescriptorList;
loop_14:
    if (var_r31_876 == NULL) {
        return NULL;
    }
    if (stricmp(M2C_FIELD(var_r31_876, s32 *, 0), arg0) == 0) {
        temp_r3_886 = M2C_FIELD(var_r31_876, MKWidget *(**)(), 0x10)();
        temp_r3_886->unkC = var_r31_876;
        MKWidget_SetUserData(temp_r3_886, arg5);
        MKWidget_SetCustomMessageHook(temp_r3_886, arg4);
        if ((u8) temp_r3_886->unk8 == 0) {
            if (var_r27_865 != (MKWidgetAttributes *) MKWidgetIdentityAttributes) {
                temp_r3_900 = temp_r3_886->unk4;
                M2C_FIELD(temp_r3_900, f64 *, 8) = (f64) var_r27_865->unk0;
                M2C_FIELD(temp_r3_900, f64 *, 0x10) = (f64) var_r27_865->unk8;
                M2C_FIELD(temp_r3_900, f64 *, 0x18) = (f64) var_r27_865->unk10;
                M2C_FIELD(temp_r3_900, f64 *, 0x20) = (f64) var_r27_865->unk18;
                M2C_FIELD(temp_r3_900, f64 *, 0x28) = (f64) var_r27_865->unk20;
                M2C_FIELD(temp_r3_900, f64 *, 0x30) = (f64) var_r27_865->unk28;
                M2C_FIELD(temp_r3_900, f64 *, 0x38) = (f64) var_r27_865->unk30;
                M2C_FIELD(temp_r3_900, f64 *, 0x40) = (f64) var_r27_865->unk38;
                M2C_FIELD(temp_r3_900, f64 *, 0x48) = (f64) var_r27_865->unk40;
                M2C_FIELD(temp_r3_900, f64 *, 0x50) = (f64) var_r27_865->unk48;
                M2C_FIELD(temp_r3_900, s32 *, 0x58) = (s32) var_r27_865->unk50;
            }
            MKWidget_SendMessage(temp_r3_886, 1U, 0U);
            MKWidget_SetName(temp_r3_886, arg1);
            MKWidget_Move(temp_r3_886, *((MKVector3 *) var_r27_865));
            MKWidget_Resize(temp_r3_886, *((MKVector3 *) &var_r27_865->unk30));
            MKWidget_Scale(temp_r3_886, *((MKVector3 *) &var_r27_865->unk10));
            MKWidget_SetColor(temp_r3_886, *((MKVector4 *) &var_r27_865->unk40));
            MKWidget_SendMessage(temp_r3_886, 2U, 0U);
        }
        if (!(var_r27_865->unk50 & 1)) {
            MKWidget_SendMessage(var_r28_862, 0x3AU, (u32) temp_r3_886);
        }
        return temp_r3_886;
    }
    var_r31_876 = M2C_FIELD(var_r31_876, void **, 0xC);
    goto loop_14;
}
#endif

void MKWidget_PushCurrentSystem(MKWidgetSystem *arg0) {
    pSystemStack[systemStackDepth] = (unsigned char) (arg0);
    systemStackDepth += 1;
}

MKWidget *MKWidget_GetCurrentSystem() {
    if ((u32) systemStackDepth != 0) {
        return M2C_FIELD(&pSystemStack[systemStackDepth], MKWidget **, -4);
    }
    return NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKWidgetSystem' to 'MKWidgetSystem *'
MKWidgetSystem *MKWidget_CreateSystem() {
    MKWidgetSystem *var_r31_1013;

    operator new(0x80U, NULL, 0);
    var_r31_1013 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r31_1013 != NULL) {
        var_r31_1013 = ((MKWidgetSystem *) (M2C_ERROR(/* Read from unset register $r3 */)))->MKWidgetSystem((MKWidgetDescriptor *) MKWidgetSystem::sMKWidgetSystemDescriptor);
    }
    M2C_FIELD(var_r31_1013->unk4, f32 *, 0x38) = (f32) gWidgetOrthoWidth;
    M2C_FIELD(var_r31_1013->unk4, f32 *, 0x3C) = (f32) gWidgetOrthoHeight;
    var_r31_1013->CreateInputReceiver(1U);
    return var_r31_1013;
}
#endif

void MKWidget_Update() {
    M2C_FIELD(*pMKWidgetSystem, M2C_UNK (**)(void **), 0x1C)(pMKWidgetSystem);
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
void MKWidget_CreateMaterial() {
    s8 *temp_r31_1088;
    s8 *var_r3_1068;

    if (MKHeap::Current() != NULL) {
        var_r3_1068 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x1000, NULL, 0));
    } else {
        var_r3_1068 = malloc(0x1000);
    }
    pBlankData = var_r3_1068;
    memset(var_r3_1068, 0xFF, 0x1000U);
    temp_r31_1088 = (const char *) (((Texture *) "WidgetBlank")->CreateFromRawData(pBlankData, NULL, 0x20, 0x20, 0, M2C_ERROR(/* Read from unset register $r9 */)));
    pWidgetBlank = (MKMaterial *) (MKMaterial_Create("WidgetBlank"));
    ((Texture *) temp_r31_1088)->Destroy();
    MKMat_MK2_SetMaterialType((MKMaterial *) pWidgetBlank, (MKMat_MK2_Standard_MaterialType) 3);
    MKCommonDialogs_InitModule();
}
#endif

void MKWidget_InitModule() {
    void **temp_r3_1130;

    gWidgetOrthoWidth = (f32) M2C_FIELD(&gDisplay, s32 *, 0x10);
    gWidgetOrthoHeight = (f32) M2C_FIELD(&gDisplay, s32 *, 0x14);
    temp_r3_1130 = (void **) (MKWidget_CreateSystem());
    pMKWidgetSystem = temp_r3_1130;
    MKWidget_PushCurrentSystem((MKWidgetSystem *) temp_r3_1130);
}
