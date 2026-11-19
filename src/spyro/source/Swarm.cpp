#include "spyro/source/Swarm.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
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

#if 0 // DRAFT: undefined identifier 'unk70'
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
    this->unk90 = MKMaterial_Create("fx_013");
}
#endif

void SwarmProp::Message(MKMessage *arg0) {
    KDProp::Message(arg0);
}

#if 0 // DRAFT: undefined identifier 'arg_sp128'
void SwarmProp::DrawEntity(SwarmEntity *arg0, const Matrix &arg1, const MKVector4 &arg2, float arg3) {
    f32 temp_f0_106;
    f32 temp_f1_108;
    f32 temp_f2_109;
    f32 temp_f4_152;
    f32 temp_f6_193;
    f32 temp_f7_195;
    f32 temp_f8_188;
    f32 temp_f9_132;
    arg_sp128 = 0.0f;
    arg_sp118 = 0.0f;
    arg_sp120 = 0.0f;
    arg_sp124 = 1.0f;
    arg_sp110 = 1.0f;
    arg_sp114 = 0.0f;
    arg_sp200 = (f64) arg_sp120;
    arg_sp208 = (f64) arg_sp128;
    arg_sp1F0 = (f64) arg_sp110;
    arg_sp1F8 = (f64) arg_sp118;
    M2C_STRUCT_COPY((s32) &arg_sp28C + 4, (s32) (&lit_620 - 4) + 4, 0x40);
    temp_f0_106 = -(f32) arg_sp1F0;
    temp_f1_108 = -arg_sp1F4;
    temp_f2_109 = -(f32) arg_sp1F8;
    arg_spF0 = temp_f0_106;
    arg_spF4 = temp_f1_108;
    arg_spF8 = temp_f2_109;
    arg_sp1E0 = (f64) arg_spF0;
    arg_sp1E8 = (f64) arg_spF8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f3, $f3, $f5 */);
    arg_sp1D0 = arg_spE0;
    arg_spE8 = (f32) arg_sp1E8 * arg3;
    arg_sp1D8 = (f64) arg_spE8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f3, $f3, $f5 */);
    temp_f9_132 = (f32) arg_sp208 * arg3;
    arg_sp1C0 = arg_sp100;
    arg_sp108 = temp_f9_132;
    arg_sp1C8 = (f64) arg_sp108;
    M2C_ERROR(/* unknown instruction: ps_add $f4, $f6, $f4 */);
    arg_sp290 = arg_spD0;
    arg_spD8 = (f32) arg_sp1C8 + (f32) arg_sp1D8;
    arg_sp298 = (f64) arg_spD8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f4, $f4, $f5 */);
    temp_f4_152 = (f32) arg_sp1F8 * arg3;
    arg_spB8 = temp_f4_152;
    arg_sp1B0 = arg_spB0;
    arg_sp1B8 = (f64) arg_spB8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f6, $f6, $f5 */);
    arg_spC8 = temp_f9_132;
    arg_sp1A0 = arg_spC0;
    arg_sp1A8 = (f64) arg_spC8;
    M2C_ERROR(/* unknown instruction: ps_add $f6, $f7, $f6 */);
    arg_sp78 = temp_f2_109;
    arg_sp70 = temp_f0_106;
    arg_sp74 = temp_f1_108;
    arg_spA8 = (f32) arg_sp1A8 + (f32) arg_sp1B8;
    arg_sp190 = (f64) arg_sp70;
    arg_sp2A0 = arg_spA0;
    arg_sp2A8 = (f64) arg_spA8;
    arg_sp198 = (f64) arg_sp78;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f5 */);
    temp_f8_188 = -(f32) arg_sp208;
    temp_f6_193 = -(f32) arg_sp200;
    arg_sp98 = temp_f8_188;
    temp_f7_195 = -arg_sp204;
    arg_sp68 = (f32) arg_sp198 * arg3;
    arg_sp90 = temp_f6_193;
    arg_sp94 = temp_f7_195;
    arg_sp180 = arg_sp60;
    arg_sp188 = (f64) arg_sp68;
    arg_sp170 = (f64) arg_sp90;
    arg_sp178 = (f64) arg_sp98;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f5 */);
    arg_sp160 = arg_sp80;
    arg_sp88 = (f32) arg_sp178 * arg3;
    arg_sp168 = (f64) arg_sp88;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp2B0 = arg_sp50;
    arg_sp58 = (f32) arg_sp168 + (f32) arg_sp188;
    arg_sp2B8 = (f64) arg_sp58;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f5 */);
    arg_sp28 = temp_f4_152;
    arg_sp48 = temp_f8_188;
    arg_sp40 = temp_f6_193;
    arg_sp44 = temp_f7_195;
    arg_sp150 = arg_sp20;
    arg_sp140 = (f64) arg_sp40;
    arg_sp158 = (f64) arg_sp28;
    arg_sp148 = (f64) arg_sp48;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f5 */);
    arg_sp130 = arg_sp30;
    arg_sp38 = (f32) arg_sp148 * arg3;
    arg_sp138 = (f64) arg_sp38;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp2C0 = arg_sp10;
    arg_sp18 = (f32) arg_sp138 + (f32) arg_sp158;
    arg_sp2C8 = (f64) arg_sp18;
    M2C_STRUCT_COPY((s32) &arg_sp24C + 4, (s32) (&arg1 - 4) + 4, 0x40);
    arg_sp210.SetIdentity();
    arg_sp210.RotateRoll((Matrix *) &arg_sp210, 0.0f);
    arg_sp250.Multiply3x3((Matrix *) &arg_sp210, (Matrix *) &arg_sp250);
    arg_sp250.Translate((Matrix *) &arg_sp250, *((MKVector3 *) arg0));
    MKSetMatrix(*((Matrix *) &arg_sp250));
    MKBegin(4);
    MKSetColorV(arg2);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp290));
    MKSetColorV(arg2);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp2A0));
    MKSetColorV(arg2);
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp2B0));
    MKSetColorV(arg2);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &arg_sp2C0));
    MKEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp6C'
