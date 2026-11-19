void GuardianCage::StateDyingEnter() {
    u8 spRes[0x58];
    MKVector3 sp78;
    MKVector3 sp68;
    f64 sp18;
    f64 sp20;
    f64 spPair;
    f64 sp10Pair;
    f32 p2x;
    f32 p2y;
    f32 p2z;
    void *temp_r4_569;
    MKVector3 *temp_r3_616;

    sp78 = MKVector(0.0f, 800.0f, 0.0f);
    temp_r4_569 = ((u8 *) this->unk8) + 0x30;
    M2C_FIELD(&sp18, f32 *, 0) = M2C_FIELD(temp_r4_569, f32 *, 0) - sp78.unk0;
    M2C_FIELD(&sp18, f32 *, 4) = M2C_FIELD(temp_r4_569, f32 *, 4) - sp78.unk4;
    M2C_FIELD(this, f64 *, 0x108) = sp18;
    M2C_FIELD(&sp20, f32 *, 0) = M2C_FIELD(temp_r4_569, f32 *, 8) - sp78.unk8;
    M2C_FIELD(this, f64 *, 0x110) = sp20;

    M2C_FIELD(spRes, f32 *, 0x00) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x04) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x08) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x10) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x14) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x18) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x20) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x24) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x28) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x2C) = 1.0f;
    M2C_FIELD(spRes, f32 *, 0x30) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x34) = 0.0f;
    M2C_FIELD(spRes, s16 *, 0x38) = 0;
    M2C_FIELD(spRes, s8 *, 0x3A) = 0;
    M2C_FIELD(spRes, s8 *, 0x3B) = 0;
    M2C_FIELD(spRes, s32 *, 0x3C) = 0;
    M2C_FIELD(spRes, f32 *, 0x40) = 3.4028235e38f;
    M2C_FIELD(spRes, s32 *, 0x44) = 0;
    M2C_FIELD(spRes, s32 *, 0x48) = 0;
    M2C_FIELD(spRes, s32 *, 0x4C) = -1;
    M2C_FIELD(spRes, s8 *, 0x50) = 0;

    p2x = M2C_FIELD(temp_r4_569, f32 *, 0) + 0.0f;
    p2y = M2C_FIELD(temp_r4_569, f32 *, 4) + -10000.0f;
    p2z = M2C_FIELD(temp_r4_569, f32 *, 8) + 0.0f;
    sp68.unk0 = p2x;
    sp68.unk4 = p2y;
    sp68.unk8 = p2z;

    temp_r3_616 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
    if (MKCollision_RayCollide(*temp_r3_616, sp68, (MKCollisionResult *) spRes, (MKCollisionMode) 7, 0) != 0) {
        M2C_FIELD(this, f64 *, 0x108) = M2C_FIELD(spRes, f64 *, 0x00);
        M2C_FIELD(this, f64 *, 0x110) = M2C_FIELD(spRes, f64 *, 0x08);
    }

    M2C_FIELD(&spPair, f32 *, 0) = 0.0f;
    M2C_FIELD(&spPair, f32 *, 4) = -1960.0f;
    M2C_FIELD(this, f64 *, 0x118) = spPair;
    M2C_FIELD(&sp10Pair, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f64 *, 0x120) = sp10Pair;
    M2C_FIELD(this, f64 *, 0x128) = M2C_FIELD(this, f64 *, 0xD8);
    M2C_FIELD(this, f64 *, 0x130) = M2C_FIELD(this, f64 *, 0xE0);
}
