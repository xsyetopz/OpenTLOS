void CynderConcurrentGoal_Think::Arbitrate() {
    typedef u8 (*BlockFn)(void *, Matrix *, s32, f32);
    typedef u8 (Enemy::*FlinchFn)(void);
    Matrix sp50;
    EnemyDamageFeedback sp10;
    f32 temp_f1_192;
    s32 enter;
    s32 temp_r3_184;
    s32 temp_r3_212;
    s32 temp_r3_224;
    s32 temp_r3_233;

    temp_r3_184 = this->unkC;
    enter = 0;
    if ((M2C_FIELD(temp_r3_184, u8 *, 0xB09) >> 7) & 1) {
        enter = 1;
    } else {
        sp50.SetIdentity();
        sp50.unk30 = M2C_FIELD(temp_r3_184, f32 *, 0x5B8);
        sp50.unk34 = M2C_FIELD(temp_r3_184, f32 *, 0x5BC);
        temp_f1_192 = M2C_FIELD(temp_r3_184, f32 *, 0x5C0);
        sp50.unk38 = temp_f1_192;
        sp50.unk3C = 1.0f;
        enter = ((BlockFn) ((void **) M2C_FIELD(temp_r3_184, void **, 0x44))[0x120 / 4])((void *) temp_r3_184, &sp50, 0, temp_f1_192) != 0;
    }
    if (enter) {
        if (((Enemy *) this->unkC)->WasHit() != 0) {
            sp10.Init();
            if (((Enemy *) this->unkC)->IsInvulnerable() != 0) {
                temp_r3_212 = this->unkC;
                M2C_FIELD(temp_r3_212, s32 *, 0x9D8) = 0;
                M2C_FIELD(temp_r3_212, s32 *, 0x9D4) = 0;
            } else {
                ((Enemy *) this->unkC)->TakeDamage(&sp10, 0U);
                ((Cynder *) this->unkC)->UpdateEnemyHud();
                temp_r3_224 = this->unkC;
                if (M2C_FIELD(temp_r3_224, f32 *, 0xAC8) <= 0.0f) {
                    ((EventMessage *) (temp_r3_224 + 0x1000))->Send(NULL);
                    temp_r3_233 = this->unkC;
                    M2C_FIELD(temp_r3_233, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r3_233, u8 *, 0xB01) | 0x80);
                }
                if ((sp10.unk28 == 4) || (sp10.unk28 == 5)) {
                    sp10.unk28 = 0xE;
                }
                if (sp10.unk28 != 0xE) {
                    AddGoal_Hit(&sp10);
                    return;
                }
            }
        }
        if ((((((Enemy *) this->unkC)->*((FlinchFn) &Enemy::IsFlinching))()) == 0) && (IsPresent(0xB9) == 0)) {
            RemoveAllSubgoals();
            AddSubgoal((Goal<Cynder> *) this->unk2C);
            ((CynderGoal_GroundAttackMode *) this->unk2C)->SetParams((AITargetData *) (this->unkC + 0x870), NULL, 0);
        }
    }
}
