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
    /* 0x1a3 */ u8 pad1A3[0x5];
    /* 0x1a8 */ PlatformObjectDesc unk1A8;
    /* 0x1ba */ u8 pad1BA[0x6];
    /* 0x1c0 */ PlatformObject unk1C0;
    /* 0x204 */ u8 pad204[0x4];
    /* 0x208 */ f64 unk208;
    /* 0x210 */ f64 unk210;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void ShatterablePlatform::UpdateMove() {

}

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterablePlatform::~ShatterablePlatform() {
    f32 temp_r0_21312;
    s32 *temp_r4_21310;

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

#if 0 // DRAFT: undefined identifier 'unk14'
inline ShatterablePlatform::ShatterablePlatform() {
    s32 *temp_r0_21353;

    temp_r0_21353 = &this->unk1C0.unk14;
    this->unkC8 = &__vt + 0x48;
    this->unk1C0.unk14 = 0;
    this->unk1C0.unk18.unk0 = 0.0f;
    this->unk1C0.unk18.unk4 = M2C_BITWISE(f32, temp_r0_21353);
    this->unk1C0.unk18.unk8 = M2C_BITWISE(f32, temp_r0_21353);
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHATTERABLEPLATFORM_H
