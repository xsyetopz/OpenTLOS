void GameStateHeap::Init() {
    s32 temp_r0_103;
    s32 var_ctr_101;
    s32 var_r4_100;

    this->unk0 = -1;
    var_r4_100 = 0;
    var_ctr_101 = 8;
    do {
        temp_r0_103 = var_r4_100 + 4;
        var_r4_100 += 4;
        M2C_FIELD(this, s32 *, temp_r0_103) = -1;
        var_ctr_101 -= 1;
    } while (var_ctr_101 != 0);
}
