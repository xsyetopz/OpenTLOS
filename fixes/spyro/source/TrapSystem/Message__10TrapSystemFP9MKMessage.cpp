void TrapSystem::Message(MKMessage *arg0) {
    u8 sp8[0x8];
    MKProp *var_r30_117;
    s32 temp_r0_98;

    MKProp::Message(arg0);
    temp_r0_98 = arg0->unk0;
    if (temp_r0_98 < 0xB6) {
        if (temp_r0_98 < 0xB0) {
            if (temp_r0_98 < 0xAE) {
                return;
            }
            goto block_9;
        }
        if (temp_r0_98 < 0xB4) {
            return;
        }
        goto block_9;
    }
    if (temp_r0_98 < 0xC0) {
        if (temp_r0_98 < 0xBE) {
            return;
        }
block_9:
        var_r30_117 = this->unk4C;
        while (var_r30_117 != NULL) {
            M2C_FIELD(sp8, s32 *, 0x4) = 0;
            M2C_FIELD(sp8, s32 *, 0x0) = arg0->unk0;
            var_r30_117->Message((MKMessage *) sp8);
            var_r30_117 = var_r30_117->unk28;
        }
    }
}
