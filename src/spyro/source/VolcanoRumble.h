#ifndef SPYRO_SOURCE_VOLCANORUMBLE_H
#define SPYRO_SOURCE_VOLCANORUMBLE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDSound.h"

class KDSoundFader;
class MKMessage;
class MKProp;
class VolcanoRumble;

class VolcanoRumble : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~VolcanoRumble(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void MakeRumbleSoundCameraShakeCrud(void);
    void EmitCrudAbovePlayer(void);
    void MakeCrudRainSound(void);
    /* 0x04c */ KDSoundFader unk4C;
    /* 0x0c0 */ u8 padC0[0x2c];
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ u8 unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: '(' expected
inline VolcanoRumble::~VolcanoRumble() {
    __destroy_arr((KDSoundFader *) &this->unk4C, &KDSoundFader::~KDSoundFader, 0x28, 4);
    if (this != NULL) {
    }
}
#endif

#endif  // SPYRO_SOURCE_VOLCANORUMBLE_H
