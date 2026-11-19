#ifndef COMMON_SOURCE_MKCOLLISIONRESULT_H
#define COMMON_SOURCE_MKCOLLISIONRESULT_H

#include <dolphin/types.h>

class MKCollisionResult;

class MKCollisionResult {
public:
    void Init(void);
    void * GetProp(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ void* unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ u8 unk50;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk4'
inline void MKCollisionResult::Init() {
    this->unk0 = 0.0f;
    this->unk4 = 0.0f;
    this->unk8 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk20 = 0.0f;
    this->unk24 = 0.0f;
    this->unk28 = 0.0f;
    this->unk2C = 1.0f;
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    M2C_FIELD(this, s16 *, 0x38) = 0;
    M2C_FIELD(this, s8 *, 0x3A) = 0;
    M2C_FIELD(this, s8 *, 0x3B) = 0;
    this->unk3C = 0;
    this->unk40 = 3.4028235e38f;
    this->unk44 = 0;
    this->unk48 = NULL;
    this->unk4C = -1;
    this->unk50 = 0;
}
#endif

inline void *MKCollisionResult::GetProp() {
    void *temp_r3_4323;
    void *temp_r3_4326;

    if (((u8) this->unk50 == 0) || (temp_r3_4323 = this->unk48, ((temp_r3_4323 == NULL) != 0)) || (temp_r3_4326 = M2C_FIELD(temp_r3_4323, void **, 8), ((temp_r3_4326 == NULL) != 0))) {
        return NULL;
    }
    return temp_r3_4326;
}

#endif  // COMMON_SOURCE_MKCOLLISIONRESULT_H
