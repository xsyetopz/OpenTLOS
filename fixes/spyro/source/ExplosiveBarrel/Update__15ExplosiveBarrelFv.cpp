void *ExplosiveBarrel::Update() {
    f64 volumeLo;
    f64 volumeHi;
    f32 inside;
    f32 zero;
    void *volume;
    ExplosiveBarrelDescriptor *desc;

    Shatterable::Update();
    ((KDSoundPlayer *) &this->unk1BC)->Update(GS_TNTBarrelFuseLP, 1U, this->unk1BA, (MKProp *) this, NULL, 0U, -1, 1);
    zero = 0.0f;
    inside = 0.0f;
    if ((u8) this->unk1B9 == 0) {
        volume = this->unk8;
        volumeLo = M2C_FIELD(volume, f64 *, 0x30);
        volumeHi = M2C_FIELD(volume, f64 *, 0x38);
        if ((((KDWaterVolume *) &volumeLo)->IsWithin(*((MKVector3 *) &zero), &inside, (int *) volume) != 0) && (M2C_BITWISE(s32, inside) == 1)) {
            this->unk1B9 = 1;
            this->unk1B4 = 2;
        }
    }
    switch (this->unk1B4) {
    case 1:
        if (this->unk1AC->Burnt() != 0) {
            Explode();
            break;
        }
        return this->unk1AC->Update();
    case 2:
        Explode();
        break;
    case 3:
        desc = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if ((this->unk16C == 0) || ((this->unk180 == desc->unk160) && (M2C_FIELD(this->unk168, s32 *, (((this->unk180 - 1) << 7) + 0x44)) == 2))) {
            SetActive(false);
            this->unk1B4 = 4;
        }
        break;
    case 4:
        break;
    default:
        return this->unk1AC->Update();
    }
}
