#include "spyro/source/TeslaTower.h"
#include "common/Source/Animation.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/ZapPS.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_TeslaTowerAlarm;
extern s32 GS_TeslaTowerBeamLP;
extern s32 GS_TeslaTowerExtra1;
extern s32 GS_TeslaTowerZapSpyro1;
extern s32 GS_TeslaTowerZapSpyro2;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'KDSpline' to
void TeslaTower::UpdateTurretTurning() {
    Matrix spD0;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    KDSpline sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    s16 sp10;
    Animation *temp_r3_103;
    f32 temp_f10_218;
    f32 temp_f11_239;
    f32 temp_f3_241;
    f32 temp_f4_249;
    f32 temp_r31_101;
    f32 var_f12_127;
    f32 var_f4_144;
    f64 temp_f0_125;
    f64 temp_f1_149;
    f64 temp_f1_155;
    f64 temp_f1_159;
    s32 temp_r3_178;
    s32 var_r0_188;
    void *temp_r30_99;

    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_BITWISE(s32, this->unk90.unk20), &spA8);
    sp68.GetMeasure(this->unk90.unk14, &this->unk90);
    spB8 = M2C_BITWISE(f64, sp68);
    temp_r30_99 = this->unk8;
    spC0 = (f64) sp68.unk8;
    temp_r31_101 = this->unk90.unk1C;
    temp_r3_103 = MKModel_GetAnimation(this->unk4);
    sp10 = M2C_BITWISE(s16, temp_r31_101);
    temp_r3_103->CalculateMatrices(&spD0, 1, &sp10, (Matrix *) temp_r30_99);
    sp48 = -spD0.unk20;
    sp4C = -spD0.unk24;
    sp50 = -spD0.unk28;
    sp98 = (f64) sp48;
    spA0 = (f64) sp50;
    temp_f0_125 = spB8 - M2C_BITWISE(f64, spA8);
    sp38 = temp_f0_125;
    var_f12_127 = 0.0f;
    sp88 = temp_f0_125;
    (*(f32 *) ((u8 *) &sp80 + 0xc)) = 0.0f;
    sp40 = (f32) spC0 - spA8.unk8;
    sp90 = (f64) sp40;
    var_f4_144 = ((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + (0.0f * 0.0f));
    if (var_f4_144 > 0.000001f) {
        if (var_f4_144 > 0.0f) {
            temp_f1_149 = __frsqrte(var_f4_144);
            temp_f1_155 = 0.5 * temp_f1_149 * -(((f64) var_f4_144 * (temp_f1_149 * temp_f1_149)) - 3.0);
            temp_f1_159 = 0.5 * temp_f1_155 * -(((f64) var_f4_144 * (temp_f1_155 * temp_f1_155)) - 3.0);
            var_f4_144 = (f32) ((f64) var_f4_144 * (0.5 * temp_f1_159 * -(((f64) var_f4_144 * (temp_f1_159 * temp_f1_159)) - 3.0)));
        } else if (var_f4_144 < M2C_BITWISE(f32, 0.0)) {
            var_f4_144 = __float_nan;
        } else {
            sp14 = var_f4_144;
            temp_r3_178 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_178) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_188 = 1;
                } else {
                    var_r0_188 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_188 = 5;
                } else {
                    var_r0_188 = 3;
                }
                break;
            default:
                var_r0_188 = 4;
                break;
            }
            if (var_r0_188 == 1) {
                var_f4_144 = __float_nan;
            }
        }
        var_f12_127 = 1.0f / var_f4_144;
    }
    sp30 = 0.0f;
    sp28 = 0.0f;
    temp_f10_218 = (*(f32 *) ((u8 *) &sp80 + 0xc)) * var_f12_127;
    sp2C = 1.0f;
    sp60 = (f64) sp30;
    sp58 = (f64) sp28;
    (*(f32 *) ((u8 *) &sp80 + 0xc)) = temp_f10_218;
    temp_f11_239 = (f32) sp88 * var_f12_127;
    sp18 = ((*(f32 *) ((u8 *) &sp58 + 0x4)) * (f32) spA0) - ((f32) sp60 * (*(f32 *) ((u8 *) &sp98 + 0x4)));
    temp_f3_241 = (f32) sp90 * var_f12_127;
    sp1C = ((f32) sp60 * (f32) sp98) - ((f32) sp58 * (f32) spA0);
    sp20 = ((f32) sp58 * (*(f32 *) ((u8 *) &sp98 + 0x4))) - ((*(f32 *) ((u8 *) &sp58 + 0x4)) * (f32) sp98);
    sp68.unk10 = (f64) sp18;
    temp_f4_249 = 1.0f - (((f32) spA0 * temp_f3_241) + (((f32) sp98 * temp_f11_239) + ((*(f32 *) ((u8 *) &sp98 + 0x4)) * temp_f10_218)));
    sp80 = (f64) sp20;
    sp88 = temp_f11_239;
    sp90 = temp_f3_241;
    if (((temp_f3_241 * (f32) sp80) + ((temp_f11_239 * M2C_BITWISE(f32, sp68.unk10)) + (temp_f10_218 * sp7C))) > 0.0f) {
        this->unk1C8 -= temp_f4_249;
        return;
    }
    this->unk1C8 += temp_f4_249;
}
#endif

