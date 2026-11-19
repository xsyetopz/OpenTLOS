#include "spyro/source/FallingLeaves.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/WindFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gFallingLeavesEnvelope; /* unable to generate initializer: confusing struct layout */

void FallingLeaves::Message(MKMessage *arg0) {
    s32 temp_r0_52;

    temp_r0_52 = arg0->unk0;
    switch (temp_r0_52) {                           /* irregular */
    case 0xB5:
        this->unk1E1 = 1;
        break;
    case 0xB4:
        this->unk1E1 = 0;
        break;
    }
    MKBaseParticleSystem::Message(arg0);
}
#endif

#if 0 // DRAFT: ')' expected
void FallingLeaves::Draw() {
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    Matrix sp180;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
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
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
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
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    MKParticleChunk *var_r27_169;
    f32 temp_f18_339;
    f32 temp_f19_333;
    f32 temp_f1_118;
    f32 temp_f31_272;
    f32 temp_f3_116;
    f32 temp_f8_114;
    f32 temp_f9_120;
    f32 var_f22_117;
    f32 var_f23_113;
    f64 temp_f25_176;
    f64 temp_f27_173;
    f64 temp_f29_170;
    s32 temp_r0_187;
    void *temp_r28_184;

    var_f23_113 = 0.0f;
    temp_f8_114 = this->unkA8;
    temp_f3_116 = this->unkAC;
    var_f22_117 = 0.0f;
    temp_f1_118 = -temp_f8_114;
    spA0 = 0.0f;
    temp_f9_120 = -temp_f3_116;
    sp90 = 0.0f;
    sp80 = 0.0f;
    sp70 = 0.0f;
    sp98 = temp_f1_118;
    sp9C = temp_f3_116;
    sp88 = temp_f1_118;
    sp8C = temp_f9_120;
    sp78 = temp_f8_114;
    sp7C = temp_f3_116;
    sp68 = temp_f8_114;
    sp6C = temp_f9_120;
    sp158 = (f64) sp98;
    sp160 = (f64) spA0;
    sp200 = (f64) sp98;
    sp208 = (f64) spA0;
    sp148 = (f64) sp88;
    sp150 = (f64) sp90;
    sp210 = (f64) sp88;
    sp218 = (f64) sp90;
    sp138 = (f64) sp78;
    sp140 = (f64) sp80;
    sp220 = (f64) sp78;
    sp228 = (f64) sp80;
    sp128 = (f64) sp68;
    sp130 = (f64) sp70;
    sp230 = (f64) sp68;
    sp238 = (f64) sp70;
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<FallingLeavesDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x38));
    MKPrimitive(0xC, 0x10);
    var_r27_169 = GetFirstParticle(&unksp10);
    temp_f29_170 = sp210;
    temp_f27_173 = sp220;
    temp_f25_176 = sp230;
