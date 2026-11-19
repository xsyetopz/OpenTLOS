void GuardianCageCrystal::Deinit() {
    ((Targetable *) ((s8 *) this + 0xC8))->UnregisterTargetable();
    Shatterable::Deinit();
    KDSound_Stop((int *) &this->unk1D8);
}
