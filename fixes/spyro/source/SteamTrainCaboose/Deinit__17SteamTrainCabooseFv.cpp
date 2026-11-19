void SteamTrainCaboose::Deinit() {
    if (M2C_FIELD(&gb, u32 *, 0x360) == (u32) this) {
        M2C_FIELD(&gb, u32 *, 0x360) = 0U;
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
    }
    this->unk160->Deinit();
    operator delete(this->unk160);
    this->unk110.RemoveAllSpawnPoints(1U);
    this->unk110.Deinit();
    this->unkE0.Deinit();
    GameProp::Deinit();
}
