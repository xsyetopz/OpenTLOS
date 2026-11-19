MKParticleChunk *MKParticleSystem_AllocChunk(int arg0) {
    MKParticleChunk **temp_r3_105;
    MKParticleChunk *temp_r3_111;
    s32 var_ctr_116;
    s32 var_r4_110;
    s32 var_r6_106;
    void *temp_r5_120;

    if ((u32) M2C_FIELD(gParticleChunks, u32 *, -4) == 0U) {
        return NULL;
    }
    temp_r3_105 = gParticleChunks - 1;
    var_r6_106 = 0;
    gParticleChunks = temp_r3_105;
    var_r4_110 = 0;
    temp_r3_111 = *temp_r3_105;
    M2C_FIELD(temp_r3_111, s32 *, 0xA84) = 0;
    M2C_FIELD(temp_r3_111, s32 *, 0xA88) = 0;
    M2C_FIELD(temp_r3_111, s32 *, 0xA8C) = 0;
    M2C_FIELD(temp_r3_111, s32 *, 0x480) = -1;
    for (var_ctr_116 = 0; var_ctr_116 < 0x18; var_ctr_116++) {
        temp_r5_120 = (u8 *) temp_r3_111 + var_r6_106 + 0x484;
        M2C_FIELD(temp_r3_111, void **, var_r4_110 + 0x2C) = temp_r5_120;
        var_r6_106 += 0x40;
        var_r4_110 += 0x30;
    }
    return temp_r3_111;
}
