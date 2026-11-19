s32 CharacterGraphNode::Link(CharacterGraphNode *arg0, int arg1, LinkInformation arg2, KDSplinePathSegmentProp *arg3) {
    s32 var_ctr_784;
    s32 var_r5_783;
    s32 var_r8_782;
    u8 *temp_r5_790;
    u8 *temp_r8_806;

    if (arg1 == -1) {
        var_r8_782 = 0;
        var_r5_783 = 0;
        for (var_ctr_784 = 6; var_ctr_784 != 0; var_ctr_784 -= 1) {
            if (*(u32 *) ((u8 *) this + var_r5_783 + 0x18) == 0) {
                temp_r5_790 = (u8 *) this + var_r5_783;
                M2C_FIELD(temp_r5_790, CharacterGraphNode **, 0x18) = arg0;
                M2C_FIELD(temp_r5_790, s32 *, 0x50) = (s32) arg2;
                M2C_FIELD(temp_r5_790, KDSplinePathSegmentProp **, 0x68) = arg3;
                this->unk30 += 1;
                return var_r8_782;
            }
            var_r8_782 += 1;
            var_r5_783 += 4;
        }
        return -1;
    }
    temp_r8_806 = (u8 *) this + (arg1 * 4);
    if (M2C_FIELD(temp_r8_806, u32 *, 0x18) == 0) {
        M2C_FIELD(temp_r8_806, CharacterGraphNode **, 0x18) = arg0;
        M2C_FIELD(temp_r8_806, s32 *, 0x50) = (s32) arg2;
        M2C_FIELD(temp_r8_806, KDSplinePathSegmentProp **, 0x68) = arg3;
        this->unk30 += 1;
        return arg1;
    }
    return -1;
}