#if 0 // DRAFT: ')' expected
void TeslaTower::ZapTarget(const MKVector3 &arg0, const MKVector3 &arg1) {
    this->unkF0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unkF8 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk100 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk108 = M2C_FIELD(&arg1, f64 *, 8);
    if ((EnergyBeam::Beam *) this->unk110 == NULL) {
        ((EnergyBeam *) (M2C_FIELD(checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x70)))->SpawnEnergyBeam((MKVector3 *) &this->unkF0, (MKVector3 *) &this->unk100, 1.0f);
        this->unk110 = M2C_ERROR(/* Read from unset register $r3 */);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp68'
u8 TeslaTower::FindZapTargets(bool arg0) {
    s8 sp139;
    s8 sp138;
    s32 sp134;
    f32 sp130;
    s32 sp12C;
    s8 sp12A;
    s8 sp129;
    s8 sp128;
    f64 sp120;                                      /* compiler-managed */
    f64 sp118;                                      /* compiler-managed */
    TeslaTower *sp114;
    s32 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    s32 spEC;
    s32 spE8;
    BreathHitMessage sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    TargetManager ***var_r31_355;
    TargetManager **temp_r30_559;
    f32 temp_f0_337;
    f32 temp_f2_410;
    f32 temp_f2_414;
    f32 temp_f31_339;
    f32 temp_f3_411;
    u8 var_r27_335;
    void *temp_r3_402;
    void *temp_r3_426;
    void *temp_r6_431;

    var_r27_335 = 0;
    temp_f0_337 = 300.0f * this->unk90.unk30;
    temp_f31_339 = temp_f0_337 * temp_f0_337;
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_BITWISE(s32, this->unk90.unk20), &sp70);
    ((KDSpline *) &sp60)->GetMeasure(this->unk90.unk14, &this->unk90);
    sp80 = sp60;
    sp88 = sp68;
    var_r31_355 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_19:
    if ((var_r31_355 == NULL) || (temp_r30_559 = *var_r31_355, ((temp_r30_559 == NULL) != 0))) {
        if (var_r27_335 == 0) {
            this->unk90.unk2C = 0.0f;
        }
        return var_r27_335;
    }
    if ((((*temp_r30_559)->unk8.unk0(temp_r30_559) != NULL) && (M2C_FIELD(*temp_r30_559, u8 (**)(TargetManager **), 0x18)(temp_r30_559) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r30_559)->unk8.unk4)(temp_r30_559) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r30_559)->unk8.unk4)(temp_r30_559)))->IsActive() != 0))) || (((u8 (*)(TargetManager **)) (*temp_r30_559)->unk8.unk8)(temp_r30_559) != 0)) {
        temp_r3_402 = M2C_FIELD((*temp_r30_559)->unk8.unk0(temp_r30_559), void **, 8);
        sp50 = M2C_FIELD(temp_r3_402, f64 *, 0x30);
        sp58 = M2C_FIELD(temp_r3_402, f64 *, 0x38);
        temp_f2_410 = (*(f32 *) ((u8 *) &sp50 + 0x4)) - (*(f32 *) ((u8 *) &sp80 + 0x4));
        temp_f3_411 = (f32) sp50 - (f32) sp80;
        temp_f2_414 = (f32) sp58 - (f32) sp88;
        if (((temp_f2_414 * temp_f2_414) + ((temp_f3_411 * temp_f3_411) + (temp_f2_410 * temp_f2_410))) <= temp_f31_339) {
            temp_r3_426 = (*temp_r30_559)->unk8.unk0(temp_r30_559);
            if (temp_r3_426 != NULL) {
                if (arg0 != 0) {
                    temp_r6_431 = M2C_FIELD(temp_r3_426, void **, 8);
                    sp40 = M2C_FIELD(temp_r6_431, f64 *, 0x30);
                    sp48 = M2C_FIELD(temp_r6_431, f64 *, 0x38);
                    ZapTarget(sp70, *((MKVector3 *) &sp40));
                    if (temp_r3_426 == M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u32 (**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0))) {
                        if (this->unk90.unk2C <= 0.0f) {
                            sp18 = 0.0f;
                            sp10 = 0.0f;
                            sp14 = 0.0f;
                            spEC = 0;
                            sp30 = (f64) sp10;
                            sp38 = (f64) sp18;
                            spE8 = 7;
                            sp110 = 1;
                            sp114 = this;
                            spF0 = (f64) sp10;
                            spF8 = (f64) sp18;
                            sp128 = 1;
                            sp134 = 2;
                            sp130 = 10.0f;
                            sp129 = 0;
                            sp12A = 1;
                            sp12C = -1;
                            sp100 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                            sp108 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                            sp138 = 0;
                            if (this != NULL) {
                                ((MKProp *) &sp20)->GetPos();
                                sp118 = sp20;
                                sp120 = sp28;
                            } else {
                                sp118 = 0.0f;
                                (*(f32 *) ((u8 *) &sp114 + 0x8)) = 0.0f;
                                sp120 = 0.0f;
                            }
                            sp139 = 0;
                            M2C_FIELD(M2C_FIELD(temp_r3_426, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_426, &spE8);
                            this->unk90.unk2C = 2.0f;
                            KDSound_Play3d(GS_TeslaTowerZapSpyro2, M2C_FIELD(temp_r3_426, void **, 8) + 0x30, 0U, -1, 0.0f, 0U);
                        }
                        var_r27_335 = 1;
                    } else {
                        sp90.unk4 = 0;
                        sp8 = -1;
                        sp90.Init((MKProp *) this, 1, 0, 0, 1, 1, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                        M2C_FIELD(M2C_FIELD(temp_r3_426, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_426, &sp90.unk0);
                        KDSound_Play3d(GS_TeslaTowerZapSpyro2, M2C_FIELD(temp_r3_426, void **, 8) + 0x30, 0U, -1, 0.0f, 0U);
                        var_r27_335 = 1;
                    }
                    goto block_18;
                }
                return 1U;
            }
        }
    }
block_18:
    var_r31_355 += 4;
    goto loop_19;
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void TeslaTower::DrawLightCone() {
    M2C_UNK sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    M2C_UNK sp20C;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;                                      /* compiler-managed */
    f64 sp1C8;                                      /* compiler-managed */
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f1_657;
    f32 temp_f23_655;
    f32 temp_f30_924;
    f32 temp_f5_812;
    f32 temp_f6_810;
    f32 temp_f7_809;
    f32 temp_r0_623;
    f32 var_f0_731;
    f32 var_f31_615;
    f32 var_f4_798;
    f64 temp_f0_907;
    f64 temp_f0_933;
    f64 temp_f0_943;
    f64 temp_f0_954;
    f64 temp_f2_737;
    f64 temp_f2_743;
    f64 temp_f2_747;
    s32 temp_r3_766;
    s32 var_r0_776;
    s32 var_r28_646;
    s32 var_r28_895;
    s32 var_r30_648;
    s32 var_r30_896;
    void *temp_r29_905;
    void *temp_r3_659;

    spC8 = 0.01f;
    var_f31_615 = 0.0f;
    spCC = 0.01f;
    spD0 = 0.01f;
    spD4 = 1.0f;
    sp1F8 = (f64) spC8;
    sp200 = (f64) spD0;
    temp_r0_623 = this->unk90.unk24;
    if ((M2C_BITWISE(s32, temp_r0_623) == 1) || (M2C_BITWISE(s32, temp_r0_623) == 2)) {
        sp68 = 0.1f;
        sp6C = 0.0f;
        sp70 = 0.0f;
        sp74 = 1.0f;
        sp198 = (f64) sp68;
        sp1A0 = (f64) sp70;
        sp1F8 = (f64) sp68;
        sp200 = (f64) sp70;
    }
    var_r28_646 = 0;
    var_r30_648 = 0;
    do {
        temp_f23_655 = 50.0f * -_table_sinf(1.5707964f + var_f31_615);
        temp_f1_657 = 50.0f * _table_sinf(var_f31_615);
        sp60 = 0.0f;
        temp_r3_659 = &sp250 + var_r30_648;
        var_r28_646 += 1;
        sp58 = temp_f1_657;
        var_f31_615 += 0.8975979f;
        var_r30_648 += 0x10;
        sp5C = temp_f23_655;
        sp190 = (f64) sp60;
        M2C_FIELD(temp_r3_659, f64 *, 0) = (f64) sp58;
        sp188 = (f64) sp58;
        M2C_FIELD(temp_r3_659, f64 *, 8) = (f64) sp60;
    } while (var_r28_646 < 8);
    M2C_STRUCT_COPY((s32) &sp20C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp50 = 0.0f;
    sp48 = 0.0f;
    sp4C = 1.0f;
    sp180 = (f64) sp50;
    sp178 = (f64) sp48;
    sp1B8 = (f64) sp48;
    sp1C0 = (f64) sp50;
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_BITWISE(s32, this->unk90.unk20), &sp1E8);
    ((KDSpline *) &sp168)->GetMeasure(this->unk90.unk14, &this->unk90);
    sp1D8 = sp168;
    sp1E0 = sp170;
    sp38 = sp168 - M2C_BITWISE(f64, sp1E8);
    sp1C8 = sp38;
    sp40 = (f32) sp1E0 - sp1E8.unk8;
    sp158 = sp38;
    sp1D0 = (f64) sp40;
    sp160 = (f64) sp40;
    var_f0_731 = ((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + ((*(f32 *) ((u8 *) &sp1C0 + 0xc)) * (*(f32 *) ((u8 *) &sp1C0 + 0xc))));
    if (var_f0_731 > 0.000001f) {
        if (var_f0_731 > 0.0f) {
            temp_f2_737 = __frsqrte(var_f0_731);
            temp_f2_743 = 0.5 * temp_f2_737 * -(((f64) var_f0_731 * (temp_f2_737 * temp_f2_737)) - 3.0);
            temp_f2_747 = 0.5 * temp_f2_743 * -(((f64) var_f0_731 * (temp_f2_743 * temp_f2_743)) - 3.0);
            var_f0_731 = (f32) ((f64) var_f0_731 * (0.5 * temp_f2_747 * -(((f64) var_f0_731 * (temp_f2_747 * temp_f2_747)) - 3.0)));
        } else if (var_f0_731 < M2C_BITWISE(f32, 0.0)) {
            var_f0_731 = __float_nan;
        } else {
            sp10 = var_f0_731;
            temp_r3_766 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_766) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_776 = 1;
                } else {
                    var_r0_776 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_776 = 5;
                } else {
                    var_r0_776 = 3;
                }
                break;
            default:
                var_r0_776 = 4;
                break;
            }
            if (var_r0_776 == 1) {
                var_f0_731 = __float_nan;
            }
        }
        var_f4_798 = 1.0f / var_f0_731;
    } else {
        var_f4_798 = 0.0f;
        var_f0_731 = 0.0f;
    }
    temp_f7_809 = (f32) sp1C8 * var_f4_798;
    temp_f6_810 = (*(f32 *) ((u8 *) &sp1C0 + 0xc)) * var_f4_798;
    temp_f5_812 = (f32) sp1D0 * var_f4_798;
    sp1C8 = temp_f7_809;
    (*(f32 *) ((u8 *) &sp1C0 + 0xc)) = temp_f6_810;
    sp28 = ((*(f32 *) ((u8 *) &sp1B8 + 0x4)) * temp_f5_812) - ((f32) sp1C0 * temp_f6_810);
    sp2C = ((f32) sp1C0 * temp_f7_809) - ((f32) sp1B8 * temp_f5_812);
    sp30 = ((f32) sp1B8 * temp_f6_810) - ((*(f32 *) ((u8 *) &sp1B8 + 0x4)) * temp_f7_809);
    sp1D0 = temp_f5_812;
    sp138 = (f64) sp28;
    sp140 = (f64) sp30;
    Normalise(sp148);
    sp1A8 = M2C_BITWISE(f64, sp148);
    sp1B0 = (f64) sp148.unk8;
    sp20 = (sp1C8 * (*(f32 *) ((u8 *) &sp1A8 + 0x4))) - ((*(f32 *) ((u8 *) &sp1C0 + 0xc)) * (f32) sp1A8);
    sp1C = (sp1D0 * (f32) sp1A8) - (sp1C8 * (f32) sp1B0);
    sp18 = ((*(f32 *) ((u8 *) &sp1C0 + 0xc)) * (f32) sp1B0) - (sp1D0 * (*(f32 *) ((u8 *) &sp1A8 + 0x4)));
    sp1C0 = (f64) sp20;
    sp1B8 = (f64) sp18;
    sp210 = (f32) sp1A8;
    sp214 = (*(f32 *) ((u8 *) &sp1A8 + 0x4));
    sp218 = (f32) sp1B0;
    sp21C = 0.0f;
    sp220 = (f32) sp1B8;
    sp224 = (*(f32 *) ((u8 *) &sp1B8 + 0x4));
    sp228 = (f32) sp1C0;
    sp22C = 0.0f;
    sp230 = sp1C8;
    sp234 = (*(f32 *) ((u8 *) &sp1C0 + 0xc));
    sp238 = sp1D0;
    sp23C = 0.0f;
    sp240 = M2C_BITWISE(f32, sp1E8);
    sp244 = sp1E8.unk4;
    sp248 = sp1E8.unk8;
    sp24C = 1.0f;
    sp128 = (f64) sp18;
    sp130 = (f64) sp20;
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x74));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(*((Matrix *) &sp210));
    MKBegin(0x10);
    var_r28_895 = 0;
    var_r30_896 = 0;
    do {
        MKSetColorV(*((MKVector4 *) &sp1F8));
        MKSetTexCoord1F(0.0f, 0.0f);
        temp_r29_905 = &sp250 + var_r30_896;
        temp_f0_907 = M2C_FIELD(temp_r29_905, f64 *, 0) * 5.122630465e-315;
        spB8 = temp_f0_907;
        sp118 = temp_f0_907;
        spC0 = M2C_FIELD(temp_r29_905, f32 *, 8) * 0.1f;
        sp120 = (f64) spC0;
        MKSetPositionV(*((MKVector3 *) &sp118));
        MKSetColorV(*((MKVector4 *) &sp1F8));
        MKSetTexCoord1F(0.0f, 0.0f);
        sp90 = 1.25f * var_f0_731;
        temp_f30_924 = this->unk90.unk30;
        sp88 = 0.0f;
        sp8C = 0.0f;
        spE0 = (f64) sp90;
        spD8 = (f64) sp88;
        temp_f0_933 = M2C_FIELD(temp_r29_905, f64 *, 0) * 5.37751863e-315;
        spA8 = temp_f0_933;
        spE8 = temp_f0_933;
        spB0 = M2C_FIELD(temp_r29_905, f32 *, 8) * 7.0f;
        spF0 = (f64) spB0;
        temp_f0_943 = temp_f0_933 * (f64) temp_f30_924;
        sp98 = temp_f0_943;
        spF8 = temp_f0_943;
        spA0 = (f32) spF0 * temp_f30_924;
        sp100 = (f64) spA0;
        temp_f0_954 = spF8 + spD8;
        sp78 = temp_f0_954;
        sp108 = temp_f0_954;
        sp80 = (f32) sp100 + (f32) spE0;
        sp110 = (f64) sp80;
        MKSetPositionV(*((MKVector3 *) &sp108));
        var_r28_895 += 1;
        var_r30_896 += 0x10;
    } while (var_r28_895 < 8);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void TeslaTower::Deinit() {
    KDSound_Stop(&this->unk114);
    KDSound_Stop(&this->unk13C);
    KDSound_Stop(&this->unk164);
    KDSound_Stop(&this->unk18C);
    ((KDSpline *) &this->unk90)->Deinit();
    ((EnergyBeam *) (M2C_FIELD(checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x70)))->FreeEnergyBeam(this->unk110);
    this->unk110 = NULL;
    KDProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void TeslaTower::Draw() {
    u8 var_r31_1046;

    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r31_1046 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r31_1046 = 1;
        }
        if (var_r31_1046 == 0) {
            goto block_6;
        }
    } else {
block_6:
        KDProp::Draw();
        DrawLightCone();
    }
}
#endif

