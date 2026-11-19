s32 ShatterableBoat::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    MKVector3 sp18;
    void *temp_r4_229;

    sp18 = MKVector(0.0f, 100.0f, 0.0f);
    temp_r4_229 = ((u8 *) this->unk8) + 0x30;
    arg1->unk0 = M2C_FIELD(temp_r4_229, f32 *, 0) + sp18.unk0;
    arg1->unk4 = M2C_FIELD(temp_r4_229, f32 *, 4) + sp18.unk4;
    arg1->unk8 = M2C_FIELD(temp_r4_229, f32 *, 8) + sp18.unk8;
    return 1;
}
