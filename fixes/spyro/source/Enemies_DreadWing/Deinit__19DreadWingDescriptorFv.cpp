void DreadWingDescriptor::Deinit() {
    CharacterBodyFXData *body = (CharacterBodyFXData *) ((s8 *) this + 0x244);

    body->Deinit();
    EnemyDescriptor::Deinit();
}
