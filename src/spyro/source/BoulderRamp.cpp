#include "spyro/source/BoulderRamp.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Ball.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Trap.h"
#include "unplaced_templates.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: illegal use of abstract class ('Trap::pure_slot16()')
static M2C_UNK lit_631;                                /* unable to generate initializer: unknown type */
static BoulderRamp states__11BoulderRamp;           /* type too large by 0xF8; unable to generate initializer: not enough data */
static struct _struct_boulderRampGroups_0x18 boulderRampGroups[8];
#endif

#if 0 // DRAFT: expression syntax error
static s8 lit_stringBase0[0x36] = {
    0x4F,
    0x6E,
    0x53,
    0x65,
    0x74,
    0,
    0x67,
    0x72,
    0x6F,
    0x75,
    0x70,
    0,
    0x62,
    0x61,
    0x6C,
    0x6C,
    0x4A,
    0x75,
    0x6D,
    0x70,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
    0x62,
    0x61,
    0x6C,
    0x6C,
    0x53,
    0x69,
    0x6E,
    0x6B,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
    0x62,
    0x61,
    0x6C,
    0x6C,
    0x53,
    0x74,
    0x6F,
    0x70,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
}; /* const */

void BoulderRamp::BoulderSinkingExit() {
    this->unkF4.unk10.Send((MKProp *) this);
    ((Ball *) (M2C_BITWISE(Ball *, this->unkEC)))->SetState((Ball::State) 6);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void BoulderRamp::BoulderSinkingUpdate() {
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    MKVector3 *temp_r31_154;
    f32 temp_r3_126;
    f32 var_f1_88;
    s32 temp_r0_76;
    u32 temp_r5_79;
    void *temp_r6_78;

    temp_r0_76 = this->unkE0;
    temp_r6_78 = M2C_FIELD(this->unkEC, void **, 8);
    temp_r5_79 = (u32) temp_r0_76 >> 0x1FU;
    sp68 = M2C_FIELD(temp_r6_78, f64 *, 0x30);
    sp70 = M2C_FIELD(temp_r6_78, f64 *, 0x38);
    if ((((temp_r0_76 & 1) ^ temp_r5_79) - temp_r5_79) != 0) {
        var_f1_88 = 120.00001f;
    } else {
        var_f1_88 = -120.00001f;
    }
    sp18.operator*(var_f1_88);
    sp28.operator*(gUpdateTimeDelta);
    sp38.operator*(44.444447f);
    sp48.operator*(gUpdateTimeDelta);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp58 = sp8;
    sp10 = sp48.unk8 + sp28.unk8;
    sp60 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_r3_126 = this->unkEC;
    M2C_FIELD(temp_r3_126, f64 *, 0xE0) = sp68;
    sp70 = (f32) sp70 - (f32) sp60;
    M2C_FIELD(temp_r3_126, f64 *, 0xE8) = (f64) sp70;
    this->unkE0 += 1;
    this->unkE8 -= gUpdateTimeDelta;
    if (this->unkE8 < 0.0f) {
        SetState((BoulderRamp::State) 3);
        if ((s32) M2C_FIELD(checked_cast<BoulderRampDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC) != 0) {
            temp_r31_154 = this->unk8 + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<BoulderRampDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC), temp_r31_154, 0U, -1, 0.0f, 0U);
        }
    }
}
#endif