loop_16:
    if (var_r27_169 != NULL) {
        temp_r28_184 = var_r27_169->unk2C;
        temp_r0_187 = (s32) var_r27_169->unk20;
        switch (temp_r0_187) {                      /* irregular */
        case 0:
            var_f23_113 = 0.0f;
            var_f22_117 = 0.0f;
            break;
        case 1:
            var_f23_113 = 0.5f;
            var_f22_117 = 0.0f;
            break;
        case 2:
            var_f23_113 = 0.0f;
            var_f22_117 = 0.5f;
            break;
        case 3:
            var_f23_113 = 0.5f;
            var_f22_117 = 0.5f;
            break;
        }
        sp180.SetIdentity();
        if ((u8) M2C_FIELD(temp_r28_184, u8 *, 0x28) == 0) {
            sp180.SetRotationPitch(0.017453292f * M2C_FIELD(temp_r28_184, f32 *, 0x24));
            sp180.RotateYaw(&sp180, 0.017453292f * var_r27_169->unk24);
            sp180.unk30 = M2C_BITWISE(f32, var_r27_169->unk0);
            sp180.unk34 = var_r27_169->unk4;
            sp180.unk38 = var_r27_169->unk8;
            sp180.unk3C = 1.0f;
        } else {
            spB8 = 0.0f;
            spBC = 0.0f;
            spC0 = 1.0f;
            sp60 = 0.0f;
            sp58 = 0.0f;
            sp5C = 1.0f;
            sp168 = (f64) spB8;
            sp170 = (f64) spC0;
            M2C_FIELD(temp_r28_184, f64 *, 0x30) = (f64) sp58;
            sp118 = (f64) sp58;
            sp120 = (f64) sp60;
            M2C_FIELD(temp_r28_184, f64 *, 0x38) = (f64) sp60;
            KDMath_BuildMatrixFromFwd(&sp180, *(temp_r28_184 + 0x30), (MKVector3 *) &sp168);
            sp180.unk30 = M2C_BITWISE(f32, var_r27_169->unk0);
            sp180.unk34 = var_r27_169->unk4;
            sp180.unk38 = var_r27_169->unk8;
            sp180.unk3C = 1.0f;
        }
        temp_f31_272 = M2C_FIELD(temp_r28_184, f32 *, 0x18);
        sp48 = sp200 * (f64) temp_f31_272;
        sp50 = (f32) sp208 * temp_f31_272;
        sp108 = sp48;
        sp110 = (f64) sp50;
        sp1C0 = sp48;
        sp1C8 = (f64) sp50;
        sp38 = temp_f29_170 * (f64) temp_f31_272;
        sp40 = (f32) sp218 * temp_f31_272;
        spF8 = sp38;
        sp100 = (f64) sp40;
        sp1D0 = sp38;
        sp1D8 = (f64) sp40;
        sp28 = temp_f27_173 * (f64) temp_f31_272;
        sp30 = (f32) sp228 * temp_f31_272;
        spE8 = sp28;
        spF0 = (f64) sp30;
        sp1E0 = sp28;
        sp1E8 = (f64) sp30;
        sp18 = temp_f25_176 * (f64) temp_f31_272;
        sp20 = (f32) sp238 * temp_f31_272;
        spD8 = sp18;
        spE0 = (f64) sp20;
        sp1F0 = sp18;
        sp1F8 = (f64) sp20;
        MKSetMatrix(sp180);
        MKBegin(4);
        spA8 = 0.5f;
        spAC = 0.5f;
        spB0 = 0.5f;
        spB4 = 1.0f;
        spC8 = (f64) spA8;
        spD0 = (f64) spB0;
        MKSetColorV(*((MKVector4 *) &spC8));
        MKSetTexCoord1F(var_f23_113, var_f22_117);
        MKSetPositionV(*((MKVector3 *) &sp1C0));
        temp_f19_333 = 0.5f + var_f22_117;
        MKSetTexCoord1F(var_f23_113, temp_f19_333);
        MKSetPositionV(*((MKVector3 *) &sp1D0));
        temp_f18_339 = 0.5f + var_f23_113;
        MKSetTexCoord1F(temp_f18_339, var_f22_117);
        MKSetPositionV(*((MKVector3 *) &sp1E0));
        MKSetTexCoord1F(temp_f18_339, temp_f19_333);
        MKSetPositionV(*((MKVector3 *) &sp1F0));
        MKEnd();
        var_r27_169 = GetNextParticle(&unksp10);
        goto loop_16;
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'FallingLeaves' to
void FallingLeaves::AddForce(const MKVector3 &arg0, const float &arg1, const float &arg2) {
    s32 var_ctr_400;
    s32 var_r7_399;
    void *temp_r3_406;

    var_r7_399 = 0;
    var_ctr_400 = 4;
loop_1:
    if ((u8) *(this + (var_r7_399 + 0x178)) == 0) {
        temp_r3_406 = this + var_r7_399;
        M2C_FIELD(temp_r3_406, s8 *, 0x178) = 1;
        M2C_FIELD(temp_r3_406, f64 *, 0x160) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_406, f64 *, 0x168) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_406, f32 *, 0x170) = (f32) &arg1;
        M2C_FIELD(temp_r3_406, f32 *, 0x174) = (f32) &arg2;
        return;
    }
    var_r7_399 += 0x20;
    var_ctr_400 -= 1;
    if (var_ctr_400 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp18'
void FallingLeaves::UpdateParticles() {
    s8 sp2C0;
    s32 sp2BC;
    s32 sp2B8;
    s32 sp2B4;
    f32 sp2B0;
    s32 sp2AC;
    s8 sp2AB;
    s8 sp2AA;
    s16 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    Matrix sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;                                      /* compiler-managed */
    f64 sp1F8;                                      /* compiler-managed */
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
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
    f32 sp14;
    f32 sp10;
    MKParticleChunk *var_r31_467;
    f32 temp_f0_689;
    f32 temp_f1_594;
    f32 temp_f1_688;
    f32 temp_f23_659;
    f32 temp_f23_933;
    f32 temp_f23_965;
    f32 temp_f24_931;
    f32 temp_f25_550;
    f32 temp_f25_938;
    f32 temp_f28_668;
    f32 temp_f29_548;
    f32 temp_f2_473;
    f32 temp_f30_517;
    f32 temp_f3_474;
    f32 temp_f4_736;
    f32 var_f0_572;
    f32 var_f3_904;
    f32 var_f4_837;
    f64 temp_f0_497;
    f64 temp_f0_524;
    f64 temp_f0_555;
    f64 temp_f0_670;
    f64 temp_f0_751;
    f64 temp_f0_952;
    f64 temp_f0_977;
    f64 temp_f1_843;
    f64 temp_f1_849;
    f64 temp_f1_853;
    f64 temp_f5_730;
    s32 temp_r3_872;
    s32 var_r0_882;
    s32 var_r27_807;
    s32 var_r29_806;
    void *temp_r30_470;
    void *temp_r4_809;

    sp108 = 0.0f;
    sp100 = 0.0f;
    sp104 = 0.0f;
    sp228 = (f64) sp108;
    sp220 = (f64) sp100;
    this->unk128 += gUpdateTimeDelta;
    var_r31_467 = GetFirstParticle(&unksp18);
loop_51:
    if (var_r31_467 != NULL) {
        temp_r30_470 = var_r31_467->unk2C;
        temp_f2_473 = this->unk12C;
        temp_f3_474 = this->unk128 - M2C_FIELD(temp_r30_470, f32 *, 0x10);
        if (temp_f3_474 > temp_f2_473) {
            var_r31_467 = DestroyParticle(&unksp18);
        } else {
            if (temp_f3_474 > (0.75f * temp_f2_473)) {
                M2C_FIELD(temp_r30_470, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 0x18) * 0.75f);
            }
            if ((u8) M2C_FIELD(temp_r30_470, u8 *, 0x28) == 0) {
                temp_f0_497 = M2C_FIELD(temp_r30_470, f64 *, 0) * (f64) gUpdateTimeDelta;
                sp80 = temp_f0_497;
                sp1E0 = temp_f0_497;
                sp88 = M2C_FIELD(temp_r30_470, f32 *, 8) * gUpdateTimeDelta;
                sp1E8 = (f64) sp88;
                M2C_FIELD(var_r31_467, f64 *, 0) = (f64) (M2C_FIELD(var_r31_467, f64 *, 0) + temp_f0_497);
                var_r31_467->unk8 += (f32) sp1E8;
                temp_f30_517 = gUpdateTimeDelta;
                sp1C0.operator*(MKRand_Float((int *) &gViewSeed, 0.0f, 0.25f));
                temp_f0_524 = sp1C0 * (f64) temp_f30_517;
                sp70 = temp_f0_524;
                sp1D0 = temp_f0_524;
                sp78 = sp1C0.unk8 * temp_f30_517;
                sp1D8 = (f64) sp78;
                M2C_FIELD(temp_r30_470, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_470, f64 *, 0) + temp_f0_524);
                M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) sp1D8);
                temp_f29_548 = gUpdateTimeDelta;
                temp_f25_550 = 1.0f - (M2C_FIELD(temp_r30_470, f32 *, 0x24) / 90.0f);
                MKVector(0.0f, -200.0f * temp_f25_550, 0.0f);
                temp_f0_555 = sp1A0 * (f64) temp_f29_548;
                sp60 = temp_f0_555;
                sp1B0 = temp_f0_555;
                sp68 = sp1A8 * temp_f29_548;
                sp1B8 = (f64) sp68;
                M2C_FIELD(temp_r30_470, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_470, f64 *, 0) + temp_f0_555);
                M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) sp1B8);
                var_f0_572 = M2C_FIELD(temp_r30_470, f32 *, 4);
                if (var_f0_572 < 1000.0f) {

                } else {
                    var_f0_572 = 1000.0f;
                }
                if (var_f0_572 > -200.0f) {

                } else {
                    var_f0_572 = -200.0f;
                }
                M2C_FIELD(temp_r30_470, f32 *, 4) = var_f0_572;
                var_r31_467->unk24 += M2C_FIELD(temp_r30_470, f32 *, 0x14) * gUpdateTimeDelta;
                temp_f1_594 = var_r31_467->unk24;
                if (temp_f1_594 >= 360.0f) {
                    var_r31_467->unk24 = temp_f1_594 - 360.0f;
                }
                sp230.SetIdentity();
                sp230.RotateYaw(&sp230, 0.017453292f * var_r31_467->unk24);
                spF0 = 0.0f;
                spF4 = 0.0f;
                spF8 = 1.0f;
                sp210 = (f64) spF0;
                sp218 = (f64) spF8;
                sp14 = 1.0f - temp_f25_550;
                sp50 = sp230.unk30 + (((f32) sp218 * sp230.unk20) + (((f32) sp210 * M2C_BITWISE(f32, sp230)) + ((*(f32 *) ((u8 *) &sp210 + 0x4)) * sp230.unk10)));
                sp54 = sp230.unk34 + (((f32) sp218 * sp230.unk24) + (((f32) sp210 * sp230.unk4) + ((*(f32 *) ((u8 *) &sp210 + 0x4)) * sp230.unk14)));
                sp58 = sp230.unk38 + (((f32) sp218 * sp230.unk28) + (((f32) sp210 * sp230.unk8) + ((*(f32 *) ((u8 *) &sp210 + 0x4)) * sp230.unk18)));
                sp190 = (f64) sp50;
                sp198 = (f64) sp58;
                sp210 = (f64) sp50;
                sp218 = (f64) sp58;
                temp_f23_659 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
                temp_f28_668 = gUpdateTimeDelta * (2000.0f * temp_f23_659 * Clamp<float>(0.25f, sp14, 0.5f));
                temp_f0_670 = sp210 * (f64) temp_f28_668;
                sp40 = temp_f0_670;
                sp180 = temp_f0_670;
                sp48 = (f32) sp218 * temp_f28_668;
                sp188 = (f64) sp48;
                M2C_FIELD(temp_r30_470, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_470, f64 *, 0) + temp_f0_670);
                M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) sp188);
            }
            temp_f1_688 = var_r31_467->unk4;
            temp_f0_689 = M2C_FIELD(temp_r30_470, f32 *, 0x20);
            if ((temp_f1_688 <= temp_f0_689) && ((u8) M2C_FIELD(temp_r30_470, u8 *, 0x28) == 0)) {
                spC0 = 0.0f;
                spC4 = -1500.0f;
                spC8 = 0.0f;
                sp270 = 0.0f;
                sp274 = 0.0f;
                sp278 = 0.0f;
                sp280 = 0.0f;
                sp284 = 0.0f;
                sp288 = 0.0f;
                sp290 = 0.0f;
                sp294 = 0.0f;
                sp298 = 0.0f;
                sp29C = 1.0f;
                sp2A0 = 0.0f;
                sp2A4 = 0.0f;
                sp2A8 = 0;
                sp2AA = 0;
                sp2AB = 0;
                sp2AC = 0;
                sp2B0 = 3.4028235e38f;
                sp2B4 = 0;
                sp2B8 = 0;
                sp2BC = -1;
                sp2C0 = 0;
                sp140 = (f64) spC0;
                sp148 = (f64) spC8;
                temp_f5_730 = M2C_FIELD(var_r31_467, f64 *, 0);
                spB0 = temp_f5_730 + sp140;
                spE8 = 0.0f;
                temp_f4_736 = var_r31_467->unk8;
                spE0 = 0.0f;
                spE4 = 500.0f;
                spB8 = temp_f4_736 + (f32) sp148;
                sp160 = (f64) spE0;
                sp150 = spB0;
                sp158 = (f64) spB8;
                sp168 = (f64) spE8;
                temp_f0_751 = temp_f5_730 + sp160;
                spD0 = temp_f0_751;
                sp170 = temp_f0_751;
                spD8 = temp_f4_736 + (f32) sp168;
                sp178 = (f64) spD8;
                if (MKCollision_RayCollide(*((MKVector3 *) &sp170), *((MKVector3 *) &sp150), (MKCollisionResult *) &sp270, (MKCollisionMode) 4, 1) != 0) {
                    M2C_FIELD(temp_r30_470, f32 *, 0x20) = (f32) (5.0f + sp274);
                    M2C_FIELD(temp_r30_470, f64 *, 0x30) = (f64) sp280;
                    M2C_FIELD(temp_r30_470, f64 *, 0x38) = (f64) sp288;
                } else {
                    sp30 = 0.0f;
                    sp34 = 1.0f;
                    sp38 = 0.0f;
                    M2C_FIELD(temp_r30_470, f64 *, 0x30) = (f64) sp30;
                    sp130 = (f64) sp30;
                    sp138 = (f64) sp38;
                    M2C_FIELD(temp_r30_470, f64 *, 0x38) = (f64) sp38;
                }
                if (var_r31_467->unk4 <= M2C_FIELD(temp_r30_470, f32 *, 0x20)) {
                    M2C_FIELD(temp_r30_470, u8 *, 0x28) = 1U;
                    var_r31_467->unk4 = M2C_FIELD(temp_r30_470, f32 *, 0x20);
                }
            } else if (temp_f1_688 > temp_f0_689) {
                M2C_FIELD(temp_r30_470, u8 *, 0x28) = 0U;
            }
            var_r29_806 = 0;
            var_r27_807 = 0;
            do {
                temp_r4_809 = this + var_r27_807;
                if (((u8) M2C_FIELD(temp_r4_809, u8 *, 0x178) != 0) && ((u8) M2C_FIELD(temp_r30_470, u8 *, 0x28) != 0)) {
                    spA0 = M2C_FIELD(var_r31_467, f64 *, 0) - M2C_FIELD(temp_r4_809, f64 *, 0x160);
                    sp200 = spA0;
                    spA8 = var_r31_467->unk8 - M2C_FIELD(temp_r4_809, f32 *, 0x168);
                    sp208 = (f64) spA8;
                    var_f4_837 = ((f32) sp208 * (f32) sp208) + (((f32) sp200 * (f32) sp200) + ((*(f32 *) ((u8 *) &sp1F0 + 0x14)) * (*(f32 *) ((u8 *) &sp1F0 + 0x14))));
                    if (var_f4_837 > 0.000001f) {
                        if (var_f4_837 > 0.0f) {
                            temp_f1_843 = __frsqrte(var_f4_837);
                            temp_f1_849 = 0.5 * temp_f1_843 * -(((f64) var_f4_837 * (temp_f1_843 * temp_f1_843)) - 3.0);
                            temp_f1_853 = 0.5 * temp_f1_849 * -(((f64) var_f4_837 * (temp_f1_849 * temp_f1_849)) - 3.0);
                            var_f4_837 = (f32) ((f64) var_f4_837 * (0.5 * temp_f1_853 * -(((f64) var_f4_837 * (temp_f1_853 * temp_f1_853)) - 3.0)));
                        } else if (var_f4_837 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_837 = __float_nan;
                        } else {
                            sp10 = var_f4_837;
                            temp_r3_872 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                            switch (temp_r3_872) {  /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                    var_r0_882 = 1;
                                } else {
                                    var_r0_882 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                    var_r0_882 = 5;
                                } else {
                                    var_r0_882 = 3;
                                }
                                break;
                            default:
                                var_r0_882 = 4;
                                break;
                            }
                            if (var_r0_882 == 1) {
                                var_f4_837 = __float_nan;
                            }
                        }
                        var_f3_904 = 1.0f / var_f4_837;
                    } else {
                        var_f3_904 = 0.0f;
                        var_f4_837 = 0.0f;
                    }
                    sp200 = (f32) sp200 * var_f3_904;
                    (*(f32 *) ((u8 *) &sp1F0 + 0x14)) *= var_f3_904;
                    M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                    if (var_f4_837 == M2C_FIELD(temp_r4_809, f32 *, 0x170)) {
                        M2C_FIELD(temp_r30_470, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 7.5f, 85.0f);
                        temp_f24_931 = 1.0f - (M2C_FIELD(temp_r30_470, f32 *, 0x24) / 90.0f);
                        temp_f23_933 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                        temp_f25_938 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.1f);
                        sp90 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                        sp94 = temp_f25_938;
                        sp98 = temp_f23_933;
                        sp1F0 = (f64) sp90;
                        sp1F8 = (f64) sp98;
                        temp_f0_952 = sp1F0 * 5.45263811e-315;
                        sp1F0 = temp_f0_952;
                        M2C_FIELD(temp_r30_470, f64 *, 0) = temp_f0_952;
                        sp1F8 = (f32) sp1F8 * 25.0f;
                        M2C_FIELD(temp_r30_470, f32 *, 8) = (f64) sp1F8;
                        temp_f23_965 = MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f);
                        MKVector(MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f), 1.0f, temp_f23_965);
                        temp_f0_977 = sp110 * 5.60222949e-315;
                        sp20 = temp_f0_977;
                        sp120 = temp_f0_977;
                        sp28 = sp118 * 300.0f;
                        sp128 = (f64) sp28;
                        M2C_FIELD(temp_r30_470, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_470, f64 *, 0) + temp_f0_977);
                        M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) sp128);
                        M2C_FIELD(temp_r30_470, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_470, f64 *, 0) * (f64) temp_f24_931);
                        M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) * temp_f24_931);
                        M2C_FIELD(temp_r30_470, u8 *, 0x28) = 0U;
                    }
                }
                var_r29_806 += 1;
                var_r27_807 += 0x20;
            } while (var_r29_806 < 4);
            var_r31_467 = GetNextParticle(&unksp18);
        }
        goto loop_51;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp8'
void FallingLeaves::ApplyWind(WindFX *arg0) {
    WindFX sp70;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r31_1079;
    f32 temp_f27_1161;
    f32 temp_f28_1159;
    f32 temp_f29_1090;
    f32 temp_f31_1120;
    f64 temp_f0_1097;
    f64 temp_f0_1173;
    void *temp_r30_1082;

    var_r31_1079 = GetFirstParticle(&unksp8);
loop_6:
    if (var_r31_1079 != NULL) {
        temp_r30_1082 = var_r31_1079->unk2C;
        if ((u8) M2C_FIELD(temp_r30_1082, u8 *, 0x28) == 0) {
            temp_f29_1090 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            sp70.GetVelocity(*((MKVector3 *) arg0));
            temp_f0_1097 = sp70.unk0 * (f64) temp_f29_1090;
            sp20 = temp_f0_1097;
            sp70.unk10 = temp_f0_1097;
            sp28 = (f32) sp70.unk8 * temp_f29_1090;
            sp70.unk18 = (f64) sp28;
            M2C_FIELD(temp_r30_1082, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_1082, f64 *, 0) + (f64) sp70.unk10);
            M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) + (f32) (f64) sp28);
        } else {
            temp_f31_1120 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            ((WindFX *) &sp60)->GetVelocity(*((MKVector3 *) arg0));
            sp30 = sp60 * (f64) temp_f31_1120;
            sp70.unk20 = sp30;
            sp38 = sp68 * temp_f31_1120;
            sp70.unk28 = (f64) sp38;
            if ((((f32) sp70.unk28 * (f32) sp70.unk28) + (((f32) sp70.unk20 * (f32) sp70.unk20) + ((*(f32 *) ((u8 *) &sp70 + 0x24)) * (*(f32 *) ((u8 *) &sp70 + 0x24))))) != 0.0f) {
                M2C_FIELD(temp_r30_1082, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 7.5f, 85.0f);
                temp_f28_1159 = 1.0f - (M2C_FIELD(temp_r30_1082, f32 *, 0x24) / 90.0f);
                temp_f27_1161 = MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f);
                MKVector(MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f), 1.0f, temp_f27_1161);
                temp_f0_1173 = sp40 * 5.60222949e-315;
                sp10 = temp_f0_1173;
                sp50 = temp_f0_1173;
                sp18 = sp48 * 300.0f;
                sp58 = (f64) sp18;
                M2C_FIELD(temp_r30_1082, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_1082, f64 *, 0) + temp_f0_1173);
                M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) + (f32) sp58);
                M2C_FIELD(temp_r30_1082, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_1082, f64 *, 0) * (f64) temp_f28_1159);
                M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) * temp_f28_1159);
                M2C_FIELD(temp_r30_1082, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_1082, f64 *, 0) + sp70.unk20);
                M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) + (f32) sp70.unk28);
                M2C_FIELD(temp_r30_1082, u8 *, 0x28) = 0U;
            }
        }
        var_r31_1079 = GetNextParticle(&unksp8);
        goto loop_6;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp70'
