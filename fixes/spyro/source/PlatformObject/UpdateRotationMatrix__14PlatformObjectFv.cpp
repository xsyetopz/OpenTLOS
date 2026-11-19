void PlatformObject::UpdateRotationMatrix() {
    Matrix sp50;
    Matrix sp10;

    if ((u8) this->unk0->unk11 != 0) {
        M2C_STRUCT_COPY(&sp10, this->unk40->unk8, 0x40);
        sp10.SetRotationPitch(this->unk8);
        sp50.SetRotationRoll(this->unk10);
        sp10.Multiply3x3(&sp10, &sp50);
        sp50.SetRotationYaw(this->unkC);
        sp10.Multiply3x3(&sp10, &sp50);
        sp10.Scale3x3(&sp10, this->unk18);
        MKModel_SetWorldMatrix(this->unk40->unk4, sp10);
    }
}
