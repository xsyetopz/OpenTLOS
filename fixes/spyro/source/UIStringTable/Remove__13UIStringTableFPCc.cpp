s32 UIStringTable::Remove(const char *arg0) {
    MKStringCache *temp_r3_18;
    u8 var_r31_19;

    if (arg0 != NULL) {
        temp_r3_18 = this->unk4;
        var_r31_19 = 0;
        if (((s32) arg0 >= (s32) temp_r3_18) && ((s32) arg0 < (s32) this->unk4 + (s32) temp_r3_18->GetUsedLength())) {
            var_r31_19 = 1;
        }
        if (var_r31_19 == 0) {
            return 0;
        }
        goto block_6;
    }
block_6:
    if (this->unk4->Find(arg0) == NULL) {
        return 0;
    }
    this->unk0 -= 1;
    return 1;
}
