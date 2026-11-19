void FuryFXFire2::UpdateMeteors() {
    f64 sp18;
    f64 sp10;
    FuryFXFire2::Meteor **temp_r3_421;
    FuryFXFire2::Meteor **var_r30_362;
    MKProp *temp_r6_406;
    f32 temp_f1_391;
    s32 temp_r0_365;
    FuryFXFire2::Meteor *temp_r31_433;
    FuryFXFire2::Meteor *temp_r4_424;

    var_r30_362 = this->unk150;
loop_9:
    if (var_r30_362 != NULL) {
        temp_r31_433 = *var_r30_362;
        if (temp_r31_433 != NULL) {
            temp_r0_365 = M2C_FIELD(temp_r31_433, s32 *, 0x44);
            switch (temp_r0_365) {                  /* irregular */
            case 1:
                sp10 = M2C_FIELD(temp_r31_433, f64 *, 0x30);
                sp18 = M2C_FIELD(temp_r31_433, f64 *, 0x38);
                (*(f32 *) ((u8 *) &sp10 + 0x4)) += -3500.0f * gUpdateTimeDelta;
                M2C_FIELD(temp_r31_433, f32 *, 0x30) = *(f32 *) &sp10;
                M2C_FIELD(temp_r31_433, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp10 + 0x4));
                M2C_FIELD(temp_r31_433, f32 *, 0x38) = *(f32 *) &sp18;
                M2C_FIELD(temp_r31_433, f32 *, 0x3C) = 1.0f;
                temp_f1_391 = M2C_FIELD(temp_r31_433, f32 *, 0x40);
                if ((*(f32 *) ((u8 *) &sp10 + 0x4)) <= temp_f1_391) {
                    (*(f32 *) ((u8 *) &sp10 + 0x4)) = temp_f1_391;
                    KDSound_Stop((int *) (((u8 *) temp_r31_433) + 0x48));
                    temp_r6_406 = (MKProp *) (gb.unk0->GetProp());
                    this->unk154->Trigger(*((MKVector3 *) &sp10), 0.4f, 1U, temp_r6_406, 0, 1U, 1U, 1U, 1U);
                    M2C_FIELD(temp_r31_433, s32 *, 0x44) = 2;
                }
                break;
            case 2:
                temp_r3_421 = this->unk150;
                this->unk150 = temp_r3_421 + 1;
                temp_r4_424 = *temp_r3_421;
                *temp_r3_421 = *var_r30_362;
                *var_r30_362 = temp_r4_424;
                break;
            }
            var_r30_362 += 1;
            goto loop_9;
        }
    }
}
