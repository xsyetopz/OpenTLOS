void ExplosiveBarrelDescriptor::LoadDone() {
    Explosion4 *explosion;
    BoundingVolume *bounds;

    ShatterableDescriptor::LoadDone();
    explosion = checked_cast<Explosion4 *, MKProp>(((MKSceneManager *) gMK)->CreateProp("Explosion4"));
    M2C_FIELD(this, Explosion4 **, 0x16C) = explosion;
    this->unk170 = MKModel_GetRefPointIndex(this->unk2C, "r_wick");
    bounds = this->unk1C;
    this->unk174 = 0.5f * (bounds->unk10 - bounds->unk0);
}