void TeslaTower::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) &this->unk114)->Message(arg0);
    ((KDSoundPlayer *) &this->unk13C)->Message(arg0);
    ((KDSoundPlayer *) &this->unk164)->Message(arg0);
    ((KDSoundPlayer *) &this->unk18C)->Message(arg0);
    KDProp::Message(arg0);
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void TeslaTower::Update() {
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    s32 sp8;
    f32 temp_f1_1169;
    f32 temp_r0_1141;
    f32 temp_r0_1177;
    u8 temp_r3_1265;
    u8 temp_r3_1294;
    u8 var_r6_1140;

    sp8 = 1;
    ((KDSoundFader *) &this->unk18C)->Update(GS_TeslaTowerExtra1, 1U, 1U, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    ((KDSoundFader *) &this->unk114)->Update(GS_TeslaTowerBeamLP, 1U, M2C_BITWISE(s32, this->unk90.unk24) == 0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    var_r6_1140 = 0;
    temp_r0_1141 = this->unk90.unk24;
    if ((M2C_BITWISE(s32, temp_r0_1141) == 1) || (M2C_BITWISE(s32, temp_r0_1141) == 2)) {
        var_r6_1140 = 1;
    }
    ((KDSoundFader *) &this->unk13C)->Update(GS_TeslaTowerAlarm, 1U, var_r6_1140, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    ((KDSoundFader *) &this->unk164)->Update(GS_TeslaTowerZapSpyro1, 1U, M2C_BITWISE(s32, this->unk90.unk24) == 2, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f1_1169 = this->unk90.unk2C;
    if (temp_f1_1169 > 0.0f) {
        this->unk90.unk2C = temp_f1_1169 - gUpdateTimeDelta;
    }
    temp_r0_1177 = this->unk90.unk24;
    switch (M2C_BITWISE(s32, temp_r0_1177)) {       /* irregular */
    case 0:
        this->unk90.unk14 += this->unk90.unk18 * gUpdateTimeDelta;
        if (this->unk90.unk18 > 0.0f) {
            if (this->unk90.unk14 >= 1.0f) {
                this->unk90.unk14 = 1.0f;
                this->unk90.unk18 = -this->unk90.unk18;
            }
        } else if (this->unk90.unk14 <= 0.0f) {
            this->unk90.unk14 = 0.0f;
            this->unk90.unk18 = -this->unk90.unk18;
        }
        if (FindZapTargets(0U) != 0) {
            this->unk90.unk24 = 1e-45f;
            this->unk90.unk28 = 0.0f;
        }
        break;
    case 1:
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_BITWISE(s32, this->unk90.unk20), &sp58);
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 1.0f;
        sp24 = 1.0f;
        sp38 = (f64) sp18;
        sp40 = (f64) sp20;
        sp10 = MKRand_Float(&gViewSeed, 16.0f, 20.0f);
        sp30 = 0.0f;
        sp28 = 0.0f;
        sp2C = 0.0f;
        sp50 = (f64) sp30;
        sp48 = (f64) sp28;
        ((ZapPS *) (M2C_FIELD(checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x78)))->Emit(sp58, *((MKVector3 *) &sp48), sp10, (MKVector4) &sp38);
        temp_r3_1265 = FindZapTargets(0U);
        this->unk90.unk28 -= gUpdateTimeDelta;
        if ((this->unk90.unk28 <= 0.0f) || (temp_r3_1265 == 0)) {
            if (temp_r3_1265 != 0) {
                this->unk90.unk28 = 1.5f;
                this->unk90.unk24 = 3e-45f;
            } else {
                this->unk90.unk28 = 0.0f;
                this->unk90.unk24 = 0.0f;
            }
        }
        break;
    case 2:
        temp_r3_1294 = FindZapTargets(1U);
        this->unk90.unk28 -= gUpdateTimeDelta;
        if ((this->unk90.unk28 <= 0.0f) || (temp_r3_1294 == 0)) {
            this->unk90.unk28 = 0.0f;
            this->unk90.unk24 = 0.0f;
            ((EnergyBeam *) (M2C_FIELD(checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x70)))->FreeEnergyBeam(this->unk110);
            this->unk110 = NULL;
        }
        break;
    }
    UpdateTurretTurning();
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void TeslaTower::UpdateTurretBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 temp_r31_1379;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = -arg0->unk0;
    sp14 = -arg0->unk4;
    sp18 = -arg0->unk8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30.Translate(&sp30, *((MKVector3 *) &sp20));
    sp30.RotateYaw(&sp30, arg0->unk10);
    sp30.Translate(&sp30, *((MKVector3 *) arg0));
    temp_r31_1379 = M2C_FIELD(this->unk20, s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix((s32) temp_r31_1379, &sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: illegal type
void TeslaTower::LoadDone() {
    Matrix sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    MKVector3 sp150;
    MKVector3 sp140;
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f32 temp_f25_1474;
    f32 temp_f29_1454;
    f32 temp_f3_1598;
    f32 temp_f3_1635;
    f32 temp_f6_1607;
    f32 temp_f7_1613;
    f32 temp_f8_1641;
    f32 temp_f9_1647;
    f64 temp_f0_1692;
    f64 temp_f2_1481;
    f64 temp_f3_1461;
    f64 temp_f3_1501;
    s32 var_r28_1502;
    s32 var_r30_1504;
    void *temp_r29_1519;
    void *temp_r3_1429;
    void *temp_r3_1436;
    void *temp_r5_1435;
    void *temp_r6_1453;
    void *temp_r6_1473;

    KDProp::LoadDone();
    this->unk90.unk20 = M2C_BITWISE(f32, Tools_GetMatchingRefPointIndex(this->unk4, "zap"));
    temp_r3_1429 = M2C_FIELD(this->unk0, void **, 0x1C);
    this->unkD0 = M2C_FIELD(temp_r3_1429, f64 *, 0);
    this->unkD8 = M2C_FIELD(temp_r3_1429, f64 *, 8);
    temp_r5_1435 = M2C_FIELD(this->unk0, void **, 0x1C);
    temp_r3_1436 = temp_r5_1435 + 0x10;
    sp90 = M2C_FIELD(temp_r5_1435, f64 *, 0) + M2C_FIELD(temp_r3_1436, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xE0) = sp90;
    sp98 = M2C_FIELD(temp_r5_1435, f32 *, 8) + M2C_FIELD(temp_r3_1436, f32 *, 8);
    sp170 = sp90;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp98;
    temp_r6_1453 = this->unk8;
    temp_f29_1454 = (f32) M2C_FIELD(this, f64 *, 0xD8);
    temp_f3_1461 = this->unkD0;
    sp178 = (f64) sp98;
    M2C_FIELD(this, f64 *, 0xD8) = (f32) (((f64) M2C_FIELD(temp_r6_1453, f32 *, 8) * temp_f3_1461) + (((f64) M2C_FIELD(temp_r6_1453, f32 *, 0x18) * temp_f3_1461) + (((f64) M2C_FIELD(temp_r6_1453, f32 *, 0x28) * (f64) temp_f29_1454) + (f64) M2C_FIELD(temp_r6_1453, f32 *, 0x38))));
    this->unkD0 = (M2C_FIELD(temp_r6_1453, f64 *, 0) * temp_f3_1461) + ((M2C_FIELD(temp_r6_1453, f64 *, 0x10) * temp_f3_1461) + ((M2C_FIELD(temp_r6_1453, f64 *, 0x20) * (f64) temp_f29_1454) + M2C_FIELD(temp_r6_1453, f64 *, 0x30)));
    temp_r6_1473 = this->unk8;
    temp_f25_1474 = this->unkE0.unk8;
    temp_f2_1481 = M2C_FIELD(this, f64 *, 0xE0);
    this->unkE0.unk8 = (f32) (((f64) M2C_FIELD(temp_r6_1473, f32 *, 8) * temp_f2_1481) + (((f64) M2C_FIELD(temp_r6_1473, f32 *, 0x18) * temp_f2_1481) + (((f64) M2C_FIELD(temp_r6_1473, f32 *, 0x28) * (f64) temp_f25_1474) + (f64) M2C_FIELD(temp_r6_1473, f32 *, 0x38))));
    M2C_FIELD(this, f64 *, 0xE0) = (f64) ((M2C_FIELD(temp_r6_1473, f64 *, 0) * temp_f2_1481) + ((M2C_FIELD(temp_r6_1473, f64 *, 0x10) * temp_f2_1481) + ((M2C_FIELD(temp_r6_1473, f64 *, 0x20) * (f64) temp_f25_1474) + M2C_FIELD(temp_r6_1473, f64 *, 0x30))));
    Min(sp160, *((MKVector3 *) &this->unkD0));
    sp190 = M2C_BITWISE(f64, sp160);
    sp198 = (f64) sp160.unk8;
    Max(sp150, *((MKVector3 *) &this->unkD0));
    temp_f3_1501 = M2C_BITWISE(f64, sp150);
    var_r28_1502 = 0;
    var_r30_1504 = 0;
    this->unkD0 = sp190;
    this->unkD8 = sp198;
    M2C_FIELD(this, f64 *, 0xE0) = temp_f3_1501;
    sp180 = temp_f3_1501;
    sp188 = (f64) sp150.unk8;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp150.unk8;
loop_2:
    if (var_r28_1502 < M2C_BITWISE(s32, this->unk90.unk4)) {
        temp_r29_1519 = M2C_BITWISE(s32, this->unk90.unkC) + var_r30_1504;
        Min(sp140, *((MKVector3 *) &this->unkD0));
        this->unkD0 = M2C_BITWISE(f64, sp140);
        this->unkD8 = (f64) sp140.unk8;
        sp80 = M2C_FIELD(temp_r29_1519, f32 *, 0);
        sp84 = 800.0f + M2C_FIELD(temp_r29_1519, f32 *, 4);
        sp88 = M2C_FIELD(temp_r29_1519, f32 *, 8);
        sp120 = (f64) sp80;
        sp128 = (f64) sp88;
        Max(sp130, this->unkE0);
        var_r28_1502 += 1;
        var_r30_1504 += 0x20;
        M2C_FIELD(this, f64 *, 0xE0) = M2C_BITWISE(f64, sp130);
        M2C_FIELD(this, f64 *, 0xE8) = (f64) sp130.unk8;
        goto loop_2;
    }
    sp70 = 400.0f;
    sp74 = 400.0f;
    sp78 = 400.0f;
    sp110 = (f64) sp70;
    sp118 = (f64) sp78;
    this->unkD0 -= sp110;
    sp68 = 400.0f;
    sp60 = 400.0f;
    sp64 = 400.0f;
    M2C_FIELD(this, f64 *, 0xD8) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xD8) - (f32) sp118);
    sp100 = (f64) sp60;
    sp108 = (f64) sp68;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) (M2C_FIELD(this, f64 *, 0xE0) + sp100);
    this->unkE0.unk8 += (f32) sp108;
    M2C_STRUCT_COPY((s32) &unksp19C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    sp1A0.Inverse(&sp1A0);
    temp_f3_1598 = M2C_FIELD(this, f32 *, 0xD4);
    temp_f6_1607 = (f32) M2C_FIELD(this, f64 *, 0xD0);
    temp_f7_1613 = (f32) M2C_FIELD(this, f64 *, 0xD8);
    sp50 = sp1A0.unk30 + ((temp_f7_1613 * sp1A0.unk20) + ((temp_f6_1607 * M2C_BITWISE(f32, sp1A0)) + (temp_f3_1598 * sp1A0.unk10)));
    sp54 = sp1A0.unk34 + ((temp_f7_1613 * sp1A0.unk24) + ((temp_f6_1607 * sp1A0.unk4) + (temp_f3_1598 * sp1A0.unk14)));
    sp58 = sp1A0.unk38 + ((temp_f7_1613 * sp1A0.unk28) + ((temp_f6_1607 * sp1A0.unk8) + (temp_f3_1598 * sp1A0.unk18)));
    this->unkD0 = (f64) sp50;
    this->unkD8 = (f64) sp58;
    temp_f3_1635 = this->unkE0.unk4;
    temp_f8_1641 = this->unkE0.unk0;
    temp_f9_1647 = this->unkE0.unk8;
    spF0 = (f64) sp50;
    sp40 = sp1A0.unk30 + ((temp_f9_1647 * sp1A0.unk20) + ((temp_f8_1641 * M2C_BITWISE(f32, sp1A0)) + (temp_f3_1635 * sp1A0.unk10)));
    sp44 = sp1A0.unk34 + ((temp_f9_1647 * sp1A0.unk24) + ((temp_f8_1641 * sp1A0.unk4) + (temp_f3_1635 * sp1A0.unk14)));
    sp48 = sp1A0.unk38 + ((temp_f9_1647 * sp1A0.unk28) + ((temp_f8_1641 * sp1A0.unk8) + (temp_f3_1635 * sp1A0.unk18)));
    M2C_FIELD(this, f64 *, 0xE0) = (f64) sp40;
    spF8 = (f64) sp58;
    spE0 = (f64) sp40;
    spE8 = (f64) sp48;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp48;
    Min(spD0, *((MKVector3 *) &this->unkD0));
    sp20 = M2C_BITWISE(f64, spD0);
    sp28 = (f64) spD0.unk8;
    Max(spC0, *((MKVector3 *) &this->unkD0));
    sp10 = M2C_BITWISE(f64, spC0);
    this->unkD0 = sp20;
    sp18 = (f64) spC0.unk8;
    this->unkD8 = sp28;
    temp_f0_1692 = sp10 - sp20;
    sp30 = temp_f0_1692;
    M2C_FIELD(this, f64 *, 0xE0) = temp_f0_1692;
    spB0 = temp_f0_1692;
    sp38 = (f32) sp18 - (f32) sp28;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp38;
    spB8 = (f64) sp38;
    this->unk90.unk1C = M2C_BITWISE(f32, Tools_GetMatchingNodeIndex(this->unk4, "orbit"));
    ((Animation *) &spA0)->GetNodeOrigin(MKModel_GetAnimation(this->unk4));
    this->unk1B8 = spA0;
    this->unk1C0 = spA8;
    MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, M2C_BITWISE(s32, this->unk90.unk1C)), (void (*)(MKDynamicBone *, void *)) &TeslaTower::UpdateTurretBone, &this->unk1B8);
    this->unk1C8 = 0.0f;
}
#endif

s32 TeslaTower::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r31_1786;

    if (KDProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("Waypoints") != 0) {
        ((KDSpline *) &this->unk90)->Init(arg0->GetNmbrOfSubLines(), 0U);
        var_r31_1786 = arg0->unkC->GetSubLine(arg0);
loop_5:
        if (var_r31_1786 != NULL) {
            var_r31_1786->AsVector3(0, &sp8);
            ((KDSpline *) &this->unk90)->AddNode(sp8);
            var_r31_1786 = var_r31_1786->unkC->GetNextLine(var_r31_1786);
            goto loop_5;
        }
    }
    return arg0->LoadFloat("patrolSpeed", &this->unk90.unk18, 0);
}

#if 0 // DRAFT: undefined identifier 'nanf'
void TeslaTower::Init() {
    KDProp::Init();
    this->unk90.unk14 = 0.0f;
    this->unk90.unk18 = 0.125f;
    this->unk90.unk24 = 0.0f;
    this->unk90.unk30 = 1.0f;
    this->unkC = (BoundingVolume *) &this->unkD0;
    this->unk90.unk1C = nanf;
    this->unk90.unk2C = 0.0f;
    ((KDSoundFader *) &this->unk114)->Init(0.25f, 0.25f);
    ((KDSoundFader *) &this->unk13C)->Init(0.25f, 0.25f);
    ((KDSoundFader *) &this->unk164)->Init(0.01f, 0.25f);
    ((KDSoundFader *) &this->unk18C)->Init(0.25f, 0.25f);
}
#endif

void TeslaTowerDescriptor::Deinit() {
    MKMaterial *temp_r3_1872;

    temp_r3_1872 = this->unk74;
    if (temp_r3_1872 != NULL) {
        MKMaterial_Destroy(temp_r3_1872);
        this->unk74 = NULL;
    }
    KDPropDescriptor::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'ZapPS *' to
void TeslaTowerDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unk78 = checked_cast<ZapPS *, MKProp>(gMK->CreateProp("ZapPS"));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'EnergyBeam *' to
void TeslaTowerDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk70 = checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp("EnergyBeam"));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void TeslaTowerDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk74 = MKMaterial_Create("teslaLight");
}
#endif
