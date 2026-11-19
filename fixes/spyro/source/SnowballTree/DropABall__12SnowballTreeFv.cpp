void SnowballTree::DropABall() {
    s32 i;

    for (i = 0; i < 3; i++) {
        if ((*(Ball **) ((u8 *) this + 0x90 + i * 4))->unk270 == 1) {
            (*(Ball **) ((u8 *) this + 0x90 + i * 4))->DropFromTree();
            return;
        }
    }
}
