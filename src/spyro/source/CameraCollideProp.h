#ifndef SPYRO_SOURCE_CAMERACOLLIDEPROP_H
#define SPYRO_SOURCE_CAMERACOLLIDEPROP_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class CameraCollideProp;
class KDProp;

class CameraCollideProp : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CameraCollideProp(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CameraCollideProp::~CameraCollideProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_CAMERACOLLIDEPROP_H
