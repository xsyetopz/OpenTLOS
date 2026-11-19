#ifndef COMMON_SOURCE_MKWIDGETS_H
#define COMMON_SOURCE_MKWIDGETS_H

#include <dolphin/types.h>

class MKVector3;
class MKVector4;
class MKWidget;
class MKWidgetAttributes;
class MKWidgetBoundingVolume;
class MKWidgetDescriptor;
class MKWidgetSystem;

class MKWidgetAttributes {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ s32 unk50;
};

f32 MKWidget_GetMetricF(int);
void * MKWidget_GetMetric(int);
void MKWidget_SetUserData(MKWidget *, void *);
void MKWidget_SetCustomMessageHook(MKWidget *, int (*)(MKWidget *, unsigned int, unsigned int, void *));
void MKWidget_GetWidgetUnderPoint(MKWidgetSystem *, const MKVector3 &);
f32 MKWidget_GetLocalMousePos(MKWidget *, MKVector3 *);
void MKWidget_BringToFront(MKWidget *);
MKWidget * MKWidget_GetFocus(void);
void MKWidget_GetMousePos(MKVector3 *);
MKWidget * MKWidget_ReleaseMouseFocus(void);
MKWidget * MKWidget_SetMouseFocus(MKWidget *);
MKWidget * MKWidget_SetFocus(MKWidget *);
void MKWidget_GetNumChildren(MKWidget *);
void MKWidget_DisableFlag(MKWidget *, unsigned int);
void MKWidget_EnableFlag(MKWidget *, unsigned int);
void MKWidget_SetFlags(MKWidget *, unsigned int);
void MKWidget_Show(MKWidget *, int);
void MKWidget_GetBoundingVolume(MKWidget *, MKWidgetBoundingVolume *);
void MKWidget_GetClientVolume(MKWidget *, MKWidgetBoundingVolume *);
void MKWidget_GetSize(MKWidget *, MKVector3 *);
void MKWidget_GetPos(MKWidget *, MKVector3 *);
void MKWidget_SetColor(MKWidget *, const MKVector4 &);
void MKWidget_Scale(MKWidget *, const MKVector3 &);
void MKWidget_Resize(MKWidget *, const MKVector3 &);
void MKWidget_Move(MKWidget *, const MKVector3 &);
void MKWidget_SetName(MKWidget *, const char *);
u8 MKWidget_IsDescendant(MKWidget *, MKWidget *);
s32 MKWidget_IsType(MKWidget *, const char *);
void MKWidget_GetSystem(MKWidget *);
s32 MKWidget_SendMessage(MKWidget *, unsigned int, unsigned int);
void MKWidget_CreateEditable(const char *, const char *, const MKWidgetAttributes *, MKWidget *, int (*)(MKWidget *, unsigned int, unsigned int, void *), void *);
void MKWidget_Destroy(MKWidget *);
MKWidget * MKWidget_Create(const char *, const char *, const MKWidgetAttributes *, MKWidget *, int (*)(MKWidget *, unsigned int, unsigned int, void *), void *);
void MKWidget_PushCurrentSystem(MKWidgetSystem *);
MKWidget * MKWidget_GetCurrentSystem(void);
MKWidgetSystem * MKWidget_CreateSystem(void);
void MKWidget_Update(void);
void MKWidget_CreateMaterial(void);
void MKWidget_InitModule(void);
extern u8 pSystemStack[0x40];
extern u32 systemStackDepth;
extern MKWidgetDescriptor * pDescriptorList;
extern void ** pMKWidgetSystem;
#endif  // COMMON_SOURCE_MKWIDGETS_H
