#include "spyro/source/SplineProp.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDSpline.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
#if 0 // DRAFT: undefined identifier 'sp48'
static BoundingVolume volume;                       /* type too large by 0x10; unable to generate initializer: not enough data */

void SplineProp::CalcBounds() {
    f64 spB0;
    f64 spA8;
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
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_103;
    f32 temp_f1_117;
    f32 temp_f1_138;
    f32 temp_f1_67;
    f32 temp_f1_76;
    f32 temp_f1_85;
    f32 temp_f1_94;
    f32 temp_f2_53;
    f32 var_f0_102;
    f32 var_f0_66;
    f32 var_f0_75;
    f32 var_f0_84;
    f32 var_f0_93;
    f32 var_f1_56;
    s32 temp_r4_35;
    s32 var_r6_12;
    void *temp_r5_36;

    var_r6_12 = 0;
    sp38 = 9.99999e7f;
    sp3C = 9.99999e7f;
    sp40 = 9.99999e7f;
    M2C_FIELD(this, f64 *, 0x90) = (f64) sp38;
    sp30 = -9.99999e7f;
    sp28 = -9.99999e7f;
    sp2C = -9.99999e7f;
    M2C_FIELD(this, f64 *, 0x98) = (f64) sp40;
    M2C_FIELD(this, f64 *, 0xA0) = (f64) sp28;
    sp98 = (f64) sp38;
    spA0 = (f64) sp40;
    sp88 = (f64) sp28;
    sp90 = (f64) sp30;
    M2C_FIELD(this, f64 *, 0xA8) = (f64) sp30;
loop_20:
    if (var_r6_12 < (s32) M2C_FIELD(this->unk50.unk60, s32 *, 0x20)) {
        temp_r4_35 = this->unk50.unk60;
        temp_r5_36 = this->unk8;
        sp78 = M2C_FIELD(temp_r5_36, f64 *, 0x30);
        sp80 = M2C_FIELD(temp_r5_36, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        temp_f2_53 = this->unk50.unk40;
        spA8 = sp48;
        sp50 = M2C_FIELD((M2C_FIELD(temp_r4_35, s32 *, 0x24) + (var_r6_12 * M2C_FIELD(temp_r4_35, s32 *, 0x1C))), f32 *, 8) - (f32) sp80;
        var_f1_56 = (f32) spA8;
        spB0 = (f64) sp50;
        if (var_f1_56 < temp_f2_53) {

        } else {
            var_f1_56 = temp_f2_53;
        }
        this->unk50.unk40 = var_f1_56;
        var_f0_66 = unkspAC;
        temp_f1_67 = this->unk50.unk44;
        if (var_f0_66 < temp_f1_67) {

        } else {
            var_f0_66 = temp_f1_67;
        }
        this->unk50.unk44 = var_f0_66;
        var_f0_75 = (f32) spB0;
        temp_f1_76 = this->unk50.unk48;
        if (var_f0_75 < temp_f1_76) {

        } else {
            var_f0_75 = temp_f1_76;
        }
        this->unk50.unk48 = var_f0_75;
        var_f0_84 = (f32) spA8;
        temp_f1_85 = this->unk50.unk50;
        if (var_f0_84 > temp_f1_85) {

        } else {
            var_f0_84 = temp_f1_85;
        }
        this->unk50.unk50 = var_f0_84;
        var_f0_93 = unkspAC;
        temp_f1_94 = this->unk50.unk54;
        if (var_f0_93 > temp_f1_94) {

        } else {
            var_f0_93 = temp_f1_94;
        }
        this->unk50.unk54 = var_f0_93;
        var_f0_102 = (f32) spB0;
        temp_f1_103 = this->unk50.unk58;
        if (var_f0_102 > temp_f1_103) {

        } else {
            var_f0_102 = temp_f1_103;
        }
        this->unk50.unk58 = var_f0_102;
        var_r6_12 += 1;
        goto loop_20;
    }
    temp_f1_117 = this->unk50.unk64;
    if (temp_f1_117 != 0.0f) {
        sp18 = temp_f1_117;
        sp1C = temp_f1_117;
        sp20 = temp_f1_117;
        sp68 = (f64) sp18;
        sp70 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r3, $r0, 0x0, qr0 */);
        this->unk50.unk48 -= (f32) sp70;
        temp_f1_138 = this->unk50.unk64;
        sp10 = temp_f1_138;
        sp8 = temp_f1_138;
        spC = temp_f1_138;
        sp60 = (f64) sp10;
        sp58 = (f64) sp8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r3, $r0, 0x0, qr0 */);
        this->unk50.unk58 += (f32) sp60;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r3, $r4, 0x0, qr0 */);
    this->unk50.unk58 -= this->unk50.unk48;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void SplineProp::LoadDone() {
    KDUniformSpline sp10;
    f32 sp8;

    sp8 = 0.0f;
    sp10.GetMeasure(0.0f, this->unk50.unk60 + 0x30, KDSpline_PositionMixer);
    M2C_FIELD(&loadInfo, f64 *, 0x40) = M2C_BITWISE(f64, sp10);
    M2C_FIELD(&loadInfo, f64 *, 0x48) = (f64) sp10.unk8;
    MKProp::LoadDone();
    this->unk8 = &this->unk50;
    M2C_STRUCT_COPY((s32) &this->unk4C + 4, (s32) (&loadInfo - 4) + 4, 0x40);
    this->unk50.SetRotationToNone();
    CalcBounds();
    this->unkC = (BoundingVolume *) &this->unk50.unk40;
    this->unk50.unk60->LoadDone();
}
#endif

#if 0 // DRAFT: pointer/array required
s32 SplineProp::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if ((arg0->IsField("waypoints") != 0) && (arg0->GetNmbrOfSubLines() > 0)) {
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x30) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x34) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x38) = 0.0f;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x3C) = 0;
        }
        this->unk50.unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk50.unk60->Init();
        M2C_FIELD(this->unk50.unk60, s8 *, 0x44) = 0;
        this->unk50.unk60->LoadLine(arg0);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void SplineProp::Deinit() {
    s32 temp_r3_292;

    temp_r3_292 = this->unk50.unk60;
    if ((u32) temp_r3_292 != 0U) {
        temp_r3_292->Deinit();
        operator delete((void *) this->unk50.unk60);
        this->unk50.unk60 = 0;
    }
    MKProp::Deinit();
}
#endif

void SplineProp::Init() {
    MKProp::Init();
    this->unk50.unk60 = 0;
    this->unk50.unk64 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'volume'
void SplinePropDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk1C = &volume;
}
#endif

#if 0 // DRAFT: undefined identifier 'volume'
void SplineProp_cpp::__sinit() {
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp18 = -0.5f;
    sp20 = -0.5f;
    sp1C = -0.5f;
    sp10 = 1.0f;
    sp8 = 1.0f;
    M2C_FIELD(&volume, f64 *, 0) = (f64) sp18;
    spC = 1.0f;
    M2C_FIELD(&volume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(&volume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(&volume, f64 *, 0x18) = (f64) sp10;
}
#endif
