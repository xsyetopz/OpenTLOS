void EnemySettings::InitToOne(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        M2C_FIELD(this, f32 *, i * 4) = 1.0f;
    }
}
