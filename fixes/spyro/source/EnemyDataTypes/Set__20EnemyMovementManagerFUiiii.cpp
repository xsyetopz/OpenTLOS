void EnemyMovementManager::Set(unsigned int arg0, int arg1, int arg2, int arg3) {
    Enemy *temp_r3_393;

    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = arg2;
    this->unk10 = arg3;
    this->unk14 &= ~0x80;
    this->unk14 &= ~0x40;
    temp_r3_393 = this->unk0;
    /* The asm loads the vptr from offset 0x44 (MKProp's vptr offset in classes.json), then slot 0x148 with the object in r3. */
    if ((temp_r3_393 != NULL) && (M2C_FIELD(M2C_FIELD(temp_r3_393, void ***, 0x44), u8 (**)(Enemy *), 0x148)(temp_r3_393) == 0)) {
        this->unk4 &= 0xFFFFFFF7;
    }
}
