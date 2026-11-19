#include "common/Source/MKCommonDialogs.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/MKWidgets.h"
#include "common/Source/MKWidgetsInternal.h"
#include <m2c_macros.h>

extern s8 *MKWIDGETTYPE_BUTTON;
extern s8 *MKWIDGETTYPE_COLOR;
extern s8 *MKWIDGETTYPE_FRAME;
extern s8 *MKWIDGETTYPE_IMAGE;
extern s8 *MKWIDGETTYPE_LISTBOX;
extern s8 *MKWIDGETTYPE_LISTITEM;
extern s8 *MKWIDGETTYPE_SLIDER;
extern s8 *MKWIDGETTYPE_WINDOW;
extern s32 MKWidgetIdentityAttributes;
extern ColorEditor gColorEditor;
extern MKWidgetContextMenu gContextMenu;
extern CreateWidgetWindow gCreateWidgetWindow;
extern MaterialEditor gMaterialEditor;
extern MKFont *gpDebugFont;
extern void *pDescriptorList;

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void CreateWidgetWindow::CreateWidgets() {
    f32 sp68;                                       /* compiler-managed */
    f32 sp64;
    f32 sp60;                                       /* compiler-managed */
    f32 sp38;                                       /* compiler-managed */
    f32 sp34;
    f32 sp30;                                       /* compiler-managed */
    M2C_UNK sp2C;
    MKWidgetBoundingVolume sp10;
    f32 sp8;
    void *var_r29_94;

    M2C_STRUCT_COPY((s32) &sp2C + 4, MKWidgetIdentityAttributes - 4 + 4, 0x58);
    this->unk8 = 0;
    placingWidget.unk0 = NULL;
    sp30 = 420.0f;
    sp34 = 20.0f;
    sp38 = 0.0f;
    sp60 = 220.0f;
    sp64 = 400.0f;
    sp68 = 0.0f;
    this->unk0 = MKWidget_Create(MKWIDGETTYPE_WINDOW, "Widget Toolbox", (MKWidgetAttributes *) &sp30, NULL, (s32 (*)(MKWidget *, u32, u32, void *)) &CreateWidgetWindow::CreateWidgetWindowHook, this);
    sp8 = 14.0f;
    MKWidget_SendMessage(this->unk0, 0x6BU, (u32) &sp8);
    MKWidget_GetClientVolume(this->unk0, &sp10);
    sp30 = M2C_FIELD(&zero, f64 *, 0);
    sp38 = M2C_FIELD(&zero, f64 *, 8);
    sp60 = (f64) sp10.unk10;
    sp68 = sp28;
    this->unk4 = MKWidget_Create(MKWIDGETTYPE_LISTBOX, "WidgetList", (MKWidgetAttributes *) &sp30, this->unk0, NULL, NULL);
    MKWidget_EnableFlag(this->unk4, 0x800000U);
    sp60 = 100.0f;
    var_r29_94 = pDescriptorList;
    sp64 = 20.0f;
    sp68 = 0.0f;
loop_4:
    if (var_r29_94 != NULL) {
        if (!(M2C_FIELD(var_r29_94, s32 *, 0x14) & 3)) {
            MKWidget_EnableFlag(MKWidget_Create(MKWIDGETTYPE_BUTTON, M2C_FIELD(var_r29_94, s8 **, 0), (MKWidgetAttributes *) &sp30, this->unk4, (s32 (*)(MKWidget *, u32, u32, void *)) &CreateWidgetWindow::CreateHook, this), 0x400U);
        }
        var_r29_94 = M2C_FIELD(var_r29_94, void **, 0xC);
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
s32 CreateWidgetWindow::CreateHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    MKWidget *temp_r0_143;
    MKWidget *temp_r3_144;

    if (arg0 != (MKWidget *)0x39) {

    } else if ((u16) M2C_FIELD(arg1, u16 *, 4) == 6) {
        MKWidget_SetMouseFocus(M2C_FIELD(arg2, MKWidget **, 0));
        placingWidget.unk0 = (MKWidget *)1U;
        temp_r0_143 = M2C_FIELD(arg1, MKWidget **, 0);
        temp_r3_144 = M2C_FIELD(arg2, MKWidget **, 8);
        if (temp_r0_143 != temp_r3_144) {
            if (temp_r3_144 != NULL) {
                MKWidget_SendMessage(temp_r3_144, 0x64U, 0U);
            }
            M2C_FIELD(arg2, MKWidget **, 8) = (MKWidget *) M2C_FIELD(arg1, MKWidget **, 0);
        } else {
            MKWidget_SendMessage(temp_r0_143, 0x64U, 1U);
        }
    }
    return 1;
}
#endif

#if 0 // DRAFT: illegal operand 'MKWidget *'
s32 CreateWidgetWindow::CreateWidgetWindowHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    f64 spC0;
    f64 spB8;
    f64 sp90;
    f64 sp88;
    M2C_UNK sp84;
    MKWidgetBoundingVolume sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    M2C_UNK sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKWidget *temp_r30_204;
    s32 temp_r30_291;

    switch (arg0) {                                 /* irregular */
    case 48:
        if ((s32) placingWidget.unk0 != 0) {
            MKWidget_ReleaseMouseFocus();
            MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 8), 0x64U, 0U);
            if (arg1 == 1) {
                MKWidget_GetMousePos(&sp58);
                MKWidget_GetSystem((MKWidget *) this);
                MKWidget_GetWidgetUnderPoint(M2C_ERROR(/* Read from unset register $r3 */), sp58);
                temp_r30_204 = M2C_ERROR(/* Read from unset register $r3 */);
                if ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x2C)() != 0) && (MKWidget_IsDescendant(temp_r30_204, M2C_FIELD(arg2, MKWidget **, 0)) == 0) && (temp_r30_204 != (MKWidget *) M2C_FIELD(arg2, MKWidget **, 0))) {
                    M2C_STRUCT_COPY((s32) &sp84 + 4, MKWidgetIdentityAttributes - 4 + 4, 0x58);
                    MKWidget_GetLocalMousePos(temp_r30_204, &sp58);
                    MKVector(0.0f, 0.0f, 0.0f);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    sp20 = sp58.unk8 - sp40;
                    sp10 = 0.0f;
                    sp8 = 80.0f;
                    spC = 32.0f;
                    sp88 = sp18;
                    sp90 = (f64) sp20;
                    spB8 = (f64) sp8;
                    spC0 = (f64) sp10;
                    sp48 = sp18;
                    sp50 = (f64) sp20;
                    sp28 = (f64) sp8;
                    sp30 = (f64) sp10;
                    MKWidget_CreateEditable(*M2C_FIELD(arg2, MKWidget **, 8)->unk4, "Default", (MKWidgetAttributes *) &sp88, temp_r30_204, NULL, NULL);
                    MKWidget_Show(M2C_ERROR(/* Read from unset register $r3 */), 1);
                }
            }
            M2C_FIELD(arg2, MKWidget **, 8) = NULL;
            return 0;
        }
