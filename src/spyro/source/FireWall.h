#ifndef SPYRO_SOURCE_FIREWALL_H
#define SPYRO_SOURCE_FIREWALL_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class FireWall;
class FireWallDescriptor;
class MKHeap;
class MKIniLine;
class MKMaterial;
class MKProp;
class MKPropDescriptor;

class FireWall : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FireWall(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ MKHeap* unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
};

class FireWallDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ MKMaterial* unk60;
};

#endif  // SPYRO_SOURCE_FIREWALL_H
