#include "spyro/source/PooledShatterProp.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal operand
void PooledShatterProp::Update() {
    MKProp *temp_r4_133;
    void *temp_r3_129;

    Shatterable::Update();
    temp_r3_129 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((s32) this->unk15C.unk0 == 0) || ((temp_r4_133 = this->unk170, ((temp_r4_133 == (s32) M2C_FIELD(temp_r3_129, s32 *, 0x160)) != 0)) && ((s32) *(this->unk158 + (((s32) (temp_r4_133 - 1) << 7) + 0x44)) == 2))) {
        Reset();
        Disable();
    }
}
#endif
