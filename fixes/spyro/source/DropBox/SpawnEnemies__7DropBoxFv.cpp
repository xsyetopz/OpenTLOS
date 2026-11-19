void DropBox::SpawnEnemies() {
    u8 sp1C[0x40];
    MKVector3 sp10;
    f32 sp5C;
    SpawnerObject *temp_r4_724;
    s32 temp_r0_734;
    s32 temp_r0_747;
    s32 temp_r0_777;
    s32 temp_r0_807;
    s32 temp_r0_837;
    s32 var_r29_670;
    s32 var_r31_668;
    u8 *temp_r27_683;
    DropBoxDescriptor *temp_desc_170;

    this->unk1D4->RemoveAllSpawnPoints(0U);
    var_r31_668 = 0;
    this->unk1D4->unk18 = this->unk18;
    var_r29_670 = 0;
loop_2:
    if ((var_r31_668 < 4) && (var_r31_668 < (s32) this->unk210)) {
        M2C_STRUCT_COPY(sp1C, &Matrix::identity, 0x40);
        temp_r27_683 = (u8 *) this + var_r29_670;
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r27_683, s32 *, 0x1E0), &sp10);
        *(f32 *) (sp1C + 0x34) = sp10.unk0;
        *(f32 *) (sp1C + 0x38) = sp10.unk4;
        *(f32 *) (sp1C + 0x3C) = sp10.unk8;
        sp5C = 1.0f;
        M2C_STRUCT_COPY((u8 *) M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC) + 0xC, sp1C, 0x40);
        M2C_FIELD(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC)->unk4, s32 *, 4) = 0x4000;
        this->unk1D4->AddSpawnPoint(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC));
        var_r31_668 += 1;
        var_r29_670 += 8;
        goto loop_2;
    }
    this->unk1D4->AddSpawnPointEnd();
    temp_r4_724 = this->unk1D4;
    if ((s32) temp_r4_724->unk20 >= (s32) temp_r4_724->unk24) {
        temp_r4_724->unk20 = 0;
    }
    temp_desc_170 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r0_734 = M2C_FIELD(temp_desc_170, s32 *, 0x170);
    switch (temp_r0_734) {
    case 0:
        temp_r0_747 = this->unk214;
        switch (temp_r0_747) {
        case 0:
            this->unk1D4->TrySpawnItems(7, 1U);
            return;
        case 1:
            this->unk1D4->TrySpawnItems(8, 1U);
            return;
        case 2:
            this->unk1D4->TrySpawnItems(9, 1U);
            return;
        }
        break;
    case 1:
        temp_r0_777 = this->unk214;
        switch (temp_r0_777) {
        case 0:
            this->unk1D4->TrySpawnItems(0xA, 1U);
            return;
        case 1:
            this->unk1D4->TrySpawnItems(0xB, 1U);
            return;
        case 2:
            this->unk1D4->TrySpawnItems(0xC, 1U);
            return;
        }
        break;
    case 2:
        temp_r0_807 = this->unk214;
        switch (temp_r0_807) {
        case 0:
            this->unk1D4->TrySpawnItems(1, 1U);
            return;
        case 1:
            this->unk1D4->TrySpawnItems(2, 1U);
            return;
        case 2:
            this->unk1D4->TrySpawnItems(3, 1U);
            return;
        }
        break;
    case 3:
        temp_r0_837 = this->unk214;
        switch (temp_r0_837) {
        case 0:
            this->unk1D4->TrySpawnItems(4, 1U);
            return;
        case 1:
            this->unk1D4->TrySpawnItems(5, 1U);
            return;
        case 2:
            this->unk1D4->TrySpawnItems(6, 1U);
            break;
        }
        break;
    }
}
