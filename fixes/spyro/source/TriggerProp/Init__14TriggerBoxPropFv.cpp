void TriggerBoxProp::Init() {
    TriggerProp::Init();
    ((TriggerBoxObject *) ((u8 *) this + 0xD0))->Init();
    this->unkA8 = (TriggerObject *) ((u8 *) this + 0xD0);
}