void FallingLeaves::Update() {
    M2C_UNK sp4C;
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f64 temp_f0_1281;
    s32 temp_r0_1326;
    s32 var_ctr_1324;
    s32 var_r3_1321;
    void *temp_r3_1247;

    if ((u8) this->unk1E1 != 0) {
        temp_r3_1247 = this->unk8;
        this->unk140 = M2C_FIELD(temp_r3_1247, f64 *, 0x30);
        this->unk148 = M2C_FIELD(temp_r3_1247, f64 *, 0x38);
    }
    M2C_STRUCT_COPY((s32) &sp4C + 4, M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), s32 *, 8) - 4 + 4, 0x40);
    sp30 = sp70;
    sp40 = sp80;
    sp48 = sp88;
    sp38 = sp78;
    temp_f0_1281 = sp30 * 5.49408334e-315;
    sp10 = temp_f0_1281;
    sp20 = temp_f0_1281;
    sp18 = (f32) sp38 * 50.0f;
    sp28 = (f64) sp18;
    sp40 += temp_f0_1281;
    sp48 = (f32) sp48 + (f32) sp28;
    (*(f32 *) ((u8 *) &sp40 + 0x4)) -= 20.0f;
    AddForce(*((MKVector3 *) &sp40), 50.0f, 200.0f);
    UpdateParticles();
    if ((u8) this->unk1E1 != 0) {
        Emit();
        SpawnGround(*((MKVector3 *) &this->unk140));
    }
    var_r3_1321 = 0;
    var_ctr_1324 = 4;
    do {
        temp_r0_1326 = var_r3_1321 + 0x178;
        var_r3_1321 += 0x20;
        *(this + temp_r0_1326) = 0;
        var_ctr_1324 -= 1;
    } while (var_ctr_1324 != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void FallingLeaves::SpawnGround(const MKVector3 &arg0) {
    MKCollisionResult spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
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
    f64 sp8;
    f32 temp_f1_1423;
    f32 temp_f27_1397;
    f32 temp_f28_1367;
    f32 temp_f29_1372;
    f32 temp_f3_1465;
    f64 temp_f0_1408;
    f64 temp_f0_1485;
    f64 temp_f0_1515;
    f64 temp_f30_1359;
    f64 temp_f31_1361;
    void *temp_r30_1432;
    void *temp_r3_1429;

    temp_f30_1359 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f31_1361 = M2C_FIELD(&arg0, f64 *, 8);
    temp_f28_1367 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    temp_f29_1372 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.1f);
    sp48 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    sp4C = temp_f29_1372;
    sp50 = temp_f28_1367;
    spC8 = (f64) sp48;
    spD0 = (f64) sp50;
    spC8 *= 5.45263811e-315;
    spB8 = temp_f30_1359;
    spC0 = temp_f31_1361;
    spD0 = (f32) spD0 * 25.0f;
    temp_f27_1397 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), 0.0f, temp_f27_1397);
    temp_f0_1408 = sp98 * 5.634608575e-315;
    sp18 = temp_f0_1408;
    spA8 = temp_f0_1408;
    sp20 = spA0 * 500.0f;
    spB0 = (f64) sp20;
    spB8 += temp_f0_1408;
    temp_f1_1423 = (f32) spC0;
    spC0 = temp_f1_1423 + (f32) spB0;
    temp_r3_1429 = CreateParticle(temp_f1_1423);
    if (temp_r3_1429 != NULL) {
        temp_r30_1432 = M2C_FIELD(temp_r3_1429, void **, 0x2C);
        M2C_FIELD(temp_r3_1429, f64 *, 0) = spB8;
        M2C_FIELD(temp_r3_1429, f64 *, 8) = (f64) spC0;
        M2C_FIELD(temp_r30_1432, f64 *, 0) = spC8;
        M2C_FIELD(temp_r30_1432, f64 *, 8) = (f64) spD0;
        M2C_FIELD(temp_r30_1432, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.1f, 0.25f);
        M2C_FIELD(temp_r30_1432, f32 *, 0x1C) = 1.0f;
        M2C_FIELD(temp_r30_1432, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 7.5f, 85.0f);
        temp_f3_1465 = (f32) MKRand_Int((int *) &gViewSeed, 0, 4);
        sp40 = 0.0f;
        M2C_FIELD(temp_r3_1429, f32 *, 0x20) = temp_f3_1465;
        sp38 = 0.0f;
        sp3C = 500.0f;
        sp80 = (f64) sp40;
        sp78 = (f64) sp38;
        M2C_FIELD(temp_r30_1432, f32 *, 0x14) = (f32) (500.0f * (1.0f - (M2C_FIELD(temp_r30_1432, f32 *, 0x24) / 90.0f)));
        M2C_FIELD(temp_r30_1432, f32 *, 0x20) = (*(f32 *) ((u8 *) &spB8 + 0x4));
        temp_f0_1485 = spB8 + sp78;
        sp28 = temp_f0_1485;
        sp88 = temp_f0_1485;
        sp30 = spC0 + (f32) sp80;
        sp90 = (f64) sp30;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp88), 3000.0f, &spD8, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
            M2C_FIELD(temp_r30_1432, f32 *, 0x20) = (f32) (10.0f + spD8.unk4);
            MKVector(0.0f, 10.0f, 0.0f);
            temp_f0_1515 = M2C_BITWISE(f64, spD8) + sp58;
            sp8 = temp_f0_1515;
            M2C_FIELD(temp_r3_1429, f64 *, 0) = temp_f0_1515;
            sp10 = spD8.unk8 + sp60;
            sp68 = temp_f0_1515;
            M2C_FIELD(temp_r3_1429, f64 *, 8) = (f64) sp10;
            sp70 = (f64) sp10;
            M2C_FIELD(temp_r30_1432, f64 *, 0x30) = (f64) spD8.unk10;
            M2C_FIELD(temp_r30_1432, f64 *, 0x38) = (f64) spD8.unk18;
        }
        M2C_FIELD(temp_r30_1432, s8 *, 0x28) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void FallingLeaves::Emit() {
    MKCollisionResult spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
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
    f32 temp_f28_1577;
    f32 temp_f28_1609;
    f32 temp_f29_1582;
    f64 temp_f0_1620;
    f64 temp_f0_1718;
    f64 temp_f1_1600;
    s32 var_r29_1571;
    void *temp_r28_1651;
    void *temp_r3_1648;

    var_r29_1571 = 0;
    do {
        temp_f28_1577 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f29_1582 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.1f);
        sp48 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f29_1582;
        sp50 = temp_f28_1577;
        spB8 = (f64) sp48;
        spC0 = (f64) sp50;
        spB8 *= 5.45263811e-315;
        temp_f1_1600 = this->unk140;
        spA8 = temp_f1_1600;
        spC0 = (f32) spC0 * 25.0f;
        spB0 = this->unk148;
        temp_f28_1609 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), 0.0f, temp_f28_1609);
        temp_f0_1620 = sp88 * 5.65176949e-315;
        sp18 = temp_f0_1620;
        sp98 = temp_f0_1620;
        sp20 = sp90 * 700.0f;
        spA0 = (f64) sp20;
        spA8 = temp_f1_1600 + temp_f0_1620;
        spB0 = (f32) spB0 + (f32) spA0;
        (*(f32 *) ((u8 *) &spA8 + 0x4)) += MKRand_Float((int *) &gViewSeed, 725.0f, 800.0f);
        temp_r3_1648 = CreateParticle();
        if (temp_r3_1648 != NULL) {
            temp_r28_1651 = M2C_FIELD(temp_r3_1648, void **, 0x2C);
            M2C_FIELD(temp_r3_1648, f64 *, 0) = spA8;
            M2C_FIELD(temp_r3_1648, f64 *, 8) = (f64) spB0;
            M2C_FIELD(temp_r28_1651, f64 *, 0) = spB8;
            M2C_FIELD(temp_r28_1651, f64 *, 8) = (f64) spC0;
            M2C_FIELD(temp_r28_1651, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.1f, 0.25f);
            M2C_FIELD(temp_r28_1651, f32 *, 0x1C) = 1.0f;
            M2C_FIELD(temp_r28_1651, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 7.5f, 85.0f);
            M2C_FIELD(temp_r3_1648, f32 *, 0x20) = (f32) MKRand_Int((int *) &gViewSeed, 0, 4);
            M2C_FIELD(temp_r3_1648, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 270.0f);
            sp10 = 0.0f;
            sp40 = 0.0f;
            sp8 = 0.0f;
            spC = 1.0f;
            M2C_FIELD(temp_r28_1651, f32 *, 0x14) = (f32) (500.0f * (1.0f - (M2C_FIELD(temp_r28_1651, f32 *, 0x24) / 90.0f)));
            M2C_FIELD(temp_r28_1651, f64 *, 0x30) = (f64) sp8;
            M2C_FIELD(temp_r28_1651, f64 *, 0x38) = (f64) sp10;
            sp38 = 0.0f;
            sp3C = 500.0f;
            sp78 = (f64) sp8;
            sp58 = (f64) sp38;
            sp80 = (f64) sp10;
            M2C_FIELD(temp_r28_1651, f32 *, 0x20) = (*(f32 *) ((u8 *) &spA8 + 0x4));
            sp60 = (f64) sp40;
            temp_f0_1718 = spA8 + sp58;
            sp28 = temp_f0_1718;
            sp68 = temp_f0_1718;
            sp30 = spB0 + (f32) sp60;
            sp70 = (f64) sp30;
            if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp68), 3000.0f, &spC8, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
                M2C_FIELD(temp_r28_1651, f32 *, 0x20) = (f32) (10.0f + spC8.unk4);
                M2C_FIELD(temp_r28_1651, f64 *, 0x30) = (f64) spC8.unk10;
                M2C_FIELD(temp_r28_1651, f64 *, 0x38) = (f64) spC8.unk18;
            }
            M2C_FIELD(temp_r28_1651, s8 *, 0x28) = 0;
        }
        var_r29_1571 += 1;
    } while (var_r29_1571 < 0xA);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void FallingLeaves::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, const int &arg3, bool arg4) {
    s8 sp128;
    s32 sp124;
    s32 sp120;
    s32 sp11C;
    f32 sp118;
    s32 sp114;
    s8 sp113;
    s8 sp112;
    s16 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f64 spD0;
    f64 spC8;
    M2C_UNK spB8;
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
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f31_1819;
    f32 temp_f4_1905;
    f64 temp_f0_1832;
    f64 temp_f0_1921;
    f64 temp_f5_1901;
    void *temp_r30_1788;
    void *temp_r3_1785;

    temp_r3_1785 = CreateParticle();
    if (temp_r3_1785 != NULL) {
        temp_r30_1788 = M2C_FIELD(temp_r3_1785, void **, 0x2C);
        M2C_FIELD(temp_r3_1785, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_1785, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r30_1788, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_1788, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_1788, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r30_1788, f32 *, 0x1C) = 1.0f;
        M2C_FIELD(temp_r30_1788, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 7.5f, 55.0f);
        M2C_FIELD(temp_r3_1785, f32 *, 0x20) = (f32) &arg3;
        temp_f31_1819 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        MKVector(1.0f, 1.0f, 1.0f, 1.0f);
        sp18 = M2C_FIELD(&spB8, f64 *, 0) * (f64) temp_f31_1819;
        temp_f0_1832 = M2C_FIELD(&spB8, f64 *, 8) * (f64) temp_f31_1819;
        sp20 = temp_f0_1832;
        M2C_FIELD(temp_r3_1785, f64 *, 0x10) = sp18;
        spC8 = sp18;
        spD0 = temp_f0_1832;
        M2C_FIELD(temp_r3_1785, f64 *, 0x18) = temp_f0_1832;
        M2C_FIELD(temp_r3_1785, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 270.0f);
        sp10 = 0.0f;
        sp8 = 0.0f;
        spC = 1.0f;
        spB0 = (f64) sp10;
        spA8 = (f64) sp8;
        M2C_FIELD(temp_r30_1788, f32 *, 0x14) = (f32) (500.0f * (1.0f - (M2C_FIELD(temp_r30_1788, f32 *, 0x24) / 90.0f)));
        M2C_FIELD(temp_r30_1788, f64 *, 0x30) = (f64) sp8;
        M2C_FIELD(temp_r30_1788, f64 *, 0x38) = (f64) sp10;
        M2C_FIELD(temp_r30_1788, f32 *, 0x20) = (f32) (arg0.unk4 - 200000.0f);
        if (arg4 != 0) {
            sp40 = 0.0f;
            sp38 = 0.0f;
            sp3C = -3000.0f;
            spD8 = 0.0f;
            sp68 = (f64) sp38;
            spDC = 0.0f;
            spE0 = 0.0f;
            spE8 = 0.0f;
            spEC = 0.0f;
            spF0 = 0.0f;
            spF8 = 0.0f;
            spFC = 0.0f;
            sp100 = 0.0f;
            sp104 = 1.0f;
            sp108 = 0.0f;
            sp10C = 0.0f;
            sp110 = 0;
            sp112 = 0;
            sp113 = 0;
            sp114 = 0;
            sp118 = 3.4028235e38f;
            sp11C = 0;
            sp120 = 0;
            sp124 = -1;
            sp128 = 0;
            sp70 = (f64) sp40;
            temp_f5_1901 = M2C_FIELD(&arg0, f64 *, 0);
            sp28 = temp_f5_1901 + sp68;
            temp_f4_1905 = arg0.unk8;
            sp60 = 0.0f;
            sp58 = 0.0f;
            sp5C = 500.0f;
            sp30 = temp_f4_1905 + (f32) sp70;
            sp88 = (f64) sp58;
            sp78 = sp28;
            sp80 = (f64) sp30;
            sp90 = (f64) sp60;
            temp_f0_1921 = temp_f5_1901 + sp88;
            sp48 = temp_f0_1921;
            sp98 = temp_f0_1921;
            sp50 = temp_f4_1905 + (f32) sp90;
            spA0 = (f64) sp50;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp98), *((MKVector3 *) &sp78), (MKCollisionResult *) &spD8, (MKCollisionMode) 4, 1) != 0) {
                M2C_FIELD(temp_r30_1788, f32 *, 0x20) = (f32) (10.0f + spDC);
                M2C_FIELD(temp_r30_1788, f64 *, 0x30) = (f64) spE8;
                M2C_FIELD(temp_r30_1788, f64 *, 0x38) = (f64) spF0;
            }
        }
        M2C_FIELD(temp_r30_1788, s8 *, 0x28) = 0;
    }
}
#endif

