MKHeap *MKStringCache::GetUsedLength() {
    s8 *var_r31_16;

    var_r31_16 = &this->unk1;
    while (*var_r31_16 != 0) {
        var_r31_16 = &var_r31_16[strlen((const char *) var_r31_16)] + 1;
    }
    return (MKHeap *) ((u32) ((s8 *) var_r31_16 - (s8 *) this) + 1);
}
