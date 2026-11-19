#include "spyro/source/FXBase.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDPropEx.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern s32 gViewSeed;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void FXBase::Burst(const MKVector3 &arg0) {
    Matrix sp130;
    M2C_UNK sp12C;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    MKVector3 spE0;
    M2C_UNK spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_93;
    f32 temp_f26_89;
    f32 temp_f28_38;
    f32 temp_f29_109;
    f32 temp_f2_182;
    f32 temp_f30_48;
    f64 temp_f0_175;
    s32 var_r28_41;
    void *temp_r30_37;

    temp_r30_37 = checked_cast<FXBaseDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_f28_38 = arg0.unk8;
    var_r28_41 = 0;
loop_2:
    if (var_r28_41 < (s32) M2C_FIELD(temp_r30_37, s32 *, 0xC0)) {
        temp_f30_48 = MKRand_Float(&gViewSeed, M2C_FIELD(temp_r30_37, f32 *, 0xD0), M2C_FIELD(temp_r30_37, f32 *, 0xD4));
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.0f, -1.0f);
        KDRand_Vector(spF0, spE0);
        sp40 = spF0 * (f64) temp_f30_48;
        sp100 = sp40;
        sp48 = spF0.unk8 * temp_f30_48;
        sp120 = sp40;
        sp108 = (f64) sp48;
        sp128 = (f64) sp48;
        M2C_STRUCT_COPY((s32) &sp12C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f26_89 = MKRand_Float(&gViewSeed, 0.0f, M2C_FIELD(temp_r30_37, f32 *, 0xC4));
        temp_f1_93 = MKRand_Float(&gViewSeed, 0.0f, M2C_FIELD(temp_r30_37, f32 *, 0xC4));
        sp38 = 0.0f;
        sp30 = temp_f1_93;
        sp34 = temp_f26_89;
        spC8 = (f64) sp38;
        spC0 = (f64) sp30;
        sp130.RotatePYR(&sp130, *((MKVector3 *) &spC0));
        temp_f29_109 = MKRand_Float(&gViewSeed, M2C_FIELD(temp_r30_37, f32 *, 0xC8), M2C_FIELD(temp_r30_37, f32 *, 0xCC));
        MKVector(0.0f, 1.0f, 0.0f);
        sp10 = sp130.unk30 + ((sp98 * sp130.unk20) + ((sp90 * M2C_BITWISE(f32, sp130)) + (sp94 * sp130.unk10)));
        sp14 = sp130.unk34 + ((sp98 * sp130.unk24) + ((sp90 * sp130.unk4) + (sp94 * sp130.unk14)));
        sp18 = sp130.unk38 + ((sp98 * sp130.unk28) + ((sp90 * sp130.unk8) + (sp94 * sp130.unk18)));
        spA0 = (f64) sp10;
        spA8 = (f64) sp18;
        sp20 = spA0 * (f64) temp_f29_109;
        sp110 = sp20;
        sp28 = (f32) spA8 * temp_f29_109;
        spB0 = sp20;
        sp118 = (f64) sp28;
        spB8 = (f64) sp28;
        MKRand_Float(&gViewSeed, M2C_FIELD(temp_r30_37, f32 *, 0xD8), M2C_FIELD(temp_r30_37, f32 *, 0xDC));
        sp50 = 1.0f;
        sp54 = 1.0f;
        sp58 = 1.0f;
        sp5C = 1.0f;
        sp70 = (f64) sp50;
        sp78 = (f64) sp58;
        temp_f0_175 = M2C_FIELD(&arg0, f64 *, 0) + sp120;
        sp60 = temp_f0_175;
        temp_f2_182 = temp_f28_38 + (f32) sp128;
        sp80 = temp_f0_175;
        sp68 = temp_f2_182;
        sp88 = (f64) sp68;
        Emit(sp80, sp110, &sp70, *temp_f2_182);
        var_r28_41 += 1;
        goto loop_2;
    }
}
#endif

void FXBase::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3) {

}

s32 FXBaseDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_232;

    var_r31_232 = 0;
    if ((KDPropExDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("iBurstCount", (int *) &this->unkC0, 0) != 0) || (arg0->LoadFloat("fBurstCone", &this->unkC4, 0) != 0) || (arg0->LoadFloat("fBurstMinVel", &this->unkC8, 0) != 0) || (arg0->LoadFloat("fBurstMaxVel", &this->unkCC, 0) != 0) || (arg0->LoadFloat("fBurstMinRadius", &this->unkD0, 0) != 0) || (arg0->LoadFloat("fBurstMaxRadius", &this->unkD4, 0) != 0) || (arg0->LoadFloat("fBurstMinScale", &this->unkD8, 0) != 0) || (arg0->LoadFloat("fBurstMaxScale", &this->unkDC, 0) != 0)) {
        var_r31_232 = 1;
    }
    return var_r31_232;
}

void FXBaseDescriptor::Init() {
    KDPropExDescriptor::Init();
    this->unkC0 = 0;
    this->unkC4 = 0.0f;
    this->unkC8 = 0.0f;
    this->unkCC = 0.0f;
    this->unkD0 = 0.0f;
    this->unkD4 = 0.0f;
    this->unkD8 = 0.0f;
    this->unkDC = 0.0f;
}
