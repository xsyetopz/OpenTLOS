#include "spyro/source/Arrow.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/Trap.h"
#include "common/Source/MKModel.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern GameGlobals gb;

void Arrow::Fire(const Matrix &arg0, float arg1, float arg2) {
    MKModel_SetWorldMatrix(this->unk4, arg0);
    this->unkE0 = arg1;
    this->unkE0 = 0.0f;
    this->unkE4 = arg2;
}

#if 0 // DRAFT: undefined identifier 'sp48'
void Arrow::Update() {
    s8 sp119;
    s8 sp118;
    s32 sp114;
    f32 sp110;
    s32 sp10C;
    s8 sp10A;
    s8 sp109;
    s8 sp108;
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;                                       /* compiler-managed */
    Arrow *spF4;
    s32 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    s32 spCC;
    s32 spC8;
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
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f64 sp18;
    f32 sp10;
    f32 temp_f1_142;
    f32 temp_f1_165;
    f32 temp_f29_132;
    f32 temp_f30_133;
    f64 temp_f1_180;
    s32 temp_r3_126;
    void *temp_r3_188;
    void *temp_r4_177;
    void *temp_r5_282;

    GameProp::Update();
    temp_r3_126 = this->unk10;
    if ((temp_r3_126 & 0x20000) && (temp_r3_126 & 0x80000)) {
        temp_f29_132 = gUpdateTimeDelta;
        temp_f30_133 = -this->unkE0;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        temp_f1_142 = M2C_FIELD((MKModel_GetWorldMatrix(this->unk4) + 0x20), f32 *, 8) * temp_f30_133;
        sp98 = sp48;
        sp50 = temp_f1_142;
        spA0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        spA8 = sp38;
        sp40 = (f32) spA0 * temp_f29_132;
        spB0 = (f64) sp40;
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &spA8));
        this->unkE0 += gUpdateTimeDelta;
        temp_f1_165 = this->unkE4;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unkE0 == temp_f1_165) {
            this->unkE0 = temp_f1_165;
            Disable();
        }
        temp_r4_177 = this->unk8;
        temp_f1_180 = M2C_FIELD(temp_r4_177, f64 *, 0x30);
        sp78 = temp_f1_180;
        sp80 = M2C_FIELD(temp_r4_177, f64 *, 0x38);
        temp_r3_188 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, void *, f64), 0xC)(gb.unk0, temp_r4_177, temp_f1_180), void **, 8);
        sp88 = M2C_FIELD(temp_r3_188, f64 *, 0x30);
        sp90 = M2C_FIELD(temp_r3_188, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spB8 = sp28;
        sp30 = (f32) sp90 - (f32) sp80;
        unkspBC = 0.0f;
        spC0 = (f64) sp30;
        if ((((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + (0.0f * 0.0f))) < 10000.0f) {
            spCC = 0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp10 = (f32) spC0 * 20.0f;
            sp68 = sp8;
            sp70 = (f64) sp10;
            spC8 = 7;
            spF0 = 1;
            spF4 = this;
            spD0 = sp8;
            spD8 = (f64) sp10;
            sp108 = 0;
            sp114 = 2;
            sp110 = 10.0f;
            sp109 = 0;
            sp10A = 1;
            sp10C = -1;
            spE0 = M2C_FIELD(&one, f64 *, 0);
            spE8 = M2C_FIELD(&one, f64 *, 8);
            sp118 = 0;
            if (this != NULL) {
                sp18.GetPos();
                spF8 = sp18;
                sp100 = sp20;
            } else {
                spF8 = 0.0f;
                unkspFC = 0.0f;
                sp100 = 0.0f;
            }
            sp119 = 0;
            M2C_FIELD(gb.unk0->__vptr, M2C_UNK (**)(HeroInterface *, s32 *), 0x1C)(gb.unk0, &spC8);
            Disable();
        }
        temp_r5_282 = this->unk8;
        sp58 = M2C_FIELD(temp_r5_282, f64 *, 0x30);
        sp60 = M2C_FIELD(temp_r5_282, f64 *, 0x38);
        gb.EmitDust(*((MKVector3 *) &sp58), zero, 0.5f, 0.0f);
    }
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void Arrow::Reset() {
    PropFlagsSet((u32 *) &this->unk10, 0x80000U);
    Trap::Reset();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ArrowDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsAttacking'
void Trap::lit_200lit_IsAttacking() {
    ((Trap *) (this - 0xC8))->Trap::IsAttacking();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetTimeLastHit'
void Trap::lit_200lit_GetTimeLastHit() {
    ((Trap *) (this - 0xC8))->Trap::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionHeight'
void Trap::lit_200lit_GetCollisionHeight() {
    ((Trap *) (this - 0xC8))->Trap::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionRadius'
void Trap::lit_200lit_GetCollisionRadius() {
    ((Trap *) (this - 0xC8))->Trap::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionInfo'
void Trap::lit_200lit_GetCollisionInfo() {
    ((Trap *) (this - 0xC8))->Trap::GetCollisionInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetVel'
void Trap::lit_200lit_GetVel() {
    Trap::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetAimPoint'
void Trap::lit_200lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Trap *) (this - 0xC8))->Trap::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetLookToPoint'
void Trap::lit_200lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Trap *) (this - 0xC8))->Trap::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetMoveToPoint'
void Trap::lit_200lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Trap *) (this - 0xC8))->Trap::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsDead'
void Trap::lit_200lit_IsDead() {
    ((Trap *) (this - 0xC8))->Trap::IsDead();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsShatterable'
void Trap::lit_200lit_IsShatterable() {
    ((Trap *) (this - 0xC8))->Trap::IsShatterable();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsEnemy'
void Trap::lit_200lit_IsEnemy() {
    ((Trap *) (this - 0xC8))->Trap::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsFriend'
void Trap::lit_200lit_IsFriend() {
    ((Trap *) (this - 0xC8))->Trap::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsHero'
void Trap::lit_200lit_IsHero() {
    ((Trap *) (this - 0xC8))->Trap::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetEnemy'
void Trap::lit_200lit_GetEnemy() {
    ((Trap *) (this - 0xC8))->Trap::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetProp'
void Trap::lit_200lit_GetProp() {
    ((Trap *) (this - 0xC8))->Trap::GetProp();
}
#endif
