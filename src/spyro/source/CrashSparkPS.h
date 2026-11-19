#ifndef SPYRO_SOURCE_CRASHSPARKPS_H
#define SPYRO_SOURCE_CRASHSPARKPS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class CrashSparkPS;
class MKProp;

class CrashSparkPS : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CrashSparkPS(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void UpdateCollision(const int &);
    /* 0x04c */ void* unk4C;
};

#endif  // SPYRO_SOURCE_CRASHSPARKPS_H
