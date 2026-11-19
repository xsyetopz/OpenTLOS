#ifndef SPYRO_SOURCE_SHATTERABLEPLATFORM_H
#define SPYRO_SOURCE_SHATTERABLEPLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKMessage;
class Shatterable;
class ShatterablePlatform;

class ShatterablePlatform : public Shatterable {  // base: vtable prefix
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
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void ShatterablePlatform::UpdateMove() {

}

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterablePlatform::~ShatterablePlatform() {
    M2C_UNK *temp_r4_21310;
    f32 temp_r0_21312;

    if (this != NULL) {
        this->unkC8 = &__vt + 0x48;
        if (&this->unk1A8.unk8 != NULL) {
            temp_r4_21310 = &this->unk1C0.unk14;
            if (temp_r4_21310 != NULL) {
                temp_r0_21312 = this->unk1C0.unk18.unk4;
                if ((M2C_BITWISE(u32, temp_r0_21312) != 0U) && (M2C_BITWISE(u32, temp_r0_21312) != temp_r4_21310)) {
                    M2C_FIELD(this->unk1C0.unk18.unk8, f32 *, 8) = temp_r0_21312;
                    M2C_FIELD(this->unk1C0.unk18.unk4, f32 *, 0xC) = (f32) this->unk1C0.unk18.unk8;
                    this->unk1C0.unk18.unk8 = M2C_BITWISE(f32, temp_r4_21310);
                    this->unk1C0.unk18.unk4 = M2C_BITWISE(f32, temp_r4_21310);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C0'
inline ShatterablePlatform::ShatterablePlatform() {
    M2C_UNK *temp_r0_21353;

    temp_r0_21353 = &this->unk1C0.unk14;
    this->unkC8 = &__vt + 0x48;
    M2C_FIELD(this, s32 *, 0x1E8) = 0;
    this->unk1C0.unk18.unk0 = 0.0f;
    this->unk1C0.unk18.unk4 = M2C_BITWISE(f32, temp_r0_21353);
    this->unk1C0.unk18.unk8 = M2C_BITWISE(f32, temp_r0_21353);
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHATTERABLEPLATFORM_H
