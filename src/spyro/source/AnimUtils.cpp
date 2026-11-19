#include "spyro/source/AnimUtils.h"
#include "common/Source/MKAnimScript.h"
#include "spyro/source/LavaCannon.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal type
void AnimManager::Init(AnimEntry *arg0, int arg1, MKAnimScript *arg2) {
    s32 temp_r0_28;
    s32 var_r30_17;
    s32 var_r31_18;
    void *temp_r3_26;

    var_r30_17 = 0;
    var_r31_18 = 0;
    this->unk0 = arg0;
    this->unk4 = arg1;
loop_2:
    if (var_r30_17 < (s32) this->unk4) {
        temp_r3_26 = arg2->GetAnim(*(this->unk0 + var_r31_18));
        temp_r0_28 = var_r31_18 + 4;
        var_r30_17 += 1;
        var_r31_18 += 8;
        *(this->unk0 + temp_r0_28) = temp_r3_26;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void AnimEventManager::Update(MKAnimScript *arg0) {
    AnimEventDesc *temp_r3_57;
    AnimEventDesc *temp_r6_84;
    s32 temp_r4_89;
    s32 var_r31_53;
    s32 var_r4_67;
    s32 var_r7_66;
    u32 temp_r3_93;

    var_r31_53 = 0;
    this->unk8 = this->unk4;
    this->unk4 = 0;
    temp_r3_57 = this->unk0;
    if (temp_r3_57 != NULL) {
        if ((AnimEventEntry *) temp_r3_57->unk0 == NULL) {
            return;
        }
loop_9:
        temp_r4_89 = var_r31_53;
        var_r31_53 += 1;
        temp_r3_93 = arg0->GetEvent(temp_r4_89, (MKAnimScriptedEvent::EventType) 0);
        if (temp_r3_93 != 0U) {
            var_r7_66 = 0;
            var_r4_67 = 0;
loop_8:
            temp_r6_84 = this->unk0;
            if (var_r7_66 < (s32) temp_r6_84->unk4) {
                if (temp_r3_93 == (u32) *(temp_r6_84->unk0 + (var_r4_67 + 4))) {
                    this->unk4 |= 1 << var_r7_66;
                }
                var_r7_66 += 1;
                var_r4_67 += 8;
                goto loop_8;
            }
            goto loop_9;
        }
    }
}
#endif

void AnimEventManager::Init(AnimEventDesc *arg0) {
    this->unk0 = arg0;
    this->unk8 = 0;
    this->unk4 = 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void AnimEventDesc::Init(AnimEventEntry *arg0, int arg1, MKAnimScript *arg2) {
    s32 temp_r0_135;
    s32 var_r30_123;
    s32 var_r31_124;
    s8 *temp_r3_133;

    var_r30_123 = 0;
    var_r31_124 = 0;
    this->unk4 = arg1;
    this->unk0 = arg0;
loop_2:
    if (var_r30_123 < (s32) this->unk4) {
        temp_r3_133 = arg2->GetEventByName(*(this->unk0 + var_r31_124), (MKAnimScriptedEvent::EventType) 0);
        temp_r0_135 = var_r31_124 + 4;
        var_r30_123 += 1;
        var_r31_124 += 8;
        *(this->unk0 + temp_r0_135) = temp_r3_133;
        goto loop_2;
    }
}
#endif
