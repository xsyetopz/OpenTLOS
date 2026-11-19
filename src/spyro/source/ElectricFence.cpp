#include "spyro/source/ElectricFence.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern s32 GS_SpyroZapBurn;
extern void **gMK;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void ElectricFence::AllocBeams() {
    f64 sp10;
    f64 sp8;
    MKSceneManager *temp_r3_57;
    f64 temp_f0_65;
    f64 temp_f1_64;
    s32 var_r28_116;
    s32 var_r28_86;
    s32 var_r31_117;
    s32 var_r31_87;
    void *temp_r29_119;
    void *temp_r30_115;
    void *temp_r30_95;
    void *temp_r3_60;
    void *temp_r3_63;
    void *temp_r3_72;
    void *temp_r3_79;
    void *temp_r4_100;

    temp_r3_57 = this->unk110;
    if (temp_r3_57 != NULL) {
        temp_r3_60 = temp_r3_57->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_60 != NULL) {
            temp_r3_63 = M2C_FIELD(temp_r3_60, void **, 8);
            temp_f1_64 = M2C_FIELD(temp_r3_63, f64 *, 0x30);
            temp_f0_65 = M2C_FIELD(temp_r3_63, f64 *, 0x38);
            sp8 = temp_f1_64;
            this->unk100 = temp_f1_64;
            sp10 = temp_f0_65;
            this->unk108 = temp_f0_65;
        } else {
            temp_r3_72 = this->unk8;
            this->unk100 = M2C_FIELD(temp_r3_72, f64 *, 0x30);
            this->unk108 = M2C_FIELD(temp_r3_72, f64 *, 0x38);
        }
    } else {
        temp_r3_79 = this->unk8;
        this->unk100 = M2C_FIELD(temp_r3_79, f64 *, 0x30);
        this->unk108 = M2C_FIELD(temp_r3_79, f64 *, 0x38);
    }
    var_r28_86 = 0;
    var_r31_87 = 0;
    do {
        temp_r30_95 = this + var_r31_87;
        temp_r4_100 = ((u8 *) this->unk4C) + ((MKRand_Int((int *) &gViewSeed, 0, this->unk50) * 0x70) + 0x30);
        M2C_FIELD(temp_r30_95, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r4_100, f64 *, 0);
        M2C_FIELD(temp_r30_95, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_100, f64 *, 8);
        var_r28_86 += 1;
        var_r31_87 += 0x18;
        M2C_FIELD(temp_r30_95, f32 *, 0xDC) = (f32) ((1000.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f)) + M2C_FIELD(temp_r30_95, f32 *, 0xDC));
    } while (var_r28_86 < 2);
    temp_r30_115 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r28_116 = 0;
    var_r31_117 = 0;
    do {
        temp_r29_119 = this + var_r31_117;
        if ((u32) M2C_FIELD(temp_r29_119, u32 *, 0xD0) == 0U) {
            ((EnergyBeam *) (M2C_FIELD(temp_r30_115, EnergyBeam **, 0x80)))->SpawnEnergyBeam((MKVector3 *) &this->unk100, ((u8 *) temp_r29_119) + 0xD8, 2.0f);
            M2C_FIELD(temp_r29_119, u32 *, 0xD0) = (u32) M2C_ERROR(/* Read from unset register $r3 */);
        }
        var_r28_116 += 1;
        var_r31_117 += 0x18;
    } while (var_r28_116 < 2);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'ElectricFence' to
void ElectricFence::FreeBeams() {
    s32 temp_r28_158;
    s32 var_r27_156;
    s32 var_r31_153;
    void *temp_r29_154;

    var_r31_153 = 0;
    temp_r29_154 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_156 = 0;
    do {
        temp_r28_158 = var_r31_153 + 0xD0;
        ((EnergyBeam *) (M2C_FIELD(temp_r29_154, EnergyBeam **, 0x80)))->FreeEnergyBeam(*(this + temp_r28_158));
        var_r27_156 += 1;
        *(this + temp_r28_158) = 0;
        var_r31_153 += 0x18;
    } while (var_r27_156 < 2);
}
#endif

