#ifndef SPYRO_SOURCE_CYNDERPORTCULLIS_H
#define SPYRO_SOURCE_CYNDERPORTCULLIS_H

#include <dolphin/types.h>
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/GameProp.h"

class CynderPortcullis;
class CynderPortcullisDescriptor;
class EnemyGenerator;
class GameProp;
class GamePropDescriptor;
class MKIniLine;
class MKMessage;

class CynderPortcullis : public GameProp {  // base: base ctor call
public:
    virtual ~CynderPortcullis(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    CynderPortcullis(void);
    /* 0x0c8 */ EnemyGenerator unkC8;
};

class CynderPortcullisDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderPortcullisDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier '__vptr'
inline CynderPortcullis::CynderPortcullis() {
    EnemyGenerator *temp_r30_21820;

    temp_r30_21820 = &this->unkC8;
    this->unkC8.__vptr = &__vt;
    this->unkC8.unk3C.unk0 = 0;
    temp_r30_21820->unk3C.Init();
    this->unkC8.unk40.unk0 = 0;
    temp_r30_21820->unk40.Init();
    this->unkC8.__vptr = &__vt;
    this->unkC8.unk68.unk0 = 0;
    temp_r30_21820->unk68.Init();
    this->unkC8.unk6C.unk0 = 0;
    temp_r30_21820->unk6C.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
inline CynderPortcullis::~CynderPortcullis() {
    EventMessage *temp_r3_24;
    EventMessage *temp_r3_30;
    EventMessage *temp_r3_37;
    EventMessage *temp_r3_43;

    if (this != NULL) {
        if (&this->unkC8 != NULL) {
            temp_r3_24 = &this->unkC8.unk6C;
            this->unkC8.__vptr = &__vt;
            if (temp_r3_24 != NULL) {
                temp_r3_24->Deinit();
            }
            temp_r3_30 = &this->unkC8.unk68;
            if (temp_r3_30 != NULL) {
                temp_r3_30->Deinit();
            }
            if (&this->unkC8 != NULL) {
                temp_r3_37 = &this->unkC8.unk40;
                this->unkC8.__vptr = &__vt;
                if (temp_r3_37 != NULL) {
                    temp_r3_37->Deinit();
                }
                temp_r3_43 = &this->unkC8.unk3C;
                if (temp_r3_43 != NULL) {
                    temp_r3_43->Deinit();
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderPortcullisDescriptor::CynderPortcullisDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CYNDERPORTCULLIS_H
