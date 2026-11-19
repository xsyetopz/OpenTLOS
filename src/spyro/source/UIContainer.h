#ifndef SPYRO_SOURCE_UICONTAINER_H
#define SPYRO_SOURCE_UICONTAINER_H

#include <dolphin/types.h>
#include "spyro/source/UIObject.h"

class RenderContext;
class UIContainer;
class UIDataLine;
class UIMessage;
class UIObject;

class UIContainer : public UIObject {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    virtual void Resolve(void);
    virtual void Message(UIMessage *);
    virtual s32 IsContainer(void) const;
    void Remove(UIObject *);
    void AddBefore(UIObject *, UIObject *);
    void Add(UIObject *);
    UIObject * GetChild(int);
    UIObject * FindChild(const char *);
    static u8 descriptor[0x14];
    /* 0x060 */ UIObject* unk60;
    /* 0x064 */ s32 unk64;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 UIContainer::IsContainer() const {
    return 1;
}

#endif  // SPYRO_SOURCE_UICONTAINER_H
