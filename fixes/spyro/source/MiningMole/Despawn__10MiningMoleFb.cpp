void MiningMole::Despawn(bool arg0) {
    s32 spC;
    s32 sp8;
    MoleTether *temp_r3_725;

    temp_r3_725 = this->unkB14;
    if (temp_r3_725 != NULL) {
        spC = 0;
        sp8 = 0xBF;
        temp_r3_725->Message((MKMessage *) &sp8);
        this->unkB14->Disable();
    }
    Enemy::Despawn(arg0);
}
