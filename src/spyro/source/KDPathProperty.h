#ifndef SPYRO_SOURCE_KDPATHPROPERTY_H
#define SPYRO_SOURCE_KDPATHPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDPathProperty;
class KDProperty;
class MKIniLine;

class KDPathProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void DeinitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void LoadDoneInstance(void);
    virtual void ResolveInstance(void);
    static KDPathProperty classInfo;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 KDPathProperty::GetInstanceDataSize() const {
    return 0x30;
}

#if 0 // DRAFT: undefined identifier 'KDPathSegment'
inline void KDPathProperty::InitInstance() {
    ((KDPathSegment *) (*KDProperty::pInstanceMem + this->unk8))->Init();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDPathSegment'
inline void KDPathProperty::DeinitInstance() {
    ((KDPathSegment *) (*KDProperty::pInstanceMem + this->unk8))->Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDPathSegment'
inline s32 KDPathProperty::LoadLineInstance(MKIniLine *arg0) {
    s8 *var_r5_2976;

    var_r5_2976 = this->unk4;
    if (var_r5_2976 != NULL) {

    } else {
        var_r5_2976 = (signed char *) ("");
    }
    ((KDPathSegment *) (*KDProperty::pInstanceMem + this->unk8))->LoadWaypoints(arg0, var_r5_2976);
}
#endif

#if 0 // DRAFT: undefined identifier 'KDPathSegment'
inline void KDPathProperty::LoadDoneInstance() {
    ((KDPathSegment *) (*KDProperty::pInstanceMem + this->unk8))->LoadDone();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDPathSegment'
inline void KDPathProperty::ResolveInstance() {
    ((KDPathSegment *) (*KDProperty::pInstanceMem + this->unk8))->Resolve();
}
#endif

inline void *KDPathProperty::GetClassInfo() const {
    return &KDPathProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDPATHPROPERTY_H
