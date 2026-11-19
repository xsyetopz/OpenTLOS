#include "spyro/source/Swarm.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
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
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(SwarmEntity **);                       /* extern */
SwarmEntity **malloc(s32);                          /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

static M2C_UNK lit_620;                                /* unable to generate initializer: unknown type; const */

void SwarmPropDescriptor::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    KDPropDescriptor::Init();
    sp18 = -100.0f;
    sp1C = -100.0f;
    sp20 = -100.0f;
    M2C_FIELD(this, f64 *, 0x70) = (f64) sp18;
    sp10 = 100.0f;
    sp8 = 100.0f;
    spC = 100.0f;
    this->unk78 = (f64) sp20;
    this->unk80 = (f64) sp8;
    this->unk88 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unk1C = (BoundingVolume *) &this->unk70;
    this->unk90 = (long) (MKMaterial_Create("fx_013"));
}

void SwarmProp::Message(MKMessage *arg0) {
    KDProp::Message(arg0);
}

void SwarmProp::DrawEntity(SwarmEntity *arg0, const Matrix &arg1, const MKVector4 &arg2, float arg3) {
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    Matrix sp250;
    Matrix sp210;
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
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
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
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
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
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f0_106;
    f32 temp_f1_108;
    f32 temp_f2_109;
    f32 temp_f4_152;
    f32 temp_f6_193;
    f32 temp_f7_195;
    f32 temp_f8_188;
    f32 temp_f9_132;
    f64 temp_f0_208;
    f64 temp_f0_219;
    f64 temp_f0_245;
    f64 temp_f0_256;
    f64 temp_f3_118;
    f64 temp_f4_139;
    f64 temp_f6_168;

    sp128 = 0.0f;
    sp118 = 0.0f;
    sp120 = 0.0f;
    sp124 = 1.0f;
    sp110 = 1.0f;
    sp114 = 0.0f;
    sp200 = (f64) sp120;
    sp208 = (f64) sp128;
    sp1F0 = (f64) sp110;
    sp1F8 = (f64) sp118;
    M2C_STRUCT_COPY((s32) &sp250.unk3C + 4, (s32) (&lit_620 - 4) + 4, 0x40);
    temp_f0_106 = -(f32) sp1F0;
    temp_f1_108 = -(*(f32 *) ((u8 *) &sp1F0 + 0x4));
    temp_f2_109 = -(f32) sp1F8;
    spF0 = temp_f0_106;
    spF4 = temp_f1_108;
    spF8 = temp_f2_109;
    sp1E0 = (f64) spF0;
    sp1E8 = (f64) spF8;
    temp_f3_118 = sp1E0 * (f64) arg3;
    spE0 = temp_f3_118;
    sp1D0 = temp_f3_118;
    spE8 = (f32) sp1E8 * arg3;
    sp1D8 = (f64) spE8;
    sp100 = (f64) sp120 * (f64) arg3;
    temp_f9_132 = (f32) sp208 * arg3;
    sp1C0 = sp100;
    sp108 = temp_f9_132;
    sp1C8 = (f64) sp108;
    temp_f4_139 = sp1C0 + sp1D0;
    spD0 = temp_f4_139;
    sp290 = temp_f4_139;
    spD8 = (f32) sp1C8 + (f32) sp1D8;
    sp298 = (f64) spD8;
    spB0 = sp1F0 * (f64) arg3;
    temp_f4_152 = (f32) sp1F8 * arg3;
    spB8 = temp_f4_152;
    sp1B0 = spB0;
    sp1B8 = (f64) spB8;
    spC0 = sp200 * (f64) arg3;
    spC8 = temp_f9_132;
    sp1A0 = spC0;
    sp1A8 = (f64) spC8;
    temp_f6_168 = spC0 + sp1B0;
    spA0 = temp_f6_168;
    sp78 = temp_f2_109;
    sp70 = temp_f0_106;
    sp74 = temp_f1_108;
    spA8 = (f32) sp1A8 + (f32) sp1B8;
    sp190 = (f64) sp70;
    sp2A0 = temp_f6_168;
    sp2A8 = (f64) spA8;
    sp198 = (f64) sp78;
    sp60 = (f64) sp70 * (f64) arg3;
    temp_f8_188 = -(f32) sp208;
    temp_f6_193 = -(f32) sp200;
    sp98 = temp_f8_188;
    temp_f7_195 = -(*(f32 *) ((u8 *) &sp200 + 0x4));
    sp68 = (f32) sp198 * arg3;
    sp90 = temp_f6_193;
    sp94 = temp_f7_195;
    sp180 = sp60;
    sp188 = (f64) sp68;
    sp170 = (f64) sp90;
    sp178 = (f64) sp98;
    temp_f0_208 = sp170 * (f64) arg3;
    sp80 = temp_f0_208;
    sp160 = temp_f0_208;
    sp88 = (f32) sp178 * arg3;
    sp168 = (f64) sp88;
    temp_f0_219 = sp160 + sp180;
    sp50 = temp_f0_219;
    sp2B0 = temp_f0_219;
    sp58 = (f32) sp168 + (f32) sp188;
    sp2B8 = (f64) sp58;
    sp20 = sp1F0 * (f64) arg3;
    sp28 = temp_f4_152;
    sp48 = temp_f8_188;
    sp40 = temp_f6_193;
    sp44 = temp_f7_195;
    sp150 = sp20;
    sp140 = (f64) sp40;
    sp158 = (f64) sp28;
    sp148 = (f64) sp48;
    temp_f0_245 = sp140 * (f64) arg3;
    sp30 = temp_f0_245;
    sp130 = temp_f0_245;
    sp38 = (f32) sp148 * arg3;
    sp138 = (f64) sp38;
    temp_f0_256 = sp130 + sp150;
    sp10 = temp_f0_256;
    sp2C0 = temp_f0_256;
    sp18 = (f32) sp138 + (f32) sp158;
    sp2C8 = (f64) sp18;
    M2C_STRUCT_COPY((s32) &sp210.unk3C + 4, (s32) (&arg1 - 4) + 4, 0x40);
    sp210.SetIdentity();
    sp210.RotateRoll(&sp210, 0.0f);
    sp250.Multiply3x3(&sp210, &sp250);
    sp250.Translate(&sp250, *((MKVector3 *) arg0));
    MKSetMatrix(sp250);
    MKBegin(4);
    MKSetColorV(arg2);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp290));
    MKSetColorV(arg2);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp2A0));
    MKSetColorV(arg2);
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp2B0));
    MKSetColorV(arg2);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp2C0));
    MKEnd();
}

void SwarmProp::Draw() {
    Matrix sp70;
    Matrix sp30;
    MKVector4 sp20;
    SwarmPropDescriptor *desc;
    SwarmEntity **cur;

    KDProp::Draw();
    M2C_STRUCT_COPY(&sp70, MKView_GetCameraMatrix(), 0x40);
    M2C_STRUCT_COPY(&sp30, &this->unk90, 0x40);
    sp30.Multiply3x3(&sp30, &sp70);
    desc = checked_cast<SwarmPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKMaterial_SetMaterial(M2C_FIELD(desc, MKMaterial **, 0x90));
    sp20.unk0 = 0.8f;
    sp20.unk4 = 0.8f;
    sp20.unk8 = 0.0f;
    sp20.unkC = 1.0f;
    MKPrimitive(0xC, 0);
    cur = this->unkF4;
    while (*cur != NULL) {
        DrawEntity(*cur, sp30, sp20, 10.0f);
        cur += 1;
    }
    MKEndPrimitive();
}

#if 0 // DRAFT: illegal operand
void *SwarmProp::Update() {
    f64 sp118;                                      /* compiler-managed */
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    MKVector3 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    MKVector3 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    SwarmEntity **temp_r24_453;
    SwarmEntity **var_r27_429;
    SwarmEntity **var_r3_454;
    SwarmEntity *temp_r28_710;
    f32 temp_f0_495;
    f32 temp_f0_540;
    f32 temp_f1_539;
    f32 temp_f26_675;
    f32 temp_f28_631;
    f32 temp_f3_541;
    f32 var_f2_614;
    f32 var_f4_547;
    f64 temp_f0_510;
    f64 temp_f0_528;
    f64 temp_f0_634;
    f64 temp_f0_655;
    f64 temp_f0_678;
    f64 temp_f1_553;
    f64 temp_f1_559;
    f64 temp_f1_563;
    f64 temp_f2_490;
    s32 temp_r0_471;
    s32 temp_r3_582;
    s32 var_ctr_484;
    s32 var_r0_592;
    s32 var_r23_450;
    s32 var_r25_451;
    s32 var_r3_479;
    void *temp_r4_477;
    void *temp_r4_487;

    KDProp::Update();
    var_r27_429 = this->unkF4;
loop_30:
    temp_r28_710 = *var_r27_429;
    if (temp_r28_710 != NULL) {
        temp_r28_710->unk30 -= gUpdateTimeDelta;
        if (temp_r28_710->unk30 <= 0.0f) {
            temp_r28_710->unk30 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
            var_r23_450 = 0;
            var_r25_451 = 0;
            do {
                temp_r24_453 = this->unkF4;
                var_r3_454 = temp_r24_453;
loop_5:
                if ((SwarmEntity *) *var_r3_454 != NULL) {
                    var_r3_454 += 4;
                    goto loop_5;
                }
                var_r23_450 += 1;
                temp_r0_471 = var_r25_451 + 0x34;
                var_r25_451 += 4;
                *(temp_r28_710 + temp_r0_471) = temp_r24_453[MKRand_Int((int *) &gViewSeed, 0, (s32) (var_r3_454 - temp_r24_453) / 4)];
            } while (var_r23_450 < 3);
        }
        temp_r4_477 = temp_r28_710->unk34;
        var_r3_479 = 4;
        sp110 = M2C_FIELD(temp_r4_477, f64 *, 0);
        sp118 = M2C_FIELD(temp_r4_477, f64 *, 8);
        var_ctr_484 = 2;
        do {
            temp_r4_487 = *(temp_r28_710 + (var_r3_479 + 0x34));
            temp_f2_490 = sp110 + M2C_FIELD(temp_r4_487, f64 *, 0);
            sp110 = temp_f2_490;
            var_r3_479 += 4;
            temp_f0_495 = (f32) sp118 + M2C_FIELD(temp_r4_487, f32 *, 8);
            sp118 = temp_f0_495;
            var_ctr_484 -= 1;
        } while (var_ctr_484 != 0);
        sp110 = temp_f2_490 * 5.194468865e-315;
        sp118 = (f32) temp_f0_495 * 0.33333334f;
        spD0 = ((MKVector3 *) temp_r28_710)->operator*(gUpdateTimeDelta);
        temp_f0_510 = sp110 - temp_r28_710->unk0;
        sp10 = temp_f0_510;
        spE0 = temp_f0_510;
        sp18 = sp118 - M2C_FIELD(temp_r28_710, f32 *, 8);
        spE8 = (f64) sp18;
        KDMath_Smooth<MKVector3>(spF0, *((MKVector3 *) &temp_r28_710->unk20), 5.0f, gUpdateTimeDelta);
        temp_f0_528 = spF0 - M2C_BITWISE(f64, spD0);
        sp60 = temp_f0_528;
        temp_r28_710->unk20 = temp_f0_528;
        sp68 = spF0.unk8 - spD0.unk8;
        sp100 = temp_f0_528;
        temp_r28_710->unk28 = (f64) sp68;
        temp_f1_539 = (f32) M2C_FIELD(temp_r28_710, f64 *, 0x20);
        temp_f0_540 = M2C_FIELD(temp_r28_710, f32 *, 0x24);
        temp_f3_541 = (f32) M2C_FIELD(temp_r28_710, f64 *, 0x28);
        sp108 = (f64) sp68;
        var_f4_547 = (temp_f3_541 * temp_f3_541) + ((temp_f1_539 * temp_f1_539) + (temp_f0_540 * temp_f0_540));
        if (var_f4_547 > 0.000001f) {
            if (var_f4_547 > 0.0f) {
                temp_f1_553 = __frsqrte(var_f4_547);
                temp_f1_559 = 0.5 * temp_f1_553 * -(((f64) var_f4_547 * (temp_f1_553 * temp_f1_553)) - 3.0);
                temp_f1_563 = 0.5 * temp_f1_559 * -(((f64) var_f4_547 * (temp_f1_559 * temp_f1_559)) - 3.0);
                var_f4_547 = (f32) ((f64) var_f4_547 * (0.5 * temp_f1_563 * -(((f64) var_f4_547 * (temp_f1_563 * temp_f1_563)) - 3.0)));
            } else if (var_f4_547 < M2C_BITWISE(f32, 0.0)) {
                var_f4_547 = __float_nan;
            } else {
                sp8 = var_f4_547;
                temp_r3_582 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_582) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_592 = 1;
                    } else {
                        var_r0_592 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_592 = 5;
                    } else {
                        var_r0_592 = 3;
                    }
                    break;
                default:
                    var_r0_592 = 4;
                    break;
                }
                if (var_r0_592 == 1) {
                    var_f4_547 = __float_nan;
                }
            }
            var_f2_614 = 1.0f / var_f4_547;
        } else {
            var_f2_614 = 0.0f;
        }
        M2C_FIELD(temp_r28_710, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(temp_r28_710, f64 *, 0x20) * var_f2_614);
        M2C_FIELD(temp_r28_710, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r28_710, f32 *, 0x24) * var_f2_614);
        M2C_FIELD(temp_r28_710, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(temp_r28_710, f64 *, 0x28) * var_f2_614);
        temp_f28_631 = gUpdateTimeDelta;
        spB0 = ((MKVector3 *) &temp_r28_710->unk20)->operator*(500.0f);
        temp_f0_634 = spB0 * (f64) temp_f28_631;
        sp50 = temp_f0_634;
        spC0 = temp_f0_634;
        sp58 = spB0.unk8 * temp_f28_631;
        spC8 = (f64) sp58;
        temp_r28_710->unk10 += temp_f0_634;
        M2C_FIELD(temp_r28_710, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_710, f32 *, 0x18) + (f32) spC8);
        temp_f0_655 = temp_r28_710->unk10 * (f64) gUpdateTimeDelta;
        sp40 = temp_f0_655;
        spA0 = temp_f0_655;
        sp48 = M2C_FIELD(temp_r28_710, f32 *, 0x18) * gUpdateTimeDelta;
        spA8 = (f64) sp48;
        temp_r28_710->unk0 += temp_f0_655;
        M2C_FIELD(temp_r28_710, f32 *, 8) = (f32) (M2C_FIELD(temp_r28_710, f32 *, 8) + (f32) spA8);
        temp_f26_675 = gUpdateTimeDelta;
        sp80 = ((MKVector3 *) &temp_r28_710->unk10)->operator*(0.1f);
        temp_f0_678 = sp80 * (f64) temp_f26_675;
        sp30 = temp_f0_678;
        sp90 = temp_f0_678;
        sp38 = sp80.unk8 * temp_f26_675;
        sp98 = (f64) sp38;
        temp_r28_710->unk10 -= temp_f0_678;
        M2C_FIELD(temp_r28_710, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_710, f32 *, 0x18) - (f32) sp98);
        sp20 = Min(*((MKVector3 *) temp_r28_710), *((MKVector3 *) &this->unkE0));
        sp70 = Max(sp20, this->unkD0);
        var_r27_429 += 4;
        *(MKVector3 *) &temp_r28_710->unk0 = sp70;
        goto loop_30;
    }
}
#endif

