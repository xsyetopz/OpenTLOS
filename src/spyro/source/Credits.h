#ifndef SPYRO_SOURCE_CREDITS_H
#define SPYRO_SOURCE_CREDITS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/UIScreen.h"

class CreditsProp;
class CreditsScreen;
class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class RenderContext;
class UIScreen;

class CreditsProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CreditsProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ EventMessage unk4C;
};

class CreditsScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    CreditsScreen(void);
    static u8 descriptor[0x14];
};

s32 Credits_Active(void);
void Credits_Message(MKMessage *);
void Credits_Draw(void);
s32 Credits_Update(void);
void Credits_Deinit(void);
void Credits_Init(MKProp *);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CreditsProp::~CreditsProp() {
    if (&this->unk4C != NULL) {
        this->unk4C.Deinit();
    }
    if (this != NULL) {
    }
}

inline CreditsScreen::CreditsScreen() {
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

#endif  // SPYRO_SOURCE_CREDITS_H
