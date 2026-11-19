void *DartTrap::Update() {
    s32 temp_r0_401;

    KDProp::Update();
    this->unkAC -= gUpdateTimeDelta;
    temp_r0_401 = this->unk94;
    switch (temp_r0_401) {                          /* irregular */
    case 0:
        break;
    case 1:
        if (this->unk80->unk2C & 1) {
            SetState(2);
            SetAnim(2);
            this->unkAC = this->unkA4;
            this->unk9C = 0.0f;
        }
        break;
    case 2:
        this->unk9C -= gUpdateTimeDelta;
        if ((this->unk9C <= 0.0f) && (this->unk80->unk2C & 1)) {
            SetAnim(2);
            this->unk9C = 1.0f / this->unkA0;
        }
        if (this->unk80->CheckEvent(0) != 0) {
            Shoot();
        }
        if (this->unkAC <= 0.0f) {
            SetState(3);
            SetAnim(3);
            this->unkAC = this->unkA8;
        }
        break;
    case 3:
        if ((this->unk80->unk2C & 1) && (this->unkAC <= 0.0f)) {
            if ((u8) this->unkB0 != 0) {
                SetState(0);
                SetAnim(0);
            } else {
                SetState(1);
                SetAnim(1);
                this->unkAC = this->unkA4;
            }
        }
        break;
    }
    KDSound_Play3d(this->unk80, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, 0.0f, false);
}
