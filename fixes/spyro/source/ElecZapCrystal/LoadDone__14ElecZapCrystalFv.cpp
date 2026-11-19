s32 ElecZapCrystal::LoadDone() {
    const char *name;
    s32 i;

    KDProp::LoadDone();
    M2C_FIELD(this, f64 *, 0xC8) = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0xD0) = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78);
    this->unk90 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "BlueCrystal");
    for (i = 0; i < 3; i++) {
        name = (const char *) Str_Printf("Elec%d", i + 1);
        ((s32 *) ((u8 *) this + 0x94))[i] = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, name);
    }
    for (i = 0; i < 4; i++) {
        name = (const char *) Str_Printf("Strike%d", i + 1);
        ((s32 *) ((u8 *) this + 0xA0))[i] = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, name);
    }
    this->unkB8 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "FX");
}
