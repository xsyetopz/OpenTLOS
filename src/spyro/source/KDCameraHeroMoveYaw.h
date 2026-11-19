#ifndef SPYRO_SOURCE_KDCAMERAHEROMOVEYAW_H
#define SPYRO_SOURCE_KDCAMERAHEROMOVEYAW_H

#include <dolphin/types.h>

class KDCameraHeroMoveYaw;

class KDCameraHeroMoveYaw {
public:
    class UpdateData;
    void Update(const KDCameraHeroMoveYaw::UpdateData &);
};

#endif  // SPYRO_SOURCE_KDCAMERAHEROMOVEYAW_H
