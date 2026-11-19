s32 ExplosiveBarrelPath::SpawnBarrel(MKProp *arg0) {
    s32 id;
    s32 off;
    s8 *slot;

    id = GetNextInactiveBarrelID();
    if (id > -1) {
        off = id * 0x44;
        slot = (s8 *) this + off;
        M2C_FIELD(slot, f32 *, 0x7C) = 0.0f;
        M2C_FIELD(slot, f32 *, 0x80) = 0.0f;
        M2C_FIELD(slot, f32 *, 0x84) = 0.0f;
        M2C_FIELD(slot, f32 *, 0x88) = 0.0f;
        M2C_FIELD(slot, f32 *, 0x8C) = 0.0f;
        M2C_FIELD(slot, s8 *, 0x90) = 0;
        UpdateBarrelModel((ExplosiveBarrelPath::BarrelData *) (slot + 0x78));
        M2C_FIELD(slot, ExplosiveBarrel **, 0x78)->SetDefaults();
        M2C_FIELD(slot, ExplosiveBarrel **, 0x78)->SetActive(1);
    }
    this->unk4C = arg0;
    return id;
}
