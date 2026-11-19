void *TotemPolePuzzle::Update() {
    s32 i;
    s32 off;
    TotemPolePiece *piece;

    if (this->unkD8 == 0) {
        off = 0;
        for (i = 0; i < this->unkCC; i++) {
            piece = *(TotemPolePiece **)((u8 *)this->unkC8 + off);
            if (piece->unkD0 != piece->unkD4) {
                goto done;
            }
            off += 4;
        }
        this->unkD8 = 1;
        this->unkD4.Send(NULL);
    }
done:
    ;
}
