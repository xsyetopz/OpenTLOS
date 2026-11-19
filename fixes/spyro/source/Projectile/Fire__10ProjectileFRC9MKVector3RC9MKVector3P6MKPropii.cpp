void Projectile::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    ProjectileDescriptor *desc;
    const MKVector3 *temp_r31_401;
    s32 var_r0_374;

    MKModel_SetPosition(this->unk4, arg0);
    *(MKVector3 *) &this->unkC8 = arg1;
    this->unk14C |= 0x80;
    this->unk14C |= 0x40;
    this->unk130 = arg2;
    this->unk14C |= 0x10;
    this->unk140 = 10.0f;
    if (arg4 != 0) {
        var_r0_374 = arg4;
    } else {
        desc = checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r0_374 = desc->unkEC;
    }
    this->unk148 = var_r0_374;
    if (arg3 != 0) {
        KDSound_Play3d(arg3, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, -1, 0.0f, false);
        return;
    }
    desc = checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (M2C_FIELD(desc, s32 *, 0xE4) != 0) {
        temp_r31_401 = (const MKVector3 *) (((u8 *) this->unk8) + 0x30);
        desc = checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        KDSound_Play3d(M2C_FIELD(desc, s32 *, 0xE4), temp_r31_401, 0U, -1, 0.0f, false);
    }
}
