void *ScorchTrail::Update() {
    s32 i;
    u8 *node;

    i = unk50 + 1;
    if (i >= 0x64) {
        i = 0;
    }
    do {
        node = (u8 *) unk4C + i * 0x30;
        *(f32 *) (node + 0x20) = *(f32 *) (node + 0x20) - gUpdateTimeDelta;
        if (*(f32 *) (node + 0x20) <= 0.0f) {
            *(s32 *) (node + 0x24) = 0;
        }
        i += 1;
        if (i >= 0x64) {
            i = 0;
        }
    } while (i != unk50);
    UpdatePlasmaBubbles();
    UpdateScorchMarks();
}
