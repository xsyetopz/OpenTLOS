void BigBeetleHiveDescriptor::LoadDone() {
    s32 temp_r0_746;
    s32 var_r29_734;
    s32 var_r31_736;
    u16 temp_r3_744;

    ShatterableDescriptor::LoadDone();
    var_r29_734 = 0;
    var_r31_736 = 0;
    do {
        temp_r3_744 = Tools_GetMatchingRefPointIndex(this->unk2C, (const char *) Str_Printf("r_fxemit%d", var_r29_734));
        var_r29_734 += 1;
        temp_r0_746 = var_r31_736 + 0x170;
        var_r31_736 += 4;
        M2C_FIELD(this, s32 *, temp_r0_746) = (s32) temp_r3_744;
    } while (var_r29_734 < 5);
}
