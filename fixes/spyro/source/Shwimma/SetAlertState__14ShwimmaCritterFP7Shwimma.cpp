void ShwimmaCritter::SetAlertState(Shwimma *arg0) {
    ShwimmaCritterDescriptor *desc;
    s32 idx;

    M2C_FIELD(arg0, f32 *, 0x64) = 4.0f * MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
    M2C_FIELD(arg0, s32 *, 0x60) = MKRand_Int((int *) &gViewSeed, 0, 5) + 6;
    idx = M2C_FIELD(arg0, s32 *, 0x60);
    desc = checked_cast<ShwimmaCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    M2C_FIELD(arg0, f32 **, 0x50) = M2C_FIELD((s8 *) desc + idx * 4, f32 **, 0x70);
    M2C_FIELD(arg0, f32 *, 0x58) = 30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(arg0, f32 **, 0x50), s16 *, 4) / 30.0f));
    M2C_FIELD(arg0, f32 *, 0x54) = 0.0f;
}