#if 0 // DRAFT: illegal type
void ElectricFence::EnableFenceCollision(bool arg0) {
    s32 temp_r0_186;
    s32 temp_r0_199;
    s32 var_r4_179;
    s32 var_r5_180;
    s32 var_r8_178;

    var_r8_178 = 0;
    var_r4_179 = 0;
    var_r5_180 = 0;
    if (arg0 != 0) {
loop_3:
        if (var_r8_178 < (s32) (this->unk50 - 1)) {
            temp_r0_186 = var_r5_180 + 0x5C;
            var_r8_178 += 1;
            var_r5_180 += 0x70;
            *(this->unk4C + temp_r0_186) = 1;
            goto loop_3;
        }
        return;
    }
loop_7:
    if (var_r8_178 < (s32) (this->unk50 - 1)) {
        temp_r0_199 = var_r4_179 + 0x5C;
        var_r8_178 += 1;
        var_r4_179 += 0x70;
        *(this->unk4C + temp_r0_199) = 0;
        goto loop_7;
    }
}
#endif

#if 0 // DRAFT: illegal type
void ElectricFence::Deinit() {
    MKHeap *temp_r3_248;
    MKModel *temp_r3_227;
    MKModel *temp_r3_234;
    s32 var_r30_221;
    s32 var_r31_222;
    void *temp_r31_247;

    KDSound_Stop((int *) &this->unk114);
    var_r30_221 = 0;
    var_r31_222 = 0;
loop_6:
    if (var_r30_221 < (s32) this->unk50) {
        temp_r3_227 = *(this->unk4C + (var_r31_222 + 0x40));
        if (temp_r3_227 != NULL) {
            MKModel_Destroy(temp_r3_227);
        }
        temp_r3_234 = *(this->unk4C + (var_r31_222 + 0x54));
        if (temp_r3_234 != NULL) {
            MKModel_Destroy(temp_r3_234);
        }
        var_r30_221 += 1;
        var_r31_222 += 0x70;
        goto loop_6;
    }
    FreeBeams();
    temp_r31_247 = this->unk4C;
    temp_r3_248 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_248 != NULL) {
        ((MKHeap *) (temp_r3_248->Current()))->Free(temp_r31_247, NULL, 0);
    } else {
        free(temp_r31_247);
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void ElectricFence::Draw() {
    s32 var_r30_278;
    s32 var_r31_279;

    var_r30_278 = 0;
    var_r31_279 = 0;
loop_2:
    if (var_r30_278 < (s32) this->unk50) {
        MKModel_Draw(*(this->unk4C + (var_r31_279 + 0x40)), NULL);
        var_r30_278 += 1;
        var_r31_279 += 0x70;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ElectricFence::Message(MKMessage *arg0) {
    MKVector3 *temp_r30_356;
    s32 temp_r0_313;
    s32 var_ctr_378;
    s32 var_ctr_393;
    s32 var_r3_376;
    s32 var_r3_391;
    void *temp_r5_381;
    void *temp_r5_396;

    ((KDSoundPlayer *) &this->unk114)->Message(arg0);
    temp_r0_313 = arg0->unk0;
    switch (temp_r0_313) {                          /* irregular */
    case 181:
        this->unk54 = 1;
        EnableFenceCollision(this->unk54);
        AllocBeams();
        return;
    case 22:
        M2C_FIELD(checked_cast<HitHeroSndMsg *, MKMessage>(arg0), s32 *, 8) = (s32) GS_SpyroZapBurn;
    default:
block_25:
        MKProp::Message(arg0);
        return;
    case 180:
        if (((s32) M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x88) != 0) && ((u8) this->unk54 != 0)) {
            temp_r30_356 = ((u8 *) this->unk8) + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x88), temp_r30_356, 0U, -1, 0.0f, 0U);
        }
        this->unk54 = 0;
        EnableFenceCollision(this->unk54);
        FreeBeams();
        return;
    case -3:
        var_r3_376 = 0;
        var_ctr_378 = 2;
        do {
            temp_r5_381 = *(this + (var_r3_376 + 0xD0));
            if (temp_r5_381 != NULL) {
                M2C_FIELD(temp_r5_381, s8 *, 0x10) = 1;
            }
            var_r3_376 += 0x18;
            var_ctr_378 -= 1;
        } while (var_ctr_378 != 0);
        goto block_25;
    case -4:
        var_r3_391 = 0;
        var_ctr_393 = 2;
        do {
            temp_r5_396 = *(this + (var_r3_391 + 0xD0));
            if (temp_r5_396 != NULL) {
                M2C_FIELD(temp_r5_396, s8 *, 0x10) = 0;
            }
            var_r3_391 += 0x18;
            var_ctr_393 -= 1;
        } while (var_ctr_393 != 0);
        goto block_25;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void *ElectricFence::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    MKSceneManager *temp_r3_445;
    f64 temp_f0_453;
    f64 temp_f1_452;
    s32 var_r29_463;
    s32 var_r31_464;
    void *temp_r30_472;
    void *temp_r3_448;
    void *temp_r3_451;
    void *temp_r4_433;
    void *temp_r4_477;

    if ((s32) M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x84) != 0) {
        temp_r4_433 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk114)->Update(M2C_FIELD(temp_r4_433, s32 *, 0x84), 1U, this->unk54, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    temp_r3_445 = this->unk110;
    if (temp_r3_445 != NULL) {
        temp_r3_448 = temp_r3_445->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_448 != NULL) {
            temp_r3_451 = M2C_FIELD(temp_r3_448, void **, 8);
            temp_f1_452 = M2C_FIELD(temp_r3_451, f64 *, 0x30);
            temp_f0_453 = M2C_FIELD(temp_r3_451, f64 *, 0x38);
            sp10 = temp_f1_452;
            this->unk100 = temp_f1_452;
            sp18 = temp_f0_453;
            this->unk108 = temp_f0_453;
        }
    }
    if ((u8) this->unk54 != 0) {
        var_r29_463 = 0;
        var_r31_464 = 0;
        do {
            temp_r30_472 = this + var_r31_464;
            temp_r4_477 = ((u8 *) this->unk4C) + ((MKRand_Int((int *) &gViewSeed, 0, this->unk50) * 0x70) + 0x30);
            M2C_FIELD(temp_r30_472, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r4_477, f64 *, 0);
            M2C_FIELD(temp_r30_472, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_477, f64 *, 8);
            var_r29_463 += 1;
            var_r31_464 += 0x18;
            M2C_FIELD(temp_r30_472, f32 *, 0xDC) = (f32) ((1000.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f)) + M2C_FIELD(temp_r30_472, f32 *, 0xDC));
        } while (var_r29_463 < 2);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'ElectricFence' to
f32 ElectricFence::Resolve() {
    s32 var_ctr_514;
    s32 var_r3_511;
    void *temp_r5_517;

    MKProp::Resolve();
    AllocBeams();
    var_r3_511 = 0;
    var_ctr_514 = 2;
    do {
        temp_r5_517 = *(this + (var_r3_511 + 0xD0));
        if (temp_r5_517 != NULL) {
            M2C_FIELD(temp_r5_517, s8 *, 0x10) = 0;
        }
        var_r3_511 += 0x18;
        var_ctr_514 -= 1;
    } while (var_ctr_514 != 0);
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
s32 ElectricFence::LoadDone() {
    Matrix sp2E0;
    Matrix sp2A0;
    M2C_UNK sp29C;
    f64 sp290;                                      /* compiler-managed */
    f64 sp288;                                      /* compiler-managed */
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    MKVector3 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    MKVector3 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
    MKVector3 sp178;
    f64 sp170;
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
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
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
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    Matrix *temp_r4_764;
    f32 temp_f3_1088;
    f32 temp_f3_1123;
    f32 temp_f6_1095;
    f32 temp_f7_1101;
    f32 temp_f8_1129;
    f32 temp_f9_1135;
    f32 var_f3_669;
    f32 var_f4_601;
    f64 temp_f0_1040;
    f64 temp_f0_579;
    f64 temp_f0_858;
    f64 temp_f1_608;
    f64 temp_f1_614;
    f64 temp_f1_618;
    s32 temp_r0_696;
    s32 temp_r0_796;
    s32 temp_r3_637;
    s32 temp_r3_695;
    s32 temp_r5_699;
    s32 temp_r7_746;
    s32 var_r0_647;
    s32 var_r26_972;
    s32 var_r27_566;
    s32 var_r27_732;
    s32 var_r29_974;
    s32 var_r30_564;
    s32 var_r30_730;
    u16 temp_r26_763;
    u16 temp_r3_804;
    void *temp_r26_896;
    void *temp_r29_770;
    void *temp_r3_576;
    void *temp_r3_733;
    void *temp_r4_574;
    void *temp_r4_704;
    void *temp_r5_571;
    void *temp_r5_917;
    void *temp_r6_1000;
    void *temp_r6_700;
    void *temp_r6_914;
    void *temp_r7_809;
    void *temp_r7_916;
    void *temp_r8_754;

    MKProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk6C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk8 = &this->unk70;
    var_r30_564 = 0;
    var_r27_566 = 0;
loop_22:
    temp_r3_695 = this->unk50;
    temp_r0_696 = temp_r3_695 - 1;
    if (var_r30_564 < temp_r0_696) {
        temp_r5_571 = this->unk4C;
        temp_r4_574 = ((u8 *) temp_r5_571) + (var_r27_566 + 0x30);
        temp_r3_576 = ((u8 *) temp_r5_571) + (((var_r30_564 + 1) * 0x70) + 0x30);
        temp_f0_579 = M2C_FIELD(temp_r3_576, f64 *, 0) - M2C_FIELD(temp_r4_574, f64 *, 0);
        sp108 = temp_f0_579;
        sp100 = 0.0f;
        sp288 = temp_f0_579;
        sp110 = M2C_FIELD(temp_r3_576, f32 *, 8) - M2C_FIELD(temp_r4_574, f32 *, 8);
        sp290 = (f64) sp110;
        spF8 = 0.0f;
        spFC = 1.0f;
        var_f4_601 = ((f32) sp290 * (f32) sp290) + (((f32) sp288 * (f32) sp288) + ((*(f32 *) ((u8 *) &sp280 + 0xc)) * (*(f32 *) ((u8 *) &sp280 + 0xc))));
        sp280 = (f64) sp100;
        sp278 = (f64) spF8;
        if (var_f4_601 > 0.000001f) {
            if (var_f4_601 > 0.0f) {
                temp_f1_608 = __frsqrte(var_f4_601);
                temp_f1_614 = 0.5 * temp_f1_608 * -(((f64) var_f4_601 * (temp_f1_608 * temp_f1_608)) - 3.0);
                temp_f1_618 = 0.5 * temp_f1_614 * -(((f64) var_f4_601 * (temp_f1_614 * temp_f1_614)) - 3.0);
                var_f4_601 = (f32) ((f64) var_f4_601 * (0.5 * temp_f1_618 * -(((f64) var_f4_601 * (temp_f1_618 * temp_f1_618)) - 3.0)));
            } else if (var_f4_601 < M2C_BITWISE(f32, 0.0)) {
                var_f4_601 = __float_nan;
            } else {
                sp10 = var_f4_601;
                temp_r3_637 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_637) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_647 = 1;
                    } else {
                        var_r0_647 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_647 = 5;
                    } else {
                        var_r0_647 = 3;
                    }
                    break;
                default:
                    var_r0_647 = 4;
                    break;
                }
                if (var_r0_647 == 1) {
                    var_f4_601 = __float_nan;
                }
            }
            var_f3_669 = 1.0f / var_f4_601;
        } else {
            var_f3_669 = 0.0f;
            var_f4_601 = 0.0f;
        }
        sp288 = (f32) sp288 * var_f3_669;
        (*(f32 *) ((u8 *) &sp280 + 0xc)) *= var_f3_669;
        sp290 = (f32) sp290 * var_f3_669;
        *(this->unk4C + (var_r27_566 + 0x68)) = var_f4_601;
        KDMath_BuildMatrixFromFwd(((u8 *) this->unk4C) + var_r27_566, *((MKVector3 *) &sp288), (MKVector3 *) &sp278);
        var_r30_564 += 1;
        var_r27_566 += 0x70;
        goto loop_22;
    }
    temp_r5_699 = temp_r0_696 * 0x70;
    temp_r6_700 = this->unk4C;
    temp_r4_704 = ((u8 *) temp_r6_700) + (temp_r5_699 + 0x30);
    sp268 = M2C_FIELD(temp_r4_704, f64 *, 0);
    sp270 = M2C_FIELD(temp_r4_704, f64 *, 8);
    M2C_STRUCT_COPY(((u8 *) temp_r6_700) + temp_r5_699, ((u8 *) temp_r6_700) + ((temp_r3_695 - 2) * 0x70), 0x40);
    var_r30_730 = 0;
    var_r27_732 = 0;
    temp_r3_733 = ((u8 *) this->unk4C) + ((this->unk50 - 1) * 0x70);
    M2C_FIELD(temp_r3_733, f32 *, 0x30) = (f32) sp268;
    M2C_FIELD(temp_r3_733, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp268 + 0x4));
    M2C_FIELD(temp_r3_733, f32 *, 0x38) = (f32) sp270;
    M2C_FIELD(temp_r3_733, f32 *, 0x3C) = 1.0f;
loop_27:
    if (var_r30_730 < (s32) this->unk50) {
        temp_r7_746 = var_r27_732 + 0x40;
        *(this->unk4C + temp_r7_746) = MKModel_Create("FX0034_ElectricFencePost", NULL, 2, NULL);
        temp_r8_754 = ((u8 *) this->unk4C) + (var_r27_732 + 0x44);
        M2C_FIELD(temp_r8_754, s32 *, 0) = 0;
        M2C_FIELD(temp_r8_754, s8 *, 4) = 1;
        M2C_FIELD(temp_r8_754, ElectricFence **, 8) = this;
        M2C_FIELD(temp_r8_754, s32 *, 0xC) = 0;
        temp_r26_763 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, *(this->unk4C + temp_r7_746), "c_collide");
        temp_r4_764 = ((u8 *) this->unk4C) + var_r27_732;
        MKModel_SetWorldMatrix(M2C_FIELD(temp_r4_764, MKModel **, 0x40), *temp_r4_764);
        temp_r29_770 = ((u8 *) this->unk4C) + var_r27_732;
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(M2C_FIELD(temp_r29_770, MKModel **, 0x40), (s32) temp_r26_763, (MKCollisionMode) 1, ((u8 *) temp_r29_770) + 0x44, 0U);
        *(this->unk4C + (var_r27_732 + 0x48)) = 1;
        if (var_r30_730 < (s32) (this->unk50 - 1)) {
            temp_r0_796 = var_r27_732 + 0x54;
            *(this->unk4C + temp_r0_796) = MKModel_Create("FX0033_CollideBox", NULL, 2, NULL);
            temp_r3_804 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, *(this->unk4C + temp_r0_796), "c_collide");
            temp_r7_809 = ((u8 *) this->unk4C) + (var_r27_732 + 0x58);
            M2C_FIELD(temp_r7_809, s32 *, 0) = 0;
            M2C_FIELD(temp_r7_809, s8 *, 4) = 1;
            M2C_FIELD(temp_r7_809, ElectricFence **, 8) = this;
            M2C_FIELD(temp_r7_809, s32 *, 0xC) = 0;
            M2C_STRUCT_COPY((s32) &sp2A0.unk3C + 4, (s32) ((((u8 *) this->unk4C) + var_r27_732) - 4) + 4, 0x40);
            MKVector(0.0f, 400.0f, 0.0f);
            sp38 = -sp2E0.unk20;
            sp3C = -sp2E0.unk24;
            sp40 = -sp2E0.unk28;
            sp208 = (f64) sp38;
            sp210 = (f64) sp40;
            sp218.operator*(*(this->unk4C + (var_r27_732 + 0x68)));
            sp228.operator*(0.5f);
            temp_f0_858 = sp228 + sp1F8;
            spE8 = temp_f0_858;
            sp238 = temp_f0_858;
            spF0 = sp228.unk8 + sp200;
            sp240 = (f64) spF0;
            sp2E0.Translate(&sp2E0, *((MKVector3 *) &sp238));
            spD8 = 100.0f;
            spDC = 800.0f;
            spE0 = *(this->unk4C + (var_r27_732 + 0x68));
            sp1E8 = (f64) spD8;
            sp1F0 = (f64) spE0;
            sp2E0.Scale3x3(&sp2E0, *((MKVector3 *) &sp1E8));
            MKModel_SetWorldMatrix(*(this->unk4C + (var_r27_732 + 0x54)), sp2E0);
            temp_r26_896 = ((u8 *) this->unk4C) + var_r27_732;
            ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(M2C_FIELD(temp_r26_896, MKModel **, 0x54), (s32) temp_r3_804, (MKCollisionMode) 1, ((u8 *) temp_r26_896) + 0x58, 0x100U);
            *(this->unk4C + (var_r27_732 + 0x5C)) = 1;
            temp_r6_914 = this->unk4C;
            temp_r7_916 = ((u8 *) temp_r6_914) + (var_r27_732 + 0x20);
            temp_r5_917 = ((u8 *) temp_r6_914) + (var_r27_732 + 0x30);
            sp28 = -M2C_FIELD(temp_r7_916, f32 *, 0);
            sp2C = -M2C_FIELD(temp_r7_916, f32 *, 4);
            sp30 = -M2C_FIELD(temp_r7_916, f32 *, 8);
            sp1C8 = (f64) sp28;
            sp1D0 = (f64) sp30;
            sp258 = M2C_FIELD(temp_r5_917, f64 *, 0);
            sp260 = M2C_FIELD(temp_r5_917, f64 *, 8);
            sp1D8.operator*(*(temp_r6_914 + (var_r27_732 + 0x68)));
            spC8 = sp258 + M2C_BITWISE(f64, sp1D8);
            spC0 = 0.0f;
            spB8 = 0.0f;
            spBC = 150.0f;
            spD0 = (f32) sp260 + sp1D8.unk8;
            sp1B8 = (f64) spB8;
            sp1C0 = (f64) spC0;
            sp258 += sp1B8;
            spA8 = 0.0f;
            spAC = 150.0f;
            spB0 = 0.0f;
        }
        var_r30_730 += 1;
        var_r27_732 += 0x70;
        goto loop_27;
    }
    EnableFenceCollision(this->unk54);
    var_r26_972 = 0;
    var_r29_974 = 0;
    sp98 = 1e11f;
    sp9C = 1e11f;
    spA0 = 1e11f;
    this->unkB0 = (f64) sp98;
    sp90 = -1e11f;
    sp88 = -1e11f;
    sp8C = -1e11f;
    this->unkB8 = (f64) spA0;
    this->unkC0 = (f64) sp88;
    sp1A8 = (f64) sp98;
    sp1B0 = (f64) spA0;
    sp198 = (f64) sp88;
    sp1A0 = (f64) sp90;
    this->unkC8 = (f64) sp90;
