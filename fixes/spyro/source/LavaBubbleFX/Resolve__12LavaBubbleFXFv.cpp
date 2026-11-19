f32 LavaBubbleFX::Resolve() {
    MKVector3 sp38;
    MKVector4 sp28;
    s32 temp_r0_1433;
    s32 var_r29_1406;
    s32 var_r31_1408;
    void *temp_r3_1440;

    KDPropEx::Resolve();
    var_r29_1406 = 0;
    var_r31_1408 = 0;
    do {
        sp38.unk0 = 0.0f;
        sp38.unk4 = 0.0f;
        sp38.unk8 = 0.0f;
        sp28.unk0 = 1.0f;
        sp28.unk4 = 0.75f;
        sp28.unk8 = 0.5f;
        sp28.unkC = 1.0f;
        temp_r0_1433 = var_r31_1408 + 0x5C;
        var_r29_1406 += 1;
        *(void **) ((u8 *) this->unkC8 + temp_r0_1433) = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(sp38, sp28, 8.0f, lit_550, lit_551);
        var_r31_1408 += 0x78;
        temp_r3_1440 = *(void **) ((u8 *) this->unkC8 + temp_r0_1433);
        M2C_FIELD(temp_r3_1440, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r3_1440, u8 *, 0x31) & ~0x40);
    } while (var_r29_1406 < 0x14);
}
