void GameData::SetSaveChunk(ChunkInfo *arg0) {
    strcpy((char *) &this->unk190, (char *) arg0->unk0);
    strcpy((char *) &this->unk20, (char *) &this->unk190);
}
