u8 EnemyTestGoal_MoveToTarget::Update() {
    ActivateIfInactive();
    ((Enemy *) this->unkC)->unk9E8.Update();
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk18) || (this->unk10->GetDist() < this->unk14) || ((u8) this->unkC->unk640->PathFollowingHasLooped() != 0)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
