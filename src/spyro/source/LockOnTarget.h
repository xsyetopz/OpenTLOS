#ifndef SPYRO_SOURCE_LOCKONTARGET_H
#define SPYRO_SOURCE_LOCKONTARGET_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class LockOnTarget;
class LockOnTargetDescriptor;
class MKMaterial;
class MKProp;
class MKPropDescriptor;

class LockOnTarget : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~LockOnTarget(void);
    virtual void Init(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    /* 0x04c */ void* unk4C;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ u8 unk78;
    /* 0x079 */ u8 unk79;
};

class LockOnTargetDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ MKMaterial* unk60;
    /* 0x064 */ MKMaterial* unk64;
    /* 0x068 */ f32 unk68;
};

#endif  // SPYRO_SOURCE_LOCKONTARGET_H
