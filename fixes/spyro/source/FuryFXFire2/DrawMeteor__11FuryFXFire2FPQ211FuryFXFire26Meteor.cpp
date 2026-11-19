void FuryFXFire2::DrawMeteor(FuryFXFire2::Meteor *arg1) {
    MKModel_SetWorldMatrix(this->unk148, *((Matrix *) arg1));
    MKModel_Draw(this->unk148, NULL);
}
