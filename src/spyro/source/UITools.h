#ifndef SPYRO_SOURCE_UITOOLS_H
#define SPYRO_SOURCE_UITOOLS_H

#include <dolphin/types.h>
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIImage.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "spyro/source/UIVideoScreen.h"

class Attributes;
class DSText;
class GameText;
class HealthSafetyScreen;
class ImageArc;
class LanguageButtonGroup;
class LocalizedVideoScreen;
class MKMaterial;
class MarkerButtonGroup;
class NoisyButtonGroup;
class NoisySystem;
class OptionButton;
class ProgressBar;
class PromptGroup;
class PromptText;
class RadialButtonGroup;
class RenderContext;
class ScriptButton;
class ScriptButtonGroup;
class ScriptProgressBar;
class ScriptVideoScreen;
class ThrobButton;
class UIButton;
class UIButtonGroup;
class UIContainer;
class UIDataLine;
class UIEvent;
class UIImage;
class UIMessage;
class UIObject;
class UIPie;
class UIScreen;
class UISystem;
class UIText;
class UITools_cpp;
class UIVideoScreen;

class DSText : public UIText {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
};

class GameText : public DSText {  // base: ctor/dtor vtable stores
public:
    virtual void Draw(const RenderContext &);
    GameText(void);
    /* 0x004 */ u8 pad4[0x64];
    /* 0x068 */ s8* unk68;
    /* 0x06c */ s32 unk6C;
};

class HealthSafetyScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    HealthSafetyScreen(void);
    /* 0x004 */ u8 pad4[0x64];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
    /* 0x0c8 */ UIImage* unkC8;
    /* 0x0cc */ UIImage* unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ u8 unkD4;
    /* 0x0d5 */ u8 unkD5;
    /* 0x0d6 */ u8 padD6[0x2];
    /* 0x0d8 */ s32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ u8 unkE0;
};

class ImageArc : public UIObject {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Draw(const RenderContext &);
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0xa];
    /* 0x064 */ MKMaterial* unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
};

class ScriptButtonGroup : public UIButtonGroup {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Message(UIMessage *);
    virtual s32 SetSelection(int);
    ScriptButtonGroup(void);
    /* 0x004 */ u8 pad4[0x64];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ u8 pad6C[0x14];
    /* 0x080 */ s8* unk80;
    /* 0x084 */ u8 unk84;
};

class LanguageButtonGroup : public ScriptButtonGroup {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    LanguageButtonGroup(void);
};

class LocalizedVideoScreen : public UIVideoScreen {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    LocalizedVideoScreen(void);
    /* 0x004 */ u8 pad4[0xdc];
    /* 0x0e0 */ s8* unkE0;
};

class MarkerButtonGroup : public UIButtonGroup {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    virtual void Message(UIMessage *);
    MarkerButtonGroup(void);
    u8 GetTargetAttributes(Attributes *);
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0xe];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ u8 pad6C[0x2c];
    /* 0x098 */ Attributes unk98;
    /* 0x0da */ u8 padDA[0x6];
    /* 0x0e0 */ s8* unkE0;
    /* 0x0e4 */ u8 padE4[0x14];
    /* 0x0f8 */ u8 unkF8;
};

class NoisyButtonGroup : public UIButtonGroup {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Message(UIMessage *);
    NoisyButtonGroup(void);
    /* 0x004 */ u8 pad4[0x74];
    /* 0x078 */ f32 unk78;
};

class NoisySystem : public UISystem {  // base: ctor/dtor vtable stores
public:
    virtual void Message(UIMessage *);
    NoisySystem(void);
};

class ScriptButton : public UIButton {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void OnActivate(void);
    virtual void OnSelection(void);
    virtual void OnDeselection(void);
    virtual void SetOnActivate(const char *);
    virtual void SetOnSelect(const char *);
    virtual void SetOnDeselect(const char *);
    ScriptButton(void);
    /* 0x004 */ u8 pad4[0x8c];
    /* 0x090 */ s8* unk90;
    /* 0x094 */ s8* unk94;
    /* 0x098 */ s8* unk98;
};

