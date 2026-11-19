#include "spyro/source/CharacterDojoFX.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/EmbersPS.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void CharacterDojoFX::Emit() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_85;
    f64 temp_f0_52;
    f64 temp_f0_95;
    s32 var_r29_36;
    void *temp_r31_41;
    void *temp_r3_44;

    this->unk28 -= gUpdateTimeDelta;
    if (this->unk28 <= 0.0f) {
        this->unk28 = 0.0f;
        var_r29_36 = 0;
        do {
            temp_r31_41 = GetRandomNode(NULL);
            temp_r3_44 = GetRandomNode(NULL);
            if ((temp_r31_41 != NULL) && (temp_r3_44 != NULL)) {
                temp_f0_52 = M2C_FIELD(temp_r3_44, f64 *, 8) - M2C_FIELD(temp_r31_41, f64 *, 8);
                sp40 = temp_f0_52;
                sp70 = temp_f0_52;
                sp48 = M2C_FIELD(temp_r3_44, f32 *, 0x10) - M2C_FIELD(temp_r31_41, f32 *, 0x10);
                sp78 = (f64) sp48;
                sp30 = temp_f0_52 * 5.222099017e-315;
                sp38 = (f32) sp78 * 0.5f;
                sp80 = sp30;
                sp88 = (f64) sp38;
                sp8 = 3.0f * M2C_FIELD(M2C_FIELD(temp_r31_41, void **, 0), f32 *, 0x10);
                temp_f1_85 = 100.0f * MKRand_Float(&gViewSeed, 1.0f, 1.5f);
                sp18 = 0.0f;
                sp10 = 0.0f;
                sp14 = temp_f1_85;
                sp58 = (f64) sp18;
                sp50 = (f64) sp10;
                temp_f0_95 = M2C_FIELD(temp_r31_41, f64 *, 8) + sp80;
                sp20 = temp_f0_95;
                sp60 = temp_f0_95;
                sp28 = M2C_FIELD(temp_r31_41, f32 *, 0x10) + (f32) sp88;
                sp68 = (f64) sp28;
                ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp60), *((MKVector3 *) &sp50), sp8, this->unk18, 0.0f);
            }
            var_r29_36 += 1;
        } while (var_r29_36 < 5);
    }
}
#endif

void CharacterDojoFX::Enable(bool arg0, MKVector4 arg1) {
    if (arg0 != 0) {
        this->unk2C = 1;
    } else {
        this->unk2C = 0;
    }
    this->unk18 = arg1;
    SetDataActive(arg0);
}

void CharacterDojoFX::Deinit() {
    CharacterBodyFX::Deinit();
}

void CharacterDojoFX::Update() {
    s32 temp_r0_174;

    CharacterBodyFX::Update();
    temp_r0_174 = this->unk2C;
    if (temp_r0_174 != 1) {
        if ((temp_r0_174 < 1) && (temp_r0_174 < 0)) {

        }
    } else {
        Emit();
    }
}

void CharacterDojoFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    CharacterBodyFX::InitData(arg0, arg1, arg2);
}

void CharacterDojoFX::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    CharacterBodyFX::Init();
    sp8 = 1.0f;
    this->unk28 = 0.0f;
    spC = 1.0f;
    this->unk2C = 0;
    sp10 = 1.0f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0x18) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x20) = (f64) sp10;
}
