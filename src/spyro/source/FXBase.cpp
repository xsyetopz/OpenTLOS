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
    f32 temp_f1_93;
    f32 temp_f26_89;
    f32 temp_f28_38;
    f32 temp_f29_109;
    f32 temp_f2_182;
    f32 temp_f30_48;
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
        KDRand_Vector(*((MKVector3 *) &arg_spF0), *((MKVector3 *) &arg_spE0));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        arg_sp100 = arg_sp40;
        arg_sp48 = arg_spF8 * temp_f30_48;
        arg_sp120 = arg_sp40;
        arg_sp108 = (f64) arg_sp48;
        arg_sp128 = (f64) arg_sp48;
        M2C_STRUCT_COPY((s32) &arg_sp12C + 4, (s32) (&identity - 4) + 4, 0x40);
        temp_f26_89 = MKRand_Float(&gViewSeed, 0.0f, M2C_FIELD(temp_r30_37, f32 *, 0xC4));
        temp_f1_93 = MKRand_Float(&gViewSeed, 0.0f, M2C_FIELD(temp_r30_37, f32 *, 0xC4));
        arg_sp38 = 0.0f;
        arg_sp30 = temp_f1_93;
        arg_sp34 = temp_f26_89;
        arg_spC8 = (f64) arg_sp38;
        arg_spC0 = (f64) arg_sp30;
        arg_sp130.RotatePYR((Matrix *) &arg_sp130, *((MKVector3 *) &arg_spC0));
        temp_f29_109 = MKRand_Float(&gViewSeed, M2C_FIELD(temp_r30_37, f32 *, 0xC8), M2C_FIELD(temp_r30_37, f32 *, 0xCC));
        MKVector(0.0f, 1.0f, 0.0f);
        arg_sp10 = arg_sp160 + ((arg_sp98 * arg_sp150) + ((arg_sp90 * arg_sp130) + (arg_sp94 * arg_sp140)));
        arg_sp14 = arg_sp164 + ((arg_sp98 * arg_sp154) + ((arg_sp90 * arg_sp134) + (arg_sp94 * arg_sp144)));
        arg_sp18 = arg_sp168 + ((arg_sp98 * arg_sp158) + ((arg_sp90 * arg_sp138) + (arg_sp94 * arg_sp148)));
        arg_spA0 = (f64) arg_sp10;
        arg_spA8 = (f64) arg_sp18;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        arg_sp110 = arg_sp20;
        arg_sp28 = (f32) arg_spA8 * temp_f29_109;
        arg_spB0 = arg_sp20;
        arg_sp118 = (f64) arg_sp28;
        arg_spB8 = (f64) arg_sp28;
        MKRand_Float(&gViewSeed, M2C_FIELD(temp_r30_37, f32 *, 0xD8), M2C_FIELD(temp_r30_37, f32 *, 0xDC));
        arg_sp50 = 1.0f;
        arg_sp54 = 1.0f;
        arg_sp58 = 1.0f;
        arg_sp5C = 1.0f;
        arg_sp70 = (f64) arg_sp50;
        arg_sp78 = (f64) arg_sp58;
        M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        temp_f2_182 = temp_f28_38 + (f32) arg_sp128;
        arg_sp80 = arg_sp60;
        arg_sp68 = temp_f2_182;
        arg_sp88 = (f64) arg_sp68;
        Emit(arg_sp80, arg_sp110, &arg_sp70, *temp_f2_182);
        var_r28_41 += 1;
        goto loop_2;
    }
}
#endif

void FXBase::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3) {

}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 FXBaseDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_232;

    var_r31_232 = 0;
    if ((KDPropExDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("iBurstCount", &this->unkC0, 0) != 0) || (arg0->LoadFloat("fBurstCone", &this->unkC4, 0) != 0) || (arg0->LoadFloat("fBurstMinVel", &this->unkC8, 0) != 0) || (arg0->LoadFloat("fBurstMaxVel", &this->unkCC, 0) != 0) || (arg0->LoadFloat("fBurstMinRadius", &this->unkD0, 0) != 0) || (arg0->LoadFloat("fBurstMaxRadius", &this->unkD4, 0) != 0) || (arg0->LoadFloat("fBurstMinScale", &this->unkD8, 0) != 0) || (arg0->LoadFloat("fBurstMaxScale", &this->unkDC, 0) != 0)) {
        var_r31_232 = 1;
    }
    return var_r31_232;
}
#endif

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
