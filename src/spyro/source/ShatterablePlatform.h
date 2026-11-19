#ifndef SPYRO_SOURCE_SHATTERABLEPLATFORM_H
#define SPYRO_SOURCE_SHATTERABLEPLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shatterable.h"

class MKMessage;
class PlatformObject;
class PlatformObjectDesc;
class Shatterable;
class ShatterablePlatform;

class ShatterablePlatform : public Shatterable {  // base: base ctor call
public:
    virtual ~ShatterablePlatform(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMove(void);
    ShatterablePlatform(void);
    /* 0x1a8 */ PlatformObjectDesc unk1A8;
    /* 0x1bc */ u8 pad1BC[0x4];
    /* 0x1c0 */ PlatformObject unk1C0;
    /* 0x208 */ f64 unk208;
    /* 0x210 */ f64 unk210;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void ShatterablePlatform::UpdateMove() {

}

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterablePlatform::~ShatterablePlatform() {
    PlatformAttachment *temp_r0_21312;
    PlatformAttachment *temp_r4_21310;

    if (this != NULL) {
        this->unkC8 = &__vt + 0x48;
        if (&this->unk1C0 != NULL) {
            temp_r4_21310 = &this->unk1C0.unk28;
            if (temp_r4_21310 != NULL) {
                temp_r0_21312 = this->unk1C0.unk28.unk8;
                if ((temp_r0_21312 != NULL) && (temp_r0_21312 != temp_r4_21310)) {
                    this->unk1C0.unk28.unkC->unk8 = temp_r0_21312;
                    this->unk1C0.unk28.unk8->unkC = this->unk1C0.unk28.unkC;
                    this->unk1C0.unk28.unkC = temp_r4_21310;
                    this->unk1C0.unk28.unk8 = temp_r4_21310;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterablePlatform::ShatterablePlatform() {
    PlatformAttachment *temp_r0_21353;

    temp_r0_21353 = &this->unk1C0.unk28;
    this->unkC8 = &__vt + 0x48;
    this->unk1C0.unk28.unk0 = NULL;
    this->unk1C0.unk28.unk4 = NULL;
    this->unk1C0.unk28.unk8 = temp_r0_21353;
    this->unk1C0.unk28.unkC = temp_r0_21353;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHATTERABLEPLATFORM_H
