#include "spyro/source/PlatformObject.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Platform.h"
#include "spyro/source/SeeSaw.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern void **gMK;
extern f32 gUpdateTimeDelta;

void PlatformObject::GetNumActorsAttached() {
    Platform *temp_r4_16;
    PlatformAttachment *var_r6_11;
    s32 temp_r5_20;

    var_r6_11 = this->unk28.unk8;
loop_6:
    if (var_r6_11 != &this->unk28) {
        temp_r4_16 = var_r6_11->unk0;
        if ((temp_r4_16 != NULL) && ((temp_r5_20 = M2C_FIELD(temp_r4_16->unk0, s32 *, 0xC), (((temp_r5_20 & 8) == 0) == 0)) || (temp_r5_20 & 0x40))) {

        }
        var_r6_11 = var_r6_11->unk8;
        goto loop_6;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void PlatformObject::SimpleMessageAttached(int arg0) {
    s32 spC;
    s32 sp8;
    Platform *temp_r3_48;
    PlatformAttachment *var_r29_45;

    var_r29_45 = this->unk28.unk8;
loop_2:
    if (var_r29_45 != &this->unk28) {
        temp_r3_48 = var_r29_45->unk0;
        spC = 0;
        sp8 = arg0;
        temp_r3_48->Message(&sp8);
        var_r29_45 = var_r29_45->unk8;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void PlatformObject::DetachAll() {
    s32 spC;
    s32 sp8;
    Platform *temp_r3_80;
    PlatformAttachment *temp_r3_89;

loop_2:
    temp_r3_89 = this->unk28.unk8;
    if (temp_r3_89 != &this->unk28) {
        temp_r3_80 = temp_r3_89->unk0;
        spC = 0;
        sp8 = 0x26;
        temp_r3_80->Message(&sp8);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
s8 PlatformObject::Detach(PlatformAttachment *arg0) {
    arg0->unkC->unk8 = arg0->unk8;
    arg0->unk8->unkC = arg0->unkC;
    arg0->unkC = arg0;
    arg0->unk8 = arg0;
    arg0->unk4 = NULL;
    this->unk38 -= 1;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
s8 PlatformObject::Attach(PlatformAttachment *arg0) {
    arg0->unk8 = &this->unk28;
    arg0->unkC = this->unk28.unkC;
    this->unk28.unkC = arg0;
    arg0->unkC->unk8 = arg0;
    arg0->unk4 = this;
    this->unk38 += 1;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
void PlatformObject::UpdateAttached() {
    u8 sp70;
    void *sp6C;
    void *sp68;
    f64 *sp64;
    void *sp60;
    s32 sp5C;
    s32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Platform *temp_r3_228;
    PlatformAttachment *var_r31_165;
    f32 temp_f2_204;
    f32 temp_f3_178;
    f32 temp_f3_201;
    f32 temp_f4_203;
    f32 temp_f5_200;
    f32 temp_f6_185;
    f32 temp_f7_194;
    s32 temp_r6_171;
    s32 var_r29_154;
    u8 temp_r6_218;
    void *temp_r3_145;
    void *temp_r3_172;
    void *temp_r5_177;
    void *temp_r5_219;
    void *temp_r6_176;
    void *temp_r8_174;
    void *temp_r8_217;

    temp_r3_145 = this->unk3C;
    if (temp_r3_145 != NULL) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        var_r29_154 = 0;
        sp48 = sp18;
        sp20 = this->unk10 - M2C_FIELD((temp_r3_145 + 0x40), f32 *, 8);
        sp38 = sp18;
        sp50 = (f64) sp20;
        sp40 = (f64) sp20;
        var_r31_165 = this->unk28.unk8;
loop_3:
        if (var_r31_165 != &this->unk28) {
            temp_r6_171 = var_r29_154 + 0x60;
            temp_r3_172 = this->unk3C;
            temp_r8_174 = this->unk40->unk8;
            temp_r6_176 = temp_r3_172 + temp_r6_171;
            temp_r5_177 = temp_r3_172 + temp_r6_171;
            temp_f3_178 = M2C_FIELD(temp_r6_176, f32 *, 4);
            temp_f6_185 = M2C_FIELD(temp_r6_176, f32 *, 0);
            temp_f7_194 = M2C_FIELD(temp_r6_176, f32 *, 8);
            temp_f5_200 = M2C_FIELD(temp_r8_174, f32 *, 0x30);
            temp_f3_201 = M2C_FIELD(temp_r8_174, f32 *, 0x34);
            temp_f4_203 = temp_f5_200 + ((temp_f7_194 * M2C_FIELD(temp_r8_174, f32 *, 0x20)) + ((temp_f6_185 * M2C_FIELD(temp_r8_174, f32 *, 0)) + (temp_f3_178 * M2C_FIELD(temp_r8_174, f32 *, 0x10))));
            temp_f2_204 = temp_f3_201 + ((temp_f7_194 * M2C_FIELD(temp_r8_174, f32 *, 0x24)) + ((temp_f6_185 * M2C_FIELD(temp_r8_174, f32 *, 4)) + (temp_f3_178 * M2C_FIELD(temp_r8_174, f32 *, 0x14))));
            sp8 = temp_f4_203;
            spC = temp_f2_204;
            sp10 = M2C_FIELD(temp_r8_174, f32 *, 0x38) + ((temp_f7_194 * M2C_FIELD(temp_r8_174, f32 *, 0x28)) + ((temp_f6_185 * M2C_FIELD(temp_r8_174, f32 *, 8)) + (temp_f3_178 * M2C_FIELD(temp_r8_174, f32 *, 0x18))));
            M2C_FIELD(temp_r5_177, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r5_177, f64 *, 8) = (f64) sp10;
            sp5C = 0;
            temp_r8_217 = this->unk3C;
            temp_r6_218 = this->unk0->unk10;
            temp_r5_219 = this->unk40->unk8;
            sp28 = (f64) sp8;
            sp58 = 0x22;
            sp60 = temp_r8_217 + temp_r6_171;
            sp64 = &sp48;
            sp68 = temp_r8_217;
            sp6C = temp_r5_219;
            sp70 = temp_r6_218;
            temp_r3_228 = var_r31_165->unk0;
            sp30 = (f64) sp10;
            temp_r3_228->Message(&sp58, temp_r5_219, temp_r6_218, temp_r6_171, temp_r8_217, (f64) sp8, temp_f2_204, temp_f3_201, temp_f4_203, temp_f5_200, temp_f6_185, temp_f7_194);
            var_r31_165 = var_r31_165->unk8;
            var_r29_154 += 0x10;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spC'
void PlatformObject::UpdateRotationMatrix() {
    if ((u8) this->unk0->unk11 != 0) {
        M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (this->unk40->unk8 - 4) + 4, 0x40);
        arg_sp10.SetRotationPitch(this->unk8);
        arg_sp50.SetRotationRoll(this->unk10);
        arg_sp10.Multiply3x3((Matrix *) &arg_sp10, (Matrix *) &arg_sp50);
        arg_sp50.SetRotationYaw(this->unkC);
        arg_sp10.Multiply3x3((Matrix *) &arg_sp10, (Matrix *) &arg_sp50);
        arg_sp10.Scale3x3((Matrix *) &arg_sp10, this->unk18);
        MKModel_SetWorldMatrix(this->unk40->unk4, *((Matrix *) &arg_sp10));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp1C'
void PlatformObject::UpdateTilt() {
    f64 sp20;                                       /* compiler-managed */
    f64 sp18;
    MKVector3 sp8;
    PlatformObjectDesc *temp_r3_354;
    PlatformObjectDesc *temp_r5_321;
    f32 temp_f0_330;
    f32 temp_f0_334;
    f32 temp_f1_329;
    f32 temp_f1_363;
    f32 temp_f1_377;
    f32 temp_f1_380;
    f32 temp_f1_396;
    f32 temp_f1_399;
    f32 temp_f1_417;
    f32 temp_f1_421;
    f32 temp_f1_437;
    f32 temp_f1_440;
    f32 temp_f3_332;
    f32 temp_f3_367;
    f32 var_f2_389;
    f32 var_f2_430;
    f32 var_f3_410;
    f32 var_f4_370;
    void *temp_r4_326;

    if (((s32) this->unk38 == 0) && (temp_r5_321 = this->unk0, ((temp_r5_321->unk0 > 0.0f) != 0))) {
        temp_r4_326 = this->unk3C;
        if (temp_r4_326 != NULL) {
            temp_f1_329 = M2C_FIELD(temp_r4_326, f32 *, 0x50);
            temp_f0_330 = M2C_FIELD(temp_r4_326, f32 *, 0x54);
            temp_f3_332 = M2C_FIELD(temp_r4_326, f32 *, 0x58);
            temp_f0_334 = temp_r5_321->unk8;
            if (((temp_f3_332 * temp_f3_332) + ((temp_f1_329 * temp_f1_329) + (temp_f0_330 * temp_f0_330))) > (temp_f0_334 * temp_f0_334)) {
                sp18 = (f64) M2C_FIELD(temp_r4_326, f32 *, 0x50);
                sp20 = (f64) M2C_FIELD(temp_r4_326, f32 *, 0x58);
                unksp1C = 0.0f;
                ClampMagnitude(sp8, temp_r5_321->unk4);
                sp18 = M2C_BITWISE(f64, sp8);
                sp20 = (f64) sp8.unk8;
                temp_r3_354 = this->unk0;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                temp_f1_363 = (f32) sp20 * (temp_r3_354->unk0 / temp_r3_354->unk4);
                sp20 = temp_f1_363;
                temp_f3_367 = -temp_f1_363;
                var_f4_370 = 0.5f * (temp_r3_354->unkC * gUpdateTimeDelta);
                if (var_f4_370 < 1.0f) {

                } else {
                    var_f4_370 = 1.0f;
                }
                temp_f1_377 = this->unk8;
                temp_f1_380 = (var_f4_370 * (temp_f3_367 - temp_f1_377)) + temp_f1_377;
                this->unk8 = (var_f4_370 * (temp_f3_367 - temp_f1_380)) + temp_f1_380;
                var_f2_389 = 0.5f * (this->unk0->unkC * gUpdateTimeDelta);
                if (var_f2_389 < 1.0f) {

                } else {
                    var_f2_389 = 1.0f;
                }
                temp_f1_396 = this->unk10;
                temp_f1_399 = (var_f2_389 * ((f32) sp18 - temp_f1_396)) + temp_f1_396;
                this->unk10 = (var_f2_389 * ((f32) sp18 - temp_f1_399)) + temp_f1_399;
                return;
            }
        }
        var_f3_410 = 0.5f * (temp_r5_321->unkC * gUpdateTimeDelta);
        if (var_f3_410 < 1.0f) {

        } else {
            var_f3_410 = 1.0f;
        }
        temp_f1_417 = this->unk8;
        temp_f1_421 = (var_f3_410 * (0.0f - temp_f1_417)) + temp_f1_417;
        this->unk8 = (var_f3_410 * (0.0f - temp_f1_421)) + temp_f1_421;
        var_f2_430 = 0.5f * (this->unk0->unkC * gUpdateTimeDelta);
        if (var_f2_430 < 1.0f) {

        } else {
            var_f2_430 = 1.0f;
        }
        temp_f1_437 = this->unk10;
        temp_f1_440 = (var_f2_430 * (0.0f - temp_f1_437)) + temp_f1_437;
        this->unk10 = (var_f2_430 * (0.0f - temp_f1_440)) + temp_f1_440;
    }
}
#endif

void PlatformObject::EndUpdate() {
    MKHeap *temp_r3_541;
    s32 temp_r31_525;
    void *temp_r31_538;

    UpdateRotationMatrix();
    temp_r31_525 = this->unk4->unkC;
    if ((u32) temp_r31_525 != 0U) {
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->ForceUpdate((u32) temp_r31_525);
    }
    UpdateAttached();
    temp_r31_538 = this->unk3C;
    if (temp_r31_538 != NULL) {
        temp_r3_541 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_541 != NULL) {
            ((MKHeap *) (temp_r3_541->Main()))->TFree(temp_r31_538, NULL, 0);
        } else {
            free(temp_r31_538);
        }
    }
    this->unk3C = NULL;
}

#if 0 // DRAFT: pointer/array required
void PlatformObject::BeginUpdate() {
    MKHeap *temp_r3_581;
    Platform *temp_r3_635;
    PlatformAttachment *var_r27_626;
    f32 temp_f3_643;
    f32 temp_f6_649;
    f32 temp_f7_658;
    s32 temp_r0_576;
    s32 temp_r0_641;
    s32 temp_r29_580;
    s32 temp_r3_579;
    s32 var_r28_616;
    s32 var_r30_618;
    void *temp_r3_613;
    void *temp_r3_622;
    void *temp_r3_645;
    void *temp_r3_678;
    void *temp_r3_681;
    void *temp_r3_703;
    void *var_r3_589;
    temp_r0_576 = this->unk38;
    if (temp_r0_576 != 0) {
        temp_r3_579 = temp_r0_576 * 0x10;
        temp_r29_580 = temp_r3_579 + 0x70;
        temp_r3_581 = temp_r3_579->Current();
        if (temp_r3_581 != NULL) {
            var_r3_589 = ((MKHeap *) (temp_r3_581->Main()))->TAlloc(temp_r29_580, NULL, 0, 0U);
        } else {
            var_r3_589 = malloc(temp_r29_580);
        }
        this->unk3C = var_r3_589;
        arg_sp40.Inverse(MKModel_GetWorldMatrix(this->unk40->unk4));
        M2C_STRUCT_COPY((s32) (this->unk3C - 4) + 4, (s32) &arg_sp3C + 4, 0x40);
        temp_r3_613 = this->unk3C;
        var_r28_616 = 0;
        var_r30_618 = 0;
        M2C_FIELD(temp_r3_613, f64 *, 0x40) = (f64) M2C_FIELD(this, f64 *, 8);
        M2C_FIELD(temp_r3_613, f64 *, 0x48) = (f64) M2C_FIELD(this, f64 *, 0x10);
        temp_r3_622 = this->unk3C;
        M2C_FIELD(temp_r3_622, f32 *, 0x50) = 0.0f;
        M2C_FIELD(temp_r3_622, f32 *, 0x54) = 0.0f;
        M2C_FIELD(temp_r3_622, f32 *, 0x58) = 0.0f;
        var_r27_626 = this->unk28.unk8;
loop_6:
        if (var_r27_626 != &this->unk28) {
            arg_sp34 = 0;
            arg_sp30 = 0x5B;
            arg_sp38 = NULL;
            temp_r3_635 = var_r27_626->unk0;
            temp_r3_635->Message(&arg_sp30);
            temp_r0_641 = var_r30_618 + 0x60;
            temp_f3_643 = M2C_FIELD(arg_sp38, f32 *, 4);
            temp_r3_645 = this->unk3C + temp_r0_641;
            temp_f6_649 = M2C_FIELD(arg_sp38, f32 *, 0);
            temp_f7_658 = M2C_FIELD(arg_sp38, f32 *, 8);
            arg_sp10 = arg_sp70 + ((temp_f7_658 * arg_sp60) + ((temp_f6_649 * arg_sp40) + (temp_f3_643 * arg_sp50)));
            arg_sp14 = arg_sp74 + ((temp_f7_658 * arg_sp64) + ((temp_f6_649 * arg_sp44) + (temp_f3_643 * arg_sp54)));
            arg_sp18 = arg_sp78 + ((temp_f7_658 * arg_sp68) + ((temp_f6_649 * arg_sp48) + (temp_f3_643 * arg_sp58)));
            M2C_FIELD(temp_r3_645, f64 *, 0) = (f64) arg_sp10;
            M2C_FIELD(temp_r3_645, f64 *, 8) = (f64) arg_sp18;
            temp_r3_678 = this->unk3C;
            arg_sp20 = (f64) arg_sp10;
            temp_r3_681 = temp_r3_678 + 0x50;
            arg_sp28 = (f64) arg_sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
            var_r28_616 += 1;
            var_r30_618 += 0x10;
            M2C_FIELD(temp_r3_681, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_681, f32 *, 8) + M2C_FIELD((temp_r3_678 + temp_r0_641), f32 *, 8));
            var_r27_626 = var_r27_626->unk8;
            goto loop_6;
        }
        temp_r3_703 = this->unk3C + 0x50;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_FIELD(temp_r3_703, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_703, f32 *, 8) * (1.0f / (f32) var_r28_616));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'PlatformMoveMsg'
void PlatformObject::Message(MKMessage *arg0) {
    s32 temp_r0_738;
    void *temp_r31_754;
    void *temp_r3_775;
    void *temp_r3_800;
    void *temp_r3_809;
    temp_r0_738 = arg0->unk0;
    switch (temp_r0_738) {                          /* irregular */
    case 34:
        BeginUpdate();
        temp_r31_754 = checked_cast<PlatformMoveMsg *, MKMessage>(arg0);
        M2C_STRUCT_COPY((s32) &arg_sp1C + 4, MKModel_GetWorldMatrix(this->unk40->unk4) - 4 + 4, 0x40);
        arg_sp20.Multiply3x3((Matrix *) &arg_sp20, M2C_FIELD(temp_r31_754, Matrix **, 0x10));
        arg_sp20.Multiply3x3((Matrix *) &arg_sp20, M2C_FIELD(temp_r31_754, Matrix **, 0x14));
        temp_r3_775 = M2C_FIELD(temp_r31_754, void **, 8);
        arg_sp50 = M2C_FIELD(temp_r3_775, f32 *, 0);
        arg_sp54 = M2C_FIELD(temp_r3_775, f32 *, 4);
        arg_sp58 = M2C_FIELD(temp_r3_775, f32 *, 8);
        arg_sp5C = 1.0f;
        MKModel_SetWorldMatrix(this->unk40->unk4, *((Matrix *) &arg_sp20));
        arg_sp10.GetRotationPYR();
        M2C_FIELD(this, f64 *, 8) = arg_sp10;
        M2C_FIELD(this, f64 *, 0x10) = arg_sp18;
        EndUpdate();
        return;
    case 35:
        temp_r3_800 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        M2C_FIELD(temp_r3_800, s8 *, 0xC) = Attach(M2C_FIELD(temp_r3_800, PlatformAttachment **, 8));
        return;
    case 36:
        temp_r3_809 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        M2C_FIELD(temp_r3_809, s8 *, 0xC) = Detach(M2C_FIELD(temp_r3_809, PlatformAttachment **, 8));
        return;
    }
}
#endif

void PlatformObject::Reset() {
    this->unk3C = NULL;
    this->unk8 = 0.0f;
    this->unkC = 0.0f;
    this->unk10 = 0.0f;
}

void PlatformObject::LoadDone(MKProp *arg0, MKVector3 *arg1) {
    this->unk40 = arg0;
    if (arg1 != NULL) {
        M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(arg1, f64 *, 8);
    }
}

void PlatformObject::Deinit() {
    DetachAll();
}

void PlatformObject::Init(PlatformObjectDesc *arg0, MKCollisionInfo *arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    this->unk0 = arg0;
    this->unk4 = arg1;
    this->unk3C = NULL;
    this->unk8 = 0.0f;
    this->unkC = 0.0f;
    this->unk10 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    this->unk38 = 0;
    sp10 = 1.0f;
    sp14 = 0.0f;
    M2C_FIELD(this, f64 *, 0x18) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x20) = (f64) sp10;
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<PlatformMoveMsg *, MKMessage>(MKMessage *arg0) {

}
#endif
