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
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/PlatformObject.h"
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
#if 0 // DRAFT: illegal implicit conversion from 'const char[11]' to
static s8 *pLeftOarAnimEvents = "EnterWater";
#endif
#if 0 // DRAFT: illegal implicit conversion from 'const char[11]' to
static s8 *pRightOarAnimEvents = "EnterWater";
#endif

static s32 lit_853 = 0;

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void ShatterableBoat::SetDefaults() {
    Shatterable::Reset();
    this->unk234 = 1;
    M2C_FIELD(this, f32 *, 0x22C) = 0.0f;
    this->unk220 = 0.0f;
    this->unk224 = 0.0f;
    this->unk230 = 0.0f;
    ((MKAnimScript *) this->unk234)->SetAnim(M2C_BITWISE(MKAnim *, this->unk23C), 1.0f, 0.0f, 0, -1);
    ((MKAnimScript *) this->unk240)->SetAnim(M2C_BITWISE(MKAnim *, this->unk248), 1.0f, 0.0f, 0, -1);
    ((PlatformObject *) &this->unk1A8.unk8)->SimpleMessageAttached(0xD5);
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
    f64 sp18;
    f32 sp10;
    f64 sp8;
    void *temp_r4_191;

    MKVector(0.0f, 100.0f, 0.0f);
    temp_r4_191 = ((u8 *) this->unk8) + 0x30;
    sp8 = M2C_FIELD(temp_r4_191, f64 *, 0) + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD(temp_r4_191, f32 *, 8) + sp20;
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
    f64 sp18;
    f32 sp10;
    f64 sp8;
    void *temp_r4_229;

    MKVector(0.0f, 100.0f, 0.0f);
    temp_r4_229 = ((u8 *) this->unk8) + 0x30;
    sp8 = M2C_FIELD(temp_r4_229, f64 *, 0) + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD(temp_r4_229, f32 *, 8) + sp20;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Deinit() {
    ((MKAnimScript *) this->unk234)->Destroy();
    ((MKAnimScript *) this->unk240)->Destroy();
    ((KDUniformSpline *) &this->unk218)->Deinit();
    MKModel_Destroy(this->unk310);
    if ((s32) M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x16C) != 0) {
        KDSound_Stop((s32 *) &this->unk320);
    }
    ShatterablePlatform::Deinit();
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Draw() {
    Matrix spF0;
    f32 spEC;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
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
    M2C_UNK sp40;
    f64 sp38;
    f64 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_402;
    s32 var_r28_318;
    s32 var_r30_319;
    u8 temp_r28_417;
    u8 temp_r29_434;
    void *temp_r29_321;

    Shatterable::Draw();
    if ((MKProp *) this->unk170 < (s32) (M2C_FIELD(checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160) - 1)) {
        M2C_STRUCT_COPY((s32) &spEC + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
        var_r28_318 = 0;
        var_r30_319 = 0;
        do {
            temp_r29_321 = this + var_r30_319;
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r29_321, s32 *, 0x274), &spA0);
            spF0.unk30 = M2C_BITWISE(f32, spA0);
            spF0.unk34 = spA0.unk4;
            spF0.unk38 = spA0.unk8;
            spF0.unk3C = 1.0f;
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r29_321, MKModel **, 0x270), spF0);
            MKModel_Draw(M2C_FIELD(temp_r29_321, MKModel **, 0x270), NULL);
            var_r28_318 += 1;
            var_r30_319 += 0x10;
        } while (var_r28_318 < 0xA);
    }
    M2C_STRUCT_COPY((s32) &spA0.unkC + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
    sp18 = 0.0f;
    sp90 = spD0;
    sp70 = spB0;
    sp98 = spD8;
    sp88 = (f64) sp18;
    sp78 = spB8;
    sp10 = 0.0f;
    sp14 = 1.0f;
    (*(f32 *) ((u8 *) &sp90 + 0x4)) = 0.0f;
    sp80 = (f64) sp10;
    sp50 = (f64) sp10;
    sp58 = (f64) sp18;
    (*(f32 *) ((u8 *) &sp70 + 0x4)) = 0.0f;
    spB0 = (f32) sp70;
    (*(f32 *) ((u8 *) &spB0 + 0x4)) = 0.0f;
    spB8 = (f32) sp78;
    (*(f32 *) ((u8 *) &spB8 + 0x4)) = 0.0f;
    spC0 = (f32) sp80;
    spC4 = (*(f32 *) ((u8 *) &sp80 + 0x4));
    spC8 = (f32) sp88;
    spCC = 0.0f;
    spD0 = (f32) sp90;
    (*(f32 *) ((u8 *) &spD0 + 0x4)) = 0.0f;
    spD8 = (f32) sp98;
    (*(f32 *) ((u8 *) &spD8 + 0x4)) = 0.0f;
    ((Matrix *) &sp40)->NormaliseScale();
    sp60 = spE0;
    temp_f3_402 = this->unk314;
    sp68 = spE8;
    spE0 = (f32) sp60;
    (*(f32 *) ((u8 *) &spE0 + 0x4)) = temp_f3_402;
    spE8 = (f32) sp68;
    spEC = 1.0f;
    (*(f32 *) ((u8 *) &sp60 + 0x4)) = temp_f3_402;
    MKModel_SetWorldMatrix(this->unk310, *((Matrix *) &spB0));
    temp_r28_417 = MKMaterial_EnableFog(0U);
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = 1.0f;
    sp2C = this->unk20;
    sp30 = (f64) sp20;
    sp38 = (f64) sp28;
    MKModel_SetColor(this->unk310, *((MKVector4 *) &sp30));
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
        ((KDSoundPlayer *) &this->unk320)->Message(arg0);
    }
    temp_r0_469 = arg0->unk0;
    switch (temp_r0_469) {                          /* irregular */
    case 0xB5:
        if ((s32) this->unk234 == 1) {
            this->unk234 = 0;
            ((MKAnimScript *) this->unk234)->SetAnim((MKAnim *) this->unk238, 1.0f, 0.0f, 0, -1);
            ((MKAnimScript *) this->unk240)->SetAnim((MKAnim *) this->unk244, 1.0f, 0.0f, 0, -1);
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
        KDSound_Play3d(GS_ShipExtra2, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
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

#if 0 // DRAFT: illegal type
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
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
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
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_814;
    f32 temp_f0_844;
    f32 temp_f31_768;
    f64 temp_f0_631;
    f64 temp_f0_643;
    f64 temp_f0_666;
    s32 var_r28_716;
    s32 var_r29_704;
    void *temp_r27_829;
    void *temp_r3_826;
    void *temp_r5_574;
    void *temp_r5_591;
    void *temp_r5_611;
    void *temp_r5_767;

    temp_r5_574 = this->unk8;
    sp48 = -M2C_FIELD(temp_r5_574, f32 *, 0x20);
    sp4C = -M2C_FIELD(temp_r5_574, f32 *, 0x24);
    sp50 = -M2C_FIELD(temp_r5_574, f32 *, 0x28);
    sp268 = (f64) sp48;
    sp270 = (f64) sp50;
    sp278.operator*(4000.0f);
    temp_r5_591 = this->unk8;
    spD8 = *(temp_r5_591 + 0x30) + M2C_BITWISE(f64, sp278);
    sp288 = spD8;
    spE0 = M2C_FIELD(temp_r5_591, f32 *, 0x38) + sp278.unk8;
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
    temp_f0_631 = sp2C8 + M2C_BITWISE(f64, sp238);
    sp28 = temp_f0_631;
    sp248 = temp_f0_631;
    sp30 = (f32) sp2D0 + sp238.unk8;
    sp250 = (f64) sp30;
    temp_f0_643 = sp248 + M2C_BITWISE(f64, sp218);
    spC8 = temp_f0_643;
    sp258 = temp_f0_643;
    sp2D8 = temp_f0_643;
    spD0 = (f32) sp250 + sp218.unk8;
    sp260 = (f64) spD0;
    sp2E0 = (f64) spD0;
    sp1D8.operator*(1000.0f);
    sp1E8.operator*(1500.0f);
    temp_f0_666 = sp2C8 + M2C_BITWISE(f64, sp1E8);
    sp18 = temp_f0_666;
    sp1F8 = temp_f0_666;
    sp20 = (f32) sp2D0 + sp1E8.unk8;
    sp200 = (f64) sp20;
    spB8 = sp1F8 + M2C_BITWISE(f64, sp1D8);
    sp208 = spB8;
    spC0 = (f32) sp200 + sp1D8.unk8;
    sp2B8 = spB8;
    sp210 = (f64) spC0;
    sp2C0 = (f64) spC0;
    spA8 = sp2C8 - sp2D8;
    sp1C8 = spA8;
    spB0 = (f32) sp2D0 - (f32) sp2E0;
    sp2A8 = spA8;
    sp1D0 = (f64) spB0;
    sp2B0 = (f64) spB0;
    sp98 = sp2C8 - sp2B8;
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
            sp88 = sp2D8 + M2C_BITWISE(f64, sp198);
            sp1A8 = sp88;
            sp90 = (f32) sp2E0 + sp198.unk8;
            sp2F8 = sp88;
            sp1B0 = (f64) sp90;
            sp300 = (f64) sp90;
        } else {
            sp178.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
            sp78 = sp2B8 + M2C_BITWISE(f64, sp178);
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
        sp68 = sp158 + M2C_BITWISE(f64, sp118);
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

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void ShatterableBoat::UpdateMove() {
    Matrix sp120;
    f64 sp118;                                      /* compiler-managed */
    f64 sp110;
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;                                       /* compiler-managed */
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;                                       /* compiler-managed */
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;
    KDUniformSpline spC0;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
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
    f64 temp_f0_1323;
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
        sp1C = 0.0f;
        spC0.GetMeasure(M2C_FIELD(this, f32 *, 0x22C), (Matrix *) &this->unk218, KDSpline_PositionMixer);
        var_f1_944 = M2C_FIELD(this, f32 *, 0x22C) - 0.001f;
        sp110 = M2C_BITWISE(f64, spC0);
        sp118 = (f64) spC0.unk8;
        if (var_f1_944 < 1.0f) {

        } else {
            var_f1_944 = 1.0f;
        }
        if (var_f1_944 > 0.0f) {

        } else {
            var_f1_944 = 0.0f;
        }
        ((KDUniformSpline *) &spB0)->GetVelocity(var_f1_944);
        sp100 = spB0;
        sp108 = spB8;
        if ((M2C_FIELD(this, f32 *, 0x22C) == 1.0f) && ((s32) this->unk234 != 1)) {
            this->unk234 = 1;
        }
        M2C_STRUCT_COPY((s32) &sp120.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        var_f7_991 = 0.0f;
        (*(f32 *) ((u8 *) &spD8 + 0x2c)) = 0.0f;
        var_f4_1000 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (0.0f * 0.0f));
        if (var_f4_1000 > 0.000001f) {
            if (var_f4_1000 > 0.0f) {
                temp_f1_1005 = __frsqrte(var_f4_1000);
                temp_f1_1011 = 0.5 * temp_f1_1005 * -(((f64) var_f4_1000 * (temp_f1_1005 * temp_f1_1005)) - 3.0);
                temp_f1_1015 = 0.5 * temp_f1_1011 * -(((f64) var_f4_1000 * (temp_f1_1011 * temp_f1_1011)) - 3.0);
                var_f4_1000 = (f32) ((f64) var_f4_1000 * (0.5 * temp_f1_1015 * -(((f64) var_f4_1000 * (temp_f1_1015 * temp_f1_1015)) - 3.0)));
            } else if (var_f4_1000 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1000 = __float_nan;
            } else {
                sp18 = var_f4_1000;
                temp_r3_1034 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_1034) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_1044 = 1;
                    } else {
                        var_r0_1044 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
        sp50 = -sp180;
        sp54 = -sp184;
        sp58 = -sp188;
        spF0 = (f64) sp50;
        spF8 = (f64) sp58;
        sp100 = (f32) sp100 * var_f7_991;
        (*(f32 *) ((u8 *) &spD8 + 0x2c)) *= var_f7_991;
        sp108 = (f32) sp108 * var_f7_991;
        var_f4_1098 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (0.0f * 0.0f));
        (*(f32 *) ((u8 *) &spD8 + 0x1c)) = 0.0f;
        if (var_f4_1098 > 0.000001f) {
            if (var_f4_1098 > 0.0f) {
                temp_f1_1104 = __frsqrte(var_f4_1098);
                temp_f1_1110 = 0.5 * temp_f1_1104 * -(((f64) var_f4_1098 * (temp_f1_1104 * temp_f1_1104)) - 3.0);
                temp_f1_1114 = 0.5 * temp_f1_1110 * -(((f64) var_f4_1098 * (temp_f1_1110 * temp_f1_1110)) - 3.0);
                var_f4_1098 = (f32) ((f64) var_f4_1098 * (0.5 * temp_f1_1114 * -(((f64) var_f4_1098 * (temp_f1_1114 * temp_f1_1114)) - 3.0)));
            } else if (var_f4_1098 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1098 = __float_nan;
            } else {
                sp14 = var_f4_1098;
                temp_r3_1133 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_1133) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_1143 = 1;
                    } else {
                        var_r0_1143 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
        spE0 = sp160;
        temp_f8_1170 = (*(f32 *) ((u8 *) &spD8 + 0x1c)) * var_f10_1073;
        var_f11_1172 = 0.0f;
        temp_f9_1177 = (f32) spF0 * var_f10_1073;
        spE8 = sp168;
        temp_f7_1184 = (f32) spF8 * var_f10_1073;
        var_f10_1192 = ((f32) spE8 * (f32) spE8) + (((f32) spE0 * (f32) spE0) + (0.0f * 0.0f));
        spF0 = temp_f9_1177;
        var_f30_1194 = 1.0f - ((temp_f7_1184 * sp108) + ((temp_f9_1177 * sp100) + (temp_f8_1170 * (*(f32 *) ((u8 *) &spD8 + 0x2c)))));
        (*(f32 *) ((u8 *) &spD8 + 0x1c)) = temp_f8_1170;
        spF8 = temp_f7_1184;
        (*(f32 *) ((u8 *) &spD8 + 0xc)) = 0.0f;
        if (var_f10_1192 > 0.000001f) {
            if (var_f10_1192 > 0.0f) {
                temp_f3_1202 = __frsqrte(var_f10_1192);
                temp_f3_1208 = 0.5 * temp_f3_1202 * -(((f64) var_f10_1192 * (temp_f3_1202 * temp_f3_1202)) - 3.0);
                temp_f3_1212 = 0.5 * temp_f3_1208 * -(((f64) var_f10_1192 * (temp_f3_1208 * temp_f3_1208)) - 3.0);
                var_f10_1192 = (f32) ((f64) var_f10_1192 * (0.5 * temp_f3_1212 * -(((f64) var_f10_1192 * (temp_f3_1212 * temp_f3_1212)) - 3.0)));
            } else if (var_f10_1192 < M2C_BITWISE(f32, 0.0)) {
                var_f10_1192 = __float_nan;
            } else {
                sp10 = var_f10_1192;
                temp_r3_1231 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1231) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1241 = 1;
                    } else {
                        var_r0_1241 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
        temp_f5_1267 = (*(f32 *) ((u8 *) &spD8 + 0xc)) * var_f11_1172;
        temp_f6_1269 = (f32) spE0 * var_f11_1172;
        temp_f4_1271 = (f32) spE8 * var_f11_1172;
        spE0 = temp_f6_1269;
        (*(f32 *) ((u8 *) &spD8 + 0xc)) = temp_f5_1267;
        spE8 = temp_f4_1271;
        if (((sp108 * temp_f4_1271) + ((sp100 * temp_f6_1269) + ((*(f32 *) ((u8 *) &spD8 + 0x2c)) * temp_f5_1267))) < 0.0f) {
            var_f30_1194 = -var_f30_1194;
        }
        temp_f31_1285 = _table_sinf(M2C_BITWISE(f32, this->unk224));
        temp_f5_1286 = M2C_FIELD(this, f64 *, 0x1C8);
        spA0 = temp_f5_1286;
        sp48 = 0.0f;
        temp_f4_1296 = M2C_FIELD(this, f64 *, 0x1D0);
        sp20 = 0.0f;
        sp24 = 200.0f * temp_f31_1285;
        sp28 = 0.0f;
        sp40 = (0.1f * -temp_f31_1285) - (f32) spA0;
        sp44 = var_f30_1194;
        sp90 = (f64) sp20;
        spA8 = temp_f4_1296;
        spC0.unk10 = (f64) sp40;
        spD8 = (f64) sp48;
        sp98 = (f64) sp28;
        sp110 += sp90;
        sp70 = temp_f5_1286;
        sp78 = temp_f4_1296;
        sp118 = (f32) sp118 + (f32) sp98;
        temp_f0_1323 = sp70 + M2C_BITWISE(f64, spC0.unk10);
        sp30 = temp_f0_1323;
        sp80 = temp_f0_1323;
        sp38 = (f32) sp78 + (f32) spD8;
        sp88 = (f64) sp38;
        sp120.SetRotationPYR(*((MKVector3 *) &sp80));
        sp120.unk30 = (f32) sp110;
        sp120.unk34 = (*(f32 *) ((u8 *) &sp110 + 0x4));
        sp120.unk38 = sp118;
        sp120.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, sp120);
        ((Matrix *) &sp60)->GetRotationPYR();
        M2C_FIELD(this, f64 *, 0x1C8) = sp60;
        M2C_FIELD(this, f64 *, 0x1D0) = sp68;
        M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
        if ((temp_f31_1285 == 0.0f) && (temp_f31_1285 >= -0.5f) && ((s32) this->unk234 != 1)) {
            EmitWaterSpray();
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Update() {
    Matrix sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    MKVector3 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    MKVector3 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    MKVector3 sp210;
    MKVector3 sp200;
    MKVector3 sp1F0;
    M2C_UNK sp1E0;
    MKVector3 sp1D0;
    MKVector3 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    MKVector3 sp170;
    MKVector3 sp160;
    M2C_UNK sp150;
    MKVector3 sp140;
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    KDUniformSpline sp100;
    f64 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKProp *temp_r3_1655;
    MKProp *temp_r3_1803;
    MKProp *temp_r3_1952;
    f32 temp_f0_1833;
    f32 temp_f0_1982;
    f32 temp_f1_1621;
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
        sp8 = 1;
        ((KDSoundFader *) &this->unk320)->Update(M2C_FIELD(temp_r29_1406, s32 *, 0x16C), 1U, temp_r3_1413 == 0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    temp_r3_1426 = this->unk8;
    temp_f1_1427 = M2C_FIELD(temp_r3_1426, f64 *, 0x30);
    temp_f0_1428 = M2C_FIELD(temp_r3_1426, f64 *, 0x38);
    sp290 = temp_f1_1427;
    M2C_FIELD(this, f64 *, 0x328) = temp_f1_1427;
    M2C_FIELD(this, f64 *, 0x330) = temp_f0_1428;
    sp298 = temp_f0_1428;
    if ((s32) this->unk234 != 1) {
        var_f28_1440 = 1.0f - _table_sinf(M2C_BITWISE(f32, this->unk224));
        if (var_f28_1440 < 0.0f) {
            var_f28_1440 = -var_f28_1440;
        }
        this->unk224 = (1.5f * (0.5f + var_f28_1440) * gUpdateTimeDelta) + M2C_BITWISE(f32, this->unk224);
        this->unk230 -= gUpdateTimeDelta;
        if (this->unk230 <= 0.0f) {
            var_f1_1465 = M2C_FIELD(this, f32 *, 0x22C) - 0.001f;
            if (var_f1_1465 < 1.0f) {

            } else {
                var_f1_1465 = 1.0f;
            }
            if (var_f1_1465 > 0.0f) {

            } else {
                var_f1_1465 = 0.0f;
            }
            sp18 = 0.0f;
            sp100.GetMeasure(var_f1_1465, (Matrix *) &this->unk218, KDSpline_VelocityMixer);
            spF0 = M2C_BITWISE(f64, sp100);
            spF8 = (f64) sp100.unk8;
            spE0 = spF0 * (f64) sp18;
            sp280 = spE0;
            spE8 = (f32) spF8 * sp18;
            sp288 = (f64) spE8;
            var_f4_1509 = ((f32) sp288 * (f32) sp288) + (((f32) sp280 * (f32) sp280) + ((*(f32 *) ((u8 *) &sp280 + 0x4)) * (*(f32 *) ((u8 *) &sp280 + 0x4))));
            if (var_f4_1509 > 1e-12f) {
                if (var_f4_1509 > 0.0f) {
                    temp_f1_1515 = __frsqrte(var_f4_1509);
                    temp_f1_1521 = 0.5 * temp_f1_1515 * -(((f64) var_f4_1509 * (temp_f1_1515 * temp_f1_1515)) - 3.0);
                    temp_f1_1525 = 0.5 * temp_f1_1521 * -(((f64) var_f4_1509 * (temp_f1_1521 * temp_f1_1521)) - 3.0);
                    var_f4_1509 = (f32) ((f64) var_f4_1509 * (0.5 * temp_f1_1525 * -(((f64) var_f4_1509 * (temp_f1_1525 * temp_f1_1525)) - 3.0)));
                } else if (var_f4_1509 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1509 = __float_nan;
                } else {
                    sp10 = var_f4_1509;
                    temp_r3_1544 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1544) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1554 = 1;
                        } else {
                            var_r0_1554 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
            spD4 = (*(f32 *) ((u8 *) &sp280 + 0x4)) * var_f3_1576;
            spD0 = (f32) sp280 * var_f3_1576;
            spD8 = (f32) sp288 * var_f3_1576;
            sp2E0 = (f64) spD0;
            sp2E8 = (f64) spD8;
            spC0 = sp2E0 * 5.717499035e-315;
            sp260 = spC0;
            spC8 = (f32) sp2E8 * 2000.0f;
            sp14 = 0.0f;
            sp268 = (f64) spC8;
            ((KDUniformSpline *) &sp270)->GetMeasure(M2C_FIELD(this, f32 *, 0x22C), (Matrix *) &this->unk218, KDSpline_PositionMixer);
            spB0 = sp270 + sp260;
            temp_f1_1621 = (3500.0f * var_f28_1440) + 5000.0f;
            spB8 = sp278 + (f32) sp268;
            sp2D0 = spB0;
            sp2D8 = (f64) spB8;
            spA0 = sp2E0 * (f64) temp_f1_1621;
            spA8 = (f32) sp2E8 * temp_f1_1621;
            sp250 = spA0;
            sp258 = (f64) spA8;
            ((WaterSurfaceFX *) (M2C_BITWISE(WaterSurfaceFX *, this->unk22C)))->AddMovementForce(*((MKVector3 *) &sp2D0), *((MKVector3 *) &sp250));
            this->unk230 = 0.125f;
        }
    }
    temp_r3_1643 = this->unk234;
    if ((u32) M2C_FIELD(temp_r3_1643, u32 *, 0x20) != 0U) {
        ((MKAnimScript *) this->unk234)->Animate(MKModel_GetAnimation(M2C_FIELD(temp_r3_1643, MKModel **, 8)), -1, NULL);
    }
    temp_r3_1655 = this->unk240;
    if (M2C_BITWISE(u32, temp_r3_1655->unk20) != 0U) {
        ((MKAnimScript *) this->unk240)->Animate(MKModel_GetAnimation((MKModel *) temp_r3_1655->unk8), -1, NULL);
    }
    if (IsDead() == 0) {
        KDSound_Play3d((MKAnimScript *) this->unk234, ((u8 *) this->unk8) + 0x30, 0U, 0.0f, 0U);
        KDSound_Play3d((MKAnimScript *) this->unk240, ((u8 *) this->unk8) + 0x30, 0U, 0.0f, 0U);
    }
    ShatterablePlatform::Update();
    ((MKProp *) &sp230)->GetPos();
    sp90 = sp230 - M2C_FIELD(this, f64 *, 0x328);
    M2C_FIELD(this, f64 *, 0x318) = sp90;
    sp98 = sp238 - this->unk318;
    sp240 = sp90;
    M2C_FIELD(this, f64 *, 0x320) = (f64) sp98;
    sp248 = (f64) sp98;
    M2C_STRUCT_COPY((s32) &unksp2EC + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
    if (((MKAnimScript *) this->unk234)->CheckEvent(0) != 0) {
        var_r27_1728 = 5;
        var_r30_1729 = 0x50;
        do {
            temp_r29_1731 = this + var_r30_1729;
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r29_1731, s32 *, 0x274), &sp2C0);
            sp2F0.unk30 = M2C_BITWISE(f32, sp2C0);
            sp2F0.unk34 = sp2C0.unk4;
            sp2F0.unk38 = sp2C0.unk8;
            sp2F0.unk3C = 1.0f;
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r29_1731, MKModel **, 0x270), sp2F0);
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r29_1731, MKModel **, 0x270), this->unk360, &sp2A0);
            var_r26_1750 = 0;
loop_42:
            temp_r5_1756 = this->unk8;
            temp_f28_1757 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            sp40 = -M2C_FIELD(temp_r5_1756, f32 *, 0x20);
            sp44 = -M2C_FIELD(temp_r5_1756, f32 *, 0x24);
            sp48 = -M2C_FIELD(temp_r5_1756, f32 *, 0x28);
            sp1B0 = (f64) sp40;
            sp1B8 = (f64) sp48;
            sp1C0.operator*(4000.0f);
            sp1D0.operator*(temp_f28_1757);
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp200, sp1F0);
            sp210.operator*(1000.0f);
            sp80 = sp210 + M2C_BITWISE(f64, sp1D0);
            temp_r3_1803 = this->unk240;
            sp220 = sp80;
            sp88 = sp210.unk8 + sp1D0.unk8;
            sp2B0 = sp80;
            sp228 = (f64) sp88;
            sp2B8 = (f64) sp88;
            temp_r3_1815 = M2C_FIELD(temp_r3_1803->__vptr, void *(**)(MKProp *, f64), 0x3C)(temp_r3_1803, sp80);
            if (temp_r3_1815 != NULL) {
                temp_r25_1818 = M2C_FIELD(temp_r3_1815, void **, 0x2C);
                M2C_FIELD(temp_r3_1815, f64 *, 0) = M2C_BITWISE(f64, sp2A0);
                M2C_FIELD(temp_r3_1815, f64 *, 8) = (f64) sp2A0.unk8;
                M2C_FIELD(temp_r3_1815, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1815, f32 *, 0x28) = 0.0f;
                temp_f0_1833 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp70 = 0.25f;
                sp74 = 0.25f;
                M2C_FIELD(temp_r3_1815, f32 *, 0x24) = (f32) (2.0f * temp_f0_1833);
                sp78 = 0.25f;
                sp7C = 1.0f;
                M2C_FIELD(temp_r3_1815, f64 *, 0x10) = (f64) sp70;
                M2C_FIELD(temp_r3_1815, f64 *, 0x18) = (f64) sp78;
                M2C_FIELD(temp_r25_1818, f64 *, 0) = sp2B0;
                sp1A0 = (f64) sp70;
                sp1A8 = (f64) sp78;
                M2C_FIELD(temp_r25_1818, f64 *, 8) = sp2B8;
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
    if (((MKAnimScript *) this->unk240)->CheckEvent(0) != 0) {
        var_r27_1877 = 0;
        var_r30_1878 = 0;
        do {
            temp_r29_1880 = this + var_r30_1878;
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r29_1880, s32 *, 0x274), &sp2C0);
            sp2F0.unk30 = M2C_BITWISE(f32, sp2C0);
            sp2F0.unk34 = sp2C0.unk4;
            sp2F0.unk38 = sp2C0.unk8;
            sp2F0.unk3C = 1.0f;
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r29_1880, MKModel **, 0x270), sp2F0);
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r29_1880, MKModel **, 0x270), this->unk364, &sp2A0);
            var_r25_1899 = 0;
loop_49:
            temp_r5_1905 = this->unk8;
            temp_f28_1906 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            sp30 = -M2C_FIELD(temp_r5_1905, f32 *, 0x20);
            sp34 = -M2C_FIELD(temp_r5_1905, f32 *, 0x24);
            sp38 = -M2C_FIELD(temp_r5_1905, f32 *, 0x28);
            sp120 = (f64) sp30;
            sp128 = (f64) sp38;
            sp130.operator*(4000.0f);
            sp140.operator*(temp_f28_1906);
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp170, sp160);
            sp180.operator*(1000.0f);
            sp60 = sp180 + M2C_BITWISE(f64, sp140);
            temp_r3_1952 = this->unk240;
            sp190 = sp60;
            sp68 = sp180.unk8 + sp140.unk8;
            sp20 = sp60;
            sp198 = (f64) sp68;
            sp28 = (f64) sp68;
            temp_r3_1964 = M2C_FIELD(temp_r3_1952->__vptr, void *(**)(MKProp *, f64), 0x3C)(temp_r3_1952, sp60);
            if (temp_r3_1964 != NULL) {
                temp_r26_1967 = M2C_FIELD(temp_r3_1964, void **, 0x2C);
                M2C_FIELD(temp_r3_1964, f64 *, 0) = M2C_BITWISE(f64, sp2A0);
                M2C_FIELD(temp_r3_1964, f64 *, 8) = (f64) sp2A0.unk8;
                M2C_FIELD(temp_r3_1964, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1964, f32 *, 0x28) = 0.0f;
                temp_f0_1982 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp50 = 0.25f;
                sp54 = 0.25f;
                M2C_FIELD(temp_r3_1964, f32 *, 0x24) = (f32) (2.0f * temp_f0_1982);
                sp58 = 0.25f;
                sp5C = 1.0f;
                M2C_FIELD(temp_r3_1964, f64 *, 0x10) = (f64) sp50;
                M2C_FIELD(temp_r3_1964, f64 *, 0x18) = (f64) sp58;
                M2C_FIELD(temp_r26_1967, f64 *, 0) = sp20;
                sp100.unk10 = (f64) sp50;
                sp118 = (f64) sp58;
                M2C_FIELD(temp_r26_1967, f64 *, 8) = sp28;
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
        ((KDSoundFader *) &this->unk320)->Init(0.25f, 0.25f);
    }
}
#endif

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

