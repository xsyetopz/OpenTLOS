u8 SpyroStartCycleAnimTable::IsAnimInTable(Spyro *arg0, MKAnim *arg1) {
    u8 var_r6_102;
    u8 var_r7_105;
    u8 *temp_r4_107;

    var_r6_102 = 0;
    if (arg1 != NULL) {
        var_r7_105 = 1;
        temp_r4_107 = (u8 *) arg0->unkB4 + 4;
        if (((u32) arg1 != *(u32 *) (temp_r4_107 + (this->unk0 * 8))) && ((u32) arg1 != *(u32 *) (temp_r4_107 + (this->unk4 * 8)))) {
            var_r7_105 = 0;
        }
        if (var_r7_105 != 0) {
            var_r6_102 = 1;
        }
    }
    return var_r6_102;
}
