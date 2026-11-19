void TargetManager::Init() {
    TargetManager ***var_r3_870;
    TargetManager ***temp_r3_885;
    TargetManager ***temp_r5_890;
    s32 var_ctr_883;

    if (MKHeap::Current() != NULL) {
        var_r3_870 = (TargetManager ***) MKHeap::Current()->Alloc(0x788, NULL, 0);
    } else {
        var_r3_870 = malloc(0x788);
    }
    this->unk0 = var_r3_870;
    *this->unk0 = NULL;
    var_ctr_883 = 0x1E0;
    do {
        temp_r3_885 = this->unk0 + 1;
        this->unk0 = temp_r3_885;
        *temp_r3_885 = (TargetManager **) 0xDEADBEEF;
        var_ctr_883 -= 1;
    } while (var_ctr_883 != 0);
    temp_r5_890 = this->unk0 + 1;
    this->unk0 = temp_r5_890;
    *temp_r5_890 = NULL;
    M2C_FIELD(Targetable::pTargetManager, TargetManager **, 0) = this;
    this->unk4 = 0;
    this->unk8.Set((Targetable *) NULL);
}
