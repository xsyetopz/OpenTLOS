#include "spyro/source/ShatterableBoat.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/WaterSurfaceFX.h"
#include "unplaced_templates.h"
#include "common/Source/OmniLight.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
extern s32 GS_PLACEHOLDER;
extern s32 GS_ShipExtra2;
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
static s8 *pLeftOarAnimEvents = lit_stringBase0;
#endif
#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
static s8 *pRightOarAnimEvents = lit_stringBase0;
#endif

static s32 lit_853 = 0;
#if 0 // DRAFT: undefined identifier 'unk234'
static s8 lit_stringBase0[0xC1] = {
    0x45,
    0x6E,
    0x74,
    0x65,
    0x72,
    0x57,
    0x61,
    0x74,
    0x65,
    0x72,
    0,
    0x73,
    0x70,
    0x65,
    0x65,
    0x64,
    0,
    0x77,
    0x61,
    0x74,
    0x65,
    0x72,
    0x68,
    0x65,
    0x69,
    0x67,
    0x68,
    0x74,
    0,
    0x77,
    0x61,
    0x79,
    0x70,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0x73,
    0,
    0x70,
    0x37,
    0x30,
    0x30,
    0x37,
    0x5F,
    0x73,
    0x68,
    0x69,
    0x70,
    0x5F,
    0x6F,
    0x61,
    0x72,
    0x5F,
    0x6C,
    0x65,
    0x66,
    0x74,
    0,
    0x72,
    0x6F,
    0x77,
    0,
    0x69,
    0x64,
    0x6C,
    0x65,
    0,
    0x70,
    0x37,
    0x30,
    0x30,
    0x38,
    0x5F,
    0x73,
    0x68,
    0x69,
    0x70,
    0x5F,
    0x6F,
    0x61,
    0x72,
    0x5F,
    0x72,
    0x69,
    0x67,
    0x68,
    0x74,
    0,
    0x72,
    0x5F,
    0x70,
    0x6F,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x5F,
    0x6F,
    0x61,
    0x72,
    0x25,
    0x64,
    0,
    0x66,
    0x78,
    0x65,
    0x6D,
    0x69,
    0x74,
    0x4C,
    0x30,
    0,
    0x66,
    0x78,
    0x65,
    0x6D,
    0x69,
    0x74,
    0x52,
    0x30,
    0,
    0x57,
    0x61,
    0x74,
    0x65,
    0x72,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x73,
    0x50,
    0x53,
    0,
    0x57,
    0x61,
    0x74,
    0x65,
    0x72,
    0x53,
    0x75,
    0x72,
    0x66,
    0x61,
    0x63,
    0x65,
    0x46,
    0x58,
    0,
    0x70,
    0x37,
    0x30,
    0x30,
    0x39,
    0x5F,
    0x57,
    0x61,
    0x74,
    0x65,
    0x72,
    0x57,
    0x61,
    0x6B,
    0x65,
    0,
    0x41,
    0x6D,
    0x62,
    0x69,
    0x65,
    0x6E,
    0x74,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0x4C,
    0x6F,
    0x6F,
    0x70,
    0,
    0x73,
    0x6E,
    0x64,
    0x53,
    0x69,
    0x6E,
    0x6B,
    0,
}; /* const */

