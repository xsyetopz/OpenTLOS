void ShatterableBoat::Deinit() {
    this->unk24C->Destroy();
    this->unk258->Destroy();
    ((KDUniformSpline *) &this->unk218)->Deinit();
    MKModel_Destroy(this->unk310);
    ShatterableBoatDescriptor *desc = checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(desc, s32 *, 0x16C) != 0) {
        KDSound_Stop((int *) &this->unk338);
    }
    ShatterablePlatform::Deinit();
}
