void AnimProperty::LoadDone() {
    f32 temp_f0;
    f32 max;
    s32 i;
    s32 off;

    max = 0.0f;
    i = 0;
    off = 0;
    while (i < (s32) this->unk18) {
        if (*(f32 *) ((s8 *) this->unk14 + off + 4) > max) {
            this->unk1C = i;
            max = *(f32 *) ((s8 *) this->unk14 + off + 4);
        }
        i += 1;
        temp_f0 = *(f32 *) ((s8 *) this->unk14 + off + 4);
        off += 8;
        this->unk20 += temp_f0;
    }
}
