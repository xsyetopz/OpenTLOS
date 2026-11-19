void ShatterableBoat::Message(MKMessage *arg0) {
    s32 temp_r0_469;
    s32 temp_r0_511;
    s32 temp_r3_539;
    s32 var_r0_516;
    s32 var_r4_510;
    ShatterableBoatDescriptor *desc;

    desc = checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(desc, s32 *, 0x16C) != 0) {
        ((KDSoundPlayer *) &this->unk338)->Message(arg0);
    }
    temp_r0_469 = arg0->unk0;
    switch (temp_r0_469) {
    case 0xB5:
        if ((s32) this->unk234 == 1) {
            this->unk234 = 0;
            this->unk24C->SetAnim(this->unk250, 1.0f, 0.0f, 0, -1);
            this->unk258->SetAnim(this->unk25C, 1.0f, 0.0f, 0, -1);
        } else {
            desc = checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            var_r4_510 = M2C_FIELD(desc, s32 *, 0x160) - 1;
            temp_r0_511 = this->unk238 + 1;
            if (temp_r0_511 < var_r4_510) {
                var_r4_510 = temp_r0_511;
            }
            var_r0_516 = lit_853;
            if (var_r4_510 > var_r0_516) {
                var_r0_516 = var_r4_510;
            }
            this->unk238 = var_r0_516;
        }
    default:
block_23:
        ShatterablePlatform::Message(arg0);
        return;
    case 0xB4:
        this->unk234 = 1;
        return;
    case 0x5:
        KDSound_Play3d(GS_ShipExtra2, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, -1, 0.0f, 0U);
        goto block_23;
    case 0xBA:
        temp_r3_539 = this->unk238;
        if ((s32) this->unk180 <= temp_r3_539) {
            this->unk180 = temp_r3_539;
            goto block_23;
        }
        break;
    case 0x15:
        SetDefaults();
        goto block_23;
    }
}
