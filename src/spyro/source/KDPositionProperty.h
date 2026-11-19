#ifndef SPYRO_SOURCE_KDPOSITIONPROPERTY_H
#define SPYRO_SOURCE_KDPOSITIONPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDPositionProperty;
class KDProperty;
class MKIniLine;

class KDPositionProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual s32 GetInstanceDataAlignment(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void GetPos(void) const;
    virtual s32 GetPosRef(void) const;
    static KDPositionProperty classInfo;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 KDPositionProperty::GetInstanceDataAlignment() const {
    return 0x10;
}

inline s32 KDPositionProperty::GetInstanceDataSize() const {
    return 0x10;
}

inline void KDPositionProperty::InitInstance() {
    void *temp_r3_24314;

    temp_r3_24314 = (void *) (*KDProperty::pInstanceMem + this->unk8);
    M2C_FIELD(temp_r3_24314, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r3_24314, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r3_24314, f32 *, 8) = 0.0f;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKIniLine'
inline s32 KDPositionProperty::LoadLineInstance(MKIniLine *arg0) {
    s8 *var_r6_24327;

    var_r6_24327 = this->unk4;
    if (var_r6_24327 != NULL) {

    } else {
        var_r6_24327 = (signed char *) ("");
    }
    arg0->LoadVector3(var_r6_24327, *KDProperty::pInstanceMem + this->unk8, 0);
}
#endif

inline void KDPositionProperty::GetPos() const {
    void *temp_r4_24354;

    temp_r4_24354 = (void *) (*KDProperty::pInstanceMem + M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), s32 *, 8));
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r4_24354, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r4_24354, f64 *, 8);
}

inline s32 KDPositionProperty::GetPosRef() const {
    return *KDProperty::pInstanceMem + this->unk8;
}

inline void *KDPositionProperty::GetClassInfo() const {
    return &KDPositionProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDPOSITIONPROPERTY_H
