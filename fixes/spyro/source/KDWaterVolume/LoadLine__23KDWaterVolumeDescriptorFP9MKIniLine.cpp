s32 KDWaterVolumeDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r28_324;
    s32 var_r29_327;
    u32 temp_r5_333;

    if (MKPropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if ((this->unk64 != 0) && (arg0->IsField("volumeType") != 0)) {
        for (var_r28_324 = 0; var_r28_324 < (s16) arg0->unk0; var_r28_324++) {
            for (var_r29_327 = 0; *(u32 *) (((u8 *) this->unk64) + var_r29_327) != 0U; var_r29_327 += 8) {
                temp_r5_333 = this->unk64;
                if (stricmp((s32) *(u32 *) (((u8 *) temp_r5_333) + var_r29_327), arg0->GetString(var_r28_324), temp_r5_333) == 0) {
                    this->unk60 |= *(s32 *) (((u8 *) temp_r5_333) + (var_r29_327 + 4));
                }
            }
        }
        return 1;
    }
    return 0;
}
