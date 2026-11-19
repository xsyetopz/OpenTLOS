void Shadow::GetLightPos(MKVector3 *arg0) {
    MKVector3 sp38;
    f32 sp18x;
    f32 sp18y;
    f32 sp18z;

    MKModel_CalculateCentre(this->unk10, &sp38);
    sp18x = this->unk0 * this->unk20;
    sp18y = this->unk4 * this->unk20;
    sp18z = this->unk8 * this->unk20;
    arg0->unk0 = sp38.unk0 - sp18x;
    arg0->unk4 = sp38.unk4 - sp18y;
    arg0->unk8 = sp38.unk8 - sp18z;
}
