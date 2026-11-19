#include "spyro/source/SmashWall.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

void SmashWall::Message(MKMessage *arg0) {
    u8 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f0_92;
    f32 temp_f3_105;
    f32 temp_f4_102;
    f32 temp_f5_98;
    s32 temp_r0_46;
    void *temp_r3_61;
    void *temp_r3_68;
    void *temp_r3_88;

    temp_r0_46 = arg0->unk0;
    switch (temp_r0_46) {                           /* irregular */
    case 1:
        temp_r3_61 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
        sp1C = 0;
        sp18 = 0x70;
        sp20 = 0;
        temp_r3_68 = M2C_FIELD(temp_r3_61, void **, 8);
        if (temp_r3_68 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_68, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp18);
        }
        if ((sp20 != 0) && ((s32) this->unk16C != 3)) {
            temp_r3_88 = this->unk8;
            temp_f0_92 = M2C_FIELD(temp_r3_61, f32 *, 0x20) + GetCollisionRadius();
            sp8 = M2C_FIELD(temp_r3_88, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r3_88, f64 *, 0x38);
            temp_f5_98 = (*(f32 *) ((u8 *) &sp8 + 0x4)) - M2C_FIELD(temp_r3_61, f32 *, 0x14);
            temp_f4_102 = (f32) sp8 - M2C_FIELD(temp_r3_61, f32 *, 0x10);
            temp_f3_105 = (f32) sp10 - M2C_FIELD(temp_r3_61, f32 *, 0x18);
            if (((temp_f3_105 * temp_f3_105) + ((temp_f4_102 * temp_f4_102) + (temp_f5_98 * temp_f5_98))) < (temp_f0_92 * temp_f0_92)) {
                SetSmashPropState((SmashPropState) 2);
                return;
            }
        }
    case 5:
    case 49:
        return;
    default:
        Shatterable::Message(arg0);
        break;
    }
}