class OptionButton : public ScriptButton {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Message(UIMessage *);
    OptionButton(void);
    /* 0x004 */ OptionButton* unk4;
    /* 0x008 */ u8 pad8[0xc];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 unk15;
    /* 0x016 */ u8 unk16;
    /* 0x017 */ u8 pad17[0xd];
    /* 0x024 */ f32 unk24;
    /* 0x028 */ u8 pad28[0x20];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0xc];
    /* 0x058 */ u16 unk58;
    /* 0x05a */ u8 pad5A[0x46];
    /* 0x0a0 */ f32 unkA0;
};

class ProgressBar : public UIImage {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void LoadDone(void);
    virtual void Draw(const RenderContext &);
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u16 unk58;
    /* 0x05a */ u8 pad5A[0x1e];
    /* 0x078 */ s32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ u16 unkC0;
    /* 0x0c2 */ u8 padC2[0x6];
    /* 0x0c8 */ f32 unkC8;
};

class PromptGroup : public UIContainer {  // base: vtable prefix
public:
    virtual void Message(UIMessage *);
    void Reset(void);
    /* 0x004 */ u8 pad4[0x48];
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ u8 pad50[0x10];
    /* 0x060 */ void* unk60;
};

class PromptText : public DSText {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Draw(const RenderContext &);
    virtual void Resolve(void);
    virtual void Message(UIMessage *);
    PromptText(void);
    /* 0x004 */ s8* unk4;
    /* 0x008 */ u8 pad8[0x60];
    /* 0x068 */ s8* unk68;
    /* 0x06c */ s32 unk6C;
};

class RadialButtonGroup : public UIButtonGroup {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    virtual void Resolve(void);
    virtual void Message(UIMessage *);
    void SetPositions(void);
    RadialButtonGroup(void);
    /* 0x004 */ u8 pad4[0x8];
    /* 0x00c */ UIContainer* unkC;
    /* 0x010 */ u8 pad10[0x5];
    /* 0x015 */ u8 unk15;
    /* 0x016 */ u8 pad16[0x12];
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ u8 pad38[0x14];
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ u8 pad54[0xc];
    /* 0x060 */ void* unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ UIEvent unk6C;
    /* 0x078 */ u8 pad78[0x14];
    /* 0x08c */ u8 unk8C;
    /* 0x08d */ u8 pad8D[0x3];
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ u8 padBC[0x8];
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ u16 unkD0;
    /* 0x0d2 */ u8 padD2[0x1e];
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ u8 padF4[0x4];
    /* 0x0f8 */ void** unkF8;
    /* 0x0fc */ s32 unkFC;
};

class ScriptProgressBar : public ProgressBar {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Message(UIMessage *);
    ScriptProgressBar(void);
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0x6e];
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ s8* unkD0;
    /* 0x0d4 */ s8* unkD4;
    /* 0x0d8 */ s8* unkD8;
    /* 0x0dc */ u8 unkDC;
};

class ScriptVideoScreen : public UIVideoScreen {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void DoExit(void);
    ScriptVideoScreen(void);
    /* 0x004 */ u8 pad4[0x124];
    /* 0x128 */ s8* unk128;
};

class ThrobButton : public ScriptButton {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Message(UIMessage *);
    ThrobButton(void);
    /* 0x004 */ u8 pad4[0x11];
    /* 0x015 */ u8 unk15;
    /* 0x016 */ u8 unk16;
    /* 0x017 */ u8 pad17[0x1];
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ u8 pad28[0x30];
    /* 0x058 */ u16 unk58;
    /* 0x05a */ u8 pad5A[0x6];
    /* 0x060 */ void* unk60;
};

class UIPie : public UIImage {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Draw(const RenderContext &);
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0xa];
    /* 0x064 */ MKMaterial* unk64;
    /* 0x068 */ u8 pad68[0x10];
    /* 0x078 */ f32 unk78;
};

class UITools_cpp {
public:
    void __sinit(void);
};

PromptGroup * FindPrompt(UIContainer *);
void UITools_RegisterAll(void);
extern u8 buttonLabel[0x1c];
extern u8 buttonString[0x1c];
#endif  // SPYRO_SOURCE_UITOOLS_H
