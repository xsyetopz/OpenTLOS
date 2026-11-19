#ifndef SPYRO_SOURCE_KDPROP_H
#define SPYRO_SOURCE_KDPROP_H

#include <dolphin/types.h>
#include "common/Source/MKCollision.h"
#include "common/Source/MKProp.h"

class KDProp;
class KDPropDescriptor;
class KDPropModuleInfo;
class MKAnimScript;
class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class KDProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual void SetPos(const MKVector3 &);
    void UpdateCameraAlpha(void);
    void AddCollisionSubObject(int, MKCollisionInfo *);
    void SetColorToGround(void);
    static u8 pCustomAnimScrName[0x4];
    static u8 pCustomModelName[0x4];
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ MKCollisionInfo unk70;
    /* 0x080 */ MKAnimScript* unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ u8 unk88;
};

class KDPropDescriptor : public MKPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 unk6C;
};

class KDPropModuleInfo {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 unk15;
};

u8 KDProp_LoadMaterialID(MKIniLine *, const char *, int *);
void KDProp_InitModule(KDPropModuleInfo *);
extern u8 gUpdateCameraAlpha[0x1];
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'MKModel_SetPosition'
inline void KDProp::SetPos(const MKVector3 &arg0) {
    MKModel_SetPosition(this->unk4, arg0);
}
#endif

inline KDProp::~KDProp() {
    s32 temp_cr0_eq_5057;

    temp_cr0_eq_5057 = this == NULL;
    if (temp_cr0_eq_5057 == 0) {
        if (temp_cr0_eq_5057 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_KDPROP_H
