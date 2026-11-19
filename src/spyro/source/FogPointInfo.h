#ifndef SPYRO_SOURCE_FOGPOINTINFO_H
#define SPYRO_SOURCE_FOGPOINTINFO_H

#include <dolphin/types.h>

class FogPointInfo;

class FogPointInfo {
public:
    FogPointInfo operator/(float);
    FogPointInfo operator*(float);
};

#endif  // SPYRO_SOURCE_FOGPOINTINFO_H