void ShatterableBoat::SetDefaults() {
    Shatterable::Reset();
    this->unk234 = 1;
    M2C_FIELD(this, f32 *, 0x22C) = 0.0f;
    this->unk220 = 0.0f;
    this->unk224 = 0.0f;
    this->unk230 = 0.0f;
    this->unk234->SetAnim(M2C_BITWISE(MKAnim *, this->unk23C), 1.0f, 0.0f, 0, -1);
    this->unk240->SetAnim(M2C_BITWISE(MKAnim *, this->unk248), 1.0f, 0.0f, 0, -1);
    this->unk1A8.unk8.SimpleMessageAttached(0xD5);
    this->unk318 = 0.0f;
    this->unk31C = 0.0f;
    this->unk320 = 0.0f;
    Update();
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 ShatterableBoat::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;

    MKVector(0.0f, 100.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + sp20;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 ShatterableBoat::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;

    MKVector(0.0f, 100.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + sp20;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk234'
void ShatterableBoat::Deinit() {
    this->unk234->Destroy();
    this->unk240->Destroy();
    this->unk218.Deinit();
    MKModel_Destroy(this->unk310);
    if ((s32) M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x16C) != 0) {
        KDSound_Stop((s32 *) &this->unk320);
    }
    ShatterablePlatform::Deinit();
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Draw() {
    f32 temp_f3_402;
    s32 var_r28_318;
    s32 var_r30_319;
    u8 temp_r28_417;
    u8 temp_r29_434;
    void *temp_r29_321;
    Shatterable::Draw();
    if ((MKProp *) this->unk170 < (s32) (M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160) - 1)) {
        M2C_STRUCT_COPY((s32) &arg_spEC + 4, (s32) (this->unk8 - 4) + 4, 0x40);
        var_r28_318 = 0;
        var_r30_319 = 0;
        do {
            temp_r29_321 = this + var_r30_319;
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r29_321, s32 *, 0x274), (MKVector3 *) &arg_spA0);
            arg_sp120 = arg_spA0;
            arg_sp124 = arg_spA4;
            arg_sp128 = arg_spA8;
            arg_sp12C = 1.0f;
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r29_321, MKModel **, 0x270), *((Matrix *) &arg_spF0));
            MKModel_Draw(M2C_FIELD(temp_r29_321, MKModel **, 0x270), NULL);
            var_r28_318 += 1;
            var_r30_319 += 0x10;
        } while (var_r28_318 < 0xA);
    }
    M2C_STRUCT_COPY((s32) &arg_spAC + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    arg_sp18 = 0.0f;
    arg_sp90 = arg_spD0;
    arg_sp70 = arg_spB0;
    arg_sp98 = arg_spD8;
    arg_sp88 = (f64) arg_sp18;
    arg_sp78 = arg_spB8;
    arg_sp10 = 0.0f;
    arg_sp14 = 1.0f;
    arg_sp94 = 0.0f;
    arg_sp80 = (f64) arg_sp10;
    arg_sp50 = (f64) arg_sp10;
    arg_sp58 = (f64) arg_sp18;
    arg_sp74 = 0.0f;
    arg_spB0 = (f32) arg_sp70;
    arg_spB4 = 0.0f;
    arg_spB8 = (f32) arg_sp78;
    arg_spBC = 0.0f;
    arg_spC0 = (f32) arg_sp80;
    arg_spC4 = arg_sp84;
    arg_spC8 = (f32) arg_sp88;
    arg_spCC = 0.0f;
    arg_spD0 = (f32) arg_sp90;
    arg_spD4 = 0.0f;
    arg_spD8 = (f32) arg_sp98;
    arg_spDC = 0.0f;
    arg_sp40.NormaliseScale();
    arg_sp60 = arg_spE0;
    temp_f3_402 = this->unk314;
    arg_sp68 = arg_spE8;
    arg_spE0 = (f32) arg_sp60;
    arg_spE4 = temp_f3_402;
    arg_spE8 = (f32) arg_sp68;
    arg_spEC = 1.0f;
    arg_sp64 = temp_f3_402;
    MKModel_SetWorldMatrix(this->unk310, *((Matrix *) &arg_spB0));
    temp_r28_417 = MKMaterial_EnableFog(0U);
    arg_sp20 = 1.0f;
    arg_sp24 = 1.0f;
    arg_sp28 = 1.0f;
    arg_sp2C = this->unk20;
    arg_sp30 = (f64) arg_sp20;
    arg_sp38 = (f64) arg_sp28;
    MKModel_SetColor(this->unk310, *((MKVector4 *) &arg_sp30));
    temp_r29_434 = OmniLight_SuspendAll(1U);
    MKModel_Draw(this->unk310, NULL);
    OmniLight_SuspendAll(temp_r29_434);
    MKMaterial_EnableFog(temp_r28_417);
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Message(MKMessage *arg0) {
    f32 temp_r3_539;
    s32 temp_r0_469;
    s32 temp_r0_511;
    s32 var_r0_516;
    s32 var_r4_510;

    if ((s32) M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x16C) != 0) {
        this->unk320.Message(arg0);
    }
    temp_r0_469 = arg0->unk0;
    switch (temp_r0_469) {                          /* irregular */
    case 0xB5:
        if ((s32) this->unk234 == 1) {
            this->unk234 = 0;
            this->unk234->SetAnim((MKAnim *) this->unk238, 1.0f, 0.0f, 0, -1);
            this->unk240->SetAnim((MKAnim *) this->unk244, 1.0f, 0.0f, 0, -1);
        } else {
            var_r4_510 = M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160) - 1;
            temp_r0_511 = M2C_BITWISE(s32, this->unk220) + 1;
            if (temp_r0_511 < var_r4_510) {
                var_r4_510 = temp_r0_511;
            }
            var_r0_516 = lit_853;
            if (var_r4_510 > var_r0_516) {
                var_r0_516 = var_r4_510;
            }
            this->unk220 = M2C_BITWISE(f32, var_r0_516);
        }
    default:
block_23:
        ShatterablePlatform::Message(arg0);
        return;
    case 0xB4:
        this->unk234 = 1;
        return;
    case 0x5:
        KDSound_Play3d(GS_ShipExtra2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        goto block_23;
    case 0xBA:
        temp_r3_539 = this->unk220;
        if ((MKProp *) this->unk170 <= M2C_BITWISE(s32, temp_r3_539)) {
            this->unk170 = M2C_BITWISE(MKProp *, temp_r3_539);
            goto block_23;
        }
        break;
    case 0x15:
        SetDefaults();
        goto block_23;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'spD8'
void ShatterableBoat::EmitWaterSpray() {
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    MKVector3 sp238;
    f64 sp230;
    f64 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    MKVector3 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    M2C_UNK sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_814;
    f32 temp_f0_844;
    f32 temp_f31_768;
    s32 var_r28_716;
    s32 var_r29_704;
    void *temp_r27_829;
    void *temp_r3_826;
    void *temp_r5_574;
    void *temp_r5_611;
    void *temp_r5_767;

    temp_r5_574 = this->unk8;
    sp48 = -M2C_FIELD(temp_r5_574, f32 *, 0x20);
    sp4C = -M2C_FIELD(temp_r5_574, f32 *, 0x24);
    sp50 = -M2C_FIELD(temp_r5_574, f32 *, 0x28);
    sp268 = (f64) sp48;
    sp270 = (f64) sp50;
    sp278.operator*(4000.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp288 = spD8;
    spE0 = M2C_FIELD(this->unk8, f32 *, 0x38) + sp278.unk8;
    sp2C8 = spD8;
    sp290 = (f64) spE0;
    sp2D0 = (f64) spE0;
    sp218.operator*(1000.0f);
    temp_r5_611 = this->unk8;
    sp38 = -M2C_FIELD(temp_r5_611, f32 *, 0);
    sp3C = -M2C_FIELD(temp_r5_611, f32 *, 4);
    sp40 = -M2C_FIELD(temp_r5_611, f32 *, 8);
    sp228 = (f64) sp38;
    sp230 = (f64) sp40;
    sp238.operator*(1500.0f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp248 = sp28;
    sp30 = (f32) sp2D0 + sp238.unk8;
    sp250 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp258 = spC8;
    sp2D8 = spC8;
    spD0 = (f32) sp250 + sp218.unk8;
    sp260 = (f64) spD0;
    sp2E0 = (f64) spD0;
    sp1D8.operator*(1000.0f);
    sp1E8.operator*(1500.0f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    sp1F8 = sp18;
    sp20 = (f32) sp2D0 + sp1E8.unk8;
    sp200 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp208 = spB8;
    spC0 = (f32) sp200 + sp1D8.unk8;
    sp2B8 = spB8;
    sp210 = (f64) spC0;
    sp2C0 = (f64) spC0;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f0 */);
    sp1C8 = spA8;
    spB0 = (f32) sp2D0 - (f32) sp2E0;
    sp2A8 = spA8;
    sp1D0 = (f64) spB0;
    sp2B0 = (f64) spB0;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f0 */);
    var_r29_704 = 0;
    sp1B8 = sp98;
    spA0 = (f32) sp2D0 - (f32) sp2C0;
    sp298 = sp98;
    sp1C0 = (f64) spA0;
    sp2A0 = (f64) spA0;
    do {
        var_r28_716 = 0;
loop_2:
        if (var_r29_704 != 0) {
            sp198.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1A8 = sp88;
            sp90 = (f32) sp2E0 + sp198.unk8;
            sp2F8 = sp88;
            sp1B0 = (f64) sp90;
            sp300 = (f64) sp90;
        } else {
            sp178.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp188 = sp78;
            sp80 = (f32) sp2C0 + sp178.unk8;
            sp2F8 = sp78;
            sp190 = (f64) sp80;
            sp300 = (f64) sp80;
        }
        temp_r5_767 = this->unk8;
        temp_f31_768 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp8 = -M2C_FIELD(temp_r5_767, f32 *, 0x20);
        spC = -M2C_FIELD(temp_r5_767, f32 *, 0x24);
        sp10 = -M2C_FIELD(temp_r5_767, f32 *, 0x28);
        spF8 = (f64) sp8;
        sp100 = (f64) sp10;
        sp108.operator*(4000.0f);
        sp118.operator*(temp_f31_768);
        MKVector(1.0f, 2.0f, 1.0f);
        MKVector(-1.0f, 0.0f, -1.0f);
        KDRand_Vector(sp148, sp138);
        sp158.operator*(2000.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_814 = this->unk240;
        sp168 = sp68;
        sp70 = sp158.unk8 + sp118.unk8;
        sp2E8 = sp68;
        sp170 = (f64) sp70;
        sp2F0 = (f64) sp70;
        temp_r3_826 = M2C_FIELD(temp_r3_814->__vptr, void *(**)(MKProp *, f64), 0x3C)(temp_r3_814, sp68);
        if (temp_r3_826 != NULL) {
            temp_r27_829 = M2C_FIELD(temp_r3_826, void **, 0x2C);
            M2C_FIELD(temp_r3_826, f64 *, 0) = sp2F8;
            M2C_FIELD(temp_r3_826, f64 *, 8) = sp300;
            M2C_FIELD(temp_r3_826, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_826, f32 *, 0x28) = 0.0f;
            temp_f0_844 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp58 = 0.25f;
            sp5C = 0.25f;
            M2C_FIELD(temp_r3_826, f32 *, 0x24) = (f32) (2.0f * temp_f0_844);
            sp60 = 0.25f;
            sp64 = 1.0f;
            M2C_FIELD(temp_r3_826, f64 *, 0x10) = (f64) sp58;
            M2C_FIELD(temp_r3_826, f64 *, 0x18) = (f64) sp60;
            M2C_FIELD(temp_r27_829, f64 *, 0) = sp2E8;
            spE8 = (f64) sp58;
            spF0 = (f64) sp60;
            M2C_FIELD(temp_r27_829, f64 *, 8) = sp2F0;
            M2C_FIELD(temp_r27_829, f32 *, 0x18) = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
            M2C_FIELD(temp_r27_829, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r27_829, f32 *, 0x14) = (f32) M2C_FIELD(this->unk240, f32 *, 0xF4);
        }
        var_r28_716 += 1;
        if (var_r28_716 < 0xF) {
            goto loop_2;
        }
        var_r29_704 += 1;
    } while (var_r29_704 < 2);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk234'
void ShatterableBoat::UpdateMove() {
    f32 temp_f31_1285;
    f32 temp_f4_1271;
    f32 temp_f5_1267;
    f32 temp_f6_1269;
    f32 temp_f7_1184;
    f32 temp_f8_1170;
    f32 temp_f9_1177;
    f32 var_f0_917;
    f32 var_f10_1073;
    f32 var_f10_1192;
    f32 var_f11_1172;
    f32 var_f1_944;
    f32 var_f30_1194;
    f32 var_f4_1000;
    f32 var_f4_1098;
    f32 var_f7_991;
    f64 temp_f1_1005;
    f64 temp_f1_1011;
    f64 temp_f1_1015;
    f64 temp_f1_1104;
    f64 temp_f1_1110;
    f64 temp_f1_1114;
    f64 temp_f3_1202;
    f64 temp_f3_1208;
    f64 temp_f3_1212;
    f64 temp_f4_1296;
    f64 temp_f5_1286;
    s32 temp_r3_1034;
    s32 temp_r3_1133;
    s32 temp_r3_1231;
    s32 var_r0_1044;
    s32 var_r0_1143;
    s32 var_r0_1241;
    if ((u32) M2C_FIELD(this, u32 *, 0x224) != 0U) {
        if ((s32) this->unk234 != 1) {
            var_f0_917 = (M2C_BITWISE(f32, this->unk218) * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0x22C);
            if (var_f0_917 < 1.0f) {

            } else {
                var_f0_917 = 1.0f;
            }
            if (var_f0_917 > 0.0f) {

            } else {
                var_f0_917 = 0.0f;
            }
            M2C_FIELD(this, f32 *, 0x22C) = var_f0_917;
        }
        arg_sp1C = 0.0f;
        arg_spC0.GetMeasure(M2C_FIELD(this, f32 *, 0x22C), (Matrix *) &this->unk218, KDSpline_PositionMixer);
        var_f1_944 = M2C_FIELD(this, f32 *, 0x22C) - 0.001f;
        arg_sp110 = arg_spC0;
        arg_sp118 = arg_spC8;
        if (var_f1_944 < 1.0f) {

        } else {
            var_f1_944 = 1.0f;
        }
        if (var_f1_944 > 0.0f) {

        } else {
            var_f1_944 = 0.0f;
        }
        arg_spB0.GetVelocity(var_f1_944);
        arg_sp100 = arg_spB0;
        arg_sp108 = arg_spB8;
        if ((M2C_FIELD(this, f32 *, 0x22C) == 1.0f) && ((s32) this->unk234 != 1)) {
            this->unk234 = 1;
        }
        M2C_STRUCT_COPY((s32) &arg_sp15C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        var_f7_991 = 0.0f;
        arg_sp104 = 0.0f;
        var_f4_1000 = ((f32) arg_sp108 * (f32) arg_sp108) + (((f32) arg_sp100 * (f32) arg_sp100) + (0.0f * 0.0f));
        if (var_f4_1000 > 0.000001f) {
            if (var_f4_1000 > 0.0f) {
                temp_f1_1005 = __frsqrte(var_f4_1000);
                temp_f1_1011 = 0.5 * temp_f1_1005 * -(((f64) var_f4_1000 * (temp_f1_1005 * temp_f1_1005)) - 3.0);
                temp_f1_1015 = 0.5 * temp_f1_1011 * -(((f64) var_f4_1000 * (temp_f1_1011 * temp_f1_1011)) - 3.0);
                var_f4_1000 = (f32) ((f64) var_f4_1000 * (0.5 * temp_f1_1015 * -(((f64) var_f4_1000 * (temp_f1_1015 * temp_f1_1015)) - 3.0)));
            } else if (var_f4_1000 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1000 = __float_nan;
            } else {
                arg_sp18 = var_f4_1000;
                temp_r3_1034 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                switch (temp_r3_1034) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                        var_r0_1044 = 1;
                    } else {
                        var_r0_1044 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                        var_r0_1044 = 5;
                    } else {
                        var_r0_1044 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_1044 = 4;
                    break;
                }
                if (var_r0_1044 == 1) {
                    var_f4_1000 = __float_nan;
                }
            }
            var_f7_991 = 1.0f / var_f4_1000;
        }
        var_f10_1073 = 0.0f;
        arg_sp50 = -arg_sp180;
        arg_sp54 = -arg_sp184;
        arg_sp58 = -arg_sp188;
        arg_spF0 = (f64) arg_sp50;
        arg_spF8 = (f64) arg_sp58;
        arg_sp100 = (f32) arg_sp100 * var_f7_991;
        arg_sp104 *= var_f7_991;
        arg_sp108 = (f32) arg_sp108 * var_f7_991;
        var_f4_1098 = ((f32) arg_spF8 * (f32) arg_spF8) + (((f32) arg_spF0 * (f32) arg_spF0) + (0.0f * 0.0f));
        arg_spF4 = 0.0f;
        if (var_f4_1098 > 0.000001f) {
            if (var_f4_1098 > 0.0f) {
                temp_f1_1104 = __frsqrte(var_f4_1098);
                temp_f1_1110 = 0.5 * temp_f1_1104 * -(((f64) var_f4_1098 * (temp_f1_1104 * temp_f1_1104)) - 3.0);
                temp_f1_1114 = 0.5 * temp_f1_1110 * -(((f64) var_f4_1098 * (temp_f1_1110 * temp_f1_1110)) - 3.0);
                var_f4_1098 = (f32) ((f64) var_f4_1098 * (0.5 * temp_f1_1114 * -(((f64) var_f4_1098 * (temp_f1_1114 * temp_f1_1114)) - 3.0)));
            } else if (var_f4_1098 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1098 = __float_nan;
            } else {
                arg_sp14 = var_f4_1098;
                temp_r3_1133 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_1133) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_1143 = 1;
                    } else {
                        var_r0_1143 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_1143 = 5;
                    } else {
                        var_r0_1143 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1143 = 4;
                    break;
                }
                if (var_r0_1143 == 1) {
                    var_f4_1098 = __float_nan;
                }
            }
            var_f10_1073 = 1.0f / var_f4_1098;
        }
        arg_spE0 = arg_sp160;
        temp_f8_1170 = arg_spF4 * var_f10_1073;
        var_f11_1172 = 0.0f;
        temp_f9_1177 = (f32) arg_spF0 * var_f10_1073;
        arg_spE8 = arg_sp168;
        temp_f7_1184 = (f32) arg_spF8 * var_f10_1073;
        var_f10_1192 = ((f32) arg_spE8 * (f32) arg_spE8) + (((f32) arg_spE0 * (f32) arg_spE0) + (0.0f * 0.0f));
        arg_spF0 = temp_f9_1177;
        var_f30_1194 = 1.0f - ((temp_f7_1184 * (f32) arg_sp108) + ((temp_f9_1177 * (f32) arg_sp100) + (temp_f8_1170 * arg_sp104)));
        arg_spF4 = temp_f8_1170;
        arg_spF8 = temp_f7_1184;
        arg_spE4 = 0.0f;
        if (var_f10_1192 > 0.000001f) {
            if (var_f10_1192 > 0.0f) {
                temp_f3_1202 = __frsqrte(var_f10_1192);
                temp_f3_1208 = 0.5 * temp_f3_1202 * -(((f64) var_f10_1192 * (temp_f3_1202 * temp_f3_1202)) - 3.0);
                temp_f3_1212 = 0.5 * temp_f3_1208 * -(((f64) var_f10_1192 * (temp_f3_1208 * temp_f3_1208)) - 3.0);
                var_f10_1192 = (f32) ((f64) var_f10_1192 * (0.5 * temp_f3_1212 * -(((f64) var_f10_1192 * (temp_f3_1212 * temp_f3_1212)) - 3.0)));
            } else if (var_f10_1192 < M2C_BITWISE(f32, 0.0)) {
                var_f10_1192 = __float_nan;
            } else {
                arg_sp10 = var_f10_1192;
                temp_r3_1231 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_1231) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_1241 = 1;
                    } else {
                        var_r0_1241 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_1241 = 5;
                    } else {
                        var_r0_1241 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_1241 = 4;
                    break;
                }
                if (var_r0_1241 == 1) {
                    var_f10_1192 = __float_nan;
                }
            }
            var_f11_1172 = 1.0f / var_f10_1192;
        }
        temp_f5_1267 = arg_spE4 * var_f11_1172;
        temp_f6_1269 = (f32) arg_spE0 * var_f11_1172;
        temp_f4_1271 = (f32) arg_spE8 * var_f11_1172;
        arg_spE0 = temp_f6_1269;
        arg_spE4 = temp_f5_1267;
        arg_spE8 = temp_f4_1271;
        if ((((f32) arg_sp108 * temp_f4_1271) + (((f32) arg_sp100 * temp_f6_1269) + (arg_sp104 * temp_f5_1267))) < 0.0f) {
            var_f30_1194 = -var_f30_1194;
        }
        temp_f31_1285 = _table_sinf(M2C_BITWISE(f32, this->unk224));
        temp_f5_1286 = M2C_FIELD(this, f64 *, 0x1C8);
        arg_spA0 = temp_f5_1286;
        arg_sp48 = 0.0f;
        temp_f4_1296 = M2C_FIELD(this, f64 *, 0x1D0);
        arg_sp20 = 0.0f;
        arg_sp24 = 200.0f * temp_f31_1285;
        arg_sp28 = 0.0f;
        arg_sp40 = (0.1f * -temp_f31_1285) - (f32) arg_spA0;
        arg_sp44 = var_f30_1194;
        arg_sp90 = (f64) arg_sp20;
        arg_spA8 = temp_f4_1296;
        arg_spD0 = (f64) arg_sp40;
        arg_spD8 = (f64) arg_sp48;
        arg_sp98 = (f64) arg_sp28;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp70 = temp_f5_1286;
        arg_sp78 = temp_f4_1296;
        arg_sp118 = (f32) arg_sp118 + (f32) arg_sp98;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp80 = arg_sp30;
        arg_sp38 = (f32) arg_sp78 + (f32) arg_spD8;
        arg_sp88 = (f64) arg_sp38;
        arg_sp120.SetRotationPYR(*((MKVector3 *) &arg_sp80));
        arg_sp150 = (f32) arg_sp110;
        arg_sp154 = arg_sp114;
        arg_sp158 = (f32) arg_sp118;
        arg_sp15C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp120));
        arg_sp60.GetRotationPYR();
        M2C_FIELD(this, f64 *, 0x1C8) = arg_sp60;
        M2C_FIELD(this, f64 *, 0x1D0) = arg_sp68;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f31_1285 == 0.0f) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((temp_f31_1285 == -0.5f) && ((s32) this->unk234 != 1)) {
                EmitWaterSpray();
            }
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Update() {
    MKProp *temp_r3_1655;
    MKProp *temp_r3_1803;
    MKProp *temp_r3_1952;
    f32 temp_f0_1833;
    f32 temp_f0_1982;
    f32 temp_f28_1757;
    f32 temp_f28_1906;
    f32 var_f1_1465;
    f32 var_f28_1440;
    f32 var_f3_1576;
    f32 var_f4_1509;
    f64 temp_f0_1428;
    f64 temp_f1_1427;
    f64 temp_f1_1515;
    f64 temp_f1_1521;
    f64 temp_f1_1525;
    s32 temp_r3_1544;
    s32 temp_r3_1643;
    s32 var_r0_1554;
    s32 var_r25_1899;
    s32 var_r26_1750;
    s32 var_r27_1728;
    s32 var_r27_1877;
    s32 var_r30_1729;
    s32 var_r30_1878;
    u8 temp_r3_1413;
    void *temp_r25_1818;
    void *temp_r26_1967;
    void *temp_r29_1406;
    void *temp_r29_1731;
    void *temp_r29_1880;
    void *temp_r3_1426;
    void *temp_r3_1815;
    void *temp_r3_1964;
    void *temp_r5_1756;
    void *temp_r5_1905;
    if ((s32) M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x16C) != 0) {
        temp_r29_1406 = checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3_1413 = IsDead();
        arg_sp8 = 1;
        this->unk320.Update(M2C_FIELD(temp_r29_1406, s32 *, 0x16C), 1U, temp_r3_1413 == 0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    temp_r3_1426 = this->unk8;
    temp_f1_1427 = M2C_FIELD(temp_r3_1426, f64 *, 0x30);
    temp_f0_1428 = M2C_FIELD(temp_r3_1426, f64 *, 0x38);
    arg_sp290 = temp_f1_1427;
    M2C_FIELD(this, f64 *, 0x328) = temp_f1_1427;
    M2C_FIELD(this, f64 *, 0x330) = temp_f0_1428;
    arg_sp298 = temp_f0_1428;
    if ((s32) this->unk234 != 1) {
        var_f28_1440 = 1.0f - _table_sinf(M2C_BITWISE(f32, this->unk224));
        if (var_f28_1440 < 0.0f) {
            var_f28_1440 = -var_f28_1440;
        }
        this->unk224 = (1.5f * (0.5f + var_f28_1440) * gUpdateTimeDelta) + M2C_BITWISE(f32, this->unk224);
        this->unk230 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk230 == 0.0f) {
            var_f1_1465 = M2C_FIELD(this, f32 *, 0x22C) - 0.001f;
            if (var_f1_1465 < 1.0f) {

            } else {
                var_f1_1465 = 1.0f;
            }
            if (var_f1_1465 > 0.0f) {

            } else {
                var_f1_1465 = 0.0f;
            }
            arg_sp18 = 0.0f;
            arg_sp100.GetMeasure(var_f1_1465, (Matrix *) &this->unk218, KDSpline_VelocityMixer);
            arg_spF0 = arg_sp100;
            arg_spF8 = arg_sp108;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp280 = arg_spE0;
            arg_spE8 = (f32) arg_spF8 * arg_sp18;
            arg_sp288 = (f64) arg_spE8;
            var_f4_1509 = ((f32) arg_sp288 * (f32) arg_sp288) + (((f32) arg_sp280 * (f32) arg_sp280) + (arg_sp284 * arg_sp284));
            if (var_f4_1509 > 1e-12f) {
                if (var_f4_1509 > 0.0f) {
                    temp_f1_1515 = __frsqrte(var_f4_1509);
                    temp_f1_1521 = 0.5 * temp_f1_1515 * -(((f64) var_f4_1509 * (temp_f1_1515 * temp_f1_1515)) - 3.0);
                    temp_f1_1525 = 0.5 * temp_f1_1521 * -(((f64) var_f4_1509 * (temp_f1_1521 * temp_f1_1521)) - 3.0);
                    var_f4_1509 = (f32) ((f64) var_f4_1509 * (0.5 * temp_f1_1525 * -(((f64) var_f4_1509 * (temp_f1_1525 * temp_f1_1525)) - 3.0)));
                } else if (var_f4_1509 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1509 = __float_nan;
                } else {
                    arg_sp10 = var_f4_1509;
                    temp_r3_1544 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_1544) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_1554 = 1;
                        } else {
                            var_r0_1554 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_1554 = 5;
                        } else {
                            var_r0_1554 = 3;
                        }
                        break;
                    default:
                        var_r0_1554 = 4;
                        break;
                    }
                    if (var_r0_1554 == 1) {
                        var_f4_1509 = __float_nan;
                    }
                }
                var_f3_1576 = 1.0f / var_f4_1509;
            } else {
                var_f3_1576 = 0.0f;
            }
            arg_spD4 = arg_sp284 * var_f3_1576;
            arg_spD0 = (f32) arg_sp280 * var_f3_1576;
            arg_spD8 = (f32) arg_sp288 * var_f3_1576;
            arg_sp2E0 = (f64) arg_spD0;
            arg_sp2E8 = (f64) arg_spD8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp260 = arg_spC0;
            arg_spC8 = (f32) arg_sp2E8 * 2000.0f;
            arg_sp14 = 0.0f;
            arg_sp268 = (f64) arg_spC8;
            arg_sp270.GetMeasure(M2C_FIELD(this, f32 *, 0x22C), (Matrix *) &this->unk218, KDSpline_PositionMixer);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spB8 = arg_sp278 + (f32) arg_sp268;
            arg_sp2D0 = arg_spB0;
            arg_sp2D8 = (f64) arg_spB8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            arg_spA8 = (f32) arg_sp2E8 * ((3500.0f * var_f28_1440) + 5000.0f);
            arg_sp250 = arg_spA0;
            arg_sp258 = (f64) arg_spA8;
            ((WaterSurfaceFX *) (M2C_BITWISE(WaterSurfaceFX *, this->unk22C)))->AddMovementForce(*((MKVector3 *) &arg_sp2D0), *((MKVector3 *) &arg_sp250));
            this->unk230 = 0.125f;
        }
    }
    temp_r3_1643 = this->unk234;
    if ((u32) M2C_FIELD(temp_r3_1643, u32 *, 0x20) != 0U) {
        this->unk234->Animate(MKModel_GetAnimation(M2C_FIELD(temp_r3_1643, MKModel **, 8)), -1, NULL);
    }
    temp_r3_1655 = this->unk240;
    if (M2C_BITWISE(u32, temp_r3_1655->unk20) != 0U) {
        this->unk240->Animate(MKModel_GetAnimation((MKModel *) temp_r3_1655->unk8), -1, NULL);
    }
    if (IsDead() == 0) {
        KDSound_Play3d((MKAnimScript *) this->unk234, this->unk8 + 0x30, 0U, 0.0f, 0U);
        KDSound_Play3d((MKAnimScript *) this->unk240, this->unk8 + 0x30, 0U, 0.0f, 0U);
    }
    ShatterablePlatform::Update();
    arg_sp230.GetPos();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x318) = arg_sp90;
    arg_sp98 = arg_sp238 - this->unk318;
    arg_sp240 = arg_sp90;
    M2C_FIELD(this, f64 *, 0x320) = (f64) arg_sp98;
    arg_sp248 = (f64) arg_sp98;
    M2C_STRUCT_COPY((s32) &arg_sp2EC + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    if (this->unk234->CheckEvent(0) != 0) {
        var_r27_1728 = 5;
        var_r30_1729 = 0x50;
        do {
            temp_r29_1731 = this + var_r30_1729;
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r29_1731, s32 *, 0x274), (MKVector3 *) &arg_sp2C0);
            arg_sp320 = arg_sp2C0;
            arg_sp324 = arg_sp2C4;
            arg_sp328 = arg_sp2C8;
            arg_sp32C = 1.0f;
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r29_1731, MKModel **, 0x270), *((Matrix *) &arg_sp2F0));
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r29_1731, MKModel **, 0x270), this->unk360, (MKVector3 *) &arg_sp2A0);
            var_r26_1750 = 0;
