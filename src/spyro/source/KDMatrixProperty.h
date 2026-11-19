#ifndef SPYRO_SOURCE_KDMATRIXPROPERTY_H
#define SPYRO_SOURCE_KDMATRIXPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDPositionProperty.h"

class KDMatrixProperty;
class KDPositionProperty;
class MKIniLine;
class Matrix;

class KDMatrixProperty : public KDPositionProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void GetPos(void) const;
    virtual s32 GetPosRef(void) const;
    virtual s32 GetMatrixRef(void) const;
    virtual void GetMatrix(Matrix *) const;
    static KDMatrixProperty classInfo;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 KDMatrixProperty::LoadLineInstance(MKIniLine *arg0) {
    return 0;
}

inline s32 KDMatrixProperty::GetInstanceDataSize() const {
    return 0x40;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Matrix'
inline void KDMatrixProperty::InitInstance() {
    ((Matrix *) (*KDProperty::pInstanceMem + this->unk8))->SetIdentity();
}
#endif

inline s32 KDMatrixProperty::GetMatrixRef() const {
    return *KDProperty::pInstanceMem + this->unk8;
}

inline void KDMatrixProperty::GetMatrix(Matrix *arg0) const {
    M2C_STRUCT_COPY(arg0, *KDProperty::pInstanceMem + this->unk8, 0x40);
}

inline void KDMatrixProperty::GetPos() const {
    void *temp_r4_24275;

    temp_r4_24275 = (void *) (*KDProperty::pInstanceMem + (M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), s32 *, 8) + 0x30));
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r4_24275, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r4_24275, f64 *, 8);
}

inline s32 KDMatrixProperty::GetPosRef() const {
    return *KDProperty::pInstanceMem + (this->unk8 + 0x30);
}

inline void *KDMatrixProperty::GetClassInfo() const {
    return &KDMatrixProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDMATRIXPROPERTY_H
