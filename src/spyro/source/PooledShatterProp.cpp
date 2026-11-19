#include "spyro/source/PooledShatterProp.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal type
void PooledShatterProp::Update() {
    s32 temp_r4_133;
    void *temp_r3_129;

    Shatterable::Update();
    temp_r3_129 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((s32) this->unk16C == 0) || ((temp_r4_133 = this->unk180, ((temp_r4_133 == (s32) M2C_FIELD(temp_r3_129, s32 *, 0x160)) != 0)) && ((s32) *(this->unk168 + (((temp_r4_133 - 1) << 7) + 0x44)) == 2))) {
        Reset();
        Disable();
    }
}
#endif