block_13:
    default:
        return 1;
    case 5:
        if ((MKWidget *) M2C_FIELD(arg2, MKWidget **, 4) != NULL) {
            temp_r30_291 = ((s32 (*)()) this->unk0->unkC)();
            MKWidget_GetClientVolume((MKWidget *) this, &sp68);
            MKWidget_Resize(M2C_FIELD(arg2, MKWidget **, 4), *((MKVector3 *) &sp68.unk10));
            return temp_r30_291;
        }
        goto block_13;
    }
}
#endif

void MaterialEditor::Show(MKMaterial *arg0) {
    MKWidget_SendMessage(this->unk4, 0x3E8U, (u32) arg0);
    MKWidget_Show(this->unk4, 1);
    MKWidget_BringToFront(this->unk4);
    MKWidget_SetFocus(this->unk4);
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MaterialEditor::CreateWidgets() {
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp10;
    f32 spC;
    f32 sp8;
    M2C_UNK sp4;
    MKWidget *temp_r3_392;

    M2C_STRUCT_COPY((s32) &sp4 + 4, MKWidgetIdentityAttributes - 4 + 4, 0x58);
    sp8 = 10.0f;
    spC = 10.0f;
    sp10 = 0.0f;
    sp38 = 400.0f;
    sp3C = 300.0f;
    sp40 = 0.0f;
    this->unk4 = MKWidget_Create(MKWIDGETTYPE_WINDOW, "Material Editor", (MKWidgetAttributes *) &sp8, NULL, (s32 (*)(MKWidget *, u32, u32, void *)) &MaterialEditor::MaterialEditorHook, this);
    sp8 = 10.0f;
    spC = 10.0f;
    sp10 = 0.0f;
    sp38 = 130.0f;
    sp3C = 130.0f;
    sp40 = 0.0f;
    temp_r3_392 = MKWidget_Create(MKWIDGETTYPE_COLOR, "MaterialFrame", (MKWidgetAttributes *) &sp8, this->unk4, NULL, NULL);
    MKWidget_DisableFlag(temp_r3_392, 0x100U);
    MKWidget_SendMessage(temp_r3_392, 0x64U, (u32) &zero);
    sp8 = 11.0f;
    spC = 11.0f;
    sp10 = 0.0f;
    sp38 = 128.0f;
    sp3C = 128.0f;
    sp40 = 0.0f;
    this->unk8 = MKWidget_Create(MKWIDGETTYPE_IMAGE, "MatPreview", (MKWidgetAttributes *) &sp8, this->unk4, NULL, NULL);
    sp8 = 150.0f;
    spC = 10.0f;
    sp10 = 0.0f;
    sp38 = 50.0f;
    sp3C = 30.0f;
    sp40 = 0.0f;
    this->unkC = MKWidget_Create(MKWIDGETTYPE_COLOR, "ColorSelect", (MKWidgetAttributes *) &sp8, this->unk4, NULL, NULL);
}
#endif

#if 0 // DRAFT: illegal operand 'MKWidget *'
s32 MaterialEditor::MaterialEditorHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    switch (arg0) {                                 /* irregular */
    case 0x3E8:
        M2C_FIELD(arg2, MKMaterial **, 0) = (MKMaterial *) arg1;
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 8), 0x46U, (u32) M2C_FIELD(arg2, MKMaterial **, 0));
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0xC), 0x64U, (u32) (M2C_FIELD(arg2, MKMaterial **, 0)->unk24 + 0x30));
        break;
    case 0x39:
        if (((u32) M2C_FIELD(arg1, u32 *, 0) == (MKWidget *) M2C_FIELD(arg2, MKWidget **, 0xC)) && ((u16) M2C_FIELD(arg1, u16 *, 4) == 1)) {
            MKMaterial_SetColor(M2C_FIELD(arg2, MKMaterial **, 0), *(M2C_FIELD(arg1, MKVector4 **, 8)));
        }
        break;
    }
    return 1;
}
#endif

