void TargetContext::Set(Targetable *arg0) {
    Targetable *temp_r4_1278;

    this->unk4 = arg0;
    M2C_FIELD(this, s32 *, 0) = -1;
    temp_r4_1278 = this->unk4;
    if (temp_r4_1278 != NULL) {
        M2C_FIELD(this, s32 *, 0) = M2C_FIELD(temp_r4_1278, s32 *, 4);
    }
}
