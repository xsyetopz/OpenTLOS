#ifndef SPYRO_SOURCE_LOADLEVEL_H
#define SPYRO_SOURCE_LOADLEVEL_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"

class ChunkInfo;
class LoadLevel_cpp;
class LoadingScreen;
class MCLoadCheckScreen;
class RenderContext;
class UIObjectDescriptor;
class UIScreen;

class LoadLevel_cpp {
public:
    void __sinit(void);
};

class LoadingScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    LoadingScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ u8 unkC8;
    /* 0x0c9 */ u8 padC9[0x3];
    /* 0x0cc */ f32 unkCC;
};

class UIObjectDescriptor {
public:
    static UIObjectDescriptor list;
    /* 0x000 */ MCLoadCheckScreen* unk0;
};

void LoadLevel_Draw(void);
void LoadLevel_Update(void);
void LoadLevel_Deactivate(bool);
void LoadLevel_Activate(ChunkInfo *);
s32 LoadLevel_GetState(void);
void LoadLevel_Deinit(void);
void LoadLevel_Init(void);
void LoadLevel_FreeResources(void);
void LoadLevel_LoadResources(void);
extern ChunkInfo * pLoadChunkInfo;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LoadingScreen::LoadingScreen() {
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

#endif  // SPYRO_SOURCE_LOADLEVEL_H
