u8 SwampTier2Goal_Attack2::Update() {
    AnimSequence *temp_r4_366;
    AnimSequence *temp_r4_381;
    AnimSequence *temp_r4_397;
    AnimSequence *temp_r4_423;
    Enemy *temp_r29_360;
    Enemy *temp_r29_417;
    Enemy *temp_r3_340;
    Enemy *temp_r3_378;
    Enemy *temp_r3_385;
    Enemy *temp_r3_394;
    Enemy *temp_r3_401;
    Enemy *temp_r4_353;
    EnemyAttack *temp_r4_402;
    u8 var_r30_339;
    u8 var_r30_361;
    u8 var_r30_418;

    var_r30_339 = 0;
    temp_r3_340 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_340, u8 *, 0x8B8) == 2) || (temp_r3_340->unk870.unk40.Get() != NULL)) {
        var_r30_339 = 1;
    }
    if (var_r30_339 != 0) {
        temp_r4_353 = this->unkC;
        temp_r4_353->unk870.Update(temp_r4_353->unk588);
    }
    ActivateIfInactive();
    temp_r29_360 = this->unkC;
    var_r30_361 = 0;
    if (((Character *) temp_r29_360)->HasAnimFinished() != 0) {
        temp_r4_366 = temp_r29_360->unkA50;
        if ((temp_r4_366 != NULL) && ((u32) temp_r4_366->unk0 == (u32) M2C_FIELD(temp_r29_360->unk630, u32 *, 0x20))) {
            var_r30_361 = 1;
        }
    }
    if (var_r30_361 != 0) {
        temp_r3_378 = this->unkC;
        temp_r4_381 = temp_r3_378->unkA50;
        temp_r3_378->SetAnim(temp_r4_381, (AnimTransition *) &temp_r4_381->unk20, 0.0f, 0U);
    }
    temp_r3_385 = this->unkC;
    if (temp_r3_385->unkA54 == (AnimTransition *) &temp_r3_385->unkA50->unk20) {
        if (((Character *) temp_r3_385)->HasAnimFinished() != 0) {
            temp_r3_394 = this->unkC;
            temp_r4_397 = temp_r3_394->unkA50;
            temp_r3_394->SetAnim(temp_r4_397, (AnimTransition *) &temp_r4_397->unk40, 0.0f, 0U);
        }
        temp_r3_401 = this->unkC;
        temp_r4_402 = temp_r3_401->unkA20;
        if (((s32) temp_r4_402->unk78 > 0) && (((u8) temp_r3_401->unkB08 >> 4U) & 1) && (temp_r3_401->CheckMeleeHit(temp_r4_402, -1) != 0)) {
            this->unkC->SetHitTarget(1U);
        }
    }
    temp_r29_417 = this->unkC;
    var_r30_418 = 0;
    if (((Character *) temp_r29_417)->HasAnimFinished() != 0) {
        temp_r4_423 = temp_r29_417->unkA50;
        if ((temp_r4_423 != NULL) && ((u32) temp_r4_423->unk40 == (u32) M2C_FIELD(temp_r29_417->unk630, u32 *, 0x20))) {
            var_r30_418 = 1;
        }
    }
    if (var_r30_418 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
