s32 WaterVolume::LoadDone() {
    Matrix sp10;
    s32 temp_r31_161;

    KDWaterVolume::LoadDone();
    this->unk4 = MKModel_Create((const char *) MKModel_GetName(M2C_FIELD(this->unk0, MKModel **, 0x2C)), NULL, 2, NULL);
    M2C_STRUCT_COPY(&sp10, (u8 *) &this->unk50 + 0x40, 0x40);
    MKModel_SetWorldMatrix(this->unk4, sp10);
    temp_r31_161 = MKModel_GetSubObjectIndex(this->unk4, (SubObjectType) 0, "C_Collide");
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(this->unk4, temp_r31_161, (MKCollisionMode) 1, &this->unkE0, 0U);
}
