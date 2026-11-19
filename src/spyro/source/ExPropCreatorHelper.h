#ifndef SPYRO_SOURCE_EXPROPCREATORHELPER_H
#define SPYRO_SOURCE_EXPROPCREATORHELPER_H

#include <dolphin/types.h>

class MKPropDescriptor;

template <class T0, class T1>
class ExPropCreatorHelper {
public:
    T0 * Create(MKPropDescriptor *);
};

#endif  // SPYRO_SOURCE_EXPROPCREATORHELPER_H
