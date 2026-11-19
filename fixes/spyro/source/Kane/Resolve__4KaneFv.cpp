f32 Kane::Resolve() {
    s32 spC;
    s32 sp8;
    u32 temp_r3_91;

    Enemy::Resolve();
    temp_r3_91 = (unsigned long) (checked_cast<CharacterGraphNodeProp *, MKProp>(MKSceneManager::PropResolver_Resolve(this->unkB10)));
    if (temp_r3_91 != 0U) {
        this->unkA80 = temp_r3_91 + 0x50;
    }
    M2C_FIELD(this->unkA3C, s8 *, 8) = 1;
    if ((u8) M2C_FIELD(this, u8 *, 0xB14) == 0) {
        spC = 0;
        sp8 = 0xBF;
        Message((MKMessage *) &sp8);
        Disable();
    }
}
