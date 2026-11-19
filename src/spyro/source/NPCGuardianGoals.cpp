#include "spyro/source/NPCGuardianGoals.h"
#include "spyro/source/Character.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 gViewSeed;
extern M2C_UNK gb;

void NPCGuardianGoal_Idle::Reset() {
    this->unk8 = 1;
    this->unk10 = 0;
}

#if 0 // DRAFT: undefined identifier 'unkAEC'
void NPCGuardianGoal_Idle::Terminate() {
    this->unkC->StopMovement(1U);
    this->unkC->unkAEC = 0;
    this->unkC->unk6F8 = 0;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 NPCGuardianGoal_Idle::Update() {
    AnimSequence *temp_r3_134;
    AnimSequence *temp_r3_182;
    Character *temp_r29_52;
    Character *temp_r3_152;
    Character *temp_r3_191;
    Character *temp_r5_227;
    Character *temp_r5_95;
    Character *temp_r6_128;
    Character *temp_r6_176;
    u32 temp_r3_216;
    u8 var_r30_112;
    u8 var_r6_153;
    u8 var_r6_192;
    void *temp_r3_53;
    void *temp_r4_116;
    void *temp_r5_154;
    void *temp_r5_193;

    ActivateIfInactive();
    temp_r29_52 = this->unkC;
    temp_r3_53 = temp_r29_52->unkA50;
    if ((temp_r3_53 != NULL) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x6C) == 1) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x68) == 1)) {
        if (temp_r29_52->HasAnimFinished() != 0) {
            if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) < 0.1f) {
                this->unkC->SetAnim((AnimSequenceType) 1, 9, 0, 0.15f, 0U, 0U);
                this->unkC->unk6F8 = 0;
            }
        } else if (((TargetContext *) (this->unk10 + 0x40))->Get() != NULL) {
            temp_r5_95 = this->unkC;
            M2C_FIELD(((TargetContext *) (this->unk10 + 0x40))->Get()->__vptr, M2C_UNK (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_95->unk588, &temp_r5_95->unk700);
        }
    } else if ((temp_r3_53 != NULL) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x6C) == 1) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x68) == 9)) {
        var_r30_112 = 0;
        if (temp_r29_52->HasAnimFinished() != 0) {
            temp_r4_116 = temp_r29_52->unkA50;
            if ((temp_r4_116 != NULL) && ((u32) M2C_FIELD(temp_r4_116, u32 *, 0) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_52, void **, 0x630), u32 *, 0x20))) {
                var_r30_112 = 1;
            }
        }
        if (var_r30_112 != 0) {
            temp_r6_128 = this->unkC;
            temp_r3_134 = temp_r6_128->unkA38->GetAnimSequence(1, 9, temp_r6_128->unkAE4, NULL);
            this->unkC->SetAnim(temp_r3_134, temp_r3_134 + 0x20, 0.15f, 0U);
            this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, 2.0f, 5.0f);
        }
        temp_r3_152 = this->unkC;
        var_r6_153 = 0;
        temp_r5_154 = temp_r3_152->unkA50;
        if ((temp_r5_154 != NULL) && ((u32) M2C_FIELD(temp_r5_154, u32 *, 0x20) == (u32) M2C_FIELD(M2C_FIELD(temp_r3_152, void **, 0x630), u32 *, 0x20))) {
            var_r6_153 = 1;
        }
        if ((var_r6_153 != 0) && (temp_r3_152->HasAnimFinished() != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk14)) {
            temp_r6_176 = this->unkC;
            temp_r3_182 = temp_r6_176->unkA38->GetAnimSequence(1, 9, temp_r6_176->unkAE4, NULL);
            this->unkC->SetAnim(temp_r3_182, temp_r3_182 + 0x40, 0.15f, 0U);
        }
        temp_r3_191 = this->unkC;
        var_r6_192 = 0;
        temp_r5_193 = temp_r3_191->unkA50;
        if ((temp_r5_193 != NULL) && ((u32) M2C_FIELD(temp_r5_193, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r3_191, void **, 0x630), u32 *, 0x20))) {
            var_r6_192 = 1;
        }
        if ((var_r6_192 != 0) && (temp_r3_191->HasAnimFinished() != 0)) {
            this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
            temp_r3_216 = this->unk10;
            if ((temp_r3_216 != 0) && (((TargetContext *) (temp_r3_216 + 0x40))->Get() != NULL)) {
                temp_r5_227 = this->unkC;
                if (M2C_FIELD(((TargetContext *) (this->unk10 + 0x40))->Get()->__vptr, u8 (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_227->unk588, &temp_r5_227->unk700) != 0) {
                    this->unkC->unk6F8 = 1;
                }
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void NPCGuardianGoal_Idle::Activate() {
    Character *temp_r5_268;
    u32 temp_r3_257;

    this->unk8 = 0;
    temp_r3_257 = this->unk10;
    if ((temp_r3_257 != 0) && (((TargetContext *) (temp_r3_257 + 0x40))->Get() != NULL)) {
        temp_r5_268 = this->unkC;
        if (M2C_FIELD(((TargetContext *) (this->unk10 + 0x40))->Get()->__vptr, u8 (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_268->unk588, &temp_r5_268->unk700) != 0) {
            this->unkC->unk6F8 = 1;
        }
    }
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
}
#endif
