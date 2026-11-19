void EnemyGenerator::StartEnemyWave() {
    if (this->unk7C < this->unk78) {
        this->unk20 = 0;
        this->unk24 = *(s32 *) ((u8 *) this->unk50->unk14 + (this->unk7C * 0x14));
        this->unk28 = *(s32 *) ((u8 *) this->unk50->unk14 + (this->unk7C * 0x14) + 4);
        this->unk30 = *(f32 *) ((u8 *) this->unk50->unk14 + (this->unk7C * 0x14) + 0xC);
        this->unk34 = *(f32 *) ((u8 *) this->unk50->unk14 + (this->unk7C * 0x14) + 0x10);
        FunctionOn();
    }
}
