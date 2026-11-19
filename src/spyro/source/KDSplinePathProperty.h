#ifndef SPYRO_SOURCE_KDSPLINEPATHPROPERTY_H
#define SPYRO_SOURCE_KDSPLINEPATHPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDPathProperty.h"

class KDPathProperty;
class KDSplinePathProperty;
class MKIniLine;

class KDSplinePathProperty : public KDPathProperty {  // base: inlined ctor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void DeinitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void LoadDoneInstance(void);
    virtual void ResolveInstance(void);
    static KDSplinePathProperty classInfo;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 KDSplinePathProperty::GetInstanceDataSize() const {
    return 0x48;
}

#if 0 // DRAFT: undefined identifier 'KDSplinePathSegment'
inline void KDSplinePathProperty::InitInstance() {
    ((KDSplinePathSegment *) (*KDProperty::pInstanceMem + this->unk8))->Init();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSplinePathSegment'
inline void KDSplinePathProperty::DeinitInstance() {
    ((KDSplinePathSegment *) (*KDProperty::pInstanceMem + this->unk8))->Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
inline s32 KDSplinePathProperty::LoadLineInstance(MKIniLine *arg0) {
    s8 *var_r5_2872;

    var_r5_2872 = this->unk4;
    if (var_r5_2872 != NULL) {

    } else {
        var_r5_2872 = "";
    }
    ((KDSplinePathSegment *) (*KDProperty::pInstanceMem + this->unk8))->LoadWaypoints(arg0, var_r5_2872);
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSplinePathSegment'
inline void KDSplinePathProperty::LoadDoneInstance() {
    ((KDSplinePathSegment *) (*KDProperty::pInstanceMem + this->unk8))->LoadDone();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDPathSegment'
inline void KDSplinePathProperty::ResolveInstance() {
    ((KDPathSegment *) (*KDProperty::pInstanceMem + this->unk8))->Resolve();
}
#endif

inline void *KDSplinePathProperty::GetClassInfo() const {
    return &KDSplinePathProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDSPLINEPATHPROPERTY_H
