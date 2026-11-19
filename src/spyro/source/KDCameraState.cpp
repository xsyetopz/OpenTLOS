#include "spyro/source/KDCameraState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "spyro/source/KDCamera.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void KDCameraStateStack::StateUpdate() {
    KDCamera *temp_r3_16;
    KDCamera *temp_r3_37;

    temp_r3_16 = this->unk14;
    temp_r3_16->PreStateUpdate();
    GetDescriptorAtIndex(this->unk10);
    if (__ptmf_test(M2C_ERROR(/* Read from unset register $r3 */) + 0x2C) != 0) {
        GetDescriptorAtIndex(this->unk10);
        __ptmf_scall(this->unk14, M2C_ERROR(/* Read from unset register $r3 */));
    }
    temp_r3_37 = this->unk14;
    temp_r3_37->PostStateUpdate();
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void KDCameraStateStack::StateExit() {
    KDCamera *temp_r3_57;
    KDCamera *temp_r3_78;

    temp_r3_57 = this->unk14;
    temp_r3_57->PreStateExit();
    GetDescriptorAtIndex(this->unk10);
    if (__ptmf_test(M2C_ERROR(/* Read from unset register $r3 */) + 0x20) != 0) {
        GetDescriptorAtIndex(this->unk10);
        __ptmf_scall(this->unk14, M2C_ERROR(/* Read from unset register $r3 */));
    }
    temp_r3_78 = this->unk14;
    temp_r3_78->PostStateExit();
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void KDCameraStateStack::StateEnter() {
    KDCamera *temp_r3_119;
    KDCamera *temp_r3_98;

    temp_r3_98 = this->unk14;
    temp_r3_98->PreStateEnter();
    GetDescriptorAtIndex(this->unk10);
    if (__ptmf_test(M2C_ERROR(/* Read from unset register $r3 */) + 0x14) != 0) {
        GetDescriptorAtIndex(this->unk10);
        __ptmf_scall(this->unk14, M2C_ERROR(/* Read from unset register $r3 */));
    }
    temp_r3_119 = this->unk14;
    temp_r3_119->PostStateEnter();
}
#endif

#if 0 // DRAFT: illegal type
void *KDCameraStateStack::GetDescriptor(int arg0) {
    s32 temp_r0_134;
    s32 var_ctr_136;
    s32 var_r5_135;
    void *temp_r6_141;

    temp_r0_134 = this->unk1C;
    var_r5_135 = 0;
    var_ctr_136 = temp_r0_134;
    if (temp_r0_134 > 0) {
loop_1:
        temp_r6_141 = this->unk18 + var_r5_135;
        if (arg0 == (s32) M2C_FIELD(temp_r6_141, s32 *, 4)) {
            return temp_r6_141;
        }
        var_r5_135 += 0x40;
        var_ctr_136 -= 1;
        if (var_ctr_136 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDCameraStateStack' to
void KDCameraStateStack::GetDescriptorAtIndex(int arg0) {
    GetDescriptor(M2C_FIELD(*(this + (arg0 * 4)), s32 *, 4));
}
#endif

void KDCameraStateStack::GetObjectAtIndex(int arg0) {

}

#if 0 // DRAFT: illegal operand
void KDCameraStateStack::Object::ClearData() {
    *this = 0;
}
#endif

#if 0 // DRAFT: illegal type
s32 KDCameraStateStack::IsStateMessage(MKMessage *arg0) {
    s32 temp_r0_190;
    s32 temp_r5_191;
    s32 var_ctr_193;
    s32 var_r4_192;
    void *temp_r6_198;

    temp_r0_190 = this->unk1C;
    temp_r5_191 = arg0->unk0;
    var_r4_192 = 0;
    var_ctr_193 = temp_r0_190;
    if (temp_r0_190 > 0) {
loop_1:
        temp_r6_198 = this->unk18 + var_r4_192;
        if (((s32) M2C_FIELD(temp_r6_198, s32 *, 0x38) == temp_r5_191) || ((s32) M2C_FIELD(temp_r6_198, s32 *, 0x3C) == temp_r5_191)) {
            return 1;
        }
        var_r4_192 += 0x40;
        var_ctr_193 -= 1;
        if (var_ctr_193 == 0) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
s32 KDCameraStateStack::HandleStateMessage(int arg0) {
    s32 temp_r0_223;
    s32 var_ctr_224;
    s32 var_r5_221;
    void *temp_r6_229;

    var_r5_221 = 0;
    temp_r0_223 = this->unk1C;
    var_ctr_224 = temp_r0_223;
    if (temp_r0_223 > 0) {
loop_1:
        temp_r6_229 = this->unk18 + var_r5_221;
        if ((s32) M2C_FIELD(temp_r6_229, s32 *, 0x38) == arg0) {
            Push(M2C_FIELD(temp_r6_229, s32 *, 4));
            return 1;
        }
        if ((s32) M2C_FIELD(temp_r6_229, s32 *, 0x3C) == arg0) {
            Pop(M2C_FIELD(temp_r6_229, s32 *, 4));
            return 1;
        }
        var_r5_221 += 0x40;
        var_ctr_224 -= 1;
        if (var_ctr_224 == 0) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void *KDCameraStateStack::PopObjectOffStack() {
    void *sp8;

    GetObjectAtIndex(this->unk10);
    sp8 = *M2C_ERROR(/* Read from unset register $r3 */);
    StateExit();
    GetObjectAtIndex(this->unk10);
    ((KDCameraStateStack::Object *) (M2C_ERROR(/* Read from unset register $r3 */)))->ClearData();
    this->unk10 -= 1;
    return sp8;
}
#endif

s32 KDCameraStateStack::Pop(int arg0) {
    s32 var_r30_311;
    s32 var_r31_295;

    var_r31_295 = -1;
    GetDescriptorAtIndex(this->unk10);
    if (arg0 == (s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4)) {
        GetDescriptorAtIndex(this->unk10);
        var_r31_295 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4);
        GetDescriptorAtIndex(this->unk10);
        if (M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 1) {
            var_r30_311 = this->unk10;
loop_5:
            if (var_r30_311 < 0) {

            } else {
                GetDescriptorAtIndex(var_r30_311);
                if (!(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 2)) {
                    PopObjectOffStack();
                    var_r30_311 -= 1;
                    goto loop_5;
                }
            }
        } else {
            PopObjectOffStack();
        }
    }
    GetDescriptorAtIndex(this->unk10);
    if (M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 4) {
        StateEnter();
    }
    return var_r31_295;
}

#if 0 // DRAFT: pointer/array required
void KDCameraStateStack::Push(int arg0) {
    s32 temp_r4_357;

    temp_r4_357 = this->unk10;
    if ((temp_r4_357 + 1) != 0) {
        GetDescriptorAtIndex(temp_r4_357);
        if (M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) & 8) {
            StateExit();
        }
    }
    this->unk10 += 1;
    GetObjectAtIndex(this->unk10);
    *M2C_ERROR(/* Read from unset register $r3 */) = GetDescriptor(arg0);
    StateEnter();
}
#endif

void KDCameraStateStack::Update() {
    StateUpdate();
}

void KDCameraStateStack::Reset() {
    s32 var_r31_408;

    var_r31_408 = 0;
    do {
        GetObjectAtIndex(var_r31_408);
        ((KDCameraStateStack::Object *) (M2C_ERROR(/* Read from unset register $r3 */)))->ClearData();
        var_r31_408 += 1;
    } while (var_r31_408 < 4);
    this->unk10 = -1;
}

void KDCameraStateStack::Deinit() {

}

void KDCameraStateStack::Init(KDCamera *arg0, KDCameraStateDescriptor *arg1, int arg2) {
    this->unk14 = arg0;
    this->unk18 = arg1;
    this->unk1C = arg2;
    Reset();
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
KDCameraStateStack::KDCameraStateStack() {
    this->unk18 = NULL;
    this->unk1C = -1;
    this->unk10 = -1;
    return this;
}
#endif
