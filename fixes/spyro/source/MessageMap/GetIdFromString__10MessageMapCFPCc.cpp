s32 MessageMap::GetIdFromString(const char *arg0) const {
    s32 stricmp(s8 *, s8 *);
    s8 **temp_r29_48;
    s32 temp_r30_50;
    s32 var_r28_51;
    s32 var_r31_52;

    temp_r29_48 = M2C_FIELD(this, s8 ***, 8);
    temp_r30_50 = this->unk4;
    var_r28_51 = 0;
    var_r31_52 = 0;
loop_4:
    if (var_r28_51 >= temp_r30_50) {
        return 0;
    }
    if (stricmp((s8 *) arg0, *(s8 **) ((s8 *) temp_r29_48 + var_r31_52)) == 0) {
        return var_r28_51 + this->unk0;
    }
    var_r28_51 += 1;
    var_r31_52 += 4;
    goto loop_4;
}
