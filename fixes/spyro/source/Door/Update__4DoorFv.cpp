void *Door::Update() {
    s32 temp_r0_123;
    s32 temp_r4_136;
    s32 temp_r4_160;

    GameProp::Update();
    if (this->unk10 & 0x20000) {
        temp_r0_123 = this->unkE0;
        switch (temp_r0_123) {                      /* irregular */
        case 0:
            temp_r4_136 = this->unkE4;
            if (temp_r4_136 == 1) {
                SetState((DoorStates) temp_r4_136);
                return;
            }
            break;
        case 1:
            if (this->unk80->unk2C & 1) {
                if (checked_cast<DoorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF4 != 0) {
                    this->unk70.unk4 = 0;
                }
                SetState((DoorStates) 2);
                return;
            }
            break;
        case 2:
            temp_r4_160 = this->unkE4;
            if (temp_r4_160 == 3) {
                SetState((DoorStates) temp_r4_160);
                return;
            }
            break;
        case 3:
            if (this->unk80->unk2C & 1) {
                if (checked_cast<DoorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF4 != 0) {
                    this->unk70.unk4 = 1;
                }
                SetState((DoorStates) 0);
            }
            break;
        }
    }
}
