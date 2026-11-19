#ifndef SPYRO_SOURCE_VELOCITYTRIGGER_H
#define SPYRO_SOURCE_VELOCITYTRIGGER_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/CreationTable.h"
#include "spyro/source/TriggerProp.h"

class MKIniLine;
class MKVector3;
class TriggerBoxProp;
class TriggerBoxPropDescriptor;
class VelocityTrigger;
class VelocityTriggerDescriptor;

class VelocityTrigger : public TriggerBoxProp {  // base: ctor/dtor vtable stores
public:
    virtual ~VelocityTrigger(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    virtual void OnAction(void);
    VelocityTrigger(void);
    /* 0x0c1 */ u8 padC1[0xcf];
    /* 0x190 */ void* unk190;
    /* 0x194 */ u8 pad194[0xbc];
    /* 0x250 */ MKVector3 unk250;
    /* 0x260 */ MKVector3 unk260;
    /* 0x270 */ MKVector3 unk270;
    /* 0x280 */ MKVector3 unk280;
};

class VelocityTriggerDescriptor : public TriggerBoxPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    VelocityTriggerDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkD0'
inline VelocityTrigger::VelocityTrigger() {
    this->unkAC.unk0 = 0;
    this->unkAC.Init();
    this->unkB0.unk0 = 0;
    this->unkB0.Init();
    this->unkB4.unk0 = 0;
    this->unkB4.Init();
    this->unkD0 = &__vt;
    this->unkD0 = &__vt;
    this->unk190 = &__vt;
    this->unk190 = &__vt;
    return this;
}
#endif

inline VelocityTrigger::~VelocityTrigger() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (&this->unkB4 != NULL) {
                    this->unkB4.Deinit();
                }
                if (&this->unkB0 != NULL) {
                    this->unkB0.Deinit();
                }
                if (&this->unkAC != NULL) {
                    this->unkAC.Deinit();
                }
                if (this != NULL) {
                }
            }
        }
    }
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline VelocityTriggerDescriptor::VelocityTriggerDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_VELOCITYTRIGGER_H