void FallingLeaves::Deinit() {
    MKParticleSystem::Deinit();
}

void FallingLeaves::Resolve() {
    MKProp::Resolve();
}

void FallingLeaves::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: illegal operand
void FallingLeaves::Init() {
    s32 temp_r0_2027;
    s32 var_ctr_2025;
    s32 var_r3_2022;

    MKParticleSystem::Init();
    this->unkA8 = 15.0f;
    this->unkAC = 15.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gFallingLeavesEnvelope, 5);
    SetMaxParticleAge(10.0f);
    var_r3_2022 = 0;
    var_ctr_2025 = 4;
    do {
        temp_r0_2027 = var_r3_2022 + 0x178;
        var_r3_2022 += 0x20;
        *(this + temp_r0_2027) = 0;
        var_ctr_2025 -= 1;
    } while (var_ctr_2025 != 0);
    this->unk1E0 = 1;
    this->unk1E1 = 0;
}
#endif

void FallingLeavesDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
}

void FallingLeaves_cpp::__sinit() {
    f32 temp_f0_2096;
    f64 temp_f1_2077;
    f64 temp_f1_2085;
    f64 temp_f3_2065;
    f64 temp_f4_2074;
    f64 temp_f4_2082;
    f64 temp_f8_2067;

    temp_f3_2065 = __frsqrte(2014000.0);
    temp_f8_2067 = __frsqrte(380000.0);
    temp_f4_2074 = 0.5 * temp_f3_2065 * -((2014000.0 * (temp_f3_2065 * temp_f3_2065)) - 3.0);
    temp_f1_2077 = 0.5 * temp_f8_2067 * -((380000.0 * (temp_f8_2067 * temp_f8_2067)) - 3.0);
    temp_f4_2082 = 0.5 * temp_f4_2074 * -((2014000.0 * (temp_f4_2074 * temp_f4_2074)) - 3.0);
    temp_f1_2085 = 0.5 * temp_f1_2077 * -((380000.0 * (temp_f1_2077 * temp_f1_2077)) - 3.0);
    temp_f0_2096 = (f32) (380000.0 * (0.5 * temp_f1_2085 * -((380000.0 * (temp_f1_2085 * temp_f1_2085)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2082 * -((2014000.0 * (temp_f4_2082 * temp_f4_2082)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2096;
}
