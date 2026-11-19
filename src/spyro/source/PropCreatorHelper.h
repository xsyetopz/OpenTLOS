#ifndef SPYRO_SOURCE_PROPCREATORHELPER_H
#define SPYRO_SOURCE_PROPCREATORHELPER_H

#include <dolphin/types.h>

class GamePropDescriptor;
class MKPropDescriptor;

template <class T0>
class PropCreatorHelper {
public:
    GamePropDescriptor * Create(MKPropDescriptor *);
};

#endif  // SPYRO_SOURCE_PROPCREATORHELPER_H
