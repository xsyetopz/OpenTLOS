f32 ShwimmaCritter::Resolve() {
    s32 i;
    s32 off;
    s32 slot;

    MKProp::Resolve();
    i = 0;
    off = 0;
    while (i < (s32) this->unk90) {
        slot = off + 0x60;
        i += 1;
        off += 0x90;
        M2C_FIELD(this->unk170, s32 *, slot) = 0;
    }
}
