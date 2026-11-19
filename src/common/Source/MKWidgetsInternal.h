#ifndef COMMON_SOURCE_MKWIDGETSINTERNAL_H
#define COMMON_SOURCE_MKWIDGETSINTERNAL_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"

class MKFont;
class MKHeap;
class MKInputEvent;
class MKInputReceiver;
class MKMaterial;
class MKVector3;
class MKVector4;
class MKWidget;
class MKWidgetBoundingVolume;
class MKWidgetButton;
class MKWidgetCheckBox;
class MKWidgetCheckMark;
class MKWidgetColor;
class MKWidgetComboBox;
class MKWidgetContainer;
class MKWidgetDescriptor;
class MKWidgetEditable;
class MKWidgetEnvelope;
class MKWidgetFoldupFrame;
class MKWidgetFrame;
class MKWidgetImage;
class MKWidgetListBox;
class MKWidgetListItem;
class MKWidgetMetaData;
class MKWidgetRenderContext;
class MKWidgetScissorRect;
class MKWidgetScrollBar;
class MKWidgetScrollableFrame;
class MKWidgetSerialise;
class MKWidgetSlider;
class MKWidgetString;
class MKWidgetSystem;
class MKWidgetTabStrip;
class MKWidgetTextBox;
class MKWidgetThumb;
class MKWidgetVector;
class MKWidgetWindow;
class MKWidgetWindowTitleBar;
class MKWidgetsInternal_cpp;
class Matrix;

class MKInputEvent {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 unkA;
    /* 0x00b */ u8 padB[0x1];
    /* 0x00c */ u8 unkC;
    /* 0x00d */ u8 unkD;
};

