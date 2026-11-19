u8 GoopFXDescriptor::TwoFrozenNodes(GoopFXDescriptor::Goop *arg1) {
    s32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 4; i++) {
        if (M2C_FIELD(arg1, u8 *, 0x20 + i * 0x28) != 0) {
            count++;
        }
    }
    return count > 1;
}