void BoulderRamp::BoulderSinkingEnter() {
    this->unkE8 = 1.8f;
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void BoulderRamp::ReceivingBoulderUpdate() {
    f64 sp68;
    KDUniformSpline sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    f32 sp18;
    f32 sp8;
    MKVector3 *temp_r31_253;
    f32 temp_f0_191;
    f32 temp_r31_199;
    f32 temp_r3_231;
    f32 var_f3_190;

    var_f3_190 = 1.0f;
    temp_f0_191 = (2.0f * gUpdateTimeDelta) + M2C_BITWISE(f32, this->unkE4);
    if (var_f3_190 < temp_f0_191) {

    } else {
        var_f3_190 = temp_f0_191;
    }
    this->unkE4 = var_f3_190;
    temp_r31_199 = this->unkEC;
    if (M2C_BITWISE(u32, temp_r31_199) != 0U) {
        sp20.operator*(M2C_FIELD(temp_r31_199, f32 *, 0x274));
        sp30.operator*(M2C_FIELD(temp_r31_199, f32 *, 0x280));
        sp40.operator*(0.5f);
        sp8 = 0.0f;
        sp50.GetMeasure(M2C_BITWISE(f32, this->unkE4), (Matrix *) &this->unkF0, KDSpline_PositionMixer);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_231 = this->unkEC;
        sp50.unk10 = sp10;
        sp18 = sp50.unk8 + sp40.unk8;
        M2C_FIELD(temp_r3_231, f64 *, 0xE0) = sp10;
        sp68 = (f64) sp18;
        M2C_FIELD(temp_r3_231, f64 *, 0xE8) = (f64) sp18;
    }
    if (M2C_BITWISE(f32, this->unkE4) == 1.0f) {
        SetState((BoulderRamp::State) 2);
        if ((s32) M2C_FIELD(checked_cast<BoulderRampDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8) != 0) {
            temp_r31_253 = this->unk8 + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<BoulderRampDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8), temp_r31_253, 0U, -1, 0.0f, 0U);
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void BoulderRamp::ReceivingBoulderEnter() {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
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
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    void *temp_r3_291;
    void *temp_r4_282;

    temp_r4_282 = M2C_FIELD(this->unkEC, void **, 8);
    spD8 = M2C_FIELD(temp_r4_282, f64 *, 0x30);
    spE0 = M2C_FIELD(temp_r4_282, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f3 */);
    temp_r3_291 = this->unk8;
    sp60 = up.unk8 * 80.0f;
    sp98 = sp58;
    spA8 = M2C_FIELD(temp_r3_291, f64 *, 0x30);
    spA0 = (f64) sp60;
    spB0 = M2C_FIELD(temp_r3_291, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 100.0f;
    sp50 = (f32) spB0 + (f32) spA0;
    spC8 = sp48;
    spD0 = (f64) sp50;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
    sp78 = sp38;
    sp40 = (f32) spE0 + (f32) spD0;
    sp80 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
    sp88 = sp28;
    sp30 = (f32) sp80 * 0.5f;
    sp90 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spB8 = sp8;
    sp10 = (f32) sp90 + (f32) sp70;
    spC0 = (f64) sp10;
    this->unkF4.unk4 = 0.0f;
    this->unkF4.unk0 = 0.0f;
    this->unkF0.AddNode(*((MKVector3 *) &spD8));
    this->unkF0.AddNode(*((MKVector3 *) &spB8));
    this->unkF0.AddNode(*((MKVector3 *) &spC8));
    this->unkE4 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Ball *' to
void BoulderRamp::SetBoulder(Ball *arg0) {
    MKVector3 *temp_r31_397;

    this->unkEC = M2C_BITWISE(f32, arg0);
    SetState((BoulderRamp::State) 1);
    if ((s32) M2C_FIELD(checked_cast<BoulderRampDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4) != 0) {
        temp_r31_397 = this->unk8 + 0x30;
        KDSound_Play3d(M2C_FIELD(checked_cast<BoulderRampDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), temp_r31_397, 0U, -1, 0.0f, 0U);
    }
}
#endif

s32 BoulderRamp::HasBoulder() {
    return M2C_BITWISE(s32, this->unkEC) != 0;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'BoulderRamp::State'
void BoulderRamp::SetState(BoulderRamp::State arg1) {
    this->unkF4.unk14.SetState(this, (s32) arg1, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
void BoulderRamp::Update() {
    this->unkF4.unk14.Update(this, 0);
    GameProp::Update();
}
#endif

void BoulderRamp::Reset() {
    this->unkE0 = 0;
    this->unkE4 = 0.0f;
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF4.unk4 = 0.0f;
    this->unkF4.unk0 = 0.0f;
    Trap::Reset();
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void BoulderRamp::LoadDone() {
    s32 var_ctr_492;
    s32 var_r4_491;
    struct _struct_boulderRampGroups_0x18 *temp_r5_496;

    var_r4_491 = 0;
    var_ctr_492 = 6;
loop_1:
    temp_r5_496 = &boulderRampGroups[this->unkE0];
    if ((u32) *(temp_r5_496 + var_r4_491) == 0U) {
        *(temp_r5_496 + var_r4_491) = this;
    } else {
        var_r4_491 += 4;
        var_ctr_492 -= 1;
        if (var_ctr_492 != 0) {
            goto loop_1;
        }
    }
    Trap::LoadDone();
}
#endif

#if 0 // DRAFT: expression syntax error
s32 BoulderRamp::LoadLine(MKIniLine *arg0) {
    if ((Trap::LoadLine(arg0) != 0) || (this->unkF4.unk10.LoadLine(arg0, lit_stringBase0) != 0)) {
        return 1;
    }
    if (arg0->IsField(&lit_stringBase0[6]) != 0) {
        this->unkE0 = (s32) arg0->GetInt(0);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void BoulderRamp::Deinit() {
    s32 var_ctr_582;
    s32 var_r3_577;
    struct _struct_boulderRampGroups_0x18 *temp_r5_586;

    this->unkF0.Deinit();
    this->unkF4.unk10.Deinit();
    this->unkF4.unk14.Deinit();
    if ((s32) this->unkE0 < 0xFF) {
        var_r3_577 = 0;
        var_ctr_582 = 6;
        do {
            temp_r5_586 = &boulderRampGroups[this->unkE0];
            if ((u32) *(temp_r5_586 + var_r3_577) == this) {
                *(temp_r5_586 + var_r3_577) = 0;
            }
            var_r3_577 += 4;
            var_ctr_582 -= 1;
        } while (var_ctr_582 != 0);
    }
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void BoulderRamp::Init() {
    this->unkE0 = 0xFF;
    this->unkE0 = 0;
    this->unkE4 = 0.0f;
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF0.Init(3, 0U);
    this->unkF4.unk10.Init();
    Init__29KDStateMachine<11BoulderRamp>FPQ229KDStateMachine<11BoulderRamp>5StateP29KDStateMachine<11BoulderRamp>((KDStateMachine<BoulderRamp> *) &this->unkF4.unk14, (KDStateMachine<BoulderRamp>::State *) &states, NULL);
    Trap::Init();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void BoulderRampDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 BoulderRampDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_662;

    var_r31_662 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0xC], &this->unkE4) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0x1A], &this->unkE8) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0x28], &this->unkEC) != 0)) {
        var_r31_662 = 1;
    }
    return var_r31_662;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void BoulderRampDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkE4 = GS_PLACEHOLDER;
    this->unkE8 = GS_PLACEHOLDER;
    this->unkEC = GS_PLACEHOLDER;
}
#endif

#if 0 // DRAFT: undefined identifier 'boulderRampGroups'
s32 BoulderRamp_GetCatapult(int arg0, int arg1) {
    return *(&boulderRampGroups[arg0] + (arg1 * 4));
}
#endif

s32 BoulderRamp_GetMaxPerGroup() {
    return 6;
}

#if 0 // DRAFT: undefined identifier 'boulderRampGroups'
void BoulderRamp_InitModule() {
    memset(boulderRampGroups, 0, 0xC0U);
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<BoulderRampDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

#if 0 // DRAFT: undefined identifier 'lit_631'
void BoulderRamp_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r27_950;

    temp_r27_950 = &lit_631 + 0x3C;
    M2C_FIELD(&lit_631, s32 *, 0x3C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_631, s32 *, 0x40) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_631, s32 *, 0x44) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_950, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_950, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_950, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_950, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_950, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_950, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_950, s32 *, 0x24) = (s32) M2C_FIELD(&lit_631, s32 *, 0);
    M2C_FIELD(temp_r27_950, s32 *, 0x28) = (s32) M2C_FIELD(&lit_631, s32 *, 4);
    M2C_FIELD(temp_r27_950, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_631, s32 *, 8);
    M2C_FIELD(temp_r27_950, s32 *, 0x30) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_950, s32 *, 0x34) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_950, s32 *, 0x38) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_950, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_631, s32 *, 0xC);
    M2C_FIELD(temp_r27_950, s32 *, 0x40) = (s32) M2C_FIELD(&lit_631, s32 *, 0x10);
    M2C_FIELD(temp_r27_950, s32 *, 0x44) = (s32) M2C_FIELD(&lit_631, s32 *, 0x14);
    M2C_FIELD(temp_r27_950, s32 *, 0x48) = (s32) M2C_FIELD(&lit_631, s32 *, 0x18);
    M2C_FIELD(temp_r27_950, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_631, s32 *, 0x1C);
    M2C_FIELD(temp_r27_950, s32 *, 0x50) = (s32) M2C_FIELD(&lit_631, s32 *, 0x20);
    M2C_FIELD(temp_r27_950, s32 *, 0x54) = (s32) M2C_FIELD(&lit_631, s32 *, 0x24);
    M2C_FIELD(temp_r27_950, s32 *, 0x58) = (s32) M2C_FIELD(&lit_631, s32 *, 0x28);
    M2C_FIELD(temp_r27_950, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_631, s32 *, 0x2C);
    M2C_FIELD(temp_r27_950, s32 *, 0x60) = (s32) M2C_FIELD(&lit_631, s32 *, 0x30);
    M2C_FIELD(temp_r27_950, s32 *, 0x64) = (s32) M2C_FIELD(&lit_631, s32 *, 0x34);
    M2C_FIELD(temp_r27_950, s32 *, 0x68) = (s32) M2C_FIELD(&lit_631, s32 *, 0x38);
    M2C_FIELD(temp_r27_950, s32 *, 0x6C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_950, s32 *, 0x70) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_950, s32 *, 0x74) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_950, s32 *, 0x78) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_950, s32 *, 0x7C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_950, s32 *, 0x80) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_950, s32 *, 0x84) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_950, s32 *, 0x88) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_950, s32 *, 0x8C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
}
#endif