loop_30:
    if (var_r26_972 < (s32) this->unk50) {
        temp_r6_1000 = ((u8 *) this->unk4C) + (var_r29_974 + 0x30);
        sp248 = M2C_FIELD(temp_r6_1000, f64 *, 0);
        sp250 = M2C_FIELD(temp_r6_1000, f64 *, 8);
        Min(sp188, *((MKVector3 *) &this->unkB0));
        this->unkB0 = M2C_BITWISE(f64, sp188);
        this->unkB8 = (f64) sp188.unk8;
        sp78 = (f32) sp248;
        sp7C = (*(f32 *) ((u8 *) &sp248 + 0x4)) + 800.0f;
        sp80 = (f32) sp250;
        sp168 = (f64) sp78;
        sp170 = (f64) sp80;
        Max(sp178, *((MKVector3 *) &this->unkC0));
        var_r26_972 += 1;
        var_r29_974 += 0x70;
        this->unkC0 = M2C_BITWISE(f64, sp178);
        this->unkC8 = (f64) sp178.unk8;
        goto loop_30;
    }
    temp_f0_1040 = this->unkC0 - this->unkB0;
    sp18 = temp_f0_1040;
    sp138 = temp_f0_1040;
    sp20 = (f32) M2C_FIELD(this, f64 *, 0xC8) - (f32) M2C_FIELD(this, f64 *, 0xB8);
    sp140 = (f64) sp20;
    sp148.operator*(0.5f);
    sp68 = this->unkB0 + M2C_BITWISE(f64, sp148);
    sp158 = sp68;
    sp70 = (f32) M2C_FIELD(this, f64 *, 0xB8) + sp148.unk8;
    this->unkA0 = (f32) sp158;
    sp160 = (f64) sp70;
    this->unkA4 = (*(f32 *) ((u8 *) &sp158 + 0x4));
    this->unkA8 = (f32) sp160;
    this->unkAC = 1.0f;
    M2C_STRUCT_COPY((s32) &sp29C + 4, (s32) &this->unk6C + 4, 0x40);
    sp2A0.Inverse(&sp2A0);
    temp_f3_1088 = M2C_FIELD(this, f32 *, 0xB4);
    temp_f6_1095 = (f32) M2C_FIELD(this, f64 *, 0xB0);
    temp_f7_1101 = (f32) M2C_FIELD(this, f64 *, 0xB8);
    sp58 = sp2A0.unk30 + ((temp_f7_1101 * sp2A0.unk20) + ((temp_f6_1095 * M2C_BITWISE(f32, sp2A0)) + (temp_f3_1088 * sp2A0.unk10)));
    sp5C = sp2A0.unk34 + ((temp_f7_1101 * sp2A0.unk24) + ((temp_f6_1095 * sp2A0.unk4) + (temp_f3_1088 * sp2A0.unk14)));
    sp60 = sp2A0.unk38 + ((temp_f7_1101 * sp2A0.unk28) + ((temp_f6_1095 * sp2A0.unk8) + (temp_f3_1088 * sp2A0.unk18)));
    this->unkB0 = (f64) sp58;
    this->unkB8 = (f64) sp60;
    temp_f3_1123 = M2C_FIELD(this, f32 *, 0xC4);
    temp_f8_1129 = (f32) M2C_FIELD(this, f64 *, 0xC0);
    temp_f9_1135 = (f32) M2C_FIELD(this, f64 *, 0xC8);
    sp128 = (f64) sp58;
    sp48 = sp2A0.unk30 + ((temp_f9_1135 * sp2A0.unk20) + ((temp_f8_1129 * M2C_BITWISE(f32, sp2A0)) + (temp_f3_1123 * sp2A0.unk10)));
    sp4C = sp2A0.unk34 + ((temp_f9_1135 * sp2A0.unk24) + ((temp_f8_1129 * sp2A0.unk4) + (temp_f3_1123 * sp2A0.unk14)));
    sp50 = sp2A0.unk38 + ((temp_f9_1135 * sp2A0.unk28) + ((temp_f8_1129 * sp2A0.unk8) + (temp_f3_1123 * sp2A0.unk18)));
    this->unkC0 = (f64) sp48;
    this->unkC8 = (f64) sp50;
    sp130 = (f64) sp60;
    sp118 = (f64) sp48;
    sp120 = (f64) sp50;
    this->unkC0 -= this->unkB0;
    M2C_FIELD(this, f64 *, 0xC8) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xC8) - (f32) M2C_FIELD(this, f64 *, 0xB8));
    this->unkC = (BoundingVolume *) &this->unkB0;
    return 0xC0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
s32 ElectricFence::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKHeap *temp_r3_1215;
    MKIniLine *var_r27_1234;
    s32 temp_r0_1249;
    s32 temp_r28_1214;
    s32 temp_r3_1211;
    s32 temp_r3_1245;
    s32 var_r29_1235;
    s32 var_r29_1274;
    void *temp_r5_1248;
    void *var_r3_1222;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("waypoints") != 0) {
        temp_r3_1211 = arg0->GetNmbrOfSubLines();
        this->unk50 = temp_r3_1211;
        temp_r28_1214 = this->unk50 * 0x70;
        temp_r3_1215 = ((MKHeap *) temp_r3_1211)->Current();
        if (temp_r3_1215 != NULL) {
            var_r3_1222 = ((MKHeap *) (temp_r3_1215->Current()))->Alloc(temp_r28_1214, NULL, 0);
        } else {
            var_r3_1222 = malloc(temp_r28_1214);
        }
        this->unk4C = var_r3_1222;
        var_r27_1234 = arg0->unkC->GetSubLine(arg0);
        var_r29_1235 = 0;
loop_8:
        if (var_r27_1234 != NULL) {
            var_r27_1234->LoadVector3("waypoint", &sp8, 0);
            temp_r3_1245 = var_r29_1235 + 0x40;
            temp_r5_1248 = ((u8 *) this->unk4C) + var_r29_1235;
            temp_r0_1249 = var_r29_1235 + 0x54;
            M2C_FIELD(temp_r5_1248, f32 *, 0x30) = M2C_BITWISE(f32, sp8);
            var_r29_1235 += 0x70;
            M2C_FIELD(temp_r5_1248, f32 *, 0x34) = sp8.unk4;
            M2C_FIELD(temp_r5_1248, f32 *, 0x38) = sp8.unk8;
            M2C_FIELD(temp_r5_1248, f32 *, 0x3C) = 1.0f;
            *(this->unk4C + temp_r3_1245) = 0;
            *(this->unk4C + temp_r0_1249) = 0;
            var_r27_1234 = var_r27_1234->unkC->GetNextLine(var_r27_1234);
            goto loop_8;
        }
    }
    var_r29_1274 = 0;
    if ((arg0->LoadBool("StartOn", &this->unk54, 0) != 0) || (arg0->LoadInt("JellyFishID", (int *) &this->unk110, 0) != 0)) {
        var_r29_1274 = 1;
    }
    return var_r29_1274;
}
#endif

