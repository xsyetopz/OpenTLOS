#ifndef COMMON_SOURCE_MKCOMMONDIALOGS_H
#define COMMON_SOURCE_MKCOMMONDIALOGS_H

#include <dolphin/types.h>

class ColorEditor;
class CreateWidgetWindow;
class MKMaterial;
class MKVector4;
class MKWidget;
class MKWidgetContainer;
class MKWidgetContextMenu;
class MaterialEditor;

class ColorEditor {
public:
    void Show(const MKVector4 &, MKWidget *);
    void CreateWidgets(void);
    s32 ColorEditorHook(MKWidget *, unsigned int, unsigned int, void *);
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ MKWidget* unk10;
    /* 0x014 */ MKWidget* unk14;
    /* 0x018 */ MKWidget* unk18;
    /* 0x01c */ MKWidget* unk1C;
    /* 0x020 */ MKWidget* unk20;
    /* 0x024 */ MKWidget* unk24;
    /* 0x028 */ MKWidget* unk28;
    /* 0x02c */ MKWidget* unk2C;
    /* 0x030 */ MKWidget* unk30;
};

class CreateWidgetWindow {
public:
    void CreateWidgets(void);
    s32 CreateHook(MKWidget *, unsigned int, unsigned int, void *);
    s32 CreateWidgetWindowHook(MKWidget *, unsigned int, unsigned int, void *);
    static u8 placingWidget[0x4];
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ MKWidget* unk4;
    /* 0x008 */ s32 unk8;
};

class MKWidgetContextMenu {
public:
    void PurgeItems(void);
    void AddItem(const char *);
    void Show(void (*)(int, void *), void *);
    void CreateWidgets(void);
    s32 ContextMenuHook(MKWidget *, unsigned int, unsigned int, void *);
    /* 0x000 */ MKWidgetContainer* unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ void* unk8;
};

class MaterialEditor {
public:
    void Show(MKMaterial *);
    void CreateWidgets(void);
    s32 MaterialEditorHook(MKWidget *, unsigned int, unsigned int, void *);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ MKWidget* unk4;
    /* 0x008 */ MKWidget* unk8;
    /* 0x00c */ MKWidget* unkC;
};

void MKCommonDialogs_InitModule(void);
extern ColorEditor gColorEditor;
extern MaterialEditor gMaterialEditor;
extern CreateWidgetWindow gCreateWidgetWindow;
extern MKWidgetContextMenu gContextMenu;
#endif  // COMMON_SOURCE_MKCOMMONDIALOGS_H
