void DreadWingGoal_PickUp::Activate() {
    this->unk8 = 0;
    ((DreadWing *) (checked_cast<DreadWing *, Enemy>(this->unkC)))->PickUpDropBox(this->unk10);
    this->unk8 = 2;
}