#if 0 // DRAFT: ')' expected
s32 ShatterableBoat::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r30_2160;
    s32 temp_r3_2147;

    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadFloat("speed", (f32 *) &this->unk218, 0) != 0) || (arg0->LoadFloat("waterheight", &this->unk314, 0) != 0)) {
        return 1;
    }
    arg0->GetFieldName();
    if (stricmp"waypoints" == 0) {
        if ((u32) M2C_FIELD(this, u32 *, 0x224) != 0U) {
            return 0;
        }
        temp_r3_2147 = arg0->GetNmbrOfSubLines();
        if (temp_r3_2147 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk218)->Init(temp_r3_2147, 0U);
        var_r30_2160 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r30_2160 != NULL) {
            var_r30_2160->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk218)->AddNode(sp8);
            var_r30_2160 = var_r30_2160->unkC->GetNextLine(var_r30_2160);
            goto loop_11;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
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

    this->unk234 = ((MKAnimScript *) "p7007_ship_oar_left")->Create((s8 *)1, M2C_ERROR(/* Read from unset register $r5 */));
    ((MKAnimScript *) this->unk234)->InitEvents(&pLeftOarAnimEvents);
    temp_r29_2206 = this->unk234;
    if (((MKAnimScript *) temp_r29_2206)->Exists("row") != 0) {
        var_r3_2218 = ((MKAnimScript *) temp_r29_2206)->GetAnim("row");
    } else {
        var_r3_2218 = NULL;
    }
    this->unk238 = (s32) var_r3_2218;
    temp_r29_2226 = this->unk234;
    if (((MKAnimScript *) temp_r29_2226)->Exists("idle") != 0) {
        var_r3_2236 = ((MKAnimScript *) temp_r29_2226)->GetAnim("idle");
    } else {
        var_r3_2236 = NULL;
    }
    this->unk23C = M2C_BITWISE(f32, var_r3_2236);
    this->unk240 = ((MKAnimScript *) "p7008_ship_oar_right")->Create((s8 *)1, M2C_ERROR(/* Read from unset register $r5 */));
    ((MKAnimScript *) this->unk240)->InitEvents(&pRightOarAnimEvents);
    temp_r29_2251 = this->unk240;
    if (((MKAnimScript *) temp_r29_2251)->Exists("row") != 0) {
        var_r3_2263 = ((MKAnimScript *) temp_r29_2251)->GetAnim("row");
    } else {
        var_r3_2263 = NULL;
    }
    this->unk244 = var_r3_2263;
    temp_r29_2271 = this->unk240;
    if (((MKAnimScript *) temp_r29_2271)->Exists("idle") != 0) {
        var_r3_2281 = ((MKAnimScript *) temp_r29_2271)->GetAnim("idle");
    } else {
        var_r3_2281 = NULL;
    }
    this->unk248 = M2C_BITWISE(f32, var_r3_2281);
    ((MKAnimScript *) this->unk234)->SetAnim(M2C_BITWISE(MKAnim *, this->unk23C), 1.0f, 0.0f, 0, -1);
    ((MKAnimScript *) this->unk240)->SetAnim(M2C_BITWISE(MKAnim *, this->unk248), 1.0f, 0.0f, 0, -1);
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
        temp_r3_2332 = Tools_GetMatchingRefPointIndex(this->unk4, Str_Printf("r_position_oar%d", var_r28_2322 + 1));
        var_r28_2322 += 1;
        temp_r0_2334 = var_r30_2324 + 0x274;
        var_r30_2324 += 0x10;
        *(this + temp_r0_2334) = (s32) temp_r3_2332;
    } while (var_r28_2322 < 0xA);
    this->unk360 = (s32) Tools_GetMatchingRefPointIndex(M2C_FIELD(this->unk234, MKModel **, 8), "fxemitL0");
    this->unk364 = (s32) Tools_GetMatchingRefPointIndex((MKModel *) this->unk240->unk8, "fxemitR0");
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterableBoat::Init() {
    ShatterablePlatform::Init();
    this->unk234 = 1;
    M2C_FIELD(this, f32 *, 0x22C) = 0.0f;
    this->unk218 = 100.0f;
    this->unk220 = 0.0f;
    this->unk224 = 0.0f;
    gMK->CreatePropDeferred("WaterDropsPS", &this->unk240);
    this->unk22C = M2C_BITWISE(f32, checked_cast<WaterSurfaceFX *, MKProp>(gMK->CreateProp("WaterSurfaceFX")));
    M2C_FIELD(this->unk22C, f32 *, 0x58) = 2.0f;
    this->unk230 = 0.0f;
    this->unk310 = MKModel_Create("p7009_WaterWake", NULL, 2, NULL);
    this->unk314 = 0.0f;
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[17], long *)' does
s32 ShatterableBoatDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2425;

    var_r31_2425 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "AmbientSoundLoop", &this->unk16C) != 0) || (KDSound_LoadLine(arg0, "sndSink", &this->unk170) != 0)) {
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
