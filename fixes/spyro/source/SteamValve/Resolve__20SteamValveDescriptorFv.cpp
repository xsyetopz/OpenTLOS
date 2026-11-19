void SteamValveDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    M2C_FIELD(this, s32 *, 0xE4) = MKModel_GetRefPointIndex(this->unk2C, "r_fxemit0");
}