void ColorEditor::Show(const MKVector4 &arg0, MKWidget *arg1) {
    MKWidget_SendMessage(this->unk10, 0x3E8U, (u32) &arg0);
    this->unk30 = arg1;
    MKWidget_Show(this->unk10, 1);
    MKWidget_BringToFront(this->unk10);
    MKWidget_SetFocus(this->unk10);
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ColorEditor::CreateWidgets() {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    M2C_UNK spC;
    f32 sp8;

    M2C_STRUCT_COPY((s32) &spC + 4, MKWidgetIdentityAttributes - 4 + 4, 0x58);
    sp10 = 50.0f;
    sp14 = 50.0f;
    sp18 = 0.0f;
    sp40 = 270.0f;
    sp44 = 200.0f;
    sp48 = 0.0f;
    this->unk10 = MKWidget_Create(MKWIDGETTYPE_WINDOW, "Color Selector", (MKWidgetAttributes *) &sp10, NULL, (s32 (*)(MKWidget *, u32, u32, void *)) &ColorEditor::ColorEditorHook, this);
    sp40 = 155.0f;
    sp44 = 155.0f;
    sp48 = 0.0f;
    sp10 = 10.0f;
    sp14 = 10.0f;
    sp18 = 0.0f;
    this->unk14 = MKWidget_Create(MKWIDGETTYPE_FRAME, "Color Wheel", (MKWidgetAttributes *) &sp10, this->unk10, NULL, NULL);
    MKWidget_SendMessage(this->unk14, 0x64U, 2U);
    sp40 = 40.0f;
    sp44 = 30.0f;
    sp48 = 0.0f;
    sp10 = 195.0f;
    sp14 = 10.0f;
    sp18 = 0.0f;
    this->unk18 = MKWidget_Create(MKWIDGETTYPE_COLOR, "Color Display", (MKWidgetAttributes *) &sp10, this->unk10, NULL, NULL);
    MKWidget_DisableFlag(this->unk18, 0x100U);
    sp8 = 1.0f;
    sp40 = 80.0f;
    sp44 = 18.0f;
    sp48 = 0.0f;
    sp10 = 175.0f;
    sp14 = 50.0f;
    sp18 = 0.0f;
    sp50 = 1.0f;
    sp54 = 0.0f;
    sp58 = 0.0f;
    sp5C = 1.0f;
    this->unk1C = MKWidget_Create(MKWIDGETTYPE_SLIDER, "Red", (MKWidgetAttributes *) &sp10, this->unk10, NULL, NULL);
    MKWidget_SendMessage(this->unk1C, 0x67U, (u32) &sp8);
    MKWidget_SendMessage(this->unk1C, 0x64U, (u32) &sp8);
    sp10 = 175.0f;
    sp14 = 70.0f;
    sp18 = 0.0f;
    sp50 = 0.0f;
    sp54 = 1.0f;
    sp58 = 0.0f;
    sp5C = 1.0f;
    this->unk20 = MKWidget_Create(MKWIDGETTYPE_SLIDER, "Green", (MKWidgetAttributes *) &sp10, this->unk10, NULL, NULL);
    MKWidget_SendMessage(this->unk20, 0x67U, (u32) &sp8);
    MKWidget_SendMessage(this->unk20, 0x64U, (u32) &sp8);
    sp10 = 175.0f;
    sp14 = 90.0f;
    sp18 = 0.0f;
    sp50 = 0.0f;
    sp54 = 0.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    this->unk24 = MKWidget_Create(MKWIDGETTYPE_SLIDER, "Blue", (MKWidgetAttributes *) &sp10, this->unk10, NULL, NULL);
    MKWidget_SendMessage(this->unk24, 0x67U, (u32) &sp8);
    MKWidget_SendMessage(this->unk24, 0x64U, (u32) &sp8);
    sp10 = 175.0f;
    sp14 = 110.0f;
    sp18 = 0.0f;
    sp50 = 1.0f;
    sp54 = 1.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    this->unk28 = MKWidget_Create(MKWIDGETTYPE_SLIDER, "Alpha", (MKWidgetAttributes *) &sp10, this->unk10, NULL, NULL);
    MKWidget_SendMessage(this->unk28, 0x67U, (u32) &sp8);
    MKWidget_SendMessage(this->unk28, 0x64U, (u32) &sp8);
    sp40 = 60.0f;
    sp44 = 26.0f;
    sp48 = 0.0f;
    sp10 = 195.0f;
    sp14 = 137.0f;
    sp18 = 0.0f;
    this->unk2C = MKWidget_Create(MKWIDGETTYPE_BUTTON, "OK", (MKWidgetAttributes *) &sp10, this->unk10, NULL, NULL);
}
#endif

#if 0 // DRAFT: illegal operand 'MKWidget *'
s32 ColorEditor::ColorEditorHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    MKWidget *temp_r3_813;
    u16 temp_r6_804;
    u32 temp_r3_825;

    switch (arg0) {                                 /* irregular */
    case 0x3E8:
        gColorEditor.unk0 = M2C_BITWISE(f64, M2C_FIELD(arg1, u32 *, 0));
        gColorEditor.unk8 = M2C_BITWISE(f64, M2C_FIELD(arg1, f32 **, 8));
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x1C), 0x64U, arg2);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x20), 0x64U, arg2 + 4);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x24), 0x64U, arg2 + 8);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x28), 0x64U, arg2 + 0xC);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
        return 0;
    case 0x39:
        temp_r6_804 = M2C_FIELD(arg1, u16 *, 4);
        if ((temp_r6_804 == 6) && ((u32) M2C_FIELD(arg1, u32 *, 0) == (u32) M2C_FIELD(arg2, u32 *, 0x2C))) {
            MKWidget_Show((MKWidget *) this, 0);
            temp_r3_813 = M2C_FIELD(arg2, MKWidget **, 0x30);
            if (temp_r3_813 != NULL) {
                MKWidget_SendMessage(temp_r3_813, 0x64U, arg2);
                MKWidget_SetFocus(M2C_FIELD(arg2, MKWidget **, 0x30));
            }
        } else if (temp_r6_804 == 1) {
            temp_r3_825 = M2C_FIELD(arg1, u32 *, 0);
            if (temp_r3_825 == (MKWidget *) M2C_FIELD(arg2, MKWidget **, 0x1C)) {
                M2C_FIELD(arg2, f32 *, 0) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            } else if (temp_r3_825 == (MKWidget *) M2C_FIELD(arg2, MKWidget **, 0x20)) {
                M2C_FIELD(arg2, f32 *, 4) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            } else if (temp_r3_825 == (MKWidget *) M2C_FIELD(arg2, MKWidget **, 0x24)) {
                M2C_FIELD(arg2, f32 *, 8) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            } else if (temp_r3_825 == (MKWidget *) M2C_FIELD(arg2, MKWidget **, 0x28)) {
                M2C_FIELD(arg2, f32 *, 0xC) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            }
        }
        /* fallthrough */
    default:
        return 1;
    }
}
#endif

