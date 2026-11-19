void GameData::SaveState::ClearData(void) {
    void *chunk;

    memset(this, 0, 0x40);
    ((GameStats *) ((s8 *) this + 0x70))->Clear();
    chunk = M2C_FIELD(&gb, void **, 0x330);
    if (chunk != NULL) {
        strcpy((char *) this + 0x190, *(char **) chunk);
        strcpy((char *) this + 0x20, (char *) this + 0x190);
    }
}
