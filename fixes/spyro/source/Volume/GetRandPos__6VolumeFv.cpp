MKVector3 Volume::GetRandPos() {
    MKVector3 result;
    f32 x0;
    f32 y0;
    f32 z0;
    f32 ax;
    f32 ay;
    f32 az;

    x0 = M2C_FIELD(Volume::boundingVolume, f32 *, 0x18) * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    y0 = M2C_FIELD(Volume::boundingVolume, f32 *, 0x14) * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    z0 = M2C_FIELD(Volume::boundingVolume, f32 *, 0x10) * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    ax = M2C_FIELD(Volume::boundingVolume, f32 *, 0x0) + z0;
    ay = M2C_FIELD(Volume::boundingVolume, f32 *, 0x4) + y0;
    az = M2C_FIELD(Volume::boundingVolume, f32 *, 0x8) + x0;
    result.unk0 = this->unk40.unk30 + ((az * this->unk40.unk20) + ((ax * this->unk40.unk0) + (ay * this->unk40.unk10)));
    result.unk4 = this->unk40.unk34 + ((az * this->unk40.unk24) + ((ax * this->unk40.unk4) + (ay * this->unk40.unk14)));
    result.unk8 = this->unk40.unk38 + ((az * this->unk40.unk28) + ((ax * this->unk40.unk8) + (ay * this->unk40.unk18)));
    return result;
}
