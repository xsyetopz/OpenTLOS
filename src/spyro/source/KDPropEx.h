#ifndef SPYRO_SOURCE_KDPROPEX_H
#define SPYRO_SOURCE_KDPROPEX_H

#include <dolphin/types.h>
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDProperty.h"

class KDMatrixRefProperty;
class KDProp;
class KDPropDescriptor;
class KDPropEx;
class KDPropExDescriptor;
class KDPropEx_cpp;
class KDPropertySet;
class MKIniLine;
class MKMessage;

class KDPropEx : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDPropEx(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
};

class KDPropExDescriptor : public KDPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    KDPropExDescriptor(void);
    static u8 propertyClassRegistry[0x4];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ KDPropertySet unk74;
    /* 0x084 */ u32 unk84;
    /* 0x088 */ u8 pad88[0x8];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ u8 pad9C[0x8];
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ u8 padA8[0x4];
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ KDMatrixRefProperty unkB0;
};

class KDPropEx_cpp {
public:
    void __sinit(void);
};

extern u8 pLocalToWorldPropertyName[0x4];
extern u8 pModelPropertyName[0x4];
extern u8 pAnimScriptPropertyName[0x4];
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline KDPropEx::~KDPropEx() {
    s32 temp_cr0_eq_17705;

    temp_cr0_eq_17705 = this == NULL;
    if (temp_cr0_eq_17705 == 0) {
        if (temp_cr0_eq_17705 == 0) {
            if (temp_cr0_eq_17705 == 0) {
            }
        }
    }
}

#if 0 // DRAFT: undefined identifier 'vtable88'
inline KDPropExDescriptor::KDPropExDescriptor() {
    this->vtable88 = &__vt;
    this->unk8C = 0;
    this->unk94 = 0;
    this->unk90 = 0;
    this->vtable88 = (struct __vt *) &__vt;
    this->unk98 = 0;
    this->vtable9C = &__vt;
    this->unkA0 = 0;
    this->unkA8 = 0;
    this->unkA4 = 0;
    this->vtable9C = (struct __vt *) &__vt;
    this->unkAC = 0;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_KDPROPEX_H
