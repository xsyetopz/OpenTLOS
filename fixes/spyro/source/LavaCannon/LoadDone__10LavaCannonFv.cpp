s32 LavaCannon::LoadDone() {
    Matrix sp70;
    Matrix sp30;
    MKVector3 sp20;

    Shatterable::LoadDone();
    this->unk244 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x54);
    M2C_STRUCT_COPY(&sp70, (const void *) MKModel_GetWorldMatrix(this->unk4), 0x40);
    sp20.unk0 = 0.0f;
    sp20.unk4 = 0.0f;
    sp20.unk8 = 0.0f;
    sp70.SetRotationPYR(sp20);
    MKModel_SetWorldMatrix(this->unk4, sp70);
    M2C_STRUCT_COPY(&sp30, (const void *) MKModel_GetWorldMatrix(this->unk4), 0x40);
    sp30.Scale3x3(&sp30, *(MKVector3 *) ((s8 *) &MKProp::loadInfo + 0x60));
    MKModel_SetWorldMatrix(this->unk4, sp30);
}
