s32 ExplosiveBarrel::LoadDone() {
    ExplosiveBarrelDescriptor *desc;
    BurningWick *wick;
    MKVector3 dir;

    Shatterable::LoadDone();
    wick = checked_cast<BurningWick *, MKProp>(((MKSceneManager *) gMK)->CreateProp("BurningWick"));
    dir.unk0 = 1.0f;
    dir.unk4 = 0.0f;
    dir.unk8 = 0.0f;
    this->unk1AC = wick;
    desc = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk1AC->InitData(desc->unk170, this->unk4, dir);
    SetDefaults();
}
