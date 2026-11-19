#ifndef SPYRO_SOURCE_UIOBJECT_H
#define SPYRO_SOURCE_UIOBJECT_H

#include <dolphin/types.h>
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIStringTable.h"

class Attributes;
class RenderContext;
class UIContainer;
class UIDataLine;
class UIMessage;
class UIObject;
class UIObject_cpp;
class UIStringTable;

class UIObject {
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(const RenderContext &) = 0;
    virtual void LoadResources(void) = 0;
    virtual void FreeResources(void) = 0;
    virtual void Resolve(void);
    virtual void Message(UIMessage *);
    virtual UIContainer * Find(const char *);
    virtual s32 IsContainer(void) const;
    UIContainer * GetRoot(void) const;
    s32 Load(const char *, const char *);
    /* 0x004 */ u32 unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ UIContainer* unkC;
    /* 0x010 */ UIObject* unk10;
    /* 0x014 */ u8 unk14;
    /* 0x015 */ s8 unk15;
    /* 0x016 */ s8 unk16;
    /* 0x017 */ u8 pad17[0x1];
    /* 0x018 */ Attributes unk18;
};

class UIObject_cpp {
public:
    void __sinit(void);
};

void UIObject_MenuStringsDeinit(void);
void UIObject_MenuStringsInit(int);
extern UIStringTable menuStrings;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void UIObject::LoadDone() {

}

inline void UIObject::Update() {

}

inline s32 UIObject::IsContainer() const {
    return 0;
}

#endif  // SPYRO_SOURCE_UIOBJECT_H
