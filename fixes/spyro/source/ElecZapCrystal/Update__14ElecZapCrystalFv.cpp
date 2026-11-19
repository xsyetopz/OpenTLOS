void *ElecZapCrystal::Update() {
    MKVector3 velRand;
    MKVector3 velMin;
    MKVector3 velMax;
    MKVector3 velocity;
    MKVector4 burstColor;
    MKVector4 sparkColor;
    f32 life;
    f32 lifeMax;
    f32 fader;
    f32 lifetime;
    f32 alpha;
    s32 index;
    s32 i;
    void **slot;
    void **head;
    void *entry;
    void *temp;

    slot = (void **) this->unkB0;
    while (slot != NULL) {
        entry = *slot;
        if (entry == NULL) {
            break;
        }
        life = M2C_FIELD(entry, f32 *, 8) - gUpdateTimeDelta;
        lifeMax = M2C_FIELD(entry, f32 *, 4);
        if (life < lifeMax) {
        } else {
            life = lifeMax;
        }
        if (life <= 0.0f) {
            life = 0.0f;
        }
        M2C_FIELD(entry, f32 *, 8) = life;
        if (M2C_FIELD(entry, f32 *, 8) <= 0.0f) {
            head = (void **) this->unkB0;
            this->unkB0 = (void *) ((u8 *) head + 4);
            temp = *head;
            *head = *slot;
            *slot = temp;
        }
        slot += 1;
    }
    this->unkBC = this->unkBC - gUpdateTimeDelta;
    switch (this->unkB4) {
    case 0:
        if (this->unkBC <= 0.0f) {
            fader = MKRand_Float((int *) &gViewSeed, 0.2f, 0.5f);
            index = MKRand_Int((int *) &gViewSeed, 0, 4);
            this->TriggerSubObjFader(((s32 *) ((u8 *) this + 0xA0))[index], fader);
            this->unkB4 = 1;
            this->unkBC = 0.5f;
            MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkB8, &this->unkD8);
            KDSound_Play3d(GS_LightningCrystal1, &this->unkD8, 0U, -1, 0.0f, 0U);
            burstColor.unk0 = 1.0f;
            burstColor.unk4 = 0.8f;
            burstColor.unk8 = 0.9f;
            burstColor.unkC = 1.0f;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(this->unkD8, MKVector3::zero, 60.0f, burstColor, 0.0f);
            i = 0;
            do {
                velMin.unk0 = -1.0f;
                velMin.unk4 = 0.0f;
                velMin.unk8 = -1.0f;
                velMax.unk0 = 1.0f;
                velMax.unk4 = 1.0f;
                velMax.unk8 = 1.0f;
                velRand = KDRand_Vector(velMin, velMax);
                velocity.unk0 = velRand.unk0 * 2000.0f;
                velocity.unk4 = velRand.unk4 * 2000.0f;
                velocity.unk8 = velRand.unk8 * 2000.0f;
                lifetime = MKRand_Float((int *) &gViewSeed, 10.0f, 20.0f);
                alpha = MKRand_Float((int *) &gViewSeed, 0.4f, 1.0f);
                sparkColor.unk0 = 1.0f;
                sparkColor.unk4 = 0.4f;
                sparkColor.unk8 = alpha;
                sparkColor.unkC = 1.0f;
                ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(this->unkD8, velocity, lifetime, sparkColor, -2000.0f);
                i += 1;
            } while (i < 0x14);
        }
        break;
    case 1:
        this->unkC0 = this->unkC0 - gUpdateTimeDelta;
        if (this->unkC0 <= 0.0f) {
            fader = MKRand_Float((int *) &gViewSeed, 0.1f, 0.4f);
            index = MKRand_Int((int *) &gViewSeed, 0, 3);
            this->TriggerSubObjFader(((s32 *) ((u8 *) this + 0x94))[index], fader);
            KDSound_Play3d(GS_LightningCrystal2, &this->unkD8, 0U, -1, 0.0f, 0U);
            this->unkC0 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.2f);
        }
        if (this->unkBC <= 0.0f) {
            this->unkB4 = 0;
            this->unkBC = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        }
        break;
    }
}
