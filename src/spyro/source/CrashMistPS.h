#ifndef SPYRO_SOURCE_CRASHMISTPS_H
#define SPYRO_SOURCE_CRASHMISTPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class CrashMistPS;
class MKParticleSystem;
class MKVector3;
class MKVector4;

class CrashMistPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~CrashMistPS(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    CrashMistPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &, const float &, const MKVector4 &, const float &);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CrashMistPS::~CrashMistPS() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

inline CrashMistPS::CrashMistPS() {
}

#endif  // SPYRO_SOURCE_CRASHMISTPS_H
