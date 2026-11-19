void CombatStateData::SetLastCombatEnemy(MKProp *arg0) {
    if ((arg0 == NULL) || !(M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x208)) {
        this->unk20.Set((Targetable *) NULL);
        return;
    }
    this->unk20.Set(arg0);
}
