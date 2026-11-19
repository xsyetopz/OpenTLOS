void LightManager::DisableAllLights() {
    s32 i;
    s32 off;

    i = 0;
    off = 0;
    do {
        EnableLight((ManagedLight *) (((u8 *) this->unk5C) + off), false);
        i += 1;
        off += 0x50;
    } while (i < 0x48);
}
