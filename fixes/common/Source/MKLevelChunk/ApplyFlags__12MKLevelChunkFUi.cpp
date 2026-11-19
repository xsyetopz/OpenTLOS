void MKLevelChunk::ApplyFlags(unsigned int arg0) {
    u32 temp_r3;

    temp_r3 = M2C_FIELD(this, u32 *, 0x13C) & 2;
    if ((temp_r3 == 0) && (arg0 & 4)) {
        MKCollision_AddManager(M2C_FIELD(this, MKCollisionManager **, 0x94));
        M2C_FIELD(this, u32 *, 0x13C) |= 2;
    } else if ((temp_r3 != 0) && !(arg0 & 4)) {
        MKCollision_RemoveManager(M2C_FIELD(this, MKCollisionManager **, 0x94));
        M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFFFFFD;
    }
    M2C_FIELD(this, u32 *, 0x138) = arg0;
}