#if 0 // DRAFT: illegal operand
void ElectricFence::Init() {
    s32 temp_r0_1319;
    s32 var_ctr_1317;
    s32 var_r3_1315;
    void *temp_r31_1327;

    MKProp::Init();
    this->unk54 = 1;
    var_r3_1315 = 0;
    this->unk50 = 0;
    var_ctr_1317 = 2;
    do {
        temp_r0_1319 = var_r3_1315 + 0xD0;
        var_r3_1315 += 0x18;
        *(this + temp_r0_1319) = 0;
        var_ctr_1317 -= 1;
    } while (var_ctr_1317 != 0);
    this->unk110 = NULL;
    temp_r31_1327 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk114)->Init(M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x8C), M2C_FIELD(temp_r31_1327, f32 *, 0x90));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'EnergyBeam *' to
void ElectricFenceDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk80 = checked_cast<EnergyBeam *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EnergyBeam"));
}
#endif

s32 ElectricFenceDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1373;

    var_r31_1373 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("fenceSoundFadeIn", &this->unk8C, 0) != 0) || (arg0->LoadFloat("fenceSoundFadeOut", &this->unk90, 0) != 0) || (KDSound_LoadLine(arg0, "fenceShutDownSound", (int *) &this->unk88) != 0) || (KDSound_LoadLine(arg0, "fenceSound", (int *) &this->unk84) != 0)) {
        var_r31_1373 = 1;
    }
    return var_r31_1373;
}
