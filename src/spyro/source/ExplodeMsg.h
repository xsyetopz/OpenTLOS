#ifndef SPYRO_SOURCE_EXPLODEMSG_H
#define SPYRO_SOURCE_EXPLODEMSG_H

#include <dolphin/types.h>

class ExplodeMsg;
class MKProp;
class MKVector3;

class ExplodeMsg {
public:
    void Init(MKProp *, const MKVector3 &, float, bool, bool, int, float, int);
};

#endif  // SPYRO_SOURCE_EXPLODEMSG_H
