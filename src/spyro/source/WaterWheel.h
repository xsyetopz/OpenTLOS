#ifndef SPYRO_SOURCE_WATERWHEEL_H
#define SPYRO_SOURCE_WATERWHEEL_H

#include <dolphin/types.h>
#include "spyro/source/Platform.h"

class MKMessage;
class Platform;
class WaterWheel;

class WaterWheel : public Platform {  // base: vtable prefix
public:
    virtual ~WaterWheel(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMove(void);
    WaterWheel(void);
    /* 0x17c */ u8 pad17C[0x4];
    /* 0x180 */ f32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ u8 pad188[0x2c];
    /* 0x1b4 */ f32 unk1B4;
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ u8 pad1BC[0x4];
    /* 0x1c0 */ u8 unk1C0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline WaterWheel::WaterWheel() {
    this->unk184 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline WaterWheel::~WaterWheel() {
    if ((&this->unk184 != NULL) && (&this->unk184 != NULL)) {
        KDSound_Stop(&this->unk184);
    }
}
#endif

#endif  // SPYRO_SOURCE_WATERWHEEL_H
