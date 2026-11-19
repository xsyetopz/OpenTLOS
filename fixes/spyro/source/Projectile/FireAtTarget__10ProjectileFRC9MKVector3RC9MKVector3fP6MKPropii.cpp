void Projectile::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
    ProjectileDescriptor *desc;
    MKVector3 sp8;
    const MKVector3 *temp_r31_322;
    s32 var_r0_295;

    MKModel_SetPosition(this->unk4, arg0);
    sp8 = Tools_CalculateVelocity(arg0, arg1, arg2, -1960.0f);
    *(MKVector3 *) &this->unkC8 = sp8;
    this->unk14C |= 0x80;
    this->unk14C |= 0x40;
    this->unk130 = arg3;
    this->unk14C |= 0x10;
    this->unk140 = 10.0f;
    if (arg5 != 0) {
        var_r0_295 = arg5;
    } else {
        desc = checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r0_295 = desc->unkEC;
    }
    this->unk148 = var_r0_295;
    if (arg4 != 0) {
        KDSound_Play3d(arg4, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, -1, 0.0f, false);
        return;
    }
    desc = checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (M2C_FIELD(desc, s32 *, 0xE4) != 0) {
        temp_r31_322 = (const MKVector3 *) (((u8 *) this->unk8) + 0x30);
        desc = checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        KDSound_Play3d(M2C_FIELD(desc, s32 *, 0xE4), temp_r31_322, 0U, -1, 0.0f, false);
    }
}
