void UISystem::DoTransition() {
    s32 temp_r0_149;
    s32 temp_r0_200;

    temp_r0_149 = this->unk68;
    switch (temp_r0_149) {
    case 0:
        break;
    case 1:
        M2C_FIELD(this, void **, this->unk6C * 4 + 0x70) = (void **) this->unk94;
        break;
    case 2:
        this->unk6C += 1;
        M2C_FIELD(this, void **, this->unk6C * 4 + 0x70) = (void **) this->unk94;
        break;
    case 3:
        M2C_FIELD(this, s32 *, this->unk6C * 4 + 0x70) = 0;
        this->unk6C -= 1;
        break;
    case 4:
loop_13:
        temp_r0_200 = this->unk6C;
        if (temp_r0_200 > 0) {
            M2C_FIELD(this, s32 *, temp_r0_200 * 4 + 0x70) = 0;
            this->unk6C -= 1;
            goto loop_13;
        }
        M2C_FIELD(this, void **, temp_r0_200 * 4 + 0x70) = (void **) this->unk94;
        break;
    }
    this->unk94 = NULL;
    if ((u32) M2C_FIELD(this, u32 *, this->unk6C * 4 + 0x70) != 0U) {
        this->unk9D = 1;
        return;
    }
    this->unk9D = 0;
    this->unk68 = 0;
}
