void CynderEnergyCrystal::UpdateMovement() {
    typedef void (*MoveFn)(void *, void *, s32, f32);
    typedef void (*PosFn)(void *, void *);
    f32 sp8[3];

    if ((this->unkC8 == NULL) && (this->unk5E8 == 0)) {
        this->unk15C -= 980.0f * gUpdateTimeDelta * gUpdateTimeDelta;
        if (this->unk15C > -1500.0f) {
        } else {
            this->unk15C = -1500.0f;
        }
        ((MoveFn) ((void **) this->unk168)[4])((void *) &this->unk168, (void *) &this->unk158, 0, 0.0f);
        ((PosFn) ((void **) this->unk168)[0x4C / 4])((void *) sp8, (void *) &this->unk168);
        this->unkD0.unk30 = sp8[0];
        this->unkD0.unk34 = sp8[1];
        this->unkD0.unk38 = sp8[2];
        this->unkD0.unk3C = 1.0f;
        this->unk5E8 = this->unk2D4 > 0;
        if (this->unk5E8 != 0) {
            KDSound_Play3d(GS_EnergyCrystalBounce, (MKVector3 *) &this->unkD0.unk30, 0U, -1, 0.0f, 0U);
            M2C_FIELD(this, f32 *, 0x158) = 0.0f;
            this->unk15C = 0.0f;
            this->unk160 = 0.0f;
            this->unkD0.SetRotationToNone();
            this->unk5E0->Reset();
            this->unk5E0->unk30 = 0;
        }
    }
}
