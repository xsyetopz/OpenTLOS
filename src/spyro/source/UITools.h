#ifndef SPYRO_SOURCE_UITOOLS_H
#define SPYRO_SOURCE_UITOOLS_H

#include <dolphin/types.h>
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIImage.h"
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
class UIImage;
class UIMessage;
class UIPie;
class UIScreen;
class UISystem;
class UIText;
class UITools_cpp;
class UIVideoScreen;

class DSText : public UIText {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    static u8 descriptor[0x14];
};

class GameText : public DSText {  // base: ctor/dtor vtable stores
public:
    virtual void Draw(const RenderContext &);
    GameText(void);
    static u8 descriptor[0x14];
};

class HealthSafetyScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    HealthSafetyScreen(void);
    static u8 descriptor[0x14];
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

class ImageArc : public UIImage {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Draw(const RenderContext &);
    static u8 descriptor[0x14];
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
};

class NoisyButtonGroup : public UIButtonGroup {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual s32 Message(UIMessage *);
    NoisyButtonGroup(void);
    static u8 descriptor[0x14];
    /* 0x078 */ f32 unk78;
};

class ScriptButtonGroup : public NoisyButtonGroup {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual s32 Message(UIMessage *);
    virtual s32 SetSelection(int);
    ScriptButtonGroup(void);
    static u8 descriptor[0x14];
    /* 0x080 */ s8* unk80;
    /* 0x084 */ u8 unk84;
};

class LanguageButtonGroup : public ScriptButtonGroup {  // base: base ctor call
public:
    virtual void LoadDone(void);
    LanguageButtonGroup(void);
    static u8 descriptor[0x14];
};

class LocalizedVideoScreen : public UIVideoScreen {  // base: base ctor call
public:
    virtual void LoadDone(void);
    LocalizedVideoScreen(void);
    static u8 descriptor[0x14];
};

class MarkerButtonGroup : public NoisyButtonGroup {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    virtual s32 Message(UIMessage *);
    MarkerButtonGroup(void);
    u8 GetTargetAttributes(Attributes *);
    static u8 descriptor[0x14];
    /* 0x080 */ void* unk80;
    /* 0x084 */ u8 pad84[0x14];
    /* 0x098 */ Attributes unk98;
    /* 0x0e0 */ s8* unkE0;
    /* 0x0e4 */ u8 padE4[0x14];
    /* 0x0f8 */ u8 unkF8;
};

class NoisySystem : public UISystem {  // base: ctor/dtor vtable stores
public:
    virtual s32 Message(UIMessage *);
    NoisySystem(void);
    static u8 descriptor[0x14];
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
    static u8 descriptor[0x14];
    /* 0x090 */ s8* unk90;
    /* 0x094 */ s8* unk94;
    /* 0x098 */ s8* unk98;
};

class OptionButton : public ScriptButton {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual s32 Message(UIMessage *);
    OptionButton(void);
    static u8 descriptor[0x14];
    /* 0x0a0 */ f32 unkA0;
};

