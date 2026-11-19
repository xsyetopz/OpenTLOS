void CharacterBodyFX::SetDataActive(bool arg0) {
    s32 i;
    s32 off;

    this->unk10 = arg0;
    if (this->unk10 == 0 && this->unk8 != NULL && this->unk4 != 0) {
        off = 0;
        i = 0;
        while (i < this->unk8->unk4) {
            ((u8 *) this->unk4)[off + 0x60] = 0;
            i += 1;
            off += 0x70;
        }
    }
}
