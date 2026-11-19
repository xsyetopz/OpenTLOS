void TrainTrackDescriptor::Resolve() {
    s32 i;

    MKPropDescriptor::Resolve();
    for (i = 0; i < this->unk27C; i++) {
        *(u32 *) ((s8 *) this + (0x240 + i * 4)) = ((MKSceneManager *) gMK)->FindDescriptor((const char *) ((s8 *) this + (0x60 + i * 0x20)));
    }
}
