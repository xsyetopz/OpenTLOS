void CharacterBodyFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    s32 size;
    s32 i;
    s32 off;
    s32 src;
    void *mem;

    this->unkC = arg1;
    if (arg0->unk4 == 0) {
        this->unk8 = NULL;
        return;
    }
    this->unk8 = arg0;
    if (arg2 == NULL) {
        this->unk11 = 0;
        size = this->unk8->unk4 * 0x70;
        if (MKHeap::Current() != NULL) {
            mem = ((MKHeap *) (MKHeap::Current()))->Alloc(size, NULL, 0);
        } else {
            mem = malloc(size);
        }
        this->unk4 = (s32) mem;
        i = 0;
        off = 0;
        src = 0;
        while (i < this->unk8->unk4) {
            *(s32 *) ((u8 *) this->unk4 + off) = (s32) this->unk8->unk0 + src;
            ((u8 *) this->unk4)[off + 0x60] = 0;
            ((Matrix *) ((u8 *) this->unk4 + off + 0x20))->SetIdentity();
            *(f32 *) ((u8 *) this->unk4 + off + 8) = 0.0f;
            *(f32 *) ((u8 *) this->unk4 + off + 12) = 0.0f;
            *(f32 *) ((u8 *) this->unk4 + off + 16) = 0.0f;
            i += 1;
            off += 0x70;
            src += 0x30;
        }
        return;
    }
    this->unk11 = 1;
    this->unk4 = (s32) arg2;
}
