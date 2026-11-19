#ifndef SPYRO_SOURCE_SPAWNEFFECTBOX_H
#define SPYRO_SOURCE_SPAWNEFFECTBOX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDVolume.h"

class KDVolume;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class SpawnEffectBox;
class SpawnEffectBoxDescriptor;

class SpawnEffectBox : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SpawnEffectBox(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ KDVolume unk50;
    /* 0x0d8 */ u8 padD8[0x8];
    /* 0x0e0 */ s8* unkE0;
    /* 0x0e4 */ void* unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ u8 unkF0;
    /* 0x0f1 */ u8 padF1[0x3];
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
};

class SpawnEffectBoxDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SpawnEffectBox::~SpawnEffectBox() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SPAWNEFFECTBOX_H
