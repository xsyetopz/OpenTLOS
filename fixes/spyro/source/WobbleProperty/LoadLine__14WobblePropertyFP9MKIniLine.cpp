s32 WobbleProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31;

    if (*(u32 *) &this->unk10 == 0) {
        *(MKIniLine **) &this->unk10 = arg0;
    }
    var_r31 = 0;
    if (((u8) arg0->LoadFloat("collisionradius", &this->unk18, 0) != 0) || ((u8) arg0->LoadFloat("antispamDelay", &this->unk1C, 0) != 0) || ((u8) arg0->LoadFloat("HitSoundSensitivity", &this->unk20, 0) != 0) || ((u8) KDSound_LoadLine(arg0, "hitSound", (int *) &this->unk30) != 0)) {
        var_r31 = 1;
    }
    return var_r31;
}
