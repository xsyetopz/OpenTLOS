#ifndef SPYRO_SOURCE_SHAKECAMERAMESSAGE_H
#define SPYRO_SOURCE_SHAKECAMERAMESSAGE_H

#include <dolphin/types.h>

class MKVector3;
class ShakeCameraMessage;

class ShakeCameraMessage {
public:
    void Init(const MKVector3 &, bool);
};

#endif  // SPYRO_SOURCE_SHAKECAMERAMESSAGE_H
