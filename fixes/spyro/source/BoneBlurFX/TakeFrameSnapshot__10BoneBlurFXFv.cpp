void BoneBlurFX::TakeFrameSnapshot() {
    s32 temp_r3_265;
    s32 var_r28_216;
    s32 var_r29_218;
    s32 var_r30_217;

    if (this->unk58[0] != NULL) {
        var_r28_216 = 0;
        var_r30_217 = 0;
        var_r29_218 = 0;
        while (var_r28_216 < (s32) this->unk68) {
            u8 *temp_r5_222 = (u8 *) this->unk64 + var_r29_218;
            s32 temp_r0_223 = M2C_FIELD(temp_r5_222, s32 *, 8);
            if (temp_r0_223 == 0) {
                MKModel_CalculateNodeWorldPosition(this->unk74, M2C_FIELD(temp_r5_222, s32 *, 4), (MKVector3 *) ((u8 *) this->unk58[this->unk4C] + var_r30_217));
            } else if (temp_r0_223 == 1) {
                MKModel_CalculateRefPointWorldPosition(this->unk74, M2C_FIELD(temp_r5_222, s32 *, 4), (MKVector3 *) ((u8 *) this->unk58[this->unk4C] + var_r30_217));
            }
            var_r28_216 += 1;
            var_r30_217 += 0x20;
            var_r29_218 += 0xC;
        }
        this->unk4C += 1;
        if ((s32) this->unk4C >= (s32) this->unk54) {
            this->unk4C = 0;
        }
        temp_r3_265 = this->unk50;
        if ((s32) this->unk4C == temp_r3_265) {
            this->unk50 = temp_r3_265 + 1;
            if ((s32) this->unk50 >= (s32) this->unk54) {
                this->unk50 = 0;
            }
        }
    }
}
