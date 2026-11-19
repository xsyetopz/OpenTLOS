u8 SwampTier2Goal_Hide::Update() {
    AnimSequence *temp_r4_1681;
    AnimSequence *temp_r4_1696;
    AnimSequence *temp_r4_1717;
    AnimSequence *temp_r4_1727;
    Character *temp_r29_1675;
    Character *temp_r29_1721;
    Character *temp_r3_1693;
    Character *temp_r3_1716;
    Character *temp_r4_1711;
    u8 temp_r3_1703;
    u8 var_r30_1676;
    u8 var_r30_1722;

    ActivateIfInactive();
    temp_r29_1675 = this->unkC;
    var_r30_1676 = 0;
    if (temp_r29_1675->HasAnimFinished() != 0) {
        temp_r4_1681 = ((Enemy *) temp_r29_1675)->unkA50;
        if ((temp_r4_1681 != NULL) && ((u32) temp_r4_1681->unk0 == (u32) M2C_FIELD(temp_r29_1675->unk630, u32 *, 0x20))) {
            var_r30_1676 = 1;
        }
    }
    if (var_r30_1676 != 0) {
        temp_r3_1693 = this->unkC;
        temp_r4_1696 = ((Enemy *) temp_r3_1693)->unkA50;
        ((Enemy *) temp_r3_1693)->SetAnim(temp_r4_1696, (AnimTransition *) &temp_r4_1696->unk20, 0.15f, 0U);
        M2C_FIELD(this->unkC, s32 *, 0xB10) = 2;
    }
    temp_r3_1703 = this->unk10;
    if ((temp_r3_1703 >> 7U) & 1) {
        this->unk10 = temp_r3_1703 & ~0x80;
        temp_r4_1711 = this->unkC;
        M2C_FIELD(temp_r4_1711, s32 *, 0xB10) = (s32) (M2C_FIELD(temp_r4_1711, s32 *, 0xB14) != 0);
        temp_r3_1716 = this->unkC;
        temp_r4_1717 = ((Enemy *) temp_r3_1716)->unkA50;
        ((Enemy *) temp_r3_1716)->SetAnim(temp_r4_1717, (AnimTransition *) &temp_r4_1717->unk40, 0.15f, 0U);
    }
    temp_r29_1721 = this->unkC;
    var_r30_1722 = 0;
    if (temp_r29_1721->HasAnimFinished() != 0) {
        temp_r4_1727 = ((Enemy *) temp_r29_1721)->unkA50;
        if ((temp_r4_1727 != NULL) && ((u32) temp_r4_1727->unk40 == (u32) M2C_FIELD(temp_r29_1721->unk630, u32 *, 0x20))) {
            var_r30_1722 = 1;
        }
    }
    if (var_r30_1722 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
