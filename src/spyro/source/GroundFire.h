#ifndef SPYRO_SOURCE_GROUNDFIRE_H
#define SPYRO_SOURCE_GROUNDFIRE_H

#include <dolphin/types.h>

class GroundFire;
class MKHeap;
class MKVector3;

class GroundFire {
public:
    void Emit(const MKVector3 &, float, bool);
    void Deinit(void);
    void Update(void);
    void Init(int);
    /* 0x000 */ MKHeap* unk0;
};

#endif  // SPYRO_SOURCE_GROUNDFIRE_H