void SwarmProp::Draw() {
    SwarmEntity **var_r31_386;
    SwarmEntity *temp_r4_396;
    KDProp::Draw();
    M2C_STRUCT_COPY((s32) &arg_sp6C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) &this->unk8C + 4, 0x40);
    arg_sp30.Multiply3x3((Matrix *) &arg_sp30, (Matrix *) &arg_sp70);
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<SwarmPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x90));
    arg_sp10 = 0.8f;
    arg_sp14 = 0.8f;
    arg_sp18 = 0.0f;
    arg_sp1C = 1.0f;
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    MKPrimitive(0xC, 0);
    var_r31_386 = this->unkF4;
loop_2:
    temp_r4_396 = *var_r31_386;
    if (temp_r4_396 != NULL) {
        DrawEntity(temp_r4_396, *((Matrix *) &arg_sp30), *((MKVector4 *) &arg_sp20), 10.0f);
        var_r31_386 += 4;
        goto loop_2;
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SwarmProp::Update() {
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
    f32 sp58;
    f32 sp48;
    f32 sp38;
    MKVector3 sp20;
    f32 sp18;
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
    f64 temp_f1_553;
    f64 temp_f1_559;
    f64 temp_f1_563;
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
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_r28_710->unk30 == 0.0f) {
            temp_r28_710->unk30 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
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
                *(temp_r28_710 + temp_r0_471) = temp_r24_453[MKRand_Int(&gViewSeed, 0, (s32) (var_r3_454 - temp_r24_453) / 4)];
            } while (var_r23_450 < 3);
        }
        temp_r4_477 = temp_r28_710->unk34;
        var_r3_479 = 4;
        sp110 = M2C_FIELD(temp_r4_477, f64 *, 0);
        sp118 = M2C_FIELD(temp_r4_477, f64 *, 8);
        var_ctr_484 = 2;
        do {
            temp_r4_487 = *(temp_r28_710 + (var_r3_479 + 0x34));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f2, $f1, $f0 */);
            var_r3_479 += 4;
            temp_f0_495 = (f32) sp118 + M2C_FIELD(temp_r4_487, f32 *, 8);
            sp118 = temp_f0_495;
            var_ctr_484 -= 1;
        } while (var_ctr_484 != 0);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f2, $f29 */);
        sp118 = (f32) temp_f0_495 * 0.33333334f;
        spD0.operator*(gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spE0 = sp10;
        sp18 = sp118 - M2C_FIELD(temp_r28_710, f32 *, 8);
        spE8 = (f64) sp18;
        KDMath_Smooth<MKVector3>(spF0, *((MKVector3 *) &temp_r28_710->unk20), 5.0f, gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        temp_r28_710->unk20 = sp60;
        sp68 = spF0.unk8 - spD0.unk8;
        sp100 = sp60;
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
        spB0.operator*(500.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        spC0 = sp50;
        sp58 = spB0.unk8 * temp_f28_631;
        spC8 = (f64) sp58;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r0, 0x0, qr0 */);
        M2C_FIELD(temp_r28_710, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_710, f32 *, 0x18) + (f32) spC8);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        spA0 = sp40;
        sp48 = M2C_FIELD(temp_r28_710, f32 *, 0x18) * gUpdateTimeDelta;
        spA8 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_FIELD(temp_r28_710, f32 *, 8) = (f32) (M2C_FIELD(temp_r28_710, f32 *, 8) + (f32) spA8);
        temp_f26_675 = gUpdateTimeDelta;
        sp80.operator*(0.1f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
        sp90 = sp30;
        sp38 = sp80.unk8 * temp_f26_675;
        sp98 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r0, 0x0, qr0 */);
        M2C_FIELD(temp_r28_710, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_710, f32 *, 0x18) - (f32) sp98);
        Min(sp20, *((MKVector3 *) temp_r28_710));
        Max(sp70, sp20);
        var_r27_429 += 4;
        temp_r28_710->unk0 = M2C_BITWISE(f64, sp70);
        temp_r28_710->unk8 = (f64) sp70.unk8;
        goto loop_30;
    }
}
#endif

void SwarmProp::Reset() {
    KDProp::Reset();
}

void SwarmProp::Resolve() {
    MKProp::Resolve();
}

#if 0 // DRAFT: undefined identifier 'unk8C'
void SwarmProp::LoadDone() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_902;
    Matrix *temp_r3_867;
    SwarmEntity **temp_r3_925;
    SwarmEntity **temp_r3_932;
    SwarmEntity **temp_r3_939;
    SwarmEntity **temp_r4_955;
    SwarmEntity **temp_r5_982;
    SwarmEntity **var_r3_912;
    SwarmEntity **var_r3_983;
    SwarmEntity **var_r4_988;
    SwarmEntity **var_r5_924;
    SwarmEntity *temp_r29_958;
    f64 temp_f29_946;
    f64 temp_f30_949;
    s32 temp_r0_968;
    s32 temp_r31_890;
    s32 var_ctr_928;
    s32 var_ctr_966;
    s32 var_r31_948;
    s32 var_r3_956;
    u32 temp_r0_985;

    KDProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk8C + 4, (s32) (&identity - 4) + 4, 0x40);
    temp_r3_867 = &this->unk90;
    temp_r3_867->Translate(temp_r3_867, *((MKVector3 *) &loadInfo.unk40));
    sp18 = -500.0f;
    sp1C = -500.0f;
    sp20 = -500.0f;
    this->unk8 = &this->unk90;
    M2C_FIELD(this, f64 *, 0xD0) = (f64) sp18;
    sp10 = 500.0f;
    sp8 = 500.0f;
    spC = 500.0f;
    M2C_FIELD(this, f64 *, 0xD8) = (f64) sp20;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) sp8;
    this->unkE8 = (f64) sp10;
    temp_r31_890 = this->unkF0;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    if (temp_r31_890 == 0) {
        this->unkF4 = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_902 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_902 != NULL) {
            var_r3_912 = ((MKHeap *) (temp_r3_902->Current()))->Alloc(((temp_r31_890 + 2) * 4) + (temp_r31_890 << 6), NULL, 0);
        } else {
            var_r3_912 = malloc(((temp_r31_890 + 2) * 4) + (temp_r31_890 << 6));
        }
        this->unkF4 = var_r3_912;
        var_r5_924 = this->unkF4;
        temp_r3_925 = var_r5_924 + (temp_r31_890 << 6);
        this->unkF4 = temp_r3_925;
        *temp_r3_925 = NULL;
        var_ctr_928 = temp_r31_890;
        if (temp_r31_890 > 0) {
            do {
                temp_r3_932 = this->unkF4;
                this->unkF4 = temp_r3_932 + 4;
                M2C_FIELD(temp_r3_932, SwarmEntity ***, 4) = var_r5_924;
                var_r5_924 += 0x40;
                var_ctr_928 -= 1;
            } while (var_ctr_928 != 0);
        }
        temp_r3_939 = this->unkF4;
        this->unkF4 = temp_r3_939 + 4;
        M2C_FIELD(temp_r3_939, SwarmEntity ***, 4) = NULL;
    }
    temp_f29_946 = M2C_FIELD(&zero, f64 *, 0);
    var_r31_948 = 0;
    temp_f30_949 = M2C_FIELD(&zero, f64 *, 8);
loop_12:
    temp_r5_982 = this->unkF4;
    var_r3_983 = temp_r5_982;
    do {
        temp_r0_985 = M2C_FIELD(var_r3_983, u32 *, -4);
        var_r3_983 -= 4;
    } while (temp_r0_985 != 0U);
    var_r4_988 = temp_r5_982;
loop_16:
    if ((SwarmEntity *) *var_r4_988 != NULL) {
        var_r4_988 += 4;
        goto loop_16;
    }
    if (var_r31_948 < (s32) ((((s32) (temp_r5_982 - var_r3_983) / 4) + ((s32) (var_r4_988 - temp_r5_982) / 4)) - 1)) {
        temp_r4_955 = this->unkF4 - 4;
        var_r3_956 = 0;
        this->unkF4 = temp_r4_955;
        temp_r29_958 = *temp_r4_955;
        temp_r29_958->unk0 = temp_f29_946;
        temp_r29_958->unk8 = temp_f30_949;
        temp_r29_958->unk10 = temp_f29_946;
        temp_r29_958->unk18 = temp_f30_949;
        temp_r29_958->unk20 = temp_f29_946;
        temp_r29_958->unk28 = temp_f30_949;
        temp_r29_958->unk30 = 0.0f;
        var_ctr_966 = 3;
        do {
            temp_r0_968 = var_r3_956 + 0x34;
            var_r3_956 += 4;
            *(temp_r29_958 + temp_r0_968) = 0;
            var_ctr_966 -= 1;
        } while (var_ctr_966 != 0);
        KDRand_Vector(sp28, this->unkD0);
        var_r31_948 += 1;
        temp_r29_958->unk0 = M2C_BITWISE(f64, sp28);
        temp_r29_958->unk8 = (f64) sp28.unk8;
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 SwarmProp::LoadLine(MKIniLine *arg0) {
    if (KDProp::LoadLine(arg0) != 0) {
        return 1;
    }
    return arg0->LoadInt("EntityCount", &this->unkF0, 0);
}
#endif

#if 0 // DRAFT: type mismatch
void SwarmProp::Deinit() {
    MKHeap *temp_r3_1084;
    SwarmEntity **var_r31_1058;
    SwarmEntity **var_r3_1059;
    SwarmEntity **var_r4_1057;
    SwarmEntity *temp_r0_1062;
    SwarmEntity *temp_r0_1081;
    u32 temp_r0_1067;

    var_r4_1057 = this->unkF4;
    var_r31_1058 = var_r4_1057;
    var_r3_1059 = var_r4_1057;
loop_3:
    temp_r0_1067 = M2C_FIELD(var_r3_1059, u32 *, -4);
    var_r3_1059 -= 4;
    if (temp_r0_1067 != 0U) {
        temp_r0_1062 = *var_r3_1059;
        if (temp_r0_1062 < var_r31_1058) {
            var_r31_1058 = (SwarmEntity **) temp_r0_1062;
        }
        goto loop_3;
    }
    if (var_r3_1059 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_1081 = *var_r4_1057;
        if (temp_r0_1081 != NULL) {
            if (temp_r0_1081 < var_r31_1058) {
                var_r31_1058 = (SwarmEntity **) temp_r0_1081;
            }
            var_r4_1057 += 4;
            goto loop_9;
        }
        temp_r3_1084 = var_r3_1059->Current();
        if (temp_r3_1084 != NULL) {
            ((MKHeap *) (temp_r3_1084->Current()))->Free(var_r31_1058, NULL, 0);
        } else {
            free(var_r31_1058);
        }
    }
    this->unkF4 = NULL;
    KDProp::Deinit();
}
#endif

void SwarmProp::Init() {
    KDProp::Init();
    this->unkF0 = 5;
    this->unkC = (BoundingVolume *) &this->unkD0;
}