loop_42:
            temp_r5_1756 = this->unk8;
            temp_f28_1757 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            arg_sp40 = -M2C_FIELD(temp_r5_1756, f32 *, 0x20);
            arg_sp44 = -M2C_FIELD(temp_r5_1756, f32 *, 0x24);
            arg_sp48 = -M2C_FIELD(temp_r5_1756, f32 *, 0x28);
            arg_sp1B0 = (f64) arg_sp40;
            arg_sp1B8 = (f64) arg_sp48;
            arg_sp1C0.operator*(4000.0f);
            arg_sp1D0.operator*(temp_f28_1757);
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp200), *((MKVector3 *) &arg_sp1F0));
            arg_sp210.operator*(1000.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r3_1803 = this->unk240;
            arg_sp220 = arg_sp80;
            arg_sp88 = arg_sp218 + arg_sp1D8;
            arg_sp2B0 = arg_sp80;
            arg_sp228 = (f64) arg_sp88;
            arg_sp2B8 = (f64) arg_sp88;
            temp_r3_1815 = M2C_FIELD(temp_r3_1803->__vptr, void *(**)(MKProp *, f64), 0x3C)(temp_r3_1803, arg_sp80);
            if (temp_r3_1815 != NULL) {
                temp_r25_1818 = M2C_FIELD(temp_r3_1815, void **, 0x2C);
                M2C_FIELD(temp_r3_1815, f64 *, 0) = arg_sp2A0;
                M2C_FIELD(temp_r3_1815, f64 *, 8) = arg_sp2A8;
                M2C_FIELD(temp_r3_1815, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1815, f32 *, 0x28) = 0.0f;
                temp_f0_1833 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp70 = 0.25f;
                arg_sp74 = 0.25f;
                M2C_FIELD(temp_r3_1815, f32 *, 0x24) = (f32) (2.0f * temp_f0_1833);
                arg_sp78 = 0.25f;
                arg_sp7C = 1.0f;
                M2C_FIELD(temp_r3_1815, f64 *, 0x10) = (f64) arg_sp70;
                M2C_FIELD(temp_r3_1815, f64 *, 0x18) = (f64) arg_sp78;
                M2C_FIELD(temp_r25_1818, f64 *, 0) = arg_sp2B0;
                arg_sp1A0 = (f64) arg_sp70;
                arg_sp1A8 = (f64) arg_sp78;
                M2C_FIELD(temp_r25_1818, f64 *, 8) = arg_sp2B8;
                M2C_FIELD(temp_r25_1818, f32 *, 0x18) = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                M2C_FIELD(temp_r25_1818, f32 *, 0x10) = 0.0f;
                M2C_FIELD(temp_r25_1818, f32 *, 0x14) = (f32) M2C_FIELD(this->unk240, f32 *, 0xF4);
            }
            var_r26_1750 += 1;
            if (var_r26_1750 < 5) {
                goto loop_42;
            }
            var_r27_1728 += 1;
            var_r30_1729 += 0x10;
        } while (var_r27_1728 < 0xA);
    }
    if (this->unk240->CheckEvent(0) != 0) {
        var_r27_1877 = 0;
        var_r30_1878 = 0;
        do {
            temp_r29_1880 = this + var_r30_1878;
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r29_1880, s32 *, 0x274), (MKVector3 *) &arg_sp2C0);
            arg_sp320 = arg_sp2C0;
            arg_sp324 = arg_sp2C4;
            arg_sp328 = arg_sp2C8;
            arg_sp32C = 1.0f;
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r29_1880, MKModel **, 0x270), *((Matrix *) &arg_sp2F0));
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r29_1880, MKModel **, 0x270), this->unk364, (MKVector3 *) &arg_sp2A0);
            var_r25_1899 = 0;
