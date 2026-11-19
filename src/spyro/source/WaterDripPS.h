#ifndef SPYRO_SOURCE_WATERDRIPPS_H
#define SPYRO_SOURCE_WATERDRIPPS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class KDPathSegment;
class MKMessage;
class MKProp;
class MKVector3;
class WaterDripPS;

class WaterDripPS : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~WaterDripPS(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    f64 UpdateCollision(const int &);
    void Emit(const MKVector3 &, const MKVector3 &, const float &, bool, bool, KDPathSegment *);
    /* 0x04c */ void* unk4C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline WaterDripPS::~WaterDripPS() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_WATERDRIPPS_H
