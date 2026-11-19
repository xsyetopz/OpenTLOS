void EventMessage::Deinit() {
    s32 temp_r4_96;

    temp_r4_96 = this->unk0;
    if ((u32) temp_r4_96 != 0U) {
        (*(UIStringTable **) ChunkData::pCurrentEventStrings)->Remove((const char *) temp_r4_96);
    }
    this->unk0 = 0;
}