loop_49:
            temp_r5_1905 = this->unk8;
            temp_f28_1906 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            arg_sp30 = -M2C_FIELD(temp_r5_1905, f32 *, 0x20);
            arg_sp34 = -M2C_FIELD(temp_r5_1905, f32 *, 0x24);
            arg_sp38 = -M2C_FIELD(temp_r5_1905, f32 *, 0x28);
            arg_sp120 = (f64) arg_sp30;
            arg_sp128 = (f64) arg_sp38;
            arg_sp130.operator*(4000.0f);
            arg_sp140.operator*(temp_f28_1906);
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp170), *((MKVector3 *) &arg_sp160));
            arg_sp180.operator*(1000.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r3_1952 = this->unk240;
            arg_sp190 = arg_sp60;
            arg_sp68 = arg_sp188 + arg_sp148;
            arg_sp20 = arg_sp60;
            arg_sp198 = (f64) arg_sp68;
            arg_sp28 = (f64) arg_sp68;
            temp_r3_1964 = M2C_FIELD(temp_r3_1952->__vptr, void *(**)(MKProp *, f64), 0x3C)(temp_r3_1952, arg_sp60);
            if (temp_r3_1964 != NULL) {
                temp_r26_1967 = M2C_FIELD(temp_r3_1964, void **, 0x2C);
                M2C_FIELD(temp_r3_1964, f64 *, 0) = arg_sp2A0;
                M2C_FIELD(temp_r3_1964, f64 *, 8) = arg_sp2A8;
                M2C_FIELD(temp_r3_1964, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1964, f32 *, 0x28) = 0.0f;
                temp_f0_1982 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp50 = 0.25f;
                arg_sp54 = 0.25f;
                M2C_FIELD(temp_r3_1964, f32 *, 0x24) = (f32) (2.0f * temp_f0_1982);
                arg_sp58 = 0.25f;
                arg_sp5C = 1.0f;
                M2C_FIELD(temp_r3_1964, f64 *, 0x10) = (f64) arg_sp50;
                M2C_FIELD(temp_r3_1964, f64 *, 0x18) = (f64) arg_sp58;
                M2C_FIELD(temp_r26_1967, f64 *, 0) = arg_sp20;
                arg_sp110 = (f64) arg_sp50;
                arg_sp118 = (f64) arg_sp58;
                M2C_FIELD(temp_r26_1967, f64 *, 8) = arg_sp28;
                M2C_FIELD(temp_r26_1967, f32 *, 0x18) = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                M2C_FIELD(temp_r26_1967, f32 *, 0x10) = 0.0f;
                M2C_FIELD(temp_r26_1967, f32 *, 0x14) = (f32) M2C_FIELD(this->unk240, f32 *, 0xF4);
            }
            var_r25_1899 += 1;
            if (var_r25_1899 < 5) {
                goto loop_49;
            }
            var_r27_1877 += 1;
            var_r30_1878 += 0x10;
        } while (var_r27_1877 < 5);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Resolve() {
    Shatterable::Resolve();
    InitOars();
    if ((s32) M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x16C) != 0) {
        this->unk320.Init(0.25f, 0.25f);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk218'
void ShatterableBoat::LoadDone() {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_2086;
    f64 temp_f1_2085;
    void *temp_r3_2084;

    ShatterablePlatform::LoadDone();
    if ((u32) M2C_FIELD(this, u32 *, 0x224) != 0U) {
        this->unk218 = M2C_BITWISE(f32, this->unk218) / M2C_FIELD(this, f32 *, 0x220);
    } else {
        this->unk218 = 0.0005f;
    }
    temp_r3_2084 = this->unk8;
    temp_f1_2085 = M2C_FIELD(temp_r3_2084, f64 *, 0x30);
    temp_f0_2086 = M2C_FIELD(temp_r3_2084, f64 *, 0x38);
    sp8 = temp_f1_2085;
    M2C_FIELD(this, f64 *, 0x328) = temp_f1_2085;
    sp10 = temp_f0_2086;
    M2C_FIELD(this, f64 *, 0x330) = temp_f0_2086;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 ShatterableBoat::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r30_2160;
    s32 temp_r3_2147;

    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadFloat(lit_stringBase0 + 0xB, (f32 *) &this->unk218, 0) != 0) || (arg0->LoadFloat(lit_stringBase0 + 0x11, &this->unk314, 0) != 0)) {
        return 1;
    }
    arg0->GetFieldName();
    if (stricmp(lit_stringBase0 + 0x1D) == 0) {
        if ((u32) M2C_FIELD(this, u32 *, 0x224) != 0U) {
            return 0;
        }
        temp_r3_2147 = arg0->GetNmbrOfSubLines();
        if (temp_r3_2147 == 0) {
            return 0;
        }
        this->unk218.Init(temp_r3_2147, 0U);
        var_r30_2160 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r30_2160 != NULL) {
            var_r30_2160->AsVector3(0, &sp8);
            this->unk218.AddNode(sp8);
            var_r30_2160 = var_r30_2160->unkC->GetNextLine(var_r30_2160);
            goto loop_11;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk234'
void ShatterableBoat::InitOars() {
    MKProp *temp_r29_2251;
    MKProp *temp_r29_2271;
    WaterSurfaceFX *var_r3_2263;
    s32 temp_r0_2306;
    s32 temp_r0_2316;
    s32 temp_r0_2334;
    s32 temp_r29_2206;
    s32 temp_r29_2226;
    s32 var_ctr_2303;
    s32 var_ctr_2313;
    s32 var_r28_2322;
    s32 var_r30_2324;
    s32 var_r3_2302;
    s32 var_r3_2312;
    u16 temp_r3_2332;
    void *var_r3_2218;
    void *var_r3_2236;
    void *var_r3_2281;

    this->unk234 = ((MKAnimScript *) ((MKAnimScript *) (lit_stringBase0 + 0x27)))->Create((s8 *)1, M2C_ERROR(/* Read from unset register $r5 */));
    this->unk234->InitEvents(&pLeftOarAnimEvents);
    temp_r29_2206 = this->unk234;
    if (temp_r29_2206->Exists(lit_stringBase0 + 0x3B) != 0) {
        var_r3_2218 = temp_r29_2206->GetAnim(lit_stringBase0 + 0x3B);
    } else {
        var_r3_2218 = NULL;
    }
    this->unk238 = (s32) var_r3_2218;
    temp_r29_2226 = this->unk234;
    if (temp_r29_2226->Exists(lit_stringBase0 + 0x3F) != 0) {
        var_r3_2236 = temp_r29_2226->GetAnim(lit_stringBase0 + 0x3F);
    } else {
        var_r3_2236 = NULL;
    }
    this->unk23C = M2C_BITWISE(f32, var_r3_2236);
    this->unk240 = ((MKAnimScript *) ((MKAnimScript *) (lit_stringBase0 + 0x44)))->Create((s8 *)1, M2C_ERROR(/* Read from unset register $r5 */));
    this->unk240->InitEvents(&pRightOarAnimEvents);
    temp_r29_2251 = this->unk240;
    if (temp_r29_2251->Exists(lit_stringBase0 + 0x3B) != 0) {
        var_r3_2263 = temp_r29_2251->GetAnim(lit_stringBase0 + 0x3B);
    } else {
        var_r3_2263 = NULL;
    }
    this->unk244 = var_r3_2263;
    temp_r29_2271 = this->unk240;
    if (temp_r29_2271->Exists(lit_stringBase0 + 0x3F) != 0) {
        var_r3_2281 = temp_r29_2271->GetAnim(lit_stringBase0 + 0x3F);
    } else {
        var_r3_2281 = NULL;
    }
    this->unk248 = M2C_BITWISE(f32, var_r3_2281);
    this->unk234->SetAnim(M2C_BITWISE(MKAnim *, this->unk23C), 1.0f, 0.0f, 0, -1);
    this->unk240->SetAnim(M2C_BITWISE(MKAnim *, this->unk248), 1.0f, 0.0f, 0, -1);
    var_r3_2302 = 0;
    var_ctr_2303 = 5;
    do {
        temp_r0_2306 = var_r3_2302 + 0x270;
        var_r3_2302 += 0x10;
        *(this + temp_r0_2306) = this->unk240->unk8;
        var_ctr_2303 -= 1;
    } while (var_ctr_2303 != 0);
    var_r3_2312 = 0x50;
    var_ctr_2313 = 5;
    do {
        temp_r0_2316 = var_r3_2312 + 0x270;
        var_r3_2312 += 0x10;
        *(this + temp_r0_2316) = M2C_FIELD(this->unk234, MKModel **, 8);
        var_ctr_2313 -= 1;
    } while (var_ctr_2313 != 0);
    var_r28_2322 = 0;
    var_r30_2324 = 0;
    do {
        temp_r3_2332 = Tools_GetMatchingRefPointIndex(this->unk4, Str_Printf(lit_stringBase0 + 0x59, var_r28_2322 + 1));
        var_r28_2322 += 1;
        temp_r0_2334 = var_r30_2324 + 0x274;
        var_r30_2324 += 0x10;
        *(this + temp_r0_2334) = (s32) temp_r3_2332;
    } while (var_r28_2322 < 0xA);
    this->unk360 = (s32) Tools_GetMatchingRefPointIndex(M2C_FIELD(this->unk234, MKModel **, 8), lit_stringBase0 + 0x6A);
    this->unk364 = (s32) Tools_GetMatchingRefPointIndex((MKModel *) this->unk240->unk8, lit_stringBase0 + 0x73);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk234'
void ShatterableBoat::Init() {
    ShatterablePlatform::Init();
    this->unk234 = 1;
    M2C_FIELD(this, f32 *, 0x22C) = 0.0f;
    this->unk218 = 100.0f;
    this->unk220 = 0.0f;
    this->unk224 = 0.0f;
    gMK->CreatePropDeferred(lit_stringBase0 + 0x7C, &this->unk240);
    this->unk22C = M2C_BITWISE(f32, checked_cast<WaterSurfaceFX *, MKProp>(gMK->CreateProp(lit_stringBase0 + 0x89)));
    M2C_FIELD(this->unk22C, f32 *, 0x58) = 2.0f;
    this->unk230 = 0.0f;
    this->unk310 = MKModel_Create(lit_stringBase0 + 0x98, NULL, 2, NULL);
    this->unk314 = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 ShatterableBoatDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2425;

    var_r31_2425 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, lit_stringBase0 + 0xA8, &this->unk16C) != 0) || (KDSound_LoadLine(arg0, lit_stringBase0 + 0xB9, &this->unk170) != 0)) {
        var_r31_2425 = 1;
    }
    return var_r31_2425;
}
#endif

void ShatterableBoatDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk16C = GS_PLACEHOLDER;
    this->unk170 = GS_PLACEHOLDER;
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetTimeLastHit'
void ShatterableBoat::lit_200lit_GetTimeLastHit() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionHeight'
void ShatterableBoat::lit_200lit_GetCollisionHeight() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionRadius'
void ShatterableBoat::lit_200lit_GetCollisionRadius() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetVel'
void ShatterableBoat::lit_200lit_GetVel() {
    ShatterableBoat::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetAimPoint'
void ShatterableBoat::lit_200lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetLookToPoint'
void ShatterableBoat::lit_200lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetMoveToPoint'
void ShatterableBoat::lit_200lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsEnemy'
void ShatterableBoat::lit_200lit_IsEnemy() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsFriend'
void ShatterableBoat::lit_200lit_IsFriend() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsHero'
void ShatterableBoat::lit_200lit_IsHero() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetEnemy'
void ShatterableBoat::lit_200lit_GetEnemy() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetProp'
void ShatterableBoat::lit_200lit_GetProp() {
    ((ShatterableBoat *) (this - 0xC8))->ShatterableBoat::GetProp();
}
#endif
