#ifndef SPYRO_SOURCE_KDSOUNDPROP_H
#define SPYRO_SOURCE_KDSOUNDPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class KDSoundProp;
class KDSoundPropDescriptor;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class Matrix;

class KDSoundProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDSoundProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void Play(void);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ Matrix unk60;
    /* 0x0a0 */ s32 unkA0;
};

class KDSoundPropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x1c];
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ s32 unk7C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk40'
inline KDSoundProp::~KDSoundProp() {
    if (&this->unk60.unk40 != NULL) {
        KDSound_Stop((s32 *) &this->unk60.unk40);
    }
    if (this != NULL) {
    }
}
#endif

#endif  // SPYRO_SOURCE_KDSOUNDPROP_H
