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
    virtual void * Update(void);
    virtual void Draw(void);
    void UpdateCollision(const int &);
    /* 0x04c */ void* unk4C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CrashSparkPS::~CrashSparkPS() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_CRASHSPARKPS_H
