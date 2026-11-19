void ElecTier2Goal_FlyIdle::Activate() {
    this->unk8 = 0;
    ((Enemy *) this->unkC)->unkAEC = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}
