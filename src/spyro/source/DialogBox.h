#ifndef SPYRO_SOURCE_DIALOGBOX_H
#define SPYRO_SOURCE_DIALOGBOX_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"

class DialogBoxContext;
class DialogBoxLine;
class DialogBoxTheme;
class DialogBox_cpp;
class MKFont;
class MKMaterial;
class MKVector4;

class DialogBoxContext {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x8];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ s8* unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ u8 unk44;
    /* 0x045 */ u8 unk45;
    /* 0x046 */ u8 pad46[0x2];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ u8* unk58;
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ MKVector4 unk70;
    /* 0x080 */ MKMaterial* unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ f32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ u8 padA8[0x4];
    /* 0x0ac */ u8 unkAC;
};

class DialogBoxLine {
public:
    /* 0x000 */ void* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ f32 unk10;
};

class DialogBoxTheme {
public:
    /* 0x000 */ u8 pad0[0xc];
    /* 0x00c */ MKMaterial* unkC;
    /* 0x010 */ MKMaterial* unk10;
    /* 0x014 */ u8 pad14[0x8];
    /* 0x01c */ MKFont* unk1C;
};

class DialogBox_cpp {
public:
    void __sinit(void);
};

void DialogBox_Draw(void);
void DialogBox_Update(void);
void DialogBox_ReleaseContexts(void);
void DialogBox_ReleaseContext(DialogBoxContext *);
void * DialogBox_InitContext(void);
void DialogBox_FreeTheme(DialogBoxTheme *);
s8 * DialogBox_LoadTheme(const char *, const char *, float, float);
void DialogBox_DeinitModule(void);
void DialogBox_InitModule(void);
void DialogBox_ColorButtons(const char *, char *, int, int);
extern s8 Dialog_bEnableDraw;
extern s8 DialogBox_bAllowOverCutscene;
#endif  // SPYRO_SOURCE_DIALOGBOX_H
