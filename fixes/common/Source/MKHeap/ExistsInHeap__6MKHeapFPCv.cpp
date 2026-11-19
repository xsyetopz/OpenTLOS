u8 MKHeap::ExistsInHeap(const void *arg0) {
    u8 var_r5_87;

    var_r5_87 = 0;
    if (((u32) arg0 >= (u32) this->unk0) && ((u32) arg0 < (u32) this->unk4)) {
        var_r5_87 = 1;
    }
    return var_r5_87;
}
