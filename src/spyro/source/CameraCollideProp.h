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

#endif  // SPYRO_SOURCE_CAMERACOLLIDEPROP_H
