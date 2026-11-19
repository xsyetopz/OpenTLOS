void *FireMolePrison::Update() {
    f32 temp_f1_117;

    Shatterable::Update();
    temp_f1_117 = this->unk20C;
    if (temp_f1_117 > 0.0f) {
        this->unk20C = temp_f1_117 - gUpdateTimeDelta;
    }
    if ((IsDead() == 0) && (KDSound_IsVoicePlaying(this->unk208) == 0) && (this->unk20C <= 0.0f)) {
        this->unk20C = MKRand_Float((int *) &gViewSeed, 1.0f, 4.0f);
        this->unk208 = KDSound_Play3d(GS_MoleHelpMe, (const MKVector3 *) ((u8 *) this->unk8 + 0x30), 0U, -1, 0.0f, 0U);
    } else if ((IsDead() != 0) && (KDSound_IsVoicePlaying(this->unk208) != 0)) {
        KDSound_Stop((int *) &this->unk208);
    }
    if ((IsDead() != 0) && ((u8) this->unk210 == 0)) {
        this->unk210 = 1;
        KDSound_Play3d(GS_MoleScurry, (const MKVector3 *) ((u8 *) this->unk8 + 0x30), 0U, -1, 0.0f, 0U);
    }
}
