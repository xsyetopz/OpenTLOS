#ifndef SPYRO_SOURCE_LIGHTMANAGER_H
#define SPYRO_SOURCE_LIGHTMANAGER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class LightManager;
class MKProp;
class MKVector3;
class MKVector4;
class ManagedLight;

class LightManager : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~LightManager(void);
    virtual void Init(void);
    virtual void Deinit(void);
    void EnableLight(ManagedLight *, bool);
    void FreeManagedLight(ManagedLight *);
    void CalculateLightPosForShadow(const MKVector3 &);
    void * AllocManagedLight(const MKVector3 &, const MKVector3 &, const MKVector4 &, const float &, const int &, const bool &);
    void DisableAllLights(void);
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0xf];
    /* 0x05c */ void* unk5C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LightManager::~LightManager() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_LIGHTMANAGER_H
