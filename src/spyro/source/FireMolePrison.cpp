#include "spyro/source/FireMolePrison.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/FireMolePrisonDescriptor.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/shatterwaypointspawn.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_MoleHelpMe;
extern s32 GS_MoleScurry;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: type mismatch
void FireMolePrison::Message(MKMessage *arg0) {
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    MKProp *temp_r3_74;
    s32 var_r30_52;
    s32 var_r31_53;
    void *temp_r6_60;

    if ((s32) arg0->unk0 != 0xBA) {

    } else {
        var_r30_52 = 0;
        var_r31_53 = 0;
loop_6:
        if (var_r30_52 < (u32 *) this->unk1A8.unk44) {
            temp_r6_60 = this->unk1A8.unk40.unk0 + var_r31_53;
            sp8 = M2C_FIELD(temp_r6_60, f64 *, 0);
            sp10 = M2C_FIELD(temp_r6_60, f64 *, 8);
            SetSpawnPos(var_r30_52, *((MKVector3 *) &sp8));
            temp_r3_74 = ((SpawnerObject *) &this->unk198)->TrySpawnItem(M2C_FIELD(M2C_FIELD(checked_cast<FireMolePrisonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x40), s32 (**)(), 0x24)());
            if (temp_r3_74 != NULL) {
                sp1C = 0;
                sp18 = 0x98;
                sp20 = sp8;
                sp28 = sp10;
                M2C_FIELD(temp_r3_74->__vptr, M2C_UNK (**)(s32 *, f64), 0x2C)(&sp18, sp8);
            }
            var_r30_52 += 1;
            var_r31_53 += 0x10;
            goto loop_6;
        }
    }
    Shatterable::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void FireMolePrison::Update() {
    f32 temp_f1_117;

    Shatterable::Update();
    temp_f1_117 = M2C_BITWISE(f32, this->unk1F8);
    if (temp_f1_117 > 0.0f) {
        this->unk1F8 = temp_f1_117 - gUpdateTimeDelta;
    }
    if ((IsDead() == 0) && (KDSound_IsVoicePlaying(this->unk208) == 0) && (M2C_BITWISE(f32, this->unk1F8) <= 0.0f)) {
        this->unk1F8 = MKRand_Float(&gViewSeed, 1.0f, 4.0f);
        this->unk208 = KDSound_Play3d(GS_MoleHelpMe, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if ((IsDead() != 0) && (KDSound_IsVoicePlaying(this->unk208) != 0)) {
        KDSound_Stop(&this->unk208);
    }
    if ((IsDead() != 0) && ((u8) M2C_FIELD(this, u8 *, 0x210) == 0)) {
        M2C_FIELD(this, u8 *, 0x210) = 1U;
        KDSound_Play3d(GS_MoleScurry, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void FireMolePrison::Deinit() {
    KDSound_Stop(&this->unk208);
    ShatterWaypointSpawn::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void FireMolePrison::Init() {
    ShatterWaypointSpawn::Init();
    this->unk208 = 0;
    this->unk1F8 = 0.0f;
    M2C_FIELD(this, s8 *, 0x210) = 0;
}
#endif
