f32 ElementalCombatController::Resolve() {
    s32 *slots;
    s32 value;
    s32 i;

    slots = (s32 *) ((u8 *) this + 0x360);
    for (i = 0; i < 0x10; i++) {
        value = slots[i];
        if (value != 0) {
            slots[i] = (s32) checked_cast<SpawnPoint *, MKProp>(MKSceneManager::PropResolver_Resolve(value));
        }
    }
    return MKProp::Resolve();
}