class ProgressBar : public UIImage {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void LoadDone(void);
    virtual void Draw(const RenderContext &);
    static u8 descriptor[0x14];
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

class PromptGroup : public UIContainer {  // base: inlined ctor vtable stores
public:
    virtual s32 Message(UIMessage *);
    void Reset(void);
    static u8 descriptor[0x14];
};

class PromptText : public DSText {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Draw(const RenderContext &);
    virtual void Resolve(void);
    virtual s32 Message(UIMessage *);
    PromptText(void);
    static u8 descriptor[0x14];
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
    virtual s32 Message(UIMessage *);
    void SetPositions(void);
    RadialButtonGroup(void);
    static u8 descriptor[0x14];
    /* 0x078 */ u8 unk78;
    /* 0x079 */ u8 pad79[0x13];
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
    virtual s32 Message(UIMessage *);
    ScriptProgressBar(void);
    static u8 descriptor[0x14];
    /* 0x0d0 */ s8* unkD0;
    /* 0x0d4 */ s8* unkD4;
    /* 0x0d8 */ s8* unkD8;
    /* 0x0dc */ u8 unkDC;
};

class ScriptVideoScreen : public UIVideoScreen {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void DoExit(void);
    ScriptVideoScreen(void);
    static u8 descriptor[0x14];
    /* 0x108 */ u8 pad108[0x20];
    /* 0x128 */ s8* unk128;
};

class ThrobButton : public ScriptButton {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual s32 Message(UIMessage *);
    ThrobButton(void);
    static u8 descriptor[0x14];
};

class UIPie : public UIImage {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Draw(const RenderContext &);
    static u8 descriptor[0x14];
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
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline GameText::GameText() {
}

inline HealthSafetyScreen::HealthSafetyScreen() {
    this->unk68.unk0 = NULL;
    this->unk68.unk4 = 0;
    this->unk68.unk8 = NULL;
    this->unk74.unk0 = NULL;
    this->unk74.unk4 = 0;
    this->unk74.unk8 = NULL;
    this->unk80.unk0 = NULL;
    this->unk80.unk4 = 0;
    this->unk80.unk8 = NULL;
    this->unk8C.unk0 = NULL;
    this->unk8C.unk4 = 0;
    this->unk8C.unk8 = NULL;
    this->unk98.unk0 = NULL;
    this->unk98.unk4 = 0;
    this->unk98.unk8 = NULL;
    this->unkA4.unk0 = NULL;
    this->unkA4.unk4 = 0;
    this->unkA4.unk8 = NULL;
    this->unkB0.unk0 = NULL;
    this->unkB0.unk4 = 0;
    this->unkB0.unk8 = NULL;
    this->unkBC.unk0 = NULL;
    this->unkBC.unk4 = 0;
    this->unkBC.unk8 = NULL;
}

inline void ImageArc::Init() {
    UIImage::Init();
    this->unk78 = 2.0f;
    this->unk7C = 2.0f;
    this->unk80 = 0.0f;
    this->unk84 = 6.2831855f;
}

inline LanguageButtonGroup::LanguageButtonGroup() {
}

inline LocalizedVideoScreen::LocalizedVideoScreen() {
}

#if 0 // DRAFT: undefined identifier '__vt'
inline MarkerButtonGroup::MarkerButtonGroup() {
    this->unk80 = &__vt;
    this->unk80 = &__vt;
}
#endif

inline NoisyButtonGroup::NoisyButtonGroup() {
    this->unk6C.unk0 = NULL;
    this->unk6C.unk4 = 0;
    this->unk6C.unk8 = NULL;
}

inline NoisySystem::NoisySystem() {
}

inline OptionButton::OptionButton() {
}

inline PromptText::PromptText() {
}

#if 0 // DRAFT: '(' expected
inline RadialButtonGroup::RadialButtonGroup() {
    this->unk6C.unk0 = NULL;
    this->unk6C.unk4 = 0;
    this->unk6C.unk8 = NULL;
    M2C_FIELD(this, struct __vt **, 0x78) = &__vt;
    M2C_FIELD(this, struct __vt **, 0x78) = &__vt;
    M2C_FIELD(this, struct __vt **, 0x78) = (struct __vt *) &__vt;
}
#endif

inline ScriptButton::ScriptButton() {
    this->unk68.unk0 = NULL;
    this->unk68.unk4 = 0;
    this->unk68.unk8 = NULL;
    this->unk74.unk0 = NULL;
    this->unk74.unk4 = 0;
    this->unk74.unk8 = NULL;
    this->unk80.unk0 = NULL;
    this->unk80.unk4 = 0;
    this->unk80.unk8 = NULL;
}

inline ScriptButtonGroup::ScriptButtonGroup() {
}

inline ScriptProgressBar::ScriptProgressBar() {
}

inline ScriptVideoScreen::ScriptVideoScreen() {
}

inline ThrobButton::ThrobButton() {
}

#endif  // SPYRO_SOURCE_UITOOLS_H
