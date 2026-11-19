#ifndef SPYRO_SOURCE_MOBILEPLATFORM_H
#define SPYRO_SOURCE_MOBILEPLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/Platform.h"

class EventMessage;
class KDSplinePathSegment;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class MobilePlatform;
class MobilePlatformDescriptor;
class Platform;
class PlatformDescriptor;

class MobilePlatform : public Platform {  // base: vtable prefix
public:
    virtual ~MobilePlatform(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void PropUpdate(void);
    virtual void UpdateMove(void);
    virtual void UpdateScale(void);
    MobilePlatform(void);
    void UpdateSag(void);
    void SetYaw(float, float);
    f32 GetTime(void);
    static u8 mpfLoadInfo[0x10];
    /* 0x17c */ u8 pad17C[0x4];
    /* 0x180 */ f32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ f32 unk190;
    /* 0x194 */ f32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ KDSplinePathSegment unk19C;
    /* 0x1e2 */ u8 pad1E2[0x2];
    /* 0x1e4 */ u8 unk1E4;
    /* 0x1e5 */ u8 pad1E5[0x3];
    /* 0x1e8 */ f32 unk1E8;
    /* 0x1ec */ u8 unk1EC;
    /* 0x1ed */ u8 pad1ED[0x3];
    /* 0x1f0 */ s32 unk1F0;
    /* 0x1f4 */ f32 unk1F4;
    /* 0x1f8 */ f32 unk1F8;
    /* 0x1fc */ f32 unk1FC;
    /* 0x200 */ EventMessage unk200;
    /* 0x204 */ EventMessage unk204;
    /* 0x208 */ f32 unk208;
    /* 0x20c */ u8 unk20C;
    /* 0x20d */ u8 pad20D[0x3];
    /* 0x210 */ f32 unk210;
    /* 0x214 */ f32 unk214;
    /* 0x218 */ u8 unk218;
    /* 0x219 */ u8 pad219[0x3];
    /* 0x21c */ s32 unk21C;
    /* 0x220 */ u8 pad220[0x24];
    /* 0x244 */ f32 unk244;
    /* 0x248 */ f32 unk248;
    /* 0x24c */ u8 pad24C[0x4];
    /* 0x250 */ f64 unk250;
    /* 0x258 */ f32 unk258;
};

class MobilePlatformDescriptor : public PlatformDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    MobilePlatformDescriptor(void);
    s32 IsDescriptor(MKPropDescriptor *);
    static u8 pFirstDesc[0x4];
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ s32 unk12C;
    /* 0x130 */ s32 unk130;
    /* 0x134 */ s32 unk134;
    /* 0x138 */ s32 unk138;
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ void* unk144;
    /* 0x148 */ MobilePlatformDescriptor* unk148;
    /* 0x14c */ MobilePlatformDescriptor* unk14C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MobilePlatform::MobilePlatform() {
    M2C_FIELD(this, s32 *, 0x1CC) = 0;
    this->unk19C.unk30.unk0 = 0;
    this->unk19C.unk30.unk4 = 0.0f;
    this->unk19C.unk30.unk8 = 0.0f;
    this->unk1F8 = 0.0f;
    ((EventMessage *) &this->unk1F8)->Init();
    this->unk1FC = 0.0f;
    ((EventMessage *) &this->unk1FC)->Init();
    this->unk214 = 0.0f;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline MobilePlatform::~MobilePlatform() {
    if ((&this->unk214 != NULL) && (&this->unk214 != NULL)) {
        KDSound_Stop((s32 *) &this->unk214);
    }
    if (&this->unk1FC != NULL) {
        ((EventMessage *) &this->unk1FC)->Deinit();
    }
    if (&this->unk1F8 != NULL) {
        ((EventMessage *) &this->unk1F8)->Deinit();
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MobilePlatformDescriptor::MobilePlatformDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MOBILEPLATFORM_H
