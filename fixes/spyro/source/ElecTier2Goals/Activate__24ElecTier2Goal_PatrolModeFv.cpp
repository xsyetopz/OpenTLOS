void ElecTier2Goal_PatrolMode::Activate() {
    MKVector3 sp18;
    MKVector3 sp8;
    Enemy *temp_r30_984;
    Enemy *temp_r3_950;
    Enemy *temp_r4_963;
    f32 temp_f2_997;
    f32 temp_f3_995;
    u8 var_r30_972;
    void **temp_r4_1032;
    void *temp_r3_1036;
    void *temp_r5_1031;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_950 = this->unkC;
    temp_r3_950->unkB08 &= ~0x40;
    if ((u8) this->unk20->unkB11 != 0) {
        AddSubgoal((Goal<Enemy> *) this->unk24);
    }
    temp_r4_963 = this->unkC;
    if (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_963->unkA7C) {
        goto block_11;
    }
    var_r30_972 = 0;
    if (((u8) M2C_FIELD(temp_r4_963, u8 *, 0x8B8) == 2) || (temp_r4_963->unk870.unk40.Get() != NULL)) {
        var_r30_972 = 1;
    }
    if (var_r30_972 != 0) {
        temp_r30_984 = this->unkC;
        if (((u8) M2C_FIELD(temp_r30_984, u8 *, 0x8B9) >> 6U) & 1) {
            sp18 = temp_r30_984->unk870.GetPos();
            temp_f3_995 = sp18.unk8 - temp_r30_984->unk588.unk8;
            temp_f2_997 = sp18.unk0 - temp_r30_984->unk588.unk0;
            if (((temp_f2_997 * temp_f2_997) + (temp_f3_995 * temp_f3_995)) < 250000.0f) {
                sp8 = this->unkC->unk870.GetPos();
                if (this->unkC->unk588.unk4 > sp8.unk4) {
                    AddSubgoal((Goal<Enemy> *) this->unk2C);
                }
            }
            goto block_13;
        }
    }
block_11:
    if (this->unkC->HasWaypoints() != 0) {
        AddSubgoal((Goal<Enemy> *) this->unk28);
        AddSubgoal((Goal<Enemy> *) this->unk30);
        temp_r5_1031 = M2C_FIELD(this->unkC->unkA44, void **, 0x18);
        temp_r4_1032 = this->unk30;
        temp_r3_1036 = (void *) (M2C_FIELD(temp_r5_1031, s32 *, 0x24) + (this->unk20->unkB14 * M2C_FIELD(temp_r5_1031, s32 *, 0x1C)));
        M2C_FIELD(temp_r4_1032, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_1036, f64 *, 0);
        M2C_FIELD(temp_r4_1032, f64 *, 0x20) = (f64) M2C_FIELD(temp_r3_1036, f64 *, 8);
        return;
    }
block_13:
    AddSubgoal((Goal<Enemy> *) this->unk28);
}
