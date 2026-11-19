#include "spyro/source/SparkleEffect.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/MKMaterial_GC.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

void SparkleEffect::FindNewSparklePoint() {

}

void SparkleEffect::Deinit() {
    this->unk4C = NULL;
    MKProp::Deinit();
}

void SparkleEffect::Draw() {
    MKMaterial_SetMaterial(M2C_FIELD(this->unk0, MKMaterial **, 0x38));
}

void *SparkleEffect::Update() {
    f32 temp_f1_125;
    f32 temp_f1_128;
    f32 var_f2_104;
    f32 var_f2_118;
    s32 var_ctr_85;
    s32 var_r4_82;
    void *temp_r5_87;

    var_r4_82 = 0;
    var_ctr_85 = 0xA;
    do {
        temp_r5_87 = this + var_r4_82;
        if ((u8) M2C_FIELD(temp_r5_87, u8 *, 0x54) != 0) {
            M2C_FIELD(temp_r5_87, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r5_87, f32 *, 0x58) + gUpdateTimeDelta);
            if ((u8) this->unk124 != 0) {
                var_f2_104 = (2.0f * (M2C_FIELD(temp_r5_87, f32 *, 0x58) / 3.0f)) - 1.0f;
                if (var_f2_104 < 0.0f) {
                    var_f2_104 = -var_f2_104;
                }
                M2C_FIELD(temp_r5_87, f32 *, 0x60) = (f32) (1.0f - var_f2_104);
            } else {
                var_f2_118 = 0.5f * (0.75f * gUpdateTimeDelta);
                if (var_f2_118 < 1.0f) {

                } else {
                    var_f2_118 = 1.0f;
                }
                temp_f1_125 = M2C_FIELD(temp_r5_87, f32 *, 0x60);
                temp_f1_128 = (var_f2_118 * (1.0f - temp_f1_125)) + temp_f1_125;
                M2C_FIELD(temp_r5_87, f32 *, 0x60) = (f32) ((var_f2_118 * (1.0f - temp_f1_128)) + temp_f1_128);
            }
            if ((M2C_FIELD(temp_r5_87, f32 *, 0x58) >= 3.0f) && ((((u8) M2C_FIELD(temp_r5_87, u8 *, 0x5C) == 0) && ((u8) this->unk124 == 0)) || ((u8) this->unk124 != 0))) {
                M2C_FIELD(temp_r5_87, u8 *, 0x54) = 0U;
            }
        }
        var_r4_82 += 0x14;
        var_ctr_85 -= 1;
    } while (var_ctr_85 != 0);
    this->unk11C += gUpdateTimeDelta;
    if (this->unk11C >= this->unk118) {
        this->unk11C = 0.0f;
        FindNewSparklePoint();
    }
}

s32 SparkleEffect::LoadDone() {
    MKProp::LoadDone();
}

#if 0 // DRAFT: illegal operand
void SparkleEffect::Init() {
    s32 temp_r0_208;
    s32 var_ctr_206;
    s32 var_r3_200;

    MKProp::Init();
    this->unk4C = NULL;
    var_r3_200 = 0;
    this->unk118 = 1.0f;
    this->unk11C = 0.0f;
    this->unk128 = 0;
    this->unk120 = 1.0f;
    this->unk124 = 0;
    var_ctr_206 = 0xA;
    do {
        temp_r0_208 = var_r3_200 + 0x54;
        var_r3_200 += 0x14;
        *(this + temp_r0_208) = 0;
        var_ctr_206 -= 1;
    } while (var_ctr_206 != 0);
}
#endif
