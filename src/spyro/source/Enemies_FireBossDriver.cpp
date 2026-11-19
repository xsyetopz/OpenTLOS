#include "spyro/source/Enemies_FireBossDriver.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/FireBossDriverGoals.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: pointer/array required
s32 FireBossDriver::IsCharging() {
    s32 temp_r3_54;
    s32 var_r31_53;

    var_r31_53 = 0;
    temp_r3_54 = this->unkAF8;
    if ((M2C_FIELD(*temp_r3_54, u8 (**)(s32, M2C_UNK), 0x38)(temp_r3_54, 0x6E) != 0) && ((u32) M2C_FIELD(M2C_FIELD(this, void **, 0x630), u32 *, 0x20) != (void *) this->unkA38->__vptr)) {
        var_r31_53 = 1;
    }
    return var_r31_53;
}
#endif

#if 0 // DRAFT: pointer/array required
void FireBossDriver::CrashExit() {
    this->unkAF8->CrashExit();
}
#endif

#if 0 // DRAFT: pointer/array required
void FireBossDriver::CrashEnter() {
    this->unkAF8->CrashEnter();
}
#endif

#if 0 // DRAFT: pointer/array required
void FireBossDriver::ChargeExit() {
    this->unkAF8->ChargeExit();
}
#endif

#if 0 // DRAFT: pointer/array required
void FireBossDriver::ChargeEnter() {
    this->unkAF8->ChargeEnter();
}
#endif

void FireBossDriver::Draw() {
    Enemy::Draw();
}

void FireBossDriver::Update() {
    Enemy::Update();
}

void FireBossDriver::Resolve() {
    M2C_FIELD(this, u8 *, 0xB09) = (u8) (M2C_FIELD(this, u8 *, 0xB09) & ~0x20);
    Enemy::Resolve();
}

void FireBossDriver::LoadDone() {
    Enemy::LoadDone();
}

void FireBossDriver::SetDefaults() {
    Enemy::SetDefaults();
    M2C_FIELD(this, s8 *, 0xB14) = 0;
}

#if 0 // DRAFT: pointer/array required
void FireBossDriver::Init() {
    Enemy::Init();
    operator new(0x30U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkAF8 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unkAF8->Init((Enemy *) this);
    this->unkA24 = checked_cast<Goal<Enemy> *, FireBossDriverGoal_Think>((FireBossDriverGoal_Think *) this->unkAF8);
}
#endif

void FireBossDriverDescriptor::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    BoundingVolume *temp_r3_269;

    EnemyDescriptor::LoadDone();
    sp8 = 0.0f;
    temp_r3_269 = this->unk1C;
    spC = 900.0f;
    sp10 = 300.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
    temp_r3_269->unk18 += (f32) sp20;
    M2C_FIELD(this, s8 *, 0x74) = 0;
}

void FireBossDriverDescriptor::Init() {
    EnemyDescriptor::Init();
    this->unk1D5 = 0;
}
