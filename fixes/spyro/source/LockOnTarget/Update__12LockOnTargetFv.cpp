void *LockOnTarget::Update() {
    LockOnTargetDescriptor *desc;
    f32 temp_f1_451;

    switch (this->unk60) {
    case 1:
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk64 = -((4.0f * gUpdateTimeDelta * desc->unk68) - this->unk64);
        this->unk6C += 1.570796f * gUpdateTimeDelta;
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (this->unk64 <= desc->unk68) {
            this->unk60 = 2;
            desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            this->unk64 = desc->unk68;
        }
        return;
    case 3:
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk74 = -((2.0f * gUpdateTimeDelta * desc->unk68) - this->unk74);
        if (this->unk74 < 0.0f) {
            this->unk60 = 0;
            Disable();
        }
        /* fallthrough */
    case 2:
        this->unk70 += 3.1415927f * gUpdateTimeDelta;
        temp_f1_451 = this->unk70;
        if (temp_f1_451 > 6.2831855f) {
            this->unk70 = temp_f1_451 - 6.2831855f;
        }
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk64 = (0.07f * _table_sinf(this->unk70)) + desc->unk68;
        break;
    }
}
