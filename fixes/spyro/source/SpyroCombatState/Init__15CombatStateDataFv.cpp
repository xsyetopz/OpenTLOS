void CombatStateData::Init() {
    SetDefaults();
    this->unk51 = 1;
    this->unk52 = 1;
    this->unk53 = 1;
    this->unk34 = 0.0f;
    this->unk3C = 0;
    this->unk20.Set((Targetable *) NULL);
    this->unk38 = 0.0f;
    this->unk48 = 0;
    ((TargetContext *) &this->unk20.unk8)->Set((Targetable *) NULL);
}
