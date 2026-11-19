void *LightManager::AllocManagedLight(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, const float &arg3, const int &arg4, const bool &arg5) {
    u8 *light;
    s32 i;

    for (i = 0; i < 0x48; i++) {
        light = ((u8 *) this->unk5C) + i * 0x50;
        if (M2C_FIELD(light, u8 *, 0x48) == 0) {
            M2C_FIELD(light, s8 *, 0x34) = 0;
            M2C_FIELD(light, u8 *, 0x48) = 1;
            M2C_FIELD(light, f32 *, 0x38) = arg3;
            M2C_FIELD(light, s32 *, 0x30) = arg4;
            M2C_FIELD(light, f64 *, 0x20) = M2C_FIELD(&arg2, f64 *, 0);
            M2C_FIELD(light, f64 *, 0x28) = M2C_FIELD(&arg2, f64 *, 8);
            M2C_FIELD(light, f64 *, 0) = M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(light, f64 *, 8) = M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(light, f64 *, 0x10) = M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(light, f64 *, 0x18) = M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(light, u8 *, 0x40) = (u8) arg5;
            M2C_FIELD(light, s32 *, 0x44) = -1;
            M2C_FIELD(light, s32 *, 0x3C) = 0;
            return light;
        }
    }
    return NULL;
}