void MKWidgetContextMenu::PurgeItems() {
    u32 var_r5_893;

    this->unk0->GetChild(0);
    var_r5_893 = M2C_ERROR(/* Read from unset register $r3 */);
loop_2:
    if (var_r5_893 != 0) {
        MKWidget_SendMessage((MKWidget *) this->unk0, 0x3BU, var_r5_893);
        this->unk0->GetChild(0);
        var_r5_893 = M2C_ERROR(/* Read from unset register $r3 */);
        goto loop_2;
    }
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MKWidgetContextMenu::AddItem(const char *arg0) {
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    M2C_UNK sp8;
    M2C_UNK sp4;

    M2C_STRUCT_COPY((s32) &sp4 + 4, MKWidgetIdentityAttributes - 4 + 4, 0x58);
    sp38 = 300.0f;
    sp3C = 15.0f;
    sp40 = 0.0f;
    MKWidget_Create(MKWIDGETTYPE_LISTITEM, arg0, (MKWidgetAttributes *) &sp8, (MKWidget *) this->unk0, NULL, NULL);
}
#endif

#if 0 // DRAFT: identifier 'arg1' redeclared
void MKWidgetContextMenu::Show(void (*arg1)(int, void *), void *arg1) {
    MKVector3 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
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
    MKFont *var_r30_980;
    MKWidget *temp_r28_976;
    f32 temp_f0_1001;
    f32 temp_f0_1014;
    f32 temp_f31_996;
    f32 var_f2_1047;
    f32 var_f30_967;
    f32 var_f3_1057;
    s32 temp_r31_968;
    s32 var_r29_969;

    this->unk4 = arg0;
    this->unk8 = arg1;
    var_f30_967 = 0.0f;
    temp_r31_968 = MKWidget_SendMessage((MKWidget *) this->unk0, 0x3CU, 0U);
    var_r29_969 = 0;
loop_13:
    if (var_r29_969 < temp_r31_968) {
        this->unk0->GetChild(var_r29_969);
        temp_r28_976 = M2C_ERROR(/* Read from unset register $r3 */);
        if (MKWidget_IsType(M2C_ERROR(/* Read from unset register $r3 */), MKWIDGETTYPE_LISTITEM) != 0) {
            var_r30_980 = M2C_FIELD(temp_r28_976, MKFont **, 0x50);
            if (var_r30_980 != NULL) {

            } else {
                var_r30_980 = gpDebugFont;
            }
            if ((s8 *) M2C_FIELD(M2C_FIELD(temp_r28_976, void **, 0x2C), s8 **, 0x68) != NULL) {
                temp_f31_996 = var_r30_980->GetScale(M2C_FIELD(temp_r28_976->unk4, f32 *, 0x3C));
                temp_f0_1001 = (temp_f31_996 * var_r30_980->CalcLength(M2C_FIELD(M2C_FIELD(temp_r28_976, void **, 0x2C), s8 **, 0x68))) + 6.0f;
                if (var_f30_967 > temp_f0_1001) {

                } else {
                    var_f30_967 = temp_f0_1001;
                }
            }
        } else {
            MKWidget_GetSize(temp_r28_976, &sp88);
            temp_f0_1014 = 4.0f + M2C_BITWISE(f32, sp88);
            if (var_f30_967 > temp_f0_1014) {

            } else {
                var_f30_967 = temp_f0_1014;
            }
        }
        var_r29_969 += 1;
        goto loop_13;
    }
    this->unk0->GetChildrenRange(&sp78, &sp68);
    sp8 = var_f30_967;
    sp10 = 0.0f;
    spC = 4.0f + sp68.unk4;
    sp50 = (f64) sp10;
    sp48 = (f64) sp8;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    MKWidget_Resize((MKWidget *) this->unk0, *((MKVector3 *) &sp48));
    MKWidget_GetMousePos(&sp58);
    var_f2_1047 = sp58.unk4;
    if ((var_f2_1047 + unksp4C) < 512.0f) {

    } else {
        var_f2_1047 -= unksp4C;
    }
    var_f3_1057 = M2C_BITWISE(f32, sp58);
    if ((var_f3_1057 + (f32) sp48) < 640.0f) {

    } else {
        var_f3_1057 -= (f32) sp48;
    }
    sp18 = var_f3_1057;
    sp1C = var_f2_1047;
    sp20 = 0.0f;
    sp28 = (f64) sp18;
    sp30 = (f64) sp20;
    MKWidget_Move((MKWidget *) this->unk0, *((MKVector3 *) &sp28));
    MKWidget_Show((MKWidget *) this->unk0, 1);
    MKWidget_BringToFront((MKWidget *) this->unk0);
    MKWidget_SetFocus((MKWidget *) this->unk0);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MKWidgetContextMenu::CreateWidgets() {
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    M2C_UNK sp8;
    M2C_UNK sp4;

    M2C_STRUCT_COPY((s32) &sp4 + 4, MKWidgetIdentityAttributes - 4 + 4, 0x58);
    sp38 = 100.0f;
    sp3C = 100.0f;
    sp40 = 0.0f;
    this->unk0 = MKWidget_Create(MKWIDGETTYPE_LISTBOX, "ContextMenu", (MKWidgetAttributes *) &sp8, NULL, (s32 (*)(MKWidget *, u32, u32, void *)) &MKWidgetContextMenu::ContextMenuHook, this);
    MKWidget_SendMessage((MKWidget *) this->unk0, 0x64U, 1U);
    MKWidget_DisableFlag((MKWidget *) this->unk0, 0x18000U);
    MKWidget_EnableFlag((MKWidget *) this->unk0, 0xC00000U);
    MKWidget_Show((MKWidget *) this->unk0, 0);
}
#endif

#if 0 // DRAFT: illegal operand 'MKWidget *'
s32 MKWidgetContextMenu::ContextMenuHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    switch (arg0) {                                 /* irregular */
    case 0x1F:
        if (arg1 == 0) {
            MKWidget_Show((MKWidget *) this, 0);
        }
        break;
    case 0x39:
        if ((MKWidget_IsType(M2C_FIELD(arg1, MKWidget **, 0), MKWIDGETTYPE_LISTITEM) != 0) && ((u16) M2C_FIELD(arg1, u16 *, 4) == 2)) {
            if (((M2C_UNK (*)()) M2C_FIELD(arg2, M2C_UNK (**)(), 4)) != NULL) {
                ((MKWidgetContainer *) (M2C_FIELD(arg2, MKWidgetContainer **, 0)))->GetChildIndex(M2C_FIELD(arg1, MKWidget **, 0));
                M2C_FIELD(arg2, M2C_UNK (**)(), 4)();
            }
            MKWidget_Show((MKWidget *) this, 0);
        }
        break;
    }
    return 1;
}
#endif

void MKCommonDialogs_InitModule() {
    gContextMenu.CreateWidgets();
    gColorEditor.CreateWidgets();
    gMaterialEditor.CreateWidgets();
    gCreateWidgetWindow.CreateWidgets();
}
