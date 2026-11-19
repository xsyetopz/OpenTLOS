void RefFXEmitterDescriptor::Resolve() {
    s32 sp8;
    s32 temp_r3_257;
    s32 temp_r4_257;

    MKPropDescriptor::Resolve();
    sp8 = -1;
    this->unk98 = 0;
    while (MKModel_RefPointExists(this->unk2C, (const char *) Str_Printf("r_fxemit%d", this->unk98), (int *) &sp8) != 0) {
        temp_r3_257 = this->unk98;
        temp_r4_257 = sp8;
        this->unk98 = temp_r3_257 + 1;
        *(s32 *) ((u8 *) this + ((temp_r3_257 * 4) + 0x70)) = temp_r4_257;
    }
    this->unk9C = (long) (checked_cast<Steam *, MKProp>(gMK->CreateProp("Steam")));
}
