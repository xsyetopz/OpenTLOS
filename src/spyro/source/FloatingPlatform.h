#ifndef SPYRO_SOURCE_FLOATINGPLATFORM_H
#define SPYRO_SOURCE_FLOATINGPLATFORM_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/Platform.h"

class FloatingPlatform;
class MKIniLine;
class MKMessage;
class MKVector3;
class Platform;

class FloatingPlatform : public Platform {  // base: vtable prefix
public:
    virtual ~FloatingPlatform(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void PropUpdate(void);
    virtual void UpdateMove(void);
    FloatingPlatform(void);
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ u8 unk194;
    /* 0x195 */ u8 pad195[0x3];
    /* 0x198 */ s32 unk198;
    /* 0x19c */ u8 pad19C[0x8];
    /* 0x1a4 */ s32 unk1A4;
    /* 0x1a8 */ u8 pad1A8[0x4];
    /* 0x1ac */ f32 unk1AC;
    /* 0x1b0 */ u8 unk1B0;
    /* 0x1b1 */ u8 pad1B1[0x7];
    /* 0x1b8 */ MKVector3 unk1B8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk19C'
inline FloatingPlatform::FloatingPlatform() {
    this->unk198 = 0;
    this->unk19C = 0;
    this->unk1A0 = 0.0f;
    this->unk1A4 = 0;
    return this;
}
#endif

inline FloatingPlatform::~FloatingPlatform() {
}

#endif  // SPYRO_SOURCE_FLOATINGPLATFORM_H
