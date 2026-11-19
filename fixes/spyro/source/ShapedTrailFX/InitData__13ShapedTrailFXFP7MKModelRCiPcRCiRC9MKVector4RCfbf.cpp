void ShapedTrailFX::InitData(MKModel *arg0, const int &arg1, char *arg2, const int &arg3, const MKVector4 &arg4, const float &arg5, bool arg6, float arg7) {
    this->unk78 = arg0;
    this->unk8C = arg1;
    this->unk7C = (MKMaterial *) (MKMaterial_Create(arg2));
    M2C_FIELD(this, f64 *, 0x50) = M2C_FIELD(&arg4, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x58) = M2C_FIELD(&arg4, f64 *, 8);
    this->unk90 = arg3 + 1;
    this->unk98 = arg5;
    this->unkA0 = (this->unkA0 & ~0x20) | ((arg6 << 5) & 0x20);
    this->unk9C = arg7;
}
