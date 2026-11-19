#ifndef SPYRO_SOURCE_ENERGYBEAM_H
#define SPYRO_SOURCE_ENERGYBEAM_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSpline.h"

class EnergyBeam;
class KDProp;
class KDSpline;
class MKHeap;
class MKMaterial;
class MKVector3;

class EnergyBeam : public KDProp {  // base: ctor/dtor vtable stores
public:
    class Beam;
    virtual ~EnergyBeam(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void DrawBeam(EnergyBeam::Beam *);
    void ResetSafePositions(EnergyBeam::Beam *);
    void UpdateTargetVelocities(EnergyBeam::Beam *);
    void FreeEnergyBeam(EnergyBeam::Beam *);
    void SpawnEnergyBeam(MKVector3 *, MKVector3 *, float);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ MKHeap* unk90;
    /* 0x094 */ KDSpline unk94;
    /* 0x0a8 */ MKMaterial* unkA8;
};

#endif  // SPYRO_SOURCE_ENERGYBEAM_H
