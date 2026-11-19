#include "spyro/source/KDCameraMessages.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

void HeroDataMessage::ClearData() {
    this->unk0 = 0x40A;
    this->unk10.SetIdentity();
    this->unk50 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk58 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk60 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk68 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk70 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk80 = M2C_FIELD(&MKVector3::up, f64 *, 0);
    this->unk88 = M2C_FIELD(&MKVector3::up, f64 *, 8);
    this->unk90 = 0.0f;
    this->unk98 = 0.001f;
    this->unk9C = 0;
    this->unkA0 = 7;
    this->unk94 = 0;
    this->unkA4 = NULL;
    this->unkA8 = NULL;
    this->unkAC = 0.0f;
    this->unkB0 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unkC'
void HeroDataMessage::Init(const Matrix *arg0) {
    f64 sp60;
    f64 sp58;
    M2C_UNK sp48;
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp10;

    ClearData();
    M2C_STRUCT_COPY((s32) &this->unkC + 4, (s32) (arg0 - 4) + 4, 0x40);
    this->unk98 = 50.0f;
    MKVector(0.0f, this->unk98, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk50 = sp18;
    sp20 = this->unk10.unk38 + sp50;
    sp58 = sp18;
    sp60 = (f64) sp20;
    this->unk58 = (f64) sp20;
    MKVector(0.0f, 80.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk70 = sp8;
    sp10 = this->unk10.unk38 + sp30;
    sp38 = sp8;
    sp40 = (f64) sp10;
    this->unk78 = (f64) sp10;
}
#endif
