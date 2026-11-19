void FireTier1Goal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Character *temp_r3_2550;
    Character *temp_r3_2557;
    Character *temp_r3_2568;
    Character *temp_r4_2563;
    Character *temp_r4_2583;
    s32 temp_r0_2521;
    s32 temp_r3_2522;
    s32 temp_r4_2498;
    s32 var_r31_2477;
    u8 temp_r3_2497;

    var_r31_2477 = arg0->unk28;
    if (IsPresent(0x5B) == 0) {
        if (IsActive(0x59) != 0) {
            temp_r3_2497 = IsActive(8);
            temp_r4_2498 = arg0->unk20;
            if (((temp_r4_2498 & 4) && ((s32) arg0->unk2C == 1)) || ((temp_r4_2498 & 8) && (var_r31_2477 == 2)) || (var_r31_2477 != 0) || (temp_r3_2497 == 0)) {
                if ((s32) this->unk14 > 0) {
                    this->unk18 += 1;
                    temp_r0_2521 = this->unk18;
                    temp_r3_2522 = this->unk10;
                    if (temp_r0_2521 >= temp_r3_2522) {
                        this->unk18 = temp_r0_2521 - temp_r3_2522;
                    }
                    this->unk14 -= 1;
                }
                goto block_12;
            }
        } else {
block_12:
            switch (var_r31_2477) {
            case 12:
            case 0:
                break;
            case 11:
                RemoveAllSubgoals();
                temp_r3_2550 = this->unkC;
                temp_r3_2550->unk6B5 |= 0x20;
                temp_r3_2557 = this->unkC;
                temp_r3_2557->unk6B5 &= ~0x10;
                this->unkC->SetMovementType((CharacterMoveType) 0);
                temp_r4_2563 = this->unkC;
                temp_r4_2563->unk5E4 = M2C_FIELD(temp_r4_2563->unk5D8, f32 *, 8);
                temp_r3_2568 = this->unkC;
                temp_r3_2568->unkA0 = 0.0f;
                temp_r3_2568->unkA4 = 0.0f;
                temp_r3_2568->unkA8 = 0.0f;
                break;
            default:
                var_r31_2477 = 0;
                break;
            }
            if (var_r31_2477 != 0xB) {
                ((Enemy *) this->unkC)->ThawIfFrozen();
            }
            arg0->unk28 = var_r31_2477;
            temp_r4_2583 = this->unkC;
            *(EnemyDamageFeedback *) ((s8 *) temp_r4_2583 + 0x910) = *arg0;
            AddSubgoalToFront((Goal<Enemy> *) this->unk2C);
        }
    }
}
