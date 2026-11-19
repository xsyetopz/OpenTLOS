#include "common/Source/MKMat_MK2_FFTWater.h"
#include "common/Source/MKMaterial_Util.h"
#include <m2c_macros.h>

static M2C_UNK platformDataXB;                      /* unable to generate initializer: unknown type */
static M2C_UNK platformDataPC;                      /* unable to generate initializer: unknown type */
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKMaterialTypeInfo'
static MKMaterialTypeInfo typeInfoGC;               /* unable to generate initializer: confusing struct layout */
#endif

void MKMaterial_LinkMaterial_MK2_FFTWater() {
    MKMaterial_LinkMaterialGC_MK2_FFTWater();
}

#if 0 // DRAFT: undefined identifier 'typeInfoGC'
void MKMaterial_LinkMaterialGC_MK2_FFTWater() {
    MKMaterialInternal_AddTypeToList(&typeInfoGC);
}
#endif

void MKMat_MK2_FFTWater_cpp::__sinit() {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp84 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 0.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    sp60 = 1.0f;
    sp64 = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp54 = 0.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 0.0f;
    sp44 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    M2C_FIELD(&platformDataXB, f64 *, 0x18) = (f64) sp78;
    M2C_FIELD(&platformDataXB, f64 *, 0x20) = (f64) sp80;
    M2C_FIELD(&platformDataXB, f64 *, 0x38) = (f64) sp68;
    M2C_FIELD(&platformDataXB, f64 *, 0x40) = (f64) sp70;
    M2C_FIELD(&platformDataXB, f64 *, 0x58) = (f64) sp58;
    M2C_FIELD(&platformDataXB, f64 *, 0x60) = (f64) sp60;
    M2C_FIELD(&platformDataXB, f64 *, 0x78) = (f64) sp48;
    M2C_FIELD(&platformDataXB, f64 *, 0x80) = (f64) sp50;
    M2C_FIELD(&platformDataPC, f64 *, 0x18) = (f64) sp38;
    M2C_FIELD(&platformDataPC, f64 *, 0x20) = (f64) sp40;
    M2C_FIELD(&platformDataPC, f64 *, 0x38) = (f64) sp28;
    M2C_FIELD(&platformDataPC, f64 *, 0x40) = (f64) sp30;
    M2C_FIELD(&platformDataPC, f64 *, 0x58) = (f64) sp18;
    M2C_FIELD(&platformDataPC, f64 *, 0x60) = (f64) sp20;
    M2C_FIELD(&platformDataPC, f64 *, 0x78) = (f64) sp8;
    M2C_FIELD(&platformDataPC, f64 *, 0x80) = (f64) sp10;
}
