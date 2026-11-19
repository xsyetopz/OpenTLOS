#ifndef SPYRO_SOURCE_CYNDERBARRACKS_H
#define SPYRO_SOURCE_CYNDERBARRACKS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_enums.h"

class CynderBarracks;
class CynderBarracksDescriptor;
class EnemyGenerator;
class EnemyGeneratorDescriptor;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class Shatterable;

class CynderBarracks : public Shatterable {  // base: vtable prefix
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
    /* 0x1a3 */ u8 pad1A3[0x5];
    /* 0x1a8 */ s32 unk1A8;
    /* 0x1ac */ s32 unk1AC;
    /* 0x1b0 */ f32 unk1B0;
    /* 0x1b4 */ EnemyGenerator unk1B4;
};

class CynderBarracksDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderBarracksDescriptor(void);
    /* 0x044 */ u8 pad44[0x20];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x104];
    /* 0x16c */ EnemyGeneratorDescriptor unk16C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'EnemyGenerator *' to
inline CynderBarracks::CynderBarracks() {
    M2C_UNK *temp_r30_21742;

    temp_r30_21742 = &this->unk1B4;
    this->unkC8 = &__vt + 0x48;
    M2C_FIELD(this, M2C_UNK **, 0x1B4) = &__vt;
    this->unk1B4.unk2C = 0;
    ((EventMessage *) (temp_r30_21742 + 0x3C))->Init();
    this->unk1B4.unk30 = 0.0f;
    ((EventMessage *) (temp_r30_21742 + 0x40))->Init();
    M2C_FIELD(this, M2C_UNK **, 0x1B4) = &__vt;
    this->unk1B4.unk58 = NULL;
    ((EventMessage *) (temp_r30_21742 + 0x68))->Init();
    this->unk1B4.unk5C = NULL;
    ((EventMessage *) (temp_r30_21742 + 0x6C))->Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline CynderBarracks::~CynderBarracks() {
    f32 *temp_r3_39;
    s32 *temp_r3_45;
    void **temp_r3_26;
    void **temp_r3_32;

    if (this != NULL) {
        this->unkC8 = &__vt.unk48;
        if (&this->unk1B4 != NULL) {
            temp_r3_26 = &this->unk1B4.unk5C;
            M2C_FIELD(this, void **, 0x1B4) = &__vt;
            if (temp_r3_26 != NULL) {
                ((EventMessage *) temp_r3_26)->Deinit();
            }
            temp_r3_32 = &this->unk1B4.unk58;
            if (temp_r3_32 != NULL) {
                ((EventMessage *) temp_r3_32)->Deinit();
            }
            if (&this->unk1B4 != NULL) {
                temp_r3_39 = &this->unk1B4.unk30;
                M2C_FIELD(this, void **, 0x1B4) = &__vt;
                if (temp_r3_39 != NULL) {
                    ((EventMessage *) temp_r3_39)->Deinit();
                }
                temp_r3_45 = &this->unk1B4.unk2C;
                if (temp_r3_45 != NULL) {
                    ((EventMessage *) temp_r3_45)->Deinit();
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