void SwarmProp::Reset() {
    KDProp::Reset();
}

f32 SwarmProp::Resolve() {
    MKProp::Resolve();
}

extern "C" void *malloc(u32);
MKVector3 KDRand_Vector(const MKVector3 &, const MKVector3 &);
s32 SwarmProp::LoadDone() {
    f64 temp_f29;
    f64 temp_f30;
    MKVector3 sp28;
    SwarmEntity **head;
    SwarmEntity **walk;
    SwarmEntity **end;
    SwarmEntity **base;
    SwarmEntity **cur;
    SwarmEntity *entity;
    u32 walkValue;
    s32 n;
    s32 i;
    s32 count;
    s32 spawned;
    s32 ctr;

    KDProp::LoadDone();
    M2C_STRUCT_COPY(&this->unk90, &Matrix::identity, 0x40);
    this->unk90.Translate(&this->unk90, *((MKVector3 *) &MKProp::loadInfo.unk40));
    M2C_FIELD(this, Matrix **, 0x8) = &this->unk90;
    M2C_FIELD(this, f32 *, 0xD0) = -500.0f;
    M2C_FIELD(this, f32 *, 0xD4) = -500.0f;
    M2C_FIELD(this, f32 *, 0xD8) = -500.0f;
    M2C_FIELD(this, f32 *, 0xE0) = 500.0f;
    M2C_FIELD(this, f32 *, 0xE4) = 500.0f;
    M2C_FIELD(this, f32 *, 0xE8) = 500.0f;
    n = this->unkF0;
    if (n == 0) {
        this->unkF4 = (SwarmEntity **) ((u8 *) &gEmptyPtrListDL + 4);
    } else {
        if (MKHeap::Current() != NULL) {
            base = (SwarmEntity **) (((MKHeap *) (MKHeap::Current()))->Alloc(((n + 2) * 4) + (n << 6), NULL, 0));
        } else {
            base = (SwarmEntity **) malloc(((n + 2) * 4) + (n << 6));
        }
        this->unkF4 = base;
        cur = this->unkF4;
        this->unkF4 = (SwarmEntity **) ((u8 *) cur + (n << 6));
        *this->unkF4 = NULL;
        ctr = n;
        if (n > 0) {
            do {
                this->unkF4 += 1;
                *this->unkF4 = (SwarmEntity *) cur;
                cur = (SwarmEntity **) ((u8 *) cur + 0x40);
                ctr -= 1;
            } while (ctr != 0);
        }
        this->unkF4 += 1;
        *this->unkF4 = NULL;
    }
    temp_f29 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    spawned = 0;
    temp_f30 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
loop_12:
    head = this->unkF4;
    walk = head;
    do {
        walkValue = M2C_FIELD(walk, u32 *, -4);
        walk -= 1;
    } while (walkValue != 0U);
    end = head;
    while (*end != NULL) {
        end += 1;
    }
    count = (s32) (head - walk) + (s32) (end - head) - 1;
    if (spawned < count) {
        this->unkF4 -= 1;
        entity = *this->unkF4;
        entity->unk0 = temp_f29;
        entity->unk8 = temp_f30;
        entity->unk10 = temp_f29;
        entity->unk18 = temp_f30;
        entity->unk20 = temp_f29;
        entity->unk28 = temp_f30;
        entity->unk30 = 0.0f;
        for (i = 0; i < 3; i++) {
            M2C_FIELD(entity, s32 *, 0x34 + (i * 4)) = 0;
        }
        sp28 = KDRand_Vector(this->unkD0, *((MKVector3 *) &this->unkE0));
        spawned += 1;
        *(MKVector3 *) &entity->unk0 = sp28;
        goto loop_12;
    }
}

s32 SwarmProp::LoadLine(MKIniLine *arg0) {
    if (KDProp::LoadLine(arg0) != 0) {
        return 1;
    }
    return arg0->LoadInt("EntityCount", (int *) &this->unkF0, 0);
}

extern "C" void free(void *);
void SwarmProp::Deinit() {
    SwarmEntity **head;
    SwarmEntity **walk;
    SwarmEntity **cur;
    SwarmEntity *entity;
    void *min;

    head = this->unkF4;
    min = head;
    walk = head;
    walk -= 1;
    while (*walk != NULL) {
        entity = *walk;
        if ((void *) entity < min) {
            min = entity;
        }
        walk -= 1;
    }
    if (walk != (SwarmEntity **) &gEmptyPtrListDL) {
        cur = head;
        while (*cur != NULL) {
            entity = *cur;
            if ((void *) entity < min) {
                min = entity;
            }
            cur += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(min, NULL, 0);
        } else {
            free(min);
        }
    }
    this->unkF4 = NULL;
    KDProp::Deinit();
}

void SwarmProp::Init() {
    KDProp::Init();
    this->unkF0 = 5;
    this->unkC = (BoundingVolume *) &this->unkD0;
}
