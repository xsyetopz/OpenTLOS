void FlyingChunkPS::Draw() {
    Matrix sp10;
    s32 i;
    Matrix **var_r30_438;
    Matrix *temp_r31_470;

    var_r30_438 = this->unkD8;
loop_2:
    if (var_r30_438 != NULL) {
        temp_r31_470 = *var_r30_438;
        if (temp_r31_470 != NULL) {
            for (i = 0; i < 0x40; i += 4) {
                M2C_FIELD(&sp10, u32 *, i) = M2C_FIELD(temp_r31_470, u32 *, i);
            }
            MKModel_SetWorldMatrix(this->unk4, sp10);
            MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r31_470, s32 *, 0x94), 1U, 1U);
            MKModel_SetColor(this->unk4, M2C_FIELD(temp_r31_470, MKVector4 *, 0x60));
            MKModel_Draw(this->unk4, NULL);
            var_r30_438 += 4;
            goto loop_2;
        }
    }
}
