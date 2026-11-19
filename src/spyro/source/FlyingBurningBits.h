#ifndef SPYRO_SOURCE_FLYINGBURNINGBITS_H
#define SPYRO_SOURCE_FLYINGBURNINGBITS_H

#include <dolphin/types.h>

class FlyingBurningBits;
class MKMaterial;
class MKVector3;

class FlyingBurningBits {
public:
    void Emit(const MKVector3 &, const MKVector3 &);
    void Deinit(void);
    void Draw(void);
    void Update(void);
    void Init(void);
    /* 0x000 */ MKVector3** unk0;
    /* 0x004 */ MKMaterial* unk4;
};

#endif  // SPYRO_SOURCE_FLYINGBURNINGBITS_H
