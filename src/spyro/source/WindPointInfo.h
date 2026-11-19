#ifndef SPYRO_SOURCE_WINDPOINTINFO_H
#define SPYRO_SOURCE_WINDPOINTINFO_H

#include <dolphin/types.h>

class WindPointInfo;

class WindPointInfo {
public:
    WindPointInfo operator/(float);
    WindPointInfo operator*(float);
};

#endif  // SPYRO_SOURCE_WINDPOINTINFO_H
