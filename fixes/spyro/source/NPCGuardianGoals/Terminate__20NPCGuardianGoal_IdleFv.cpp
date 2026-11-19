void NPCGuardianGoal_Idle::Terminate() {
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->unkAEC = 0;
    M2C_FIELD(this->unkC, u8 *, 0x6F8) = 0;
    this->unk8 = 1;
}