class MKWidget {
public:
    virtual ~MKWidget(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void Draw(MKWidgetRenderContext);
    virtual void UpdateState(void);
    virtual void Update(void);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual MKWidget * GetWidgetUnderPoint(MKVector3);
    virtual void GetLocalToWorldMatrix(Matrix *);
    virtual u8 IsContainer(void);
    virtual u8 IsChildWidget(MKWidget *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    void GetWidgetMatrix(Matrix *);
    u8 IsFlagSet(unsigned int) const;
    MKWidget(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidget_FactoryFunc(void);
    static u8 sMKWidgetDescriptor[0x18];
    /* 0x004 */ s8** unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ void* unkC;
    /* 0x010 */ u32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ MKWidget* unk18;
    /* 0x01c */ MKWidget* unk1C;
    /* 0x020 */ u32 unk20;
    /* 0x024 */ s32 unk24;
};

class MKWidgetBoundingVolume {
public:
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
};

class MKWidgetButton : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetButton(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetButton(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetButton_FactoryFunc(void);
    static u8 sMKWidgetButtonDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget unk28;
    /* 0x050 */ u8 pad50[0x4];
    /* 0x054 */ MKWidget unk54;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ u8 unk84;
    /* 0x085 */ u8 unk85;
};

class MKWidgetCheckBox : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetCheckBox(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetCheckBox(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetCheckBox_FactoryFunc(void);
    static u8 sMKWidgetCheckBoxDescriptor[0x18];
    /* 0x004 */ u32* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget unk28;
    /* 0x050 */ u8 pad50[0x4];
    /* 0x054 */ MKWidget unk54;
};

class MKWidgetCheckMark : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetCheckMark(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetCheckMark(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetCheckMark_FactoryFunc(void);
    static u8 sMKWidgetCheckMarkDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ u8 unk28;
    /* 0x029 */ u8 unk29;
};

class MKWidgetColor : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetColor(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetColor(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetColor_FactoryFunc(void);
    static u8 sMKWidgetColorDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
};

class MKWidgetComboBox : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetComboBox(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    s32 ListBoxHook(MKWidget *, unsigned int, unsigned int, void *);
    MKWidgetComboBox(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetComboBox_FactoryFunc(void);
    static u8 sMKWidgetComboBoxDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget unk28;
    /* 0x050 */ MKWidget unk50;
    /* 0x078 */ u8 pad78[0x4];
    /* 0x07c */ MKWidget unk7C;
    /* 0x0a4 */ u8 padA4[0xc];
    /* 0x0b0 */ MKWidget unkB0;
    /* 0x0d8 */ u8 padD8[0x28];
    /* 0x100 */ MKWidget* unk100;
};

class MKWidgetContainer : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetContainer(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Draw(MKWidgetRenderContext);
    virtual void Update(void);
    virtual MKWidget * GetWidgetUnderPoint(MKVector3);
    virtual u8 IsContainer(void);
    virtual u8 IsChildWidget(MKWidget *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    void GetChild(int);
    void GetChildIndex(MKWidget *);
    MKWidgetContainer(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetContainer_FactoryFunc(void);
    static u8 sMKWidgetContainerDescriptor[0x18];
    /* 0x004 */ u8 pad4[0x1c];
    /* 0x020 */ u32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ MKWidget* unk28;
    /* 0x02c */ u32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
};

class MKWidgetDescriptor {
public:
    MKWidgetDescriptor(const char *, MKWidgetDescriptor *, MKWidget *(*)(void), unsigned int, unsigned int);
    /* 0x000 */ s8* unk0;
    /* 0x004 */ u32 unk4;
    /* 0x008 */ MKWidgetDescriptor* unk8;
    /* 0x00c */ MKWidgetDescriptor* unkC;
    /* 0x010 */ u8 pad10[0x4];
    /* 0x014 */ u32 unk14;
};

class MKWidgetEditable : public MKWidgetContainer {  // base: ctor/dtor vtable stores
public:
    virtual ~MKWidgetEditable(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    void ContextMenuProc(int, void *);
    u32 EditableMessageHook(MKWidget *, unsigned int, unsigned int, void *);
    MKWidgetEditable(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetEditable_FactoryFunc(void);
    static u8 sMKWidgetEditableDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 pad8[0x10];
    /* 0x018 */ MKWidget* unk18;
    /* 0x01c */ u8 pad1C[0xc];
    /* 0x028 */ MKWidget* unk28;
    /* 0x02c */ u8 pad2C[0xc];
    /* 0x038 */ f64 unk38;
    /* 0x040 */ MKVector3 unk40;
    /* 0x050 */ s8 unk50;
    /* 0x051 */ s8 unk51;
    /* 0x052 */ u8 pad52[0x2];
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ s32 unk5C;
};

class MKWidgetEnvelope : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetEnvelope(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetEnvelope(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetEnvelope_FactoryFunc(void);
    static u8 sMKWidgetEnvelopeDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0x18];
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f32 unk38;
};

class MKWidgetFrame : public MKWidgetContainer {  // base: ctor/dtor vtable stores
public:
    virtual ~MKWidgetFrame(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    virtual void ArrangeChildren(void);
    MKWidgetFrame(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetFrame_FactoryFunc(void);
    static u8 sMKWidgetFrameDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget* unk28;
};

class MKWidgetFoldupFrame : public MKWidgetFrame {  // base: ctor/dtor vtable stores
public:
    virtual ~MKWidgetFoldupFrame(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetFoldupFrame(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetFoldupFrame_FactoryFunc(void);
    static u8 sMKWidgetFoldupFrameDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 pad8[0x38];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 pad44[0xc];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ MKWidget unk54;
    /* 0x07c */ MKWidget unk7C;
    /* 0x0a4 */ u8 padA4[0x4];
    /* 0x0a8 */ MKWidget unkA8;
    /* 0x0d0 */ u8 padD0[0xc];
    /* 0x0dc */ MKWidget unkDC;
};

class MKWidgetImage : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetImage(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetImage(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetImage_FactoryFunc(void);
    static u8 sMKWidgetImageDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 pad8[0x10];
    /* 0x018 */ MKWidget* unk18;
    /* 0x01c */ u8 pad1C[0xc];
    /* 0x028 */ MKMaterial* unk28;
};

class MKWidgetScrollableFrame : public MKWidgetFrame {  // base: ctor/dtor vtable stores
public:
    virtual ~MKWidgetScrollableFrame(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void UpdateState(void);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    void CheckScrollBarRequirements(void);
    void GetChildrenRange(MKVector3 *, MKVector3 *);
    MKWidgetScrollableFrame(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetScrollableFrame_FactoryFunc(void);
    static u8 sMKWidgetScrollableFrameDescriptor[0x18];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ void* unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ MKVector3 unk40;
    /* 0x050 */ MKVector3 unk50;
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ MKWidget unk70;
    /* 0x098 */ MKWidget unk98;
    /* 0x0c0 */ u8 padC0[0x60];
    /* 0x120 */ MKWidget unk120;
    /* 0x148 */ u8 pad148[0x60];
    /* 0x1a8 */ MKWidget unk1A8;
    /* 0x1d0 */ u8 pad1D0[0x38];
    /* 0x208 */ MKWidget unk208;
    /* 0x230 */ MKWidget unk230;
    /* 0x258 */ u8 pad258[0x60];
    /* 0x2b8 */ MKWidget unk2B8;
    /* 0x2e0 */ u8 pad2E0[0x60];
    /* 0x340 */ MKWidget unk340;
};

class MKWidgetListBox : public MKWidgetScrollableFrame {  // base: vtable prefix
public:
    virtual ~MKWidgetListBox(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Draw(MKWidgetRenderContext);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    virtual void ArrangeChildren(void);
    void SortChildren(void);
    MKWidgetListBox(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetListBox_FactoryFunc(void);
    static u8 sMKWidgetListBoxDescriptor[0x18];
    /* 0x004 */ MKWidgetListBox* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget* unk28;
    /* 0x02c */ u32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x28];
    /* 0x064 */ f32 unk64;
    /* 0x068 */ u8 pad68[0x18];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ u8 pad84[0x184];
    /* 0x208 */ MKWidget unk208;
    /* 0x230 */ u8 pad230[0x170];
    /* 0x3a0 */ s32 unk3A0;
};

class MKWidgetListItem : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetListItem(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetListItem(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetListItem_FactoryFunc(void);
    static u8 sMKWidgetListItemDescriptor[0x18];
    /* 0x004 */ u32* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget unk28;
};

class MKWidgetRenderContext {
public:
    static u8 identity[0x50];
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0xc];
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ MKVector4 unk40;
};

class MKWidgetScissorRect {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ MKVector3 unk10;
    /* 0x020 */ MKWidgetScissorRect* unk20;
};

class MKWidgetScrollBar : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetScrollBar(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    void GetThumbFromValue(void);
    void GetValueFromThumb(void);
    MKWidgetScrollBar(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetScrollBar_FactoryFunc(void);
    static u8 sMKWidgetScrollBarDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget unk28;
    /* 0x050 */ MKWidget unk50;
    /* 0x078 */ u8 pad78[0x4];
    /* 0x07c */ MKWidget unk7C;
    /* 0x0a4 */ u8 padA4[0xc];
    /* 0x0b0 */ MKWidget unkB0;
    /* 0x0d8 */ MKWidget unkD8;
    /* 0x100 */ u8 pad100[0x4];
    /* 0x104 */ MKWidget unk104;
    /* 0x12c */ u8 pad12C[0xc];
    /* 0x138 */ MKWidget unk138;
};

class MKWidgetSerialise {
public:
    void SerialiseVersion(void);
    u8 GetMetaData(MKWidgetMetaData *&, unsigned int);
    static u8 metaDataResolveIndex[0x4];
    static u8 pMetaDataFile[0x4];
    static u8 pHierarchyFile[0x4];
    static u8 pIndexList[0x4];
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
};

class MKWidgetSlider : public MKWidgetScrollBar {  // base: ctor/dtor vtable stores
public:
    virtual ~MKWidgetSlider(void);
    MKWidgetSlider(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetSlider_FactoryFunc(void);
    static u8 sMKWidgetSliderDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget unk28;
    /* 0x050 */ MKWidget unk50;
    /* 0x078 */ u8 pad78[0x4];
    /* 0x07c */ MKWidget unk7C;
    /* 0x0a4 */ u8 padA4[0xc];
    /* 0x0b0 */ MKWidget unkB0;
    /* 0x0d8 */ MKWidget unkD8;
    /* 0x100 */ u8 pad100[0x4];
    /* 0x104 */ MKWidget unk104;
    /* 0x12c */ u8 pad12C[0xc];
    /* 0x138 */ MKWidget unk138;
};

class MKWidgetString : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetString(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetString(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetString_FactoryFunc(void);
    static u8 sMKWidgetStringDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0xf];
    /* 0x018 */ MKWidget* unk18;
    /* 0x01c */ u8 pad1C[0xc];
    /* 0x028 */ MKFont* unk28;
};

class MKWidgetSystem : public MKWidgetContainer {  // base: ctor/dtor vtable stores
public:
    virtual ~MKWidgetSystem(void);
    virtual void Draw(MKWidgetRenderContext);
    virtual void UpdateState(void);
    void CreateInputReceiver(bool);
    u8 AnyVisible(void);
    MKWidget * ChangeMouseFocus(MKWidget *);
    MKWidget * ChangeFocus(MKWidget *);
    MKWidgetSystem(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetSystem_FactoryFunc(void);
    static u8 sMKWidgetSystemDescriptor[0x18];
    /* 0x004 */ u8 pad4[0x24];
    /* 0x028 */ MKWidget* unk28;
    /* 0x02c */ u8 pad2C[0x14];
    /* 0x040 */ s32 unk40;
    /* 0x044 */ u8 pad44[0x4];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ MKWidget* unk4C;
    /* 0x050 */ MKWidget* unk50;
    /* 0x054 */ MKWidget* unk54;
    /* 0x058 */ MKWidgetSystem* unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u8 pad64[0x4];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ MKInputReceiver* unk78;
};

class MKWidgetTabStrip : public MKWidgetContainer {  // base: ctor/dtor vtable stores
public:
    virtual ~MKWidgetTabStrip(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    void FreeResources(void);
    MKWidgetTabStrip(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetTabStrip_FactoryFunc(void);
    static u8 sMKWidgetTabStripDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 pad8[0xc];
    /* 0x014 */ void* unk14;
    /* 0x018 */ u8 pad18[0x10];
    /* 0x028 */ MKWidget* unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ u8 pad30[0x10];
    /* 0x040 */ s32 unk40;
};

class MKWidgetTextBox : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetTextBox(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    void FindCaretPos(void);
    s32 GetCharIndexFromPoint(const MKVector3 &);
    MKWidgetTextBox(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetTextBox_FactoryFunc(void);
    static u8 sMKWidgetTextBoxDescriptor[0x18];
    /* 0x004 */ MKHeap* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ s8* unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ u8 pad34[0x8];
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ u8 unk4C;
};

class MKWidgetThumb : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetThumb(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetThumb(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetThumb_FactoryFunc(void);
    static u8 sMKWidgetThumbDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 pad8[0x28];
    /* 0x030 */ f64 unk30;
    /* 0x038 */ u8 pad38[0x8];
    /* 0x040 */ f64 unk40;
    /* 0x048 */ MKVector3 unk48;
    /* 0x058 */ u8 unk58;
};

class MKWidgetVector : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetVector(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetVector(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetVector_FactoryFunc(void);
    static u8 sMKWidgetVectorDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x1f];
    /* 0x028 */ MKWidget unk28;
    /* 0x050 */ u8 pad50[0x28];
    /* 0x078 */ MKWidget unk78;
    /* 0x0a0 */ u8 padA0[0x28];
    /* 0x0c8 */ MKWidget unkC8;
    /* 0x0f0 */ u8 padF0[0x28];
    /* 0x118 */ MKWidget unk118;
    /* 0x140 */ u8 pad140[0x28];
    /* 0x168 */ u8 unk168;
};

class MKWidgetWindow : public MKWidgetFrame {  // base: vtable prefix
public:
    virtual ~MKWidgetWindow(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetWindow(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetWindow_FactoryFunc(void);
    static u8 sMKWidgetWindowDescriptor[0x18];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x17];
    /* 0x020 */ MKWidgetWindow* unk20;
    /* 0x024 */ u8 pad24[0x1c];
    /* 0x040 */ MKWidget unk40;
    /* 0x068 */ u8 pad68[0x10];
    /* 0x078 */ MKWidget unk78;
    /* 0x0a0 */ u8 padA0[0x4];
    /* 0x0a4 */ MKWidget unkA4;
    /* 0x0cc */ void* unkCC;
    /* 0x0d0 */ u8 padD0[0x28];
    /* 0x0f8 */ void* unkF8;
    /* 0x0fc */ u8 padFC[0x34];
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f64 unk138;
    /* 0x140 */ MKVector3 unk140;
    /* 0x150 */ s32 unk150;
    /* 0x154 */ s32 unk154;
    /* 0x158 */ s32 unk158;
};

class MKWidgetWindowTitleBar : public MKWidget {  // base: vtable prefix
public:
    virtual ~MKWidgetWindowTitleBar(void);
    virtual s32 MessageHandler(unsigned int, unsigned int);
    virtual void Render(MKWidgetRenderContext *);
    virtual MKWidget * TestPoint(MKVector3 *);
    virtual void BuildMetaData(int);
    virtual void BuildAggregateMetaData(void);
    MKWidgetWindowTitleBar(MKWidgetDescriptor *);
    MKWidgetEditable * MKWidgetWindowTitleBar_FactoryFunc(void);
    static u8 sMKWidgetWindowTitleBarDescriptor[0x18];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0xf];
    /* 0x018 */ MKWidget* unk18;
    /* 0x01c */ u8 pad1C[0xc];
    /* 0x028 */ MKVector3 unk28;
    /* 0x038 */ MKWidget unk38;
    /* 0x060 */ u8 pad60[0x4];
    /* 0x064 */ MKWidget unk64;
    /* 0x08c */ MKWidget unk8C;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ MKWidget unkB8;
    /* 0x0e0 */ u8 padE0[0xc];
    /* 0x0ec */ u8 unkEC;
};

class MKWidgetsInternal_cpp {
public:
    void __sinit(void);
};

void * MKWidget_FindMessageHook(const char *);
void MKWidgetEnvelope_GetEnvelopeValuesFromPoint(MKWidgetBoundingVolume *, MKVector3 *, float *, float *);
void MKWidgetEnvelope_GetEnvelopePos(MKWidgetEnvelope *, int, MKWidgetBoundingVolume *);
s32 SystemReceiverCallback(MKInputEvent *, void *);
void WidgetDrawBox(const MKVector3 &, const MKVector3 &, int);
void WidgetDrawBox(const MKVector3 &, const MKVector3 &, const MKVector4 &);
void WidgetDrawSquare(const MKVector3 &, const MKVector3 &, float, const MKVector4 &);
void WidgetDrawBevel(const MKVector3 &, const MKVector3 &, float, const MKVector4 &, const MKVector4 &, bool, bool);
void PopScissorRect(void);
u8 PushScissorRect(MKWidgetScissorRect *);
void ApplyScissorRect(void);
void MKWidget_LoadHierarchy(const char *, MKWidgetContainer *);
void MKWidget_SaveHierarchy(const char *, MKWidget *);
void MKWidget_AddToDescriptorList(MKWidgetDescriptor *);
extern u8 gMKWidgetMetrics[0x2e0];
extern u8 gClipboardBuffer;
extern s8 gShowCursor;
extern s32 MKWidgetIdentityAttributes;
extern MKWidgetScissorRect * pScissorRectStack;
extern MKMaterial * pWidgetBlank;
extern s8 * pBlankData;
extern u8 gWidgetDebug;
extern f32 gWidgetOrthoWidth;
extern f32 gWidgetOrthoHeight;
extern s32 gWidgetCursor;
extern void * pHookEntryRoot;
extern s8 * MKWIDGETTYPE_FRAME;
extern s8 * MKWIDGETTYPE_LISTBOX;
extern s8 * MKWIDGETTYPE_WINDOW;
extern s8 * MKWIDGETTYPE_IMAGE;
extern s8 * MKWIDGETTYPE_BUTTON;
extern u8 MKWIDGETTYPE_TEXTBOX[0x4];
extern s8 * MKWIDGETTYPE_SLIDER;
extern s8 * MKWIDGETTYPE_LISTITEM;
extern s8 * MKWIDGETTYPE_COLOR;
#endif  // COMMON_SOURCE_MKWIDGETSINTERNAL_H
