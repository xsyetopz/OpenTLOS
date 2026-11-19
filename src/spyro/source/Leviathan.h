#ifndef SPYRO_SOURCE_LEVIATHAN_H
#define SPYRO_SOURCE_LEVIATHAN_H

#include <dolphin/types.h>
#include "spyro/source/Platform.h"

class Leviathan;
class MKIniLine;
class MKMessage;
class MKModel;
class MKProp;
class Platform;
class WaterSurfaceFX;

class Leviathan : public Platform {  // base: base ctor call
public:
    virtual ~Leviathan(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMove(void);
    Leviathan(void);
    void SetDefaults(void);
    void EmitWaterSpray(void);
    void EmitHugeSplash(void);
    void SetAnim(int);
    /* 0x180 */ s32 unk180;
    /* 0x184 */ u8 pad184[0x4];
    /* 0x188 */ f32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ u8 pad190[0x4];
    /* 0x194 */ f32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ s32 unk19C;
    /* 0x1a0 */ MKProp* unk1A0;
    /* 0x1a4 */ WaterSurfaceFX* unk1A4;
    /* 0x1a8 */ s32 unk1A8;
    /* 0x1ac */ s32 unk1AC;
    /* 0x1b0 */ s32 unk1B0;
    /* 0x1b4 */ s32 unk1B4;
    /* 0x1b8 */ MKModel* unk1B8;
    /* 0x1bc */ f32 unk1BC;
    /* 0x1c0 */ s32 unk1C0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk184'
inline Leviathan::Leviathan() {
    this->unk180 = 0;
    this->unk184 = 0;
    this->unk188 = 0.0f;
    this->unk18C = 0;
    this->unk1C0 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline Leviathan::~Leviathan() {
    if ((&this->unk1C0 != NULL) && (&this->unk1C0 != NULL)) {
        KDSound_Stop(&this->unk1C0);
    }
}
#endif

#endif  // SPYRO_SOURCE_LEVIATHAN_H
