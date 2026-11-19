void SpawnerObject::Init(void (*arg0)(SpawnAction, int, MKProp **, SpawnerObject *), int arg1) {
    s32 temp_r3_1769;
    s32 temp_r4_1775;
    s32 var_ctr_1767;
    s32 var_r5_1763;
    u32 *var_r3_1754;

    this->unk14.unk0 = arg1;
    this->unkC.unk0 = (s32) arg0;
    this->unk24 = 0;
    this->unk28 = 0;
    this->unk2C = 0;
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    this->unk4C &= ~0x40;
    this->unk4C &= ~0x80;
    this->unk4C &= ~0x20;
    this->unk4C &= ~0x10;
    this->unk18 = 1;
    this->unk3C.Init();
    this->unk40.Init();
    this->unk4 = NULL;
    if (MKHeap::Current() != NULL) {
        var_r3_1754 = (unsigned long *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x38, NULL, 0));
    } else {
        var_r3_1754 = malloc(0x38);
    }
    this->unk8.unk0 = (s32) var_r3_1754;
    var_r5_1763 = this->unk8.unk0;
    this->unk8.unk0 = var_r5_1763 + 0x20;
    M2C_FIELD(var_r5_1763, s32 *, 0x20) = 0;
    var_ctr_1767 = 4;
    do {
        temp_r3_1769 = this->unk8.unk0;
        this->unk8.unk0 = temp_r3_1769 + 4;
        M2C_FIELD(temp_r3_1769, s32 *, 4) = var_r5_1763;
        var_r5_1763 += 8;
        var_ctr_1767 -= 1;
    } while (var_ctr_1767 != 0);
    temp_r4_1775 = this->unk8.unk0;
    this->unk8.unk0 = temp_r4_1775 + 4;
    M2C_FIELD(temp_r4_1775, s32 *, 4) = 0;
    SetDefaults();
}
