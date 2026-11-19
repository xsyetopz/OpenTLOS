void SplitPath::Deinit() {
    s32 i;
    s32 off;
    void *buf;

    off = 0;
    for (i = 0; i < this->unk4; i++) {
        ((KDUniformSpline *) M2C_FIELD(this->unk0, void **, off))->Deinit();
        operator delete(M2C_FIELD(this->unk0, void **, off));
        off += 0x14;
    }
    buf = this->unk0;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(buf, NULL, 0);
        return;
    }
    free(buf);
}
