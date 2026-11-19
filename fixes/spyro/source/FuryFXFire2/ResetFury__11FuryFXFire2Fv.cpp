void FuryFXFire2::ResetFury() {
    f64 sp18;
    f64 sp10;
    FuryFXFire2::Meteor **var_r29_55;
    FuryFXFire2::Meteor *temp_r30_100;
    FuryFXFire2::Meteor **temp_r3_88;
    FuryFXFire2::Meteor *temp_r4_91;
    MKProp *temp_r6_75;

    SetDefaults();
    var_r29_55 = this->unk150;
loop_4:
    if (var_r29_55 != NULL) {
        temp_r30_100 = *var_r29_55;
        if (temp_r30_100 == NULL) {
        } else {
            if ((s32) M2C_FIELD(temp_r30_100, s32 *, 0x44) != 2) {
                sp10 = M2C_FIELD(temp_r30_100, f64 *, 0x30);
                sp18 = M2C_FIELD(temp_r30_100, f64 *, 0x38);
                KDSound_Stop((int *) (((u8 *) temp_r30_100) + 0x48));
                temp_r6_75 = (MKProp *) (gb.unk0->GetProp());
                this->unk154->Trigger(*((MKVector3 *) &sp10), 0.4f, 1U, temp_r6_75, 0, 1U, 1U, 1U, 1U);
                M2C_FIELD(temp_r30_100, s32 *, 0x44) = 2;
                temp_r3_88 = this->unk150;
                this->unk150 = temp_r3_88 + 1;
                temp_r4_91 = *temp_r3_88;
                *temp_r3_88 = *var_r29_55;
                *var_r29_55 = temp_r4_91;
            }
            var_r29_55 += 1;
            goto loop_4;
        }
    }
loop_8:
    if (*this->unk150 != NULL) {
        this->unk150 = this->unk150 + 1;
        goto loop_8;
    }
    gb.EnableSlowMotion(0U, -1.0f, 0.5f);
    this->unk158 = -1;
}
