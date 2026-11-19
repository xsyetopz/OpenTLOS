#ifndef SPYRO_SOURCE_KDCAMERAHERODATA_H
#define SPYRO_SOURCE_KDCAMERAHERODATA_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class HeroDataMessage;
class KDCameraHeroData;
class MKVector3;
class Matrix;

class KDCameraHeroData {
public:
    u8 IsMoving(void);
    void Copy(HeroDataMessage &);
    MKVector3 GetDir(void);
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ Matrix unk10;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ u8 pad60[0x34];
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 pad95[0x13];
    /* 0x0a8 */ void* unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ u8 padB4[0x14];
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f32 unkD0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline u8 KDCameraHeroData::IsMoving() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f1_4107;

    temp_f1_4107 = M2C_FIELD(this, f64 *, 0x40);
    sp38 = this->unkC8;
    sp48 = temp_f1_4107;
    sp40 = M2C_FIELD(this, f64 *, 0xD0);
    sp50 = M2C_FIELD(this, f64 *, 0x48);
    sp8 = temp_f1_4107 - sp38;
    sp18 = sp8;
    sp10 = (f32) sp50 - (f32) sp40;
    sp28 = sp8;
    sp20 = (f64) sp10;
    sp30 = (f64) sp10;
    return ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * (*(f32 *) ((u8 *) &sp18 + 0x4))))) < 1.0f) == 0;
}

#if 0 // DRAFT: undefined identifier 'unkC0'
inline void KDCameraHeroData::Copy(HeroDataMessage &arg0) {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f64 temp_f0_818;
    f64 temp_f0_890;
    f64 temp_f1_817;
    f64 temp_f1_888;
    u8 temp_r30_823;
    void *temp_r31_821;
    void *temp_r5_816;

    temp_r5_816 = this->unkC0;
    temp_f1_817 = M2C_FIELD(this, f64 *, 0x40);
    temp_f0_818 = M2C_FIELD(this, f64 *, 0x48);
    sp88 = temp_f1_817;
    temp_r31_821 = this->unkA8;
    sp90 = temp_f0_818;
    temp_r30_823 = this->unk94;
    sp98 = temp_f1_817;
    spA0 = temp_f0_818;
    if ((temp_r5_816 != NULL) && ((u32) M2C_FIELD(temp_r5_816, u32 *, 8) != 0U)) {
        ((HeroDataMessage *) this)->ClearData();
        ((HeroDataMessage *) this)->Init(M2C_FIELD(this->unkC0, Matrix **, 8));
        this->unkA8 = this->unkC0;
    } else {
        this->unk0 = arg0.unk0;
        this->unk4 = arg0.unk4;
        M2C_STRUCT_COPY((s32) &this->unkC + 4, (s32) arg0.unkC + 4, 0x40);
        this->unk50 = arg0.unk50;
        this->unk58 = arg0.unk58;
        this->unk60 = arg0.unk60;
        this->unk68 = arg0.unk68;
        this->unk70 = arg0.unk70;
        this->unk78 = arg0.unk78;
        this->unk80 = arg0.unk80;
        this->unk88 = arg0.unk88;
        this->unk90 = arg0.unk90;
        this->unk94 = arg0.unk94;
        this->unk98 = arg0.unk98;
        this->unk9C = arg0.unk9C;
        this->unkA0 = arg0.unkA0;
        this->unkA4 = arg0.unkA4;
        this->unkA8 = arg0.unkA8;
        this->unkAC = arg0.unkAC;
        this->unkB0 = arg0.unkB0;
    }
    temp_f1_888 = M2C_FIELD(this, f64 *, 0x40);
    temp_f0_890 = M2C_FIELD(this, f64 *, 0x48);
    sp78 = temp_f1_888;
    sp8 = temp_f1_888;
    sp10 = temp_f0_890;
    sp80 = temp_f0_890;
    sp18 = this->unkC8 - sp78;
    sp28 = sp18;
    sp20 = this->unkD0 - (f32) sp80;
    sp38 = sp18;
    sp30 = (f64) sp20;
    sp40 = (f64) sp20;
    if ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU) == 0) || (temp_r31_821 != (void *) this->unkA8)) {
        this->unkC8 = sp8;
        M2C_FIELD(this, f32 *, 0xD0) = sp10;
        sp68 = sp8;
        sp70 = sp10;
        if ((u8) this->unk94 != 0) {
            sp58 = M2C_FIELD(this, f64 *, 0x40);
            sp60 = M2C_FIELD(this, f64 *, 0x48);
            M2C_FIELD(this, f32 *, 0xD8) = (*(f32 *) ((u8 *) &sp58 + 0x4));
        }
    } else {
        this->unkC8 = sp98;
        M2C_FIELD(this, f32 *, 0xD0) = spA0;
    }
    if ((temp_r30_823 == 0) && ((u8) this->unk94 != 0)) {
        sp48 = M2C_FIELD(this, f64 *, 0x40);
        sp50 = M2C_FIELD(this, f64 *, 0x48);
        M2C_FIELD(this, f32 *, 0xD8) = (*(f32 *) ((u8 *) &sp48 + 0x4));
    }
}
#endif

#if 0 // DRAFT: identifier 'KDCameraHeroData::GetDir()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
inline void KDCameraHeroData::GetDir() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_5287;

    temp_f0_5287 = M2C_FIELD(this, f64 *, 0x30) * 1.58735232e-314;
    sp8 = temp_f0_5287;
    M2C_FIELD(sret, f64 *, 0) = temp_f0_5287;
    sp10 = this->unk10.unk28 * -1.0f;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10;
    return result;
}
#endif

#endif  // SPYRO_SOURCE_KDCAMERAHERODATA_H
