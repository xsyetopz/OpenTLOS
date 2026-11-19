
u8 EnemyGoal_FlyIdle::Update() {
    MKCollisionResult sp38;
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    MKVector3 sp8;
    AITargetData *temp_r3_1909;
    Character *temp_r29_1862;
    Character *temp_r3_1856;
    Character *temp_r3_1895;
    Character *temp_r3_1925;
    Character *temp_r3_1949;
    Character *temp_r4_1890;
    Character *temp_r4_1978;
    Character *temp_r4_1992;
    f32 temp_f2_1952;
    f32 var_f2_1939;
    s32 temp_r3_1994;
    u32 *temp_r4_1867;
    u32 *temp_r4_1897;
    u8 var_r30_1857;
    u8 var_r30_1913;
    u8 var_r5_1896;
    void *temp_r3_1968;

    ActivateIfInactive();
    temp_r3_1856 = this->unkC;
    var_r30_1857 = 0;
    *(MKVector3 *) ((u8 *) temp_r3_1856 + 0x598) = *(MKVector3 *) ((u8 *) temp_r3_1856 + 0x90);
    temp_r29_1862 = this->unkC;
    if (temp_r29_1862->HasAnimFinished() != 0) {
        temp_r4_1867 = M2C_FIELD(temp_r29_1862, u32 **, 0xA50);
        if ((temp_r4_1867 != NULL) && ((u32) *temp_r4_1867 == (u32) M2C_FIELD(temp_r29_1862->unk630, u32 *, 0x20))) {
            var_r30_1857 = 1;
        }
    }
    if (var_r30_1857 != 0) {
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
        ((Enemy *) this->unkC)->SetIdleMovementSpeed(1U);
        temp_r4_1890 = this->unkC;
        temp_r4_1890->unk68C = M2C_FIELD(M2C_FIELD(temp_r4_1890, void **, 0xA38), f32 *, 0x15C);
    }
    temp_r3_1895 = this->unkC;
    var_r5_1896 = 0;
    temp_r4_1897 = M2C_FIELD(temp_r3_1895, u32 **, 0xA50);
    if ((temp_r4_1897 != NULL) && ((u32) M2C_FIELD(temp_r4_1897, u32 *, 0x20) == (u32) M2C_FIELD(temp_r3_1895->unk630, u32 *, 0x20))) {
        var_r5_1896 = 1;
    }
    if (var_r5_1896 != 0) {
        temp_r3_1909 = this->unk10;
        if (temp_r3_1909 != NULL) {
            var_r30_1913 = 0;
            if (((u8) M2C_FIELD(temp_r3_1909, u8 *, 0x48) == 2) || (temp_r3_1909->unk40.Get() != NULL)) {
                var_r30_1913 = 1;
            }
            if (var_r30_1913 != 0) {
                temp_r3_1925 = this->unkC;
                if (MKCollision_GetGroundPoint(temp_r3_1925->unk588, 500.0f, &sp38, M2C_FIELD(temp_r3_1925->unk110.unk460, s32 *, 0x18), 2, NULL, (MKCollisionMode) 6) != 0) {
                    var_f2_1939 = 80.0f + sp38.unk4;
                } else {
                    sp28 = this->unk10->GetPos();
                    var_f2_1939 = 80.0f + sp28.unk4;
                }
                temp_r3_1949 = this->unkC;
                temp_f2_1952 = var_f2_1939 - temp_r3_1949->unk588.unk4;
                if ((f32) __fabs(temp_f2_1952) > 0.5f) {
                    temp_r3_1949->unk59C += temp_f2_1952 * gUpdateTimeDelta;
                } else {
                    temp_r3_1949->unk59C = 0.0f;
                }
                temp_r3_1968 = M2C_FIELD(this->unkC, void **, 0x8);
                sp18 = M2C_FIELD(temp_r3_1968, f64 *, 0x30);
                sp20 = M2C_FIELD(temp_r3_1968, f64 *, 0x38);
                this->unk10->Update(*((MKVector3 *) &sp18));
                sp8 = this->unk10->GetDir();
                temp_r4_1978 = this->unkC;
                M2C_FIELD(temp_r4_1978, MKVector3 *, 0xE0) = sp8;
                temp_r4_1978->unk6B5 &= ~0x40;
            }
        }
        if (this->unkC->HasAnimFinished() != 0) {
            temp_r4_1992 = this->unkC;
            temp_r3_1994 = M2C_FIELD(temp_r4_1992, s32 *, 0xAEC) + 1;
            M2C_FIELD(temp_r4_1992, s32 *, 0xAEC) = temp_r3_1994;
            if (temp_r3_1994 >= (s32) this->unk14) {
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
