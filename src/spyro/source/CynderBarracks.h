#ifndef SPYRO_SOURCE_CYNDERBARRACKS_H
#define SPYRO_SOURCE_CYNDERBARRACKS_H

#include <dolphin/types.h>
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_enums.h"

class CynderBarracks;
class CynderBarracksDescriptor;
class EnemyGenerator;
class MKIniLine;
class MKMessage;
class Shatterable;
class ShatterableDescriptor;

class CynderBarracks : public Shatterable {  // base: base ctor call
public:
    virtual ~CynderBarracks(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    CynderBarracks(void);
    void SetState(CynderBarracksState);
    /* 0x1a8 */ s32 unk1A8;
    /* 0x1ac */ s32 unk1AC;
    /* 0x1b0 */ f32 unk1B0;
    /* 0x1b4 */ EnemyGenerator unk1B4;
};

class CynderBarracksDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderBarracksDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline CynderBarracks::CynderBarracks() {
    EnemyGenerator *temp_r30_21742;

    temp_r30_21742 = &this->unk1B4;
    this->unkC8 = &__vt + 0x48;
    this->unk1B4.__vptr = &__vt;
    this->unk1B4.unk3C.unk0 = 0;
    temp_r30_21742->unk3C.Init();
    this->unk1B4.unk40.unk0 = 0;
    temp_r30_21742->unk40.Init();
    this->unk1B4.__vptr = &__vt;
    this->unk1B4.unk68.unk0 = 0;
    temp_r30_21742->unk68.Init();
    this->unk1B4.unk6C.unk0 = 0;
    temp_r30_21742->unk6C.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline CynderBarracks::~CynderBarracks() {
    EventMessage *temp_r3_26;
    EventMessage *temp_r3_32;
    EventMessage *temp_r3_39;
    EventMessage *temp_r3_45;

    if (this != NULL) {
        this->unkC8 = &__vt.unk48;
        if (&this->unk1B4 != NULL) {
            temp_r3_26 = &this->unk1B4.unk6C;
            this->unk1B4.__vptr = &__vt;
            if (temp_r3_26 != NULL) {
                temp_r3_26->Deinit();
            }
            temp_r3_32 = &this->unk1B4.unk68;
            if (temp_r3_32 != NULL) {
                temp_r3_32->Deinit();
            }
            if (&this->unk1B4 != NULL) {
                temp_r3_39 = &this->unk1B4.unk40;
                this->unk1B4.__vptr = &__vt;
                if (temp_r3_39 != NULL) {
                    temp_r3_39->Deinit();
                }
                temp_r3_45 = &this->unk1B4.unk3C;
                if (temp_r3_45 != NULL) {
                    temp_r3_45->Deinit();
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderBarracksDescriptor::CynderBarracksDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CYNDERBARRACKS_H
